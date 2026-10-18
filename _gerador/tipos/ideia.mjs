// Diagrama da ideia: caixas coloridas e setas contando o exemplo do assunto,
// como um slide do Excalidraw. O título e a explicação ficam no texto da aula.
//
// caixas: { id, x, y, w?, h?, cor?, rotulo?, texto, forma?: 'losango' }
//   ou um desenho do conceito (tipos/icones.mjs), com forma: 'caixinha',
//   'balao', 'pessoa', 'terminal', 'cardapio', 'arquivo' ou 'marca'
//   cores: azul (dado que entra ou sai), roxo (o programa faz algo),
//   amarelo (pergunta), verde (resultado, caminho do Sim),
//   vermelho (erro, caminho do Não), cinza (neutro)
// setas:  { de, para, rotulo?, cor?, lados?: 'de' (lado de saída + chegada:
//           d = direita, e = esquerda, c = cima, b = baixo), cotovelo?, dx?, dy? }
//         ou { pontos: [[x, y], ...], rotulo?, cor? } para um caminho livre
// notas:  { x, y, texto, cor? } texto solto
import { novoQuadro, CORES, TINTA, medir } from '../quadro.mjs'
import { ICONES } from './icones.mjs'

// três caixas lado a lado, ligadas por setas; a largura acompanha o texto
export const fileira = (y, [a, b, c], [s1, s2] = []) => {
  const trio = [a, b, c]
  const linhas = Math.max(...trio.map((x) => [].concat(x.texto).length))
  const h = 150 + (linhas - 1) * 40
  const larg = trio.map(
    (x) =>
      x.w ??
      Math.max(
        300,
        ...[].concat(x.texto).map((l) => medir(l, 30) + 60),
        (x.rotulo ?? '').length * 24 * 0.75 + 60,
      ),
  )
  const vao = Math.max(140, (1380 - larg[0] - larg[1] - larg[2]) / 2)
  const xs = [110, 110 + larg[0] + vao, 110 + larg[0] + larg[1] + 2 * vao]
  const cores = ['azul', 'roxo', 'verde']
  return {
    caixas: trio.map((x, i) => ({ id: 'abc'[i], x: xs[i], y, w: larg[i], h, cor: cores[i], ...x })),
    setas: [
      { de: 'a', para: 'b', rotulo: s1 },
      { de: 'b', para: 'c', rotulo: s2 },
    ],
  }
}

// uma pergunta (losango) que abre dois caminhos
export const bifurcacao = ({ inicio, pergunta, sim, nao, rotuloSim = 'Sim', rotuloNao = 'Não' }) => {
  const w = Math.max(430, ...[sim, nao].flatMap((c) => [].concat(c.texto).map((l) => medir(l, 30) + 60)))
  return {
    caixas: [
      { id: 'ini', x: 110, y: 380, w: 320, cor: 'azul', ...inicio },
      { id: 'p', x: 540, y: 355, w: 340, h: 200, forma: 'losango', cor: 'amarelo', texto: pergunta },
      { id: 'sim', x: 1060, y: 250, w, cor: 'verde', ...sim },
      { id: 'nao', x: 1060, y: 510, w, cor: 'vermelho', ...nao },
    ],
    setas: [
      { de: 'ini', para: 'p' },
      { de: 'p', para: 'sim', lados: 'ce', cotovelo: true, rotulo: rotuloSim, cor: 'verde' },
      { de: 'p', para: 'nao', lados: 'be', cotovelo: true, rotulo: rotuloNao, cor: 'vermelho' },
    ],
  }
}

