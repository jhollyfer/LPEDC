export const ideia = {
  caixas: [
    {
      id: 'l',
      forma: 'lista',
      x: 100,
      y: 80,
      cabeca: 'inicio',
      dupla: true,
      itens: ['98', '105', '87', '110'],
      estados: { 2: 'vermelho' },
      rotulos: { 2: 'p' },
    },
  ],
  setas: [
    { pontos: [[648, 128], [648, 40], [1040, 40], [1040, 94]], rotulo: 'p->ant->prox = p->prox', cor: 'verde' },
    { pontos: [[1051, 160], [1051, 240], [656, 240], [656, 184]], rotulo: 'p->prox->ant = p->ant', cor: 'verde' },
    { pontos: [[1160, 330], [1160, 190]], cor: 'roxo' },
  ],
  notas: [
    { x: 1160, y: 370, texto: 'fim', cor: 'roxo', ancora: 'middle' },
    { x: 849, y: 300, texto: 'free(p): sem procurar ninguém', cor: 'vermelho', ancora: 'middle' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início: remover p (87)'],
    ['B', 'dec', 'p->ant == NULL?'],
    ['C', 'proc', 'inicio = p->prox'],
    ['D', 'proc', 'p->ant->prox = p->prox'],
    ['E', 'dec', 'p->prox == NULL?'],
    ['F', 'proc', 'fim = p->ant'],
    ['G', 'proc', 'p->prox->ant = p->ant'],
    ['H', 'proc', 'free(p); tamanho--'],
    ['I', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C', 'Sim'],
    ['B', 'D', 'Não'],
    ['C', 'E'],
    ['D', 'E'],
    ['E', 'F', 'Sim'],
    ['E', 'G', 'Não'],
    ['F', 'H'],
    ['G', 'H'],
    ['H', 'I'],
  ],
  caminho: ['A', 'B', 'D', 'E', 'G', 'H', 'I'],
}
