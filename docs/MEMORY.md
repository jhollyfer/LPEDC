# Memória do curso

**LPEDC** · onde a gente está, para a próxima conversa

> O agente lê no início de toda sessão e atualiza no fim. Histórico vai para `CHANGELOG.md` e
> `DECISIONS.md`.

| Atualizado | Fase atual | Progresso | Status |
|---|---|---|---|
| 2026-11-13 | 5 · Quiz e guia de estudo (concluída) | 23/23 tarefas | curso pronto para a prova de 2026-11-27 |

## Parou em

Os 29 módulos e os guias da raiz estão em três partes: conceitos gerais (tópicos com a fonte
citada), exemplos de uso e exercícios práticos (`DECISIONS.md` #12). O `conferir-texto.py` exige a
forma nova e confere se cada autor citado tem a obra no "Para ler mais".

## Próximos passos

1. Passar o `humanizer-pt` nos conceitos reescritos (ficou pendente) e conferir à mão as citações que
   os relatórios marcaram como indiretas (Cormen e Ziviani não têm fichamento; capítulos vêm do
   "Para ler mais").
2. 0074: o 1º e o 2º bloco de código são iguais; trocar o 2º pelo `contador.h` (mexe em código).
3. Se chegarem provas novas, gravar em `_fontes/provas-ppgi.md` e atualizar `PROVAS.md` e o `PPGI.md`.
4. As questões dos módulos ainda usam 5 alternativas (A a E); as provas desde 2022 usam 4.

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
| 2026-11-10 | Revisão por busca de padrão (sed/grep) apresentada como leitura | Cada arquivo é lido inteiro; o agente entrega um registro por arquivo e a cobertura é conferida | revisão de texto em lote |
| 2026-11-12 | Dica do quiz encurtada até virar tautologia, e bloco de código colado no texto quebrou o exemplo no celular; testei uma questão só | Cada conceito tem definição de 10+ palavras e `Ex.:`, conferido pelo `quiz.mjs --check`; toda mudança no quiz roda `quiz-navegador.mjs` nas 210 questões | quiz das provas |
| 2026-11-09 | Commits com agente como autor e coautor | Autor único Jhollyfer, sem linha de coautoria | todo commit |

## Problemas conhecidos

- A auditoria do `humanizer-pt` acusa BLOQUEIO em "vestígios de ferramenta": falso positivo, explicado em `TEST-PLAN.md` §3.

## Links úteis

- Quiz: https://jhollyfer.github.io/LPEDC/ (Pages: `main`, raiz)
- Repositório: https://github.com/jhollyfer/LPEDC · Padrão: https://github.com/jhollyfer/maiyu-pattern
