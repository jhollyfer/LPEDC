// 0095 · Busca binária
// Exercício E569 · ★★★
//
// Alguém "modernizou" a busca binária trocando int por size_t, "porque índice
// nunca é negativo". O código compila sem nenhum aviso, acha o 35... e
// explode ao procurar o 3. O erro é de propósito: rode com o rodar e leia o
// que o AddressSanitizer diz. Explique o que acontece e conserte, mantendo
// size_t.
//
//   Saída esperada (depois de consertar):
//   35: posição 3
//   3: posição -1
//   vazio: posição -1
//
// Dicas:
// 1. Faça o teste de mesa da busca pelo 3: quanto vale meio na última volta?
// 2. Quanto é 0 - 1 num tipo sem sinal? (assunto 0008)
// 3. O vetor vazio (n = 0) tem o mesmo problema logo na primeira linha.
// 4. Resposta esperada: fim = meio - 1 com meio = 0 dá a volta para SIZE_MAX,
//    ini <= fim continua verdadeiro e v[meio] lê longe do vetor. Conserto:
//    intervalo semiaberto (fim = n, while (ini < fim), fim = meio), que nunca
//    subtrai 1 de um size_t.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <stddef.h>

int busca(const int v[], size_t n, int x) {
    size_t ini = 0, fim = n - 1;
    while (ini <= fim) {
        size_t meio = ini + (fim - ini) / 2;
        if (v[meio] == x) {
            return (int) meio;
        }
        if (v[meio] < x) {
            ini = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;
}

int main(void) {
    int tempos[] = {10, 20, 28, 35, 41, 57, 63};
    size_t n = sizeof tempos / sizeof tempos[0];

    printf("35: posição %d\n", busca(tempos, n, 35));
    printf("3: posição %d\n", busca(tempos, n, 3));
    printf("vazio: posição %d\n", busca(tempos, 0, 35));
    return 0;
}
