export const ideia = {
  caixas: [
    { id: 's', x: 100, y: 40, w: 400, cor: 'roxo', texto: ['%-10s', '10 casas, à esquerda'] },
    { id: 'd', x: 560, y: 40, w: 380, cor: 'roxo', texto: ['%3d', '3 casas, à direita'] },
    { id: 'f', x: 1000, y: 40, w: 440, cor: 'roxo', texto: ['%9.2f', '9 casas, 2 decimais'] },
    { id: 'a1', x: 140, y: 340, w: 320, h: 110, cor: 'azul', texto: ['"Arroz 5kg"'] },
    { id: 'a2', x: 600, y: 340, w: 300, h: 110, cor: 'azul', texto: ['2'] },
    { id: 'a3', x: 1060, y: 340, w: 320, h: 110, cor: 'azul', texto: ['51.80'] },
    { id: 't', forma: 'terminal', x: 400, y: 580, w: 700, texto: ['[Arroz 5kg ][  2][    51.80]'] },
  ],
  setas: [
    { de: 'a1', para: 's', rotulo: '1º' },
    { de: 'a2', para: 'd', rotulo: '2º' },
    { de: 'a3', para: 'f', rotulo: '3º' },
    { de: 'a2', para: 't', rotulo: 'monta a linha', cor: 'verde' },
  ],
  notas: [
    { x: 1130, y: 640, texto: ['os [ ] marcam a', 'largura de cada', 'buraco'], cor: 'roxo' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'io', 'Mostrar o cabeçalho'],
    ['C', 'io', 'Mostrar arroz, leite e banana'],
    ['D', 'io', 'Mostrar o total'],
    ['E', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D'],
    ['D', 'E'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E'],
}
