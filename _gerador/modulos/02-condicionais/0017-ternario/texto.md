## 0017 · Ternário: condição ? a : b

- **Operador ternário**: o único do C com três partes. Escolhe um entre dois
  valores (DEITEL; DEITEL, 2011, cap. 3).

```c
condição ? valor_se_verdade : valor_se_falso
```

- **É expressão**: ao contrário do `if`, **devolve um valor**. Cabe à direita
  de uma atribuição, num `printf` ou no meio de uma conta
  (BACKES, 2013, cap. 4).

```c
double frete = total >= 199 ? 0.0 : 19.90;   // escolhe um valor
printf("%s\n", qtd == 1 ? "item" : "itens"); // escolhe um texto
```

- **Só um lado roda**: o C avalia a condição e depois um dos lados, como no
  curto-circuito. `b != 0 ? a / b : 0` nunca divide por zero
  (KERNIGHAN; RITCHIE, 1988, cap. 2).
- **Tipo comum**: os dois lados viram o mesmo tipo. Em `n > 0 ? n : 0.5`, com
  `n` inteiro, o resultado é `double` (KERNIGHAN; RITCHIE, 1988, cap. 2).
- **Associatividade**: desempata operadores da mesma linha da tabela, do mais
  forte ao mais fraco (a completa, com bits e ponteiros, está no 0170)
  (CPPREFERENCE, s.d.).
- **Quando usar**: para escolher **um valor**, com condição curta. Se cada lado
  faz várias coisas, ou os ternários se aninham, volte ao `if/else`.

| Operadores | Associatividade |
| --- | --- |
| `x++` `x--` (pós) | esquerda → direita |
| `!` `-x` `++x` `--x` `(tipo)` `sizeof` | direita → esquerda |
| `*` `/` `%` | esquerda → direita |
| `+` `-` | esquerda → direita |
| `<` `<=` `>` `>=` | esquerda → direita |
| `==` `!=` | esquerda → direita |
| `&&` | esquerda → direita |
| `\|\|` | esquerda → direita |
| `?:` | direita → esquerda |
| `=` `+=` `-=` `*=` `/=` `%=` | direita → esquerda |

> [!WARNING]
> **O ternário tem precedência baixíssima.** `40 - estudante ? 20 : 0` é
> `(40 - estudante) ? 20 : 0`, que dá 20 para todo mundo. Escreva
> `40 - (estudante ? 20 : 0)`: no meio de uma conta, ternário entre parênteses.

{{exemplo}}

No carrinho da loja, o frete é zero acima de R$ 199. Entram R$ 150, "passou
de 199?" é Não, e o ternário devolve 19.90 para a caixinha `frete`:

{{ideia}}

```c
#include <stdio.h>

int main(void) {
    int qtd = 3;
    double total = 150.0;

    double frete = total >= 199 ? 0.0 : 19.90;

    printf("%d %s no carrinho\n", qtd, qtd == 1 ? "item" : "itens");
    printf("Frete: R$ %.2f\n", frete);
    printf("Total: R$ %.2f\n", total + frete);
    return 0;
}
// Saída:
// 3 itens no carrinho
// Frete: R$ 19.90
// Total: R$ 169.90
```

O desenho é um `if/else` em que cada lado só guarda um valor na mesma
variável; um ternário resolve isso em uma linha:

{{fluxograma}}
