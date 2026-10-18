// A270 · Quando o item não se divide: o guloso perde

#include <stdio.h>

#define N 5

// mochila 0/1: cada item vai inteiro ou fica. O guloso por razão é rápido,
// mas não garante o melhor. Aqui ele é comparado com a força bruta, que testa
// os 2^5 = 32 subconjuntos (um bit por item, como no assunto 0125).
int main(void) {
    const char *nome[N] = {"videogame", "relógios", "caixas de som", "TV", "panela elétrica"};
    int peso[N] = {6, 2, 8, 12, 9};             // kg (já em ordem de R$/kg)
    int valor[N] = {600, 180, 640, 900, 630};   // R$ de revenda
    int cap = 20;                               // limite da mala, em kg

    // guloso por razão: leva o item inteiro se couber
    int livre = cap, guloso = 0;
    printf("Guloso:");
    for (int i = 0; i < N; i++) {
        if (peso[i] <= livre) {
            livre -= peso[i];
            guloso += valor[i];
            printf(" [%s]", nome[i]);
        }
    }
    printf(" = R$ %d (%d kg)\n", guloso, cap - livre);

    // força bruta: o subconjunto de maior valor que cabe
    int melhor = 0, escolha = 0;
    for (int m = 0; m < (1 << N); m++) {
        int p = 0, v = 0;
        for (int i = 0; i < N; i++) {
            if (m & (1 << i)) {
                p += peso[i];
                v += valor[i];
            }
        }
        if (p <= cap && v > melhor) {
            melhor = v;
            escolha = m;
        }
    }
    printf("Ótimo: ");
    int p = 0;
    for (int i = 0; i < N; i++) {
        if (escolha & (1 << i)) {
            printf(" [%s]", nome[i]);
            p += peso[i];
        }
    }
    printf(" = R$ %d (%d kg)\n", melhor, p);
    // o guloso enche 16 kg com os itens de melhor razão e deixa 4 kg sem
    // uso, porque a TV (12 kg) não cabe mais. Na fracionária, esses 4 kg
    // levariam um terço da TV (R$ 300): R$ 1720, um teto para a 0/1.
    return 0;
}
// Saída:
// Guloso: [videogame] [relógios] [caixas de som] = R$ 1420 (16 kg)
// Ótimo:  [videogame] [relógios] [TV] = R$ 1680 (20 kg)
