// 16 Pix num vetor que começa com 1 posição e dobra quando enche. Linha de
// cima: o número do Pix. Meio: o custo real (vermelho = mudança, copia
// tudo). Embaixo: o cofrinho, se cada inserção pagasse 3.
const X = 300
const C = 75
const custos = [1, 2, 3, 1, 5, 1, 1, 1, 9, 1, 1, 1, 1, 1, 1, 1]
let saldo = 0
const cofrinho = custos.map((c) => (saldo += 3 - c))
const caras = Object.fromEntries(custos.map((c, i) => [i, c > 1 ? 'vermelho' : 'roxo']))
const verdes = Object.fromEntries(cofrinho.map((_, i) => [i, custos[i] > 1 ? 'amarelo' : 'verde']))

export const ideia = {
  caixas: [
    { id: 'pix', forma: 'array', x: X, y: 60, celula: C, itens: custos.map((_, i) => i + 1), estados: Object.fromEntries(custos.map((_, i) => [i, 'apagado'])), indices: false },
    { id: 'custo', forma: 'array', x: X, y: 200, celula: C, itens: custos, estados: caras, indices: false },
    { id: 'cofre', forma: 'array', x: X, y: 340, celula: C, itens: cofrinho, estados: verdes, indices: false },
  ],
  setas: [],
  notas: [
    { x: 100, y: 112, texto: 'Pix nº', cor: 'cinza' },
    { x: 100, y: 252, texto: 'custo', cor: 'roxo' },
    { x: 100, y: 392, texto: 'cofrinho', cor: 'verde' },
    { x: X, y: 500, texto: 'vermelho: o vetor encheu e copiou tudo (1, 2, 4 e 8 cópias)', cor: 'vermelho' },
    { x: X, y: 545, texto: 'total: 16 escritas + 15 cópias = 31 < 3 × 16 = 48', cor: 'roxo' },
    { x: X, y: 590, texto: 'cada inserção paga 3: o cofrinho cai nas mudanças, mas nunca fica negativo', cor: 'verde' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início: insere(v, valor)'],
    ['B', 'dec', 'n == cap?'],
    ['C', 'proc', 'maior = malloc(2 × cap)'],
    ['D', 'proc', 'copia os n antigos (custo += n)'],
    ['E', 'proc', 'free(dados); dados = maior'],
    ['F', 'proc', 'dados[n++] = valor'],
    ['G', 'inicio', 'Fim: devolve o custo'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C', 'Sim'],
    ['B', 'F', 'Não'],
    ['C', 'D'],
    ['D', 'E'],
    ['E', 'F'],
    ['F', 'G'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'F', 'G'],
}
