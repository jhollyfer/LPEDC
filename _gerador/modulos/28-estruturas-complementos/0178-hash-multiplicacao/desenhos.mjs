// A multiplicação em inteiros para o fardo 48 com m = 16 (p = 4):
// 48 × s dá 64 bits; o uint32_t fica com os 32 de baixo; os 4 bits mais
// altos deles são o balde. Embaixo, a divisão por 16 e por 13 do mesmo fardo.
export const ideia = {
  caixas: [
    { id: 'k', forma: 'caixinha', x: 100, y: 120, nome: 'k', valor: '48', tipo: 'uint32_t' },
    { id: 's', x: 430, y: 130, w: 400, h: 150, cor: 'roxo', rotulo: 'multiplica por s', texto: ['× 2654435769'] },
    { id: 'p1', x: 960, y: 130, w: 200, h: 150, cor: 'cinza', rotulo: 'de cima', texto: ['0x1D'] },
    { id: 'p0', x: 1160, y: 130, w: 300, h: 150, cor: 'azul', rotulo: 'os 32 de baixo', texto: ['0xAA66D2B0'] },
    { id: 'b0', x: 700, y: 430, w: 170, h: 110, cor: 'verde', texto: ['1010'] },
    { id: 'b1', x: 870, y: 430, w: 590, h: 110, cor: 'cinza', texto: ['1010 0110 0110 1101 0010 1011 0000'] },
    { id: 'h', x: 700, y: 650, w: 330, h: 150, cor: 'verde', rotulo: 'balde', texto: ['1010 = 10'] },
    { id: 'd16', x: 100, y: 430, w: 440, h: 150, cor: 'vermelho', rotulo: 'divisão por 16', texto: ['48 % 16 = 0'] },
    { id: 'd13', x: 100, y: 650, w: 440, h: 150, cor: 'verde', rotulo: 'divisão por 13 (primo)', texto: ['48 % 13 = 9'] },
  ],
  setas: [
    { de: 'k', para: 's' },
    { de: 's', para: 'p1' },
    { pontos: [[1310, 296], [1310, 380], [1160, 380], [1160, 420]], rotulo: 'em binário', cor: 'roxo' },
    { de: 'b0', para: 'h', lados: 'bc' },
  ],
  notas: [
    { x: 960, y: 320, texto: 'o uint32_t descarta', cor: 'cinza', tam: 22 },
    { x: 880, y: 600, texto: 'os p = 4 bits mais altos: produto >> 28', cor: 'verde', tam: 24 },
    { x: 1080, y: 720, texto: ['nenhuma divisão:', 'multiplica e desloca'], cor: 'roxo', tam: 24 },
    { x: 100, y: 620, texto: 'os 4 bits de baixo de 48 são 0000', cor: 'vermelho', tam: 22 },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'io', 'Ler k (48) e p (4)'],
    ['H', 'dec', 'p entre 1 e 31?'],
    ['I', 'io', 'Mostrar "p inválido"'],
    ['C', 'proc', 'produto = k * 2654435769u'],
    ['D', 'proc', 'uint32_t: fica produto mod 2^32'],
    ['E', 'proc', 'balde = produto >> (32 - p)'],
    ['F', 'io', 'Mostrar balde (10)'],
    ['G', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'H'],
    ['H', 'C', 'Sim'],
    ['H', 'I', 'Não'],
    ['C', 'D'],
    ['D', 'E'],
    ['E', 'F'],
    ['F', 'G'],
    ['I', 'G'],
  ],
  caminho: ['A', 'B', 'H', 'C', 'D', 'E', 'F', 'G'],
}
