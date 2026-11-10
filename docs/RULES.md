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
[`README.md`](../README.md#como-preparar-o-computador).

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

Um assunto conta **um exemplo só**, em quatro partes que batem entre si: texto,
diagrama da ideia, código e fluxograma, com o **mesmo cenário e os mesmos
valores**. Roteiro:

1. `## 0002 · Variáveis` (título curto).
2. **Gancho**: uma situação do dia a dia (feira, ônibus, conta de luz,
   mercado, Pix, academia, futebol...). Cenários brasileiros, valores em R$.
3. O conceito em parágrafos curtos (2 a 4 linhas cada). Termos novos em
   **negrito**. Código inline com crase.
4. Um parágrafo que apresenta o exemplo e termina apontando para o desenho →
   `{{ideia}}`. Varie a abertura: nada de repetir a mesma frase em todo assunto.
5. O código do mesmo exemplo, em bloco ```` ```c ````, completo e compilável,
   com a saída em comentário (`// Saída: ...`).
6. Um parágrafo que puxa o fluxograma (o caminho que o exemplo faz) →
   `{{fluxograma}}`.
7. `> [!WARNING]` com a pegadinha principal (o erro que todo mundo comete).
8. `> [!TIP]` começando com **Por dentro do C:**, com o que acontece por baixo:
   memória, bytes, endereços, o que o compilador faz, custo. É a marca do curso.
   Nos assuntos de estrutura de dados também vale: "Por dentro do C" mostra a
   memória.
9. `> [!NOTE]` com **Pergunta para você:** algo para prever antes de rodar.
10. `{{pratique}}` (gerado: exemplos e exercícios).

Tamanho: o texto de um assunto (sem o pratique) tem entre 60 e 140 linhas.
Assunto difícil (ponteiros, recursão, árvores) pode ter uma seção extra
`### Passo a passo` com um teste de mesa em tabela markdown.

Estilo de escrita: frases curtas, voz ativa, sem enrolação, sem emoji, sem
"Neste assunto veremos". Explique o **porquê**, não só o como. Sem vícios de
linguagem ("onde" como coringa, "de forma X", "através de" no lugar de "por
meio de", "realizar" no lugar de "fazer", "possuir" no lugar de "ter", "vale
ressaltar", "é importante notar", "basicamente", "na verdade", "ou seja" em
série) e sem marcas de texto gerado ("não é só X, é Y", trios forçados,
"crucial", "fundamental" a cada parágrafo, conclusão genérica, travessão).
O `humanizer-pt` entra antes do commit (`TEST-PLAN.md` §3). Não repita o que outro assunto ou o README já disse: aponte para ele.

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
- O gerador põe a lista inteira no `.md` do módulo, numa seção antes das
  "Questões no estilo da prova". Não edite o `modulo.md` para isso.
- Confira com `_gerador/conferir.sh <modulo>` (`TEST-PLAN.md`).

## 7. modulo.md

```md
# Módulo 01 · Fundamentos de C

(2 a 4 parágrafos: por que este módulo existe, o que muda na cabeça)

## O que você vai aprender
- ...

## Antes de começar
(o que precisa saber/instalar; avisos; o que os desenhos deste módulo têm de
próprio. O roteiro de estudo e a legenda de cores ficam só no README.md: não
repita aqui.)

{{indice}}

---

{{assuntos}}

---

## Desafios do módulo
(8 a 12 problemas extras, só no markdown, misturando os assuntos do módulo,
do médio ao difícil. Cada um com enunciado e, num <details>, a resposta
esperada e uma dica de caminho.)

## Questões no estilo da prova
(8 a 10 questões objetivas originais, no formato da prova do PPGI: enunciado
curto, trecho de código C ou pseudocódigo quando couber, alternativas (A) a
(E). Cada uma termina com um <details><summary>Gabarito</summary> com a letra
e a justificativa, citando o assunto onde estudar (ex.: "veja 0095"). Cubra os
tópicos do edital que o módulo toca. Rode todo código de questão antes de
fixar o gabarito.)

## Para ler mais
(referências em ABNT: os livros dos fichamentos que serviram de base para o
módulo + K&R, cppreference, man pages quando couber)
```

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
- Estruturas de dados a partir do módulo 10 seguem o padrão **TAD**: `pilha.h`
  (interface) + `pilha.c` (implementação) na pasta do assunto + o exemplo
  `A165.c` com `#include "pilha.h"`. O comando do exemplo lista junto os `.c` de apoio
  da pasta (todo `.c` cujo nome não é `A000.c`/`E000.c`). Exercícios que
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
