const letras = ['M', 'a', 'r', 'i', 'a', ' ', 'C', 'l', 'a', 'r', 'a']

export const ideia = {
  caixas: [
    { id: 't', forma: 'terminal', x: 120, y: 0, w: 520, texto: ['Nome completo: Maria Clara'] },
    {
      id: 'a',
      forma: 'array',
      x: 120,
      y: 210,
      nome: 'depois do fgets',
      itens: [...letras, '\\n', '\\0', '?'],
      celula: 92,
      estados: { 11: 'amarelo', 12: 'roxo', 13: 'apagado' },
    },
    {
      id: 'b',
      forma: 'array',
      x: 120,
      y: 520,
      nome: 'depois do strcspn',
      itens: [...letras, '\\0', '\\0', '?'],
      celula: 92,
      estados: { 11: 'verde', 12: 'apagado', 13: 'apagado' },
    },
  ],
  setas: [
    { pontos: [[380, 140], [380, 205]], rotulo: 'fgets(nome, 40, stdin)' },
    { pontos: [[1178, 400], [1178, 565]], rotulo: 'nome[11] = \'\\0\'', cor: 'verde' },
  ],
  notas: [
    { x: 760, y: 70, texto: 'cabem 40 bytes; o fgets usa 13', cor: 'cinza' },
    { x: 1178, y: 200, texto: 'o Enter', cor: 'vermelho', ancora: 'middle' },
    { x: 700, y: 440, texto: 'strcspn(nome, "\\n") = 11', cor: 'roxo' },
    { x: 120, y: 730, texto: 'strlen = 11: o texto acaba antes do Enter', cor: 'verde' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'io', 'Mostrar "Nome completo:"'],
    ['C', 'io', 'fgets(nome, 40, stdin)'],
    ['D', 'dec', 'devolveu NULL?'],
    ['E', 'io', 'Mostrar "Nada foi digitado."'],
    ['F', 'proc', "nome[strcspn(nome, \"\\n\")] = '\\0'"],
    ['G', 'io', 'Mostrar "Olá, Maria Clara!" e 11'],
    ['H', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D'],
    ['D', 'E', 'Sim'],
    ['D', 'F', 'Não'],
    ['F', 'G'],
    ['E', 'H'],
    ['G', 'H'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'F', 'G', 'H'],
}
