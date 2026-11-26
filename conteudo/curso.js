(() => {
  'use strict'

  const PREFIXO = '#conteudo'
  const PREFACIO = 'README'
  const ACERVO = 'arquivos'
  const RAIZ = new URL('.', location.href)
  const GRUPOS = new Map([
    ['.', 'Livro e guias'],
    ['provas-ppgi-ufam', 'Cadernos do PPGI'],
    ['_fontes', 'Bibliografia e fichamentos'],
    ['docs', 'Documentação do projeto'],
    ['_gerador', 'Fontes dos módulos'],
  ])
  const AVISOS = {
    NOTE: 'Nota', TIP: 'Dica', IMPORTANT: 'Importante', WARNING: 'Atenção', CAUTION: 'Cuidado',
  }

  class Livro {
    constructor() {
      this.quiz = document.getElementById('app')
      this.pagina = document.getElementById('curso')
      this.artigo = this.pagina.querySelector('article')
      this.caminho = this.pagina.querySelector('.livro-caminho')
      this.paginacao = this.pagina.querySelector('.livro-paginacao')
      this.sumario = this.pagina.querySelector('.livro-sumario')
      this.menu = this.sumario.querySelector('nav')
      this.linkCurso = document.querySelector('.link-curso')
      this.tituloOriginal = document.title
      this.telaLarga = matchMedia('(min-width: 850px)')
      this.sumario.open = this.telaLarga.matches
      this.telaLarga.addEventListener('change', (evento) => { this.sumario.open = evento.matches })
      this.menu.addEventListener('click', (evento) => {
        if (!this.telaLarga.matches && evento.target.closest('a')) this.sumario.open = false
      })
      window.addEventListener('hashchange', () => this.atualizar())
      this.atualizar()
    }

    elemento(tag, texto, classe) {
      const elemento = document.createElement(tag)
      if (texto) elemento.textContent = texto
      if (classe) elemento.className = classe
      return elemento
    }

    codificar(caminho) {
      return caminho.split('/').map(encodeURIComponent).join('/')
    }

    rota(caminho, ancora = '') {
      let rota = PREFIXO
      if (caminho !== PREFACIO) rota += `/${this.codificar(caminho)}`
      if (ancora) rota += `#${encodeURIComponent(ancora)}`
      return rota
    }

    link(caminho, titulo, ancora = '') {
      const link = this.elemento('a', titulo)
      link.href = this.rota(caminho, ancora)
      return link
    }

    mensagem(titulo, texto) {
      this.artigo.replaceChildren(this.elemento('h1', titulo), this.elemento('p', texto))
      this.paginacao.hidden = true
    }

    async obter(url, signal) {
      const resposta = await fetch(new URL(url, RAIZ), { signal })
      if (!resposta.ok) throw new Error(`HTTP ${resposta.status}`)
      return resposta
    }

    async atualizar() {
      const hash = location.hash
      const lendo = hash === PREFIXO || hash.startsWith(`${PREFIXO}/`) || hash.startsWith(`${PREFIXO}#`)
      this.quiz.hidden = lendo
      this.pagina.hidden = !lendo
      this.linkCurso.hidden = !lendo && Boolean(hash)
      if (lendo) this.linkCurso.setAttribute('aria-current', 'location')
      else this.linkCurso.removeAttribute('aria-current')
      this.pedido?.abort()
      if (!lendo) {
        document.title = this.tituloOriginal
        return
      }

      const pedido = new AbortController()
      this.pedido = pedido
      try {
        const [rota, fragmento = ''] = hash.slice(PREFIXO.length).split('#')
        const ancora = decodeURIComponent(fragmento)
        let caminho = PREFACIO
        if (rota && rota !== '/') caminho = decodeURIComponent(rota.slice(1)).replace(/\.(html|md)$/i, '')
        if (location.protocol === 'file:') {
          this.mensagem('Livro LPEDC', 'Abra o site para ler o livro.')
          const site = this.elemento('a', 'Abrir no GitHub Pages')
          site.href = `https://jhollyfer.github.io/LPEDC/${hash}`
          this.artigo.append(site)
          return
        }
        if (!this.arquivos) {
          this.mensagem('Livro LPEDC', 'Carregando o sumário…')
          const resposta = await this.obter('conteudo/arquivos.json', pedido.signal)
          const indice = await resposta.json()
          if (pedido.signal.aborted) return
          this.prepararSumario(indice)
        }
        if (caminho === ACERVO) {
          this.mostrarAcervo()
          this.mostrarNavegacao(caminho)
          this.posicionar()
          return
        }
        if (!Object.hasOwn(this.arquivos, caminho)) {
          this.mostrarNavegacao(caminho)
          this.mensagem('Página não encontrada', 'Escolha um capítulo no sumário ou um texto no acervo.')
          return
        }

        if (this.documento?.caminho !== caminho) {
          this.mensagem('Livro LPEDC', 'Carregando a página…')
          const paginas = await this.carregar(caminho, pedido.signal)
          if (pedido.signal.aborted) return
          this.documento = { caminho, paginas }
        }
        const paginas = this.documento.paginas
        let secao = ''
        if (ancora) {
          for (const [nome, pagina] of paginas) {
            if (!pagina.getElementById(`curso-secao-${ancora}`)) continue
            secao = nome
            break
          }
        }
        this.mostrarPagina(caminho, secao, paginas.get(secao))
        this.mostrarNavegacao(caminho, secao)
        this.posicionar(ancora, secao)
      } catch {
        if (pedido.signal.aborted) return
        this.mensagem('Não foi possível abrir a página', 'Tente recarregar a página ou escolha outro capítulo.')
      }
    }

    prepararSumario({ arquivos, partes }) {
      this.arquivos = arquivos
      this.modulos = new Map()
      this.linksDoMenu = new Map()
      this.ordem = [{ caminho: PREFACIO, titulo: 'Prefácio', ancora: '' }]
      const prefacio = this.link(PREFACIO, 'Prefácio')
      this.linksDoMenu.set(prefacio.hash, prefacio)
      this.menu.replaceChildren(prefacio)

      for (const [indice, [nome, modulos]] of partes.entries()) {
        const parte = this.elemento('details', '', 'livro-parte')
        parte.append(this.elemento('summary', `Parte ${indice + 1} · ${nome}`))
        const lista = this.elemento('ul')
        for (const [caminho, secoes] of modulos) {
          const titulo = arquivos[caminho].replace(/^Módulo /, '')
          const modulo = this.link(caminho, titulo)
          const item = this.elemento('li')
          const capitulos = this.elemento('ul', '', 'livro-capitulos')
          capitulos.hidden = true
          this.modulos.set(caminho, { nome, parte, capitulos, titulo })
          this.ordem.push({ caminho, titulo, ancora: '' })
          this.linksDoMenu.set(modulo.hash, modulo)
          for (const [ancora, capitulo] of secoes) {
            const link = this.link(caminho, capitulo, ancora)
            const linha = this.elemento('li')
            linha.append(link)
            capitulos.append(linha)
            this.ordem.push({ caminho, titulo: capitulo, ancora })
            this.linksDoMenu.set(link.hash, link)
          }
          item.append(modulo, capitulos)
          lista.append(item)
        }
        parte.append(lista)
        this.menu.append(parte)
      }
      const apendices = this.elemento('ul', '', 'livro-apendices')
      for (const [caminho, titulo] of [['PPGI', 'Guia do PPGI'], ['TRILHA', 'Trilha de estudo'], ['PROVAS', 'Provas comentadas'], ['SIMULADOS', 'Simulados'], [ACERVO, 'Acervo completo']]) {
        const link = this.link(caminho, titulo)
        const item = this.elemento('li')
        item.append(link)
        apendices.append(item)
        this.linksDoMenu.set(link.hash, link)
      }
      this.menu.append(apendices)
      this.posicoes = new Map(this.ordem.map(({ caminho, ancora }, indice) => [this.rota(caminho, ancora), indice]))
    }

    mostrarNavegacao(caminho, secao = '') {
      this.linkAtivo?.removeAttribute('aria-current')
      this.linkAtivo = this.linksDoMenu.get(this.rota(caminho, secao))
      this.linkAtivo?.setAttribute('aria-current', 'page')
      if (this.moduloAtivo) this.moduloAtivo.capitulos.hidden = true
      this.moduloAtivo = this.modulos.get(caminho)
      if (this.moduloAtivo) {
        this.moduloAtivo.parte.open = true
        this.moduloAtivo.capitulos.hidden = false
      }

      this.caminho.replaceChildren(this.link(PREFACIO, 'Livro'))
      if (this.moduloAtivo) this.caminho.append(this.elemento('span', this.moduloAtivo.nome))
      if (secao) this.caminho.append(this.link(caminho, this.moduloAtivo.titulo))
      else if (caminho === ACERVO) this.caminho.append(this.elemento('span', 'Acervo'))
      else if (caminho !== PREFACIO && !this.moduloAtivo) this.caminho.append(this.elemento('span', this.arquivos[caminho]))

      const indice = this.posicoes.get(this.rota(caminho, secao))
      this.paginacao.replaceChildren()
      this.paginacao.hidden = indice === undefined
      if (indice === undefined) return
      for (const [vizinho, rotulo, classe] of [[this.ordem[indice - 1], 'Anterior', 'anterior'], [this.ordem[indice + 1], 'Seguinte', 'seguinte']]) {
        if (!vizinho) continue
        const link = this.link(vizinho.caminho, '', vizinho.ancora)
        link.className = classe
        link.append(this.elemento('span', rotulo), this.elemento('strong', vizinho.titulo))
        this.paginacao.append(link)
      }
    }

    mostrarAcervo() {
      const titulo = this.elemento('h1', 'Acervo do livro')
      const grupos = new Map()
      for (const [caminho, nome] of Object.entries(this.arquivos)) {
        let pasta = '.'
        if (caminho.includes('/')) pasta = caminho.split('/')[0]
        if (!grupos.has(pasta)) grupos.set(pasta, this.elemento('ul'))
        const item = this.elemento('li')
        item.append(this.link(caminho, nome), this.elemento('small', caminho))
        grupos.get(pasta).append(item)
      }
      this.artigo.replaceChildren(titulo)
      for (const pasta of new Set([...GRUPOS.keys(), ...grupos.keys()])) {
        if (!grupos.has(pasta)) continue
        const grupo = this.elemento('details', '', 'curso-grupo')
        grupo.open = pasta === '.'
        grupo.append(this.elemento('summary', GRUPOS.get(pasta) ?? pasta), grupos.get(pasta))
        this.artigo.append(grupo)
      }
      document.title = 'Acervo · LPEDC'
    }

    async carregar(caminho, signal) {
      const url = `${this.codificar(caminho)}.html`
      const [resposta, { default: purify }, { default: Slugger }] = await Promise.all([
        this.obter(url, signal),
        import('./vendor/dompurify/dist/purify.es.js'),
        import('./vendor/github-slugger/index.js'),
      ])
      const html = await resposta.text()
      if (signal.aborted) return
      const conteudo = purify.sanitize(html, {
        USE_PROFILES: { html: true },
        FORBID_ATTR: ['id', 'name', 'style'],
        RETURN_DOM_FRAGMENT: true,
      })
      const slugger = new Slugger()
      for (const titulo of conteudo.querySelectorAll('h1, h2, h3, h4, h5, h6')) {
        titulo.id = `curso-secao-${slugger.slug(titulo.textContent)}`
        titulo.tabIndex = -1
      }
      this.prepararConteudo(conteudo, caminho, url)
      const paginas = new Map([['', document.createDocumentFragment()]])
      let pagina = ''
      for (const no of [...conteudo.childNodes]) {
        if (this.modulos.has(caminho) && no.nodeName === 'H2' && (pagina || /^\d{4} · /.test(no.textContent))) {
          pagina = no.id.slice('curso-secao-'.length)
          paginas.set(pagina, document.createDocumentFragment())
        }
        paginas.get(pagina).append(no)
      }
      return paginas
    }

    prepararConteudo(conteudo, caminho, url) {
      const base = new URL(url, RAIZ)
      for (const link of conteudo.querySelectorAll('a[href]')) {
        const destino = new URL(link.getAttribute('href'), base)
        const interno = destino.origin === RAIZ.origin && destino.pathname.startsWith(RAIZ.pathname)
        if (interno) {
          const arquivo = decodeURIComponent(destino.pathname.slice(RAIZ.pathname.length)).replace(/\.(html|md)$/i, '')
          if (Object.hasOwn(this.arquivos, arquivo)) {
            link.href = this.rota(arquivo, decodeURIComponent(destino.hash.slice(1)))
            continue
          }
        }
        link.href = destino
      }
      for (const imagem of conteudo.querySelectorAll('img[src]')) {
        const origem = imagem.getAttribute('src')
        let pasta = base
        if (caminho.startsWith('_gerador/modulos/') && origem.startsWith('_fontes/')) pasta = RAIZ
        imagem.src = new URL(origem, pasta)
        imagem.loading = 'lazy'
      }
      for (const tabela of conteudo.querySelectorAll('table')) {
        const caixa = this.elemento('div', '', 'curso-tabela')
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
        bloco.prepend(this.elemento('strong', AVISOS[aviso[1]]))
      }
    }

    mostrarPagina(caminho, secao, pagina) {
      const conteudo = pagina.cloneNode(true)
      let titulo = conteudo.querySelector('h1')
      if (!titulo) {
        titulo = this.elemento('h1')
        const cabecalho = conteudo.firstElementChild
        if (cabecalho && /^H[2-6]$/.test(cabecalho.tagName)) {
          titulo.id = cabecalho.id
          titulo.append(...cabecalho.childNodes)
          cabecalho.replaceWith(titulo)
        } else {
          titulo.textContent = this.arquivos[caminho]
          conteudo.prepend(titulo)
        }
      }
      if (caminho === PREFACIO) {
        const capa = this.elemento('header', '', 'livro-capa')
        const subtitulo = titulo.nextElementSibling
        titulo.before(capa)
        const acoes = this.elemento('div', '', 'livro-acoes')
        const comecar = this.ordem[1]
        acoes.append(this.link(comecar.caminho, 'Começar a leitura'), this.link(PREFACIO, 'Ver sumário', 'sumário'))
        capa.append(titulo)
        if (subtitulo?.tagName === 'P') capa.append(subtitulo)
        capa.append(acoes)
      }

      this.artigo.replaceChildren(conteudo)
      document.title = secao ? `${titulo.textContent} · LPEDC` : this.arquivos[caminho]
    }

    posicionar(ancora = '', secao = '') {
      const alvo = document.getElementById(`curso-secao-${ancora}`)
      const titulo = this.artigo.querySelector('h1')
      const foco = alvo ?? titulo
      foco.tabIndex = -1
      foco.focus({ preventScroll: true })
      if (alvo && ancora !== secao) alvo.scrollIntoView()
      else window.scrollTo(0, 0)
    }
  }

  new Livro()
})()
