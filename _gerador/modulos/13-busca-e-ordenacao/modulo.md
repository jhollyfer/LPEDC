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
AddressSanitizer (ou o UBSan) do gcc com as flags de estudo vai parar o programa. O enunciado
avisa.

{{indice}}

---

{{assuntos}}

---

## Desafios do módulo

Problemas para fechar o módulo, misturando os assuntos. Escreva em C e rode
com as flags de estudo.

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

Questões objetivas no formato da prova do mestrado: conceito, afirmações
combinadas, simulação à mão, cálculo e código com erro. Resolva no papel,
marque a letra e só depois abra o gabarito. Nas de ordenação, escreva o vetor
depois de cada passada, como nos testes de mesa dos assuntos.

**1.** Considere as afirmações sobre busca em vetores.

I. Numa busca sequencial por uma chave que está no vetor, o melhor caso faz
uma única comparação.
II. Se o vetor ordenado tem chaves repetidas, a busca binária devolve sempre a
posição da primeira ocorrência.
III. Dobrar o tamanho de um vetor ordenado aumenta em no máximo uma unidade o
número máximo de comparações da busca binária.

Marque a alternativa CORRETA.

- (A) Apenas I.
- (B) Apenas I e II.
- (C) Apenas I e III.
- (D) Apenas II e III.
- (E) I, II e III.

<details><summary>Gabarito</summary>

**C.** I é verdadeira: a chave na primeira posição custa 1 comparação. II é
falsa: com repetidas, a busca binária para na primeira que o `meio` encontrar,
e essa pode ser qualquer uma; o "sempre" derruba a afirmação. III é verdadeira:
o máximo é ⌊log₂ n⌋ + 1, e ⌊log₂ 2n⌋ = ⌊log₂ n⌋ + 1 (1000
elementos dão 10, 2000 dão 11). Veja 0089 e 0090.

</details>

**2.** Um vetor ordenado tem 5000 elementos. Usando a busca binária do assunto
0090 (intervalo fechado, uma comparação de igualdade por volta), qual é o
número máximo de elementos comparados com a chave, entre chave presente e
ausente?

- (A) 12
- (B) 13
- (C) 14
- (D) 2500
- (E) 5000

<details><summary>Gabarito</summary>

**B.** O máximo é ⌊log₂ n⌋ + 1 = ⌊12,29⌋ + 1 = 13. A (12) esquece o "+ 1"; D e E
são os custos da busca sequencial no pior caso (E) e no caso médio (D, quando
a chave está no vetor). Nenhuma chave, presente
ou ausente, passa de 13 comparações. Veja 0090.

</details>

**3.** A busca binária do assunto 0090 procura a chave 53 no vetor abaixo,
com `ini = 0` e `fim = 11`, e `meio = ini + (fim - ini) / 2`.

```c
int v[] = {4, 9, 13, 18, 22, 27, 31, 36, 42, 47, 53, 61};
```

Quantos elementos do vetor são comparados com a chave até ela ser encontrada?

- (A) 3
- (B) 4
- (C) 6
- (D) 11
- (E) 12

<details><summary>Gabarito</summary>

**A.** Meio 5 (27 < 53, `ini = 6`), meio 8 (42 < 53, `ini = 9`), meio 10 (53,
achou). São 3 comparações, contra 11 da busca sequencial. Veja 0090.

</details>

**4.** O selection sort do assunto 0092 escolhe o menor de `v[i..n-1]` com a
comparação `v[j] < v[menor]` (estrita) e troca com `v[i]`. Ele roda em
`9 4 7 4 1 8`. Como fica o vetor depois de **três** passadas (`i = 0, 1, 2`)?

- (A) `1 4 7 4 9 8`
- (B) `1 4 4 7 8 9`
- (C) `1 4 4 9 7 8`
- (D) `4 1 7 4 9 8`
- (E) `1 4 4 7 9 8`

<details><summary>Gabarito</summary>

**E.** Passada 0: o menor é o 1 (posição 4), que troca com o 9: `1 4 7 4 9 8`.
Passada 1: com `<` estrito, o menor continua sendo o 4 da posição 1 (o outro 4
não é *menor*), então não há troca. Passada 2: o menor de `7 4 9 8` é o 4, que
troca com o 7: `1 4 4 7 9 8`. A alternativa (A) é o estado depois de duas passadas. Veja
0092.

</details>

**5.** O insertion sort do assunto 0093 ordena `6 2 9 4 1`. Cada avaliação de
`v[i] > x` conta uma comparação, inclusive a que interrompe o laço. Quantas
comparações são feitas no total?

- (A) 6
- (B) 7
- (C) 8
- (D) 9
- (E) 10

<details><summary>Gabarito</summary>

**D.** Inserir o 2: 1 comparação. Inserir o 9: 1 (o 6 é menor, para). Inserir
o 4: 3 (9, 6, e o 2 que interrompe). Inserir o 1: 4 (9, 6, 4 e 2; o laço acaba
porque `i` chega a -1, sem comparação extra). Total 1 + 1 + 3 + 4 = 9. Num vetor já ordenado seriam só
n - 1 = 4. Veja 0093.

</details>

**6.** Considere as afirmações sobre algoritmos de ordenação, nas versões
clássicas vistas no módulo.

