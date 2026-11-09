// Lista · Módulo 14 · Árvores
// Exercício P1417 · ★★☆ · As 4 passagens mais baratas
//
// Um site de passagens recebe os preços um de cada vez e quer, no fim, as
// k = 4 MAIS BARATAS, sem guardar todos os preços. Use um heap de MÁXIMO com
// no máximo 4 elementos: enquanto ele não está cheio, insira; depois, se o
// preço novo for menor que a raiz (a mais cara das 4 guardadas), ele toma o
// lugar da raiz e desce. No fim, tire os 4 do heap para mostrar do mais
// barato para o mais caro.
//
//   Preços: 780 455 920 610 390 1200 505 430 870 399 640 415
//
//   Saída esperada:
//   as 4 mais baratas: 390 399 415 430
//
// Dicas:
// 1. Escreva sobe(h, i) e desce(h, n, i) de um heap de máximo.
// 2. Parece ao contrário, mas é isso: para guardar os MENORES, o heap é de
//    MÁXIMO, porque quem você precisa descartar rápido é o maior deles.
// 3. Custa O(n log k), com memória O(k). Com k pequeno, quase O(n).
// 4. Ao extrair, o primeiro que sai é o mais caro: preencha a resposta de
//    trás para frente.
// 5. Resposta esperada: 390 399 415 430.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {
    int precos[] = {780, 455, 920, 610, 390, 1200, 505, 430, 870, 399, 640, 415};
    (void)precos;

    return 0;
}
