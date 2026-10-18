// pilha no ponto mais fundo de fatorial(5); à esquerda, o que cada quadro
// devolve na volta
const x = 560
const y = 60
const alt = 106 // cada quadro tem 2 linhas
const centro = (i) => y + 6 * alt - alt * (i + 1) + alt / 2
const devolve = ['mostra 120', 'devolve 120', 'devolve 24', 'devolve 6', 'devolve 2', 'devolve 1']

export const ideia = {
  caixas: [
    {
      id: 'p',
      forma: 'pilha',
      x,
      y,
      w: 380,
      titulo: 'a pilha no ponto mais fundo',
      topo: 'topo: caso base',
      estados: { 0: 'azul', 5: 'verde' },
      itens: [
        ['main', 'printf(fatorial(5))'],
        ['fatorial(5)', 'espera 5 * fatorial(4)'],
        ['fatorial(4)', 'espera 4 * fatorial(3)'],
        ['fatorial(3)', 'espera 3 * fatorial(2)'],
        ['fatorial(2)', 'espera 2 * fatorial(1)'],
        ['fatorial(1)', 'n <= 1: return 1'],
      ],
    },
  ],
  setas: [
    { pontos: [[200, centro(5)], [200, centro(0)]], rotulo: '', cor: 'verde' },
  ],
  notas: devolve.map((t, i) => ({ x: 520, y: centro(i) + 9, texto: t, cor: i === 5 ? 'verde' : 'roxo', ancora: 'end' })).concat([
    { x: 150, y: centro(3), texto: 'volta', cor: 'verde', ancora: 'end' },
  ]),
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início: main chama fatorial(5)'],
    ['B', 'proc', 'Empilha fatorial(n)'],
    ['C', 'dec', 'n <= 1?'],
    ['D', 'proc', 'Chama de novo com n - 1'],
    ['E', 'proc', 'Caso base: devolve 1'],
    ['F', 'dec', 'Algum quadro esperando?'],
    ['G', 'proc', 'Desempilha: n * resposta'],
    ['H', 'io', 'Mostrar 120'],
    ['I', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D', 'Não'],
    ['D', 'B'],
    ['C', 'E', 'Sim'],
    ['E', 'F'],
    ['F', 'G', 'Sim'],
    ['G', 'F'],
    ['F', 'H', 'Não'],
    ['H', 'I'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'B', 'C', 'E', 'F', 'G', 'F', 'H', 'I'],
}
