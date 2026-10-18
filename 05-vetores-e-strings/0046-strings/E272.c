// 0046 · Strings
// Exercício E272 · ★☆☆
//
// Sem rodar, preveja cada linha. Para o strcmp, diga só o sinal (negativo,
// zero ou positivo): o valor exato pode mudar de um sistema para outro.
//
//   char s[10] = "pastel";
//   printf("%zu %zu\n", strlen(s), sizeof(s));
//   printf("%zu\n", sizeof("verde"));
//   s[4] = '\0';
//   printf("%s %zu\n", s, strlen(s));
//   printf("%d\n", strcmp("abc", "abd") < 0);
//   printf("%d\n", strcmp("Zebra", "abelha") < 0);
//   printf("%d\n", strcmp("casa", "casamento") < 0);
//
// Dicas:
// 1. sizeof de um literal conta o '\0'; strlen não.
// 2. Depois de s[4] = '\0', o texto acaba na posição 4. O "el" continua na
//    memória, só que ninguém olha para ele.
// 3. strcmp compara os códigos, letra a letra: 'Z' é 90 e 'a' é 97.
//    Quando uma string acaba antes, o '\0' (0) é menor que qualquer letra.
// 4. Resposta esperada: "6 10", "6", "past 4", 1, 1 e 1.
//
// Escreva sua resposta abaixo (o código está pronto para conferir):

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
