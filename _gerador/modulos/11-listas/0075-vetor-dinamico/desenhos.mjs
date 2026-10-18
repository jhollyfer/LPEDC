export const ideia = {
  caixas: [
    { id: 's', x: 100, y: 330, w: 340, cor: 'roxo', rotulo: 'viagem (struct lista)', texto: ['itens: endereço', 'tam = 5', 'cap = 8'] },
    { id: 'a', forma: 'array', x: 620, y: 40, nome: 'antes: cap 4, cheio', itens: ['12', '35', '8', '50'], estados: { 0: 'apagado', 1: 'apagado', 2: 'apagado', 3: 'apagado' } },
    {
      id: 'b',
      forma: 'array',
      x: 620,
      y: 330,
      nome: 'depois: cap 8',
      itens: ['12', '35', '8', '50', '27', '', '', ''],
      estados: { 4: 'verde', 5: 'apagado', 6: 'apagado', 7: 'apagado' },
    },
  ],
  setas: [
    { de: 'a', para: 'b', rotulo: 'inserir o 27: cheio! realloc dobra e copia', lados: 'bc' , dx: 20 },
    { de: 's', para: 'b', lados: 'de' },
  ],
  notas: [
    { x: 1000, y: 120, texto: 'bloco antigo: devolvido', cor: 'cinza' },
    { x: 1080, y: 560, texto: '3 vagas livres', cor: 'cinza' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'io', 'Recebe o valor 27'],
    ['C', 'dec', 'tam == cap?'],
    ['D', 'proc', 'realloc com cap * 2'],
    ['E', 'dec', 'realloc deu NULL?'],
    ['F', 'io', 'Devolve false'],
    ['G', 'proc', 'itens[tam] = 27; tam++'],
    ['H', 'io', 'Devolve true'],
    ['I', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D', 'Sim'],
    ['C', 'G', 'Não'],
    ['D', 'E'],
    ['E', 'F', 'Sim'],
    ['E', 'G', 'Não'],
    ['G', 'H'],
    ['F', 'I'],
    ['H', 'I'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'G', 'H', 'I'],
}
