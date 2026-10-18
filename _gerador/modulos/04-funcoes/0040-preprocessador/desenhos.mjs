export const ideia = {
  caixas: [
    { id: 'r1', x: 100, y: 60, w: 400, cor: 'azul', rotulo: 'você escreve', texto: ['QUAD_RUIM(lado + 3)'] },
    { id: 'p1', x: 620, y: 60, w: 280, cor: 'roxo', rotulo: 'pré-processa', texto: ['troca x por', 'lado + 3'] },
    { id: 's1', x: 1020, y: 60, w: 460, cor: 'vermelho', rotulo: 'compilador recebe', texto: ['lado + 3 * lado + 3', '2 + 6 + 3 = 11'] },
    { id: 'r2', x: 100, y: 330, w: 400, cor: 'azul', rotulo: 'você escreve', texto: ['QUAD(lado + 3)'] },
    { id: 'p2', x: 620, y: 330, w: 280, cor: 'roxo', rotulo: 'pré-processa', texto: ['troca x por', 'lado + 3'] },
    { id: 's2', x: 1020, y: 330, w: 460, cor: 'verde', rotulo: 'compilador recebe', texto: ['((lado + 3) * (lado + 3))', '5 * 5 = 25'] },
  ],
  setas: [
    { de: 'r1', para: 'p1' },
    { de: 'p1', para: 's1', cor: 'vermelho' },
    { de: 'r2', para: 'p2' },
    { de: 'p2', para: 's2', cor: 'verde' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início: A079.c'],
    ['B', 'proc', 'Pré-processador lê a linha'],
    ['C', 'dec', 'Tem nome de macro?'],
    ['D', 'proc', 'Troca pelo texto, x = lado + 3'],
    ['E', 'proc', 'Compilador calcula a expressão'],
    ['F', 'io', 'Mostrar 11 e 25'],
    ['G', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D', 'Sim'],
    ['C', 'E', 'Não'],
    ['D', 'E'],
    ['E', 'F'],
    ['F', 'G'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'F', 'G'],
}
