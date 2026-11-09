// A372 · Boletos que fecham o Pix: soma de subconjuntos

#include <stdbool.h>
#include <stdio.h>

#define N 7

const char *boletos[N] = {"luz", "água", "internet", "gás", "condomínio", "celular", "academia"};
const int valor[N] = {186, 66, 99, 115, 420, 49, 89}; // em reais

// verificador: confere um certificado (quais boletos) em O(n)
bool confere(const bool usa[], int alvo) {
    int soma = 0;
    for (int i = 0; i < N; i++)
        if (usa[i]) soma += valor[i];
    return soma == alvo;
}

void mostra(const bool usa[]) {
    for (int i = 0; i < N; i++)
        if (usa[i]) printf(" %s(%d)", boletos[i], valor[i]);
    printf("\n");
}

int main(void) {
    int pix = 400; // a mãe mandou R$ 400 para pagar contas: quais fecham certinho?

    bool palpite[N] = {true, true, true, false, false, true, false}; // luz, água, internet, celular
    printf("Palpite:");
    mostra(palpite);
    printf("Soma bate com R$ %d? %s\n", pix, confere(palpite, pix) ? "sim" : "não");

    int tentativas = 0;
    for (int m = 0; m < (1 << N); m++) { // todos os 2^7 = 128 subconjuntos
        bool usa[N];
        for (int i = 0; i < N; i++) usa[i] = (m >> i) & 1;
        tentativas++;
        if (confere(usa, pix)) {
            printf("Achei na tentativa %d:", tentativas);
            mostra(usa);
            return 0;
        }
    }
    printf("Nenhum grupo fecha R$ %d\n", pix);
    return 0;
}
// Saída:
// Palpite: luz(186) água(66) internet(99) celular(49)
// Soma bate com R$ 400? sim
// Achei na tentativa 14: luz(186) internet(99) gás(115)
//
// Dois certificados diferentes para o mesmo "sim". Conferir qualquer um
// custa uma soma; achar um sem palpite custou 14 das 128 tentativas aqui,
// mas no pior caso (quando a resposta é "não") são todas as 2^n. A soma de
// subconjuntos é NP-completa. Quando os valores são pequenos (em reais,
// até alguns milhares), uma PD parecida com a mochila do 0140 resolve em
// O(n · alvo), e isso não contradiz nada: o alvo é um número, e o tamanho
// da entrada é o número de DÍGITOS dele. Um dígito a mais no alvo
// multiplica o trabalho da PD por 10.
