export const ideia = {
  caixas: [
    { id: 'cod', forma: 'caixinha', x: 100, y: 90, nome: 'codigo', valor: '2', tipo: 'int' },
    {
      id: 'card',
      forma: 'cardapio',
      x: 530,
      y: 40,
      w: 460,
      titulo: 'LANCHONETE',
      itens: [
        ['case 1', 'X-Burger 15.00'],
        ['case 2', 'X-Salada 18.00'],
        ['case 3', 'Misto 9.00'],
      ],
      destaque: 1,
    },
    { id: 'r', x: 1120, y: 120, w: 400, cor: 'verde', rotulo: 'break: sai do switch', texto: ['X-Salada', 'Total: R$ 36.00'] },
  ],
  setas: [
    { de: 'cod', para: 'card:1', rotulo: 'pula direto' },
    { de: 'card:1', para: 'r', cor: 'verde' },
  ],
  notas: [{ x: 760, y: 350, texto: 'default: "Código inválido"', cor: 'cinza', ancora: 'middle' }],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'io', 'Ler código e quantidade'],
    ['C', 'dec', 'codigo?'],
    ['D', 'proc', 'X-Burger: preco = 15'],
    ['E', 'proc', 'X-Salada: preco = 18'],
    ['F', 'proc', 'Misto: preco = 9'],
    ['G', 'io', 'Mostrar "Código inválido"'],
    ['H', 'io', 'Mostrar quantidade * preco'],
    ['I', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D', 'case 1'],
    ['C', 'E', 'case 2'],
    ['C', 'F', 'case 3'],
    ['C', 'G', 'default'],
    ['D', 'H'],
    ['E', 'H'],
    ['F', 'H'],
    ['G', 'H'],
    ['H', 'I'],
  ],
  caminho: ['A', 'B', 'C', 'E', 'H', 'I'],
}
