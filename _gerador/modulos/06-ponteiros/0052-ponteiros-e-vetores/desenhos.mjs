const linha = (i) => 60 + i * 80 + 48
export const ideia = {
  caixas: [
    {
      id: 'm',
      forma: 'memoria',
      x: 150,
      y: 60,
      celula: 80,
      titulo: 'int kwh[5]',
      celulas: [
        { end: '0x1000', nome: 'kwh[0]', valor: '210', cor: 'verde' },
        { end: '0x1004', nome: 'kwh[1]', valor: '185', cor: 'verde' },
        { end: '0x1008', nome: 'kwh[2]', valor: '240', cor: 'verde' },
        { end: '0x100C', nome: 'kwh[3]', valor: '198', cor: 'verde' },
        { end: '0x1010', nome: 'kwh[4]', valor: '225', cor: 'verde' },
        { end: '0x1014', valor: 'kwh + 5', cor: 'apagado' },
      ],
    },
    { id: 'p', forma: 'caixinha', x: 960, y: 0, nome: 'p', valor: '0x1000', tipo: 'const int *', cor: 'roxo' },
    {
      id: 's',
      x: 960,
      y: 330,
      w: 420,
      h: 170,
      cor: 'verde',
      rotulo: 'soma += *p a cada volta',
      texto: ['soma = 1058'],
    },
  ],
  setas: [{ pontos: [[950, linha(0) - 8], [720, linha(0) - 8]], rotulo: 'p aponta' }],
  notas: [
    { x: 570, y: linha(1), texto: 'p + 1', cor: 'roxo' },
    { x: 570, y: linha(2), texto: 'p + 2', cor: 'roxo' },
    { x: 570, y: linha(3), texto: 'p + 3  (+12 bytes)', cor: 'roxo' },
    { x: 570, y: linha(4), texto: 'p + 4', cor: 'roxo' },
    { x: 470, y: linha(5), texto: 'só para comparar: nunca leia', cor: 'cinza' },
    { x: 960, y: 290, texto: 'p++ anda 4 bytes (um int)', cor: 'roxo' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'proc', 'p = kwh; soma = 0'],
    ['C', 'dec', 'p < kwh + 5?'],
    ['D', 'proc', 'soma = soma + *p'],
    ['E', 'proc', 'p++ (próxima gaveta)'],
    ['F', 'io', 'Mostrar total 1058 e média 211.6'],
    ['G', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D', 'Sim'],
    ['D', 'E'],
    ['E', 'C'],
    ['C', 'F', 'Não'],
    ['F', 'G'],
  ],
}
