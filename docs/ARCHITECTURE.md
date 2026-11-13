# Arquitetura do curso

**LPEDC** · como o material está montado e como o texto vira `.md`

## 1. Peças

```
LPEDC/
├── README.md  PPGI.md  TRILHA.md  PROVAS.md  SIMULADOS.md   guias (escritos à mão)
├── 01-fundamentos.md ...      gerados: um por módulo (texto, exercícios, lista, questões)
├── material/                  a única pasta de conteúdo: tudo o que se roda ou se vê
│   ├── A003.c  A004.c ...     exemplos resolvidos
│   ├── E007.c ...             exercícios (esqueleto vazio; a resposta vai dentro do arquivo)
│   ├── P0101.c ...            lista prática (P + número do módulo + número na lista)
│   ├── 0002-ideia.svg  0002-fluxograma.svg   desenhos do assunto (gerados)
│   ├── 0076-lista.c  0076-lista.h ...        apoio (TAD) do assunto, com o número dele no nome
│   └── legenda.svg            formas e cores (gerado)
├── _respostas/<modulo>/       uma resolução de cada exercício (e os apoios das respostas)
├── _gerador/modulos/<modulo>/ FONTE dos .md: modulo.md, e por assunto texto.md e desenhos.mjs
├── _gerador/arquivos.json     quais A, E e apoios pertencem a cada assunto
├── _gerador/fases.json        a rota do jogo: ordem das etapas, mundo e missão de cada módulo
├── _fontes/                   sumário, fichamentos dos livros e provas do PPGI
├── docs/  AGENTS.md  rodar    documentação viva, instruções de agentes e auxiliar do conferir.sh
├── index.html  .nojekyll      quiz das provas (GitHub Pages, raiz da main)
├── quiz/                      gerado: questoes.js e figuras/*.svg do quiz
├── _gerador/trilha/           FONTE da trilha: requer, porquê e "saia sabendo" de cada assunto
├── _gerador/provas/           FONTE do quiz: <slug>.json (questões e porquês) e <slug>.figuras.json
├── provas-ppgi-ufam/          provas de 2016 a 2019 com os recortes das figuras
```

Gerar: `cd _gerador && npm run gerar -- 01-` (só o módulo 01). Nunca edite o
`01-fundamentos.md` (ou outro `.md` de módulo na raiz) à mão: ele é
sobrescrito. **Todo arquivo do curso fica numa só pasta, `material/`** (`DECISIONS.md` #9): exemplos,
exercícios, lista, desenhos e apoios. Escreva os links do texto a partir da raiz (`material/0002-ideia.svg`).
Ao criar assunto ou exercício novo, acrescente os nomes em `_gerador/arquivos.json`.

Ferramentas: `gcc` (C17) com as flags de estudo (AddressSanitizer e UBSan), Node para o gerador
(`_gerador/gerar.mjs`, com `roughjs` e `dagre` para os desenhos) e Python 3 para
`_gerador/conferir-texto.py`. O quiz sai de `cd _gerador && node quiz.mjs` (`--check` confere letra contra o `PROVAS.md`, porquê de toda alternativa e figura citada); `index.html` e `quiz/` vão para o GitHub Pages pela `main`, sem build. Não há servidor nem banco: o curso é lido no GitHub ou
num editor de markdown.

## 2. Numeração

Assunto `N` (ex.: 0002 → N = 2):

- exemplos: `A(2N-1)` e `A(2N)` → 0002 tem `A003.c` e `A004.c`
- exercícios: 4 por assunto, escolhidos do bloco original `E(6N-5)` a `E(6N)` → 0002 manteve 4 dos 6 (`E007.c` a `E012.c`)

Sempre 3 dígitos (4 a partir de 1000: `E1000.c`). Sempre 2 exemplos e 4 exercícios por assunto; a numeração dos exercícios tem buracos.

## 3. Do texto ao `.md`

1. A fonte de cada módulo é `_gerador/modulos/<modulo>/modulo.md` mais um `texto.md` e um
   `desenhos.mjs` por assunto.
2. Os enunciados dos exercícios e da lista saem do bloco de comentários do topo dos `.c`
   (`RULES.md` §5 e §6).
3. O gerador (§1) monta o `.md` na raiz e os SVGs `NNNN-ideia.svg` e `NNNN-fluxograma.svg`, também na raiz.

## 4. Linguagem do domínio

| Termo | Significa |
|---|---|
| módulo | o `.md` numerado da raiz (`01-fundamentos.md`) |
| assunto | uma seção `## NNNN · Título`, com um exemplo contado em texto, ideia, código e fluxograma |
| exemplo (A) | programa resolvido que mostra outra faceta do assunto |
| exercício (E) | esqueleto vazio para a pessoa codificar, com enunciado e saída esperada |
| lista prática (P) | 30 exercícios por módulo no estilo da prova |
| pratique | bloco gerado com os exemplos e exercícios do assunto |
| prova | Prova de Conhecimentos do Mestrado do PPGI/UFAM (`PRD.md`) |
