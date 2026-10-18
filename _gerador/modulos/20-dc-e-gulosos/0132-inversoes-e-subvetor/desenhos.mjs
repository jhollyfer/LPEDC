// contar inversões: o vetor do Caio, as duas metades já ordenadas (com as
// inversões de dentro) e a intercalação, onde cada elemento da direita soma
// os que ainda sobram na esquerda
const CEL = 100
export const ideia = {
  caixas: [
    { id: 'v', forma: 'array', x: 300, y: 40, nome: 'caio', celula: CEL, itens: [3, 7, 1, 5, 8, 2, 6, 4] },
    { id: 'e', forma: 'array', x: 110, y: 340, celula: CEL, itens: [1, 3, 5, 7], estados: { 0: 'roxo', 1: 'roxo', 2: 'roxo', 3: 'roxo' }, indices: false },
    { id: 'd', forma: 'array', x: 900, y: 340, celula: CEL, itens: [2, 4, 6, 8], estados: { 0: 'amarelo', 1: 'amarelo', 2: 'amarelo', 3: 'amarelo' }, indices: false },
    {
      id: 'r',
      forma: 'array',
      x: 300,
      y: 660,
      celula: CEL,
      itens: [1, 2, 3, 4, 5, 6, 7, 8],
      estados: { 0: 'verde', 1: 'amarelo', 2: 'verde', 3: 'amarelo', 4: 'verde', 5: 'amarelo', 6: 'verde', 7: 'amarelo' },
      indices: false,
    },
  ],
  setas: [
    { pontos: [[560, 250], [420, 320]], cor: 'roxo' },
    { pontos: [[840, 250], [980, 320]], cor: 'roxo' },
    { pontos: [[300, 505], [430, 595]], cor: 'verde' },
    { pontos: [[1100, 505], [970, 595]], cor: 'verde' },
  ],
  notas: [
    { x: 700, y: 300, texto: ['a recursão ordena', 'e conta cada metade'], cor: 'roxo', ancora: 'middle' },
    { x: 110, y: 482, texto: '3 inversões dentro', cor: 'roxo' },
    { x: 900, y: 482, texto: '4 inversões dentro', cor: 'roxo' },
    { x: 700, y: 560, texto: 'intercala', cor: 'verde', ancora: 'middle' },
    { x: 450, y: 642, texto: '+3', cor: 'vermelho', ancora: 'middle' },
    { x: 650, y: 642, texto: '+2', cor: 'vermelho', ancora: 'middle' },
    { x: 850, y: 642, texto: '+1', cor: 'vermelho', ancora: 'middle' },
    { x: 1050, y: 642, texto: '+0', cor: 'vermelho', ancora: 'middle' },
    { x: 300, y: 800, texto: 'o 2 sai antes de 3, 5 e 7: são 3 pares em desacordo de uma vez', cor: 'cinza' },
    { x: 300, y: 860, texto: 'total: 3 + 4 + 6 = 13 pares em desacordo', cor: 'roxo' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início: conta(p, r)'],
    ['B', 'dec', 'r - p < 2?'],
    ['C', 'io', 'Devolve 0'],
    ['D', 'proc', 'q = p + (r - p) / 2'],
    ['D2', 'proc', 'esq = conta(p, q)'],
    ['E', 'proc', 'dir = conta(q, r)'],
    ['F', 'proc', 'cruz = intercala(p, q, r)'],
    ['G', 'io', 'Devolve esq + dir + cruz'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C', 'Sim'],
    ['B', 'D', 'Não'],
    ['D', 'D2'],
    ['D2', 'E'],
    ['E', 'F'],
    ['F', 'G'],
  ],
  caminho: ['A', 'B', 'D', 'D2', 'E', 'F', 'G'],
}
