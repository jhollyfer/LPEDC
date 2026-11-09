// Apertos de mão com 8 moradores: linha i = quem chega, coluna j = quem já
// estava. Roxo: aperto contado (j < i). Amarelo: ele mesmo (j = i).
// Cinza: quem ainda não chegou. 0 + 1 + ... + 7 = 28 = 8 · 7 / 2.
const N = 8
const L = 66
const P = 74
const X0 = 330
const Y0 = 110
const caixas = []
const notas = []
for (let i = 0; i < N; i++) {
  for (let j = 0; j < N; j++) {
    const cor = j < i ? 'roxo' : j === i ? 'amarelo' : 'cinza'
    caixas.push({ id: `c${i}_${j}`, x: X0 + j * P, y: Y0 + i * P, w: L, h: L, cor, texto: [] })
  }
  notas.push({ x: 170, y: Y0 + i * P + 44, texto: `i = ${i}`, cor: 'azul' })
  const acum = (i * (i + 1)) / 2
  notas.push({ x: X0 + N * P + 30, y: Y0 + i * P + 44, texto: `+${i}  →  total ${acum}`, cor: i === N - 1 ? 'verde' : 'roxo' })
}
for (let j = 0; j < N; j++) notas.push({ x: X0 + j * P + 24, y: Y0 + N * P + 30, texto: String(j), cor: 'cinza' })
notas.push({ x: X0 - 10, y: Y0 + N * P + 85, texto: 'coluna j = quem já está na sala (0 a 7)', cor: 'cinza' })
notas.push({ x: 1220, y: 300, texto: 'roxo: aperto (j < i)', cor: 'roxo' })
notas.push({ x: 1220, y: 350, texto: 'amarelo: ele mesmo', cor: 'amarelo' })
notas.push({ x: 1220, y: 400, texto: 'cinza: ainda não chegou', cor: 'cinza' })
notas.push({ x: 1220, y: 500, texto: '(64 - 8) / 2 = 28', cor: 'verde' })
notas.push({ x: 1220, y: 550, texto: 'n(n-1)/2 = Θ(n²)', cor: 'verde' })

export const ideia = { caixas, setas: [], notas }

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início: apertos_de_mao(8)'],
    ['B', 'proc', 'apertos = 0; i = 0'],
    ['C', 'dec', 'i < n?'],
    ['D', 'proc', 'j = 0'],
    ['E', 'dec', 'j < i?'],
    ['F', 'proc', 'apertos++; j++'],
    ['G', 'proc', 'i++'],
    ['H', 'io', 'devolve apertos (28)'],
    ['I', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D', 'Sim'],
    ['C', 'H', 'Não'],
    ['D', 'E'],
    ['E', 'F', 'Sim'],
    ['F', 'E'],
    ['E', 'G', 'Não'],
    ['G', 'C'],
    ['H', 'I'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'G', 'C', 'D', 'E', 'F', 'E', 'G', 'C', 'H', 'I'],
}
