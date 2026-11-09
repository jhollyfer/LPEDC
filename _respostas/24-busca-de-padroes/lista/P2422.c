// Lista · Módulo 24 · Busca de padrões em texto
// Exercício P2422 · ★★★ · Um hash ou dois

#include <stdio.h>
#include <string.h>

#define N 3000
#define M 6
#define B 4

char texto[N + 1];

int main(void) {
    unsigned estado = 2026; // gerador fixo: o mesmo texto em qualquer máquina
    for (int i = 0; i < N; i++) {
        estado = estado * 1103515245u + 12345u;
        texto[i] = "ACGT"[(estado >> 16) % 4];
    }
    texto[N] = '\0';
    char padrao[M + 1];
    memcpy(padrao, texto + 1500, M);
    padrao[M] = '\0';
    printf("padrão: %s\n", padrao);

    const int q1 = 97, q2 = 89;
    int val[256] = {0};
    val['C'] = 1;
    val['G'] = 2;
    val['T'] = 3;
    int pot1 = 1, pot2 = 1;
    for (int k = 1; k < M; k++) {
        pot1 = pot1 * B % q1;
        pot2 = pot2 * B % q2;
    }
    int hp1 = 0, hp2 = 0, ht1 = 0, ht2 = 0;
    for (int k = 0; k < M; k++) {
        hp1 = (hp1 * B + val[(unsigned char)padrao[k]]) % q1;
        hp2 = (hp2 * B + val[(unsigned char)padrao[k]]) % q2;
        ht1 = (ht1 * B + val[(unsigned char)texto[k]]) % q1;
        ht2 = (ht2 * B + val[(unsigned char)texto[k]]) % q2;
    }
    int achou = 0, falso_um = 0, falso_dois = 0;
    for (int i = 0; i + M <= N; i++) {
        int igual = strncmp(texto + i, padrao, M) == 0;
        achou += igual;
        if (ht1 == hp1 && !igual) falso_um++;
        if (ht1 == hp1 && ht2 == hp2 && !igual) falso_dois++;
        if (i + M < N) {
            int sai = val[(unsigned char)texto[i]], entra = val[(unsigned char)texto[i + M]];
            ht1 = ((ht1 - sai * pot1 % q1 + q1) * B + entra) % q1;
            ht2 = ((ht2 - sai * pot2 % q2 + q2) * B + entra) % q2;
        }
    }
    printf("janelas: %d, ocorrências: %d\n", N - M + 1, achou);
    printf("falsos positivos com um hash (q = %d): %d\n", q1, falso_um);
    printf("falsos positivos com dois hashes (q = %d e %d): %d\n", q1, q2, falso_dois);
    return 0;
}
