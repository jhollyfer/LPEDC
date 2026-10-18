// 0086 · Fila encadeada
// Exercício E511 · ★☆☆
//
// Resposta:
//   insere 7   inicio -> 7 -> NULL           (fim no 7)
//   insere 4   inicio -> 7 -> 4 -> NULL      (fim no 4)
//   retira     inicio -> 4 -> NULL           mostra "7 " (fim no 4)
//   insere 9   inicio -> 4 -> 9 -> NULL      (fim no 9)
//   retira     inicio -> 9 -> NULL           mostra "4 " (fim no 9)
//   insere 1   inicio -> 9 -> 1 -> NULL      (fim no 1)
//   retira     inicio -> 1 -> NULL           mostra "9 " (fim no 1)
// Saída: "7 4 9 " e "sobrou 1 (1 na fila)".
// inicio e fim apontam para o mesmo nó quando a fila tem um nó só: depois
// de inserir o 7 e depois de cada uma das três retiradas.
