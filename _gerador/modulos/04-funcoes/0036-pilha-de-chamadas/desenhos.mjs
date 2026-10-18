export const ideia = {
  caixas: [
    {
      id: 'p1',
      forma: 'pilha',
      x: 120,
      y: 60,
      w: 420,
      titulo: 'durante taxa_entrega',
      estados: { 0: 'azul', 1: 'roxo', 2: 'verde' },
      itens: [
        ['main', 'subtotal = 50.00'],
        ['total_com_entrega', 'valor = 50.00'],
        ['taxa_entrega', 'valor = 50.00', 'taxa = 7.90'],
      ],
    },
    {
      id: 'p2',
      forma: 'pilha',
      x: 960,
      y: 194,
      w: 420,
      titulo: 'depois do return 7.90',
      estados: { 0: 'azul', 1: 'verde' },
      itens: [
        ['main', 'subtotal = 50.00'],
        ['total_com_entrega', 'valor = 50.00', 'total = 57.90'],
      ],
    },
  ],
  setas: [{ pontos: [[790, 330], [920, 330]], rotulo: 'desempilha', cor: 'verde' }],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início: main na pilha'],
    ['B', 'proc', 'Empilha total_com_entrega(50.00)'],
    ['C', 'proc', 'Empilha taxa_entrega(50.00)'],
    ['D', 'dec', 'valor < 80?'],
    ['E', 'proc', 'taxa = 7.90'],
    ['F', 'proc', 'taxa = 0.00'],
    ['G', 'proc', 'Desempilha taxa_entrega, devolve a taxa'],
    ['H', 'proc', 'Desempilha total_com_entrega, devolve 57.90'],
    ['I', 'io', 'Mostrar "Total: R$ 57.90"'],
    ['J', 'inicio', 'Fim: pilha vazia'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D'],
    ['D', 'E', 'Sim'],
    ['D', 'F', 'Não'],
    ['E', 'G'],
    ['F', 'G'],
    ['G', 'H'],
    ['H', 'I'],
    ['I', 'J'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'G', 'H', 'I', 'J'],
}
