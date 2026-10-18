// a árvore do cartão de R$ 35, com as podas: cada caixa é uma chamada de
// tenta e mostra a soma até ali; esquerda = leva o item, direita = não leva.
// vermelho = passou de 35 (poda), verde = fechou 35, cinza = itens acabaram
const precos = [30, 20, 15, 5]
const ALVO = 35

// monta a árvore de chamadas exatamente como o código
const monta = (i, soma) => {
  const no = { soma, filhos: [] }
  if (soma > ALVO) no.cor = 'vermelho'
  else if (soma === ALVO) no.cor = 'verde'
  else if (i === precos.length) no.cor = 'cinza'
  else {
    no.cor = 'amarelo'
    no.filhos = [monta(i + 1, soma + precos[i]), monta(i + 1, soma)]
  }
  return no
}
const raiz = monta(0, 0)

// posição: as folhas ocupam colunas da esquerda para a direita; o pai fica no meio dos filhos
const X0 = 360
const PASSO = 104
const W = 84
const H = 60
let coluna = 0
const caixas = []
const setas = []
let n = 0
const posiciona = (no, nivel) => {
  no.id = `n${n++}`
  if (!no.filhos.length) no.cx = X0 + PASSO * coluna++
  else {
    no.filhos.forEach((f) => posiciona(f, nivel + 1))
    no.cx = (no.filhos[0].cx + no.filhos[1].cx) / 2
  }
  caixas.push({ id: no.id, x: no.cx - W / 2, y: 40 + nivel * 130, w: W, h: H, cor: no.cor, texto: String(no.soma) })
  no.filhos.forEach((f, k) =>
    setas.push({ de: no.id, para: f.id, lados: 'bc', cor: k === 0 ? 'verde' : 'cinza' }),
  )
}
posiciona(raiz, 0)

const itens = ['atlas 30', 'mangá 20', 'poesia 15', 'marcador 5']
const notas = itens.map((t, k) => ({ x: 100, y: 40 + k * 130 + 105, texto: t, cor: 'roxo' }))
notas.push({ x: 100, y: 40 + 4 * 130 + 120, texto: 'seta verde: leva o item; seta cinza: não leva', cor: 'cinza' })
notas.push({ x: 100, y: 40 + 4 * 130 + 158, texto: '21 caixas = 21 chamadas (a árvore inteira teria 31)', cor: 'roxo' })

export const ideia = { caixas, setas, notas }

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início: tenta(i, soma)'],
    ['B', 'dec', 'soma > ALVO?'],
    ['C', 'dec', 'soma == ALVO?'],
    ['D', 'io', 'Mostra a solução'],
    ['E', 'dec', 'i == N?'],
    ['F', 'proc', 'Leva o item i: tenta(i+1, soma+preço)'],
    ['G', 'proc', 'Não leva: tenta(i+1, soma)'],
    ['H', 'inicio', 'Volta'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'H', 'Sim'],
    ['B', 'C', 'Não'],
    ['C', 'D', 'Sim'],
    ['D', 'H'],
    ['C', 'E', 'Não'],
    ['E', 'H', 'Sim'],
    ['E', 'F', 'Não'],
    ['F', 'G'],
    ['G', 'H'],
  ],
  caminho: ['A', 'B', 'C', 'E', 'F', 'G', 'H', 'A', 'B', 'C', 'D', 'H', 'A', 'B', 'H', 'A', 'B', 'C', 'E', 'H'],
}
