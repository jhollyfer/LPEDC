export const ideia = {
  caixas: [
    {
      id: 'txt',
      forma: 'arquivo',
      x: 100,
      y: 90,
      w: 360,
      nome: 'comentários',
      texto: ['O pão de queijo', 'estava quente e o', 'café estava frio.', 'Pão bom, café...'],
    },
    { id: 'tok', x: 100, y: 420, w: 360, h: 190, cor: 'roxo', rotulo: 'palavra a palavra', texto: ['minúsculas', 'contador_soma'] },
    {
      id: 't',
      forma: 'tabela',
      x: 560,
      y: 90,
      w: 120,
      baldes: [[], ['da:1'], ['pão:6'], ['café:3'], ['estava:2', 'queijo:2'], ['tarde:1', 'de:2']],
      estados: { 2: 'verde', 3: 'verde' },
    },
    { id: 'rk', forma: 'terminal', x: 1110, y: 470, w: 330, texto: ['1. pão: 6', '2. o: 4', '3. café: 3'] },
  ],
  setas: [
    { de: 'txt', para: 'tok' },
    { pontos: [[476, 515], [516, 515], [516, 250], [560, 250]], cor: 'roxo' },
    { pontos: [[800, 560], [800, 600], [1094, 600]], rotulo: 'vetor + qsort', cor: 'verde' },
  ],
  notas: [
    { x: 596, y: 66, texto: 'baldes 0 a 5 de 17', cor: 'cinza' },
    { x: 604, y: 520, texto: '... até o balde 16', cor: 'cinza' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'proc', 'próxima palavra, em minúsculas'],
    ['C', 'dec', 'tem palavra?'],
    ['D', 'proc', 'i = hash(palavra) % 17'],
    ['E', 'dec', 'já está no balde i?'],
    ['G', 'proc', 'cria nó com vezes = 0'],
    ['F', 'proc', 'vezes++; total++'],
    ['H', 'proc', 'copia para vetor; qsort'],
    ['I', 'io', 'Mostrar o ranking (pão: 6...)'],
    ['J', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'H', 'Não'],
    ['C', 'D', 'Sim'],
    ['D', 'E'],
    ['E', 'G', 'Não'],
    ['E', 'F', 'Sim'],
    ['G', 'F'],
    ['F', 'B'],
    ['H', 'I'],
    ['I', 'J'],
  ],
}
