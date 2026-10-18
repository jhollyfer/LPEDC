export const ideia = {
  caixas: [
    { id: 's1', forma: 'caixinha', x: 100, y: 20, w: 280, nome: 'saldo', valor: '20.00', tipo: 'início', cor: 'cinza' },
    { id: 's2', forma: 'caixinha', x: 760, y: 20, w: 280, nome: 'saldo', valor: '50.00', tipo: 'depois da recarga', cor: 'cinza' },
    { id: 's3', forma: 'caixinha', x: 760, y: 420, w: 280, nome: 'saldo', valor: '45.60', tipo: '1ª viagem', cor: 'cinza' },
    { id: 's4', forma: 'caixinha', x: 100, y: 420, w: 280, nome: 'saldo', valor: '41.20', tipo: '2ª viagem', cor: 'verde' },
    { id: 'v', forma: 'caixinha', x: 1180, y: 420, w: 260, nome: 'viagens', valor: '0 → 1 → 2', tipo: 'viagens++ duas vezes' },
  ],
  setas: [
    { de: 's1', para: 's2', rotulo: 'saldo += 30.00' },
    { de: 's2', para: 's3', rotulo: 'saldo -= 4.40' },
    { de: 's3', para: 's4', rotulo: 'saldo -= 4.40' },
  ],
  notas: [{ x: 100, y: 700, texto: 'é sempre a mesma caixinha: cada valor novo apaga o anterior', cor: 'roxo' }],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'proc', 'saldo = 20.00; viagens = 0'],
    ['C', 'proc', 'saldo += 30.00'],
    ['D', 'proc', 'saldo -= 4.40; viagens++'],
    ['E', 'proc', 'saldo -= 4.40; viagens++'],
    ['F', 'io', 'Mostrar saldo e viagens'],
    ['G', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D'],
    ['D', 'E'],
    ['E', 'F'],
    ['F', 'G'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'F', 'G'],
}
