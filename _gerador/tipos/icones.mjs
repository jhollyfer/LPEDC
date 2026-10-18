// Desenhos do conceito para o diagrama da ideia: caixinha com etiqueta, balão
// de fala, pessoa, terminal, cardápio, arquivo e marca de certo/errado.
// Cada função desenha a partir de (x, y) e devolve as caixas que as setas podem
// usar: { [id]: { x, y, w, h } }.
import { CORES, TINTA, medir } from '../quadro.mjs'

const cinzaTexto = '#495057'
// largura de um texto na letra de mão; maiúscula ocupa mais espaço
const largura = (s, tam) => [...String(s)].reduce((t, c) => t + (/[A-ZÀ-Ý_]/.test(c) ? 0.74 : 0.55) * tam, 0)

// caixinha com etiqueta: a variável. O nome fica na etiqueta, o valor dentro.
function caixinha(q, c) {
  const cor = CORES[c.cor ?? 'azul']
  const valor = String(c.valor ?? '')
  const wEtiqueta = largura(c.nome ?? '', 26) + 44
  const w = c.w ?? Math.max(230, largura(valor, 36) + 70, wEtiqueta + (c.cadeado ? 90 : 40))
  const h = 140
  const yCaixa = c.y + 54
  // etiqueta pendurada
  q.poligono(
    [
      [c.x + 16, c.y + 4],
      [c.x + 16 + wEtiqueta - 16, c.y + 4],
      [c.x + 16 + wEtiqueta, c.y + 24],
      [c.x + 16 + wEtiqueta - 16, c.y + 44],
      [c.x + 16, c.y + 44],
    ],
    { borda: cor.borda, fundo: '#ffffff' },
  )
  q.texto(c.x + 30, c.y + 33, c.nome ?? '', { tam: 26, cor: cor.texto })
  q.forma(q.gen.line(c.x + 40, c.y + 44, c.x + 50, yCaixa, q.opcoes({ stroke: cor.borda, strokeWidth: 2 })))
  // a caixa, com a tampa
  q.caixa(c.x, yCaixa, w, h, cor, 12)
  q.forma(
    q.gen.line(
      c.x + 8,
      yCaixa + 30,
      c.x + w - 8,
      yCaixa + 30,
      q.opcoes({ stroke: cor.borda, strokeWidth: 1.5 }),
    ),
  )
  q.texto(c.x + w / 2, yCaixa + 88, valor, { tam: 36, ancora: 'middle' })
  if (c.tipo) q.texto(c.x + w / 2, yCaixa + h - 12, c.tipo, { tam: 20, cor: cinzaTexto, ancora: 'middle' })
  if (c.cadeado) cadeado(q, c.x + w - 40, yCaixa - 26)
  // endereço na memória, embaixo da caixa (ex.: 0x7ffc10)
  if (c.end) q.texto(c.x + w / 2, yCaixa + h + 32, c.end, { tam: 22, cor: '#868e96', ancora: 'middle' })
  return { [c.id]: { x: c.x, y: yCaixa, w, h: h + (c.end ? 40 : 0) } }
}

function cadeado(q, x, y) {
  const cor = { borda: '#495057', fundo: '#ced4da' }
  q.forma(
    q.gen.arc(
      x + 20,
      y + 22,
      26,
      34,
      Math.PI,
      2 * Math.PI,
      false,
      q.opcoes({ stroke: '#495057', strokeWidth: 3 }),
    ),
  )
  q.caixa(x, y + 20, 40, 32, cor, 5)
  q.forma(
    q.gen.circle(x + 20, y + 34, 7, q.opcoes({ stroke: '#495057', fill: '#495057', fillStyle: 'solid' })),
  )
}

