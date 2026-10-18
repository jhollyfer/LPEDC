// 0112 · Endereçamento aberto
// Exercício E669 · ★★☆

#include <stdio.h>
#include <stdbool.h>

#define M 7

typedef enum { LIVRE, OCUPADA, REMOVIDA } Estado;

typedef struct {
    int chave;
    Estado estado;
} Armario;

void guarda(Armario t[], int chave) {
    int i = chave % M;
    while (t[i].estado == OCUPADA) {
        i = (i + 1) % M;
    }
    t[i].chave = chave;
    t[i].estado = OCUPADA;
}

bool busca(const Armario t[], int chave, int *sondagens) {
    int i = chave % M;
    *sondagens = 0;
    for (int passo = 0; passo < M; passo++) {
        (*sondagens)++;
        if (t[i].estado == LIVRE) {
            return false; // fim do caminho: não está
        }
        if (t[i].estado == OCUPADA && t[i].chave == chave) {
            return true;
        }
        i = (i + 1) % M; // REMOVIDA ou outra chave: segue
    }
    return false; // deu a volta inteira
}

int main(void) {
    Armario t[M] = {{0, LIVRE}};
    guarda(t, 14);
    guarda(t, 21);
    guarda(t, 28);
    t[1].estado = REMOVIDA; // o 21 foi retirado

    int procurar[] = {28, 35};
    for (int k = 0; k < 2; k++) {
        int s;
        bool achou = busca(t, procurar[k], &s);
        printf("%d: %s, sondagens: %d\n", procurar[k], achou ? "achou" : "não está", s);
    }
    return 0;
}
