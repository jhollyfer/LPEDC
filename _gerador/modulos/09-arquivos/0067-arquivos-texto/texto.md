## 0067 · Arquivos texto

Todo mês você anota as despesas: mercado, luz, internet. Se anotar só de
cabeça, esquece. Se anotar no caderno, no mês que vem está tudo lá. Um
programa tem o mesmo problema: as variáveis moram na RAM e **somem quando ele
termina**. Para lembrar de alguma coisa na próxima execução, ele precisa
escrever num **arquivo**, que fica no disco.

No C, esse trabalho acontece em passos que você enxerga: **abrir**, **ler ou
escrever** e **fechar**. Tudo vem do `<stdio.h>`, o mesmo do `printf`.

Para o C, um arquivo é só uma **sequência de bytes** no disco. Num **arquivo
texto**, esses bytes são caracteres que você consegue ler no editor: o número
152.40 vira os caracteres `'1' '5' '2' '.' '4' '0'`. Quem dá sentido a eles é o
seu programa.

**Abrir.** `fopen(caminho, modo)` devolve um `FILE *`, um ponteiro para uma
struct que a biblioteca usa para controlar o arquivo aberto. Se não der para
abrir (pasta que não existe, sem permissão, disco cheio), devolve `NULL`. Por
isso todo `fopen` vem seguido de um `if`. O `perror("texto")` mostra o motivo
que o sistema deu, como `No such file or directory`.

| modo | o que faz | se o arquivo não existe | se já existe |
| --- | --- | --- | --- |
| `"r"` | só leitura | `fopen` devolve `NULL` | lê do começo |
| `"w"` | só escrita | cria vazio | **apaga tudo** e começa vazio |
| `"a"` | escrita no fim (*append*) | cria vazio | mantém e escreve depois do fim |
| `"r+"` `"w+"` `"a+"` | leitura e escrita | como `r`, `w` e `a` | como `r`, `w` e `a` |

**Escrever.** `fprintf(arq, ...)` é o `printf` com o arquivo na frente.
Também existem `fputs(texto, arq)` (uma string, sem pôr `\n`) e
`fputc(c, arq)` (um caractere).

**Ler.** Três jeitos, conforme o formato:

- `fgets(linha, tamanho, arq)`: uma **linha** inteira, com o `\n` no fim.
  Devolve `NULL` quando o arquivo acaba. É o mesmo `fgets` do assunto 0042, só
  que lendo do arquivo em vez do teclado.
- `fscanf(arq, "%s %lf", ...)`: campos com formato, como o `scanf`. Devolve
  quantos campos conseguiu ler.
- `fgetc(arq)`: um **caractere** por vez. Devolve um `int`, que vale `EOF` no
  fim.

**Fechar.** `fclose(arq)` termina a conversa com o arquivo: grava o que ainda
estava pendente e libera o `FILE`. Arquivo aberto é recurso emprestado, como
memória do `malloc`: abriu, fecha.

Você já usava arquivos sem saber: `stdin`, `stdout` e `stderr` são `FILE *`
que o programa recebe abertos. `printf("oi")` é o mesmo que
`fprintf(stdout, "oi")`.

Vamos ver na prática. O programa grava as três despesas do mês. Os
`fprintf` não vão direto para o disco: param num **buffer**, uma área na RAM.
O `fclose` descarrega o buffer em `despesas.txt`. Depois o programa abre o
arquivo de novo, em modo leitura, e o `fgets` traz as linhas de volta, uma
por vez:

{{ideia}}

O código grava em `/tmp/despesas.txt` e deixa o arquivo lá, para você abrir
com `cat`:

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

Repara no fluxograma: a leitura é um laço que pergunta ao próprio `fgets` se
ele conseguiu ler. Quem diz que o arquivo acabou é a leitura que falhou, não
uma pergunta feita antes dela:

{{fluxograma}}

> [!WARNING]
> Você vai ver `while (!feof(arq))` em muito material, inclusive livro. Não use.
> O `feof` não olha adiante: ele só fica verdadeiro **depois** que uma leitura
> tentou passar do fim e falhou. Resultado: o laço roda uma vez a mais e
> processa a última linha duas vezes (o E401 mostra isso). Teste o retorno da
> leitura: `fgets(...) != NULL`, `fscanf(...) == 2`, `(c = fgetc(arq)) != EOF`.
> E nesse último, `c` é `int`: com `char`, o `EOF` (que vale -1) se confunde
> com um byte de verdade.

> [!TIP]
> **Por dentro do C:** a struct `FILE` guarda a posição atual no arquivo, os
> indicadores de erro e de fim e um **buffer** de alguns KB (no Linux, em
> geral 4096 bytes). Cada `fprintf` só copia bytes para esse buffer, na RAM. A
> entrega ao sistema operacional, uma chamada `write`, só acontece quando o
> buffer enche, quando você chama `fflush(arq)` ou no `fclose`. Compile sem o
> sanitizer (`gcc A133.c -o /tmp/a143`, porque o ASan não gosta do `strace`) e
> rode `strace -e trace=write /tmp/a143`: as três despesas saem num único
> `write` de 40 bytes (15 + 10 + 15). Se o programa cair antes do `fclose`, o
> que estava no buffer se perde.

> [!NOTE]
> **Pergunta para você:** rode o A133 duas vezes seguidas. O arquivo fica com
> 3 ou com 6 linhas? E se o primeiro `fopen` usasse `"a"` em vez de `"w"`?

{{pratique}}
