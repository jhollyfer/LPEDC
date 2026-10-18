export const ideia = {
  caixas: [
    { id: 'n', forma: 'caixinha', x: 100, y: 40, nome: 'n', valor: '4', tipo: 'int' },
    { id: 'm', x: 420, y: 64, w: 380, cor: 'roxo', rotulo: 'malloc', texto: ['4 * sizeof(double)', '= 32 bytes'] },
    { id: 'hp', x: 960, y: 20, w: 540, h: 230, cor: 'verde', rotulo: 'heap', texto: [] },
    { id: 'blk', forma: 'array', x: 990, y: 110, itens: ['12.50', '18.00', '25.90', '9.60'], celula: 120, cor: 'verde' },
    { id: 'p', forma: 'caixinha', x: 100, y: 330, nome: 'corridas', valor: '0x5030...', tipo: 'double * (pilha)' },
    { id: 't', forma: 'terminal', x: 1140, y: 340, w: 330, texto: ['Total: R$ 66.00'] },
    { id: 'f', x: 1100, y: 560, w: 400, cor: 'roxo', rotulo: 'free(corridas)', texto: ['os 32 bytes voltam'] },
  ],
  setas: [
    { de: 'n', para: 'm' },
    { de: 'm', para: 'hp', rotulo: 'endereço' },
    { pontos: [[350, 455], [1050, 455], [1050, 258]], rotulo: 'corridas aponta para o bloco' },
    { pontos: [[1305, 258], [1305, 332]], rotulo: 'soma', dx: 50, dy: 30 },
    { de: 't', para: 'f', rotulo: 'no fim' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'io', 'Ler n (4)'],
    ['C', 'proc', 'corridas = malloc(n * 8)'],
    ['D', 'dec', 'corridas != NULL?'],
    ['E', 'io', 'Ler os 4 valores'],
    ['F', 'dec', 'leu tudo?'],
    ['G', 'io', 'Total: R$ 66.00'],
    ['H', 'proc', 'free(corridas)'],
    ['I', 'io', 'Sem memória'],
    ['J', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D'],
    ['D', 'E', 'Sim'],
    ['D', 'I', 'Não'],
    ['E', 'F'],
    ['F', 'G', 'Sim'],
    ['F', 'H', 'Não'],
    ['G', 'H'],
    ['H', 'J'],
    ['I', 'J'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'J'],
}
