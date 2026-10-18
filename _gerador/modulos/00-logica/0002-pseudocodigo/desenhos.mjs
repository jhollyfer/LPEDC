export const ideia = {
  caixas: [
    { id: 'n1', forma: 'caixinha', x: 100, y: 40, nome: 'nota1', valor: '7.5', tipo: 'real' },
    { id: 'n2', forma: 'caixinha', x: 100, y: 290, nome: 'nota2', valor: '5.5', tipo: 'real' },
    { id: 'c', x: 480, y: 175, w: 360, cor: 'roxo', rotulo: 'calcula', texto: ['(7.5 + 5.5) / 2', 'media = 6.5'] },
    { id: 'p', x: 960, y: 145, w: 280, h: 200, forma: 'losango', cor: 'amarelo', texto: ['media >= 6 ?'] },
    { id: 't', forma: 'terminal', x: 1300, y: 185, w: 230, texto: ['Aprovado'] },
  ],
  setas: [
    { de: 'n1', para: 'c' },
    { de: 'n2', para: 'c' },
    { de: 'c', para: 'p' },
    { de: 'p', para: 't', rotulo: 'Sim', cor: 'verde' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'io', 'Ler nota1 e nota2'],
    ['C', 'proc', 'media = (nota1 + nota2) / 2'],
    ['D', 'dec', 'media >= 6?'],
    ['E', 'io', 'Mostrar "Aprovado"'],
    ['F', 'io', 'Mostrar "Reprovado"'],
    ['G', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D'],
    ['D', 'E', 'Sim'],
    ['D', 'F', 'Não'],
    ['E', 'G'],
    ['F', 'G'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'G'],
}
