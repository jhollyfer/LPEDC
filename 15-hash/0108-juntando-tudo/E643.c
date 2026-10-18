// 0108 · Juntando tudo: o contador de palavras
// Exercício E643 · ★☆☆
//
// O primeiro passo do contador é quebrar o texto em palavras. Escreva um
// programa que percorre a frase "Bom dia, Brasil! Bom dia, São Paulo.",
// mostra cada palavra em minúsculas, uma por linha, e no fim o total.
// Palavra é uma sequência de letras; letra é o que isalpha aceita ou
// qualquer byte de 128 para cima (os pedaços de "ã" em UTF-8).
//
//   Saída esperada:
//   bom
//   dia
//   brasil
//   bom
//   dia
//   são
//   paulo
//   7 palavras
//
// Dicas:
// 1. Dois laços dentro de um: o primeiro pula o que não é letra, o segundo
//    mostra as letras com putchar(tolower(...)).
// 2. Sempre converta para unsigned char antes de chamar isalpha e tolower.
// 3. Resposta esperada: a saída acima. O "São" sai como "são": o tolower
//    muda o 'S' e deixa os bytes do "ã" como estão.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <ctype.h>

int main(void) {

    return 0;
}
