// Lista · Módulo 20 · Divisão e conquista e algoritmos gulosos
// Exercício P2011 · ★★☆ · Mínimo e máximo de dois em dois
//
// O aplicativo da corrida de rua guarda os tempos dos 10 atletas da
// categoria, em segundos: 1520 1384 1702 1455 1611 1398 1830 1290 1477
// 1563. Achar o menor com um laço e o maior com outro custa 2(n - 1) = 18
// comparações. Dá para fazer com 3n/2 - 2: ande de DOIS em DOIS, compare
// os dois entre si (1 comparação), depois o menor deles com o mínimo e o
// maior com o máximo (mais 2). São 3 comparações para cada 2 elementos.
// Escreva do zero as duas versões, contando as comparações, e mostre os
// resultados.
//
//   Saída esperada:
//   Ingênuo: menor 1290, maior 1830, 18 comparações
//   Aos pares: menor 1290, maior 1830, 13 comparações
//
// Dicas:
// 1. Comece com o primeiro par: compare v[0] com v[1] (1 comparação) e
//    eles viram o mínimo e o máximo iniciais. Depois, de i = 2 em diante,
//    de 2 em 2.
// 2. Com n ímpar, o primeiro elemento sozinho seria mínimo e máximo, e os
//    pares começariam em i = 1. Aqui n = 10.
// 3. Resposta esperada: 1290 e 1830 nas duas; 18 comparações contra 13
//    (3 · 10 / 2 - 2). É o limite inferior para achar os dois (Cormen 9.1).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
