// os nove pedidos da quadra numa linha do tempo, na ordem em que o guloso
// olha para eles (por hora de fim): verde aceito, cinza recusado
const X0 = 260 // x das 7h
const H = 110 // px por hora
const x = (h) => X0 + (h - 7) * H
const pedidos = [
  ['Ana', 8, 10, true],
  ['Carla', 10, 11, true],
  ['Bruno', 9, 12, false],
  ['Eva', 12, 13, true],
  ['Davi', 11, 14, false],
  ['Gil', 14, 15, true],
  ['Fred', 13, 16, false],
  ['Iara', 7, 17, false],
  ['Hugo', 15, 18, true],
]

const caixas = []
const notas = []
const Y0 = 100
pedidos.forEach(([nome, ini, fim, ok], i) => {
  const y = Y0 + i * 76
  caixas.push({ id: `p${i}`, x: x(ini), y, w: (fim - ini) * H, h: 58, cor: ok ? 'verde' : 'cinza', texto: nome })
  notas.push({ x: 110, y: y + 38, texto: `${ini}h-${fim}h`, cor: ok ? 'verde' : 'cinza' })
})
for (let h = 7; h <= 18; h++) notas.push({ x: x(h), y: 70, texto: `${h}h`, cor: 'azul', ancora: 'middle' })
notas.push({ x: 110, y: Y0 + 9 * 76 + 40, texto: 'ordem: pela hora de FIM; aceita se começa quando a quadra já está livre', cor: 'roxo' })
notas.push({ x: 110, y: Y0 + 9 * 76 + 90, texto: '5 aceitas: Ana, Carla, Eva, Gil e Hugo', cor: 'verde' })

export const ideia = { caixas, setas: [], notas }

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'proc', 'Ordena os pedidos por fim'],
    ['C', 'proc', 'livre_em = 0; i = 0'],
    ['D', 'dec', 'i < n?'],
    ['E', 'dec', 'ini[i] >= livre_em?'],
    ['F', 'proc', 'Aceita; livre_em\u00a0=\u00a0fim[i]'],
    ['G', 'proc', 'i++'],
    ['H', 'io', 'Mostra as aceitas (5)'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D'],
    ['D', 'E', 'Sim'],
    ['E', 'F', 'Sim'],
    ['E', 'G', 'Não'],
    ['F', 'G'],
    ['G', 'D'],
    ['D', 'H', 'Não'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'D', 'E', 'G', 'D', 'H'],
}
