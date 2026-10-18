// a tabela d[i][j] de CARTA (linhas) para ARTES (colunas) e o caminho de
// volta: roxo = canto de partida, amarelo = edição (custa 1), verde =
// letras iguais (de graça). As setas apontam para a célula de onde cada
// passo veio.
const X = 420
const Y = 130
const CEL = 110
const PASSO = 110
const H = 84
const a = ['-', 'C', 'A', 'R', 'T', 'A']
const b = ['-', 'A', 'R', 'T', 'E', 'S']
const tabela = [
  [0, 1, 2, 3, 4, 5],
  [1, 1, 2, 3, 4, 5],
  [2, 1, 2, 3, 4, 5],
  [3, 2, 1, 2, 3, 4],
  [4, 3, 2, 1, 2, 3],
  [5, 4, 3, 2, 2, 3],
]
const cores = {
  '5,5': 'roxo',
  '4,4': 'amarelo',
  '4,3': 'verde',
  '3,2': 'verde',
  '2,1': 'verde',
  '1,0': 'amarelo',
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

const x0 = (j) => X + j * CEL
const y0 = (i) => Y + i * PASSO
// setas curtas entre células vizinhas do caminho
const diag = (i, j) => ({ pontos: [[x0(j) + 14, y0(i) + 12], [x0(j) - 12, y0(i) - 12]], cor: 'roxo' })
const esq = (i, j) => ({ pontos: [[x0(j) + 16, y0(i) + 20], [x0(j) - 16, y0(i) + 20]], cor: 'roxo' })
const cima = (i, j) => ({ pontos: [[x0(j) + 20, y0(i) + 14], [x0(j) + 20, y0(i) - PASSO + H + 2]], cor: 'roxo' })

export const ideia = {
  caixas,
  setas: [diag(5, 5), esq(4, 4), diag(4, 3), diag(3, 2), diag(2, 1), cima(1, 0)],
  notas: [
    ...a.map((l, i) => ({ x: X - 30, y: y0(i) + 52, texto: l, cor: 'azul', ancora: 'end', tam: 30 })),
    ...b.map((l, j) => ({ x: x0(j) + CEL / 2, y: Y - 24, texto: l, cor: 'azul', ancora: 'middle', tam: 30 })),
    { x: X - 30, y: Y - 24, texto: 'a \\ b', cor: 'cinza', ancora: 'end' },
    { x: X + 6 * CEL + 50, y: y0(1) + 52, texto: 'de baixo para cima:', cor: 'roxo' },
    { x: X + 6 * CEL + 50, y: y0(2) + 30, texto: '(5,5) troca A por S', cor: 'roxo' },
    { x: X + 6 * CEL + 50, y: y0(2) + 70, texto: '(4,4) insere E', cor: 'roxo' },
    { x: X + 6 * CEL + 50, y: y0(3) + 30, texto: 'T, R, A: iguais', cor: 'verde' },
    { x: X + 6 * CEL + 50, y: y0(3) + 70, texto: '(1,0) remove C', cor: 'roxo' },
    { x: X + 6 * CEL + 50, y: y0(4) + 52, texto: 'CARTA, ARTA,', cor: 'cinza' },
    { x: X + 6 * CEL + 50, y: y0(4) + 92, texto: 'ARTEA, ARTES', cor: 'cinza' },
    { x: X, y: y0(6) + 40, texto: 'a borda conta edições: d[i][0] = i (remove), d[0][j] = j (insere)', cor: 'azul' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Célula d[i][j] (i, j >= 1)'],
    ['B', 'dec', 'a[i-1] == b[j-1]?'],
    ['C', 'proc', 'd[i][j] = d[i-1][j-1] (de graça)'],
    ['D', 'proc', 'Olha diagonal (troca), cima (remove) e esquerda (insere)'],
    ['E', 'proc', 'd[i][j] = 1 + o menor dos três'],
    ['F', 'inicio', 'Próxima célula'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C', 'Sim'],
    ['B', 'D', 'Não'],
    ['D', 'E'],
    ['C', 'F'],
    ['E', 'F'],
  ],
  caminho: ['A', 'B', 'D', 'E', 'F'],
}
