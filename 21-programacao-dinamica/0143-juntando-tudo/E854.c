// 0143 · Juntando tudo: um mini-diff
// Exercício E854 · ★☆☆
//
// Alguém abriu o arquivo de configuração da loja num editor que mudou
// maiúsculas e deixou espaços sobrando no fim das linhas. O diff abaixo
// acusa as 5 linhas como trocadas, mas só duas mudaram de verdade. Complete
// a função iguais() (marcada com COMPLETE AQUI) para ela considerar iguais
// as linhas que só diferem em maiúsculas/minúsculas ou em espaços no FIM
// da linha, como faz o "diff -i -Z". O resto do programa já usa iguais().
//
//   Saída esperada:
//     Nome: Loja do Zé
//     Cidade: Fortaleza
//   - Horario: 8h as 18h
//   + Horario: 8h as 20h
//     Pix: sim
//   - Entrega: nao
//   + Entrega: sim
//
// Dicas:
// 1. Calcule o tamanho "útil" de cada linha: comece em strlen e recue
//    enquanto o último caractere for ' '.
// 2. Tamanhos úteis diferentes: não são iguais. Senão, compare letra a letra
//    com tolower de <ctype.h>, passando (unsigned char) x[k] (um char
//    negativo, como os bytes do "é", é proibido no tolower).
// 3. As linhas iguais saem como estão na versão antiga.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (complete o código):

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX 20

// 1 se as duas linhas são iguais ignorando maiúsculas/minúsculas e os
// espaços no fim da linha; 0 se não
int iguais(const char *x, const char *y) {
    // COMPLETE AQUI: hoje ela só aceita linhas idênticas
    return strcmp(x, y) == 0;
}

void diff(const char *a[], int m, const char *b[], int n) {
    int c[MAX + 1][MAX + 1];
    for (int i = m; i >= 0; i--) {
        for (int j = n; j >= 0; j--) {
            if (i == m || j == n) {
                c[i][j] = 0;
            } else if (iguais(a[i], b[j])) {
                c[i][j] = c[i + 1][j + 1] + 1;
            } else {
                c[i][j] = c[i + 1][j] >= c[i][j + 1] ? c[i + 1][j] : c[i][j + 1];
            }
        }
    }
    int i = 0, j = 0;
    while (i < m || j < n) {
        if (i < m && j < n && iguais(a[i], b[j])) {
            printf("  %s\n", a[i]);
            i++;
            j++;
        } else if (j == n || (i < m && c[i + 1][j] >= c[i][j + 1])) {
            printf("- %s\n", a[i++]);
        } else {
            printf("+ %s\n", b[j++]);
        }
    }
}

int main(void) {
    const char *antes[] = {"Nome: Loja do Zé", "Cidade: Fortaleza",
                           "Horario: 8h as 18h", "Pix: sim", "Entrega: nao"};
    const char *depois[] = {"NOME: Loja do Zé   ", "cidade: fortaleza",
                            "Horario: 8h as 20h", "Pix: SIM", "Entrega: sim"};
    diff(antes, 5, depois, 5);
    return 0;
}