// balão de fala; a ponta aponta para quem fala
function balao(q, c) {
  const cor = CORES[c.cor ?? 'cinza']
  const linhas = [].concat(c.texto)
  const w = c.w ?? Math.max(...linhas.map((l) => medir(l, 30))) + 60
  const h = c.h ?? linhas.length * 40 + 40
  const { x, y } = c
  const ponta = c.ponta ?? 'esq'
  const pontas = {
    esq: [
      [x + 30, y + h - 4],
      [x - 10, y + h + 34],
      [x + 66, y + h - 4],
    ],
    dir: [
      [x + w - 66, y + h - 4],
      [x + w + 10, y + h + 34],
      [x + w - 30, y + h - 4],
    ],
  }
  q.poligono(pontas[ponta], cor)
  q.caixa(x, y, w, h, cor, 26)
  // cobre a emenda entre a ponta e o balão
  const [a, , b] = pontas[ponta]
  q.partes.push(
    `<rect x="${a[0] + 4}" y="${y + h - 14}" width="${b[0] - a[0] - 8}" height="12" fill="${cor.fundo}"/>`,
  )
  const y0 = y + h / 2 - ((linhas.length - 1) * 40) / 2 + 10
  linhas.forEach((l, i) => q.texto(x + w / 2, y0 + i * 40, l, { tam: 30, ancora: 'middle' }))
  return { [c.id]: { x, y, w, h } }
}

// bonequinho com o nome embaixo
function pessoa(q, c) {
  const { x, y } = c
  const cor = CORES[c.cor ?? 'cinza']
  const o = (extra) => q.opcoes({ stroke: cor.borda, strokeWidth: 3, ...extra })
  q.forma(q.gen.circle(x + 50, y + 34, 56, o({ fill: cor.fundo, fillStyle: 'solid' })))
  q.forma(q.gen.line(x + 50, y + 62, x + 50, y + 130, o()))
  q.forma(q.gen.line(x + 50, y + 84, x + 14, y + 112, o()))
  q.forma(q.gen.line(x + 50, y + 84, x + 86, y + 112, o()))
  q.forma(q.gen.line(x + 50, y + 130, x + 22, y + 176, o()))
  q.forma(q.gen.line(x + 50, y + 130, x + 78, y + 176, o()))
  if (c.nome) q.texto(x + 50, y + 214, c.nome, { tam: 28, ancora: 'middle' })
  return { [c.id]: { x, y, w: 100, h: 220 } }
}

// janela de terminal com o que o programa mostrou
function terminal(q, c) {
  const linhas = [].concat(c.texto)
  const w = c.w ?? Math.max(300, ...linhas.map((l) => medir(l, 30) + 60))
  const h = linhas.length * 42 + 76
  const { x, y } = c
  q.caixa(x, y, w, h, { borda: '#343a40', fundo: '#343a40' }, 14)
  ;['#ff6b6b', '#ffd43b', '#69db7c'].forEach((f, i) =>
    q.forma(
      q.gen.circle(
        x + 26 + i * 24,
        y + 22,
        13,
        q.opcoes({ stroke: f, fill: f, fillStyle: 'solid', roughness: 0.4 }),
      ),
    ),
  )
  q.texto(x + w - 18, y + 30, 'terminal', { tam: 20, cor: '#adb5bd', ancora: 'end' })
  linhas.forEach((l, i) => q.texto(x + 24, y + 80 + i * 42, l, { tam: 30, cor: '#f8f9fa' }))
  return { [c.id]: { x, y, w, h } }
}

// cardápio: uma lista de opções, com a escolhida em destaque
function cardapio(q, c) {
  const { x, y } = c
  const w = c.w ?? 420
  const alt = 56
  const h = 84 + c.itens.length * alt
  q.caixa(x, y, w, h, { borda: '#868e96', fundo: '#fff9db' }, 8)
  q.texto(x + w / 2, y + 48, c.titulo ?? 'CARDÁPIO', { tam: 28, cor: CORES.amarelo.texto, ancora: 'middle' })
  q.forma(q.gen.line(x + 30, y + 64, x + w - 30, y + 64, q.opcoes({ stroke: '#ced4da', strokeWidth: 2 })))
  const registro = { [c.id]: { x, y, w, h } }
  c.itens.forEach(([chave, texto], i) => {
    const yi = y + 76 + i * alt
    if (i === c.destaque) q.caixa(x + 14, yi, w - 28, alt - 8, CORES.verde, 10)
    q.texto(x + 34, yi + 34, chave, { tam: 28, cor: CORES.roxo.texto })
    q.texto(x + 34 + Math.max(110, medir(chave, 28) + 30), yi + 34, texto, { tam: 28 })
    registro[`${c.id}:${i}`] = { x: x + 14, y: yi, w: w - 28, h: alt - 8 }
  })
  return registro
}

