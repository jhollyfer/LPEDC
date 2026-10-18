// Gera o README de cada módulo e os desenhos de cada assunto, tudo a partir de
// modulos/<NN-nome>/:
//
//   modulos/01-fundamentos/modulo.md                 começo e fim do README do módulo
//   modulos/01-fundamentos/0007-.../texto.md         o texto do assunto
//   modulos/01-fundamentos/0007-.../desenhos.mjs     o diagrama da ideia e o fluxograma
//
// Saída: 01-fundamentos/README.md, legenda.svg (na raiz) e, em cada pasta de
// assunto, ideia.svg e fluxograma.svg.
//
//   npm run gerar            tudo
//   npm run gerar -- 03-     só o módulo 03 (README e desenhos)
//   npm run gerar -- 0016    só o módulo do assunto 0016, redesenhando só a 0016
//
// No texto.md, {{ideia}}, {{fluxograma}} e {{pratique}} viram a imagem ou o
// rodapé do assunto. No modulo.md, {{indice}} e {{assuntos}} viram a lista e os
// assuntos.
import { readFileSync, writeFileSync, readdirSync, existsSync } from 'node:fs'
import { join, dirname } from 'node:path'
import { fileURLToPath, pathToFileURL } from 'node:url'
import { desenharIdeia } from './tipos/ideia.mjs'
import { desenharFluxograma } from './tipos/fluxograma.mjs'
import { desenharLegenda } from './tipos/legenda.mjs'

const AQUI = dirname(fileURLToPath(import.meta.url))
const RAIZ = join(AQUI, '..')
const filtro = process.argv[2] ?? ''

// mesma regra do GitHub para o link de um título
const ancora = (titulo) =>
  titulo
    .toLowerCase()
    .replace(/[^\p{L}\p{N}\- ]/gu, '')
    .replaceAll(' ', '-')

// todas as imagens na mesma escala, para a letra ter o mesmo tamanho em todas
const ESCALA = 0.58
const imagem = (src, alt, svg) => {
  const largura = Number(svg.match(/width="(\d+(?:\.\d+)?)"/)[1])
  return `<p align="center"><img src="${src}" alt="${alt}" width="${Math.round(largura * ESCALA)}"></p>`
}

// "Hora de praticar": cada exemplo (A) com título, código e comando; cada
// exercício (E) com nível, enunciado, dicas (escondidas) e comando
const comando = (caminho) => ['```bash', `~/LPEDC/rodar ${caminho}`, '```']

// exemplo: a 1ª linha "// A001 · título" é o título, o resto é o código
const exemplo = (caminho, nome) => {
  const [cabeca, ...resto] = readFileSync(join(RAIZ, caminho), 'utf8').trimEnd().split('\n')
  if (!/^\/\/ A\d{3} · /.test(cabeca)) throw new Error(`${caminho}: a 1ª linha precisa ser "// ${nome.slice(0, 4)} · título"`)
  while (resto[0]?.trim() === '') resto.shift()
  const titulo = cabeca.replace(/^\/\/\s*/, '').replace(/^A\d{3}\s*·\s*/, '')
  return [`**Exemplo ${nome.slice(0, 4)} · ${titulo}**`, '', '```c', ...resto, '```', '', ...comando(caminho)]
}

// exercício: o bloco de comentários do começo do arquivo traz o enunciado
// e as dicas
const exercicio = (caminho, nome) => {
  const todas = readFileSync(join(RAIZ, caminho), 'utf8').split('\n')
  const fimBloco = todas.findIndex((l) => !l.startsWith('//'))
  const linhas = todas.slice(0, fimBloco < 0 ? todas.length : fimBloco).map((l) => l.replace(/^\/\/ ?/, ''))
  const fim = (rotulo) => {
    const i = linhas.findIndex((l) => l.startsWith(rotulo))
    return i < 0 ? linhas.length : i
  }
  const iCabeca = linhas.findIndex((l) => /^Exercício E\d{3}/.test(l))
  if (iCabeca < 0) throw new Error(`${caminho}: falta a linha "// Exercício ${nome.slice(0, 4)} · ★☆☆"`)
  const nivel = linhas[iCabeca].split(' · ')[1] ?? ''
  const fimEnunciado = Math.min(fim('Dicas:'), fim('Escreva sua resposta'))
  const enunciado = linhas.slice(iCabeca + 1, fimEnunciado)
  const dicas = linhas.slice(fim('Dicas:') + 1, fim('Escreva sua resposta'))
  // linhas com recuo de 2 espaços no enunciado são código ou saída: viram um bloco
  const corpo = []
  for (const l of enunciado) {
    const codigo = l.startsWith('  ')
    if (codigo && corpo.at(-1) !== 'CODIGO') corpo.push('', '```text', 'CODIGO')
    if (!codigo && corpo.at(-1) === 'CODIGO') corpo.splice(-1, 1, '```', '')
    if (codigo) corpo.splice(-1, 0, l.slice(2))
    else corpo.push(l)
  }
  if (corpo.at(-1) === 'CODIGO') corpo.splice(-1, 1, '```')
  const listaDicas = dicas.filter((l) => l.trim())
  return [
    `**Exercício ${nome.slice(0, 4)}**${nivel ? ` · ${nivel}` : ''}`,
    '',
    ...corpo.join('\n').trim().split('\n'),
    '',
    ...(listaDicas.length
      ? ['<details>', '<summary>Dicas</summary>', '', ...listaDicas, '', '</details>', '']
      : []),
    ...comando(caminho),
  ]
}

