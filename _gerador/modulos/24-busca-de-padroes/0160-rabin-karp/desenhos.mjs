// "2718281828459" e o padrão 182 com q = 13: o hash de cada janela embaixo da
// posição onde ela começa. Verde = ocorrência, vermelho = falso positivo
const digitos = ['2', '7', '1', '8', '2', '8', '1', '8', '2', '8', '4', '5', '9']
const hashes = ['11', '3', '0', '9', '8', '12', '0', '9', '11', '0', '4']
const X = 330
const W = 86
const cx = (i) => X + i * W + W / 2

export const ideia = {
  caixas: [
    {
      id: 'p',
      x: 110,
      y: 20,
      w: 520,
      h: 190,
      cor: 'roxo',
      rotulo: 'padrão',
      texto: ['182 % 13 = 0', 'procurar janelas com hash 0'],
    },
    {
      id: 'r',
      x: 760,
      y: 20,
      w: 740,
      h: 190,
      cor: 'amarelo',
      rotulo: 'rolar 271 → 718',
      texto: ['(11 - 2·9 % 13 + 13) % 13 = 6', '(6·10 + 8) % 13 = 3'],
    },
    {
      id: 't',
      forma: 'array',
      x: X,
      y: 330,
      celula: W,
      itens: digitos,
      estados: { 2: 'verde', 3: 'verde', 4: 'verde', 6: 'verde', 7: 'verde', 8: 'verde', 9: 'vermelho', 10: 'vermelho', 11: 'vermelho' },
    },
    {
      id: 'h',
      forma: 'array',
      x: X,
      y: 560,
      celula: W,
      itens: hashes,
      cor: 'roxo',
      estados: { 2: 'verde', 6: 'verde', 9: 'vermelho' },
    },
  ],
  setas: [
    { pontos: [[cx(2), 470], [cx(2), 545]], cor: 'verde' },
    { pontos: [[cx(6), 470], [cx(6), 545]], cor: 'verde' },
    { pontos: [[cx(9), 470], [cx(9), 545]], cor: 'vermelho' },
  ],
  notas: [
    { x: 110, y: 382, texto: 'texto', cor: 'azul' },
    { x: 110, y: 612, texto: 'hash', cor: 'roxo' },
    { x: 110, y: 645, texto: 'da janela', cor: 'roxo' },
    { x: cx(4), y: 314, texto: '182: ocorrência em 2', cor: 'verde', ancora: 'middle' },
    { x: cx(7) + 10, y: 314, texto: 'e em 6', cor: 'verde', ancora: 'middle' },
    { x: cx(10) + 30, y: 314, texto: '845: falso positivo', cor: 'vermelho', ancora: 'middle' },
    { x: X, y: 760, texto: 'hash 0 em três janelas: as letras só são comparadas nessas três', cor: 'cinza' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início: hp, ht da 1ª janela; i = 0'],
    ['B', 'dec', 'i <= n - m?'],
    ['C', 'dec', 'ht == hp?'],
    ['D', 'dec', 'letras iguais?'],
    ['E', 'io', 'Mostrar i (2, 6)'],
    ['F', 'io', 'Falso positivo (9)'],
    ['G', 'proc', 'Rola: tira t[i], põe t[i+m]; i++'],
    ['H', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C', 'Sim'],
    ['C', 'D', 'Sim'],
    ['C', 'G', 'Não'],
    ['D', 'E', 'Sim'],
    ['D', 'F', 'Não'],
    ['E', 'G'],
    ['F', 'G'],
    ['G', 'B'],
    ['B', 'H', 'Não'],
  ],
  caminho: ['A', 'B', 'C', 'G', 'B', 'C', 'D', 'E', 'G', 'B', 'H'],
}
