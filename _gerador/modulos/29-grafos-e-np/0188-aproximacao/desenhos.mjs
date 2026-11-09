// as viagens do barco (10 t cada): first fit na ordem de chegada (6 viagens)
// e first fit decrescente (5 viagens, igual ao limite inferior)
const ff = [['4', '4', '2'], ['6'], ['9'], ['6'], ['7'], ['7']]
const ffd = [['9'], ['7', '2'], ['7'], ['6', '4'], ['6', '4']]
const soma = (v) => v.reduce((t, x) => t + Number(x), 0)
const viagens = (lista, y, cor, pref) =>
  lista.map((v, i) => ({
    id: `${pref}${i}`,
    x: 110 + i * 228,
    y,
    w: 200,
    h: 230,
    cor,
    rotulo: `viagem ${i + 1}`,
    texto: [v.join(' + '), `= ${soma(v)} t`],
  }))

export const ideia = {
  caixas: [
    { id: 'chega', x: 110, y: 60, w: 1380, h: 110, cor: 'azul', texto: ['chegam ao porto: 4, 4, 6, 9, 2, 6, 7, 7 (total 45 t; barco leva 10 t)'] },
    ...viagens(ff, 290, 'amarelo', 'a'),
    ...viagens(ffd, 650, 'verde', 'b'),
  ],
  notas: [
    { x: 110, y: 260, texto: 'first fit, na ordem de chegada: 6 viagens', cor: 'vermelho' },
    { x: 110, y: 620, texto: 'first fit decrescente (9, 7, 7, 6, 6, 4, 4, 2): 5 viagens', cor: 'verde' },
    { x: 1270, y: 760, texto: 'limite', cor: 'roxo', tam: 24 },
    { x: 1270, y: 798, texto: 'inferior:', cor: 'roxo', tam: 24 },
    { x: 1270, y: 836, texto: '45 / 10 -> 5', cor: 'roxo', tam: 24 },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Carga i'],
    ['B', 'proc', 'v = 0'],
    ['C', 'dec', 'v < viagens?'],
    ['D', 'dec', 'livre[v] >= carga?'],
    ['E', 'proc', 'v++'],
    ['F', 'proc', 'Abre viagem nova'],
    ['G', 'proc', 'livre[v] -= carga'],
    ['H', 'inicio', 'Próxima carga'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D', 'Sim'],
    ['D', 'G', 'Sim'],
    ['D', 'E', 'Não'],
    ['E', 'C'],
    ['C', 'F', 'Não'],
    ['F', 'G'],
    ['G', 'H'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'C', 'F', 'G', 'H'],
}
