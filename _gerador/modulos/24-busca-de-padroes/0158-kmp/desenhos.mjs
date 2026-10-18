// a senha 12123 e a tabela pi; as teclas 1212123 e o "escorregão" do padrão
// depois da falha na 5ª tecla: o 12 do fim continua casado
const W = 90
const XT = 420 // onde começa o texto
const cx = (i) => XT + i * W + W / 2

export const ideia = {
  caixas: [
    { id: 'p', forma: 'array', x: 110, y: 30, nome: 'padrão', celula: W, itens: ['1', '2', '1', '2', '3'], cor: 'roxo' },
    {
      id: 'pi',
      forma: 'array',
      x: 110,
      y: 250,
      nome: 'pi',
      celula: W,
      itens: ['0', '0', '1', '2', '0'],
      estados: { 3: 'amarelo' },
    },
    {
      id: 'b',
      x: 720,
      y: 240,
      w: 760,
      h: 220,
      cor: 'amarelo',
      rotulo: 'borda de 1212',
      texto: ['o prefixo 12 também é o fim', 'pi[3] = 2: se falhar depois de 1212,', 'as 2 últimas letras ainda servem'],
    },
    {
      id: 't1',
      forma: 'array',
      x: XT,
      y: 560,
      celula: W,
      itens: ['1', '2', '1', '2', '1', '2', '3'],
      estados: { 0: 'verde', 1: 'verde', 2: 'verde', 3: 'verde', 4: 'vermelho', 5: 'apagado', 6: 'apagado' },
    },
    {
      id: 'q1',
      forma: 'array',
      x: XT,
      y: 690,
      celula: W,
      indices: false,
      itens: ['1', '2', '1', '2', '3'],
      cor: 'roxo',
    },
    {
      id: 't2',
      forma: 'array',
      x: XT,
      y: 880,
      celula: W,
      itens: ['1', '2', '1', '2', '1', '2', '3'],
      estados: { 0: 'apagado', 1: 'apagado', 2: 'verde', 3: 'verde', 4: 'verde', 5: 'verde', 6: 'verde' },
    },
    {
      id: 'q2',
      forma: 'array',
      x: XT + 2 * W,
      y: 1010,
      celula: W,
      indices: false,
      itens: ['1', '2', '1', '2', '3'],
      cor: 'roxo',
    },
  ],
  setas: [
    { de: 'pi', para: 'b', cor: 'amarelo' },
    { pontos: [[cx(4), 800], [cx(4), 870]], rotulo: 'k = pi[3] = 2', cor: 'amarelo', dx: 20 },
  ],
  notas: [
    { x: 110, y: 610, texto: 'teclas', cor: 'azul' },
    { x: 110, y: 738, texto: 'senha', cor: 'roxo' },
    { x: cx(4), y: 544, texto: "'1' ≠ '3' com k = 4", cor: 'vermelho', ancora: 'middle' },
    { x: 110, y: 930, texto: 'teclas', cor: 'azul' },
    { x: 110, y: 1058, texto: 'senha', cor: 'roxo' },
    { x: cx(6) + 60, y: 960, texto: 'k = 5: achou na posição 2', cor: 'verde' },
    { x: 110, y: 1160, texto: 'o índice das teclas nunca volta: a 5ª tecla é comparada de novo, mas com padrao[2]', cor: 'cinza' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início: k = 0, i = 0'],
    ['B', 'dec', 'i < n?'],
    ['C', 'dec', 'k > 0 e texto[i] != padrao[k]?'],
    ['D', 'proc', 'k = pi[k - 1]'],
    ['E', 'dec', 'texto[i] == padrao[k]?'],
    ['F', 'proc', 'k++'],
    ['G', 'dec', 'k == m?'],
    ['H', 'io', 'Mostrar i - m + 1 (2); k = pi[m-1]'],
    ['I', 'proc', 'i++'],
    ['J', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C', 'Sim'],
    ['C', 'D', 'Sim'],
    ['D', 'C'],
    ['C', 'E', 'Não'],
    ['E', 'F', 'Sim'],
    ['E', 'G', 'Não'],
    ['F', 'G'],
    ['G', 'H', 'Sim'],
    ['G', 'I', 'Não'],
    ['H', 'I'],
    ['I', 'B'],
    ['B', 'J', 'Não'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'C', 'E', 'F', 'G', 'H', 'I', 'B', 'J'],
}
