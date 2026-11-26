## 0013 · Lógicos: E, OU, NÃO

Uma comparação sozinha responde uma pergunta. Muitas regras da vida real
dependem de várias ao mesmo tempo: pode dirigir quem tem 18 anos **e** tem
carteira; ganha frete grátis quem é assinante **ou** comprou acima de
R$ 100. Para juntar comparações numa resposta só, o C tem os operadores
lógicos.

Pense na bilheteria do cinema. Paga meia quem é estudante **ou** tem 60
anos ou mais, **e** a sessão **não** é pré-estreia. São três respostas de
sim ou não, ligadas pelas palavras E, OU e NÃO. A atendente não pensa nessas
palavras, mas aplica cada uma delas toda vez que vende um ingresso.

Os **operadores lógicos** do C são esses três (DEITEL; DEITEL, 2011, cap.
4). O **E**, escrito `a && b`, é verdade só quando as duas partes são
verdade. O **OU**, `a || b`, é verdade quando pelo menos uma parte é
verdade. O **NÃO**, `!a`, inverte: `!1` vale 0 e `!0` vale 1. Como nas
comparações do 0012, o resultado é um `int` que vale 0 ou 1.

A **tabela-verdade** reúne todas as combinações possíveis de `a` e `b` e o
resultado de cada operador. Vale a pena conferir uma linha de cada vez:
com `a` falso e `b` verdadeiro, o E dá 0, porque falta uma parte, e o OU dá
1, porque uma basta.

| `a` | `b` | `a && b` | `a \|\| b` | `!a` |
| --- | --- | --- | --- | --- |
| 0 | 0 | 0 | 0 | 1 |
| 0 | 1 | 0 | 1 | 1 |
| 1 | 0 | 0 | 1 | 0 |
| 1 | 1 | 1 | 1 | 0 |

O uso mais comum do E é o intervalo. Na matemática você escreve
18 ≤ idade ≤ 65; no C, o intervalo é um E de duas comparações:
`idade >= 18 && idade <= 65` (BACKES, 2013, cap. 3). Escrever
`18 <= idade <= 65` compila, mas faz outra coisa: compara o 0 ou 1 da
primeira parte com 65, que é sempre menor. Com idade 67, o resultado é 1.

Quando a expressão mistura vários operadores, vale a **precedência**, da
mais forte para a mais fraca: o `!` (junto com o menos de `-x`), os
aritméticos, os relacionais (`<`, `>`, `<=`, `>=`), a igualdade (`==`,
`!=`), o `&&` e, por último, o `||` (KERNIGHAN; RITCHIE, 1988, cap. 2).
Por isso `x > 0 && x < 10` dispensa parênteses: as comparações acontecem
antes do E. E `a || b && c` é lido como `a || (b && c)`. Na dúvida, ponha
parênteses; eles também mostram a intenção para quem lê.

O C avalia `&&` e `||` da esquerda para a direita e **para assim que sabe a
resposta**. Isso se chama **curto-circuito**, e o padrão garante esse
comportamento (DEITEL; DEITEL, 2011, cap. 4). Em `a && b`, se `a` é falso,
o resultado já é falso e o `b` nem é calculado. Em `a || b`, se `a` é
verdade, o resultado já é verdade e o `b` é pulado. Isso protege contas
perigosas: em `n != 0 && total / n > 3`, a divisão só acontece quando `n`
não é zero. Também economiza trabalho; ponha à esquerda o teste mais barato
ou o que mais dá falso.

Às vezes você precisa negar uma condição inteira. As **leis de De Morgan**
dizem como: o NÃO entra nos parênteses e troca E por OU. `!(a && b)` é o
mesmo que `!a || !b`, e `!(a || b)` é o mesmo que `!a && !b` (DEITEL;
DEITEL, 2011, cap. 4). Em palavras: "não é (estudante ou idoso)" é "não é
estudante e não é idoso". A troca do E pelo OU é o ponto que mais se
esquece.

> [!WARNING]
> **`&` não é `&&`.** O `&` é o E **bit a bit** (0065): sem curto-circuito
> e com precedência **menor** que a do `==`. `if (x & 1 == 0)` vira
> `x & (1 == 0)`, sempre 0. O certo é `(x & 1) == 0` ou `x % 2 == 0`. O
> `-Wall` avisa: "suggest parentheses".

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
