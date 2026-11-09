// a conta da Carla, bit a bit: (base[MEMBRO] | extra) & ~bloqueio
const linha = (id, y, nome, itens, extra = {}) => ({
  id,
  forma: 'array',
  x: 420,
  y,
  nome,
  itens,
  celula: 110,
  indices: false,
  ...extra,
})

export const ideia = {
  caixas: [
    linha('b', 60, 'base[MEMBRO]', ['0', '0', '1', '1', '1']),
    linha('x', 230, 'extra', ['0', '0', '0', '0', '0'], { cor: 'cinza' }),
    linha('k', 400, '~bloqueio  (bloqueio = IMPRIMIR)', ['1', '1', '0', '1', '1'], {
      cor: 'roxo',
      estados: { 2: 'vermelho' },
    }),
    linha('r', 600, 'efetivas da Carla', ['0', '0', '0', '1', '1'], {
      estados: { 3: 'verde', 4: 'verde', 2: 'vermelho' },
    }),
    { id: 'op1', x: 120, y: 240, w: 200, h: 110, cor: 'roxo', texto: ['|  junta'] },
    { id: 'op2', x: 120, y: 410, w: 200, h: 110, cor: 'roxo', texto: ['&  apaga'] },
    { id: 'res', x: 1100, y: 640, w: 380, h: 130, cor: 'verde', texto: ['entrar e reunião'] },
  ],
  setas: [{ de: 'r', para: 'res' }],
  notas: [
    { x: 475, y: 40, texto: 'C', cor: 'cinza', ancora: 'middle' },
    { x: 585, y: 40, texto: 'G', cor: 'cinza', ancora: 'middle' },
    { x: 695, y: 40, texto: 'I', cor: 'cinza', ancora: 'middle' },
    { x: 805, y: 40, texto: 'R', cor: 'cinza', ancora: 'middle' },
    { x: 915, y: 40, texto: 'E', cor: 'cinza', ancora: 'middle' },
    { x: 1100, y: 140, texto: ['o papel dá', 'imprimir, reunião, entrar'], cor: 'azul' },
    { x: 1100, y: 470, texto: ['o 0 do ~bloqueio', 'apaga a impressora:', 'o bloqueio vence'], cor: 'vermelho' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'mascara = REUNIAO | IMPRIMIR'],
    ['B', 'proc', 'i = 0'],
    ['C', 'dec', 'i < n?'],
    ['D', 'dec', '(efetivas & mascara) == mascara?'],
    ['E', 'io', 'mostrar nome (Ana, Bruno)'],
    ['F', 'proc', 'i++'],
    ['G', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D', 'Sim'],
    ['D', 'E', 'Sim'],
    ['D', 'F', 'Não'],
    ['E', 'F'],
    ['F', 'C'],
    ['C', 'G', 'Não'],
  ],
}
