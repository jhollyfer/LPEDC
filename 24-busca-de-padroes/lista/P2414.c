// Lista · Módulo 24 · Busca de padrões em texto
// Exercício P2414 · ★★☆ · O mesmo colar visto de outro ponto
//
// A artesã anota cada colar de miçangas pelas cores (A azul, B branca,
// V vermelha) a partir de uma conta qualquer. Dois registros são o mesmo
// colar se um é rotação do outro. Para agrupar, use a FORMA CANÔNICA: a
// menor rotação em ordem alfabética. Escreva:
// - menor_rotacao(s), que compara as n rotações letra a letra, dando a
//   volta com (k + j) % n, sem montar nenhuma string, e devolve o início
//   da menor;
// - canonica(s, saida), que escreve essa rotação em saida.
// Mostre a forma de cada colar do main e os grupos de colares iguais.
//
//   Saída esperada:
//   VAAVB -> AAVBV
//   AVBVA -> AAVBV
//   BAVAV -> AVAVB
//   VBVAA -> AAVBV
//   AVAVB -> AVAVB
//   ABAVV -> ABAVV
//   Colar 1: VAAVB AVBVA VBVAA
//   Colar 2: BAVAV AVAVB
//   Colar 3: ABAVV
//
// Dicas:
// 1. Para comparar as rotações k e melhor, avance j enquanto
//    s[(k + j) % n] == s[(melhor + j) % n]; a primeira diferença decide.
// 2. Força bruta O(n²): para colares pequenos está ótimo. Os grupos saem
//    comparando as formas com strcmp.
// 3. Resposta esperada: 3 colares diferentes: VAAVB, AVBVA e VBVAA são o
//    mesmo (forma AAVBV).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {
    const char *colares[] = {"VAAVB", "AVBVA", "BAVAV", "VBVAA", "AVAVB", "ABAVV"};
    printf("%s\n", colares[0]);
    return 0;
}
