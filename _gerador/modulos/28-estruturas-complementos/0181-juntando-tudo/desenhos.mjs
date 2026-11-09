// As três estruturas da agenda depois de a Ana desmarcar: a hash dos
// pacientes (só as posições ocupadas das 101), a rubro-negra dos horários
// e a fila de espera com sentinela.
export const ideia = {
  caixas: [
    {
      id: 'h',
      forma: 'memoria',
      x: 110,
      y: 150,
      w: 360,
      titulo: 'hash (m = 101)',
      celulas: [
        { end: '[22]', valor: 'Carla · 08:00', cor: 'azul' },
        { end: '[25]', valor: 'Diego · 09:00', cor: 'verde' },
        { end: '[28]', valor: 'Elisa · espera', cor: 'amarelo' },
        { end: '[45]', valor: 'Ana · sem horário', cor: 'azul' },
        { end: '[66]', valor: 'Bruno · 10:30', cor: 'azul' },
      ],
    },
    {
      id: 'a',
      forma: 'arvore',
      x: 690,
      y: 170,
      dx: 150,
      dy: 150,
      raio: 50,
      raiz: { v: '09:00', nota: 'Diego', e: { v: '08:00', nota: 'Carla' }, d: { v: '10:30', nota: 'Bruno' } },
      estados: { '09:00': 'cinza', '08:00': 'vermelho', '10:30': 'vermelho' },
      marcadas: [],
    },
    {
      id: 'f',
      forma: 'lista',
      x: 690,
      y: 560,
      dupla: true,
      circular: true,
      cabeca: 'fila',
      itens: ['nil', 'Elisa'],
      estados: { 0: 'cinza', 1: 'amarelo' },
    },
  ],
  setas: [],
  notas: [
    { x: 690, y: 130, texto: 'RUBRO-NEGRA DOS HORÁRIOS', cor: 'cinza' },
    { x: 1080, y: 230, texto: ['o 09:00 era da Ana:', 'o Diego, 1º da fila,', 'assumiu'], cor: 'verde', tam: 24 },
    { x: 690, y: 530, texto: 'FILA DE ESPERA (LISTA COM SENTINELA)', cor: 'cinza' },
    { x: 110, y: 560, texto: ['chave: CPF', 'h1 = cpf % 101', 'h2 = 1 + cpf % 100'], cor: 'roxo', tam: 24 },
    { x: 110, y: 720, texto: ['as estruturas se ligam', 'por chaves: CPF e horário'], cor: 'cinza', tam: 24 },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'ag_cancela(09:00)'],
    ['B', 'dec', 'tem consulta às 09:00?'],
    ['C', 'io', 'Devolver -1'],
    ['D', 'proc', 'Ana fica sem horário; x->cpf = 0'],
    ['E', 'dec', 'fila vazia?'],
    ['F', 'io', 'Devolver 0 (vago)'],
    ['G', 'proc', 'Diego, o 1º da fila, marca as 09:00 e sai da fila'],
    ['H', 'io', 'Devolver o CPF do Diego'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C', 'Não'],
    ['B', 'D', 'Sim'],
    ['D', 'E'],
    ['E', 'F', 'Sim'],
    ['E', 'G', 'Não'],
    ['G', 'H'],
  ],
  caminho: ['A', 'B', 'D', 'E', 'G', 'H'],
}
