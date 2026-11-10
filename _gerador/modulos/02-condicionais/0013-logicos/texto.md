## 0013 · Lógicos: E, OU, NÃO

Bilheteria do cinema. Paga meia quem é estudante **ou** tem 60 anos ou mais,
**e** a sessão **não** é pré-estreia. São três respostas de sim ou não,
ligadas por E, OU e NÃO.

Os **operadores lógicos** juntam comparações:

- `a && b` (**E**): verdade só se as duas forem verdade;
- `a || b` (**OU**): verdade se pelo menos uma for verdade;
- `!a` (**NÃO**): inverte. `!1` vale 0 e `!0` vale 1.

A **tabela-verdade** mostra todas as combinações. Como no 0012, o resultado é
um `int` 0 ou 1:

| `a` | `b` | `a && b` | `a \|\| b` | `!a` |
| --- | --- | --- | --- | --- |
| 0 | 0 | 0 | 0 | 1 |
| 0 | 1 | 0 | 1 | 1 |
| 1 | 0 | 0 | 1 | 0 |
| 1 | 1 | 1 | 1 | 0 |

Na escola, 18 ≤ idade ≤ 65. No C, intervalo é um E de duas comparações:
`idade >= 18 && idade <= 65`. `18 <= idade <= 65` compila, mas compara o 0 ou
1 da primeira parte com 65 (veja o 0012).

**Precedência**, da mais forte para a mais fraca: `!` (e o menos unário), os
aritméticos, os relacionais (`<` `>` `<=` `>=`), a igualdade (`==` `!=`), o
`&&` e por último o `||`. Por isso `x > 0 && x < 10` dispensa parênteses, e
`a || b && c` é `a || (b && c)`. Na dúvida, use parênteses: mostram a
intenção.

No **curto-circuito**, o C avalia da esquerda para a direita e **para assim
que sabe a resposta**, garantido pelo padrão. Em `a && b`, se `a` é falso, o
`b` nem é calculado. Em `a || b`, se `a` é verdade, o `b` é pulado. Isso
protege contas perigosas: `convidados != 0 && fatias / convidados > 3` nunca
divide por zero. Ponha à esquerda o teste mais barato ou o que mais dá falso.

As **leis de De Morgan** negam uma condição composta: o NÃO entra nos
parênteses e troca E por OU. `!(a && b)` é `!a || !b`, e `!(a || b)` é
`!a && !b`. "Não é (estudante ou idoso)" é "não é estudante e não é idoso".

No exemplo, uma pessoa de 67 anos, não estudante, numa sessão comum. O OU dá
verdade pela idade, o NÃO da pré-estreia dá verdade, e o E fecha com
meia-entrada:

{{ideia}}

A bilheteria em C:

```c
#include <stdbool.h>
#include <stdio.h>

int main(void) {
    int idade = 67;
    bool estudante = false;
    bool pre_estreia = false;

    // os parênteses são obrigatórios aqui: && vem antes de ||
    bool meia = (estudante || idade >= 60) && !pre_estreia;

    printf("Meia-entrada? %d\n", meia);
    printf("Ingresso: R$ %.2f\n", 40.0 - meia * 20.0);
    return 0;
}
// Saída:
// Meia-entrada? 1
// Ingresso: R$ 20.00
```

O C avalia como no fluxograma, uma pergunta de cada vez. Como `estudante` é
falso, olha a idade; se fosse verdade, pularia direto para a pré-estreia. É o
curto-circuito desenhado.

{{fluxograma}}

> [!WARNING]
> **`&` não é `&&`.** O `&` simples é o E **bit a bit** (assunto 0065): não tem
> curto-circuito e sua precedência é **menor** que a do `==`. Em
> `if (x & 1 == 0)`, o C calcula `x & (1 == 0)`, ou seja `x & 0`, **sempre
> 0**. O certo é `(x & 1) == 0` ou, mais claro, `x % 2 == 0`. O mesmo vale
> para `|` e `||`. O `-Wall` avisa: "suggest parentheses".

> [!NOTE]
> **Pergunta para você:** se a pessoa fosse estudante, a comparação
> `idade >= 60` seria feita? E se a sessão fosse pré-estreia, a idade mudaria
> alguma coisa? Siga o fluxograma e depois mude os valores no código acima.

{{pratique}}
