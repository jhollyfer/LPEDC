// 0170 · Precedência e ordem de avaliação
// Exercício E1015 · ★☆☆
//
// As três fórmulas abaixo foram digitadas sem parênteses e dão resultados
// absurdos. Conserte cada uma pondo parênteses só onde precisa, para que a
// média das notas 7, 8 e 9 dê 8, os 104 °F virem 40 °C (C = (F - 32) * 5 / 9)
// e a área de um quadro de 4 x 3 com 1 de moldura de cada lado dê 30.
//
//   Saída esperada:
//   media = 8
//   celsius = 40
//   area = 30
//
// Dicas:
// 1. Rode antes de mexer: sai 18, 87 e 12. Descubra por que, olhando a
//    tabela de precedência.
// 2. Na moldura, cada lado ganha 2: (4 + 2) * (3 + 2).
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

int main(void) {
    int n1 = 7, n2 = 8, n3 = 9;
    int media = n1 + n2 + n3 / 3;
    printf("media = %d\n", media);

    int f = 104;
    int celsius = f - 32 * 5 / 9;
    printf("celsius = %d\n", celsius);

    int largura = 4, altura = 3;
    int area = largura + 2 * altura + 2;
    printf("area = %d\n", area);
    return 0;
}
