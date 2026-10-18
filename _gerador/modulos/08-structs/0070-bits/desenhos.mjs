export const ideia = {
  caixas: [
    { id: 'p', forma: 'array', x: 420, y: 60, nome: 'perm = 6 (rw-)', itens: ['1', '1', '0'], celula: 120, indices: false },
    { id: 'm', forma: 'array', x: 420, y: 260, nome: 'máscara EXECUTAR = 1', itens: ['0', '0', '1'], celula: 120, indices: false, cor: 'roxo', estados: { 2: 'roxo' } },
    { id: 'r', forma: 'array', x: 420, y: 500, nome: 'perm | EXECUTAR', itens: ['1', '1', '1'], celula: 120, indices: false, estados: { 0: 'verde', 1: 'verde', 2: 'verde' } },
    { id: 'res', x: 1000, y: 520, w: 420, h: 130, cor: 'verde', texto: ['perm = 7 (rwx)'] },
    { id: 'op', x: 100, y: 330, w: 220, h: 110, cor: 'roxo', texto: ['OU ( | )'] },
  ],
  setas: [{ de: 'r', para: 'res' }],
  notas: [
    { x: 480, y: 40, texto: 'r', cor: 'cinza', ancora: 'middle' },
    { x: 600, y: 40, texto: 'w', cor: 'cinza', ancora: 'middle' },
    { x: 720, y: 40, texto: 'x', cor: 'cinza', ancora: 'middle' },
    { x: 1000, y: 150, texto: ['cada casa: 1 se alguma', 'das duas de cima tem 1'], cor: 'roxo' },
    { x: 1000, y: 330, texto: ['os bits r e w', 'continuam como estavam'], cor: 'cinza' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'proc', 'perm = LER | ESCREVER (110)'],
    ['C', 'proc', 'perm |= EXECUTAR (111)'],
    ['D', 'proc', 'perm &= ~ESCREVER (101)'],
    ['E', 'dec', 'perm & ESCREVER?'],
    ['F', 'io', 'pode escrever'],
    ['G', 'io', 'não pode escrever'],
    ['H', 'proc', 'perm ^= EXECUTAR (100)'],
    ['I', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D'],
    ['D', 'E'],
    ['E', 'F', 'Sim'],
    ['E', 'G', 'Não'],
    ['F', 'H'],
    ['G', 'H'],
    ['H', 'I'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'G', 'H', 'I'],
}
