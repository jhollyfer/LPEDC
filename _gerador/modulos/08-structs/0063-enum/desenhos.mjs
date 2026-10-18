const etapa = (i, nome, cor = 'roxo') => ({
  id: 'e' + i,
  x: 100 + i * 370,
  y: 260,
  w: 290,
  h: 150,
  cor,
  texto: [nome, `= ${i}`],
})

export const ideia = {
  caixas: [
    { id: 's', forma: 'caixinha', x: 100, y: 0, nome: 's', valor: 'RECEBIDO', tipo: 'Status (um int)', w: 290, cor: 'azul' },
    etapa(0, 'RECEBIDO'),
    etapa(1, 'PREPARANDO'),
    etapa(2, 'A_CAMINHO'),
    etapa(3, 'ENTREGUE', 'verde'),
    { id: 'pergunta', x: 840, y: 20, w: 660, h: 130, cor: 'amarelo', texto: ['s != ENTREGUE? continua o laço'] },
  ],
  setas: [
    { de: 's', para: 'e0', rotulo: 'começa' },
    { de: 'e0', para: 'e1', rotulo: 's++' },
    { de: 'e1', para: 'e2', rotulo: 's++' },
    { de: 'e2', para: 'e3', rotulo: 's++' },
  ],
  notas: [{ x: 800, y: 480, texto: 'no código, nomes; na memória, os inteiros 0, 1, 2 e 3', cor: 'cinza', ancora: 'middle' }],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'proc', 's = RECEBIDO'],
    ['C', 'dec', 's != ENTREGUE?'],
    ['D', 'io', 'Mostrar [s] e nome_status(s)'],
    ['E', 'proc', 's++'],
    ['F', 'io', 'Pedido entregue. Bom apetite!'],
    ['G', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D', 'Sim'],
    ['D', 'E'],
    ['E', 'C'],
    ['C', 'F', 'Não'],
    ['F', 'G'],
  ],
}
