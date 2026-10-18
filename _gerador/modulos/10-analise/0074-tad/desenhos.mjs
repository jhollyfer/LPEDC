// Em cima, os três arquivos: o cliente e a implementação incluem o mesmo
// contrato. Embaixo, a memória: o cliente só tem o ponteiro; os campos moram
// num bloco do heap que só o contador.c sabe abrir.
export const ideia = {
  caixas: [
    { id: 'cli', forma: 'arquivo', x: 100, y: 40, w: 360, cor: 'azul', nome: 'cliente (main)', texto: ['contador_cria(3)', 'contador_incrementa', 'contador_libera'] },
    { id: 'h', forma: 'arquivo', x: 620, y: 40, w: 380, cor: 'verde', nome: 'contador.h · contrato', texto: ['typedef struct', '  contador Contador;', '+ 7 protótipos'] },
    { id: 'c', forma: 'arquivo', x: 1160, y: 40, w: 340, cor: 'roxo', nome: 'contador.c · oculto', texto: ['struct contador {', '  int valor;', '  int limite;', '};'] },
    { id: 'p', forma: 'caixinha', x: 100, y: 400, nome: 'vagas', valor: '0x5a10', tipo: 'Contador *', w: 300 },
    { id: 'heap', x: 620, y: 440, w: 380, h: 190, cor: 'roxo', rotulo: 'no heap (0x5a10)', texto: ['valor = 3', 'limite = 3'] },
    { id: 'erro', x: 1160, y: 440, w: 340, h: 190, cor: 'vermelho', rotulo: 'no cliente', texto: ['vagas->valor = 0;', 'não compila'] },
  ],
  setas: [
    { de: 'cli', para: 'h', rotulo: '#include' },
    { de: 'c', para: 'h', rotulo: '#include' },
    { de: 'p', para: 'heap', rotulo: 'aponta' },
  ],
  notas: [{ x: 810, y: 680, texto: 'só o contador.c abre este bloco', cor: 'cinza', ancora: 'middle' }],
}

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'proc', 'vagas = contador_cria(3)'],
    ['C', 'io', 'Chega um carro'],
    ['D', 'dec', 'contador_incrementa deu true?'],
    ['E', 'io', 'Mostrar "entrou (n/3)"'],
    ['F', 'io', 'Mostrar "lotado, espere"'],
    ['G', 'dec', 'Mais carros?'],
    ['H', 'proc', 'contador_libera(vagas)'],
    ['I', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D'],
    ['D', 'E', 'Sim'],
    ['D', 'F', 'Não'],
    ['E', 'G'],
    ['F', 'G'],
    ['G', 'C', 'Sim'],
    ['G', 'H', 'Não'],
    ['H', 'I'],
  ],
  caminho: ['A', 'B', 'C', 'D', 'E', 'G', 'C', 'D', 'F', 'G', 'H', 'I'],
}
