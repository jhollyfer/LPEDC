export const ideia = {
  caixas: [
    {
      id: 'molde',
      x: 100,
      y: 60,
      w: 360,
      h: 240,
      cor: 'cinza',
      rotulo: 'molde: struct pedido',
      texto: ['char tamanho', 'int quantidade', 'double preco'],
    },
    {
      id: 'm',
      forma: 'memoria',
      x: 600,
      y: 70,
      w: 260,
      titulo: 'p1 (16 bytes)',
      celulas: [
        { end: 'byte 0', nome: 'tamanho', valor: "'M'", tipo: 'char' },
        { end: 'bytes 1-3', valor: 'sobra', cor: 'apagado' },
        { end: 'byte 4', nome: 'quantidade', valor: '2', tipo: 'int' },
        { end: 'byte 8', nome: 'preco', valor: '18.50', tipo: 'double' },
      ],
    },
    { id: 'conta', x: 1240, y: 40, w: 340, cor: 'roxo', rotulo: 'o programa faz', texto: ['quantidade * preco', '2 * 18.50'] },
    { id: 'res', x: 1240, y: 340, w: 340, cor: 'verde', rotulo: 'resultado', texto: ['Total: R$ 37.00', 'Frete grátis!'] },
  ],
  setas: [
    { de: 'molde', para: 'm', rotulo: 'declara p1' },
    { pontos: [[1115, 290], [1175, 290], [1175, 135], [1224, 135]] },
    { de: 'conta', para: 'res', rotulo: '>= 30?' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'proc', "p1 = {'M', 2, 18.50}"],
    ['C', 'proc', 'total = quantidade * preco'],
    ['D', 'dec', 'total >= 30?'],
    ['E', 'io', 'Frete grátis!'],
    ['F', 'io', 'Frete: R$ 5.00'],
    ['G', 'io', 'Mostrar total R$ 37.00'],
    ['H', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'G'],
    ['G', 'D'],
    ['D', 'E', 'Sim'],
    ['D', 'F', 'Não'],
    ['E', 'H'],
    ['F', 'H'],
  ],
  caminho: ['A', 'B', 'C', 'G', 'D', 'E', 'H'],
}
