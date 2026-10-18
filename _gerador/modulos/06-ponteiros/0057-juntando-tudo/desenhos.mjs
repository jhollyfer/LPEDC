const y = (i) => 80 + i * 90 + 45
export const ideia = {
  caixas: [
    {
      id: 'fat',
      forma: 'memoria',
      x: 120,
      y: 80,
      celula: 90,
      titulo: 'double fat[4] (não muda)',
      celulas: [
        { end: '0x1000', nome: 'tomate', valor: '195.00', tipo: 'fat[0]' },
        { end: '0x1008', nome: 'alface', valor: '135.00', tipo: 'fat[1]' },
        { end: '0x1010', nome: 'queijo', valor: '256.00', tipo: 'fat[2]' },
        { end: '0x1018', nome: 'pastel', valor: '540.00', tipo: 'fat[3]', cor: 'verde' },
      ],
    },
    {
      id: 'ord',
      forma: 'memoria',
      x: 1000,
      y: 80,
      celula: 90,
      cor: 'roxo',
      titulo: 'ordem[4] depois do qsort',
      celulas: [
        { end: '1º', nome: 'ordem[0]', valor: '0x1018' },
        { end: '2º', nome: 'ordem[1]', valor: '0x1010' },
        { end: '3º', nome: 'ordem[2]', valor: '0x1000' },
        { end: '4º', nome: 'ordem[3]', valor: '0x1008' },
      ],
    },
    {
      id: 'k',
      x: 120,
      y: 520,
      w: 1260,
      h: 110,
      cor: 'verde',
      texto: ['ordem[0] - fat = 3   →   produtos[3] = "pastel", R$ 540.00'],
    },
  ],
  setas: [
    { pontos: [[985, y(0)], [700, y(3)]] },
    { pontos: [[985, y(1)], [700, y(2)]] },
    { pontos: [[985, y(2)], [700, y(0)]] },
    { pontos: [[985, y(3)], [700, y(1)]] },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'proc', 'fat[i] = qtd[i] * preco[i]; ordem[i] = &fat[i]'],
    ['C', 'proc', 'qsort(ordem, maior_primeiro); i = 0'],
    ['D', 'dec', 'i < 4?'],
    ['E', 'proc', 'k = ordem[i] - fat'],
    ['F', 'io', 'Mostrar produtos[k] e *ordem[i]'],
    ['G', 'io', 'Mostrar total 1126.00 e campeão'],
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
