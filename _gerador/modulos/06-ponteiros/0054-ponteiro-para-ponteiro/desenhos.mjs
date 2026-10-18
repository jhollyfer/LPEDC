export const ideia = {
  caixas: [
    {
      id: 'm',
      forma: 'memoria',
      x: 320,
      y: 80,
      celula: 110,
      titulo: 'memória (endereços fictícios)',
      celulas: [
        { end: '0x1000', nome: 'vagas', valor: '40 → 38', tipo: 'int', cor: 'verde' },
        { end: '0x1008', nome: 'p', valor: '0x1000', tipo: 'int *', cor: 'roxo' },
        { end: '0x1010', nome: 'pp', valor: '0x1008', tipo: 'int **', cor: 'roxo' },
      ],
      ponteiros: [
        [1, 0],
        [2, 1],
      ],
    },
    {
      id: 'tab',
      x: 900,
      y: 40,
      w: 480,
      h: 270,
      cor: 'azul',
      rotulo: 'lendo a partir de pp',
      texto: ['pp    vale 0x1008', '*pp   vale 0x1000', '**pp  vale 40'],
    },
    { id: 'muda', x: 900, y: 390, w: 480, cor: 'verde', texto: ['**pp = **pp - 2;', 'vagas vira 38'] },
  ],
  setas: [{ de: 'tab', para: 'muda', rotulo: '2 carros entraram' }],
  notas: [
    { x: 150, y: 210, texto: '2º salto', cor: 'roxo', tam: 22 },
    { x: 150, y: 320, texto: '1º salto', cor: 'roxo', tam: 22 },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'proc', 'vagas = 40'],
    ['C', 'proc', 'p = &vagas'],
    ['D', 'proc', 'pp = &p'],
    ['E', 'proc', '**pp = **pp - 2'],
    ['F', 'io', 'Mostrar vagas (38)'],
    ['G', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D'],
    ['D', 'E'],
    ['E', 'F'],
    ['F', 'G'],
  ],
}
