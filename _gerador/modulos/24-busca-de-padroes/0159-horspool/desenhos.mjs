// "A BANCA VENDE MANGA" e o padrão "MANGA": a tabela de saltos e os cinco
// alinhamentos. No texto, amarelo = letra que foi olhada, cinza = nunca olhada
const texto = ['A', '␣', 'B', 'A', 'N', 'C', 'A', '␣', 'V', 'E', 'N', 'D', 'E', '␣', 'M', 'A', 'N', 'G', 'A']
const padrao = ['M', 'A', 'N', 'G', 'A']
const X = 200
const W = 68
const olhadas = [4, 5, 6, 9, 14, 15, 16, 17, 18]

const estTexto = {}
texto.forEach((_, k) => {
  estTexto[k] = olhadas.includes(k) ? 'amarelo' : 'apagado'
})

// cada alinhamento: [i, letras que bateram (da direita), salto, nota]
const passos = [
  [0, 0, "'N': salta 2"],
  [2, 1, "'A': salta 3"],
  [5, 0, "'E' não está: salta 5"],
  [10, 0, "'M': salta 4"],
  [14, 5, 'achou na posição 14'],
]
const Y0 = 420
const DY = 100

const linhas = passos.map(([i, ok], r) => {
  const e = {}
  for (let k = 0; k < ok; k++) e[4 - k] = 'verde'
  if (ok < 5) e[4 - ok] = 'vermelho'
  return { id: `p${r}`, forma: 'array', x: X + i * W, y: Y0 + r * DY, celula: W, indices: false, itens: padrao, cor: 'roxo', estados: e }
})

export const ideia = {
  caixas: [
    {
      id: 'tab',
      forma: 'array',
      x: X,
      y: 20,
      nome: 'salto',
      celula: 190,
      indices: false,
      itens: ['M: 4', 'A: 3', 'N: 2', 'G: 1', 'outras: 5'],
      cor: 'roxo',
    },
    { id: 't', forma: 'array', x: X, y: 250, celula: W, itens: texto, estados: estTexto },
    ...linhas,
  ],
  setas: [],
  notas: [
    { x: 90, y: 302, texto: 'texto', cor: 'azul' },
    ...passos.map(([i, , nota], r) => ({
      x: X + (i + 5) * W + 20,
      y: Y0 + r * DY + 52,
      texto: nota,
      cor: r === 4 ? 'verde' : 'roxo',
      ...(r === 4 ? { ancora: 'end', x: X + i * W - 20 } : {}),
    })),
    { x: 110, y: Y0 + 5 * DY + 30, texto: '5 alinhamentos e 10 comparações; 10 letras do texto (cinza) nem foram olhadas', cor: 'cinza' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início: monta saltos; i = 0'],
    ['B', 'dec', 'i <= n - m?'],
    ['C', 'proc', 'j = m - 1'],
    ['D', 'dec', 'j >= 0 e texto[i+j] == padrao[j]?'],
    ['E', 'proc', 'j--'],
    ['F', 'dec', 'j < 0?'],
    ['G', 'io', 'Mostrar i (14)'],
    ['H', 'proc', 'i += salto[texto[i+m-1]]'],
    ['I', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C', 'Sim'],
    ['C', 'D'],
    ['D', 'E', 'Sim'],
    ['E', 'D'],
    ['D', 'F', 'Não'],
    ['F', 'G', 'Sim'],
    ['F', 'H', 'Não'],
    ['G', 'H'],
    ['H', 'B'],
    ['B', 'I', 'Não'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'F', 'H', 'B', 'C', 'D', 'E', 'D', 'F', 'G', 'H', 'B', 'I'],
}
