// 0105 · BST: remoção
// Exercício E625 · ★☆☆
//
// Resposta:
// Árvore inicial: 60 (25 (10, 40 (35, 50)), 80 (70, 90)).
// - Sem o 10: folha, só sai. pré 60 25 40 35 50 80 70 90.
// - Sem o 80: dois filhos. O sucessor (menor da direita) é o 90, que vai
//   para o lugar do 80. pré 60 25 40 35 50 90 70.
// - Sem o 25: agora ele tem um filho só (o 40), que sobe com 35 e 50.
//   pré 60 40 35 50 90 70.
//
//   60
//   ├── esq: 40
//   │   ├── esq: 35
//   │   └── dir: 50
//   └── dir: 90
//       └── esq: 70
