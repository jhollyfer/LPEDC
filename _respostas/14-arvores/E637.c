// 0107 · Heap e fila de prioridade
// Exercício E637 · ★☆☆
//
// Resposta:
// a) [95 60 80 20 60 75 10]: é heap. Pais: 95 >= 60, 80; 60 >= 20, 60;
//    80 >= 75, 10. Repetido não atrapalha (a regra é >=).
// b) [50 40 45 42 10 30 44]: não é. v[3] = 42 tem pai v[1] = 40.
//    (O 44 em v[6] está certo: o pai dele é v[2] = 45.)
// c) [7]: é heap (um elemento só, não há pai para conferir).
// d) [10 20]: não é. v[1] = 20 tem pai v[0] = 10.
// e) [9 8 7 6 5 4 3 2 1]: é heap. Num vetor decrescente, todo pai vem antes
//    do filho e por isso é maior. A recíproca é falsa: (a) é heap e não é
//    decrescente.
