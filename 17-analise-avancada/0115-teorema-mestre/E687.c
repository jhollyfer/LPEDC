// 0115 · Teorema mestre
// Exercício E687 · ★★☆
//
// As 1024 notas de um concurso (de 0 a 10) estão em ordem crescente. A
// função conta_lento conta quantas notas 7 existem dividindo o vetor ao
// meio, mas olha SEMPRE as duas metades: T(n) = 2 T(n/2) + 1, caso 1 do
// teorema, Θ(n). Ela não aproveita que o vetor está ordenado.
//
// Escreva primeira(v, ini, fim, x), recursiva, que devolve a primeira
// posição de v[ini..fim-1] com valor >= x (ou fim, se não houver),
// seguindo só UMA metade a cada chamada: T(n) = T(n/2) + 1, caso 2,
// Θ(log n). Conte as chamadas no mesmo contador global. As notas 7 são as
// que ficam entre primeira(..., 7) e primeira(..., 8):
//
//   Saída esperada:
//   lento:  93 notas 7 em 2047 chamadas
//   rápido: 93 notas 7 em 22 chamadas
//
// Dicas:
// 1. Caso base: com ini == fim, o pedaço está vazio; devolva ini.
// 2. Se v[meio] < x, a resposta está à direita: [meio + 1, fim). Senão,
//    o próprio meio pode ser a resposta: [ini, meio).
// 3. Quantidade = primeira(notas, 0, 1024, 8) - primeira(notas, 0, 1024, 7).
// 4. Resposta esperada: a saída acima (11 chamadas em cada busca). Com um
//    milhão de notas, o lento faria 2 milhões de chamadas; o rápido, uns 42.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

long chamadas = 0;

// olha as duas metades sempre: T(n) = 2 T(n/2) + 1
int conta_lento(const int v[], int ini, int fim, int x) {
    chamadas++;
    if (fim - ini == 1) {
        return v[ini] == x;
    }
    int meio = ini + (fim - ini) / 2;
    return conta_lento(v, ini, meio, x) + conta_lento(v, meio, fim, x);
}

int main(void) {
    int notas[1024];
    for (int i = 0; i < 1024; i++) {
        notas[i] = i * 11 / 1024; // notas de 0 a 10, em ordem
    }

    chamadas = 0;
    int qtd = conta_lento(notas, 0, 1024, 7);
    printf("lento:  %d notas 7 em %ld chamadas\n", qtd, chamadas);
    return 0;
}
