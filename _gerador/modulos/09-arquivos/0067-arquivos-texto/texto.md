## 0067 · Arquivos texto

Todo programa que você escreveu até aqui esquece tudo ao terminar. As
variáveis moram na RAM, a memória de trabalho do computador, e **somem quando
o programa acaba**. Se ele calcula as despesas do mês, na próxima execução
começa do zero. Para lembrar de uma vez para outra, o programa precisa
guardar os dados no disco, que mantém o conteúdo mesmo com a máquina
desligada.

É a diferença entre anotar as despesas de cabeça e anotar num caderno. O
caderno do programa é o **arquivo**: uma sequência de bytes guardada no
disco, com um nome, que continua lá depois que o programa termina (BACKES,
2013, cap. 12). Num **arquivo texto**, esses bytes são caracteres que você
lê num editor comum. O número 152.40 não fica guardado como um `double` de 8
bytes, mas como os seis caracteres `'1' '5' '2' '.' '4' '0'` (BACKES, 2013,
cap. 12). O assunto 0068 mostra a outra opção, o arquivo binário.

Trabalhar com arquivo sempre segue três passos: **abrir**, **ler ou
escrever** e **fechar**. Todas as funções vêm do `<stdio.h>`, o mesmo
cabeçalho do `printf` (KERNIGHAN; RITCHIE, 1989, cap. 7).

Para abrir, use `fopen(caminho, modo)`. O caminho é o nome do arquivo, como
`"despesas.txt"` ou `"/tmp/despesas.txt"`. O modo diz o que você quer fazer:
`"r"` para ler, `"w"` para escrever do zero, `"a"` para acrescentar no fim.
O `fopen` devolve um `FILE *`, um ponteiro para uma struct que a biblioteca
usa para controlar o arquivo; você nunca mexe nos campos dela, só passa o
ponteiro adiante. Se o arquivo não abrir, porque a pasta não existe, falta
permissão ou o disco encheu, o `fopen` devolve `NULL`. Por isso todo `fopen`
vem seguido de um `if`, e o `perror("Erro ao abrir")` escreve o motivo, como
`No such file or directory` (CELES; RANGEL, 2002). A tabela mostra o que
cada modo faz com um arquivo que existe ou não:

| modo | o que faz | se o arquivo não existe | se já existe |
| --- | --- | --- | --- |
| `"r"` | só leitura | `fopen` devolve `NULL` | lê do começo |
| `"w"` | só escrita | cria vazio | **apaga tudo** e começa vazio |
| `"a"` | escrita no fim (*append*) | cria vazio | mantém e escreve depois do fim |
| `"r+"` `"w+"` `"a+"` | leitura e escrita | como `r`, `w` e `a` | como `r`, `w` e `a` |

Para escrever, você já conhece quase tudo. `fprintf(arq, "Luz %.2f\n",
98.75)` é o `printf` com o arquivo como primeiro argumento, e usa o mesmo
molde do assunto 0005. `fputs(texto, arq)` grava uma string inteira, sem
acrescentar `\n`, e `fputc(c, arq)` grava um caractere (BACKES, 2013,
cap. 12).

Para ler, há três jeitos, e cada um devolve um valor que diz se deu certo
(CELES; RANGEL, 2002). `fgets(linha, tamanho, arq)` traz uma linha inteira,
com o `\n` no fim, e devolve `NULL` quando o arquivo acaba; é o mesmo `fgets`
do assunto 0042, lendo do arquivo. `fscanf(arq, "%s %lf", nome, &valor)` lê
campos com formato, como o `scanf`, e devolve quantos campos conseguiu ler.
`fgetc(arq)` lê um caractere e devolve um `int`, que vale a constante `EOF`
(*end of file*, fim de arquivo) quando não há mais nada.

Por fim, `fclose(arq)` fecha. Ele importa mais do que parece, por causa do
**buffer**: o `fprintf` não vai ao disco a cada chamada, porque o disco é
lento. Ele copia os bytes para uma área na RAM, e só quando essa área enche,
ou no `fflush(arq)`, ou no `fclose`, os bytes descem para o disco. Se o
programa cair antes do `fclose`, o que estava no buffer se perde (BACKES,
2013, cap. 12). Como no `malloc`: abriu, fecha.

Você já usou três arquivos sem abrir nenhum. `stdin` (o teclado), `stdout` (a
tela) e `stderr` (a saída de erros) são `FILE *` que o programa recebe
abertos. `printf("oi")` é o mesmo que `fprintf(stdout, "oi")`, e
`fgets(linha, 100, stdin)` lê do teclado (FEOFILOFF, 2009, ap. H).

> [!WARNING]
> Não use `while (!feof(arq))`: o `feof` só fica verdadeiro **depois** que uma
> leitura falhou, e a última linha é processada duas vezes. Teste o retorno da
> leitura (`fgets(...) != NULL`, `fscanf(...) == 2`). Com `fgetc`, guarde em
> `int`, não em `char`: num `char`, o `EOF` (-1) se confunde com um byte real.

{{exemplo}}

O programa grava as três despesas do mês (mercado, luz, internet) em
`/tmp/despesas.txt`, reabre o arquivo em leitura e o `fgets` traz as linhas,
uma por vez:

{{ideia}}

```c
#include <stdio.h>

int main(void) {
    const char *caminho = "/tmp/despesas.txt";

    FILE *arq = fopen(caminho, "w");          // "w": cria (ou apaga) o arquivo
    if (arq == NULL) {
        perror("Erro ao criar o arquivo");
        return 1;
    }
    fprintf(arq, "Mercado %.2f\n", 152.40);   // printf, mas no arquivo
    fprintf(arq, "Luz %.2f\n", 98.75);
    fprintf(arq, "Internet %.2f\n", 99.90);
    fclose(arq);                              // descarrega o buffer no disco

    arq = fopen(caminho, "r");                // agora para ler
    if (arq == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }
    char linha[100];
    int n = 0;
    while (fgets(linha, sizeof linha, arq) != NULL) { // NULL = acabou
        n++;
        printf("%d: %s", n, linha);           // a linha já traz o '\n'
    }
    fclose(arq);

    printf("%d linhas em %s\n", n, caminho);
    return 0;
}
// Saída:
// 1: Mercado 152.40
// 2: Luz 98.75
// 3: Internet 99.90
// 3 linhas em /tmp/despesas.txt
```

A leitura é um laço que testa o retorno do `fgets`: o fim do arquivo é
anunciado pela leitura que falhou:

{{fluxograma}}
