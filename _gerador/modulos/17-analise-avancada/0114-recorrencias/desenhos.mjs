// A árvore de recursão da auditoria com 8 notas: cada caixa é uma chamada,
// com o tamanho do lote que ela confere. Somando cada nível dá 8, e são 4
// níveis: T(8) = 32.
const W = 100
const H = 80
const PASSO = 125
const X0 = 120
const niveis = [8, 4, 2, 1]
const caixas = []
const setas = []
const notas = []
niveis.forEach((tam, k) => {
  const qtd = 2 ** k
  const y = 60 + k * 160
  for (let i = 0; i < qtd; i++) {
    // centro: média dos centros das folhas que estão embaixo desta caixa
    const folhas = 8 / qtd
    const centro = X0 + W / 2 + (i * folhas + (folhas - 1) / 2) * PASSO
    caixas.push({ id: `n${k}_${i}`, x: centro - W / 2, y, w: W, h: H, cor: k === 3 ? 'verde' : 'roxo', texto: [String(tam)] })
    if (k > 0) setas.push({ de: `n${k - 1}_${Math.floor(i / 2)}`, para: `n${k}_${i}`, lados: 'bc', cor: 'cinza' })
  }
  const conta = qtd === 1 ? '1 × 8 = 8' : `${qtd} × ${tam} = 8`
  notas.push({ x: 1180, y: y + 50, texto: `nível ${k}: ${conta}`, cor: k === 3 ? 'verde' : 'roxo' })
})
notas.push({ x: 1180, y: 60 + 4 * 160 + 20, texto: '4 níveis × 8 = 32', cor: 'azul' })
notas.push({ x: X0, y: 60 + 4 * 160 + 20, texto: 'roxo: divide e repassa    verde: caso base, T(1) = 1', cor: 'cinza' })

export const ideia = { caixas, setas, notas }

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início: audita(ini, fim)'],
    ['B', 'proc', 'n = fim - ini; custo_nivel += n'],
    ['C', 'dec', 'n == 1?'],
    ['D', 'proc', 'meio = ini + n / 2'],
    ['E', 'proc', 'audita(ini, meio)'],
    ['F', 'proc', 'audita(meio, fim)'],
    ['G', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'G', 'Sim'],
    ['C', 'D', 'Não'],
    ['D', 'E'],
    ['E', 'F'],
    ['F', 'G'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'F', 'G'],
}
