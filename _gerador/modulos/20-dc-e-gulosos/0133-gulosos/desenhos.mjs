// o guloso do troco em duas linhas: no Real ele acerta (190 centavos em 5
// moedas); com fichas de 1, 3 e 4 ele erra (6 créditos em 3 fichas, quando
// 3 + 3 resolve com 2)
const moeda = (id, x, y, v, cor, resta) => [
  { id, x, y, w: 130, h: 90, cor, texto: String(v) },
  { x: x + 65, y: y + 130, texto: `resta ${resta}`, cor: 'cinza', ancora: 'middle' },
]

const caixas = []
const notas = []
const setas = []
const linha = (pref, y, inicio, passos, corFinal) => {
  caixas.push({ id: `${pref}0`, x: 110, y, w: 200, h: 90, cor: 'azul', texto: `troco ${inicio}` })
  passos.forEach(([v, resta, cor], i) => {
    const [c, n] = moeda(`${pref}${i + 1}`, 420 + i * 190, y, v, cor, resta)
    caixas.push(c)
    notas.push(n)
    setas.push({ de: `${pref}${i}`, para: `${pref}${i + 1}` })
  })
  return corFinal
}

notas.push({ x: 110, y: 30, texto: 'Real (centavos): moedas 100, 50, 25, 10, 5', cor: 'azul' })
linha('r', 60, 190, [
  [100, 90, 'verde'],
  [50, 40, 'verde'],
  [25, 15, 'verde'],
  [10, 5, 'verde'],
  [5, 0, 'verde'],
])
notas.push({ x: 420, y: 250, texto: '5 moedas: o mínimo, e o guloso acertou', cor: 'verde' })

notas.push({ x: 110, y: 330, texto: 'fliperama: fichas de 4, 3 e 1 créditos', cor: 'azul' })
linha('f', 360, 6, [
  [4, 2, 'vermelho'],
  [1, 1, 'roxo'],
  [1, 0, 'roxo'],
])
notas.push({ x: 1000, y: 416, texto: '3 fichas: o guloso errou', cor: 'vermelho' })

caixas.push({ id: 'o0', x: 110, y: 610, w: 200, h: 90, cor: 'azul', texto: 'troco 6' })
caixas.push({ id: 'o1', x: 420, y: 610, w: 130, h: 90, cor: 'verde', texto: '3' })
caixas.push({ id: 'o2', x: 610, y: 610, w: 130, h: 90, cor: 'verde', texto: '3' })
setas.push({ de: 'o0', para: 'o1' }, { de: 'o1', para: 'o2' })
notas.push({ x: 800, y: 666, texto: 'o ótimo: 2 fichas, que o guloso nunca testa', cor: 'verde' })
notas.push({ x: 420, y: 590, texto: 'começar pelo 4 parecia melhor e fechou este caminho', cor: 'cinza' })

export const ideia = { caixas, setas, notas }

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'io', 'Recebe valor (190)'],
    ['C', 'proc', 'i = 0 (a maior moeda)'],
    ['D', 'dec', 'valor > 0?'],
    ['E', 'dec', 'moedas[i] <= valor?'],
    ['F', 'proc', 'Dá moedas[i]; valor -= moedas[i]'],
    ['G', 'proc', 'i++ (a próxima menor)'],
    ['H', 'io', 'Mostra quantas moedas'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D'],
    ['D', 'E', 'Sim'],
    ['E', 'F', 'Sim'],
    ['E', 'G', 'Não'],
    ['F', 'D'],
    ['G', 'D'],
    ['D', 'H', 'Não'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'F', 'D', 'E', 'G', 'D', 'H'],
}
