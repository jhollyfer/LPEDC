# LPEDC · guia para escrever o conteúdo

Curso pessoal de **Lógica de Programação, Linguagem C e Estrutura de Dados**, em
português do Brasil. Mesma filosofia do LPPOO (github.com/jhollyfer/LPPOO), mas
organizado por **módulos** em vez de datas.

Quem estuda: um dev adulto que já programa em TypeScript (React + Vite,
Node + Fastify, AdonisJS) e quer **relembrar lógica**, **aprender estrutura de
dados** e **entender de verdade como o C e a memória funcionam**. Não é aula
para turma: o texto fala com "você", direto, sem infantilizar. Pode comparar
com JS/TS quando ajudar ("no JS o array cresce sozinho; no C, não").

O sumário completo (módulos, assuntos e números) está em
[`_fontes/sumario.md`](_fontes/sumario.md). Os fichamentos dos livros estão em
`_fontes/*.md`.

## Onde fica cada coisa

```
LPEDC/
├── rodar                      compila (gcc + AddressSanitizer) e roda um .c
├── legenda.svg                formas e cores (gerado)
├── 01-fundamentos/            SAÍDA: o que a pessoa estuda
│   ├── README.md              gerado: o módulo inteiro
│   └── 0007-variaveis/
│       ├── ideia.svg          gerado
│       ├── fluxograma.svg     gerado
│       ├── A013.c  A014.c     exemplos resolvidos
│       └── E037.c ... E042.c  exercícios (a resposta vai dentro do arquivo)
├── _respostas/01-fundamentos/E037.c ...   uma resolução de cada exercício
├── _gerador/modulos/01-fundamentos/       FONTE do README e dos desenhos
│   ├── modulo.md              começo e fim do README ({{indice}}, {{assuntos}})
│   └── 0007-variaveis/
│       ├── texto.md           o texto do assunto ({{ideia}}, {{fluxograma}}, {{pratique}})
│       └── desenhos.mjs       export const ideia e fluxograma
└── _fontes/                   sumário e fichamentos dos livros
```

Gerar: `cd _gerador && npm run gerar -- 01-` (só o módulo 01). Nunca edite o
`README.md` de um módulo à mão: ele é sobrescrito.

## Numeração (fixa, não mude)

Assunto `N` (ex.: 0007 → N = 7):

- exemplos: `A(2N-1)` e `A(2N)` → 0007 tem `A013.c` e `A014.c`
- exercícios: `E(6N-5)` até `E(6N)` → 0007 tem `E037.c` até `E042.c`

Sempre 3 dígitos. Sempre 2 exemplos e 6 exercícios por assunto.

## Cada assunto (texto.md)

Um assunto conta **um exemplo só**, em quatro partes que batem entre si: texto,
diagrama da ideia, código e fluxograma, com o **mesmo cenário e os mesmos
valores**. Roteiro:

1. `## 0007 · Variáveis` (título curto).
2. **Gancho**: uma situação do dia a dia (feira, ônibus, conta de luz,
   mercado, Pix, academia, futebol...). Cenários brasileiros, valores em R$.
3. O conceito em parágrafos curtos (2 a 4 linhas cada). Termos novos em
   **negrito**. Código inline com crase.
4. "Vamos ver na prática..." e o parágrafo termina apontando para o desenho →
   `{{ideia}}`.
5. O código do mesmo exemplo, em bloco ```` ```c ````, completo e compilável,
   com a saída em comentário (`// Saída: ...`).
6. Um parágrafo que puxa o fluxograma ("Repara no fluxograma: ...") →
   `{{fluxograma}}`.
7. `> [!WARNING]` com a pegadinha principal (o erro que todo mundo comete).
8. `> [!TIP]` começando com **Por dentro do C:** — o que acontece por baixo:
   memória, bytes, endereços, o que o compilador faz, custo. É a marca do curso
   (no LPPOO era o "Poder do TypeScript"). No módulo 00 e nos assuntos de
   estrutura de dados também vale: "Por dentro do C" mostra a memória.
9. `> [!NOTE]` com **Pergunta para você:** algo para prever antes de rodar.
10. `{{pratique}}` (gerado: exemplos e exercícios).

Tamanho: o texto de um assunto (sem o pratique) tem entre 60 e 140 linhas.
Assunto difícil (ponteiros, recursão, árvores) pode ter uma seção extra
`### Passo a passo` com um teste de mesa em tabela markdown.

Estilo de escrita: frases curtas, voz ativa, sem enrolação, sem emoji, sem
"Neste assunto veremos". Explique o **porquê**, não só o como.

## Desenhos (desenhos.mjs)

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
  - `caixinha` `{ nome, valor, tipo, end? }` — uma variável (end = endereço)
  - `array` `{ nome?, itens, estados? }` — gavetas com índice
  - `memoria` `{ celulas: [{ end, nome, valor, tipo, cor }], ponteiros: [[de, para]], titulo }` — a RAM
  - `lista` `{ itens, cabeca: 'inicio', dupla?, circular?, estados?, rotulos? }` — lista encadeada
  - `pilha` `{ itens (de baixo p/ cima, item pode ser array de linhas), topo?, titulo? }` — pilha / pilha de chamadas
  - `arvore` `{ raiz: { v, e, d, nota? }, estados: { valor: cor }, marcadas: [[pai, filho]] }`
  - `grafo` `{ vertices: [[nome, x, y]], arestas: [[a, b, peso?]], dirigido?, estados, marcadas, notas }`
  - `tabela` `{ baldes: [[], ['ana'], ['bia', 'caio']] }` — hash com encadeamento
  - `terminal`, `arquivo`, `balao`, `pessoa`, `cardapio`, `marca`
  - caixas comuns `{ id, x, y, w?, h?, cor, rotulo?, texto: [linhas] }` e `forma: 'losango'`
