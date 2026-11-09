# Memória do curso

**LPEDC** · onde a gente está, para a próxima conversa

> O agente lê no início de toda sessão e atualiza no fim. Histórico vai para `CHANGELOG.md` e
> `DECISIONS.md`.

| Atualizado | Fase atual | Progresso | Status |
|---|---|---|---|
| 2026-11-09 | 4 · Provas reais | 12/15 tarefas | conteúdo completo, revisão feita |

## Já feito

- 29 módulos gerados na raiz, com lista prática, desafios e questões no estilo da prova.
- Revisão de texto e humanizer em todos os módulos, no `README.md` e no `PPGI.md`.
- `AGENTS.md` e `docs/` no formato do `maiyu-pattern`; histórico reescrito com autor único.

## Parou em

Resolvendo as 8 provas de 2016 a 2019 (`_fontes/provas-ppgi.md`, `TASKS.md` 4.4).

## Próximos passos

1. Quando as provas chegarem: mapear tópicos e frequência no `PPGI.md` (4.2).
2. Ajustar as questões dos módulos ao formato real (4.1).
3. Montar os simulados de 20 questões (4.3).

## Contexto importante

- A prova é em 2026-11-27 (`PPGI.md`, "Roteiro até a prova").
- A branch `claude/inspiring-einstein-y1aulj` no GitHub é antiga e já está toda na `main`; o proxy
  da sessão na nuvem recusa apagá-la. O dono apaga pela página de branches.

## Lições

> Uma linha por correção do dono. Lida no início de toda sessão.

| Data | Erro | Regra que evita | Vale para |
|---|---|---|---|
| 2026-11-09 | Conteúdo em `README.md` dentro de cada pasta de módulo | Todo markdown de conteúdo fica na raiz, um `.md` por módulo | gerador e qualquer `.md` novo |
| 2026-11-09 | Trabalho deixado em outra branch | Só existe a `main`; commit e push direto nela | todo commit |
| 2026-11-09 | Commits com agente como autor e coautor | Autor único Jhollyfer, sem linha de coautoria | todo commit |

## Problemas conhecidos

| Problema | Onde | Contorno |
|---|---|---|
| A auditoria do `humanizer-pt` sempre acusa BLOQUEIO em "vestígios de ferramenta" | `{{ideia}}`, `[!TIP]`, `<details>`, `[i]` | é falso positivo: compare com o arquivo do `HEAD` contra ele mesmo (`TEST-PLAN.md` §3) |

## Links úteis

- Repositório: https://github.com/jhollyfer/LPEDC · Padrão: https://github.com/jhollyfer/maiyu-pattern
