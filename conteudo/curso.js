(() => {
  'use strict'

  const PREFIXO = '#conteudo'
  const SUMARIO = 'README.md'
  const RAIZ = new URL('.', location.href)
  const GRUPOS = new Map([
    ['.', 'Material de estudo'],
    ['provas-ppgi-ufam', 'Cadernos do PPGI'],
    ['_fontes', 'Bibliografia e fichamentos'],
    ['docs', 'Documentação do projeto'],
    ['_gerador', 'Arquivos-fonte dos módulos'],
  ])
  const AVISOS = {
    NOTE: 'Nota', TIP: 'Dica', IMPORTANT: 'Importante', WARNING: 'Atenção', CAUTION: 'Cuidado',
  }

  class Curso {
    constructor() {
      this.quiz = document.getElementById('app')
      this.pagina = document.getElementById('curso')
      this.artigo = this.pagina.querySelector('article')
      this.link = document.querySelector('.link-curso')
      this.tituloOriginal = document.title
      this.paginaAberta = ''
      window.addEventListener('hashchange', () => this.atualizar())
      this.atualizar()
    }

    codificarCaminho(caminho) {
      return caminho.split('/').map(encodeURIComponent).join('/')
    }

    rota(caminho, ancora = '') {
      let rota = PREFIXO
      if (caminho !== SUMARIO) rota += `/${this.codificarCaminho(caminho.slice(0, -3))}`
      if (ancora) rota += `#${encodeURIComponent(ancora)}`
      return rota
    }

    linkDoArquivo(caminho, titulo) {
      const link = document.createElement('a')
      link.href = this.rota(caminho)
      link.textContent = titulo
      return link
    }

    mensagem(titulo, texto) {
      const cabecalho = document.createElement('h1')
      cabecalho.textContent = titulo
      const paragrafo = document.createElement('p')
      paragrafo.textContent = texto
      this.artigo.replaceChildren(cabecalho, paragrafo)
    }

    async obter(url, signal) {
      const resposta = await fetch(url, { signal })
      if (!resposta.ok) throw new Error(`HTTP ${resposta.status}`)
      return resposta
    }

    async atualizar() {
      const hash = location.hash
      const noCurso = hash === PREFIXO || hash.startsWith(`${PREFIXO}/`) || hash.startsWith(`${PREFIXO}#`)
      this.quiz.hidden = noCurso
      this.pagina.hidden = !noCurso
      this.link.hidden = !noCurso && Boolean(hash)
      if (noCurso) this.link.setAttribute('aria-current', 'location')
      else this.link.removeAttribute('aria-current')
      this.pedido?.abort()
      if (!noCurso) {
        document.title = this.tituloOriginal
        return
      }

      const [rota, fragmento = ''] = hash.slice(PREFIXO.length).split('#')
      const pedido = new AbortController()
      this.pedido = pedido
      try {
        let caminho = SUMARIO
        if (rota && rota !== '/') caminho = `${decodeURIComponent(rota.slice(1))}.md`
        const ancora = decodeURIComponent(fragmento)
        const catalogo = rota === '/arquivos'
        this.pagina.querySelectorAll('nav a').forEach((link) => {
          if (link.hash === `${PREFIXO}${rota}`) link.setAttribute('aria-current', 'page')
          else link.removeAttribute('aria-current')
        })

        if (this.paginaAberta !== caminho) {
          this.paginaAberta = ''
          this.mensagem('Curso', 'Carregando…')
          document.title = 'Curso · LPEDC'
          if (location.protocol === 'file:') {
            this.mensagem('Curso', 'Abra o site para ler os arquivos Markdown.')
            const site = document.createElement('a')
            site.href = `https://jhollyfer.github.io/LPEDC/${hash}`
            site.textContent = 'Abrir no GitHub Pages'
            this.artigo.append(site)
            return
          }

          if (!this.arquivos) {
            const resposta = await this.obter(new URL('conteudo/arquivos.json', RAIZ), pedido.signal)
            this.arquivos = new Map(await resposta.json())
          }
          if (pedido.signal.aborted) return
          if (catalogo) this.mostrarCatalogo()
          else if (this.arquivos.has(caminho)) await this.mostrarArquivo(caminho, pedido.signal)
          else {
            this.mensagem('Arquivo não encontrado', 'Escolha um arquivo no sumário ou na lista completa.')
            return
          }
          if (pedido.signal.aborted) return
          this.paginaAberta = caminho
        }

        document.title = catalogo ? 'Todos os arquivos · LPEDC' : this.arquivos.get(caminho)
        const alvo = document.getElementById(`curso-secao-${ancora}`)
        if (alvo) {
          alvo.focus({ preventScroll: true })
          alvo.scrollIntoView()
        } else {
          const titulo = this.artigo.querySelector('h1')
          titulo.focus({ preventScroll: true })
          window.scrollTo(0, 0)
        }
      } catch {
        if (pedido.signal.aborted) return
        this.paginaAberta = ''
        this.mensagem('Não foi possível abrir o arquivo', 'Tente recarregar a página ou escolha outro arquivo.')
      }
    }

    mostrarCatalogo() {
      const titulo = document.createElement('h1')
      titulo.textContent = 'Todos os arquivos'
      titulo.tabIndex = -1
      const grupos = new Map()

      for (const [caminho, nome] of this.arquivos) {
        let pasta = '.'
        if (caminho.includes('/')) pasta = caminho.split('/')[0]
        if (!grupos.has(pasta)) grupos.set(pasta, document.createElement('ul'))
        const item = document.createElement('li')
        item.append(this.linkDoArquivo(caminho, nome))
        const rotulo = document.createElement('small')
        rotulo.textContent = caminho
        item.append(rotulo)
        grupos.get(pasta).append(item)
      }

      this.artigo.replaceChildren(titulo)
      const ordem = new Set([...GRUPOS.keys(), ...grupos.keys()])
      for (const pasta of ordem) {
        if (!grupos.has(pasta)) continue
        const grupo = document.createElement('details')
        grupo.open = pasta === '.'
        grupo.className = 'curso-grupo'
        const rotulo = document.createElement('summary')
        rotulo.textContent = GRUPOS.get(pasta) ?? pasta
        grupo.append(rotulo, grupos.get(pasta))
        this.artigo.append(grupo)
      }
    }

    async mostrarArquivo(caminho, signal) {
      const url = new URL(this.codificarCaminho(caminho), RAIZ)
      const [resposta, { marked }, { default: purify }, { default: Slugger }] = await Promise.all([
        this.obter(url, signal),
        import('./vendor/marked/lib/marked.esm.js'),
        import('./vendor/dompurify/dist/purify.es.js'),
        import('./vendor/github-slugger/index.js'),
      ])
      const markdown = await resposta.text()
      if (signal.aborted) return

      const conteudo = purify.sanitize(marked.parse(markdown), {
        USE_PROFILES: { html: true },
        FORBID_ATTR: ['id', 'name', 'style'],
        RETURN_DOM_FRAGMENT: true,
      })
      const slugger = new Slugger()
      const titulos = conteudo.querySelectorAll('h1, h2, h3, h4, h5, h6')
      for (const titulo of titulos) {
        titulo.id = `curso-secao-${slugger.slug(titulo.textContent)}`
        titulo.tabIndex = -1
      }
      if (!conteudo.querySelector('h1')) {
        const titulo = document.createElement('h1')
        titulo.tabIndex = -1
        if (titulos[0] && titulos[0] === conteudo.firstElementChild) {
          titulo.id = titulos[0].id
          titulo.append(...titulos[0].childNodes)
          titulos[0].replaceWith(titulo)
        } else {
          titulo.textContent = this.arquivos.get(caminho)
          conteudo.prepend(titulo)
        }
      }

      for (const link of conteudo.querySelectorAll('a[href]')) {
        this.ajustarLink(link, url)
      }
      for (const imagem of conteudo.querySelectorAll('img[src]')) {
        const origem = imagem.getAttribute('src')
        let base = url
        // Os módulos-fonte apontam para as figuras a partir da raiz, como os módulos gerados.
        if (caminho.startsWith('_gerador/modulos/') && origem.startsWith('_fontes/')) base = RAIZ
        imagem.src = new URL(origem, base)
        imagem.loading = 'lazy'
      }
      for (const tabela of conteudo.querySelectorAll('table')) {
        const caixa = document.createElement('div')
        caixa.className = 'curso-tabela'
        caixa.tabIndex = 0
        tabela.replaceWith(caixa)
        caixa.append(tabela)
      }
      for (const bloco of conteudo.querySelectorAll('blockquote')) {
        const texto = bloco.firstElementChild?.firstChild
        const aviso = texto?.textContent.match(/^\[!(NOTE|TIP|IMPORTANT|WARNING|CAUTION)\]\s*/)
        if (!aviso || texto.nodeType !== Node.TEXT_NODE) continue
        texto.textContent = texto.textContent.slice(aviso[0].length)
        bloco.classList.add('curso-aviso')
        const rotulo = document.createElement('strong')
        rotulo.textContent = AVISOS[aviso[1]]
        bloco.prepend(rotulo)
      }

      this.artigo.replaceChildren(conteudo)
    }

    ajustarLink(link, base) {
      const destino = new URL(link.getAttribute('href'), base)
      if (destino.origin === RAIZ.origin && destino.pathname.startsWith(RAIZ.pathname)) {
        const caminho = decodeURIComponent(destino.pathname.slice(RAIZ.pathname.length))
        if (this.arquivos.has(caminho)) {
          link.href = this.rota(caminho, decodeURIComponent(destino.hash.slice(1)))
          return
        }
      }
      link.href = destino
    }
  }

  new Curso()
})()