I. O insertion sort faz cerca de n comparações quando o vetor já está
ordenado.
II. O quick sort é estável.
III. O merge sort precisa de um vetor auxiliar de tamanho proporcional a n.
IV. O selection sort faz no máximo n - 1 trocas.

Marque a alternativa CORRETA.

- (A) Apenas I, III e IV.
- (B) Apenas I e III.
- (C) Apenas II e IV.
- (D) Apenas I, II e III.
- (E) I, II, III e IV.

<details><summary>Gabarito</summary>

**A.** I é verdadeira (o laço interno para na primeira comparação de cada
elemento). II é falsa: a partição troca elementos distantes e pode inverter
iguais. III é verdadeira: a intercalação grava num vetor auxiliar, Θ(n) de
espaço extra. IV é verdadeira: cada passada troca no máximo uma vez, e a
última passada nem acontece. Veja 0093, 0094, 0095, 0092 e 0096.

</details>

**7.** A partição de Lomuto (pivô no último elemento, como no assunto 0095) é
aplicada ao vetor `14 3 21 9 17 6 12`. Considere as afirmações sobre o
resultado.

I. O pivô termina no índice 3 (contando de 0).
II. Todos os elementos à esquerda do pivô são menores ou iguais a ele.
III. Os elementos à direita do pivô ficam na mesma ordem relativa que tinham
no vetor original.

Marque a alternativa CORRETA.

- (A) Apenas I.
- (B) Apenas II.
- (C) Apenas I e II.
- (D) Apenas II e III.
- (E) I, II e III.

<details><summary>Gabarito</summary>

**C.** Os elementos `<= 12` são 3, 9 e 6, então o pivô vai para o índice 3 e o
vetor fica `3 9 6 12 17 21 14`. I e II são verdadeiras. III
é falsa: no original, os maiores aparecem como 14, 21, 17 e, depois da
partição, como 17, 21, 14: a troca final do pivô com o primeiro dos maiores
(o 14) bagunça a ordem. É por isso que o quick sort não é estável. Veja 0095.

</details>

**8.** O código abaixo deveria devolver a posição de `x` em `v` (ordenado) ou
-1, mas tem um erro.

```c
int busca(int v[], int n, int x) {
    int ini = 0, fim = n - 1;
    while (ini < fim) {
        int meio = ini + (fim - ini) / 2;
        if (v[meio] == x) return meio;
        if (v[meio] < x) ini = meio + 1;
        else fim = meio - 1;
    }
    return -1;
}
```

Com `int v[] = {10, 20, 30, 40, 50, 60};` e `n = 6`, marque a alternativa
CORRETA.

- (A) A função devolve -1 apenas para chaves que não estão no vetor.
- (B) A função acha todas as chaves, mas faz uma comparação a mais que a versão correta.
- (C) A função falha só para `v[n - 1]`, a última posição.
- (D) A função lê `v[n]`, fora do vetor, para alguma chave.
- (E) `busca(v, 6, 20)` devolve -1 embora o 20 esteja no vetor.

<details><summary>Gabarito</summary>

**E.** Com `ini < fim`, o intervalo de um só elemento (`ini == fim`) nunca é
examinado. Para o 20: meio 2 (30 > 20, `fim = 1`), meio 0 (10 < 20,
`ini = 1`), e o laço acaba com `ini == fim`, sem olhar o 20. Rodando, o código
devolve -1 para 20, 40 e 60, e acerta 10, 30 e 50; por isso C é falsa. `meio`
nunca chega a `n`, então D também é falsa. A condição correta é `ini <= fim`.
Veja 0090.

</details>

**9.** O quick sort com pivô no último elemento (partição de Lomuto) ordena um
vetor de 12 elementos **já ordenado**. Quantas comparações de um elemento com
o pivô são feitas no total?

- (A) 11
- (B) 36
- (C) 78
- (D) 66
- (E) 144

<details><summary>Gabarito</summary>

**D.** Cada partição de um trecho de `m` elementos faz `m - 1` comparações com
o pivô e deixa um lado vazio, então o trecho seguinte tem `m - 1` elementos:
11 + 10 + ... + 1 = 66 = n(n - 1)/2, o pior caso Θ(n²). A (C) é a soma até 12,
que conta uma comparação do pivô consigo mesmo. Veja 0095.

</details>

**10.** Sobre o merge sort, marque a alternativa INCORRETA.

- (A) Faz Θ(n log n) comparações no melhor, no médio e no pior caso.
- (B) É sempre mais rápido que o insertion sort, para qualquer vetor.
- (C) Precisa de espaço extra proporcional a n na versão com vetor auxiliar.
- (D) É estável se, no empate, a intercalação tira o elemento da metade esquerda.
- (E) Divide o vetor ao meio, ordena cada metade e intercala os resultados.

<details><summary>Gabarito</summary>

**B.** O "sempre" entrega a pegadinha: num vetor já ordenado, o insertion sort
faz só n - 1 comparações, menos que o merge sort. As demais são verdadeiras: o
merge sort não depende da ordem inicial (A), usa o vetor auxiliar (C) e é
estável com `<=` na intercalação (D). Veja 0094, 0093 e 0096.

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
