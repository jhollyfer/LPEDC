// a rodada de craps: o 1º lançamento abre três caminhos; o 9 vira o ponto e
// o jogo relança até sair 9 (ganha) ou 7 (perde)
export const ideia = {
  caixas: [
    { id: 'soma', forma: 'caixinha', x: 100, y: 236, nome: 'soma', valor: '3 + 6 = 9', tipo: '1º lançamento', w: 260 },
    { id: 'sw', x: 470, y: 290, w: 300, cor: 'amarelo', rotulo: 'switch (soma)', texto: ['qual caso?'] },
    { id: 'g', x: 900, y: 40, w: 330, cor: 'cinza', rotulo: '7 ou 11', texto: ['ganha de cara'] },
    { id: 'p', x: 900, y: 230, w: 330, cor: 'cinza', rotulo: '2, 3 ou 12', texto: ['perde de cara'] },
    { id: 'pt', x: 900, y: 420, w: 330, cor: 'roxo', rotulo: 'outro: o 9', texto: ['vira o ponto'] },
    { id: 'r', x: 895, y: 680, w: 340, h: 200, forma: 'losango', cor: 'amarelo', texto: ['relança:', '9? 7?'] },
    { id: 't', forma: 'terminal', x: 1300, y: 721, w: 220, texto: ['Ganhou'] },
  ],
  setas: [
    { de: 'soma', para: 'sw' },
    { de: 'sw', para: 'g', cor: 'cinza' },
    { de: 'sw', para: 'p', cor: 'cinza' },
    { de: 'sw', para: 'pt', cor: 'verde' },
    { de: 'pt', para: 'r', lados: 'bc', cor: 'verde' },
    { de: 'r', para: 't', lados: 'de', rotulo: '9', cor: 'verde' },
    { pontos: [[1065, 896], [1065, 940], [820, 940], [820, 780], [879, 780]], rotulo: 'nem 9 nem 7: de novo', cor: 'roxo', dy: 34, dx: 40 },
  ],
  notas: [
    { x: 100, y: 690, texto: 'lançamentos 2 e 3: 8 e 5', cor: 'roxo' },
    { x: 100, y: 728, texto: 'lançamento 4: 9, ganhou', cor: 'verde' },
    { x: 100, y: 766, texto: '(um 7 antes do 9 perderia)', cor: 'cinza' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'proc', 'soma = 1º lançamento'],
    ['C', 'dec', 'soma é 7 ou 11?'],
    ['D', 'dec', 'é 2, 3 ou 12? (senão, ponto = soma)'],
    ['E', 'proc', 'soma = novo lançamento'],
    ['F', 'dec', 'soma == ponto?'],
    ['G', 'dec', 'soma == 7?'],
    ['H', 'io', 'Mostrar "Ganhou"'],
    ['I', 'io', 'Mostrar "Perdeu"'],
    ['J', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'H', 'Sim'],
    ['C', 'D', 'Não'],
    ['D', 'I', 'Sim'],
    ['D', 'E', 'Não'],
    ['E', 'F'],
    ['F', 'H', 'Sim'],
    ['F', 'G', 'Não'],
    ['G', 'I', 'Sim'],
    ['G', 'E', 'Não'],
    ['H', 'J'],
    ['I', 'J'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'E', 'F', 'H', 'J'],
}
