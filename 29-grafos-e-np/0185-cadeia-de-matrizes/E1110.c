// 0185 · Cadeia de matrizes
// Exercício E1110 · ★★★
//
// Um colega propõe uma regra gulosa (0133) para fugir da tabela: "olhe os
// pares vizinhos e multiplique primeiro o mais barato; repita até sobrar
// uma matriz". Teste a ideia na cadeia p = 10, 20, 5, 40, 30, 2. Escreva:
//
//   long guloso(void): mostra cada junção e devolve o total;
//   long otimo(void): a PD do texto, devolvendo m[1][5].
//
//   Saída esperada:
//   Guloso (junta o par vizinho mais barato):
//     junta 10x20 com 20x5: 1000
//     junta 10x5 com 5x40: 2000
//     junta 40x30 com 30x2: 2400
//     junta 10x40 com 40x2: 800
//   Guloso: 6200
//   PD: 3400
//
// Dicas:
// 1. No guloso, trabalhe numa cópia do vetor de dimensões. Juntar as
//    matrizes de dimensões p[i-1] x p[i] e p[i] x p[i+1] custa
//    p[i-1] · p[i] · p[i+1] e simplesmente apaga p[i] do vetor.
// 2. Em caso de empate, fique com o par mais à esquerda (o primeiro).
// 3. Resposta esperada: a saída acima. O guloso gasta quase o dobro: a
//    escolha barata de agora (10x20 por 20x5) deixa a dimensão 10 presa no
//    resultado. A PD começa pelo fim: A1 (A2 (A3 (A4 A5))), usando o 2
//    para eliminar o 30, o 40, o 5 e o 20, um de cada vez.
//
// Escreva sua resposta abaixo:

#include <limits.h>
#include <stdio.h>

int main(void) {

    return 0;
}
