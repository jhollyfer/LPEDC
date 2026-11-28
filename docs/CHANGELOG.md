# Changelog

Mudanças do LPEDC que quem estuda percebe. Formato
[Keep a Changelog](https://keepachangelog.com/pt-BR/1.1.0/), versões em
[SemVer](https://semver.org/lang/pt-BR/).

## [Não lançado]

### Mudado

- Na lista de provas do quiz, cada edital mostra o semestre da seleção ao lado de questões e
  alternativas ("Mestrado 2026/1"), porque o número do edital é do ano anterior ao da seleção.

### Adicionado

- As cinco provas que faltavam no quiz e em `PROVAS.md`: 031/2024 (2024/2), 092/2024 (2025/1),
  048/2025 (2025/2), 098/2025 (2026/1) e 014/2026 (2026/2), com o gabarito final da banca. O quiz
  passa a ter 17 provas e 330 questões. Aulas novas de While (0020), Prim (0153) e
  Floyd-Warshall (0155); cinco pares de questões parecidas entre provas ligados no Resumo.
- Prova do edital 070/2026 (seleção 2027/1, aplicada em 27/11/2026) no quiz e em `PROVAS.md`, com
  o gabarito preliminar da banca. São 20 questões com conceito antes de responder, porquê de cada
  alternativa, contraponto e a árvore B da Q09 redesenhada. O caderno está em
  `provas-ppgi-ufam/2026-070-prova-conhecimento.md`.
- Aulas novas no painel do quiz: deque (0087), bits e máscaras (0065) e Bellman-Ford (0154).
- `PPGI.md`: "O que caiu" passa a contar as 12 provas (230 questões).

### Corrigido

- Varredura das 210 questões do quiz: porquês e resumos com conta ou fato errado, dicas que
  entregavam a resposta e questões que abriam na aula do assunto errado. Altura de árvore passa a
  ser contada sempre em arestas.

### Mudado

- No quiz, o painel da direita passou a ensinar. Tem três abas: **Aula**, **Resumo** e
  **Para pensar**.
- **Aula:** cada um dos 67 assuntos cobrados nas provas tem o que é, como funciona, características,
  vantagens, desvantagens, um passo a passo desenhado (árvore, heap, hash, lista, pilha, vetor),
  custos, como a prova cobra e os livros de onde o conceito vem.
- **Para pensar:** nas questões de afirmações, um contraponto por afirmação, sem dizer a resposta.
- Questão que se repete em outra prova mostra o link para ela, e as duas têm a mesma explicação.
- Depois de responder, o porquê do acerto ou do erro aparece num bloco só, no topo do painel da
  direita. O porquê das outras alternativas fica recolhido.
- O curso abre como livro, com prefácio, sumário por partes, um assunto por página e navegação entre capítulos.
- Os documentos em Markdown voltaram a ser a fonte do livro e do acervo.
- No quiz, o tópico 3 do edital saiu separado: **3.1 Lista**, **3.2 Fila**, **3.3 Pilha** e
  **3.4 Vetor e matriz**, cada um com o seu acerto e o seu filtro. Questão que mistura pilha e fila
  aparece nos dois. O `PPGI.md` segue a mesma divisão, no "onde estudar" e no que caiu.
- O curso lê como um livro. Cada assunto é um capítulo inteiro: **Conceito**, **Exemplos de uso** e
  **Exercícios**, um depois do outro, sem precisar pular de parte em parte.
- O conceito voltou a ser explicação em texto corrido: parte do problema, dá a intuição com um caso
  do dia a dia e explica peça por peça, com a fonte de cada definição dentro do texto.
- O README virou o sumário do livro: a rota de estudo, mundo por mundo, com link para cada um dos
  189 assuntos.
- Os guias da raiz (PPGI, TRILHA, PROVAS e SIMULADOS) seguem três partes: **1. Conceitos gerais**,
  **2. Exemplos de uso** e **3. Exercícios práticos**.
- Exercícios no `.md` mostram só o enunciado, a saída e a resposta esperada; as dicas ficam no `.c`.

### Adicionado

- Link **Curso** no site para abrir o sumário, os módulos e os demais Markdown, com links diretos para as seções.
- Trilha de conceitos (`#trilha` no quiz): os 189 assuntos do curso numa escada em que cada degrau
  usa só o que veio antes, com o que saber de cabeça, o link para o curso, as questões das provas que
  cobram o assunto e o "Dominei". Abre no modo "só o que cai" (106 degraus) com o ranking do que
  mais cai.
- Quiz das 11 provas do PPGI em `index.html`, publicado no GitHub Pages: você marca a alternativa
  e vê na hora se acertou, o porquê de cada alternativa e o módulo onde estudar. Tem filtro por
  tópico do edital, modo "refazer as que errei" e progresso salvo no navegador. As figuras das
  provas foram redesenhadas no traço do curso.
- Quiz: painel "Antes de responder" em todas as 210 questões: o que a questão cobra, de 2 a 4
  conceitos principais, cada um com uma definição, um exemplo breve e o link para o assunto do curso
  onde é ensinado, e como atacar. Interface nova, com acerto por tópico e modo prova.
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
