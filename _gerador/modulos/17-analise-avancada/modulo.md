# Módulo 17 · Medindo algoritmos recursivos

No módulo 10 você aprendeu a contar passos e a ler a classe de um código
pelos laços: um laço é O(n), dois aninhados são O(n²), um laço que divide por
2 é O(log n). Isso funciona até aparecer uma função que chama a si
mesma. Quanto custa o merge sort? O "n log n" que você leu no módulo 13 veio
de um desenho e de um pouco de fé. Aqui ele vira conta.

Este módulo traz as ferramentas que faltavam. A **recorrência** transforma o código recursivo numa equação, e a **árvore de
recursão** resolve a equação somando nível por nível. O **teorema mestre**
resolve de uma vez as recorrências de divisão e conquista mais comuns. A
**análise amortizada** explica por que o vetor que dobra é barato, mesmo
copiando tudo de vez em quando. E o **limite inferior** troca a pergunta
"quanto custa este algoritmo?" por "dá para fazer melhor?". Para ordenar
comparando, não dá: n log n é o piso.

No último assunto, você usa tudo isso para prever quanto
tempo quatro ordenações levam com 1 milhão de elementos, a partir de uma
medida com 16 mil, e confere a previsão no computador.

## O que você vai aprender

- escrever a **recorrência** de uma função recursiva lendo o código, e resolvê-la com a **árvore de recursão**
- a diferença entre `T(n-1)` e `T(n/2)`, e por que "duas chamadas" pode ser Θ(n) ou Θ(2ⁿ)
- o **teorema mestre**: os três casos, como reconhecer cada um e quando ele **não** se aplica
- a **análise amortizada**: método agregado e método do banqueiro no vetor que dobra, no contador binário e na pilha com multipop
- a **árvore de decisão** e o limite **Ω(n log n)** para ordenar por comparação
- as notações **Θ** e **Ω**, ao lado do **O** que você já conhece
- **medir** com `clock()` e contadores, e **prever** o tempo para entradas grandes

## Antes de começar

Este módulo usa sem cerimônia: **recursão** e pilha de chamadas (0031 a
0033), **Big-O** e contagem de passos (0071 e 0072), o **vetor que cresce**
(0055 e 0075), **pilha** (0082) e **fila** (0085), as ordenações do módulo 13
(merge sort e quick sort, principalmente) e o **heap** (0102 e 0103). Também
aparecem ponteiros para função (0050), para guardar várias ordenações num
vetor.

Matemática: só potências e logaritmos. Lembre que `log₂ n` é "quantas vezes
dá para dividir n por 2 até chegar em 1" (`log₂ 1024 = 10`), e que
`log_b a` é o expoente que leva `b` a `a` (`log₂ 8 = 3`, `log₃ 9 = 2`). No C,
`log2` e `log` ficam em `<math.h>`, e o `rodar` já liga a biblioteca
matemática (`-lm`).

O último assunto tem um TAD na pasta, `ordena.h` e `ordena.c`, com as quatro
ordenações e um contador de comparações. O `rodar` compila o `ordena.c` junto
com qualquer exemplo ou exercício da pasta. Alguns programas medem **tempo**:
os números de tempo mudam de máquina para máquina e de uma execução para
outra; os de comparações, não. Os exercícios de "ache o erro" trazem o bug de
propósito, e o enunciado avisa.

Nos diagramas da ideia, **roxo** é trabalho sendo feito (uma chamada, um
nível), **verde** é o que domina o custo ou o resultado, **amarelo** marca um
empate e **vermelho** é o caro demais ou o que deu errado. Abra cada
recorrência à mão no **Passo a passo**: quase todo exemplo conta algo (chamadas, cópias,
comparações) e confere a contagem com a fórmula.

{{indice}}

---

{{assuntos}}

---

## Desafios do módulo

Problemas para fechar o módulo, misturando os assuntos. Resolva no papel e,
sempre que der, confira com um programa em C rodado com o `rodar`.

