export const ideia = {
  caixas: [
    { id: 'd', forma: 'caixinha', x: 100, y: 20, w: 300, nome: 'diametro', valor: '35.0', tipo: 'cm · a grande' },
    { id: 'r', x: 540, y: 60, w: 400, cor: 'roxo', rotulo: 'raio', texto: ['35.0 / 2 = 17.5'] },
    { id: 'p', x: 1060, y: 60, w: 400, cor: 'roxo', rotulo: 'pow(17.5, 2)', texto: ['17.5² = 306.25'] },
    { id: 'a', x: 1060, y: 360, w: 400, cor: 'verde', rotulo: 'área da grande', texto: ['PI * 306.25', '= 962.11 cm²'] },
    { id: 'm', x: 1060, y: 660, w: 400, cor: 'verde', rotulo: 'área das 2 médias', texto: ['2 * PI * pow(12.5, 2)', '= 981.75 cm²'] },
    { id: 't', forma: 'terminal', x: 100, y: 470, w: 600, texto: ['Grande: 962 cm²', 'Duas médias: 982 cm²', 'Diferença: 19.6 cm²'] },
  ],
  setas: [
    { de: 'd', para: 'r' },
    { de: 'r', para: 'p' },
    { de: 'p', para: 'a' },
    { de: 'a', para: 't', rotulo: 'round e fabs' },
    { de: 'm', para: 't', lados: 'eb', cotovelo: true },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'proc', 'Diâmetros e preços'],
    ['C', 'proc', 'area = PI * pow(d / 2, 2)'],
    ['D', 'proc', 'custo = preço / area * 100'],
    ['E', 'proc', 'igual = 2 * sqrt(area / PI)'],
    ['F', 'io', 'Mostrar a comparação'],
    ['G', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D'],
    ['D', 'E'],
    ['E', 'F'],
    ['F', 'G'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'F', 'G'],
}
