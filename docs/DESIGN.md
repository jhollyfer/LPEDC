# Desenhos do curso

**LPEDC** · o diagrama da ideia e o fluxograma de cada assunto

> A legenda de cores para quem estuda está no `README.md` ("As cores e as formas") e em
> `legenda.svg`. Este arquivo é para quem escreve os desenhos.

```js
import { bifurcacao, fileira } from '../../../tipos/ideia.mjs' // opcional
export const ideia = { caixas: [...], setas: [...], notas: [...] }
export const fluxograma = { nos: [[id, tipo, texto]], setas: [[de, para, rotulo?]], caminho: [ids] }
```

- Cores: **azul** dado que entra ou sai, **roxo** o programa faz algo,
  **amarelo** pergunta, **verde** caminho seguido e resultado, **cinza** o que o
  exemplo não usa, **vermelho** erro.
- Fluxograma: tipos `inicio`, `io`, `proc`, `dec`. Marque `caminho` com o
  trajeto do exemplo do texto. Mantenha de 4 a 10 nós.
- Diagrama da ideia: **desenhe o conceito, não o código**. Peças prontas (use
  `forma`) em `_gerador/tipos/icones.mjs`:
  - `caixinha` `{ nome, valor, tipo, end? }`: uma variável (end = endereço)
  - `array` `{ nome?, itens, estados? }`: gavetas com índice
  - `memoria` `{ celulas: [{ end, nome, valor, tipo, cor }], ponteiros: [[de, para]], titulo }`: a RAM
  - `lista` `{ itens, cabeca: 'inicio', dupla?, circular?, estados?, rotulos? }`: lista encadeada
  - `pilha` `{ itens (de baixo p/ cima, item pode ser array de linhas), topo?, titulo? }`: pilha / pilha de chamadas
  - `arvore` `{ raiz: { v, e, d, nota? }, estados: { valor: cor }, marcadas: [[pai, filho]] }`
  - `grafo` `{ vertices: [[nome, x, y]], arestas: [[a, b, peso?]], dirigido?, estados, marcadas, notas }`
  - `tabela` `{ baldes: [[], ['ana'], ['bia', 'caio']] }`: hash com encadeamento
  - `terminal`, `arquivo`, `balao`, `pessoa`, `cardapio`, `marca`
  - caixas comuns `{ id, x, y, w?, h?, cor, rotulo?, texto: [linhas] }` e `forma: 'losango'`
- Coordenadas: o quadro tem ~1600 px de largura útil (x de 100 a 1500).
- Depois de gerar, **olhe o desenho**: `cd _gerador && node ver.mjs
  ../01-fundamentos/0002-variaveis/ideia.svg` gera um PNG em `/tmp/lpedc-ver/`;
  abra o PNG com a ferramenta Read e confira sobreposição, texto cortado e
  setas. Ajuste as coordenadas até ficar limpo.
