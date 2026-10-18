// 0088 · Pilha encadeada
// Exercício E523 · ★☆☆
//
// Resposta:
//   empilha 3      topo -> 3 -> NULL
//   empilha 8      topo -> 8 -> 3 -> NULL
//   desempilha     topo -> 3 -> NULL            mostra "8"
//   empilha 5      topo -> 5 -> 3 -> NULL
//   empilha 9      topo -> 9 -> 5 -> 3 -> NULL
//   desempilha     topo -> 5 -> 3 -> NULL       mostra "9"
//   topo           (não muda)                   mostra "2 itens, topo 5"
// mallocs: 5 (1 da struct da pilha + 4 nós).
// frees: 5 (2 nos desempilhas + 2 nós no pilha_libera + 1 da struct).
