// 0114 · Recorrências e árvore de recursão
// Exercício E683 · ★★★
//
// Conserte o programa. Ele acha a maior temperatura de 20 dias e a resposta
// está certa, mas ele é lento demais para o que faz:
//
//   Saída que aparece:
//   maior: 35 graus, 1048575 chamadas
//
// Com 30 dias, o mesmo programa faria mais de um bilhão de chamadas. Leia
// os argumentos das duas chamadas recursivas, escreva (num comentário) a
// recorrência que o código segue de verdade, e conserte a divisão para que
// cada chamada receba METADE do pedaço. Depois acrescente a medição para
// 30 dias:
//
//   Saída esperada:
//   maior: 35 graus, 39 chamadas
//   30 dias: maior 35 graus, 59 chamadas
//
// Dicas:
// 1. Com fim - ini = n, quantos elementos tem [ini, fim - 1)? E
//    [ini + 1, fim)? Os dois pedaços quase inteiros se sobrepõem.
// 2. O código segue T(n) = 2 T(n-1) + 1, a recorrência de Hanói: 2^n - 1
//    chamadas. Para n = 20, 2^20 - 1 = 1.048.575.
// 3. Use meio = ini + (fim - ini) / 2 e as chamadas [ini, meio) e
//    [meio, fim). Agora é T(n) = 2 T(n/2) + 1: 2n - 1 chamadas.
// 4. Resposta esperada: 39 chamadas para 20 dias e 59 para 30.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

long chamadas = 0;

// maior valor de t[ini..fim-1]
int maior(const int t[], int ini, int fim) {
    chamadas++;
    if (fim - ini == 1) {
        return t[ini];
    }
    int a = maior(t, ini, fim - 1);      // todos menos o último
    int b = maior(t, ini + 1, fim);      // todos menos o primeiro
    return a > b ? a : b;
}

int main(void) {
    int temp[30] = {28, 31, 27, 25, 30, 33, 29, 26, 24, 27,
                    32, 35, 30, 28, 26, 25, 29, 31, 34, 30,
                    27, 26, 28, 33, 35, 31, 29, 27, 26, 30};

    int m = maior(temp, 0, 20);
    printf("maior: %d graus, %ld chamadas\n", m, chamadas);
    return 0;
}
