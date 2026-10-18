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
// Dicas:
// 1. freq[letra - 'a']++ para cada letra de 'a' a 'z' (pule os espaços).
// 2. O counting sort deixa as chaves em ordem crescente. Para a ordem
//    decrescente, use a chave maior - freq[l], em que maior é a maior
//    frequência: a letra mais frequente fica com chave 0.
// 3. Se as letras entrarem de 'a' a 'z' e o sort for estável (terceiro
//    laço de trás para a frente), os empates saem em ordem alfabética sem
//    nenhum esforço extra.
// 4. O vetor ordenado guarda letras (0 a 25), não frequências: ranking[i]
//    é a letra que ficou na posição i.
// 5. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {
    const char *frase = "o rato roeu a roupa do rei de roma e a rainha ficou brava";
    (void) frase; // apague esta linha

    return 0;
}
