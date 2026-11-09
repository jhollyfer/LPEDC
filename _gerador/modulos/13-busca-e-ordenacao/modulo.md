# Módulo 13 · Busca e ordenação

Procurar e ordenar são as duas tarefas que um computador mais faz. A lista de
contatos do celular, o extrato do banco, o resultado de uma busca na loja
virtual, o índice de um banco de dados: tudo isso é dado ordenado para depois
ser achado rápido.

Aqui você abre essas caixas pretas. Vai ver por que uma busca num vetor
ordenado acha qualquer coisa entre um milhão de elementos em 20 passos, por
que uma ordenação "óbvia" leva horas quando outra leva um segundo, e por que
a comparação `a - b`, tão comum numa função de comparar, pode dar errado no C.

O módulo usa vetores e ponteiros, recursão, `malloc`, structs e, acima de
tudo, a contagem de passos e o Big-O do módulo 10. Em cada algoritmo você
**conta comparações e trocas** e confere se a teoria bate com a prática.

## O que você vai aprender

- **busca sequencial**: o básico, o custo O(n) e o truque da sentinela
- **busca binária**: O(log n) em vetor ordenado, invariantes e os famosos erros de um
- os três algoritmos simples, O(n²): **bubble sort**, **selection sort** e **insertion sort**
- os dois de dividir e conquistar, O(n log n): **merge sort** e **quick sort**
- **estabilidade**, ordenação in-place e como escolher o algoritmo
- usar o **`qsort`** e o **`bsearch`** da biblioteca, com funções de comparação corretas

## Antes de começar

Nos diagramas da ideia, cada linha de gavetas é um momento do algoritmo:
**amarela** é a gaveta comparada (ou o menor achado), **roxa** é a posição ou
o pivô da vez, **verde** já está no lugar, **cinza** foi descartada ou nem
olhada. Faça o **Passo a passo** no papel antes de conferir a tabela.

Cada exemplo cabe num arquivo só: os algoritmos são funções curtas, e ver a
função inteira junto do `main` ajuda mais do que separar em `.h` e `.c`.
Exercício que precisa de outra versão do algoritmo traz tudo no próprio
arquivo.

Vários exemplos contam comparações com uma variável `static` de arquivo ou
com um ponteiro para contador. Esse contador não faz parte do algoritmo: é o
"cronômetro" que mostra o custo. Tempo de relógio varia de máquina para
máquina; o número de comparações, não.

Alguns exercícios de "ache o erro" trazem o bug de propósito, e o
AddressSanitizer (ou o UBSan) do `rodar` vai parar o programa. O enunciado
avisa.

{{indice}}

---

{{assuntos}}

---

## Desafios do módulo

Problemas para fechar o módulo, misturando os assuntos. Escreva em C e rode
com o `rodar`.

**1. Quantas voltas no pior caso?** Escreva a busca binária com um contador
de voltas do laço, devolvido por um ponteiro `int *voltas`. Num vetor criado
com `malloc` e preenchido só com pares (`v[i] = 2 * i`), busque **todos** os
ímpares de `-1` a `2n - 1` (todas essas buscas falham) e mostre o maior
número de voltas que alguma delas deu. Rode com `n = 5000` e com
`n = 5000000`.

<details><summary>Resposta</summary>

```text
n = 5000: no máximo 13 voltas
n = 5000000: no máximo 23 voltas
```

O intervalo cai pela metade a cada volta: o máximo é `⌊log₂ n⌋ + 1`. Para
5.000, 2¹² = 4096 ≤ 5000 < 8192 = 2¹³, então 13 voltas; para 5 milhões,
2²² ≤ 5.000.000 < 2²³, então 23. Mil vezes mais dados, só 10 voltas a mais.
Caminho: `ini = 0`, `fim = n - 1`, `(*voltas)++` logo no começo do `while
(ini <= fim)`, e no `main` um laço `for (int x = -1; x <= 2 * n - 1; x += 2)`
guardando o maior. Use `meio = ini + (fim - ini) / 2`; com 5 milhões, a
soma `ini + fim` ainda cabe em `int`, mas o hábito evita o estouro.

</details>

**2. O par que soma.** Dado um vetor ordenado `3 8 11 15 19 24 30` e um valor
`alvo = 34`, ache dois elementos que somam o alvo em O(n), sem laço dentro de
laço.

<details><summary>Resposta</summary>

