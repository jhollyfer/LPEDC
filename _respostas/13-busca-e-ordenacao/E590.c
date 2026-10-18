// 0099 · Merge sort
// Exercício E590 · ★☆☆
//
// Resposta:
//   [0, 5)
//     [0, 2)
//       [0, 1)
//       [1, 2)
//     [2, 5)
//       [2, 3)
//       [3, 5)
//         [3, 4)
//         [4, 5)
// São 9 chamadas: as 5 folhas são os pedaços de 1 elemento, e as 4 de cima
// são as que fazem intercalação (sempre n - 1 delas). Com 5 elementos a
// árvore fica torta: a metade direita, de 3, desce um nível a mais.
