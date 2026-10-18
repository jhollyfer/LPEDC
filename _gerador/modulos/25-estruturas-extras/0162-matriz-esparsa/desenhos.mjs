// as notas da locadora: à esquerda a matriz cheia (32 posições, 5 com nota);
// à direita a lista por linha, que só guarda as 5 células
const notas = [
  [0, 4, 0, 0, 0, 0, 5, 0],
  [0, 0, 0, 0, 0, 0, 0, 0],
  [0, 0, 0, 0, 0, 0, 0, 0],
  [5, 0, 0, 4, 0, 0, 0, 1],
]
const linha = (i) => ({
  id: `l${i}`,
  forma: 'array',
  x: 110,
  y: 130 + i * 100,
  celula: 64,
  itens: notas[i],
  indices: i === 3,
  estados: Object.fromEntries(notas[i].map((v, j) => [j, v ? 'verde' : 'apagado'])),
})

export const ideia = {
  caixas: [
    ...[0, 1, 2, 3].map(linha),
    {
      id: 'tab',
      forma: 'tabela',
      x: 760,
      y: 140,
      w: 110,
      baldes: [['c1: 4', 'c6: 5'], [], [], ['c0: 5', 'c3: 4', 'c7: 1']],
    },
  ],
  setas: [{ pontos: [[640, 265], [740, 265]], rotulo: 'só os ≠ 0', cor: 'roxo' }],
  notas: [
    { x: 110, y: 610, texto: ['matriz cheia: 32 posições', 'linhas: Ana, Bruno, Carla, Davi', 'colunas: filmes 0 a 7'], cor: 'cinza' },
    { x: 760, y: 470, texto: 'lista por linha: só 5 células (c = coluna)', cor: 'verde' },
    { x: 760, y: 530, texto: ['linha 1: Bruno apagou a nota', 'linha 2: Carla não deu nenhuma', 'NULL = a linha toda vale 0'], cor: 'cinza' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'io', 'Ler i, j e valor (1, 3, 0)'],
    ['C', 'proc', 'Andar na linha i até col >= j'],
    ['D', 'dec', 'Achou a coluna j?'],
    ['E', 'dec', 'valor == 0?'],
    ['F', 'proc', 'Tirar a célula (free)'],
    ['G', 'proc', 'Trocar o valor'],
    ['H', 'dec', 'valor == 0?'],
    ['I', 'proc', 'Criar célula entre ant e p'],
    ['J', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D'],
    ['D', 'E', 'Sim'],
    ['D', 'H', 'Não'],
    ['E', 'F', 'Sim'],
    ['E', 'G', 'Não'],
    ['H', 'J', 'Sim'],
    ['H', 'I', 'Não'],
    ['F', 'J'],
    ['G', 'J'],
    ['I', 'J'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'F', 'J'],
}
