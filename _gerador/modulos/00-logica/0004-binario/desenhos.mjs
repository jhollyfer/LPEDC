export const ideia = {
  caixas: [
    { id: 'n', forma: 'caixinha', x: 100, y: 40, nome: 'n', valor: '13', tipo: 'decimal' },
    { id: 'b', forma: 'array', x: 520, y: 70, itens: ['1', '1', '0', '1'], indices: false, celula: 120, estados: { 2: 'apagado' } },
    { id: 's', x: 520, y: 300, w: 480, h: 110, cor: 'verde', texto: ['8 + 4 + 0 + 1 = 13'] },
    { id: 'h', forma: 'terminal', x: 1120, y: 70, w: 300, texto: ['0xD'] },
  ],
  setas: [
    { de: 'n', para: 'b' },
    { de: 'b', para: 's', rotulo: 'some as casas com 1' },
    { de: 'b', para: 'h', rotulo: 'em hexa' },
  ],
  notas: [
    { x: 580, y: 60, texto: '8', cor: 'roxo', ancora: 'middle' },
    { x: 700, y: 60, texto: '4', cor: 'roxo', ancora: 'middle' },
    { x: 820, y: 60, texto: '2', cor: 'cinza', ancora: 'middle' },
    { x: 940, y: 60, texto: '1', cor: 'roxo', ancora: 'middle' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'io', 'Ler n (13)'],
    ['C', 'proc', 'casa = 8'],
    ['D', 'dec', 'casa >= 1?'],
    ['E', 'dec', 'n >= casa?'],
    ['F', 'proc', 'anota 1; n = n - casa'],
    ['G', 'proc', 'anota 0'],
    ['H', 'proc', 'casa = casa / 2'],
    ['I', 'io', 'Mostrar os bits: 1101'],
    ['J', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D'],
    ['D', 'E', 'Sim'],
    ['E', 'F', 'Sim'],
    ['E', 'G', 'Não'],
    ['F', 'H'],
    ['G', 'H'],
    ['H', 'D'],
    ['D', 'I', 'Não'],
    ['I', 'J'],
  ],
}
