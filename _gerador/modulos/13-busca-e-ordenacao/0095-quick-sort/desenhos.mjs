// o quick sort dos preços dos fones. roxo = pivô da vez, verde = já no lugar
const X = 300
const linhas = [
  ['início', ['35', '12', '48', '7', '29', '51', '20'], { 6: 'roxo' }, ['pivô = o último: 20']],
  ['separa', ['12', '7', '20', '35', '29', '51', '48'], { 1: 'roxo', 2: 'verde', 6: 'roxo' }, ['≤ 20 à esquerda, > 20 à', 'direita (6 comparações)']],
  ['separa', ['7', '12', '20', '35', '29', '48', '51'], { 0: 'verde', 1: 'verde', 2: 'verde', 4: 'roxo', 5: 'verde', 6: 'verde' }, ['cada lado com o seu pivô:', '7 e 48 (1 + 3 comparações)']],
  ['separa', ['7', '12', '20', '29', '35', '48', '51'], Object.fromEntries([0, 1, 2, 3, 4, 5, 6].map((i) => [i, 'verde'])), ['pivô 29 (1 comparação)', 'total: 11 comparações']],
]

export const ideia = {
  caixas: linhas.map(([, itens, estados], i) => ({
    id: `v${i}`,
    forma: 'array',
    x: X,
    y: 60 + i * 160,
    celula: 100,
    itens,
    estados,
    indices: i === 0,
  })),
  setas: [],
  notas: [
    ...linhas.map(([rotulo], i) => ({ x: 100, y: 112 + i * 160, texto: rotulo, cor: i === 0 ? 'azul' : 'roxo' })),
    ...linhas.map(([, , , nota], i) => ({
      x: 1050,
      y: (nota.length > 1 ? 94 : 112) + i * 160,
      texto: nota,
      cor: i === 3 ? 'verde' : 'roxo',
    })),
    { x: 400, y: 208, texto: '≤ 20', cor: 'cinza', ancora: 'middle' },
    { x: 800, y: 208, texto: '> 20', cor: 'cinza', ancora: 'middle' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início: quick_sort(p, r)'],
    ['B', 'dec', 'p < r?'],
    ['C', 'proc', 'pivô = v[r]'],
    ['D', 'proc', 'separa: ≤ pivô à esquerda, > pivô à direita'],
    ['E', 'proc', 'pivô vai para v[j]'],
    ['F', 'proc', 'quick_sort(p, j - 1)'],
    ['G', 'proc', 'quick_sort(j + 1, r)'],
    ['H', 'inicio', 'Fim: v[p..r] ordenado'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C', 'Sim'],
    ['B', 'H', 'Não'],
    ['C', 'D'],
    ['D', 'E'],
    ['E', 'F'],
    ['F', 'G'],
    ['G', 'H'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'],
}
