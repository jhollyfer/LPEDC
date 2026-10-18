// 0053 · Pilha e heap
// Exercício E314 · ★☆☆

#include <stdio.h>

void registrar_entrada(void) {
    int hoje = 0;         // pilha: nasce de novo a cada chamada
    static int total = 0; // dados: zera uma vez só
    hoje++;
    total++;
    printf("local: %d | static: %d\n", hoje, total);
}

int main(void) {
    registrar_entrada();
    registrar_entrada();
    registrar_entrada();
    return 0;
}
// Saída:
// local: 1 | static: 1
// local: 1 | static: 2
// local: 1 | static: 3
