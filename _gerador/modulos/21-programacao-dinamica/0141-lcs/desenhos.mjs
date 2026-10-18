// a tabela c[i][j] de MORANGO (linhas) x MANGA (colunas) e o caminho de
// volta a partir de c[7][5]: verde = letra da LCS (diagonal), amarelo =
// passo sem letra, roxo = o canto de onde a volta parte
const X = 400
const Y = 130
const CEL = 96
const PASSO = 100
const a = ['-', 'M', 'O', 'R', 'A', 'N', 'G', 'O']
const b = ['-', 'M', 'A', 'N', 'G', 'A']
const tabela = [
  [0, 0, 0, 0, 0, 0],
  [0, 1, 1, 1, 1, 1],
  [0, 1, 1, 1, 1, 1],
  [0, 1, 1, 1, 1, 1],
  [0, 1, 2, 2, 2, 2],
  [0, 1, 2, 3, 3, 3],
  [0, 1, 2, 3, 4, 4],
  [0, 1, 2, 3, 4, 4],
]
const cores = {
  '7,5': 'roxo',
  '6,5': 'amarelo',
  '6,4': 'verde',
  '5,3': 'verde',
  '4,2': 'verde',
  '3,1': 'amarelo',
  '2,1': 'amarelo',
  '1,1': 'verde',
  '0,0': 'apagado',
}

const caixas = tabela.map((linha, i) => ({
  id: `l${i}`,
  forma: 'array',
  x: X,
  y: Y + i * PASSO,
  celula: CEL,
  itens: linha,
  indices: false,
  estados: Object.fromEntries(linha.map((_, j) => [j, cores[`${i},${j}`]]).filter(([, v]) => v)),
}))

const cx = (j) => X + j * CEL + CEL / 2
const cy = (i) => Y + i * PASSO + 42

export const ideia = {
  caixas,
  setas: [],
  notas: [
    ...a.map((l, i) => ({ x: X - 30, y: cy(i) + 10, texto: l, cor: 'azul', ancora: 'end', tam: 30 })),
    ...b.map((l, j) => ({ x: cx(j), y: Y - 24, texto: l, cor: 'azul', ancora: 'middle', tam: 30 })),
    { x: X - 30, y: Y - 24, texto: 'a \\ b', cor: 'cinza', ancora: 'end' },
    { x: X + 6 * CEL + 60, y: cy(1) + 10, texto: 'verde: letras iguais,', cor: 'verde' },
    { x: X + 6 * CEL + 60, y: cy(1) + 48, texto: 'vem da diagonal + 1', cor: 'verde' },
    { x: X + 6 * CEL + 60, y: cy(3) + 10, texto: 'amarelo: letras diferentes,', cor: 'cinza' },
    { x: X + 6 * CEL + 60, y: cy(3) + 48, texto: 'sobe ou vai para a esquerda', cor: 'cinza' },
    { x: X + 6 * CEL + 60, y: cy(5) + 10, texto: 'a volta lê a resposta', cor: 'roxo' },
    { x: X + 6 * CEL + 60, y: cy(5) + 48, texto: 'de trás para a frente:', cor: 'roxo' },
    { x: X + 6 * CEL + 60, y: cy(5) + 86, texto: 'G, N, A, M = MANG', cor: 'roxo' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Célula c[i][j]'],
    ['B', 'dec', 'i == 0 ou j == 0?'],
    ['C', 'proc', 'c[i][j] = 0'],
    ['D', 'dec', 'a[i-1] == b[j-1]?'],
    ['E', 'proc', 'c[i][j] = c[i-1][j-1] + 1 (diagonal)'],
    ['F', 'proc', 'c[i][j] = maior entre cima e esquerda'],
    ['G', 'inicio', 'Próxima célula'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C', 'Sim'],
    ['B', 'D', 'Não'],
    ['D', 'E', 'Sim'],
    ['D', 'F', 'Não'],
    ['C', 'G'],
    ['E', 'G'],
    ['F', 'G'],
  ],
  caminho: ['A', 'B', 'D', 'E', 'G'],
}
