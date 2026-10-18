export const ideia = {
  caixas: [
    { id: 'e', x: 100, y: 120, w: 380, cor: 'azul', rotulo: 'entrada (scanf)', texto: ['anterior = 45230', 'atual = 45487', 'moradores = 3'] },
    {
      id: 'p',
      x: 600,
      y: 80,
      w: 480,
      cor: 'roxo',
      rotulo: 'processamento',
      texto: ['consumo = 257 kWh', 'total = 257 * 0.82', '      + 18.50 = 229.24', 'cada = 76.42 (ceil)'],
    },
    {
      id: 't',
      forma: 'terminal',
      x: 600,
      y: 480,
      w: 520,
      texto: ['Consumo:      257 kWh', 'Por dia:     8.57 kWh', 'Total:  R$   229.24', 'Cada:   R$    76.42'],
    },
  ],
  setas: [
    { de: 'e', para: 'p' },
    { de: 'p', para: 't', rotulo: 'saída (printf)' },
  ],
  notas: [
    { x: 1200, y: 140, texto: ['#define TARIFA_KWH', 'int e double', 'scanf com &', '- * / e +=', 'cast (double)', 'ceil do math.h', 'printf com largura'], cor: 'cinza', tam: 24 },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'io', 'Ler leituras e moradores'],
    ['C', 'proc', 'consumo = atual - anterior'],
    ['D', 'proc', 'total = consumo * TARIFA'],
    ['D2', 'proc', 'total += ILUMINACAO'],
    ['E', 'proc', 'cada = ceil(total / moradores * 100) / 100'],
    ['F', 'io', 'Mostrar a conta'],
    ['G', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D'],
    ['D', 'D2'],
    ['D2', 'E'],
    ['E', 'F'],
    ['F', 'G'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'D2', 'E', 'F', 'G'],
}
