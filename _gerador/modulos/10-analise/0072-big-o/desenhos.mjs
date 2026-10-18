// Tabela de calor: cada linha é uma classe, cada coluna um tamanho de n.
// Verde ainda é leve, amarelo pesa, vermelho explodiu. Valores do A143.
const linhas = [
  ['O(1)', 'primeiro da fila', ['1', '1', '1'], ['verde', 'verde', 'verde']],
  ['O(log n)', 'cortar ao meio', ['3', '6', '10'], ['verde', 'verde', 'verde']],
  ['O(n)', 'somar tudo', ['8', '64', '1024'], ['verde', 'verde', 'amarelo']],
  ['O(n log n)', 'uma busca por pedido', ['24', '384', '10240'], ['verde', 'amarelo', 'amarelo']],
  ['O(n²)', 'todos os pares', ['28', '2016', '523776'], ['verde', 'amarelo', 'vermelho']],
]
const colunas = [640, 930, 1220]
const caixas = []
linhas.forEach(([classe, pergunta, valores, cores], r) => {
  const y = 90 + r * 150
  caixas.push({ id: `c${r}`, x: 100, y, w: 460, h: 130, cor: 'roxo', rotulo: classe, texto: [pergunta] })
  valores.forEach((v, k) => caixas.push({ id: `v${r}${k}`, x: colunas[k], y, w: 250, h: 130, cor: cores[k], texto: [v] }))
})

export const ideia = {
  caixas,
  setas: [],
  notas: [
    { x: 330, y: 60, texto: 'pergunta', cor: 'cinza', ancora: 'middle' },
    { x: 765, y: 60, texto: 'n = 8', cor: 'azul', ancora: 'middle' },
    { x: 1055, y: 60, texto: 'n = 64', cor: 'azul', ancora: 'middle' },
    { x: 1345, y: 60, texto: 'n = 1024', cor: 'azul', ancora: 'middle' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'io', 'Ler n (1024)'],
    ['C', 'proc', 'passos = 0'],
    ['D', 'dec', 'n > 1?'],
    ['E', 'proc', 'n = n / 2; passos++'],
    ['F', 'io', 'Mostrar passos (10)'],
    ['G', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D'],
    ['D', 'E', 'Sim'],
    ['E', 'D'],
    ['D', 'F', 'Não'],
    ['F', 'G'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'D', 'F', 'G'],
}
