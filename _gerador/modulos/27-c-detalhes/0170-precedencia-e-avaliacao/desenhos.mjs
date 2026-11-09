// duas árvores de expressão: o operador de menor precedência fica na raiz
export const ideia = {
  caixas: [
    // preco * qtd + frete
    { id: 'r1', x: 290, y: 40, w: 220, h: 110, cor: 'roxo', texto: ['+  → 66'] },
    { id: 'm1', x: 120, y: 230, w: 220, h: 110, cor: 'roxo', texto: ['*  → 54'] },
    { id: 'f1', x: 440, y: 230, w: 240, h: 110, cor: 'azul', texto: ['frete = 12'] },
    { id: 'p1', x: 100, y: 420, w: 220, h: 110, cor: 'azul', texto: ['preco = 18'] },
    { id: 'q1', x: 360, y: 420, w: 200, h: 110, cor: 'azul', texto: ['qtd = 3'] },
    // compra + compra >= 50 ? 0 : frete
    { id: 'r2', x: 1060, y: 40, w: 220, h: 110, cor: 'amarelo', texto: ['?:  → 0'] },
    { id: 'c2', x: 860, y: 230, w: 240, h: 110, cor: 'amarelo', texto: ['>=  → 1'] },
    { id: 'z2', x: 1140, y: 230, w: 120, h: 110, cor: 'verde', texto: ['0'] },
    { id: 'fr2', x: 1300, y: 230, w: 220, h: 110, cor: 'cinza', texto: ['frete'] },
    { id: 's2', x: 800, y: 420, w: 240, h: 110, cor: 'roxo', texto: ['+  → 108'] },
    { id: 'n2', x: 1080, y: 420, w: 120, h: 110, cor: 'azul', texto: ['50'] },
    { id: 'a2', x: 720, y: 610, w: 220, h: 110, cor: 'azul', texto: ['compra = 54'] },
    { id: 'b2', x: 980, y: 610, w: 220, h: 110, cor: 'azul', texto: ['compra = 54'] },
  ],
  setas: [
    { de: 'r1', para: 'm1', lados: 'bc' },
    { de: 'r1', para: 'f1', lados: 'bc' },
    { de: 'm1', para: 'p1', lados: 'bc' },
    { de: 'm1', para: 'q1', lados: 'bc' },
    { de: 'r2', para: 'c2', lados: 'bc' },
    { de: 'r2', para: 'z2', lados: 'bc', cor: 'verde' },
    { de: 'r2', para: 'fr2', lados: 'bc', cor: 'cinza' },
    { de: 'c2', para: 's2', lados: 'bc' },
    { de: 'c2', para: 'n2', lados: 'bc' },
    { de: 's2', para: 'a2', lados: 'bc' },
    { de: 's2', para: 'b2', lados: 'bc' },
  ],
  notas: [
    { x: 100, y: 610, texto: ['preco * qtd + frete', 'total = 66'], cor: 'roxo' },
    { x: 720, y: 790, texto: ['compra + compra >= 50 ? 0 : frete', 'pegadinha = 0'], cor: 'vermelho' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'proc', 'total = 18 * 3 + 12 (66)'],
    ['C', 'proc', 'sobra = 100 - 66 - 20 (14)'],
    ['D', 'proc', 'compra = 18 * 3 (54)'],
    ['E', 'dec', 'compra >= 50?'],
    ['F', 'proc', 'parcela do frete = 0'],
    ['G', 'proc', 'parcela do frete = 12'],
    ['H', 'io', 'certo = 54 + 0 = 54'],
    ['I', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D'],
    ['D', 'E'],
    ['E', 'F', 'Sim'],
    ['E', 'G', 'Não'],
    ['F', 'H'],
    ['G', 'H'],
    ['H', 'I'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'F', 'H', 'I'],
}
