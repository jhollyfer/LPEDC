// 0097 · Árvores
// Exercício E577 · ★☆☆
//
// O site de uma loja organiza os produtos em categorias:
//
//   loja
//   ├── eletronicos
//   │   ├── celulares
//   │   └── tvs
//   │       ├── oled
//   │       └── led
//   ├── casa
//   │   └── cozinha
//   └── moda
//
// Escreva as funções novo, adiciona(pai, nome), altura e libera, monte a
// árvore no main e escreva ficha(n, prof), que imprime uma linha por
// categoria, recuada 2 espaços por nível, com a profundidade, o grau e a
// palavra "folha" quando o nó não tem filhos. Por fim, imprima a altura.
//
//   Saída esperada:
//   loja: prof 0, grau 3
//     eletronicos: prof 1, grau 2
//       celulares: prof 2, grau 0, folha
//       tvs: prof 2, grau 2
//         oled: prof 3, grau 0, folha
//         led: prof 3, grau 0, folha
//     casa: prof 1, grau 1
//       cozinha: prof 2, grau 0, folha
//     moda: prof 1, grau 0, folha
//   Altura: 3
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILHOS 4

typedef struct No {
    char nome[16];
    struct No *filhos[MAX_FILHOS];
    int qtd;
} No;

int main(void) {

    return 0;
}
