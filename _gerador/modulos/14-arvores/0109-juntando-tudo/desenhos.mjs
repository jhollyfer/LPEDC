// o programa do módulo: a BST guarda os alunos pela matrícula; o ranking
// copia os treinos para um vetor, monta um heap e tira o máximo 3 vezes
export const ideia = {
  caixas: [
    {
      id: 'cad',
      forma: 'arvore',
      x: 100,
      y: 130,
      dx: 95,
      dy: 150,
      raiz: {
        v: 50,
        e: { v: 30, nota: 'sai', e: { v: 20 }, d: { v: 40 } },
        d: { v: 70, e: { v: 60, nota: 'treinou' }, d: { v: 80 } },
      },
      estados: { 30: 'vermelho', 50: 'amarelo', 70: 'amarelo', 60: 'verde' },
      marcadas: [
        [50, 70],
        [70, 60],
      ],
    },
    {
      id: 'vet',
      forma: 'array',
      x: 830,
      y: 110,
      nome: 'treinos, em ordem de matrícula',
      celula: 100,
      itens: [4, 20, 12, 10, 15, 11],
    },
    {
      id: 'h',
      x: 830,
      y: 370,
      w: 600,
      h: 150,
      cor: 'roxo',
      rotulo: 'heap de máximo pelos treinos',
      texto: ['monta em O(n), tira o máximo 3 vezes'],
    },
    { id: 't', forma: 'terminal', x: 830, y: 600, w: 600, texto: ['1º Eva (20)', '2º Carla (15)', '3º Ana (12)'] },
  ],
  setas: [
    { pontos: [[680, 206], [815, 206]], rotulo: 'em ordem', cor: 'roxo' },
    { de: 'vet', para: 'h' },
    { de: 'h', para: 't' },
  ],
  notas: [
    { x: 100, y: 620, texto: ['BST pela matrícula:', 'busca, insere e remove', 'descendo um caminho só'], cor: 'cinza' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'proc', 'Insere os 7 alunos na BST'],
    ['C', 'io', 'Lista em ordem de matrícula'],
    ['D', 'proc', 'Busca o 60; treinos++'],
    ['E', 'proc', 'Remove o 30'],
    ['F', 'proc', 'Copia para um vetor e monta o heap'],
    ['G', 'dec', 'Já mostrou 3?'],
    ['H', 'io', 'Mostra o máximo e tira do heap'],
    ['I', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D'],
    ['D', 'E'],
    ['E', 'F'],
    ['F', 'G'],
    ['G', 'H', 'Não'],
    ['H', 'G'],
    ['G', 'I', 'Sim'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'G', 'I'],
}
