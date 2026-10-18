// o heap da triagem depois das 6 chegadas: a árvore e o vetor lado a lado,
// com o 70 (índice 1) e os filhos dele (índices 3 e 4) destacados
export const ideia = {
  caixas: [
    {
      id: 'arv',
      forma: 'arvore',
      x: 110,
      y: 120,
      dx: 100,
      dy: 160,
      raiz: {
        v: 90,
        e: { v: 70, e: { v: 40 }, d: { v: 50 } },
        d: { v: 30, e: { v: 20 } },
      },
      estados: { 90: 'roxo', 70: 'amarelo', 40: 'verde', 50: 'verde' },
      marcadas: [
        [70, 40],
        [70, 50],
      ],
    },
    {
      id: 'vet',
      forma: 'array',
      x: 820,
      y: 120,
      nome: 'v',
      celula: 100,
      itens: [90, 70, 30, 40, 50, 20],
      estados: { 0: 'roxo', 1: 'amarelo', 3: 'verde', 4: 'verde' },
    },
    {
      id: 'f',
      x: 820,
      y: 380,
      w: 600,
      h: 230,
      cor: 'azul',
      rotulo: 'sem ponteiros: só contas',
      texto: ['pai de i: (i - 1) / 2', 'filhos de i: 2i + 1 e 2i + 2', 'i = 1 (70): filhos 3 e 4'],
    },
  ],
  setas: [{ de: 'vet', para: 'f' }],
  notas: [
    { x: 400, y: 136, texto: '[0]', cor: 'cinza', ancora: 'end' },
    { x: 200, y: 296, texto: '[1]', cor: 'cinza', ancora: 'end' },
    { x: 692, y: 296, texto: '[2]', cor: 'cinza' },
    { x: 146, y: 545, texto: '[3]', cor: 'cinza', ancora: 'middle' },
    { x: 346, y: 545, texto: '[4]', cor: 'cinza', ancora: 'middle' },
    { x: 546, y: 545, texto: '[5]', cor: 'cinza', ancora: 'middle' },
    { x: 110, y: 615, texto: 'todo pai >= filhos; o maior (90) fica na raiz', cor: 'roxo' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'io', 'Recebe x (30)'],
    ['C', 'proc', 'v[n] = x; i = n; n++'],
    ['D', 'dec', 'i > 0 e v[pai] < v[i]?'],
    ['E', 'proc', 'Troca com o pai; i = pai'],
    ['F', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D'],
    ['D', 'E', 'Sim'],
    ['E', 'D'],
    ['D', 'F', 'Não'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'D', 'F'],
}
