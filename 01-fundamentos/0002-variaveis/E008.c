// 0002 · Variáveis
// Exercício E008 · ★☆☆
//
// Quais destes nomes de variável o C aceita? Para cada inválido, diga o
// motivo. Depois tente declarar alguns (int nome = 0;) e veja o erro do gcc.
//
//   preco_kg    2via       _total      valor-final   Preco
//   float       nota1      média       qtd$          dia util
//
// E mais uma: preco e Preco podem existir no mesmo programa? São a mesma
// variável?
//
// Dicas:
// 1. Só letras, dígitos e _, sem começar por dígito, sem acento, sem espaço.
// 2. Palavras do próprio C (int, float, return...) são reservadas.
// 3. Resposta esperada: válidos: preco_kg, _total, Preco, nota1. Inválidos:
//    2via (começa com dígito), valor-final (o - é subtração), float (palavra
//    reservada), média (acento), qtd$ ($ não faz parte do padrão; o gcc
//    aceita como extensão, mas não use) e dia util (espaço). preco e Preco
//    podem coexistir e são variáveis diferentes. Evite começar nomes com _:
//    é válido, mas o compilador e a biblioteca usam esses nomes.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
