// 0102 · Árvores
// Exercício E612 · ★★★
//
// O menu do app de delivery é uma árvore:
//
//   app
//   ├── lanches
//   │   ├── x-salada
//   │   └── x-bacon
//   └── bebidas
//       ├── suco
//       └── refri
//           ├── lata
//           └── 2 litros
//
// Escreva do zero (struct, montagem, função e liberação) um programa que
// imprime o caminho da raiz até cada folha, com "/" entre os nomes, como um
// endereço de pasta, e no fim conta os caminhos:
//
//   Saída esperada:
//   app/lanches/x-salada
//   app/lanches/x-bacon
//   app/bebidas/suco
//   app/bebidas/refri/lata
//   app/bebidas/refri/2 litros
//   Total de caminhos: 5
//
// Dicas:
// 1. Guarde o caminho até o nó atual num vetor const char *trilha[10] e
//    passe junto a profundidade: caminhos(n, trilha, prof).
// 2. Ao entrar no nó, faça trilha[prof] = n->nome. Se for folha, imprima
//    trilha[0..prof] separados por "/" e devolva 1; senão, chame para cada
//    filho com prof + 1 e some.
// 3. Resposta esperada: as 5 linhas acima e "Total de caminhos: 5". Libere
//    tudo: o rodar não pode acusar vazamento.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    return 0;
}
