// Lista · Módulo 20 · Divisão e conquista e algoritmos gulosos
// Exercício P2009 · ★☆☆ · Quando a razão engana
//
// A mochila fracionária é resolvida pelo guloso da razão valor/peso. Na
// mochila 0/1 (cada item vai inteiro ou não vai), o mesmo guloso pode
// errar. Uma mochila de 50 kg e três itens:
//
//   item   peso   valor
//   TV      10     600
//   som     20    1000
//   PC      30    1200
//
// O programa abaixo já tem o guloso 0/1 (pega pela razão, inteiro, se
// couber). Complete otimo(), que testa os 2^3 subconjuntos por máscara de
// bits (assunto 0125) e devolve o maior valor que cabe. Mostre os dois.
//
//   Saída esperada:
//   Guloso pela razão: R$ 1600
//   Ótimo (força bruta): R$ 2200
//
// Dicas:
// 1. for (int m = 0; m < (1 << N); m++): some peso e valor dos itens com o
//    bit ligado; se o peso cabe e o valor é o maior até agora, guarde.
// 2. As razões são 60, 50 e 40 R$/kg: o guloso pega TV e som e sobram 20
//    kg, onde o PC não cabe.
// 3. Resposta esperada: guloso R$ 1600, ótimo R$ 2200 (som + PC).
//
// Escreva sua resposta abaixo (complete o código):

#include <stdio.h>

#define N 3
#define CAP 50

const char *nome[N] = {"TV", "som", "PC"};
const int peso[N] = {10, 20, 30};
const int valor[N] = {600, 1000, 1200};

int guloso(void) {
    int livre = CAP, total = 0;
    for (int i = 0; i < N; i++) { // os itens já estão por razão decrescente
        if (peso[i] <= livre) {
            livre -= peso[i];
            total += valor[i];
        }
    }
    return total;
}

int otimo(void) {
    // COMPLETE AQUI
    return 0;
}

int main(void) {
    printf("Guloso pela razão: R$ %d\n", guloso());
    printf("Ótimo (força bruta): R$ %d\n", otimo());
    return 0;
}
