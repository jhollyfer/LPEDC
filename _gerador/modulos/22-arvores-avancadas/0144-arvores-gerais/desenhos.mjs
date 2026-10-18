// Em cima, o orçamento como árvore geral (cada pai ligado a todos os filhos);
// embaixo, o mesmo orçamento na memória: seta verde = filho (primeiro filho),
// seta roxa = irmao (próximo irmão).
const no = (id, x, y, texto, cor = 'azul') => ({
  id, x, y, w: 220, h: [].concat(texto).length > 1 ? 110 : 70, cor, texto: [].concat(texto),
})

export const ideia = {
  caixas: [
    // árvore geral (em cima): os grupos mostram o total
    no('g0', 690, 130, ['reforma', 'total 5250'], 'cinza'),
    no('g1', 280, 320, ['cozinha', 'total 2450'], 'cinza'),
    no('g2', 690, 320, ['banheiro', 'total 1600'], 'roxo'),
    no('g3', 1100, 320, 'pintura 1200'),
    no('g4', 160, 510, 'piso 1800'),
    no('g5', 400, 510, 'pia 650'),
    no('g6', 640, 510, 'box 900'),
    no('g7', 880, 510, ['loucas', 'total 700'], 'cinza'),
    no('g8', 760, 700, 'vaso 420'),
    no('g9', 1000, 700, 'cuba 280'),
    // primeiro filho / próximo irmão (embaixo): cada fila de irmãos numa linha
    no('b0', 120, 960, 'reforma', 'cinza'),
    no('b1', 120, 1110, 'cozinha', 'cinza'),
    no('b2', 720, 1110, 'banheiro', 'roxo'),
    no('b3', 1020, 1110, 'pintura 1200'),
    no('b4', 120, 1260, 'piso 1800'),
    no('b5', 420, 1260, 'pia 650'),
    no('b6', 720, 1260, 'box 900'),
    no('b7', 1020, 1260, 'loucas', 'cinza'),
    no('b8', 1020, 1410, 'vaso 420'),
    no('b9', 1320, 1410, 'cuba 280'),
  ],
  setas: [
    { de: 'g0', para: 'g1', cor: 'cinza', lados: 'bc' },
    { de: 'g0', para: 'g2', cor: 'cinza', lados: 'bc' },
    { de: 'g0', para: 'g3', cor: 'cinza', lados: 'bc' },
    { de: 'g1', para: 'g4', cor: 'cinza', lados: 'bc' },
    { de: 'g1', para: 'g5', cor: 'cinza', lados: 'bc' },
    { de: 'g2', para: 'g6', cor: 'cinza', lados: 'bc' },
    { de: 'g2', para: 'g7', cor: 'cinza', lados: 'bc' },
    { de: 'g7', para: 'g8', cor: 'cinza', lados: 'bc' },
    { de: 'g7', para: 'g9', cor: 'cinza', lados: 'bc' },
    // filho (verde, para baixo) e irmão (roxo, para o lado)
    { de: 'b0', para: 'b1', cor: 'verde' },
    { de: 'b1', para: 'b2', cor: 'roxo' },
    { de: 'b2', para: 'b3', cor: 'roxo' },
    { de: 'b1', para: 'b4', cor: 'verde' },
    { de: 'b4', para: 'b5', cor: 'roxo' },
    { de: 'b2', para: 'b6', cor: 'verde' },
    { de: 'b6', para: 'b7', cor: 'roxo' },
    { de: 'b7', para: 'b8', cor: 'verde' },
    { de: 'b8', para: 'b9', cor: 'roxo' },
  ],
  notas: [
    { x: 100, y: 100, texto: 'COMO VOCÊ PENSA: cada pai ligado a todos os filhos', cor: 'cinza' },
    { x: 100, y: 920, texto: 'NA MEMÓRIA: dois ponteiros por nó', cor: 'cinza' },
    { x: 1000, y: 990, texto: '↓ verde: filho (o primeiro)', cor: 'verde' },
    { x: 1000, y: 1030, texto: '→ roxo: irmao (o próximo)', cor: 'roxo' },
    { x: 400, y: 1220, texto: 'pia->irmao = NULL', cor: 'cinza', tam: 22 },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'ag_total(r)'],
    ['B', 'proc', 'soma = r->valor'],
    ['C', 'proc', 'p = r->filho'],
    ['D', 'dec', 'p != NULL?'],
    ['E', 'proc', 'soma += ag_total(p)'],
    ['F', 'proc', 'p = p->irmao'],
    ['G', 'io', 'Devolver soma'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D'],
    ['D', 'E', 'Sim'],
    ['E', 'F'],
    ['F', 'D'],
    ['D', 'G', 'Não'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'F', 'D', 'G'],
}
