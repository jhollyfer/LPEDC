export const ideia = {
  caixas: [
    { id: 's', forma: 'array', x: 110, y: 40, nome: 'só os delimitadores', itens: ['{', '[', '(', ')', ']', '}'], estados: { 0: 'roxo', 1: 'roxo', 2: 'roxo', 3: 'verde', 4: 'apagado', 5: 'apagado' }, celula: 90, indices: false },
    { id: 'p', forma: 'pilha', x: 880, y: 60, itens: ['{', '[', '('], estados: { 2: 'verde' }, w: 160, topo: 'topo: (', titulo: 'quando chega o )' },
    { id: 'c', x: 110, y: 300, w: 560, h: 130, cor: 'verde', texto: [') casa com o ( do topo:', 'desempilha e segue'] },
    { id: 't', forma: 'terminal', x: 1150, y: 360, w: 300, texto: ['balanceada'] },
  ],
  setas: [
    { pontos: [[670, 140], [860, 140]], rotulo: 'empilha', cor: 'roxo' },
    { pontos: [[425, 190], [425, 284]], cor: 'verde' },
  ],
  notas: [
    { x: 1150, y: 330, texto: 'no fim, pilha vazia', cor: 'verde' },
    { x: 110, y: 500, texto: 'contar não basta: ( [ ) ] tem 2 aberturas e 2 fechamentos e está errada', cor: 'vermelho' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'proc', 'c = próximo caractere'],
    ['C', 'dec', 'acabou a string?'],
    ['D', 'dec', 'c abre?'],
    ['E', 'proc', 'empilha c'],
    ['F', 'dec', 'c fecha e não casa com o topo?'],
    ['G', 'dec', 'pilha vazia?'],
    ['H', 'io', 'Mostrar "balanceada"'],
    ['I', 'io', 'Mostrar "com erro"'],
    ['J', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'G', 'Sim'],
    ['C', 'D', 'Não'],
    ['D', 'E', 'Sim'],
    ['E', 'B'],
    ['D', 'F', 'Não'],
    ['F', 'B', 'Não'],
    ['F', 'I', 'Sim'],
    ['G', 'H', 'Sim'],
    ['G', 'I', 'Não'],
    ['H', 'J'],
    ['I', 'J'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'B', 'C', 'D', 'F', 'B', 'C', 'G', 'H', 'J'],
}
