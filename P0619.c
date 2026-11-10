// Lista · Módulo 06 · Ponteiros
// Exercício P0619 · ★★☆ · Média e desvio de uma vez
//
// Uma corredora anotou os tempos (em minutos) dos seus treinos de 5 km:
//
//   double tempos[6] = {28.5, 27.9, 30.2, 26.8, 29.1, 27.5};
//
// Escreva bool estatisticas(const double *v, int n, double *media,
// double *desvio), que devolve false se n < 1 e, senão, entrega a média e o
// desvio padrão (populacional) pelos ponteiros. Mostre os dois e quais
// treinos ficaram abaixo da média:
//
//   Saída esperada:
//   Média: 28.33 min
//   Desvio: 1.11 min
//   Abaixo da média: treino 2 (27.9) treino 4 (26.8) treino 6 (27.5)
//
// Dicas:
// 1. Desvio padrão = raiz da média dos quadrados das diferenças:
//    sqrt(soma de (v[i] - media)² / n). sqrt está no math.h (o rodar já
//    liga a biblioteca com -lm).
// 2. São duas passadas: a primeira acha a média; a segunda usa a média.
// 3. Atenção: dentro da função, media é um ponteiro. A conta usa *media.
// 4. Resposta esperada: a saída acima (média 28.33, desvio 1.11).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main(void) {
    double tempos[6] = {28.5, 27.9, 30.2, 26.8, 29.1, 27.5};
    (void) tempos; // apague esta linha quando escrever

    return 0;
}
