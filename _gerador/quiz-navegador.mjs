// Abre as 210 questões do quiz no celular (iPhone 13, 390px) e no desktop (1440px) e acusa:
// página mais larga que a tela, markdown cru (** ou ```) fora de código e erro de script.
//   node quiz-navegador.mjs        (usa o Chromium do Playwright, como o ver.mjs)
import { createRequire } from 'node:module'
import { execSync } from 'node:child_process'
import { join, dirname } from 'node:path'
import { fileURLToPath, pathToFileURL } from 'node:url'

const require = createRequire(import.meta.url)
const { chromium, devices } = require(`${execSync('npm root -g').toString().trim()}/playwright`)
const pagina = pathToFileURL(join(dirname(fileURLToPath(import.meta.url)), '..', 'index.html')).href

const browser = await chromium.launch()
let falhas = 0
for (const [nome, opcoes] of [['390px', devices['iPhone 13']], ['1440px', { viewport: { width: 1440, height: 900 } }]]) {
  const ctx = await browser.newContext(opcoes)
  const page = await ctx.newPage()
  const erros = []
  page.on('pageerror', (e) => erros.push(e.message))
  await page.route(/fonts\.(googleapis|gstatic)/, (r) => r.abort())
  await page.goto(pagina)
  const ids = await page.evaluate(() => window.PROVAS.flatMap((p) => p.questoes.map((q) => `${p.slug}-q${String(q.numero).padStart(2, '0')}`)))
  const ruins = []
  for (const id of ids) {
    await page.evaluate((h) => { location.hash = h }, `q/${id}`)
    await page.waitForSelector('.alternativas')
    const r = await page.evaluate(() => {
      const texto = [...document.querySelectorAll('.antes, .enunciado, .alternativas')].map((e) => {
        const c = e.cloneNode(true)
        c.querySelectorAll('code, pre').forEach((x) => x.remove())
        return c.innerText
      }).join('\n')
      return { largo: document.documentElement.scrollWidth > innerWidth + 1, cru: /\*\*|```/.test(texto) }
    })
    if (r.largo || r.cru) ruins.push(`${id}${r.largo ? ' mais larga que a tela' : ''}${r.cru ? ' markdown cru' : ''}`)
  }
  // a trilha: a escada inteira aberta, sem página mais larga que a tela
  await page.evaluate(() => { location.hash = 'trilha' })
  await page.waitForSelector('.degraus')
  await page.evaluate(() => document.querySelectorAll('.degrau details').forEach((d) => { d.open = true }))
  const trilha = await page.evaluate(() => ({ largo: document.documentElement.scrollWidth > innerWidth + 1, degraus: document.querySelectorAll('.degrau').length }))
  if (trilha.largo) ruins.push('trilha mais larga que a tela')
  if (trilha.degraus !== await page.evaluate(() => window.TRILHA.length)) ruins.push(`trilha com ${trilha.degraus} degraus`)
  console.log(`${nome}: ${ids.length} questões + trilha, ${ruins.length} com problema, ${erros.length} erros de script`)
  for (const x of [...ruins, ...erros]) console.log(`  ${x}`)
  falhas += ruins.length + erros.length
  await ctx.close()
}
await browser.close()
process.exit(falhas ? 1 : 0)
