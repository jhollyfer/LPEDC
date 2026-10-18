// 0090 · Fila
// Exercício E535 · ★☆☆
//
// Resposta (CAPACIDADE 4):
//   operação     vetor          inicio  n
//   começo       [_, _, _, _]   0       0
//   insere 1     [1, _, _, _]   0       1   gaveta (0 + 0) % 4 = 0
//   insere 2     [1, 2, _, _]   0       2   gaveta 1
//   retira -> 1  [1, 2, _, _]   1       1   o 1 fica lá, mas saiu
//   insere 3     [1, 2, 3, _]   1       2   gaveta (1 + 1) % 4 = 2
//   insere 4     [1, 2, 3, 4]   1       3   gaveta 3
//   insere 5     [5, 2, 3, 4]   1       4   gaveta (1 + 3) % 4 = 0: deu a volta
//   insere 6     recusado: n == 4, a fila está cheia
//   retira -> 2  [5, 2, 3, 4]   2       3
//   retira -> 3  [5, 2, 3, 4]   3       2
// Sobram 4 e 5, nessa ordem. O próximo entraria na gaveta (3 + 2) % 4 = 1.
