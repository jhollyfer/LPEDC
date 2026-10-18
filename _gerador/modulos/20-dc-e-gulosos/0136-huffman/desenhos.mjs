// a árvore de Huffman de "BANANA NA CABANA": folhas verdes com símbolo e
// frequência, nós internos roxos com a soma; 0 à esquerda, 1 à direita.
// Ao lado, a tabela de códigos lida da árvore.
const X = 110
const Y = 70
const DX = 120
const DY = 140
const R = 46
const raiz = {
  v: '16',
  e: { v: 'A:7' },
  d: {
    v: '9',
    e: { v: 'N:4' },
    d: { v: '5', e: { v: 'B:2' }, d: { v: '3', e: { v: 'C:1' }, d: { v: 'esp:2' } } },
  },
}

// posições iguais às do desenho da árvore (ordem em-ordem, um nível por linha)
const pos = {}
let ordem = 0
const visita = (n, nivel) => {
  if (!n) return
  visita(n.e, nivel + 1)
  pos[n.v] = [X + R + ordem++ * DX, Y + R + nivel * DY]
  visita(n.d, nivel + 1)
}
visita(raiz, 0)

// rótulo 0/1 no meio de cada aresta, um pouco para fora
const notas = []
const rotula = (n) => {
  if (!n || !n.e) return
  for (const [filho, bit] of [
    [n.e, '0'],
    [n.d, '1'],
  ]) {
    const [x1, y1] = pos[n.v]
    const [x2, y2] = pos[filho.v]
    const mx = (x1 + x2) / 2 + (bit === '0' ? -26 : 26)
    notas.push({ x: mx, y: (y1 + y2) / 2, texto: bit, cor: bit === '0' ? 'azul' : 'vermelho', ancora: 'middle', tam: 30 })
  }
  rotula(n.e)
  rotula(n.d)
}
rotula(raiz)

const estados = { 16: 'roxo', 9: 'roxo', 5: 'roxo', 3: 'roxo', 'A:7': 'verde', 'N:4': 'verde', 'B:2': 'verde', 'C:1': 'verde', 'esp:2': 'verde' }

notas.push({ x: 1180, y: 280, texto: 'C e espaço, os mais raros,', cor: 'cinza' })
notas.push({ x: 1180, y: 318, texto: 'se juntam primeiro e', cor: 'cinza' })
notas.push({ x: 1180, y: 356, texto: 'ficam lá no fundo', cor: 'cinza' })
notas.push({ x: 110, y: 790, texto: '7·1 + 4·2 + 2·3 + 1·4 + 2·4 = 33 bits (contra 128 com 8 bits por letra)', cor: 'roxo' })

export const ideia = {
  caixas: [
    { id: 'arv', forma: 'arvore', x: X, y: Y, dx: DX, dy: DY, raio: R, raiz, estados },
    {
      id: 'tab',
      x: 1180,
      y: 410,
      w: 300,
      h: 330,
      cor: 'azul',
      rotulo: 'códigos',
      texto: ['A    0', 'N    10', 'B    110', 'C    1110', 'esp  1111'],
    },
  ],
  setas: [],
  notas,
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'io', 'Recebe as frequências'],
    ['C', 'proc', 'Uma folha por símbolo no heap de mínimo'],
    ['D', 'dec', 'Mais de um nó no heap?'],
    ['E', 'proc', 'a = tira o menor; b = tira o menor'],
    ['F', 'proc', 'pai = novo\u00a0nó\u00a0(a,\u00a0b); freq\u00a0=\u00a0a\u00a0+\u00a0b'],
    ['G', 'proc', 'Põe o pai no heap'],
    ['H', 'io', 'Devolve a raiz (16)'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D'],
    ['D', 'E', 'Sim'],
    ['E', 'F'],
    ['F', 'G'],
    ['G', 'D'],
    ['D', 'H', 'Não'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'D', 'H'],
}
