export const ideia = {
  caixas: [
    {
      id: 'l',
      forma: 'lista',
      x: 260,
      y: 120,
      circular: true,
      itens: ['3', '7', '12', '15'],
      estados: { 0: 'verde', 3: 'roxo' },
      rotulos: { 0: 'ultimo->prox (1ª mesa)', 3: 'ultimo' },
    },
    { id: 'g', forma: 'pessoa', x: 1140, y: 110, nome: 'garçom' },
    { id: 'b', forma: 'balao', x: 1280, y: 20, texto: ['3, 7, 12, 15,', '3, 7, ...'], ponta: 'esq' },
  ],
  notas: [{ x: 647, y: 320, texto: 'nenhum prox é NULL: o 15 aponta de volta para o 3', cor: 'cinza', ancora: 'middle' }],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'dec', 'ultimo == NULL?'],
    ['C', 'io', 'Mostrar "(vazia)"'],
    ['D', 'proc', 'p = ultimo->prox'],
    ['E', 'io', 'Mostrar p->valor'],
    ['F', 'proc', 'p = p->prox'],
    ['G', 'dec', 'p != ultimo->prox?'],
    ['H', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C', 'Sim'],
    ['B', 'D', 'Não'],
    ['D', 'E'],
    ['E', 'F'],
    ['F', 'G'],
    ['G', 'E', 'Sim'],
    ['G', 'H', 'Não'],
    ['C', 'H'],
  ],
  caminho: ['A', 'B', 'D', 'E', 'F', 'G', 'E', 'F', 'G', 'H'],
}
