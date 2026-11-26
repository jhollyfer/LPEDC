// Monta os módulos HTML e os desenhos a partir de modulos/<NN-nome>/.
// Em modulo.html, {{indice}} e {{assuntos}} recebem o índice e os capítulos.
// Cada texto.html guarda o conceito e o exemplo, separados por {{exemplo}}.
//   npm run gerar         livro inteiro
//   npm run gerar -- 03-  só o módulo 03
//   npm run gerar -- 0016 módulo do assunto 0016, redesenhando só a 0016
import { readFileSync, writeFileSync, readdirSync, existsSync } from 'node:fs'
import { join, dirname, posix } from 'node:path'
import { fileURLToPath, pathToFileURL } from 'node:url'
import { desenharIdeia } from './tipos/ideia.mjs'
import { desenharFluxograma } from './tipos/fluxograma.mjs'
import { desenharLegenda } from './tipos/legenda.mjs'
import { marked } from '../conteudo/vendor/marked/lib/marked.esm.js'
import { textoHtml } from './html.mjs'

const AQUI = dirname(fileURLToPath(import.meta.url))
const RAIZ = join(AQUI, '..')
const MAT = join(RAIZ, 'material') // exemplos, exercícios, lista, apoios e desenhos
const filtro = process.argv[2] ?? ''
// arquivos de cada assunto (exemplos, exercícios e .c/.h de apoio), todos na raiz
const ARQUIVOS = JSON.parse(readFileSync(join(AQUI, 'arquivos.json'), 'utf8'))
const assuntoDe = (nome) => Object.keys(ARQUIVOS).find((n) => [...ARQUIVOS[n].A, ...ARQUIVOS[n].E].includes(nome))

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
// exercício (E) com nível, enunciado, dicas e comando
// o .c do exemplo mais os .c de apoio do assunto (NNNN-nome.c); -lm entra quando algum inclui math.h
const comando = (caminho) => {
  const apoio = (ARQUIVOS[assuntoDe(caminho)]?.apoio ?? []).filter((f) => f.endsWith('.c'))
  const fontes = [caminho, ...apoio]
  const matematica = fontes.some((f) => readFileSync(join(MAT, f), 'utf8').includes('math.h'))
  const base = caminho.replace(/\.c$/, '')
  const gcc = `gcc ${fontes.map((f) => `~/LPEDC/material/${f}`).join(' ')} -o ~/LPEDC/material/${base}${matematica ? ' -lm' : ''}`
  return ['```bash', `${gcc} && ~/LPEDC/material/${base}`, '```']
}

// exemplo: a 1ª linha "// A001 · título" é o título, o resto é o código
const exemplo = (caminho, nome) => {
  const [cabeca, ...resto] = readFileSync(join(MAT, caminho), 'utf8').trimEnd().split('\n')
  if (!/^\/\/ A\d{3,4} · /.test(cabeca)) throw new Error(`${caminho}: a 1ª linha precisa ser "// ${nome.replace(/\.c$/, '')} · título"`)
  while (resto[0]?.trim() === '') resto.shift()
  const titulo = cabeca.replace(/^\/\/\s*/, '').replace(/^A\d{3,4}\s*·\s*/, '')
  return [`**Exemplo ${nome.replace(/\.c$/, '')} · ${titulo}**`, '', '```c', ...resto, '```', '', ...comando(caminho)]
}

