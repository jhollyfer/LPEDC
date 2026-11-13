# Módulo 13 · Busca e ordenação

Procurar e ordenar estão em toda lista de contatos, extrato bancário e busca
de loja virtual. Aqui você abre essas caixas pretas: a busca binária acha um
item entre um milhão em 20 passos, e a comparação `a - b` pode dar errado no C.

**Progressão.** O módulo usa vetores, ponteiros, recursão, `malloc` e structs
dos módulos anteriores e o Big-O do módulo 10: em cada algoritmo você **conta
comparações e trocas** e confere a teoria. O módulo 14 troca o vetor por
árvores: a busca binária vira BST e o heapsort fecha as ordenações.

## O que você vai aprender

- **busca sequencial**: custo O(n) e sentinela
- **busca binária**: O(log n) em vetor ordenado, invariantes e erros de um
- **bubble**, **selection** e **insertion sort**, O(n²)
- **merge sort** e **quick sort**, O(n log n) por dividir e conquistar
- **estabilidade**, ordenação in-place e como escolher o algoritmo
- **`qsort`** e **`bsearch`**, com funções de comparação corretas

## Antes de começar

Nos diagramas, cada linha de gavetas é um momento do algoritmo: **amarela** é
a gaveta comparada (ou o menor achado), **roxa** é a posição ou o pivô da vez,
**verde** já está no lugar e **cinza** foi descartada. Faça o **Passo a passo**
no papel antes de conferir a tabela.

O contador de comparações (`static` ou ponteiro) não faz parte do algoritmo:
é o cronômetro do custo. O tempo de relógio varia de máquina para máquina; o
número de comparações, não.

Compile com o gcc e as flags de estudo: o AddressSanitizer e o UBSan param o
programa nos erros de índice e de overflow.

{{indice}}

---

{{assuntos}}

---

### Desafios do módulo

Problemas para fechar o módulo, misturando os assuntos. Escreva em C e compile
com o gcc e as flags de estudo.

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

É a partição de três vias com pivô 1 (a "bandeira holandesa" de Dijkstra),
com `lt`, `i` e `gt`. 0 vai para a frente (`troca(v[lt], v[i])`, `lt++`,
`i++`), 2 vai para o fim (`troca(v[i], v[gt])`, `gt--`), 1 fica (`i++`).
Resultado: `0 0 0 1 1 1 2 2 2`, com n comparações.

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

### Questões do POSCOMP

Questões reais do POSCOMP (SBC) sobre este módulo. O enunciado está no caderno oficial: abra o link, resolva e confira o gabarito.

| Ano | Questão | Assunto | Gabarito | Prova |
| --- | --- | --- | --- | --- |
| 2025 | 24 | Shellsort e ordenação h-ordenada | a conferir no gabarito oficial | [caderno](https://www2.uesb.br/curso/cienciadacomputacao/wp-content/uploads/2026/05/caderno_2025.pdf) |

O gabarito oficial de 2025 não estava disponível quando este material foi montado.


### Questões de provas do PPGI

Questões reais das provas de conhecimento do PPGI/UFAM, na íntegra e com o gabarito oficial. Resolva no papel, em 3 minutos por questão, e só depois abra o gabarito.

**Edital 032/2016 · Questão 04**

Se você tem que implementar um algoritmo de ordenação que tem um tempo de execução competitivo quando comparado a outros, e que não varia muito seu desempenho em função da entrada de dados fornecida. Qual das opções é melhor?

- a) Ordenação por inserção
- b) Heapsort
- c) Quicksort
- d) Tanto Quicksort quanto Heapsort atendem aos requisitos
- e) Hash

<details><summary>Gabarito</summary>

**B.** Heapsort faz O(n log n) em qualquer entrada; o Quicksort varia (pior caso O(n²)). Assunto 0096.

</details>

**Edital 032/2016 · Questão 10**

Considere os códigos de funções abaixo, assumindo que os mesmos são usados dentro de um programa e que os todos os cabeçalhos necessários são incluídos:

```c
/*QUADRO I) função que retorna 1 se a chave
de busca chave, passada como parâmetro, ocorre
dentro de um vetor de inteiros ordenado e
retorna 0 caso a chave não ocorra no vetor. O
vetor tem tamanho determinado pelo parâmetro
tm */
int buscaChave(int v[], int chave, int tm) {
  while((tm>= 0) && (v[tm]!= chave)) tm --;
  if (tm >= 0) return 1;
  return 0;
}
```

