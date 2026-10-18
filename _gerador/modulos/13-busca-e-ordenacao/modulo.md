# Módulo 13 · Busca e ordenação

Procurar e ordenar são as duas tarefas que um computador mais faz. A lista de
contatos do celular, o extrato do banco, o resultado de uma busca na loja
virtual, o índice de um banco de dados: tudo isso é dado sendo ordenado para
depois ser achado rápido.

No TypeScript você escreve `lista.sort((a, b) => a - b)` e
`lista.indexOf(x)` e segue a vida. Aqui você vai abrir essas caixas pretas.
Vai ver por que uma busca num vetor ordenado acha qualquer coisa entre um
milhão de elementos em 20 passos, por que uma ordenação "óbvia" leva horas
onde outra leva um segundo, e por que o próprio `a - b` daquele `sort` pode
dar errado no C.

O módulo junta as ferramentas dos anteriores: vetores e ponteiros, recursão,
`malloc`, structs e, principalmente, o jeito de contar passos e pensar em
Big-O do módulo 10. Em cada algoritmo você vai **contar comparações e
trocas** e conferir que a teoria bate com a prática.

## O que você vai aprender

- **busca sequencial**: o básico, o custo O(n) e o truque da sentinela
- **busca binária**: O(log n) em vetor ordenado, invariantes e os famosos erros de um
- os três algoritmos simples, O(n²): **bubble sort**, **selection sort** e **insertion sort**
- os dois de dividir e conquistar, O(n log n): **merge sort** e **quick sort**
- **estabilidade**, ordenação in-place e como escolher o algoritmo certo
- usar o **`qsort`** e o **`bsearch`** da biblioteca, com funções de comparação corretas

## Como estudar cada assunto

1. Leia o texto e olhe o **diagrama da ideia**: cada linha de gavetas é um
   momento do algoritmo, com as cores contando o que acontece.
2. Leia o código. É o mesmo exemplo, com os mesmos valores.
3. Faça o **Passo a passo** com papel e lápis antes de conferir a tabela.
4. Siga o **fluxograma** com o dedo.
5. Rode os exemplos. Mude os vetores, compare as contagens.
6. Faça os exercícios. ★☆☆ é aquecimento, ★★☆ pede raciocínio, ★★★ é desafio.
   As dicas ficam escondidas: abra só se travar.

No meio de cada assunto tem uma **Pergunta para você**. Responda antes de rodar.

## As cores e as formas

Nos fluxogramas, caixa azul é dado entrando ou saindo, roxa é o programa
fazendo alguma coisa, amarela é pergunta. Verde é o caminho que o exemplo
segue; cinza, o que ele não usa.

Nos vetores dos diagramas da ideia, as cores contam o estado de cada gaveta:
**amarela** é a que está sendo comparada (ou o menor achado), **roxa** é a
posição ou o pivô da vez, **verde** é o que já está no lugar certo, **cinza**
é o que o algoritmo descartou ou nem olhou, **vermelha** é o que deu errado.

<p align="center"><img src="../legenda.svg" alt="Legenda: formas e cores do fluxograma" width="916"></p>

## Antes de começar

Os exemplos deste módulo cabem cada um num arquivo só: os algoritmos são
funções curtas, e ver a função inteira junto do `main` ajuda mais do que
separar em `.h` e `.c`. Quando um exercício precisa de uma versão diferente
do algoritmo, ele traz tudo no próprio arquivo.

Vários exemplos contam comparações com uma variável `static` de arquivo ou
com um ponteiro para contador. Isso não faz parte do algoritmo: é o
"cronômetro" que mostra o custo. Tempo de relógio varia de máquina para
máquina; o número de comparações, não.

Alguns exercícios de "ache o erro" trazem o bug de propósito, e o
AddressSanitizer (ou o UBSan) do `rodar` vai parar o programa. É esperado: o
enunciado avisa.

{{indice}}

---

{{assuntos}}

---

## Desafios do módulo

Problemas para fechar o módulo, misturando os assuntos. Escreva em C e rode
com o `rodar`.

**1. Quantas voltas no pior caso?** Uma busca binária num vetor ordenado de
5.000 CPFs falhou (o CPF não estava lá). Quantas voltas do laço ela deu, no
máximo? E num vetor de 5 milhões?

<details><summary>Resposta</summary>

O intervalo cai pela metade a cada volta: o máximo é `⌊log₂ n⌋ + 1`. Para
5.000, 2¹² = 4096 ≤ 5000 < 8192 = 2¹³, então **13 voltas**. Para 5 milhões,
2²² = 4.194.304 ≤ 5.000.000 < 2²³, então **23 voltas**. Mil vezes mais dados,
só 10 voltas a mais.

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

**3. Primeiro ordena, depois busca?** Você tem um vetor desordenado de `n =
100.000` elementos e precisa responder `k` buscas. A partir de quantas buscas
vale a pena ordenar (n log₂ n ≈ 1,7 milhão de comparações) e usar busca
binária (17 por busca), em vez de fazer busca sequencial (uns n/2 = 50 mil por
busca)?

