// a tabela t[i][c] do isopor (W = 7): t[3][7] escolhe entre não levar o
// suco (t[2][7] = 42) e levar (30 + t[2][3] = 54). As verdes são a
// recuperação, de baixo para cima: (4,7) -> (3,7) -> (2,3) -> (1,0) -> (0,0)
const X = 520
const Y = 140
const CEL = 104
const PASSO = 112
const tabela = [
  [0, 0, 0, 0, 0, 0, 0, 0],
  [0, 0, 18, 18, 18, 18, 18, 18],
  [0, 0, 18, 24, 24, 42, 42, 42],
  [0, 0, 18, 24, 30, 42, 48, 54],
  [0, 0, 18, 24, 30, 42, 48, 54],
]
const rotulos = ['0: nenhum item', '1: água 2 kg R$ 18', '2: refri 3 kg R$ 24', '3: suco 4 kg R$ 30', '4: açaí 5 kg R$ 35']
const cores = {
  '0,0': 'verde',
  '1,0': 'verde',
  '2,3': 'verde',
  '2,7': 'amarelo',
  '3,7': 'roxo',
  '4,7': 'verde',
}

const caixas = tabela.map((linha, i) => ({
  id: `l${i}`,
  forma: 'array',
  x: X,
  y: Y + i * PASSO,
  celula: CEL,
  itens: linha,
  indices: false,
  estados: Object.fromEntries(linha.map((_, c) => [c, cores[`${i},${c}`]]).filter(([, v]) => v)),
}))

const cx = (c) => X + c * CEL + CEL / 2
const cy = (i) => Y + i * PASSO + 42

const notas = [
  ...rotulos.map((t, i) => ({ x: X - 24, y: cy(i) + 9, texto: t, cor: 'azul', ancora: 'end' })),
  ...tabela[0].map((_, c) => ({ x: cx(c), y: Y - 22, texto: `c=${c}`, cor: 'cinza', ancora: 'middle' })),
  { x: X - 24, y: Y - 22, texto: 'itens  \\  capacidade', cor: 'cinza', ancora: 'end' },
  { x: X, y: Y + 5 * PASSO + 40, texto: 't[3][7] = maior entre 42 (não leva) e 30 + 24 = 54 (leva o suco)', cor: 'roxo' },
  { x: X, y: Y + 5 * PASSO + 80, texto: 'resposta: refri + suco, 7 kg, R$ 54', cor: 'verde' },
]

export const ideia = {
  caixas,
  setas: [
    // de t[2][3] para t[3][7]: leva o suco (+30)
    {
      pontos: [
        [cx(3) + 20, cy(2) + 40],
        [cx(3) + 20, Y + 3 * PASSO - 12],
        [cx(7) - 30, Y + 3 * PASSO - 12],
        [cx(7) - 30, Y + 3 * PASSO - 2],
      ],
      cor: 'verde',
    },
    // de t[2][7] para t[3][7]: não leva
    {
      pontos: [
        [cx(7) + 30, cy(2) + 40],
        [cx(7) + 30, Y + 3 * PASSO - 2],
      ],
      cor: 'cinza',
    },
  ],
  notas,
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Célula t[i][c]'],
    ['B', 'proc', 't[i][c] = t[i-1][c] (não leva)'],
    ['C', 'dec', 'peso[i] <= c?'],
    ['D', 'dec', 'Levar o item i dá mais lucro?'],
    ['E', 'proc', 'Leva: t[i][c] = lucro[i] + t[i-1][c-peso[i]]'],
    ['F', 'inicio', 'Próxima célula'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D', 'Sim'],
    ['C', 'F', 'Não'],
    ['D', 'E', 'Sim'],
    ['D', 'F', 'Não'],
    ['E', 'F'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'F'],
}
