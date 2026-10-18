// 0096 · Comparando: estabilidade, custo e qsort
// Exercício E576 · ★★★
//
// O boletim está em ordem alfabética: Ana 8, Bruno 9, Caio 8, Duda 7,
// Enzo 9, Fabi 8, Gui 7. A coordenação quer por nota, da maior para a menor,
// e, entre empatados, a ordem alfabética de antes. O qsort não promete ser
// estável, então FORCE a estabilidade: acrescente à struct um campo ordem
// com a posição original de cada aluno e use-o como desempate.
//
//   typedef struct { char nome[10]; int nota; int ordem; } Aluno;
//
//   Saída esperada:
//   9 Bruno
//   9 Enzo
//   8 Ana
//   8 Caio
//   8 Fabi
//   7 Duda
//   7 Gui
//
// Dicas:
// 1. Antes do qsort, um laço faz turma[i].ordem = i.
// 2. Na compara: notas diferentes decidem (decrescente); notas iguais,
//    decide a ordem (crescente).
// 3. Com esse desempate, não existem dois elementos "iguais" para a compara,
//    então a estabilidade do algoritmo deixa de importar.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
