// A árvore de decisão do insertion sort de 3 encomendas (A, B, C). Cada
// losango é uma pesagem; cada folha, uma das 3! = 6 ordens (da mais leve
// para a mais pesada). Em verde, o caminho de A = 5, B = 9, C = 2.
const LW = 250
const LH = 140
const FW = 190
const FH = 90
// pergunta: [id, centro x, y do topo, texto, no caminho?]
const perguntas = [
  ['r', 760, 40, 'A > B?', true],
  ['n1', 400, 300, 'B > C?', true],
  ['n2', 590, 560, 'A > C?', true],
  ['n3', 1120, 300, 'A > C?', false],
  ['n4', 1310, 560, 'B > C?', false],
]
// folha: [id, centro x, y do topo, ordem, no caminho?, pesagens]
const folhas = [
  ['f1', 200, 585, 'A B C', false, 2],
  ['f2', 470, 830, 'A C B', false, 3],
  ['f3', 710, 830, 'C A B', true, 3],
  ['f4', 920, 585, 'B A C', false, 2],
  ['f5', 1190, 830, 'B C A', false, 3],
  ['f6', 1430, 830, 'C B A', false, 3],
]
const caixas = [
  ...perguntas.map(([id, cx, y, t]) => ({ id, x: cx - LW / 2, y, w: LW, h: LH, forma: 'losango', cor: 'amarelo', texto: [t] })),
  ...folhas.map(([id, cx, y, t, cam]) => ({ id, x: cx - FW / 2, y, w: FW, h: FH, cor: cam ? 'verde' : 'cinza', texto: [t] })),
]
// [de, para, resposta, no caminho?]
const ligacoes = [
  ['r', 'n1', 'não', true],
  ['r', 'n3', 'sim', false],
  ['n1', 'f1', 'não', false],
  ['n1', 'n2', 'sim', true],
  ['n2', 'f2', 'não', false],
  ['n2', 'f3', 'sim', true],
  ['n3', 'f4', 'não', false],
  ['n3', 'n4', 'sim', false],
  ['n4', 'f5', 'não', false],
  ['n4', 'f6', 'sim', false],
]
const setas = ligacoes.map(([de, para, rotulo, cam]) => ({ de, para, rotulo, lados: 'bc', cor: cam ? 'verde' : 'cinza' }))

export const ideia = {
  caixas,
  setas,
  notas: [
    { x: 100, y: 1030, texto: '6 folhas: uma para cada ordem possível (3! = 6)', cor: 'roxo' },
    { x: 100, y: 1075, texto: 'altura 3: com 2 pesagens só caberiam 2² = 4 folhas', cor: 'roxo' },
    { x: 1010, y: 1030, texto: 'entrada: A = 5, B = 9, C = 2', cor: 'verde' },
    { x: 1010, y: 1075, texto: 'resposta: C A B (3 pesagens)', cor: 'verde' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início: n elementos'],
    ['B', 'proc', 'n! ordens: precisa de n! folhas'],
    ['C', 'proc', 'altura h: no máximo 2^h folhas'],
    ['D', 'proc', 'h = 0'],
    ['E', 'dec', '2^h >= n!?'],
    ['F', 'proc', 'h = h + 1 (faltam folhas)'],
    ['G', 'io', 'pior caso >= h comparações'],
    ['H', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D'],
    ['D', 'E'],
    ['E', 'F', 'Não'],
    ['F', 'E'],
    ['E', 'G', 'Sim'],
    ['G', 'H'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'F', 'E', 'G', 'H'],
}
