// Lista · Módulo 02 · Decisões
// Exercício P0223 · ★★★ · O placar do set de vôlei
//
// Um set de vôlei acaba quando um time chega a 25 pontos com pelo menos 2 de
// vantagem; se empatar em 24, o jogo segue até alguém abrir 2 (26 × 24, 27 ×
// 25...). Escreva um programa que leia o placar dos times A e B e diga se o set
// está em andamento, quem venceu, ou se o placar é impossível (negativo, ou
// acima de 25 com mais de 2 de diferença, como 27 × 20, porque o set teria
// acabado antes). Três interações:
//
//   Saída esperada:
//   Placar (A B): 25 23
//   Set do time A (25 x 23)
//
//   Placar (A B): 25 24
//   Set em andamento
//
//   Placar (A B): 27 20
//   Placar impossível
//
// Dicas:
// 1. Calcule o maior, o menor e a diferença com ternários; depois decida só
//    olhando para eles.
// 2. Ordem dos testes: negativo → impossível; maior < 25 ou diferença < 2 →
//    em andamento; maior > 25 e diferença > 2 → impossível; senão, acabou.
// 3. O vencedor é A se a > b, senão B.
// 4. Resposta esperada: as três saídas acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
