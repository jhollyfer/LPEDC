# LPEDC · instruções para agentes

Curso pessoal de lógica de programação, linguagem C e estrutura de dados, em pt-BR, para a
Prova de Conhecimentos do Mestrado do PPGI/UFAM.

## O padrão Maiyu, adaptado ao curso

Este repositório segue a filosofia do `maiyu-pattern` (github.com/jhollyfer/maiyu-pattern):
documentação viva em `docs/`, autor único, commits Conventional em pt-BR, zero duplicidade e
texto para humano passado no humanizer. A régua de TypeScript (`_doc-lib/`, `_standards/`, skills
de backend e frontend) não vem para cá: o curso não tem código de aplicação. O que muda em relação
ao padrão está em `docs/DECISIONS.md`.

- Autor único `Jhollyfer Rodrigues <jhollyfer.fr@gmail.com>`: nenhum commit ou arquivo leva agente
  como autor ou coautor (sem `Co-Authored-By`, `Claude-Session` nem "Generated with").
- Commits Conventional em pt-BR e atômicos: `feat(13-busca): ...`, `fix(0095): ...`,
  `docs: ...`, `refactor(gerador): ...`. Nunca `claude`, `anthropic` ou outro agente na mensagem.
- Só existe a `main`, e a mudança vai direto nela, sem branch nem PR (`docs/DECISIONS.md` #2).
- Texto que alguém vai ler (módulos, README, PPGI, `docs/`) passa pelo `humanizer-pt` antes do
  commit (`docs/TEST-PLAN.md` §3).

## Antes de qualquer tarefa

1. `docs/MEMORY.md`: onde o trabalho parou e as lições.
2. `docs/TASKS.md`: o que está em andamento e o que vem depois.
3. O que a tarefa pede:
   - escrever ou revisar conteúdo: `docs/RULES.md`;
   - mexer em pasta, numeração ou gerador: `docs/ARCHITECTURE.md`;
   - desenho (ideia ou fluxograma): `docs/DESIGN.md`;
   - conferir antes de dar como pronto: `docs/TEST-PLAN.md`;
   - escopo do curso, módulo novo, prova: `docs/PRD.md` e `PPGI.md`;
   - escolha difícil de desfazer: `docs/DECISIONS.md`.

Leia pela seção (`grep -n '^## ' docs/RULES.md`), não o arquivo inteiro.

## Ao terminar

No mesmo commit da mudança:

- status em `docs/TASKS.md`;
- "Parou em" e "Próximos passos" em `docs/MEMORY.md`; correção do dono vira linha em "Lições";
- `docs/DECISIONS.md` se decidiu algo difícil de desfazer;
- `docs/CHANGELOG.md` em `[Não lançado]` se quem estuda percebe a mudança.

## Não toque sem perguntar

Lista em `docs/RULES.md` §2.
