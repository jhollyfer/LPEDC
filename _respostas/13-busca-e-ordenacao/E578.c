// 0097 · Selection sort
// Exercício E578 · ★☆☆
//
// Resposta:
//   i = 0: 1 3 2 5 4
//   i = 1: 1 2 3 5 4
//   i = 2: 1 2 3 5 4
//   i = 3: 1 2 3 4 5
//   trocas: 3
// Na passada i = 2 o menor de v[2..4] já é o próprio v[2] (o 3): menor == i,
// e o if pula a troca. As comparações continuam 4 + 3 + 2 + 1 = 10.
