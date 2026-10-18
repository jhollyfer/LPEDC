const linha = (i, texto, cor = 'azul') => ({
  id: 't' + i,
  x: 100,
  y: i * 150,
  w: 600,
  h: 130,
  cor,
  rotulo: `tabela[${i}]`,
  texto: [texto],
})

export const ideia = {
  caixas: [
    linha(0, 'Bahia: 8V 5E 3D = 29 pts'),
    linha(1, 'Flamengo: 9V 6E 1D = 33 pts'),
    linha(2, 'Palmeiras: 10V 4E 2D = 34 pts', 'verde'),
    linha(3, 'Vasco: 7V 7E 2D = 28 pts'),
    { id: 'conta', x: 900, y: 60, w: 520, cor: 'roxo', rotulo: 'para cada time', texto: ['pontos = 3 * v + e', 'maior até agora?'] },
    { id: 'res', x: 900, y: 360, w: 520, cor: 'verde', rotulo: 'resultado', texto: ['lider = 2', 'Palmeiras, 34 pontos'] },
  ],
  setas: [
    { de: 't1', para: 'conta', lados: 'de' },
    { de: 'conta', para: 'res' },
    { de: 't2', para: 'res', lados: 'de', cor: 'verde' },
  ],
  notas: [{ x: 400, y: 640, texto: 'cada linha: um Time de 32 bytes, todos colados', cor: 'cinza', ancora: 'middle' }],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'proc', 'lider = 0; i = 0'],
    ['C', 'dec', 'i < 4?'],
    ['D', 'dec', 'pontos de i > pontos do líder?'],
    ['E', 'proc', 'lider = i'],
    ['F', 'proc', 'i++'],
    ['G', 'io', 'Líder: Palmeiras, 34 pontos'],
    ['H', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D', 'Sim'],
    ['D', 'E', 'Sim'],
    ['D', 'F', 'Não'],
    ['E', 'F'],
    ['F', 'C'],
    ['C', 'G', 'Não'],
    ['G', 'H'],
  ],
}
