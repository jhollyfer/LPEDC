export const ideia = {
  caixas: [
    { id: 'casa', forma: 'caixinha', x: 100, y: 20, nome: 'gols_casa', valor: '2', tipo: 'int' },
    { id: 'fora', forma: 'caixinha', x: 100, y: 300, nome: 'gols_fora', valor: '1', tipo: 'int' },
    {
      id: 'cmp',
      x: 470,
      y: 110,
      w: 400,
      h: 250,
      cor: 'amarelo',
      rotulo: 'três perguntas',
      texto: ['2 >  1  vale 1', '2 == 1  vale 0', '2 <  1  vale 0'],
    },
    {
      id: 'b',
      x: 990,
      y: 40,
      w: 420,
      cor: 'roxo',
      rotulo: 'bool',
      texto: ['venceu = 1 (true)', 'empatou = 0 (false)'],
    },
    { id: 'p', x: 990, y: 300, w: 420, cor: 'verde', rotulo: 'pontos', texto: ['3 * 1 + 0 = 3'] },
  ],
  setas: [
    { de: 'casa', para: 'cmp' },
    { de: 'fora', para: 'cmp' },
    { de: 'cmp', para: 'b', rotulo: 'guarda' },
    { de: 'b', para: 'p', rotulo: 'vira conta' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'io', 'Ler gols_casa e gols_fora'],
    ['C', 'proc', 'venceu = casa > fora'],
    ['D', 'proc', 'empatou = casa == fora'],
    ['E', 'proc', 'pontos = 3 * venceu + empatou'],
    ['F', 'io', 'Mostrar pontos (3)'],
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
