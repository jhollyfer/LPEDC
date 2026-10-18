// 0048 · Ponteiros e strings
// Exercício E284 · ★☆☆
//
// Considere as declarações
//
//   char cidade[] = "Natal";
//   const char *estado = "RN";
//
// a) Quanto vale sizeof cidade? E sizeof estado?
// b) Quanto vale strlen(cidade)? E strlen(estado)?
// c) Quais destas linhas compilam e funcionam? Para as outras, diga se o
//    erro é de compilação ou de execução:
//
//   1. cidade[0] = 'n';
//   2. estado = "PB";
//   3. cidade = "Recife";
//   4. estado[0] = 'r';
//   5. strcpy(cidade, "Natal");
//
// Responda em comentário. Depois teste: escreva o programa com as linhas que
// funcionam e mostre os sizeof e strlen com printf.
//
// Dicas:
// 1. Vetor: o tamanho inclui o '\0'. Ponteiro: o tamanho de um endereço.
// 2. Vetor não recebe outro endereço; const char * não deixa escrever.
// 3. Resposta esperada: a) 6 e 8; b) 5 e 2; c) 1 funciona; 2 funciona;
//    3 não compila (vetor não pode ser atribuído); 4 não compila por
//    causa do const (sem o const, compilaria e cairia na execução);
//    5 funciona (cabe: 5 letras + '\0' em 6 bytes).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {

    return 0;
}
