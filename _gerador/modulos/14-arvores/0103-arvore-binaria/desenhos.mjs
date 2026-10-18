// a árvore de (8 - 3) * (4 + 2): operadores em roxo, números em azul, e os
// quatro percursos ao lado
export const ideia = {
  caixas: [
    {
      id: 'arv',
      forma: 'arvore',
      x: 140,
      y: 90,
      dx: 115,
      dy: 140,
      raiz: {
        v: '*',
        e: { v: '-', e: { v: '8' }, d: { v: '3' } },
        d: { v: '+', e: { v: '4' }, d: { v: '2' } },
      },
      estados: { '*': 'roxo', '-': 'roxo', '+': 'roxo' },
    },
    {
      id: 'p',
      x: 960,
      y: 60,
      w: 500,
      h: 280,
      cor: 'roxo',
      rotulo: 'percursos',
      texto: ['pré:  * - 8 3 + 4 2', 'em:  8 - 3 * 4 + 2', 'pós:  8 3 - 4 2 + *', 'nível:  * - + 8 3 4 2'],
    },
    { id: 'v', x: 960, y: 420, w: 500, h: 110, cor: 'verde', texto: ['valor: 5 * 6 = 30'] },
  ],
  setas: [
    { de: 'p', para: 'v', rotulo: 'pós-ordem calcula' },
  ],
  notas: [
    { x: 520, y: 70, texto: 'raiz', cor: 'roxo', ancora: 'middle' },
    { x: 140, y: 560, texto: 'folhas = operandos; nós internos = operadores', cor: 'cinza' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'em_ordem(r)'],
    ['B', 'dec', 'r == NULL?'],
    ['C', 'proc', 'em_ordem(r->esq)'],
    ['D', 'io', 'Mostrar r->info'],
    ['E', 'proc', 'em_ordem(r->dir)'],
    ['F', 'inicio', 'Volta para quem chamou'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'F', 'Sim'],
    ['B', 'C', 'Não'],
    ['C', 'D'],
    ['D', 'E'],
    ['E', 'F'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'F'],
}
