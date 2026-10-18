export const ideia = {
  caixas: [
    { id: 'c', forma: 'arquivo', x: 100, y: 20, w: 250, nome: 'ola.c', texto: ['#include', 'main()'], cor: 'azul' },
    { id: 'pp', x: 470, y: 0, w: 380, cor: 'roxo', rotulo: '1. pré-processador', texto: ['cola o stdio.h'] },
    { id: 'cc', x: 470, y: 230, w: 380, cor: 'roxo', rotulo: '2. compilador', texto: ['C vira assembly'] },
    { id: 'as', x: 470, y: 460, w: 380, cor: 'roxo', rotulo: '3. montador', texto: ['assembly vira ola.o'] },
    { id: 'ld', x: 470, y: 690, w: 380, cor: 'roxo', rotulo: '4. ligador', texto: ['junta com o printf'] },
    { id: 'x', forma: 'arquivo', x: 990, y: 690, w: 230, h: 150, nome: 'ola', texto: ['executável'], cor: 'verde' },
    { id: 't', forma: 'terminal', x: 990, y: 420, w: 360, texto: ['$ ./ola', 'Olá, LPEDC!'] },
  ],
  setas: [
    { de: 'c', para: 'pp' },
    { de: 'pp', para: 'cc' },
    { de: 'cc', para: 'as' },
    { de: 'as', para: 'ld' },
    { de: 'ld', para: 'x' },
    { de: 'x', para: 't', rotulo: 'roda' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início: ola.c'],
    ['B', 'proc', 'Pré-processar'],
    ['C', 'dec', 'Achou os #include?'],
    ['D', 'proc', 'Compilar e montar'],
    ['E', 'dec', 'Código sem erro?'],
    ['F', 'proc', 'Ligar com as bibliotecas'],
    ['G', 'dec', 'Achou todas as funções?'],
    ['H', 'io', 'Executável ola'],
    ['I', 'io', 'Mostrar o erro'],
    ['J', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D', 'Sim'],
    ['C', 'I', 'Não'],
    ['D', 'E'],
    ['E', 'F', 'Sim'],
    ['E', 'I', 'Não'],
    ['F', 'G'],
    ['G', 'H', 'Sim'],
    ['G', 'I', 'Não'],
    ['H', 'J'],
    ['I', 'J'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'J'],
}
