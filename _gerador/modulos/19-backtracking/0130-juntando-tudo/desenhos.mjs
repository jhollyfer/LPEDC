// o jogo da revista: a primeira casa vazia, (0, 1), olha a linha 0, a
// coluna 1 e a caixa 0 (amarelo). Os dígitos que já aparecem ali ficam de
// fora; sobram o 5 e o 7
const jogo = ['2.3.8....', '6......7.', '.412.3.86', '5........', '.97.28...', '164.9...5', '.3...6...', '4.....2..', '.1.832.5.']
const CEL = 62
const VAO = 14
const X0 = 100
const Y0 = 50

const caixas = []
for (let l = 0; l < 9; l++) {
  for (let b = 0; b < 3; b++) {
    const itens = []
    const estados = {}
    for (let k = 0; k < 3; k++) {
      const c = b * 3 + k
      const ch = jogo[l][c]
      const olha = l === 0 || c === 1 || (l < 3 && c < 3)
      if (l === 0 && c === 1) {
        itens.push('?')
        estados[k] = 'roxo'
      } else {
        itens.push(ch === '.' ? '' : ch)
        if (olha) estados[k] = ch === '.' ? 'amarelo' : 'amarelo'
        else if (ch === '.') estados[k] = 'apagado'
      }
    }
    caixas.push({
      id: `g${l}${b}`,
      forma: 'array',
      x: X0 + b * (3 * CEL + VAO),
      y: Y0 + l * 84 + Math.floor(l / 3) * VAO,
      celula: CEL,
      itens,
      estados,
      indices: false,
    })
  }
}

const XN = 800
export const ideia = {
  caixas,
  setas: [],
  notas: [
    { x: XN, y: Y0 + 50, texto: 'casa (0, 1): quem pode entrar?', cor: 'roxo' },
    { x: XN, y: Y0 + 130, texto: 'linha 0 já tem: 2 3 8', cor: 'amarelo' },
    { x: XN, y: Y0 + 180, texto: 'coluna 1 já tem: 4 9 6 3 1', cor: 'amarelo' },
    { x: XN, y: Y0 + 230, texto: 'caixa 0 já tem: 2 3 6 4 1', cor: 'amarelo' },
    { x: XN, y: Y0 + 310, texto: 'sobram: 5 e 7', cor: 'verde' },
    { x: XN, y: Y0 + 380, texto: 'resolve tenta o 5 primeiro; muitos', cor: 'cinza' },
    { x: XN, y: Y0 + 418, texto: 'retrocessos depois, descobre o 7', cor: 'cinza' },
    { x: XN, y: Y0 + 500, texto: 'o teste é O(1): na_linha[0][d],', cor: 'roxo' },
    { x: XN, y: Y0 + 538, texto: 'na_coluna[1][d] e na_caixa[0][d]', cor: 'roxo' },
    { x: XN, y: Y0 + 620, texto: 'cinza claro: casa vazia que a', cor: 'cinza' },
    { x: XN, y: Y0 + 658, texto: 'casa (0, 1) não enxerga', cor: 'cinza' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início: resolve(k)'],
    ['B', 'proc', 'Pula as casas preenchidas'],
    ['C', 'dec', 'k == 81?'],
    ['D', 'dec', 'Ainda há dígito d?'],
    ['E', 'dec', 'd na linha, coluna ou caixa?'],
    ['F', 'proc', 'Escreve d e marca'],
    ['G', 'dec', 'Deu certo resolve(k+1)?'],
    ['H', 'proc', 'Apaga d e desmarca'],
    ['I', 'inicio', 'Devolve true'],
    ['J', 'inicio', 'Devolve false'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'I', 'Sim'],
    ['C', 'D', 'Não'],
    ['D', 'J', 'Não'],
    ['D', 'E', 'Sim'],
    ['E', 'D', 'Sim'],
    ['E', 'F', 'Não'],
    ['F', 'G'],
    ['G', 'I', 'Sim'],
    ['G', 'H', 'Não'],
    ['H', 'D'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'D', 'E', 'F', 'G', 'H', 'D', 'E', 'F', 'G', 'I', 'A', 'B', 'C', 'I', 'A', 'B', 'C', 'D', 'J'],
}
