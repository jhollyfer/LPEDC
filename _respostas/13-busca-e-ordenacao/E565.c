// 0095 · Quick sort
// Exercício E565 · ★☆☆
//
// Resposta:
//   troca v[0] e v[1]
//   troca v[1] e v[3]
//   troca v[2] e v[5]
//   vetor: 2 4 5 9 8 6
//   pivô na posição 2
// O 2 (k = 1) vai para a gaveta 0 e o 4 (k = 3) para a 1. A última troca põe
// o pivô 5 em v[2]: à esquerda só há menores (2 4), à direita só maiores
// (9 8 6), ainda fora de ordem entre si.
