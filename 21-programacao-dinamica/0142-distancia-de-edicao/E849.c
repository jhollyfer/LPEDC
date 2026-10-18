// 0142 · Distância de edição
// Exercício E849 · ★★☆
//
// Alguns sistemas de controle de versão não "trocam" letras: cada mudança é
// uma remoção seguida de uma inserção. Nessa distância sem troca, BOLO para
// BOLA custa 2 (remove O, insere A), e não 1.
//
// Escreva int dist_sem_troca(const char *a, const char *b), com a mesma
// tabela da distância de edição mas só com remover e inserir. Escreva também
// int lcs(const char *a, const char *b) e confira, para cada par, que a
// distância sem troca é igual a m + n - 2 x LCS (tudo que não está na LCS
// sai de a ou entra de b).
//
//   Saída esperada:
//   PALMEIRAS PALMAS     PD:  3   m + n - 2 x LCS = 9 + 6 - 2 x 6 =  3
//   CARTA     ARTES      PD:  4   m + n - 2 x LCS = 5 + 5 - 2 x 3 =  4
//   BOLO      BOLA       PD:  2   m + n - 2 x LCS = 4 + 4 - 2 x 3 =  2
//   RECIFE    FORTALEZA  PD: 11   m + n - 2 x LCS = 6 + 9 - 2 x 2 = 11
//
// Dicas:
// 1. Na distância sem troca, letras diferentes têm só duas saídas:
//    1 + o menor entre d[i - 1][j] (remove) e d[i][j - 1] (insere).
// 2. A borda é a mesma da distância comum: d[i][0] = i, d[0][j] = j.
// 3. Para alinhar as colunas, use %-9s nas palavras e %2d nos números.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {

    return 0;
}
