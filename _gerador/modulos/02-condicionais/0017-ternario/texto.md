## 0017 · Ternário: condição ? a : b

Muitas decisões servem só para escolher um valor. O frete é zero ou
R$ 19,90; a palavra é "item" ou "itens"; a nota mínima é 5 ou 6. Com
`if/else`, cada escolha dessas ocupa cinco linhas e repete o nome da
variável nos dois blocos. Quando o programa tem várias delas, o código
cresce sem dizer nada de novo.

Pense no carrinho de uma loja on-line. Ele mostra "3 itens" ou "1 item",
conforme a quantidade, e mostra o frete, que é zero para compras a partir
de R$ 199. Nenhuma dessas decisões faz trabalho: cada uma só escolhe o que
vai aparecer numa lacuna da tela.

Para isso o C tem o **operador ternário**, o único da linguagem com três
partes: uma condição, o valor para quando ela é verdadeira e o valor para
quando é falsa (DEITEL; DEITEL, 2011, cap. 3). O `?` separa a condição do
primeiro valor, e o `:` separa os dois valores.

```c
condição ? valor_se_verdade : valor_se_falso
```

A diferença para o `if` está na natureza das duas coisas. O `if` é um
comando: ele escolhe quais instruções rodam. O ternário é uma
**expressão**: ele **devolve um valor**, como `2 + 3` devolve 5 (BACKES,
2013, cap. 4). Por isso ele cabe em lugares em que um `if` não cabe: à
direita de uma atribuição, dentro dos argumentos de um `printf`, no meio de
uma conta.

```c
double frete = total >= 199 ? 0.0 : 19.90;   // escolhe um valor
printf("%s\n", qtd == 1 ? "item" : "itens"); // escolhe um texto
```

O C avalia primeiro a condição e depois **só um** dos lados, o escolhido. O
outro nem é calculado, como no curto-circuito do 0013. Isso torna seguro
escrever `b != 0 ? a / b : 0`: quando `b` é zero, a divisão nunca acontece
(KERNIGHAN; RITCHIE, 1988, cap. 2).

Como o ternário devolve um valor só, esse valor precisa ter um tipo só. Os
dois lados são convertidos para um **tipo comum**, pelas regras de
conversão do 0008. Em `n > 0 ? n : 0.5`, com `n` inteiro, o resultado é
`double` mesmo quando quem sai é o `n` (KERNIGHAN; RITCHIE, 1988, cap. 2).
O mais simples é manter os dois lados do mesmo tipo.

Com o ternário, você já conhece quase todos os operadores do C, e vale ver
a ordem completa. A tabela vai do mais forte ao mais fraco. Quando dois
operadores da mesma linha aparecem juntos, quem decide é a
**associatividade**, o sentido em que a conta é feita: `a - b - c` é
`(a - b) - c`, da esquerda para a direita, e `a = b = c` é `a = (b = c)`,
da direita para a esquerda (CPPREFERENCE, s.d.). A tabela completa, com os
operadores de bits e de ponteiros, está no 0170.

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

Repare onde o `?:` ficou: quase no fim, acima só da atribuição. Isso
explica o erro do alerta abaixo. Use o ternário para escolher **um valor**
entre dois, com uma condição curta. Se cada lado precisa fazer várias
coisas, ou se você começa a pôr um ternário dentro de outro, volte ao
`if/else`, que se lê com mais facilidade.

> [!WARNING]
> **O ternário tem precedência baixíssima.** `40 - estudante ? 20 : 0` é
> `(40 - estudante) ? 20 : 0`, que dá 20 para todo mundo. Escreva
> `40 - (estudante ? 20 : 0)`: no meio de uma conta, ternário entre
> parênteses.

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