```c
/* QUADRO II) Conta ocorrências de uma
chave na lista encadeada, retornando o total de
ocorrências , zero caso a chave não ocorra
*/
int ContaOcorrenciasChave(tipoNo *prim, int
chave) {
  tipoNo *aux = prim;
  int cont = 0;
  int x;;
  for (x = 0; aux[x] != NULL; x++){
    if(aux[x]. dado == chave) cont++;
  }
  return cont;
}
```

Marque a alternativa correta dentre as afirmações abaixo:

- a) Os dois códigos executam as tarefas propostas sem gerar qualquer tipo de erro de lógica ou de vazamento de memória
- b) Apenas os código I executa sem erros a tarefa proposta
- c) Apenas o código II executa sem erros a tarefa proposta
- d) Os dois códigos geram erros de vazamento de memória ou de falha de segmentação
- e) Nenhuma das alternativas anteriores

<details><summary>Gabarito</summary>

**B.** Assunto 0089.

</details>

**Edital 032/2016 · Questão 16**

Considere um vetor não ordenado utilizado para armazenar chaves únicas (sem repetição). Pode-se afirmar que:

I) O melhor algoritmo para busca no vetor é a busca binária mesmo que o vetor não esteja ordenado, independente do número de elementos do vetor e da quantidade de buscas a serem realizadas\
II) Uma busca binária implementada no vetor não funcionaria adequadamente, fornecendo resultados errados a menos que fosse feita uma ordenação\
III) Um algoritmo de busca sequencial funcionaria e daria resultados comparando a chave com todas as posições do vetor na pior das hipóteses\

Sobre as afirmações, sabe-se que:

- a) Apenas as afirmações I e III estão corretas
- b) Apenas as afirmações II e III estão corretas
- c) Todas as afirmações estão corretas
- d) Todas as afirmações estão erradas
- e) Nenhuma das alternativas anteriores

<details><summary>Gabarito</summary>

**B.** I é falsa (a binária exige vetor ordenado), II e III são verdadeiras. Assunto 0089.

</details>

**Edital 032/2016 · Questão 18**

Considere que o vetor abaixo será ordenado com o algoritmo de ordenação por seleção

`4 5 2 3 17 2 1 22`

Considerando-se que o vetor tem sua primeira posição contada como 0 (zero), a primeira troca de valores entre posições do vetor ocorrerá entre:

- a) posição 0 e posição 2
- b) posição 0 e posição 7
- c) Posição 0 e posição 6
- d) Posição 1 e posição 6
- e) Posição 3 e posição 5

<details><summary>Gabarito</summary>

**C.** O menor é 1, na posição 6, que troca com a posição 0. Assunto 0092.

</details>

**Edital 032/2016 · Questão 19**

Considere os vetores abaixo

VetI: `1 2 3 4 5 6 8 7`
VetII: `7 8 8 5 4 3 2 1`

E considere as afirmações a seguir:

I) A ordenação por inserção é melhor que a ordenação por seleção em VetI se considerarmos o número de comparações entre chaves realizadas pelos dois algoritmos\
II) O RADIX sort executado em base 10 realiza um número menor de operações (instruções) nos dois casos quando comparado ao mergesort\
III) O RADIX sort executado em base 10 realiza um número menor de operações apenas em VetII quando comparado ao mergesort, ocorrendo o oposto em VetI\

Sobre as afirmações, sabe-se que:

- a) Apenas a afirmação I é verdadeira
- b) Apenas a afirmação II é verdadeira
- c) Apenas a afirmação III é verdadeira
- d) Apenas as afirmações I e II são verdadeiras
- e) Apenas as afirmações I e III são verdadeiras

<details><summary>Gabarito</summary>

**D.** I verdadeira (inserção faz ~n comparações em quase ordenado, seleção sempre n(n-1)/2); II verdadeira (radix de 1 dígito, ~n+10 passos contra ~n log n); III falsa. Assunto 0093.

</details>

**Edital 053/2016 · Questão 01**

Seja um vetor de inteiros com 400 elementos distintos ordenados em ordem crescente. Qual é o número máximo de iterações necessárias para encontrar um elemento qualquer desse vetor, caso seja utilizado o algoritmo de busca binária?

- a) 9
- b) 8
- c) 7
- d) 200
- e) 400

<details><summary>Gabarito</summary>

**A.** ⌊log2 400⌋+1 = 9; conferido em C (máximo de 9 iterações). Assunto 0090.

</details>

**Edital 053/2016 · Questão 04**

