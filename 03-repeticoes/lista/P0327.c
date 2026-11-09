// Lista · Módulo 03 · Laços
// Exercício P0327 · ★★★ · O juro escondido no parcelamento
//
// A loja anuncia uma TV de R$ 1000.00 "em 10 vezes de R$ 120.00". Qual é o juro
// mensal escondido? Não há fórmula direta, mas dá para achar por bissecção: a
// parcela P(i) = V · i / (1 − (1 + i)^−n) cresce com i. Comece com a taxa entre
// 0.0001 e 1 (0,01% e 100%), teste o meio, e jogue fora a metade em que a
// resposta não está, até o intervalo ficar menor que 0.0000001. Mostre a taxa
// e quantas voltas foram precisas:
//
//   Saída esperada:
//   Taxa mensal: 3.46%
//   Voltas da bissecção: 24
//   Conferindo: parcela de R$ 120.00
//
// Dicas:
// 1. while (alto - baixo > 0.0000001) { meio = (baixo + alto) / 2; ... }.
// 2. Se a parcela com a taxa do meio passa de 120, a taxa certa é menor: alto
//    = meio. Senão, baixo = meio.
// 3. Para conferir, calcule a parcela de novo com a taxa achada.
// 4. Resposta esperada: Taxa mensal: 3.46%.
//
// Escreva sua resposta abaixo:

#include <math.h>
#include <stdio.h>

int main(void) {

    return 0;
}
