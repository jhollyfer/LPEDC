// 0054 · malloc e free
// Exercício E324 · ★★★
//
// Escreva a função
//
//   char *juntar(const char *a, const char *b);
//
// que devolve uma string NOVA, no heap, com a, um espaço e b. Depois, em
// main, monte o nome do crachá "Maria Clara Fonseca" chamando juntar duas
// vezes: primeiro "Maria" com "Clara", depois o resultado com "Fonseca".
// Mostre o nome e o tamanho, e não deixe nenhum bloco para trás.
//
//   Saída esperada:
//   Crachá: Maria Clara Fonseca (19 caracteres)
//
// Dicas:
// 1. O bloco precisa de strlen(a) + 1 (espaço) + strlen(b) + 1 ('\0') bytes.
// 2. strcpy(novo, a); strcat(novo, " "); strcat(novo, b);
// 3. Resposta esperada: a saída acima. O resultado do primeiro juntar
//    ("Maria Clara") também é um bloco do heap: libere-o depois de usá-lo no
//    segundo juntar. São dois malloc, então dois free.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    return 0;
}
