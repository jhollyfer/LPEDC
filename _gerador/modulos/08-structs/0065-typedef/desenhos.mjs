export const ideia = {
  caixas: [
    { id: 'tpix', x: 100, y: 40, w: 200, h: 110, cor: 'cinza', texto: ['Pix'] },
    { id: 'spix', x: 430, y: 20, w: 420, cor: 'cinza', rotulo: 'struct sem nome', texto: ['chave, valor, hora'] },
    { id: 'treais', x: 100, y: 200, w: 200, h: 110, cor: 'cinza', texto: ['Reais'] },
    { id: 'dbl', x: 430, y: 200, w: 420, h: 110, cor: 'cinza', texto: ['double'] },
    {
      id: 'p',
      x: 1000,
      y: 20,
      w: 440,
      h: 230,
      cor: 'azul',
      rotulo: 'Pix p',
      texto: ['chave: ana@email.com', 'valor: 1500.00', 'hora: 22'],
    },
    { id: 'q', forma: 'losango', x: 1000, y: 310, w: 440, h: 230, cor: 'amarelo', texto: ['22h é noturno', 'e 1500 > 1000?'] },
    { id: 'bloq', x: 430, y: 360, w: 420, h: 130, cor: 'vermelho', texto: ['Bloqueado'] },
  ],
  setas: [
    { de: 'tpix', para: 'spix', rotulo: 'apelido de' },
    { de: 'treais', para: 'dbl', rotulo: 'apelido de' },
    { de: 'p', para: 'q' },
    { de: 'q', para: 'bloq', lados: 'ed', rotulo: 'Sim', cor: 'vermelho' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'io', 'Pix de R$ 1500.00 às 22h'],
    ['C', 'dec', 'hora >= 20 ou < 6?'],
    ['D', 'dec', 'valor > 1000?'],
    ['E', 'io', 'Bloqueado'],
    ['F', 'io', 'Enviado!'],
    ['G', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D', 'Sim'],
    ['C', 'F', 'Não'],
    ['D', 'E', 'Sim'],
    ['D', 'F', 'Não'],
    ['E', 'G'],
    ['F', 'G'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'G'],
}
