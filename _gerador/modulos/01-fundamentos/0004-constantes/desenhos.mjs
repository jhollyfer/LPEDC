export const ideia = {
  caixas: [
    {
      id: 'src',
      forma: 'arquivo',
      x: 100,
      y: 20,
      w: 400,
      nome: 'onibus.c',
      texto: ['#define TARIFA 4.90', '2 * TARIFA'],
      cor: 'azul',
    },
    { id: 'pp', x: 610, y: 30, w: 360, cor: 'roxo', rotulo: 'pré-processador', texto: ['troca TARIFA', 'por 4.90'] },
    { id: 'out', forma: 'arquivo', x: 1080, y: 20, w: 380, nome: 'o compilador vê', texto: ['2 * 4.90'], cor: 'verde' },
    {
      id: 'l',
      forma: 'caixinha',
      x: 100,
      y: 380,
      w: 300,
      nome: 'linha',
      valor: '101',
      tipo: 'const int · 4 bytes',
      cadeado: true,
      end: '0x7ffe...04c',
    },
    {
      id: 't',
      forma: 'terminal',
      x: 900,
      y: 380,
      texto: ['Viação Sol', 'Linha 101 "Centro - Bairro"', 'Tarifa: R$ 4.90', 'Ida e volta: R$ 9.80'],
    },
  ],
  setas: [
    { de: 'src', para: 'pp' },
    { de: 'pp', para: 'out' },
    { de: 'out', para: 't', lados: 'bc', rotulo: 'roda' },
    { de: 'l', para: 't', rotulo: 'só leitura' },
  ],
  notas: [{ x: 100, y: 680, texto: 'tem tipo e endereço, mas "linha = 102;" não compila', cor: 'roxo' }],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'proc', 'Trocar TARIFA e EMPRESA pelo texto'],
    ['C', 'io', 'Mostrar a empresa'],
    ['D', 'io', 'Mostrar a linha'],
    ['E', 'io', 'Mostrar tarifa e ida e volta'],
    ['F', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D'],
    ['D', 'E'],
    ['E', 'F'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'F'],
}
