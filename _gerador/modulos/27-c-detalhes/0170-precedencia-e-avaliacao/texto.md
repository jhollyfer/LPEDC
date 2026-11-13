## 0170 · Precedência e ordem de avaliação

- **Precedência**: diz qual operador pega os operandos primeiro; `*` vem antes
  de `+` (DEITEL; DEITEL, 2011, cap. 2).
- **Associatividade**: desempata operadores do mesmo nível. `100 - 66 - 20` é
  `(100 - 66) - 20`; `a = b = 5` é `a = (b = 5)` (KERNIGHAN; RITCHIE, 1988, cap. 2).
- **Três armadilhas da tabela**: `&`, `^` e `|` ficam **abaixo** do `==`; o
  `?:` fica abaixo de quase tudo; `a *= 2 + 1` é `a = a * (2 + 1)`
  (CPPREFERENCE, s.d.).
- **Ordem de avaliação**: agrupar não é calcular. Em `f() + g()` a ordem das
  chamadas não é especificada. Só `&&`, `||`, `?:` e a vírgula avaliam a
  esquerda antes da direita (ISO/IEC, 2018).
- **Curto-circuito**: em `&&`, o lado direito nem roda se o esquerdo der 0;
  em `||`, se der 1 (DEITEL; DEITEL, 2011, cap. 4).
- **Efeito colateral**: o que a expressão muda além de dar um valor (`i++`
  muda `i`, `printf` escreve). Mudar a mesma variável duas vezes sem ordem
  garantida é **comportamento indefinido**: `i = i++`, `v[i] = i++`
  (ISO/IEC, 2018).

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
> `i = i++` é comportamento indefinido, e o gcc com `-Wall` avisa. Ele também
> avisa `x & 3 == 3` e `a || b && c`, mas **não**
> `compra + compra >= 50 ? 0 : frete`. Na dúvida, use parênteses.

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
