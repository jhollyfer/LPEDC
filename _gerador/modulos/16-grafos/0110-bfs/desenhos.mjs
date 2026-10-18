// as ondas da BFS da esquerda para a direita: distância 0, 1, 2 e 3
export const ideia = {
  caixas: [
    {
      id: 'g',
      forma: 'grafo',
      x: 100,
      y: 60,
      raio: 50,
      vertices: [
        ['Lia', 60, 250],
        ['Max', 360, 110],
        ['Nina', 360, 390],
        ['Otto', 660, 110],
        ['Pedro', 660, 390],
        ['Rita', 960, 250],
      ],
      arestas: [
        ['Lia', 'Max'],
        ['Lia', 'Nina'],
        ['Max', 'Otto'],
        ['Nina', 'Otto'],
        ['Nina', 'Pedro'],
        ['Otto', 'Rita'],
        ['Pedro', 'Rita'],
      ],
      estados: { Lia: 'roxo', Rita: 'verde' },
      marcadas: [
        ['Lia', 'Max'],
        ['Lia', 'Nina'],
        ['Max', 'Otto'],
        ['Nina', 'Pedro'],
        ['Otto', 'Rita'],
      ],
      notas: { Lia: 'dist 0', Max: 'dist 1', Nina: 'dist 1', Otto: 'dist 2', Pedro: 'dist 2', Rita: 'dist 3' },
    },
    {
      id: 'f',
      forma: 'array',
      x: 250,
      y: 610,
      nome: 'fila',
      itens: ['Lia', 'Max', 'Nina', 'Otto', 'Pedro', 'Rita'],
      celula: 130,
      estados: { 0: 'roxo', 5: 'verde' },
    },
  ],
  notas: [
    { x: 1080, y: 690, texto: 'sai pela frente,', cor: 'cinza' },
    { x: 1080, y: 728, texto: 'entra no fim', cor: 'cinza' },
    { x: 1200, y: 250, texto: 'Lia -> Max ->', cor: 'verde' },
    { x: 1200, y: 290, texto: 'Otto -> Rita', cor: 'verde' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'proc', 'dist = -1 em todos; dist[Lia] = 0'],
    ['C', 'proc', 'Pôr Lia na fila'],
    ['D', 'dec', 'A fila esvaziou?'],
    ['E', 'proc', 'Tirar u da frente da fila'],
    ['F', 'proc', 'Vizinho v com dist -1: dist[v] = dist[u] + 1, pai[v] = u, v na fila'],
    ['G', 'io', 'Mostrar dist e o caminho até Rita'],
    ['H', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D'],
    ['D', 'E', 'Não'],
    ['E', 'F'],
    ['F', 'D'],
    ['D', 'G', 'Sim'],
    ['G', 'H'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'F', 'D', 'G', 'H'],
}
