export const ideia = {
  caixas: [
    { id: 't', forma: 'terminal', x: 100, y: 20, w: 600, texto: ['$ gastos novo luz 98.75', '$ gastos lista', '$ gastos exporta g.csv'] },
    { id: 'm', x: 840, y: 30, w: 560, h: 190, cor: 'roxo', rotulo: 'main(argc, argv)', texto: ['argv[1] escolhe:', 'novo | lista | exporta'] },
    { id: 'd', forma: 'arquivo', x: 560, y: 400, w: 440, nome: 'gastos.dat (binário)', texto: ['3 registros', 'de 32 bytes'], cor: 'azul' },
    { id: 'c', forma: 'arquivo', x: 1140, y: 400, w: 360, nome: 'g.csv (texto)', texto: ['categoria;valor', 'mercado;152.40', 'luz;98.75'], cor: 'verde' },
    { id: 'o', forma: 'terminal', x: 100, y: 700, w: 560, texto: ['0  mercado  R$ 152.40', '1  luz      R$  98.75', 'Total: R$ 296.45 ...'] },
  ],
  setas: [
    { de: 't', para: 'm', rotulo: 'argv' },
    { pontos: [[900, 236], [900, 384]], rotulo: 'novo: fwrite' },
    { de: 'd', para: 'c', rotulo: 'exporta' },
    { de: 'd', para: 'o', lados: 'bd', cotovelo: true, rotulo: 'lista: fread' },
  ],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início: gastos lista'],
    ['B', 'dec', 'argc >= 2?'],
    ['C', 'dec', 'argv[1] é "novo"?'],
    ['D', 'proc', 'fopen "ab" e fwrite'],
    ['E', 'dec', 'argv[1] é "lista"?'],
    ['F', 'proc', 'fread até devolver 0'],
    ['G', 'io', 'Mostrar gastos e total'],
    ['H', 'io', 'Uso em stderr'],
    ['I', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C', 'Sim'],
    ['B', 'H', 'Não'],
    ['C', 'D', 'Sim'],
    ['C', 'E', 'Não'],
    ['E', 'F', 'Sim'],
    ['E', 'H', 'Não'],
    ['F', 'G'],
    ['D', 'I'],
    ['G', 'I'],
    ['H', 'I'],
  ],
  caminho: ['A', 'B', 'C', 'E', 'F', 'G', 'I'],
}
