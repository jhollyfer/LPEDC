// a tabela dp dos selos {1, 4, 5}: dp[8] olha para dp[7], dp[4] e dp[3]
// (um vizinho por selo) e fica com o menor, dp[4] + 1 = 2
const X = 110
const Y = 300
const CEL = 130
const meio = (i) => X + i * CEL + CEL / 2
const topo = Y + 54 // o array tem nome: as gavetas começam 54 px abaixo

// seta que sai do topo da gaveta i, sobe até a altura h e desce na gaveta 8
const arco = (i, h, rotulo, cor) => ({
  pontos: [
    [meio(i), topo - 6],
    [meio(i), h],
    [meio(8) - 40 + (8 - i) * 16, h],
    [meio(8) - 40 + (8 - i) * 16, topo - 8],
  ],
  rotulo,
  cor,
})

export const ideia = {
  caixas: [
    {
      id: 'dp',
      forma: 'array',
      x: X,
      y: Y,
      nome: 'dp',
      celula: CEL,
      itens: [0, 1, 2, 3, 1, 1, 2, 3, 2],
      estados: { 3: 'amarelo', 4: 'verde', 7: 'amarelo', 8: 'roxo' },
    },
    {
      id: 'gul',
      x: X,
      y: 540,
      w: 560,
      h: 170,
      cor: 'vermelho',
      rotulo: 'guloso (maior selo primeiro)',
      texto: ['5 + 1 + 1 + 1 = 4 selos'],
    },
    {
      id: 'pd',
      x: 760,
      y: 540,
      w: 560,
      h: 170,
      cor: 'verde',
      rotulo: 'programação dinâmica',
      texto: ['4 + 4 = 2 selos'],
    },
  ],
  setas: [
    arco(7, 250, 'selo 1: 3 + 1', 'cinza'),
    arco(4, 170, 'selo 4: 1 + 1 = 2', 'verde'),
    arco(3, 90, 'selo 5: 3 + 1', 'cinza'),
  ],
  notas: [{ x: 1340, y: 420, texto: 'v = 8', cor: 'roxo' }],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'proc', 'dp[0] = 0; v = 1'],
    ['C', 'dec', 'v <= porte?'],
    ['D', 'proc', 'dp[v] = INF; testa cada selo s <= v'],
    ['E', 'proc', 'dp[v] = menor dp[v - s] + 1; anota ultimo[v]'],
    ['F', 'proc', 'v++'],
    ['G', 'io', 'Mostra dp[porte] e volta por ultimo[]'],
    ['H', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D', 'Sim'],
    ['D', 'E'],
    ['E', 'F'],
    ['F', 'C'],
    ['C', 'G', 'Não'],
    ['G', 'H'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'F', 'C', 'G', 'H'],
}
