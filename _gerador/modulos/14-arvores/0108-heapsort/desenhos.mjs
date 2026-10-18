// um passo da fase 2: o máximo (91) troca com o último e vai para a parte
// ordenada (verde); o 66 desce no heap, que agora tem 6 elementos
export const ideia = {
  caixas: [
    { id: 'a', forma: 'array', x: 100, y: 110, celula: 90, itens: [91, 52, 73, 40, 18, 25, 66], estados: { 0: 'roxo', 6: 'amarelo' } },
    { id: 'b', forma: 'array', x: 100, y: 360, celula: 90, itens: [66, 52, 73, 40, 18, 25, 91], estados: { 0: 'amarelo', 6: 'verde' } },
    { id: 'c', forma: 'array', x: 100, y: 610, celula: 90, itens: [73, 52, 66, 40, 18, 25, 91], estados: { 0: 'roxo', 2: 'amarelo', 6: 'verde' } },
    {
      id: 't',
      forma: 'arvore',
      x: 1010,
      y: 400,
      dx: 80,
      dy: 130,
      raiz: { v: 73, e: { v: 52, e: { v: 40 }, d: { v: 18 } }, d: { v: 66, e: { v: 25 } } },
      estados: { 73: 'roxo', 66: 'amarelo' },
      marcadas: [[73, 66]],
    },
  ],
  setas: [
    { de: 'a', para: 'b', rotulo: '1. troca v[0] com v[6]' },
    { de: 'b', para: 'c', rotulo: '2. o 66 desce pelo maior filho' },
    { pontos: [[760, 655], [990, 560]], cor: 'cinza' },
  ],
  notas: [
    { x: 100, y: 90, texto: 'heap pronto: o máximo está na raiz', cor: 'roxo' },
    { x: 625, y: 350, texto: 'ordenado', cor: 'verde', ancora: 'middle' },
    { x: 1010, y: 370, texto: 'o heap agora: v[0..5]', cor: 'cinza' },
    { x: 100, y: 790, texto: 'repete com o heap de 6, de 5, ... até sobrar 1', cor: 'cinza' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'heapsort(v, n)'],
    ['B', 'proc', 'Fase 1: desce cada pai, de n/2 - 1 até 0'],
    ['C', 'proc', 'fim = n - 1'],
    ['D', 'dec', 'fim > 0?'],
    ['E', 'proc', 'Troca v[0] com v[fim]'],
    ['F', 'proc', 'Desce v[0] no heap v[0..fim-1]; fim--'],
    ['G', 'io', 'Vetor em ordem crescente'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D'],
    ['D', 'E', 'Sim'],
    ['E', 'F'],
    ['F', 'D'],
    ['D', 'G', 'Não'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'F', 'D', 'G'],
}
