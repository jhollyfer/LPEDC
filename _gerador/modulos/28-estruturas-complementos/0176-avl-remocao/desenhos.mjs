// Em cima, a AVL dos pedidos antes de o 30 sair (vermelho), e o conserto
// no 28 (rotação dupla). Embaixo, a árvore no fim, depois da rotação
// simples no 20. Amarelo: nó desequilibrado; verde: quem subiu.
const comum = { forma: 'arvore', dx: 54, dy: 110, raio: 30 }
const nota = (x, y, texto, cor = 'roxo') => ({ x, y, texto, cor, tam: 24 })

export const ideia = {
  caixas: [
    {
      ...comum,
      id: 'antes',
      x: 110,
      y: 130,
      raiz: {
        v: 20,
        e: {
          v: 12,
          e: { v: 6, e: { v: 3, e: { v: 1 }, d: { v: 4 } }, d: { v: 9, e: { v: 8 }, d: { v: 10 } } },
          d: { v: 16, e: { v: 14 }, d: { v: 18 } },
        },
        d: { v: 28, e: { v: 25, d: { v: 26 } }, d: { v: 30 } },
      },
      estados: { 30: 'vermelho', 28: 'amarelo', 20: 'amarelo', 25: 'azul', 26: 'azul' },
    },
    { ...comum, id: 's1', x: 1000, y: 160, dx: 70, raiz: { v: 28, e: { v: 25, d: { v: 26 } } }, estados: { 28: 'amarelo', 25: 'azul', 26: 'azul' } },
    { ...comum, id: 's2', x: 1330, y: 160, dx: 70, raiz: { v: 26, e: { v: 25 }, d: { v: 28 } }, estados: { 26: 'verde' } },
    {
      ...comum,
      id: 'depois',
      x: 110,
      y: 780,
      raiz: {
        v: 12,
        e: { v: 6, e: { v: 3, e: { v: 1 }, d: { v: 4 } }, d: { v: 9, e: { v: 8 }, d: { v: 10 } } },
        d: { v: 20, e: { v: 16, e: { v: 14 }, d: { v: 18 } }, d: { v: 26, e: { v: 25 }, d: { v: 28 } } },
      },
      estados: { 12: 'verde', 20: 'amarelo', 26: 'verde' },
      marcadas: [[12, 20], [20, 16]],
    },
  ],
  setas: [
    { pontos: [[1240, 196], [1330, 196]], cor: 'roxo' },
    { pontos: [[700, 640], [700, 760]], rotulo: 'simples à direita no 20', cor: 'roxo' },
  ],
  notas: [
    { x: 100, y: 100, texto: 'ANTES: O PEDIDO 30 SAI (ALTURA 4)', cor: 'cinza' },
    nota(1050, 120, ['1. no 28: fator 2, filho com -1'], 'roxo'),
    nota(1050, 470, ['dupla: o 26 sobe', 'a subárvore cai de altura 2', 'para 1: o 20 fica com fator 2'], 'roxo'),
    { x: 100, y: 750, texto: 'DEPOIS: 3 ROTAÇÕES, ALTURA 3', cor: 'cinza' },
    nota(1050, 860, ['2. no 20: fator 2, filho 12', 'com fator 1: simples', 'o 12 vira a raiz e o 16', 'passa para a esquerda do 20'], 'verde'),
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'rebalanceia(28)'],
    ['B', 'proc', 'atualiza a altura e calcula fb (2)'],
    ['C', 'dec', 'fb > 1?'],
    ['D', 'dec', 'fator do filho esquerdo < 0?'],
    ['E', 'proc', 'r->esq = rot_esquerda(r->esq)'],
    ['F', 'proc', 'r = rot_direita(r)'],
    ['G', 'dec', 'fb < -1?'],
    ['H', 'proc', 'simples ou dupla, do outro lado'],
    ['I', 'io', 'Devolver r (26)'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D', 'Sim'],
    ['C', 'G', 'Não'],
    ['D', 'E', 'Sim'],
    ['D', 'F', 'Não'],
    ['E', 'F'],
    ['F', 'I'],
    ['G', 'H', 'Sim'],
    ['G', 'I', 'Não'],
    ['H', 'I'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'F', 'I'],
}
