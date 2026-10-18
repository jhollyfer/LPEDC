// O "quadro" onde todo diagrama é desenhado: traço à mão (rough.js), fonte do
// Excalidraw, caixas e setas. Cada tipo de diagrama
// (tipos/*.mjs) usa estas peças.
import { readFileSync } from 'node:fs'
import { join, dirname } from 'node:path'
import { fileURLToPath } from 'node:url'
import rough from 'roughjs'

const PASTA_FONTES = join(dirname(fileURLToPath(import.meta.url)), 'fonte')
const FONTE = readFileSync(join(PASTA_FONTES, 'Excalifont-Regular.woff2')).toString('base64')

export const LARGURA = 1600
export const ESCURO = '#1e1e1e'

// cor da borda, do preenchimento e do rótulo de cada caixa
export const CORES = {
  azul: { borda: '#1971c2', fundo: '#d0ebff', texto: '#1864ab' },
  roxo: { borda: '#9c36b5', fundo: '#e5dbff', texto: '#862e9c' },
  verde: { borda: '#2f9e44', fundo: '#d3f9d8', texto: '#2b8a3e' },
  amarelo: { borda: '#e8590c', fundo: '#ffec99', texto: '#d9480f' },
  vermelho: { borda: '#e03131', fundo: '#ffc9c9', texto: '#c92a2a' },
  cinza: { borda: '#868e96', fundo: '#f1f3f5', texto: '#495057' },
}
export const TINTA = {
  roxo: '#9c36b5',
  verde: '#2f9e44',
  vermelho: '#e03131',
  azul: '#1971c2',
  cinza: '#868e96',
}

const escapar = (s) =>
  String(s).replaceAll('&', '&amp;').replaceAll('<', '&lt;').replaceAll('>', '&gt;').replaceAll('"', '&quot;')

// largura aproximada de um texto na Excalifont
export const medir = (s, tam) => String(s).length * tam * 0.55

export function novoQuadro() {
  const gen = rough.generator()
  let semente = 1
  const partes = []
  const opcoes = (extra) => ({ roughness: 1.1, bowing: 1, strokeWidth: 2.5, seed: semente++, ...extra })

  const forma = (desenho) => {
    for (const p of gen.toPaths(desenho)) {
      partes.push(
        `<path d="${p.d}" stroke="${p.stroke}" stroke-width="${p.strokeWidth}" fill="${p.fill ?? 'none'}" stroke-linecap="round" stroke-linejoin="round"/>`,
      )
    }
  }

  const texto = (x, y, conteudo, { tam = 30, cor = ESCURO, ancora = 'start' } = {}) => {
    partes.push(
      `<text x="${x}" y="${y}" font-size="${tam}" fill="${cor}" text-anchor="${ancora}">${escapar(conteudo)}</text>`,
    )
  }

  const solido = (cor) => opcoes({ stroke: cor.borda, fill: cor.fundo, fillStyle: 'solid' })

  // caixa de cantos arredondados; r grande vira pílula
  const caixa = (x, y, w, h, cor, r = 22) => {
    r = Math.min(r, h / 2, w / 2)
    const d = `M ${x + r} ${y} L ${x + w - r} ${y} Q ${x + w} ${y} ${x + w} ${y + r} L ${x + w} ${y + h - r} Q ${x + w} ${y + h} ${x + w - r} ${y + h} L ${x + r} ${y + h} Q ${x} ${y + h} ${x} ${y + h - r} L ${x} ${y + r} Q ${x} ${y} ${x + r} ${y} Z`
    forma(gen.path(d, solido(cor)))
  }
  const poligono = (pontos, cor) => forma(gen.polygon(pontos, solido(cor)))

  // seta passando pelos pontos; o rótulo fica no trecho mais comprido
  const seta = (pontos, { cor = TINTA.roxo, rotulo, dx = 0, dy } = {}) => {
    forma(gen.linearPath(pontos, opcoes({ stroke: cor, roughness: 0.8 })))
    const [px, py] = pontos.at(-1)
    const [ux, uy] = pontos.at(-2)
    const ang = Math.atan2(py - uy, px - ux)
    for (const abre of [0.45, -0.45]) {
      const ponta = [px - 22 * Math.cos(ang + abre), py - 22 * Math.sin(ang + abre)]
      forma(gen.line(px, py, ...ponta, opcoes({ stroke: cor, roughness: 0.6 })))
    }
    if (!rotulo) return
    const tamanho = (k) => Math.hypot(pontos[k + 1][0] - pontos[k][0], pontos[k + 1][1] - pontos[k][1])
    let i = 0
    for (let k = 1; k < pontos.length - 1; k++) if (tamanho(k) > tamanho(i)) i = k
    const [qx, qy] = pontos[i]
    const [rx, ry] = pontos[i + 1]
    const deitada = Math.abs(qy - ry) < 4
    const mx = (qx + rx) / 2 + dx
    const my = (qy + ry) / 2 + (dy ?? (deitada ? -14 : 0))
    texto(deitada ? mx : mx + 14, my, rotulo, { tam: 24, cor, ancora: deitada ? 'middle' : 'start' })
  }

  // recorte: { x, y, w, h } é o pedaço do quadro que vira imagem
  const svg = (titulo, { x = 0, y = 0, w = LARGURA, h }) => {
    const corpo = partes.join('\n')
    const estilo = `@font-face{font-family:Excalifont;src:url(data:font/woff2;base64,${FONTE}) format('woff2')}text{font-family:Excalifont,'Comic Sans MS',cursive;white-space:pre}`
    return `<svg xmlns="http://www.w3.org/2000/svg" width="${w}" height="${h}" viewBox="${x} ${y} ${w} ${h}">
<title>${escapar(titulo)}</title>
<style>${estilo}</style>
<rect x="${x}" y="${y}" width="${w}" height="${h}" fill="#ffffff"/>
${corpo}
</svg>
`
  }

  return { gen, opcoes, forma, texto, caixa, poligono, seta, svg, partes }
}
