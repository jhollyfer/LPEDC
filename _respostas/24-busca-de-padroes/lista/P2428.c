// Lista · Módulo 24 · Busca de padrões em texto
// Exercício P2428 · ★★★ · O logotipo na tela

#include <stdio.h>
#include <string.h>

#define L 6
#define C 12
#define LL 2
#define LC 3
#define B 256
#define Q 1000003

const char *tela[L] = {"..#.#.......", ".###..#.#...", "......###...",
                       "..#.#.......", ".###...#.#..", ".......###.."};
const char *logo[LL] = {"#.#", "###"};

long long hash(const char *s, int m) {
    long long h = 0;
    for (int k = 0; k < m; k++) h = (h * B + (unsigned char)s[k]) % Q;
    return h;
}

int main(void) {
    long long pot = 1;
    for (int k = 1; k < LC; k++) pot = pot * B % Q;
    long long hl[LL];
    for (int r = 0; r < LL; r++) hl[r] = hash(logo[r], LC);

    // janela[i][j]: hash do trecho de LC letras da linha i que começa em j
    long long janela[L][C];
    for (int i = 0; i < L; i++) {
        long long h = hash(tela[i], LC);
        for (int j = 0; j + LC <= C; j++) {
            janela[i][j] = h;
            if (j + LC < C) {
                h = (h - (unsigned char)tela[i][j] * pot % Q + Q) % Q;
                h = (h * B + (unsigned char)tela[i][j + LC]) % Q;
            }
        }
    }

    int achou = 0, conferidas = 0;
    for (int i = 0; i + LL <= L; i++)
        for (int j = 0; j + LC <= C; j++) {
            int bate = 1;
            for (int r = 0; r < LL && bate; r++) bate = janela[i + r][j] == hl[r];
            if (!bate) continue;
            conferidas++;
            int igual = 1;
            for (int r = 0; r < LL && igual; r++) igual = strncmp(tela[i + r] + j, logo[r], LC) == 0;
            if (igual) {
                achou++;
                printf("logotipo na linha %d, coluna %d\n", i, j);
            }
        }
    printf("Total: %d; blocos conferidos letra a letra: %d\n", achou, conferidas);
    return 0;
}
