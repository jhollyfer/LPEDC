const linha = (l, itens, estados = {}) => ({
  id: `l${l}`,
  forma: 'array',
  x: 330,
  y: 60 + l * 100,
  itens,
  celula: 110,
  indices: false,
  estados,
})

export const ideia = {
  caixas: [
    linha(0, ['12', '15', '9', '20']),
    linha(1, ['8', '11', '14', '10'], { 2: 'verde' }),
    linha(2, ['17', '13', '16', '19']),
    { id: 'tot', x: 900, y: 60, w: 420, h: 250, cor: 'roxo', rotulo: 'total por linha', texto: ['loja 1: 56', 'loja 2: 43', 'loja 3: 65'] },
    {
      id: 'mem',
      forma: 'array',
      x: 140,
      y: 470,
      itens: ['12', '15', '9', '20', '8', '11', '14', '10', '17', '13', '16', '19'],
      celula: 100,
      estados: { 0: 'apagado', 1: 'apagado', 2: 'apagado', 3: 'apagado', 6: 'verde', 8: 'apagado', 9: 'apagado', 10: 'apagado', 11: 'apagado' },
    },
  ],
  setas: [],
  notas: [
    { x: 190, y: 112, texto: 'linha 0', cor: 'azul' },
    { x: 190, y: 212, texto: 'linha 1', cor: 'azul' },
    { x: 190, y: 312, texto: 'linha 2', cor: 'azul' },
    { x: 385, y: 40, texto: 'col 0', cor: 'azul', ancora: 'middle' },
    { x: 495, y: 40, texto: 'col 1', cor: 'azul', ancora: 'middle' },
    { x: 605, y: 40, texto: 'col 2', cor: 'azul', ancora: 'middle' },
    { x: 715, y: 40, texto: 'col 3', cor: 'azul', ancora: 'middle' },
    { x: 340, y: 620, texto: 'linha 0', cor: 'cinza', ancora: 'middle' },
    { x: 740, y: 620, texto: 'linha 1', cor: 'azul', ancora: 'middle' },
    { x: 1140, y: 620, texto: 'linha 2', cor: 'cinza', ancora: 'middle' },
    { x: 140, y: 430, texto: 'na memória: vendas[1][2] fica na posição 1 × 4 + 2 = 6', cor: 'verde' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'proc', 'l = 0'],
    ['C', 'dec', 'l < 3?'],
    ['D', 'proc', 'total = 0; s = 0'],
    ['E', 'dec', 's < 4?'],
    ['F', 'proc', 'total += vendas[l][s]; s++'],
    ['G', 'io', 'Mostrar total da loja; l++'],
    ['H', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D', 'Sim'],
    ['D', 'E'],
    ['E', 'F', 'Sim'],
    ['F', 'E'],
    ['E', 'G', 'Não'],
    ['G', 'C'],
    ['C', 'H', 'Não'],
  ],
}
