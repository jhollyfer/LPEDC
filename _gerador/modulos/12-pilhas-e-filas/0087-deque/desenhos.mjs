export const ideia = {
  caixas: [
    {
      id: 'v',
      forma: 'array',
      x: 110,
      y: 190,
      itens: ['5', '8', '3', '', '', '', '', '11'],
      estados: { 3: 'apagado', 4: 'apagado', 5: 'apagado', 6: 'apagado', 7: 'verde' },
      celula: 110,
    },
    { id: 't', forma: 'terminal', x: 1110, y: 40, w: 380, texto: ['Tocando a faixa 11', 'Removida a faixa 3'] },
  ],
  setas: [
    { pontos: [[935, 80], [935, 182]], cor: 'verde' },
    { pontos: [[385, 120], [385, 182]], cor: 'roxo' },
    { pontos: [[165, 340], [165, 380], [935, 380], [935, 340]], cor: 'verde' },
  ],
  notas: [
    { x: 935, y: 65, texto: 'início (era 0, recuou)', cor: 'verde', ancora: 'middle' },
    { x: 385, y: 105, texto: 'fim: próxima vaga', cor: 'roxo', ancora: 'middle' },
    { x: 550, y: 430, texto: 'insere_inicio(11): anterior(0) = (0 - 1 + 8) % 8 = 7', cor: 'verde', ancora: 'middle' },
    { x: 1110, y: 270, texto: ['retira_inicio: sai o 11', 'retira_fim: sai o 3', 'sobram 5 e 8'], cor: 'roxo' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início: insere 11 no início'],
    ['B', 'dec', 'n == CAPACIDADE?'],
    ['C', 'io', 'Devolver false (cheio)'],
    ['D', 'proc', 'inicio = anterior(0) = 7'],
    ['E', 'proc', 'itens[7] = 11'],
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
