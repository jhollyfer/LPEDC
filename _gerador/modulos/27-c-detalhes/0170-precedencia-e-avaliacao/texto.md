## 0170 · Precedência e ordem de avaliação

Três pacotes de café a R$ 18 cada, mais R$ 12 de frete. Você escreve
`18 * 3 + 12` e espera 66, e o C dá 66. Mas por que não 270, que seria
`18 * (3 + 12)`? Porque a ordem em que os operadores pegam seus operandos é
fixa, e quem escreve a expressão precisa conhecê-la. A prova adora esconder
essa ordem numa linha só, com cinco operadores e nenhum parêntese.

A primeira regra é a **precedência**: ela diz qual operador pega os
operandos primeiro (DEITEL; DEITEL, 2011, cap. 2). O `*` tem precedência
maior que o `+`, então em `18 * 3 + 12` o `*` agarra o 18 e o 3, e o `+`
recebe o resultado e o 12. Uma boa imagem é uma árvore: o operador de
**menor** precedência fica na raiz e age por último; os de maior
precedência ficam nos galhos e agem antes. Os parênteses mudam a árvore:
`18 * (3 + 12)` põe o `+` num galho.

A segunda regra resolve empates. Quando dois operadores têm a mesma
precedência, a **associatividade** diz de que lado começa o agrupamento
(KERNIGHAN; RITCHIE, 1988, cap. 2). A subtração agrupa da esquerda para a
direita: `100 - 66 - 20` é `(100 - 66) - 20`, que dá 14, e não
`100 - (66 - 20)`, que daria 54. A atribuição agrupa da direita para a
esquerda: `a = b = 5` é `a = (b = 5)`, que guarda 5 em `b` e depois o
mesmo 5 em `a`.

A tabela completa está no fim, mas três pontos dela caem em prova e merecem
atenção (CPPREFERENCE, s.d.). Os operadores bit a bit `&`, `^` e `|` ficam
**abaixo** do `==`, então `x & 3 == 3` é `x & (3 == 3)`, que vira `x & 1`.
O `?:` fica abaixo de quase tudo, então
`compra + compra >= 50 ? 0 : frete` pergunta se a soma inteira passa de 50.
E as atribuições compostas têm a precedência mais baixa antes da vírgula:
`a *= 2 + 1` é `a = a * (2 + 1)`, e não `a * 2 + 1`.

Agora a parte que mais confunde: **agrupar não é calcular**. A precedência
e a associatividade dizem como a expressão se divide em pedaços; elas não
dizem em que ordem os pedaços são calculados. Em `f() + g()`, a soma junta
os dois resultados, mas a **ordem de avaliação**, qual das duas funções
roda primeiro, não é especificada pela norma. O compilador visita os galhos
da árvore na ordem que preferir. Só quatro operadores garantem que o lado
esquerdo é calculado antes do direito: `&&`, `||`, `?:` e a vírgula. E uma
função só começa depois de todos os seus argumentos estarem prontos
(ISO/IEC, 2018).

O `&&` e o `||` vão além: eles têm **curto-circuito**. Em `a && b`, se `a`
dá 0, o resultado já é 0, e o `b` nem é calculado. Em `a || b`, se `a` dá
diferente de 0, o resultado já é 1, e o `b` também é pulado (DEITEL;
DEITEL, 2011, cap. 4). É isso que torna seguro escrever
`p != NULL && p->valor > 0`: se `p` é `NULL`, o acesso `p->valor` não
acontece.

A ordem de avaliação importa por causa dos **efeitos colaterais**, tudo o
que uma expressão muda além de produzir um valor. `i++` produz o valor de
`i` e, como efeito colateral, muda `i`; `printf` produz um número e escreve
na tela. Se a mesma variável é mudada duas vezes, ou mudada e lida, sem que
a norma garanta qual vem antes, o resultado é **comportamento
indefinido**: o programa pode dar qualquer coisa, e cada compilador pode dar
algo diferente. São exemplos `i = i++`, `v[i] = i++` e
`printf("%d %d", i, i++)` (ISO/IEC, 2018).

| Nível | Operadores | Agrupa |
| --- | --- | --- |
| 1 | `()` `[]` `->` `.` `x++` `x--` | esquerda → direita |
| 2 | `++x` `--x` `+x` `-x` `!` `~` `*p` `&x` `(tipo)` `sizeof` | direita → esquerda |
| 3 | `*` `/` `%` | esquerda → direita |
| 4 | `+` `-` | esquerda → direita |
| 5 | `<<` `>>` | esquerda → direita |
| 6 | `<` `<=` `>` `>=` | esquerda → direita |
| 7 | `==` `!=` | esquerda → direita |
| 8 | `&` | esquerda → direita |
| 9 | `^` | esquerda → direita |
| 10 | `\|` | esquerda → direita |
| 11 | `&&` | esquerda → direita |
| 12 | `\|\|` | esquerda → direita |
| 13 | `?:` | direita → esquerda |
| 14 | `=` `+=` `-=` `*=` `/=` `%=` `<<=` `>>=` `&=` `^=` `\|=` | direita → esquerda |
| 15 | `,` | esquerda → direita |

> [!WARNING]
> `i = i++` é comportamento indefinido. Com `-Wall`, o gcc avisa
> (`operation on 'i' may be undefined`). Ele também avisa `x & 3 == 3` e
> `a || b && c`, mas **não** `compra + compra >= 50 ? 0 : frete`. Na
> dúvida, use parênteses.

{{exemplo}}

Três pacotes de café a R$ 18 mais R$ 12 de frete, com frete grátis a partir
de R$ 50. O operador de menor precedência fica na raiz da árvore e age por
último; no frete grátis, é o `?:`:

{{ideia}}

```c
#include <stdio.h>

int main(void) {
    int preco = 18, qtd = 3, frete = 12; // 3 pacotes de café a R$ 18

    int total = preco * qtd + frete;    // * antes de +: (18 * 3) + 12
    int outro = preco * (qtd + frete);  // parênteses mandam: 18 * 15
    printf("total = %d, outro = %d\n", total, outro);

    int sobra = 100 - total - 20;       // - é da esquerda: (100 - 66) - 20
    printf("sobra = %d\n", sobra);

    int a, b;
    a = b = 5;                          // = é da direita: a = (b = 5)
    a *= 2 + 1;                         // a = a * (2 + 1), não a * 2 + 1
    printf("a = %d, b = %d\n", a, b);

    int compra = preco * qtd;           // 54
    // frete grátis a partir de R$ 50: o ?: fica ABAIXO do +
    int pegadinha = compra + compra >= 50 ? 0 : frete; // ((54 + 54) >= 50) ? 0 : 12
    int certo = compra + (compra >= 50 ? 0 : frete);   // 54 + 0
    printf("pegadinha = %d, certo = %d\n", pegadinha, certo);

    int gratis = compra >= 50 && qtd >= 3; // relacionais antes de &&: (54 >= 50) && (3 >= 3)
    printf("frete grátis? %d\n", gratis);
    return 0;
}
// Saída:
// total = 66, outro = 270
// sobra = 14
// a = 15, b = 5
// pegadinha = 0, certo = 54
// frete grátis? 1
```

No fluxograma, o `?:` é uma pergunta escondida; no `certo`, ela olha só o
`compra`:

{{fluxograma}}

Com `-Wall`, o gcc avisa sobre `i = i++`:
`warning: operation on 'i' may be undefined [-Wsequence-point]`.
