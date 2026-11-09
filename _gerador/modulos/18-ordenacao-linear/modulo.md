# Módulo 18 · Ordenação além da comparação e seleção

No módulo 13 você ordenou comparando: bubble, selection, insertion, merge e
quick sort, todos decidindo a ordem com perguntas do tipo "`a` vem antes de
`b`?". No módulo 17 viu que esse jeito tem um piso: nenhuma ordenação que só
compara faz menos que uns n log₂ n comparações no pior caso. Este módulo
mostra o que existe fora desse piso.

O truque é olhar para os **dados**, e não só para o algoritmo. Se as chaves
são inteiros pequenos, o valor vira índice de vetor, e não há comparação
nenhuma: é o **counting sort**. Se as chaves têm dígitos ou bytes, dá para
ordenar casa por casa: **radix sort**. Se os valores estão bem espalhados num
intervalo conhecido, baldes por faixa resolvem quase tudo: **bucket sort**. Os
três são lineares e cobram um preço: memória extra e suposições sobre os
dados que, se forem falsas, viram escrita fora do vetor.

O módulo ainda traz dois parentes. O **shell sort** continua comparando, mas
dá ao insertion sort pulos longos e foge do n² com quase o mesmo código. E o
**quickselect** responde "quem é o k-ésimo menor?" (a mediana, o percentil,
os k maiores) sem ordenar nada, reaproveitando a separação do quick sort.

## O que você vai aprender

- **shell sort**: insertion sort com saltos, a sequência de Knuth e por que os saltos importam
- **counting sort**: contar, acumular e distribuir; a **estabilidade** e por que ela depende de um laço de trás para a frente
- **radix sort**: ordenar dígito a dígito (LSD), em base 10 e em base 256 com operadores de bits
- **bucket sort**: baldes por faixa com listas encadeadas, o caso médio O(n) e o pior caso O(n²)
- **quickselect**: o k-ésimo menor, a mediana e os k maiores em O(n) médio, com pivô sorteado para fugir do pior caso
- ordenar por **duas chaves** com passadas estáveis e medir 1 milhão de registros contra o `qsort`

## Antes de começar

Este módulo usa muito do que veio antes: o insertion sort (0093) e a
separação do quick sort (0095), listas encadeadas (0076 a 0078), filas
(0085), operadores de bits (0065), `malloc` e `calloc`, e o `qsort` com
função de comparação (0096). Se algum desses estiver enferrujado, revise
antes.

Nos vetores dos diagramas, cada linha de gavetas é um momento do algoritmo:
**roxo** marca o pivô ou a posição da vez, **amarelo** destaca o que você deve
acompanhar (uma fileira, um empate), **verde** é o que já está no lugar e
**cinza** é o que o algoritmo descartou. Faça o **Passo a passo** no papel
antes de conferir a tabela e responda a **Pergunta para você** antes de
rodar.

Os exemplos dos cinco primeiros assuntos cabem num arquivo só. O último
assunto, que ordena 1 milhão de registros, usa um TAD: `pix.h` e `pix.c`
ficam na pasta do assunto, e o `rodar` compila os dois junto com o exemplo.

Vários exemplos geram dados com um gerador de números pseudoaleatórios
escrito à mão (uma conta com `unsigned` que dá a volta), em vez do `rand`:
assim a saída é a mesma em qualquer computador. Os exemplos que medem
**tempo** com `clock()` são a exceção: os números mudam a cada execução, e
o AddressSanitizer do `rodar` deixa tudo mais lento. Compare as proporções,
não os valores.

Alguns exercícios de "ache o erro" trazem o bug de propósito: o programa
roda até o fim, mas a saída sai errada. O enunciado avisa.

{{indice}}

---

{{assuntos}}

---

## Desafios do módulo

Problemas para fechar o módulo, misturando os assuntos. Escreva em C e rode
com o `rodar`.

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
`k = 9` deixa os 10 menores em `v[0..9]`; ordenar esses 10 é nada: O(n) em
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

## Questões no estilo da prova

Questões objetivas no formato da prova do PPGI. Resolva no papel, marque a
letra e só depois abra o gabarito. Sempre que a questão traz código ou um
vetor, dá para conferir rodando.

**1.** O counting sort recebe `4 1 3 1 0 4 2 1`, com chaves de 0 a 4. Como
fica o vetor de contagem `c` depois dos passos de **contar** e **acumular**
(cada `c[x]` passa a ser quantos elementos têm chave menor ou igual a `x`)?

