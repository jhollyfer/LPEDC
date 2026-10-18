// 0112 · Endereçamento aberto
// Exercício E672 · ★★★
//
// A sondagem linear sofre com o agrupamento: chaves com o mesmo hash formam
// um bloco que cresce. O hash duplo resolve com um passo que depende da
// chave: em vez de i = (i + 1) % m, faz i = (i + passo) % m, com
// passo = 1 + k % 10. Com m = 11 (primo), qualquer passo de 1 a 10 visita
// todas as posições.
//
// Escreva uma função que simula as inserções numa tabela de 11 posições e
// recebe o passo como ponteiro para função. Para as chaves
//
//   5 16 27 8 38 19 30 2
//
// mostre as sondagens de cada inserção e o total, primeiro com passo 1
// (linear), depois com o hash duplo.
//
//   Saída esperada:
//   linear: 1 2 3 1 5 3 4 1 | total: 20
//   duplo : 1 2 2 1 2 2 2 4 | total: 16
//
// Dicas:
// 1. "int passo_linear(int k)" devolve 1 (use (void)k para calar o aviso
//    de parâmetro não usado) e "int passo_duplo(int k)" devolve 1 + k % 10.
// 2. A função recebe "int (*passo)(int)" e começa cada simulação com a
//    tabela toda livre.
// 3. Resposta esperada: a saída acima. Na linear, 5, 16, 27 e 38 (hash 5)
//    formam um bloco 5-6-7 que engole o 8 e cresce até a 9; o 38 paga 5
//    sondagens. No duplo, cada um salta com o seu passo e o bloco não se
//    forma.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