export function desenharIdeia(titulo, d) {
  const q = novoQuadro()
  let topo = Infinity
  let fundo = 0

  const caixas = new Map()
  for (const c of d.caixas) {
    // desenhos do conceito (caixinha, balão, pessoa...)
    if (ICONES[c.forma]) {
      for (const [id, b] of Object.entries(ICONES[c.forma](q, c))) {
        caixas.set(id, b)
        fundo = Math.max(fundo, b.y + b.h)
      }
      topo = Math.min(topo, c.y)
      continue
    }
    const cor = CORES[c.cor ?? 'azul']
    const linhas = [].concat(c.texto ?? [])
    const losango = c.forma === 'losango'
    const w = c.w ?? (losango ? 300 : 320)
    const h = c.h ?? (losango ? 200 : 150 + Math.max(0, linhas.length - 1) * 40)
    const { x, y } = c
    caixas.set(c.id, { x, y, w, h })
    topo = Math.min(topo, y)
    fundo = Math.max(fundo, y + h)

    if (losango) {
      q.poligono(
        [
          [x + w / 2, y],
          [x + w, y + h / 2],
          [x + w / 2, y + h],
          [x, y + h / 2],
        ],
        cor,
      )
      const topo = y + h / 2 - ((linhas.length - 1) * 38) / 2 + 10
      linhas.forEach((l, i) => q.texto(x + w / 2, topo + i * 38, l, { tam: 28, ancora: 'middle' }))
      continue
    }

    q.caixa(x, y, w, h, cor)
    let ty = y + 50
    if (c.rotulo) {
      // código (.trim(), Math.ceil) fica como está; o resto vai em maiúsculas
      const rotulo = /[.()]/.test(c.rotulo) ? c.rotulo : c.rotulo.toUpperCase()
      q.texto(x + 26, ty, rotulo, { tam: 24, cor: cor.texto })
      ty += 52
    } else {
      ty = y + h / 2 - ((linhas.length - 1) * 40) / 2 + 10
    }
    linhas.forEach((l, i) => q.texto(x + 26, ty + i * 40, l, { tam: 30 }))
  }

  // setas: saem do lado de uma caixa e chegam no lado da outra
  const ponto = (b, lado) =>
    ({
      d: [b.x + b.w, b.y + b.h / 2],
      e: [b.x, b.y + b.h / 2],
      c: [b.x + b.w / 2, b.y],
      b: [b.x + b.w / 2, b.y + b.h],
    })[lado]
  const ladoAuto = (a, b) => {
    const dx = b.x + b.w / 2 - (a.x + a.w / 2)
    const dy = b.y + b.h / 2 - (a.y + a.h / 2)
    if (Math.abs(dx) >= Math.abs(dy)) return dx > 0 ? ['d', 'e'] : ['e', 'd']
    return dy > 0 ? ['b', 'c'] : ['c', 'b']
  }
  const folga = ([px, py], lado) => {
    const [vx, vy] = { d: [1, 0], e: [-1, 0], c: [0, -1], b: [0, 1] }[lado]
    return [px + vx * 16, py + vy * 16]
  }
  for (const s of d.setas ?? []) {
    // seta com caminho livre: pontos [[x, y], ...]
    if (s.pontos) {
      // o rótulo fica uns 40 px acima da seta; o recorte precisa alcançar
      topo = Math.min(topo, ...s.pontos.map(([, y]) => y + 40 - (s.rotulo ? 50 : 0)))
      fundo = Math.max(fundo, ...s.pontos.map(([, y]) => y))
      q.seta(s.pontos, { cor: TINTA[s.cor ?? 'roxo'], rotulo: s.rotulo, dx: s.dx, dy: s.dy })
      continue
    }
    const a = caixas.get(s.de)
    const b = caixas.get(s.para)
    if (!a || !b) throw new Error(`${titulo}: seta ${s.de} -> ${s.para} aponta para caixa que não existe`)
    const [la, lb] = s.lados ? [...s.lados] : ladoAuto(a, b)
    let p1 = folga(ponto(a, la), la)
    let p2 = folga(ponto(b, lb), lb)
    // caixas lado a lado: a seta sai reta, no meio da parte em comum
    if (!s.lados && !s.cotovelo) {
      if ('de'.includes(la)) {
        const topo = Math.max(a.y, b.y)
        const base = Math.min(a.y + a.h, b.y + b.h)
        if (base - topo > 40) ((p1 = [p1[0], (topo + base) / 2]), (p2 = [p2[0], (topo + base) / 2]))
      } else {
        const esq = Math.max(a.x, b.x)
        const dir = Math.min(a.x + a.w, b.x + b.w)
        if (dir - esq > 40) ((p1 = [(esq + dir) / 2, p1[1]]), (p2 = [(esq + dir) / 2, p2[1]]))
      }
    }
    // com cotovelo: anda reto e depois vira
    const pontos = s.cotovelo
      ? 'de'.includes(la)
        ? [p1, [p2[0], p1[1]], p2]
        : [p1, [p1[0], p2[1]], p2]
      : [p1, p2]
    q.seta(pontos, { cor: TINTA[s.cor ?? 'roxo'], rotulo: s.rotulo, dx: s.dx, dy: s.dy })
  }

  // notas soltas (texto colorido, sem caixa)
  for (const n of d.notas ?? []) {
    const linhas = [].concat(n.texto)
    linhas.forEach((l, i) =>
      q.texto(n.x, n.y + i * 38, l, { tam: n.tam ?? 26, cor: TINTA[n.cor ?? 'roxo'], ancora: n.ancora }),
    )
    fundo = Math.max(fundo, n.y + (linhas.length - 1) * 38)
  }

  // corta o quadro em volta do desenho (rótulos de seta podem subir um pouco)
  topo -= 60
  const direita = Math.max(...[...caixas.values()].map((c) => c.x + c.w)) + 60
  return q.svg(titulo, { x: 60, y: topo, w: Math.max(1480, direita - 60), h: fundo + 50 - topo })
}
