// o mini-grep: as linhas do quadro de avisos passam por uma Busca escolhida
// num vetor de algoritmos; as linhas com "garagem" vão para a tela
export const ideia = {
  caixas: [
    {
      id: 'arq',
      forma: 'arquivo',
      x: 110,
      y: 40,
      w: 520,
      nome: 'avisos (8 linhas)',
      cor: 'azul',
      texto: ['1 Aviso: a piscina fecha...', '3 A garagem ... da garagem', '5 Proibido lavar ... garagem', '8 Interfone da garagem ...'],
    },
    {
      id: 'g',
      x: 820,
      y: 70,
      w: 640,
      h: 190,
      cor: 'roxo',
      rotulo: 'mini-grep',
      texto: ['para cada linha l:', 'k = busca(l, "garagem")'],
    },
    {
      id: 'alg',
      forma: 'cardapio',
      x: 920,
      y: 400,
      w: 440,
      titulo: 'Algoritmo algs[]',
      destaque: 1,
      itens: [
        ['bruta', '348 comp.'],
        ['KMP', '368 comp.'],
        ['Horspool', '83 comp.'],
        ['Rabin-Karp', '28 comp.'],
      ],
    },
    {
      id: 't',
      forma: 'terminal',
      x: 110,
      y: 430,
      w: 660,
      texto: ['grep "garagem":', '3: A garagem do bloco B...', '5: Proibido lavar carro...', '8: Interfone da garagem...'],
    },
  ],
  setas: [
    { de: 'arq', para: 'g', rotulo: 'linha a linha' },
    { de: 'g', para: 'alg', lados: 'bc', rotulo: 'ponteiro de função' },
    { pontos: [[860, 276], [860, 350], [440, 350], [440, 414]], rotulo: 'k > 0: mostra a linha', cor: 'verde' },
  ],
  notas: [
    { x: 920, y: 790, texto: 'mesmo resultado (4 ocorrências),', cor: 'cinza' },
    { x: 920, y: 828, texto: 'trabalho bem diferente', cor: 'cinza' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início: l = 0'],
    ['B', 'dec', 'l < linhas?'],
    ['C', 'proc', 'k = pb_kmp(linha l, "garagem")'],
    ['D', 'dec', 'k > 0?'],
    ['E', 'io', 'Mostrar l + 1 e a linha (3, 5, 8)'],
    ['F', 'proc', 'l++'],
    ['G', 'proc', 'Repetir com os 4 algoritmos, somando as comparações'],
    ['H', 'io', 'Mostrar a tabela'],
    ['I', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C', 'Sim'],
    ['C', 'D'],
    ['D', 'E', 'Sim'],
    ['D', 'F', 'Não'],
    ['E', 'F'],
    ['F', 'B'],
    ['B', 'G', 'Não'],
    ['G', 'H'],
    ['H', 'I'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'F', 'B', 'G', 'H', 'I'],
}
