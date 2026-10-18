// 0096 · Comparando: estabilidade, custo e qsort
// Exercício E572 · ★☆☆
//
// Para cada situação, escolha UM algoritmo do módulo (bubble, selection,
// insertion, merge, quick ou o qsort da biblioteca) e justifique em uma
// linha. Responda como comentário.
//
//   a) Um placar de 20 jogadores, reordenado a cada ponto marcado (o vetor
//      está sempre quase em ordem).
//   b) A lista de alunos já está em ordem alfabética e você quer ordenar
//      por nota sem bagunçar a ordem alfabética dos empatados, sem mexer
//      na compara.
//   c) Registros enormes num cartão de memória lento: cada troca custa
//      caro, comparar é barato.
//   d) Um servidor que ordena dados enviados por usuários e não pode, de jeito
//      nenhum, cair num caso O(n²).
//   e) Ordenar um vetor de structs num programa comum, sem requisitos
//      especiais.
//   f) Em que situação real o bubble sort é a melhor escolha?
//
// Dicas:
// 1. Releia a tabela de custo e estabilidade do assunto.
// 2. "Adaptativo" e "estável" são as palavras-chave de a) e b).
// 3. Resposta esperada: a) insertion; b) merge (estável); c) selection (no
//    máximo n - 1 trocas); d) merge (n log n garantido); e) qsort; f) em
//    nenhuma: o insertion faz o mesmo papel melhor.
//
// Escreva sua resposta abaixo (como comentário):

#include <stdio.h>

int main(void) {

    return 0;
}
