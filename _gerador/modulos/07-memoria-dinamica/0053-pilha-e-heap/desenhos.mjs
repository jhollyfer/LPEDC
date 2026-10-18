export const ideia = {
  caixas: [
    { id: 'cod', x: 100, y: 60, w: 260, h: 230, cor: 'cinza', rotulo: 'código', texto: ['main', 'abrir_comanda', '"Sem memória"'] },
    { id: 'dad', x: 400, y: 60, w: 280, h: 230, cor: 'azul', rotulo: 'dados', texto: ['pedidos_do_dia', '= 1'] },
    { id: 'hp', x: 720, y: 60, w: 300, h: 230, cor: 'verde', rotulo: 'heap', texto: [] },
    { id: 'blk', forma: 'array', x: 735, y: 150, itens: ['18', '25', '7'], celula: 90, cor: 'verde', indices: false },
    { id: 'liv', x: 1060, y: 60, w: 150, h: 230, cor: 'cinza', rotulo: 'livre', texto: [] },
    { id: 'pil', forma: 'pilha', x: 1250, y: 60, w: 250, topo: false, titulo: 'pilha', itens: [['main()', 'comanda'], ['abrir_comanda()', 'mesa = 4', 'itens = 3']], estados: { 1: 'apagado' } },
  ],
  setas: [
    { pontos: [[1300, 332], [1300, 400], [870, 400], [870, 246]], rotulo: 'comanda guarda o endereço do bloco', dx: -70, dy: 40 },
    { pontos: [[180, 470], [1420, 470]], cor: 'cinza' },
  ],
  notas: [
    { x: 1375, y: 30, texto: 'some no return', cor: 'vermelho', ancora: 'middle', tam: 22 },
    { x: 1080, y: 200, texto: ['heap', 'cresce →'], cor: 'cinza', tam: 20 },
    { x: 100, y: 520, texto: 'endereços baixos', cor: 'cinza', tam: 22 },
    { x: 1500, y: 520, texto: 'endereços altos', cor: 'cinza', tam: 22, ancora: 'end' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'proc', 'abrir_comanda(4): frame com itens = 3'],
    ['C', 'proc', 'malloc: bloco de 3 ints no heap'],
    ['D', 'dec', 'comanda != NULL?'],
    ['E', 'proc', 'preenche 18, 25, 7 e pedidos_do_dia++'],
    ['F', 'proc', 'return: o frame some, o bloco fica'],
    ['G', 'io', 'Total: R$ 50'],
    ['H', 'proc', 'free(comanda)'],
    ['I', 'io', 'Sem memória'],
    ['J', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D'],
    ['D', 'E', 'Sim'],
    ['D', 'I', 'Não'],
    ['E', 'F'],
    ['F', 'G'],
    ['G', 'H'],
    ['H', 'J'],
    ['I', 'J'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'J'],
}
