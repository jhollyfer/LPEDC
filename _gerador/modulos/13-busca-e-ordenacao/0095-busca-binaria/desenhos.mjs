// as 15 gavetas do catálogo, em três momentos da busca por 216
const codigos = ['103', '118', '125', '140', '152', '167', '171', '189', '204', '216', '230', '245', '258', '263', '279']
const X = 200
const W = 86
const estados = (cinzas, meio, cor) => {
  const e = {}
  for (const i of cinzas) e[i] = 'apagado'
  e[meio] = cor
  return e
}
const faixa = (a, b) => Array.from({ length: b - a + 1 }, (_, k) => a + k)
const centro = (i) => X + i * W + W / 2

export const ideia = {
  caixas: [
    { id: 'v1', forma: 'array', x: X, y: 60, celula: W, itens: codigos, estados: estados([], 7, 'amarelo') },
    { id: 'v2', forma: 'array', x: X, y: 260, celula: W, itens: codigos, estados: estados(faixa(0, 7), 11, 'amarelo') },
    {
      id: 'v3',
      forma: 'array',
      x: X,
      y: 460,
      celula: W,
      itens: codigos,
      estados: estados([...faixa(0, 7), ...faixa(10, 14)], 9, 'verde'),
    },
  ],
  setas: [],
  notas: [
    { x: 100, y: 112, texto: '1ª', cor: 'roxo' },
    { x: 100, y: 312, texto: '2ª', cor: 'roxo' },
    { x: 100, y: 512, texto: '3ª', cor: 'verde' },
    { x: centro(7), y: 44, texto: '189 < 216: descarta a esquerda', cor: 'roxo', ancora: 'middle' },
    { x: centro(11), y: 244, texto: '245 > 216: descarta a direita', cor: 'roxo', ancora: 'middle' },
    { x: centro(9), y: 444, texto: 'achou: posição 9', cor: 'verde', ancora: 'middle' },
    { x: 200, y: 640, texto: 'sobram 15, depois 7, depois 3 candidatos: 3 voltas', cor: 'cinza' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início: ini=0, fim=14'],
    ['C', 'dec', 'ini <= fim?'],
    ['D', 'proc', 'meio = ini + (fim - ini) / 2'],
    ['E', 'dec', 'v[meio] == x?'],
    ['F', 'dec', 'v[meio] < x?'],
    ['G', 'proc', 'ini = meio + 1'],
    ['H', 'proc', 'fim = meio - 1'],
    ['I', 'io', 'Mostrar meio (9)'],
    ['J', 'io', 'Mostrar -1'],
    ['K', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'C'],
    ['C', 'D', 'Sim'],
    ['D', 'E'],
    ['E', 'I', 'Sim'],
    ['E', 'F', 'Não'],
    ['F', 'G', 'Sim'],
    ['F', 'H', 'Não'],
    ['G', 'C'],
    ['H', 'C'],
    ['C', 'J', 'Não'],
    ['I', 'K'],
    ['J', 'K'],
  ],
  caminho: ['A', 'C', 'D', 'E', 'F', 'G', 'C', 'D', 'E', 'F', 'H', 'C', 'D', 'E', 'I', 'K'],
}
