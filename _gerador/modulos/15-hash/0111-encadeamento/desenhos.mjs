export const ideia = {
  caixas: [
    { id: 'k', forma: 'caixinha', x: 100, y: 120, nome: 'busca', valor: '"kiwi"', tipo: 'a chave' },
    { id: 'h', x: 100, y: 400, w: 300, h: 150, cor: 'roxo', rotulo: 'hash % 5', texto: ['índice 1'] },
    {
      id: 't',
      forma: 'tabela',
      x: 560,
      y: 60,
      baldes: [[], ['manga', 'kiwi'], ['uva'], [], ['caju', 'pera', 'banana']],
      estados: { 1: 'amarelo' },
    },
  ],
  setas: [
    { de: 'k', para: 'h' },
    { pontos: [[416, 475], [470, 475], [470, 156], [562, 156]], cor: 'roxo' },
  ],
  notas: [
    { x: 765, y: 112, texto: '1ª: manga? não', cor: 'vermelho' },
    { x: 960, y: 220, texto: '2ª: kiwi? achou!', cor: 'verde' },
    { x: 1030, y: 400, texto: ['3 frutas no balde 4:', 'cada nova entra na frente'], cor: 'cinza' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'io', 'Ler chave ("kiwi")'],
    ['C', 'proc', 'i = hash % 5; p = baldes[i]'],
    ['D', 'dec', 'p != NULL?'],
    ['E', 'dec', 'p->chave igual?'],
    ['F', 'proc', 'p = p->prox'],
    ['G', 'io', 'Mostrar valor (5 caixas)'],
    ['H', 'io', 'Mostrar "não tem"'],
    ['I', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D'],
    ['D', 'H', 'Não'],
    ['D', 'E', 'Sim'],
    ['E', 'G', 'Sim'],
    ['E', 'F', 'Não'],
    ['F', 'D'],
    ['G', 'I'],
    ['H', 'I'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'F', 'D', 'E', 'G', 'I'],
}
