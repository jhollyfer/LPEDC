// as duas rotas da farmácia no mapa de quarteirões: exata (28) e a da
// árvore mínima (36)
const pts = [
  ['Fm', 0, 0],
  ['An', 1, 3],
  ['Br', 4, 4],
  ['Cl', 6, 3],
  ['Dê', 7, 0],
  ['Ed', 5, 1],
  ['Fá', 2, 6],
  ['Gi', 3, 1],
]
const ESC = 82
const vertices = pts.map(([n, x, y]) => [n, x * ESC, (6 - y) * ESC])
const ciclo = (ordem) => ordem.map((v, i) => [v, ordem[(i + 1) % ordem.length]])
const exata = ciclo(['Fm', 'Gi', 'Ed', 'Dê', 'Cl', 'Br', 'Fá', 'An'])
const aprox = ciclo(['Fm', 'An', 'Br', 'Cl', 'Ed', 'Dê', 'Gi', 'Fá'])

export const ideia = {
  caixas: [
    { id: 'e', forma: 'grafo', x: 160, y: 200, raio: 34, vertices, arestas: exata, marcadas: exata, estados: { Fm: 'roxo' } },
    { id: 'a', forma: 'grafo', x: 900, y: 200, raio: 34, vertices, arestas: aprox, estados: { Fm: 'roxo' } },
  ],
  notas: [
    { x: 120, y: 800, texto: 'exato (Held-Karp): 28 quarteirões', cor: 'verde' },
    { x: 860, y: 800, texto: 'aproximado (árvore): 36 quarteirões', cor: 'vermelho' },
    { x: 860, y: 840, texto: '(a volta Fá -> Fm passa por cima de An)', cor: 'cinza', tam: 22 },
    { x: 120, y: 870, texto: 'Fm = farmácia; An, Br, Cl, Dê, Ed, Fá, Gi = clientes', cor: 'cinza', tam: 24 },
    { x: 120, y: 915, texto: '1351 passos contra 64: o exato paga caro pela certeza', cor: 'roxo', tam: 24 },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'io', 'Endereços do dia'],
    ['C', 'proc', 'Monta as distâncias'],
    ['D', 'dec', 'Até 20 pontos?'],
    ['E', 'proc', 'Held-Karp: rota exata'],
    ['F', 'proc', 'Árvore mínima + pré-ordem'],
    ['G', 'proc', 'Melhora com 2-opt'],
    ['H', 'io', 'Rota e custo'],
    ['I', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D'],
    ['D', 'E', 'Sim'],
    ['D', 'F', 'Não'],
    ['F', 'G'],
    ['E', 'H'],
    ['G', 'H'],
    ['H', 'I'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'H', 'I'],
}
