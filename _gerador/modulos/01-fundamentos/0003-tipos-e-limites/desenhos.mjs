const uns = Array(16).fill('1')
const zeros = Array(16).fill('0')
const vermelhos = Object.fromEntries(zeros.map((_, i) => [i, 'vermelho']))

export const ideia = {
  caixas: [
    { id: 'c', forma: 'caixinha', x: 100, y: 20, w: 360, nome: 'catraca', valor: '65535', tipo: 'unsigned short · 2 bytes' },
    { id: 'op', x: 620, y: 40, w: 360, cor: 'roxo', rotulo: 'mais um torcedor', texto: ['catraca + 1'] },
    { id: 'b1', forma: 'array', x: 100, y: 330, itens: uns, indices: false, celula: 62 },
    { id: 'b2', forma: 'array', x: 100, y: 600, itens: zeros, indices: false, celula: 62, estados: vermelhos },
  ],
  setas: [
    { de: 'c', para: 'b1', lados: 'bc', rotulo: 'em bits' },
    { de: 'b1', para: 'b2', rotulo: '+ 1' },
    { de: 'op', para: 'b1', lados: 'bc' },
  ],
  notas: [
    { x: 1120, y: 385, texto: '= 0xFFFF = 65535', cor: 'azul' },
    { x: 1120, y: 655, texto: '= 0x0000 = 0', cor: 'vermelho' },
    { x: 640, y: 540, texto: 'o 17º bit (o "vai um") não cabe e some', cor: 'vermelho' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'proc', 'catraca = 65535'],
    ['C', 'proc', 'catraca = catraca + 1'],
    ['D', 'dec', 'Cabe em 16 bits?'],
    ['E', 'proc', 'Guarda o valor'],
    ['F', 'proc', 'Guarda só os 16 bits de baixo: 0'],
    ['G', 'io', 'Mostrar a catraca'],
    ['H', 'inicio', 'Fim'],
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
  ],
  caminho: ['A', 'B', 'C', 'D', 'F', 'G', 'H'],
}
