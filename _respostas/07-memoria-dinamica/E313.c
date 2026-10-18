// 0053 · Pilha e heap
// Exercício E313 · ★☆☆

#include <stdio.h>
#include <stdlib.h>

int recorde = 0; // dados (global)

int *ler_placar(int jogos); // as instruções da função ficam no código

// Atualiza o recorde com o maior gol do bloco e devolve o bloco ao heap.
void conferir_e_liberar(int *placar, int jogos) { // placar e jogos: pilha
    for (int i = 0; i < jogos; i++) {             // i: pilha
        if (placar[i] > recorde) {
            recorde = placar[i];
        }
    }
    free(placar);
}

int main(void) {
    int *placar = ler_placar(3); // o ponteiro: pilha; o bloco: heap
    if (placar == NULL) {
        return 1;
    }
    conferir_e_liberar(placar, 3);

    placar = ler_placar(2);
    if (placar == NULL) {
        return 1;
    }
    conferir_e_liberar(placar, 2);

    printf("Recorde: %d\n", recorde);
    return 0;
}

int *ler_placar(int jogos) {           // jogos: pilha (parâmetro)
    static int chamadas = 0;           // dados: vive o programa todo
    int *placar = malloc(jogos * sizeof *placar); // ponteiro: pilha; bloco: heap
    if (placar == NULL) {
        return NULL;
    }
    chamadas++;
    printf("Chamada %d:", chamadas);
    for (int i = 0; i < jogos; i++) {  // i: pilha
        placar[i] = i * 2;
        printf(" %d", placar[i]);
    }
    printf("\n");
    return placar; // o ponteiro some com o frame; o bloco continua no heap
}
// Saída:
// Chamada 1: 0 2 4
// Chamada 2: 0 2
// Recorde: 4
