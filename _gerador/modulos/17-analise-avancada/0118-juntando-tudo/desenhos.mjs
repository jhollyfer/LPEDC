// Medir em 8 mil e 16 mil, conferir a razão, prever 1 milhão e conferir.
// Só comparações (saem iguais em qualquer máquina). Verde: a previsão bateu;
// vermelho: o insertion nem roda em 1 milhão.
const linhas = [
  ['insertion', 'Θ(n²)', ['16,2 mi', '64,8 mi', '× 4,00', '253 bi', 'não roda'], ['roxo', 'roxo', 'amarelo', 'vermelho', 'vermelho']],
  ['merge', 'Θ(n log n)', ['93.744', '203.390', '× 2,17', '18,1 mi', '18,7 mi'], ['roxo', 'roxo', 'amarelo', 'verde', 'verde']],
  ['heap', 'Θ(n log n)', ['182.686', '397.420', '× 2,18', '35,4 mi', '36,8 mi'], ['roxo', 'roxo', 'amarelo', 'verde', 'verde']],
  ['quick', 'Θ(n log n)', ['120.347', '275.805', '× 2,29', '24,6 mi', '25,0 mi'], ['roxo', 'roxo', 'amarelo', 'verde', 'verde']],
]
const colunas = [370, 590, 810, 1030, 1250]
const W = 205
const caixas = []
linhas.forEach(([nome, classe, valores, cores], r) => {
  const y = 170 + r * 150
  caixas.push({ id: `a${r}`, x: 100, y, w: 250, h: 130, cor: 'azul', rotulo: nome, texto: [classe] })
  valores.forEach((v, k) => caixas.push({ id: `v${r}${k}`, x: colunas[k], y, w: W, h: 130, cor: cores[k], texto: [v] }))
})
const titulos = [['n = 8 mil'], ['n = 16 mil'], ['dobrou n:', 'custo ×'], ['previsão', '1 milhão'], ['medido', '1 milhão']]
titulos.forEach((t, k) => caixas.push({ id: `t${k}`, x: colunas[k], y: 30, w: W, h: 110, cor: 'cinza', texto: t }))
const notas = [{ x: 100, y: 800, texto: 'comparações entre elementos; mi = milhões, bi = bilhões', cor: 'cinza' }]

export const ideia = { caixas, setas: [], notas }

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início: um algoritmo'],
    ['B', 'proc', 'classe pela análise (n² ou n log n)'],
    ['C', 'io', 'mede com n e com 2n'],
    ['D', 'dec', 'a razão bate com a classe?'],
    ['E', 'proc', 'revisar a análise ou o código'],
    ['F', 'proc', 'prevê N: medida × fator'],
    ['G', 'dec', 'N cabe no tempo de teste?'],
    ['H', 'io', 'roda N e compara'],
    ['I', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D'],
    ['D', 'E', 'Não'],
    ['E', 'B'],
    ['D', 'F', 'Sim'],
    ['F', 'G'],
    ['G', 'H', 'Sim'],
    ['G', 'I', 'Não'],
    ['H', 'I'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'F', 'G', 'H', 'I'],
}
