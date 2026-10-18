// 0130 · Juntando tudo
// Exercício E778 · ★★☆
//
// Um sudoku bem feito tem UMA solução só. A editora da revista quer
// conferir os jogos antes de imprimir. O programa abaixo prepara e resolve
// dois jogos: o do texto e o mesmo jogo sem o 5 do fim da linha 5. Estenda o
// programa com uma função
//
//   int conta(int k, int limite)
//
// que conta as soluções a partir da casa k, mas para assim que a contagem
// chegar a limite. Com limite 2, ela responde o que a editora quer saber:
// 1 é solução única, 2 é "mais de uma". No main, troque a chamada de
// resolve por conta(0, 2) e mostre o veredito.
//
//   Saída esperada:
//   jogo 1: solução única
//   jogo 2: mais de uma solução
//
// Dicas:
// 1. conta é o resolve com duas mudanças: na folha (k == 81) devolve 1, e
//    no laço SOMA o que cada chamada devolve, em vez de parar no primeiro
//    true.
// 2. Depois de cada chamada, se a soma já chegou ao limite, desfaça a
//    marcação e devolva. Sem isso, um jogo com milhares de soluções faria a
//    busca rodar por muito tempo.
// 3. Não esqueça de desfazer antes de qualquer return dentro do laço: a
//    grade e os vetores precisam voltar como estavam.
// 4. Resposta esperada: as 2 linhas acima.
//
// Escreva sua resposta abaixo (estenda o programa):

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int g[9][9];
bool na_linha[9][10], na_coluna[9][10], na_caixa[9][10];

int caixa(int l, int c) {
    return (l / 3) * 3 + c / 3;
}

void marca(int l, int c, int d, bool valor) {
    na_linha[l][d] = na_coluna[c][d] = na_caixa[caixa(l, c)][d] = valor;
}

void prepara(const char *jogo[9]) {
    memset(na_linha, 0, sizeof na_linha);
    memset(na_coluna, 0, sizeof na_coluna);
    memset(na_caixa, 0, sizeof na_caixa);
    for (int l = 0; l < 9; l++) {
        for (int c = 0; c < 9; c++) {
            g[l][c] = jogo[l][c] == '.' ? 0 : jogo[l][c] - '0';
            if (g[l][c] != 0) {
                marca(l, c, g[l][c], true);
            }
        }
    }
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
        marca(l, c, d, false);
        g[l][c] = 0;
    }
    return false;
}

int main(void) {
    const char *jogo1[9] = {
        "2.3.8....", "6......7.", ".412.3.86",
        "5........", ".97.28...", "164.9...5",
        ".3...6...", "4.....2..", ".1.832.5.",
    };
    const char *jogo2[9] = {
        "2.3.8....", "6......7.", ".412.3.86",
        "5........", ".97.28...", "164.9....",
        ".3...6...", "4.....2..", ".1.832.5.",
    };
    prepara(jogo1);
    printf("jogo 1: %s\n", resolve(0) ? "tem solução" : "sem solução");
    prepara(jogo2);
    printf("jogo 2: %s\n", resolve(0) ? "tem solução" : "sem solução");
    return 0;
}
