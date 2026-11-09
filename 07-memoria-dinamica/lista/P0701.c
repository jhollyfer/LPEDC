// Lista · Módulo 07 · Memória dinâmica
// Exercício P0701 · ★☆☆ · Uma cópia no heap
//
// O motorista de aplicativo anotou os km rodados nas corridas de hoje:
//
//   double km[6] = {12.4, 3.8, 25.1, 7.6, 18.0, 5.3};
//
// Escreva double *copiar(const double *v, int n), que reserva com malloc um
// bloco novo do tamanho exato, copia os n valores e devolve o endereço (ou
// NULL se faltar memória). No main, faça a cópia, aplique na CÓPIA um
// desconto de 10% em cada corrida e mostre os dois vetores e o total de cada
// um. No fim, libere a cópia:
//
//   Saída esperada:
//   Original: 12.40  3.80 25.10  7.60 18.00  5.30 | total 72.20
//   Desconto: 11.16  3.42 22.59  6.84 16.20  4.77 | total 64.98
//
// Dicas:
// 1. double *novo = malloc(n * sizeof *novo); e confira if (novo == NULL).
// 2. sizeof *novo é o tamanho de UM double (8 bytes): escrever assim
//    continua certo mesmo se o tipo do ponteiro mudar.
// 3. km mora na pilha (some com o main); a cópia mora no heap e só some com
//    free.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    double km[6] = {12.4, 3.8, 25.1, 7.6, 18.0, 5.3};
    (void) km; // apague esta linha quando escrever

    return 0;
}
