// Lista · Módulo 27 · Detalhes de C que caem em prova
// Exercício P2718 · ★★☆ · A catraca do ônibus

#include <stdio.h>

typedef enum { TRAVADA, LIBERADA } Estado;

int main(void) {
    const char *eventos = "PMPMMPP";
    Estado estado = TRAVADA;
    int passagens = 0, moedas = 0, desperdicadas = 0, bloqueios = 0;

    const char *p = eventos;
    do {
        if (*p == 'M') {
            moedas++;
        }
        switch (estado) {
        case TRAVADA:
            if (*p == 'M') {
                estado = LIBERADA;
            } else {
                bloqueios++;
            }
            break;
        case LIBERADA:
            if (*p == 'P') {
                passagens++;
                estado = TRAVADA;
            } else {
                desperdicadas++;
            }
            break;
        }
        p++;
    } while (*p != '\0');

    printf("passagens: %d\n", passagens);
    printf("moedas: %d (%d desperdiçada)\n", moedas, desperdicadas);
    printf("bloqueios: %d\n", bloqueios);
    return 0;
}
