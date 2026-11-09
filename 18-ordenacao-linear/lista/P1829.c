// Lista · Módulo 18 · Ordenação além da comparação e seleção
// Exercício P1829 · ★★★ · A classificação do campeonato com quatro critérios
//
// No campeonato amador do Amazonas, a classificação segue os critérios, em
// ordem: mais PONTOS, depois mais VITÓRIAS, depois maior SALDO de gols e, por
// fim, ordem ALFABÉTICA. Os times chegam do sistema já em ordem alfabética.
//
// Monte a tabela só com passadas estáveis de counting sort, da chave menos
// significativa para a mais (o alfabeto já vem resolvido pela entrada):
// saldo, vitórias e pontos, todas DECRESCENTES. O saldo vai de -30 a +30:
// desloque a chave para ficar em 0..60. Mostre a ordem depois de cada
// passada e a tabela final, e confira com o qsort e um comparador dos quatro
// critérios.
//
//   Saída esperada:
//   por saldo:     Tucu Tamb Boto Jara Arar Pira Peix Vito Onca Suma
//   por vitórias:  Tucu Boto Jara Tamb Peix Arar Pira Vito Onca Suma
//   por pontos:    Tucu Boto Jara Tamb Peix Arar Pira Vito Onca Suma
//    #  Time           Pts  V  Saldo
//    1  Tucunare        22  7    +11
//    2  Boto Rosa       19  6     +8
//    3  Jaraqui         19  6     +5
//    4  Tambaqui        19  5     +9
//    5  Peixe-Boi       15  5     -1
//    6  Arara Azul      15  4     +3
//    7  Pirarucu        15  4     +3
//    8  Vitoria-Regia   10  3     -2
//    9  Onca Pintada    10  2     -6
//   10  Sumauma          7  1    -12
//   qsort concorda: sim
//
// Dicas:
// 1. Decrescente e estável: use a chave invertida (MAX - valor). Para o
//    saldo, chave = 30 - saldo, que vai de 0 (saldo +30) a 60 (saldo -30).
// 2. A ordem das passadas é saldo, vitórias, pontos: a última decide o
//    critério principal, e cada passada estável preserva os desempates das
//    anteriores.
// 3. O qsort não é estável, mas aqui isso não importa: com o nome no
//    comparador, não há dois times "iguais".
// 4. Resposta esperada: Tucunare (22 pts) em 1º; Boto e Jaraqui empatam em
//    19 pontos e 6 vitórias, e o saldo (+8 contra +5) põe o Boto na frente;
//    Arara e Pirarucu empatam em tudo menos no nome; o qsort concorda.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

typedef struct {
    const char *nome;
    int pontos, vitorias, saldo;
} Time;

int main(void) {
    Time v[N] = {{"Arara Azul", 15, 4, 3},   {"Boto Rosa", 19, 6, 8},     {"Jaraqui", 19, 6, 5},
                 {"Onca Pintada", 10, 2, -6}, {"Peixe-Boi", 15, 5, -1},    {"Pirarucu", 15, 4, 3},
                 {"Sumauma", 7, 1, -12},     {"Tambaqui", 19, 5, 9},      {"Tucunare", 22, 7, 11},
                 {"Vitoria-Regia", 10, 3, -2}};

    for (int i = 0; i < N; i++) printf("%s %d\n", v[i].nome, v[i].pontos);
    return 0;
}
