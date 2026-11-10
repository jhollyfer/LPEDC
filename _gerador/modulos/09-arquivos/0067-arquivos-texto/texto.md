## 0067 · Arquivos texto

Todo mês você anota as despesas: mercado, luz, internet. Anotadas só de
cabeça, somem. No caderno, ficam. Com um programa é igual: as variáveis moram
na RAM e **somem quando ele termina**. Para lembrar na próxima execução, ele
escreve num **arquivo**, que fica no disco.

No C são três passos: **abrir**, **ler ou escrever** e **fechar**. Tudo vem do
`<stdio.h>`, o mesmo do `printf`. Para o C, um arquivo é uma **sequência de
bytes**. Num **arquivo texto**, esses bytes são caracteres legíveis no editor:
o número 152.40 vira `'1' '5' '2' '.' '4' '0'`.

**Abrir.** `fopen(caminho, modo)` devolve um `FILE *`, ponteiro para uma
struct que a biblioteca usa para controlar o arquivo. Se não abrir (pasta
inexistente, sem permissão, disco cheio), devolve `NULL`. Por isso todo
`fopen` leva um `if`. O `perror("texto")` mostra o motivo, como
`No such file or directory`.

| modo | o que faz | se o arquivo não existe | se já existe |
| --- | --- | --- | --- |
| `"r"` | só leitura | `fopen` devolve `NULL` | lê do começo |
| `"w"` | só escrita | cria vazio | **apaga tudo** e começa vazio |
| `"a"` | escrita no fim (*append*) | cria vazio | mantém e escreve depois do fim |
| `"r+"` `"w+"` `"a+"` | leitura e escrita | como `r`, `w` e `a` | como `r`, `w` e `a` |

**Escrever.** `fprintf(arq, ...)` é o `printf` com o arquivo na frente.
`fputs(texto, arq)` grava uma string (sem pôr `\n`) e `fputc(c, arq)`, um
caractere.

**Ler.** Três jeitos:

- `fgets(linha, tamanho, arq)`: uma **linha**, com o `\n` no fim. Devolve
  `NULL` quando o arquivo acaba. É o `fgets` do 0042, lendo do arquivo.
- `fscanf(arq, "%s %lf", ...)`: campos com formato. Devolve quantos campos
  leu.
- `fgetc(arq)`: um **caractere**. Devolve `int`, que vale `EOF` no fim.

**Fechar.** `fclose(arq)` grava o que ficou pendente e libera o `FILE`. Como
no `malloc`: abriu, fecha.

`stdin`, `stdout` e `stderr` já são `FILE *` abertos pelo programa:
`printf("oi")` equivale a `fprintf(stdout, "oi")`.

O exemplo grava as três despesas do mês. Os `fprintf` param num **buffer**
(área na RAM); o `fclose` o descarrega em `despesas.txt`. Depois o programa
reabre o arquivo em leitura e o `fgets` traz as linhas, uma por vez:

{{ideia}}

O código grava em `/tmp/despesas.txt` e deixa o arquivo lá, para `cat`:

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

No fluxograma, a leitura é um laço que testa o retorno do `fgets`: o fim do
arquivo é anunciado pela leitura que falhou:

{{fluxograma}}

> [!WARNING]
> Não use `while (!feof(arq))`, comum em materiais e livros. O `feof` só fica
> verdadeiro **depois** que uma leitura tentou passar do fim. O laço roda uma
> vez a mais e processa a última linha duas vezes (o E401 mostra). Teste o
> retorno da leitura: `fgets(...) != NULL`, `fscanf(...) == 2`,
> `(c = fgetc(arq)) != EOF`. Neste último, `c` é `int`: com `char`, o `EOF`
> (-1) se confunde com um byte de verdade.

> [!TIP]
> **Por dentro do C:** cada `fprintf` só copia bytes para o buffer do `FILE`
> (em geral 4096 bytes). A entrega ao sistema, um `write`, ocorre quando o
> buffer enche, no `fflush(arq)` ou no `fclose`. Se o programa cair antes do
> `fclose`, o que estava no buffer se perde.

> [!NOTE]
> **Pergunta para você:** rode o programa das despesas duas vezes seguidas. O
> arquivo fica com 3 ou com 6 linhas? E se o primeiro `fopen` usasse `"a"` em
> vez de `"w"`?


{{pratique}}
