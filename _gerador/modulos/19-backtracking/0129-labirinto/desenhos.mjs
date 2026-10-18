// o labirinto do texto depois da busca: números = ordem dos passos do
// caminho achado (verde), x = becos visitados e abandonados (vermelho),
// # = parede (cinza); as casas azuis são corredores que a busca nem visitou
const mapa = ['S.....#', '#..#..#', '..#.##.', '...##.#', '.#.#.##', '......F']
const caminho = [
  [0, 1], [0, 2], [1, 2], [1, 1], [2, 1], [3, 1], [3, 2], [4, 2], [5, 2], [5, 3], [5, 4], [5, 5],
]
const becos = ['0,3', '0,4', '0,5', '1,4', '1,5']
const CEL = 90
const X0 = 160
const Y0 = 90

const caixas = mapa.map((linha, l) => {
  const itens = []
  const estados = {}
  ;[...linha].forEach((ch, c) => {
    const k = caminho.findIndex(([a, b]) => a === l && b === c)
    if (ch === '#') {
      itens.push('#')
      estados[c] = 'cinza'
    } else if (ch === 'S' || ch === 'F') {
      itens.push(ch)
      estados[c] = 'roxo'
    } else if (k >= 0) {
      itens.push(String(k + 1))
      estados[c] = 'verde'
    } else if (becos.includes(`${l},${c}`)) {
      itens.push('x')
      estados[c] = 'vermelho'
    } else itens.push('')
  })
  return { id: `l${l}`, forma: 'array', x: X0, y: Y0 + l * 84, celula: CEL, itens, estados, indices: false }
})

const notas = []
for (let k = 0; k < 7; k++) notas.push({ x: X0 + k * CEL + CEL / 2, y: Y0 - 16, texto: String(k), cor: 'cinza', ancora: 'middle' })
for (let k = 0; k < 6; k++) notas.push({ x: X0 - 26, y: Y0 + k * 84 + 52, texto: String(k), cor: 'cinza', ancora: 'middle' })
notas.push(
  { x: 900, y: Y0 + 40, texto: 'ordem dos vizinhos: direita, baixo,', cor: 'roxo' },
  { x: 900, y: Y0 + 78, texto: 'esquerda, cima', cor: 'roxo' },
  { x: 900, y: Y0 + 150, texto: 'verde: o caminho achado, 13 passos', cor: 'verde' },
  { x: 900, y: Y0 + 210, texto: 'vermelho: becos (marcados com x', cor: 'vermelho' },
  { x: 900, y: Y0 + 248, texto: 'na volta, nunca mais visitados)', cor: 'vermelho' },
  { x: 900, y: Y0 + 310, texto: 'azul: corredor que a busca não usou', cor: 'azul' },
  { x: 900, y: Y0 + 380, texto: 'existe caminho de 11 passos: o', cor: 'cinza' },
  { x: 900, y: Y0 + 418, texto: 'backtracking acha um, não o menor', cor: 'cinza' },
)

export const ideia = { caixas, setas: [], notas }

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início: anda(l, c)'],
    ['B', 'dec', 'Fora do mapa?'],
    ['C', 'dec', 'É a saída F?'],
    ['D', 'dec', 'Parede ou já marcada?'],
    ['E', 'proc', "Marca '*'"],
    ['F', 'dec', 'Algum vizinho chega à saída?'],
    ['G', 'proc', "Desfaz: marca 'x'"],
    ['H', 'inicio', 'Devolve false'],
    ['I', 'inicio', 'Devolve true'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'H', 'Sim'],
    ['B', 'C', 'Não'],
    ['C', 'I', 'Sim'],
    ['C', 'D', 'Não'],
    ['D', 'H', 'Sim'],
    ['D', 'E', 'Não'],
    ['E', 'F'],
    ['F', 'I', 'Sim'],
    ['F', 'G', 'Não'],
    ['G', 'H'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'A', 'B', 'C', 'D', 'H', 'A', 'B', 'H', 'A', 'B', 'C', 'I', 'A', 'B', 'C', 'D', 'E', 'F', 'I'],
}
