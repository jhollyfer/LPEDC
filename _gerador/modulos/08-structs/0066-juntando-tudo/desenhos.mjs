const linha = (y, prefixo, nome, tags, res, passa) => [
  { id: prefixo + 't', forma: 'array', x: 100, y, celula: 90, indices: false, nome, itens: tags },
  { id: prefixo + 'm', forma: 'array', x: 530, y, celula: 90, indices: false, nome: 'máscara V|SG', itens: ['0', '1', '1'], cor: 'roxo' },
  {
    id: prefixo + 'r',
    forma: 'array',
    x: 960,
    y,
    celula: 90,
    indices: false,
    nome: 'tags & máscara',
    itens: res,
    cor: passa ? 'verde' : 'vermelho',
  },
]

export const ideia = {
  caixas: [
    ...linha(60, 's', 'Suco de caju', ['0', '1', '1'], ['0', '1', '1'], true),
    ...linha(330, 'b', 'Burger de grão-de-bico', ['0', '0', '1'], ['0', '0', '1'], false),
    { id: 'ok', x: 1430, y: 100, w: 220, h: 110, cor: 'verde', texto: ['passa'] },
    { id: 'nao', x: 1430, y: 370, w: 220, h: 110, cor: 'vermelho', texto: ['fica fora'] },
  ],
  setas: [
    { de: 'sr', para: 'ok', rotulo: '== máscara' },
    { de: 'br', para: 'nao', rotulo: '!= máscara', cor: 'vermelho' },
  ],
  notas: [
    { x: 145, y: 40, texto: 'P', cor: 'cinza', ancora: 'middle' },
    { x: 235, y: 40, texto: 'SG', cor: 'cinza', ancora: 'middle' },
    { x: 325, y: 40, texto: 'V', cor: 'cinza', ancora: 'middle' },
    { x: 445, y: 160, texto: '&', cor: 'roxo', ancora: 'middle', tam: 40 },
    { x: 445, y: 430, texto: '&', cor: 'roxo', ancora: 'middle', tam: 40 },
    { x: 875, y: 160, texto: '=', cor: 'roxo', ancora: 'middle', tam: 40 },
    { x: 875, y: 430, texto: '=', cor: 'roxo', ancora: 'middle', tam: 40 },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'filtrar(c, V | SG)'],
    ['B', 'proc', 'i = 0'],
    ['C', 'dec', 'i < c->n?'],
    ['D', 'dec', '(tags & mascara) == mascara?'],
    ['E', 'io', 'mostrar_item: Suco de caju'],
    ['F', 'proc', 'i++'],
    ['G', 'inicio', 'Fim'],
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
  ],
}
