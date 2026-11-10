// Lista · Módulo 18 · Ordenação além da comparação e seleção
// Exercício P1823 · ★★★ · O ponto de encontro da turma: duas medianas
//
// Nove amigos moram em esquinas de um bairro em grade, e cada um anda pelas
// ruas (distância de Manhattan: |x1 - x2| + |y1 - y2| quarteirões). Em que
// esquina marcar o churrasco para que a SOMA das distâncias seja a menor
// possível?
//
// Como a distância separa x e y, o problema se divide em dois de uma dimensão,
// e em uma dimensão a soma de |x - p| é mínima na MEDIANA. Logo, o melhor
// ponto é (mediana dos x, mediana dos y), e cada mediana sai de um
// quickselect em Θ(n) médio, sem ordenar nada.
//
// Escreva o quickselect (Lomuto, pivô no último; trabalhe em cópias, porque
// ele bagunça o vetor) e mostre: o ponto das medianas e a soma das distâncias
// nele; o "centro de massa" (médias arredondadas) e a soma nele; e o melhor
// ponto por força bruta, testando todas as esquinas de 0 a 20 nos dois
// eixos, para conferir.
//
//   Saída esperada:
//   Medianas: (6, 5), soma 67
//   Centro de massa: (8, 7), soma 75
//   Força bruta: (6, 5), soma 67
//
// Dicas:
// 1. Com n = 9 (ímpar), a mediana é o elemento de posição 4 (a partir de 0).
//    Com n par, qualquer ponto entre os dois do meio serve.
// 2. As médias minimizam a soma dos QUADRADOS das distâncias. Quem mora longe
//    puxa a média, mas não a mediana.
// 3. A força bruta testa 21 × 21 esquinas, cada uma com 9 distâncias: tudo
//    bem para conferir, mas é Θ(L² n) contra Θ(n) das medianas.
// 4. Resposta esperada: medianas em (6, 5) com soma 67; o centro de massa
//    (8, 7) dá 75; a força bruta confirma (6, 5) e 67.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

#define N 9
#define L 21 // esquinas de 0 a 20

int main(void) {
    int x[N] = {2, 6, 3, 7, 20, 5, 9, 6, 15};
    int y[N] = {4, 5, 9, 1, 18, 6, 3, 12, 5};

    for (int i = 0; i < N; i++) printf("(%d, %d) ", x[i], y[i]);
    printf("\n");
    return 0;
}
