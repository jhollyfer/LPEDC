export const ideia = {
  caixas: [
    {
      id: 'main',
      forma: 'memoria',
      x: 150,
      y: 100,
      celula: 90,
      titulo: 'frame do main',
      celulas: [
        { end: '0x1000', nome: 'arroz', valor: '8 → 25', tipo: 'int', cor: 'verde' },
        { end: '0x1004', nome: 'feijao', valor: '25 → 8', tipo: 'int', cor: 'verde' },
      ],
    },
    {
      id: 'troca',
      forma: 'memoria',
      x: 920,
      y: 100,
      celula: 90,
      cor: 'roxo',
      titulo: 'frame de troca',
      celulas: [
        { end: '0x2000', nome: 'a', valor: '0x1000', tipo: 'int *' },
        { end: '0x2008', nome: 'b', valor: '0x1004', tipo: 'int *' },
        { end: '0x2010', nome: 'tmp', valor: '8', tipo: 'int', cor: 'cinza' },
      ],
    },
    {
      id: 'ch',
      x: 150,
      y: 400,
      w: 540,
      cor: 'azul',
      rotulo: 'a chamada',
      texto: ['troca(&arroz, &feijao);'],
    },
  ],
  setas: [
    { pontos: [[910, 145], [600, 145]], rotulo: '*a' },
    { pontos: [[910, 235], [600, 235]], rotulo: '*b' },
    { pontos: [[700, 470], [1060, 470], [1060, 350]], rotulo: 'copia os endereços', cor: 'azul' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'proc', 'arroz = 8; feijao = 25'],
    ['C', 'dec', 'arroz < feijao?'],
    ['D', 'proc', 'troca(&arroz, &feijao)'],
    ['E', 'proc', 'tmp = *a'],
    ['F', 'proc', '*a = *b; *b = tmp'],
    ['G', 'io', 'Mostrar arroz 25, feijão 8'],
    ['H', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D', 'Sim'],
    ['D', 'E'],
    ['E', 'F'],
    ['F', 'G'],
    ['C', 'G', 'Não'],
    ['G', 'H'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'],
}
