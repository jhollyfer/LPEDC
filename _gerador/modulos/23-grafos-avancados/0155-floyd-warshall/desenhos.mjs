// os cinco bairros (mão única, minutos) e a tabela final do Floyd-Warshall;
// verde = melhor caminho Centro -> Alto (8 min), e a linha do Centro na tabela
const nomes = ['Centro', 'Porto', 'Vila', 'Alto', 'Feira']
const tabela = [
  [0, 5, 2, 8, 7],
  [8, 0, 10, 3, 2],
  [11, 3, 0, 6, 5],
  [5, 10, 7, 0, 12],
  [6, 11, 8, 1, 0],
]
const XT = 1030
const YT = 150
const CEL = 96
const LIN = 96

export const ideia = {
  caixas: [
    {
      id: 'g',
      forma: 'grafo',
      dirigido: true,
      x: 100,
      y: 80,
      raio: 62,
      vertices: [
        ['Centro', 70, 330],
        ['Vila', 380, 500],
        ['Porto', 380, 80],
        ['Feira', 760, 500],
        ['Alto', 760, 80],
      ],
      arestas: [
        ['Centro', 'Vila', 2],
        ['Vila', 'Porto', 3],
        ['Centro', 'Porto', 6],
        ['Porto', 'Alto', 4],
        ['Alto', 'Centro', 5],
        ['Vila', 'Feira', 7],
        ['Feira', 'Alto', 1],
        ['Porto', 'Feira', 2],
      ],
      estados: { Centro: 'roxo', Alto: 'verde' },
      marcadas: [
        ['Centro', 'Vila'],
        ['Vila', 'Porto'],
        ['Porto', 'Feira'],
        ['Feira', 'Alto'],
      ],
    },
    ...tabela.map((linha, i) => ({
      id: `l${i}`,
      forma: 'array',
      x: XT,
      y: YT + i * LIN,
      itens: linha,
      celula: CEL,
      indices: false,
      estados: i === 0 ? { 0: 'verde', 1: 'verde', 2: 'verde', 3: 'verde', 4: 'verde' } : {},
    })),
  ],
  notas: [
    ...nomes.map((n, j) => ({ x: XT + CEL / 2 + j * CEL, y: YT - 22, texto: n.slice(0, 4), cor: 'cinza', ancora: 'middle', tam: 22 })),
    ...nomes.map((n, i) => ({ x: XT - 18, y: YT + i * LIN + 52, texto: n, cor: 'cinza', ancora: 'end', tam: 22 })),
    { x: 1030, y: 680, texto: 'd[Centro][Alto] = 8', cor: 'verde' },
    { x: 1030, y: 718, texto: '= 2 + 3 + 2 + 1', cor: 'verde' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'proc', 'd = ruas diretas (0 na diagonal, INFINITO sem rua)'],
    ['C', 'dec', 'Ainda tem k?'],
    ['D', 'dec', 'Ainda tem par (i, j)?'],
    ['E', 'dec', 'd[i][k] + d[k][j] < d[i][j]?'],
    ['F', 'proc', 'd[i][j] = d[i][k] + d[k][j]'],
    ['G', 'io', 'Mostrar a tabela'],
    ['H', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D', 'Sim'],
    ['D', 'E', 'Sim'],
    ['E', 'F', 'Sim'],
    ['E', 'D', 'Não'],
    ['F', 'D'],
    ['D', 'C', 'Não'],
    ['C', 'G', 'Não'],
    ['G', 'H'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'F', 'D', 'E', 'D', 'C', 'G', 'H'],
}
