# Módulo 18 · Ordenação além da comparação e seleção

Quem só compara faz uns n log₂ n comparações no pior caso (módulo 17). Este
módulo sai desse piso usando os **dados**: counting, radix e bucket sort são
lineares, mas gastam memória e supõem algo sobre as chaves. Completam o módulo
o **shell sort** e o **quickselect**. Depende do módulo 13 (insertion sort e
separação do quick sort).

## O que você vai aprender

- **shell sort**: insertion sort com saltos e a sequência de Knuth
- **counting sort**: contar, acumular e distribuir, e a **estabilidade**
- **radix sort**: dígito a dígito (LSD), em base 10 e em base 256
- **bucket sort**: baldes com listas encadeadas, O(n) médio e O(n²) no pior caso
- **quickselect**: o k-ésimo menor em O(n) médio, com pivô sorteado
- ordenar por **duas chaves** e medir 1 milhão de registros contra o `qsort`

## Antes de começar

Revise o insertion sort (0093), a separação do quick sort (0095), listas
encadeadas (0076 a 0078), filas (0085), operadores de bits (0065), `malloc` e
`calloc` e o `qsort` (0096).

Nos diagramas, **roxo** marca o pivô ou a posição da vez, **amarelo** o que
acompanhar, **verde** o que já está no lugar e **cinza** o descartado.

O último assunto usa o TAD `pix.h`/`pix.c`, compilado junto com o exemplo. Os
tempos medidos com `clock()` variam de máquina para máquina: compare
proporções.

{{indice}}

---

{{assuntos}}

---

## Desafios do módulo

Problemas para fechar o módulo, misturando os assuntos. Escreva em C e compile
com as flags de estudo.

**1. Quantas passadas?** Você vai ordenar 50 milhões de CPFs (11 dígitos,
guardados em `uint64_t`) com radix sort. Quantas passadas são em base 10? E
em base 256? E em base 65536 (dois bytes por vez)? Qual o tamanho do vetor
de contadores em cada caso?

<details><summary>Resposta</summary>

Base 10: **11 passadas**, 10 contadores. O maior CPF é menor que 10¹¹, que
é menor que 2³⁷: cabe em 37 bits. Base 256: ⌈37 / 8⌉ = **5 passadas**, 256
contadores (1 KB). Base 65536: ⌈37 / 16⌉ = **3 passadas**, 65536 contadores
(256 KB, que já não cabem no cache L1). Menos passadas nem sempre é mais
rápido: os contadores precisam caber perto do processador.

</details>

**2. Notas do vestibular.** São 2 milhões de candidatos, com notas de 0,00 a
1000,00 (duas casas). Ordene em O(n) do maior para o menor, mantendo, em
caso de empate, a ordem de inscrição.

<details><summary>Resposta</summary>

Multiplique por 100: as notas viram inteiros de 0 a 100000. Counting sort
estável com `k = 100001` contadores (uns 400 KB) e a chave invertida,
`100000 - nota`, para a ordem decrescente. Os empates ficam na ordem de
inscrição porque o terceiro laço anda de trás para a frente. Custo:
O(n + k), uns 2,1 milhões de passos.

</details>

**3. Elemento majoritário.** Um vetor de 1 milhão de votos (números de 1 a
5000) tem um candidato com **mais da metade** dos votos. Ache-o em O(n) de
dois jeitos: com contagem e com o quickselect.

<details><summary>Resposta</summary>

Contagem: `c[5001]`, um laço, e o `x` com `c[x] > n / 2`. Quickselect: se
um valor aparece mais de `n / 2` vezes, ele ocupa obrigatoriamente a
posição `n / 2` do vetor ordenado, então `quickselect(v, n, n / 2)` é a
resposta. O primeiro gasta 20 KB de contadores e não mexe no vetor; o
segundo não gasta memória, mas bagunça o vetor.

</details>

**4. Shell sort com Ciura.** Troque os saltos de Knuth pelos de Ciura (1,
4, 10, 23, 57, 132, 301, 701, e depois multiplicando por 2,25) e conte as
comparações num vetor aleatório de 100 mil elementos, com o gerador do
exemplo A237.

<details><summary>Resposta</summary>

Guarde os saltos num vetor e use do maior que seja menor que `n` até o 1.
Os de Ciura foram achados por experimento e costumam fazer menos
comparações que os de Knuth, no caso médio. Não há fórmula fechada para o custo
de nenhum dos dois: é um dos problemas em aberto da análise de algoritmos.

</details>

