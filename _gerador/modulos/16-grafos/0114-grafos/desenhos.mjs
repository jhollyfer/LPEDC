// a matriz: uma fileira de gavetas por vértice; 1 em verde na linha da Feira
const adj = [
  [0, 1, 1, 0, 0],
  [1, 0, 1, 0, 0],
  [1, 1, 0, 1, 0],
  [0, 0, 1, 0, 1],
  [0, 0, 0, 1, 0],
]
const X0 = 1040
const Y0 = 110
const linhas = adj.map((linha, i) => ({
  id: `l${i}`,
  forma: 'array',
  x: X0,
  y: Y0 + i * 84,
  itens: linha,
  indices: false,
  celula: 70,
  estados: Object.fromEntries(linha.map((v, j) => [j, v ? (i === 2 ? 'verde' : 'azul') : 'apagado'])),
}))

export const ideia = {
  caixas: [
    {
      id: 'g',
      forma: 'grafo',
      x: 100,
      y: 60,
      raio: 58,
      vertices: [
        ['Centro', 70, 230],
        ['Praia', 300, 80],
        ['Feira', 300, 400],
        ['Parque', 540, 400],
        ['Estadio', 760, 230],
      ],
      arestas: [
        ['Centro', 'Praia'],
        ['Centro', 'Feira'],
        ['Praia', 'Feira'],
        ['Feira', 'Parque'],
        ['Parque', 'Estadio'],
      ],
      estados: { Feira: 'verde' },
      marcadas: [
        ['Feira', 'Centro'],
        ['Feira', 'Praia'],
        ['Feira', 'Parque'],
      ],
    },
    ...linhas,
  ],
  notas: [
    { x: X0 + 175, y: Y0 - 50, texto: 'int adj[5][5]', cor: 'roxo', ancora: 'middle' },
    ...[0, 1, 2, 3, 4].map((j) => ({ x: X0 + 35 + j * 70, y: Y0 - 12, texto: String(j), cor: 'cinza', ancora: 'middle' })),
    ...[0, 1, 2, 3, 4].map((i) => ({ x: X0 - 16, y: Y0 + 52 + i * 84, texto: String(i), cor: 'cinza', ancora: 'end' })),
    { x: X0 + 370, y: Y0 + 52 + 2 * 84, texto: 'grau 3', cor: 'verde' },
    { x: 400, y: 580, texto: 'Feira tem 3 vizinhos', cor: 'verde', ancora: 'middle' },
    { x: X0 + 175, y: Y0 + 470, texto: 'espelhada na diagonal', cor: 'cinza', ancora: 'middle' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'proc', 'Zerar a matriz adj[5][5]'],
    ['C', 'dec', 'Ainda tem ciclovia?'],
    ['D', 'proc', 'adj[a][b] = 1 e adj[b][a] = 1'],
    ['E', 'proc', 'Grau = soma de cada linha'],
    ['F', 'io', 'Mostrar a matriz e os graus'],
    ['G', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D', 'Sim'],
    ['D', 'C'],
    ['C', 'E', 'Não'],
    ['E', 'F'],
    ['F', 'G'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'C', 'E', 'F', 'G'],
}
