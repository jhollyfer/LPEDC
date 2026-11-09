// 0167 · Somatórios que saem de laços
// Exercício E1002 · ★★★
//
// Na feira há n bancas, numeradas de 1 a n. O fiscal p (p = 1..n) visita
// as bancas p, 2p, 3p, ... Escreva:
// - visitas(n), com dois laços, contando cada visita;
// - visitas_rapido(n), com UM laço só, que chega no mesmo total sabendo
//   quantas bancas o fiscal p visita sem andar por elas.
// Para n = 10, 100, ..., 1.000.000, mostre os dois totais, n ln n e a razão
// visitas / (n ln n):
//
//   Saída esperada:
//         n    visitas    rápido    n ln n  razão
//        10         27        27        23  1.173
//       100        482       482       461  1.047
//      1000       7069      7069      6908  1.023
//     10000      93668     93668     92103  1.017
//    100000    1166750   1166750   1151293  1.013
//   1000000   13970034  13970034  13815511  1.011
//
// Dicas:
// 1. O fiscal p visita n / p bancas (divisão inteira).
// 2. visitas é Θ(n log n): a soma harmônica n/1 + n/2 + ... + n/n.
//    visitas_rapido é Θ(n): uma conta por fiscal.
// 3. log de <math.h> é o logaritmo natural (ln). A razão desce para 1
//    devagar: é isso que "≈ n ln n" quer dizer.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <math.h>

int main(void) {

    return 0;
}
