## 0013 · Lógicos: E, OU, NÃO

- **Operadores lógicos**: `a && b` (**E**) é verdade só se as duas forem;
  `a || b` (**OU**) é verdade se pelo menos uma for; `!a` (**NÃO**) inverte. O
  resultado é um `int` 0 ou 1 (DEITEL; DEITEL, 2011, cap. 4).
- **Intervalo**: 18 ≤ idade ≤ 65 vira `idade >= 18 && idade <= 65`. Escrever
  `18 <= idade <= 65` compila, mas compara o 0 ou 1 da primeira parte com 65
  (BACKES, 2013, cap. 3).
- **Precedência**, da mais forte para a mais fraca: `!`, aritméticos,
  relacionais, igualdade, `&&` e por último `||`. `a || b && c` é
  `a || (b && c)` (KERNIGHAN; RITCHIE, 1988, cap. 2).
- **Curto-circuito**: o C avalia da esquerda para a direita e **para assim que
  sabe a resposta**. Em `a && b`, se `a` é falso, `b` nem é calculado; em
  `a || b`, se `a` é verdade, `b` é pulado. Assim,
  `n != 0 && total / n > 3` nunca divide por zero (DEITEL; DEITEL, 2011, cap. 4).
- **De Morgan**: o NÃO entra nos parênteses e troca E por OU. `!(a && b)` é
  `!a || !b`, e `!(a || b)` é `!a && !b` (DEITEL; DEITEL, 2011, cap. 4).

| `a` | `b` | `a && b` | `a \|\| b` | `!a` |
| --- | --- | --- | --- | --- |
| 0 | 0 | 0 | 0 | 1 |
| 0 | 1 | 0 | 1 | 1 |
| 1 | 0 | 0 | 1 | 0 |
| 1 | 1 | 1 | 1 | 0 |

> [!WARNING]
> **`&` não é `&&`.** O `&` é o E **bit a bit** (0065): sem curto-circuito e
> com precedência **menor** que a do `==`. `if (x & 1 == 0)` vira
> `x & (1 == 0)`, sempre 0. O `-Wall` avisa: "suggest parentheses".

{{exemplo}}

No cinema, paga meia quem é estudante **ou** tem 60 anos ou mais, **e** a
sessão **não** é pré-estreia. Para uma pessoa de 67 anos, não estudante, numa
sessão comum, o OU dá verdade pela idade, o NÃO dá verdade e o E fecha com
meia-entrada:

{{ideia}}

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

O C pergunta uma coisa de cada vez: como `estudante` é falso, olha a idade; se
fosse verdade, pularia direto para a pré-estreia. É o curto-circuito
desenhado:

{{fluxograma}}
