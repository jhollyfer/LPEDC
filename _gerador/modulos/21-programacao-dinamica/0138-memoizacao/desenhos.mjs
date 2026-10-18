// a árvore de chamadas de formas(5): com memo, só as coloridas acontecem.
// verde = calcula e anota; azul = caso base; amarelo = acha no memo;
// cinza = chamadas que a recursão pura faria e a memoização corta.
// Os valores repetem na árvore, mas a peça colore por valor: o sufixo de
// espaços não separáveis deixa cada nó com uma chave diferente.
const u = (v, k) => v + ' '.repeat(k)

export const ideia = {
  caixas: [
    {
      id: 'arv',
      forma: 'arvore',
      x: 110,
      y: 110,
      dx: 88,
      dy: 105,
      raiz: {
        v: u(5, 0),
        e: {
          v: u(4, 0),
          e: {
            v: u(3, 0),
            e: { v: u(2, 0), e: { v: u(1, 0) }, d: { v: u(0, 0) } },
            d: { v: u(1, 1) },
          },
          d: { v: u(2, 1), e: { v: u(1, 2) }, d: { v: u(0, 1) } },
        },
        d: {
          v: u(3, 1),
          e: { v: u(2, 2), e: { v: u(1, 3) }, d: { v: u(0, 2) } },
          d: { v: u(1, 4) },
        },
      },
      estados: {
        [u(5, 0)]: 'verde',
        [u(4, 0)]: 'verde',
        [u(3, 0)]: 'verde',
        [u(2, 0)]: 'verde',
        [u(2, 1)]: 'amarelo',
        [u(3, 1)]: 'amarelo',
        [u(1, 2)]: 'apagado',
        [u(0, 1)]: 'apagado',
        [u(2, 2)]: 'apagado',
        [u(1, 3)]: 'apagado',
        [u(0, 2)]: 'apagado',
        [u(1, 4)]: 'apagado',
      },
      marcadas: [
        [u(5, 0), u(4, 0)],
        [u(4, 0), u(3, 0)],
        [u(3, 0), u(2, 0)],
      ],
    },
    {
      id: 'memo',
      forma: 'array',
      x: 110,
      y: 630,
      nome: 'memo',
      celula: 90,
      itens: ['-1', '-1', '2', '3', '5', '8'],
      estados: { 0: 'apagado', 1: 'apagado', 2: 'verde', 3: 'verde', 4: 'verde', 5: 'verde' },
    },
  ],
  setas: [],
  notas: [
    { x: 1440, y: 130, texto: 'cada bolinha é uma', cor: 'cinza', ancora: 'end' },
    { x: 1440, y: 168, texto: 'chamada formas(n)', cor: 'cinza', ancora: 'end' },
    { x: 760, y: 700, texto: 'verde: calcula e anota no memo', cor: 'verde' },
    { x: 760, y: 740, texto: 'amarelo: já está no memo, volta na hora', cor: 'amarelo' },
    { x: 760, y: 780, texto: 'azul: caso base (0 ou 1 degrau)', cor: 'azul' },
    { x: 760, y: 820, texto: 'cinza: só a recursão pura faria', cor: 'cinza' },
    { x: 110, y: 830, texto: 'memo: 9 chamadas; recursão pura: 15', cor: 'roxo' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início: formas_memo(n)'],
    ['B', 'dec', 'n <= 1?'],
    ['C', 'io', 'Devolve 1'],
    ['D', 'dec', 'memo[n] != -1?'],
    ['E', 'io', 'Devolve memo[n]'],
    ['F', 'proc', 'memo[n] = f(n-1) + f(n-2)'],
    ['G', 'io', 'Devolve memo[n] (novo)'],
    ['H', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C', 'Sim'],
    ['B', 'D', 'Não'],
    ['D', 'E', 'Sim'],
    ['D', 'F', 'Não'],
    ['F', 'G'],
    ['C', 'H'],
    ['E', 'H'],
    ['G', 'H'],
  ],
  caminho: ['A', 'B', 'D', 'F', 'G', 'H'],
}
