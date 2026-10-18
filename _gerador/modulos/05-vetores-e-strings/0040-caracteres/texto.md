## 0040 · Caracteres

No app do Detran, você digita a placa do carro em minúsculas: `bra2e19`. O app
mostra `BRA2E19` e diz que o formato está certo: três letras, um número, uma
letra, dois números. Como um programa sabe que `b` é letra, que `2` é dígito e
qual é a maiúscula de `b`?

Porque, para o computador, **caractere é número**. O tipo `char` é um inteiro
de 1 byte, e cada símbolo tem um código combinado na **tabela ASCII**: `'A'` é
65, `'B'` é 66, ..., `'a'` é 97, `'0'` é 48, o espaço é 32, o `'\n'` é 10. As
aspas simples são só um jeito legível de escrever o número: `'A'` e `65` são o
mesmo valor.

| símbolos | códigos | repare |
| --- | --- | --- |
| `'0'` a `'9'` | 48 a 57 | em ordem: `'7' - '0'` = 7 |
| `'A'` a `'Z'` | 65 a 90 | em ordem alfabética |
| `'a'` a `'z'` | 97 a 122 | cada minúscula = maiúscula + 32 |

O que decide se você vê a letra ou o número é o `printf`: `%c` mostra o
símbolo, `%d` mostra o código. Como é número, dá para fazer conta e comparar:
`'a' + 1` é `'b'`, `c >= 'A' && c <= 'Z'` pergunta se é maiúscula, e
`c - '0'` transforma o dígito `'7'` no número 7. Não há função de conversão
nenhuma: o caractere já é o número.

Para não decorar a tabela, o `<ctype.h>` traz funções prontas:

- **testes**: `isalpha` (letra), `isdigit` (dígito), `isalnum` (letra ou
  dígito), `isspace` (espaço, `\t`, `\n`...), `isupper`, `islower`, `ispunct`;
- **conversões**: `toupper` e `tolower`. O que não é letra volta igual:
  `toupper('2')` é `'2'`.

Os testes devolvem **diferente de zero** para verdadeiro, não necessariamente
1. Escreva `if (isdigit(c))`, nunca `if (isdigit(c) == 1)`.

Para ler um caractere por vez do teclado, existe o `getchar()`. Ele devolve um
**`int`**: o código do caractere ou **`EOF`**, um valor negativo que avisa que
a entrada acabou (Ctrl+D no Linux). Guarde sempre num `int`. O exemplo A080
conta letras e dígitos assim, até o Enter.

Vamos ver na prática. A placa está num vetor de 7 `char`. O `toupper` troca
cada minúscula pela maiúscula, que fica 32 posições antes na tabela. Os
dígitos passam sem mudar:

{{ideia}}

O código mostra cada caractere com `%c` e `%d`, antes e depois, e confere o
formato com `isdigit` e `isalpha`:

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

O `putchar` mostra um caractere só, sem formatação. O vetor `placa` ainda não
é uma **string**: falta o marcador de fim que o `%s` precisa. Isso é o
próximo assunto.

Repara no fluxograma: para cada posição, converte e pergunta o que ela deveria
ser. Basta uma posição errada para a placa ficar inválida, e o laço segue até
o fim mesmo assim:

{{fluxograma}}

> [!WARNING]
> **Letra não é "tudo entre `'A'` e `'z'`".** Entre o `'Z'` (90) e o `'a'`
> (97) moram `[ \ ] ^ _` e a crase. O teste `c >= 'A' && c <= 'z'` aceita
> `_` como letra. Use `isalpha(c)`, ou os dois intervalos separados. E não
> confunda `'0'` (o caractere zero, código 48) com `0` (o número zero, que é o
> caractere nulo `'\0'`).

> [!TIP]
> **Por dentro do C:** um `char` é só 1 byte, e o C nem garante se ele tem
> sinal: no PC (x86) ele vai de -128 a 127; em muitos ARM, de 0 a 255. ASCII
> usa só de 0 a 127. E o "ç"? Em UTF-8, que é o que o seu terminal usa, ele
> ocupa **dois** bytes (`0xC3 0xA7`) e não cabe num `char`. Num `char` com
> sinal, esses bytes viram números negativos, e passar um negativo (que não
> seja `EOF`) para as funções do `ctype.h` é comportamento indefinido. Por isso
> o jeito blindado é `toupper((unsigned char) c)`. Com o `int` que vem do
> `getchar`, você já está seguro: ele devolve o byte como valor de 0 a 255.

> [!NOTE]
> **Pergunta para você:** o que `printf("%c %d\n", 'A' + 2, 'z' - 'a');`
> mostra? E `printf("%d\n", '9' - '0' + 1);`?

{{pratique}}