Dois índices: `i = 0` no começo e `j = n - 1` no fim. Se `v[i] + v[j]` é
menor que o alvo, `i++`; se é maior, `j--`; se é igual, achou. Para 34: 3 + 30
= 33 (i++), 8 + 30 = 38 (j--), 8 + 24 = 32 (i++), 11 + 24 = 35 (j--), 11 + 19
= 30 (i++), **15 + 19 = 34**. Funciona porque o vetor está ordenado: cada passo
descarta um elemento que não pode fazer parte de nenhum par.

</details>

**3. Primeiro ordena, depois busca?** Você tem um vetor desordenado de
`n = 100.000` elementos e precisa responder `k` buscas. Escreva um programa
que calcule o custo dos dois planos em comparações: busca sequencial (uns
`n / 2` por busca) e ordenar (`n · log₂ n`) para depois fazer busca binária
(`log₂ n` por busca). Calcule `log₂ n` arredondado para cima com um laço que
dobra uma variável até passar de `n`. Mostre os dois custos para `k = 1, 10,
34, 35, 1000` e, com um `while`, o primeiro `k` em que ordenar fica mais
barato.

<details><summary>Resposta</summary>

```text
log2(n) arredondado para cima: 17
Ordenar: 1700000 comparações
k =    1: sequencial     50000, ordenar + binária  1700017
k =   10: sequencial    500000, ordenar + binária  1700170
k =   34: sequencial   1700000, ordenar + binária  1700578
k =   35: sequencial   1750000, ordenar + binária  1700595  <- ordenar ganha
k = 1000: sequencial  50000000, ordenar + binária  1717000  <- ordenar ganha
Ordenar compensa a partir de 35 buscas
```

Igualando `50.000 k = 1.700.000 + 17 k`, dá `k ≈ 34`: com mais de umas 34
buscas, ordenar compensa; com milhares, a diferença é enorme; com 1 ou 2,
ordenar é desperdício. Use `long` nas contas: com `k` acima de uns 43 mil,
`k * 50000` passa do `INT_MAX`. O `while (ordenar + k * lg >= k * (n /
2)) k++;` acha o ponto de virada.

</details>

**4. Ordenar 0, 1 e 2.** Um vetor tem só os valores 0, 1 e 2 (por exemplo,
`2 0 1 2 1 0 0 2 1`). Ordene em **uma passada**, in-place, sem contar
quantos há de cada.

<details><summary>Resposta</summary>

É a partição de três vias do exercício E570 com pivô 1 (a "bandeira holandesa"
de Dijkstra): `lt`, `i` e `gt`. 0 vai para a frente (`troca(v[lt], v[i])`,
`lt++`, `i++`), 2 vai para o fim (`troca(v[i], v[gt])`, `gt--`), 1 fica
(`i++`). Resultado: `0 0 0 1 1 1 2 2 2`, com n comparações.

</details>

**5. Ordenar sem comparar.** As notas de 3.000 candidatos são inteiros de 0 a
100. Ordene em O(n) usando um vetor `contagem[101]`.

<details><summary>Resposta</summary>

**Counting sort**: um laço conta quantas vezes cada nota aparece
(`contagem[nota]++`); outro laço percorre as notas de 0 a 100 e escreve cada
uma `contagem[nota]` vezes. São O(n + 101) passos e nenhuma comparação entre
elementos. Só funciona porque as chaves são inteiros num intervalo pequeno: o
limite de O(n log n) vale para algoritmos que **comparam**.

</details>

**6. O merge sort de baixo para cima.** Escreva o merge sort sem recursão:
intercale pedaços de tamanho 1, depois 2, 4, 8... até cobrir o vetor. Teste
com as notas do assunto 0094, `52 18 33 7 41 26 60 12`, e com um vetor de 7
elementos.

<details><summary>Resposta</summary>

Laço de fora: `for (int b = 1; b < n; b *= 2)`. Laço de dentro:
`for (int p = 0; p + b < n; p += 2 * b)` intercala `[p, p + b)` com
`[p + b, min(p + 2b, n))`. O cuidado é o último pedaço, que pode ser menor
(ou nem existir) quando `n` não é potência de 2. O resultado é
`7 12 18 26 33 41 52 60`.

</details>

**7. Quick sort que não estoura a pilha.** Mude o quick sort do assunto 0095 para
fazer a recursão só no lado **menor** e tratar o maior com um `while`. Meça a
maior profundidade de recursão num vetor já ordenado de 10.000 elementos,
antes e depois.

<details><summary>Resposta</summary>

