// a linha de ônibus como skip list: 8 paradas (km) em 3 andares.
// Busca do km 47: anda no andar 2 até o 23, desce, anda até o 40, desce,
// e o próximo no andar 0 é o 47. O 56 (amarelo) foi olhado e já passou.
const km = [5, 12, 18, 23, 31, 40, 47, 56]
const andares = [1, 2, 1, 3, 1, 2, 1, 3]
const X0 = 340 // x do primeiro nó
const DX = 140
const Y = [470, 330, 190] // y de cada andar (0, 1, 2)
// verde: os nós onde a busca parou (x) e o achado; amarelo: olhado e já passou
const verdes = ['23_2', '23_1', '40_1', '40_0', '47_0']
const cor = (v, k) => {
  if (verdes.includes(`${v}_${k}`)) return 'verde'
  if (v === 56 && k >= 1) return 'amarelo'
  return 'cinza'
}

const caixas = []
const setas = []
for (let k = 0; k < 3; k++) {
  caixas.push({ id: `c${k}`, x: 110, y: Y[k], w: 170, h: 70, cor: 'azul', texto: `andar ${k}` })
  let ant = `c${k}`
  km.forEach((v, i) => {
    if (andares[i] <= k) return
    const id = `n${v}_${k}`
    caixas.push({ id, x: X0 + i * DX, y: Y[k], w: 90, h: 70, cor: cor(v, k), texto: String(v) })
    const noCaminho =
      (k === 2 && v === 23) || (k === 1 && v === 40) || (k === 0 && v === 47)
    setas.push({ de: ant, para: id, cor: noCaminho ? 'verde' : 'cinza' })
    ant = id
  })
}
// as descidas da busca
setas.push({ de: 'n23_2', para: 'n23_1', cor: 'verde', rotulo: 'desce' })
setas.push({ de: 'n40_1', para: 'n40_0', cor: 'verde', rotulo: 'desce' })

export const ideia = {
  caixas,
  setas,
  notas: [
    { x: 110, y: 620, texto: ['azul: a cabeça, um ponteiro por andar', 'andar 2: o ônibus direto', 'andar 1: o semidireto', 'andar 0: o parador (todas as paradas)'], cor: 'cinza' },
    { x: 860, y: 620, texto: ['busca do 47: 5 nós olhados;', 'o parador olharia 7'], cor: 'verde' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'io', 'Ler a chave (47)'],
    ['C', 'proc', 'x = cabeça; k = andar mais alto'],
    ['D', 'dec', 'k >= 0?'],
    ['E', 'dec', 'prox[k] existe e é menor que a chave?'],
    ['F', 'proc', 'x = x->prox[k] (avança)'],
    ['G', 'proc', 'k-- (desce um andar)'],
    ['H', 'dec', 'x->prox[0] é a chave?'],
    ['I', 'io', 'Mostrar "tem parada"'],
    ['J', 'io', 'Mostrar "não tem"'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D'],
    ['D', 'E', 'Sim'],
    ['E', 'F', 'Sim'],
    ['F', 'E'],
    ['E', 'G', 'Não'],
    ['G', 'D'],
    ['D', 'H', 'Não'],
    ['H', 'I', 'Sim'],
    ['H', 'J', 'Não'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'F', 'E', 'G', 'D', 'E', 'F', 'E', 'G', 'D', 'E', 'G', 'D', 'H', 'I'],
}
