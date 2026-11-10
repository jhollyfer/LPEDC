// Lista · Módulo 06 · Ponteiros
// Exercício P0610 · ★☆☆ · O maior da matriz por um ponteiro só
//
// A matriz guarda as vendas de 3 vendedores (linhas) em 4 semanas (colunas):
//
//   int v[3][4] = {{12, 18, 9, 14}, {20, 7, 16, 11}, {13, 15, 22, 8}};
//
// Na memória, as 12 casas ficam uma depois da outra, linha por linha. Use um
// único ponteiro int *p = &v[0][0] e ande pelas 12 casas com p++ (sem
// v[i][j]) para achar o maior valor. Depois, com a POSIÇÃO dele no bloco
// (k = p_maior - &v[0][0]), descubra a linha (k / 4) e a coluna (k % 4):
//
//   Saída esperada:
//   Maior venda: 22
//   Posição no bloco: 10
//   Vendedor (linha): 2
//   Semana (coluna): 2
//
// Dicas:
// 1. int *inicio = &v[0][0]; int *fim = inicio + 12; e um for de p = inicio
//    até p < fim.
// 2. Guarde o ponteiro do maior (int *p_maior), não só o valor.
// 3. A casa (i, j) fica em i * 4 + j a partir do início: é o mesmo cálculo
//    ao contrário.
// 4. Resposta esperada: a saída acima (22 na posição 10: linha 2, coluna 2).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {
    int v[3][4] = {{12, 18, 9, 14}, {20, 7, 16, 11}, {13, 15, 22, 8}};
    (void) v; // apague esta linha quando escrever

    return 0;
}
