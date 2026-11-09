// Lista · Módulo 26 · Notação assintótica, somatórios e espaço
// Exercício P2606 · ★☆☆ · O primeiro débito do extrato
//
// A função primeiro_debito procura o primeiro valor negativo do extrato e
// conta as comparações. Rode-a nos três extratos de 8 lançamentos do main
// e mostre as comparações de cada um, dizendo qual é o melhor caso e qual
// é o pior:
//
//   Saída esperada:
//   extrato a (melhor caso): posição 0, 1 comparações
//   extrato b: posição 3, 4 comparações
//   extrato c (pior caso): posição -1, 8 comparações
//
// Dicas:
// 1. Acrescente um contador global, zerado antes de cada busca e somado a
//    cada valor olhado.
// 2. O melhor caso olha 1 valor; o pior olha os 8 (o débito no fim ou nenhum
//    débito).
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (complete o programa):

#include <stdio.h>

// devolve a posição do primeiro débito (valor negativo), ou -1
int primeiro_debito(const double extrato[], int n) {
    for (int i = 0; i < n; i++) {
        if (extrato[i] < 0) {
            return i;
        }
    }
    return -1;
}

int main(void) {
    double a[8] = {-50.0, 120.0, 30.5, 80.0, 15.0, 200.0, 9.9, 60.0};
    double b[8] = {120.0, 30.5, 80.0, -50.0, 15.0, 200.0, 9.9, 60.0};
    double c[8] = {120.0, 30.5, 80.0, 15.0, 200.0, 9.9, 60.0, 45.0};
    printf("%d %d %d\n", primeiro_debito(a, 8), primeiro_debito(b, 8), primeiro_debito(c, 8));
    return 0;
}
