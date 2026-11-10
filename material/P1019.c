// Lista · Módulo 10 · Pensar como cientista da computação
// Exercício P1019 · ★★☆ · O resumo da corrida em O(1)
//
// O app de corrida mostra o resumo depois de cada treino e não quer guardar
// a lista inteira de tempos. Escreva o TAD Resumo, num arquivo só
// ("resumo.h", "resumo.c" e cliente), em que TODA operação custa O(1),
// guardando só agregados (quantidade, soma, soma dos quadrados, menor e
// maior):
//
//   Resumo *resumo_cria(void);
//   void resumo_adiciona(Resumo *r, double x);
//   int resumo_quantidade(const Resumo *r);
//   double resumo_media(const Resumo *r);
//   double resumo_menor(const Resumo *r);
//   double resumo_maior(const Resumo *r);
//   double resumo_desvio(const Resumo *r);  // desvio padrão populacional
//   void resumo_libera(Resumo *r);
//
// Teste com os tempos, em minutos, 32, 29, 35, 31, 28 e 33.
//
//   Saída esperada:
//   Corridas: 6
//   Média: 31.33 min
//   Melhor: 28 min
//   Pior: 35 min
//   Desvio: 2.36 min
//
// Dicas:
// 1. Variância = (soma dos quadrados / n) - média². O desvio é a raiz
//    (sqrt, de math.h; o rodar já liga a biblioteca com -lm).
// 2. A interface não muda se um dia você trocar a implementação para
//    guardar todos os tempos (para ter a mediana, por exemplo): o cliente
//    continua compilando igual. Só o custo muda.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
