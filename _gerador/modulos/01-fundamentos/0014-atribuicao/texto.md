## 0014 · Atribuição, ++ e --

O bilhete único tem R$ 20,00. Você recarrega R$ 30,00, pega dois ônibus de
R$ 4,40 e o validador conta as viagens. O saldo não é recalculado do zero a
cada passo: ele é **atualizado**, somando ou tirando do valor que já está lá.

O `=` do C não é o "igual" da matemática: é "guarde o valor da direita na
variável da esquerda". Por isso `saldo = saldo + 30.00` faz sentido: calcula
com o valor antigo e escreve o novo por cima. Do lado esquerdo só pode ficar
algo que tem endereço, uma variável; `30 = saldo` e `saldo + 1 = 5` não
compilam.

Atualizar uma variável é tão comum que tem atalho, os **operadores
compostos**:

| Atalho | Quer dizer | Com `x = 10` |
| --- | --- | --- |
| `x += 3` | `x = x + 3` | 13 |
| `x -= 3` | `x = x - 3` | 7 |
| `x *= 3` | `x = x * 3` | 30 |
| `x /= 3` | `x = x / 3` | 3 (divisão inteira!) |
| `x %= 3` | `x = x % 3` | 1 |

O operador composto age sobre **toda** a expressão da direita, como se ela
estivesse entre parênteses: `x *= y + 1` é `x = x * (y + 1)`, e não
`x * y + 1`.

Para somar ou tirar 1 há atalhos ainda menores: **`++`** e **`--`**. Numa
linha sozinha, `viagens++` e `++viagens` fazem a mesma coisa. A diferença
aparece quando o valor é **usado** na mesma expressão:

- **pós** (`x++`): a expressão vale o valor **antigo**, e depois `x` aumenta;
- **pré** (`++x`): `x` aumenta primeiro, e a expressão vale o valor **novo**.

E um detalhe que explica muita coisa: a atribuição também é uma expressão, e
vale o valor guardado. Por isso `a = b = c = 7` funciona: o C faz `c = 7`,
que vale 7, depois `b = 7` e por fim `a = 7`.

Vamos ver na prática. O saldo passa por quatro valores, cada um calculado a
partir do anterior, na mesma caixinha. As viagens sobem de um em um:

{{ideia}}

O mesmo exemplo em C:

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

Repara no fluxograma: cada atualização é um retângulo, e todos mexem nas
mesmas duas variáveis. No módulo 03 esses passos repetidos vão virar uma
repetição; o `+=` e o `++` são o coração de todo contador e acumulador:

{{fluxograma}}

> [!WARNING]
> Nunca altere a mesma variável duas vezes na mesma expressão, nem altere e
> leia ao mesmo tempo. `i = i++;`, `x = x++ + ++x;` e
> `printf("%d %d", n++, n);` são **comportamento indefinido**: o padrão não
> diz em que ordem as partes acontecem, e cada compilador faz de um jeito. O
> `-Wall` avisa
> (`operation on 'i' may be undefined`). Regra prática: use `++` e `--`
> sozinhos na linha, ou num lugar onde a variável apareça uma vez só.

> [!TIP]
> **Por dentro do C:** `x = x + 1`, `x += 1`, `x++` e `++x`, sozinhos numa
> linha, viram **a mesma instrução** de máquina (`add` ou `inc`). Os atalhos
> não deixam o programa mais rápido; eles existem para você escrever o nome
> da variável uma vez só, o que evita errar quando o nome é comprido. A
> diferença entre pré e pós é só qual valor a expressão entrega: no pós, o
> compilador guarda uma cópia do valor antigo antes de somar.

> [!NOTE]
> **Pergunta para você:** com `int x = 5;`, quanto valem `y` e `x` depois de
> `int y = x++ * 2;`? E se fosse `++x * 2`? Responda e teste.

{{pratique}}
