// 0097 · Árvores
// Exercício E580 · ★★☆
//
// Cada pasta guarda arquivos soltos (campo mb, em megabytes):
//
//   casa (5)
//   ├── fotos (10)
//   │   ├── praia (300)
//   │   └── natal (120)
//   └── contas (2)
//       ├── agua (5)
//       └── luz (8)
//
// Escreva tamanho(n), que soma a pasta com tudo que está dentro dela, e duas
// funções que mostram o tamanho total de cada pasta:
//
// - du(n): imprime "<total> MB  <nome>", com cada pasta DEPOIS de todas as
//   subpastas dela (a raiz por último);
// - arvore(n, prof): imprime "nome (total MB)", a pasta ANTES das
//   subpastas, recuada 2 espaços por nível.
//
//   Saída esperada:
//   -- du --
//   300 MB  praia
//   120 MB  natal
//   430 MB  fotos
//   5 MB  agua
//   8 MB  luz
//   15 MB  contas
//   450 MB  casa
//   -- arvore --
//   casa (450 MB)
//     fotos (430 MB)
//       praia (300 MB)
//       natal (120 MB)
//     contas (15 MB)
//       agua (5 MB)
//       luz (8 MB)
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILHOS 4

typedef struct No {
    char nome[16];
    int mb; // arquivos soltos dentro desta pasta
    struct No *filhos[MAX_FILHOS];
    int qtd;
} No;

int main(void) {

    return 0;
}
