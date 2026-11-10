// Lista · Módulo 04 · Funções e modularização
// Exercício P0430 · ★★★ · A fatoração em primos
//
// Todo inteiro maior que 1 se escreve de um jeito só como produto de primos:
// 360 = 2³ × 3² × 5. Escreva, sem laço, três funções recursivas: "int
// expoente(int n, int d)" (quantas vezes d divide n), "int sem_fator(int n,
// int d)" (n depois de tirar todos os fatores d) e "void fatorar(int n, int
// d)", que mostra a fatoração tentando os divisores d = 2, 3, 4, ... Fatore
// 360, 2026, 1024 e 9973:
//
//   Saída esperada:
//   360 = 2^3 x 3^2 x 5
//   2026 = 2 x 1013
//   1024 = 2^10
//   9973 = 9973
//
// Dicas:
// 1. expoente(n, d): se n % d != 0, devolve 0; senão 1 + expoente(n / d, d).
//    sem_fator é parecida, devolvendo o n que sobrou.
// 2. fatorar(n, d): se n == 1, acabou. Se d * d > n, o que sobrou é primo:
//    mostre n. Se d não divide n, tente d + 1. Se divide, mostre d (com ^e se
//    e > 1) e continue com sem_fator(n, d) e d + 1.
// 3. O " x " entre os fatores aparece antes de cada fator que não é o
//    primeiro: passe essa informação num parâmetro a mais, ou mostre o " x "
//    antes da chamada recursiva quando ainda sobrar algo.
// 4. Resposta esperada: as quatro linhas acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
