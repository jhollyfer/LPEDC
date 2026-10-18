const codigos = (y, lista, cor) =>
  lista.map((t, i) => ({ x: 215 + i * 130, y, texto: t, cor, ancora: 'middle', tam: 24 }))

export const ideia = {
  caixas: [
    { id: 'a', forma: 'array', x: 150, y: 40, nome: 'placa (antes)', itens: ["'b'", "'r'", "'a'", "'2'", "'e'", "'1'", "'9'"], celula: 130, indices: false },
    {
      id: 'b',
      forma: 'array',
      x: 150,
      y: 400,
      nome: 'placa (depois)',
      itens: ["'B'", "'R'", "'A'", "'2'", "'E'", "'1'", "'9'"],
      celula: 130,
      indices: false,
      estados: { 0: 'verde', 1: 'verde', 2: 'verde', 3: 'apagado', 4: 'verde', 5: 'apagado', 6: 'apagado' },
    },
    { id: 't', forma: 'terminal', x: 1150, y: 430, w: 330, texto: ['BRA2E19', 'válida'] },
  ],
  setas: [
    { pontos: [[1080, 240], [1080, 440]], rotulo: 'toupper' },
    { de: 'b', para: 't' },
  ],
  notas: [
    ...codigos(210, ['98', '114', '97', '50', '101', '49', '57'], 'cinza'),
    ...codigos(570, ['66', '82', '65', '50', '69', '49', '57'], 'cinza'),
    { x: 150, y: 300, texto: 'letra: código - 32      dígito: não muda', cor: 'roxo' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'proc', 'i = 0; valida = true'],
    ['C', 'dec', 'i < 7?'],
    ['D', 'proc', 'placa[i] = toupper(placa[i])'],
    ['E', 'dec', 'tipo certo na posição i?'],
    ['F', 'proc', 'valida = false'],
    ['G', 'proc', 'i++'],
    ['H', 'io', 'Mostrar BRA2E19 e "válida"'],
    ['I', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D', 'Sim'],
    ['D', 'E'],
    ['E', 'G', 'Sim'],
    ['E', 'F', 'Não'],
    ['F', 'G'],
    ['G', 'C'],
    ['C', 'H', 'Não'],
    ['H', 'I'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'G', 'C', 'H', 'I'],
}
