export const ideia = {
  caixas: [
    {
      id: 'm',
      forma: 'memoria',
      x: 160,
      y: 60,
      celula: 90,
      titulo: 'memória (endereços fictícios)',
      celulas: [
        { end: '0x1000', nome: 'idade', valor: '30', tipo: 'int · 4 bytes' },
        { end: '0x1004', valor: '', cor: 'apagado' },
        { end: '0x1008', nome: 'mensalidade', valor: '119.90', tipo: 'double · 8 bytes' },
        { end: '0x1010', nome: 'plano', valor: "'B'", tipo: 'char · 1 byte' },
      ],
    },
    {
      id: 'amp',
      x: 820,
      y: 20,
      w: 560,
      cor: 'roxo',
      rotulo: 'o & pergunta: onde mora?',
      texto: ['&idade vale 0x1000', '&mensalidade vale 0x1008', '&plano vale 0x1010'],
    },
    {
      id: 't',
      forma: 'terminal',
      x: 820,
      y: 330,
      w: 560,
      texto: ['idade: 30, mora em 0x1000', 'ocupa 4 bytes'],
    },
  ],
  setas: [
    { pontos: [[690, 105], [800, 105]], rotulo: '&idade' },
    { de: 'amp', para: 't', rotulo: '%p mostra' },
  ],
  notas: [{ x: 300, y: 470, texto: 'cada gaveta = 1 byte; a variável usa várias', cor: 'cinza', ancora: 'start', tam: 22 }],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'proc', 'Guardar idade, mensalidade e plano'],
    ['C', 'io', 'Mostrar o valor (30)'],
    ['D', 'proc', 'Pegar o endereço com &'],
    ['E', 'io', 'Mostrar o endereço com %p'],
    ['F', 'io', 'Mostrar o tamanho (sizeof)'],
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
