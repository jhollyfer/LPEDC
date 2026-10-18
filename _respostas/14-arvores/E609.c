// 0102 · Heap e fila de prioridade
// Exercício E609 · ★★☆
//
// Resposta: a saída é
//
//   depois das 5 inserções: [45 35 25 15 5]
//   saiu 45: [35 15 25 5]
//   entrou 40: [40 35 25 5 15]
//   saiu 40: [35 15 25 5]
//   saiu 35: [25 15 5]
//
// Inserções: 15; 35 sobe sobre o 15; 25 fica; 45 entra no índice 3, passa o
// 15 e o 35; 5 fica. Tirar o 45: o 5 vai para a raiz e desce pelo 35 (maior
// que 25) e depois pelo 15. Entrar 40: índice 4, pai 15 (troca), pai 35
// (troca). Tirar o 40: o 15 vai para a raiz e desce pelo 35; os filhos dele
// agora são só o 5, então para. Tirar o 35: o 5 sobe para a raiz e desce
// pelo 25.
