export const ideia = {
  caixas: [
    {
      id: 'v',
      forma: 'array',
      x: 110,
      y: 190,
      itens: ['39', '40', '33', '34', '35', '36', '37', '38'],
      estados: { 0: 'verde', 1: 'verde', 2: 'apagado', 3: 'apagado' },
      celula: 110,
    },
    { id: 't', forma: 'terminal', x: 1110, y: 40, w: 380, texto: ['Na fila (6):', '35 36 37 38 39 40'] },
  ],
  setas: [
    { pontos: [[385, 120], [385, 182]], cor: 'roxo' },
    { pontos: [[605, 80], [605, 182]], cor: 'roxo' },
    { pontos: [[990, 232], [1040, 232], [1040, 360], [165, 360], [165, 330]], cor: 'verde' },
  ],
  notas: [
    { x: 385, y: 105, texto: 'fim: próxima vaga', cor: 'roxo', ancora: 'middle' },
    { x: 605, y: 65, texto: 'início: sai primeiro', cor: 'roxo', ancora: 'middle' },
    { x: 330, y: 410, texto: 'cinza: 33 e 34 já saíram, a gaveta virou vaga', cor: 'cinza' },
    { x: 330, y: 450, texto: 'verde: 39 e 40 deram a volta, (7 + 1) % 8 = 0', cor: 'verde' },
    { x: 1110, y: 270, texto: ['inicio = 4, n = 6', 'fim = (4 + 6) % 8 = 2'], cor: 'roxo' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início: insere 39'],
    ['B', 'dec', 'n == CAPACIDADE?'],
    ['C', 'io', 'Devolver false (cheia)'],
    ['D', 'proc', 'fim = (4 + 4) % 8 = 0'],
    ['E', 'proc', 'itens[0] = 39'],
    ['F', 'proc', 'n = n + 1'],
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
