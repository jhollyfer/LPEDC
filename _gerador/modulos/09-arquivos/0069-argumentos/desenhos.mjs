export const ideia = {
  caixas: [
    { id: 't', forma: 'terminal', x: 100, y: 30, w: 560, texto: ['$ ./racha 187.40 4'] },
    { id: 'n', forma: 'caixinha', x: 1060, y: 0, nome: 'argc', valor: '3', tipo: 'int' },
    { id: 'v', forma: 'array', x: 100, y: 330, nome: 'argv', celula: 220, itens: ['"./racha"', '"187.40"', '"4"', 'NULL'], estados: { 3: 'apagado' } },
    { id: 'c', x: 1060, y: 300, w: 440, h: 190, cor: 'roxo', rotulo: 'converte', texto: ['strtod: 187.4', 'strtol: 4'] },
    { id: 'r', x: 1060, y: 600, w: 440, h: 190, cor: 'verde', rotulo: 'resultado', texto: ['187.40 / 4', 'Cada um: R$ 46.85'] },
  ],
  setas: [
    { pontos: [[430, 200], [430, 370]], rotulo: 'o shell corta nos espaços' },
    { de: 't', para: 'n', rotulo: 'quantos' },
    { de: 'v', para: 'c', rotulo: 'texto' },
    { de: 'c', para: 'r', rotulo: 'números' },
  ],
  notas: [
    { x: 100, y: 560, texto: 'tudo no argv é string (char *)', cor: 'azul' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início: ./racha 187.40 4'],
    ['B', 'dec', 'argc == 3?'],
    ['C', 'proc', 'total = strtod(argv[1])'],
    ['D', 'proc', 'pessoas = strtol(argv[2])'],
    ['E', 'dec', 'Os dois são válidos?'],
    ['F', 'io', 'Mostrar R$ 46.85 cada'],
    ['G', 'io', 'Erro em stderr, return 1'],
    ['H', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C', 'Sim'],
    ['B', 'G', 'Não'],
    ['C', 'D'],
    ['D', 'E'],
    ['E', 'F', 'Sim'],
    ['E', 'G', 'Não'],
    ['F', 'H'],
    ['G', 'H'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'F', 'H'],
}
