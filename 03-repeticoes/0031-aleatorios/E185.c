// 0031 · Aleatórios
// Exercício E185 · ★★★
//
// Dá para estimar pi jogando dardos. Sorteie um ponto (x, y) com x e y entre
// 0 e 1: ele cai num quadrado de lado 1. O quarto de círculo de raio 1 ocupa
// pi/4 desse quadrado. Então, com muitos pontos:
//
//   pi ~ 4 x (pontos dentro do círculo) / (total de pontos)
//
// Sorteie 1 000 000 de pontos (com srand(42)) e mostre a estimativa com 4
// casas. Um ponto está dentro se x * x + y * y <= 1.
//
// Dicas:
// 1. Um double entre 0 e 1: (double) rand() / RAND_MAX. Sem o cast, a divisão
//    é inteira e dá quase sempre 0.
// 2. Use 4.0 na conta final, pelo mesmo motivo.
// 3. Resposta esperada: algo perto de 3.14. Na glibc (Linux) com semente
//    42: "Dentro do círculo: 784696 de 1000000" e "pi ~ 3.1388". Com 100
//    pontos, o erro é bem maior: teste.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
