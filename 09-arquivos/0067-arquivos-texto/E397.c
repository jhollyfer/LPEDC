// 0067 · Arquivos texto
// Exercício E397 · ★☆☆
//
// Grave a tabuada do 7 no arquivo /tmp/tabuada7.txt, uma conta por linha,
// usando fprintf. Feche o arquivo, abra de novo em modo leitura e mostre o
// conteúdo na tela com fgets. Confira se o fopen deu certo nas duas vezes.
//
//   Saída esperada:
//   7 x 1 = 7
//   7 x 2 = 14
//   ...
//   7 x 10 = 70
//
// Dicas:
// 1. Um for de 1 a 10 com fprintf(arq, "7 x %d = %d\n", i, 7 * i).
// 2. Para ler: while (fgets(linha, sizeof linha, arq) != NULL) printf("%s", linha);
// 3. Resposta esperada: as 10 linhas da tabuada, de "7 x 1 = 7" até
//    "7 x 10 = 70". O arquivo fica em /tmp: confira com cat /tmp/tabuada7.txt.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
