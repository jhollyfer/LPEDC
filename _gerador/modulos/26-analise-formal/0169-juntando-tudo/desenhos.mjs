// A ficha conferida das cinco funções: passos com n = 1024 e 2048, a razão,
// e o espaço extra medido com n = 2048 (frames na pilha e bytes no heap).
// Verde: espaço constante; vermelho: espaço que cresce com n.
const linhas = [
  ['soma', 'Θ(n)', '1024', '2048', '× 2', 'Θ(1)', '1 frame', 'verde'],
  ['busca', 'Θ(log n)', '11', '12', '+ 1', 'Θ(1)', '1 frame', 'verde'],
  ['pares', 'Θ(n²)', '523.776', '2.096.128', '× 4', 'Θ(1)', '1 frame', 'verde'],
  ['merge', 'Θ(n log n)', '10.240', '22.528', '× 2,2', 'Θ(n)', '8192 bytes', 'vermelho'],
  ['soma_rec', 'Θ(n)', '1025', '2049', '× 2', 'Θ(n)', '2049 frames', 'vermelho'],
]
const xs = [100, 300, 510, 720, 930, 1100, 1270]
const ws = [190, 200, 200, 200, 160, 160, 230]
const caixas = []
const titulos = [['função'], ['tempo'], ['passos', 'n = 1024'], ['passos', 'n = 2048'], ['razão'], ['espaço'], ['medido', 'n = 2048']]
titulos.forEach((t, k) => caixas.push({ id: `t${k}`, x: xs[k], y: 30, w: ws[k], h: 110, cor: 'cinza', texto: t }))
linhas.forEach((l, r) => {
  const y = 160 + r * 120
  const corEsp = l[7]
  const cores = ['azul', 'roxo', 'roxo', 'roxo', 'amarelo', corEsp, corEsp]
  for (let k = 0; k < 7; k++) caixas.push({ id: `c${r}_${k}`, x: xs[k], y, w: ws[k], h: 100, cor: cores[k], texto: [l[k]] })
})
const notas = [{ x: 100, y: 800, texto: 'as cinco fichas conferem: fórmula exata, razão ao dobrar n e espaço medido', cor: 'cinza' }]

export const ideia = { caixas, setas: [], notas }

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início: uma função e a ficha'],
    ['B', 'proc', 'fórmula de passos e de espaço lendo o código'],
    ['C', 'proc', 'instrumenta: passos, bytes, frames'],
    ['D', 'io', 'mede com n e com 2n'],
    ['E', 'dec', 'a medida bate com a fórmula?'],
    ['F', 'proc', 'revisar a fórmula ou o contador'],
    ['G', 'dec', 'a razão bate com a classe da ficha?'],
    ['H', 'io', 'ficha conferida'],
    ['I', 'io', 'ficha errada: reclamar'],
    ['J', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D'],
    ['D', 'E'],
    ['E', 'F', 'Não'],
    ['F', 'B'],
    ['E', 'G', 'Sim'],
    ['G', 'H', 'Sim'],
    ['G', 'I', 'Não'],
    ['H', 'J'],
    ['I', 'J'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'G', 'H', 'J'],
}
