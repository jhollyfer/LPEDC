// 0108 · Juntando tudo: o contador de palavras
// Exercício E648 · ★★★
//
// No assunto 0105 a soma dos códigos juntava os anagramas por acidente.
// Agora junte de propósito. A "assinatura" de uma palavra são as suas
// letras em ordem: "roma", "mora" e "amor" têm a mesma assinatura, "amor".
// Use uma tabela hash cuja chave é a assinatura e cujo valor é o grupo de
// palavras com ela. Para a lista
//
//   amor pato roma sala topa mora alas lata ramo cafe
//
// mostre os grupos com 2 palavras ou mais, um por linha, na ordem em que o
// grupo apareceu pela primeira vez.
//
//   Saída esperada:
//   amor roma mora ramo
//   pato topa
//   sala alas
//
// Dicas:
// 1. Assinatura: copie a palavra e ordene as letras com qsort (cada
//    elemento tem 1 byte; a comparação é a diferença entre os dois char).
// 2. O nó do balde é um grupo: a assinatura, um vetor de palavras, o
//    número de palavras e o prox. Para imprimir na ordem de chegada, guarde
//    também um vetor com os ponteiros dos grupos na ordem em que nasceram.
// 3. Resposta esperada: a saída acima. "lata" e "cafe" ficam sozinhas e não
//    aparecem. É o mesmo truque do contador: muda só o que vira chave.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    return 0;
}
