// Lista · Módulo 13 · Busca e ordenação
// Exercício P1316 · ★★☆ · Classificação do concurso com desempate
//
// O edital do concurso da prefeitura diz: classifica primeiro quem tem a
// maior nota; no empate, o candidato mais velho; persistindo, a ordem
// alfabética do nome. Escreva a função compara para o qsort com essa chave
// composta e mostre a classificação.
//
//   Candidatos: Paulo 82 (30 anos), Rita 90 (25), Lucas 82 (41), Ana 82 (30),
//   Bruna 75 (52), Igor 90 (25), Celia 82 (41)
//
//   Saída esperada:
//   1º Igor   nota 90, 25 anos
//   2º Rita   nota 90, 25 anos
//   3º Celia  nota 82, 41 anos
//   4º Lucas  nota 82, 41 anos
//   5º Ana    nota 82, 30 anos
//   6º Paulo  nota 82, 30 anos
//   7º Bruna  nota 75, 52 anos
//
// Dicas:
// 1. Compare um critério de cada vez: só passe para o próximo se o atual
//    empatar.
// 2. Para "maior primeiro", inverta: (y->nota > x->nota) - (y->nota < x->nota).
// 3. O último critério é strcmp(x->nome, y->nome).
// 4. Mostre cada linha com printf("%dº %-6s nota %d, %d anos\n", ...).
// 5. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (escreva compara):

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[12];
    int nota;
    int idade;
} Candidato;

int main(void) {
    Candidato c[] = {
        {"Paulo", 82, 30}, {"Rita", 90, 25}, {"Lucas", 82, 41}, {"Ana", 82, 30},
        {"Bruna", 75, 52}, {"Igor", 90, 25}, {"Celia", 82, 41},
    };
    int n = 7;

    // ordene com qsort(c, n, sizeof c[0], compara) e mostre
    (void)c;
    (void)n;
    return 0;
}
