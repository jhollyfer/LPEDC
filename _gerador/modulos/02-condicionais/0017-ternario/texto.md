## 0017 · Ternário: condição ? a : b

Carrinho da loja on-line: "3 itens", "Frete: R$ 19,90". Com um item só,
"1 item". Se a compra passar de R$ 199, o frete é zero. São decisões de um
valor só, e um `if/else` de cinco linhas para cada uma polui o código.

O **operador ternário** (o único do C com três partes) resolve isso:

```c
condição ? valor_se_verdade : valor_se_falso
```

Ao contrário do `if`, o ternário é uma **expressão**: **devolve um valor**.
Por isso cabe à direita de uma atribuição, dentro de um `printf`, no meio de
uma conta.

```c
double frete = total >= 199 ? 0.0 : 19.90;   // escolhe um valor
printf("%s\n", qtd == 1 ? "item" : "itens"); // escolhe um texto
```

O C avalia a condição e depois **só um** dos lados, como no curto-circuito do
0013: `b != 0 ? a / b : 0` nunca divide por zero.

Com o ternário, você conhece quase todos os operadores do C. A tabela vai do
mais forte ao mais fraco; a **associatividade** desempata operadores da mesma
linha (a tabela completa, com bits e ponteiros, está no 0170):

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

Os dois lados viram um **tipo comum**: em `n > 0 ? n : 0.5`, com `n` inteiro,
o resultado é `double` mesmo quando sai o `n`. Mantenha os dois lados do mesmo
tipo.

Use o ternário para escolher **um valor** entre dois, com condição curta. Se
cada lado faz várias coisas, ou os ternários se aninham, volte ao `if/else`.

No carrinho, entram R$ 150, "passou de 199?" é Não, e o ternário devolve 19.90
para a caixinha `frete`:

{{ideia}}

Em C, um ternário escolhe o frete e outro, a palavra:

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
variável. Nesse formato, um ternário resolve em uma linha:

{{fluxograma}}

> [!WARNING]
> **O ternário tem precedência baixíssima**: só ganha da atribuição e da
> vírgula. Em `double preco = 40 - estudante ? 20 : 0;`, o C entende
> `(40 - estudante) ? 20 : 0`; como `40 - estudante` nunca é zero, o preço
> sai **20 para todo mundo**. O certo é `40 - (estudante ? 20 : 0)`. No meio
> de uma conta, ponha o ternário inteiro entre parênteses.

> [!NOTE]
> **Pergunta para você:** com `qtd = 1` e `total = 199.0`, quais são as três
> linhas da saída? Pense nos dois ternários antes de mudar o código acima.

{{pratique}}
