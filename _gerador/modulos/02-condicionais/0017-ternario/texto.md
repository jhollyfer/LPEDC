## 0017 · Ternário: condição ? a : b

Carrinho da loja on-line: "3 itens", "Frete: R$ 19,90". Se fosse um item só,
apareceria "1 item", no singular. E se a compra passasse de R$ 199, o frete
seria zero. São decisões minúsculas, de um valor só, e escrever um `if/else`
de cinco linhas para cada uma polui o código.

Para isso existe o **operador ternário** (o único do C com três partes):

```c
condição ? valor_se_verdade : valor_se_falso
```

A diferença para o
`if` é que o ternário é uma **expressão**: ele **devolve um valor**. Por isso
cabe onde um `if` não cabe: do lado direito de uma atribuição, dentro de um
`printf`, no meio de uma conta.

```c
double frete = total >= 199 ? 0.0 : 19.90;   // escolhe um valor
printf("%s\n", qtd == 1 ? "item" : "itens"); // escolhe um texto
```

O C garante a ordem: primeiro avalia a condição e depois **só um** dos dois
lados. O outro nem é calculado, como no curto-circuito do 0013. Então
`b != 0 ? a / b : 0` nunca divide por zero.

Os dois lados viram um **tipo comum**. Em `n > 0 ? n : 0.5`, com `n` inteiro,
o resultado é `double` mesmo quando sai o `n`. Mantenha os dois lados do mesmo
tipo e você não terá surpresa no `printf`.

Quando usar? Para escolher **um valor** entre dois, com uma condição curta. Se
cada lado faz várias coisas, ou se você começa a encadear ternários dentro de
ternários, volte para o `if/else`. Código esperto que ninguém entende é pior
que código longo.

Vamos ver na prática. Os R$ 150 entram, a pergunta "passou de 199?" responde
Não, e o ternário devolve 19.90, que vai direto para a caixinha `frete`:

{{ideia}}

O mesmo exemplo em C. Dois ternários: um escolhe o frete, o outro escolhe a
palavra:

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

Repara no fluxograma: é o mesmo desenho de um `if/else` em que cada lado só
guarda um valor na mesma variável. Sempre que você vir esse formato, um
ternário resolve em uma linha:

{{fluxograma}}

> [!WARNING]
> **O ternário tem precedência baixíssima**: só ganha da atribuição e da
> vírgula. Em `double preco = 40 - estudante ? 20 : 0;` o C entende
> `(40 - estudante) ? 20 : 0`. Como `40 - estudante` nunca é zero, o preço
> sai **20 para todo mundo**. O certo é `40 - (estudante ? 20 : 0)`. Regra
> prática: quando o ternário aparece no meio de uma conta, coloque o ternário
> inteiro entre parênteses.

> [!TIP]
> **Por dentro do C:** um `if` vira um salto, e saltos têm um custo escondido.
> O processador moderno tenta **adivinhar** para onde o salto vai e já vai
> adiantando o trabalho. Quando erra, joga tudo fora. Para escolhas simples
> como `x > y ? x : y`, o `gcc -O2` costuma gerar uma instrução sem salto
> nenhum, a `cmov` ("copia se"): calcula a condição e copia o valor certo, sem
> adivinhar nada. Ternário e `if/else` simples geram o mesmo código: escolha
> pelo que fica mais legível.

> [!NOTE]
> **Pergunta para você:** com `qtd = 1` e `total = 199.0`, quais são as três
> linhas da saída? Pense nos dois ternários antes de mudar o A033.

{{pratique}}
