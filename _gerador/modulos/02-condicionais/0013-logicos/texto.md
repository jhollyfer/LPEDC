## 0013 · Lógicos: E, OU, NÃO

Bilheteria do cinema. A regra da meia-entrada diz: paga meia quem é
estudante **ou** tem 60 anos ou mais, **e** a sessão **não** é pré-estreia.
Uma pergunta só não resolve. São três respostas de sim ou não, costuradas com
E, OU e NÃO.

Os **operadores lógicos** juntam comparações:

- `a && b` (**E**): verdade só se as duas forem verdade;
- `a || b` (**OU**): verdade se pelo menos uma for verdade;
- `!a` (**NÃO**): inverte. `!1` vale 0 e `!0` vale 1.

A **tabela-verdade** mostra todas as combinações. Como no assunto 0012, o
resultado é sempre um `int` 0 ou 1:

| `a` | `b` | `a && b` | `a \|\| b` | `!a` |
| --- | --- | --- | --- | --- |
| 0 | 0 | 0 | 0 | 1 |
| 0 | 1 | 0 | 1 | 1 |
| 1 | 0 | 0 | 1 | 0 |
| 1 | 1 | 1 | 1 | 0 |

Na escola você escrevia 18 ≤ idade ≤ 65. No C, intervalo é sempre um E de duas
comparações: `idade >= 18 && idade <= 65`. Escrever `18 <= idade <= 65` compila,
mas compara o 0 ou 1 da primeira parte com 65 (lembra do 0012?).

**Precedência**, da mais forte para a mais fraca: `!` (junto com o menos
unário), depois os aritméticos, os relacionais (`<` `>` `<=` `>=`), a
igualdade (`==` `!=`), o `&&` e por último o `||`. Por isso
`x > 0 && x < 10` dispensa parênteses. Mas `a || b && c` é `a || (b && c)`:
o E vem antes do OU. Na dúvida, ponha parênteses. Eles não custam nada e
contam a sua intenção.

E tem o **curto-circuito**. O C avalia da esquerda para a
direita e **para assim que sabe a resposta**. Em `a && b`, se `a` é falso, o
`b` nem é calculado: falso E qualquer coisa é falso. Em `a || b`, se `a` é
verdade, o `b` é pulado. Isso protege contas perigosas:
`convidados != 0 && fatias / convidados > 3` nunca divide por zero.

Por fim, as **leis de De Morgan**, para negar uma condição composta: o NÃO
entra nos parênteses e troca E por OU. `!(a && b)` é `!a || !b`, e
`!(a || b)` é `!a && !b`. "Não é (estudante ou idoso)" é o mesmo que "não é
estudante e não é idoso".

Vamos ver na prática. Uma pessoa de 67 anos, que não é estudante, numa sessão
comum. O OU dá verdade pela idade, o NÃO da pré-estreia dá verdade, e o E
fecha com meia-entrada:

{{ideia}}

O mesmo exemplo em C:

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

Repara no fluxograma: é assim que o C avalia a expressão, uma pergunta de cada
vez. Como `estudante` é falso, ele precisa olhar a idade. Se fosse verdade,
pularia direto para a pré-estreia: isso é o curto-circuito desenhado:

{{fluxograma}}

> [!WARNING]
> **`&` não é `&&`.** O `&` simples é o E **bit a bit** (assunto 0065): não tem
> curto-circuito e, pior, tem precedência **menor** que o `==`. Quem escreve
> `if (x & 1 == 0)` para testar se `x` é par ganha `x & (1 == 0)`, que é
> `x & 0`, que é **sempre 0**. O certo é `(x & 1) == 0` ou, mais claro,
> `x % 2 == 0`. O mesmo vale para `|` e `||`. O `-Wall` avisa: "suggest
> parentheses". Leia os avisos.

> [!TIP]
> **Por dentro do C:** o `&&` e o `||` não viram uma instrução de "E". Viram
> **saltos**. `a && b` é compilado como "calcula `a`; se deu zero, pula para o
> resultado 0; senão, calcula `b`". É literalmente o fluxograma acima, e é por
> isso que o curto-circuito é garantido pelo padrão do C. Uma consequência
> prática: em `a && b`, ponha à esquerda o teste mais barato ou o que mais
> costuma dar falso. Ele poupa o resto.

> [!NOTE]
> **Pergunta para você:** se a pessoa fosse estudante, a comparação
> `idade >= 60` seria feita? E se a sessão fosse pré-estreia, a idade mudaria
> alguma coisa? Siga o fluxograma e depois mude os valores no código acima.

{{pratique}}
