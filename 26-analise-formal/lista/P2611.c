// Lista · Módulo 26 · Notação assintótica, somatórios e espaço
// Exercício P2611 · ★★☆ · O sanduíche completo
//
// O fechamento mensal da farmácia faz f(n) = 4n² + 30n + 100 operações com n
// produtos. Escreva n0_teto(c) e n0_piso(c) (testando n de 1 até 100000) e
// mostre o n0 do teto para c = 5, 6 e 8, e o do piso para c = 4. No fim,
// escreva a conclusão com os valores de c1, c2 e n0 do Θ (use o teto com
// c = 5):
//
//   Saída esperada:
//   teto c = 5: n0 = 34
//   teto c = 6: n0 = 18
//   teto c = 8: n0 = 10
//   piso c = 4: n0 = 1
//   Θ(n²) com c1 = 4, c2 = 5 e n0 = 34
//
// Dicas:
// 1. Teto: falha quando f(n) > c n². Piso: falha quando f(n) < c n².
// 2. À mão: 4n² + 30n + 100 <= 5n² vira n² - 30n - 100 >= 0, n >= 33,2.
// 3. O piso com c = 4 vale desde n = 1, então o n0 do Θ é o do teto.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
