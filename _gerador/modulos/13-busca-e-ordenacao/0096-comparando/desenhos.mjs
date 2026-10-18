// estabilidade: os pedidos chegam por horário (R1 = Recife, pedido 1...).
// Ordenar por cidade com um algoritmo estável mantém a ordem de chegada
// dentro de cada cidade; o selection sort não garante isso.
const X = 400
const C = 120

export const ideia = {
  caixas: [
    { id: 'chegada', forma: 'array', x: X, y: 60, celula: C, itens: ['R1', 'M2', 'R3', 'N4', 'M5', 'R6'] },
    {
      id: 'estavel',
      forma: 'array',
      x: X,
      y: 300,
      celula: C,
      itens: ['M2', 'M5', 'N4', 'R1', 'R3', 'R6'],
      estados: { 0: 'verde', 1: 'verde', 2: 'verde', 3: 'verde', 4: 'verde', 5: 'verde' },
      indices: false,
    },
    {
      id: 'instavel',
      forma: 'array',
      x: X,
      y: 500,
      celula: C,
      itens: ['M2', 'M5', 'N4', 'R3', 'R1', 'R6'],
      estados: { 3: 'vermelho', 4: 'vermelho' },
      indices: false,
    },
  ],
  setas: [{ pontos: [[X + 3 * C, 206], [X + 3 * C, 290]], cor: 'roxo', rotulo: 'ordena por cidade' }],
  notas: [
    { x: 100, y: 112, texto: 'chegada', cor: 'azul' },
    { x: 100, y: 352, texto: 'estável', cor: 'verde' },
    { x: 100, y: 552, texto: 'instável', cor: 'vermelho' },
    { x: 1150, y: 112, texto: ['por horário:', 'R = Recife, M = Manaus,', 'N = Natal'], cor: 'cinza' },
    { x: 1150, y: 334, texto: ['insertion, merge:', 'R1, R3, R6 na ordem', 'em que chegaram'], cor: 'verde' },
    { x: 1150, y: 534, texto: ['selection sort:', 'R3 passou na frente', 'do R1'], cor: 'vermelho' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início: preciso ordenar'],
    ['B', 'dec', 'n pequeno ou quase ordenado?'],
    ['C', 'proc', 'insertion sort'],
    ['D', 'dec', 'dá para desempatar na compara?'],
    ['E', 'proc', 'merge sort (estável)'],
    ['F', 'proc', 'qsort com desempate'],
    ['G', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C', 'Sim'],
    ['B', 'D', 'Não'],
    ['D', 'F', 'Sim'],
    ['D', 'E', 'Não'],
    ['C', 'G'],
    ['E', 'G'],
    ['F', 'G'],
  ],
  caminho: ['A', 'B', 'D', 'F', 'G'],
}
