// Lista · Módulo 22 · Árvores e conjuntos avançados
// Exercício P2223 · ★★★ · As estradas que a cheia fecha
//
// Seis comunidades (0 a 5) são ligadas por 7 estradas de terra. Na cheia,
// a Defesa Civil já sabe a ordem em que as estradas vão ficar alagadas:
//
//   ordem:   1    2    3    4    5    6    7
//   estrada 0-1  2-3  1-2  3-4  4-5  0-5  2-4
//
// Depois de cada fechamento, quantos grupos de comunidades ainda se
// alcançam? O union-find sabe UNIR, mas não sabe separar. O truque é
// pensar AO CONTRÁRIO: comece com tudo fechado (6 grupos) e reabra as
// estradas da última para a primeira; o número de grupos antes de reabrir
// a estrada k é a resposta depois de fechar a estrada k. Escreva do zero
// (union-find com posto e compressão) e mostre a resposta na ordem dos
// fechamentos.
//
//   Saída esperada:
//   Fecha 0-1: 1 grupo(s)
//   Fecha 2-3: 1 grupo(s)
//   Fecha 1-2: 2 grupo(s)
//   Fecha 3-4: 3 grupo(s)
//   Fecha 4-5: 4 grupo(s)
//   Fecha 0-5: 5 grupo(s)
//   Fecha 2-4: 6 grupo(s)
//
// Dicas:
// 1. grupos[k] = número de componentes com só as estradas k + 1, ..., 7
//    abertas (as que ainda não fecharam). Calcule de k = 7 até k = 1.
// 2. Reabrir a estrada k: une as pontas; se eram raízes diferentes, os
//    componentes caem 1.
// 3. Resposta esperada: 1 1 2 3 4 5 6.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