// arquivo com o canto dobrado e o nome em cima
function arquivo(q, c) {
  const cor = CORES[c.cor ?? 'cinza']
  const linhas = [].concat(c.texto ?? [])
  const w = c.w ?? Math.max(260, ...linhas.map((l) => medir(l, 28) + 60))
  const h = c.h ?? linhas.length * 40 + 90
  const { x, y } = c
  const dobra = 34
  q.poligono(
    [
      [x, y],
      [x + w - dobra, y],
      [x + w, y + dobra],
      [x + w, y + h],
      [x, y + h],
    ],
    cor,
  )
  q.forma(
    q.gen.linearPath(
      [
        [x + w - dobra, y],
        [x + w - dobra, y + dobra],
        [x + w, y + dobra],
      ],
      q.opcoes({ stroke: cor.borda, strokeWidth: 2 }),
    ),
  )
  q.texto(x + 22, y + 40, c.nome ?? '', { tam: 26, cor: cor.texto })
  linhas.forEach((l, i) => q.texto(x + 22, y + 86 + i * 40, l, { tam: 28 }))
  return { [c.id]: { x, y, w, h } }
}

// marca de certo (✓) ou errado (✗), desenhada à mão
function marca(q, c) {
  const { x, y } = c
  const t = c.tamanho ?? 60
  const o = (cor) => q.opcoes({ stroke: cor, strokeWidth: 6, roughness: 0.8 })
  if (c.tipo === 'certo') {
    q.forma(
      q.gen.linearPath(
        [
          [x, y + t * 0.55],
          [x + t * 0.38, y + t],
          [x + t, y],
        ],
        o(TINTA.verde),
      ),
    )
  } else {
    q.forma(q.gen.line(x, y, x + t, y + t, o(TINTA.vermelho)))
    q.forma(q.gen.line(x + t, y, x, y + t, o(TINTA.vermelho)))
  }
  return { [c.id]: { x, y, w: t, h: t } }
}

// array: gavetas lado a lado, com o índice embaixo de cada uma
// estados: { [indice]: 'verde' | 'vermelho' | 'amarelo' | 'roxo' | 'apagado' }
function array(q, c) {
  const cor = CORES[c.cor ?? 'azul']
  const itens = c.itens.map(String)
  const wCel = c.celula ?? Math.max(90, ...itens.map((v) => largura(v, 30) + 40))
  const hCel = 84
  const yCel = c.nome ? c.y + 54 : c.y
  const registro = {}
  if (c.nome) {
    const wEtiqueta = largura(c.nome, 26) + 44
    q.poligono(
      [
        [c.x + 16, c.y + 4],
        [c.x + wEtiqueta, c.y + 4],
        [c.x + wEtiqueta + 16, c.y + 24],
        [c.x + wEtiqueta, c.y + 44],
        [c.x + 16, c.y + 44],
      ],
      { borda: cor.borda, fundo: '#ffffff' },
    )
    q.texto(c.x + 30, c.y + 33, c.nome, { tam: 26, cor: cor.texto })
  }
  itens.forEach((v, i) => {
    const estado = c.estados?.[i]
    const x = c.x + i * wCel
    const corCel = estado === 'apagado' ? { borda: '#ced4da', fundo: '#f8f9fa' } : (CORES[estado] ?? cor)
    q.caixa(x, yCel, wCel, hCel, corCel, 6)
    q.texto(x + wCel / 2, yCel + 54, v, {
      tam: 30,
      ancora: 'middle',
      cor: estado === 'apagado' ? '#adb5bd' : undefined,
    })
    if (c.indices !== false)
      q.texto(x + wCel / 2, yCel + hCel + 30, String(i), { tam: 22, cor: '#868e96', ancora: 'middle' })
    registro[`${c.id}:${i}`] = { x, y: yCel, w: wCel, h: hCel }
  })
  registro[c.id] = { x: c.x, y: yCel, w: wCel * itens.length, h: hCel + (c.indices !== false ? 40 : 0) }
  return registro
}

export const ICONES = { caixinha, balao, pessoa, terminal, cardapio, arquivo, marca, array }

// ---------------------------------------------------------------------------
// Peças do LPEDC: memória, ponteiros e estruturas de dados
// ---------------------------------------------------------------------------

