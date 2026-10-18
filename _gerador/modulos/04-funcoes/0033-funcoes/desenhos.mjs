export const ideia = {
  caixas: [
    { id: 'm', x: 100, y: 120, w: 380, cor: 'azul', rotulo: 'main', texto: ['preco_corrida(4.0)'] },
    { id: 'f', x: 700, y: 60, w: 420, h: 240, cor: 'roxo', rotulo: 'preco_corrida(km)', texto: ['km = 4.0', 'preco = 5.00 + 2.50 * km', 'return preco;'] },
    { id: 'r', x: 700, y: 470, w: 420, cor: 'verde', rotulo: 'de volta no main', texto: ['recebe 15.00'] },
    { id: 't', forma: 'terminal', x: 100, y: 480, w: 380, texto: ['Corrida 1:', 'R$ 15.00'] },
  ],
  setas: [
    { de: 'm', para: 'f', rotulo: 'copia 4.0' },
    { de: 'f', para: 'r', rotulo: 'devolve 15.00', cor: 'verde' },
    { de: 'r', para: 't', rotulo: 'printf' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início do main'],
    ['B', 'proc', 'Chama preco_corrida(4.0)'],
    ['C', 'proc', 'km = 4.0'],
    ['D', 'proc', 'preco = 5.00 + 2.50 * km'],
    ['E', 'proc', 'return preco: volta ao main'],
    ['F', 'io', 'Mostrar "Corrida: R$ 15.00"'],
    ['G', 'dec', 'Falta corrida?'],
    ['H', 'inicio', 'Fim'],
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
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'B', 'C', 'D', 'E', 'F', 'G', 'H'],
}
