// 0042 · Vetores
// Exercício E251 · ★★★
//
// Este programa deveria mostrar a máxima e a mínima de uma madrugada fria em
// São Joaquim (SC), medidas em 6 horários. Ele tem DOIS erros de propósito.
// Rode com o rodar: o AddressSanitizer vai acusar um deles. O outro não dá
// erro nenhum, só resultado errado. Ache os dois, explique e conserte.
//
//   Saída esperada depois do conserto:
//   Máxima: -1 graus
//   Mínima: -6 graus
//
// Dicas:
// 1. Leia o relatório: "index 6 out of bounds for type 'int [6]'" e
//    "stack-buffer-overflow" apontam a mesma linha. Qual?
// 2. Quantas vezes o laço roda? Quais índices existem num vetor de 6?
// 3. Todas as temperaturas são negativas. Alguma delas é maior que 0?
// 4. Resposta esperada: o laço usa i <= 6 e lê temps[6], que não existe
//    (troque por i < 6); e maior começa em 0, que nenhuma temperatura supera,
//    então a máxima sairia 0 (comece maior e menor com temps[0]).
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

int main(void) {
    int temps[6] = {-2, -6, -1, -4, -3, -5};
    int maior = 0;
    int menor = temps[0];

    for (int i = 0; i <= 6; i++) {
        if (temps[i] > maior) {
            maior = temps[i];
        }
        if (temps[i] < menor) {
            menor = temps[i];
        }
    }

    printf("Máxima: %d graus\n", maior);
    printf("Mínima: %d graus\n", menor);
    return 0;
}
