// A358 · Lápides que se acumulam

#include <stdio.h>
#include "0179-sondagem.h"

// média de sondagens de 500 buscas por chaves que não estão na tabela
double media_sem_sucesso(const Sondagem *t) {
    long soma = 0;
    for (int i = 0; i < 500; i++) {
        int s;
        sd_busca(t, 900000 + i, &s);
        soma += s;
    }
    return soma / 500.0;
}

void relata(const char *quando, const Sondagem *t) {
    printf("%-23s chaves %3d | lápides %3d | busca sem sucesso: %5.1f sondagens\n", quando,
           sd_tamanho(t), sd_lapides(t), media_sem_sucesso(t));
}

int main(void) {
    int m = 211;
    Sondagem *t = sd_cria(m, SD_DUPLA);
    if (t == NULL) {
        return 1;
    }
    int presentes[100]; // as 100 chaves que estão na tabela agora
    for (int i = 0; i < 100; i++) {
        presentes[i] = i * 37 + 1;
        sd_insere(t, presentes[i], NULL);
    }
    relata("inicial:", t);

    int proxima = 10000; // troca 400 vezes: sai uma chave antiga, entra uma nova
    for (int rodada = 1; rodada <= 400; rodada++) {
        int k = (rodada * 7) % 100;
        sd_remove(t, presentes[k]);
        presentes[k] = proxima;
        proxima += 13;
        sd_insere(t, presentes[k], NULL);
        if (rodada == 100 || rodada == 400) {
            char rotulo[32];
            snprintf(rotulo, sizeof rotulo, "depois de %d trocas:", rodada);
            relata(rotulo, t);
        }
    }

    Sondagem *nova = sd_cria(m, SD_DUPLA); // reconstruir: reinsere só as chaves vivas
    if (nova == NULL) {
        sd_libera(t);
        return 1;
    }
    for (int i = 0; i < 100; i++) {
        sd_insere(nova, presentes[i], NULL);
    }
    sd_libera(t);
    relata("depois de reconstruir:", nova);
    sd_libera(nova);
    return 0;
}
// Saída:
// inicial:                chaves 100 | lápides   0 | busca sem sucesso:   2.4 sondagens
// depois de 100 trocas:   chaves 100 | lápides  68 | busca sem sucesso:   5.0 sondagens
// depois de 400 trocas:   chaves 100 | lápides 111 | busca sem sucesso: 211.0 sondagens
// depois de reconstruir:  chaves 100 | lápides   0 | busca sem sucesso:   2.8 sondagens
