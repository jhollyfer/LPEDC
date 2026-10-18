// Converte SVGs em PNG para conferir os desenhos (usa o Chromium do Playwright).
//   node ver.mjs ../01-fundamentos/0007-variaveis/ideia.svg [outro.svg ...]
// O PNG sai em /tmp/lpedc-ver/<pasta>-<nome>.png
import { createRequire } from 'node:module'
import { execSync } from 'node:child_process'
import { mkdirSync, readFileSync } from 'node:fs'
import { resolve, basename, dirname } from 'node:path'

const require = createRequire(import.meta.url)
const raizGlobal = execSync('npm root -g').toString().trim()
const { chromium } = require(`${raizGlobal}/playwright`)

const saida = '/tmp/lpedc-ver'
mkdirSync(saida, { recursive: true })
const browser = await chromium.launch()
const page = await browser.newPage()
for (const arq of process.argv.slice(2)) {
  const svg = readFileSync(arq, 'utf8')
  const w = Number(svg.match(/width="([\d.]+)"/)[1])
  const h = Number(svg.match(/height="([\d.]+)"/)[1])
  await page.setViewportSize({ width: Math.ceil(w), height: Math.ceil(h) })
  await page.setContent(`<html><body style="margin:0">${svg}</body></html>`)
  await page.waitForTimeout(150)
  const destino = `${saida}/${basename(dirname(resolve(arq)))}-${basename(arq, '.svg')}.png`
  await page.screenshot({ path: destino })
  console.log(destino)
}
await browser.close()
