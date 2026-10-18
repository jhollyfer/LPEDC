// 0093 · Insertion sort
// Exercício E556 · ★★☆
//
// Resposta:
//   j = 1: 3 6 8 3 1 (deslocou 1)
//   j = 2: 3 6 8 3 1 (deslocou 0)
//   j = 3: 3 3 6 8 1 (deslocou 2)
//   j = 4: 1 3 3 6 8 (deslocou 4)
//   total: 7
// O segundo 3 empurra o 8 e o 6 e para no primeiro 3 (3 > 3 é falso): os dois
// 3 mantêm a ordem de chegada, o insertion é estável. O total 7 é o número de
// inversões do vetor original.
