// 0103 · Heapsort
// Exercício E616 · ★★☆
//
// Resposta: a saída é
//
//   depois da fase 1: 7 5 6 4 2 1 3
//   trocas na fase 1: 4
//   trocas na fase 2: 6
//   ordenado: 1 2 3 4 5 6 7
//
// Fase 1: o 3 troca com o 7 ([1 2 7 4 5 6 3]); o 2 troca com o 5
// ([1 5 7 4 2 6 3]); o 1 troca com o 7 e depois com o 6 ([7 5 6 4 2 1 3]).
// São 4 trocas: o vetor crescente está "de cabeça para baixo" para um heap.
// Na fase 2, o heapsort faz o trabalho de sempre: ele não percebe que o vetor
// já estava em ordem (ao contrário do insertion sort, que seria O(n) aqui).
