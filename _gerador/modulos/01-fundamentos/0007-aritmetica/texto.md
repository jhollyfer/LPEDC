## 0007 · Aritmética

- **Expressão**: operadores, operandos e parênteses. Em `24 / 5`, o `/` é o
  **operador** e 24 e 5 são os **operandos**. Toda expressão tem um valor
  (DEITEL; DEITEL, 2011, cap. 2).
- **Divisão inteira**: com **dois** operandos inteiros, o `/` joga fora a
  parte fracionária, sem arredondar. `7 / 2` dá 3 e `2 / 3` dá 0. Basta **um**
  lado real para a divisão ser real: `159.0 / 5` dá 31,8
  (DEITEL; DEITEL, 2011, cap. 2).
- **Resto (`%`)**: o que sobra da divisão inteira; só com inteiros. Sempre vale
  `(a / b) * b + a % b == a`. Separa dígitos (`2026 % 10` é 6) e testa
  paridade (`n % 2`) (DEITEL; DEITEL, 2011, cap. 2).
- **Negativos**: desde o C99, a divisão corta em direção ao zero (`-7 / 2` dá
  -3) e o resto segue o sinal do dividendo (`-7 % 3` dá -1)
  (FEOFILOFF, 2009, ap. C).
- **Precedência**: `*`, `/` e `%` antes de `+` e `-`. No empate, da esquerda
  para a direita (**associatividade**): `100 / 10 / 2` é 5. Parênteses mandam
  em tudo (BACKES, 2013, cap. 3).
- **Potência**: o C não tem operador para ela (`^` é outra coisa, assunto
  0065). Use `pow` (0010) ou `x * x` (DEITEL; DEITEL, 2011, cap. 2).
- **Divisão por zero**: com inteiros, derruba o programa
  (`Floating point exception`); com `double`, dá `inf` (ISO/IEC, 2018).

| Operador | Faz | Exemplo | Resultado |
| --- | --- | --- | --- |
| `+` `-` | soma, subtração | `24 - 4` | `20` |
| `*` | multiplicação | `3 * 8` | `24` |
| `/` | divisão | `24 / 5` | `4` (!) |
| `%` | resto da divisão | `24 % 5` | `4` |

> [!WARNING]
> Com `int a = 7, b = 8;`, `double media = (a + b) / 2;` guarda **7.0**: a
> divisão é entre dois `int` **antes** de ir para o `double`. Escreva
> `(a + b) / 2.0`. E `a + b / 2` divide só o `b`.

{{exemplo}}

Cinco amigos dividem três pizzas de 8 fatias e uma conta de R$ 159. O `/`
conta as rodadas completas de fatias e o `%` as que sobram:

{{ideia}}

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

Cada conta é um retângulo, e a ordem importa: `cada` e `sobra` dependem de
`fatias`:

{{fluxograma}}
