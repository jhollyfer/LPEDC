// Lista · Módulo 27 · Detalhes de C que caem em prova
// Exercício P2707 · ★☆☆ · A lista da feira no arquivo
//
// Grave a lista da feira no arquivo p2707_feira.txt, um item por linha no
// formato nome;preço, com fopen e fprintf. Feche, abra de novo para leitura,
// leia cada linha com fscanf e some os preços. No fim, apague o arquivo com
// remove.
//
//   banana 6.50    tomate 8.90    alface 3.00    queijo 22.40
//
//   Saída esperada:
//   gravados 4 itens
//   banana: R$ 6.50
//   tomate: R$ 8.90
//   alface: R$ 3.00
//   queijo: R$ 22.40
//   total da feira: R$ 40.80
//
// Dicas:
// 1. Sempre confira se o fopen devolveu NULL.
// 2. fscanf(f, " %31[^;];%lf", nome, &preco) lê o nome até o ; e depois o
//    número. O espaço no começo pula o \n da linha anterior.
// 3. O laço continua enquanto o fscanf devolver 2.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
