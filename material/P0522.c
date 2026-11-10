// Lista · Módulo 05 · Vetores, matrizes e strings
// Exercício P0522 · ★★★ · A matriz esparsa do estacionamento
//
// Um estacionamento de 5 andares e 6 setores anota quantos carros estão
// parados em cada setor. Quase tudo é zero:
//
//   int m[5][6] = {{0, 0, 3, 0, 0, 0},
//                  {0, 0, 0, 0, 0, 7},
//                  {1, 0, 0, 0, 0, 0},
//                  {0, 0, 4, 0, 0, 0},
//                  {0, 2, 0, 0, 0, 0}};
//
// Guardar 30 números para 5 que importam é desperdício. Uma MATRIZ ESPARSA
// guarda só as triplas (linha, coluna, valor) dos que não são zero. Escreva:
// - int compactar(int m[5][6], int t[][3]): preenche as triplas, varrendo
//   linha por linha, e devolve quantas são;
// - int transpor(int t[][3], int k, int tt[][3]): monta as triplas da
//   transposta (6x5) JÁ em ordem de linha, sem montar a matriz cheia;
// - void mostrar_cheia(int t[][3], int k, int linhas, int colunas): mostra
//   a matriz completa a partir das triplas (zero onde não há tripla).
//
//   Saída esperada:
//   5 de 30 casas guardadas
//   Triplas: (0,2,3) (1,5,7) (2,0,1) (3,2,4) (4,1,2)
//   Transposta: (0,2,1) (1,4,2) (2,0,3) (2,3,4) (5,1,7)
//   Transposta cheia (6x5):
//   0 0 1 0 0
//   0 0 0 0 2
//   3 0 0 4 0
//   0 0 0 0 0
//   0 0 0 0 0
//   0 7 0 0 0
//
// Dicas:
// 1. Na transposta, a tripla (l, c, v) vira (c, l, v). Para sair em ordem de
//    linha da transposta, percorra as colunas c = 0 a 5 da original e, para
//    cada uma, passe pelas k triplas pegando as que têm coluna c.
// 2. Para mostrar a cheia sem montar a matriz, para cada (i, j) procure uma
//    tripla com linha i e coluna j; achou, mostra o valor; senão, 0.
// 3. As triplas cabem em int t[30][3] (no pior caso, nada é zero).
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {
    int m[5][6] = {{0, 0, 3, 0, 0, 0},
                   {0, 0, 0, 0, 0, 7},
                   {1, 0, 0, 0, 0, 0},
                   {0, 0, 4, 0, 0, 0},
                   {0, 2, 0, 0, 0, 0}};
    (void) m; // apague esta linha quando escrever

    return 0;
}
