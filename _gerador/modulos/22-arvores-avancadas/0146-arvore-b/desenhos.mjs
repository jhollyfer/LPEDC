// Em cima, a inserção do 25: a folha cheia [10 20 30] se divide na descida e o
// 20 sobe. Embaixo, a árvore depois do 85, com o caminho da busca pelo 60.
const no = (id, x, y, chaves, cor = 'azul') => ({
  id, x, y, w: 60 + chaves.length * 60, h: 70, cor, texto: [chaves.join('  ')],
})

export const ideia = {
  caixas: [
    // antes do 25
    no('a0', 240, 220, [40, 70], 'cinza'),
    no('a1', 90, 380, [10, 20, 30], 'vermelho'),
    no('a2', 330, 380, [50, 60], 'cinza'),
    no('a3', 530, 380, [80, 90], 'cinza'),
    // depois do 25
    no('d0', 1010, 220, [20, 40, 70], 'verde'),
    no('d1', 830, 380, [10], 'cinza'),
    no('d2', 970, 380, [25, 30], 'azul'),
    no('d3', 1170, 380, [50, 60], 'cinza'),
    no('d4', 1370, 380, [80, 90], 'cinza'),
    // depois do 85, com a busca pelo 60
    no('f0', 720, 680, [40], 'verde'),
    no('f1', 440, 830, [20], 'cinza'),
    no('f2', 1000, 830, [70], 'verde'),
    no('f3', 270, 980, [10], 'cinza'),
    no('f4', 420, 980, [25, 30], 'cinza'),
    no('f5', 840, 980, [50, 60], 'verde'),
    no('f6', 1060, 980, [80, 85, 90], 'cinza'),
  ],
  setas: [
    { de: 'a0', para: 'a1', lados: 'bc', cor: 'cinza' },
    { de: 'a0', para: 'a2', lados: 'bc', cor: 'cinza' },
    { de: 'a0', para: 'a3', lados: 'bc', cor: 'cinza' },
    { pontos: [[720, 330], [810, 330]], rotulo: 'insere 25', cor: 'roxo' },
    { de: 'd0', para: 'd1', lados: 'bc', cor: 'cinza' },
    { de: 'd0', para: 'd2', lados: 'bc', cor: 'cinza' },
    { de: 'd0', para: 'd3', lados: 'bc', cor: 'cinza' },
    { de: 'd0', para: 'd4', lados: 'bc', cor: 'cinza' },
    { de: 'f0', para: 'f1', lados: 'bc', cor: 'cinza' },
    { de: 'f0', para: 'f2', lados: 'bc', cor: 'verde' },
    { de: 'f1', para: 'f3', lados: 'bc', cor: 'cinza' },
    { de: 'f1', para: 'f4', lados: 'bc', cor: 'cinza' },
    { de: 'f2', para: 'f5', lados: 'bc', cor: 'verde' },
    { de: 'f2', para: 'f6', lados: 'bc', cor: 'cinza' },
  ],
  notas: [
    { x: 100, y: 190, texto: 'INSERE 25: DIVIDE NA DESCIDA', cor: 'cinza' },
    { x: 90, y: 500, texto: ['cheia (3 chaves):', 'divide antes de descer'], cor: 'vermelho', tam: 24 },
    { x: 1290, y: 262, texto: 'o 20 subiu', cor: 'verde', tam: 24 },
    { x: 970, y: 500, texto: ['o 25 entra', 'na metade da direita'], cor: 'azul', tam: 24 },
    { x: 100, y: 650, texto: 'DEPOIS DO 85: BUSCA PELO 60', cor: 'cinza' },
    { x: 1140, y: 720, texto: ['3 nós lidos:', '[40], [70], [50 60]'], cor: 'verde', tam: 24 },
    { x: 270, y: 1110, texto: 'todas as folhas no mesmo nível', cor: 'roxo', tam: 24 },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'insere_nao_cheio(x, chave)'],
    ['B', 'dec', 'x é folha?'],
    ['C', 'proc', 'Abre espaço e põe a chave'],
    ['D', 'proc', 'Acha o filho i da descida'],
    ['E', 'dec', 'filho[i] está cheio?'],
    ['F', 'proc', 'divide(x, i): a do meio sobe'],
    ['G', 'dec', 'chave > x->chave[i]?'],
    ['H', 'proc', 'i++'],
    ['I', 'proc', 'insere_nao_cheio(filho[i], chave)'],
    ['J', 'io', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C', 'Sim'],
    ['B', 'D', 'Não'],
    ['C', 'J'],
    ['D', 'E'],
    ['E', 'F', 'Sim'],
    ['E', 'I', 'Não'],
    ['F', 'G'],
    ['G', 'H', 'Sim'],
    ['G', 'I', 'Não'],
    ['H', 'I'],
    ['I', 'J'],
  ],
  caminho: ['A', 'B', 'D', 'E', 'F', 'G', 'H', 'I', 'J'],
}
