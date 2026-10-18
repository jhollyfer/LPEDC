// o mapa da transportadora: verde = rota do Dijkstra (10 km);
// a BFS prefere CD -> Centro -> Vila (2 trechos, 16 km); a Ilha fica de fora
export const ideia = {
  caixas: [
    {
      id: 'g',
      forma: 'grafo',
      x: 100,
      y: 60,
      raio: 56,
      vertices: [
        ['CD', 60, 270],
        ['Centro', 320, 100],
        ['Feira', 320, 440],
        ['Morro', 600, 440],
        ['Porto', 840, 300],
        ['Vila', 1100, 100],
        ['Ilha', 1100, 460],
      ],
      arestas: [
        ['CD', 'Centro', 4],
        ['CD', 'Feira', 2],
        ['Feira', 'Centro', 1],
        ['Centro', 'Porto', 7],
        ['Feira', 'Morro', 3],
        ['Morro', 'Porto', 2],
        ['Porto', 'Vila', 3],
        ['Centro', 'Vila', 12],
      ],
      estados: { CD: 'roxo', Vila: 'verde', Ilha: 'apagado' },
      marcadas: [
        ['CD', 'Feira'],
        ['Feira', 'Morro'],
        ['Morro', 'Porto'],
        ['Porto', 'Vila'],
      ],
    },
  ],
  notas: [
    { x: 160, y: 680, texto: 'DFS: alcança 6 de 7 (a Ilha só tem balsa)', cor: 'cinza' },
    { x: 160, y: 725, texto: 'BFS: CD -> Centro -> Vila = 2 trechos, 16 km', cor: 'vermelho' },
    { x: 160, y: 770, texto: 'Dijkstra: CD -> Feira -> Morro -> Porto -> Vila = 4 trechos, 10 km', cor: 'verde' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'proc', 'Montar o Grafo (struct + matriz de km)'],
    ['C', 'proc', 'DFS a partir do CD'],
    ['D', 'dec', 'A Vila foi alcançada?'],
    ['E', 'proc', 'BFS: rota com menos trechos'],
    ['F', 'proc', 'Dijkstra: rota com menos km'],
    ['G', 'io', 'Mostrar as duas rotas'],
    ['H', 'io', 'Mostrar "sem rota"'],
    ['I', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D'],
    ['D', 'E', 'Sim'],
    ['D', 'H', 'Não'],
    ['E', 'F'],
    ['F', 'G'],
    ['G', 'I'],
    ['H', 'I'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'I'],
}
