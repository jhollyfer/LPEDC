// remover o 30 (dois filhos): o sucessor 35 (o menor da direita) assume o
// lugar. Antes à esquerda, depois à direita.
export const ideia = {
  caixas: [
    {
      id: 'antes',
      forma: 'arvore',
      x: 100,
      y: 170,
      dx: 72,
      dy: 140,
      raiz: {
        v: 50,
        e: { v: 30, nota: 'sai', e: { v: 20 }, d: { v: 40, e: { v: 35, nota: 'sucessor' }, d: { v: 45 } } },
        d: { v: 70, e: { v: 60 }, d: { v: 80 } },
      },
      estados: { 30: 'vermelho', 40: 'amarelo', 35: 'verde' },
      marcadas: [
        [30, 40],
        [40, 35],
      ],
    },
    {
      id: 'depois',
      forma: 'arvore',
      x: 900,
      y: 170,
      dx: 72,
      dy: 140,
      raiz: {
        v: 50,
        e: { v: 35, e: { v: 20 }, d: { v: 40, d: { v: 45 } } },
        d: { v: 70, e: { v: 60 }, d: { v: 80 } },
      },
      estados: { 35: 'verde' },
    },
  ],
  setas: [{ pontos: [[730, 360], [860, 360]], rotulo: 'remove 30', cor: 'roxo' }],
  notas: [
    { x: 100, y: 145, texto: 'ANTES', cor: 'cinza' },
    { x: 900, y: 145, texto: 'DEPOIS', cor: 'cinza' },
    { x: 100, y: 720, texto: ['1. desce à direita do 30 e vai à esquerda até o fim: 35', '2. copia 35 para o lugar do 30', '3. remove o 35 de baixo (era folha)'], cor: 'roxo' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'remove(r, chave)'],
    ['B', 'dec', 'r == NULL?'],
    ['N', 'io', 'Devolver NULL'],
    ['C', 'dec', 'chave == r->chave?'],
    ['D', 'proc', 'Desce: r->esq ou r->dir = remove(...)'],
    ['F', 'dec', 'Tem dois filhos?'],
    ['G', 'proc', 'O filho (ou NULL) sobe; free(r)'],
    ['H', 'proc', 'Copia o sucessor; remove ele da direita'],
    ['I', 'io', 'Devolver r'],
    ['J', 'io', 'Devolver o filho'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'N', 'Sim'],
    ['B', 'C', 'Não'],
    ['C', 'D', 'Não'],
    ['C', 'F', 'Sim'],
    ['F', 'G', 'Não'],
    ['F', 'H', 'Sim'],
    ['G', 'J'],
    ['H', 'I'],
    ['D', 'I'],
  ],
  caminho: ['A', 'B', 'C', 'F', 'H', 'I'],
}
