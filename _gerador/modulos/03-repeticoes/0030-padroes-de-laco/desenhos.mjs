// as máximas da semana entram uma a uma; cada padrão é uma caixinha que
// guarda um resumo; o 999 (sentinela) só manda parar
const cx = (id, x, nome, valor, tipo, cor) => ({ id, forma: 'caixinha', x, y: 340, w: 240, nome, valor, tipo, cor })

export const ideia = {
  caixas: [
    { id: 'e', forma: 'array', x: 330, y: 40, celula: 120, itens: [28, 31, 36, 25, 30, 999], estados: { 5: 'vermelho' }, indices: false },
    cx('c', 100, 'dias', '5', 'contador', 'roxo'),
    cx('a', 385, 'soma', '150', 'acumulador', 'roxo'),
    cx('M', 670, 'maior', '36', 'o maior visto', 'verde'),
    cx('m', 955, 'menor', '25', 'o menor visto', 'verde'),
    cx('f', 1240, 'calorao', 'true', 'flag', 'amarelo'),
  ],
  setas: [
    { pontos: [[630, 150], [630, 320]], rotulo: 'cada dia atualiza as caixinhas', cor: 'roxo' },
  ],
  notas: [
    { x: 1070, y: 70, texto: 'sentinela: manda parar,', cor: 'vermelho' },
    { x: 1070, y: 108, texto: 'não entra em conta nenhuma', cor: 'vermelho' },
    { x: 100, y: 640, texto: 'média = soma / dias = 150 / 5 = 30.0', cor: 'verde' },
    { x: 100, y: 678, texto: 'a flag subiu no 36 e não desceu mais', cor: 'cinza' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'io', 'Ler temp'],
    ['C', 'dec', 'temp != 999?'],
    ['D', 'proc', 'dias++; soma += temp'],
    ['E', 'proc', 'atualiza maior, menor e a flag'],
    ['F', 'io', 'Ler a próxima temp'],
    ['G', 'io', 'Mostrar dias, média, maior, menor'],
    ['H', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D', 'Sim'],
    ['D', 'E'],
    ['E', 'F'],
    ['F', 'C'],
    ['C', 'G', 'Não'],
    ['G', 'H'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'F', 'C', 'G', 'H'],
}
