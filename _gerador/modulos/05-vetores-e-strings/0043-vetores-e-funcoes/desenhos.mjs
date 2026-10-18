export const ideia = {
  caixas: [
    { id: 'fm', x: 100, y: 0, w: 680, h: 360, cor: 'cinza', rotulo: 'main', texto: [] },
    {
      id: 'v',
      forma: 'array',
      x: 140,
      y: 110,
      itens: ['13.75', '8.80', '25.19', '6.05'],
      celula: 150,
      estados: { 0: 'verde', 1: 'verde', 2: 'verde', 3: 'verde' },
    },
    { id: 'ff', x: 980, y: 0, w: 520, h: 520, cor: 'roxo', rotulo: 'reajustar', texto: [] },
    { id: 'p', forma: 'caixinha', x: 1020, y: 90, nome: 'precos', valor: 'endereço', tipo: 'de cardapio[0]', w: 260, cor: 'roxo' },
    { id: 'n', forma: 'caixinha', x: 1020, y: 310, nome: 'n', valor: '4', w: 180, cor: 'roxo' },
    { id: 'pc', forma: 'caixinha', x: 1240, y: 310, nome: 'percentual', valor: '10', w: 220, cor: 'roxo' },
  ],
  setas: [
    { pontos: [[1004, 214], [880, 214], [880, -40], [215, -40], [215, 94]], rotulo: 'precos[i] é cardapio[i]', cor: 'roxo' },
  ],
  notas: [
    { x: 140, y: 280, texto: 'cardapio: antes 12.50  8.00  22.90  5.50', cor: 'cinza', tam: 24 },
    { x: 140, y: 320, texto: 'os 32 bytes ficam aqui', cor: 'cinza', tam: 24 },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início do main'],
    ['B', 'proc', 'cardapio = {12.50, 8.00, 22.90, 5.50}'],
    ['C', 'proc', 'chama reajustar(cardapio, 4, 10)'],
    ['D', 'dec', 'i < n?'],
    ['E', 'proc', 'precos[i] = precos[i] * 1.10'],
    ['F', 'proc', 'i++'],
    ['G', 'io', 'mostrar: 13.75 8.80 25.19 6.05'],
    ['H', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D', 'i = 0'],
    ['D', 'E', 'Sim'],
    ['E', 'F'],
    ['F', 'D'],
    ['D', 'G', 'Não'],
    ['G', 'H'],
  ],
}
