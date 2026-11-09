// O teto 4n² contra o custo medido f(n) = 3n² + 10n + 20, de n = 6 a 15.
// Vermelho: o teto ainda perde; verde: de n0 = 12 em diante, o teto vale.
const f = (n) => 3 * n * n + 10 * n + 20
const ns = [6, 7, 8, 9, 10, 11, 12, 13, 14, 15]
const X0 = 330
const COL = 115
const caixas = [
  { id: 'r0', x: 100, y: 120, w: 210, h: 90, cor: 'cinza', texto: ['n'] },
  { id: 'r1', x: 100, y: 230, w: 210, h: 90, cor: 'azul', texto: ['f(n)'] },
  { id: 'r2', x: 100, y: 340, w: 210, h: 90, cor: 'roxo', texto: ['4n²'] },
  { id: 'r3', x: 100, y: 450, w: 210, h: 90, cor: 'roxo', texto: ['3n²'] },
]
ns.forEach((n, i) => {
  const x = X0 + i * COL
  const ok = f(n) <= 4 * n * n
  caixas.push({ id: `n${n}`, x, y: 120, w: COL - 10, h: 90, cor: n === 12 ? 'amarelo' : 'cinza', texto: [String(n)] })
  caixas.push({ id: `f${n}`, x, y: 230, w: COL - 10, h: 90, cor: 'azul', texto: [String(f(n))] })
  caixas.push({ id: `t${n}`, x, y: 340, w: COL - 10, h: 90, cor: ok ? 'verde' : 'vermelho', texto: [String(4 * n * n)] })
  caixas.push({ id: `p${n}`, x, y: 450, w: COL - 10, h: 90, cor: 'verde', texto: [String(3 * n * n)] })
})
const xn0 = X0 + 6 * COL + (COL - 10) / 2
const setas = [{ pontos: [[xn0, 40], [xn0, 110]], rotulo: 'n₀ = 12', cor: 'verde' }]
const notas = [
  { x: 100, y: 600, texto: 'teto: 4n² ≥ f(n) só de n₀ = 12 em diante (vermelho antes)', cor: 'vermelho' },
  { x: 100, y: 650, texto: 'piso: 3n² ≤ f(n) para todo n ≥ 1', cor: 'verde' },
  { x: 100, y: 700, texto: '3n² ≤ f(n) ≤ 4n² para n ≥ 12:  f(n) = Θ(n²)', cor: 'azul' },
]
export const ideia = { caixas, setas, notas }

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início: n0_teto(c)'],
    ['B', 'proc', 'n0 = 1; n = 1'],
    ['C', 'dec', 'n <= LIMITE?'],
    ['D', 'dec', 'custo(n) > c · n²?'],
    ['E', 'proc', 'n0 = n + 1'],
    ['F', 'proc', 'n++'],
    ['G', 'io', 'devolve n0 (12 com c = 4)'],
    ['H', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D', 'Sim'],
    ['C', 'G', 'Não'],
    ['D', 'E', 'Sim'],
    ['D', 'F', 'Não'],
    ['E', 'F'],
    ['F', 'C'],
    ['G', 'H'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'F', 'C', 'D', 'F', 'C', 'G', 'H'],
}
