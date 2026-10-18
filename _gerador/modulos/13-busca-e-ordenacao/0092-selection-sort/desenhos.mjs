// cada linha: o vetor ANTES da troca da passada i.
// verde = já no lugar, roxo = gaveta i (vai receber o menor), amarelo = o menor achado
const X = 330
const linhas = [
  ['i = 0', ['58', '31', '47', '19', '26'], { 0: 'roxo', 3: 'amarelo' }, 'menor é 19: troca com o 58'],
  ['i = 1', ['19', '31', '47', '58', '26'], { 0: 'verde', 1: 'roxo', 4: 'amarelo' }, 'menor é 26: troca com o 31'],
  ['i = 2', ['19', '26', '47', '58', '31'], { 0: 'verde', 1: 'verde', 2: 'roxo', 4: 'amarelo' }, 'menor é 31: troca com o 47'],
  ['i = 3', ['19', '26', '31', '58', '47'], { 0: 'verde', 1: 'verde', 2: 'verde', 3: 'roxo', 4: 'amarelo' }, 'menor é 47: troca com o 58'],
  ['fim', ['19', '26', '31', '47', '58'], { 0: 'verde', 1: 'verde', 2: 'verde', 3: 'verde', 4: 'verde' }, '10 comparações, 4 trocas'],
]

export const ideia = {
  caixas: linhas.map(([, itens, estados], i) => ({
    id: `v${i}`,
    forma: 'array',
    x: X,
    y: 40 + i * 140,
    celula: 100,
    itens,
    estados,
    indices: i === 0,
  })),
  setas: [],
  notas: [
    ...linhas.map(([rotulo], i) => ({ x: 100, y: 92 + i * 140, texto: rotulo, cor: i === 4 ? 'verde' : 'roxo' })),
    ...linhas.map(([, , , nota], i) => ({ x: 880, y: 92 + i * 140, texto: nota, cor: i === 4 ? 'verde' : 'roxo' })),
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início: 58 31 47 19 26'],
    ['B', 'dec', 'i < n - 1?'],
    ['C', 'proc', 'menor = i'],
    ['D', 'proc', 'acha o menor de v[i..n-1]'],
    ['E', 'dec', 'menor != i?'],
    ['F', 'proc', 'troca v[i] com v[menor]'],
    ['G', 'proc', 'i = i + 1'],
    ['H', 'io', 'Mostrar 19 26 31 47 58'],
    ['I', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C', 'Sim'],
    ['C', 'D'],
    ['D', 'E'],
    ['E', 'F', 'Sim'],
    ['E', 'G', 'Não'],
    ['F', 'G'],
    ['G', 'B'],
    ['B', 'H', 'Não'],
    ['H', 'I'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'B', 'H', 'I'],
}
