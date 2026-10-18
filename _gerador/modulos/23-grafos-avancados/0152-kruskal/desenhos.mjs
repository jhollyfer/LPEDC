// as seis vilas e os nove trechos (R$ mil); verde = aceita pelo Kruskal.
// embaixo, a lista ordenada: verde aceita, vermelho fecha ciclo, cinza não olhada
const XA = 130
const CEL = 150
const rotulos = ['Ser-Lag', 'Pon-Bre', 'Sed-Bre', 'Pon-Ser', 'Sed-Pon', 'Ser-Val', 'Lag-Val', 'Bre-Ser', 'Pon-Lag']

export const ideia = {
  caixas: [
    {
      id: 'g',
      forma: 'grafo',
      x: 120,
      y: 60,
      raio: 62,
      vertices: [
        ['Sede', 80, 300],
        ['Brejo', 380, 470],
        ['Ponte', 380, 120],
        ['Serra', 720, 300],
        ['Lagoa', 1030, 120],
        ['Vale', 1030, 470],
      ],
      arestas: [
        ['Sede', 'Brejo', 4],
        ['Ponte', 'Brejo', 3],
        ['Sede', 'Ponte', 6],
        ['Brejo', 'Serra', 8],
        ['Ponte', 'Serra', 5],
        ['Ponte', 'Lagoa', 9],
        ['Serra', 'Lagoa', 2],
        ['Serra', 'Vale', 7],
        ['Lagoa', 'Vale', 7],
      ],
      estados: { Sede: 'verde', Brejo: 'verde', Ponte: 'verde', Serra: 'verde', Lagoa: 'verde', Vale: 'verde' },
      marcadas: [
        ['Serra', 'Lagoa'],
        ['Ponte', 'Brejo'],
        ['Sede', 'Brejo'],
        ['Ponte', 'Serra'],
        ['Serra', 'Vale'],
      ],
    },
    {
      id: 'lista',
      forma: 'array',
      x: XA,
      y: 680,
      nome: 'arestas ordenadas por custo',
      itens: [2, 3, 4, 5, 6, 7, 7, 8, 9],
      celula: CEL,
      indices: false,
      estados: { 0: 'verde', 1: 'verde', 2: 'verde', 3: 'verde', 4: 'vermelho', 5: 'verde', 6: 'apagado', 7: 'apagado', 8: 'apagado' },
    },
  ],
  notas: [
    ...rotulos.map((r, i) => ({ x: XA + CEL / 2 + i * CEL, y: 860, texto: r, cor: 'cinza', ancora: 'middle', tam: 22 })),
    { x: 1280, y: 300, texto: 'total:', cor: 'verde' },
    { x: 1280, y: 338, texto: '2+3+4+5+7', cor: 'verde' },
    { x: 1280, y: 376, texto: '= R$ 21 mil', cor: 'verde' },
    { x: 130, y: 920, texto: 'Sede-Ponte (6): Sede e Ponte já estão ligadas pelo Brejo, então fecharia ciclo', cor: 'vermelho' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'proc', 'Ordenar as arestas por custo'],
    ['C', 'proc', 'Cada vértice no seu próprio grupo'],
    ['D', 'dec', 'Sobrou aresta e faltam arestas?'],
    ['E', 'proc', '(a, b) = próxima mais barata'],
    ['F', 'dec', 'acha(a) != acha(b)?'],
    ['G', 'proc', 'Aceita: une os grupos e soma o custo'],
    ['H', 'io', 'Mostrar a árvore e o total'],
    ['I', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D'],
    ['D', 'E', 'Sim'],
    ['E', 'F'],
    ['F', 'G', 'Sim'],
    ['F', 'D', 'Não'],
    ['G', 'D'],
    ['D', 'H', 'Não'],
    ['H', 'I'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'D', 'E', 'F', 'D', 'H', 'I'],
}
