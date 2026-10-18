// 0112 · Dijkstra: caminho mínimo
// Exercício E672 · ★★★
//
// Resposta:
// a) O programa mostra:
//      A: R$ 5
//      B: R$ 6
//      C: R$ 6
// b) O certo é A = 3 (Base -> B -> A: 6 + (-3)) e C = 4 (Base -> B -> A -> C).
//    B continua 6.
// c) Dijkstra fixa A com 5 porque é o menor dist naquele momento, supondo
//    que nenhum caminho por outro vértice (B, com dist 6) pode ficar mais
//    barato: somar pesos não negativos só aumenta. O trecho de -3 quebra essa
//    hipótese. Quando B é fixado, A já está fixo e C já foi calculado a partir
//    do valor errado. Dijkstra exige pesos >= 0; com pesos negativos (e sem
//    ciclo negativo) use Bellman-Ford, que relaxa todas as arestas V - 1 vezes.
