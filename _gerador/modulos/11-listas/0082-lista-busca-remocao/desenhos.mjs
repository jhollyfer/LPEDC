export const ideia = {
  caixas: [
    {
      id: 'l',
      forma: 'lista',
      x: 100,
      y: 60,
      cabeca: 'fila',
      itens: ['31', '17', '42', '8'],
      estados: { 1: 'amarelo', 2: 'vermelho' },
      rotulos: { 1: 'ant', 2: 'p' },
    },
    { id: 'b', x: 1150, y: 40, w: 330, cor: 'roxo', rotulo: 'remover o 42', texto: ['1. acha p e ant', '2. religa', '3. free(p)'] },
  ],
  setas: [{ pontos: [[539, 162], [539, 240], [931, 240], [931, 170]], rotulo: 'ant->prox = p->prox', cor: 'verde' }],
  notas: [{ x: 715, y: 300, texto: 'free(p)', cor: 'vermelho', ancora: 'middle' }],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início: remover 42'],
    ['B', 'proc', 'ant = NULL; p = início'],
    ['C', 'dec', 'p != NULL e p->valor != 42?'],
    ['D', 'proc', 'ant = p; p = p->prox'],
    ['E', 'dec', 'achou (p != NULL)?'],
    ['F', 'dec', 'ant == NULL?'],
    ['G', 'proc', 'início = p->prox'],
    ['H', 'proc', 'ant->prox = p->prox'],
    ['I', 'proc', 'free(p)'],
    ['J', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D', 'Sim'],
    ['D', 'C'],
    ['C', 'E', 'Não'],
    ['E', 'F', 'Sim'],
    ['E', 'J', 'Não'],
    ['F', 'G', 'Sim'],
    ['F', 'H', 'Não'],
    ['G', 'I'],
    ['H', 'I'],
    ['I', 'J'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'C', 'E', 'F', 'H', 'I', 'J'],
}
