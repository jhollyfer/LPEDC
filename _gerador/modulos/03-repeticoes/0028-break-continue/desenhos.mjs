// um laço com duas portas: o break sai do laço; o continue volta direto para
// a leitura, pulando a soma
export const ideia = {
  caixas: [
    { id: 'l', x: 100, y: 60, w: 300, cor: 'azul', rotulo: 'lê', texto: ['preço'] },
    { id: 'p1', x: 520, y: 35, w: 300, h: 200, forma: 'losango', cor: 'amarelo', texto: ['preço == 0 ?'] },
    { id: 't', forma: 'terminal', x: 1000, y: 55, w: 400, texto: ['Itens: 3', 'Total: R$ 25.40'] },
    { id: 'p2', x: 520, y: 330, w: 300, h: 200, forma: 'losango', cor: 'amarelo', texto: ['preço < 0 ?'] },
    { id: 's', x: 520, y: 620, w: 300, cor: 'roxo', rotulo: 'soma', texto: ['total += preço', 'itens++'] },
  ],
  setas: [
    { de: 'l', para: 'p1' },
    { de: 'p1', para: 't', lados: 'de', rotulo: 'Sim: break', cor: 'verde' },
    { de: 'p1', para: 'p2', lados: 'bc', rotulo: 'Não', cor: 'vermelho' },
    { pontos: [[504, 430], [260, 430], [260, 226]], rotulo: 'Sim: continue', cor: 'verde', dx: -40 },
    { de: 'p2', para: 's', lados: 'bc', rotulo: 'Não', cor: 'vermelho' },
    { pontos: [[504, 715], [150, 715], [150, 226]], rotulo: 'volta', cor: 'roxo', dy: -14 },
  ],
  notas: [
    { x: 960, y: 420, texto: '12.90  soma', cor: 'verde' },
    { x: 960, y: 458, texto: '-1     continue (pula a soma)', cor: 'roxo' },
    { x: 960, y: 496, texto: '8.50   soma', cor: 'verde' },
    { x: 960, y: 534, texto: '4.00   soma', cor: 'verde' },
    { x: 960, y: 572, texto: '0      break (sai do laço)', cor: 'vermelho' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'io', 'Ler preço'],
    ['C', 'dec', 'preço == 0?'],
    ['D', 'dec', 'preço < 0? (continue)'],
    ['F', 'proc', 'total += preço; itens++'],
    ['G', 'io', 'Mostrar itens e total'],
    ['H', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'G', 'Sim'],
    ['C', 'D', 'Não'],
    ['D', 'F', 'Não'],
    ['D', 'B', 'Sim'],
    ['F', 'B'],
    ['G', 'H'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'F', 'B', 'C', 'D', 'B', 'C', 'D', 'F', 'B', 'C', 'G', 'H'],
}
