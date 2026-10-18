// 0057 · Erros de memória
// Exercício E338 · ★☆☆
//
// Resposta:
// a) estouro (heap-buffer-overflow): escreveu 4 bytes logo depois do fim de
//    um bloco de 16 bytes. 16 bytes são 4 ints (índices 0 a 3) e o índice
//    usado foi 4. Ex.: int *v = malloc(4 * sizeof *v);
//    for (int i = 0; i <= 4; i++) v[i] = 0;
// b) uso depois do free: free(p); printf("%d\n", p[0]);
// c) free duplo: free(p); free(p); (ou dois ponteiros para o mesmo bloco,
//    cada um com o seu free)
// d) vazamento: um malloc sem free; o LeakSanitizer lista no fim da
//    execução onde cada bloco perdido foi alocado.
// e) acesso pelo NULL: int *p = NULL; *p = 1; ou um malloc que falhou e
//    ninguém conferiu o retorno.

#include <stdio.h>

int main(void) {
    return 0;
}
