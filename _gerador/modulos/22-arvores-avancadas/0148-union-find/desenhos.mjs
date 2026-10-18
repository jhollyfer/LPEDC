// A floresta do union-find: cada pessoa aponta para o pai, e a raiz (verde)
// representa o grupo. À esquerda, depois das sete amizades; à direita, depois
// das buscas por 3 (Duda) e 7 (Hugo), que comprimem o caminho.
const vertices = (dx) => [
  ['0', dx + 100, 60],
  ['1', dx + 20, 190],
  ['2', dx + 180, 190],
  ['3', dx + 180, 320],
  ['4', dx + 400, 60],
  ['5', dx + 320, 190],
  ['6', dx + 480, 190],
  ['7', dx + 480, 320],
]

export const ideia = {
  caixas: [
    {
      forma: 'grafo',
      id: 'antes',
      x: 140,
      y: 240,
      dirigido: true,
      vertices: vertices(0),
      arestas: [
        ['1', '0'],
        ['2', '0'],
        ['3', '2'],
        ['5', '4'],
        ['6', '4'],
        ['7', '6'],
      ],
      estados: { 0: 'verde', 4: 'verde', 3: 'amarelo', 7: 'amarelo' },
    },
    {
      forma: 'grafo',
      id: 'depois',
      x: 140,
      y: 240,
      dirigido: true,
      vertices: [
        ['0', 880, 60],
        ['1', 780, 210],
        ['2', 880, 210],
        ['3', 980, 210],
        ['4', 1240, 60],
        ['5', 1140, 210],
        ['6', 1240, 210],
        ['7', 1340, 210],
      ],
      arestas: [
        ['1', '0'],
        ['2', '0'],
        ['3', '0'],
        ['5', '4'],
        ['6', '4'],
        ['7', '4'],
      ],
      estados: { 0: 'verde', 4: 'verde', 3: 'roxo', 7: 'roxo' },
    },
    { forma: 'array', id: 'p1', x: 120, y: 680, nome: 'pai', itens: [0, 0, 0, 2, 4, 4, 4, 6], celula: 72, estados: { 3: 'amarelo', 7: 'amarelo' } },
    { forma: 'array', id: 'p2', x: 900, y: 680, nome: 'pai', itens: [0, 0, 0, 0, 4, 4, 4, 4], celula: 72, estados: { 3: 'roxo', 7: 'roxo' } },
  ],
  setas: [{ pontos: [[700, 480], [820, 480]], rotulo: 'acha(3), acha(7)', cor: 'roxo' }],
  notas: [
    { x: 100, y: 220, texto: 'DEPOIS DAS AMIZADES: 2 GRUPOS', cor: 'cinza' },
    { x: 880, y: 220, texto: 'DEPOIS DAS BUSCAS: CAMINHOS COMPRIMIDOS', cor: 'cinza' },
    { x: 120, y: 905, texto: '0 Ana · 1 Beto · 2 Caio · 3 Duda · 4 Edu · 5 Fia · 6 Gui · 7 Hugo', cor: 'cinza', tam: 24 },
    { x: 120, y: 945, texto: 'verde: raiz (o representante); a seta vai do filho para o pai', cor: 'verde', tam: 24 },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'uf_une(u, a, b)'],
    ['B', 'proc', 'ra = acha(a); rb = acha(b)'],
    ['C', 'dec', 'ra == rb?'],
    ['D', 'io', 'Já estavam juntos: false'],
    ['E', 'dec', 'tam[ra] < tam[rb]?'],
    ['F', 'proc', 'Troca ra e rb'],
    ['G', 'proc', 'pai[rb] = ra; tam[ra] += tam[rb]'],
    ['H', 'io', 'Juntou: true'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D', 'Sim'],
    ['C', 'E', 'Não'],
    ['E', 'F', 'Sim'],
    ['E', 'G', 'Não'],
    ['F', 'G'],
    ['G', 'H'],
  ],
  caminho: ['A', 'B', 'C', 'E', 'G', 'H'],
}
