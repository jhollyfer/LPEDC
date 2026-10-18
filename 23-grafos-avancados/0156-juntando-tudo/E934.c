// 0156 · Juntando tudo: o assistente do calouro
// Exercício E934 · ★★☆
//
// A faculdade só deixa cursar DUAS disciplinas por semestre. Escreva
// planeja(limite, mostrar): a cada semestre, escolhe até "limite"
// disciplinas liberadas (grau de entrada 0 e ainda não feitas), as de menor
// índice primeiro, e só depois do semestre desconta os graus das que
// dependem delas. Devolve o número de semestres (ou -1 se travar). As
// regras de pré-requisito:
//
//   Algoritmos -> Estruturas   Cálculo I -> Cálculo II   Cálculo I -> Física
//   Estruturas -> Redes        Cálculo II -> TCC         Redes -> TCC
//
//   Saída esperada:
//   Sem limite: 4 semestres
//   Com no máximo 2 por semestre:
//     1º: Algoritmos Cálculo I
//     2º: Inglês Física
//     3º: Cálculo II Estruturas
//     4º: Redes
//     5º: TCC
//     total: 5 semestres
//
// Dicas:
// 1. Guarde as escolhidas do semestre num vetor e só desconte os graus
//    depois de escolher todas. Se descontar na hora, uma disciplina e o
//    pré-requisito dela podem cair no mesmo semestre.
// 2. "Sem limite" é a mesma função com limite = V.
// 3. Resposta esperada: a saída acima. Repare que escolher pelo índice não
//    é o melhor: com Cálculo II e Estruturas no 2º semestre, daria para
//    terminar em 4. Priorizar quem tem a corrente mais longa pela frente é a
//    regra usada na prática (e um bom desafio para depois).
//
// Escreva sua resposta abaixo (escreva planeja):

#include <stdbool.h>
#include <stdio.h>

#define V 8

const char *disc[V] = {"Algoritmos", "Cálculo I", "Inglês", "Física",
                       "Cálculo II", "Estruturas", "Redes", "TCC"};
int pre[V][V];

int planeja(int limite, bool mostrar) {
    (void)limite; // apague estas duas linhas
    (void)mostrar;
    return 0;
}

int main(void) {
    int regras[][2] = {{0, 5}, {1, 4}, {1, 3}, {5, 6}, {4, 7}, {6, 7}};
    for (int k = 0; k < 6; k++) pre[regras[k][0]][regras[k][1]] = 1;

    printf("Sem limite: %d semestres\n", planeja(V, false));
    printf("Com no máximo 2 por semestre:\n");
    int s = planeja(2, true);
    printf("  total: %d semestres\n", s);
    return 0;
}