**1. O pior quick sort.** Com o pivô sempre no último elemento, um vetor já
ordenado faz o quick sort particionar em pedaços de tamanho `n - 1` e 0.
Escreva a recorrência das comparações, resolva e calcule para `n = 10.000`.
Compare com o melhor caso.

<details><summary>Resposta</summary>

`T(n) = T(n-1) + (n - 1)`, com `T(1) = 0`: a árvore vira uma linha, e a soma
é `(n - 1) + (n - 2) + ... + 1 = n(n - 1)/2`. Para 10.000: **49.995.000
comparações**. No melhor caso (pivô sempre no meio), `T(n) = 2 T(n/2) + n`,
uns `n log₂ n ≈ 133 mil`. Quase 400 vezes menos. Para conferir, conte as
comparações de um quick sort com pivô no fim num vetor `0, 1, ..., 9999`.

</details>

**2. Três terços.** Resolva `T(n) = 3 T(n/3) + n`, com `T(1) = 1`, pelo
teorema mestre e pela árvore. Quanto dá `T(81)`?

<details><summary>Resposta</summary>

`a = 3`, `b = 3`, `k = 1`: `b^k = 3 = a`, caso 2, **Θ(n log n)**. Na árvore,
cada nível custa `n` e são `log₃ n + 1` níveis: `T(n) = n (log₃ n + 1)`.
Com `n = 81 = 3⁴`, são 5 níveis de 81: **T(81) = 405**.

</details>

**3. Pedaços de tamanhos diferentes.** O teorema mestre não resolve
`T(n) = T(n/2) + T(n/4) + n`. Use a árvore de recursão para achar a classe.

<details><summary>Resposta</summary>

O nível 0 custa `n`. O nível 1 tem pedaços de `n/2` e `n/4`: custa `3n/4`. O
nível 2 custa `9n/16`, e assim por diante: cada nível custa `3/4` do
anterior. A soma de uma progressão geométrica de razão `3/4` fica abaixo de
`4n`, e o primeiro nível já é `n`. Logo **Θ(n)**: a raiz domina, como num
caso 3.

</details>

**4. Quick sort azarado, mas nem tanto.** Um quick sort sempre divide o
pedaço na proporção 1 para 9 (10% de um lado, 90% do outro). Ele continua
O(n log n)? Quantos níveis tem a árvore para `n = 1 milhão`?

<details><summary>Resposta</summary>

Sim. Cada nível da árvore custa no máximo `n` (os pedaços de um nível não se
sobrepõem). O caminho mais fundo é o que segue sempre os 90%: o tamanho cai
por `10/9` a cada nível, então são `log_{10/9} n` níveis, uns `6,6 log₂ n`.
Para 1 milhão, **cerca de 131 níveis**, contra 20 da divisão ao meio. A
constante piora, mas continua **Θ(n log n)**. Qualquer proporção fixa serve;
o desastre é dividir em `n - 1` e 0.

</details>

**5. A tabela hash que dobra.** Uma tabela hash do módulo 15 começa com
espaço para 1 elemento e dobra de tamanho quando enche, reinserindo todos os
elementos na tabela nova. Quantas reinserções acontecem até ela guardar 1024
elementos? Qual o custo amortizado por inserção?

<details><summary>Resposta</summary>

As mudanças acontecem com 1, 2, 4, ..., 512 elementos: `1 + 2 + 4 + ... +
512` dá **1023 reinserções**, menos que `2 · 1024`. Somando as 1024 inserções
normais, menos de 3 operações por elemento: **O(1) amortizado**. É a mesma
conta do vetor que dobra do assunto 0116.

</details>

**6. O contador inteiro.** Um contador binário de 10 bits vai de 0 até 1023,
um incremento por vez. Quantas trocas de bit acontecem no total?

<details><summary>Resposta</summary>

O bit 0 troca 1023 vezes, o bit 1, 511, o bit 2, 255... o bit 9, 1 vez. A
soma é `(1024 - 1) + (512 - 1) + ... + (2 - 1) = 2046 - 10`:
**2036 trocas**. Em geral, `n` incrementos a partir do zero fazem `2n` menos
a quantidade de bits 1 de `n`: aqui, `2 · 1023 - 10`. Menos de 2 por incremento, como no A231.

