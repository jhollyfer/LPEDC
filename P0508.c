// Lista · Módulo 05 · Vetores, matrizes e strings
// Exercício P0508 · ★☆☆ · O nome do crachá
//
// O crachá do congresso mostra o sobrenome em maiúsculas, uma vírgula e o
// primeiro nome. Com
//
//   char nome[] = "Raimunda";
//   char sobrenome[] = "Nonato";
//
// monte numa terceira string char cracha[40] o texto "NONATO, Raimunda",
// usando strcpy e strcat. Depois mostre o crachá, o tamanho dele (strlen) e
// as iniciais "R.N.".
//
//   Saída esperada:
//   Crachá: NONATO, Raimunda
//   Tamanho: 16
//   Iniciais: R.N.
//
// Dicas:
// 1. strcpy(cracha, sobrenome) copia; depois passe cada posição de cracha
//    por toupper até o '\0'.
// 2. strcat(cracha, ", ") e strcat(cracha, nome) completam o texto.
// 3. As iniciais são nome[0] e sobrenome[0]: mostre com %c.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char nome[] = "Raimunda";
    char sobrenome[] = "Nonato";
    char cracha[40];
    (void) nome, (void) sobrenome, (void) cracha; // apague esta linha quando escrever

    return 0;
}
