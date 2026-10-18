// o mapa do cinema no meio da execução: a fileira A já foi inteira, a B está
// na poltrona 3, e C e D ainda não começaram
const fileira = (letra, y, estados) => ({
  id: letra,
  forma: 'array',
  x: 450,
  y,
  celula: 110,
  indices: false,
  itens: [1, 2, 3, 4, 5].map((n) => `${letra}${n}`),
  estados,
})
const apagada = { 0: 'apagado', 1: 'apagado', 2: 'apagado', 3: 'apagado', 4: 'apagado' }

export const ideia = {
  caixas: [
    fileira('A', 60, { 0: 'verde', 1: 'verde', 2: 'verde', 3: 'verde', 4: 'verde' }),
    fileira('B', 230, { 0: 'verde', 1: 'verde', 2: 'amarelo', 3: 'apagado', 4: 'apagado' }),
    fileira('C', 400, apagada),
    fileira('D', 570, apagada),
  ],
  setas: [
    { pontos: [[340, 70], [340, 650]], cor: 'roxo' },
    { pontos: [[460, 205], [990, 205]], rotulo: 'de dentro: poltrona 1 a 5', cor: 'verde' },
  ],
  notas: [
    { x: 315, y: 340, texto: ['de fora:', 'fileira++'], cor: 'roxo', ancora: 'end' },
    { x: 420, y: 114, texto: 'A', cor: 'cinza', ancora: 'end', tam: 30 },
    { x: 420, y: 284, texto: 'B', cor: 'cinza', ancora: 'end', tam: 30 },
    { x: 420, y: 454, texto: 'C', cor: 'cinza', ancora: 'end', tam: 30 },
    { x: 420, y: 624, texto: 'D', cor: 'cinza', ancora: 'end', tam: 30 },
    { x: 1040, y: 114, texto: 'pronta: o de dentro deu 5 voltas', cor: 'verde' },
    { x: 1040, y: 284, texto: 'agora: fileira B, poltrona 3', cor: 'azul' },
    { x: 1040, y: 454, texto: 'esperando a vez', cor: 'cinza' },
    { x: 1040, y: 624, texto: 'esperando a vez', cor: 'cinza' },
    { x: 450, y: 740, texto: '4 fileiras x 5 poltronas = 20 voltas do laço de dentro', cor: 'roxo' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'proc', "fileira = 'A'"],
    ['C', 'dec', "fileira <= 'D'?"],
    ['D', 'proc', 'poltrona = 1'],
    ['E', 'dec', 'poltrona <= 5?'],
    ['F', 'io', 'Mostrar e poltrona++'],
    ['H', 'proc', 'pula linha; fileira++'],
    ['I', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D', 'Sim'],
    ['D', 'E'],
    ['E', 'F', 'Sim'],
    ['F', 'E'],
    ['E', 'H', 'Não'],
    ['H', 'C'],
    ['C', 'I', 'Não'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'F', 'E', 'H', 'C', 'I'],
}