Considere que o vetor abaixo será ordenado com o algoritmo de ordenação por seleção.

`4 5 5 3 17 2 1 22`

Considerando-se que o vetor tem sua primeira posição contada como 0 (zero), a segunda troca de valores entre posições do vetor ocorrerá entre:

- a) Posição 0 e posição 2
- b) Posição 0 e posição 7
- c) Posição 1 e posição 5
- d) Posição 1 e posição 6
- e) Posição 3 e posição 5

<details><summary>Gabarito</summary>

**C.** 1ª troca 0 e 6 (vira 1 5 5 3 17 2 4 22); 2ª troca 1 e 5 (o 2). Conferido em C. Assunto 0092.

</details>

**Edital 053/2016 · Questão 15**

Considere as afirmações a seguir sobre os algoritmos de ordenação Quicksort, MergeSort, HeapSort e InsertionSort

I) São algoritmos estáveis: InsertionSort, QuickSort e MergeSorte\
II) Pior caso tem número de operações quadrático (proporcional a uma constante vezes n²): InsertionSort, QuickSort\
III) Utiliza um espaço extra proporcional a n² (proporcional ao quadrado do número de elementos): HeapSort,\
IV) A ordem das entradas é incapaz de influenciar o desempenho do algoritmo: InsertionSort, MergeSort\

Marque a alternativa que indica TODAS as afirmações INCORRETAS feitas:

- a) I e IV
- b) I , III e IV
- c) I, II e III
- d) I, II, III e IV
- e) II e IV

<details><summary>Gabarito</summary>

**B.** Incorretas: I (Quick não é estável), III (Heap usa O(1) extra), IV (Insertion depende da ordem). Assunto 0096.

</details>

**Edital 053/2016 · Questão 17**

Considere os códigos de funções abaixo, assumindo que os mesmos são usados dentro de um programa e que os todos os cabeçalhos necessários são incluídos:

```c
/*QUADRO I) função que retorna 1 se a chave
de busca chave, passada como parâmetro, ocorre
dentro de um vetor de inteiros ordenado e
retorna 0 caso a chave não ocorra no vetor. O
vetor tem tamanho determinado pelo parâmetro
tm */
int buscaChave(int v[],int chave,int tm) {
  while((tm>= 0) && (v[tm]!= chave)) tm--;
  if (tm >= 0) return 0;
  return 1;
}
```

```c
/* QUADRO II) Conta ocorrências de uma
chave na lista encadeada, retornando o total de
ocorrências , zero caso a chave não ocorra
*/
int ContaOcorrenciasChave(tipoNo *prim, int
chave) {
  tipoNo *aux = prim;
  int cont = 0;
  int x;
  for (x = 0; aux[x] != NULL; x++){
    if(aux[x]. dado == chave) cont++;
  }
  return x;
}
```

Marque a alternativa correta dentre as afirmações abaixo:

- a) Os dois códigos executam as tarefas propostas sem gerar qualquer tipo de erro de lógica ou de vazamento de memória
- b) Apenas o código I executa sem erros a tarefa proposta
- c) Apenas o código II executa sem erros a tarefa proposta
- d) Os dois códigos geram erros de vazamento de memória ou de falha de segmentação
- e) Nenhuma das alternativas anteriores

<details><summary>Gabarito</summary>

**E.** Assunto 0089.

</details>

**Edital 024/2017 · Questão 03**

Marque a alternativa CORRETA.
Qual dos algoritmos abaixo apresenta o menor custo (em termos de número movimentações de elementos realizadas) ao considerar-se, para cada algoritmo, a pior disposição possível para os elementos do vetor a ser ordenado. Considere que o vetor a ser ordenado é muito grande, acima de 1 milhão de elementos.

- a) Heapsort
- b) Quicksort
- c) Inserção
- d) Seleção
- e) Mergesort

<details><summary>Gabarito</summary>

**D.** seleção faz no máximo n-1 trocas; heap e merge movem O(n log n) Assunto 0092.

</details>

**Edital 024/2017 · Questão 12**

Sobre as afirmações abaixo:

I. A busca sequencial só pode ser realizada corretamente em vetores que não estejam ordenados\
II. A busca por uma chave em um vetor ordenado pode ser realizada corretamente com número constante de operações, não dependendo do tamanho do vetor.\
III. Pode-se encontrar o maior elemento de um vetor não ordenado com um algoritmo que realiza um número de operações proporcional ao tamanho do vetor na pior das situação possível para o algoritmo.\

Pode-se dizer que:

