export const ideia = {
  caixas: [
    { id: 'p', forma: 'pilha', x: 120, y: 90, itens: ['R$ 25,90', 'R$ 8,00', 'R$ 12,00'], estados: { 2: 'verde' }, titulo: 'o pedido (a pilha)' },
    {
      id: 'v',
      forma: 'array',
      x: 720,
      y: 60,
      nome: 'itens',
      itens: ['2590', '800', '1200', '', '', ''],
      estados: { 2: 'verde', 3: 'apagado', 4: 'apagado', 5: 'apagado' },
      celula: 120,
    },
    { id: 't', forma: 'terminal', x: 1000, y: 380, w: 470, texto: ['Desfeito: R$ 12,00', 'Agora no topo: R$ 8,00'] },
  ],
  setas: [
    { de: 'p', para: 'v', rotulo: 'por dentro' },
    { pontos: [[1150, 300], [1240, 372]], rotulo: 'pop', cor: 'verde', dx: 40 },
  ],
  notas: [
    { x: 1140, y: 40, texto: 'n = 3: próxima vaga', cor: 'roxo', ancora: 'middle' },
    { x: 780, y: 290, texto: 'fundo', cor: 'cinza', ancora: 'middle' },
    { x: 1000, y: 290, texto: 'topo = itens[n - 1]', cor: 'verde', ancora: 'middle' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início: desfazer'],
    ['B', 'dec', 'pilha vazia (n == 0)?'],
    ['C', 'io', 'Mostrar "nada para desfazer"'],
    ['D', 'proc', 'n = n - 1'],
    ['E', 'proc', 'preco = itens[n]'],
    ['F', 'io', 'Mostrar "Desfeito: R$ 12,00"'],
    ['G', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C', 'Sim'],
    ['B', 'D', 'Não'],
    ['D', 'E'],
    ['E', 'F'],
    ['C', 'G'],
    ['F', 'G'],
  ],
  caminho: ['A', 'B', 'D', 'E', 'F', 'G'],
}
