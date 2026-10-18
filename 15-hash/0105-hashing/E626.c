// 0105 · A ideia e a função hash
// Exercício E626 · ★☆☆
//
// Sem rodar, preveja a saída. Os códigos que você vai precisar: 's' = 115,
// 'o' = 111, 'l' = 108, 'S' = 83, 'u' = 117, 'a' = 97.
//
//   #define M 5
//   
//   unsigned h(const char *s) {
//       unsigned soma = 0;
//       for (int i = 0; s[i] != '\0'; i++) {
//           soma += (unsigned char)s[i];
//       }
//       return soma % M;
//   }
//   
//   int main(void) {
//       const char *p[] = {"sol", "los", "Sol", "lua"};
//       for (int i = 0; i < 4; i++) {
//           printf("%s=%u\n", p[i], h(p[i]));
//       }
//       return 0;
//   }
//
// Quais palavras colidem, e por que cada colisão acontece?
//
// Dicas:
// 1. Some os três códigos de cada palavra e tire o resto por 5.
// 2. Maiúscula e minúscula têm códigos diferentes: 'S' não é 's'.
// 3. Resposta esperada: sol=4, los=4, Sol=2, lua=2. "sol" e "los" colidem
//    porque são anagramas (soma 334); "Sol" (302) e "lua" (322) colidem
//    por acaso: só o resto por 5 é igual.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
