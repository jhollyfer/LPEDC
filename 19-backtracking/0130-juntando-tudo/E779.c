// 0130 · Juntando tudo
// Exercício E779 · ★★★
//
// Ache o bug. Este resolvedor recebeu um jogo novo da revista, que tem
// solução, mas responde "sem solução". Ele compila sem aviso e roda sem
// erro do sanitizer. O erro está numa linha que FALTA. Ache, conserte e rode
// de novo.
//
//   Saída esperada:
//   354617892
//   987523146
//   162894753
//   493165278
//   725438619
//   618279435
//   549782361
//   231946587
//   876351924
//
// Dicas:
// 1. Depois que resolve(0) devolve false, mostre quantos true sobraram nos
//    três vetores de marcação. Quantos deviam sobrar? (Só os das 30 casas
//    dadas: 30 em cada vetor.)
// 2. Compare o que o programa faz antes da chamada recursiva com o que ele
//    desfaz depois. Uma das duas ações não é desfeita.
// 3. Resposta esperada: falta marca(l, c, d, false); logo depois da chamada
//    recursiva que falhou (junto do g[l][c] = 0). Sem ela, um dígito
//    tentado e abandonado continua "ocupando" a linha, a coluna e a caixa, e
//    a poda corta dígitos que eram a resposta.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdbool.h>
#include <stdio.h>

int g[9][9];
bool na_linha[9][10], na_coluna[9][10], na_caixa[9][10];

int caixa(int l, int c) {
    return (l / 3) * 3 + c / 3;
}

void marca(int l, int c, int d, bool valor) {
    na_linha[l][d] = na_coluna[c][d] = na_caixa[caixa(l, c)][d] = valor;
}

bool resolve(int k) {
    while (k < 81 && g[k / 9][k % 9] != 0) {
        k++;
    }
    if (k == 81) {
        return true;
    }
    int l = k / 9, c = k % 9;
    for (int d = 1; d <= 9; d++) {
        if (na_linha[l][d] || na_coluna[c][d] || na_caixa[caixa(l, c)][d]) {
            continue;
        }
        g[l][c] = d;
        marca(l, c, d, true);
        if (resolve(k + 1)) {
            return true;
        }
        g[l][c] = 0;
    }
    return false;
}

int main(void) {
    const char *jogo[9] = {
        "..46.789.", "9.....1.6", ".....4..3",
        "4.....2.8", ".........", ".1.279..5",
        ".....2..1", "..19..587", "87.3...24",
    };
    for (int l = 0; l < 9; l++) {
        for (int c = 0; c < 9; c++) {
            g[l][c] = jogo[l][c] == '.' ? 0 : jogo[l][c] - '0';
            if (g[l][c] != 0) {
                marca(l, c, g[l][c], true);
            }
        }
    }
    if (resolve(0)) {
        for (int l = 0; l < 9; l++) {
            for (int c = 0; c < 9; c++) {
                printf("%d", g[l][c]);
            }
            printf("\n");
        }
    } else {
        printf("sem solução\n");
    }
    return 0;
}
