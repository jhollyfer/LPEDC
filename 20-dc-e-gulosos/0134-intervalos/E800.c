// 0134 · Seleção de intervalos
// Exercício E800 · ★☆☆
//
// A cabeleireira atende uma cliente por vez e quer encaixar o maior número
// possível de pedidos. Os horários estão em minutos desde a abertura do
// salão, como [ini, fim). O programa está pronto, mas a função de comparação
// do qsort, por_fim, está vazia (marcada com "COMPLETE AQUI") e sempre
// devolve 0, então a ordem fica errada. Complete a função para ordenar pela
// hora de fim.
//
//   Saída esperada:
//   Lia (0 a 45)
//   Duda (45 a 100)
//   Nina (100 a 120)
//   Gabi (150 a 180)
//
// Dicas:
// 1. Converta os ponteiros: const Horario *x = a; const Horario *y = b;
// 2. Devolva negativo se x termina antes, positivo se termina depois e 0 se
//    empatam: (x->fim > y->fim) - (x->fim < y->fim).
// 3. Resposta esperada: a saída acima. Repare que a Duda (45 a 100) encosta
//    na Lia, e a Nina (100 a 120) encosta na Duda.
//
// Escreva sua resposta abaixo (complete o código):

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    const char *cliente;
    int ini, fim; // minutos desde a abertura, [ini, fim)
} Horario;

int por_fim(const void *a, const void *b) {
    // COMPLETE AQUI
    (void)a;
    (void)b;
    return 0;
}

int main(void) {
    Horario h[] = {
        {"Rita", 60, 150}, {"Lia", 0, 45},     {"Bia", 30, 90},
        {"Gabi", 150, 180}, {"Nina", 100, 120}, {"Duda", 45, 100},
        {"Mel", 120, 200},
    };
    int n = 7;

    qsort(h, n, sizeof h[0], por_fim);
    int livre_em = 0;
    for (int i = 0; i < n; i++) {
        if (h[i].ini >= livre_em) {
            printf("%s (%d a %d)\n", h[i].cliente, h[i].ini, h[i].fim);
            livre_em = h[i].fim;
        }
    }
    return 0;
}
