// 0101 · AVL: balanceamento e rotações
// Exercício E602 · ★☆☆
//
// Resposta: a saída é
//
//   30 10 20 -> pré 20 10 30 | altura 1 | rotações 2
//   1 a 7    -> pré 4 2 1 3 6 5 7 | altura 2 | rotações 6
//
// 30, 10, 20: o 30 fica com +2 e o filho 10 com -1 (esquerda-direita).
// Rotação dupla: à esquerda no 10 (o 20 sobe) e à direita no 30. São 2.
// 1 a 7: rotação à esquerda no 1 (ao inserir 3), no 3 (ao inserir 5), no 2
// (ao inserir 6, a raiz vira 4) e no 5 (ao inserir 7). São mais 4, e o
// contador é um só: 2 + 4 = 6. A árvore final é perfeita, com raiz 4.
