// radix sort dos números de pedido: uma linha por passada (unidades,
// dezenas, centenas). O 807 e o 830 (amarelos) mostram a estabilidade
const X = 330
const linhas = [
  ['início', ['251', '047', '830', '509', '074', '216', '553', '807'], { 2: 'amarelo', 7: 'amarelo' }, ['8 números, até', '3 dígitos']],
  ['unidades', ['830', '251', '553', '074', '216', '047', '807', '509'], { 0: 'amarelo', 6: 'amarelo' }, ['ordem pelo último', 'dígito: 0 1 3 4 6 7 7 9']],
  ['dezenas', ['807', '509', '216', '830', '047', '251', '553', '074'], { 0: 'amarelo', 3: 'amarelo' }, ['dígito do meio:', '807 (0) antes de 830 (3)']],
  ['centenas', ['047', '074', '216', '251', '509', '553', '807', '830'], { 0: 'verde', 1: 'verde', 2: 'verde', 3: 'verde', 4: 'verde', 5: 'verde', 6: 'amarelo', 7: 'amarelo' }, ['empate no 8: fica a', 'ordem que já estava']],
]

export const ideia = {
  caixas: linhas.map(([, itens, estados], i) => ({
    id: `v${i}`,
    forma: 'array',
    x: X,
    y: 60 + i * 160,
    celula: 96,
    itens,
    estados,
    indices: false,
  })),
  setas: [],
  notas: [
    ...linhas.map(([rotulo], i) => ({ x: 110, y: 112 + i * 160, texto: rotulo, cor: i === 0 ? 'azul' : i === 3 ? 'verde' : 'roxo' })),
    ...linhas.map(([, , , nota], i) => ({ x: 1120, y: 94 + i * 160, texto: nota, cor: i === 3 ? 'verde' : 'roxo' })),
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'io', 'Recebe v (8 pedidos)'],
    ['C', 'proc', 'acha o maior (830); exp = 1'],
    ['D', 'dec', 'maior / exp > 0?'],
    ['E', 'proc', 'counting sort estável pelo dígito (v[i] / exp) % 10'],
    ['F', 'proc', 'exp = exp * 10'],
    ['G', 'io', 'Mostra v ordenado'],
    ['H', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D'],
    ['D', 'E', 'Sim'],
    ['E', 'F'],
    ['F', 'D'],
    ['D', 'G', 'Não'],
    ['G', 'H'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'F', 'D', 'E', 'F', 'D', 'E', 'F', 'D', 'G', 'H'],
}
