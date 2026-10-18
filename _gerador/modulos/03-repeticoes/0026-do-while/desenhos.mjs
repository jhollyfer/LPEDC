// do-while: o corpo vem primeiro; a pergunta fica no fim e, no Sim, a seta
// volta para o começo do corpo
export const ideia = {
  caixas: [
    { id: 'd', x: 480, y: 40, w: 360, cor: 'azul', rotulo: 'primeiro faz', texto: ['pergunta e lê', 'parcelas'] },
    { id: 'p', x: 490, y: 320, w: 340, h: 200, forma: 'losango', cor: 'amarelo', texto: ['fora de', '1 a 12 ?'] },
    { id: 'r', x: 990, y: 345, w: 400, cor: 'verde', rotulo: 'aceita', texto: ['4x de R$ 300.00'] },
  ],
  setas: [
    { de: 'd', para: 'p', lados: 'bc', rotulo: 'depois pergunta', cor: 'roxo' },
    { pontos: [[474, 420], [390, 420], [390, 135], [464, 135]], rotulo: 'Sim', cor: 'verde', dx: -60 },
    { de: 'p', para: 'r', lados: 'de', rotulo: 'Não', cor: 'vermelho' },
  ],
  notas: [
    { x: 490, y: 590, texto: 'digitou 0: fora, Sim, de novo', cor: 'cinza' },
    { x: 490, y: 628, texto: 'digitou 15: fora, Sim, de novo', cor: 'cinza' },
    { x: 490, y: 666, texto: 'digitou 4: dentro, Não, segue', cor: 'verde' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'io', 'Mostrar a pergunta'],
    ['B2', 'io', 'Ler parcelas'],
    ['C', 'dec', 'parcelas < 1 ou > 12?'],
    ['D', 'proc', 'valor = preco / parcelas'],
    ['E', 'io', 'Mostrar "4x de R$ 300.00"'],
    ['F', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'B2'],
    ['B2', 'C'],
    ['C', 'B', 'Sim'],
    ['C', 'D', 'Não'],
    ['D', 'E'],
    ['E', 'F'],
  ],
  caminho: ['A', 'B', 'B2', 'C', 'B', 'B2', 'C', 'B', 'B2', 'C', 'D', 'E', 'F'],
}
