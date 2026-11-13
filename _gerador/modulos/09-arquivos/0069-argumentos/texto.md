## 0069 · Argumentos da linha de comando

- **Argumentos da linha de comando**: dados que vão junto do comando, como em
  `cp origem destino`. Chegam como parâmetros do `main`
  (BACKES, 2013, cap. 13).

```c
int main(int argc, char *argv[])
```

- **`argc`** (*argument count*): quantos itens vieram, **contando o nome do
  programa**. Vale pelo menos 1 (FEOFILOFF, 2009, ap. H).
- **`argv`** (*argument vector*): vetor de `char *`, uma string por item.
  `argv[0]` é o nome do programa e `argv[argc]` é `NULL`
  (KERNIGHAN; RITCHIE, 1989).
- **Shell**: corta a linha antes de o programa começar. Separa nos espaços,
  tira as aspas e expande coringas: `"São Paulo"` chega como um argumento só.
- **Tudo é texto**: o `4` chega como `"4"`. `strtol(texto, &fim, 10)` e
  `strtod(texto, &fim)` convertem e apontam `fim` para o que sobrou; se
  `*fim != '\0'`, veio lixo (LINUX MAN-PAGES PROJECT, s.d.).
- **`atoi` e `atof`**: não avisam erro, `atoi("quatro")` devolve 0. Servem para
  teste rápido (BACKES, 2013, cap. 13).
- **`stderr` e código de saída**: erros vão para `stderr`, que aparece mesmo com
  `> saida.txt`. O `return` do `main` é 0 no sucesso e outro valor na falha; o
  shell guarda em `$?` (BACKES, 2013, cap. 12).

> [!WARNING]
> Nunca use `argv[1]` sem conferir o `argc`: sem argumentos, ele é `NULL` e
> `atoi(NULL)` derruba o programa. E em `./calc 9 * 3` o shell troca o `*`
> pelos nomes dos arquivos da pasta; use aspas (`'*'`) ou `x`.

{{exemplo}}

Fim do rodízio de pizza: conta de R$ 187,40 para 4 pessoas. O comando
`./racha 187.40 4` chega com `argc = 3`. O programa confere a quantidade,
converte `argv[1]` e `argv[2]` e divide:

{{ideia}}

Salve como `racha.c`, compile com as flags de estudo e passe os argumentos
depois do executável: `./programa 187.40 4`.

```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Uso: %s <total> <pessoas>\n", argv[0]);
        return 1;                             // diferente de 0: deu errado
    }

    char *fim;
    double total = strtod(argv[1], &fim);     // texto -> double
    if (*fim != '\0' || total <= 0) {
        fprintf(stderr, "Total inválido: %s\n", argv[1]);
        return 1;
    }
    long pessoas = strtol(argv[2], &fim, 10); // texto -> inteiro, base 10
    if (*fim != '\0' || pessoas <= 0) {
        fprintf(stderr, "Número de pessoas inválido: %s\n", argv[2]);
        return 1;
    }

    printf("Conta: R$ %.2f\n", total);
    printf("Pessoas: %ld\n", pessoas);
    printf("Cada um: R$ %.2f\n", total / pessoas);
    return 0;
}
// $ ./programa 187.40 4
// Conta: R$ 187.40
// Pessoas: 4
// Cada um: R$ 46.85
//
// $ ./programa 187.40 quatro
// Número de pessoas inválido: quatro
```

Duas perguntas antes da conta: veio a quantidade certa de argumentos, e são
números de verdade? O programa só trabalha no caminho verde:

{{fluxograma}}
