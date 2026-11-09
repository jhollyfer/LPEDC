// 0186 · P e NP
// Exercício E1113 · ★★☆
//
// No texto, a força bruta para na primeira atribuição que satisfaz o
// churrasco. Agora o organizador quer TODAS as opções de grupo. Escreva o
// programa com a mesma fórmula do texto (Ana, Beto, Caio, Davi; cláusulas
// {1, 2}, {-1, -3}, {3, 4}, {-2, 4}, {-4, -1, 3}), percorra as 16 máscaras
// e mostre, numeradas, só os nomes de quem vai em cada grupo válido, além
// do total.
//
//   Saída esperada:
//   Grupo 1: Beto Davi
//   Grupo 2: Beto Caio Davi
//   Total: 2 de 16 atribuições
//
// Dicas:
// 1. Copie o verificador do texto. O laço externo vai de 0 a (1 << 4) - 1
//    e não para no primeiro sim.
// 2. A Ana nunca aparece: com ela, a cláusula 2 tira o Caio, a 3 obriga o
//    Davi e a 5 exige o Caio de volta. Confira isso nos números.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
