// busca do 60 na BST das matrículas: 50 e 70 comparados (amarelo), 60 achado
// (verde), arestas do caminho marcadas
export const ideia = {
  caixas: [
    {
      id: 'arv',
      forma: 'arvore',
      x: 140,
      y: 110,
      dx: 120,
      dy: 150,
      raiz: {
        v: 50,
        e: { v: 30, e: { v: 20 }, d: { v: 40, nota: '45 cairia aqui' } },
        d: { v: 70, e: { v: 60 }, d: { v: 80 } },
      },
      estados: { 50: 'amarelo', 70: 'amarelo', 60: 'verde' },
      marcadas: [
        [50, 70],
        [70, 60],
      ],
    },
    { id: 'q', x: 1010, y: 60, w: 450, h: 110, cor: 'azul', texto: ['procurando: 60'] },
    {
      id: 'c',
      x: 1010,
      y: 250,
      w: 450,
      h: 230,
      cor: 'amarelo',
      rotulo: 'uma comparação por nível',
      texto: ['60 > 50: direita', '60 < 70: esquerda', '60 = 60: achou!'],
    },
  ],
  setas: [{ de: 'q', para: 'c' }],
  notas: [
    { x: 140, y: 620, texto: 'menores à esquerda, maiores à direita, em todo nó', cor: 'cinza' },
    { x: 1010, y: 540, texto: ['3 comparações para 7 chaves;', 'com 1 milhão, umas 20'], cor: 'verde' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'io', 'Ler a chave (60)'],
    ['C', 'proc', 'r = raiz'],
    ['D', 'dec', 'r == NULL?'],
    ['N', 'io', 'Mostrar "não existe"'],
    ['F', 'dec', 'chave == r->chave?'],
    ['S', 'io', 'Mostrar "achou"'],
    ['G', 'dec', 'chave < r->chave?'],
    ['H', 'proc', 'r = r->esq'],
    ['I', 'proc', 'r = r->dir'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D'],
    ['D', 'N', 'Sim'],
    ['D', 'F', 'Não'],
    ['F', 'S', 'Sim'],
    ['F', 'G', 'Não'],
    ['G', 'H', 'Sim'],
    ['G', 'I', 'Não'],
    ['H', 'D'],
    ['I', 'D'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'F', 'G', 'I', 'D', 'F', 'G', 'H', 'D', 'F', 'S'],
}
