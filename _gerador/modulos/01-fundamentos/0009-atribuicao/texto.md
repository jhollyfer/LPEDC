## 0009 · Atribuição, ++ e --

O bilhete único tem R$ 20,00. Você recarrega R$ 30,00, pega dois ônibus de
R$ 4,40 e o validador conta as viagens. O saldo não é recalculado do zero:
é **atualizado** a partir do valor que já está lá.

No C, `=` significa "guarde o valor da direita na variável da esquerda", não
o "igual" da matemática. Por isso `saldo = saldo + 30.00` faz sentido: calcula
com o valor antigo e escreve o novo por cima. À esquerda só pode ficar algo
com endereço, uma variável; `30 = saldo` e `saldo + 1 = 5` não compilam.

Os **operadores compostos** são atalhos para atualizar uma variável:

| Atalho | Quer dizer | Com `x = 10` |
| --- | --- | --- |
| `x += 3` | `x = x + 3` | 13 |
| `x -= 3` | `x = x - 3` | 7 |
| `x *= 3` | `x = x * 3` | 30 |
| `x /= 3` | `x = x / 3` | 3 (divisão inteira!) |
| `x %= 3` | `x = x % 3` | 1 |

O composto age sobre **toda** a expressão da direita, como se estivesse entre
parênteses: `x *= y + 1` é `x = x * (y + 1)`, não `x * y + 1`.

Para somar ou tirar 1, há **`++`** e **`--`**. Sozinhos na linha, `viagens++` e
`++viagens` são iguais. A diferença aparece quando o valor é **usado** na
mesma expressão:

- **pós** (`x++`): a expressão vale o valor **antigo**, depois `x` aumenta;
- **pré** (`++x`): `x` aumenta primeiro, e a expressão vale o valor **novo**.

A atribuição também é uma expressão e vale o valor guardado. Ela associa **da
direita para a esquerda**: em `a = b = c = 7`, o C faz `c = 7` (que vale 7),
depois `b = 7` e por fim `a = 7`.

O saldo passa por quatro valores, cada um calculado a partir do anterior, na
mesma caixinha. As viagens sobem de um em um:

{{ideia}}

O bilhete único em C:

```c
#include <stdio.h>

int main(void) {
    double saldo = 20.00;
    int viagens = 0;

    saldo += 30.00;   // recarga: saldo = saldo + 30.00
    saldo -= 4.40;    // 1ª viagem
    viagens++;        // viagens = viagens + 1
    saldo -= 4.40;    // 2ª viagem
    viagens++;

    printf("Saldo: R$ %.2f depois de %d viagens\n", saldo, viagens);

    int antes = viagens++;   // pós: usa o 2, depois soma (viagens vira 3)
    int depois = ++viagens;  // pré: soma primeiro (vira 4), depois usa o 4
    printf("antes = %d, depois = %d, viagens = %d\n", antes, depois, viagens);
    return 0;
}
// Saída:
// Saldo: R$ 41.20 depois de 2 viagens
// antes = 2, depois = 4, viagens = 4
```

Cada atualização é um retângulo sobre as mesmas duas variáveis. No módulo 03,
esses passos viram um laço, com `+=` e `++` como acumulador e contador:

{{fluxograma}}

> [!WARNING]
> Nunca altere a mesma variável duas vezes na mesma expressão, nem altere e
> leia ao mesmo tempo. `i = i++;`, `x = x++ + ++x;` e
> `printf("%d %d", n++, n);` são **comportamento indefinido**: o padrão não
> define a ordem e cada compilador faz de um jeito. O `-Wall` avisa
> (`operation on 'i' may be undefined`). Use `++` e `--` sozinhos na linha ou
> com a variável aparecendo uma vez só.

> [!NOTE]
> **Pergunta para você:** com `int x = 5;`, quanto valem `y` e `x` depois de
> `int y = x++ * 2;`? E se fosse `++x * 2`? Responda e teste.

{{pratique}}
