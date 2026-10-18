// A027 · Avisos independentes no painel do carro

#include <stdbool.h>
#include <stdio.h>

// Três if seguidos, sem else: cada pergunta é feita, não importa o que as
// outras responderam. Pode acender nenhum aviso, um, dois ou os três.
int main(void) {
    int combustivel = 12; // porcentagem do tanque
    bool porta_aberta = true;
    int km_revisao = 0;   // quilômetros até a próxima revisão

    if (combustivel < 15) {
        printf("Aviso: tanque na reserva (%d%%).\n", combustivel);
    }
    if (porta_aberta) { // a variável sozinha: verdade se não for zero
        printf("Aviso: porta aberta.\n");
    }
    if (!km_revisao) {  // o mesmo que km_revisao == 0
        printf("Aviso: hora da revisão.\n");
    }
    printf("Boa viagem!\n");
    return 0;
}
// Saída:
// Aviso: tanque na reserva (12%).
// Aviso: porta aberta.
// Aviso: hora da revisão.
// Boa viagem!