// exercício: o bloco de comentários do começo do arquivo traz o enunciado
// e as dicas
const exercicio = (caminho, nome) => {
  const todas = readFileSync(join(MAT, caminho), 'utf8').split('\n')
  const fimBloco = todas.findIndex((l) => !l.startsWith('//'))
  const linhas = todas.slice(0, fimBloco < 0 ? todas.length : fimBloco).map((l) => l.replace(/^\/\/ ?/, ''))
  const fim = (rotulo) => {
    const i = linhas.findIndex((l) => l.startsWith(rotulo))
    return i < 0 ? linhas.length : i
  }
  const iCabeca = linhas.findIndex((l) => /^Exercício [EP]\d{3,4}/.test(l))
  if (iCabeca < 0) throw new Error(`${caminho}: falta a linha "// Exercício ${nome.replace(/\.c$/, '')} · ★☆☆"`)
  const [, nivel = '', ...resto] = linhas[iCabeca].split(' · ')
  const tituloEx = resto.join(' · ')
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
  // compacto: título, enunciado e a resposta esperada; as outras dicas ficam só no .c.
  // "Resposta esperada: a saída acima." repete o enunciado e também sai.
  // cada dica numerada pode continuar nas linhas seguintes (com recuo): junta antes
  const itens = []
  for (const l of dicas) {
    if (/^\d+\. /.test(l.trim())) itens.push(l.trim())
    else if (l.trim() && itens.length) itens[itens.length - 1] += ` ${l.trim()}`
  }
  const resposta = itens
    .map((l) => l.match(/^\d+\. Resposta esperada: (.+)$/)?.[1])
    .filter((r) => r && !/^(a saída( esperada)?|a tabela|as \S+ linhas) acima\.$/.test(r))
    .map((r) => r.replace(/^(a saída( esperada)?|a tabela|as \S+ linhas) acima\. /, ''))
  // o comando só aparece quando o exercício precisa de arquivo de apoio ou de -lm
  const apoio = (ARQUIVOS[assuntoDe(caminho)]?.apoio ?? []).some((f) => f.endsWith('.c'))
  const matematica = todas.some((l) => l.includes('math.h'))
  return [
    `**Exercício ${nome.replace(/\.c$/, '')}**${nivel ? ` · ${nivel}` : ''}${tituloEx ? ` · ${tituloEx}` : ''}`,
    '',
    ...corpo.join('\n').trim().split('\n'),
    // a resposta só entra quando acrescenta algo à saída que o enunciado já mostra
    ...resposta.filter((r) => !corpo.join('\n').includes(r.replace(/\.$/, ''))).map((r) => `\n**Resposta esperada:** ${r}`),
    ...(apoio || matematica ? ['', ...comando(caminho)] : []),
  ]
}

// exemplos (A) e exercícios (E) de um assunto
const exemplosDoAssunto = (pasta) => ARQUIVOS[pasta.slice(0, 4)].A.map((a) => exemplo(a, a).join('\n')).join('\n\n')
const exerciciosDoAssunto = (pasta) => ARQUIVOS[pasta.slice(0, 4)].E.map((a) => exercicio(a, a).join('\n')).join('\n\n')

// Lista prática do módulo: material/P????.c vira a seção "Lista do módulo",
// depois do último assunto.
const lista = (modulo) => {
  const numero = modulo.slice(0, 2)
  const arquivos = readdirSync(MAT)
    .filter((a) => new RegExp(`^P${numero}\\d{2}\\.c$`).test(a))
    .sort((a, b) => a.localeCompare(b, 'en', { numeric: true }))
  if (!arquivos.length) return null
  const niveis = [['★☆☆', 'Aquecimento'], ['★★☆', 'Para pensar'], ['★★★', 'Desafio']]
  const blocos = arquivos.map((a) => exercicio(a, a))
  const partes = [
    '## Lista do módulo',
    '',
    `${arquivos.length} exercícios que misturam os assuntos do módulo, no ritmo da prova. Arquivos ${arquivos[0]} a ${arquivos.at(-1)}, em \`material/\`; resoluções em \`_respostas/${modulo}/lista/\`.`,
  ]
  for (const [estrelas, nomeNivel] of niveis) {
    const doNivel = blocos.filter((md) => md[0].includes(estrelas))
    if (!doNivel.length) continue
    partes.push('', `### ${estrelas} ${nomeNivel}`, '', doNivel.map((md) => md.join('\n')).join('\n\n---\n\n'))
  }
  return partes.join('\n') + '\n'
}

const pastaModulos = join(AQUI, 'modulos')

