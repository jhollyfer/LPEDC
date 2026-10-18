export const ideia = {
  caixas: [
    { id: 'pil', forma: 'pilha', x: 110, y: 60, w: 330, topo: false, titulo: 'pilha', itens: [['main()', 'pedido = 30 12 45 8'], ['total_do_pedido()', 'copia = ●']], estados: { 1: 'apagado' } },
    { id: 'hp', x: 700, y: 20, w: 760, h: 420, cor: 'cinza', rotulo: 'heap (sem o free)', texto: [] },
    { id: 'b1', forma: 'array', x: 740, y: 110, itens: ['30', '12', '45', '8'], celula: 90, cor: 'vermelho', indices: false },
    { id: 'b2', forma: 'array', x: 740, y: 220, itens: ['30', '12', '45', '8'], celula: 90, cor: 'vermelho', indices: false },
    { id: 'b3', forma: 'array', x: 740, y: 330, itens: ['30', '12', '45', '8'], celula: 90, cor: 'vermelho', indices: false },
    { id: 't', forma: 'terminal', x: 700, y: 500, w: 760, texto: ['48 byte(s) leaked in 3 allocation(s)'] },
    { id: 'x', forma: 'marca', x: 505, y: 100, tamanho: 50 },
    { id: 'ok', x: 110, y: 500, w: 470, cor: 'verde', rotulo: 'com free(copia)', texto: ['0 bytes perdidos'] },
  ],
  setas: [
    { pontos: [[450, 125], [600, 125], [600, 375], [732, 375]], cor: 'vermelho' },
  ],
  notas: [
    { x: 110, y: 395, texto: ['o frame morreu: ninguém', 'mais acha o bloco'], cor: 'vermelho', tam: 24 },
    { x: 1130, y: 160, texto: 'pedido 1: 16 bytes', cor: 'vermelho', tam: 24 },
    { x: 1130, y: 270, texto: 'pedido 2: 16 bytes', cor: 'vermelho', tam: 24 },
    { x: 1130, y: 380, texto: 'pedido 3: 16 bytes', cor: 'vermelho', tam: 24 },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'dec', 'falta algum pedido?'],
    ['C', 'proc', 'copia = malloc(16 bytes)'],
    ['D', 'proc', 'soma 30 + 12 + 45 + 8'],
    ['E', 'proc', 'free(copia)'],
    ['F', 'proc', 'return 95: o frame some'],
    ['G', 'io', 'Pedido N: R$ 95'],
    ['H', 'inicio', 'Fim: 0 bytes perdidos'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C', 'Sim'],
    ['C', 'D'],
    ['D', 'E'],
    ['E', 'F'],
    ['F', 'G'],
    ['G', 'B'],
    ['B', 'H', 'Não'],
  ],
}