// seta curva (arco) de um ponto a outro, para ponteiros
function arco(q, [x1, y1], [x2, y2], cor, curva = 60) {
  const mx = (x1 + x2) / 2 + curva
  const my = (y1 + y2) / 2
  const pts = []
  for (let t = 0; t <= 1.0001; t += 0.1) {
    const x = (1 - t) ** 2 * x1 + 2 * (1 - t) * t * mx + t ** 2 * x2
    const y = (1 - t) ** 2 * y1 + 2 * (1 - t) * t * my + t ** 2 * y2
    pts.push([x, y])
  }
  q.seta(pts, { cor })
}

// memória: uma coluna de gavetas, cada uma com endereço à esquerda, valor
// dentro e nome à direita. ponteiros: [[de, para]] (índices das gavetas)
// celulas: [{ end, nome?, valor, tipo?, cor?: 'verde' | 'vermelho' | 'amarelo' | 'roxo' | 'apagado' }]
function memoria(q, c) {
  const { x, y } = c
  const w = c.w ?? Math.max(200, ...c.celulas.map((m) => largura(m.valor ?? '', 30) + 50))
  const h = c.celula ?? 70
  const wEnd = Math.max(...c.celulas.map((m) => largura(m.end ?? '', 22))) + 20
  const x0 = x + wEnd
  const registro = {}
  if (c.titulo) q.texto(x0 + w / 2, y - 18, c.titulo, { tam: 24, cor: cinzaTexto, ancora: 'middle' })
  c.celulas.forEach((m, i) => {
    const yi = y + i * h
    const apagado = m.cor === 'apagado'
    const cor = apagado ? { borda: '#ced4da', fundo: '#f8f9fa' } : CORES[m.cor ?? c.cor ?? 'azul']
    q.caixa(x0, yi, w, h, cor, 4)
    q.texto(x0 + w / 2, yi + h / 2 + 10, m.valor ?? '', { tam: 30, ancora: 'middle', cor: apagado ? '#adb5bd' : undefined })
    if (m.end) q.texto(x0 - 12, yi + h / 2 + 8, m.end, { tam: 22, cor: '#868e96', ancora: 'end' })
    if (m.nome) {
      q.texto(x0 + w + 18, yi + h / 2 + 4, m.nome, { tam: 28, cor: (CORES[m.cor] ?? CORES[c.cor ?? 'azul']).texto })
      if (m.tipo) q.texto(x0 + w + 18, yi + h / 2 + 28, m.tipo, { tam: 20, cor: cinzaTexto })
    }
    registro[`${c.id}:${i}`] = { x: x0, y: yi, w, h }
  })
  for (const [de, para] of c.ponteiros ?? []) {
    const a = registro[`${c.id}:${de}`]
    const b = registro[`${c.id}:${para}`]
    // o ponteiro sai pela esquerda (antes dos endereços) e chega no endereço do alvo
    arco(q, [x - 6, a.y + a.h / 2], [x - 6, b.y + b.h / 2], TINTA.roxo, -50 - Math.abs(de - para) * 14)
  }
  registro[c.id] = { x, y, w: w + wEnd, h: c.celulas.length * h }
  return registro
}

