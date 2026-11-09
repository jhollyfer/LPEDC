// Os três casos do conserto com os pacotes do exemplo. Vermelho = nó
// vermelho; cinza = nó preto (a sentinela nil não aparece). Azul: o z.
const comum = { forma: 'arvore', dx: 70, dy: 110, raio: 32 }
const nota = (x, y, texto, cor = 'roxo') => ({ x, y, texto, cor, tam: 24 })
const seta = (x1, x2, y) => ({ pontos: [[x1, y], [x2, y]], cor: 'roxo' })

export const ideia = {
  caixas: [
    // caso 1: insere 20
    { ...comum, id: 'a1', x: 110, y: 140, raiz: { v: 50, e: { v: 30, e: { v: 20 } }, d: { v: 70 } }, estados: { 50: 'cinza', 30: 'vermelho', 70: 'vermelho', 20: 'azul' } },
    { ...comum, id: 'a2', x: 480, y: 140, raiz: { v: 50, e: { v: 30, e: { v: 20 } }, d: { v: 70 } }, estados: { 50: 'cinza', 30: 'cinza', 70: 'cinza', 20: 'vermelho' } },
    // casos 2 e 3: insere 25 (só a subárvore do 30)
    { ...comum, id: 'b1', x: 110, y: 640, raiz: { v: 30, e: { v: 20, d: { v: 25 } } }, estados: { 30: 'cinza', 20: 'vermelho', 25: 'azul' } },
    { ...comum, id: 'b2', x: 480, y: 640, raiz: { v: 30, e: { v: 25, e: { v: 20 } } }, estados: { 30: 'cinza', 25: 'vermelho', 20: 'azul' } },
    { ...comum, id: 'b3', x: 860, y: 640, raiz: { v: 25, e: { v: 20 }, d: { v: 30 } }, estados: { 25: 'cinza', 20: 'vermelho', 30: 'vermelho' } },
    // a árvore no fim
    {
      ...comum,
      id: 'f',
      x: 950,
      y: 140,
      dx: 64,
      raiz: { v: 50, e: { v: 25, e: { v: 20 }, d: { v: 40, e: { v: 30 }, d: { v: 45 } } }, d: { v: 70 } },
      estados: { 50: 'cinza', 25: 'vermelho', 20: 'cinza', 40: 'cinza', 30: 'vermelho', 45: 'vermelho', 70: 'cinza' },
    },
  ],
  setas: [seta(370, 460, 230), seta(320, 460, 730), seta(690, 840, 730)],
  notas: [
    { x: 100, y: 110, texto: 'CASO 1 (INSERE 20): TIO VERMELHO', cor: 'cinza' },
    nota(110, 470, ['pai 30 e tio 70 vermelhos'], 'vermelho'),
    nota(480, 470, ['recolore e sobe: z = 50 (raiz),', 'que volta a ser preta'], 'roxo'),
    { x: 940, y: 110, texto: 'NO FIM (DEPOIS DO 45)', cor: 'cinza' },
    nota(1180, 590, ['altura 3, altura negra 2'], 'verde'),
    { x: 100, y: 600, texto: 'CASOS 2 E 3 (INSERE 25): TIO PRETO (A NIL)', cor: 'cinza' },
    nota(110, 950, ['caso 2: triângulo', 'gira à esquerda no 20'], 'roxo'),
    nota(480, 950, ['caso 3: linha', '25 preto, 30 vermelho,', 'gira à direita no 30'], 'roxo'),
    nota(860, 950, ['pai de z preto: fim'], 'verde'),
    nota(1200, 760, ['vermelho: nó vermelho', 'cinza: nó preto', 'azul: o z da vez'], 'cinza'),
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'conserta(z = 25)'],
    ['B', 'dec', 'pai de z vermelho?'],
    ['C', 'dec', 'tio vermelho?'],
    ['D', 'proc', 'caso 1: recolore, z = avô'],
    ['E', 'dec', 'z em triângulo?'],
    ['F', 'proc', 'caso 2: z = pai; gira no z'],
    ['G', 'proc', 'caso 3: recolore e gira no avô'],
    ['H', 'proc', 'raiz preta'],
    ['I', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C', 'Sim'],
    ['B', 'H', 'Não'],
    ['C', 'D', 'Sim'],
    ['C', 'E', 'Não'],
    ['D', 'B'],
    ['E', 'F', 'Sim'],
    ['E', 'G', 'Não'],
    ['F', 'G'],
    ['G', 'B'],
    ['H', 'I'],
  ],
  caminho: ['A', 'B', 'C', 'E', 'F', 'G', 'B', 'H', 'I'],
}
