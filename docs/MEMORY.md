# Memória do curso

**LPEDC** · onde a gente está, para a próxima conversa

> O agente lê no início de toda sessão e atualiza no fim. Histórico vai para `CHANGELOG.md` e
> `DECISIONS.md`.

| Atualizado | Fase atual | Progresso | Status |
|---|---|---|---|
| 2026-11-09 | 4 · Provas reais (concluída) | 16/16 tarefas | curso pronto para a prova de 2026-11-27 |

## Parou em

Fase 4 concluída: `PROVAS.md` (11 provas), frequência em `PPGI.md`, questões dos 29 módulos ajustadas e `SIMULADOS.md`.

## Próximos passos

1. Se chegarem provas novas ou o gabarito oficial de outras, gravar em `_fontes/provas-ppgi.md` e atualizar `PROVAS.md` e a frequência do `PPGI.md`.
2. As questões dos módulos ainda usam 5 alternativas (A a E); as provas desde 2022 usam 4. Os simulados já usam 4.

## Contexto importante

- Sobre as provas (gabarito, formato, data): `PROVAS.md` e `PPGI.md`.
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

- A auditoria do `humanizer-pt` acusa BLOQUEIO em "vestígios de ferramenta": falso positivo, explicado em `TEST-PLAN.md` §3.

## Links úteis

- Repositório: https://github.com/jhollyfer/LPEDC · Padrão: https://github.com/jhollyfer/maiyu-pattern
