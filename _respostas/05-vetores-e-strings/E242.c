// 0041 · Strings
// Exercício E242 · ★☆☆
//
// Resposta:
//   6 10     "pastel" tem 6 letras; o vetor tem 10 bytes
//   6        "verde" + '\0'
//   past 4   o '\0' na posição 4 corta o texto ("el" segue na memória)
//   1        "abc" < "abd": 'c' (99) < 'd' (100)
//   1        "Zebra" < "abelha": 'Z' (90) < 'a' (97)
//   1        "casa" < "casamento": na posição 4, '\0' (0) < 'm'

#include <stdio.h>
#include <string.h>

int main(void) {
    char s[10] = "pastel";

    printf("%zu %zu\n", strlen(s), sizeof(s));
    printf("%zu\n", sizeof("verde"));
    s[4] = '\0';
    printf("%s %zu\n", s, strlen(s));
    printf("%d\n", strcmp("abc", "abd") < 0);
    printf("%d\n", strcmp("Zebra", "abelha") < 0);
    printf("%d\n", strcmp("casa", "casamento") < 0);
    return 0;
}
