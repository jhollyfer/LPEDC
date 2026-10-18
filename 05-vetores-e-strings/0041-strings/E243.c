// 0041 · Strings
// Exercício E243 · ★★☆
//
// Implemente, sem usar o string.h, as suas versões de três funções:
//
//   int meu_strlen(const char s[]);
//   void meu_strcat(char dest[], const char orig[]);
//   int meu_strcmp(const char a[], const char b[]);
//
// meu_strcmp devolve 0 se forem iguais, um negativo se a vem antes e um
// positivo se a vem depois. No main, teste:
//
//   char usuario[30] = "joao";
//   meu_strcat(usuario, ".silva");
//
//   Saída esperada:
//   joao.silva (10)
//   igual a "joao.silva"? sim
//   "ana" antes de "bia"? sim
//   "bia" antes de "bianca"? sim
//
// Dicas:
// 1. meu_strcat: ache o '\0' de dest (use meu_strlen) e copie orig a partir
//    dali, sem esquecer de pôr o '\0' no fim.
// 2. meu_strcmp: avance enquanto a[i] == b[i] e a[i] != '\0'. Quando parar,
//    devolva a[i] - b[i]. Se as duas acabaram juntas, isso dá 0.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
