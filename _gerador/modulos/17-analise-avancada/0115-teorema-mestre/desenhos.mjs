// As três árvores do escritório para n = 16, nível por nível: com a = 1 o
// custo cai (a raiz pesa), com a = 2 fica igual (empate), com a = 4 cresce
// (as folhas pesam). Em verde, a parte que domina o total.
const colunas = [
  {
    x: 110,
    titulo: ['T(n) = T(n/2) + n', 'a = 1  <  b^k = 2'],
    niveis: ['1 × 16 = 16', '1 × 8 = 8', '1 × 4 = 4', '1 × 2 = 2', '1 × 1 = 1'],
    dominante: [0],
    total: 'total 31',
    caso: ['caso 3: a raiz domina', 'Θ(n)'],
  },
  {
    x: 590,
    titulo: ['T(n) = 2 T(n/2) + n', 'a = 2  =  b^k = 2'],
    niveis: ['1 × 16 = 16', '2 × 8 = 16', '4 × 4 = 16', '8 × 2 = 16', '16 × 1 = 16'],
    dominante: [0, 1, 2, 3, 4],
    total: 'total 80',
    caso: ['caso 2: todos pesam igual', 'Θ(n log n)'],
  },
  {
    x: 1070,
    titulo: ['T(n) = 4 T(n/2) + n', 'a = 4  >  b^k = 2'],
    niveis: ['1 × 16 = 16', '4 × 8 = 32', '16 × 4 = 64', '64 × 2 = 128', '256 × 1 = 256'],
    dominante: [4],
    total: 'total 496',
    caso: ['caso 1: as folhas dominam', 'Θ(n²)'],
  },
]
const W = 380
const caixas = []
const notas = []
const setas = []
colunas.forEach((c, i) => {
  caixas.push({ id: `t${i}`, x: c.x, y: 40, w: W, h: 120, cor: 'azul', texto: c.titulo })
  c.niveis.forEach((t, k) => {
    const cor = c.dominante.length === 5 ? 'amarelo' : c.dominante.includes(k) ? 'verde' : 'roxo'
    caixas.push({ id: `c${i}n${k}`, x: c.x, y: 200 + k * 100, w: W, h: 76, cor, texto: [`nível ${k}:  ${t}`] })
  })
  notas.push({ x: c.x + W / 2, y: 730, texto: c.total, cor: 'cinza', ancora: 'middle' })
  notas.push({ x: c.x + W / 2, y: 780, texto: c.caso, cor: 'verde', ancora: 'middle' })
})

export const ideia = { caixas, setas, notas }

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'io', 'T(n) = a T(n/b) + n^k'],
    ['C', 'dec', 'o tamanho é dividido por b?'],
    ['N', 'proc', 'não se aplica: árvore de recursão'],
    ['D', 'dec', 'a > b^k?'],
    ['F', 'proc', 'caso 1: Θ(n^(log_b a))'],
    ['E', 'dec', 'a = b^k?'],
    ['G', 'proc', 'caso 2: Θ(n^k log n)'],
    ['H', 'proc', 'caso 3: Θ(n^k)'],
    ['Z', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'N', 'Não'],
    ['C', 'D', 'Sim'],
    ['D', 'F', 'Sim'],
    ['D', 'E', 'Não'],
    ['E', 'G', 'Sim'],
    ['E', 'H', 'Não'],
    ['N', 'Z'],
    ['F', 'Z'],
    ['G', 'Z'],
    ['H', 'Z'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'G', 'Z'],
}
