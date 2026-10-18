// a semente entra no gerador, que tira cada número do anterior; o % 6 + 1
// transforma os números enormes em faces de dado
export const ideia = {
  caixas: [
    { id: 's', forma: 'caixinha', x: 100, y: 51, nome: 'semente', valor: '2022', tipo: 'srand(2022)', w: 240 },
    { id: 'g', x: 450, y: 80, w: 330, cor: 'roxo', rotulo: 'rand()', texto: ['conta fixa sobre', 'o número anterior'] },
    {
      id: 'b',
      x: 890,
      y: 40,
      w: 520,
      cor: 'azul',
      rotulo: 'sai de rand(), de 0 a RAND_MAX',
      texto: ['1341262422 e 470018536', '1999695688 e 506003004', '176614656 e 1031155547', '2054337963 e 23099775'],
    },
    { id: 'd', x: 890, y: 470, w: 520, cor: 'verde', rotulo: 'as faces: 1 + (r % 6)', texto: ['1 e 5', '5 e 1', '1 e 6', '4 e 4: dupla!'] },
  ],
  setas: [
    { de: 's', para: 'g' },
    { de: 'g', para: 'b', lados: 'de' },
    { de: 'b', para: 'd', lados: 'bc', rotulo: '% 6 + 1' },
  ],
  notas: [
    { x: 100, y: 520, texto: 'mesma semente: mesma sequência,', cor: 'roxo' },
    { x: 100, y: 558, texto: 'em toda execução', cor: 'roxo' },
    { x: 100, y: 636, texto: 'srand(time(NULL)): a semente', cor: 'cinza' },
    { x: 100, y: 674, texto: 'muda a cada segundo', cor: 'cinza' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'proc', 'srand(2022)'],
    ['C', 'proc', 'dado1 e dado2 = 1 + rand() % 6'],
    ['D', 'io', 'Mostrar a jogada'],
    ['E', 'dec', 'dado1 != dado2?'],
    ['F', 'io', 'Mostrar "Saiu da prisão!"'],
    ['G', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D'],
    ['D', 'E'],
    ['E', 'C', 'Sim'],
    ['E', 'F', 'Não'],
    ['F', 'G'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'C', 'D', 'E', 'F', 'G'],
}
