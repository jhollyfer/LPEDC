## 0040 · Caracteres

No app do Detran, você digita a placa em minúsculas, `bra2e19`, e ele mostra
`BRA2E19` e confere o formato: três letras, um dígito, uma letra, dois
dígitos. Para isso o programa precisa saber que `b` é letra, que `2` é dígito
e qual é a maiúscula de `b`. Antes de juntar caracteres em textos, vale
entender o que um caractere é para o computador.

A resposta curta: **caractere é número**. O tipo `char` guarda um inteiro de
1 byte, e cada símbolo tem um código combinado numa tabela, a **tabela
ASCII**. É como o número de chamada de uma turma: a professora fala "17" e
todo mundo sabe quem é. Na ASCII, `'A'` é 65, `'B'` é 66, `'a'` é 97, `'0'` é
48, o espaço é 32 e o `'\n'` é 10. As aspas simples só escrevem esse número de
um jeito legível: `'A'` e `65` são o mesmo valor (DEITEL; DEITEL, 2011,
cap. 8).

| símbolos | códigos | repare |
| --- | --- | --- |
| `'0'` a `'9'` | 48 a 57 | em ordem: `'7' - '0'` = 7 |
| `'A'` a `'Z'` | 65 a 90 | em ordem alfabética |
| `'a'` a `'z'` | 97 a 122 | cada minúscula = maiúscula + 32 |

Quem decide o que aparece na tela é o `printf`. Com `%c` ele mostra o
símbolo; com `%d`, o código. Como o `char` é número, dá para fazer conta e
comparar: `'a' + 1` é `'b'`, e `c >= 'A' && c <= 'Z'` pergunta se `c` é uma
maiúscula. A conta mais útil é `c - '0'`: como os dígitos estão em ordem a
partir do 48, ela transforma o caractere `'7'` no número 7 (BACKES, 2013,
cap. 7). A tabela mostra outra regularidade: cada minúscula fica 32 posições
depois da sua maiúscula.

Fazer essas contas na mão funciona, mas o `<ctype.h>` já traz as funções
prontas. Há testes, que respondem sim ou não: `isalpha` (é letra?),
`isdigit` (é dígito?), `isalnum` (letra ou dígito?), `isspace` (espaço, `\t`
ou `\n`?), `isupper`, `islower` e `ispunct` (pontuação?). E há conversões:
`toupper` devolve a maiúscula e `tolower` a minúscula. O que não é letra volta
igual, então `toupper('2')` é `'2'` (DEITEL; DEITEL, 2011, cap. 8).

Os testes seguem a regra do C para verdadeiro: qualquer valor **diferente de
zero**. Eles não prometem devolver 1; podem devolver 8 ou 1024. Por isso
escreva `if (isdigit(c))`, nunca `if (isdigit(c) == 1)`, que pode falhar
mesmo quando `c` é um dígito (LINUX MAN-PAGES PROJECT, s.d.).

Para ler um caractere do teclado, existe o `getchar()`. Ele devolve um
**`int`**, e não um `char`, porque precisa de um valor a mais: além dos 256
códigos possíveis, ele pode devolver **`EOF`**, um número negativo que avisa
que a entrada acabou (Ctrl+D no Linux). Guarde o resultado num `int`, ou o
`EOF` pode se confundir com um caractere de verdade (DEITEL; DEITEL, 2011,
cap. 8).

Acento pede um cuidado. O C não garante se o `char` tem sinal; no x86 ele vai
de -128 a 127. No UTF-8, o "ç" ocupa **dois** bytes (`0xC3 0xA7`) e não cabe
num `char`. Num `char` com sinal, esses bytes viram números negativos, e
passar um negativo que não seja `EOF` às funções do `<ctype.h>` é
comportamento indefinido. O jeito seguro é converter antes:
`toupper((unsigned char) c)` (CPPREFERENCE, s.d.).

> [!WARNING]
> Letra não é "tudo entre `'A'` e `'z'`": entre o `'Z'` (90) e o `'a'` (97)
> ficam `[ \ ] ^ _` e a crase, então esse teste aceita `_` como letra. Use
> `isalpha(c)`. E não confunda `'0'` (o caractere zero, código 48) com `0`
> (o número zero, que é o caractere nulo `'\0'`).

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
