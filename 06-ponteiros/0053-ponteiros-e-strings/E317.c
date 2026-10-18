// 0053 · Ponteiros e strings
// Exercício E317 · ★★★
//
// Escreva bool palindromo(const char *s), que diz se uma frase é um
// palíndromo IGNORANDO os espaços. Use dois ponteiros: um no começo e outro
// no último caractere (antes do '\0'), que andam um em direção ao outro,
// pulando espaços. Teste com "arara", "socorram me subi no onibus em
// marrocos" e "pix caiu".
//
//   Saída esperada:
//   arara: sim
//   socorram me subi no onibus em marrocos: sim
//   pix caiu: não
//
// Dicas:
// 1. fim = s + strlen(s) - 1. Cuidado com a string vazia.
// 2. while (ini < fim): se *ini é espaço, ini++ e continue; se *fim é
//    espaço, fim-- e continue; se forem diferentes, não é palíndromo.
// 3. Resposta esperada: sim, sim, não.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(void) {

    return 0;
}
