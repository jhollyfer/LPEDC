// Lista · Módulo 10 · Pensar como cientista da computação
// Exercício P1017 · ★★☆ · A busca que não acha o último ônibus
//
// Os horários de saída do terminal (em minutos depois das 5h) estão em
// ordem: 5, 12, 20, 33, 41 e 58. A busca binária abaixo compila sem aviso e
// acha o 5, mas diz que o 58 e o 33 "não têm". Ela tem um erro de propósito.
// Conserte, usando o invariante para guiar: "se x está no vetor, está em
// v[ini..fim]" (intervalo FECHADO, com as duas pontas valendo).
//
//   Saída esperada:
//   58: posição 5
//   5: posição 0
//   33: posição 3
//   40: não tem
//
// Dicas:
// 1. Faça o teste de mesa do 58: ini = 0, fim = 5, meio = 2, ...
//    Quando ini == fim, quantas posições ainda podem ter o x?
// 2. Com intervalo fechado, o intervalo só fica vazio quando ini > fim.
// 3. Resposta esperada: o laço é while (ini < fim), que para com uma
//    posição ainda sem olhar. O certo é while (ini <= fim). A saída fica
//    igual à de cima.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

int busca(const int v[], int n, int x) {
    int ini = 0, fim = n - 1;
    while (ini < fim) {
        int meio = (ini + fim) / 2;
        if (v[meio] == x) {
            return meio;
        }
        if (v[meio] < x) {
            ini = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;
}

int main(void) {
    int horarios[6] = {5, 12, 20, 33, 41, 58};
    int procurados[4] = {58, 5, 33, 40};
    for (int k = 0; k < 4; k++) {
        int pos = busca(horarios, 6, procurados[k]);
        if (pos >= 0) {
            printf("%d: posição %d\n", procurados[k], pos);
        } else {
            printf("%d: não tem\n", procurados[k]);
        }
    }
    return 0;
}
