// Em cima, a fila 12, 25, 7 com a sentinela (cinza) fechando o anel; a 25
// vai sair. Embaixo, a fila depois da remoção e a busca pela 40 parando na
// sentinela.
export const ideia = {
  caixas: [
    {
      id: 'l1',
      forma: 'lista',
      x: 120,
      y: 140,
      dupla: true,
      circular: true,
      itens: ['nil', '12', '25', '7'],
      estados: { 0: 'cinza', 2: 'vermelho' },
      rotulos: { 0: 'sentinela', 1: 'nil.prox', 2: 'desistiu', 3: 'nil.ant' },
    },
    {
      id: 'l2',
      forma: 'lista',
      x: 120,
      y: 480,
      dupla: true,
      circular: true,
      itens: ['nil: 40', '12', '7'],
      estados: { 0: 'cinza', 1: 'amarelo', 2: 'amarelo' },
      rotulos: { 0: 'a chave buscada fica aqui', 1: '12 ≠ 40', 2: '7 ≠ 40' },
    },
  ],
  setas: [],
  notas: [
    { x: 1250, y: 200, texto: ['remover a 25:', 'x->ant->prox = x->prox', 'x->prox->ant = x->ant'], cor: 'vermelho', tam: 24 },
    { x: 100, y: 410, texto: 'SEM A 25. BUSCA PELA 40: UM TESTE SÓ POR VOLTA', cor: 'cinza' },
    { x: 1250, y: 330, texto: ['nenhum NULL dentro', 'da lista'], cor: 'cinza', tam: 24 },
    { x: 1100, y: 540, texto: ['voltou à sentinela:', 'a 40 não está na fila'], cor: 'verde', tam: 24 },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'sent_busca(fila, 40)'],
    ['B', 'proc', 'nil.chave = 40'],
    ['C', 'proc', 'x = nil.prox'],
    ['D', 'dec', 'x->chave != 40?'],
    ['E', 'proc', 'x = x->prox'],
    ['F', 'dec', 'x == &nil?'],
    ['G', 'io', 'Mostrar "não está na fila"'],
    ['H', 'io', 'Devolver x: achou'],
    ['I', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D'],
    ['D', 'E', 'Sim'],
    ['E', 'D'],
    ['D', 'F', 'Não'],
    ['F', 'G', 'Sim'],
    ['F', 'H', 'Não'],
    ['G', 'I'],
    ['H', 'I'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'D', 'E', 'D', 'F', 'G', 'I'],
}
