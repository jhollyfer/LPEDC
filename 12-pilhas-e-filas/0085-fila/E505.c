// 0085 · Fila
// Exercício E505 · ★☆☆
//
// Este programa traz uma fila circular igual à do fila.c, mas com só 4
// gavetas e com os campos à vista. Escreva a função mostra, que imprime o
// vetor inteiro (com _ nas gavetas que valem -1, ou seja, nunca usadas),
// depois inicio e n. O main já faz as operações e chama mostra depois de
// cada uma. Rode e acompanhe o 5 dando a volta no vetor.
//
//   Saída esperada:
//   insere 1: [1 _ _ _] inicio 0, n 1
//   insere 2: [1 2 _ _] inicio 0, n 2
//   retira 1: [1 2 _ _] inicio 1, n 1
//   insere 3: [1 2 3 _] inicio 1, n 2
//   insere 4: [1 2 3 4] inicio 1, n 3
//   insere 5: [5 2 3 4] inicio 1, n 4
//   insere 6: recusado [5 2 3 4] inicio 1, n 4
//   retira 2: [5 2 3 4] inicio 2, n 3
//   retira 3: [5 2 3 4] inicio 3, n 2
//   próxima vaga: gaveta 1
//
// Dicas:
// 1. Um for de 0 a CAP - 1: se itens[i] == -1, mostre "_"; senão, o número.
// 2. Repare que retirar não apaga a gaveta: o 1 continua lá depois de sair.
// 3. A próxima vaga é (inicio + n) % CAP: mostre no fim do main.
// 4. Resposta esperada: as dez linhas acima.
//
// Escreva sua resposta abaixo (escreva mostra e a última linha do main):

#include <stdbool.h>
#include <stdio.h>

#define CAP 4

typedef struct {
    int itens[CAP];
    int inicio;
    int n;
} Fila4;

bool insere(Fila4 *f, int valor) {
    if (f->n == CAP) {
        return false;
    }
    f->itens[(f->inicio + f->n) % CAP] = valor;
    f->n++;
    return true;
}

bool retira(Fila4 *f, int *valor) {
    if (f->n == 0) {
        return false;
    }
    *valor = f->itens[f->inicio];
    f->inicio = (f->inicio + 1) % CAP;
    f->n--;
    return true;
}

void mostra(const Fila4 *f) {
    (void)f; // apague esta linha quando usar f
    printf("\n");
}

int main(void) {
    Fila4 f = {.itens = {-1, -1, -1, -1}, .inicio = 0, .n = 0};
    int x;

    for (int v = 1; v <= 6; v++) {
        printf("insere %d: ", v);
        if (!insere(&f, v)) {
            printf("recusado ");
        }
        mostra(&f);
        if (v == 2 && retira(&f, &x)) { // depois do 2, sai um
            printf("retira %d: ", x);
            mostra(&f);
        }
    }
    for (int i = 0; i < 2; i++) {
        if (retira(&f, &x)) {
            printf("retira %d: ", x);
            mostra(&f);
        }
    }
    // mostre aqui a próxima vaga
    return 0;
}