const pratique = (modulo, pasta) => {
  const arquivos = readdirSync(join(RAIZ, modulo, pasta)).sort()
  const exemplos = arquivos.filter((a) => /^A\d{3}\.c$/.test(a))
  const exercicios = arquivos.filter((a) => /^E\d{3}\.c$/.test(a))
  return [
    '### Hora de praticar',
    '',
    `Os arquivos ficam em [\`${pasta}/\`](${pasta}/). Os comandos funcionam de qualquer pasta do terminal. Nos exemplos, rode, mude, quebre e rode de novo. Nos exercícios, a resposta vai dentro do próprio arquivo. ★☆☆ é aquecimento, ★★☆ pede raciocínio e ★★★ é desafio.`,
    '',
    exemplos.map((a) => exemplo(`${modulo}/${pasta}/${a}`, a).join('\n')).join('\n\n'),
    '',
    '#### Exercícios',
    '',
    exercicios.map((a) => exercicio(`${modulo}/${pasta}/${a}`, a).join('\n')).join('\n\n'),
  ].join('\n')
}

const pastaModulos = join(AQUI, 'modulos')
for (const modulo of readdirSync(pastaModulos).filter((n) => /^\d{2}-/.test(n)).sort()) {
  const origem = join(pastaModulos, modulo)
  const destino = join(RAIZ, modulo)
  const assuntos = readdirSync(origem)
    .filter((n) => /^\d{4}-/.test(n))
    .sort()
  // com filtro, só entra o módulo que tem o filtro no nome ou em algum assunto
  if (filtro && !modulo.includes(filtro) && !assuntos.some((a) => a.includes(filtro))) continue
  const desenharTudo = modulo.includes(filtro)
  const indice = []
  const partes = []

  for (const pasta of assuntos) {
    if (!existsSync(join(destino, pasta))) throw new Error(`pasta ${modulo}/${pasta} não encontrada`)
    const texto = readFileSync(join(origem, pasta, 'texto.md'), 'utf8').trim()
    const titulo = texto.match(/^## (.+)$/m)?.[1]
    if (!titulo) throw new Error(`${pasta}/texto.md precisa começar com "## título"`)
    const [numero, assunto] = titulo.split(' · ')
    const { ideia, fluxograma } = await import(pathToFileURL(join(origem, pasta, 'desenhos.mjs')))

    const svgIdeia = desenharIdeia(`Ideia: ${assunto}`, ideia)
    const svgFluxo = desenharFluxograma(`Fluxograma: ${assunto}`, fluxograma)
    if (desenharTudo || pasta.includes(filtro)) {
      writeFileSync(join(destino, pasta, 'ideia.svg'), svgIdeia)
      writeFileSync(join(destino, pasta, 'fluxograma.svg'), svgFluxo)
      console.log(`ok  ${modulo}/${pasta}/ideia.svg e fluxograma.svg`)
    }

    indice.push(`| [${numero}](#${ancora(titulo)}) | ${assunto.replaceAll('|', '\\|')} | [\`${pasta}/\`](${pasta}/) |`)
    partes.push(
      texto
        .replace('{{ideia}}', () => imagem(`${pasta}/ideia.svg`, `Diagrama da ideia: ${assunto}`, svgIdeia))
        .replace('{{fluxograma}}', () => imagem(`${pasta}/fluxograma.svg`, `Fluxograma: ${assunto}`, svgFluxo))
        .replace('{{pratique}}', () => pratique(modulo, pasta)),
    )
  }

  const texto = readFileSync(join(origem, 'modulo.md'), 'utf8')
    .replace('{{indice}}', () => ['| # | Assunto | Pasta |', '| --- | --- | --- |', ...indice].join('\n'))
    .replace('{{assuntos}}', () => partes.join('\n\n---\n\n'))
  const aviso = `<!-- Gerado por _gerador. Para mudar este arquivo, edite _gerador/modulos/${modulo}/ e rode: cd _gerador && npm run gerar -->\n\n`
  writeFileSync(join(destino, 'README.md'), aviso + texto)
  console.log(`ok  ${modulo}/README.md`)
}
writeFileSync(join(RAIZ, 'legenda.svg'), desenharLegenda())
