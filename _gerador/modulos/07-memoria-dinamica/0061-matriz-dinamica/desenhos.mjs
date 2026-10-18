export const ideia = {
  caixas: [
    { id: 'm', forma: 'caixinha', x: 100, y: 150, nome: 'm', valor: '●', tipo: 'int ** (pilha)' },
    { id: 'p0', x: 500, y: 90, w: 150, h: 90, cor: 'roxo', texto: ['m[0] ●'] },
    { id: 'p1', x: 500, y: 180, w: 150, h: 90, cor: 'roxo', texto: ['m[1] ●'] },
    { id: 'p2', x: 500, y: 270, w: 150, h: 90, cor: 'roxo', texto: ['m[2] ●'] },
    { id: 'l0', forma: 'array', x: 900, y: 20, itens: ['12', '15', '11', '18'], celula: 90, cor: 'verde' },
    { id: 'l1', forma: 'array', x: 820, y: 190, itens: ['9', '10', '14', '13'], celula: 90, cor: 'verde' },
    { id: 'l2', forma: 'array', x: 960, y: 360, itens: ['20', '17', '19', '22'], celula: 90, cor: 'verde' },
  ],
  setas: [
    { de: 'm', para: 'p1' },
    { pontos: [[650, 135], [760, 135], [760, 62], [892, 62]] },
    { pontos: [[650, 225], [812, 232]] },
    { pontos: [[650, 315], [760, 315], [760, 402], [952, 402]] },
  ],
  notas: [
    { x: 575, y: 70, texto: 'vetor de 3 int *', cor: 'roxo', ancora: 'middle', tam: 24 },
    { x: 1270, y: 70, texto: 'loja 1 = 56', cor: 'verde', tam: 24 },
    { x: 1190, y: 240, texto: 'loja 2 = 46', cor: 'verde', tam: 24 },
    { x: 1330, y: 410, texto: 'loja 3 = 78', cor: 'verde', tam: 24 },
    { x: 575, y: 410, texto: ['libera: linhas', 'primeiro, m depois'], cor: 'vermelho', ancora: 'middle', tam: 22 },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início: 3 x 4'],
    ['B', 'proc', 'm = malloc(3 ponteiros)'],
    ['C', 'dec', 'falta alguma linha?'],
    ['D', 'proc', 'm[i] = malloc(4 ints)'],
    ['E', 'dec', 'm[i] != NULL?'],
    ['F', 'proc', 'libera as linhas já feitas e m'],
    ['G', 'proc', 'preenche e soma cada loja'],
    ['H', 'io', 'Loja 1: R$ 56 mil ...'],
    ['I', 'proc', 'libera as 3 linhas, depois m'],
    ['J', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D', 'Sim'],
    ['D', 'E'],
    ['E', 'C', 'Sim'],
    ['E', 'F', 'Não'],
    ['C', 'G', 'Não'],
    ['G', 'H'],
    ['H', 'I'],
    ['I', 'J'],
    ['F', 'J'],
  ],
}
