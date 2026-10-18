// 0003 · Fluxograma
// Exercício E018 · ★★★
//
// Este fluxograma deveria mostrar 5, 4, 3, 2, 1 e "Já!". Mas ele nunca
// termina. Ache o erro e conserte.
//
//   (Início)
//      |
//   [n <- 5]
//      |
//   <n > 0?> --Não--> /Mostrar "Já!"/ --> (Fim)
//      |   ^
//     Sim  |
//      |   |
//   /Mostrar n/
//      |   |
//      +---+
//
// Dicas:
// 1. Faça o teste de mesa: qual o valor de n na segunda volta? E na décima?
// 2. Alguma forma dentro do laço muda o valor de n?
// 3. Resposta esperada: falta um processo "n <- n - 1" depois de "Mostrar n",
//    antes da seta voltar. Sem ele, n vale 5 para sempre: é um laço infinito.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
