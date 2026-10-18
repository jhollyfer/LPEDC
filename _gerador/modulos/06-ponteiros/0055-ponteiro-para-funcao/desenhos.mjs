export const ideia = {
  caixas: [
    {
      id: 'cod',
      forma: 'memoria',
      x: 120,
      y: 80,
      celula: 90,
      cor: 'cinza',
      titulo: 'área de código',
      celulas: [
        { end: '0x401136', nome: 'eh_calor', valor: 'return t >= 30;', cor: 'verde' },
        { end: '0x401150', nome: 'eh_frio', valor: 'return t <= 18;' },
        { end: '0x401170', nome: 'conta_se', valor: 'laço que chama', cor: 'roxo' },
      ],
    },
    {
      id: 'pil',
      forma: 'memoria',
      x: 1010,
      y: 80,
      celula: 90,
      cor: 'roxo',
      titulo: 'frame de conta_se',
      celulas: [
        { end: '0x7010', nome: 'criterio', valor: '0x401136', tipo: 'int (*)(int)' },
        { end: '0x7018', nome: 'cont', valor: '3', tipo: 'int', cor: 'verde' },
      ],
    },
    {
      id: 'v',
      forma: 'array',
      x: 120,
      y: 430,
      nome: 'temps',
      itens: ['31', '27', '33', '18', '16', '29', '34'],
      estados: { 0: 'verde', 2: 'verde', 6: 'verde' },
    },
    { id: 'r', x: 1010, y: 430, w: 430, cor: 'verde', texto: ['criterio(v[i])', 'é eh_calor(v[i])'] },
  ],
  setas: [
    { pontos: [[1000, 125], [740, 125]], rotulo: 'aponta' },
    { de: 'v', para: 'r', rotulo: '3 passam' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'proc', 'criterio = eh_calor; cont = 0; i = 0'],
    ['C', 'dec', 'i < 7?'],
    ['D', 'dec', 'criterio(v[i])?'],
    ['E', 'proc', 'cont++'],
    ['F', 'proc', 'i++'],
    ['G', 'io', 'Mostrar "Dias de calor: 3"'],
    ['H', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D', 'Sim'],
    ['D', 'E', 'Sim'],
    ['D', 'F', 'Não'],
    ['E', 'F'],
    ['F', 'C'],
    ['C', 'G', 'Não'],
    ['G', 'H'],
  ],
}
