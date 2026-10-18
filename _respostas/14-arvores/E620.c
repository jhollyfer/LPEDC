// 0104 · Juntando tudo
// Exercício E620 · ★☆☆
//
// Resposta: a saída é
//
//   altura 2, 6 alunos
//   40 saiu; nova raiz: 50 (Joana)
//   busca 40: não achou
//   altura 2, 5 alunos
//      10  Rita      3 treinos
//      20  Paulo     7 treinos
//      30  Lia       9 treinos
//      50  Joana     5 treinos
//      60  Caio      6 treinos
//
// A árvore começa com 40 na raiz, 20 (10, 30) à esquerda e 60 (50) à direita:
// altura 2. O 40 tem dois filhos; o sucessor é o 50 (o menor da direita), que
// é copiado inteiro (matrícula, nome e treinos) para a raiz. O 50 de baixo era
// folha e sai. A altura continua 2 por causa do 10 e do 30.
