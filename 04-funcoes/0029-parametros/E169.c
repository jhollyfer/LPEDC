// 0029 · Parâmetros e passagem por valor
// Exercício E169 · ★☆☆
//
// Sem rodar, preveja as quatro linhas que este programa mostra:
//
//   int dobrar_pontos(int pontos) {
//       pontos = pontos * 2;
//       printf("dentro: %d\n", pontos);
//       return pontos;
//   }
//
//   int main(void) {
//       int pontos = 150;
//       dobrar_pontos(pontos);
//       printf("main: %d\n", pontos);
//       pontos = dobrar_pontos(pontos);
//       printf("main: %d\n", pontos);
//       return 0;
//   }
//
// Dicas:
// 1. O "pontos" da função e o "pontos" do main são duas variáveis.
// 2. Na primeira chamada, o retorno não é guardado em lugar nenhum.
// 3. Resposta esperada: dentro: 300 / main: 150 / dentro: 300 / main: 300.
//
// Escreva sua resposta abaixo (em comentário, ou cole o código e rode):

#include <stdio.h>

int main(void) {

    return 0;
}
