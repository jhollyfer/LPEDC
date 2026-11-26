import { execFileSync } from 'node:child_process'
import { readFileSync, writeFileSync } from 'node:fs'

const raiz = new URL('../', import.meta.url)
const destino = new URL('conteudo/arquivos.json', raiz)
const caminhos = execFileSync('git', ['ls-files', '-z', '--', '*.md'], { cwd: raiz, encoding: 'utf8' })
  .split('\0').filter(Boolean)
const arquivos = caminhos.map((caminho) => {
  const markdown = readFileSync(new URL(caminho.split('/').map(encodeURIComponent).join('/'), raiz), 'utf8')
  const titulo = markdown.match(/^#{1,6} +(.+)$/m)?.[1] ?? caminho
  return [caminho, titulo.replaceAll('`', '')]
})
const indice = `${JSON.stringify(arquivos, null, 2)}\n`

if (process.argv.includes('--check')) {
  if (readFileSync(destino, 'utf8') !== indice) {
    console.error('Índice desatualizado. Rode node _gerador/conteudo.mjs.')
    process.exitCode = 1
  } else {
    console.log(`${arquivos.length} arquivos Markdown no índice`)
  }
} else {
  writeFileSync(destino, indice)
}
