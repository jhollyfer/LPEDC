// 0120 · Counting sort
// Exercício E720 · ★★★
//
// Quem quebra códigos secretos começa contando letras. Escreva um programa
// que mostre as letras da frase abaixo da MAIS frequente para a menos
// frequente (só as que aparecem), com empates em ordem alfabética:
//
//   o rato roeu a roupa do rei de roma e a rainha ficou brava
//
//   Saída esperada:
//   a:9 o:7 r:7 e:4 i:3 u:3 d:2 b:1 c:1 f:1 h:1 m:1 n:1 p:1 t:1 v:1
//
// A regra: nada de comparar letra com letra. Conte as frequências (um
// contador por letra) e depois ordene as 26 letras com um counting sort
// estável cuja chave é a frequência.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {
    const char *frase = "o rato roeu a roupa do rei de roma e a rainha ficou brava";
    (void) frase; // apague esta linha

    return 0;
}
