// Em cima: inverter copiando para uma rota auxiliar (6 gavetas a mais,
// 24 bytes, Θ(n)). Embaixo: inverter no lugar, trocando as pontas com uma
// caixinha tmp (4 bytes, Θ(1)).
const rota = [12, 7, 30, 5, 18, 9]
const C = 90
const cx = (x0, i) => x0 + C / 2 + i * C
const caixas = [
  { id: 'ida', forma: 'array', x: 100, y: 40, nome: 'rota (entrada)', itens: rota },
  { id: 'aux', forma: 'array', x: 900, y: 40, nome: 'aux (extra)', itens: [...rota].reverse(), cor: 'vermelho' },
  {
    id: 'lugar',
    forma: 'array',
    x: 100,
    y: 400,
    nome: 'rota (a mesma)',
    itens: rota,
    estados: { 0: 'roxo', 5: 'roxo', 1: 'azul', 4: 'azul', 2: 'verde', 3: 'verde' },
    indices: false,
  },
  { id: 'tmp', forma: 'caixinha', x: 900, y: 380, nome: 'tmp', valor: '12', tipo: 'int · 4 bytes', cor: 'verde' },
]
const setas = [{ de: 'ida', para: 'aux', rotulo: 'copia ao contrário', cor: 'vermelho' }]
// trocas: um U embaixo de cada par de pontas
;[0, 1, 2].forEach((i) => {
  const y = 680 - i * 40
  const cores = ['roxo', 'azul', 'verde']
  setas.push({ pontos: [[cx(100, i), 562], [cx(100, i), y], [cx(100, 5 - i), y], [cx(100, 5 - i), 568]], cor: cores[i] })
})
const notas = [
  { x: 900, y: 250, texto: 'extra: 6 × 4 = 24 bytes  →  Θ(n)', cor: 'vermelho' },
  { x: 900, y: 650, texto: 'extra: só o tmp, 4 bytes  →  Θ(1)', cor: 'verde' },
  { x: 100, y: 750, texto: '3 trocas, das pontas para o meio, na mesma rota', cor: 'roxo' },
]
export const ideia = { caixas, setas, notas }

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início: inverte_no_lugar(rota, 6)'],
    ['B', 'proc', 'i = 0; j = n - 1'],
    ['C', 'dec', 'i < j?'],
    ['D', 'proc', 'tmp = rota[i]'],
    ['E', 'proc', 'rota[i] = rota[j]; rota[j] = tmp'],
    ['F', 'proc', 'i++; j--'],
    ['G', 'io', 'devolve 4 bytes extras'],
    ['H', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D', 'Sim'],
    ['C', 'G', 'Não'],
    ['D', 'E'],
    ['E', 'F'],
    ['F', 'C'],
    ['G', 'H'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'F', 'C', 'G', 'H'],
}
