export const ideia = {
  caixas: [
    { id: 'p', x: 100, y: 40, w: 400, h: 210, cor: 'roxo', rotulo: 'programa', texto: ['fprintf(arq, ...)', 'x 3 despesas'] },
    { id: 'b', x: 600, y: 40, w: 380, h: 210, cor: 'azul', rotulo: 'buffer (na RAM)', texto: ['Mercado 152.40', 'Luz 98.75 ...'] },
    { id: 'a', forma: 'arquivo', x: 1100, y: 20, w: 380, nome: 'despesas.txt', texto: ['Mercado 152.40', 'Luz 98.75', 'Internet 99.90'], cor: 'azul' },
    { id: 't', forma: 'terminal', x: 560, y: 400, w: 460, texto: ['1: Mercado 152.40', '2: Luz 98.75', '3: Internet 99.90'] },
  ],
  setas: [
    { de: 'p', para: 'b', rotulo: 'copia' },
    { de: 'b', para: 'a', rotulo: 'fclose' },
    { de: 'a', para: 't', lados: 'bd', cotovelo: true, rotulo: 'fgets, linha a linha' },
  ],
  notas: [
    { x: 1260, y: 300, texto: 'no disco', cor: 'cinza', ancora: 'end' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'proc', 'Abrir despesas.txt com "w"'],
    ['C', 'dec', 'Abriu o arquivo?'],
    ['D', 'io', 'fprintf das 3 despesas'],
    ['E', 'proc', 'fclose e abrir com "r"'],
    ['F', 'dec', 'fgets leu uma linha?'],
    ['G', 'io', 'Mostrar n: linha'],
    ['H', 'io', 'Mostrar "3 linhas"'],
    ['I', 'io', 'perror e sai'],
    ['J', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D', 'Sim'],
    ['C', 'I', 'Não'],
    ['D', 'E'],
    ['E', 'F'],
    ['F', 'G', 'Sim'],
    ['G', 'F'],
    ['F', 'H', 'Não'],
    ['H', 'J'],
    ['I', 'J'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'F', 'H', 'J'],
}
