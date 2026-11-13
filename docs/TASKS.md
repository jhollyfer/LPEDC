# Tarefas do curso

**LPEDC** · divididas em fases

> Atualiza no mesmo commit em que a tarefa começa ou termina.

**Resumo:** 23 tarefas · 23 feitas · 0 em andamento · 0 a fazer · atualizado 2026-11-13

Status: `A fazer` · `Em andamento` · `Feita` · `Bloqueada` (com motivo nas notas).
Prioridade: `Alta` · `Média` · `Baixa`.

## Fase 1 · Conteúdo (5/5)

| # | Tarefa | Prioridade | Status | Notas |
|---|---|---|---|---|
| 1.1 | Gerador de `.md` e de desenhos | Alta | Feita | `_gerador/` |
| 1.2 | Fichamentos dos livros | Alta | Feita | `_fontes/` |
| 1.3 | 29 módulos com assuntos, exemplos, exercícios e respostas | Alta | Feita | |
| 1.4 | Lista prática de 30 exercícios por módulo | Alta | Feita | |
| 1.5 | Mapa edital → assuntos | Alta | Feita | `PPGI.md` |

## Fase 2 · Revisão (5/5)

| # | Tarefa | Prioridade | Status | Notas |
|---|---|---|---|---|
| 2.1 | Um `.md` por módulo na raiz, sem markdown em subpasta | Alta | Feita | `DECISIONS.md` #1 |
| 2.2 | Revisão de texto: repetição e vícios de linguagem | Alta | Feita | verificador `conferir-texto.py` |
| 2.3 | Humanizer (`humanizer-pt` e `humanizer`) em todo o texto e nos enunciados | Alta | Feita | callouts quebrados unidos |
| 2.5 | Passada estrita de humanizer em cada `.md` (texto, enunciados, fichamentos) e dica repetida tirada pelo gerador | Alta | Feita | registro por arquivo conferido |
| 2.4 | Filosofia do `maiyu-pattern`: `AGENTS.md`, `docs/`, autor único | Alta | Feita | `DECISIONS.md` #3 e #4 |

## Fase 3 · Acertos apontados na revisão (3/3)

| # | Tarefa | Prioridade | Status | Notas |
|---|---|---|---|---|
| 3.1 | 0180: TIP do pigeonhole partido em dois callouts | Média | Feita | |
| 3.2 | 0185: conta das casas desperdiçadas em `m` e `s` | Média | Feita | eram 15 de 25, não 4 × 4 |
| 3.3 | 0110: "ali o grau é a distância" era ambíguo | Baixa | Feita | "prova do PPGI" e "prova do mestrado" ficam: nomeiam a mesma prova |

## Fase 4 · Provas reais (4/4)

Provas recebidas: 11 cadernos de 2016 a 2023 em `_fontes/provas-ppgi.md`; só a 071/2023 tem gabarito oficial.

| # | Tarefa | Prioridade | Status | Notas |
|---|---|---|---|---|
| 4.1 | Ajustar as "Questões no estilo da prova" dos módulos ao formato e ao nível das provas reais | Alta | Feita | 10 a 18, 22 e 28 reescritos; os outros com afirmações e código |
| 4.2 | Registrar no `PPGI.md` o que cai e com que frequência, ligado a módulo e assunto | Alta | Feita | `PPGI.md`, "O que caiu de 2016 a 2023" |
| 4.3 | Simulados completos de 20 questões com gabarito comentado | Alta | Feita | `SIMULADOS.md`: 3 simulados, 4 alternativas |
| 4.4 | Resolver as 210 questões das 11 provas, com letra, justificativa e assunto do curso | Alta | Feita | `PROVAS.md`: 13 sem letra (figura ausente); 071/2023 com gabarito oficial |

## Fase 5 · Quiz das provas e guia de estudo (6/6)

| # | Tarefa | Prioridade | Status | Notas |
|---|---|---|---|---|
| 5.1 | Quiz das 11 provas no GitHub Pages, com o porquê de cada alternativa e as figuras no traço do curso | Alta | Feita | `index.html`, `quiz/`, fonte em `_gerador/provas/`, gerado por `_gerador/quiz.mjs` |
| 5.2 | Conferir as 11 provas com os PDFs da banca (Drive do PPGI): cadernos de 2022 e 2023, gabarito oficial, texto, figuras e observações | Alta | Feita | 020/2023 Q06 B→C e Q09 →A; 2016 a 2019 sem divergência de letra |
| 5.3 | Conceito e exemplo antes de responder, em cada questão | Alta | Feita | campo `dica` no JSON; `quiz.mjs --check` exige |
| 5.4 | Conceitos curtos com o assunto do curso e interface redesenhada (skill de taste, estilo editorial-greeting) | Alta | Feita | `[NNNN]` vira link para a seção do módulo; até 110 palavras |
| 5.5 | Trilha de conceitos: os 189 assuntos em escada de pré-requisitos, priorizando o que cai na prova | Alta | Feita | `#trilha`; fonte em `_gerador/trilha/*.json`; `quiz.mjs --check` confere a ordem |
| 5.6 | Guia de estudo em três partes (conceitos com fonte, exemplos, exercícios) nos 29 módulos e nos guias da raiz | Alta | Substituída por 5.7 | `DECISIONS.md` #12; `conferir-texto.py` exige a forma e a fonte; humanizer ainda não passou |
| 5.7 | Curso como livro: cada assunto é um capítulo (conceito, exemplos, exercícios juntos), conceito em texto corrido com fonte nos 189 assuntos, README como sumário gerado | Alta | Feita | `DECISIONS.md` #13; `conferir-texto.py` reprova glossário; humanizer-pt ainda não passou |

---

## Como escrever uma tarefa

Antes de começar, a tarefa tem um resultado claro, dependências listadas, arquivos identificados e
critério de aceite (o de `TEST-PLAN.md` §4). Ao terminar: resultado conferido e status atualizado.
