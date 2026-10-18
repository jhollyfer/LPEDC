// 0089 · Busca sequencial
// Exercício E533 · ★★★
//
// A função abaixo deveria devolver a PRIMEIRA posição da senha procurada no
// painel do banco. Ela tem DOIS erros, de propósito. Rode com o rodar: o
// AddressSanitizer vai reclamar de um deles. Conserte os dois e rode de novo
// até a saída bater com a esperada.
//
//   Saída esperada (depois de consertar):
//   Primeira senha 7: posição 1
//   Primeira senha 99: posição -1
//
// Dicas:
// 1. Quantas voltas o laço dá para n = 6? Qual o último i?
// 2. Mesmo sem o erro de memória, que posição ela devolve para 7: 1, 3 ou 5?
// 3. Resposta esperada: i <= n lê v[6], fora do vetor (stack-buffer-overflow);
//    e, sem parar no primeiro encontro, pos guarda a ÚLTIMA ocorrência (5).
//    Conserto: i < n e return i assim que achar.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

int primeira(const int v[], int n, int x) {
    int pos = -1;
    for (int i = 0; i <= n; i++) {
        if (v[i] == x) {
            pos = i;
        }
    }
    return pos;
}

int main(void) {
    int senhas[] = {12, 7, 30, 7, 18, 7};
    int n = 6;

    printf("Primeira senha 7: posição %d\n", primeira(senhas, n, 7));
    printf("Primeira senha 99: posição %d\n", primeira(senhas, n, 99));
    return 0;
}
