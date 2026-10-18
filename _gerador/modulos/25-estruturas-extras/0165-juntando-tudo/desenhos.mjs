// a bancada: o mesmo teste passa pelos quatro concorrentes, que só se
// conhecem pela interface Estrutura; o terminal mostra o custo médio
const conc = [
  ['bst', 'BST', 'árvore sem equilíbrio', 'roxo'],
  ['avl', 'AVL', 'árvore com rotações', 'verde'],
  ['skip', 'skip list', 'andares sorteados', 'roxo'],
  ['mtf', 'lista MTF', 'o achado vai à frente', 'roxo'],
]

export const ideia = {
  caixas: [
    {
      id: 'teste',
      x: 110,
      y: 250,
      w: 330,
      h: 270,
      cor: 'azul',
      rotulo: 'o mesmo teste',
      texto: ['1000 chaves', '10000 buscas', '80% delas em', '20 chaves'],
    },
    ...conc.map(([id, nome, desc, cor], i) => ({
      id,
      x: 560,
      y: 100 + i * 150,
      w: 360,
      h: 120,
      cor,
      rotulo: nome,
      texto: [desc],
    })),
    {
      id: 't',
      forma: 'terminal',
      x: 1030,
      y: 230,
      w: 470,
      texto: ['        emb.  cresc.', 'BST     11.9  569.7', 'AVL      8.9    9.1', 'skip    16.4   18.3', 'MTF    114.6  114.5'],
    },
  ],
  setas: [
    ...conc.map(([id]) => ({ de: 'teste', para: id, lados: 'de', cor: 'roxo' })),
    { pontos: [[935, 385], [1015, 385]], cor: 'roxo' },
  ],
  notas: [
    { x: 110, y: 740, texto: 'custo = chaves comparadas por busca (a média das 10000)', cor: 'cinza' },
    { x: 1030, y: 590, texto: ['emb. = chaves inseridas', 'embaralhadas; cresc. = em', 'ordem crescente'], cor: 'cinza' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'proc', 'Montar as duas ordens e as 10000 buscas'],
    ['C', 'dec', 'Falta algum concorrente?'],
    ['D', 'proc', 'Criar e inserir as 1000 chaves'],
    ['E', 'proc', 'Fazer as buscas somando o custo'],
    ['F', 'io', 'Mostrar o custo médio'],
    ['G', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D', 'Sim'],
    ['D', 'E'],
    ['E', 'F'],
    ['F', 'C'],
    ['C', 'G', 'Não'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'F', 'C', 'G'],
}
