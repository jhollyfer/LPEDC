// Lista · Módulo 29 · Grafos: ciclos e cortes; problemas difíceis
// Exercício P2920 · ★★☆ · Quatro heurísticas contra o ótimo
//
// Nove encomendas (em kg) vão em motos que levam 10 kg: 6, 3, 7, 2, 5, 4,
// 5, 3, 5. Compare next fit, first fit, best fit e first fit decrescente
// com o ótimo, que você acha por backtracking: tente pôr cada encomenda
// (na ordem decrescente) em cada moto já aberta onde caiba ou numa nova, e
// corte quando o número de motos já igualar o melhor achado.
//
//   Saída esperada:
//   Next fit: 5
//   First fit: 5
//   Best fit: 5
//   First fit decrescente: 4
//   Ótimo: 4
//
// Dicas:
// 1. Escreva cada heurística como int nome(const int x[], int n). O FFD chama o
//    first fit numa cópia ordenada.
// 2. No backtracking, bt(i, motos) com livre[] global; ao abrir moto nova
//    pela primeira vez já não adianta tentar abrir outra para o mesmo item.
// 3. Resposta esperada: a saída acima. Soma 40: o limite inferior é 4.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    return 0;
}
