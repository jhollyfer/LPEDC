// 0056 · void * e cast
// Exercício E334 · ★★☆
//
// Escreva uma função que mostra vetores de QUALQUER tipo:
//
//   void mostra_vetor(const void *v, size_t n, size_t tam,
//                     void (*mostra)(const void *))
//
// Ela calcula o endereço de cada elemento (o i-ésimo começa i * tam bytes
// depois do início) e chama mostra com esse endereço. Escreva também
// mostra_int e mostra_double. Teste com
//
//   int senhas[4] = {101, 102, 103, 104};
//   double notas[3] = {7.5, 9.25, 6.0};
//
//   Saída esperada:
//   101 102 103 104
//   7.50 9.25 6.00
//
// Dicas:
// 1. Converta o início para const unsigned char * e some i * tam: isso anda
//    byte a byte.
// 2. mostra_int faz printf("%d ", *(const int *)p);
// 3. Resposta esperada: as duas linhas acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
