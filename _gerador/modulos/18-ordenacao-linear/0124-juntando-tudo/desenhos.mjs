// o milhão de Pix: os mesmos dados vão para o qsort e para o radix; os dois
// conferem, e o counting sort estável põe o vetor do radix em ordem de horário
export const ideia = {
  caixas: [
    { id: 'ger', x: 110, y: 230, w: 330, h: 190, cor: 'azul', rotulo: 'pix_gera', texto: ['1 milhão de Pix', 'id, hora e valor'] },
    { id: 'qs', x: 560, y: 60, w: 400, h: 190, cor: 'roxo', rotulo: 'qsort(a)', texto: ['~20 milhões de', 'comparações: 0,28 s'] },
    { id: 'rx', x: 560, y: 400, w: 400, h: 190, cor: 'roxo', rotulo: 'pix_por_valor(b)', texto: ['radix: 4 passadas', 'de 1 milhão: 0,08 s'] },
    { id: 'cmp', x: 1080, y: 225, w: 330, h: 200, forma: 'losango', cor: 'amarelo', texto: ['mesma ordem', 'de valores?'] },
    { id: 'ct', x: 1050, y: 560, w: 390, h: 190, cor: 'roxo', rotulo: 'pix_por_horario(b)', texto: ['counting estável,', 'k = 86400: 0,04 s'] },
    { id: 'res', x: 560, y: 720, w: 400, h: 190, cor: 'verde', rotulo: 'resultado', texto: ['por horário e, no', 'segundo, por valor'] },
  ],
  setas: [
    { de: 'ger', para: 'qs', lados: 'ce', cotovelo: true, rotulo: 'cópia a' },
    { de: 'ger', para: 'rx', lados: 'be', cotovelo: true, rotulo: 'cópia b' },
    { de: 'qs', para: 'cmp', lados: 'dc', cotovelo: true },
    { pontos: [[976, 495], [1030, 495], [1030, 325], [1064, 325]] },
    { de: 'cmp', para: 'ct', lados: 'bc', rotulo: 'sim' },
    { de: 'ct', para: 'res', lados: 'bd', cotovelo: true },
  ],
  notas: [{ x: 110, y: 950, texto: 'tempos de uma execução com o rodar (mudam de máquina para máquina)', cor: 'cinza' }],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'io', 'Gera 1 milhão de Pix em a'],
    ['C', 'proc', 'copia a para b'],
    ['D', 'proc', 'qsort(a) pelo valor'],
    ['E', 'proc', 'radix(b) pelo valor'],
    ['F', 'io', 'Mostra os tempos e se a e b batem (sim)'],
    ['G', 'proc', 'counting(b) pelo horário'],
    ['H', 'dec', 'conseguiu os 86400 contadores?'],
    ['I', 'io', 'Mostra os 4 primeiros do dia'],
    ['J', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D'],
    ['D', 'E'],
    ['E', 'F'],
    ['F', 'G'],
    ['G', 'H'],
    ['H', 'I', 'Sim'],
    ['H', 'J', 'Não'],
    ['I', 'J'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'],
}
