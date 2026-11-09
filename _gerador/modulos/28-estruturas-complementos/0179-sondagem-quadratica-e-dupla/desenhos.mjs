// As três tabelas (m = 13) depois dos cartões 18, 31, 44, 20 e 57. Amarelo:
// posições ocupadas que a busca do 57 olha; verde: onde ele está.
const t = (id, x, baldes, estados) => ({ id, forma: 'tabela', x, y: 210, w: 130, baldes, estados })
const v = (pares) => Array.from({ length: 13 }, (_, i) => pares[i] ?? '')

export const ideia = {
  caixas: [
    t('lin', 110, v({ 5: '18', 6: '31', 7: '44', 8: '20', 9: '57' }), { 5: 'amarelo', 6: 'amarelo', 7: 'amarelo', 8: 'amarelo', 9: 'verde' }),
    t('qua', 610, v({ 1: '57', 5: '18', 6: '31', 7: '20', 9: '44' }), { 5: 'amarelo', 6: 'amarelo', 9: 'amarelo', 1: 'verde' }),
    t('dup', 1110, v({ 0: '31', 1: '44', 2: '57', 5: '18', 7: '20' }), { 5: 'amarelo', 2: 'verde' }),
  ],
  setas: [],
  notas: [
    { x: 110, y: 186, texto: 'LINEAR: h + i', cor: 'cinza' },
    { x: 610, y: 186, texto: 'QUADRÁTICA: h + i²', cor: 'cinza' },
    { x: 1110, y: 186, texto: 'DUPLA: h1 + i · h2', cor: 'cinza' },
    { x: 110, y: 1100, texto: 'o 57 olha 5, 6, 7, 8, 9', cor: 'roxo', tam: 22 },
    { x: 610, y: 1100, texto: 'o 57 olha 5, 6, 9, 1', cor: 'roxo', tam: 22 },
    { x: 1110, y: 1100, texto: 'o 57 olha 5, 2 (passo 10)', cor: 'roxo', tam: 22 },
    { x: 300, y: 620, texto: ['bloco 5..9:', 'o 20 (h = 7)', 'caiu no bloco', 'e o aumentou', '(agrupamento', 'primário)'], cor: 'vermelho', tam: 22 },
    { x: 800, y: 620, texto: ['31, 44 e 57', 'começam no 5', 'e seguem a', 'mesma trilha', '(agrupamento', 'secundário)'], cor: 'vermelho', tam: 22 },
    { x: 1300, y: 620, texto: ['cada cartão', 'anda com um', 'passo próprio:', '8, 9 e 10'], cor: 'verde', tam: 22 },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'io', 'Ler cartão (57)'],
    ['C', 'proc', 'h1 = 57 % 13 (5); h2 = 1 + 57 % 12 (10); i = 0'],
    ['D', 'proc', 'j = (h1 + i · h2) % 13'],
    ['E', 'dec', 'posição j livre ou lápide?'],
    ['F', 'proc', 'i = i + 1'],
    ['G', 'proc', 'guarda o 57 em j (2)'],
    ['H', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D'],
    ['D', 'E'],
    ['E', 'G', 'Sim'],
    ['E', 'F', 'Não'],
    ['F', 'D'],
    ['G', 'H'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'F', 'D', 'E', 'G', 'H'],
}
