import { execFileSync } from 'node:child_process'
import { existsSync, readFileSync, writeFileSync } from 'node:fs'
import Slugger from '../conteudo/vendor/github-slugger/index.js'
import { marked } from '../conteudo/vendor/marked/lib/marked.esm.js'
import { textoHtml } from './html.mjs'

const raiz = new URL('../', import.meta.url)
const destino = new URL('conteudo/arquivos.json', raiz)
const fases = JSON.parse(readFileSync(new URL('fases.json', import.meta.url), 'utf8'))
const caminhos = execFileSync('git', ['ls-files', '-z', '--cached', '--others', '--exclude-standard', '--', '*.md'], {
  cwd: raiz, encoding: 'utf8',
}).split('\0').filter(Boolean)
const arquivos = {}
const secoes = new Map()
const modulos = new Set(fases.map((fase) => fase.modulo))

for (const caminho of [...new Set(caminhos)].sort()) {
  const fonte = new URL(caminho.split('/').map(encodeURIComponent).join('/'), raiz)
  if (!existsSync(fonte)) continue
  const html = marked.parse(readFileSync(fonte, 'utf8'))
  const rota = caminho.slice(0, -3)
  const titulos = [...html.matchAll(/<h([1-6])>(.*?)<\/h\1>/gs)]
  arquivos[rota] = titulos.length ? textoHtml(titulos[0][2]) : rota
  if (!modulos.has(rota)) continue

  const slugger = new Slugger()
  const capitulos = []
  for (const [, nivel, corpo] of titulos) {
    const titulo = textoHtml(corpo)
    const ancora = slugger.slug(titulo)
    if (nivel === '2' && (capitulos.length || /^\d{4} · /.test(titulo))) capitulos.push([ancora, titulo])
  }
  if (!capitulos.length) throw new Error(`Módulo sem capítulos: ${caminho}`)
  secoes.set(rota, capitulos)
}

const partes = new Map()
for (const { mundo, modulo } of fases) {
  if (!secoes.has(modulo)) throw new Error(`Módulo ausente: ${modulo}`)
  const nome = mundo.replace(/^Mundo \d+ · /, '')
  if (!partes.has(nome)) partes.set(nome, [])
  partes.get(nome).push([modulo, secoes.get(modulo)])
}

const indice = `${JSON.stringify({ arquivos, partes: [...partes] }, null, 2)}\n`
if (process.argv.includes('--check')) {
  if (readFileSync(destino, 'utf8') !== indice) {
    console.error('Sumário desatualizado. Rode node _gerador/conteudo.mjs.')
    process.exitCode = 1
  } else {
    const capitulos = [...secoes.values()].flat().filter(([, titulo]) => /^\d{4} · /.test(titulo))
    console.log(`${Object.keys(arquivos).length} documentos, ${modulos.size} módulos, ${capitulos.length} capítulos`)
  }
} else {
  writeFileSync(destino, indice)
}
