// 0108 · Heapsort
// Exercício E643 · ★☆☆
//
// Resposta:
// Fase 1 (pais 2, 1 e 0):
//   pai 2 (o 2): filho único 8, troca          → [3 9 8 7 5 2]
//   pai 1 (o 9): filhos 7 e 5, 9 é maior: fica → [3 9 8 7 5 2]
//   pai 0 (o 3): troca com o 9 e depois com o 7 → [9 7 8 3 5 2]
// Fase 2:
//   troca 9 com 2, o 2 desce pelo 8            → [8 7 2 3 5 | 9]
//   troca 8 com 5, o 5 desce pelo 7            → [7 5 2 3 | 8 9]