**5. Os 10 mais próximos.** Um app de entregas tem 200 mil motoboys, cada um
com a distância (em metros) até o restaurante. Ache os 10 mais próximos,
em ordem. Compare três jeitos: ordenar tudo, quickselect + ordenar 10, e um
heap de máximo de tamanho 10 (assunto 0102).

<details><summary>Resposta</summary>

Ordenar: O(n log n), uns 3,5 milhões de comparações. Quickselect em
`k = 9` deixa os 10 menores em `v[0..9]`; ordenar esses 10 custa quase nada: O(n) em
média, uns 400 mil passos. O heap de 10 passa uma vez pelo vetor: cada
motoboy mais perto que o pior do heap entra no lugar dele, O(n log 10), sem
bagunçar o vetor e funcionando com dados que chegam aos poucos.

</details>

**6. Datas e horas em uma chave.** Ordene 1 milhão de registros de ponto
(data e hora de entrada de cada funcionário) em ordem cronológica com **uma**
ordenação linear, sem passadas por campo.

<details><summary>Resposta</summary>

Monte uma chave numérica que já esteja em ordem cronológica:
`chave = ((ano * 12 + mes) * 31 + dia) * 86400 + segundo`, num
`uint64_t`. Depois, um radix em base 256 sobre a chave (5 passadas bastam
para os bits usados). É o mesmo truque das datas do E724, mas com as casas
juntas num número só.

</details>

**7. Bucket sort que se adapta.** O bucket sort do assunto 0122 sofre quando
os dados se concentram numa faixa. Proponha uma versão que não dependa de
o intervalo estar bem espalhado.

<details><summary>Resposta</summary>

Escolha as fronteiras dos baldes pelos **dados**, não pelo intervalo: pegue
uma amostra (por exemplo, 1000 elementos), ordene a amostra e use os seus
percentis como fronteiras. Para achar o balde de um valor, faça uma busca
binária (assunto 0090) nas fronteiras. Cada balde recebe mais ou menos a
mesma quantidade, qualquer que seja a distribuição. É a ideia do
*samplesort*, usado em ordenações paralelas.

</details>

**8. Radix de strings de tamanhos diferentes.** O radix LSD do exemplo A241
exige strings do mesmo tamanho. Ordene `"ana", "bia", "an", "bianca", "a"`
com radix, sem completar as strings com espaços.

<details><summary>Resposta</summary>

Trate a posição que não existe como o caractere 0, menor que qualquer
letra: a chave da posição `p` é `p < strlen(s) ? (unsigned char) s[p] : 0`.
Faça as passadas da posição `max - 1` até 0 (aqui, `max = 6`). O resultado
é `a an ana bia bianca`. A alternativa é o radix **MSD**: começa pela
primeira letra, divide em baldes e ordena cada balde recursivamente, o que
nem olha o fim das strings curtas.

</details>

**9. Mediana em fluxo.** As temperaturas de um sensor chegam uma a uma, e a
cada leitura você precisa mostrar a mediana até ali. Rodar o quickselect a
cada leitura custa O(n) por leitura. Faça melhor.

<details><summary>Resposta</summary>

Dois heaps (assunto 0102): um heap de **máximo** com a metade menor e um
de **mínimo** com a metade maior, com tamanhos que diferem no máximo em 1.
Cada leitura entra num deles e, se precisar, um elemento passa de um para o
outro. A mediana é a raiz do maior (ou a média das duas raízes). Cada
leitura custa O(log n).

</details>

**10. Contar inversões em O(n log n).** O exercício E714 contou inversões
com dois laços, O(n²). Conte as inversões de um vetor de 100 mil elementos
em O(n log n).

<details><summary>Resposta</summary>

Modifique o merge sort (assunto 0094): na intercalação, quando um elemento
da metade **direita** passa na frente, ele forma inversão com todos os que
ainda restam na metade esquerda. Some `meio - i` nesse momento. O total sai
junto com o vetor ordenado. Num vetor decrescente de 100 mil, são
4.999.950.000 inversões: use `long long`.

</details>

## Questões do POSCOMP

Questões reais do POSCOMP (SBC) sobre este módulo. O enunciado está no caderno oficial: abra o link, resolva e confira o gabarito.

