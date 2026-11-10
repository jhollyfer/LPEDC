## 0170 · Precedência e ordem de avaliação

Três pacotes de café a R$ 18 mais R$ 12 de frete: `18 * 3 + 12` dá 66, não
270. A ordem entre operadores é fixa, e a prova a esconde numa linha só.

A **precedência** diz qual operador pega os operandos primeiro: `*` antes de
`+`. A **associatividade** desempata operadores do mesmo nível: `100 - 66 -
20` é `(100 - 66) - 20`, mas `a = b = 5` é `a = (b = 5)`.

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

Três pontos da tabela caem em prova. Os bit a bit `&`, `^` e `|` ficam
**abaixo** do `==`. O `?:` fica abaixo de quase tudo, então `compra + compra
>= 50 ? 0 : frete` pergunta pela soma inteira. E `a *= 2 + 1` é `a = a * (2 +
1)`.

Agrupar não é calcular. Em `f() + g()`, a soma junta os dois resultados, mas a
**ordem de avaliação** deles não é especificada. Só `&&`, `||`, `?:` e a
vírgula avaliam o lado esquerdo antes do direito, e uma função só começa
depois de todos os argumentos prontos.

**Efeito colateral** é o que a expressão muda além de produzir valor: `i++`
muda `i`, `printf` escreve na tela. Mudar a mesma variável duas vezes, ou
mudar e ler sem ordem garantida, é **comportamento indefinido**: `i = i++`,
`v[i] = i++`, `printf("%d %d", i, i++)`.

O operador de menor precedência fica na raiz da árvore e age por último. No
frete grátis, é o `?:`:

{{ideia}}

O programa mostra cada agrupamento:

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

> [!WARNING]
> `i = i++` é comportamento indefinido. Com `-Wall`, o gcc avisa:
>
> ```text
> warning: operation on 'i' may be undefined [-Wsequence-point]
> ```
>
> Ele também avisa `x & 3 == 3` e `a || b && c`, mas **não**
> `compra + compra >= 50 ? 0 : frete`. Na dúvida, use parênteses.

> [!TIP]
> O compilador visita os galhos da árvore na ordem que quiser, por isso `f()
> + g()` não tem ordem prometida. Já em `&&`, o lado direito nem roda se o
> esquerdo der 0.

> [!NOTE]
> **Pergunta para você:** quanto vale `x` depois de `int x = 10; x -= 2 * 3 - 1;`?
> E `1 + 2 << 1`, que o gcc avisa mas compila?

{{pratique}}
