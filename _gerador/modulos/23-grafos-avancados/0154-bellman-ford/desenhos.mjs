// o mapa do motoboy: setas com o custo líquido (negativo = a corrida paga);
// em cima de cada lugar, a dist final; verde = rota até Casa.
// embaixo, o vetor dist nas rodadas 3 e 4
const XA = 330
const CEL = 150
const nomes = ['Base', 'Shopping', 'Centro', 'Faculdade', 'Hospital', 'Casa']

export const ideia = {
  caixas: [
    {
      id: 'g',
      forma: 'grafo',
      dirigido: true,
      x: 110,
      y: 70,
      raio: 80,
      vertices: [
        ['Base', 80, 260],
        ['Shopping', 330, 80],
        ['Centro', 480, 460],
        ['Faculdade', 740, 80],
        ['Hospital', 890, 460],
        ['Casa', 1150, 270],
      ],
      arestas: [
        ['Base', 'Shopping', 6],
        ['Base', 'Centro', 4],
        ['Shopping', 'Centro', -4],
        ['Centro', 'Hospital', 5],
        ['Shopping', 'Faculdade', 7],
        ['Faculdade', 'Hospital', -2],
        ['Hospital', 'Casa', 3],
        ['Faculdade', 'Casa', 6],
        ['Centro', 'Faculdade', 9],
      ],
      estados: { Base: 'roxo', Casa: 'verde' },
      marcadas: [
        ['Base', 'Shopping'],
        ['Shopping', 'Centro'],
        ['Centro', 'Hospital'],
        ['Hospital', 'Casa'],
      ],
      notas: { Base: '0', Shopping: '6', Centro: '2', Faculdade: '11', Hospital: '7', Casa: '10' },
    },
    {
      id: 'r3',
      forma: 'array',
      x: XA,
      y: 700,
      itens: [0, 6, 2, 11, 7, 12],
      celula: CEL,
      indices: false,
      estados: { 5: 'vermelho' },
    },
    {
      id: 'r4',
      forma: 'array',
      x: XA,
      y: 820,
      itens: [0, 6, 2, 11, 7, 10],
      celula: CEL,
      indices: false,
      estados: { 5: 'verde' },
    },
  ],
  notas: [
    { x: 110, y: 755, texto: 'rodada 3', cor: 'cinza' },
    { x: 110, y: 875, texto: 'rodada 4', cor: 'cinza' },
    ...nomes.map((n, i) => ({ x: XA + CEL / 2 + i * CEL, y: 960, texto: n, cor: 'cinza', ancora: 'middle', tam: 22 })),
    { x: 1260, y: 740, texto: '12: o mesmo erro', cor: 'vermelho' },
    { x: 1260, y: 776, texto: 'do Dijkstra', cor: 'vermelho' },
    { x: 1260, y: 870, texto: '10 = 6 - 4 + 5 + 3', cor: 'verde' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'proc', 'dist = INFINITO; dist[Base] = 0'],
    ['C', 'dec', 'Faltam rodadas (até V - 1)?'],
    ['D', 'proc', 'Relaxar todas as arestas'],
    ['E', 'dec', 'Alguma dist mudou?'],
    ['F', 'dec', 'Rodada extra ainda melhora?'],
    ['G', 'io', 'Avisar: ciclo negativo'],
    ['H', 'io', 'Mostrar dist e a rota'],
    ['I', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D', 'Sim'],
    ['D', 'E'],
    ['E', 'C', 'Sim'],
    ['E', 'F', 'Não'],
    ['C', 'F', 'Não'],
    ['F', 'G', 'Sim'],
    ['F', 'H', 'Não'],
    ['G', 'I'],
    ['H', 'I'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'C', 'D', 'E', 'F', 'H', 'I'],
}
