// 0133 · Algoritmos gulosos
// Exercício E797 · ★★★
//
// Vamos caçar contraexemplos com o computador. Para cada sistema de moedas
// abaixo, ache o MENOR valor, de 1 a 100, em que o guloso usa mais moedas
// que o necessário, ou diga que ele acertou todos.
//
// Escreva:
// - int guloso(const int m[], int k, int valor): o troco guloso com / e %
//   (moedas em ordem decrescente; a última é sempre 1);
// - int otimo(const int m[], int k, int i, int valor): o mínimo de verdade,
//   por força bruta recursiva: para a moeda m[i], teste usar 0, 1, 2, ...
//   unidades dela e resolva o resto com as moedas seguintes (i + 1). Quando
//   i chega na última moeda (o 1), a resposta é o próprio valor;
// - void testa(const char *nome, const int m[], int k, int limite).
//
//   Saída esperada:
//   {25, 10, 5, 1}: o guloso acertou de 1 a 100
//   {4, 3, 1}: falha em 6 (guloso 3, ótimo 2)
//   {10, 7, 1}: falha em 14 (guloso 5, ótimo 2)
//   {12, 5, 1}: falha em 15 (guloso 4, ótimo 3)
//
// Dicas:
// 1. Em otimo, comece com melhor = valor (tudo em moedas de 1) e, no laço
//    for (int c = 0; c * m[i] <= valor; c++), compare com
//    c + otimo(m, k, i + 1, valor - c * m[i]).
// 2. Em testa, pare no primeiro valor em que guloso != otimo.
// 3. Resposta esperada: a saída acima. O teste só vai até 100, então
//    "acertou de 1 a 100" não é prova de que o sistema é canônico. (Para
//    sistemas de moedas existe um resultado conhecido: se o guloso falha,
//    falha num valor menor que a soma das duas maiores moedas.)
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {
    int real[] = {25, 10, 5, 1};
    int fichas[] = {4, 3, 1};
    int selos[] = {10, 7, 1};
    int bonus[] = {12, 5, 1};
    (void)real;
    (void)fichas;
    (void)selos;
    (void)bonus;

    return 0;
}
