export const ideia = {
  caixas: [
    { id: 'x', forma: 'caixinha', x: 100, y: 50, nome: 'x', valor: '1290', tipo: 'procurado' },
    {
      id: 'v',
      forma: 'array',
      x: 460,
      y: 110,
      celula: 130,
      itens: ['4172', '3305', '8821', '1290', '5567', '7034'],
      estados: { 0: 'amarelo', 1: 'amarelo', 2: 'amarelo', 3: 'verde', 4: 'apagado', 5: 'apagado' },
    },
    { id: 't', forma: 'terminal', x: 460, y: 360, w: 520, texto: ['posição 3', '4 comparações'] },
  ],
  setas: [
    { de: 'x', para: 'v', rotulo: 'compara' },
    { pontos: [[915, 250], [915, 350]], cor: 'verde', rotulo: 'achou' },
  ],
  notas: [
    { x: 525, y: 92, texto: '1ª ≠', cor: 'roxo', ancora: 'middle' },
    { x: 655, y: 92, texto: '2ª ≠', cor: 'roxo', ancora: 'middle' },
    { x: 785, y: 92, texto: '3ª ≠', cor: 'roxo', ancora: 'middle' },
    { x: 915, y: 92, texto: '4ª =', cor: 'verde', ancora: 'middle' },
    { x: 1110, y: 92, texto: 'nem olha', cor: 'cinza', ancora: 'middle' },
    { x: 1060, y: 410, texto: ['olha uma gaveta', 'por vez, da esquerda', 'para a direita'], cor: 'roxo' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'io', 'Ler x (1290)'],
    ['C', 'proc', 'i = 0'],
    ['D', 'dec', 'i < n?'],
    ['E', 'dec', 'v[i] == x?'],
    ['F', 'proc', 'i = i + 1'],
    ['G', 'io', 'Mostrar i (3)'],
    ['H', 'io', 'Mostrar -1'],
    ['I', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D'],
    ['D', 'E', 'Sim'],
    ['E', 'G', 'Sim'],
    ['E', 'F', 'Não'],
    ['F', 'D'],
    ['D', 'H', 'Não'],
    ['G', 'I'],
    ['H', 'I'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'F', 'D', 'E', 'G', 'I'],
}
