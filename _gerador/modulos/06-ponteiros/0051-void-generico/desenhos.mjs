export const ideia = {
  caixas: [
    {
      id: 'main',
      forma: 'memoria',
      x: 120,
      y: 80,
      celula: 90,
      titulo: 'frame do main',
      celulas: [
        { end: '0x1000', nome: 'senha_a', valor: '17 → 42', tipo: 'int · 4 bytes', cor: 'verde' },
        { end: '0x1004', nome: 'senha_b', valor: '42 → 17', tipo: 'int · 4 bytes', cor: 'verde' },
        { end: '0x1008', nome: 'preco_a', valor: '12.90', tipo: 'double · 8 bytes', cor: 'cinza' },
        { end: '0x1010', nome: 'preco_b', valor: '8.50', tipo: 'double · 8 bytes', cor: 'cinza' },
      ],
    },
    {
      id: 'tg',
      forma: 'memoria',
      x: 1000,
      y: 80,
      celula: 90,
      cor: 'roxo',
      titulo: 'troca_generica (1ª chamada)',
      celulas: [
        { end: '0x2000', nome: 'a', valor: '0x1000', tipo: 'void *' },
        { end: '0x2008', nome: 'b', valor: '0x1004', tipo: 'void *' },
        { end: '0x2010', nome: 'tam', valor: '4', tipo: 'size_t', cor: 'azul' },
      ],
    },
    {
      id: 'n',
      x: 1000,
      y: 420,
      w: 440,
      cor: 'amarelo',
      texto: ['void * não sabe o tipo:', 'tam diz quantos bytes', 'trocar, um por um'],
    },
  ],
  setas: [
    { pontos: [[990, 125], [720, 125]] },
    { pontos: [[990, 215], [720, 215]] },
  ],
  notas: [{ x: 300, y: 500, texto: '2ª chamada: a, b nos preços, tam = 8', cor: 'cinza', tam: 22 }],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'io', 'Recebe a, b e tam (4)'],
    ['C', 'proc', 'x = a; y = b; i = 0'],
    ['D', 'dec', 'i < tam?'],
    ['E', 'proc', 'troca x[i] e y[i]'],
    ['F', 'proc', 'i++'],
    ['G', 'io', 'Mostrar senhas: 42 e 17'],
    ['H', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D'],
    ['D', 'E', 'Sim'],
    ['E', 'F'],
    ['F', 'D'],
    ['D', 'G', 'Não'],
    ['G', 'H'],
  ],
}
