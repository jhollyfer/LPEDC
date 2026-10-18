export const ideia = {
  caixas: [
    { id: 'num', x: 100, y: 20, w: 600, h: 110, cor: 'azul', texto: ['ip.numero = 0xC0A8000A'] },
    { id: 'b', forma: 'array', x: 100, y: 240, celula: 150, itens: ['0A', '00', 'A8', 'C0'], estados: { 0: 'verde' } },
    { id: 'q', forma: 'losango', x: 800, y: 180, w: 360, h: 220, cor: 'amarelo', texto: ['bytes[0]', '== 0x0A?'] },
    { id: 'le', x: 1240, y: 220, w: 280, h: 140, cor: 'verde', texto: ['little-endian'] },
  ],
  setas: [
    { de: 'b', para: 'q', lados: 'de' },
    { de: 'q', para: 'le', rotulo: 'Sim', cor: 'verde' },
  ],
  notas: [
    { x: 400, y: 190, texto: 'os mesmos 4 bytes, lidos como ip.bytes[i]', cor: 'roxo', ancora: 'middle' },
    { x: 175, y: 420, texto: 'menor', cor: 'cinza', ancora: 'middle' },
    { x: 175, y: 452, texto: 'endereço', cor: 'cinza', ancora: 'middle' },
    { x: 625, y: 420, texto: 'maior', cor: 'cinza', ancora: 'middle' },
    { x: 625, y: 452, texto: 'endereço', cor: 'cinza', ancora: 'middle' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'proc', 'ip.numero = 0xC0A8000A'],
    ['C', 'io', 'Mostrar ip.bytes: 0A 00 A8 C0'],
    ['D', 'dec', 'ip.bytes[0] == 0x0A?'],
    ['E', 'io', 'little-endian'],
    ['F', 'io', 'big-endian'],
    ['G', 'proc', 'ip.bytes[3] = 10'],
    ['H', 'io', 'Mostrar 0x0AA8000A'],
    ['I', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D'],
    ['D', 'E', 'Sim'],
    ['D', 'F', 'Não'],
    ['E', 'G'],
    ['F', 'G'],
    ['G', 'H'],
    ['H', 'I'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'G', 'H', 'I'],
}
