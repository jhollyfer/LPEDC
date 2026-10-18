// 0084 · Pilha na prática: parênteses e notação pós-fixa
// Exercício E499 · ★☆☆
//
// Resposta:
//   a) (7 + 3) * 2        ->  7 3 + 2 *          = 20
//   b) 7 + 3 * 2          ->  7 3 2 * +          = 13
//   c) 100 / (2 + 3) - 4  ->  100 2 3 + / 4 -    = 16
//   d) 6 2 / 3 1 - *
//      lê 6: 6 | lê 2: 6 2 | lê /: 3 | lê 3: 3 3 | lê 1: 3 3 1 |
//      lê -: 3 2 | lê *: 6. Vale 6; a infixa é (6 / 2) * (3 - 1).
