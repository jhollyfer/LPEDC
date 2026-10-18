// A busca da comanda 70: seis comparações erradas (amarelo), a sétima acerta
// (verde) e a última gaveta nem é olhada (apagada).
export const ideia = {
  caixas: [
    { id: 'alvo', forma: 'caixinha', x: 100, y: 40, nome: 'alvo', valor: '70', tipo: 'int' },
    {
      id: 'v',
      forma: 'array',
      x: 520,
      y: 40,
      nome: 'comandas',
      celula: 120,
      itens: ['41', '17', '88', '23', '56', '9', '70', '35'],
      estados: { 0: 'amarelo', 1: 'amarelo', 2: 'amarelo', 3: 'amarelo', 4: 'amarelo', 5: 'amarelo', 6: 'verde', 7: 'apagado' },
    },
    { id: 'p', forma: 'caixinha', x: 100, y: 330, nome: 'passos', valor: '7', tipo: 'int', cor: 'verde' },
    { id: 'melhor', x: 520, y: 330, w: 440, cor: 'cinza', rotulo: 'melhor caso', texto: ['41 está na frente: 1 passo'] },
    { id: 'pior', x: 1020, y: 330, w: 460, cor: 'cinza', rotulo: 'pior caso', texto: ['99 não está: 8 passos'] },
  ],
  setas: [{ de: 'alvo', para: 'v', rotulo: 'compara' }],
  notas: [
    { x: 580, y: 238, texto: '1', cor: 'amarelo', ancora: 'middle' },
    { x: 700, y: 238, texto: '2', cor: 'amarelo', ancora: 'middle' },
    { x: 820, y: 238, texto: '3', cor: 'amarelo', ancora: 'middle' },
    { x: 940, y: 238, texto: '4', cor: 'amarelo', ancora: 'middle' },
    { x: 1060, y: 238, texto: '5', cor: 'amarelo', ancora: 'middle' },
    { x: 1180, y: 238, texto: '6', cor: 'amarelo', ancora: 'middle' },
    { x: 1300, y: 238, texto: '7: achou!', cor: 'verde', ancora: 'middle' },
    { x: 1420, y: 276, texto: 'nem olha', cor: 'cinza', ancora: 'middle' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'io', 'Ler alvo (70)'],
    ['C', 'proc', 'i = 0; passos = 0'],
    ['D', 'dec', 'i < 8?'],
    ['E', 'proc', 'passos++'],
    ['F', 'dec', 'comandas[i] == alvo?'],
    ['G', 'proc', 'i++'],
    ['H', 'io', 'Mostrar posição 6, passos 7'],
    ['I', 'io', 'Mostrar posição -1'],
    ['J', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D'],
    ['D', 'E', 'Sim'],
    ['E', 'F'],
    ['F', 'H', 'Sim'],
    ['F', 'G', 'Não'],
    ['G', 'D'],
    ['D', 'I', 'Não'],
    ['H', 'J'],
    ['I', 'J'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'D', 'E', 'F', 'H', 'J'],
}
