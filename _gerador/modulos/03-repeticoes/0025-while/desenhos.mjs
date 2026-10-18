// o cofrinho: o saldo entra na pergunta; enquanto a resposta é Sim, deposita
// e volta para perguntar de novo; no Não, sai com a resposta
export const ideia = {
  caixas: [
    { id: 's', forma: 'caixinha', x: 110, y: 20, nome: 'saldo', valor: 'R$ 0', tipo: 'começa vazio', w: 250 },
    { id: 'p', x: 520, y: 230, w: 340, h: 200, forma: 'losango', cor: 'amarelo', texto: ['saldo < 1000 ?'] },
    { id: 'd', x: 520, y: 530, w: 340, cor: 'roxo', rotulo: 'deposita', texto: ['saldo += 150', 'meses++'] },
    { id: 't', forma: 'terminal', x: 990, y: 250, w: 400, texto: ['Meta batida', 'em 7 meses'] },
  ],
  setas: [
    { pontos: [[376, 144], [690, 144], [690, 214]] },
    { de: 'p', para: 'd', lados: 'bc', rotulo: 'Sim', cor: 'verde' },
    { pontos: [[504, 625], [420, 625], [420, 330], [504, 330]], rotulo: 'volta', cor: 'roxo', dx: -96 },
    { de: 'p', para: 't', lados: 'de', rotulo: 'Não', cor: 'vermelho' },
  ],
  notas: [
    { x: 520, y: 770, texto: 'saldo: 150, 300, 450, 600, 750, 900, 1050', cor: 'verde' },
    { x: 520, y: 808, texto: '7 voltas com Sim, a 8ª pergunta dá Não', cor: 'cinza' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'proc', 'saldo = 0; meses = 0'],
    ['C', 'dec', 'saldo < 1000?'],
    ['D', 'proc', 'saldo += 150; meses++'],
    ['E', 'io', 'Mostrar mês e saldo'],
    ['F', 'io', 'Mostrar "Meta batida em 7 meses"'],
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
  caminho: ['A', 'B', 'C', 'D', 'E', 'C', 'F', 'G'],
}
