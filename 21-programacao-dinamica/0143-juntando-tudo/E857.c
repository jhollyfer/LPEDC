// 0143 · Juntando tudo: um mini-diff
// Exercício E857 · ★★★
//
// A empresa de ônibus mudou o itinerário da linha 42 e quer mostrar o que
// mudou. O programa abaixo é o mini-diff do texto adaptado para vetores de
// strings, mas o AddressSanitizer para o programa com
// "heap-buffer-overflow" logo na montagem da tabela. Há UM erro de
// propósito. Ache, conserte e rode até a saída ficar limpa.
//
//   Saída esperada (depois de consertar):
//   Itinerário da linha 42:
//     Terminal
//   + Mercado
//     Centro
//   - Hospital
//     Universidade
//     Praia
//   + Aeroporto
//
// Dicas:
// 1. Leia o relatório do ASan: quantos bytes o bloco tem ("120-byte
//    region") e quantos int isso dá?
// 2. Quantas células tem a tabela de m = 5 contra n = 6, contando a linha e
//    a coluna dos sufixos vazios? E qual é o maior índice que o laço usa?
// 3. A conta do índice usa w = n + 1 colunas por linha; a conta do malloc
//    precisa usar o mesmo formato.
// 4. Resposta esperada: o malloc reserva m * n = 30 int, mas a tabela tem
//    (m + 1) * (n + 1) = 42 células (índices 0 a 41). Conserto:
//    malloc((size_t) (m + 1) * w * sizeof *c).
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// diff de dois vetores de linhas, com a tabela dos sufixos num bloco do malloc
int compara_versoes(const char *a[], int m, const char *b[], int n) {
    int w = n + 1;
    int *c = malloc((size_t) m * n * sizeof *c);
    if (c == NULL) {
        return 1;
    }
    for (int i = m; i >= 0; i--) {
        for (int j = n; j >= 0; j--) {
            if (i == m || j == n) {
                c[i * w + j] = 0;
            } else if (strcmp(a[i], b[j]) == 0) {
                c[i * w + j] = c[(i + 1) * w + j + 1] + 1;
            } else {
                int baixo = c[(i + 1) * w + j], dir = c[i * w + j + 1];
                c[i * w + j] = baixo >= dir ? baixo : dir;
            }
        }
    }
    int i = 0, j = 0;
    while (i < m || j < n) {
        if (i < m && j < n && strcmp(a[i], b[j]) == 0) {
            printf("  %s\n", a[i]);
            i++;
            j++;
        } else if (j == n || (i < m && c[(i + 1) * w + j] >= c[i * w + j + 1])) {
            printf("- %s\n", a[i++]);
        } else {
            printf("+ %s\n", b[j++]);
        }
    }
    free(c);
    return 0;
}

int main(void) {
    const char *ida[] = {"Terminal", "Centro", "Hospital", "Universidade", "Praia"};
    const char *nova[] = {"Terminal", "Mercado", "Centro", "Universidade",
                          "Praia", "Aeroporto"};
    printf("Itinerário da linha 42:\n");
    return compara_versoes(ida, 5, nova, 6);
}
