// as quatro partes do for, na ordem em que rodam: começa (uma vez), pergunta,
// corpo, passo, e volta para a pergunta
export const ideia = {
  caixas: [
    { id: 'i', x: 100, y: 325, w: 330, cor: 'roxo', rotulo: '1. começa (uma vez)', texto: ['parcela = 1'] },
    { id: 'p', x: 520, y: 300, w: 340, h: 200, forma: 'losango', cor: 'amarelo', texto: ['2. pergunta', 'parcela <= 6 ?'] },
    { id: 'c', x: 980, y: 305, w: 420, cor: 'roxo', rotulo: '3. corpo', texto: ['falta = falta - 300', 'mostra a parcela'] },
    { id: 's', x: 980, y: 600, w: 420, cor: 'roxo', rotulo: '4. passo', texto: ['parcela++'] },
    { id: 't', forma: 'terminal', x: 520, y: 40, w: 340, texto: ['Carnê quitado!'] },
  ],
  setas: [
    { de: 'i', para: 'p' },
    { de: 'p', para: 'c', lados: 'de', rotulo: 'Sim', cor: 'verde' },
    { de: 'c', para: 's', lados: 'bc' },
    { pontos: [[964, 675], [690, 675], [690, 516]], rotulo: 'volta', cor: 'roxo' },
    { de: 'p', para: 't', lados: 'cb', rotulo: 'Não', cor: 'vermelho' },
  ],
  notas: [
    { x: 100, y: 820, texto: 'parcela vale 1, 2, 3, 4, 5, 6: seis voltas com Sim', cor: 'verde' },
    { x: 100, y: 858, texto: 'com parcela = 7 a pergunta dá Não e o laço acaba', cor: 'cinza' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'proc', 'parcela = 1'],
    ['C', 'dec', 'parcela <= 6?'],
    ['D', 'proc', 'falta = falta - 300'],
    ['E', 'io', 'Mostrar parcela e falta'],
    ['F', 'proc', 'parcela++'],
    ['G', 'io', 'Mostrar "Carnê quitado!"'],
    ['H', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D', 'Sim'],
    ['D', 'E'],
    ['E', 'F'],
    ['F', 'C'],
    ['C', 'G', 'Não'],
    ['G', 'H'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'F', 'C', 'G', 'H'],
}
