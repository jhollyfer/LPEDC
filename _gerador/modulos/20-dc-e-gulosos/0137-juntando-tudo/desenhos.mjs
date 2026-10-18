// o compactador de ponta a ponta: em cima a compactação (duas passadas), no
// meio o formato do arquivo .huf, embaixo a descompactação
export const ideia = {
  caixas: [
    { id: 'txt', forma: 'arquivo', x: 110, y: 60, w: 260, h: 150, nome: 'feira.txt', texto: ['9560 bytes'] },
    { id: 'p1', x: 480, y: 60, w: 330, h: 150, cor: 'roxo', rotulo: '1ª passada', texto: ['conta as', 'frequências'] },
    { id: 'p2', x: 900, y: 60, w: 330, h: 150, cor: 'roxo', rotulo: '2ª passada', texto: ['árvore, códigos,', 'grava os bits'] },

    { id: 'h1', x: 110, y: 330, w: 180, h: 110, cor: 'azul', rotulo: '4 bytes', texto: 'HUF1' },
    { id: 'h2', x: 290, y: 330, w: 190, h: 110, cor: 'azul', rotulo: '8 bytes', texto: '9560' },
    { id: 'h3', x: 480, y: 330, w: 390, h: 110, cor: 'amarelo', rotulo: '1024 bytes', texto: '256 frequências' },
    { id: 'h4', x: 870, y: 330, w: 610, h: 110, cor: 'verde', rotulo: '5120 bytes', texto: 'os códigos, 8 bits por byte' },

    { id: 'd1', x: 110, y: 580, w: 380, h: 150, cor: 'roxo', rotulo: 'lê o cabeçalho', texto: ['monta a mesma', 'árvore'] },
    { id: 'd2', x: 590, y: 580, w: 380, h: 150, cor: 'roxo', rotulo: 'lê bit a bit', texto: ['0 esquerda, 1 direita,', 'na folha escreve'] },
    { id: 'out', forma: 'arquivo', x: 1080, y: 580, w: 300, h: 150, nome: 'feira2.txt', texto: ['9560 bytes', 'igual ao original'] },
  ],
  setas: [
    { de: 'txt', para: 'p1' },
    { de: 'p1', para: 'p2' },
    { de: 'p2', para: 'h4', lados: 'bc' },
    { de: 'h3', para: 'd1', lados: 'bc', cotovelo: true },
    { de: 'd1', para: 'd2' },
    { de: 'd2', para: 'out' },
  ],
  notas: [
    { x: 720, y: 510, texto: 'feira.huf: 6156 bytes (64,4% do original)', cor: 'verde' },
    { x: 110, y: 300, texto: 'o arquivo .huf:', cor: 'verde' },
    { x: 110, y: 800, texto: 'o tamanho no cabeçalho diz quando parar: os zeros de enchimento do último byte ficam de fora', cor: 'cinza' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'io', 'Lê HUF1, o total (9560) e as frequências'],
    ['C', 'proc', 'Monta a mesma árvore; k = 0'],
    ['D', 'dec', 'k < total?'],
    ['E', 'proc', 'no = raiz'],
    ['F', 'dec', 'no é folha?'],
    ['G', 'proc', 'Lê um bit: 0 esquerda, 1 direita'],
    ['H', 'io', 'Escreve o byte da folha; k++'],
    ['I', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D'],
    ['D', 'E', 'Sim'],
    ['E', 'F'],
    ['F', 'G', 'Não'],
    ['G', 'F'],
    ['F', 'H', 'Sim'],
    ['H', 'D'],
    ['D', 'I', 'Não'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'F', 'H', 'D', 'I'],
}
