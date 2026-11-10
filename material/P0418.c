// Lista · Módulo 04 · Funções e modularização
// Exercício P0418 · ★★☆ · O imposto de cada estado
//
// A mesma loja virtual compila uma versão do sistema para cada estado. Escreva
// o programa com "#define ESTADO 1" no topo e, com #if, #elif e #else, defina
// ICMS como 0.20 para o Amazonas (1), 0.18 para São Paulo (2) e 0.17 para os
// outros, e NOME_ESTADO com o nome. Escreva também a macro MOSTRAR(expr), que
// mostra o texto da expressão (com #expr) e o valor dela. Para um produto de
// R$ 100.00:
//
//   Saída esperada:
//   Estado: Amazonas
//   preco * (1 + ICMS) = 120.00
//   preco * ICMS = 20.00
//
// Dicas:
// 1. #if ESTADO == 1 ... #define ICMS 0.20 ... #elif ESTADO == 2 ... #else
//    ... #endif.
// 2. #define MOSTRAR(expr) printf("%s = %.2f\n", #expr, (expr)). O #expr vira
//    o texto da expressão, entre aspas.
// 3. Troque ESTADO para 2 e a saída vira 118.00 e 18.00, sem mexer em mais
//    nada.
// 4. Resposta esperada: 120.00 e 20.00 com ESTADO 1.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
