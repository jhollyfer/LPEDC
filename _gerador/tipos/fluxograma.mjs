// Fluxograma: o caminho que o programa faz, com as formas de sempre
// (início/fim, entrada/saída, processo, decisão). A posição de cada forma é
// calculada pelo dagre.
//
// nos:   [id, tipo, texto]   tipos: inicio, io, proc, dec
// setas: [de, para, rotulo?] rótulo 'Sim' fica verde, 'Não' vermelho
// caminho: [ids] (opcional) por onde o exemplo do texto passa; o resto fica cinza
import dagre from '@dagrejs/dagre'
import { novoQuadro, CORES, TINTA, medir } from '../quadro.mjs'

const TAM = 28
// mesmas cores do diagrama da ideia: azul entra e sai, roxo faz, amarelo pergunta
export const ESTILO = {
  inicio: CORES.cinza,
  io: CORES.azul,
  proc: CORES.roxo,
  dec: CORES.amarelo,
}

// textos compridos quebram em duas linhas, perto do meio
const quebrar = (texto) => {
  if (texto.length <= 24) return [texto]
  const espacos = [...texto.matchAll(/ /g)].map((m) => m.index)
  if (!espacos.length) return [texto]
  const meio = espacos.reduce((a, b) =>
    Math.abs(b - texto.length / 2) < Math.abs(a - texto.length / 2) ? b : a,
  )
  return [texto.slice(0, meio), texto.slice(meio + 1)]
}

const tamanho = (tipo, linhas) => {
  const w = Math.max(...linhas.map((l) => medir(l, TAM)))
  const extra = (linhas.length - 1) * 36
  if (tipo === 'dec') return { width: w * 1.5 + 90, height: 150 + extra }
  if (tipo === 'inicio') return { width: Math.max(150, w + 70), height: 76 }
  if (tipo === 'io') return { width: Math.max(190, w + 110), height: 90 + extra }
  return { width: Math.max(190, w + 60), height: 90 + extra }
}

// desenha uma forma com o centro em (x, y)
export function forma(q, tipo, x, y, w, h, linhas = [], apagado = false) {
  const cor = apagado ? CORES.cinza : ESTILO[tipo]
  const esq = x - w / 2
  const topo = y - h / 2
  if (tipo === 'inicio') q.caixa(esq, topo, w, h, cor, h / 2)
  else if (tipo === 'proc') q.caixa(esq, topo, w, h, cor, 10)
  else if (tipo === 'io') {
    const inc = Math.min(26, w / 4)
    q.poligono(
      [
        [esq + inc, topo],
        [esq + w, topo],
        [esq + w - inc, topo + h],
        [esq, topo + h],
      ],
      cor,
    )
  } else {
    q.poligono(
      [
        [x, topo],
        [esq + w, y],
        [x, topo + h],
        [esq, y],
      ],
      cor,
    )
  }
  const y0 = y - ((linhas.length - 1) * 36) / 2 + 10
  linhas.forEach((l, i) =>
    q.texto(x, y0 + i * 36, l, { tam: TAM, ancora: 'middle', cor: apagado ? '#868e96' : undefined }),
  )
}

export function desenharFluxograma(titulo, { nos, setas, caminho }) {
  const passou = (id) => !caminho || caminho.includes(id)
  const andou = (de, para) => !caminho || caminho.some((id, i) => id === de && caminho[i + 1] === para)
  const g = new dagre.graphlib.Graph()
  // sem decisão, o caminho é uma linha só e fica deitado; com decisão, em pé
  const deitado = !nos.some(([, tipo]) => tipo === 'dec')
  g.setGraph({
    rankdir: deitado ? 'LR' : 'TB',
    nodesep: 60,
    ranksep: deitado ? 70 : 60,
    marginx: 50,
    marginy: 40,
  })
  g.setDefaultEdgeLabel(() => ({}))
  const linhas = {}
  for (const [id, tipo, texto] of nos) {
    if (!ESTILO[tipo]) throw new Error(`${titulo}: tipo de nó desconhecido "${tipo}"`)
    linhas[id] = quebrar(texto)
    g.setNode(id, tamanho(tipo, linhas[id]))
  }
  for (const [de, para, rotulo] of setas) {
    if (!g.hasNode(de) || !g.hasNode(para)) throw new Error(`${titulo}: seta ${de} -> ${para} sem nó`)
    g.setEdge(de, para, rotulo ? { width: medir(rotulo, 24) + 20, height: 30, labelpos: 'c' } : {})
  }
  dagre.layout(g)

  const q = novoQuadro()
  for (const [id, tipo] of nos) {
    const n = g.node(id)
    forma(q, tipo, n.x, n.y, n.width, n.height, linhas[id], !passou(id))
  }
  for (const [de, para, rotulo] of setas) {
    const e = g.edge(de, para)
    const cor = !andou(de, para)
      ? '#ced4da'
      : rotulo === 'Sim'
        ? TINTA.verde
        : rotulo === 'Não'
          ? TINTA.vermelho
          : TINTA.cinza
    q.seta(
      e.points.map((p) => [p.x, p.y]),
      { cor },
    )
    if (rotulo) q.texto(e.x, e.y + 8, rotulo, { tam: 24, cor, ancora: 'middle' })
  }
  const { width, height } = g.graph()
  return q.svg(titulo, { w: Math.ceil(width), h: Math.ceil(height) })
}
