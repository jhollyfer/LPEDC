// Lista · Módulo 18 · Ordenação além da comparação e seleção
// Exercício P1825 · ★★★ · Counting sort sem vetor de saída: as camisas no lugar
//
// O counting sort do Cormen precisa de um vetor de saída B do tamanho da
// entrada. Quando a memória aperta, dá para ordenar NO LUGAR com poucas
// chaves: conte, calcule onde começa e onde termina cada bloco, e vá
// trocando cada item para dentro do seu bloco ("ciclos").
//
// A loja tem 12 camisas de tamanhos P, M, G, GG e XG (chaves 0 a 4). Escreva:
//
//   void ordena_no_lugar(Camisa v[], int n);
//
// 1. conte as chaves e calcule prox[k] (a próxima vaga do bloco k, começando
// no início do bloco) e fim[k] (onde o bloco k termina);
// 2. para cada bloco k, enquanto prox[k] < fim[k]: olhe a camisa em
// v[prox[k]]; se ela é do bloco k, avance prox[k]; senão, troque-a com
// v[prox[chave]] e avance prox[chave].
//
// Mostre o vetor antes e depois, o número de trocas (cada troca põe pelo
// menos uma camisa no lugar definitivo: no máximo n) e se o resultado ficou
// ESTÁVEL (compare a ordem dos códigos dentro de cada tamanho).
//
//   Saída esperada:
//   antes:  G(1) XG(2) P(3) G(4) M(5) GG(6) M(7) P(8) XG(9) G(10) GG(11) M(12)
//   depois: P(3) P(8) M(7) M(12) M(5) G(1) G(10) G(4) GG(6) GG(11) XG(9) XG(2)
//   Trocas: 9 (n = 12) | estável: não
//
// Dicas:
// 1. Comece prox[0] = 0 e prox[k] = prox[k - 1] + c[k - 1]; fim[k] =
//    prox[k] + c[k] (calcule antes de mexer em prox).
// 2. A troca manda uma camisa direto para o seu bloco, na vaga prox[chave],
//    que avança. A camisa que veio de lá é examinada na próxima volta, sem
//    avançar prox[k].
// 3. É Θ(n + k) de tempo e Θ(k) de memória extra, mas NÃO é estável: as
//    trocas embaralham os empates. Para um passo de radix sort, isso não
//    serve.
// 4. Resposta esperada: P P M M M G G G GG GG XG XG, com 9 trocas, e não
//    estável (o M 107 fica antes do M 105, por exemplo).
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

#define N 12
#define K 5

typedef struct {
    int codigo, tam; // tam: 0 P, 1 M, 2 G, 3 GG, 4 XG
} Camisa;

const char *tamanhos[K] = {"P", "M", "G", "GG", "XG"};

int main(void) {
    Camisa v[N] = {{101, 2}, {102, 4}, {103, 0}, {104, 2}, {105, 1}, {106, 3},
                   {107, 1}, {108, 0}, {109, 4}, {110, 2}, {111, 3}, {112, 1}};

    for (int i = 0; i < N; i++) printf("%s(%d) ", tamanhos[v[i].tam], v[i].codigo);
    printf("\n");
    return 0;
}
