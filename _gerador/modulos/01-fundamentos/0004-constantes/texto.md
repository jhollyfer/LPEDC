## 0004 · Constantes

- **Literal**: valor escrito direto no código. A forma de escrever decide o
  tipo: `101` é `int`, `4.90` é `double`, `4.90f` é `float`
  (BACKES, 2013, cap. 2).
- **Sufixos e bases**: `L`, `LL` e `U` mudam o tipo do inteiro; `0x1F` é
  hexadecimal e `017` é **octal** (zero à esquerda muda a base); `1.5e3` é
  notação científica (KERNIGHAN; RITCHIE, 1988, cap. 2).
- **`'A'` e `"A"`**: aspas simples dão um caractere, que vale o código (65);
  aspas duplas dão um texto, a letra mais o byte zero (DEITEL; DEITEL, 2011).
- **`#define`**: ordem ao pré-processador. Faz um "localizar e substituir"
  antes da compilação, sem tipo e sem memória. Nome em MAIÚSCULAS, sem `=` e
  sem `;` (BACKES, 2013, cap. 2).
- **`const`**: variável de verdade (tipo, endereço, tamanho), mas só de
  leitura. Mudá-la é erro de compilação, então o valor vem na declaração
  (BACKES, 2013, cap. 2).
- **Sequência de escape**: barra invertida dentro das aspas. `\n` pula linha,
  `\t` tabula, `\"` põe aspas, `\\` é a barra, `\0` é o byte zero. Para `%`
  no `printf`, use `%%` (DEITEL; DEITEL, 2011, cap. 9).

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

> [!WARNING]
> O `#define` cola **exatamente** o texto que vem depois do nome. Com
> `#define TARIFA 4.90;`, `2 * TARIFA` vira `2 * 4.90;` e não compila. O erro
> aparece na linha em que o nome é **usado**, não na do `#define`.

{{exemplo}}

A tarifa do ônibus aparece em vários lugares do sistema e muda todo ano: fica
escrita uma vez só, com nome. O pré-processador troca `TARIFA` e `EMPRESA`
pelos valores; a `linha` é uma caixinha com cadeado:

{{ideia}}

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
