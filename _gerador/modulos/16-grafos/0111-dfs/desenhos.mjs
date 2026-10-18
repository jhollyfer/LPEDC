// a DFS a partir da Sede: números = ordem da visita; verde = árvore da DFS
export const ideia = {
  caixas: [
    {
      id: 'g',
      forma: 'grafo',
      x: 100,
      y: 60,
      raio: 50,
      vertices: [
        ['Sede', 80, 90],
        ['Lago', 340, 90],
        ['Gruta', 600, 90],
        ['Ponte', 300, 450],
        ['Topo', 470, 330],
        ['Bica', 730, 450],
      ],
      arestas: [
        ['Sede', 'Lago'],
        ['Sede', 'Ponte'],
        ['Lago', 'Gruta'],
        ['Lago', 'Topo'],
        ['Gruta', 'Topo'],
        ['Topo', 'Bica'],
      ],
      estados: { Sede: 'roxo', Ponte: 'verde' },
      marcadas: [
        ['Sede', 'Lago'],
        ['Lago', 'Gruta'],
        ['Gruta', 'Topo'],
        ['Topo', 'Bica'],
        ['Sede', 'Ponte'],
      ],
      notas: { Sede: '1º', Lago: '2º', Gruta: '3º', Topo: '4º', Bica: '5º', Ponte: '6º' },
    },
    {
      id: 'p',
      forma: 'pilha',
      x: 1000,
      y: 60,
      itens: ['main()', 'dfs(Sede)', 'dfs(Lago)', 'dfs(Gruta)', 'dfs(Topo)', 'dfs(Bica)'],
      estados: { 0: 'cinza', 5: 'verde' },
      topo: 'topo',
      titulo: 'pilha de chamadas',
    },
  ],
  notas: [
    { x: 478, y: 262, texto: 'retorno', cor: 'cinza', ancora: 'end' },
    { x: 180, y: 600, texto: 'a Ponte fica por último:', cor: 'verde' },
    { x: 180, y: 638, texto: 'só depois de voltar à Sede', cor: 'verde' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'proc', 'Chamar dfs(Sede)'],
    ['C', 'proc', 'Marcar u e mostrar'],
    ['D', 'dec', 'u tem vizinho não visitado?'],
    ['E', 'proc', 'Descer: dfs(vizinho)'],
    ['F', 'dec', 'u é a Sede?'],
    ['G', 'proc', 'Voltar para quem chamou'],
    ['H', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D'],
    ['D', 'E', 'Sim'],
    ['E', 'C'],
    ['D', 'F', 'Não'],
    ['F', 'G', 'Não'],
    ['G', 'D'],
    ['F', 'H', 'Sim'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'C', 'D', 'F', 'G', 'D', 'F', 'H'],
}
