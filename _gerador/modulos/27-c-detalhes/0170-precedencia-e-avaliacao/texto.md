## 0170 · Precedência e ordem de avaliação

Você pede 3 pacotes de café a R$ 18 no app do mercado, e o frete é R$ 12. A
conta é `18 * 3 + 12`. Ninguém pensa duas vezes: dá 66. Mas por que não
`18 * (3 + 12)`, que dá 270? Porque o C, como a matemática da escola, tem uma
regra fixa de quem vai primeiro, e a prova gosta de esconder essa regra numa
linha só.

Duas regras decidem como o C **agrupa** uma expressão. A **precedência** diz
qual operador pega os operandos primeiro: `*` antes de `+`. A
**associatividade** desempata operadores do mesmo nível: `100 - 66 - 20` é
`(100 - 66) - 20`, da esquerda para a direita, mas `a = b = 5` é
`a = (b = 5)`, da direita para a esquerda.

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

Três pontos dessa tabela caem em prova. Os bit a bit `&`, `^` e `|` ficam
**abaixo** do `==`. O `?:` fica abaixo de quase tudo, então
`compra + compra >= 50 ? 0 : frete` é uma pergunta sobre a soma inteira. E a
atribuição composta trata o lado direito como um bloco: `a *= 2 + 1` é
`a = a * (2 + 1)`.

Agrupar não é calcular. A precedência diz que em `f() + g()` a soma junta os
dois resultados, mas **não** diz qual função roda primeiro: a **ordem de
avaliação** dos operandos não é especificada, e cada compilador escolhe. Só
alguns pontos fixam a ordem: `&&`, `||`, `?:` e a vírgula avaliam o lado
esquerdo inteiro antes do direito, e uma função só começa depois de todos os
argumentos prontos.

Um **efeito colateral** é tudo que uma expressão muda além de produzir valor:
`i++` muda `i`, `x = 3` muda `x`, `printf` escreve na tela. Mudar a mesma
variável duas vezes, ou mudar e ler sem ordem garantida, na mesma expressão,
é **comportamento indefinido**: `i = i++`, `v[i] = i++` e
`printf("%d %d", i, i++)` não têm resposta certa. O programa pode dar
qualquer coisa.

O desenho mostra como o C monta a árvore de cada conta:
o operador de menor precedência fica na raiz e é o último a agir. Na
pegadinha do frete grátis, a raiz é o `?:`, e o `+` foi parar lá embaixo:

{{ideia}}

O programa faz as contas do carrinho e mostra cada agrupamento:

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

No fluxograma, o `?:` aparece como o que ele é: uma pergunta escondida dentro
da expressão. O que entra na pergunta depende só dos parênteses, e no `certo`
ela olha apenas o `compra`:


{{fluxograma}}

> [!WARNING]
> `i = i++` não "soma 1 e guarda", nem "guarda o antigo": é comportamento
> indefinido, e a pergunta "quanto vale `i`?" não tem resposta. Com `-Wall`, o
> gcc avisa:
>
> ```text
> warning: operation on 'i' may be undefined [-Wsequence-point]
> ```
>
> Ele também avisa `x & 3 == 3` ("suggest parentheses around comparison") e
> `a || b && c`. Mas **não** avisa `compra + compra >= 50 ? 0 : frete`. Na
> dúvida, ponha parênteses: eles não custam nada no programa pronto.

> [!TIP]
> **Por dentro do C:** o compilador transforma cada expressão numa árvore,
> como a do desenho, e gera instruções de baixo para cima. A precedência fixa
> o **formato** da árvore; a ordem em que ele visita os galhos é livre, e o gcc
> usa essa liberdade para guardar valores em registradores e economizar
> instruções. É por isso que o padrão não promete a ordem de `f() + g()`. Os
> pontos que fixam a ordem (`&&`, `||`, `?:`, `,` e o fim de cada instrução)
> viram, no código de máquina, um teste e um salto: o lado direito do `&&`
> nem chega a rodar quando o esquerdo dá 0.

> [!NOTE]
> **Pergunta para você:** quanto vale `x` depois de `int x = 10; x -= 2 * 3 - 1;`?
> E `1 + 2 << 1`, que o gcc avisa mas compila?

{{pratique}}
