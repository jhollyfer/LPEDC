// counting sort das avaliações: a entrada, os contadores (índice = estrelas),
// o acumulado e a saída. Os três pedidos de 3 estrelas (verdes) mantêm a ordem
const X = 330
const tres = { 0: 'verde', 2: 'verde', 7: 'verde' }

export const ideia = {
  caixas: [
    {
      id: 'ent',
      forma: 'array',
      x: X,
      y: 60,
      celula: 100,
      itens: ['A3', 'B1', 'C3', 'D2', 'E1', 'F4', 'G0', 'H3'],
      estados: tres,
    },
    {
      id: 'cont',
      forma: 'array',
      x: X,
      y: 250,
      celula: 100,
      itens: ['1', '2', '1', '3', '1'],
      estados: { 3: 'roxo' },
    },
    {
      id: 'acum',
      forma: 'array',
      x: X,
      y: 440,
      celula: 100,
      itens: ['1', '3', '4', '7', '8'],
      estados: { 3: 'roxo' },
    },
    {
      id: 'sai',
      forma: 'array',
      x: X,
      y: 630,
      celula: 100,
      itens: ['G0', 'B1', 'E1', 'D2', 'A3', 'C3', 'H3', 'F4'],
      estados: { 4: 'verde', 5: 'verde', 6: 'verde' },
    },
  ],
  setas: [
    { pontos: [[580, 194], [580, 244]], rotulo: 'conta', dy: 8 },
    { pontos: [[580, 384], [580, 434]], rotulo: 'acumula', dy: 8 },
    { pontos: [[580, 574], [580, 624]], rotulo: 'distribui', dy: 8 },
  ],
  notas: [
    { x: 110, y: 112, texto: 'entrada', cor: 'azul' },
    { x: 110, y: 302, texto: 'contagem', cor: 'roxo' },
    { x: 110, y: 492, texto: 'acumulado', cor: 'roxo' },
    { x: 110, y: 682, texto: 'saída', cor: 'verde' },
    { x: 900, y: 284, texto: ['c[x]: quantos têm', 'x estrelas'], cor: 'roxo' },
    { x: 900, y: 474, texto: ['c[3] = 7: há 7 com até', '3 estrelas; o bloco do 3', 'termina na posição 6'], cor: 'roxo' },
    { x: 1180, y: 664, texto: ['A, C, H na ordem', 'de chegada: estável'], cor: 'verde' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'io', 'Recebe v (8 avaliações)'],
    ['C', 'proc', 'conta: c[estrelas]++'],
    ['D', 'proc', 'acumula: c[x] += c[x - 1]'],
    ['E', 'dec', 'Falta algum v[i], de trás para a frente?'],
    ['F', 'proc', 'c[x]--; saida[c[x]] = v[i]'],
    ['G', 'io', 'Mostra saida'],
    ['H', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D'],
    ['D', 'E'],
    ['E', 'F', 'Sim'],
    ['F', 'E'],
    ['E', 'G', 'Não'],
    ['G', 'H'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'F', 'E', 'G', 'H'],
}
