// A legenda que abre a aula: as formas do fluxograma e o que cada cor quer
// dizer. As cores são as mesmas no diagrama da ideia.
import { novoQuadro, TINTA } from '../quadro.mjs'
import { forma } from './fluxograma.mjs'

const ITENS = [
  ['inicio', 'início / fim', 'onde o programa', 'começa e termina'],
  ['io', 'entra ou sai', 'scanf e', 'printf'],
  ['proc', 'o programa faz', 'conta, guarda', 'um valor'],
  ['dec', 'pergunta', 'sim ou não?', 'o caminho se divide'],
]

export function desenharLegenda() {
  const q = novoQuadro()
  ITENS.forEach(([tipo, nome, l1, l2], i) => {
    const x = 200 + i * 340
    forma(q, tipo, x, 90, tipo === 'dec' ? 200 : 220, tipo === 'dec' ? 110 : 80, [])
    q.texto(x, 185, nome, { tam: 32, ancora: 'middle' })
    q.texto(x, 228, l1, { tam: 24, cor: '#495057', ancora: 'middle' })
    q.texto(x, 262, l2, { tam: 24, cor: '#495057', ancora: 'middle' })
  })
  // Sim e Não
  q.seta(
    [
      [1440, 70],
      [1560, 70],
    ],
    { cor: TINTA.verde },
  )
  q.texto(1500, 55, 'Sim', { tam: 26, cor: TINTA.verde, ancora: 'middle' })
  q.seta(
    [
      [1440, 150],
      [1560, 150],
    ],
    { cor: TINTA.vermelho },
  )
  q.texto(1500, 135, 'Não', { tam: 26, cor: TINTA.vermelho, ancora: 'middle' })
  q.texto(1500, 228, 'os dois caminhos', { tam: 24, cor: '#495057', ancora: 'middle' })
  q.texto(1500, 262, 'de uma pergunta', { tam: 24, cor: '#495057', ancora: 'middle' })
  return q.svg('Legenda: formas e cores', { x: 40, y: 20, w: 1580, h: 280 })
}