<details><summary>Resposta</summary>

Sequencial: `50.000 k`. Ordenar e buscar: `1.700.000 + 17 k`. Igualando,
`k ≈ 34`. Com **mais de umas 34 buscas**, ordenar compensa; com milhares de
buscas, a diferença é enorme. Com 1 ou 2 buscas, ordenar é desperdício.

</details>

**4. Ordenar 0, 1 e 2.** Um vetor tem só os valores 0, 1 e 2 (por exemplo,
`2 0 1 2 1 0 0 2 1`). Ordene em **uma passada**, in-place, sem contar
quantos há de cada.

<details><summary>Resposta</summary>

É a partição de três vias do exercício E600 com pivô 1 (a "bandeira holandesa"
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
com as notas do assunto 0099, `52 18 33 7 41 26 60 12`, e com um vetor de 7
elementos.

<details><summary>Resposta</summary>

Laço de fora: `for (int b = 1; b < n; b *= 2)`. Laço de dentro:
`for (int p = 0; p + b < n; p += 2 * b)` intercala `[p, p + b)` com
`[p + b, min(p + 2b, n))`. O cuidado é o último pedaço, que pode ser menor
(ou nem existir) quando `n` não é potência de 2. O resultado é
`7 12 18 26 33 41 52 60`.

</details>

**7. Quick sort que não estoura a pilha.** Mude o quick sort do A199 para
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
pedaço tiver menos de `L` elementos. Com o contador de comparações do A202,
teste `L = 1, 8, 16, 32` num vetor aleatório de 10.000.

<details><summary>Resposta</summary>

As comparações quase não mudam (às vezes até sobem um pouco), mas o tempo de
relógio costuma cair, com o melhor valor em geral entre 8 e 32: o insertion
não tem recursão nem chamadas, e pedaços pequenos cabem inteiros no cache. É o que as bibliotecas de verdade fazem. Moral: comparações são um bom
modelo, mas não são tudo.

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
para o menor: `return *(const int *) a < *(const int *) b;`. Ela compila. O
que está errado e o que pode acontecer?

<details><summary>Resposta</summary>

Ela devolve só 0 ou 1, nunca negativo. Para o `qsort`, "0" quer dizer
"empate" e "1" quer dizer "a vem depois": quando `a > b`, ela diz que empatam.
O contrato fica inconsistente (se `a` empata com `b` e `b` empata com `c`,
`a` deveria empatar com `c`), e o resultado depende de como a biblioteca
implementa o `qsort`: pode sair certo num computador e errado em outro. O
certo é `return (x < y) - (x > y);`.

</details>

## Para ler mais

- FEOFILOFF, P. *Algoritmos em linguagem C*. Rio de Janeiro: Elsevier, 2009. Caps. de busca em vetor ordenado, ordenação elementar, mergesort e quicksort.
- TENENBAUM, A. M.; LANGSAM, Y.; AUGENSTEIN, M. J. *Estruturas de dados usando C*. São Paulo: Makron Books, 1995. Cap. 6 (classificação) e cap. 7 (busca).
- CELES, W.; RANGEL, J. L. *Apostila de estruturas de dados*. Rio de Janeiro: PUC-Rio, 2002. Parte III: ordenação e busca.
- LAUREANO, M. *Estrutura de dados com algoritmos e C*. Rio de Janeiro: Brasport, 2008. Caps. de busca e ordenação.
- ROCHA, A. M. A.; BORGES, A. R. O. S. *Programação, estruturas de dados e algoritmos em C*. Aveiro: Universidade de Aveiro. Cap. de pesquisa e ordenação.
- DEITEL, P.; DEITEL, H. *C: como programar*. 6. ed. São Paulo: Pearson Prentice Hall, 2011. Cap. 6 (classificação e pesquisa em arrays).
- KERNIGHAN, B. W.; RITCHIE, D. M. *C: a linguagem de programação padrão ANSI*. Rio de Janeiro: Campus, 1989. Seções 4.10 (recursão e quicksort) e 5.11 (ponteiros para funções).
- CORMEN, T. H. et al. *Algoritmos: teoria e prática*. 3. ed. Rio de Janeiro: Elsevier, 2012. Caps. 2 (insertion sort e merge sort) e 7 (quicksort).
- BLOCH, J. Extra, extra: read all about it: nearly all binary searches and mergesorts are broken. *Google Research Blog*, 2006. Disponível em: <https://research.google/blog/extra-extra-read-all-about-it-nearly-all-binary-searches-and-mergesorts-are-broken/>.
- CPPREFERENCE. *qsort, qsort_s* e *bsearch, bsearch_s*. Disponível em: <https://en.cppreference.com/w/c/algorithm>.
- LINUX MAN-PAGES. *qsort(3)* e *bsearch(3)*. Disponível em: <https://man7.org/linux/man-pages/man3/qsort.3.html>.
