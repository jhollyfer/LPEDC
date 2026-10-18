export const ideia = {
  caixas: [
    {
      id: 'pilha',
      forma: 'memoria',
      x: 140,
      y: 70,
      celula: 74,
      titulo: 'pilha (pode mudar)',
      celulas: [
        { end: '0x7000', nome: 'nome[0]', valor: "'a' → 'A'", cor: 'verde' },
        { end: '0x7001', nome: 'nome[1]', valor: "'n' → 'N'", cor: 'verde' },
        { end: '0x7002', nome: 'nome[2]', valor: "'a' → 'A'", cor: 'verde' },
        { end: '0x7003', nome: 'nome[3]', valor: "'\\0'", cor: 'verde' },
        { end: '0x7008', nome: 'apelido', valor: '0x4000', tipo: 'const char *', cor: 'roxo' },
      ],
    },
    {
      id: 'ro',
      forma: 'memoria',
      x: 920,
      y: 70,
      celula: 74,
      cor: 'cinza',
      titulo: 'área só de leitura',
      celulas: [
        { end: '0x4000', valor: "'b'" },
        { end: '0x4001', valor: "'i'" },
        { end: '0x4002', valor: "'a'" },
        { end: '0x4003', valor: "'\\0'" },
      ],
    },
    { id: 'x', x: 920, y: 420, w: 470, cor: 'vermelho', texto: ["apelido[0] = 'B';", 'o programa cai'] },
  ],
  setas: [
    { pontos: [[650, 403], [800, 403], [800, 107], [905, 107]], rotulo: 'aponta' },
  ],
  notas: [{ x: 140, y: 500, texto: ['nome[]: cópia de "ana"', 'na pilha'], cor: 'verde' }],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'proc', 'p = nome'],
    ['C', 'dec', "*p != '\\0'?"],
    ['D', 'proc', '*p = toupper(*p)'],
    ['E', 'proc', 'p++'],
    ['F', 'io', 'Mostrar "Crachá: ANA (bia)"'],
    ['G', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D', 'Sim'],
    ['D', 'E'],
    ['E', 'C'],
    ['C', 'F', 'Não'],
    ['F', 'G'],
  ],
}
