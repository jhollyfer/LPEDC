// Lista · Módulo 25 · Estruturas especiais
// Exercício P2523 · ★★★ · O jogo da vida esparso
//
// No jogo da vida de Conway, numa grade infinita, cada célula viva com 2 ou
// 3 vizinhas vivas (das 8 em volta) sobrevive, e cada célula morta com
// exatamente 3 vizinhas vivas nasce. Grade infinita não cabe em matriz:
// guarde só as VIVAS, num vetor de (lin, col) em ordem. Para a próxima
// geração:
//   1. para cada viva, ponha num vetor de candidatos as 8 vizinhas dela;
//   2. ordene os candidatos (qsort); uma célula aparece ali uma vez para
//      cada vizinha viva, então o tamanho de cada grupo de iguais é a
//      contagem de vizinhas;
//   3. ela fica viva com contagem 3, ou 2 se já era viva (bsearch).
// Escreva do zero e rode o planador abaixo por 4 gerações, mostrando as
// vivas de cada uma, e depois até a geração 400.
//
//   Planador: (0,1) (1,2) (2,0) (2,1) (2,2)
//
//   Saída esperada:
//   geração 0 (5 vivas): (0,1) (1,2) (2,0) (2,1) (2,2)
//   geração 1 (5 vivas): (1,0) (1,2) (2,1) (2,2) (3,1)
//   geração 2 (5 vivas): (1,2) (2,0) (2,2) (3,1) (3,2)
//   geração 3 (5 vivas): (1,1) (2,2) (2,3) (3,1) (3,2)
//   geração 4 (5 vivas): (1,2) (2,3) (3,1) (3,2) (3,3)
//   geração 400 (5 vivas): (100,101) (101,102) (102,100) (102,101) (102,102)
//
// Dicas:
// 1. Use o mesmo comparador (lin, depois col) no qsort e no bsearch. Os
//    candidatos já ordenados geram a nova geração em ordem.
// 2. Célula viva sem vizinha nenhuma nem aparece nos candidatos: morre
//    sozinha, como deve.
// 3. Resposta esperada: na geração 4 o planador é o da geração 0 andado
//    uma casa na diagonal; na 400, ele está 100 casas longe, ainda com 5
//    células.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    return 0;
}
