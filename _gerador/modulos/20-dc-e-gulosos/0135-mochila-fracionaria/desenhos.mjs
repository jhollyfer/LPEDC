// mochila fracionária: à esquerda os produtos já ordenados por R$/kg; à
// direita a carga da caminhonete (60 kg), empilhada na ordem em que entrou,
// com a altura proporcional ao peso (10 px por kg)
const itens = [
  ['açafrão', 80, 5, 5, 'verde'],
  ['castanha', 50, 15, 15, 'verde'],
  ['café', 30, 20, 20, 'verde'],
  ['feijão', 9, 30, 20, 'amarelo'],
  ['arroz', 5, 40, 0, 'cinza'],
]

const caixas = []
const notas = []
itens.forEach(([nome, razao, peso, leva], i) => {
  const cor = itens[i][4]
  caixas.push({ id: `l${i}`, x: 110, y: 90 + i * 112, w: 560, h: 84, cor, texto: `${nome}: R$ ${razao}/kg, ${peso} kg` })
  if (leva === peso) notas.push({ x: 690, y: 140 + i * 112, texto: 'inteiro', cor: 'verde' })
  else if (leva > 0) notas.push({ x: 690, y: 140 + i * 112, texto: `${leva} de ${peso} kg`, cor: 'roxo' })
  else notas.push({ x: 690, y: 140 + i * 112, texto: 'não cabe', cor: 'cinza' })
})

// a pilha da carga: de baixo para cima
const X = 1000
const BASE = 700
let topo = BASE
itens.forEach(([nome, , , leva], i) => {
  if (!leva) return
  const h = leva * 10
  topo -= h
  caixas.push({ id: `c${i}`, x: X, y: topo, w: 330, h, cor: itens[i][4], texto: `${nome} ${leva} kg` })
})
notas.push({ x: X + 165, y: 76, texto: 'caminhonete: 60 kg', cor: 'azul', ancora: 'middle' })
notas.push({ x: 110, y: 60, texto: '1. ordena por valor/kg', cor: 'roxo' })
notas.push({ x: 110, y: 700, texto: '2. enche na ordem: o último entra partido', cor: 'roxo' })
notas.push({ x: 110, y: 770, texto: 'R$ 400 + 750 + 600 + 180 = R$ 1930', cor: 'verde' })

export const ideia = { caixas, setas: [], notas }

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'proc', 'Ordena por valor/peso (maior primeiro)'],
    ['C', 'proc', 'livre = 60; i = 0'],
    ['D', 'dec', 'i < n e livre > 0?'],
    ['E', 'dec', 'peso[i] <= livre?'],
    ['F', 'proc', 'Leva tudo; livre\u00a0-=\u00a0peso[i]'],
    ['G', 'proc', 'Leva a fração livre\u00a0/\u00a0peso[i]; livre\u00a0=\u00a00'],
    ['H', 'proc', 'i++'],
    ['I', 'io', 'Mostra o total (R$ 1930)'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D'],
    ['D', 'E', 'Sim'],
    ['E', 'F', 'Sim'],
    ['E', 'G', 'Não'],
    ['F', 'H'],
    ['G', 'H'],
    ['H', 'D'],
    ['D', 'I', 'Não'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'F', 'H', 'D', 'E', 'G', 'H', 'D', 'I'],
}
