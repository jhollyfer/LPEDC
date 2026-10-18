// 0071 · Eficiência: contar passos
// Exercício E425 · ★★★
//
// Este programa busca três senhas de atendimento do banco e deveria mostrar
// os passos 1, 4 e 6. Ele compila sem aviso, mas mostra 0, 3 e 9. Há DOIS
// erros na instrumentação (a busca em si está certa). Ache e conserte os dois.
//
//   Saída esperada:
//   senha 12: passos 1
//   senha 8: passos 4
//   senha 40: passos 6
//
// Dicas:
// 1. Faça o teste de mesa da senha 12, que está na posição 0. Quando o
//    passos++ roda?
// 2. Depois olhe a senha 8: o 3 que apareceu é dela ou é acumulado?
// 3. Resposta esperada: (1) o passos++ está depois do if que dá return, então
//    a comparação que acerta nunca é contada: ele tem de vir antes do if;
//    (2) o contador é zerado uma vez só, antes do for do main: tem de ser
//    zerado dentro do for, antes de cada busca.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

int passos = 0;

int busca(const int v[], int n, int alvo) {
    for (int i = 0; i < n; i++) {
        if (v[i] == alvo) {
            return i;
        }
        passos++;
    }
    return -1;
}

int main(void) {
    int senhas[6] = {12, 5, 30, 8, 19, 27};
    int alvos[3] = {12, 8, 40};

    passos = 0;
    for (int k = 0; k < 3; k++) {
        busca(senhas, 6, alvos[k]);
        printf("senha %d: passos %d\n", alvos[k], passos);
    }
    return 0;
}
