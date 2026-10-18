// as pastas do computador: casa no topo, folhas em verde e o caminho mais
// longo (a altura) marcado
const no = (id, x, y, texto, cor = 'azul') => ({ id, x, y, w: 180, h: 90, cor, texto: [texto] })

export const ideia = {
  caixas: [
    no('casa', 905, 60, 'casa'),
    no('fotos', 510, 260, 'fotos'),
    no('contas', 970, 260, 'contas'),
    no('musica', 1300, 260, 'musica', 'verde'),
    no('praia', 400, 460, 'praia', 'verde'),
    no('natal', 620, 460, 'natal', 'verde'),
    no('agua', 860, 460, 'agua', 'verde'),
    no('luz', 1080, 460, 'luz'),
    no('2025', 1080, 660, '2025', 'verde'),
  ],
  setas: [
    { de: 'casa', para: 'fotos', lados: 'bc', cor: 'cinza' },
    { de: 'casa', para: 'contas', lados: 'bc', cor: 'verde' },
    { de: 'casa', para: 'musica', lados: 'bc', cor: 'cinza' },
    { de: 'fotos', para: 'praia', lados: 'bc', cor: 'cinza' },
    { de: 'fotos', para: 'natal', lados: 'bc', cor: 'cinza' },
    { de: 'contas', para: 'agua', lados: 'bc', cor: 'cinza' },
    { de: 'contas', para: 'luz', lados: 'bc', cor: 'verde' },
    { de: 'luz', para: '2025', lados: 'bc', cor: 'verde' },
  ],
  notas: [
    { x: 110, y: 115, texto: 'profundidade 0', cor: 'cinza' },
    { x: 110, y: 315, texto: 'profundidade 1', cor: 'cinza' },
    { x: 110, y: 515, texto: 'profundidade 2', cor: 'cinza' },
    { x: 110, y: 715, texto: 'profundidade 3', cor: 'cinza' },
    { x: 1110, y: 100, texto: 'raiz', cor: 'azul' },
    { x: 1050, y: 690, texto: ['caminho mais longo:', '3 arestas = altura 3'], cor: 'verde', ancora: 'end' },
    { x: 400, y: 620, texto: ['verde = folha (sem filhos)', '5 folhas'], cor: 'verde' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'altura(nó)'],
    ['B', 'proc', 'maior = -1; i = 0'],
    ['C', 'dec', 'i < qtd de filhos?'],
    ['D', 'proc', 'h = altura(filho i)'],
    ['E', 'proc', 'se h > maior: maior = h; i++'],
    ['F', 'io', 'Devolver maior + 1'],
    ['G', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D', 'Sim'],
    ['D', 'E'],
    ['E', 'C'],
    ['C', 'F', 'Não'],
    ['F', 'G'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'C', 'F', 'G'],
}
