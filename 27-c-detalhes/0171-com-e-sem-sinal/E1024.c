// 0171 · Com sinal e sem sinal
// Exercício E1024 · ★★☆
//
// Escreva duas funções que não caiam na armadilha do size_t, que nunca é
// negativo:
//
//   const char *mais_longo(const char *a, const char *b)
//   size_t restantes(const char *msg, size_t limite)
//
// mais_longo devolve o nome mais comprido (no empate, o segundo).
// restantes diz quantos caracteres ainda cabem numa mensagem de até
// limite caracteres, e dá 0 quando a mensagem já passou. No main, chame
// mais_longo com ("Ana", "Bernardo") e ("Bernardo", "Ana"), e restantes com
// "Oi, tudo bem?" e com "Chego em 15 minutos, me espera", ambas com limite 20.
//
//   Saída esperada:
//   mais longo: Bernardo
//   mais longo: Bernardo
//   restam 7 caracteres
//   restam 0 caracteres
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

const char *mais_longo(const char *a, const char *b);
size_t restantes(const char *msg, size_t limite);

int main(void) {

    return 0;
}
