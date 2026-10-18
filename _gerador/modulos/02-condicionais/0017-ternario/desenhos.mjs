export const ideia = {
  caixas: [
    { id: 'total', forma: 'caixinha', x: 100, y: 300, nome: 'total', valor: 'R$ 150', tipo: 'double' },
    { id: 'p', x: 430, y: 325, w: 320, h: 200, forma: 'losango', cor: 'amarelo', texto: ['total >= 199 ?'] },
    { id: 's', x: 860, y: 170, w: 200, h: 110, cor: 'cinza', texto: ['0.0'] },
    { id: 'n', x: 860, y: 570, w: 200, h: 110, cor: 'verde', texto: ['19.90'] },
    { id: 'f', forma: 'caixinha', x: 1190, y: 330, nome: 'frete', valor: '19.90', tipo: 'recebe o valor', cor: 'verde', w: 260 },
  ],
  setas: [
    { de: 'total', para: 'p' },
    { de: 'p', para: 's', lados: 'ce', cotovelo: true, rotulo: '? (Sim)', cor: 'cinza' },
    { de: 'p', para: 'n', lados: 'be', cotovelo: true, rotulo: ': (Não)', cor: 'verde' },
    { de: 's', para: 'f', lados: 'dc', cotovelo: true, cor: 'cinza' },
    { de: 'n', para: 'f', lados: 'db', cotovelo: true, cor: 'verde' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'io', 'Ler qtd e total (3 e 150)'],
    ['C', 'dec', 'total >= 199?'],
    ['D', 'proc', 'frete = 0.0'],
    ['E', 'proc', 'frete = 19.90'],
    ['F', 'io', 'Mostrar itens, frete e total'],
    ['G', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D', 'Sim'],
    ['C', 'E', 'Não'],
    ['D', 'F'],
    ['E', 'F'],
    ['F', 'G'],
  ],
  caminho: ['A', 'B', 'C', 'E', 'F', 'G'],
}
