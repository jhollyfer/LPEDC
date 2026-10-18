export const ideia = {
  caixas: [
    { id: 'p', x: 100, y: 60, w: 340, cor: 'azul', rotulo: 'pedidos', texto: ['códigos 1, 2, 3', '(o 9 é recusado)'] },
    { id: 'c', forma: 'arquivo', x: 560, y: 40, w: 400, nome: 'cardapio.c', texto: ['1850 + 1200 + 790', '= 3840 centavos'], cor: 'roxo' },
    { id: 't', x: 1080, y: 60, w: 400, cor: 'roxo', rotulo: 'TAXA_SERVICO 10%', texto: ['3840 + 384', '= 4224'] },
    { id: 'pg', x: 1080, y: 360, w: 400, cor: 'azul', rotulo: 'valor pago', texto: ['R$ 50 = 5000'] },
    { id: 'r', x: 560, y: 360, w: 400, cor: 'roxo', rotulo: 'dar_troco(776, ...)', texto: ['recursão: uma nota', 'e resolve o resto'] },
    { id: 's', forma: 'terminal', x: 100, y: 340, w: 340, texto: ['Troco: R$ 7.76', '5.00  2.00', '0.50  0.25', '0.01'] },
  ],
  setas: [
    { de: 'p', para: 'c' },
    { de: 'c', para: 't' },
    { de: 't', para: 'pg' },
    { de: 'pg', para: 'r', rotulo: '776' },
    { de: 'r', para: 's', cor: 'verde' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início: mostra o cardápio'],
    ['B', 'io', 'Ler código'],
    ['C', 'dec', 'Código é 0?'],
    ['D', 'proc', 'total += preço do item'],
    ['E', 'proc', 'conta = total + 10%'],
    ['F', 'io', 'Ler valor pago'],
    ['G', 'dec', 'Pagou o suficiente?'],
    ['H', 'proc', 'dar_troco (recursiva)'],
    ['I', 'io', 'Mostrar quanto falta'],
    ['J', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D', 'Não'],
    ['D', 'B'],
    ['C', 'E', 'Sim'],
    ['E', 'F'],
    ['F', 'G'],
    ['G', 'H', 'Sim'],
    ['G', 'I', 'Não'],
    ['H', 'J'],
    ['I', 'J'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'B', 'C', 'E', 'F', 'G', 'H', 'J'],
}