// Rota do jogo: a ordem de estudo, com os módulos bônus (★) no ponto em que destravam
const FASES = JSON.parse(readFileSync(join(AQUI, 'fases.json'), 'utf8'))
const tituloDoModulo = (m) => textoHtml(readFileSync(join(pastaModulos, m, 'modulo.html'), 'utf8').match(/<h1>(.*?)<\/h1>/)[1])
const mapaDaFase = (modulo, assuntos, qtdLista) => {
  const i = FASES.findIndex((f) => f.modulo === modulo)
  if (i < 0) return ''
  const f = FASES[i]
  const link = (x) => `[${tituloDoModulo(x.modulo)}](${x.modulo}.html)`
  const ordem = `Rota do jogo: etapa ${i + 1} de ${FASES.length}${f.bonus ? ' · módulo bônus ★' : ''}`
  const numeros = assuntos.map((a) => a.slice(0, 4))
  const lista = qtdLista ? `${modulo.slice(0, 2).padStart(2, '0')}01 a ${modulo.slice(0, 2)}${String(qtdLista).padStart(2, '0')}` : null
  return [
    '> [!IMPORTANT]',
    `> **${f.mundo} · ${ordem}**`,
    '>',
    `> **Missão:** ${f.missao}.`,
    '>',
    `> **Vem de:** ${i ? link(FASES[i - 1]) : 'o começo da rota'}. **Segue para:** ${i < FASES.length - 1 ? link(FASES[i + 1]) : 'a prova: simulados e provas antigas'}.`,
    '>',
    '> **Checkpoints desta fase:**',
    `> - [ ] Ler os assuntos ${numeros[0]} a ${numeros.at(-1)} e refazer os exemplos`,
    '> - [ ] Resolver os 4 exercícios de cada assunto, escrevendo o código sozinho',
    lista ? `> - [ ] Fechar a lista prática (P${lista.replace(' a ', ' a P')})` : null,
    '> - [ ] Enfrentar os desafios do módulo',
    '> - [ ] Chefão: resolver as questões de prova do módulo sem consultar',
    '',
  ].filter((l) => l !== null).join('\n')
}
for (const modulo of readdirSync(pastaModulos).filter((n) => /^\d{2}-/.test(n)).sort()) {
  const origem = join(pastaModulos, modulo)
  const assuntos = readdirSync(origem)
    .filter((n) => /^\d{4}-/.test(n))
    .sort()
  // com filtro, só entra o módulo que tem o filtro no nome ou em algum assunto
  // "10-" ou "10-analise" escolhe o módulo pelo começo do nome; "0016" escolhe pelo assunto
  const porModulo = /^\d{2}-/.test(filtro)
  const doModulo = porModulo ? modulo.startsWith(filtro) : !filtro
  if (filtro && !doModulo && (porModulo || !assuntos.some((a) => a.includes(filtro)))) continue
  const desenharTudo = doModulo
  const indice = []
  const capitulos = []

  for (const pasta of assuntos) {
    if (!ARQUIVOS[pasta.slice(0, 4)]) throw new Error(`assunto ${pasta} não está em arquivos.json`)
    const texto = readFileSync(join(origem, pasta, 'texto.html'), 'utf8').trim()
    const cabecalho = texto.match(/^<h2>(.*?)<\/h2>/)
    if (!cabecalho) throw new Error(`${pasta}/texto.html precisa começar pelo título do assunto`)
    const titulo = textoHtml(cabecalho[1])
    const [numero, assunto] = titulo.split(' · ')
    const { ideia, fluxograma } = await import(pathToFileURL(join(origem, pasta, 'desenhos.mjs')))

    const svgIdeia = desenharIdeia(`Ideia: ${assunto}`, ideia)
    const svgFluxo = desenharFluxograma(`Fluxograma: ${assunto}`, fluxograma)
    if (desenharTudo || pasta.includes(filtro)) {
      writeFileSync(join(MAT, `${pasta.slice(0, 4)}-ideia.svg`), svgIdeia)
      writeFileSync(join(MAT, `${pasta.slice(0, 4)}-fluxograma.svg`), svgFluxo)
      console.log(`ok  ${pasta.slice(0, 4)}-ideia.svg e fluxograma.svg`)
    }

    indice.push(`| [${numero}](#${ancora(titulo)}) | ${assunto.replaceAll('|', '\\|')} |`)
    const divisor = '<p>{{exemplo}}</p>'
    if (!texto.includes(divisor)) throw new Error(`${pasta}/texto.html precisa do marcador {{exemplo}}`)
    const corpo = texto.slice(cabecalho[0].length)
      .replace(/<h3>(Passo a passo.*?)<\/h3>/g, '<h4>$1</h4>')
      .replace('<p>{{pratique}}</p>', '')
      .replace('<p>{{ideia}}</p>', () => imagem(`material/${numero}-ideia.svg`, `Diagrama da ideia: ${assunto}`, svgIdeia))
      .replace('<p>{{fluxograma}}</p>', () => imagem(`material/${numero}-fluxograma.svg`, `Fluxograma: ${assunto}`, svgFluxo))
    const [conceito, trabalhado] = corpo.split(divisor).map((parte) => parte.trim())
    capitulos.push([
      cabecalho[0],
      '<h3>Conceito</h3>', conceito,
      '<h3>Exemplos de uso</h3>', trabalhado, marked.parse(exemplosDoAssunto(pasta)).trimEnd(),
      '<h3>Exercícios</h3>', marked.parse(exerciciosDoAssunto(pasta)).trimEnd(),
    ].join('\n'))
  }

  const secaoLista = lista(modulo)
  const nota = '> [!NOTE]\n> Cada assunto é um capítulo: **Conceito** (a explicação), **Exemplos de uso** (programas que compilam sozinhos: rode com o comando abaixo de cada um e compare com a saída no fim do código) e **Exercícios** (cada um é um arquivo em `material/` com o esqueleto, as dicas e o espaço para a resposta; resoluções em `_respostas/' + modulo + '/`).'
  const partes = [marked.parse(nota).trimEnd(), capitulos.join('\n<hr>\n')]
  if (secaoLista) partes.push('<hr>', marked.parse(secaoLista).trimEnd())
  const qtdLista = Number(secaoLista?.match(/^(\d+) exercícios/m)?.[1] ?? 0)
  const texto = readFileSync(join(origem, 'modulo.html'), 'utf8')
    .replace('<p>{{indice}}</p>', () => marked.parse(['| # | Assunto |', '| --- | --- |', ...indice].join('\n')).trimEnd())
    .replace('<p>{{assuntos}}</p>', () => partes.join('\n'))
    .replace(/^(<h1>.*?<\/h1>\n)/, (titulo) => titulo + marked.parse(mapaDaFase(modulo, assuntos, qtdLista)))
  const aviso = `<!-- Gerado por _gerador. Para mudar este arquivo, edite _gerador/modulos/${modulo}/ e rode: cd _gerador && npm run gerar -->`
  writeFileSync(join(RAIZ, `${modulo}.html`), aviso + texto)
  console.log(`ok  ${modulo}.html`)
}
writeFileSync(join(MAT, 'legenda.svg'), desenharLegenda())

