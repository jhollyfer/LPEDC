// a planilha da reforma: dois grupos independentes (componentes) e, no
// grupo do financiamento, a seta Parcela -> Juros chegando num vértice cinza.
// verde = preto (terminado), amarelo = cinza (na pilha); números = ordem da DFS
export const ideia = {
  caixas: [
    {
      id: 'obra',
      forma: 'grafo',
      dirigido: true,
      x: 120,
      y: 150,
      raio: 64,
      vertices: [
        ['Total', 70, 230],
        ['Obra', 320, 80],
        ['Tinta', 600, 80],
        ['Piso', 600, 370],
        ['Frete', 320, 420],
      ],
      arestas: [
        ['Total', 'Obra'],
        ['Total', 'Frete'],
        ['Obra', 'Tinta'],
        ['Obra', 'Piso'],
        ['Piso', 'Frete'],
      ],
      estados: { Total: 'verde', Obra: 'verde', Tinta: 'verde', Piso: 'verde', Frete: 'verde' },
      notas: { Total: '1', Obra: '2', Tinta: '3', Piso: '4', Frete: '5' },
    },
    {
      id: 'fin',
      forma: 'grafo',
      dirigido: true,
      x: 960,
      y: 150,
      raio: 64,
      vertices: [
        ['Juros', 70, 80],
        ['Saldo', 420, 80],
        ['Parcela', 245, 400],
      ],
      arestas: [
        ['Juros', 'Saldo'],
        ['Saldo', 'Parcela'],
        ['Parcela', 'Juros'],
      ],
      estados: { Juros: 'amarelo', Saldo: 'amarelo', Parcela: 'amarelo' },
      notas: { Juros: '6', Saldo: '7', Parcela: '8' },
    },
    {
      id: 'leg',
      x: 120,
      y: 770,
      w: 1340,
      h: 110,
      cor: 'cinza',
      texto: ['branco: nunca visto    amarelo (cinza): na pilha    verde (preto): terminado'],
    },
  ],
  notas: [
    { x: 120, y: 660, texto: 'grupo 1: orçamento da obra', cor: 'azul' },
    { x: 960, y: 660, texto: 'grupo 2: financiamento', cor: 'azul' },
    { x: 1290, y: 540, texto: 'Parcela -> Juros:', cor: 'vermelho' },
    { x: 1290, y: 578, texto: 'Juros é cinza', cor: 'vermelho' },
    { x: 1290, y: 616, texto: '= ciclo', cor: 'vermelho' },
    { x: 120, y: 710, texto: 'Total -> Frete chega num preto: não é ciclo', cor: 'verde' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'acha_ciclo(u)'],
    ['B', 'proc', 'cor[u] = CINZA'],
    ['C', 'dec', 'Tem vizinho v?'],
    ['D', 'dec', 'cor[v] == CINZA?'],
    ['E', 'dec', 'cor[v] == BRANCO?'],
    ['F', 'proc', 'pai[v] = u; acha_ciclo(v)'],
    ['G', 'io', 'Mostrar o ciclo pelos pais'],
    ['H', 'proc', 'cor[u] = PRETO'],
    ['I', 'inicio', 'Volta'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D', 'Sim'],
    ['D', 'G', 'Sim'],
    ['D', 'E', 'Não'],
    ['E', 'F', 'Sim'],
    ['E', 'C', 'Não'],
    ['F', 'C'],
    ['C', 'H', 'Não'],
    ['G', 'I'],
    ['H', 'I'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'F', 'C', 'D', 'G', 'I'],
}
