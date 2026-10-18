// pesos em minutos; em cima de cada lugar, a dist final; verde = rota até a Praia
const nomes = ['Casa', 'Escola', 'Padaria', 'Mercado', 'Praia']
const XA = 300
const CEL = 150

export const ideia = {
  caixas: [
    {
      id: 'g',
      forma: 'grafo',
      x: 100,
      y: 60,
      raio: 68,
      vertices: [
        ['Casa', 70, 260],
        ['Padaria', 450, 90],
        ['Escola', 300, 430],
        ['Mercado', 720, 430],
        ['Praia', 1010, 260],
      ],
      arestas: [
        ['Casa', 'Padaria', 4],
        ['Casa', 'Escola', 1],
        ['Escola', 'Padaria', 2],
        ['Padaria', 'Mercado', 5],
        ['Escola', 'Mercado', 8],
        ['Mercado', 'Praia', 3],
        ['Padaria', 'Praia', 10],
      ],
      estados: { Casa: 'roxo', Praia: 'verde' },
      marcadas: [
        ['Casa', 'Escola'],
        ['Escola', 'Padaria'],
        ['Padaria', 'Mercado'],
        ['Mercado', 'Praia'],
      ],
      notas: { Casa: '0', Escola: '1', Padaria: '3', Mercado: '8', Praia: '11' },
    },
    {
      id: 'd',
      forma: 'array',
      x: XA,
      y: 680,
      nome: 'dist',
      itens: ['0', '1', '3', '8', '11'],
      celula: CEL,
      indices: false,
      estados: { 4: 'verde' },
    },
  ],
  notas: [
    ...nomes.map((n, i) => ({ x: XA + CEL / 2 + i * CEL, y: 860, texto: n, cor: 'cinza', ancora: 'middle' })),
    { x: 1150, y: 520, texto: '11 min:', cor: 'verde' },
    { x: 1150, y: 558, texto: '1 + 2 + 5 + 3', cor: 'verde' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'proc', 'dist = INFINITO; dist[Casa] = 0'],
    ['C', 'proc', 'u = não fixo de menor dist'],
    ['D', 'dec', 'Achou u (dist finita)?'],
    ['E', 'proc', 'Fixar u'],
    ['F', 'proc', 'Relaxar: dist[u] + peso < dist[v]? atualiza dist e anterior'],
    ['G', 'io', 'Mostrar dist e a rota até a Praia'],
    ['H', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D'],
    ['D', 'E', 'Sim'],
    ['E', 'F'],
    ['F', 'C'],
    ['D', 'G', 'Não'],
    ['G', 'H'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'F', 'C', 'D', 'G', 'H'],
}
