// o vetor dos tempos de entrega no fim de cada passada; verde = já no lugar
const X = 330
const linhas = [
  ['início', ['42', '17', '35', '8', '23'], {}, ''],
  ['passada 1', ['17', '35', '8', '23', '42'], { 4: 'verde' }, '4 trocas: o 42 afundou até o fim'],
  ['passada 2', ['17', '8', '23', '35', '42'], { 3: 'verde', 4: 'verde' }, '2 trocas: o 35 foi para o lugar'],
  ['passada 3', ['8', '17', '23', '35', '42'], { 2: 'verde', 3: 'verde', 4: 'verde' }, '1 troca: o 8 chegou na frente'],
  ['passada 4', ['8', '17', '23', '35', '42'], { 0: 'verde', 1: 'verde', 2: 'verde', 3: 'verde', 4: 'verde' }, '0 trocas: a bandeira manda parar'],
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
    ...linhas.map(([rotulo], i) => ({ x: 100, y: 92 + i * 140, texto: rotulo, cor: i === 0 ? 'azul' : 'roxo' })),
    ...linhas.slice(1).map(([, , , nota], i) => ({ x: 880, y: 92 + (i + 1) * 140, texto: nota, cor: i === 3 ? 'verde' : 'roxo' })),
    { x: 880, y: 92, texto: 'compara vizinhos e troca se', cor: 'cinza' },
    { x: 880, y: 130, texto: 'o da esquerda for maior', cor: 'cinza' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início: 42 17 35 8 23'],
    ['B', 'proc', 'nova passada: j = 0, trocou = não'],
    ['C', 'dec', 'j < n - passada?'],
    ['D', 'dec', 'v[j] > v[j+1]?'],
    ['E', 'proc', 'troca os vizinhos; trocou = sim'],
    ['F', 'proc', 'j = j + 1'],
    ['G', 'dec', 'trocou?'],
    ['H', 'io', 'Mostrar 8 17 23 35 42'],
    ['I', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D', 'Sim'],
    ['D', 'E', 'Sim'],
    ['D', 'F', 'Não'],
    ['E', 'F'],
    ['F', 'C'],
    ['C', 'G', 'Não'],
    ['G', 'B', 'Sim'],
    ['G', 'H', 'Não'],
    ['H', 'I'],
  ],
}
