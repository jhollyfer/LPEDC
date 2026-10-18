const nomes = ['Dona Cida', 'Seu Jorge', 'Bia', 'Tonho', 'Rosa']
const X = 140
const CEL = 230

export const ideia = {
  caixas: [
    ...nomes.map((n, i) => ({ id: `s${i}`, x: X + i * CEL + 10, y: 20, w: CEL - 20, h: 90, cor: 'verde', texto: [n] })),
    { id: 'n', forma: 'array', x: X, y: 200, itens: ['●', '●', '●', '●', '●'], celula: CEL, cor: 'roxo' },
    { id: 'c', forma: 'array', x: X, y: 420, itens: ['1720', '0', '2000', '315', '560'], celula: CEL, cor: 'azul', estados: { 1: 'verde' } },
  ],
  setas: nomes.map((_, i) => ({ de: `n:${i}`, para: `s${i}`, lados: 'cb' })),
  notas: [
    { x: X + 5 * CEL + 30, y: 240, texto: 'nomes (char **)', cor: 'roxo', tam: 24 },
    { x: X + 5 * CEL + 30, y: 285, texto: ['+ 3 livres', '(capacidade 8)'], cor: 'cinza', tam: 24 },
    { x: X + 5 * CEL + 30, y: 480, texto: 'centavos (int *)', cor: 'azul', tam: 24 },
    { x: X + 5 * CEL + 30, y: 525, texto: ['+ 3 livres'], cor: 'cinza', tam: 24 },
    { x: X + CEL * 1.5, y: 610, texto: 'Seu Jorge pagou: zerou', cor: 'verde', ancora: 'middle', tam: 24 },
    { x: X + 5 * CEL + 30, y: 70, texto: ['um bloco', 'por nome'], cor: 'verde', tam: 24 },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início: caderno com 2 linhas'],
    ['B', 'dec', 'tem anotação?'],
    ['C', 'dec', 'cliente já existe?'],
    ['D', 'proc', 'soma na conta dele'],
    ['F', 'proc', 'se o caderno encheu: crescer'],
    ['G', 'proc', 'duplicar o nome e criar a linha'],
    ['H', 'io', 'Mostrar contas: total R$ 45.95'],
    ['I', 'proc', 'liberar: cada nome, depois os vetores'],
    ['J', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C', 'Sim'],
    ['C', 'D', 'Sim'],
    ['C', 'F', 'Não'],
    ['F', 'G'],
    ['D', 'B'],
    ['G', 'B'],
    ['B', 'H', 'Não'],
    ['H', 'I'],
    ['I', 'J'],
  ],
}
