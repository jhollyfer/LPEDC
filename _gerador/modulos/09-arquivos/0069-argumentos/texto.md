## 0069 · Argumentos da linha de comando

Fim do rodízio de pizza, conta de R$ 187,40 para 4 pessoas. Um programa
poderia perguntar total e pessoas com `scanf`. Mas os programas de terminal
não perguntam: `git commit -m "msg"`, `cp origem destino`,
`gcc -o prog prog.c`. Os dados vão **junto do comando**, são os **argumentos
da linha de comando**.

No C, chegam como parâmetros do `main`, que até agora tinha `void`:

```c
int main(int argc, char *argv[])
```

- **`argc`** (*argument count*): quantos itens vieram, **contando o nome do
  programa**. Vale pelo menos 1.
- **`argv`** (*argument vector*): vetor de `char *`, uma string por item.
  `argv[0]` é o nome do programa, `argv[1]` é o primeiro argumento seu, e
  `argv[argc]` é `NULL`, que marca o fim como o `'\0'` numa string.

Quem corta a linha é o **shell** (bash, zsh), antes de o programa começar:
separa nos espaços, tira as aspas e expande coringas como `*`. `"São Paulo"`
chega como um argumento só; sem aspas, como dois.

Tudo no `argv` é **texto**: o `4` chega como `"4"`, e `argv[2] * 2` nem
compila. Para converter:

- **`strtol(texto, &fim, 10)`** converte para `long` e **`strtod(texto,
  &fim)`** para `double`. Ambos apontam `fim` para o primeiro caractere não
  convertido. Se `*fim != '\0'`, sobrou lixo: `"4x"`, `"quatro"`.
- **`atoi`** e **`atof`** são mais curtos, mas não avisam erro:
  `atoi("quatro")` devolve 0. Servem para teste rápido, não para entrada de
  usuário.

Duas convenções de programas de terminal. Erros vão para **`stderr`**
(`fprintf(stderr, ...)`): quem redireciona a saída (`./racha 10 2 > saida.txt`)
ainda vê o erro na tela. E o `return` do `main` é o **código de saída**: 0 é
sucesso, outro valor é falha. O shell o guarda em `$?`, e scripts e o `&&`
decidem com base nele.

O comando `./racha 187.40 4` chega com `argc = 3` e um `argv` de três
strings mais o `NULL`. O programa confere a quantidade, converte `argv[1]` e
`argv[2]` e divide:

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

O fluxograma faz duas perguntas antes da conta: veio a quantidade certa de
argumentos, e são números de verdade? O programa só trabalha no caminho verde:

{{fluxograma}}

> [!WARNING]
> Nunca use `argv[1]` sem conferir o `argc`. Sem argumentos, `argv[1]` é
> `NULL`, e `atoi(NULL)` ou `strlen(NULL)` derruba o programa (o E412 mostra).
> Cuidado com `*`: em `./calc 9 * 3` o shell troca o `*` pelos nomes dos
> arquivos da pasta antes de o programa rodar. Use aspas (`'*'`) ou outro
> símbolo, como `x`.

> [!TIP]
> **Por dentro do C:** quem chama o `main` é o código de partida da biblioteca
> (`_start`): ele conta os ponteiros do `argv`, chama `main(argc, argv)` e
> passa o `return` ao `exit`. Por isso `char *argv[]` e `char **argv` são
> iguais num parâmetro: vetor como parâmetro vira ponteiro (0038).

> [!NOTE]
> **Pergunta para você:** quanto vale `argc` em `./racha "187.40 4"`? E em
> `./racha 187.40 4 > conta.txt`? Pense em quem trata as aspas e o `>` antes
> de rodar o A138 para conferir.

{{pratique}}
