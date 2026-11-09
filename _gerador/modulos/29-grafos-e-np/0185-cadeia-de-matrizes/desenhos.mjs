// a tabela m[i][j] da cadeia A1 (10x30), A2 (30x5), A3 (5x60), A4 (60x10):
// preenchida diagonal por diagonal; o canto m[1][4] vem de m[1][2] + m[3][4]
const m = [
  [0, 1500, 4500, 5000],
  [null, 0, 9000, 4500],
  [null, null, 0, 3000],
  [null, null, null, 0],
]
const X0 = 200
const Y0 = 200
const W = 190
const H = 110
const cor = (i, j) => {
  if (i === 0 && j === 3) return 'verde'
  if ((i === 0 && j === 1) || (i === 2 && j === 3)) return 'amarelo'
  if (i === j) return 'cinza'
  return 'azul'
}
const celulas = []
m.forEach((linha, i) =>
  linha.forEach((v, j) => {
    if (v === null) return
    celulas.push({ id: `m${i + 1}${j + 1}`, x: X0 + j * W, y: Y0 + i * H, w: W - 10, h: H - 10, cor: cor(i, j), texto: [String(v)] })
  }),
)

export const ideia = {
  caixas: [
    ...celulas,
    {
      id: 'dims',
      x: 1020,
      y: 200,
      w: 470,
      h: 270,
      cor: 'azul',
      rotulo: 'as quatro tabelas',
      texto: ['A1: 10 x 30', 'A2: 30 x 5', 'A3: 5 x 60', 'A4: 60 x 10'],
    },
    {
      id: 'res',
      x: 1020,
      y: 520,
      w: 470,
      h: 190,
      cor: 'verde',
      rotulo: 's[1][4] = 2',
      texto: ['((A1 A2) (A3 A4))', '1500 + 3000 + 500'],
    },
  ],
  setas: [
    { cor: 'amarelo', pontos: [[X0 + W + 90, Y0 - 10], [X0 + W + 90, Y0 - 50], [X0 + 3 * W + 90, Y0 - 50], [X0 + 3 * W + 90, Y0 - 10]] },
    { cor: 'amarelo', pontos: [[X0 + 4 * W - 4, Y0 + 2 * H + 50], [X0 + 4 * W + 30, Y0 + 2 * H + 50], [X0 + 4 * W + 30, Y0 + 50], [X0 + 4 * W - 4, Y0 + 50]] },
  ],
  notas: [
    { x: X0 + 0 * W + 85, y: Y0 + 4 * H + 40, texto: 'j = 1', cor: 'cinza', tam: 22, ancora: 'middle' },
    { x: X0 + 1 * W + 85, y: Y0 + 4 * H + 40, texto: 'j = 2', cor: 'cinza', tam: 22, ancora: 'middle' },
    { x: X0 + 2 * W + 85, y: Y0 + 4 * H + 40, texto: 'j = 3', cor: 'cinza', tam: 22, ancora: 'middle' },
    { x: X0 + 3 * W + 85, y: Y0 + 4 * H + 40, texto: 'j = 4', cor: 'cinza', tam: 22, ancora: 'middle' },
    { x: X0 - 30, y: Y0 + 0 * H + 60, texto: 'i = 1', cor: 'cinza', tam: 22, ancora: 'end' },
    { x: X0 - 30, y: Y0 + 1 * H + 60, texto: 'i = 2', cor: 'cinza', tam: 22, ancora: 'end' },
    { x: X0 - 30, y: Y0 + 2 * H + 60, texto: 'i = 3', cor: 'cinza', tam: 22, ancora: 'end' },
    { x: X0 - 30, y: Y0 + 3 * H + 60, texto: 'i = 4', cor: 'cinza', tam: 22, ancora: 'end' },
    { x: X0, y: Y0 + 4 * H + 100, texto: 'cinza: uma matriz só (custo 0)   amarelo: as metades do corte k = 2', cor: 'roxo', tam: 24 },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'dec', 'Próximo tamanho?'],
    ['C', 'dec', 'Próximo i?'],
    ['D', 'proc', 'j = i + tam - 1; m[i][j] = infinito'],
    ['E', 'dec', 'Próximo corte k?'],
    ['F', 'dec', 'custo < m[i][j]?'],
    ['G', 'proc', 'm[i][j] = custo; s[i][j] = k'],
    ['H', 'io', 'm[1][n] e os parênteses'],
    ['I', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C', 'Sim'],
    ['C', 'D', 'Sim'],
    ['D', 'E'],
    ['E', 'F', 'Sim'],
    ['F', 'G', 'Sim'],
    ['F', 'E', 'Não'],
    ['G', 'E'],
    ['E', 'C', 'Não'],
    ['C', 'B', 'Não'],
    ['B', 'H', 'Não'],
    ['H', 'I'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'E', 'F', 'E', 'C', 'B', 'H', 'I'],
}
