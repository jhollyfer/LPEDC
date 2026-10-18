// 0106 · AVL: balanceamento e rotações
// Exercício E631 · ★☆☆
//
// Resposta:
// alturas: 10: 0, 20: 1, 40: 0, 30: 2, 90: 0, 80: 1, 70: 2, 50: 3.
// fatores: 50: 2 - 2 = 0; 30: 1 - 0 = +1; 20: 0 - (-1) = +1; 10: 0; 40: 0;
//          70: -1 - 1 = -2; 80: -1 - 0 = -1; 90: 0.
// (a) Não é AVL: o 70 tem fator -2.
// (b) O 70 está pesado à direita e o filho direito (80) também (fator -1):
//     caso direita-direita.
// (c) Rotação à esquerda no 70: o 80 sobe, o 70 vira filho esquerdo dele e o
//     90 continua à direita. A árvore fica:
//
//   50
//   ├── esq: 30
//   │   ├── esq: 20
//   │   │   └── esq: 10
//   │   └── dir: 40
//   └── dir: 80
//       ├── esq: 70
//       └── dir: 90