// lista encadeada: nós [valor | próx] ligados por setas; termina em NULL.
// itens: ['3', '7'], cabeca: 'inicio' (rótulo do ponteiro de entrada),
// dupla: true desenha [ant | valor | próx], circular: true volta ao primeiro
// estados: { [i]: cor }
function lista(q, c) {
  const { x, y } = c
  const itens = c.itens.map(String)
  const wVal = c.celula ?? Math.max(80, ...itens.map((v) => largura(v, 30) + 36))
  const wPtr = 46
  const wNo = wVal + wPtr * (c.dupla ? 2 : 1)
  const h = 76
  const vao = c.vao ?? 90
  const x0 = c.cabeca ? x + Math.max(120, largura(c.cabeca, 26) + 40) : x
  const yNo = y + 20
  const registro = {}
  if (c.cabeca) {
    q.texto(x, yNo + h / 2 + 8, c.cabeca, { tam: 26, cor: TINTA.roxo })
    q.seta([[x + largura(c.cabeca, 26) + 10, yNo + h / 2], [x0 - 6, yNo + h / 2]], { cor: TINTA.roxo })
  }
  itens.forEach((v, i) => {
    const xi = x0 + i * (wNo + vao)
    const estado = c.estados?.[i]
    const cor = estado === 'apagado' ? { borda: '#ced4da', fundo: '#f8f9fa' } : (CORES[estado] ?? CORES[c.cor ?? 'azul'])
    q.caixa(xi, yNo, wNo, h, cor, 8)
    const xv = xi + (c.dupla ? wPtr : 0)
    q.texto(xv + wVal / 2, yNo + h / 2 + 10, v, { tam: 30, ancora: 'middle' })
    const divisor = (dx) => q.forma(q.gen.line(dx, yNo + 4, dx, yNo + h - 4, q.opcoes({ stroke: cor.borda, strokeWidth: 2 })))
    divisor(xv + wVal)
    if (c.dupla) divisor(xv)
    // ponto de onde sai o ponteiro próx
    const px = xv + wVal + wPtr / 2
    q.forma(q.gen.circle(px, yNo + h / 2, 10, q.opcoes({ stroke: ESCURO_LOCAL, fill: ESCURO_LOCAL, fillStyle: 'solid', roughness: 0.3 })))
    const ultimo = i === itens.length - 1
    if (!ultimo) q.seta([[px, yNo + h / 2], [xi + wNo + vao - 6, yNo + h / 2]], { cor: ESCURO_LOCAL })
    else if (c.circular) {
      const volta = yNo + h + 50
      q.seta([[px, yNo + h / 2], [px, volta], [x0 + wNo / 2, volta], [x0 + wNo / 2, yNo + h + 6]], { cor: ESCURO_LOCAL })
    } else {
      q.seta([[px, yNo + h / 2], [xi + wNo + 60, yNo + h / 2]], { cor: ESCURO_LOCAL })
      q.texto(xi + wNo + 70, yNo + h / 2 + 9, 'NULL', { tam: 26, cor: cinzaTexto })
    }
    if (c.dupla) {
      const ax = xi + wPtr / 2
      q.forma(q.gen.circle(ax, yNo + h / 2, 10, q.opcoes({ stroke: ESCURO_LOCAL, fill: ESCURO_LOCAL, fillStyle: 'solid', roughness: 0.3 })))
      if (i > 0) q.seta([[ax, yNo + h / 2 + 22], [xi - vao + 6, yNo + h / 2 + 22]], { cor: cinzaTexto })
      else {
        q.seta([[ax, yNo + h / 2 + 22], [xi - 50, yNo + h / 2 + 22]], { cor: cinzaTexto })
        if (!c.cabeca && !c.circular) q.texto(xi - 60, yNo + h / 2 + 30, 'NULL', { tam: 22, cor: cinzaTexto, ancora: 'end' })
      }
    }
    if (c.rotulos?.[i]) q.texto(xi + wNo / 2, yNo - 14, c.rotulos[i], { tam: 24, cor: TINTA.roxo, ancora: 'middle' })
    registro[`${c.id}:${i}`] = { x: xi, y: yNo, w: wNo, h }
  })
  const fim = x0 + itens.length * (wNo + vao) + (c.circular ? 0 : 80)
  registro[c.id] = { x, y, w: fim - x, h: h + 20 + (c.circular ? 60 : 0) }
  return registro
}
const ESCURO_LOCAL = '#1e1e1e'

// pilha: caixas empilhadas (o primeiro item fica embaixo), seta no topo
// itens: ['A', 'B'] ou [['main()', 'x = 3'], ...] para mais de uma linha
function pilha(q, c) {
  const { x, y } = c
  const itens = c.itens.map((v) => [].concat(v).map(String))
  const w = c.w ?? Math.max(200, ...itens.flat().map((l) => largura(l, 28) + 50))
  const alturas = itens.map((l) => 30 + l.length * 38)
  const total = alturas.reduce((a, b) => a + b, 0)
  const registro = {}
  // o "copo" da pilha
  q.forma(q.gen.linearPath([[x - 14, y - 20], [x - 14, y + total + 14], [x + w + 14, y + total + 14], [x + w + 14, y - 20]], q.opcoes({ stroke: '#868e96', strokeWidth: 3 })))
  let yi = y + total
  itens.forEach((linhas, i) => {
    const hi = alturas[i]
    yi -= hi
    const estado = c.estados?.[i]
    const cor = estado === 'apagado' ? { borda: '#ced4da', fundo: '#f8f9fa' } : (CORES[estado] ?? CORES[c.cor ?? 'roxo'])
    q.caixa(x, yi + 3, w, hi - 6, cor, 8)
    linhas.forEach((l, k) => q.texto(x + w / 2, yi + 3 + (hi - 6) / 2 - ((linhas.length - 1) * 38) / 2 + 10 + k * 38, l, { tam: 28, ancora: 'middle' }))
    registro[`${c.id}:${i}`] = { x, y: yi, w, h: hi }
  })
  if (c.topo !== false && itens.length) {
    const a = registro[`${c.id}:${itens.length - 1}`]
    q.seta([[x + w + 130, a.y + a.h / 2], [x + w + 24, a.y + a.h / 2]], { cor: TINTA.roxo })
    q.texto(x + w + 140, a.y + a.h / 2 + 9, c.topo ?? 'topo', { tam: 26, cor: TINTA.roxo })
  }
  if (c.titulo) q.texto(x + w / 2, y + total + 56, c.titulo, { tam: 24, cor: cinzaTexto, ancora: 'middle' })
  registro[c.id] = { x, y, w: w + 220, h: total + (c.titulo ? 60 : 20) }
  return registro
}

