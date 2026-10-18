// 0138 · Memoização
// Exercício E826 · ★★☆
//
// A feira de domingo tem 8 vagas de barraca enfileiradas, numeradas de 0 a 7.
// Você tem barracas suficientes, mas a prefeitura proíbe montar em duas
// vagas VIZINHAS. O lucro estimado de cada vaga, em reais, é:
//
//   vaga:   0   1   2   3   4   5   6   7
//   lucro: 40  25  60  30  10  55  35  20
//
// Escreva um programa que calcula, de baixo para cima, melhor[i] = o maior
// lucro usando só as vagas 0..i, mostre o vetor, o lucro máximo e quais
// vagas usar.
//
//   Saída esperada:
//   melhor: 40 40 100 100 110 155 155 175
//   Lucro máximo: R$ 175
//   Barracas: 0 2 5 7
//
// Dicas:
// 1. Na vaga i há duas escolhas: não montar (fica melhor[i - 1]) ou montar
//    (lucro[i] + melhor[i - 2], porque a i - 1 tem que ficar vazia).
// 2. Bases: melhor[0] = lucro[0]; melhor[1] = o maior entre lucro[0] e
//    lucro[1].
// 3. Para achar as vagas, ande de trás para a frente: se melhor[i] é
//    diferente de melhor[i - 1], a vaga i foi usada e você pula para i - 2;
//    senão, vai para i - 1. A vaga 0, se você chegar nela, é usada.
// 4. Resposta esperada: a saída acima (40 + 60 + 55 + 20 = 175).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
