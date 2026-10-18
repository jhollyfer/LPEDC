// A171 · Pedágio na sexta: a fila cresce, esvazia e recomeça

#include <stdio.h>
#include "fila.h"

// a cabine libera todos os carros que estão na fila
int libera_todos(Fila *f) {
    int passaram = 0;
    int placa;
    while (fila_retira(f, &placa)) {
        passaram++;
    }
    return passaram;
}

int main(void) {
    Fila *cabine = fila_cria();
    if (cabine == NULL) {
        return 1;
    }

    // 18h: chegam 12 carros. O painel de 8 do 0085 recusaria 4; aqui cabem todos
    for (int placa = 1001; placa <= 1012; placa++) {
        if (!fila_insere(cabine, placa)) {
            printf("Faltou memória para o carro %d\n", placa);
        }
    }
    int primeiro;
    fila_primeiro(cabine, &primeiro);
    printf("Na fila: %d carros, o primeiro é o %d\n", fila_tamanho(cabine), primeiro);

    int passaram = libera_todos(cabine); // antes do printf: a ordem dos argumentos não é garantida
    printf("Passaram: %d; vazia? %d\n", passaram, fila_vazia(cabine));

    // 19h: a fila tinha esvaziado. O fila_retira zerou o fim lá dentro, então
    // o próximo carro vira início e fim ao mesmo tempo, sem tocar no nó liberado
    fila_insere(cabine, 2001);
    fila_insere(cabine, 2002);
    fila_primeiro(cabine, &primeiro);
    printf("Recomeçou: %d carros, o primeiro é o %d\n", fila_tamanho(cabine), primeiro);

    fila_libera(cabine); // libera os 2 nós que sobraram
    return 0;
}
// Saída:
// Na fila: 12 carros, o primeiro é o 1001
// Passaram: 12; vazia? 1
// Recomeçou: 2 carros, o primeiro é o 2001
