// 0126 · Permutações
// Exercício E755 · ★★★
//
// Ache o bug. Um mágico quer listar todas as ordens das cartas A, 2, 3 e 4
// para ensaiar um truque. Devem sair 4! = 24 ordens, todas diferentes, seis
// por linha. O programa compila sem aviso e roda, mas mostra menos ordens do
// que devia. O erro está numa linha só. Ache, conserte e rode de novo.
//
//   Saída esperada:
//   A234 A243 A324 A342 A432 A423
//   2A34 2A43 23A4 234A 243A 24A3
//   32A4 324A 3A24 3A42 34A2 342A
//   423A 42A3 432A 43A2 4A32 4A23
//   24 ordens
//
// Dicas:
// 1. Acrescente um printf no começo de embaralha mostrando i. Algum nível é
//    pulado?
// 2. A chamada recursiva decide a PRÓXIMA posição. Depois de escolher quem
//    fica na posição i, a próxima é a i + 1, não importa de onde veio a
//    carta escolhida.
// 3. Resposta esperada: a chamada era embaralha(v, j + 1); o certo é
//    embaralha(v, i + 1). Com o erro saem só 8 ordens.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

#define N 4

int total = 0;

void troca(char *a, char *b) {
    char t = *a;
    *a = *b;
    *b = t;
}

void embaralha(char v[], int i) {
    if (i == N) {
        total++;
        printf("%s%s", v, total % 6 == 0 ? "\n" : " ");
        return;
    }
    for (int j = i; j < N; j++) {
        troca(&v[i], &v[j]);
        embaralha(v, j + 1);
        troca(&v[i], &v[j]);
    }
}

int main(void) {
    char cartas[N + 1] = "A234";
    embaralha(cartas, 0);
    if (total % 6 != 0) {
        printf("\n");
    }
    printf("%d ordens\n", total);
    return 0;
}