Antes, com o pivô no fim, a profundidade chega a 9.999. Depois, cada chamada
recursiva recebe no máximo metade do pedaço atual, então a profundidade fica
abaixo de `log₂ 10.000 ≈ 14`. As comparações continuam O(n²) nesse caso: o
truque protege a **pilha**, não o tempo. Para o tempo, mude o pivô (meio ou
mediana de três).

</details>

**8. Quick sort híbrido.** Faça o quick sort chamar o insertion sort quando o
pedaço tiver menos de `L` elementos. Com o contador de comparações do A192,
teste `L = 1, 8, 16, 32` num vetor aleatório de 10.000.

<details><summary>Resposta</summary>

As comparações quase não mudam (às vezes até sobem um pouco), mas o tempo de
relógio costuma cair, com o melhor valor em geral entre 8 e 32: o insertion
não tem recursão nem chamadas, e pedaços pequenos cabem inteiros no cache. As bibliotecas de verdade fazem
isso.

</details>

**9. Mediana de duas listas.** Duas lojas têm listas ordenadas de preços, com
5 e 6 itens: `12 30 45 60 88` e `9 25 41 50 70 95`. Ache a mediana dos 11
preços sem criar um vetor novo.

<details><summary>Resposta</summary>

Faça a intercalação **sem gravar**: avance os dois índices como no merge,
contando quantos elementos já "saíram", e pare no 6º (o do meio de 11). A
sequência é 9, 12, 25, 30, 41, **45**: a mediana é **45**, com O(n) passos e
O(1) de memória.

</details>

**10. A compara que mente.** Esta compara foi escrita para ordenar do maior
para o menor: `return *(const int *) a < *(const int *) b;`. Ela compila.
Escreva-a ao lado da versão certa, `certa`, e mostre o que cada uma devolve
para os pares `(3, 7)`, `(7, 3)` e `(5, 5)`, marcando o par em que a errada
devolve 0 com números diferentes. Depois ordene `52 18 33 7 41 26 60 12` com
`qsort` e a `certa`.

<details><summary>Resposta</summary>

```text
(3, 7): errada  1, certa  1
(7, 3): errada  0, certa -1  <- a errada diz que empatam
(5, 5): errada  0, certa  0
60 52 41 33 26 18 12 7
```

A errada devolve só 0 ou 1, nunca negativo: quando `a > b`, ela diz ao
`qsort` que empatam. O contrato fica inconsistente (se `a` empata com `b` e
`b` empata com `c`, `a` deveria empatar com `c`), e o resultado depende de
como a biblioteca implementa o `qsort`: pode sair certo num computador e
errado em outro. Por isso o teste olha a **compara**, não só o vetor
ordenado. A certa é `int x = *(const int *) a, y = *(const int *) b; return
(x < y) - (x > y);`, que devolve -1, 0 ou 1 sem risco de estouro.

</details>

## Questões no estilo da prova

Questões objetivas no formato da prova do mestrado. Nas de ordenação, escreva
o vetor depois de cada passada, como nos testes de mesa dos assuntos.

**1.** Uma busca binária (a do assunto 0090, com intervalo fechado e
`meio = ini + (fim - ini) / 2`) roda num vetor ordenado de 1000 elementos.
No pior caso, quantos elementos do vetor ela compara com a chave?

- (A) 9
- (B) 500
- (C) 11
- (D) 10
- (E) 1000

<details><summary>Gabarito</summary>

**D.** No pior caso são ⌊log₂ n⌋ + 1 voltas: ⌊log₂ 1000⌋ = 9, mais 1. Os
pedaços examinados, sempre indo para a direita, têm 1000, 500, 250, 125, 62,
31, 15, 7, 3 e 1 elementos. Veja 0090.

</details>

**2.** Com a mesma busca binária, procura-se o 50 no vetor de 15 posições
abaixo. Quais elementos são examinados, na ordem?

```c
int v[] = {3, 9, 14, 21, 27, 33, 40, 46, 52, 58, 65, 71, 77, 84, 90};
```

- (A) 46, 71, 58, 52
- (B) 46, 58, 52
- (C) 40, 58, 52
- (D) 46, 71, 52
- (E) 46, 65, 58, 52

<details><summary>Gabarito</summary>

**A.** Meio 7 (46 < 50, `ini = 8`), meio 11 (71 > 50, `fim = 10`), meio 9
(58 > 50, `fim = 8`), meio 8 (52 > 50, `fim = 7`). O intervalo fica vazio e a
busca devolve `-1` depois de 4 comparações, o máximo para n = 15. Veja 0090.

</details>

**3.** O bubble sort (vizinhos trocados quando `v[j] > v[j + 1]`) roda no
vetor `29 10 14 37 13 5`. Como fica o vetor depois de **duas** passadas?