- (A) `1 3 1 1 2`
- (B) `0 1 4 5 6`
- (C) `1 4 5 6 7`
- (D) `1 4 5 6 8`
- (E) `2 4 5 6 8`

<details><summary>Gabarito</summary>

**D.** A contagem dá `c = 1 3 1 1 2` (um 0, três 1, um 2, um 3, dois 4), que
é a alternativa (A), parada um passo antes. Acumulando: 1, 1 + 3 = 4, 4 + 1 =
5, 5 + 1 = 6, 6 + 2 = 8. O último sempre vale `n`. Veja 0120.

</details>

**2.** Um counting sort recebe os pares (chave, rótulo) `(3,a) (1,b) (3,c)
(2,d) (1,e)`. Por engano, o laço de distribuir anda **da frente para trás**
(`for (i = 0; i < n; i++)`), mantendo `saida[--c[x]] = v[i]`. Qual é a saída?

- (A) `1b 1e 2d 3a 3c`
- (B) `1e 1b 2d 3c 3a`
- (C) `1b 1e 2d 3c 3a`
- (D) `1e 1b 2d 3a 3c`
- (E) o vetor não sai ordenado pela chave

<details><summary>Gabarito</summary>

**B.** As chaves saem em ordem, mas, com `--c[x]`, o primeiro par de cada
chave ocupa a **última** vaga do bloco: os empates saem invertidos. Andando
de trás para a frente, a resposta seria (A), a estável. Veja 0120.

</details>

**3.** Na forma usual de cada um, quais destes algoritmos são **estáveis**:
insertion sort, merge sort, counting sort, heapsort, quicksort e selection
sort?

- (A) insertion, merge e counting
- (B) merge, counting e heapsort
- (C) só o counting
- (D) insertion, merge, counting e quicksort
- (E) todos, desde que as chaves sejam distintas

<details><summary>Gabarito</summary>

**A.** Insertion só passa à frente de quem é estritamente maior; merge tira
da esquerda no empate; counting distribui de trás para a frente. Heapsort,
quicksort e selection sort fazem trocas longas que pulam por cima de iguais.
Com chaves distintas a estabilidade nem é observável, por isso (E) não diz
nada. Veja 0096 e 0120.

</details>

**4.** O radix sort LSD, com counting sort estável em cada passada e base 10,
ordena `512 108 371 245 903 117 650 284`. Como fica o vetor depois da
**segunda** passada (a das dezenas)?

- (A) `108 117 245 284 371 512 650 903`
- (B) `650 371 512 903 284 245 117 108`
- (C) `903 108 512 117 245 650 371 284`
- (D) `108 903 117 512 245 650 371 284`
- (E) `903 108 117 512 245 650 284 371`

<details><summary>Gabarito</summary>

**C.** A primeira passada (unidades) dá `650 371 512 903 284 245 117 108`, a
alternativa (B). Na das dezenas, 903 e 108 têm dezena 0 e mantêm a ordem que
já tinham (903 antes); 512 e 117, dezena 1, também. A alternativa (D) inverte
esses empates, o que só acontece com uma passada instável. A (A) é o vetor
depois da terceira passada. Veja 0121.

</details>

**5.** Um milhão de inteiros sem sinal de 32 bits são ordenados por radix
sort, tomando 8 bits por "dígito" (base 256). Quantas passadas são feitas e
qual é o custo, em termos do Cormen, com `b` bits por chave e `r` bits por
dígito?

- (A) 32 passadas; Θ(b · n)
- (B) 10 passadas; Θ(n log n)
- (C) 2 passadas; Θ(n + 2^r)
- (D) 4 passadas; Θ(n log n)
- (E) 4 passadas; Θ((b/r) · (n + 2^r))

<details><summary>Gabarito</summary>

**E.** São `b/r = 32/8 = 4` passadas de counting sort, cada uma Θ(n + 2^r)
com `2^r = 256` contadores. Com `b` e `r` fixos, é linear em `n`. O limite
Ω(n log n) não se aplica, porque nenhum elemento é comparado com outro. Veja
0121.

</details>

**6.** Você precisa ordenar `n` inteiros com valores de 0 a n³ - 1. Qual é a
melhor escolha?

- (A) counting sort direto, em Θ(n)
- (B) radix sort com base `n` (3 dígitos), em Θ(n)
- (C) bucket sort com 10 baldes, em Θ(n) no pior caso
- (D) nada abaixo de Θ(n log n) é possível
- (E) counting sort direto, em Θ(n log n)

