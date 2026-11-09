// Lista · Módulo 07 · Memória dinâmica
// Exercício P0703 · ★☆☆ · A lista de espera que cresce de 3 em 3
//
// O posto de vacinação registra as senhas que chegam num vetor dinâmico de
// int que começa com capacidade 3 e, quando enche, ganha mais 3 posições com
// realloc. Chegaram estas 8 senhas:
//
//   int chegada[8] = {501, 502, 503, 504, 505, 506, 507, 508};
//
// Adicione uma de cada vez e mostre uma linha toda vez que a capacidade
// mudar. No fim, mostre o vetor e libere:
//
//   Saída esperada:
//   Capacidade inicial: 3
//   Senha 504 não cabia: capacidade agora 6
//   Senha 507 não cabia: capacidade agora 9
//   Fila (8 de 9): 501 502 503 504 505 506 507 508
//
// Dicas:
// 1. Guarde três coisas: int *v, int n (quantos estão em uso) e int cap
//    (quantos cabem).
// 2. Antes de pôr a senha: if (n == cap) { int *novo = realloc(v, (cap + 3)
//    * sizeof *v); ... }. Use um ponteiro novo: se o realloc falhar, v
//    continua valendo e precisa ser liberado.
// 3. Para começar, v = malloc(3 * sizeof *v) e cap = 3.
// 4. Resposta esperada: a saída acima (3 -> 6 -> 9).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int chegada[8] = {501, 502, 503, 504, 505, 506, 507, 508};
    (void) chegada; // apague esta linha quando escrever

    return 0;
}