// árvore binária: raiz = { v, e?, d? }. Posição horizontal pela ordem
// em-ordem; estados: { [valor]: cor }; arestasMarcadas: [[pai, filho]]
function arvore(q, c) {
  const { x, y } = c
  const dx = c.dx ?? 110
  const dy = c.dy ?? 120
  const r = c.raio ?? 36
  const nos = []
  let ordem = 0
  const visita = (n, nivel, pai) => {
    if (!n) return
    visita(n.e, nivel + 1, n)
    const no = { n, nivel, pai, i: ordem++ }
    nos.push(no)
    n.__no = no
    visita(n.d, nivel + 1, n)
  }
  visita(c.raiz, 0, null)
  const pos = (no) => [x + r + no.i * dx, y + r + no.nivel * dy]
  const registro = {}
  for (const no of nos) {
    if (!no.pai) continue
    const [x1, y1] = pos(no.pai.__no)
    const [x2, y2] = pos(no)
    const marcada = (c.marcadas ?? []).some(([p, f]) => String(p) === String(no.pai.v) && String(f) === String(no.n.v))
    q.forma(q.gen.line(x1, y1 + r * 0.9, x2, y2 - r * 0.9, q.opcoes({ stroke: marcada ? TINTA.verde : '#495057', strokeWidth: marcada ? 4 : 2.5 })))
  }
  for (const no of nos) {
    const [cx, cy] = pos(no)
    const estado = c.estados?.[no.n.v]
    const cor = estado === 'apagado' ? { borda: '#ced4da', fundo: '#f8f9fa' } : (CORES[estado] ?? CORES[c.cor ?? 'azul'])
    q.forma(q.gen.circle(cx, cy, r * 2, q.opcoes({ stroke: cor.borda, fill: cor.fundo, fillStyle: 'solid' })))
    q.texto(cx, cy + 10, String(no.n.v), { tam: 28, ancora: 'middle', cor: estado === 'apagado' ? '#adb5bd' : undefined })
    if (no.n.nota) q.texto(cx, cy + r + 30, no.n.nota, { tam: 20, cor: TINTA.roxo, ancora: 'middle' })
    registro[`${c.id}:${no.n.v}`] = { x: cx - r, y: cy - r, w: 2 * r, h: 2 * r }
    delete no.n.__no
  }
  const niveis = Math.max(...nos.map((n) => n.nivel))
  registro[c.id] = { x, y, w: 2 * r + (nos.length - 1) * dx, h: 2 * r + niveis * dy + 30 }
  return registro
}

