// 0096 · Comparando: estabilidade, custo e qsort
// Exercício E574 · ★★☆
//
// Os saldos (em centavos) de cinco contas de uma corretora precisam sair do
// menor para o maior. A compara abaixo é a "versão curta" que aparece em
// muito tutorial. O erro é de propósito: rode e veja o UBSan reclamar
// ("signed integer overflow") e a ordem sair errada. Conserte a compara sem
// mudar o tipo int e rode de novo.
//
//   Saída esperada (depois de consertar):
//   -1500000000
//   -7
//   15
//   1000000000
//   2000000000
//
// Dicas:
// 1. Quanto é 2000000000 - (-1500000000)? Cabe num int (assunto 0003)?
// 2. A compara não precisa devolver a diferença, só o SINAL certo.
// 3. (x > y) - (x < y) vale 1, 0 ou -1 e nunca estoura.
// 4. Resposta esperada: x - y dá overflow com valores grandes de sinais
//    opostos; o resultado vira negativo e a compara diz que 2000000000 vem
//    antes de -1500000000. Conserto: return (x > y) - (x < y);
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <stdlib.h>

int compara(const void *a, const void *b) {
    int x = *(const int *) a;
    int y = *(const int *) b;
    return x - y;
}

int main(void) {
    int saldos[] = {2000000000, -1500000000, 15, -7, 1000000000};
    size_t n = sizeof saldos / sizeof saldos[0];

    qsort(saldos, n, sizeof saldos[0], compara);
    for (size_t i = 0; i < n; i++) {
        printf("%d\n", saldos[i]);
    }
    return 0;
}