| Ano | Questão | Assunto | Gabarito | Prova |
| --- | --- | --- | --- | --- |
| 2023 | 26 | Ordenação por contagem | C | [caderno](https://www.sbc.org.br/wp-content/uploads/2025/02/0761.001_Exame_POSCOMP_2023.pdf) |

O gabarito de 2023 vem de um blog de terceiros que reproduz o gabarito definitivo; confira no PDF oficial da SBC.


## Questões no estilo da prova

Questões objetivas no formato da prova do PPGI: conceito, afirmações
combinadas, simulação à mão, cálculo e código com erro. Resolva no papel,
marque a letra e só depois abra o gabarito. Sempre que a questão traz código
ou um vetor, dá para conferir rodando.

**1.** O counting sort do assunto 0120 ordena `3 0 2 3 1 0 3 2` (chaves de 0
a 3) com contagem, acumulação e distribuição **de trás para a frente**
(`saida[--c[x]] = v[i]`, de `i = n - 1` até 0). Em que posição do vetor de
saída (contando de 0) cai o elemento `v[0]`, o primeiro 3?

- (A) 3
- (B) 4
- (C) 5
- (D) 6
- (E) 7

<details><summary>Gabarito</summary>

**C.** A contagem dá `2 1 2 3`, e a acumulação, `c = 2 3 5 8`. Os três 3 ocupam
as posições 5, 6 e 7. Andando de trás para a frente, o último 3 (`v[6]`) pega a
7, o do meio (`v[3]`) pega a 6 e o primeiro (`v[0]`) pega a 5. É a ordem
original dos iguais, o que torna o método estável. Com o laço de frente para
trás, o `v[0]` iria para a 7 (a alternativa E). Veja 0120.

</details>

**2.** O radix sort LSD do assunto 0121, com counting sort estável em cada
passada e base 10, ordena `457 126 305 891 243 672 118 123`. Como fica o
vetor depois da **segunda** passada (a das dezenas)?

- (A) `305 118 123 126 243 457 672 891`
- (B) `891 672 243 123 305 126 457 118`
- (C) `305 118 126 123 243 457 672 891`
- (D) `118 123 126 243 305 457 672 891`
- (E) `305 118 123 126 243 672 457 891`

<details><summary>Gabarito</summary>

**A.** A passada das unidades dá `891 672 243 123 305 126 457 118` (a
alternativa B). Na das dezenas, 123 e 126 têm dezena 2 e mantêm a ordem da
passada anterior (123 antes de 126); a C inverte esse empate, o que só um
método instável faria. A D é o vetor depois da terceira passada. Veja 0121.

</details>

**3.** O shell sort do assunto 0119, com a sequência de intervalos 4, 2, 1,
ordena `23 8 41 5 16 30 2 19`. Como fica o vetor depois da passada com
`h = 2`?

- (A) `16 8 2 5 23 30 41 19`
- (B) `2 5 8 16 19 23 30 41`
- (C) `2 8 16 5 23 19 41 30`
- (D) `2 5 16 8 23 19 41 30`
- (E) `5 8 16 23 2 19 30 41`

<details><summary>Gabarito</summary>

**D.** Depois de `h = 4`: `16 8 2 5 23 30 41 19` (a alternativa A). A passada
com `h = 2` faz insertion sort nas posições pares (`16 2 23 41` vira
`2 16 23 41`) e nas ímpares (`8 5 30 19` vira `5 8 19 30`), intercaladas:
`2 5 16 8 23 19 41 30`. Falta a passada `h = 1`, que termina o serviço (a B).
Veja 0119.

</details>

**4.** Considere as afirmações sobre ordenação linear.

I. O counting sort não compara chaves entre si.
II. O counting sort é estável, qualquer que seja a ordem do laço que
distribui os elementos.
III. O radix sort LSD só funciona se a ordenação usada em cada passada for
estável.
IV. O counting sort é pouco indicado quando o intervalo de chaves `k` é muito
maior que `n`.

Marque a alternativa CORRETA.

- (A) Apenas I e III.
- (B) Apenas I, III e IV.
- (C) Apenas II e IV.
- (D) Apenas I, II e III.
- (E) I, II, III e IV.

<details><summary>Gabarito</summary>

**B.** I é verdadeira: ele usa a chave como índice. II é falsa: só a
distribuição de trás para a frente preserva a ordem dos iguais; "qualquer que
seja" é a pegadinha. III é verdadeira: sem estabilidade, a passada de um dígito
desfaz o trabalho da anterior. IV é verdadeira: o custo e o espaço são
Θ(n + k). Veja 0120 e 0121.

</details>

**5.** Considere as afirmações.

I. O quickselect tem custo esperado Θ(n) para achar o k-ésimo menor elemento
de um vetor de `n` posições.
II. O shell sort não é estável.
III. Todo algoritmo que ordena **só por comparações** faz Ω(n log n)
comparações no pior caso.

Marque a alternativa CORRETA.

- (A) Apenas I.
- (B) Apenas II e III.
- (C) Apenas I e III.
- (D) Apenas I e II.
- (E) I, II e III.

<details><summary>Gabarito</summary>

**E.** I é verdadeira: depois de particionar, o quickselect segue por um lado
só, e a soma `n + n/2 + n/4 + ...` dá menos que 2n. II é verdadeira: os saltos
de `h` posições passam por cima de iguais (com `20 21 10`, chaves iguais com
rótulos, o shell sort troca os dois iguais de lugar). III é verdadeira: a
árvore de decisão com `n!` folhas tem altura de pelo menos log₂ n!. O "todo"
aqui está certo porque a afirmação restringe o conjunto aos métodos por
comparação. Veja 0119, 0123 e 0117.

</details>

**6.** Chaves inteiras de 48 bits serão ordenadas por radix sort LSD, tomando
12 bits por "dígito" e um counting sort estável em cada passada. Quantas
passadas são feitas e quantos contadores o counting sort usa em cada uma?

- (A) 12 passadas; 4 contadores
- (B) 4 passadas; 48 contadores
- (C) 48 passadas; 2 contadores
- (D) 4 passadas; 4096 contadores
- (E) 2 passadas; 2²⁴ contadores

<details><summary>Gabarito</summary>

**D.** São `b/r = 48/12 = 4` passadas, e cada dígito de 12 bits vai de 0 a
2¹² - 1 = 4095, ou seja, 4096 contadores. O custo é Θ(4 · (n + 4096)), linear
em `n`. Veja 0121.

</details>

**7.** O counting sort abaixo tem chaves de 0 a `K = 4`, mas o laço de
acumulação foi escrito com `x < K`.

```c
#include <stdio.h>

int main(void) {
    enum { K = 4, N = 8 };
    int v[N] = {3, 1, 4, 1, 2, 4, 0, 3};
    int c[K + 1] = {0}, saida[N] = {0};

    for (int i = 0; i < N; i++) c[v[i]]++;
    for (int x = 1; x < K; x++) c[x] += c[x - 1];
    for (int i = N - 1; i >= 0; i--) saida[--c[v[i]]] = v[i];

    for (int i = 0; i < N; i++) printf("%d ", saida[i]);
    printf("\n");
    return 0;
}
```

O que o programa imprime?

- (A) `4 1 1 2 3 3 0 0`
- (B) `0 1 1 2 3 3 4 4`
- (C) `1 1 2 3 3 4 4 0`
- (D) `0 1 1 2 3 3 4 0`
- (E) Nada: o programa não compila.

<details><summary>Gabarito</summary>

**A.** O laço pula `c[4]`, que fica com a contagem simples (2) em vez da
acumulada (8). Os dois 4 vão para as posições 1 e 0, a posição 0 que deveria
ser do 0, e o 0 acaba sobrescrito pelo 4. As posições 6 e 7 nunca são
escritas e ficam com o 0 inicial. Compila sem aviso, e o resultado é o
impresso. O limite correto é `x <= K`. Veja 0120.

</details>

**8.** Considere as afirmações.

I. Ordenar 10 inteiros entre 0 e 10⁹ por counting sort direto é uma boa
escolha, porque o custo é linear.
II. O bucket sort que ordena cada balde com insertion sort pode custar Θ(n²)
no pior caso.
III. Para chaves inteiras entre `a` e `b`, o counting sort pode indexar os
contadores por `x - a`, e bastam `b - a + 1` contadores.

Marque a alternativa CORRETA.

- (A) Apenas I e II.
- (B) Apenas II e III.
- (C) Apenas I e III.
- (D) Apenas III.
- (E) I, II e III.

<details><summary>Gabarito</summary>

**B.** I é falsa: o custo é Θ(n + k), e aqui `k` é 10⁹ + 1, ou seja, um bilhão
de contadores para ordenar 10 números. II é verdadeira: se todos os valores
caem no mesmo balde, sobra um insertion sort de `n` elementos. III é
verdadeira, e é a forma de poupar memória quando as chaves ficam longe de 0.
Veja 0120 e 0122.

</details>

**9.** O quickselect (partição de Lomuto, pivô no último elemento do trecho)
procura o **3º menor** elemento de `12 7 19 3 15 8 21`. Qual é o resultado e
quantas partições são feitas?

- (A) 7, com 1 partição
- (B) 8, com 3 partições
- (C) 8, com 2 partições
- (D) 12, com 2 partições
- (E) 19, com 3 partições

<details><summary>Gabarito</summary>

**C.** O 3º menor está no índice 2 do vetor ordenado. 1ª partição, pivô 21: ele
fica no índice 6, e o 3º menor está à esquerda. 2ª partição, no trecho `12 7
19 3 15 8` com pivô 8: o vetor fica `7 3 8 12 15 19 21` e o 8 cai no índice 2.
Achou, com 2 partições e sem precisar ordenar nada. Veja
0123.

</details>

**10.** Qual é o menor número de comparações que **qualquer** algoritmo de
ordenação por comparações precisa fazer, no pior caso, para ordenar 5
elementos distintos?

- (A) 4
- (B) 5
- (C) 6
- (D) 8
- (E) 7

<details><summary>Gabarito</summary>

**E.** A árvore de decisão tem 5! = 120 folhas, e uma árvore binária de altura
`h` tem no máximo 2ʰ folhas. Logo 2ʰ ≥ 120, e `h ≥ ⌈log₂ 120⌉ = 7` (2⁶ = 64
é pouco; 2⁷ = 128 basta). Veja 0117 e 0120.

</details>

## Para ler mais

- CORMEN, T. H. et al. *Algoritmos: teoria e prática*. 4. ed. Rio de Janeiro: GEN LTC, 2024. Cap. 8 (limite inferior, counting, radix e bucket sort) e cap. 9 (medianas e estatísticas de ordem: `RANDOMIZED-SELECT` e `SELECT`).
- ZIVIANI, N. *Projeto de algoritmos com implementações em Pascal e C*. 3. ed. São Paulo: Cengage Learning, 2010. Cap. 4: ordenação (shellsort, estabilidade e ordenação parcial).
- SEDGEWICK, R. *Algorithms in C, parts 1-4*. 3. ed. Boston: Addison-Wesley, 1998. Caps. 6 (shellsort), 7 (quicksort e seleção) e 10 (radix sort).
- SEDGEWICK, R.; WAYNE, K. *Algorithms*. 4. ed. Boston: Addison-Wesley, 2011. Seções 2.1 (shellsort) e 5.1 (ordenação de strings). Disponível em: <https://algs4.cs.princeton.edu/>.
- KNUTH, D. E. *The art of computer programming, volume 3: sorting and searching*. 2. ed. Boston: Addison-Wesley, 1998. Seção 5.2.1 (shellsort) e 5.2.5 (ordenação por distribuição).
- SZWARCFITER, J. L.; MARKENZON, L. *Estruturas de dados e seus algoritmos*. 3. ed. Rio de Janeiro: LTC, 2010. Caps. de ordenação: limite inferior e ordenação por distribuição.
- TENENBAUM, A. M.; LANGSAM, Y.; AUGENSTEIN, M. J. *Estruturas de dados usando C*. São Paulo: Makron Books, 1995. Cap. 6 (classificação: shell sort, radix sort e cálculo de endereço).
- ROVAI, K. R. *Algoritmos e estrutura de dados*. Londrina: Editora e Distribuidora Educacional, 2018. Seção sobre espalhamento por cálculo de endereço (a semente do bucket sort).
- LINTZMAYER, C. N.; MOTA, G. O. *Análise de algoritmos e de estruturas de dados*. Santo André: UFABC, 2023. Rascunho. Seções de shellsort, counting sort e seleção.
- FEOFILOFF, P. *Algoritmos em linguagem C*. Rio de Janeiro: Elsevier, 2009. Caps. de ordenação; e as notas "Ordenação digital" e "Mediana e seleção". Disponível em: <https://www.ime.usp.br/~pf/algoritmos/>.
- HOARE, C. A. R. Algorithm 65: find. *Communications of the ACM*, v. 4, n. 7, p. 321-322, 1961.
- BLUM, M. et al. Time bounds for selection. *Journal of Computer and System Sciences*, v. 7, n. 4, p. 448-461, 1973.
- SHELL, D. L. A high-speed sorting procedure. *Communications of the ACM*, v. 2, n. 7, p. 30-32, 1959.
- CIURA, M. Best increments for the average case of shellsort. In: INTERNATIONAL SYMPOSIUM ON FUNDAMENTALS OF COMPUTATION THEORY, 13., 2001, Riga. *Proceedings*. Berlin: Springer, 2001. p. 106-117.
- KERNIGHAN, B. W.; RITCHIE, D. M. *C: a linguagem de programação padrão ANSI*. Rio de Janeiro: Campus, 1989. Seções 2.9 (operadores bit a bit) e 5.11 (ponteiros para funções).
- CPPREFERENCE. *qsort, qsort_s* e *clock*. Disponível em: <https://en.cppreference.com/w/c/algorithm/qsort> e <https://en.cppreference.com/w/c/chrono/clock>.
- LINUX MAN-PAGES. *qsort(3)* e *clock(3)*. Disponível em: <https://man7.org/linux/man-pages/man3/qsort.3.html>.