// Sumário do livro: a rota do jogo (fases.json), mundo por mundo, cada módulo
// com seus assuntos e o link direto para o capítulo. Fica entre os marcadores
// <!-- sumario:inicio --> e <!-- sumario:fim -->.
const sumario = () => {
  const linhas = []
  let mundo = ''
  FASES.forEach((f, i) => {
    if (f.mundo !== mundo) {
      mundo = f.mundo
      linhas.push(`### ${mundo}`, '')
    }
    const pasta = join(pastaModulos, f.modulo)
    linhas.push(`**${i + 1}. [${tituloDoModulo(f.modulo)}](${f.modulo}.html)**${f.bonus ? ' ★' : ''}: ${f.missao}.`, '')
    for (const a of readdirSync(pasta).filter((n) => /^\d{4}-/.test(n)).sort()) {
      const titulo = textoHtml(readFileSync(join(pasta, a, 'texto.html'), 'utf8').match(/<h2>(.*?)<\/h2>/)[1])
      linhas.push(`- [${titulo}](${f.modulo}.html#${ancora(titulo)})`)
    }
    linhas.push('')
  })
  return linhas.join('\n').trimEnd()
}
const readme = join(RAIZ, 'README.html')
const textoReadme = readFileSync(readme, 'utf8')
if (textoReadme.includes('<!-- sumario:inicio -->')) {
  writeFileSync(readme, textoReadme.replace(/<!-- sumario:inicio -->[\s\S]*<!-- sumario:fim -->/, () => `<!-- sumario:inicio -->\n${marked.parse(sumario())}<!-- sumario:fim -->`))
  console.log('ok  README.html (sumário)')
}
