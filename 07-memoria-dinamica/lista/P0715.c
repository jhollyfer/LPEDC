// Lista · Módulo 07 · Memória dinâmica
// Exercício P0715 · ★★☆ · Conserte o diário de bordo
//
// O diário de bordo de um barco de linha guarda o nome do barco numa cópia
// no heap e as paradas num vetor que cresce. O programa tem TRÊS erros de
// propósito. Dois o AddressSanitizer acusa (um de cada vez); o terceiro não
// aparece nos testes, porque só dá problema no dia em que faltar memória.
// Conserte os três. O programa deve mostrar:
//
//   Saída esperada:
//   Barco: Comandante Paiva
//   Paradas (h): 0 6 14 20 31
//   Viagem total: 31 horas
//
// Dicas:
// 1. Uma cópia de string precisa de strlen + 1 bytes: o '\0' também ocupa.
// 2. O realloc recebe BYTES, não elementos: cap * sizeof *paradas.
// 3. Se o realloc falhar, ele devolve NULL e o bloco antigo continua lá.
//    Com v = realloc(v, ...), você perde o único endereço dele (vazamento).
//    Receba o retorno num ponteiro novo e só depois troque.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    const char *nome_barco = "Comandante Paiva";
    char *barco = malloc(strlen(nome_barco));
    if (barco == NULL) {
        return 1;
    }
    strcpy(barco, nome_barco);

    int horas[5] = {0, 6, 14, 20, 31}; // horas de viagem até cada parada
    int cap = 2, n = 0;
    int *paradas = malloc(cap * sizeof *paradas);
    if (paradas == NULL) {
        free(barco);
        return 1;
    }
    for (int i = 0; i < 5; i++) {
        if (n == cap) {
            cap *= 2;
            paradas = realloc(paradas, cap);
            if (paradas == NULL) {
                free(barco);
                return 1;
            }
        }
        paradas[n++] = horas[i];
    }

    printf("Barco: %s\n", barco);
    printf("Paradas (h):");
    for (int i = 0; i < n; i++) {
        printf(" %d", paradas[i]);
    }
    printf("\nViagem total: %d horas\n", paradas[n - 1]);
    free(paradas);
    free(barco);
    return 0;
}
