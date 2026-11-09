// Lista · Módulo 25 · Estruturas especiais
// Exercício P2530 · ★★★ · Três políticas no mesmo balcão
//
// No balcão da farmácia, 10 remédios (0 a 9) são pedidos com frequências
// muito desiguais: o remédio i sai com peso 2520 / (i + 1). A lista começa
// AO CONTRÁRIO (9, 8, ..., 0), o pior caso. Sorteie 5000 pedidos com o
// gerador fixo (s = s * 1103515245u + 12345u, começando em 2026, e o
// sorteio (s >> 16) % soma_dos_pesos) e compare o custo total e médio de:
// lista fixa, mover para a frente, transposição, contagem e a ótima fixa
// (em ordem de frequência, que só dá para montar sabendo o futuro).
// Escreva tudo do zero com vetores.
//
//   Saída esperada:
//   Frequências: 1755 894 585 441 320 251 237 192 159 166
//   Ordem ótima: 0 1 2 3 4 5 6 7 9 8
//    custo  média  política
//    38546   7.71  fixa (ao contrário)
//    20786   4.16  mover para a frente
//    18027   3.61  transposição
//    16521   3.30  contagem
//    16447   3.29  ótima fixa
//
// Dicas:
// 1. Para sortear com pesos: tire o sorteio de cada peso, em ordem, até
//    ele ficar menor que o peso da vez; esse é o remédio.
// 2. Na contagem, guarde c[i] junto com a posição: ao trocar dois itens,
//    troque as contagens também.
// 3. Resposta esperada: fixa 38546, MTF 20786, transposição 18027,
//    contagem 16521 e ótima 16447. Começando no pior caso, o MTF corrige a
//    lista na hora, mas paga por jogar na frente até remédio raro.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
