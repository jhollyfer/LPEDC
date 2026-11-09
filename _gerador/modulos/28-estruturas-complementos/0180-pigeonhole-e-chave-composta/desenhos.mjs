// Em cima, a lista de chamada (ordem alfabética). No meio, as casas das
// notas 3, 5, 7 e 9 (as outras ficam vazias), cada uma uma fila. Embaixo,
// as casas esvaziadas em ordem: por nota e, no empate, por nome.
const casa = (id, x, nota, nomes) => ({ id, x, y: 420, w: 240, h: 110 + nomes.length * 40, cor: 'roxo', rotulo: `casa ${nota}`, texto: nomes })

export const ideia = {
  caixas: [
    { id: 'e', forma: 'array', x: 110, y: 120, nome: 'chamada', celula: 160, itens: ['Ana 7', 'Bruno 5', 'Carla 9', 'Diego 5', 'Elisa 7', 'Fabio 3', 'Gabi 9', 'Hugo 5'] },
    casa('c3', 110, 3, ['Fabio']),
    casa('c5', 420, 5, ['Bruno', 'Diego', 'Hugo']),
    casa('c7', 730, 7, ['Ana', 'Elisa']),
    casa('c9', 1040, 9, ['Carla', 'Gabi']),
    {
      id: 's',
      forma: 'array',
      x: 110,
      y: 830,
      nome: 'saída',
      celula: 160,
      cor: 'verde',
      itens: ['Fabio 3', 'Bruno 5', 'Diego 5', 'Hugo 5', 'Ana 7', 'Elisa 7', 'Carla 9', 'Gabi 9'],
    },
  ],
  setas: [
    { pontos: [[695, 300], [695, 400]], rotulo: '1. cada um no fim da fila da sua nota', cor: 'roxo' },
    { pontos: [[695, 700], [695, 820]], rotulo: '2. esvazia as casas 0, 1, ..., 10 em ordem', cor: 'roxo' },
  ],
  notas: [
    { x: 1320, y: 470, texto: ['casas 0, 1, 2,', '4, 6, 8 e 10:', 'vazias'], cor: 'cinza', tam: 22 },
    { x: 110, y: 1060, texto: 'empates na ordem de chegada (estável): a chave composta (nota, nome) sai de graça', cor: 'verde', tam: 24 },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'io', 'Ler os 8 alunos e o intervalo 0..10'],
    ['C', 'proc', 'cria 11 casas vazias; i = 0'],
    ['D', 'dec', 'i < n?'],
    ['E', 'proc', 'põe v[i] no fim da casa v[i].nota; i++'],
    ['F', 'proc', 'para c de 0 a 10: tira os alunos da casa c, em ordem'],
    ['G', 'io', 'Mostrar a lista ordenada'],
    ['H', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D'],
    ['D', 'E', 'Sim'],
    ['E', 'D'],
    ['D', 'F', 'Não'],
    ['F', 'G'],
    ['G', 'H'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'D', 'F', 'G', 'H'],
}
