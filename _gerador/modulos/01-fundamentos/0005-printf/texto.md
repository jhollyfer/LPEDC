## 0005 · printf

- **String de formato**: o primeiro argumento do `printf`. É um texto com
  **especificadores** (`%d`, `%f`...), buracos que os outros argumentos
  preenchem **na ordem**, um para cada `%` (BACKES, 2013, cap. 2).
- **Saída padrão** (`stdout`): onde o `printf` escreve. O `fprintf` do
  módulo 09 usa o mesmo formato para escrever num arquivo
  (DEITEL; DEITEL, 2011, cap. 9).
- **Forma completa**: `%[flags][largura][.precisão]letra`
  (KERRISK, s.d.).
- **Largura**: o **mínimo** de caracteres, alinhado à direita. `%6d` de 42 dá
  `    42`; valor maior sai inteiro, nada é cortado
  (DEITEL; DEITEL, 2011, cap. 9).
- **Flags**: `-` alinha à esquerda, `0` completa com zeros, `+` mostra sempre
  o sinal (DEITEL; DEITEL, 2011, cap. 9).
- **Precisão**: em real, as casas decimais (`%.2f`); em texto, o máximo de
  caracteres (`%.3s` de `"Brasil"` dá `Bra`). Ela **arredonda só na tela**: a
  variável não muda (DEITEL; DEITEL, 2011, cap. 9).
- **`float` vira `double`** na passagem para o `printf`, por isso `%f` serve
  para os dois. A largura conta **bytes**: o `ã` ocupa 2 no UTF-8
  (KERRISK, s.d.).

| Especificador | Mostra | Exemplo | Sai |
| --- | --- | --- | --- |
| `%d` | `int` em decimal | `printf("%d", 42)` | `42` |
| `%u`, `%ld`, `%lld` | `unsigned`, `long`, `long long` | `printf("%ld", 9L)` | `9` |
| `%f` | `double` ou `float` | `printf("%f", 2.5)` | `2.500000` |
| `%e`, `%g` | real em notação científica / o mais curto | `printf("%e", 1500.0)` | `1.500000e+03` |
| `%c` | um caractere | `printf("%c", 'A')` | `A` |
| `%s` | um texto | `printf("%s", "Pix")` | `Pix` |
| `%x`, `%X`, `%o` | inteiro em hexa e em octal | `printf("%X", 255)` | `FF` |
| `%p` | um endereço | `printf("%p", (void *)&n)` | `0x7ffe...` |
| `%zu` | o resultado do `sizeof` | `printf("%zu", sizeof n)` | `4` |
| `%%` | o próprio `%` | `printf("10%%")` | `10%` |

> [!WARNING]
> O `printf` **confia** no formato. Se o especificador não combina com o tipo,
> lê os bytes do jeito errado: `printf("%d", 9.90)` mostra lixo. O `-Wall`
> avisa (`format '%d' expects argument of type 'int'`). E no `printf` não vai `&`.

{{exemplo}}

O cupom do mercado sai com colunas alinhadas. Na linha do arroz, `%-10s`
reserva 10 casas para o nome, `%3d` reserva 3 para a quantidade e `%9.2f`
reserva 9 para o total, com 2 decimais:

{{ideia}}

```c
#include <stdio.h>

int main(void) {
    printf("%-10s %3s %9s\n", "Item", "Qtd", "Total");
    printf("%-10s %3d %9.2f\n", "Arroz 5kg", 2, 51.80);
    printf("%-10s %3d %9.2f\n", "Leite", 12, 71.88);
    printf("%-10s %3d %9.2f\n", "Banana", 1, 7.49);
    printf("%-10s %13.2f\n", "TOTAL", 131.17);
    return 0;
}
// Saída:
// Item       Qtd     Total
// Arroz 5kg    2     51.80
// Leite       12     71.88
// Banana       1      7.49
// TOTAL             131.17
```

Cada `printf` é uma saída com o mesmo formato. Para mudar uma coluna, troque
um número em cada linha:

{{fluxograma}}
