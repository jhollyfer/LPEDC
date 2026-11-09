// Lista · Módulo 24 · Busca de padrões em texto
// Exercício P2410 · ★☆☆ · O letreiro que gira
//
// O letreiro do ônibus mostra "030 CENTRO " e gira 3 letras para a
// esquerda a cada passo. Escreva do zero gira(s, k), que roda a string k
// casas para a esquerda NO PRÓPRIO VETOR, sem vetor auxiliar, com o
// truque das três inversões: inverta s[0..k-1], depois s[k..n-1], depois a
// string inteira. Mostre o letreiro entre colchetes antes e depois de cada
// um de 4 passos. Por fim gire "ABCDE" 12 casas.
//
//   Saída esperada:
//   [030 CENTRO ]
//   [ CENTRO 030]
//   [NTRO 030 CE]
//   [O 030 CENTR]
//   [30 CENTRO 0]
//   ABCDE girado 12: CDEAB
//
// Dicas:
// 1. Escreva antes inverte(s, i, j), que troca s[i] com s[j] e anda até
//    os índices se cruzarem.
// 2. Girar n casas é não girar: use k %= n antes.
// 3. Resposta esperada: depois do 4º passo, [30 CENTRO 0]; ABCDE girado
//    12 vira CDEAB (12 % 5 = 2).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {

    return 0;
}
