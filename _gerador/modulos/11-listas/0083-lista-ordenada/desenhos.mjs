export const ideia = {
  caixas: [
    {
      id: 'l',
      forma: 'lista',
      x: 100,
      y: 40,
      cabeca: 'agenda',
      itens: ['09:00', '14:30', '16:00'],
      estados: { 0: 'amarelo', 1: 'roxo' },
      rotulos: { 0: 'ant', 1: 'p' },
    },
    { id: 'n', x: 230, y: 330, w: 200, h: 150, cor: 'verde', rotulo: 'novo', texto: ['10:15'] },
    { id: 'c', x: 1080, y: 250, w: 400, cor: 'amarelo', rotulo: 'o laço parou porque', texto: ['14:30 < 10:15 é falso'] },
  ],
  setas: [
    { pontos: [[300, 150], [300, 322]], cor: 'verde' },
    { pontos: [[438, 405], [562, 405], [562, 152]], rotulo: '1. novo->prox = p', cor: 'verde' },
  ],
  notas: [{ x: 286, y: 230, texto: ['2. ant->prox', '= novo'], cor: 'verde', ancora: 'end' }],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início: inserir 10:15'],
    ['B', 'proc', 'novo = cria_no; ant = NULL; p = início'],
    ['C', 'dec', 'p != NULL e p->valor < 10:15?'],
    ['D', 'proc', 'ant = p; p = p->prox'],
    ['E', 'proc', 'novo->prox = p'],
    ['F', 'dec', 'ant == NULL?'],
    ['G', 'proc', 'início = novo'],
    ['H', 'proc', 'ant->prox = novo'],
    ['I', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D', 'Sim'],
    ['D', 'C'],
    ['C', 'E', 'Não'],
    ['E', 'F'],
    ['F', 'G', 'Sim'],
    ['F', 'H', 'Não'],
    ['G', 'I'],
    ['H', 'I'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'C', 'E', 'F', 'H', 'I'],
}
