// conferir (rápido) x achar (2^n): o palpite passa pelo verificador e cai
// na cláusula 5; a força bruta testa as máscaras 0, 1, 2... e acha a 10
export const ideia = {
  caixas: [
    {
      id: 'cert',
      x: 110,
      y: 120,
      w: 360,
      h: 230,
      cor: 'azul',
      rotulo: 'certificado (palpite)',
      texto: ['Ana = sim', 'Beto = não', 'Caio = não', 'Davi = sim'],
    },
    {
      id: 'ver',
      x: 560,
      y: 120,
      w: 400,
      h: 230,
      cor: 'roxo',
      rotulo: 'verificador',
      texto: ['olha cada literal', 'uma vez só:', 'O(tamanho da fórmula)'],
    },
    {
      id: 'res',
      x: 1050,
      y: 120,
      w: 450,
      h: 230,
      cor: 'vermelho',
      rotulo: 'resposta',
      texto: ['cláusula 5', '(não Davi ou não Ana', 'ou Caio) é falsa'],
    },
    {
      id: 'forca',
      forma: 'array',
      x: 110,
      y: 520,
      celula: 86,
      nome: 'força bruta: máscara (bit 0 = Ana ... bit 3 = Davi)',
      itens: ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '10', '11', '12', '13', '14', '15'],
      indices: false,
      estados: { 0: 'vermelho', 1: 'vermelho', 2: 'vermelho', 3: 'vermelho', 4: 'vermelho', 5: 'vermelho', 6: 'vermelho', 7: 'vermelho', 8: 'vermelho', 9: 'vermelho', 10: 'verde', 11: 'apagado', 12: 'apagado', 13: 'apagado', 14: 'apagado', 15: 'apagado' },
    },
  ],
  setas: [
    { de: 'cert', para: 'ver' },
    { de: 'ver', para: 'res' },
  ],
  notas: [
    { x: 110, y: 720, texto: 'máscara 10 = 1010 em binário: Ana não, Beto sim, Caio não, Davi sim (11ª tentativa)', cor: 'verde', tam: 24 },
    { x: 110, y: 770, texto: 'com n variáveis são 2^n máscaras: cada variável a mais dobra o trabalho', cor: 'roxo', tam: 24 },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'satisfaz(vai)'],
    ['B', 'dec', 'Próxima cláusula?'],
    ['C', 'dec', 'Algum literal verdadeiro?'],
    ['D', 'inicio', 'Devolve false'],
    ['E', 'inicio', 'Devolve true'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C', 'Sim'],
    ['C', 'B', 'Sim'],
    ['C', 'D', 'Não'],
    ['B', 'E', 'Não'],
  ],
  caminho: ['A', 'B', 'C', 'B', 'C', 'D'],
}
