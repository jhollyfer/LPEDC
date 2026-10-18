// árvore de chamadas de fib(5): cada nó é uma chamada, o número é o n
const fib = (n) => (n < 2 ? { v: n } : { v: n, e: fib(n - 1), d: fib(n - 2) })

export const ideia = {
  caixas: [
    {
      id: 'arv',
      forma: 'arvore',
      x: 100,
      y: 60,
      dx: 74,
      dy: 120,
      raio: 32,
      raiz: fib(5),
      estados: { 3: 'amarelo', 5: 'roxo' },
    },
    {
      id: 'p',
      forma: 'pilha',
      x: 1260,
      y: 40,
      w: 200,
      topo: false,
      titulo: 'pilha no fundo',
      estados: { 0: 'azul', 5: 'verde' },
      itens: ['main', 'fib(5)', 'fib(4)', 'fib(3)', 'fib(2)', 'fib(1)'],
    },
  ],
  setas: [],
  notas: [
    { x: 100, y: 640, texto: '15 chamadas no total; fib(3) é calculado 2 vezes', cor: 'vermelho' },
    { x: 1360, y: 560, texto: 'no máximo 5 quadros de fib', cor: 'verde', ancora: 'middle' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início: fib(n)'],
    ['B', 'dec', 'n < 2?'],
    ['C', 'proc', 'return n'],
    ['D', 'proc', 'a = fib(n - 1)'],
    ['E', 'proc', 'b = fib(n - 2)'],
    ['F', 'proc', 'return a + b'],
    ['G', 'inicio', 'Fim: volta para quem chamou'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C', 'Sim'],
    ['B', 'D', 'Não'],
    ['D', 'E'],
    ['E', 'F'],
    ['C', 'G'],
    ['F', 'G'],
  ],
  caminho: ['A', 'B', 'D', 'E', 'F', 'G'],
}
