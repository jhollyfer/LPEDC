const entidades = { amp: '&', lt: '<', gt: '>', quot: '"', apos: "'", nbsp: ' ' }

export const textoHtml = (html) => html
  .replace(/<[^>]+>/g, '')
  .replace(/&(#x[\da-f]+|#\d+|[a-z]+);/gi, (entidade, chave) => {
    if (chave.startsWith('#x')) return String.fromCodePoint(parseInt(chave.slice(2), 16))
    if (chave.startsWith('#')) return String.fromCodePoint(Number(chave.slice(1)))
    return entidades[chave] ?? entidade
  })
