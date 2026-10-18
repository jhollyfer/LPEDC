export const ideia = {
  caixas: [
    { id: 'i', forma: 'caixinha', x: 100, y: 40, w: 290, nome: 'idade', valor: '25', tipo: 'int · 4 bytes', end: '0x7ffe...048' },
    { id: 'a', forma: 'caixinha', x: 450, y: 40, w: 290, nome: 'altura', valor: '1.75', tipo: 'float · 4 bytes', end: '0x7ffe...04c' },
    { id: 'p', forma: 'caixinha', x: 800, y: 40, w: 290, nome: 'peso', valor: '72.5', tipo: 'double · 8 bytes', end: '0x7ffe...050', cor: 'cinza' },
    { id: 'c', forma: 'caixinha', x: 1150, y: 40, w: 290, nome: 'plano', valor: "'B'", tipo: 'char · 1 byte', end: '0x7ffe...047' },
    { id: 'n', forma: 'caixinha', x: 800, y: 420, w: 290, nome: 'peso', valor: '71.8', tipo: 'double · 8 bytes', end: 'mesmo endereço', cor: 'verde' },
    { id: 'x', x: 280, y: 450, w: 420, cor: 'roxo', rotulo: 'um mês depois', texto: ['peso = 71.8;', 'o 72.5 some'] },
  ],
  setas: [
    { de: 'p', para: 'n', rotulo: 'escreve por cima' },
    { de: 'x', para: 'n' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'proc', 'Criar idade, altura, peso e plano'],
    ['C', 'io', 'Mostrar a ficha'],
    ['D', 'proc', 'peso = 71.8'],
    ['E', 'io', 'Mostrar o peso novo e os bytes'],
    ['F', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D'],
    ['D', 'E'],
    ['E', 'F'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'F'],
}
