// A327 · A gaveta de temperos num vetor

#include <stdio.h>
#include <string.h>

#define N 8

typedef struct {
    char nome[16];
} Pote;

// busca sequencial; devolve a posição (ou -1) e soma as comparações
int procura(const Pote v[], int n, const char *nome, int *comparacoes) {
    for (int i = 0; i < n; i++) {
        (*comparacoes)++;
        if (strcmp(v[i].nome, nome) == 0) {
            return i;
        }
    }
    return -1;
}

// mover para a frente no vetor: os i anteriores andam uma casa para trás
void usa_mtf(Pote v[], int n, const char *nome, int *comparacoes, int *movidos) {
    int i = procura(v, n, nome, comparacoes);
    if (i > 0) {
        Pote achado = v[i];
        for (int j = i; j > 0; j--) {
            v[j] = v[j - 1];
        }
        v[0] = achado;
        *movidos += i + 1; // todas as posições de 0 a i mudaram
    }
}

// transposição no vetor: uma troca com o vizinho da esquerda
void usa_transpoe(Pote v[], int n, const char *nome, int *comparacoes, int *movidos) {
    int i = procura(v, n, nome, comparacoes);
    if (i > 0) {
        Pote aux = v[i];
        v[i] = v[i - 1];
        v[i - 1] = aux;
        *movidos += 2;
    }
}

void mostra(const char *titulo, const Pote v[], int comparacoes, int movidos) {
    printf("%s:", titulo);
    for (int i = 0; i < N; i++) {
        printf(" %s", v[i].nome);
    }
    printf("\n  comparações: %d, potes movidos: %d\n", comparacoes, movidos);
}

int main(void) {
    const Pote inicial[N] = {{"sal"}, {"oleo"}, {"alho"}, {"cravo"},
                             {"cominho"}, {"louro"}, {"pimenta"}, {"oregano"}};
    const char *receitas[] = {"pimenta", "louro", "pimenta", "alho", "pimenta",
                              "louro", "pimenta", "sal", "pimenta", "louro"};
    Pote a[N], b[N];
    memcpy(a, inicial, sizeof inicial); // vetor não se copia com =: memcpy copia os bytes
    memcpy(b, inicial, sizeof inicial);

    int ca = 0, ma = 0, cb = 0, mb = 0;
    for (int k = 0; k < 10; k++) {
        usa_mtf(a, N, receitas[k], &ca, &ma);
        usa_transpoe(b, N, receitas[k], &cb, &mb);
    }
    mostra("Para a frente", a, ca, ma);
    mostra("Transposição", b, cb, mb);
    return 0;
}
// Saída:
// Para a frente: louro pimenta sal alho oleo cravo cominho oregano
//   comparações: 37, potes movidos: 37
// Transposição: sal alho pimenta oleo louro cravo cominho oregano
//   comparações: 53, potes movidos: 18
