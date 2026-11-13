## 0067 · Arquivos texto

- **Arquivo**: sequência de bytes guardada no disco. Variáveis moram na RAM e
  somem quando o programa termina; o arquivo fica (BACKES, 2013, cap. 12).
- **Arquivo texto**: os bytes são caracteres legíveis no editor. O número
  152.40 vira `'1' '5' '2' '.' '4' '0'` (BACKES, 2013, cap. 12).
- **Três passos**: abrir, ler ou escrever, fechar. Tudo vem do `<stdio.h>`
  (KERNIGHAN; RITCHIE, 1989, cap. 7).
- **`fopen(caminho, modo)`**: devolve um `FILE *` ou `NULL` se não abrir. Todo
  `fopen` leva um `if`; `perror("texto")` mostra o motivo
  (CELES; RANGEL, 2002).
- **Escrever**: `fprintf(arq, ...)` é o `printf` com o arquivo na frente;
  `fputs` grava uma string (sem `\n`) e `fputc`, um caractere
  (BACKES, 2013, cap. 12).
- **Ler**: `fgets` traz uma linha com o `\n` e devolve `NULL` no fim; `fscanf`
  devolve quantos campos leu; `fgetc` devolve `int`, que vale `EOF` no fim
  (CELES; RANGEL, 2002).
- **Buffer e `fclose`**: a escrita para numa área da RAM e o `fclose` (ou
  `fflush`) a descarrega no disco. Se o programa cair antes, perde-se o que
  estava no buffer (BACKES, 2013, cap. 12).
- **`stdin`, `stdout`, `stderr`**: `FILE *` já abertos; `printf("oi")` equivale
  a `fprintf(stdout, "oi")` (FEOFILOFF, 2009, ap. H).

| modo | o que faz | se o arquivo não existe | se já existe |
| --- | --- | --- | --- |
| `"r"` | só leitura | `fopen` devolve `NULL` | lê do começo |
| `"w"` | só escrita | cria vazio | **apaga tudo** e começa vazio |
| `"a"` | escrita no fim (*append*) | cria vazio | mantém e escreve depois do fim |
| `"r+"` `"w+"` `"a+"` | leitura e escrita | como `r`, `w` e `a` | como `r`, `w` e `a` |

> [!WARNING]
> Não use `while (!feof(arq))`: o `feof` só fica verdadeiro **depois** que uma
> leitura falhou, e a última linha é processada duas vezes. Teste o retorno da
> leitura (`fgets(...) != NULL`). Com `fgetc`, guarde em `int`, não em `char`.

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
