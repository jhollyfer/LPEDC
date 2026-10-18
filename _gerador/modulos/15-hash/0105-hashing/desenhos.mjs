export const ideia = {
  caixas: [
    { id: 'nome', forma: 'caixinha', x: 100, y: 362, nome: 'nome', valor: '"caio"', tipo: 'a chave' },
    {
      id: 'h',
      x: 440,
      y: 381,
      w: 420,
      h: 210,
      cor: 'roxo',
      rotulo: 'função hash',
      texto: ['99+97+105+111 = 412', '412 % 7 = 6'],
    },
    {
      id: 't',
      forma: 'tabela',
      x: 1050,
      y: 70,
      w: 170,
      baldes: ['davi', '', 'lia', 'ana', '', '', 'bia'],
      estados: { 6: 'vermelho' },
    },
  ],
  setas: [
    { de: 'nome', para: 'h' },
    { pontos: [[876, 486], [1050, 486]], rotulo: 'índice 6', cor: 'vermelho' },
  ],
  notas: [
    { x: 1290, y: 488, texto: ['ocupado por bia:', 'colisão!'], cor: 'vermelho' },
    { x: 1086, y: 40, texto: 'armários (m = 7)', cor: 'cinza' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'io', 'Ler nome ("caio")'],
    ['C', 'proc', 'soma = 0'],
    ['D', 'dec', 'tem mais letra?'],
    ['E', 'proc', 'soma = soma + código da letra'],
    ['F', 'proc', 'a = soma % 7 (412 % 7 = 6)'],
    ['G', 'dec', 'armário a ocupado?'],
    ['H', 'io', 'Mostrar "colisão com bia!"'],
    ['I', 'proc', 'dono[a] = nome; mostrar a'],
    ['J', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D'],
    ['D', 'E', 'Sim'],
    ['E', 'D'],
    ['D', 'F', 'Não'],
    ['F', 'G'],
    ['G', 'H', 'Sim'],
    ['G', 'I', 'Não'],
    ['H', 'J'],
    ['I', 'J'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'D', 'F', 'G', 'H', 'J'],
}
