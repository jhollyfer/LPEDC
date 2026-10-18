// o shell sort dos pacotes da van: na rodada h = 4, cada cor é uma fileira
// (posições a 4 casas de distância); na rodada h = 1, tudo fica no lugar
const X = 300
const grupo = (i) => ['amarelo', 'roxo', 'verde', 'azul'][i % 4]
const cores = Object.fromEntries([0, 1, 2, 3, 4, 5, 6, 7, 8, 9].map((i) => [i, grupo(i)]))
const linhas = [
  ['início', ['62', '17', '85', '40', '9', '73', '28', '51', '94', '33'], cores, ['mesma cor = mesma', 'fileira (salto 4)']],
  ['h = 4', ['9', '17', '28', '40', '62', '33', '85', '51', '94', '73'], cores, ['cada fileira em ordem', '3 movimentos']],
  ['h = 1', ['9', '17', '28', '33', '40', '51', '62', '73', '85', '94'], Object.fromEntries([0, 1, 2, 3, 4, 5, 6, 7, 8, 9].map((i) => [i, 'verde'])), ['insertion comum:', '6 movimentos (total 9)']],
]

export const ideia = {
  caixas: linhas.map(([, itens, estados], i) => ({
    id: `v${i}`,
    forma: 'array',
    x: X,
    y: 60 + i * 170,
    celula: 86,
    itens,
    estados,
    indices: i === 0,
  })),
  setas: [
    // os três pulos da rodada h = 4: 62, 85 e 73 andam 4 casas
    { pontos: [[343, 54], [343, 34], [687, 34], [687, 54]] },
    { pontos: [[515, 54], [515, 14], [859, 14], [859, 54]] },
    { pontos: [[773, 54], [773, -6], [1117, -6], [1117, 54]] },
  ],
  notas: [
    ...linhas.map(([rotulo], i) => ({ x: 110, y: 112 + i * 170, texto: rotulo, cor: i === 0 ? 'azul' : 'roxo' })),
    ...linhas.map(([, , , nota], i) => ({ x: 1200, y: 94 + i * 170, texto: nota, cor: i === 2 ? 'verde' : 'roxo' })),
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início: v com n elementos'],
    ['B', 'proc', 'h = 1'],
    ['C', 'dec', 'h < n / 3?'],
    ['D', 'proc', 'h = 3h + 1'],
    ['E', 'dec', 'h >= 1?'],
    ['F', 'proc', 'insertion sort com salto h'],
    ['G', 'proc', 'h = h / 3'],
    ['H', 'inicio', 'Fim: v ordenado'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D', 'Sim'],
    ['D', 'C'],
    ['C', 'E', 'Não'],
    ['E', 'F', 'Sim'],
    ['F', 'G'],
    ['G', 'E'],
    ['E', 'H', 'Não'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'C', 'E', 'F', 'G', 'E', 'F', 'G', 'E', 'H'],
}
