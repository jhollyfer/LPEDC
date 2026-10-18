// 0088 · Juntando tudo: a calculadora de expressões
// Exercício E523 · ★☆☆
//
// Resposta: conversão de 2 * (3 + 4)
//   lê   pilha de operadores   fila de saída
//   2    (vazia)               2
//   *    *                     2
//   (    * (                   2
//   3    * (                   2 3
//   +    * ( +                 2 3            (o "(" protege o *)
//   4    * ( +                 2 3 4
//   )    *                     2 3 4 +        (o "(" é descartado)
//   fim  (vazia)               2 3 4 + *
// Avaliação: 2 | 2 3 | 2 3 4 | 2 7 | 14. Resultado: 14.
