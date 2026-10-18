// 0110 · BFS: busca em largura
// Exercício E655 · ★☆☆
//
// Resposta (saída do programa):
//   Penha(0) Lapa(1) Moema(1) Tatuape(1) Centro(2) Saude(2)
//
// Fila: [Penha] -> tira Penha, entram Lapa, Moema, Tatuape (dist 1)
//       -> tira Lapa, entra Centro (dist 2)
//       -> tira Moema, entra Saude (dist 2; Centro já tem dist)
//       -> tira Tatuape (Saude já tem dist) -> tira Centro -> tira Saude.
