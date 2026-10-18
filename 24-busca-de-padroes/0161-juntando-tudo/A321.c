// A321 · O cronômetro: 2 milhões de letras, quatro algoritmos

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "padroes.h"

#define N 2000000

typedef struct {
    const char *nome;
    Busca busca;
} Algoritmo;

static const Algoritmo algs[] = {
    {"força bruta", pb_forca_bruta},
    {"KMP", pb_kmp},
    {"Horspool", pb_horspool},
    {"Rabin-Karp", pb_rabin_karp},
};

// gerador próprio (sempre a mesma sequência, em qualquer máquina)
static unsigned long semente = 2026;
static int sorteia(int limite) {
    semente = (semente * 1103515245UL + 12345UL) % 2147483648UL;
    return (int) (semente / 65536 % (unsigned long) limite);
}

void mede(const char *titulo, const char *texto, const char *padrao) {
    int n = (int) strlen(texto);
    int m = (int) strlen(padrao);
    printf("%s, m = %d:\n", titulo, m);
    for (int a = 0; a < 4; a++) {
        long comp = 0;
        clock_t ini = clock();
        int achou = algs[a].busca(texto, n, padrao, m, NULL, 0, &comp);
        double ms = 1000.0 * (double) (clock() - ini) / CLOCKS_PER_SEC;
        printf("  %5d ocorrências %8ld comparações %6.1f ms  %s\n",
               achou, comp, ms, algs[a].nome);
    }
}

int main(void) {
    char *dna = malloc(N + 1);
    char *prosa = malloc(N + 1);
    if (dna == NULL || prosa == NULL) {
        free(dna);
        free(prosa);
        return 1;
    }
    const char *bases = "ACGT";
    for (int i = 0; i < N; i++) {
        dna[i] = bases[sorteia(4)];         // alfabeto de 4 letras
    }
    dna[N] = '\0';

    const char *frase = "o menino do pastel corre com a bandeja enquanto a fila "
                        "do caldo de cana dobra a esquina; ";
    int tf = (int) strlen(frase);
    for (int i = 0; i < N; i++) {
        prosa[i] = frase[i % tf];           // texto comum, alfabeto maior
    }
    prosa[N] = '\0';

    mede("DNA", dna, "GATTACA");
    mede("DNA", dna, "ACGTACGTTGCATGCAACGTACGTTGCATGCA");
    mede("prosa", prosa, "caldo de cana");
    mede("prosa", prosa, "a fila do caldo de cana dobra a esquina");

    free(dna);
    free(prosa);
    return 0;
}
// Saída (as comparações são sempre estas; os milissegundos variam de máquina
// para máquina e de uma execução para outra):
// DNA, m = 7:
//      89 ocorrências  2666712 comparações   22.6 ms  força bruta
//      89 ocorrências  2499967 comparações   21.3 ms  KMP
//      89 ocorrências   938338 comparações   12.5 ms  Horspool
//      89 ocorrências      623 comparações   16.0 ms  Rabin-Karp
// DNA, m = 32:
//       0 ocorrências  2666474 comparações   22.8 ms  força bruta
//       0 ocorrências  2500062 comparações   22.7 ms  KMP
//       0 ocorrências  1124384 comparações   15.0 ms  Horspool
//       0 ocorrências        0 comparações   18.2 ms  Rabin-Karp
// prosa, m = 13:
//   22472 ocorrências  2359540 comparações   14.9 ms  força bruta
//   22472 ocorrências  2044944 comparações   11.8 ms  KMP
//   22472 ocorrências   808985 comparações    7.8 ms  Horspool
//   22472 ocorrências   292136 comparações   19.3 ms  Rabin-Karp
// prosa, m = 39:
//   22471 ocorrências  3258344 comparações   19.9 ms  força bruta
//   22471 ocorrências  2134831 comparações   13.1 ms  KMP
//   22471 ocorrências  1190966 comparações    8.2 ms  Horspool
//   22471 ocorrências   876369 comparações   22.3 ms  Rabin-Karp
