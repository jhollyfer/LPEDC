// 0008 · Conversão e cast
// Exercício E048 · ★★★
//
// Letras são números, e as contas com elas seguem as regras de conversão.
// Escreva um programa que comece com char letra = 'g'; e mostre as linhas
// abaixo. Regras: tirando a própria letra 'g', só valem os literais 'a',
// 'A', 1 e 3 (nada de escrever 'G', 71, 7, 'j' ou 32). Na última linha, use
// as variáveis double x = 3.7, y = 3.7 e casts para int.
//
//   Saída esperada:
//   Letra: g (código 103)
//   Maiúscula: G (código 71)
//   Posição no alfabeto: 7
//   Três adiante: j
//   Somando e cortando: 7; cortando e somando: 6
//
// Dicas:
// 1. Numa conta, o char vira int: letra - 'a' é a distância da letra até o
//    'a' (g está 6 depois do a).
// 2. Maiúscula: a mesma distância, a partir do 'A'. Mostre o resultado com
//    %c e com %d.
// 3. Somar antes de cortar não é o mesmo que cortar antes de somar:
//    (int) (x + y) e (int) x + (int) y.
// 4. Resposta esperada: as cinco linhas acima. A maiúscula é
//    letra - 'a' + 'A'; a posição, letra - 'a' + 1; três adiante,
//    letra + 3; e 7.4 cortado dá 7, enquanto 3 + 3 dá 6.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
