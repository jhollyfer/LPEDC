// 0102 · Heap e fila de prioridade
// Exercício E607 · ★☆☆
//
// No heap, a árvore mora no vetor e ninguém guarda ponteiro: os filhos de i
// estão em 2i + 1 e 2i + 2. Complete a função mostra_filhos(v, n), que, para
// cada posição do vetor, mostra o valor e quem são os filhos dele (só os que
// existem, isto é, com índice menor que n). Teste com o heap da triagem
// depois das seis chegadas:
//
//   Saída esperada:
//   v[0] = 90: filhos 70 e 30
//   v[1] = 70: filhos 40 e 50
//   v[2] = 30: filho 20
//   v[3] = 40: folha
//   v[4] = 50: folha
//   v[5] = 20: folha
//
// Dicas:
// 1. Calcule esq = 2 * i + 1 e dir = 2 * i + 2.
// 2. Se esq >= n, é folha. Se só esq < n, tem um filho. Senão, tem os dois.
// 3. Resposta esperada: a saída acima. Só o v[2] tem um filho só: num heap,
//    no máximo um nó fica nessa situação.
//
// Escreva sua resposta abaixo (complete mostra_filhos):

#include <stdio.h>

void mostra_filhos(const int v[], int n) {
    (void)v; // apague estas duas linhas quando escrever a função
    (void)n;
}

int main(void) {
    int heap[] = {90, 70, 30, 40, 50, 20};
    mostra_filhos(heap, 6);
    return 0;
}
