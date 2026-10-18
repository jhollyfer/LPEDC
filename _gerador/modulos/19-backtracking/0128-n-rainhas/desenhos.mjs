// três tabuleiros 4 × 4: a primeira solução, o número l + c (diagonal ↗) e o
// número l - c + 3 (diagonal ↘) de cada casa. A rainha da casa (1, 3) ocupa a
// diagonal ↗ 4 e a diagonal ↘ 1: essas casas ficam proibidas
const N = 4
const CEL = 80
const pos = [1, 3, 0, 2]
const Y0 = 90

const grade = (prefixo, x, valor, estado) => {
  const caixas = []
  for (let l = 0; l < N; l++) {
    const itens = []
    const estados = {}
    for (let c = 0; c < N; c++) {
      itens.push(valor(l, c))
      const e = estado(l, c)
      if (e) estados[c] = e
    }
    caixas.push({ id: `${prefixo}${l}`, forma: 'array', x, y: Y0 + l * 84, celula: CEL, itens, estados, indices: false })
  }
  return caixas
}

const caixas = [
  ...grade('t', 140, (l, c) => (pos[l] === c ? 'R' : ''), (l, c) => (pos[l] === c ? (l === 1 ? 'roxo' : 'verde') : null)),
  ...grade('a', 620, (l, c) => String(l + c), (l, c) => (l === 1 && c === 3 ? 'roxo' : l + c === 4 ? 'vermelho' : null)),
  ...grade('b', 1100, (l, c) => String(l - c + N - 1), (l, c) =>
    l === 1 && c === 3 ? 'roxo' : l - c + N - 1 === 1 ? 'vermelho' : null,
  ),
]

// números das linhas e colunas do tabuleiro da esquerda
const notas = []
for (let k = 0; k < N; k++) {
  notas.push({ x: 110, y: Y0 + k * 84 + 52, texto: String(k), cor: 'cinza', ancora: 'middle' })
  notas.push({ x: 140 + k * CEL + CEL / 2, y: Y0 - 16, texto: String(k), cor: 'cinza', ancora: 'middle' })
}
notas.push({ x: 140 + 2 * CEL, y: Y0 + 4 * 84 + 50, texto: 'solução 1: pos = {1, 3, 0, 2}', cor: 'verde', ancora: 'middle' })
notas.push({ x: 620 + 2 * CEL, y: Y0 + 4 * 84 + 50, texto: 'l + c: diagonal ↗', cor: 'roxo', ancora: 'middle' })
notas.push({ x: 620 + 2 * CEL, y: Y0 + 4 * 84 + 88, texto: 'a rainha (1, 3) ocupa a 4', cor: 'vermelho', ancora: 'middle' })
notas.push({ x: 1100 + 2 * CEL, y: Y0 + 4 * 84 + 50, texto: 'l - c + 3: diagonal ↘', cor: 'roxo', ancora: 'middle' })
notas.push({ x: 1100 + 2 * CEL, y: Y0 + 4 * 84 + 88, texto: 'a rainha (1, 3) ocupa a 1', cor: 'vermelho', ancora: 'middle' })

export const ideia = { caixas, setas: [], notas }

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início: rainha(l)'],
    ['B', 'dec', 'l == N?'],
    ['C', 'io', 'Conta e mostra a solução'],
    ['D', 'dec', 'Ainda há coluna c?'],
    ['E', 'dec', 'Casa (l, c) atacada?'],
    ['F', 'proc', 'pos[l] = c; marca coluna e diagonais'],
    ['G', 'proc', 'rainha(l + 1)'],
    ['H', 'proc', 'Desmarca; próxima coluna'],
    ['I', 'inicio', 'Volta'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C', 'Sim'],
    ['C', 'I'],
    ['B', 'D', 'Não'],
    ['D', 'I', 'Não'],
    ['D', 'E', 'Sim'],
    ['E', 'D', 'Sim'],
    ['E', 'F', 'Não'],
    ['F', 'G'],
    ['G', 'H'],
    ['H', 'D'],
  ],
  caminho: ['A', 'B', 'D', 'E', 'D', 'E', 'F', 'G', 'H', 'D', 'I', 'A', 'B', 'C', 'I'],
}
