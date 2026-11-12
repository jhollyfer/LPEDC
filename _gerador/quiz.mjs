// Monta o quiz das provas do PPGI (index.html na raiz) a partir de provas/:
//
//   provas/<slug>.json           questões, alternativas, porquê de cada uma, gabarito
//   provas/<slug>.figuras.json   descrição de cada figura (árvore, árvore B, vetor, hash)
//
// Saída: ../quiz/questoes.js (window.QUESTOES) e ../quiz/figuras/<nome>.svg,
// desenhadas no mesmo quadro dos diagramas do curso (quadro.mjs + icones.mjs).
//
//   node quiz.mjs            gera tudo
//   node quiz.mjs --check    só confere: alternativas com porquê, letra igual à do
//                            PROVAS.md, figura citada existe
import { readFileSync, writeFileSync, readdirSync, mkdirSync, existsSync } from 'node:fs'
import { join, dirname } from 'node:path'
import { fileURLToPath } from 'node:url'
import { createHash } from 'node:crypto'
import { novoQuadro, CORES } from './quadro.mjs'
import { ICONES } from './tipos/icones.mjs'

const AQUI = dirname(fileURLToPath(import.meta.url))
const RAIZ = join(AQUI, '..')
const PROVAS = join(AQUI, 'provas')
const SAIDA = join(RAIZ, 'quiz')
const SO_CONFERIR = process.argv.includes('--check')

