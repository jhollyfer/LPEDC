export const ideia = {
  caixas: [
    { id: 'total', forma: 'caixinha', x: 100, y: 300, nome: 'total', valor: 'R$ 230', tipo: 'double' },
    { id: 'p', x: 430, y: 325, w: 320, h: 200, forma: 'losango', cor: 'amarelo', texto: ['total >= 200 ?'] },
    { id: 'd', x: 860, y: 140, w: 350, cor: 'roxo', rotulo: 'desconto', texto: ['total = total * 0.9'] },
    { id: 't', forma: 'terminal', x: 1120, y: 360, w: 380, texto: ['Total: R$ 230.00', 'A pagar: R$ 207.00'] },
  ],
  setas: [
    { de: 'total', para: 'p' },
    { de: 'p', para: 'd', lados: 'ce', cotovelo: true, rotulo: 'Sim', cor: 'verde' },
    { de: 'd', para: 't', lados: 'dc', cotovelo: true, cor: 'verde' },
    {
      pontos: [
        [590, 541],
        [590, 640],
        [1310, 640],
        [1310, 556],
      ],
      rotulo: 'Não: pula o desconto',
      cor: 'cinza',
    },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'io', 'Ler total (230)'],
    ['C', 'dec', 'total >= 200?'],
    ['D', 'proc', 'total = total * 0.9'],
    ['E', 'io', 'Mostrar o total a pagar'],
    ['F', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D', 'Sim'],
    ['C', 'E', 'Não'],
    ['D', 'E'],
    ['E', 'F'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'F'],
}
