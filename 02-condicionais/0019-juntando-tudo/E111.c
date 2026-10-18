// 0019 · Juntando tudo: a conta de luz
// Exercício E111 · ★★☆
//
// Leia uma data no formato dia/mês/ano e diga se ela existe. O mês vai de 1
// a 12; o dia vai de 1 até o número de dias do mês, e fevereiro tem 29 dias
// nos anos bissextos.
//
//   Data (dd/mm/aaaa): 29/02/2023
//   Data inválida.
//
// Dicas:
// 1. scanf("%d/%d/%d", &dia, &mes, &ano) lê as barras também. Confira o
//    retorno (3).
// 2. Um switch descobre quantos dias tem o mês (com case empilhados, como no
//    A036) e um default marca o mês inválido. Depois, um if confere o dia.
// 3. Resposta esperada: 29/02/2023 → inválida; 29/02/2024 → válida;
//    31/04/2025 → inválida; 15/13/2025 → inválida; 31/12/2025 → válida.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
