// 0143 · Juntando tudo: um mini-diff
// Exercício E853 · ★☆☆
//
// A fila de espera do posto de saúde é um arquivo com um nome por linha.
// Ontem e hoje ela estava assim:
//
//   ontem: Ana Bruno Carla Davi Elisa Fábio Gabi Hugo
//   hoje:  Ana Carla Davi Igor Elisa Gabi Hugo Júlia Kátia
//
// Sem imprimir o diff, mostre só o resumo, como o "diff --stat": quantas
// linhas ficaram iguais, quantas saíram e quantas entraram, e a semelhança
// entre as duas versões, 2 x LCS / (m + n), em porcentagem. Guarde as
// listas em vetores de strings no próprio programa (const char *ontem[]) e
// escreva int lcs_linhas(const char *a[], int m, const char *b[], int n).
//
//   Saída esperada:
//   6 iguais, 2 removidas, 3 adicionadas
//   semelhança: 70.6%
//
// Dicas:
// 1. É a LCS do assunto 0141 com strcmp(a[i], b[j]) == 0 no lugar de
//    a[i] == b[j]. A tabela dos sufixos (texto) ou dos prefixos (0141): tanto
//    faz, só o tamanho importa.
// 2. Removidas = m - LCS; adicionadas = n - LCS.
// 3. Para mostrar o %, use %% no printf; e faça a conta em double
//    (100.0 * 2 * l / (m + n)), senão a divisão é inteira.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {

    return 0;
}
