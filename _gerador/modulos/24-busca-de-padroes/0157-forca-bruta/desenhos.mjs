// "banana bacana" e o padrão "ana": quatro dos 11 alinhamentos da força bruta.
// verde = letra que bateu, vermelho = a letra que errou, cinza = fora da janela
const texto = ['b', 'a', 'n', 'a', 'n', 'a', '␣', 'b', 'a', 'c', 'a', 'n', 'a']
const X = 300
const W = 80
const centro = (i) => X + i * W + W / 2

// estados de uma linha: i = alinhamento, ok = letras que bateram, erro = a que falhou
const linha = (i, ok, erro) => {
  const e = {}
  texto.forEach((_, k) => {
    if (k < i || k >= i + 3) e[k] = 'apagado'
  })
  for (let k = 0; k < ok; k++) e[i + k] = 'verde'
  if (erro) e[i + ok] = 'vermelho'
  return e
}

const Y = [300, 490, 680, 870]

export const ideia = {
  caixas: [
    { id: 'p', forma: 'array', x: X, y: 30, nome: 'padrão (m = 3)', celula: W, itens: ['a', 'n', 'a'], cor: 'roxo' },
    { id: 'r0', forma: 'array', x: X, y: Y[0], celula: W, itens: texto, estados: linha(0, 0, true) },
    { id: 'r1', forma: 'array', x: X, y: Y[1], celula: W, itens: texto, estados: linha(1, 3, false) },
    { id: 'r5', forma: 'array', x: X, y: Y[2], celula: W, itens: texto, estados: linha(5, 1, true) },
    { id: 'r10', forma: 'array', x: X, y: Y[3], celula: W, itens: texto, estados: linha(10, 3, false) },
  ],
  setas: [],
  notas: [
    { x: 110, y: Y[0] + 52, texto: 'i = 0', cor: 'roxo' },
    { x: 110, y: Y[1] + 52, texto: 'i = 1', cor: 'roxo' },
    { x: 110, y: Y[2] + 52, texto: 'i = 5', cor: 'roxo' },
    { x: 110, y: Y[3] + 52, texto: 'i = 10', cor: 'roxo' },
    { x: centro(0) - 30, y: Y[0] - 16, texto: "'b' ≠ 'a': 1 comparação, falha", cor: 'vermelho' },
    { x: centro(2), y: Y[1] - 16, texto: '3 comparações: ocorrência em 1', cor: 'verde', ancora: 'middle' },
    { x: centro(6), y: Y[2] - 16, texto: "'a' bateu, '␣' ≠ 'n': 2 comparações", cor: 'vermelho', ancora: 'middle' },
    { x: centro(11) + 40, y: Y[3] - 16, texto: 'ocorrência em 10', cor: 'verde', ancora: 'end' },
    { x: 110, y: Y[3] + 175, texto: '11 alinhamentos (i = 0 até n - m = 10), sempre andando 1: 19 comparações no total', cor: 'cinza' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início: i = 0'],
    ['B', 'dec', 'i <= n - m?'],
    ['C', 'proc', 'j = 0'],
    ['D', 'dec', 'j < m e texto[i+j] == padrao[j]?'],
    ['E', 'proc', 'j++'],
    ['F', 'dec', 'j == m?'],
    ['G', 'io', 'Mostrar i (1, 3, 10)'],
    ['H', 'proc', 'i++'],
    ['I', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C', 'Sim'],
    ['C', 'D'],
    ['D', 'E', 'Sim'],
    ['E', 'D'],
    ['D', 'F', 'Não'],
    ['F', 'G', 'Sim'],
    ['F', 'H', 'Não'],
    ['G', 'H'],
    ['H', 'B'],
    ['B', 'I', 'Não'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'D', 'F', 'G', 'H', 'B', 'I'],
}
