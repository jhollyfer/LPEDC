// o mesmo grupo visto três vezes: independente em G, clique no complemento,
// e o resto como cobertura de G
const pos = [
  ['Jorge', 70, 0],
  ['Rita', 270, 0],
  ['Kátia', 0, 200],
  ['Léo', 340, 200],
  ['Nina', 70, 400],
  ['Márcio', 270, 400],
]
const brigas = [
  ['Jorge', 'Rita'],
  ['Jorge', 'Kátia'],
  ['Rita', 'Léo'],
  ['Kátia', 'Léo'],
  ['Léo', 'Márcio'],
  ['Márcio', 'Nina'],
  ['Kátia', 'Nina'],
]
const paz = [
  ['Jorge', 'Léo'],
  ['Jorge', 'Nina'],
  ['Jorge', 'Márcio'],
  ['Rita', 'Kátia'],
  ['Rita', 'Nina'],
  ['Rita', 'Márcio'],
  ['Kátia', 'Márcio'],
  ['Léo', 'Nina'],
]
const comissao = { Rita: 'verde', Kátia: 'verde', Márcio: 'verde' }

export const ideia = {
  caixas: [
    { id: 'g', forma: 'grafo', x: 160, y: 150, raio: 56, vertices: pos, arestas: brigas, estados: { ...comissao, Jorge: 'apagado', Léo: 'apagado', Nina: 'apagado' } },
    {
      id: 'c',
      forma: 'grafo',
      x: 670,
      y: 150,
      raio: 56,
      vertices: pos,
      arestas: paz,
      estados: { ...comissao, Jorge: 'apagado', Léo: 'apagado', Nina: 'apagado' },
      marcadas: [
        ['Rita', 'Kátia'],
        ['Rita', 'Márcio'],
        ['Kátia', 'Márcio'],
      ],
    },
    {
      id: 'k',
      forma: 'grafo',
      x: 1180,
      y: 150,
      raio: 56,
      vertices: pos,
      arestas: brigas,
      estados: { Jorge: 'roxo', Léo: 'roxo', Nina: 'roxo', Rita: 'apagado', Kátia: 'apagado', Márcio: 'apagado' },
    },
  ],
  notas: [
    { x: 100, y: 660, texto: 'G (brigas)', cor: 'azul' },
    { x: 100, y: 698, texto: 'independente: sem arestas', cor: 'verde', tam: 22 },
    { x: 610, y: 660, texto: 'complemento (paz)', cor: 'azul' },
    { x: 610, y: 698, texto: 'o mesmo grupo é clique', cor: 'verde', tam: 22 },
    { x: 1120, y: 660, texto: 'G de novo', cor: 'azul' },
    { x: 1120, y: 698, texto: 'V - S cobre toda briga', cor: 'roxo', tam: 22 },
    { x: 100, y: 770, texto: 'independente de tamanho k  <=>  clique de tamanho k no complemento  <=>  cobertura de tamanho n - k', cor: 'roxo', tam: 24 },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'io', 'Brigas (grafo G)'],
    ['C', 'dec', 'Próximo par (a, b)?'],
    ['D', 'proc', 'Liga a e b se não brigaram'],
    ['E', 'proc', 'Chama maior_clique(paz)'],
    ['F', 'io', 'Clique = comissão'],
    ['G', 'proc', 'Cobertura = todos menos a comissão'],
    ['H', 'io', 'Mediadores'],
    ['I', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D', 'Sim'],
    ['D', 'C'],
    ['C', 'E', 'Não'],
    ['E', 'F'],
    ['F', 'G'],
    ['G', 'H'],
    ['H', 'I'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'C', 'E', 'F', 'G', 'H', 'I'],
}
