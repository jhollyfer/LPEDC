// a árvore de decisões do açaí: cada nível decide um complemento
// (esquerda = sem, direita = com); as 8 folhas são os 8 copos, na ordem da saída
const folhas = [
  ['nenhum', 'R$ 0'],
  ['P', 'R$ 4'],
  ['B', 'R$ 3'],
  ['B P', 'R$ 7'],
  ['G', 'R$ 2'],
  ['G P', 'R$ 6'],
  ['G B', 'R$ 5'],
  ['G B P', 'R$ 9'],
]
const PASSO = 175
const cx = (j) => 185 + PASSO * j // centro da folha j
const meio = (a, b) => (cx(a) + cx(b)) / 2

const caixas = []
const setas = []
const no = (id, centro, y, w, h, cor, texto) => caixas.push({ id, x: centro - w / 2, y, w, h, cor, texto })

no('r', meio(0, 7), 40, 190, 80, 'amarelo', 'granola?')
no('n0', meio(0, 3), 200, 180, 80, 'amarelo', 'banana?')
no('n1', meio(4, 7), 200, 180, 80, 'amarelo', 'banana?')
for (let k = 0; k < 4; k++) no(`p${k}`, meio(2 * k, 2 * k + 1), 360, 160, 80, 'amarelo', 'paçoca?')
folhas.forEach(([t, preco], j) => no(`f${j}`, cx(j), 520, 160, 120, 'verde', [t, preco]))

const liga = (de, para, com) =>
  setas.push({ de, para, lados: 'bc', rotulo: com ? 'com' : 'sem', cor: com ? 'verde' : 'cinza', dx: com ? 0 : -70 })
liga('r', 'n0', false)
liga('r', 'n1', true)
liga('n0', 'p0', false)
liga('n0', 'p1', true)
liga('n1', 'p2', false)
liga('n1', 'p3', true)
for (let j = 0; j < 8; j++) liga(`p${j >> 1}`, `f${j}`, j % 2 === 1)

export const ideia = {
  caixas,
  setas,
  notas: [
    { x: 100, y: 700, texto: 'G = granola (R$ 2), B = banana (R$ 3), P = paçoca (R$ 4)', cor: 'cinza' },
    { x: 100, y: 740, texto: '1 + 2 + 4 + 8 = 15 nós: cada nó é uma chamada de gera', cor: 'roxo' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início: gera(i, k)'],
    ['B', 'dec', 'i == N?'],
    ['C', 'io', 'Mostra a cesta e o total'],
    ['D', 'proc', 'Sem o item i: gera(i+1, k)'],
    ['E', 'proc', 'cesta[k] = i'],
    ['F', 'proc', 'Com o item i: gera(i+1, k+1)'],
    ['G', 'inicio', 'Fim da chamada'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C', 'Sim'],
    ['B', 'D', 'Não'],
    ['D', 'E'],
    ['E', 'F'],
    ['F', 'G'],
    ['C', 'G'],
  ],
  caminho: ['A', 'B', 'C', 'G', 'A', 'B', 'D', 'E', 'F', 'G'],
}
