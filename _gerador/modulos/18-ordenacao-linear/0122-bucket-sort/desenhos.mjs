// bucket sort das notas: a entrada, os 10 baldes (cada um uma lista já em
// ordem) e a saída, que é só ler os baldes de cima para baixo
const notas = ['6.4', '2.7', '8.1', '4.5', '2.2', '9.6', '6.9', '0.8', '4.1', '2.9']

export const ideia = {
  caixas: [
    {
      id: 'ent',
      forma: 'array',
      x: 330,
      y: 40,
      celula: 90,
      itens: notas,
      estados: { 1: 'amarelo', 4: 'amarelo', 9: 'amarelo' },
      indices: false,
    },
    {
      id: 'tab',
      forma: 'tabela',
      x: 330,
      y: 220,
      w: 120,
      baldes: [['0.8'], [], ['2.2', '2.7', '2.9'], [], ['4.1', '4.5'], [], ['6.4', '6.9'], [], ['8.1'], ['9.6']],
      estados: { 2: 'amarelo' },
    },
    {
      id: 'sai',
      forma: 'array',
      x: 330,
      y: 940,
      celula: 90,
      itens: ['0.8', '2.2', '2.7', '2.9', '4.1', '4.5', '6.4', '6.9', '8.1', '9.6'],
      estados: Object.fromEntries([0, 1, 2, 3, 4, 5, 6, 7, 8, 9].map((i) => [i, 'verde'])),
      indices: false,
    },
  ],
  setas: [
    { pontos: [[780, 140], [780, 206]], rotulo: 'espalha', dy: 8 },
    { pontos: [[780, 868], [780, 930]], rotulo: 'junta', dy: 8 },
  ],
  notas: [
    { x: 110, y: 92, texto: 'entrada', cor: 'azul' },
    { x: 110, y: 992, texto: 'saída', cor: 'verde' },
    { x: 1020, y: 380, texto: ['balde de x = (int) x', '2.7, 2.2 e 2.9 caem no 2', 'e entram em ordem'], cor: 'roxo' },
    { x: 1020, y: 640, texto: ['baldes vazios ficam', 'com NULL'], cor: 'cinza' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'io', 'Recebe v (10 notas)'],
    ['C', 'proc', '10 baldes vazios (NULL)'],
    ['D', 'dec', 'Falta algum v[i]?'],
    ['E', 'proc', 'insere v[i] em ordem no balde (int) v[i]'],
    ['F', 'proc', 'junta os baldes, do 0 ao 9, e libera os nós'],
    ['G', 'io', 'Mostra v ordenado'],
    ['H', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D'],
    ['D', 'E', 'Sim'],
    ['E', 'D'],
    ['D', 'F', 'Não'],
    ['F', 'G'],
    ['G', 'H'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'D', 'F', 'G', 'H'],
}
