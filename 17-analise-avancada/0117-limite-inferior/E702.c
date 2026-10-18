// 0117 · Limite inferior da ordenação
// Exercício E702 · ★★★
//
// O limite para 4 elementos é 5 comparações, e o insertion sort faz 6 no
// pior caso (E698). Escreva ordena4(v), que ordena 4 valores com NO
// MÁXIMO 5 comparações, todas pela função menor(). A estratégia:
//
//   1. compare v[0] com v[1]: fica um par (menor1, maior1);
//   2. compare v[2] com v[3]: outro par (menor2, maior2);
//   3. o menor de menor1 e menor2 é o mínimo de todos;
//   4. o maior de maior1 e maior2 é o máximo de todos;
//   5. sobram dois elementos: compare os dois para pôr o meio em ordem.
//
// O main já testa as 24 ordens possíveis:
//
//   Saída esperada:
//   24 ordens testadas, 24 certas
//   pior caso: 5 comparações (limite: 5)
//
// Dicas:
// 1. Copie os quatro valores para variáveis locais (lo1, hi1, lo2, hi2) e
//    troque dentro de cada par quando precisar.
// 2. No passo 3, quem perde (o maior dos dois "menores") é um dos do meio.
//    No passo 4, quem perde (o menor dos dois "maiores") é o outro.
// 3. No fim, escreva mínimo, meio, meio e máximo de volta em v[0..3].
// 4. Resposta esperada: a saída acima. Esse método atinge o limite: é
//    ótimo. Para 5 elementos o limite é 7, e também existe um método com
//    7 (bem mais chato de escrever).
//
// Escreva sua resposta abaixo (escreva ordena4):

#include <stdio.h>

int comparacoes = 0;

int menor(int a, int b) {
    comparacoes++;
    return a < b;
}

// ordena 4 valores com no máximo 5 comparações (use sempre menor())
void ordena4(int v[]) {
    (void)v; // apague esta linha e escreva a função
}

int main(void) {
    int precos[4] = {10, 20, 30, 40};
    int testadas = 0, certas = 0, pior = 0;
    for (int a = 0; a < 4; a++) {
        for (int b = 0; b < 4; b++) {
            for (int c = 0; c < 4; c++) {
                for (int d = 0; d < 4; d++) {
                    if (a == b || a == c || a == d || b == c || b == d || c == d) {
                        continue;
                    }
                    int v[4] = {precos[a], precos[b], precos[c], precos[d]};
                    comparacoes = 0;
                    ordena4(v);
                    testadas++;
                    if (v[0] == 10 && v[1] == 20 && v[2] == 30 && v[3] == 40) {
                        certas++;
                    }
                    if (comparacoes > pior) {
                        pior = comparacoes;
                    }
                }
            }
        }
    }
    printf("%d ordens testadas, %d certas\n", testadas, certas);
    printf("pior caso: %d comparações (limite: 5)\n", pior);
    return 0;
}
