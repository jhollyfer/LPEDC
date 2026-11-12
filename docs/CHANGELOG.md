# Changelog

Mudanças do LPEDC que quem estuda percebe. Formato
[Keep a Changelog](https://keepachangelog.com/pt-BR/1.1.0/), versões em
[SemVer](https://semver.org/lang/pt-BR/).

## [Não lançado]

### Adicionado

- Quiz das 11 provas do PPGI em `index.html`, publicado no GitHub Pages: você marca a alternativa
  e vê na hora se acertou, o porquê de cada alternativa e o módulo onde estudar. Tem filtro por
  tópico do edital, modo "refazer as que errei" e progresso salvo no navegador. As figuras das
  provas foram redesenhadas no traço do curso.
- Quiz: botão "Conceito e exemplo" em todas as 210 questões, com a regra cobrada e um exemplo
  resolvido com outros dados, para você responder sem ver a resposta.
- Cadernos completos de 057/2022, 020/2023 e 071/2023 em `provas-ppgi-ufam/`; as 11 provas agora usam
  o gabarito oficial.

### Corrigido

- 020/2023: Q06 passa de B para C e Q09 ganha a letra A, pelo gabarito oficial.
- Provas de 2016 a 2019 conferidas com os PDFs: subscritos e palavras que faltavam, recortes de figura
  sem sobra, porquês do quiz e observações do `PROVAS.md` que ainda falavam em figura ausente.

- `TRILHA.md`: trilha de estudo em 9 etapas, em ordem de dependência, com o que saber de cabeça e o
  treino de cada uma; complementa o plano por peso do `PPGI.md`.
- `PPGI.md`, "Comece aqui": plano de estudo dia a dia de 09/11 até a prova (27/11), com
  assuntos e treino (provas antigas e simulados) em cada dia.
- `PROVAS.md`: as 11 provas do PPGI de 2016 a 2023 resolvidas (a de 2023 com o gabarito
  oficial), com a letra, o porquê e o link para o módulo de cada questão.
- `SIMULADOS.md`: 3 simulados de 20 questões, com 4 alternativas como nas provas de 2022 e
  2023, e gabarito comentado.
- `PPGI.md`: o que caiu de 2016 a 2023, por tópico, assunto e formato de questão.

### Alterado

- Os comandos dos exemplos e exercícios passam de `~/LPEDC/rodar caminho.c` para `gcc ... -o ... && ...`,
  com os `.c` de apoio da pasta e `-lm` quando preciso; o texto explica as flags de estudo.
- Dicas "Resposta esperada: a saída acima." saem do `.md` dos módulos: repetiam a saída já mostrada
  no enunciado (cerca de 980 linhas a menos).
- "Questões no estilo da prova" dos 29 módulos no formato da prova real: afirmações I, II e III
  combinadas, simulação, cálculo e código C com erro; árvores, listas, ordenação e hash
  reescritos por inteiro.
- Texto, enunciados e dicas de todos os módulos, `README.md`, `PPGI.md` e fichamentos
  revisados: menos repetição entre assuntos, sem vícios de linguagem e sem travessão.

### Corrigido

- Avisos (`[!TIP]`, `[!WARNING]`, `[!NOTE]`) que apareciam partidos ao meio em vários assuntos.
- 0185: a conta das casas que `m` e `s` não usam (15 de 25).
- 0184: Flores é ponta da ponte Aleixo-Flores; o texto dizia o contrário.
- 0110: o "ali" ambíguo sobre o grau no LinkedIn.

## [1.0.0] - 2026-11-09

### Adicionado

- 29 módulos, de fundamentos de C a grafos e NP, com 189 assuntos, 378 exemplos e 1.134
  exercícios com resolução.
- Lista prática de 30 exercícios por módulo, desafios e questões no estilo da prova do PPGI.
- Mapa do edital em `PPGI.md`, com o roteiro até a prova.

[Não lançado]: https://github.com/jhollyfer/LPEDC/compare/v1.0.0...HEAD
[1.0.0]: https://github.com/jhollyfer/LPEDC/releases/tag/v1.0.0
