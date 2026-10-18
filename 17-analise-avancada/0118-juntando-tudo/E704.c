// 0118 · Juntando tudo
// Exercício E704 · ★☆☆
//
// Complete prever(t0, n0, n1, quadratico): a partir do tempo t0 medido
// com n0 elementos, devolve o tempo previsto para n1 elementos. Se
// quadratico for 1, o fator é (n1/n0)²; se for 0, é
// (n1 log₂ n1) / (n0 log₂ n0). O main já faz quatro previsões com medidas
// de um computador de escritório: o insertion levou 0,8 s para 20 mil
// pedidos e o merge sort, 0,004 s:
//
//   Saída esperada:
//   insertion, 20 mil -> 100 mil:    20.0000 s
//   insertion, 20 mil -> 1 milhão: 2000.0000 s
//   merge,     20 mil -> 100 mil:     0.0233 s
//   merge,     20 mil -> 1 milhão:    0.2790 s
//
// Dicas:
// 1. log2 está em <math.h> (o rodar já liga a biblioteca matemática).
// 2. Use double em tudo: n1 * n1 com int estoura para n1 = 1 milhão.
// 3. Resposta esperada: a saída acima. 2000 s são mais de 33 minutos,
//    contra um quarto de segundo. Entrada 50 vezes maior: o insertion fica
//    2500 vezes mais lento, o merge, só 70.
//
// Escreva sua resposta abaixo (complete prever):

#include <math.h>
#include <stdio.h>

double prever(double t0, double n0, double n1, int quadratico) {
    (void)n0; // apague estas três linhas
    (void)n1;
    (void)quadratico;
    return t0;
}

int main(void) {
    printf("insertion, 20 mil -> 100 mil: %10.4f s\n", prever(0.8, 20000, 100000, 1));
    printf("insertion, 20 mil -> 1 milhão: %9.4f s\n", prever(0.8, 20000, 1000000, 1));
    printf("merge,     20 mil -> 100 mil: %10.4f s\n", prever(0.004, 20000, 100000, 0));
    printf("merge,     20 mil -> 1 milhão: %9.4f s\n", prever(0.004, 20000, 1000000, 0));
    return 0;
}
