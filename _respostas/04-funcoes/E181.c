// 0031 · A pilha de chamadas
// Exercício E181 · ★☆☆
//
// Resposta (base -> topo), quando a linha (*) roda:
//   main      resultado ainda sem valor (esperando imc voltar)
//   imc       peso = 72.0, altura = 1.80 (esperando quadrado voltar)
//   quadrado  x = 1.80                     <- topo, é quem está rodando
// quadrado devolve 3.24, imc devolve 72.0 / 3.24 = 22.2..., main mostra.

#include <stdio.h>

double quadrado(double x) {
    return x * x; // (*)
}

double imc(double peso, double altura) {
    return peso / quadrado(altura);
}

int main(void) {
    double resultado = imc(72.0, 1.80);
    printf("IMC: %.1f\n", resultado);
    return 0;
}
