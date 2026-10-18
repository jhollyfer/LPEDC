export const ideia = {
  caixas: [
    { id: 'in', x: 100, y: 240, w: 330, cor: 'azul', rotulo: 'dois int', texto: ['km = 523', 'litros = 41'] },
    { id: 'e', x: 560, y: 40, w: 480, cor: 'vermelho', rotulo: 'sem cast', texto: ['523 / 41 = 12', 'só depois vira 12.0'] },
    { id: 'c', x: 560, y: 440, w: 480, cor: 'verde', rotulo: 'com cast', texto: ['(double) 523 = 523.0', '523.0 / 41 = 12.756'] },
    { id: 't1', forma: 'terminal', x: 1150, y: 70, w: 320, texto: ['12.00 km/l'] },
    { id: 't2', forma: 'terminal', x: 1150, y: 470, w: 320, texto: ['12.76 km/l'] },
  ],
  setas: [
    { de: 'in', para: 'e', lados: 'ce', cotovelo: true, cor: 'vermelho', rotulo: 'km / litros' },
    { de: 'in', para: 'c', lados: 'be', cotovelo: true, cor: 'verde', rotulo: '(double) km / litros' },
    { de: 'e', para: 't1' },
    { de: 'c', para: 't2' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'proc', 'km = 523, litros = 41'],
    ['C', 'dec', 'Tem um real na divisão?'],
    ['D', 'proc', 'Divisão real: 12.756'],
    ['E', 'proc', 'Divisão inteira: 12'],
    ['F', 'proc', 'Guarda no double'],
    ['G', 'io', 'Mostrar o consumo'],
    ['H', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D', 'Sim'],
    ['C', 'E', 'Não'],
    ['D', 'F'],
    ['E', 'F'],
    ['F', 'G'],
    ['G', 'H'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'F', 'G', 'H'],
}
