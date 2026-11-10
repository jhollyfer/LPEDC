## 0004 · Constantes

A tarifa do ônibus aparece em dez lugares do sistema: letreiro, ida e volta,
recibo, relatório. Em janeiro ela sobe de R$ 4,40 para R$ 4,90. Com o valor
escrito à mão em cada lugar, alguém esquece um. O certo é escrevê-lo **uma
vez só**, com um nome.

Todo valor escrito direto no código é um **literal**, e o jeito de escrever
decide seu tipo:

| Literal | Tipo | Observação |
| --- | --- | --- |
| `101` | `int` | inteiro sem ponto |
| `4.90` | `double` | todo real é `double`, a não ser que... |
| `4.90f` | `float` | ...tenha o sufixo `f` |
| `5000000000LL` | `long long` | sufixos `L`, `LL`, `U` |
| `0x1F`, `017` | `int` | hexadecimal (31) e **octal** (15): zero à esquerda muda a base! |
| `1.5e3` | `double` | notação científica: 1,5 × 10³ = 1500 |
| `'A'` | `int` | um caractere: vale o código, 65 |
| `"A"` | texto | aspas duplas: `'A'` seguido do byte zero |

O C tem dois jeitos de dar nome a um valor. O **`#define`** é uma ordem para o
pré-processador: `#define TARIFA 4.90` faz um "localizar e substituir" antes de
o compilador ver o código, que só enxerga `4.90`. Por convenção, o nome vai em
MAIÚSCULAS, sem `=` e sem `;`.

O **`const`** cria uma variável de verdade (tipo, endereço, tamanho), mas
**só de leitura**: `const int linha = 101;`. Mudá-la dá erro de compilação, e
por isso o valor vem na declaração.

Dentro das aspas, a barra invertida inicia uma **sequência de escape**: `\n`
pula linha, `\t` é tabulação, `\"` põe aspas no texto, `\\` é a barra e `\0`
é o byte zero. Para mostrar `%` no `printf`, escreva `%%` (regra do
`printf`, não escape).

O pré-processador troca `TARIFA` por `4.90` e `EMPRESA` pelo nome da viação.
A `linha` é uma caixinha com cadeado: tem endereço, mas ninguém escreve nela:

{{ideia}}

O mesmo exemplo em C:

```c
#include <stdio.h>

#define TARIFA 4.90          // muda aqui, muda no programa todo
#define EMPRESA "Viação Sol"

int main(void) {
    const int linha = 101;   // variável só de leitura

    printf("%s\n", EMPRESA);
    printf("Linha %d \"Centro - Bairro\"\n", linha);
    printf("Tarifa: R$ %.2f\n", TARIFA);
    printf("Ida e volta: R$ %.2f\n", 2 * TARIFA); // o compilador vê 2 * 4.90
    return 0;
}
// Saída:
// Viação Sol
// Linha 101 "Centro - Bairro"
// Tarifa: R$ 4.90
// Ida e volta: R$ 9.80
```

A troca de texto acontece na compilação; o executável já nasce só com os
números:

{{fluxograma}}

> [!WARNING]
> O `#define` cola **exatamente** o texto que vem depois do nome. Com
> `#define TARIFA 4.90;`, a linha `printf("%.2f\n", 2 * TARIFA);` vira
> `printf("%.2f\n", 2 * 4.90;);` e não compila. Com `#define TARIFA = 4.90`,
> vira `2 * = 4.90`. O erro aparece na linha em que o nome é **usado**, não na
> do `#define`.

> [!TIP]
> O `#define` não ocupa memória e não tem tipo; a `const int linha` tem
> endereço (`&linha`) e `sizeof linha` vale 4. Literais também têm tamanho:
> `sizeof(4.90)` é 8, `sizeof(4.90f)` é 4, `sizeof('A')` é 4 (no C, `'A'` é
> `int`) e `sizeof("A")` é 2 (a letra e o byte zero).

> [!NOTE]
> **Pergunta para você:** o pré-processador troca `TARIFA` dentro das aspas?
> O que `printf("TARIFA\n");` mostra? Teste no programa acima.

{{pratique}}
