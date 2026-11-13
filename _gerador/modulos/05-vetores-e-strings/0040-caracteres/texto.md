## 0040 · Caracteres

- **Caractere é número**: o `char` é um inteiro de 1 byte, e cada símbolo tem
  um código na **tabela ASCII**. `'A'` e `65` são o mesmo valor (DEITEL;
  DEITEL, 2011, cap. 8).
- **`%c` e `%d`**: o `printf` mostra o símbolo ou o código. Como é número, dá
  para calcular: `'a' + 1` é `'b'` e `c - '0'` transforma `'7'` em 7 (BACKES,
  2013, cap. 7).
- **`<ctype.h>`**: testes (`isalpha`, `isdigit`, `isalnum`, `isspace`,
  `isupper`, `islower`, `ispunct`) e conversões (`toupper`, `tolower`). O que
  não é letra volta igual (DEITEL; DEITEL, 2011, cap. 8).
- **Verdadeiro é não zero**: os testes não devolvem necessariamente 1.
  Escreva `if (isdigit(c))`, nunca `== 1` (LINUX MAN-PAGES PROJECT, s.d.).
- **`getchar()`**: lê um caractere e devolve um **`int`**, o código ou
  **`EOF`** (negativo, fim da entrada). Guarde num `int` (DEITEL; DEITEL, 2011,
  cap. 8).
- **Acento**: o "ç" em UTF-8 ocupa dois bytes e não cabe num `char`. Para o
  `ctype.h`, use `toupper((unsigned char) c)` (CPPREFERENCE, s.d.).

| símbolos | códigos | repare |
| --- | --- | --- |
| `'0'` a `'9'` | 48 a 57 | em ordem: `'7' - '0'` = 7 |
| `'A'` a `'Z'` | 65 a 90 | em ordem alfabética |
| `'a'` a `'z'` | 97 a 122 | cada minúscula = maiúscula + 32 |

> [!WARNING]
> Letra não é "tudo entre `'A'` e `'z'`": no meio ficam `[ \ ] ^ _` e a crase.
> Use `isalpha(c)`. E `'0'` (código 48) não é `0` (o caractere nulo `'\0'`).

{{exemplo}}

A placa `bra2e19` vira `BRA2E19`: o `toupper` troca cada minúscula pela
maiúscula, 32 posições antes na tabela, e os dígitos passam sem mudar:

{{ideia}}

```c
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define TAM 7

int main(void) {
    // placa Mercosul: letra letra letra número letra número número
    char placa[TAM] = {'b', 'r', 'a', '2', 'e', '1', '9'};
    bool valida = true;

    for (int i = 0; i < TAM; i++) {
        char antes = placa[i];
        placa[i] = (char) toupper(placa[i]);
        printf("%c (%3d) -> %c (%3d)\n", antes, antes, placa[i], placa[i]);

        // posições 3, 5 e 6 são dígitos; as outras, letras
        bool deve_ser_digito = (i == 3 || i == 5 || i == 6);
        if (deve_ser_digito && !isdigit(placa[i])) {
            valida = false;
        }
        if (!deve_ser_digito && !isalpha(placa[i])) {
            valida = false;
        }
    }

    printf("Placa: ");
    for (int i = 0; i < TAM; i++) {
        putchar(placa[i]);
    }
    printf(" -> %s\n", valida ? "válida" : "inválida");
    return 0;
}
// Saída:
// b ( 98) -> B ( 66)
// r (114) -> R ( 82)
// a ( 97) -> A ( 65)
// 2 ( 50) -> 2 ( 50)
// e (101) -> E ( 69)
// 1 ( 49) -> 1 ( 49)
// 9 ( 57) -> 9 ( 57)
// Placa: BRA2E19 -> válida
```

O vetor `placa` ainda não é string: falta o marcador de fim (próximo assunto).
Uma posição errada invalida a placa, mas o laço segue até o fim:

{{fluxograma}}
