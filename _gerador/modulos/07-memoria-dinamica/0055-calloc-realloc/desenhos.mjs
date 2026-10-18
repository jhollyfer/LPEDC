export const ideia = {
  caixas: [
    { id: 'a', forma: 'array', x: 120, y: 40, nome: 'capacidade 2', itens: ['50', '120'], celula: 110, cor: 'azul' },
    { id: 'b', forma: 'array', x: 120, y: 290, nome: 'capacidade 4', itens: ['50', '120', '35', '80'], celula: 110, cor: 'azul', estados: { 2: 'verde', 3: 'verde' } },
    { id: 'c', forma: 'array', x: 120, y: 540, nome: 'capacidade 8', itens: ['50', '120', '35', '80', '15', '?', '?', '?'], celula: 110, cor: 'azul', estados: { 4: 'verde', 5: 'apagado', 6: 'apagado', 7: 'apagado' } },
    { id: 'r1', x: 1080, y: 40, w: 420, cor: 'amarelo', rotulo: '3º Pix: encheu', texto: ['realloc para 4'] },
    { id: 'r2', x: 1080, y: 290, w: 420, cor: 'amarelo', rotulo: '5º Pix: encheu', texto: ['realloc para 8'] },
    { id: 't', forma: 'terminal', x: 1080, y: 577, w: 420, texto: ['5 Pix, total R$ 300'] },
  ],
  setas: [
    { de: 'a', para: 'r1' },
    { pontos: [[1290, 196], [1290, 250], [450, 250], [450, 330]], rotulo: 'copia e continua', dx: 0 },
    { de: 'b', para: 'r2' },
    { pontos: [[1290, 446], [1290, 500], [450, 500], [450, 580]], rotulo: 'copia e continua', dx: 0 },
    { de: 'c', para: 't', lados: 'de' },
  ],
  notas: [
    { x: 740, y: 760, texto: '3 posições livres (lixo)', cor: 'cinza', ancora: 'middle', tam: 22 },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'proc', 'pix = malloc(2 ints)'],
    ['C', 'dec', 'chegou mais um Pix?'],
    ['D', 'dec', 'quantidade == capacidade?'],
    ['E', 'proc', 'maior = realloc(pix, dobro)'],
    ['F', 'proc', 'pix = maior; capacidade *= 2'],
    ['G', 'proc', 'pix[quantidade++] = valor'],
    ['H', 'io', '5 Pix, total R$ 300'],
    ['I', 'proc', 'free(pix)'],
    ['J', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D', 'Sim'],
    ['D', 'E', 'Sim'],
    ['D', 'G', 'Não'],
    ['E', 'F'],
    ['F', 'G'],
    ['G', 'C'],
    ['C', 'H', 'Não'],
    ['H', 'I'],
    ['I', 'J'],
  ],
}
