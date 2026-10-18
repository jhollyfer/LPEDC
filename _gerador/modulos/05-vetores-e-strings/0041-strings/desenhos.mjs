export const ideia = {
  caixas: [
    {
      id: 'c',
      forma: 'array',
      x: 120,
      y: 60,
      nome: 'cracha[20]',
      itens: ['B', 'r', 'u', 'n', 'a', ' ', 'M', 'a', 't', 'o', 's', '\\0', '?', '?'],
      celula: 92,
      estados: { 11: 'amarelo', 12: 'apagado', 13: 'apagado' },
    },
    { id: 'l', x: 120, y: 360, w: 400, cor: 'roxo', rotulo: 'strlen(cracha)', texto: ['11 caracteres'] },
    { id: 's', x: 580, y: 360, w: 360, cor: 'cinza', rotulo: 'sizeof(cracha)', texto: ['20 bytes'] },
    { id: 'p', x: 1000, y: 360, w: 460, cor: 'verde', rotulo: 'strcmp(cracha, ...)', texto: ['0: confere'] },
  ],
  setas: [
    { pontos: [[166, 300], [1110, 300]], rotulo: 'conta 11 até o \\0', cor: 'roxo' },
  ],
  notas: [
    { x: 1350, y: 40, texto: '... até a 19', cor: 'cinza' },
    { x: 1168, y: 50, texto: 'fim', cor: 'vermelho', ancora: 'middle' },
    { x: 626, y: 50, texto: 'espaço', cor: 'cinza', ancora: 'middle' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'proc', 'cracha = "Bruna " (strcpy e strcat)'],
    ['C', 'proc', 'i = 0'],
    ['D', 'dec', "cracha[i] == '\\0'?"],
    ['E', 'proc', 'i++'],
    ['F', 'proc', 'copia "Matos" a partir de cracha[i]'],
    ['G', 'proc', "põe '\\0' no fim"],
    ['H', 'io', 'Mostrar "Bruna Matos"'],
    ['I', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C', 'strcat(cracha, "Matos")'],
    ['C', 'D'],
    ['D', 'E', 'Não'],
    ['E', 'D'],
    ['D', 'F', 'Sim'],
    ['F', 'G'],
    ['G', 'H'],
    ['H', 'I'],
  ],
}