// grafo: vertices [['A', x, y]] (relativos a c.x, c.y), arestas [['A', 'B', peso?]]
// dirigido: true desenha setas; estados: { A: cor }; marcadas: [['A','B']]
function grafo(q, c) {
  const r = c.raio ?? 36
  const P = Object.fromEntries(c.vertices.map(([v, vx, vy]) => [v, [c.x + vx, c.y + vy]]))
  const registro = {}
  for (const [a, b, peso] of c.arestas) {
    const [x1, y1] = P[a]
    const [x2, y2] = P[b]
    const ang = Math.atan2(y2 - y1, x2 - x1)
    const p1 = [x1 + r * Math.cos(ang), y1 + r * Math.sin(ang)]
    const p2 = [x2 - (r + 4) * Math.cos(ang), y2 - (r + 4) * Math.sin(ang)]
    const marcada = (c.marcadas ?? []).some(([m, n]) => (m === a && n === b) || (!c.dirigido && m === b && n === a))
    const cor = marcada ? TINTA.verde : '#495057'
    if (c.dirigido) q.seta([p1, p2], { cor })
    else q.forma(q.gen.line(...p1, ...p2, q.opcoes({ stroke: cor, strokeWidth: marcada ? 4 : 2.5 })))
    if (peso !== undefined) {
      const mx = (x1 + x2) / 2 + 26 * Math.sin(ang)
      const my = (y1 + y2) / 2 - 26 * Math.cos(ang) + 8
      q.texto(mx, my, String(peso), { tam: 24, cor: CORES.amarelo.texto, ancora: 'middle' })
    }
  }
  for (const [v] of c.vertices) {
    const [cx, cy] = P[v]
    const estado = c.estados?.[v]
    const cor = estado === 'apagado' ? { borda: '#ced4da', fundo: '#f8f9fa' } : (CORES[estado] ?? CORES[c.cor ?? 'azul'])
    q.forma(q.gen.circle(cx, cy, r * 2, q.opcoes({ stroke: cor.borda, fill: cor.fundo, fillStyle: 'solid' })))
    q.texto(cx, cy + 10, v, { tam: 28, ancora: 'middle' })
    if (c.notas?.[v]) q.texto(cx, cy - r - 12, c.notas[v], { tam: 22, cor: TINTA.roxo, ancora: 'middle' })
    registro[`${c.id}:${v}`] = { x: cx - r, y: cy - r, w: 2 * r, h: 2 * r }
  }
  const xs = Object.values(P).map(([a]) => a)
  const ys = Object.values(P).map(([, b]) => b)
  registro[c.id] = { x: Math.min(...xs) - r, y: Math.min(...ys) - r, w: Math.max(...xs) - Math.min(...xs) + 2 * r, h: Math.max(...ys) - Math.min(...ys) + 2 * r }
  return registro
}

// tabela hash: baldes na vertical (índice à esquerda) e a corrente de cada um
// baldes: [[], ['ana'], ['bia', 'caio']] ou, sem corrente, ['', 'ana', '']
function tabela(q, c) {
  const { x, y } = c
  const h = 64
  const wB = c.w ?? 150
  const corrente = c.baldes.some((b) => Array.isArray(b))
  const registro = {}
  c.baldes.forEach((b, i) => {
    const yi = y + i * h
    const estado = c.estados?.[i]
    const cor = CORES[estado] ?? CORES[c.cor ?? 'azul']
    q.texto(x + 30, yi + h / 2 + 8, String(i), { tam: 24, cor: '#868e96', ancora: 'end' })
    q.caixa(x + 44, yi, wB, h, cor, 4)
    registro[`${c.id}:${i}`] = { x: x + 44, y: yi, w: wB, h }
    if (!corrente) {
      q.texto(x + 44 + wB / 2, yi + h / 2 + 10, String(b ?? ''), { tam: 28, ancora: 'middle' })
      return
    }
    if (!b.length) {
      q.texto(x + 44 + wB / 2, yi + h / 2 + 8, 'NULL', { tam: 22, cor: '#adb5bd', ancora: 'middle' })
      return
    }
    let xn = x + 44 + wB + 70
    q.forma(q.gen.circle(x + 44 + wB / 2, yi + h / 2, 10, q.opcoes({ stroke: ESCURO_LOCAL, fill: ESCURO_LOCAL, fillStyle: 'solid', roughness: 0.3 })))
    q.seta([[x + 44 + wB / 2, yi + h / 2], [xn - 6, yi + h / 2]], { cor: ESCURO_LOCAL })
    b.forEach((v, k) => {
      const wn = Math.max(90, largura(v, 26) + 30)
      q.caixa(xn, yi + 8, wn, h - 16, CORES.verde, 8)
      q.texto(xn + wn / 2, yi + h / 2 + 9, String(v), { tam: 26, ancora: 'middle' })
      if (k < b.length - 1) q.seta([[xn + wn, yi + h / 2], [xn + wn + 50, yi + h / 2]], { cor: ESCURO_LOCAL })
      xn += wn + 56
    })
  })
  registro[c.id] = { x, y, w: wB + 44, h: c.baldes.length * h }
  return registro
}

Object.assign(ICONES, { memoria, lista, pilha, arvore, grafo, tabela })
