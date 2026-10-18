export const ideia = {
  caixas: [
    { id: 'l', forma: 'lista', x: 100, y: 30, cabeca: 'extrato', itens: ['80', '10', '45', '20'], estados: { 0: 'verde' }, rotulos: { 0: 'último a chegar' } },
    {
      id: 'm',
      forma: 'memoria',
      x: 560,
      y: 290,
      titulo: 'no heap, os nós ficam espalhados',
      celulas: [
        { end: '0x490', valor: '10 | 0x520', nome: 'nó do 10' },
        { end: '0x4c0', valor: '20 | NULL', nome: 'nó do 20' },
        { end: '0x4f0', valor: 'outro dado', cor: 'apagado' },
        { end: '0x520', valor: '45 | 0x4c0', nome: 'nó do 45' },
        { end: '0x550', valor: '80 | 0x490', nome: 'nó do 80', cor: 'verde' },
      ],
      ponteiros: [[4, 0], [0, 3], [3, 1]],
    },
    { id: 'v', forma: 'caixinha', x: 110, y: 380, nome: 'extrato', valor: '0x550', tipo: 'No *' },
  ],
  setas: [{ pontos: [[180, 592], [180, 700], [690, 700], [690, 658]] }],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'proc', 'p = extrato; total = 0'],
    ['C', 'dec', 'p != NULL?'],
    ['D', 'proc', 'total += p->valor'],
    ['E', 'proc', 'p = p->prox'],
    ['F', 'io', 'Mostrar total: R$ 155'],
    ['G', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D', 'Sim'],
    ['D', 'E'],
    ['E', 'C'],
    ['C', 'F', 'Não'],
    ['F', 'G'],
  ],
}
