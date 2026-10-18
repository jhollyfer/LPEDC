// 0112 · Dijkstra: caminho mínimo
// Exercício E667 · ★☆☆
//
// Resposta (teste de mesa, dist depois de relaxar):
//
//   Fixa      | CD | A  | B | C  | D
//   (início)  | 0  | ∞  | ∞ | ∞  | ∞
//   CD (0)    | 0  | 7  | 2 | ∞  | ∞
//   B (2)     |    | 5  | 2 | 10 | ∞     A: 2 + 3 = 5 < 7; C: 2 + 8 = 10
//   A (5)     |    | 5  |   | 6  | 11    C: 5 + 1 = 6 < 10; D: 5 + 6 = 11
//   C (6)     |    |    |   | 6  | 8     D: 6 + 2 = 8 < 11
//   D (8)     |    |    |   |    | 8
//
// Finais: A = 5, B = 2, C = 6, D = 8.
// Caminho até D: CD -> B -> A -> C -> D (2 + 3 + 1 + 2 = 8 km).
