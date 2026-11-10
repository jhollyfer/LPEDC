# Arquitetura do curso

**LPEDC** · como o material está montado e como o texto vira `.md`

## 1. Peças

```
LPEDC/
├── rodar                      auxiliar do conferir.sh: compila com as flags de estudo e roda um .c
├── legenda.svg                formas e cores (gerado)
├── README.md                  guia do curso e índice (escrito à mão)
├── 01-fundamentos.md          gerado: o módulo inteiro (texto, exercícios, lista, questões)
├── 01-fundamentos/            os arquivos que se rodam e os desenhos (nenhum .md aqui)
│   ├── lista/P0101.c ...      a lista prática
│   └── 0002-variaveis/
│       ├── ideia.svg          gerado
│       ├── fluxograma.svg     gerado
│       ├── A003.c  A004.c     exemplos resolvidos
│       └── E007.c ... E012.c  exercícios (a resposta vai dentro do arquivo)
├── _respostas/01-fundamentos/E007.c ...   uma resolução de cada exercício
├── _gerador/modulos/01-fundamentos/       FONTE dos .md dos módulos e dos desenhos
│   ├── modulo.md              começo e fim do .md do módulo ({{indice}}, {{assuntos}})
│   └── 0002-variaveis/
│       ├── texto.md           o texto do assunto ({{ideia}}, {{fluxograma}}, {{pratique}})
│       └── desenhos.mjs       export const ideia e fluxograma
└── _fontes/                   sumário e fichamentos dos livros
```

Gerar: `cd _gerador && npm run gerar -- 01-` (só o módulo 01). Nunca edite o
`01-fundamentos.md` (ou outro `.md` de módulo na raiz) à mão: ele é
sobrescrito. **Nenhum markdown fica em subdiretório**: todo o texto mora na raiz.
Escreva os links como se o texto estivesse dentro da pasta do módulo
(`0002-variaveis/ideia.svg`, `../legenda.svg`); o gerador acerta o caminho.

Ferramentas: `gcc` (C17) com as flags de estudo (AddressSanitizer e UBSan), Node para o gerador
(`_gerador/gerar.mjs`, com `roughjs` e `dagre` para os desenhos) e Python 3 para
`_gerador/conferir-texto.py`. Não há servidor, banco nem deploy: o curso é lido no GitHub ou
num editor de markdown.

## 2. Numeração

Assunto `N` (ex.: 0002 → N = 2):

- exemplos: `A(2N-1)` e `A(2N)` → 0002 tem `A003.c` e `A004.c`
- exercícios: `E(6N-5)` até `E(6N)` → 0002 tem `E007.c` até `E012.c`

Sempre 3 dígitos (4 a partir de 1000: `E1000.c`). Sempre 2 exemplos e 4 exercícios por assunto; a numeração dos exercícios tem buracos.

## 3. Do texto ao `.md`

1. A fonte de cada módulo é `_gerador/modulos/<modulo>/modulo.md` mais um `texto.md` e um
   `desenhos.mjs` por assunto.
2. Os enunciados dos exercícios e da lista saem do bloco de comentários do topo dos `.c`
   (`RULES.md` §5 e §6).
3. O gerador (§1) monta o `.md` na raiz, os SVGs na pasta do módulo e acerta os caminhos dos
   links e das imagens.

## 4. Linguagem do domínio

| Termo | Significa |
|---|---|
| módulo | uma pasta numerada (`01-fundamentos`) e o `.md` dela na raiz |
| assunto | uma seção `## NNNN · Título`, com um exemplo contado em texto, ideia, código e fluxograma |
| exemplo (A) | programa resolvido que mostra outra faceta do assunto |
| exercício (E) | esqueleto vazio para a pessoa codificar, com enunciado e saída esperada |
| lista prática (P) | 30 exercícios por módulo no estilo da prova |
| pratique | bloco gerado com os exemplos e exercícios do assunto |
| prova | Prova de Conhecimentos do Mestrado do PPGI/UFAM (`PRD.md`) |
