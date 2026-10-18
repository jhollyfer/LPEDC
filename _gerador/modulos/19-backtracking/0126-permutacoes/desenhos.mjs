// a árvore das trocas do sarau: o 1º nível escolhe quem abre (posição 0),
// o 2º escolhe a posição 1; as 6 folhas são as ordens, na ordem da saída
const PASSO = 233
const cx = (j) => 217 + PASSO * j
const meio = (a, b) => (cx(a) + cx(b)) / 2

const caixas = []
const setas = []
const no = (id, centro, y, w, h, cor, texto) => caixas.push({ id, x: centro - w / 2, y, w, h, cor, texto })

no('r', meio(0, 5), 40, 200, 80, 'azul', 'R S F')
const nivel1 = ['R | S F', 'S | R F', 'F | S R']
nivel1.forEach((t, k) => no(`n${k}`, meio(2 * k, 2 * k + 1), 230, 200, 80, 'roxo', t))
const folhas = ['1: R S F', '2: R F S', '3: S R F', '4: S F R', '5: F S R', '6: F R S']
folhas.forEach((t, j) => no(`f${j}`, cx(j), 420, 200, 80, 'verde', t))

setas.push({ de: 'r', para: 'n0', lados: 'bc', rotulo: 'troca(0, 0)', dx: -150 })
setas.push({ de: 'r', para: 'n1', lados: 'bc', rotulo: 'troca(0, 1)' })
setas.push({ de: 'r', para: 'n2', lados: 'bc', rotulo: 'troca(0, 2)', dx: 10 })
for (let j = 0; j < 6; j++) {
  const esq = j % 2 === 0
  setas.push({
    de: `n${j >> 1}`,
    para: `f${j}`,
    lados: 'bc',
    rotulo: esq ? 'troca(1, 1)' : 'troca(1, 2)',
    dx: esq ? -140 : 0,
  })
}

export const ideia = {
  caixas,
  setas,
  notas: [
    { x: 100, y: 580, texto: 'R = Rap, S = Samba, F = Forró; à esquerda da | fica o que já foi decidido', cor: 'cinza' },
    { x: 100, y: 620, texto: 'na volta de cada ramo, a mesma troca é desfeita: o vetor volta a R S F', cor: 'roxo' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início: permuta(v, i)'],
    ['B', 'dec', 'i == N?'],
    ['C', 'io', 'Mostra a ordem'],
    ['D', 'proc', 'j = i'],
    ['E', 'dec', 'j < N?'],
    ['F', 'proc', 'Escolhe: troca v[i] e v[j]'],
    ['G', 'proc', 'permuta(v, i + 1)'],
    ['H', 'proc', 'Desfaz: troca de novo; j++'],
    ['I', 'inicio', 'Fim da chamada'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C', 'Sim'],
    ['C', 'I'],
    ['B', 'D', 'Não'],
    ['D', 'E'],
    ['E', 'I', 'Não'],
    ['E', 'F', 'Sim'],
    ['F', 'G'],
    ['G', 'H'],
    ['H', 'E'],
  ],
  caminho: ['A', 'B', 'C', 'I', 'A', 'B', 'D', 'E', 'F', 'G', 'H', 'E', 'I'],
}
