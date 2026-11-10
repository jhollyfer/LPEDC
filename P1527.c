// Lista · Módulo 15 · Tabelas hash
// Exercício P1527 · ★★★ · Dispersão dupla com o tamanho errado
//
// Na dispersão dupla, h(k, i) = (h1(k) + i · h2(k)) % m, a sequência de k só
// visita todas as m posições se h2(k) e m não tiverem divisor comum. Com m
// primo isso sempre vale; com m = 8, um passo par deixa metade da tabela de
// fora. Mostre o problema.
//
// Use h1(k) = k % m e h2(k) = 1 + k % (m - 1). Escreva:
//
//   int sondagem(int k, int i, int m)
//   int visitadas(int k, int m)    quantas posições DIFERENTES a sequência
//                                  de k visita em m tentativas
//   void testa(int m, const int chaves[], int n)
//
// testa monta a tabela do zero e, para cada chave, mostra h2, quantas
// posições ela visita e onde ficou (ou "NÃO COUBE", se as m tentativas só
// acharam posições ocupadas). Rode com m = 8 e com m = 11, chaves
// 3, 19, 43, 99, 59, 27.
//
//   Saída esperada:
//   m = 8:
//     3: h2 = 4, visita 2 de 8 posições, ficou na 3
//     19: h2 = 6, visita 4 de 8 posições, ficou na 1
//     43: h2 = 2, visita 4 de 8 posições, ficou na 5
//     99: h2 = 2, visita 4 de 8 posições, ficou na 7
//     59: h2 = 4, visita 2 de 8 posições, NÃO COUBE
//     27: h2 = 7, visita 8 de 8 posições, ficou na 2
//   m = 11:
//     3: h2 = 4, visita 11 de 11 posições, ficou na 3
//     19: h2 = 10, visita 11 de 11 posições, ficou na 8
//     43: h2 = 4, visita 11 de 11 posições, ficou na 10
//     99: h2 = 10, visita 11 de 11 posições, ficou na 0
//     59: h2 = 10, visita 11 de 11 posições, ficou na 4
//     27: h2 = 8, visita 11 de 11 posições, ficou na 5
//
// Dicas:
// 1. A sequência visita m / mdc(h2, m) posições: com m = 8 e passo 4, só 2
//    (a 3 e a 7).
// 2. O 59 não coube com a tabela pela metade: as posições livres existiam,
//    mas a sequência dele nunca passa por elas.
// 3. O Cormen dá duas saídas: m primo, ou m potência de 2 com h2 sempre
//    ímpar.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define VAZIO -1

int main(void) {

    return 0;
}
