export const ideia = {
  caixas: [
    { id: 'in', x: 110, y: 60, w: 420, h: 120, cor: 'azul', rotulo: 'infixa', texto: ['(35 + 25) * 3 / 4'] },
    { id: 'ops', forma: 'pilha', x: 200, y: 340, itens: ['*'], w: 120, topo: false, titulo: 'pilha de operadores' },
    { id: 'f', forma: 'array', x: 720, y: 60, nome: 'fila pós-fixa', itens: ['35', '25', '+', '3', '*', '4', '/'], celula: 96, indices: false, estados: { 2: 'roxo', 4: 'roxo', 6: 'roxo' } },
    { id: 'val', forma: 'pilha', x: 800, y: 340, itens: ['180', '4'], w: 140, topo: false, titulo: 'pilha de valores' },
    { id: 't', forma: 'terminal', x: 1166, y: 330, w: 320, texto: ['Resultado: 45'] },
  ],
  setas: [
    { de: 'in', para: 'f', rotulo: '1. converte' },
    { pontos: [[320, 196], [320, 300]], rotulo: 'operador espera', cor: 'roxo', dx: 100 },
    { pontos: [[870, 210], [870, 300]], rotulo: '2. avalia', cor: 'verde', dx: 70 },
    { pontos: [[990, 400], [1150, 400]], rotulo: '180 / 4', cor: 'verde' },
  ],
  notas: [
    { x: 110, y: 610, texto: 'números vão direto para a fila; a pilha segura os operadores até a hora certa', cor: 'cinza' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'io', 'Ler "(35 + 25) * 3 / 4"'],
    ['C', 'proc', 'Converter: números para a fila, operadores pela pilha'],
    ['D', 'proc', 'Avaliar: tira da fila, calcula na pilha'],
    ['E', 'dec', 'faltou operando ou divisão por zero?'],
    ['F', 'dec', 'sobrou um número só?'],
    ['G', 'io', 'Mostrar "Resultado: 45"'],
    ['H', 'io', 'Mostrar "Expressão inválida"'],
    ['I', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D'],
    ['D', 'E'],
    ['E', 'H', 'Sim'],
    ['E', 'F', 'Não'],
    ['F', 'G', 'Sim'],
    ['F', 'H', 'Não'],
    ['G', 'I'],
    ['H', 'I'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'I'],
}
