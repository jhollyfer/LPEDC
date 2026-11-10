// Lista · Módulo 05 · Vetores, matrizes e strings
// Exercício P0515 · ★★☆ · Tirar da vitrine o que acabou
//
// A loja on-line tem 9 produtos, cada um com um código e o estoque, em dois
// vetores paralelos (a posição i dos dois fala do mesmo produto):
//
//   int codigo[9]  = {11, 12, 13, 14, 15, 16, 17, 18, 19};
//   int estoque[9] = { 4,  0,  7,  0,  0,  2,  9,  0,  1};
//
// Escreva int compactar(int cod[], int est[], int n), que remove dos DOIS
// vetores os produtos com estoque 0, sem usar vetor auxiliar e mantendo a
// ordem, e devolve quantos sobraram. Mostre os vetores antes e depois:
//
//   Saída esperada:
//   Antes (9):  11:4 12:0 13:7 14:0 15:0 16:2 17:9 18:0 19:1
//   Depois (5): 11:4 13:7 16:2 17:9 19:1
//
// Dicas:
// 1. Use dois índices: i lê todas as posições e k marca onde o próximo
//    produto que fica vai ser escrito.
// 2. Se est[i] != 0, copie cod[i] e est[i] para a posição k e faça k++.
// 3. No fim, k é o novo tamanho. É uma passada só: n operações, e não n²
//    como "apagar e empurrar tudo" a cada zero.
// 4. Resposta esperada: a saída acima (sobram 5 produtos).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {
    int codigo[9]  = {11, 12, 13, 14, 15, 16, 17, 18, 19};
    int estoque[9] = { 4,  0,  7,  0,  0,  2,  9,  0,  1};
    (void) codigo, (void) estoque; // apague esta linha quando escrever

    return 0;
}
