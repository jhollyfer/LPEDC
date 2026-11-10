// A265 · Postos na estrada: parar o mínimo de vezes

#include <stdio.h>

// guloso que ACERTA: siga até onde o tanque deixa e só abasteça no último
// posto antes de o combustível acabar. Parar antes nunca ajuda: o tanque
// cheio num posto mais à frente leva você pelo menos tão longe.
int main(void) {
    int destino = 600;   // km da viagem
    int autonomia = 200; // km com o tanque cheio
    int posto[] = {80, 150, 230, 310, 360, 450, 520, 590}; // km de cada posto
    int n = 8;

    int alcance = autonomia; // até onde chego sem parar
    int paradas = 0;
    int i = 0;
    while (alcance < destino) {
        int ultimo = -1;
        while (i < n && posto[i] <= alcance) {
            ultimo = posto[i];   // o posto mais distante que ainda alcanço
            i++;
        }
        if (ultimo < 0) {
            printf("Sem posto ao alcance: a viagem não dá\n");
            return 1;
        }
        paradas++;
        alcance = ultimo + autonomia;
        printf("Parada %d: km %d (agora chego ao km %d)\n", paradas, ultimo, alcance);
    }
    printf("Chegou ao km %d com %d paradas\n", destino, paradas);
    return 0;
}
// Saída:
// Parada 1: km 150 (agora chego ao km 350)
// Parada 2: km 310 (agora chego ao km 510)
// Parada 3: km 450 (agora chego ao km 650)
// Chegou ao km 600 com 3 paradas
