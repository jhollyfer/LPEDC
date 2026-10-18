// Em cima, os três consertos em sequência quando a tag 20 entra (zigue-zague
// 30, 10, 20). Embaixo, a árvore depois da tag 40 e a árvore 2-3 que ela
// representa. Vermelho = nó vermelho; cinza = nó preto.
const comum = { forma: 'arvore', dx: 70, dy: 120 }
const nota = (x, y, texto, cor = 'roxo') => ({ x, y, texto, cor, tam: 24 })

export const ideia = {
  caixas: [
    {
      ...comum,
      id: 't1',
      x: 110,
      y: 240,
      raiz: { v: 30, e: { v: 10, d: { v: 20 } } },
      estados: { 30: 'cinza', 10: 'vermelho', 20: 'vermelho' },
    },
    {
      ...comum,
      id: 't2',
      x: 500,
      y: 240,
      raiz: { v: 30, e: { v: 20, e: { v: 10 } } },
      estados: { 30: 'cinza', 20: 'vermelho', 10: 'vermelho' },
    },
    {
      ...comum,
      id: 't3',
      x: 860,
      y: 240,
      raiz: { v: 20, e: { v: 10 }, d: { v: 30 } },
      estados: { 20: 'cinza', 10: 'vermelho', 30: 'vermelho' },
    },
    {
      ...comum,
      id: 't4',
      x: 1230,
      y: 240,
      raiz: { v: 20, e: { v: 10 }, d: { v: 30 } },
      estados: { 20: 'verde', 10: 'cinza', 30: 'cinza' },
    },
    // embaixo: depois da tag 40
    {
      ...comum,
      id: 'f',
      x: 110,
      y: 770,
      raiz: { v: 40, e: { v: 20, e: { v: 10 }, d: { v: 30 } }, d: { v: 50 } },
      estados: { 40: 'cinza', 20: 'vermelho', 10: 'cinza', 30: 'cinza', 50: 'cinza' },
    },
    { id: 'n0', x: 900, y: 750, w: 200, h: 80, cor: 'cinza', texto: ['20  40'] },
    { id: 'n1', x: 720, y: 930, w: 130, h: 80, cor: 'cinza', texto: ['10'] },
    { id: 'n2', x: 935, y: 930, w: 130, h: 80, cor: 'cinza', texto: ['30'] },
    { id: 'n3', x: 1150, y: 930, w: 130, h: 80, cor: 'cinza', texto: ['50'] },
  ],
  setas: [
    { pontos: [[380, 300], [480, 300]], cor: 'roxo' },
    { pontos: [[740, 300], [840, 300]], cor: 'roxo' },
    { pontos: [[1100, 300], [1210, 300]], cor: 'roxo' },
    { de: 'n0', para: 'n1', lados: 'bc', cor: 'cinza' },
    { de: 'n0', para: 'n2', lados: 'bc', cor: 'cinza' },
    { de: 'n0', para: 'n3', lados: 'bc', cor: 'cinza' },
    { pontos: [[480, 870], [690, 870]], rotulo: 'é a mesma coisa que', cor: 'cinza' },
  ],
  notas: [
    { x: 100, y: 218, texto: 'INSERE 20: OS TRÊS CONSERTOS, UM ATRÁS DO OUTRO', cor: 'cinza' },
    nota(110, 600, ['1. vermelho só à direita', 'gira à esquerda no 10']),
    nota(500, 600, ['2. dois vermelhos seguidos', 'gira à direita no 30']),
    nota(860, 600, ['3. dois filhos vermelhos', 'inverte as cores']),
    nota(1230, 600, ['raiz preta,', 'altura preta 2'], 'verde'),
    { x: 100, y: 715, texto: 'DEPOIS DA TAG 40: RUBRO-NEGRA E ÁRVORE 2-3', cor: 'cinza' },
    nota(110, 1130, ['o 20 vermelho "cola" no 40:', 'os dois formam um nó de 2 chaves']),
    nota(720, 1090, ['todas as folhas no mesmo nível'], 'verde'),
    nota(1180, 1050, ['vermelho: nó vermelho', 'cinza: nó preto'], 'vermelho'),
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Na volta da inserção, em h'],
    ['B', 'dec', 'Vermelho só à direita?'],
    ['C', 'proc', 'h = gira_esquerda(h)'],
    ['D', 'dec', 'Dois vermelhos seguidos à esquerda?'],
    ['E', 'proc', 'h = gira_direita(h)'],
    ['F', 'dec', 'Dois filhos vermelhos?'],
    ['G', 'proc', 'inverte_cores(h)'],
    ['H', 'io', 'Devolver h'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C', 'Sim'],
    ['B', 'D', 'Não'],
    ['C', 'D'],
    ['D', 'E', 'Sim'],
    ['D', 'F', 'Não'],
    ['E', 'F'],
    ['F', 'G', 'Sim'],
    ['F', 'H', 'Não'],
    ['G', 'H'],
  ],
  caminho: ['A', 'B', 'D', 'E', 'F', 'G', 'H'],
}
