export const ideia = {
  caixas: [
    { id: 'm', forma: 'caixinha', x: 100, y: 80, nome: 'mensalidade', valor: '120.00', tipo: 'double (main)', end: '0x7ffc10', w: 280 },
    { id: 'c', forma: 'caixinha', x: 620, y: 80, nome: 'mensalidade', valor: '132.00', tipo: 'double (reajustar)', end: '0x7ffbd8', w: 280, cor: 'roxo' },
    { id: 'r', x: 1110, y: 120, w: 360, cor: 'verde', rotulo: 'return', texto: ['devolve 132.00'] },
    { id: 'g', x: 620, y: 420, w: 850, cor: 'verde', rotulo: 'no main', texto: ['mensalidade = reajustar(mensalidade, 10);'] },
    { id: 'i', x: 100, y: 420, w: 380, cor: 'cinza', rotulo: 'sem guardar', texto: ['continua 120.00'] },
  ],
  setas: [
    { de: 'm', para: 'c', rotulo: 'copia 120.00' },
    { de: 'c', para: 'r' },
    { de: 'r', para: 'g', rotulo: 'guardou' },
    { de: 'm', para: 'i' },
  ],
  notas: [
    { x: 760, y: 60, texto: 'x 1.10', cor: 'roxo', ancora: 'middle' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'proc', 'mensalidade = 120.00'],
    ['C', 'proc', 'Copia 120.00 para o parâmetro'],
    ['D', 'proc', 'Cópia vira 132.00'],
    ['E', 'proc', 'return 132.00'],
    ['F', 'dec', 'Guardou o retorno?'],
    ['G', 'io', 'Mostrar 132.00'],
    ['H', 'io', 'Mostrar 120.00'],
    ['I', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D'],
    ['D', 'E'],
    ['E', 'F'],
    ['F', 'G', 'Sim'],
    ['F', 'H', 'Não'],
    ['G', 'I'],
    ['H', 'I'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'I'],
}
