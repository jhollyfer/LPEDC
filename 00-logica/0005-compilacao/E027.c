// 0005 · Do .c ao executável
// Exercício E027 · ★★☆
//
// Este programa tem DOIS erros, e cada um aparece numa estação diferente da
// linha de montagem. Rode com o rodar, leia as mensagens e responda: qual
// estação reclamou de cada erro? Depois conserte.
//
// Dicas:
// 1. Um erro é de gramática do C. O outro é um nome digitado errado.
// 2. Conserte o primeiro e rode de novo: só então o segundo aparece inteiro.
// 3. Resposta esperada: falta ";" depois do primeiro printf (compilador:
//    "expected ';'"); "prinft" está escrito errado (o compilador só avisa
//    "implicit declaration", e o ligador para com "undefined reference to
//    prinft"). Consertado, mostra "Linha 1" e "Linha 2".
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

int main(void) {
    printf("Linha 1\n")
    prinft("Linha 2\n");
    return 0;
}
