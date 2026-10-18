export const ideia = {
  caixas: [
    { id: 'h', forma: 'arquivo', x: 560, y: 20, w: 380, nome: 'conversao.h', texto: ['protótipos', '(o contrato)'], cor: 'azul' },
    { id: 'a', forma: 'arquivo', x: 100, y: 300, w: 340, nome: 'viagem.c', texto: ['main()', 'usa as funções'], cor: 'roxo' },
    { id: 'c', forma: 'arquivo', x: 1060, y: 300, w: 340, nome: 'conversao.c', texto: ['o corpo', 'das funções'], cor: 'roxo' },
    { id: 'ao', x: 100, y: 570, w: 340, cor: 'cinza', rotulo: 'viagem.o', texto: ['buracos: U km_...'] },
    { id: 'co', x: 1060, y: 570, w: 340, cor: 'cinza', rotulo: 'conversao.o', texto: ['T km_para_milhas'] },
    { id: 'l', x: 560, y: 790, w: 380, cor: 'roxo', rotulo: 'ligador', texto: ['tapa os buracos'] },
    { id: 'x', forma: 'terminal', x: 550, y: 1050, w: 400, texto: ['$ ./viagem', '30 °C = 86.0 °F'] },
  ],
  setas: [
    { de: 'h', para: 'a', lados: 'ec', cotovelo: true, rotulo: '#include' },
    { de: 'h', para: 'c', lados: 'dc', cotovelo: true, rotulo: '#include' },
    { de: 'a', para: 'ao', rotulo: 'gcc -c' },
    { de: 'c', para: 'co', rotulo: 'gcc -c' },
    { de: 'ao', para: 'l', lados: 'be', cotovelo: true },
    { de: 'co', para: 'l', lados: 'bd', cotovelo: true },
    { de: 'l', para: 'x', rotulo: 'viagem', cor: 'verde' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início: viagem.c e conversao.c'],
    ['B', 'proc', 'Compila viagem.c (só vê o .h)'],
    ['C', 'proc', 'Compila conversao.c'],
    ['D', 'dec', 'Código sem erro?'],
    ['E', 'proc', 'Liga viagem.o + conversao.o'],
    ['F', 'dec', 'Achou todas as funções?'],
    ['G', 'io', 'Executável viagem'],
    ['H', 'io', 'Mostrar o erro'],
    ['I', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D'],
    ['D', 'E', 'Sim'],
    ['D', 'H', 'Não'],
    ['E', 'F'],
    ['F', 'G', 'Sim'],
    ['F', 'H', 'Não'],
    ['G', 'I'],
    ['H', 'I'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'I'],
}