- a) Apenas I está correta
- b) Apenas II está correta
- c) Apenas III está correta
- d) Apenas II e III estão corretas
- e) Apenas I e III estão corretas

<details><summary>Gabarito</summary>

**C.** I falsa (sequencial vale em ordenado), II falsa (busca em vetor ordenado é O(log n)), III verdadeira (varredura O(n)) Assunto 0089.

</details>

**Edital 055/2017 · Questão 08**

Marque a alternativa CORRETA.
Considerando um array R que contém 1.000.000 de chaves ordenadas, assinale o número máximo de acessos a R necessários para encontrar uma determinada chave ao se utilizar o algoritmo de busca binária.

- A) 10
- B) 20
- C) 40
- D) 80
- E) 160

<details><summary>Gabarito</summary>

**B.** floor(log2 1.000.000)+1 = 20 Assunto 0090.

</details>

**Edital 055/2017 · Questão 12**

Qual dos algoritmos abaixo apresenta o menor custo (em termos de número comparações entre elementos) ao considerar-se que o vetor passado está previamente ordenado, a menos da ocorrência de duas chaves consecutivas que estão com posições trocadas. Considere que o vetor a ser ordenado é muito grande, com mais de 1 milhão de elementos.

- A) Heapsort.
- B) Quicksort.
- C) Inserção.
- D) Seleção.
- E) Nenhuma das anteriores, pois todos apresentam custo igual.

<details><summary>Gabarito</summary>

**C.** inserção faz cerca de n comparações; heap e quick fazem n log n ou pior; seleção n² Assunto 0093.

</details>

**Edital 055/2017 · Questão 14**

Sobre as afirmações abaixo:

I. Pode-se implementar uma busca em um vetor não ordenado a custo máximo inferior a n/2 operações, onde n é o número de elementos do vetor, desde que a chave buscada ocorra no vetor, não importando qual a posição em que a mesma ocorre.\
II. A busca por uma chave em um vetor ordenado pode ser realizada corretamente com um número de operações proporcional a log2 n, onde n é o número de elementos do vetor.\
III. O número de comparações realizadas para determinar se uma chave de busca está ou não em um vetor não ordenado é sempre menor do que o número de comparações envolvendo a mesma chave de busca em uma lista encadeada dinâmica, desde que a quantidade e a ordem dos elementos inseridos nas duas estruturas seja a mesma.\

Marque a alternativa CORRETA:

- A) Apenas a afirmativa I está correta.
- B) Apenas a afirmativa II está correta.
- C) Apenas a afirmativa III está correta.
- D) Todas as afirmativas estão corretas.
- E) Nenhuma das afirmativas está corretas.

<details><summary>Gabarito</summary>

**B.** I falsa (pior caso n), II verdadeira, III falsa (mesma contagem) Assunto 0089.

</details>

**Edital 055/2017 · Questão 19**

Suponha que você recebeu a tarefa de depurar uma implementação de Quicksort, cujo objetivo é classificar um vetor em ordem decrescente. Após a primeira etapa da partição ser concluída, o conteúdo do vetor está na seguinte ordem:

`20 22 24 18 13 9 3 10`

Qual das seguintes afirmações está CORRETA sobre a fase de partição?

- A) O pivô que gerou a partição pode ter o valor 13 ou 18.
- B) O pivô que gerou a partição pode ter o valor 13, mas não pode ter o valor 18.
- C) O pivô que gerou a partição pode ter o valor 18, mas não pode ter o valor 13.
- D) O pivô que gerou a partição não pode ter o valor 13 nem 18.
- E) O conteúdo do vetor não pode representar o resultado da etapa partição.

<details><summary>Gabarito</summary>

**A.** 18 (índice 3) e 13 (índice 4) separam maiores à esquerda e menores à direita Assunto 0095.

</details>

**Edital 023/2018 · Questão 01**

Dois vetores ordenados, contendo, cada um deles, N números inteiros, precisam ser unidos em outro vetor maior, que conterá os 2N números, que também serão armazenados de forma ordenada. A complexidade de tempo de melhor caso desse processo será, então,

- a) O(1), pois se precisa fazer apenas uma cópia simples de cada um dos elementos originais.
- b) O(log N), pois se usa a busca binária para determinar qual será o próximo elemento copiado para o vetor de destino.
- c) O(N), pois se precisa fazer uma cópia de cada um dos elementos originais, o que implica uma varredura completa de cada vetor de origem.
- d) O(Nlog N), pois se precisa fazer uma busca de cada elemento para depois inseri-lo no vetor de destino.
- e) O(N²), pois, como há dois vetores, precisa-se fazer dois laços de forma aninhada (um dentro do outro), gerando uma multiplicação das quantidades de elementos.

