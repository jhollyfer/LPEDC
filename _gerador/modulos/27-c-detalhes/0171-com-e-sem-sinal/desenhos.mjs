// os mesmos 32 bits, duas leituras; a comparação com 0u escolhe a sem sinal
export const ideia = {
  caixas: [
    {
      id: 'bits',
      forma: 'array',
      x: 320,
      y: 40,
      nome: 'saldo: os 4 bytes na memória',
      itens: ['1111 1111', '1111 1111', '1111 1111', '1111 1111'],
      celula: 230,
      indices: false,
    },
    { id: 'int', x: 140, y: 330, w: 520, h: 130, cor: 'azul', rotulo: 'lido como int', texto: ['-1'] },
    { id: 'uns', x: 860, y: 330, w: 520, h: 130, cor: 'roxo', rotulo: 'lido como unsigned', texto: ['4294967295'] },
    { id: 'p', x: 120, y: 540, w: 560, h: 200, forma: 'losango', cor: 'amarelo', texto: ['saldo > 0u ?'] },
    { id: 'res', x: 860, y: 570, w: 520, h: 140, cor: 'vermelho', texto: ['4294967295 > 0', 'verdadeiro!'] },
  ],
  setas: [
    { de: 'bits', para: 'int', lados: 'bc' },
    { de: 'bits', para: 'uns', lados: 'bc' },
    { de: 'p', para: 'res', rotulo: 'int vira unsigned', cor: 'vermelho' },
  ],
  notas: [{ x: 160, y: 300, texto: 'complemento de dois', cor: 'cinza' }],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'proc', 'estoque = 2u - 3u'],
    ['C', 'io', 'estoque = 4294967295'],
    ['D', 'proc', 'saldo = -1 vira unsigned'],
    ['E', 'dec', '4294967295 > 0?'],
    ['F', 'io', '-1 > 0u? sim'],
    ['G', 'io', '-1 > 0u? não'],
    ['H', 'io', 'a + b = 300 (int); c = 44'],
    ['I', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D'],
    ['D', 'E'],
    ['E', 'F', 'Sim'],
    ['E', 'G', 'Não'],
    ['F', 'H'],
    ['G', 'H'],
    ['H', 'I'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'F', 'H', 'I'],
}
