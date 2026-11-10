## 0007 · Aritmética

Sexta à noite, cinco amigos pedem três pizzas de 8 fatias. São 24 fatias:
quantas cada um come e quantas sobram? E a conta de R$ 159, quanto cada um
paga? Isso é **processamento**: calcular, com o que entrou, o que vai sair.

Em `24 / 5`, o `/` é o **operador** e 24 e 5 são os **operandos**. Operadores,
operandos e parênteses formam uma **expressão**, e toda expressão tem um
valor. Os operadores aritméticos:

| Operador | Faz | Exemplo | Resultado |
| --- | --- | --- | --- |
| `+` `-` | soma, subtração | `24 - 4` | `20` |
| `*` | multiplicação | `3 * 8` | `24` |
| `/` | divisão | `24 / 5` | `4` (!) |
| `%` | resto da divisão | `24 % 5` | `4` |

A pegadinha está no `/`. Com **dois** operandos inteiros, a divisão é
**inteira**: o resultado é inteiro e a parte fracionária é jogada fora, sem
arredondar. `24 / 5` dá 4, `7 / 2` dá 3, `2 / 3` dá 0. Basta **um** lado ser
real para a divisão ser real: `159.0 / 5` dá 31,8.

O **`%`** (módulo) devolve o resto da divisão inteira e só funciona com
inteiros. `24 / 5` diz quantas vezes o 5 cabe no 24, e `24 % 5` diz o que
sobrou; sempre vale `(a / b) * b + a % b == a`. Serve para separar dígitos
(`2026 % 10` é 6), converter segundos em minutos e testar paridade (`n % 2` é
0 se `n` é par).

A **precedência** é a da escola: `*`, `/` e `%` antes de `+` e `-`. O empate
se resolve da esquerda para a direita (**associatividade**): `100 / 10 / 2` é
`(100 / 10) / 2`, que dá 5. Parênteses mandam em tudo e deixam a intenção
clara. O C não tem operador de potência (`^` é outra coisa, assunto 0065); use
`pow` (assunto 0010) ou multiplique: `x * x`.

As 24 fatias são divididas entre os cinco, quatro para cada um. O `/` conta
as rodadas completas e o `%` as fatias que sobram:

{{ideia}}

A divisão das fatias em C:

```c
#include <stdio.h>

int main(void) {
    int pizzas = 3;
    int fatias = pizzas * 8;      // 24
    int amigos = 5;

    int cada = fatias / amigos;   // divisão inteira: 4
    int sobra = fatias % amigos;  // resto: 4

    printf("%d fatias para %d amigos\n", fatias, amigos);
    printf("Cada um come %d, sobram %d\n", cada, sobra);

    double conta = 159.00;
    printf("Cada um paga R$ %.2f\n", conta / amigos); // real / int: divisão real
    printf("Com inteiros: R$ %d\n", 159 / amigos);    // int / int: corta o resto
    return 0;
}
// Saída:
// 24 fatias para 5 amigos
// Cada um come 4, sobram 4
// Cada um paga R$ 31.80
// Com inteiros: R$ 31
```

Cada conta é um retângulo de processamento, e a ordem importa: `cada` e
`sobra` dependem de `fatias`:

{{fluxograma}}

> [!WARNING]
> Com `int a = 7, b = 8;`, a linha `double media = (a + b) / 2;` guarda
> **7.0**, não 7,5. A divisão é entre dois `int` **antes** de ir para o
> `double`, e os decimais já se perderam. Escreva `(a + b) / 2.0`. Cuidado
> também com a precedência: `a + b / 2` divide só o `b`, e `1 / 2 * x` dá
> sempre zero.

> [!TIP]
> Desde o C99, a divisão inteira corta em direção ao zero: `-7 / 2` dá -3, e o
> resto tem o sinal do dividendo: `-7 % 3` dá -1. Dividir **inteiro por zero**
> derruba o programa (`Floating point exception`); com `double`, o resultado
> é `inf`.

> [!NOTE]
> **Pergunta para você:** quanto vale `2 + 3 * 4 % 5`? Resolva na mão, na
> ordem da precedência, e depois confira com um `printf`.

{{pratique}}
