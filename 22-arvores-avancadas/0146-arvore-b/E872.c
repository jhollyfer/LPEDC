// 0146 · Árvore B
// Exercício E872 · ★☆☆
//
// A estação meteorológica guardou as máximas de 15 dias numa árvore B
// (arvoreb.h). Escreva minimo(r, &lidos) e maximo(r, &lidos): elas devolvem
// a menor e a maior chave e contam, em lidos, quantos nós foram visitados.
// Não percorra a árvore inteira: cada uma desce um caminho só.
//
//   Saída esperada:
//     nível 0: [27]
//     nível 1: [19 22] [31]
//     nível 2: [17 18] [21] [24 25 26] [29 30] [33 35 36]
//   mínima: 17 graus (3 nós lidos)
//   máxima: 36 graus (3 nós lidos)
//
// Dicas:
// 1. A menor chave está na folha mais à esquerda: desça por filho[0] até
//    r->folha ser verdadeiro e devolva chave[0].
// 2. A maior está na folha mais à direita: desça por filho[r->n] e devolva
//    chave[r->n - 1].
// 3. Resposta esperada: a saída acima. Como todas as folhas estão no mesmo
//    nível, os dois caminhos leem altura + 1 nós.
//
// Escreva sua resposta abaixo (escreva as funções e complete o main):

#include <stdio.h>
#include "arvoreb.h"

int main(void) {
    int temperaturas[] = {27, 31, 19, 24, 35, 22, 18, 29, 33, 21, 26, 30, 17, 36, 25};
    NoB *r = NULL;
    for (int i = 0; i < 15; i++) {
        r = ab_insere(r, temperaturas[i]);
    }
    ab_mostra(r);

    r = ab_libera(r);
    return 0;
}
