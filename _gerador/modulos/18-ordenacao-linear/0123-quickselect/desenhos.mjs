// quickselect da mediana dos aluguéis (k = 4): cada separação deixa o pivô
// (roxo) no lugar e descarta (cinza) o lado que não tem a posição 4
const X = 300
const cinza = (ids) => Object.fromEntries(ids.map((i) => [i, 'apagado']))
const linhas = [
  ['início', ['1850', '1200', '2400', '980', '1450', '2050', '3100', '1600', '1300'], { 4: 'amarelo', 8: 'roxo' }, ['queremos a posição 4;', 'pivô = o último (1300)']],
  ['separa', ['1200', '980', '1300', '1850', '1450', '2050', '3100', '1600', '2400'], { ...cinza([0, 1]), 2: 'roxo', 8: 'roxo' }, ['1300 na posição 2:', '4 > 2, segue à direita']],
  ['separa', ['1200', '980', '1300', '1850', '1450', '2050', '1600', '2400', '3100'], { ...cinza([0, 1, 2, 8]), 6: 'roxo', 7: 'roxo' }, ['2400 na posição 7:', '4 < 7, segue à esquerda']],
  ['separa', ['1200', '980', '1300', '1450', '1600', '2050', '1850', '2400', '3100'], { ...cinza([0, 1, 2, 3, 5, 6, 7, 8]), 4: 'verde' }, ['1600 na posição 4:', 'achou a mediana']],
]

export const ideia = {
  caixas: linhas.map(([, itens, estados], i) => ({
    id: `v${i}`,
    forma: 'array',
    x: X,
    y: 60 + i * 170,
    celula: 96,
    itens,
    estados,
    indices: i === 0,
  })),
  setas: [],
  notas: [
    ...linhas.map(([rotulo], i) => ({ x: 110, y: 112 + i * 170, texto: rotulo, cor: i === 0 ? 'azul' : 'roxo' })),
    ...linhas.map(([, , , nota], i) => ({ x: 1200, y: 94 + i * 170, texto: nota, cor: i === 3 ? 'verde' : 'roxo' })),
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'io', 'Recebe v, n = 9 e k = 4'],
    ['C', 'proc', 'p = 0; r = n - 1'],
    ['D', 'proc', 'j = separa(v, p, r)'],
    ['E', 'dec', 'j == k?'],
    ['F', 'dec', 'k < j?'],
    ['G', 'proc', 'r = j - 1 (esquerda)'],
    ['H', 'proc', 'p = j + 1 (direita)'],
    ['I', 'io', 'Mostra v[j] (1600)'],
    ['J', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D'],
    ['D', 'E'],
    ['E', 'I', 'Sim'],
    ['E', 'F', 'Não'],
    ['F', 'G', 'Sim'],
    ['F', 'H', 'Não'],
    ['G', 'D'],
    ['H', 'D'],
    ['I', 'J'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'F', 'H', 'D', 'E', 'F', 'G', 'D', 'E', 'I', 'J'],
}
