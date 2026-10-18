// as duas versões da lista lado a lado: os traços ligam as 5 linhas da LCS
// (iguais, azul); o que sobra vira "-" (vermelho, só na antiga) ou "+"
// (verde, só na nova). À direita, o que o diff imprime.
const v1 = ['arroz', 'feijão', 'café', 'leite', 'pão', 'banana', 'sabão']
const v2 = ['arroz', 'feijão', 'açúcar', 'café', 'leite sem lactose', 'pão', 'banana']
const so1 = [3, 6] // leite, sabão
const so2 = [2, 4] // açúcar, leite sem lactose
const pares = [
  [0, 0],
  [1, 1],
  [2, 3],
  [4, 5],
  [5, 6],
]
const Y = 140
const PASSO = 70
const H = 56

const caixas = [
  ...v1.map((t, i) => ({
    id: `a${i}`,
    x: 110,
    y: Y + i * PASSO,
    w: 230,
    h: H,
    cor: so1.includes(i) ? 'vermelho' : 'azul',
    texto: [t],
  })),
  ...v2.map((t, j) => ({
    id: `b${j}`,
    x: 560,
    y: Y + j * PASSO,
    w: 330,
    h: H,
    cor: so2.includes(j) ? 'verde' : 'azul',
    texto: [t],
  })),
  {
    id: 't',
    forma: 'terminal',
    x: 1000,
    y: Y - 30,
    w: 470,
    texto: ['  arroz', '  feijão', '+ açúcar', '  café', '- leite', '+ leite sem lactose', '  pão', '  banana', '- sabão'],
  },
]

export const ideia = {
  caixas,
  setas: pares.map(([i, j]) => ({
    pontos: [
      [356, Y + i * PASSO + H / 2],
      [544, Y + j * PASSO + H / 2],
    ],
    cor: 'cinza',
  })),
  notas: [
    { x: 225, y: Y - 30, texto: 'compras-v1.txt', cor: 'azul', ancora: 'middle' },
    { x: 725, y: Y - 30, texto: 'compras-v2.txt', cor: 'azul', ancora: 'middle' },
    { x: 110, y: Y + 7 * PASSO + 30, texto: 'LCS das linhas: 5 iguais; 2 removidas (-) e 2 adicionadas (+)', cor: 'roxo' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início da volta: i = 0, j = 0'],
    ['B', 'dec', 'Sobrou linha em a ou em b?'],
    ['C', 'dec', 'a[i] igual a b[j]?'],
    ['D', 'io', 'Mostra a linha como igual; i++ e j++'],
    ['E', 'io', 'Mostra - a[i] ou + b[j] (o lado que perde menos)'],
    ['H', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C', 'Sim'],
    ['B', 'H', 'Não'],
    ['C', 'D', 'Sim'],
    ['C', 'E', 'Não'],
    ['D', 'B'],
    ['E', 'B'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'B'],
}
