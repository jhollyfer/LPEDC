// a terceira chamada do exemplo: Caio é achado na 4ª comparação e vai para
// a frente da lista; quem estava antes dele anda uma casa para trás
export const ideia = {
  caixas: [
    {
      id: 'antes',
      forma: 'lista',
      x: 110,
      y: 150,
      cabeca: 'inicio',
      vao: 70,
      itens: ['Edu', 'Ana', 'Bia', 'Caio', 'Duda'],
      estados: { 0: 'amarelo', 1: 'amarelo', 2: 'amarelo', 3: 'verde' },
      rotulos: ['1ª', '2ª', '3ª', '4ª'],
    },
    {
      id: 'depois',
      forma: 'lista',
      x: 110,
      y: 420,
      cabeca: 'inicio',
      vao: 70,
      itens: ['Caio', 'Edu', 'Ana', 'Bia', 'Duda'],
      estados: { 0: 'verde' },
    },
  ],
  setas: [{ pontos: [[985, 270], [985, 330], [330, 330], [330, 418]], rotulo: 'Caio vai para a frente', cor: 'verde' }],
  notas: [
    { x: 110, y: 620, texto: ['busca "Caio": 4 comparações', 'na próxima chamada de Caio: 1'], cor: 'cinza' },
    { x: 800, y: 620, texto: ['os 5 acessos custam 13,', 'contra 23 na lista fixa'], cor: 'verde' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'io', 'Ler o nome (Caio)'],
    ['C', 'proc', 'p = início; ant = NULL'],
    ['D', 'dec', 'p == NULL?'],
    ['N', 'io', 'Mostrar "não achou"'],
    ['E', 'dec', 'p->nome é o nome?'],
    ['F', 'proc', 'ant = p; p = p->prox'],
    ['G', 'dec', 'ant == NULL?'],
    ['H', 'proc', 'Tirar p do lugar e pôr no início'],
    ['I', 'io', 'Mostrar a lista'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D'],
    ['D', 'N', 'Sim'],
    ['D', 'E', 'Não'],
    ['E', 'F', 'Não'],
    ['F', 'D'],
    ['E', 'G', 'Sim'],
    ['G', 'I', 'Sim'],
    ['G', 'H', 'Não'],
    ['H', 'I'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'F', 'D', 'E', 'F', 'D', 'E', 'F', 'D', 'E', 'G', 'H', 'I'],
}
