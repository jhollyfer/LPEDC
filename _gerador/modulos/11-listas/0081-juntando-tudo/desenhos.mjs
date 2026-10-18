export const ideia = {
  caixas: [
    {
      id: 'tela',
      forma: 'cardapio',
      x: 100,
      y: 40,
      w: 560,
      titulo: 'PLAYLIST DA VIAGEM',
      destaque: 3,
      itens: [
        ['1', 'Aquarela  4:12'],
        ['2', 'Mas Que Nada  3:02'],
        ['3', 'Evidências  4:39'],
        ['4', 'Tempo Perdido  5:02'],
      ],
    },
    {
      id: 'l',
      forma: 'lista',
      x: 800,
      y: 150,
      dupla: true,
      itens: ['1', '2', '3', '4'],
      celula: 50,
      vao: 40,
      estados: { 3: 'verde' },
      rotulos: { 0: 'inicio', 3: 'atual = fim' },
    },
    { id: 'p', x: 800, y: 390, w: 620, cor: 'roxo', rotulo: 'struct playlist (escondida)', texto: ['inicio, fim, atual, tamanho, repetir'] },
  ],
  setas: [{ pontos: [[1417, 262], [1417, 310], [871, 310], [871, 270]], rotulo: 'próxima com repetir: volta ao 1', cor: 'verde', dy: 34 }],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início: próxima'],
    ['B', 'dec', 'atual->prox != NULL?'],
    ['C', 'proc', 'atual = atual->prox'],
    ['D', 'dec', 'repetir ligado?'],
    ['E', 'proc', 'atual = inicio'],
    ['F', 'io', 'Devolve NULL: fim da playlist'],
    ['G', 'io', 'Devolve a música atual'],
    ['H', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C', 'Sim'],
    ['B', 'D', 'Não'],
    ['D', 'E', 'Sim'],
    ['D', 'F', 'Não'],
    ['C', 'G'],
    ['E', 'G'],
    ['F', 'H'],
    ['G', 'H'],
  ],
  caminho: ['A', 'B', 'D', 'E', 'G', 'H'],
}