// letra de cada questão no PROVAS.md: { '2016-032': { 1: 'anulada', 2: 'C', ... } }
const letrasDoGuia = () => {
  const guia = {}
  let slug = null
  for (const linha of readFileSync(join(RAIZ, 'PROVAS.md'), 'utf8').split('\n')) {
    const edital = linha.match(/^## Edital (\d{3})\/(\d{4})/)
    if (edital) {
      slug = `${edital[2]}-${edital[1]}`
      guia[slug] = {}
      continue
    }
    const linhaTabela = slug && linha.match(/^\| (\d{2}) \| ([^|]*) \|/)
    if (linhaTabela) guia[slug][Number(linhaTabela[1])] = linhaTabela[2].trim()
  }
  return guia
}

// letra do guia no formato do quiz: 'A'..'E', 'anulada' ou null (sem letra)
const normalizar = (letra) => {
  if (/anulada/i.test(letra)) return 'anulada'
  const m = letra.match(/^\**([A-Ea-e])\**$/)
  if (m) return m[1].toUpperCase()
  return null
}

// mapa dos assuntos do curso: '0102' -> { titulo, modulo, ancora, ideia }
// (mesma regra de âncora do GitHub que o gerar.mjs usa)
const ancora = (titulo) =>
  titulo
    .toLowerCase()
    .replace(/[^\p{L}\p{N}\- ]/gu, '')
    .replaceAll(' ', '-')
const mapaAssuntos = () => {
  const mapa = {}
  for (const modulo of readdirSync(RAIZ).filter((a) => /^\d{2}-.*\.md$/.test(a)).sort()) {
    for (const linha of readFileSync(join(RAIZ, modulo), 'utf8').split('\n')) {
      const m = linha.match(/^## (\d{4}) · (.+)$/)
      if (!m) continue
      mapa[m[1]] = {
        titulo: m[2].trim(),
        modulo,
        ancora: ancora(linha.slice(3)),
        ideia: existsSync(join(RAIZ, 'material', `${m[1]}-ideia.svg`)),
      }
    }
  }
  return mapa
}
const ASSUNTOS = mapaAssuntos()

// ---------------------------------------------------------------------------
// figuras
// ---------------------------------------------------------------------------
const MARGEM = 30

function desenharFigura(nome, f) {
  const q = novoQuadro()
  const topo = f.titulo ? 70 : MARGEM
  if (f.titulo) q.texto(MARGEM, 44, f.titulo, { tam: 30, cor: CORES.roxo.texto })
  let caixa
  if (f.tipo === 'arvore') {
    caixa = ICONES.arvore(q, { id: 'a', x: MARGEM, y: topo, raiz: structuredClone(f.raiz), dx: f.dx ?? 90, dy: f.dy ?? 110, estados: f.estados, notaAoLado: true })
    caixa.a.w += 30
    caixa.a.h -= 20
  } else if (f.tipo === 'arvoreB') {
    caixa = ICONES.arvoreB(q, { id: 'a', x: MARGEM, y: topo, raiz: structuredClone(f.raiz) })
  } else if (f.tipo === 'vetor') {
    const itens = f.itens.map((v) => String(v ?? ''))
    caixa = ICONES.array(q, { id: 'a', x: MARGEM, y: topo, itens, celula: f.celula })
  } else if (f.tipo === 'hash') {
    caixa = ICONES.tabela(q, { id: 'a', x: MARGEM + 20, y: topo, baldes: f.baldes })
    const maior = Math.max(...f.baldes.map((b) => (Array.isArray(b) ? b.length : 0)))
    caixa.a.w += maior * 150
  } else if (f.tipo === 'texto') {
    f.linhas.forEach((l, i) => q.texto(MARGEM, topo + 34 + i * 40, l, { tam: 28 }))
    const maior = Math.max(...f.linhas.map((l) => l.length))
    caixa = { a: { x: MARGEM, y: topo, w: maior * 15, h: f.linhas.length * 40 + 10 } }
  } else {
    throw new Error(`${nome}: tipo de figura desconhecido "${f.tipo}"`)
  }
  const largura = Math.max(caixa.a.x + caixa.a.w, f.titulo ? f.titulo.length * 17 + MARGEM : 0) + MARGEM
  const altura = caixa.a.y + caixa.a.h + MARGEM
  return q.svg(f.titulo ?? nome, { x: 0, y: 0, w: Math.ceil(largura), h: Math.ceil(altura) })
}

// ---------------------------------------------------------------------------
// conferência
// ---------------------------------------------------------------------------
function conferir(provas, figuras) {
  const guia = letrasDoGuia()
  const erros = []
  for (const p of provas) {
    const letras = guia[p.slug]
    if (!letras) erros.push(`${p.slug}: edital não está no PROVAS.md`)
    const numeros = p.questoes.map((q) => q.numero)
    if (letras && numeros.length !== Object.keys(letras).length)
      erros.push(`${p.slug}: ${numeros.length} questões, PROVAS.md tem ${Object.keys(letras).length}`)
    for (const q of p.questoes) {
      const id = `${p.slug} Q${String(q.numero).padStart(2, '0')}`
      const esperado = letras && normalizar(letras[q.numero] ?? '')
      if (letras && (q.gabarito ?? null) !== esperado) erros.push(`${id}: gabarito ${q.gabarito}, PROVAS.md diz ${letras[q.numero]}`)
      if (!q.enunciado?.trim()) erros.push(`${id}: sem enunciado`)
      if (!q.resumo?.trim()) erros.push(`${id}: sem resumo`)
      if (!q.dica?.trim()) erros.push(`${id}: sem dica (conceito e exemplo)`)
      for (const [, num] of (q.dica ?? '').matchAll(/\[(\d{4})\]/g))
        if (!ASSUNTOS[num]) erros.push(`${id}: a dica cita [${num}], que não é assunto do curso`)
      const palavras = (q.dica ?? '').replace(/```[\s\S]*?```/g, '').split(/\s+/).filter(Boolean).length
      if (palavras > 110) erros.push(`${id}: dica com ${palavras} palavras (máximo 110)`)
      if (q.dica && !/\[\d{4}\]/.test(q.dica)) erros.push(`${id}: a dica não cita nenhum assunto [NNNN]`)
      for (const [campo, texto] of [['dica', q.dica], ['resumo', q.resumo], ['enunciado', q.enunciado], ...q.alternativas.map((x) => [`porquê ${x.letra}`, x.porque])]) {
        const t = texto ?? ''
        if ((t.match(/```/g) ?? []).length % 2) erros.push(`${id}: ${campo} com bloco de código sem fechar`)
        if (t.split('\n').some((l) => l.includes('```') && !l.trim().startsWith('```'))) erros.push(`${id}: ${campo} com \`\`\` no meio da linha`)
      }
      if (q.alternativas.length < 4) erros.push(`${id}: só ${q.alternativas.length} alternativas`)
      const letrasAlt = q.alternativas.map((a) => a.letra)
      if (/^[A-E]$/.test(q.gabarito ?? '') && !letrasAlt.includes(q.gabarito)) erros.push(`${id}: gabarito fora das alternativas`)
      for (const a of q.alternativas) {
        if (!a.porque?.trim()) erros.push(`${id} ${a.letra}: sem porquê`)
        if (a.figura && !figuras[a.figura]) erros.push(`${id} ${a.letra}: figura ${a.figura} não descrita`)
      }
      for (const f of q.figuras ?? []) if (!figuras[f]) erros.push(`${id}: figura ${f} não descrita`)
      for (const s of q.assuntos ?? []) if (!existsSync(join(RAIZ, s.modulo))) erros.push(`${id}: módulo ${s.modulo} não existe`)
    }
  }
  return erros
}

// ---------------------------------------------------------------------------
// principal
// ---------------------------------------------------------------------------
const arquivos = readdirSync(PROVAS).filter((a) => a.endsWith('.json') && !a.endsWith('.figuras.json')).sort()
const provas = arquivos.map((a) => JSON.parse(readFileSync(join(PROVAS, a), 'utf8')))
const figuras = {}
for (const a of readdirSync(PROVAS).filter((a) => a.endsWith('.figuras.json')))
  Object.assign(figuras, JSON.parse(readFileSync(join(PROVAS, a), 'utf8')))

const erros = conferir(provas, figuras)
for (const e of erros) console.error(`erro: ${e}`)
if (SO_CONFERIR) {
  const total = provas.reduce((t, p) => t + p.questoes.length, 0)
  console.log(`${provas.length} provas, ${total} questões, ${Object.keys(figuras).length} figuras, ${erros.length} erros`)
  process.exit(erros.length ? 1 : 0)
}

mkdirSync(join(SAIDA, 'figuras'), { recursive: true })
for (const [nome, f] of Object.entries(figuras)) writeFileSync(join(SAIDA, 'figuras', `${nome}.svg`), desenharFigura(nome, f))

// recorte original (PNG da prova) de cada questão, para comparar
const originais = (slug, numero) => {
  const pasta = join(RAIZ, 'provas-ppgi-ufam', slug, 'figuras')
  if (!existsSync(pasta)) return []
  const prefixo = `q${String(numero).padStart(2, '0')}-`
  return readdirSync(pasta)
    .filter((a) => a.startsWith(prefixo))
    .sort()
    .map((a) => `provas-ppgi-ufam/${slug}/figuras/${a}`)
}

const dados = provas.map((p) => ({
  edital: p.edital,
  slug: p.slug,
  ano: p.ano,
  oficial: p.oficial,
  questoes: p.questoes.map((q) => ({ ...q, originais: originais(p.slug, q.numero) })),
}))
writeFileSync(
  join(SAIDA, 'questoes.js'),
  `// Gerado por _gerador/quiz.mjs a partir de _gerador/provas/. Não edite à mão.\nwindow.ASSUNTOS = ${JSON.stringify(ASSUNTOS)}\nwindow.PROVAS = ${JSON.stringify(dados, null, 1)}\n`,
)
// versão do questoes.js no index.html, para o navegador não misturar dados novos com cache velho
const versao = createHash('sha1').update(readFileSync(join(SAIDA, 'questoes.js'))).digest('hex').slice(0, 8)
const pagina = join(RAIZ, 'index.html')
writeFileSync(pagina, readFileSync(pagina, 'utf8').replace(/quiz\/questoes\.js\?v=[\w]+/, `quiz/questoes.js?v=${versao}`))
console.log(`quiz/questoes.js: ${dados.length} provas · quiz/figuras: ${Object.keys(figuras).length} svg${erros.length ? ` · ${erros.length} erros` : ''}`)
