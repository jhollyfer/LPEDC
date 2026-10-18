// 0058 · Juntando tudo
// Exercício E343 · ★☆☆
//
// Leia 3 nomes com fgets num buffer de 100 chars. Para cada um, tire o '\n'
// e guarde uma CÓPIA de tamanho exato no heap, num vetor char *nomes[3].
// Depois mostre cada nome com quantos bytes o bloco dele ocupa e libere
// tudo.
//
//   Exemplo de uso:
//   Nome 1: Ana
//   Nome 2: Joao Pedro
//   Nome 3: Lu
//   Ana (4 bytes)
//   Joao Pedro (11 bytes)
//   Lu (3 bytes)
//
// Para testar: printf 'Ana\nJoao Pedro\nLu\n' | ~/LPEDC/rodar <este arquivo>
//
// Dicas:
// 1. O buffer de 100 é só a área de leitura, reaproveitada a cada nome. Os
//    nomes de verdade vão para blocos de strlen + 1.
// 2. buffer[strcspn(buffer, "\n")] = '\0'; tira o '\n' (assunto 0042).
// 3. Resposta esperada: a saída acima: o bloco de cada nome tem strlen + 1
//    bytes. 3 malloc, 3 free. Se guardasse o próprio buffer em nomes[i], os
//    três ponteiros apontariam para o mesmo lugar e mostrariam "Lu" três
//    vezes.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    return 0;
}