- Coordenadas: o quadro tem ~1600 px de largura útil (x de 100 a 1500).
- Depois de gerar, **olhe o desenho**: `cd _gerador && node ver.mjs
  ../01-fundamentos/0007-variaveis/ideia.svg` gera um PNG em `/tmp/lpedc-ver/`;
  abra o PNG com a ferramenta Read e confira sobreposição, texto cortado e
  setas. Ajuste as coordenadas até ficar limpo.

## Exemplos (A013.c)

```c
// A013 · A idade na caixinha

#include <stdio.h>

int main(void) {
    int idade = 25; // a caixinha "idade" guarda 25

    printf("Idade: %d\n", idade); // Idade: 25
    return 0;
}
```

- 1ª linha: `// A013 · título curto` (o gerador exige esse formato).
- C17 padrão, `int main(void)`, `return 0;`, 4 espaços de recuo, nomes em
  português sem acento em `snake_case`, comentários curtos em português.
- Prefira valores fixos (saída previsível). Quando ler do teclado, mostre no
  comentário um exemplo de interação: `// Digite a idade: 25`.
- **Obrigatório**: compila sem nenhum warning com `./rodar` (que usa
  `-std=c17 -Wall -Wextra -pedantic -fsanitize=address,undefined`) e roda sem
  erro do sanitizer (sem vazamento). A saída nos comentários tem que ser a
  saída real: rode e confira. Para ler entrada no teste, use
  `printf '25\n' | ./rodar caminho.c`.
- Os dois exemplos do assunto: o primeiro é o exemplo do texto (ou bem
  próximo); o segundo mostra outra faceta do mesmo conceito.

## Exercícios (E037.c)

```c
// 0007 · Variáveis
// Exercício E037 · ★☆☆
//
// Enunciado claro, com cenário e valores concretos. Linhas com 2 espaços de
// recuo viram bloco de código/saída no README:
//
//   Saída esperada:
//   Produto: Arroz
//   Preço: R$ 25.90
//
// Dicas:
// 1. Primeira dica, a mais leve.
// 2. Segunda dica.
// 3. Resposta esperada: ...
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
```

- O bloco de comentários do topo é lido pelo gerador até a primeira linha que
  não começa com `//`. Respeite as linhas `Exercício E037 · ★☆☆`, `Dicas:` e
  `Escreva sua resposta abaixo:`.
- Dificuldade dos 6: **E1 e E2 ★☆☆** (aplicar direto), **E3 e E4 ★★☆**
  (combinar com assuntos anteriores, pensar), **E5 e E6 ★★★** (desafio de
  verdade: um probleminha completo, um "descubra o bug", um "preveja a saída"
  ou uma variação esperta). Varie os tipos: escrever do zero, completar código,
  achar o erro, prever a saída, refatorar.
- Exercício só usa o que já foi ensinado até aquele assunto (siga o sumário).
- Sempre termine as dicas com a resposta esperada (valor final ou saída).
- O esqueleto (includes + main vazio) **compila** com `./rodar`. Inclua os
  `#include` que a solução vai precisar.
- Escreva uma resolução de cada exercício em
  `_respostas/<modulo>/E037.c` (mesmo cabeçalho de 2 linhas + código
  resolvido), compile, rode e confira com a resposta esperada.

## modulo.md

```md
# Módulo 01 · Fundamentos de C

(2 a 4 parágrafos: por que este módulo existe, o que muda na cabeça)

## O que você vai aprender
- ...

## Como estudar cada assunto
(o roteiro: ideia → código → fluxograma → rodar → exercícios; ★ níveis)

## As cores e as formas
<p align="center"><img src="../legenda.svg" alt="Legenda: formas e cores do fluxograma" width="916"></p>

## Antes de começar
(o que precisa saber/instalar; avisos)

{{indice}}

---

{{assuntos}}

---

## Desafios do módulo
(8 a 12 problemas extras, só no markdown, misturando os assuntos do módulo,
do médio ao difícil. Cada um com enunciado e, num <details>, a resposta
esperada e uma dica de caminho.)

## Para ler mais
(referências em ABNT: os livros dos fichamentos que serviram de base para o
módulo + K&R, cppreference, man pages quando couber)
```

## C moderno: regras

- Nunca: `gets`, `conio.h` (`getch`, `clrscr`, `gotoxy`), `void main`,
  `fflush(stdin)`, `system("pause")`, `system("cls")`, Turbo C. Quando um livro
  usar, o texto pode citar como "você vai ver isso em material antigo; não use"
  e mostrar a alternativa.
- Até 0011: `scanf` simples. A partir de 0011, confira o retorno do `scanf`
  quando fizer sentido. A partir de 0047, strings com `fgets`.
- `bool` de `<stdbool.h>` a partir de 0017.
- Memória: todo `malloc` tem `free`; confira `NULL`. Os exemplos rodam limpos
  no AddressSanitizer.
- Estruturas de dados a partir do módulo 10 seguem o padrão **TAD**: `pilha.h`
  (interface) + `pilha.c` (implementação) na pasta do assunto + o exemplo
  `A175.c` com `#include "pilha.h"`. O `rodar` compila junto os `.c` de apoio
  da pasta (todo `.c` cujo nome não é `A000.c`/`E000.c`). Exercícios que
  precisam de uma implementação diferente trazem tudo no próprio arquivo.

## Fontes e direitos autorais

Os livros fichados em `_fontes/` são referência. Nunca copie texto, exemplos
ou exercícios literalmente: escreva do zero, com outro cenário e outros
valores. Ideias, conceitos e algoritmos clássicos são livres; o texto deles
não.