</details>

**7. Intercalar é ótimo?** Juntar duas listas ordenadas de 4 elementos cada
custa até 7 comparações na intercalação do merge sort. Algum método faz
menos no pior caso?

<details><summary>Resposta</summary>

Não. Conte as folhas da árvore de decisão: o resultado é decidido por
**quais 4 das 8 posições** ficam com elementos da primeira lista, e isso dá
`C(8, 4) = 70` respostas possíveis. Com `h` comparações cabem `2^h` folhas:
`2^6 = 64 < 70 ≤ 128 = 2^7`. Precisa de **7 comparações** no pior caso, e a
intercalação comum faz exatamente `2 · 4 - 1 = 7`: ela é ótima.

</details>

**8. O vice-campeão.** Ache o **segundo maior** de 16 valores. O jeito
óbvio (achar o maior, tirá-lo e achar o maior de novo) usa `15 + 14 = 29`
comparações. Faça com 18.

<details><summary>Resposta</summary>

Um **torneio**: os 16 jogam em pares, os vencedores jogam em pares, até
sobrar o campeão. São 15 comparações (todo mundo, menos o campeão, perde uma
vez). O segundo maior só pode ter perdido **para o campeão**, e o campeão
jogou `log₂ 16 = 4` vezes. O máximo entre esses 4 adversários sai com 3
comparações: `15 + 3`, **18 comparações**. Em geral, `n + ⌈log₂ n⌉ - 2`.
Guarde, para cada vencedor, a lista de quem ele derrotou.

</details>

**9. Prever a multiplicação de números enormes.** Um programa de
criptografia multiplica números de 10 mil dígitos em 2 segundos com o
método de Karatsuba, Θ(n^(log₂ 3)). Quanto tempo ele deve levar com 40 mil
dígitos? E se usasse o método da escola, Θ(n²), com os mesmos 2 segundos em
10 mil dígitos?

<details><summary>Resposta</summary>

O tamanho foi multiplicado por 4. Karatsuba: `4^(log₂ 3) = (2²)^(log₂ 3) =
3² = 9`, então **uns 18 segundos**. Método da escola: `4² = 16`, **uns 32
segundos**. A diferença cresce com `n`: com 160 mil dígitos seriam 162
segundos contra 512.

</details>

**10. Descobrir o expoente.** Você não tem o código de uma função, só pode
rodá-la. Com `n = 50 mil` ela leva 1,2 s; com `n = 100 mil`, 3,4 s. Qual é o
expoente provável do custo? Quanto deve levar com 400 mil?

<details><summary>Resposta</summary>

A razão é `3,4 / 1,2 ≈ 2,83`. Se o custo é `n^p`, dobrar `n` multiplica por
`2^p`: `p = log₂ 2,83`, logo **p ≈ 1,5**. De 100 mil para 400 mil, o tamanho
multiplica por 4 e o tempo por `4^1,5 = 8`: **uns 27 segundos**. Antes de
confiar, meça mais um ponto (200 mil deve dar uns 9,6 s): duas medidas
apenas não distinguem `n^1,5` de, digamos, `n log² n`.

</details>

## Questões no estilo da prova

Questões objetivas no formato da prova do PPGI. Resolva no papel, marque a
letra e só depois abra o gabarito. O teorema mestre usado aqui é o da forma
do Cormen (veja o `[!NOTE]` do assunto 0115). Quando o enunciado diz que
cada passo custa 1, conte passo a passo, sem estimar.

**1.** Considere as afirmações sobre notação assintótica:

I. Se `f(n) = Θ(g(n))`, então `f(n) = O(g(n))` e `f(n) = Ω(g(n))`.
II. `3n² + 10n = O(n³)`.
III. Um algoritmo O(n) é sempre mais rápido que um O(n²), para qualquer
entrada e qualquer valor de `n`.
IV. `n log n = O(n²)`.

Marque a alternativa **CORRETA**.

- (A) Apenas I e II.
- (B) Apenas II e III.
- (C) Apenas I, II e IV.
- (D) Apenas III e IV.
- (E) I, II, III e IV.

