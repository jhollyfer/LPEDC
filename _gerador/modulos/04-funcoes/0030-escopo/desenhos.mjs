export const ideia = {
  caixas: [
    { id: 'dados', x: 100, y: 40, w: 760, h: 360, cor: 'cinza', rotulo: 'dados: vive o programa todo', texto: [] },
    { id: 'g', forma: 'caixinha', x: 140, y: 130, nome: 'atendidos', valor: '3', tipo: 'global', w: 300, cor: 'verde' },
    { id: 's', forma: 'caixinha', x: 520, y: 130, nome: 'senha', valor: '103', tipo: 'static', w: 300, cor: 'verde' },
    { id: 'pilha', x: 960, y: 40, w: 500, h: 360, cor: 'cinza', rotulo: 'pilha: só durante a chamada', texto: [] },
    { id: 'v', forma: 'caixinha', x: 1060, y: 130, nome: 'vezes', valor: '1', tipo: 'local', w: 300, cor: 'roxo' },
    { id: 'm', x: 100, y: 500, w: 760, cor: 'azul', rotulo: 'main', texto: ['chamar(); chamar(); chamar();'] },
    { id: 'z', x: 960, y: 500, w: 500, cor: 'vermelho', rotulo: 'no return', texto: ['vezes some'] },
  ],
  setas: [
    { de: 'm', para: 'dados', rotulo: '3 chamadas' },
    { de: 'pilha', para: 'z' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início: senha = 100'],
    ['B', 'proc', 'main chama chamar()'],
    ['C', 'proc', 'Cria vezes = 0'],
    ['D', 'proc', 'senha++, vezes++, atendidos++'],
    ['E', 'io', 'Mostrar senha, vezes, atendidos'],
    ['F', 'proc', 'return: vezes some'],
    ['G', 'dec', 'Mais uma chamada?'],
    ['H', 'io', 'Mostrar a última senha (103)'],
    ['I', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D'],
    ['D', 'E'],
    ['E', 'F'],
    ['F', 'G'],
    ['G', 'B', 'Sim'],
    ['G', 'H', 'Não'],
    ['H', 'I'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'],
}
