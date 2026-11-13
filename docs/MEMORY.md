# Memória do curso

**LPEDC** · onde a gente está, para a próxima conversa

> O agente lê no início de toda sessão e atualiza no fim. Histórico vai para `CHANGELOG.md` e
> `DECISIONS.md`.

| Atualizado | Fase atual | Progresso | Status |
|---|---|---|---|
| 2026-11-13 | 5 · Quiz e guia de estudo (concluída) | 24/24 tarefas | curso pronto para a prova de 2026-11-27 |

## Parou em

O curso lê como livro (`DECISIONS.md` #13). Cada assunto é um capítulo no `.md` do módulo, com
Conceito, Exemplos de uso e Exercícios juntos. Os 189 conceitos estão em texto corrido, com a fonte
dentro do texto; o modelo é o 0005 printf. O README é o sumário, gerado pelo `gerar.mjs` a partir
de `fases.json`, com link para cada assunto. O `conferir-texto.py` dá 0 problema nos 29 módulos.

## Próximos passos

1. Passar o `humanizer-pt` nos 189 conceitos reescritos (não estava disponível na sessão).
2. Conferir à mão citações sem capítulo ou sem fonte apontadas na reescrita: 0018 (tabela de
   saltos), 0019 (Deitel cap. 4), 0058 (centavos), 0095 (Hoare 1960 no Cormen cap. 7), 0146
   (Knuth fora do "Para ler mais"), 0168, 0180 (custo do pigeonhole), 0182 (Euler 1736), 0188
   (11/9 do FFD).
3. Decidir com o dono se os guias da raiz (PPGI, TRILHA, PROVAS, SIMULADOS) também viram texto de
   livro; hoje seguem as três partes de #12.
4. 0074: o 1º e o 2º bloco de código são iguais; trocar o 2º pelo `contador.h` (mexe em código).
5. As questões dos módulos ainda usam 5 alternativas (A a E); as provas desde 2022 usam 4.

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
| 2026-11-13 | Conceito virou glossário em tópicos e o módulo foi partido em três blocos; o dono não conseguia estudar | Conceito é texto de livro (problema, intuição, definição com fonte, peça por peça) e o assunto fica inteiro; mudança de formato em lote começa por um piloto mostrado ao dono | todo texto de estudo |
| 2026-11-09 | Commits com agente como autor e coautor | Autor único Jhollyfer, sem linha de coautoria | todo commit |

## Problemas conhecidos

- A auditoria do `humanizer-pt` acusa BLOQUEIO em "vestígios de ferramenta": falso positivo, explicado em `TEST-PLAN.md` §3.

## Links úteis

- Quiz: https://jhollyfer.github.io/LPEDC/ (Pages: `main`, raiz)
- Repositório: https://github.com/jhollyfer/LPEDC · Padrão: https://github.com/jhollyfer/maiyu-pattern
