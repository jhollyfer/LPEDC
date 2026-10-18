// A326 · A agenda do barbeiro

#include <stdio.h>
#include "skip.h"

// horário em minutos desde a meia-noite: 570 é 9h30
void mostra_hora(int min) {
    printf("%02dh%02d", min / 60, min % 60);
}

int main(void) {
    // os clientes marcam fora de ordem; a skip list mantém tudo em ordem
    int hora[] = {570, 540, 660, 600, 630, 720};
    int andares[] = {1, 2, 1, 3, 2, 1};
    Skip *agenda = skip_cria(0);
    for (int i = 0; i < 6; i++) {
        skip_insere_andares(agenda, hora[i], andares[i]);
    }
    printf("Agenda (%d andares):\n", agenda->andares);
    skip_mostra(agenda);

    // o cliente das 10h cancela: o 600 sai dos 3 andares dele, e o andar 2,
    // que só tinha ele, fica vazio
    skip_remove(agenda, 600);
    printf("Sem o das 10h00 (%d andares):\n", agenda->andares);
    skip_mostra(agenda);

    // atender em ordem: o primeiro do andar 0 é sempre o próximo horário
    printf("Atendimentos:");
    while (agenda->cabeca.prox[0] != NULL) {
        int proximo = agenda->cabeca.prox[0]->chave;
        printf(" ");
        mostra_hora(proximo);
        skip_remove(agenda, proximo); // tirar o primeiro: nada para procurar
    }
    printf("\nNa agenda: %d\n", agenda->n);

    skip_libera(agenda);
    return 0;
}
// Saída:
// Agenda (3 andares):
// andar 2:         600
// andar 1: 540     600 630
// andar 0: 540 570 600 630 660 720
// Sem o das 10h00 (2 andares):
// andar 1: 540     630
// andar 0: 540 570 630 660 720
// Atendimentos: 09h00 09h30 10h30 11h00 12h00
// Na agenda: 0
