// 0104 · BST: busca e inserção
// Exercício E619 · ★☆☆
//
// Resposta:
//
//   45
//   ├── esq: 20
//   │   ├── esq: 10
//   │   └── dir: 30
//   │       └── esq: 25
//   └── dir: 70
//       ├── esq: 60
//       └── dir: 90
//
// (a) altura 3 (45 → 20 → 30 → 25).
// (b) a busca pelo 25 passa por 45, 20, 30 e acha o 25 (4 comparações).
// (c) a busca pelo 65 passa por 45, 70, 60 e cai no NULL à direita do 60.
// O programa confirma: em ordem 10 20 25 30 45 60 70 90 e altura 3.