<details><summary>Gabarito</summary>

**C.** Intercalar dois vetores ordenados copia 2N elementos, então O(N) mesmo no melhor caso. Assunto 0094.

</details>

**Edital 023/2018 · Questão 12**

Considere o vetor ordenado abaixo e indique quais os valores serão comparados com a chave de busca de valor 20 se for realizada uma busca binária no vetor. Considere que a primeira posição do vetor é a posição 0.

`32 | 8 | 12 | 16 | 20 | 24 | 28 | 16 | 36`

- a) Chaves 20, 12, 8 e 4, nessa ordem
- b) Chaves 20, 28,32 e 36, nessa ordem
- c) Chaves 4, 8, 12, 16 e 20, nessa ordem
- d) Chaves 36, 32, 28 e 24, nessa ordem
- e) Apenas a chave 20

<details><summary>Gabarito</summary>

**E.** A posição do meio (índice 4) já vale 20: uma única comparação. Assunto 0090.

</details>

**Edital 023/2018 · Questão 14**

Considere as afirmações sobre busca binária:

I) é utilizada apenas sobre vetores ordenados\
II) pode determinar se uma chave está ou não com um número de comparações de chave inferior a 2log2 n passos, onde n é o tamanho do vetor.\
III) Supera a busca sequencial quando o vetor é grande, por exemplo com mais que mil elementos, e está ordenado.\

- a) Apenas as afirmações II e III estão corretas
- b) Apenas as afirmações I e II estão corretas
- c) Apenas as afirmações I e III estão corretas
- d) Todas as afirmações estão corretas
- e) Nenhuma das alternativas anteriores

<details><summary>Gabarito</summary>

**D.** As três são verdadeiras (ordenado, no máximo log2 n + 1 comparações, supera a sequencial em n grande). Assunto 0090.

</details>

**Edital 023/2018 · Questão 17**

Considerando os algoritmos de ordenação Quicksort, MergeSort, HeapSort e InsertionSort

I. São algoritmos estáveis: HeapSort, QuickSort e MergeSort\
II. A complexidade de uso de espaço é O(n²): HeapSort,\
III. A ordem das entradas é incapaz de influenciar o desempenho do algoritmo: InsertionSort, MergeSort\
IV. Melhor caso da complexidade de tempo em Ω(n) : InsertionSort\
V. A complexidade de uso de espaço é O(n): MergeSort\

Marque a alternativa que indica SOMENTE afirmações INCORRETAS feitas:

- a) I IV e V
- b) I , III e IV
- c) I, II, III e IV
- d) I, II e III
- e) II e V

<details><summary>Gabarito</summary>

**D.** I, II e III são falsas; IV e V são verdadeiras. A alternativa D lista só as incorretas. Assunto 0096.

</details>

**Edital 061/2018 · Questão 06**

Marque a alternativa CORRETA. O método de ordenação QuickSort (ordenação rápida) é um método sofisticado de ordenação de vetores que:

- a) Considera em cada passo somente um único elemento sucessor na sequência fonte e todos os elementos do vetor destino para encontrar o ponto correto da inserção.
- b) Ordena todos os elementos que estiverem a intervalos de 4 posições entre si na sequência corrente.
- c) É baseado nos princípios de ordenação por inserção direta através de incrementos decrescentes.
- d) O Quicksort é um algoritmo que pode usar espaço extra linear no pior caso.
- e) É baseado nos princípios de ordenação por seleção direta que consiste na seleção repetitiva da menor dentre as chaves de n elementos, e depois dentre os n-1 elementos restantes, e assim por diante.

<details><summary>Gabarito</summary>

**D.** No pior caso a pilha de recursão do quicksort chega a O(n). Assunto 0095.

</details>

**Edital 033/2019 · Questão 01**

Sabendo que o algoritmo Quick Sort classifica os elementos em ordem crescente usando o primeiro elemento como pivô, qual das seguintes sequências de entrada irá requerer o maior número de comparações quando o algoritmo for aplicado?

- a) 22 25 33 42 56 67 89
- b) 63 70 47 42 36 38 73
- c) 42 25 22 33 67 56 89
- d) 13 52 25 58 10 22 17
- e) 23 25 33 42 11 22 30

<details><summary>Gabarito</summary>