- (A) `10 13 14 5 29 37`
- (B) `5 10 14 13 29 37`
- (C) `10 14 13 5 29 37`
- (D) `10 14 29 13 5 37`
- (E) `5 10 13 14 29 37`

<details><summary>Gabarito</summary>

**C.** A passada 1 leva o 37 até o fim: `10 14 29 13 5 37` (a alternativa D).
A passada 2 leva o 29 até a penúltima: `10 14 13 5 29 37`. Veja 0091.

</details>

**4.** O insertion sort roda no vetor `18 7 25 3 12 30 9`. Como fica o vetor
depois de inserir os **três** primeiros elementos depois do `v[0]` (ou seja,
ao fim da volta `j = 3` do laço externo)?

- (A) `7 18 25 3 12 30 9`
- (B) `3 7 12 18 25 30 9`
- (C) `3 7 9 25 12 30 18`
- (D) `7 18 3 25 12 30 9`
- (E) `3 7 18 25 12 30 9`

<details><summary>Gabarito</summary>

**E.** O 7 entra antes do 18, o 25 fica, o 3 atravessa a mão inteira. A parte
`v[0..3]` está em ordem entre si; o resto ainda não foi tocado. A (A) é o
estado depois de `j = 2`. Veja 0093.

</details>

**5.** O selection sort (acha o menor de `v[i..n-1]` e troca com `v[i]`) roda
no vetor `44 12 35 8 27 19`. Como fica o vetor depois de **três** passadas?

- (A) `8 12 19 27 35 44`
- (B) `8 12 19 44 27 35`
- (C) `8 12 35 44 27 19`
- (D) `8 12 19 35 27 44`
- (E) `12 8 19 44 27 35`

<details><summary>Gabarito</summary>

**B.** Passada 0: o 8 troca com o 44. Passada 1: o 12 já está no lugar.
Passada 2: o 19 troca com o 35, que salta para a última gaveta. Repare nesse
salto: é ele que faz o selection ser instável. Veja 0092.

</details>

**6.** Qual conjunto tem **só** algoritmos de ordenação estáveis, nas versões
clássicas vistas no módulo?

- (A) quick sort, merge sort e insertion sort
- (B) selection sort, bubble sort e merge sort
- (C) heap sort, insertion sort e bubble sort
- (D) insertion sort, merge sort e bubble sort
- (E) quick sort, heap sort e selection sort

<details><summary>Gabarito</summary>

**D.** Bubble e insertion só movem um elemento por cima de vizinhos
estritamente maiores; o merge pega o da esquerda no empate (`<=`). Quick,
selection e heap fazem trocas de longa distância e podem inverter iguais.
Veja 0096 e 0103.

</details>

**7.** A partição de Lomuto (a `PARTITION` do Cormen, com o último elemento
como pivô) é aplicada ao vetor `15 4 23 8 42 16 11`. Qual é o vetor depois da
partição e o índice do pivô (contando de 0)?

- (A) `4 8 11 15 42 16 23`, índice 2
- (B) `4 8 11 23 42 16 15`, índice 2
- (C) `8 4 11 15 42 16 23`, índice 2
- (D) `4 8 11 15 16 23 42`, índice 2
- (E) `11 4 8 15 42 16 23`, índice 0

<details><summary>Gabarito</summary>

**A.** O pivô é o 11. Só o 4 e o 8 são `<= 11`: o 4 troca com o 15 e o 8 troca
com o 15 de novo. No fim, o pivô troca com o 23, o primeiro da parte dos
maiores. No Cormen, que indexa a partir de 1, a `PARTITION` devolveria 3. A partição de
Hoare (dois índices que se cruzam) daria outro vetor. Veja 0095.

</details>

**8.** O quick sort com pivô no último elemento ordena um vetor de 8
elementos **já ordenado**. Quantas comparações com o pivô são feitas no total,
e qual é a ordem de crescimento desse caso?

- (A) 8, Θ(n)
- (B) 24, Θ(n log n)
- (C) 16, Θ(n log n)
- (D) 7, Θ(n)
- (E) 28, Θ(n²)

<details><summary>Gabarito</summary>

**E.** Cada partição deixa um lado vazio e o outro com um elemento a menos:
7 + 6 + 5 + 4 + 3 + 2 + 1 = 28 = n(n − 1)/2. É o pior caso do quick sort,
Θ(n²). Veja 0095 e o exemplo A190.

</details>

