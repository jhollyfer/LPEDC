# Documento de requisitos

**LPEDC** · curso de lógica, C e estrutura de dados para a prova do mestrado do PPGI/UFAM

| Versão | Status | Data | Dono do produto | Meta |
|---|---|---|---|---|
| 1.0 | Aprovado | 2026-11-09 | Jhollyfer Rodrigues | curso completo antes da prova de 2026-11-27 |

> Escopo é decisão do dono. O agente não altera este arquivo sem pedido; viu contradição entre a
> tarefa e o PRD, pergunta.

## 1. Problema

A Prova de Conhecimentos do PPGI/UFAM (edital 070/2026) cobra 20 questões objetivas de algoritmos,
C, estruturas de dados, análise, ordenação, hash, árvores e grafos, com base em Cormen, Ziviani e
Deitel. O material espalhado em livros e apostilas não treina o formato da prova nem mostra o que o
C faz na memória.

## 2. Para quem

| Perfil | Quem é | O que precisa |
|---|---|---|
| Estudante | adulto que quer relembrar lógica, aprender estrutura de dados e entender o C por dentro | um caminho em ordem, com código que roda e exercício conferível |
| Candidato | quem vai fazer a prova do PPGI | treino no formato da prova e o mapa edital → assunto (`PPGI.md`) |

## 3. Objetivos

- Cobrir todos os tópicos do edital, cada um ligado a um assunto do curso (`PPGI.md`).
- Todo código do curso compila sem aviso e roda limpo no AddressSanitizer.
- Treino no formato da prova em todo módulo (questões objetivas com gabarito comentado).

## 4. Primeira versão

| # | Item | Situação |
|---|---|---|
| 1 | 29 módulos, 189 assuntos, cada um com texto, ideia, código e fluxograma | feito |
| 2 | 2 exemplos e 4 exercícios por assunto (1 ★☆☆, 2 ★★☆, 1 ★★★), com resolução em `_respostas/` | feito |
| 3 | Lista prática de 30 exercícios por módulo | feito |
| 4 | Desafios e questões no estilo da prova em cada módulo | feito |
| 5 | Questões, mapa e simulados ajustados a provas reais anteriores | feito |

## 5. Fica de fora

- Outras linguagens: tudo é explicado em C (`RULES.md` §1).
- Interface gráfica, site próprio ou aplicativo: o curso é markdown lido no GitHub ou no editor.

## 6. Requisitos não funcionais

| Tema | Requisito |
|---|---|
| Leitura | cada `.md` de módulo abre no GitHub (abaixo do limite de renderização; `DECISIONS.md` #1) |
| Ambiente | Arch Linux primeiro, depois Debian/Ubuntu e Windows com WSL |
| Código | C17, `-Wall -Wextra -pedantic`, AddressSanitizer e UBSan sem erro |

## 7. Métricas de sucesso

| Métrica | Hoje | Meta | Como medir |
|---|---|---|---|
| Tópicos do edital com assunto no curso | todos | todos | tabela de `PPGI.md` |
| Arquivos com problema no `conferir.sh` | 0 | 0 | `TEST-PLAN.md` §2 |

## 8. Perguntas em aberto

- [x] Provas anteriores como referência de formato e frequência: as 11 de 2016 a 2023 entraram (`TASKS.md` fase 4).

## Histórico

| Versão | Data | Mudança |
|---|---|---|
| 1.0 | 2026-11-09 | Primeira versão, no formato do `maiyu-pattern` |
