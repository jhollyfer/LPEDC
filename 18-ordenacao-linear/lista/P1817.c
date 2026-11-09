// Lista · Módulo 18 · Ordenação além da comparação e seleção
// Exercício P1817 · ★★☆ · Conserte o radix sort das encomendas
//
// Conserte o programa. A transportadora ordena os pesos das encomendas (em
// gramas) com radix sort LSD em base 10, mas o colega deixou DOIS erros de
// propósito. Não há erro de memória; o resultado é que sai fora de ordem:
//
//   Saída que aparece:
//   45 3005 120 1250 340 12400 870 9800
//
// Depois do conserto:
//
//   Saída esperada:
//   45 120 340 870 1250 3005 9800 12400
//
// Dicas:
// 1. Quantas passadas o radix precisa? Tantas quantos dígitos tem o MAIOR
//    número, não o primeiro do vetor.
// 2. Cada passada tem de ser ESTÁVEL. Com --c[d], a colocação precisa andar
//    de trás para frente; da frente para trás, os empates de cada dígito
//    saem invertidos e a ordem das passadas anteriores se perde.
// 3. Para achar o erro 2, rode à mão uma passada com dois números de mesmo
//    dígito: 120 e 340 na passada das dezenas... não, das unidades (os dois
//    terminam em 0).
// 4. Resposta esperada: 45 120 340 870 1250 3005 9800 12400.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define N 8

void passada(int v[], int n, int div) {
    int c[10] = {0}, saida[N];
    for (int i = 0; i < n; i++) c[(v[i] / div) % 10]++;
    for (int d = 1; d < 10; d++) c[d] += c[d - 1];
    for (int i = 0; i < n; i++) saida[--c[(v[i] / div) % 10]] = v[i];
    for (int i = 0; i < n; i++) v[i] = saida[i];
}

int main(void) {
    int peso[N] = {870, 12400, 45, 3005, 120, 9800, 340, 1250};

    int digitos = 0;
    for (int x = peso[0]; x > 0; x /= 10) digitos++;
    for (int k = 0, div = 1; k < digitos; k++, div *= 10) passada(peso, N, div);

    for (int i = 0; i < N; i++) printf("%d ", peso[i]);
    printf("\n");
    return 0;
}