<details><summary>Gabarito</summary>

**B.** O counting sort direto precisa de `k = n³` contadores: Θ(n + n³) =
Θ(n³). Escrevendo cada número em base `n`, ele tem 3 dígitos de 0 a n - 1, e
o radix faz 3 passadas de Θ(n + n): Θ(n). Veja 0120 e 0121.

</details>

**7.** O bucket sort do Cormen recebe `n` valores em [0, 1), usa `n` baldes
(o valor `x` vai para o balde ⌊n · x⌋) e ordena cada balde com insertion
sort. Assinale a correta.

- (A) Custa Θ(n) no pior caso, para qualquer entrada.
- (B) Não é estável, qualquer que seja a inserção no balde.
- (C) Custa Θ(n log n) em média, como os métodos por comparação.
- (D) Custa Θ(n) em média se os valores forem uniformes no intervalo, e Θ(n²)
  no pior caso, quando todos caem no mesmo balde.
- (E) Só funciona com números inteiros.

<details><summary>Gabarito</summary>

**D.** Com distribuição uniforme, cada balde recebe O(1) elementos em média,
e o insertion sort nos baldes custa O(n) no total. Se todos caem num balde só,
sobra um insertion sort de `n` elementos. Ele é estável quando a inserção põe
o novo depois dos iguais, como o `<=` do assunto. Veja 0122.

</details>

**8.** Sobre achar o k-ésimo menor elemento de um vetor de `n` posições,
assinale a correta.

- (A) O quickselect (o `RANDOMIZED-SELECT` do Cormen) custa Θ(n) esperado e
  Θ(n²) no pior caso; o `SELECT` com mediana das medianas garante O(n) no pior
  caso.
- (B) Qualquer seleção exige ordenar antes, então custa Ω(n log n).
- (C) O quickselect custa Θ(n log n) no pior caso.
- (D) O quickselect faz duas chamadas recursivas, como o quicksort.
- (E) Achar o mínimo custa Θ(log n).

<details><summary>Gabarito</summary>

**A.** Depois de separar, o quickselect segue **um lado só**, por isso a média
é `n + n/2 + n/4 + ... < 2n`. Com o pivô sempre no extremo, vira
`n + (n - 1) + ...`: Θ(n²). A mediana das medianas escolhe um pivô que
descarta uma fração fixa do vetor a cada passo, e isso garante O(n). Veja
0123.

</details>

**9.** Um sistema guarda 1 milhão de leituras de temperatura, todas inteiras
entre 1000 e 1009 (décimos de grau). Para ordenar com counting sort (ou
pigeonhole sort), qual é o tamanho do vetor de contagem e o custo?

- (A) 1010 contadores; Θ(n log n)
- (B) 10⁶ contadores; Θ(n)
- (C) 1009 contadores; Θ(n + k) com k = 1009
- (D) 10 contadores; Θ(n log n)
- (E) 10 contadores, indexados por `x - 1000`; Θ(n + k) = Θ(n)

<details><summary>Gabarito</summary>

**E.** O intervalo tem `max - min + 1 = 10` valores. Subtraindo o mínimo
(`c[x - 1000]++`), bastam 10 contadores, e o custo Θ(n + 10) é linear. Alocar
1010 posições funcionaria, mas desperdiça memória. O pigeonhole sort, com
uma "casa" por valor do intervalo, é o assunto 0180. Veja 0120.

</details>

**10.** Assinale a afirmação correta sobre o limite inferior Ω(n log n) para
ordenar.

- (A) Ele vale para qualquer algoritmo de ordenação, inclusive o counting
  sort.
- (B) O shell sort é o único algoritmo por comparação que o fura.
- (C) Ele vale para algoritmos que só aprendem sobre os dados comparando pares;
  counting, radix e bucket sort usam o valor da chave como índice e escapam
  dele, ao custo de hipóteses sobre as chaves.
- (D) Ele vale só para o caso médio.
- (E) Ele mostra que o merge sort é Θ(n²) no pior caso.

<details><summary>Gabarito</summary>

**C.** A árvore de decisão modela só comparações: com `n!` folhas, a altura é
pelo menos log₂ n! = Θ(n log n). Os métodos lineares não fazem comparações
entre elementos; em troca, exigem chaves inteiras num intervalo pequeno, com
poucos dígitos ou distribuídas de modo uniforme. Veja 0117 e 0120.

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
