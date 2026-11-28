# Memória do curso

**LPEDC** · onde a gente está, para a próxima conversa

> O agente lê no início de toda sessão e atualiza no fim. Histórico vai para `CHANGELOG.md` e
> `DECISIONS.md`.

| Atualizado | Fase atual | Progresso | Status |
|---|---|---|---|
| 2026-11-28 | 9 · Prova de 2026 (concluída) | 34/34 tarefas | prova 070/2026 no quiz com gabarito preliminar |

## Parou em

A prova de 27/11/2026 (edital 070/2026, seleção 2027/1; o caderno vale também para o 071/2026, do
doutorado) entrou no acervo, no `PROVAS.md` e no quiz: 12 provas, 230 questões. O gabarito é o
preliminar da banca e bateu com a resolução do curso nas 20 questões. Os assuntos 0065, 0087 e
0154 ganharam aula (agora são 70).

O link **Curso** abre o prefácio. O livro tem oito partes, 29 módulos e 189 capítulos. Os 304 arquivos
Markdown abastecem o leitor e o acervo no mesmo `index.html`. O quiz abre na página inicial.

O curso lê como livro (`DECISIONS.md` #13). Cada assunto é um capítulo no `.md` do módulo, com
Conceito, Exemplos de uso e Exercícios juntos. Os 189 conceitos estão em texto corrido, com a fonte
dentro do texto; o modelo é o 0005 printf. O README é o sumário, gerado pelo `gerar.mjs` a partir
de `fases.json`, com link para cada assunto. O `conferir-texto.py` dá 0 problema nos 29 módulos.

No quiz, o tópico 3 virou quatro subtópicos (3.1 Lista, 3.2 Fila, 3.3 Pilha, 3.4 Vetor e matriz),
marcados à mão nas 54 questões; `quiz-navegador.mjs` passou nas 210.

O painel da direita do quiz ensina o assunto (fase 8). Tem três abas: **Aula**, **Resumo** e
**Para pensar**. Cada um dos 67 assuntos citados nas questões tem uma aula em
`_gerador/aulas/NNNN.json` (o que é, como funciona, características, vantagens, desvantagens,
exemplo, `passos` com figura, custos, como a prova cobra, fontes). As figuras dos passos usam os
ícones do curso (`arvore`, `vetor`, `lista`, `pilha`, `hash`, `arvoreB`, `texto`) e saem em
`quiz/figuras/aula-NNNN-k.svg`. Questão de afirmações tem `contrapontos`, um por afirmação, que
provocam sem dizer se é verdadeira ou falsa (o `quiz.mjs --check` barra as palavras que entregam).
Depois de responder, o porquê aparece num bloco só no topo do painel. As questões repetidas entre
provas estão em `_gerador/parecidas.json` (13 grupos): o Resumo mostra o link e o conteúdo comum
é igual nas duas. Convenções das aulas e das questões: altura em arestas (ou "níveis" dito na
frase), "BST" como nome, uma comparação de chave por volta na busca binária.

## Próximos passos

- Quando sair o gabarito definitivo da 070/2026, conferir as letras e anuladas em `PROVAS.md`,
  `provas-ppgi-ufam/2026-070-prova-conhecimento.md` e `_gerador/provas/2026-070.json`.
- O plano de estudo do `PPGI.md` ("Comece aqui") ainda é o de 09/11 a 27/11; decidir com o dono se
  vira plano para a próxima seleção.

Ao mudar a lista de arquivos Markdown ou seus títulos, atualize o índice com
`node _gerador/conteudo.mjs`.

0. As aulas, os contrapontos e a varredura das 210 questões foram feitos por agentes e conferidos
   por `quiz.mjs --check` e `quiz-navegador.mjs`; o dono ainda não leu tudo. A skill `humanizer-pt`
   não estava instalada: a passada de texto foi feita à mão pela regra de `RULES.md` §3. Rodar a
   skill quando houver.
1. Passar o `humanizer-pt` nos 189 conceitos reescritos (não estava disponível na sessão).
2. Conferir à mão citações sem capítulo ou sem fonte apontadas na reescrita: 0018 (tabela de
   saltos), 0019 (Deitel cap. 4), 0058 (centavos), 0095 (Hoare 1960 no Cormen cap. 7), 0146
   (Knuth fora do "Para ler mais"), 0168, 0180 (custo do pigeonhole), 0182 (Euler 1736), 0188
   (11/9 do FFD).
3. Decidir com o dono se os guias da raiz (PPGI, TRILHA, PROVAS, SIMULADOS) também viram texto de
   livro; hoje seguem as três partes de #12.
4. 0074: o 1º e o 2º bloco de código são iguais; trocar o 2º pelo `contador.h` (mexe em código).
5. As questões dos módulos ainda usam 5 alternativas (A a E); as provas desde 2022 usam 4.
6. Altura da árvore B com t = 100 e 1 milhão de chaves: a dica da 2017-055 Q10 diz "no máximo 2" e
   a da 2019-033 Q13 diz "uns 3" (arestas contra níveis). Uniformizar.
7. As figuras das aulas somam cerca de 20 MB porque cada SVG embute a fonte; dá para trocar por
   uma fonte compartilhada.

## Contexto importante

- Sobre as provas (gabarito, formato, data): `PROVAS.md` e `PPGI.md`.
- A branch `claude/inspiring-einstein-y1aulj` no GitHub é antiga e já está toda na `main`; o proxy
  da sessão na nuvem recusa apagá-la. O dono apaga pela página de branches.

## Lições

> Uma linha por correção do dono. Lida no início de toda sessão.

| Data | Erro | Regra que evita | Vale para |
|---|---|---|---|
| 2026-11-09 | Conteúdo em `README.md` dentro de cada pasta de módulo | Todo markdown de conteúdo fica na raiz, um `.md` por módulo | gerador e qualquer `.md` novo |
| 2026-11-26 | Os `.md` foram removidos na mudança de apresentação do livro | Manter Markdown como fonte dos capítulos para reaproveitar o material em um futuro app React | conteúdo e leitor do livro |
| 2026-11-09 | Trabalho deixado em outra branch | Só existe a `main`; commit e push direto nela | todo commit |
| 2026-11-10 | Revisão por busca de padrão (sed/grep) apresentada como leitura | Cada arquivo é lido inteiro; o agente entrega um registro por arquivo e a cobertura é conferida | revisão de texto em lote |
| 2026-11-12 | Dica do quiz encurtada até virar tautologia, e bloco de código colado no texto quebrou o exemplo no celular; testei uma questão só | Cada conceito tem definição de 10+ palavras e `Ex.:`, conferido pelo `quiz.mjs --check`; toda mudança no quiz roda `quiz-navegador.mjs` nas 210 questões | quiz das provas |
| 2026-11-13 | Conceito virou glossário em tópicos e o módulo foi partido em três blocos; o dono não conseguia estudar | Conceito é texto de livro (problema, intuição, definição com fonte, peça por peça) e o assunto fica inteiro; mudança de formato em lote começa por um piloto mostrado ao dono | todo texto de estudo |
| 2026-11-26 | Painel do quiz só com definições curtas e o porquê embaixo de cada alternativa | No quiz o dono quer aprender na própria questão: aula com conceito da literatura, passo a passo desenhado, contraponto que não entrega a resposta e o porquê num bloco só à direita; tela limpa, sem caixa dentro de caixa | quiz das provas |
| 2026-11-28 | Contagem do "O que caiu" (`PPGI.md`) atualizada somando a prova nova aos números antigos, que já estavam errados | Toda contagem por tópico, formato e assunto sai de recontagem em `_gerador/provas/*.json`, nunca de soma sobre o número anterior | `PPGI.md` e qualquer estatística das provas |
| 2026-11-09 | Commits com agente como autor e coautor | Autor único Jhollyfer, sem linha de coautoria | todo commit |

## Problemas conhecidos

- A auditoria do `humanizer-pt` acusa BLOQUEIO em "vestígios de ferramenta": falso positivo, explicado em `TEST-PLAN.md` §3.

## Links úteis

- Quiz: https://jhollyfer.github.io/LPEDC/ (Pages: `main`, raiz)
- Repositório: https://github.com/jhollyfer/LPEDC · Padrão: https://github.com/jhollyfer/maiyu-pattern
