// tabela em y = 60: a vaga i ocupa de 60 + 64 i até 124 + 64 i
const meio = (i) => 60 + 64 * i + 32

export const ideia = {
  caixas: [
    { id: 'k', forma: 'caixinha', x: 100, y: 110, nome: 'busca', valor: '1104', tipo: 'apartamento' },
    { id: 'h', x: 100, y: 410, w: 330, h: 150, cor: 'roxo', rotulo: 'hash', texto: ['1104 % 11 = 4'] },
    {
      id: 't',
      forma: 'tabela',
      x: 640,
      y: 60,
      w: 170,
      baldes: ['', '', '101', '', '202', '301', '1104', '', '', '504', ''],
      estados: { 4: 'amarelo', 5: 'amarelo', 6: 'verde' },
    },
  ],
  setas: [
    { de: 'k', para: 'h' },
    { pontos: [[446, 485], [540, 485], [540, meio(4)], [634, meio(4)]], cor: 'roxo' },
    { pontos: [[880, meio(4)], [920, meio(4)], [920, meio(5)], [880, meio(5)]], cor: 'cinza' },
    { pontos: [[880, meio(5)], [920, meio(5)], [920, meio(6)], [880, meio(6)]], cor: 'cinza' },
  ],
  notas: [
    { x: 950, y: meio(4) + 8, texto: '1ª: 202? não, próxima', cor: 'vermelho' },
    { x: 950, y: meio(5) + 8, texto: '2ª: 301? não, próxima', cor: 'vermelho' },
    { x: 950, y: meio(6) + 8, texto: '3ª: 1104? achou!', cor: 'verde' },
    { x: 950, y: meio(7) + 8, texto: 'livre: aqui uma busca pararia', cor: 'cinza' },
    { x: 676, y: 36, texto: 'vagas (m = 11)', cor: 'cinza' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'io', 'Ler apto (1104)'],
    ['C', 'proc', 'i = apto % 11 (4)'],
    ['D', 'dec', 'vaga i livre?'],
    ['E', 'dec', 'é o apto?'],
    ['F', 'proc', 'i = (i + 1) % 11'],
    ['G', 'io', 'Mostrar "achou na vaga i"'],
    ['H', 'io', 'Mostrar "não está"'],
    ['I', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D'],
    ['D', 'H', 'Sim'],
    ['D', 'E', 'Não'],
    ['E', 'G', 'Sim'],
    ['E', 'F', 'Não'],
    ['F', 'D'],
    ['G', 'I'],
    ['H', 'I'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'F', 'D', 'E', 'F', 'D', 'E', 'G', 'I'],
}