<details><summary>Gabarito</summary>

**C.** A III é falsa por dois "quaisquer": a notação O descreve o crescimento
para `n` grande e esconde constantes. Um algoritmo `100n` perde para um `n²` em
`n < 100`. O limite superior não precisa ser justo, então II e IV são
verdadeiras. Veja 0114.

</details>

**2.** Considere as afirmações sobre recorrências e o teorema mestre:

I. `T(n) = 2T(n/2) + n` tem solução Θ(n log n).
II. `T(n) = T(n/2) + n` tem solução Θ(n log n).
III. `T(n) = T(n − 1) + n` não pode ser resolvida diretamente pelo teorema
mestre, pois `n − 1` não é uma fração de `n`.
IV. `T(n) = 4T(n/2) + n` tem solução Θ(n²).

Marque a alternativa **CORRETA**.

- (A) Apenas I, III e IV.
- (B) Apenas I e II.
- (C) Apenas II e IV.
- (D) Apenas III e IV.
- (E) I, II, III e IV.

<details><summary>Gabarito</summary>

**A.** Em I, `n^(log₂ 2) = n` empata com `f(n) = n` (caso 2): Θ(n log n). Em II, `a = 1`
e `n^(log₂ 1) = 1`, e `f(n) = n` domina (caso 3): a solução é Θ(n), não Θ(n log n).
Em IV, `n^(log₂ 4) = n²` domina `f(n) = n` (caso 1): Θ(n²). A III é verdadeira:
a forma `T(n − 1)` se resolve pela árvore de recursão (soma `n + (n−1) + ...`,
Θ(n²)). Veja 0114 e 0115.

</details>

**3.** Considere as afirmações:

I. A análise amortizada dá o custo médio por operação no pior caso de uma
**sequência** de operações, sem usar probabilidade.
II. Numa sequência de inserções num vetor dinâmico que dobra a capacidade,
cada inserção individual custa O(1) no pior caso.
III. Qualquer algoritmo de ordenação por comparação precisa de Ω(n log n)
comparações no pior caso.
IV. O limite Ω(n log n) vale para todo algoritmo de ordenação, inclusive os que
não comparam chaves.

Marque a alternativa **CORRETA**.

- (A) Apenas I.
- (B) Apenas I, III e IV.
- (C) Apenas II e III.
- (D) Apenas I, II e III.
- (E) Apenas I e III.

<details><summary>Gabarito</summary>

**E.** A II é falsa: a inserção que enche o vetor copia todos os elementos e custa
Θ(n); só o custo **amortizado** é O(1). A IV é falsa porque o limite vem da
árvore de decisão, que só existe para quem decide por comparações; ordenações
que usam os dígitos ou os valores das chaves como índice escapam dele. Veja
0116 e 0117.

</details>

**4.** Qual é o valor de `conta` depois de `g(20)`? Lembre que `20 / 4 = 5` e
`1 / 4 = 0` em divisão inteira.

```c
int conta = 0;

void g(int n) {
    if (n <= 1) return;
    conta++;
    g(n / 2);
    g(n / 2);
    g(n / 4);
}
```

- (A) 15
- (B) 20
- (C) 19
- (D) 25
- (E) 10

<details><summary>Gabarito</summary>

**B.** Seja `c(n)` o valor deixado por `g(n)`. Para `n ≤ 1`, `c = 0`. Então
`c(2) = c(3) = 1` (só `g(1)` e `g(0)` por dentro), `c(5) = 1 + 2·c(2) + c(1) = 3`,
`c(10) = 1 + 2·c(5) + c(2) = 8` e `c(20) = 1 + 2·c(10) + c(5) = 1 + 16 + 3 = 20`.
Rodando o programa, `conta` vale 20. Veja 0114.

</details>

**5.** Um contador binário de 5 bits começa em 00000. Cada incremento troca os bits
`1` finais para `0` e o primeiro `0` para `1`; cada troca de bit custa 1. Qual é
o custo total de 20 incrementos seguidos?

- (A) 20
- (B) 34
- (C) 36
- (D) 38
- (E) 40

