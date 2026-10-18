export const ideia = {
  caixas: [
    { id: 'velho', x: 110, y: 90, w: 150, h: 96, cor: 'cinza', texto: ['501'] },
    { id: 'l', forma: 'lista', x: 380, y: 100, cabeca: 'início', itens: ['502', '503', '504'], estados: { 0: 'verde', 2: 'roxo' } },
    { id: 't', forma: 'terminal', x: 110, y: 320, w: 470, texto: ['Preparando: 501', 'Próximo: 502 (3 esperando)'] },
  ],
  setas: [
    { pontos: [[1056, 50], [1056, 112]], cor: 'roxo' },
    { pontos: [[185, 202], [185, 300]], rotulo: 'free', cor: 'cinza', dx: 40 },
  ],
  notas: [
    { x: 1076, y: 70, texto: 'fim: entra aqui', cor: 'roxo' },
    { x: 185, y: 60, texto: 'saiu', cor: 'cinza', ancora: 'middle' },
    { x: 700, y: 330, texto: ['retirar: inicio = inicio->prox', 'inserir: fim->prox = novo; fim = novo'], cor: 'roxo' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início: insere 504'],
    ['B', 'proc', 'novo = malloc(...)'],
    ['C', 'dec', 'novo == NULL?'],
    ['D', 'io', 'Devolver false'],
    ['E', 'proc', 'novo->valor = 504; novo->prox = NULL'],
    ['F', 'dec', 'fila vazia (fim == NULL)?'],
    ['G', 'proc', 'inicio = novo'],
    ['H', 'proc', 'fim->prox = novo'],
    ['I', 'proc', 'fim = novo; n++'],
    ['J', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D', 'Sim'],
    ['C', 'E', 'Não'],
    ['E', 'F'],
    ['F', 'G', 'Sim'],
    ['F', 'H', 'Não'],
    ['G', 'I'],
    ['H', 'I'],
    ['D', 'J'],
    ['I', 'J'],
  ],
  caminho: ['A', 'B', 'C', 'E', 'F', 'H', 'I', 'J'],
}
