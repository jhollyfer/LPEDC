export const ideia = {
  caixas: [
    { id: 'b2', forma: 'caixinha', x: 110, y: 40, nome: 'celula', valor: '2500', tipo: 'B2 agora', w: 240 },
    { id: 'l', forma: 'lista', x: 620, y: 80, cabeca: 'topo', itens: ['2100', '1800', '1500'], estados: { 0: 'verde' }, rotulos: { 0: 'sai primeiro', 2: 'fundo' } },
    { id: 't', forma: 'terminal', x: 640, y: 310, w: 400, texto: ['Ctrl+Z: B2 = 2100', 'Ctrl+Z: B2 = 1800'] },
  ],
  setas: [
    { de: 'b2', para: 'l', rotulo: 'empilha o antigo' },
    { pontos: [[803, 200], [803, 292]], cor: 'verde', rotulo: 'pop' },
  ],
  notas: [
    { x: 110, y: 330, texto: ['cada nó: um malloc', 'de 16 bytes no heap'], cor: 'cinza' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início: empilha 2100'],
    ['B', 'proc', 'novo = malloc(...)'],
    ['C', 'dec', 'novo == NULL?'],
    ['D', 'io', 'Devolver false'],
    ['E', 'proc', 'novo->valor = 2100'],
    ['F', 'proc', 'novo->prox = topo'],
    ['G', 'proc', 'topo = novo; n++'],
    ['H', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D', 'Sim'],
    ['C', 'E', 'Não'],
    ['E', 'F'],
    ['F', 'G'],
    ['D', 'H'],
    ['G', 'H'],
  ],
  caminho: ['A', 'B', 'C', 'E', 'F', 'G', 'H'],
}