<details><summary>Gabarito</summary>

**D.** O bit 0 troca em todos os 20 incrementos; o bit 1, em 10; o bit 2, em 5;
o bit 3, em 2; o bit 4, em 1. Total: 20 + 10 + 5 + 2 + 1 = 38 (rodando o contador,
o valor final é 10100). Em geral, `n` incrementos custam `2n − (número de bits 1
de n)`, sempre menos que `2n`: o custo amortizado por incremento é O(1). A (E)
é o teto grosseiro `2n`. Veja 0116.

</details>

**6.** Pelo teorema mestre, qual é a solução de `T(n) = 3T(n/3) + n²`?

- (A) Θ(n log n)
- (B) Θ(n³)
- (C) Θ(n²)
- (D) Θ(n² log n)
- (E) Θ(n)

<details><summary>Gabarito</summary>

**C.** Aqui `a = 3`, `b = 3` e `n^(log₃ 3) = n`. Como `f(n) = n²` cresce
polinomialmente mais que `n`, é o caso 3. A condição de regularidade vale:
`3 · (n/3)² = n²/3 ≤ c · n²` com `c = 1/3`. Solução Θ(n²). A (A) seria o caso 2,
se `f(n)` fosse `n`. Veja 0115.

</details>

**7.** Quanto vale `passos` ao fim do trecho abaixo, com `n = 64`?

```c
long passos = 0;
for (int i = n; i >= 1; i /= 2)
    for (int j = 0; j < n; j++)
        passos++;
```

- (A) 384
- (B) 64
- (C) 512
- (D) 4096
- (E) 448

<details><summary>Gabarito</summary>

**E.** O laço externo roda com `i = 64, 32, 16, 8, 4, 2, 1`: sete vezes (`log₂ 64 + 1`).
O interno roda `n = 64` vezes a cada volta: 7 · 64 = 448, ordem Θ(n log n). A (A)
esquece a volta com `i = 1`. Veja 0114.

</details>

**8.** A busca binária recursiva abaixo tem um defeito. O que acontece em
`bb(v, 0, 4, 5)`, com `v = {2, 5, 9, 14, 20}`?

```c
int bb(int v[], int ini, int fim, int x) {
    if (ini > fim) return -1;
    int meio = (ini + fim) / 2;
    if (v[meio] == x) return meio;
    if (v[meio] < x) return bb(v, meio, fim, x);
    return bb(v, ini, meio - 1, x);
}
```

- (A) Não termina (estouro de pilha): a chamada da direita usa `meio` em vez de `meio + 1`, e com `ini = 0`, `fim = 1` ela se repete idêntica.
- (B) Devolve 1 e termina normalmente.
- (C) Devolve -1, porque a base da recursão está errada.
- (D) Falta um `free(v)` no fim da função.
- (E) `(ini + fim) / 2` sempre estoura o `int`.

<details><summary>Gabarito</summary>

**A.** A primeira chamada tem `meio = 2` e `v[2] = 9 > 5`, então vai para
`bb(v, 0, 1, 5)`. Aí `meio = 0`, `v[0] = 2 < 5` e a chamada é `bb(v, 0, 1, 5)` de novo,
sem reduzir nada: recursão infinita. Rodando, o programa termina em falha de
segmentação. O certo é `bb(v, meio + 1, fim, x)`. O estouro de `ini + fim` (E)
só ocorre com índices próximos de `INT_MAX`. Veja 0114 e 0090.

</details>

**9.** Sobre o limite inferior de ordenação por comparação, marque a alternativa
**INCORRETA**.

- (A) A árvore de decisão de um algoritmo que ordena `n` elementos tem pelo menos `n!` folhas.
- (B) A altura mínima dessa árvore é ⌈log₂ n⌉.
- (C) Mergesort e heapsort são assintoticamente ótimos entre os algoritmos por comparação.
- (D) `log₂(n!) = Θ(n log n)`.
- (E) O limite vale para o pior caso: em certas entradas, um algoritmo pode fazer só `n − 1` comparações.

<details><summary>Gabarito</summary>

