export const ideia = {
  caixas: [
    {
      id: 'v',
      forma: 'array',
      x: 140,
      y: 40,
      nome: 'passos',
      itens: ['8200', '10450', '6300', '12000', '9100', '15300', '7400'],
      celula: 160,
      estados: { 5: 'verde' },
    },
    { id: 't', x: 140, y: 330, w: 520, cor: 'roxo', rotulo: 'soma as 7 gavetas', texto: ['total = 68750', 'média = 9821.4'] },
    { id: 'm', x: 860, y: 330, w: 500, cor: 'verde', rotulo: 'a maior', texto: ['passos[5] = 15300', 'dia 5 + 1 = dia 6'] },
  ],
  setas: [
    { pontos: [[400, 230], [400, 314]], rotulo: 'i de 0 a 6' },
    { pontos: [[1020, 245], [1020, 314]], cor: 'verde' },
  ],
  notas: [
    { x: 1230, y: 270, texto: ['passos[7]', 'não existe'], cor: 'vermelho' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'proc', 'maior = passos[0]; total = 0'],
    ['C', 'proc', 'i = 0'],
    ['D', 'dec', 'i < 7?'],
    ['E', 'proc', 'total += passos[i]'],
    ['F', 'dec', 'passos[i] > maior?'],
    ['G', 'proc', 'maior = passos[i]; dia = i'],
    ['H', 'proc', 'i++'],
    ['I', 'io', 'Mostrar total, média e dia + 1'],
    ['J', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D'],
    ['D', 'E', 'Sim'],
    ['E', 'F'],
    ['F', 'G', 'Sim'],
    ['F', 'H', 'Não'],
    ['G', 'H'],
    ['H', 'D'],
    ['D', 'I', 'Não'],
    ['I', 'J'],
  ],
}