**9.** Quantas comparações a intercalação (merge) faz para juntar as listas
ordenadas `6 11 20 24` e `1 3 15 22`?

- (A) 4
- (B) 7
- (C) 8
- (D) 6
- (E) 16

<details><summary>Gabarito</summary>

**B.** Saem 1, 3, 6, 11, 15, 20 e 22, cada um depois de uma comparação. Aí a
segunda lista acaba e o 24 vai sem comparar. Juntar m + n elementos custa no
máximo m + n − 1 comparações (aqui, 7) e no mínimo min(m, n). Veja 0094.

</details>

**10.** Uma lista de alunos deve sair ordenada por **turma** e, dentro de cada
turma, por **nota** (uma chave composta). Você só pode usar duas passadas de
um algoritmo que ordena por uma chave simples. Qual estratégia funciona?

- (A) ordenar primeiro por turma e depois por nota, com um algoritmo estável
- (B) ordenar primeiro por nota e depois por turma, com o selection sort
- (C) ordenar primeiro por nota e depois por turma, com um algoritmo estável
- (D) qualquer uma das duas ordens, desde que o algoritmo seja estável
- (E) qualquer uma das duas ordens, com qualquer algoritmo

<details><summary>Gabarito</summary>

**C.** A última passada é a da chave principal (turma), e a estabilidade
preserva, dentro de cada turma, a ordem por nota deixada pela primeira. Na
(A), a passada por nota destrói o agrupamento por turma. Na (B), o selection
pode bagunçar as notas de uma mesma turma. É a ideia por trás do radix sort.
A alternativa com uma passada só é comparar a chave composta (turma, depois
nota) na `compara` do `qsort`. Veja 0096 e o assunto 0180, que aprofunda chave
composta.

</details>

## Para ler mais

- CORMEN, T. H.; LEISERSON, C. E.; RIVEST, R. L.; STEIN, C. *Algoritmos: teoria e prática*. 4. ed. Rio de Janeiro: GEN LTC, 2024. Caps. 2 (insertion sort e merge sort), 7 (quicksort) e 8 (estabilidade e ordenação em tempo linear).
- ZIVIANI, N. *Projeto de algoritmos: com implementações em Pascal e C*. 3. ed. São Paulo: Cengage Learning, 2010. Caps. 4 (ordenação) e 5 (pesquisa sequencial e binária).
- CELES, W.; CERQUEIRA, R.; RANGEL, J. L. *Introdução a estruturas de dados: com técnicas de programação em C*. 2. ed. Rio de Janeiro: Elsevier, 2016.
- FEOFILOFF, P. *Algoritmos em linguagem C*. Rio de Janeiro: Elsevier, 2009. Caps. de busca em vetor ordenado, ordenação elementar, mergesort e quicksort.
- TENENBAUM, A. M.; LANGSAM, Y.; AUGENSTEIN, M. J. *Estruturas de dados usando C*. São Paulo: Makron Books, 1995. Cap. 6 (classificação) e cap. 7 (busca).
- CELES, W.; RANGEL, J. L. *Apostila de estruturas de dados*. Rio de Janeiro: PUC-Rio, 2002. Parte III: ordenação e busca.
- LAUREANO, M. *Estrutura de dados com algoritmos e C*. Rio de Janeiro: Brasport, 2008. Caps. de busca e ordenação.
- ROCHA, A. M. A.; BORGES, A. R. O. S. *Programação, estruturas de dados e algoritmos em C*. Aveiro: Universidade de Aveiro. Cap. de pesquisa e ordenação.
- DEITEL, P.; DEITEL, H. *C: como programar*. 6. ed. São Paulo: Pearson Prentice Hall, 2011. Cap. 6 (classificação e pesquisa em arrays).
- KERNIGHAN, B. W.; RITCHIE, D. M. *C: a linguagem de programação padrão ANSI*. Rio de Janeiro: Campus, 1989. Seções 4.10 (recursão e quicksort) e 5.11 (ponteiros para funções).
- BLOCH, J. Extra, extra: read all about it: nearly all binary searches and mergesorts are broken. *Google Research Blog*, 2006. Disponível em: <https://research.google/blog/extra-extra-read-all-about-it-nearly-all-binary-searches-and-mergesorts-are-broken/>.
- CPPREFERENCE. *qsort, qsort_s* e *bsearch, bsearch_s*. Disponível em: <https://en.cppreference.com/w/c/algorithm>.
- LINUX MAN-PAGES. *qsort(3)* e *bsearch(3)*. Disponível em: <https://man7.org/linux/man-pages/man3/qsort.3.html>.
