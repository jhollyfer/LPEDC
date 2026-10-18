export const ideia = {
  caixas: [
    { id: 'cm', forma: 'caixinha', x: 120, y: 60, nome: 'c (no main)', valor: '0x5010', tipo: 'Cartao *', cor: 'roxo' },
    { id: 'cf', forma: 'caixinha', x: 120, y: 340, nome: 'c (em cobrar_passagem)', valor: '0x5010', tipo: 'Cartao *', cor: 'roxo' },
    {
      id: 'h',
      forma: 'memoria',
      x: 900,
      y: 140,
      w: 240,
      titulo: 'heap: um Cartao (48 bytes)',
      celulas: [
        { end: '0x5010', nome: 'titular', valor: '"Luana"', tipo: 'char[30]' },
        { end: '0x5030', nome: 'saldo', valor: '1.20', tipo: 'double', cor: 'verde' },
        { end: '0x5038', nome: 'viagens', valor: '2', tipo: 'int', cor: 'verde' },
      ],
    },
  ],
  setas: [
    { pontos: [[320, 180], [825, 180]], rotulo: 'aponta para o cartão' },
    { pontos: [[485, 465], [700, 465], [700, 200], [825, 200]], rotulo: 'o mesmo endereço', dx: -270 },
  ],
  notas: [
    { x: 260, y: 30, texto: 'pilha', cor: 'cinza', ancora: 'middle' },
    { x: 1080, y: 420, texto: ['c->saldo: 10.00 -> 5.60 -> 1.20', 'c->viagens: 0 -> 1 -> 2'], cor: 'verde', ancora: 'middle' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'proc', 'c = malloc; saldo = 10.00'],
    ['C', 'dec', 'i <= 3?'],
    ['D', 'dec', 'c->saldo < 4.40?'],
    ['E', 'proc', 'c->saldo -= 4.40; c->viagens++'],
    ['F', 'io', 'Saldo insuficiente'],
    ['L', 'io', 'Viagem liberada'],
    ['G', 'io', 'Luana fez 2 viagens'],
    ['H', 'proc', 'free(c)'],
    ['I', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D', 'Sim'],
    ['D', 'E', 'Não'],
    ['D', 'F', 'Sim'],
    ['E', 'L'],
    ['L', 'C'],
    ['F', 'C'],
    ['C', 'G', 'Não'],
    ['G', 'H'],
    ['H', 'I'],
  ],
}
