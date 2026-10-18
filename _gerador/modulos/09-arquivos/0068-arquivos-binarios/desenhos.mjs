export const ideia = {
  caixas: [
    { id: 'f', x: 150, y: 20, w: 480, h: 190, cor: 'azul', rotulo: 'estoque.bin', texto: ['3 registros', '32 bytes cada'] },
    { id: 's', x: 760, y: 20, w: 620, h: 150, cor: 'roxo', rotulo: 'fseek', texto: ['2 * 32 bytes do começo'] },
    { id: 'e', forma: 'array', x: 150, y: 340, celula: 380, indices: false, itens: ['Arroz | 12 | 25.90', 'Feijão | 7 | 8.75', 'Café | 4 | 18.50'], estados: { 2: 'verde' } },
    { id: 't', forma: 'terminal', x: 760, y: 560, w: 680, texto: ['Registro 2: Café, 4 un., R$ 18.50'] },
  ],
  setas: [
    { pontos: [[910, 186], [910, 330]] },
    { de: 'e:2', para: 't', lados: 'bc', rotulo: 'fread' },
  ],
  notas: [
    { x: 340, y: 320, texto: 'registro 0', cor: 'azul', ancora: 'middle' },
    { x: 720, y: 320, texto: 'registro 1', cor: 'azul', ancora: 'middle' },
    { x: 1100, y: 320, texto: 'registro 2', cor: 'verde', ancora: 'middle' },
    { x: 150, y: 466, texto: 'byte 0', cor: 'cinza', ancora: 'middle' },
    { x: 530, y: 466, texto: 'byte 32', cor: 'cinza', ancora: 'middle' },
    { x: 910, y: 466, texto: 'byte 64', cor: 'cinza', ancora: 'middle' },
    { x: 1290, y: 466, texto: 'byte 96', cor: 'cinza', ancora: 'middle' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'io', 'fwrite dos 3 produtos'],
    ['C', 'proc', 'Abrir estoque.bin com "rb"'],
    ['D', 'proc', 'fseek até o fim e ftell'],
    ['E', 'io', 'Mostrar "96 bytes"'],
    ['F', 'proc', 'fseek até o byte 64'],
    ['G', 'dec', 'fread leu 1 registro?'],
    ['H', 'io', 'Mostrar Café, 4, 18.50'],
    ['I', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D'],
    ['D', 'E'],
    ['E', 'F'],
    ['F', 'G'],
    ['G', 'H', 'Sim'],
    ['G', 'I', 'Não'],
    ['H', 'I'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'],
}
