// A BST dos horários com pai. Embaixo de cada nó: profundidade (p) e
// altura (h). O caminho verde é o sucessor das 7h30 (caso 2: sobe até
// chegar por um filho esquerdo); o roxo é o sucessor das 8h00 (caso 1).
export const ideia = {
  caixas: [
    {
      id: 'a',
      forma: 'arvore',
      x: 120,
      y: 120,
      dx: 124,
      dy: 150,
      raio: 46,
      raiz: {
        v: '8h00',
        nota: 'p0 · h3',
        e: {
          v: '6h15',
          nota: 'p1 · h2',
          d: { v: '7h00', nota: 'p2 · h1', e: { v: '6h50', nota: 'p3 · h0' }, d: { v: '7h30', nota: 'p3 · h0' } },
        },
        d: { v: '10h30', nota: 'p1 · h1', e: { v: '9h20', nota: 'p2 · h0' }, d: { v: '12h00', nota: 'p2 · h0' } },
      },
      estados: { '7h30': 'azul', '7h00': 'amarelo', '6h15': 'amarelo', '8h00': 'verde', '9h20': 'roxo', '10h30': 'cinza', '12h00': 'cinza', '6h50': 'cinza' },
      marcadas: [['6h15', '7h00'], ['7h00', '7h30'], ['8h00', '6h15']],
    },
  ],
  setas: [],
  notas: [
    { x: 1190, y: 150, texto: ['sucessor das 7h30:', 'caso 2, sem filho', 'direito'], cor: 'verde', tam: 24 },
    { x: 1190, y: 290, texto: ['sobe para 7h00: veio', 'da direita, continua;', 'sobe para 6h15: idem;', 'sobe para 8h00: veio', 'da esquerda, é ele!'], cor: 'roxo', tam: 22 },
    { x: 1190, y: 540, texto: ['sucessor das 8h00', '(caso 1): o mínimo da', 'direita, 9h20'], cor: 'roxo', tam: 22 },
    { x: 120, y: 760, texto: 'p = profundidade (o nível)   h = altura   grau do 8h00: 2   grau do 6h15: 1', cor: 'cinza', tam: 24 },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'ap_sucessor(7h30)'],
    ['B', 'dec', 'x->dir != NULL?'],
    ['C', 'io', 'Devolver ap_minimo(x->dir)'],
    ['D', 'proc', 'y = x->pai'],
    ['E', 'dec', 'y != NULL e x == y->dir?'],
    ['F', 'proc', 'x = y; y = y->pai'],
    ['G', 'io', 'Devolver y (8h00)'],
    ['H', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C', 'Sim'],
    ['B', 'D', 'Não'],
    ['D', 'E'],
    ['E', 'F', 'Sim'],
    ['F', 'E'],
    ['E', 'G', 'Não'],
    ['C', 'H'],
    ['G', 'H'],
  ],
  caminho: ['A', 'B', 'D', 'E', 'F', 'E', 'F', 'E', 'G', 'H'],
}
