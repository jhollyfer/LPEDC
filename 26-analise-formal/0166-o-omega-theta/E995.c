// 0166 · O, Ω e Θ de verdade
// Exercício E995 · ★★★
//
// Conserte o programa. O sistema do torneio de futsal monta a rodada com
// 2n² operações; com n ímpar, um time folga e a tabela é refeita (30n a
// mais). O programa diz que custo(n) <= 3n² vale "a partir de n0 = 2",
// mas a conferência logo abaixo acha falhas:
//
//   Saída que aparece:
//   custo(n) <= 3n² a partir de n0 = 2
//   falhas de n0 até 1000: 14
//
// Corrija a função acha_n0 para que ela respeite o "para todo n >= n0" da
// definição de O:
//
//   Saída esperada:
//   custo(n) <= 3n² a partir de n0 = 30
//   falhas de n0 até 1000: 0
//
// Dicas:
// 1. A função para no primeiro n que funciona. Com n = 2 (par) funciona,
//    mas n = 3 (ímpar) volta a falhar.
// 2. Percorra todos os n até LIMITE e faça n0 = n + 1 a cada falha.
// 3. À mão: com n ímpar, 2n² + 30n <= 3n² vira n >= 30, então o último
//    ímpar que falha é 29 e o n0 é 30.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

#define LIMITE 1000

// operações para montar a rodada do torneio com n times
long custo(long n) {
    long base = 2 * n * n;
    if (n % 2 == 1) {
        base += 30 * n;                  // um time folga: refaz a tabela
    }
    return base;
}

// menor n0 com custo(n) <= c * n² para todo n >= n0
long acha_n0(long c) {
    for (long n = 1; n <= LIMITE; n++) {
        if (custo(n) <= c * n * n) {
            return n;                    // achou um n que funciona
        }
    }
    return LIMITE + 1;
}

int main(void) {
    long n0 = acha_n0(3);
    printf("custo(n) <= 3n² a partir de n0 = %ld\n", n0);

    int falhas = 0;
    for (long n = n0; n <= LIMITE; n++) {
        if (custo(n) > 3 * n * n) {
            falhas++;
        }
    }
    printf("falhas de n0 até %d: %d\n", LIMITE, falhas);
    return 0;
}
