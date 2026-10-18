export const ideia = {
  caixas: [
    { id: 't', forma: 'terminal', x: 100, y: 40, w: 270, texto: ['boto', 'Arara', 'CAPIVARA', 'boto', 'Tatu', '...'] },
    { id: 'n', x: 470, y: 60, w: 380, cor: 'roxo', rotulo: 'normalizar', texto: ['"CAPIVARA\\n"', 'vira "capivara"'] },
    { id: 'b', x: 510, y: 330, w: 300, h: 190, forma: 'losango', cor: 'amarelo', texto: ['buscar', 'na matriz'] },
    { id: 'v', forma: 'array', x: 930, y: 60, nome: 'votos', itens: ['arara 2', 'boto 4', 'capivara 2'], celula: 190, indices: false, estados: { 1: 'verde' } },
    { id: 'i', x: 1000, y: 470, w: 390, cor: 'vermelho', rotulo: 'inválidos', texto: ['"tatu": 1'] },
  ],
  setas: [
    { de: 't', para: 'n' },
    { de: 'n', para: 'b' },
    { de: 'b', para: 'v', lados: 'db', cotovelo: true, rotulo: 'pos >= 0: votos[pos]++', cor: 'verde' },
    { de: 'b', para: 'i', lados: 'be', cotovelo: true, rotulo: 'pos = -1', cor: 'vermelho' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'dec', 'fgets leu uma linha?'],
    ['C', 'proc', 'normalizar(linha)'],
    ['D', 'dec', 'buscar achou?'],
    ['E', 'proc', 'votos[pos]++'],
    ['F', 'proc', 'invalidos++'],
    ['X', 'proc', 'próximo voto'],
    ['G', 'io', 'Mostrar barras e o vencedor: boto'],
    ['H', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C', 'Sim'],
    ['C', 'D'],
    ['D', 'E', 'Sim'],
    ['D', 'F', 'Não'],
    ['E', 'X'],
    ['F', 'X'],
    ['X', 'B'],
    ['B', 'G', 'Não'],
    ['G', 'H'],
  ],
}
