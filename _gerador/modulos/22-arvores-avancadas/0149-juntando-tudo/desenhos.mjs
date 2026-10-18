// O caminho de uma palavra pelo corretor: o texto vira palavras, cada palavra
// é procurada na trie e, se não estiver lá, vira 290 candidatos a uma edição de
// distância, que a trie filtra até sobrar "feira".
export const ideia = {
  caixas: [
    { id: 'a', x: 110, y: 200, w: 330, h: 190, cor: 'azul', rotulo: 'texto', texto: ['"...e a fiera', 'tinha bolo..."'] },
    { id: 'b', x: 540, y: 200, w: 300, h: 190, cor: 'roxo', rotulo: 'cor_proxima', texto: ['fiera'] },
    { id: 'p', x: 930, y: 195, w: 300, h: 200, forma: 'losango', cor: 'amarelo', texto: ['está na', 'trie?'] },
    { id: 'ok', x: 1330, y: 230, w: 200, h: 130, cor: 'verde', texto: ['segue'] },
    {
      id: 's',
      x: 830,
      y: 545,
      w: 560,
      h: 250,
      cor: 'roxo',
      rotulo: 'cor_sugere("fiera")',
      texto: ['tirar uma letra: 5', 'trocar vizinhas: 4', 'trocar uma letra: 125', 'pôr uma letra: 156'],
    },
    {
      id: 'f',
      x: 110,
      y: 560,
      w: 470,
      h: 220,
      cor: 'verde',
      rotulo: 'filtra na trie',
      texto: ['290 candidatos', 'só "feira" existe', '(fiera: trocar i e e)'],
    },
  ],
  setas: [
    { de: 'a', para: 'b' },
    { de: 'b', para: 'p' },
    { de: 'p', para: 'ok', rotulo: 'Sim', cor: 'verde' },
    { de: 'p', para: 's', lados: 'bc', rotulo: 'Não', cor: 'vermelho' },
    { de: 's', para: 'f', lados: 'ed', rotulo: 'cor_contem', cor: 'roxo' },
  ],
  notas: [
    { x: 110, y: 850, texto: 'Sugestão: feira', cor: 'verde', tam: 30 },
    { x: 830, y: 845, texto: ['cada candidato custa O(tamanho da palavra)', 'na trie, qualquer que seja o dicionário'], cor: 'cinza', tam: 24 },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início: dicionário na trie'],
    ['B', 'io', 'cor_proxima: próxima palavra'],
    ['C', 'dec', 'Tem palavra?'],
    ['D', 'dec', 'Está no dicionário?'],
    ['E', 'proc', 'cor_sugere: candidatos filtrados na trie'],
    ['F', 'io', 'Mostra as sugestões'],
    ['G', 'io', 'Mostra o total'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D', 'Sim'],
    ['C', 'G', 'Não'],
    ['D', 'B', 'Sim'],
    ['D', 'E', 'Não'],
    ['E', 'F'],
    ['F', 'B'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'F', 'B', 'C', 'G'],
}