**A.** Com pivô no primeiro, a entrada já ordenada é o pior caso: 21 comparações contra 11 a 12 nas outras (rodado em C). Assunto 0095.

</details>

**Edital 033/2019 · Questão 14**

Dada a seguinte entrada (34, 8, 64, 51, 32, 21) e empregando o algoritmo Insertion Sort, qual será a aparência do array de elementos após a segunda rodada de ordenação?

- a) 8, 21, 32, 34, 51, 64
- b) 8, 32, 34, 51, 64, 21
- c) 8, 34, 51, 64, 32, 21
- d) 8, 34, 64, 51, 32, 21
- e) 8, 51, 64, 34, 32, 21

<details><summary>Gabarito</summary>

**D.** Após a 1ª rodada: 8 34 64 51 32 21; a 2ª insere o 64 sem mover nada. Assunto 0093.

</details>

**Edital 033/2019 · Questão 18**

Qual das afirmações abaixo sobre Insertion Sort está CORRETA?

- a) Existem arrays de tamanhos variados N tais que o Insertion Sort é executado em Θ(N).
- b) Existem arrays de tamanhos variados N tais que o Insertion Sort é executado em Θ(1).
- c) Existem arrays de tamanhos variados N tais que o Insertion Sort é executado em Θ(N³).
- d) Existem arrays de tamanhos variados N tais que o Insertion Sort é executado em Θ(2^N).
- e) Nenhuma das sentenças anteriores está correta.

<details><summary>Gabarito</summary>

**A.** Insertion sort em vetor já ordenado roda em Θ(N). Assunto 0093.

</details>

**Edital 060/2019 · Questão 04**

Considere um vetor com 25 elementos (posição 0 até a posição 24) que representam os números primos entre 1 a 100, em ordem crescente (Ex: [2, 3, 5, 7, 11, 13, ..., 89, 97]). Empregando pesquisa binária, quantos itens do vetor precisam ser examinados antes de se concluir que o número 52 não está no vetor e, portanto, não é primo?

- a) 12
- b) 7
- c) 5
- d) 1
- e) 4

<details><summary>Gabarito</summary>

**C.** Posições examinadas: 12, 18, 15, 13, 14 = 5. Assunto 0090.

</details>

**Edital 060/2019 · Questão 08**

Qual dos seguintes algoritmos apresenta tempo O(n) quando ordenando um vetor com n elementos idênticos de texto?

- a) Heapsort
- b) Insertion sort
- c) Mergesort
- d) Quicksort
- e) Nenhum dos algoritmos apresenta tempo O(n) para essa entrada

<details><summary>Gabarito</summary>

**B.** Insertion sort faz n-1 comparações em entrada ordenada ou igual. Assunto 0093.

</details>

**Edital 060/2019 · Questão 17**

Suponha que, no pior caso, um algoritmo Merge Sort leve 30 segundos para ordenar uma entrada de tamanho 64. Qual das opções a seguir se aproxima mais do tamanho máximo de entrada de um problema que pode ser resolvido em 6 minutos?

- a) 256
- b) 1024
- c) 512
- d) 2048
- e) 4096

<details><summary>Gabarito</summary>

**C.** c·n·log n: 64 x 6 = 384 ↔ 30 s; 360 s dá n·log n = 4608, que é 512 x 9. Assunto 0094.

</details>

**Edital 060/2019 · Questão 18**

Considere que os seguintes elementos {5,4,3,2,1} foram inseridos nesta ordem em um vetor. Em seguida, você aplicou o algoritmo Insertion Sort nele. Qual é a sequência de passos feitos durante o uso do Insertion Sort neste vetor?

- a) 4 5 3 2 1 / 3 4 5 2 1 / 2 3 4 5 1 / 1 2 3 4 5
- b) 5 4 3 1 2 / 5 4 1 2 3 / 5 1 2 3 4 / 1 2 3 4 5
- c) 4 3 2 1 5 / 3 2 1 5 4 / 2 1 5 4 3 / 1 5 4 3 2
- d) 4 5 3 2 1 / 2 3 4 5 1 / 3 4 5 2 1 / 1 2 3 4 5
- e) 4 5 3 1 2 / 2 3 4 5 1 / 3 4 5 2 1 / 1 2 3 4 5

<details><summary>Gabarito</summary>

**A.** Cada rodada insere o próximo elemento: 4 5 3 2 1, 3 4 5 2 1, 2 3 4 5 1, 1 2 3 4 5. Assunto 0093.

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
