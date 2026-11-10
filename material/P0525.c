// Lista · Módulo 05 · Vetores, matrizes e strings
// Exercício P0525 · ★★★ · A ronda em espiral
//
// O vigia de um galpão com 4 corredores de 5 prateleiras faz a ronda em
// espiral: vai pela borda de cima da esquerda para a direita, desce pela
// direita, volta por baixo, sobe pela esquerda e repete por dentro, até passar
// por todas. Cada prateleira tem um número:
//
//   int g[4][5] = {{ 1,  2,  3,  4,  5},
//                  { 6,  7,  8,  9, 10},
//                  {11, 12, 13, 14, 15},
//                  {16, 17, 18, 19, 20}};
//
// Mostre a ordem da ronda e, depois, uma matriz com o número do passo em que
// cada prateleira foi visitada (%3d):
//
//   Saída esperada:
//   Ronda: 1 2 3 4 5 10 15 20 19 18 17 16 11 6 7 8 9 14 13 12
//     1  2  3  4  5
//    14 15 16 17  6
//    13 20 19 18  7
//    12 11 10  9  8
//
// Dicas:
// 1. Guarde quatro limites: cima = 0, baixo = 3, esq = 0, dir = 4. Cada
//    volta percorre a linha cima (e faz cima++), a coluna dir (dir--), a
//    linha baixo de trás para a frente (baixo--) e a coluna esq de baixo
//    para cima (esq++).
// 2. Depois de cima++ e de dir--, o retângulo pode ter sumido: confira
//    cima <= baixo antes da linha de baixo e esq <= dir antes da coluna da
//    esquerda. Sem isso, matrizes não quadradas repetem casas.
// 3. Um contador de passos que começa em 1 preenche a segunda matriz.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {
    int g[4][5] = {{ 1,  2,  3,  4,  5},
                   { 6,  7,  8,  9, 10},
                   {11, 12, 13, 14, 15},
                   {16, 17, 18, 19, 20}};
    (void) g; // apague esta linha quando escrever

    return 0;
}
