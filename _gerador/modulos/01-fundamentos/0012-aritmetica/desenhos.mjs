// 24 fatias: 4 para cada um dos 5 amigos (A a E) e 4 que sobram (S)
const donos = ['A', 'B', 'C', 'D', 'E'].flatMap((a) => [a, a, a, a])
const itens = [...donos, 'S', 'S', 'S', 'S']
const estados = Object.fromEntries(
  itens.map((v, i) => [i, v === 'S' ? 'amarelo' : 'ABCDE'.indexOf(v) % 2 ? 'roxo' : 'verde']),
)

export const ideia = {
  caixas: [
    { id: 'p', forma: 'caixinha', x: 100, y: 20, w: 300, nome: 'fatias', valor: '24', tipo: '3 pizzas * 8' },
    { id: 'a', forma: 'caixinha', x: 520, y: 20, w: 300, nome: 'amigos', valor: '5', tipo: 'A, B, C, D, E' },
    { id: 'f', forma: 'array', x: 100, y: 340, itens, estados, indices: false, celula: 54 },
    { id: 'div', x: 100, y: 560, w: 560, cor: 'verde', rotulo: 'divisão inteira', texto: ['24 / 5 = 4 fatias cada'] },
    { id: 'mod', x: 800, y: 560, w: 560, cor: 'amarelo', rotulo: 'resto', texto: ['24 % 5 = 4 sobram (S)'] },
  ],
  setas: [
    { de: 'p', para: 'f', lados: 'bc', rotulo: 'divide entre os 5' },
    { pontos: [[400, 440], [400, 544]], cor: 'verde', rotulo: '4 para cada' },
    { pontos: [[1188, 440], [1188, 544]], cor: 'vermelho', rotulo: 'não dá mais 1 para cada' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'proc', 'fatias = pizzas * 8'],
    ['C', 'proc', 'cada = fatias / amigos'],
    ['D', 'proc', 'sobra = fatias % amigos'],
    ['E', 'io', 'Mostrar cada e sobra'],
    ['F', 'io', 'Mostrar conta / amigos'],
    ['G', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D'],
    ['D', 'E'],
    ['E', 'F'],
    ['F', 'G'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'F', 'G'],
}
