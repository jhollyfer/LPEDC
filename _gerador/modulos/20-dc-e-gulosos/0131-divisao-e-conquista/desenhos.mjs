// a potência rápida de 3^20: à esquerda a recursão descendo (o expoente cai
// pela metade), à direita os resultados subindo (cada um combina o de baixo)
const descendo = [
  ['3^20 = (3^10)²', '20 é par'],
  ['3^10 = (3^5)²', '10 é par'],
  ['3^5 = (3^2)² · 3', '5 é ímpar'],
  ['3^2 = (3^1)²', '2 é par'],
  ['3^1 = (3^0)² · 3', '1 é ímpar'],
  ['3^0 = 1', 'caso base'],
]
const subindo = ['3486784401', '59049', '243', '9', '3', '1']

const caixas = []
const setas = []
const notas = []
descendo.forEach(([t], i) => {
  const y = 60 + i * 120
  caixas.push({ id: `d${i}`, x: 110, y, w: 440, h: 86, cor: i === 5 ? 'amarelo' : 'roxo', texto: t })
  caixas.push({ id: `s${i}`, x: 1000, y, w: 360, h: 86, cor: 'verde', texto: subindo[i] })
  setas.push({ de: `d${i}`, para: `s${i}`, cor: 'cinza' })
  if (i < 5) {
    setas.push({ de: `d${i}`, para: `d${i + 1}`, lados: 'bc' })
    setas.push({ de: `s${i + 1}`, para: `s${i}`, lados: 'cb', cor: 'verde' })
  }
})
descendo.forEach(([, n], i) => notas.push({ x: 580, y: 60 + i * 120 + 36, texto: n, cor: i === 5 ? 'azul' : 'cinza' }))
notas.push({ x: 110, y: 22, texto: 'divide: o expoente cai pela metade', cor: 'roxo' })
notas.push({ x: 1000, y: 22, texto: 'combina: o resultado sobe', cor: 'verde' })
notas.push({ x: 110, y: 820, texto: '6 chamadas e 7 multiplicações, contra 19 do laço simples', cor: 'roxo' })

export const ideia = { caixas, setas, notas }

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início: potencia(x, n)'],
    ['B', 'dec', 'n == 0?'],
    ['C', 'io', 'Devolve 1'],
    ['D', 'proc', 'metade = potencia(x, n / 2)'],
    ['E', 'dec', 'n é par?'],
    ['F', 'proc', 'r = metade * metade'],
    ['G', 'proc', 'r = metade * metade * x'],
    ['H', 'io', 'Devolve r'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C', 'Sim'],
    ['B', 'D', 'Não'],
    ['D', 'E'],
    ['E', 'F', 'Sim'],
    ['E', 'G', 'Não'],
    ['F', 'H'],
    ['G', 'H'],
  ],
  caminho: ['A', 'B', 'D', 'E', 'F', 'H'],
}
