// Foto do começo da volta com i = 4: a parte verde (pix[0..3]) já foi vista e
// o invariante garante que maior = 300 é o máximo dela. Embaixo, os quatro
// passos da prova.
export const ideia = {
  caixas: [
    { id: 'maior', forma: 'caixinha', x: 100, y: 40, nome: 'maior', valor: '300', tipo: 'int', cor: 'verde' },
    {
      id: 'v',
      forma: 'array',
      x: 560,
      y: 40,
      nome: 'pix',
      celula: 130,
      itens: ['120', '45', '300', '80', '210', '95'],
      estados: { 0: 'verde', 1: 'verde', 2: 'verde', 3: 'verde', 4: 'apagado', 5: 'apagado' },
    },
    { id: 'p1', x: 100, y: 420, w: 300, h: 170, cor: 'roxo', rotulo: '1. início', texto: ['maior = pix[0]', 'vale para [0..0]'] },
    { id: 'p2', x: 480, y: 420, w: 300, h: 170, cor: 'roxo', rotulo: '2. manutenção', texto: ['olha pix[i]:', 'continua valendo'] },
    { id: 'p3', x: 860, y: 420, w: 300, h: 170, cor: 'verde', rotulo: '3. término', texto: ['i == n: maior é', 'o máximo de tudo'] },
    { id: 'p4', x: 1240, y: 420, w: 300, h: 170, cor: 'roxo', rotulo: '4. parada', texto: ['n - i diminui', 'a cada volta'] },
  ],
  setas: [
    { de: 'p1', para: 'p2' },
    { de: 'p2', para: 'p3' },
    { pontos: [[1145, 330], [1145, 236]], cor: 'roxo' },
  ],
  notas: [
    { x: 820, y: 262, texto: 'pix[0..3]: já visto', cor: 'verde', ancora: 'middle' },
    { x: 1145, y: 366, texto: 'i = 4', cor: 'roxo', ancora: 'middle' },
    { x: 330, y: 300, texto: ['invariante: maior é', 'o máximo de pix[0..i-1]'], cor: 'verde', ancora: 'middle' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'io', 'Ler os 6 Pix'],
    ['C', 'proc', 'maior = pix[0]; i = 1'],
    ['D', 'dec', 'i < 6?'],
    ['E', 'dec', 'pix[i] > maior?'],
    ['F', 'proc', 'maior = pix[i]'],
    ['G', 'proc', 'i++'],
    ['H', 'io', 'Mostrar maior (300)'],
    ['I', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D'],
    ['D', 'E', 'Sim'],
    ['E', 'F', 'Sim'],
    ['E', 'G', 'Não'],
    ['F', 'G'],
    ['G', 'D'],
    ['D', 'H', 'Não'],
    ['H', 'I'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'G', 'D', 'E', 'F', 'G', 'D', 'H', 'I'],
}
