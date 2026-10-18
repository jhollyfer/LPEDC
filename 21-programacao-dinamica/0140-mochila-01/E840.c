// 0140 · Mochila 0/1
// Exercício E840 · ★★★
//
// Um drone de entregas carrega até 10 kg E até 8 litros de volume no
// compartimento. Há seis pacotes esperando, cada um com peso, volume e o
// frete que paga:
//
//   pacote  peso (kg)  volume (L)  frete (R$)
//     1         3          4           25
//     2         4          2           30
//     3         2          3           18
//     4         5          3           40
//     5         1          2            9
//     6         3          3           22
//
// Agora há DUAS capacidades. Estenda a ideia da mochila 0/1 para uma tabela
// de três dimensões, t[i][p][v] = maior frete usando os pacotes 1..i com
// até p kg e v litros. Mostre o frete máximo, os pacotes (do último para o
// primeiro, como sai da volta pela tabela), o peso e o volume usados, e
// confira o valor com uma força bruta pelos 2^6 subconjuntos.
//
//   Saída esperada:
//   Frete máximo: R$ 79
//   Pacotes: 5 4 2
//   Usa 10 kg e 7 L
//   Força bruta: R$ 79
//
// Dicas:
// 1. static int t[7][11][9]; começa toda zerada, o que já resolve a "linha"
//    i = 0.
// 2. Três laços (i, p, v). O pacote i só pode entrar se peso[i] <= p E
//    volume[i] <= v; aí a outra opção é frete[i] + t[i - 1][p - peso[i]]
//    [v - volume[i]].
// 3. A recuperação é a mesma de antes, descontando peso e volume juntos.
// 4. A tabela tem 7 x 11 x 9 = 693 células: o custo é O(n x P x V).
// 5. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
