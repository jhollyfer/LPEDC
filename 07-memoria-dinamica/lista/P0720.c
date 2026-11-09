// Lista · Módulo 07 · Memória dinâmica
// Exercício P0720 · ★★☆ · A borda e o miolo do terreno
//
// Um terreno foi dividido num quadriculado, e cada casa tem a altura do solo
// em centímetros. Leia do teclado o número de linhas e de colunas e depois as
// alturas, linha por linha. Guarde numa matriz dinâmica (vetor de ponteiros)
// e mostre a soma das casas da BORDA (primeira e última linha, primeira e
// última coluna, sem contar canto duas vezes) e a do MIOLO (o resto):
//
//   Exemplo de execução:
//   Linhas e colunas: 3 4
//   Alturas:
//   5 2 7 1
//   3 9 8 4
//   6 0 2 5
//   Borda: 35
//   Miolo: 17
//
// (as alturas são digitadas; o programa mostra só as outras linhas)
//
// Dicas:
// 1. Uma casa (i, j) é da borda se i == 0, i == l - 1, j == 0 ou j == c - 1.
//    Um if só, com ||: assim o canto não conta duas vezes.
// 2. Confira o retorno de cada scanf; se a leitura falhar, libere o que já
//    alocou antes de sair.
// 3. Com l ou c menor que 3 não há miolo: o programa mostra Miolo: 0.
// 4. Teste: printf '3 4\n5 2 7 1\n3 9 8 4\n6 0 2 5\n' | ./rodar ...
// 5. Resposta esperada: Borda 35 e Miolo 17.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
