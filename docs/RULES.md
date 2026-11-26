# Regras de escrita do curso

**LPEDC** · valem para quem escreve ou revisa conteúdo aqui, pessoa ou agente

> Onde cada arquivo mora e a numeração estão em `ARCHITECTURE.md`; os desenhos, em `DESIGN.md`;
> como conferir, em `TEST-PLAN.md`. Este arquivo diz **como** o conteúdo se escreve.

## 1. Para quem e com que voz

Curso pessoal de **Lógica de Programação, Linguagem C e Estrutura de Dados**, em
português do Brasil. Mesma filosofia do LPPOO (github.com/jhollyfer/LPPOO), mas
organizado por **módulos** em vez de datas.

Quem estuda: um adulto que quer **relembrar (ou aprender) lógica de
programação**, **aprender estrutura de dados** e **entender de verdade como o C
e a memória funcionam**. Não é aula para turma: o texto fala com "você",
direto, sem infantilizar. **Nunca** compare com outra linguagem (nada de
TypeScript, JavaScript, Python, Java...): tudo é explicado em termos de C.

O curso começa direto em C: o módulo 01 abre com algoritmo e o modelo
entrada → processamento → saída (a estrutura sequencial); depois vêm
decisões, laços, funções e assim por diante. A instalação está no
[`README.md`](../README.md#preparar-o-computador).

**Objetivo principal:** preparar para a Prova de Conhecimentos do Mestrado do
PPGI/UFAM (escopo em `PRD.md`; mapa edital → assuntos e roteiro em
[`PPGI.md`](../PPGI.md)). Quando um livro divergir, siga as
definições e os nomes do **Cormen** e cite o nome alternativo ("também chamado
de...").

O sumário completo (módulos, assuntos e números) está em
[`_fontes/sumario.md`](../_fontes/sumario.md). Os fichamentos dos livros estão em
`_fontes/*.md`.

## 2. O agente não mexe sem perguntar

- Numeração de assuntos, exemplos e exercícios (`ARCHITECTURE.md` §2): links e listas dependem dela.
- Letra de gabarito ou resposta esperada que já foi conferida rodando o código.
- Escopo do curso e ordem dos módulos (`PRD.md`).
- Os `.md` de módulo na raiz: são gerados; a mudança vai na fonte em `_gerador/modulos/`.
- Os fichamentos em `_fontes/`: são referência, não conteúdo.

## 3. Cada assunto (texto.md)

Cada assunto é um **capítulo de livro**: no `.md` do módulo ele sai inteiro, com `### Conceito`,
`### Exemplos de uso` e `### Exercícios`, um depois do outro (`DECISIONS.md` #13). O `texto.md`
alimenta as duas primeiras; o marcador `{{exemplo}}` separa uma da outra. Modelo:
`_gerador/modulos/01-fundamentos/0005-printf/texto.md`.

```md
## 0005 · printf

Parágrafo que parte do problema: para que serve, o que falta sem isso.

Uma imagem do dia a dia (o formulário, a fila do banco) que dá a intuição, e
o termo novo em **negrito**, definido com outras palavras e com a fonte
(BACKES, 2013, cap. 2).

(trecho curto de código, se ajudar a ver a ideia)

Um parágrafo por peça da ideia, do simples ao detalhe, cada um com um
exemplo pequeno e o porquê ("isso importa porque...") (DEITEL; DEITEL, 2011, cap. 9).

(tabela, só se ajudar a consultar)

> [!WARNING]
> O erro que todo mundo comete, em 2 a 5 linhas.

{{exemplo}}

Uma ou duas frases com o cenário, terminando no desenho:

{{ideia}}

(bloco ```c completo e compilável, com a saída em comentário: // Saída: ...)

Uma frase que puxa o fluxograma:

{{fluxograma}}
```

- **Lê como livro.** O conceito é texto corrido, em parágrafos que se encadeiam: o problema, a
  intuição, a definição e as peças uma de cada vez, cada uma com um exemplo pequeno e o porquê.
  Quem lê não precisa adivinhar nada: todo termo é explicado na primeira vez que aparece. Nada de
  glossário em tópicos (`- **termo**: ...`); o `conferir-texto.py` reprova conceito com menos de 4
  parágrafos corridos ou com mais de 3 tópicos desse tipo.
- **Fonte dentro do texto.** A frase que define ou afirma algo de livro termina com a obra, no
  estilo ABNT curto: `(AUTOR, ano)` ou `(AUTOR, ano, cap. N)`. A definição vem dos fichamentos de
  `_fontes/`, escrita com outras palavras (§9). O autor citado tem a referência completa em "Para
  ler mais" do `modulo.md`. Capítulo ou página só quando o fichamento confirma; nunca invente.
- **Tamanho.** O necessário para entender sem esforço: de 25 a 70 linhas de conceito fora o
  código. Termos novos em **negrito**, código inline com crase.
- **Um alerta só**: o `> [!WARNING]` com o erro que todo mundo comete. Não há `TIP` nem `NOTE`; o
  que era "Por dentro do C" e vale a pena vira parágrafo do conceito.
- **O exemplo** usa um cenário do dia a dia (feira, ônibus, Pix...), valores em R$, e o código, o
  diagrama da ideia e o fluxograma mostram o **mesmo cenário com os mesmos valores**.
- Assunto difícil (ponteiros, recursão, árvores) pode ter `### Passo a passo` depois do código,
  com um teste de mesa em tabela; o gerador o rebaixa para `####`.
- O gerador cuida do resto: os exemplos A entram em "Exemplos de uso" e os exercícios E em
  "Exercícios", no mesmo assunto.

Estilo de escrita: frases curtas, voz ativa, sem emoji, sem "Neste assunto veremos". Frases de ligação entre as peças da explicação são bem-vindas; o que se corta é enchimento. Sem vícios de
linguagem ("onde" como coringa, "de forma X", "através de", "realizar", "possuir", "vale
ressaltar", "é importante notar", "basicamente", "na verdade", "ou seja" em série) e sem marcas de
texto gerado ("não é só X, é Y", trios forçados, "crucial", "fundamental", conclusão genérica,
travessão). O `humanizer-pt` entra antes do commit (`TEST-PLAN.md` §3). Não repita o que outro
assunto ou o README já disse: aponte para ele.

## 4. Exemplos (A003.c)

```c
// A003 · A idade na caixinha

#include <stdio.h>

int main(void) {
    int idade = 25; // a caixinha "idade" guarda 25

    printf("Idade: %d\n", idade); // Idade: 25
    return 0;
}
```

- 1ª linha: `// A003 · título curto` (o gerador exige esse formato).
- C17 padrão, `int main(void)`, `return 0;`, 4 espaços de recuo, nomes em
  português sem acento em `snake_case`, comentários curtos em português.
- Prefira valores fixos (saída previsível). Quando ler do teclado, mostre no
  comentário um exemplo de interação: `// Digite a idade: 25`.
- **Obrigatório**: passa na conferência de `TEST-PLAN.md` §1. A saída nos
  comentários tem que ser a saída real: rode e confira.
- Os dois exemplos **não repetem o código que já aparece no texto**. O texto
  mostra o exemplo principal; os arquivos A trazem cenários novos que mostram
  outras facetas do mesmo conceito (um caso de borda, uma variação, um uso
  real). Quem leu o texto e roda os exemplos tem que aprender algo a mais.

## 5. Exercícios (E007.c)

```c
// 0002 · Variáveis
// Exercício E007 · ★☆☆
//
// Enunciado claro, com cenário e valores concretos. Linhas com 2 espaços de
// recuo viram bloco de código/saída no .md do módulo:
//
//   Saída esperada:
//   Produto: Arroz
//   Preço: R$ 25.90
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
```

- O bloco de comentários do topo é lido pelo gerador até a primeira linha que
  não começa com `//`. Respeite as linhas `Exercício E007 · ★☆☆`, `Saída esperada:` e
  `Escreva sua resposta abaixo:`.
- **Todo exercício é para codificar**: a pessoa escreve código C que compila, roda e mostra um resultado conferível. Nada de
  "preveja a saída", "explique", "responda" ou pseudocódigo como resposta.
  Quer treinar leitura de código? Peça para modificar o programa e mostrar o
  resultado ("acrescente um printf que mostre o valor de x em cada volta").
- Dificuldade dos 4: **E1 ★☆☆** (aplicar direto), **E2 e E3 ★★☆** (combinar com assuntos
  anteriores, pensar), **E4 ★★★** (desafio de verdade: um probleminha completo ou uma variação
  esperta). Todos pedem escrever o código do zero.
- Exercício só usa o que já foi ensinado até aquele assunto (siga o sumário).
- Exercício de assunto não tem dicas: só enunciado e "Saída esperada" (com "Entrada:" quando o
  programa lê do teclado). Todo exercício manda escrever código do zero; nada de "conserte" ou
  código pronto para completar.
- O esqueleto (includes + main vazio) **compila** com `gcc`. Inclua os
  `#include` que a solução vai precisar.
- Escreva uma resolução de cada exercício em
  `_respostas/<modulo>/E007.c` (mesmo cabeçalho de 2 linhas + código
  resolvido), compile, rode e confira com a resposta esperada. Toda resolução
  é código que roda (se precisar de um TAD, traga uma cópia do `.h`/`.c` na
  pasta `_respostas/<modulo>/`).

## 6. Lista prática do módulo (lista/P????.c)

Além dos 4 exercícios de cada assunto, todo módulo tem uma **lista prática**
com **30 exercícios** em `<modulo>/lista/`, que misturam os assuntos do módulo
(e dos anteriores) no estilo dos problemas da prova do PPGI.

- Nome: `P` + número do módulo (2 dígitos) + índice (2 dígitos): o módulo 14
  tem `P1401.c` a `P1430.c`.
- Níveis: P01 a P10 ★☆☆, P11 a P20 ★★☆, P21 a P30 ★★★.
- Cabeçalho (o gerador exige):

```c
// Lista · Módulo 14 · Árvores
// Exercício P1407 · ★☆☆ · Altura da árvore de categorias
//
// Enunciado... (mesmas regras dos exercícios E: cenário, valores, saída
// esperada com 2 espaços de recuo)
//
// Escreva sua resposta abaixo:
```

- Mesmas regras dos exercícios E: sempre de codificar, esqueleto que compila
  com `gcc`, variedade (do zero, completar, consertar, estender), só o que
  já foi ensinado até o fim do módulo. Exercício que precisa de TAD traz tudo
  no próprio arquivo.
- Resolução em `_respostas/<modulo>/lista/P1407.c` (mesmo cabeçalho + código),
  rodada e conferida. Respostas autocontidas: nada de `.c` de apoio na pasta.
- O gerador põe a lista inteira no `.md` do módulo, em "3. Exercícios práticos", depois dos
  exercícios dos assuntos e antes dos desafios. Não edite o `modulo.md` para isso.
- No `.md`, cada exercício (E e P) mostra só o enunciado, a saída e a "Resposta esperada" quando ela
  acrescenta algo; as outras dicas ficam só no `.c`.
- Confira com `_gerador/conferir.sh <modulo>` (`TEST-PLAN.md`).

## 7. modulo.md

```md
# Módulo 01 · Fundamentos de C

(até 5 linhas: o que o módulo cobre e de que módulo depende)

## O que você vai aprender
- ...

## Antes de começar
(o que precisa instalar ou saber; o que os desenhos do módulo têm de próprio)

{{indice}}

---

{{assuntos}}

---

### Desafios do módulo
(8 a 12 problemas extras que misturam os assuntos, cada um com a resposta num <details>)

### Questões no estilo da prova
(8 a 10 questões objetivas no formato do PPGI, cada uma com <details><summary>Gabarito</summary>,
a letra, a justificativa e o assunto onde estudar. Rode todo código antes de fixar o gabarito.)

## Para ler mais
(referências ABNT completas de toda obra citada nos conceitos: livros dos fichamentos, artigos
originais, normas, K&R, cppreference, man pages)
```

O gerador troca `{{assuntos}}` pelos assuntos em ordem, cada um como `## NNNN · Título` com
`### Conceito`, `### Exemplos de uso` e `### Exercícios`, e pela `## Lista do módulo` no fim.
Desafios, "Questões do POSCOMP", "Questões de provas do PPGI" e "Questões no estilo da prova" ficam
em `##`.

## 8. C moderno

- Nunca: `gets`, `conio.h` (`getch`, `clrscr`, `gotoxy`), `void main`,
  `fflush(stdin)`, `system("pause")`, `system("cls")`, Turbo C. Quando um livro
  usar, o texto pode citar como "você vai ver isso em material antigo; não use"
  e mostrar a alternativa.
- Até 0011: `scanf` simples. A partir de 0011, confira o retorno do `scanf`
  quando fizer sentido. A partir de 0042, strings com `fgets`.
- `bool` de `<stdbool.h>` a partir de 0012.
- Memória: todo `malloc` tem `free`; confira `NULL`. Os exemplos rodam limpos
  no AddressSanitizer.
- Estruturas de dados a partir do módulo 10 seguem o padrão **TAD**: `0082-pilha.h`
  (interface) + `0082-pilha.c` (implementação), em `material/`, com o número do assunto no nome, + o
  exemplo `A165.c` com `#include "0082-pilha.h"`. O comando do exemplo lista junto os `.c` de
  apoio do assunto (`_gerador/arquivos.json`). Exercícios que
  precisam de uma implementação diferente trazem tudo no próprio arquivo.

## 9. Fontes e direitos autorais

Os livros fichados em `_fontes/` são referência. Nunca copie texto, exemplos
ou exercícios literalmente: escreva do zero, com outro cenário e outros
valores. Ideias, conceitos e algoritmos clássicos são livres; o texto deles
não.

Exceção: as questões das provas do PPGI/UFAM entram na íntegra, por decisão do dono
(`DECISIONS.md` #7), com o edital e o gabarito oficial indicados.

## Histórico

| Data | Mudança |
|---|---|
| 2026-11-09 | Regras saem do `CLAUDE.md` para cá, no formato do `maiyu-pattern` |
| 2026-11-10 | 4 exercícios por assunto, só de escrever código, com enunciado e saída esperada; sem dicas |
| 2026-11-13 | Módulo em três partes (conceitos, exemplos, exercícios); conceito em tópicos com fonte citada; um WARNING só, sem TIP e NOTE |
| 2026-11-13 | Assunto como capítulo de livro (conceito, exemplos, exercícios juntos); conceito em texto corrido com fonte, não em tópicos (`DECISIONS.md` #13) |