**B.** Com `n!` folhas, uma árvore binária tem altura de pelo menos ⌈log₂(n!)⌉, que é
Θ(n log n), muito maior que ⌈log₂ n⌉. As outras são verdadeiras. Em (E), o
insertion sort num vetor já ordenado faz `n − 1` comparações: o limite fala do
pior caso, não de toda entrada. Veja 0117.

</details>

**10.** Qual é o limite inferior da árvore de decisão para o número de
comparações de **qualquer** ordenação por comparação de 6 elementos distintos,
no pior caso?

- (A) 6
- (B) 7
- (C) 9
- (D) 10
- (E) 12

<details><summary>Gabarito</summary>

**D.** Há 6! = 720 ordens possíveis, e uma árvore binária de altura `h` tem no
máximo `2^h` folhas. Como `2^9 = 512 < 720 ≤ 1024 = 2^10`, a altura mínima é 10:
⌈log₂ 720⌉ = 10. A (C) é o piso de `log₂ 720 ≈ 9,49`; é preciso arredondar para
cima. Veja 0117.

</details>

## Para ler mais

- CORMEN, T. H. et al. *Algoritmos: teoria e prática*. 4. ed. Rio de Janeiro: GEN LTC, 2024. Cap. 3 (notações O, Ω e Θ), cap. 4 (recorrências: substituição, árvore de recursão e teorema mestre), cap. 8 (limite inferior da ordenação) e cap. 16 (análise amortizada: métodos agregado, contábil e do potencial).
- ZIVIANI, N. *Projeto de algoritmos com implementações em Pascal e C*. 3. ed. São Paulo: Cengage Learning, 2010. Cap. 1 (análise de algoritmos e notação assintótica) e cap. 2 (recursividade e divisão e conquista).
- LINTZMAYER, C. N.; MOTA, G. O. *Análise de algoritmos e de estruturas de dados*. Santo André: UFABC; São Paulo: IME-USP, 2023. Notas de aula. Partes sobre recorrências, teorema mestre e limite inferior para ordenação.
- SZWARCFITER, J. L.; MARKENZON, L. *Estruturas de dados e seus algoritmos*. 3. ed. Rio de Janeiro: LTC, 2010. Caps. 1 (complexidade e limites inferiores), 7 (ordenação e árvore de decisão) e a análise amortizada.
- FEOFILOFF, P. *Análise de algoritmos* (livrinho). São Paulo: IME-USP. Disponível em: <https://www.ime.usp.br/~pf/livrinho-AA/>.
- FEOFILOFF, P. *Algoritmos em linguagem C*. Rio de Janeiro: Elsevier, 2009. Caps. de recursão, mergesort e quicksort.
- TENENBAUM, A. M.; LANGSAM, Y.; AUGENSTEIN, M. J. *Estruturas de dados usando C*. São Paulo: Makron Books, 1995. Cap. 6 (classificação, eficiência e o limite de log₂ n! comparações).
- CORTÉS, M. I. *Estrutura de dados*. 3. ed. Fortaleza: EdUECE, 2015. Cap. 1 (complexidade) e a seção de listas autoajustáveis, onde aparece a ideia de custo amortizado.
- ROVAI, K. R. *Algoritmos e estrutura de dados*. Londrina: Editora e Distribuidora Educacional, 2018. Unidade de tabelas de espalhamento (a tabela que dobra).
- MORIN, P. *Open data structures*. Edição em C++/Java/pseudocódigo. Disponível em: <https://opendatastructures.org/>. Caps. 1 e 2 (análise amortizada do vetor que cresce).
- KERNIGHAN, B. W.; RITCHIE, D. M. *C: a linguagem de programação padrão ANSI*. Rio de Janeiro: Campus, 1989. Seção 4.10 (recursão).
- CPPREFERENCE. *clock* e *CLOCKS_PER_SEC*. Disponível em: <https://en.cppreference.com/w/c/chrono/clock>.
- LINUX MAN-PAGES. *clock(3)* e *log2(3)*. Disponível em: <https://man7.org/linux/man-pages/man3/clock.3.html>.
