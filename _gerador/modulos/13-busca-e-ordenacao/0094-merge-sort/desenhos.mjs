// o merge sort em 6 linhas: 3 descendo (dividir) e 3 subindo (intercalar).
// Cada linha é um ou mais pedaços do vetor, com um vão entre os pedaços.
const CEL = 90
const VAO = 50
const CENTRO = 700
const linhas = [
  // [rótulo, pedaços, cor, nota]
  ['vetor', [['52', '18', '33', '7', '41', '26', '60', '12']], 'azul', ''],
  ['divide', [['52', '18', '33', '7'], ['41', '26', '60', '12']], 'azul', ''],
  ['divide', [['52', '18'], ['33', '7'], ['41', '26'], ['60', '12']], 'azul', ['cada metade de um par', 'já está ordenada']],
  ['intercala', [['18', '52'], ['7', '33'], ['26', '41'], ['12', '60']], 'verde', '4 × 1 = 4 comparações'],
  ['intercala', [['7', '18', '33', '52'], ['12', '26', '41', '60']], 'verde', '3 + 3 = 6 comparações'],
  ['intercala', [['7', '12', '18', '26', '33', '41', '52', '60']], 'verde', '7 comparações'],
]

const caixas = []
const notas = []
linhas.forEach(([rotulo, pedacos, cor, nota], l) => {
  const y = 40 + l * 130
  const largura = 8 * CEL + (pedacos.length - 1) * VAO
  let x = CENTRO - largura / 2
  pedacos.forEach((itens, k) => {
    const estados = cor === 'verde' ? Object.fromEntries(itens.map((_, i) => [i, 'verde'])) : {}
    caixas.push({ id: `l${l}p${k}`, forma: 'array', x, y, celula: CEL, itens, estados, indices: false })
    x += itens.length * CEL + VAO
  })
  notas.push({ x: 100, y: y + 52, texto: rotulo, cor: cor === 'verde' ? 'verde' : 'azul' })
  if (nota) notas.push({ x: 1180, y: y + (Array.isArray(nota) ? 38 : 52), texto: nota, cor: cor === 'verde' ? 'verde' : 'cinza' })
})
notas.push({ x: 1180, y: 40 + 5 * 130 + 100, texto: 'total: 17 comparações', cor: 'roxo' })

export const ideia = { caixas, setas: [], notas }

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início: merge_sort(p, r)'],
    ['B', 'dec', 'r - p < 2?'],
    ['C', 'proc', 'q = meio de p e r'],
    ['D', 'proc', 'merge_sort(p, q)'],
    ['E', 'proc', 'merge_sort(q, r)'],
    ['F', 'proc', 'intercala v[p..q-1] e v[q..r-1]'],
    ['G', 'inicio', 'Fim: v[p..r-1] ordenado'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'G', 'Sim'],
    ['B', 'C', 'Não'],
    ['C', 'D'],
    ['D', 'E'],
    ['E', 'F'],
    ['F', 'G'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'F', 'G'],
}
