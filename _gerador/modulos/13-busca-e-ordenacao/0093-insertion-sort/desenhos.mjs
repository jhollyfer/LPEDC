// a mão de cartas depois de cada encaixe.
// verde = parte já ordenada, amarelo = a carta que acabou de ser encaixada
const X = 330
const v = (n, amarela) => Object.fromEntries(Array.from({ length: n }, (_, i) => [i, i === amarela ? 'amarelo' : 'verde']))
const linhas = [
  ['início', ['7', '4', '9', '2', '5'], { 0: 'verde' }, 'só o 7: uma carta já está em ordem'],
  ['j = 1', ['4', '7', '9', '2', '5'], v(2, 0), 'o 4 passa o 7: 1 deslocamento'],
  ['j = 2', ['4', '7', '9', '2', '5'], v(3, 2), 'o 9 fica onde está: 0'],
  ['j = 3', ['2', '4', '7', '9', '5'], v(4, 0), 'o 2 vai para a frente: 3'],
  ['j = 4', ['2', '4', '5', '7', '9'], v(5, 2), 'o 5 entra entre 4 e 7: 2'],
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
    ...linhas.map(([, , , nota], i) => ({ x: 880, y: 92 + i * 140, texto: nota, cor: i === 4 ? 'verde' : 'roxo' })),
    { x: 880, y: 740, texto: '8 comparações, 6 deslocamentos', cor: 'verde' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início: j = 1'],
    ['B', 'dec', 'j < n?'],
    ['C', 'proc', 'x = v[j]; i = j - 1'],
    ['D', 'dec', 'i >= 0 e v[i] > x?'],
    ['E', 'proc', 'v[i+1] = v[i]; i = i - 1'],
    ['F', 'proc', 'v[i+1] = x; j = j + 1'],
    ['G', 'io', 'Mostrar 2 4 5 7 9'],
    ['H', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C', 'Sim'],
    ['C', 'D'],
    ['D', 'E', 'Sim'],
    ['E', 'D'],
    ['D', 'F', 'Não'],
    ['F', 'B'],
    ['B', 'G', 'Não'],
    ['G', 'H'],
  ],
}
