// 0140 · Mochila 0/1
// Exercício E839 · ★★★
//
// Numa mudança, você pode despachar só 10 kg no bagageiro do ônibus e quer
// levar os objetos de maior valor (os outros vão de transportadora, mais
// tarde). O programa abaixo monta a tabela certa e acha o valor máximo, mas
// a RECUPERAÇÃO tem um erro de propósito: o AddressSanitizer para o
// programa com "stack-buffer-overflow" (e o UBSan antes avisa de um índice
// -1). Ache, conserte e rode até a saída ficar limpa.
//
//   Saída esperada (depois de consertar):
//   Valor máximo: R$ 97
//   Leva: micro-ondas bicicleta notebook
//   Sobrou: 0 kg
//
// Dicas:
// 1. A mensagem do UBSan diz a linha e o índice. Em que linha da tabela
//    (que i) e com que c isso acontece?
// 2. A volta começa no item 5 com c = 10. Depois de levar o micro-ondas e
//    a bicicleta, o c chegou a quanto? E quanto pesa o violão, o próximo a
//    ser testado?
// 3. O teste "t[i][c] == valor[i] + t[i - 1][c - peso[i]]" só faz sentido
//    quando o item cabe. Na montagem da tabela, esse cuidado existe.
// 4. Resposta esperada: falta conferir peso[i] <= c antes de ler
//    t[i - 1][c - peso[i]]. Com c = 3 e o violão de 4 kg, o índice fica -1.
//    Conserto: if (peso[i] <= c && t[i][c] == ...).
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

#define N 5
#define W 10

int main(void) {
    const char *nome[N + 1] = {"", "TV", "notebook", "violão", "bicicleta", "micro-ondas"};
    int peso[N + 1] = {0, 6, 3, 4, 2, 5};
    int valor[N + 1] = {0, 50, 40, 30, 22, 35};
    int t[N + 1][W + 1];

    for (int c = 0; c <= W; c++) {
        t[0][c] = 0;
    }
    for (int i = 1; i <= N; i++) {
        for (int c = 0; c <= W; c++) {
            t[i][c] = t[i - 1][c];
            if (peso[i] <= c && valor[i] + t[i - 1][c - peso[i]] > t[i][c]) {
                t[i][c] = valor[i] + t[i - 1][c - peso[i]];
            }
        }
    }
    printf("Valor máximo: R$ %d\n", t[N][W]);

    printf("Leva:");
    int c = W;
    for (int i = N; i >= 1; i--) {
        // o item i entrou se o valor da célula é "valor[i] + o resto"
        if (t[i][c] == valor[i] + t[i - 1][c - peso[i]]) {
            printf(" %s", nome[i]);
            c -= peso[i];
        }
    }
    printf("\nSobrou: %d kg\n", c);
    return 0;
}
