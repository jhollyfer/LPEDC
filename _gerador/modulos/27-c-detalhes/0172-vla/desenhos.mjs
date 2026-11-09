// a planilha 3 x 4 e o lugar dela: um bloco reservado na pilha, na hora
const linha = (i, itens) => ({
  id: 'l' + i,
  forma: 'array',
  x: 100,
  y: 80 + i * 110,
  itens,
  celula: 100,
  indices: false,
})

export const ideia = {
  caixas: [
    linha(0, ['1', '3', '5', '2']),
    linha(1, ['4', '1', '3', '5']),
    linha(2, ['2', '4', '1', '3']),
    { id: 'tam', x: 100, y: 450, w: 400, h: 150, cor: 'verde', texto: ['3 x 4 x 4 bytes', '= 48 bytes'] },
    { id: 'livre', x: 900, y: 40, w: 520, h: 130, cor: 'cinza', texto: ['espaço livre (até ~8 MB)'] },
    { id: 'vla', x: 900, y: 190, w: 520, h: 150, cor: 'roxo', rotulo: 'treinos[alunos][semanas]', texto: ['48 bytes, reservados agora'] },
    { id: 'vars', x: 900, y: 360, w: 520, h: 150, cor: 'azul', rotulo: 'main', texto: ['alunos = 3, semanas = 4'] },
    { id: 'erro', x: 900, y: 560, w: 520, h: 150, cor: 'vermelho', texto: ['int v[3000000]: 12 MB', 'não cabe: o programa cai'] },
  ],
  setas: [{ de: 'l1', para: 'vla', rotulo: 'mora na pilha' }],
  notas: [
    { x: 100, y: 50, texto: 'semana 1   2   3   4', cor: 'cinza' },
    { x: 1440, y: 360, texto: ['pilha', 'cresce', 'para', 'cima'], cor: 'cinza' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'io', 'ler alunos = 3, semanas = 4'],
    ['C', 'dec', 'leu e está entre os limites?'],
    ['D', 'io', 'valores inválidos'],
    ['E', 'proc', 'int treinos[3][4] na pilha'],
    ['F', 'io', 'sizeof treinos = 48 bytes'],
    ['G', 'proc', 'preencher(3, 4, treinos)'],
    ['H', 'io', 'mostrar cada aluno e o total'],
    ['I', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'E', 'Sim'],
    ['C', 'D', 'Não'],
    ['E', 'F'],
    ['F', 'G'],
    ['G', 'H'],
    ['H', 'I'],
    ['D', 'I'],
  ],
  caminho: ['A', 'B', 'C', 'E', 'F', 'G', 'H', 'I'],
}
