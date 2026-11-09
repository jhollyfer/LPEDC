# Módulo 25 · Estruturas especiais

Os módulos anteriores montaram a caixa de ferramentas clássica: listas, pilhas,
filas, árvores, heaps, tabelas hash e grafos. Este módulo mostra três estruturas
que nascem de um problema específico e o resolvem com uma ideia simples, quase
sempre uma lista encadeada com um truque a mais.

A **matriz esparsa** aparece quando quase tudo é zero: notas de clientes para
filmes, voos entre aeroportos, produtos por pedido. Guardar os zeros desperdiça
gigabytes; guardar só o que existe cabe em megabytes. A **skip list** é uma lista
ordenada com linhas expressas sorteadas por uma moeda: busca em O(log n) na
média, sem nenhuma rotação. E as **listas autoajustáveis** aproveitam o fato de
que, na vida real, poucos itens recebem quase todas as buscas: cada busca arruma
a lista um pouco para a próxima.

O assunto final coloca tudo na mesma bancada: BST, AVL, skip list e lista com
mover para a frente respondem ao mesmo teste, atrás da mesma interface de
ponteiros para função. Não existe estrutura melhor em abstrato, só a melhor
**para aquele padrão de uso**, e o jeito honesto de descobrir é medir.

## O que você vai aprender

- guardar uma **matriz esparsa** em **triplas** e em **listas por linha**, sem nunca guardar zero
- somar, transpor e multiplicar matrizes esparsas visitando só o que existe
- a **skip list**: andares, a moeda que sorteia a altura e a busca que desce como um elevador
- inserir e remover numa skip list ligando e desligando o nó em todos os andares
- as três políticas autoajustáveis: **mover para a frente**, **transposição** e **contagem**
- quando cada política ganha e quando perde (o cache **LRU** é uma delas)
- comparar estruturas com justiça: mesmas chaves, mesmas buscas, mesma medida

## Antes de começar

Este módulo é complemento: matriz esparsa, skip list e listas autoajustáveis
não caem direto na prova do PPGI (o que mais cai está em `PPGI.md`, na raiz do
curso).

Cada assunto tem um **TAD** na pasta (`esparsa.h`, `skip.h`, `autolista.h`,
`bancada.h`); abra o `.c` dele, que guarda os ponteiros. Desenhe antes e depois
de cada operação: uma linha da matriz é uma lista, um nó da skip list é uma
torre de ponteiros, e uma busca autoajustável muda a lista. Nos desenhos de
lista, o nó verde é o achado, os amarelos são os comparados pelo caminho e os
cinza, os que a busca nem tocou.

O módulo é uma síntese. Você vai usar o tempo todo a **lista encadeada** com o
par `ant` e `p` (assuntos 0076 a 0078), `malloc` e `free` (0054), **ponteiro para
ponteiro** (0049) e a ideia de **TAD** (0074). O 0164 conversa com a busca
sequencial (0089), e o 0165 usa a BST (0099), a AVL (0101), ponteiros para função
(0050) e `void *` (0051).

O `rodar` compila junto os `.c` de apoio da pasta (como `skip.c`). Por isso os
comandos são os de sempre:

```bash
~/LPEDC/rodar 25-estruturas-extras/0163-skip-list/A325.c
```

Uma convenção vale para o módulo todo: o **custo** de uma busca é quantas chaves
ela comparou. Contar comparações dá o mesmo número em qualquer computador, ao
contrário do cronômetro. E os sorteios usam um gerador próprio de uma linha, em
vez de `rand`, para a mesma semente dar a mesma saída em qualquer máquina.

{{indice}}

---

{{assuntos}}

---

## Desafios do módulo

Problemas para resolver no papel e, quando fizer sentido, num arquivo `.c` seu.
Eles misturam os assuntos do módulo.

**1. Quanto cabe?** Uma matriz de `int` com 20 000 linhas, 20 000 colunas e
60 000 valores diferentes de zero. Quanto ocupa cheia? E com lista por linha
(16 bytes por célula e 8 por ponteiro de linha)? A partir de quantos não-zeros a
lista por linha passa a gastar mais que a matriz cheia?

<details><summary>Resposta</summary>

Cheia: 4 × 10⁸ posições × 4 bytes = **1,6 GB**. Lista por linha: 60 000 × 16 +
20 000 × 8 = 960 000 + 160 000 bytes, cerca de **1,1 MB**. Empata quando
16k + 160 000 = 1,6 × 10⁹, isto é, k perto de **100 milhões** de células: um
quarto das posições. Caminho: cada célula custa 4 `int`s, então a esparsa só
compensa abaixo de 25% de ocupação (na prática, bem abaixo, porque ler uma
posição custa andar na lista).

</details>

**2. Transponha as triplas.** Uma matriz 3 × 4 tem as triplas (0,1,5), (0,3,2),
(1,0,7), (2,1,4) e (2,2,9). Dê as triplas da transposta, em ordem de linha e
coluna. Quantas triplas cada linha da transposta tem?

<details><summary>Resposta</summary>

Trocando linha e coluna e reordenando: **(0,1,7) (1,0,5) (1,2,4) (2,2,9) (3,0,2)**.
A transposta tem 4 linhas, com 1, 2, 1 e 1 triplas: é a contagem das colunas da
original. Com essa contagem dá para transpor sem ordenar: as somas acumuladas
(0, 1, 3, 4) dizem em que posição começa cada linha nova, como no counting sort.

</details>

**3. A soma que some.** A linha 2 de A tem as células (col 1: 4), (col 3: -2) e
(col 6: 5). A linha 2 de B tem (col 0: 1), (col 3: 2) e (col 6: 1). Quais células
estão na linha 2 de A + B, e quantas comparações de coluna a intercalação faz?

<details><summary>Resposta</summary>

**(col 0: 1) (col 1: 4) (col 6: 6)**: a coluna 3 deu 0 e não entra. A intercalação
compara 1 com 0 (sai o 0 de B), 1 com 3 (sai o 1 de A), 3 com 3 (soma, zera), 6
com 6 (soma): **4 comparações**, e nenhuma lista sobra. O custo é proporcional às
células das duas linhas, não ao número de colunas.

</details>

**4. A moeda em números.** Uma skip list tem 1024 nós e a moeda sobe com
probabilidade 1/2. Quantos nós chegam ao andar 3 (o quarto, contando do 0), em
média? Quantos ponteiros a lista usa ao todo? E com probabilidade 1/4?

<details><summary>Resposta</summary>

Com 1/2: 1024 / 2³ = **128** nós no andar 3, e cerca de 1024 × 2 = **2048**
ponteiros (a média de andares por nó é 1 + 1/2 + 1/4 + ... = 2). Com 1/4: 1024 /
4³ = **16** nós no andar 3 e cerca de 1024 × 4/3 ≈ **1365** ponteiros. O exercício
E975 mostra que a busca custa quase o mesmo nos dois casos.

</details>

**5. Duas buscas na rodovia.** Na skip list do texto (andar 2: 23 56; andar 1: 12
23 40 56; andar 0: 5 12 18 23 31 40 47 56), quantos nós `skip_busca` olha para
achar o 31? E para procurar o 60?

<details><summary>Resposta</summary>

31: olha o 23 (avança) e o 56 no andar 2, o 40 no andar 1 e o 31 no andar 0:
**4 nós**. 60: olha o 23 e o 56 no andar 2 (avança nos dois) e, a partir do 56,
não há mais ninguém em nenhum andar: **2 nós**, e não acha. A chave maior que todas
é a busca mais barata: o direto leva até o fim da linha.

</details>

**6. A torre nova.** Na mesma skip list, o km 35 entra com 3 andares. Quem fica
em `antes[0]`, `antes[1]` e `antes[2]`? Como ficam os três andares?

<details><summary>Resposta</summary>

`antes[2]` = 23, `antes[1]` = 23 e `antes[0]` = 31. Andar 2: **23 35 56**;
andar 1: **12 23 35 40 56**; andar 0: **5 12 18 23 31 35 40 47 56**. Mudam três
ponteiros antigos (o `prox[2]` e o `prox[1]` do 23 e o `prox[0]` do 31) e o nó
novo recebe três.

</details>

**7. Três políticas, uma sequência.** A lista começa como [A, B, C, D] e recebe os
acessos D, D, C, D, A. Calcule o custo total e a lista final com mover para a
frente, com transposição e com contagem.

<details><summary>Resposta</summary>

Mover para a frente: 4 + 1 + 4 + 2 + 3 = **14**, final [A, D, C, B].
Transposição: 4 + 3 + 4 + 2 + 2 = **15**, final [A, D, C, B]. Contagem: 4 + 1 + 4 +
1 + 3 = **13**, final [D, C, A, B] (o D, com 3 acessos, nunca sai da frente).
Confira com o TAD `autolista.h`.

</details>

**8. O pior dia do mover para a frente.** A lista tem n itens. Que sequência de
acessos faz cada busca com mover para a frente custar n? Quanto a lista fixa
gastaria em média, com a mesma sequência?

<details><summary>Resposta</summary>

Acessar sempre o **último** da lista: com [A, B, C, D], a sequência D, C, B, A,
D, C, B, A... (depois de cada acesso, o próximo da sequência é o que ficou no
fim). Cada busca custa **n**. A lista fixa [A, B, C, D] gasta 4 + 3 + 2 + 1 a cada
quatro acessos: **(n + 1)/2** em média. A razão fica abaixo de 2, como garante o
resultado de Sleator e Tarjan.

</details>

**9. O cache de duas fotos.** Um cache LRU com capacidade 2 recebe os pedidos 1,
2, 1, 3, 2, 1. Quantos acertos e quantas faltas? E com capacidade 3?

<details><summary>Resposta</summary>

Capacidade 2: falta [1], falta [2 1], acerto [1 2], falta [3 1] (sai o 2), falta
[2 3] (sai o 1), falta [1 2]: **1 acerto e 5 faltas**. Capacidade 3: falta, falta,
acerto, falta [3 1 2], acerto [2 3 1], acerto [1 2 3]: **3 acertos e 3 faltas**.
Um lugar a mais no cache triplicou os acertos.

</details>

**10. Somar uma coluna.** Uma matriz esparsa 1000 × 1000 tem 5000 não-zeros,
5 por linha, espalhados. Quantas células você visita, no máximo, para somar a
coluna 999 com listas por linha? E se cada célula também estivesse numa lista
por coluna (as **listas cruzadas**)?

<details><summary>Resposta</summary>

Com listas por linha, você percorre a linha inteira de cada uma das 1000 linhas
para saber se a coluna 999 está lá: até **5000 células** (com a coluna 999, que é
a última, nenhuma linha termina cedo). Com listas cruzadas, você anda só na lista
da coluna 999: uns **5 nós**. O preço é um segundo ponteiro (e o índice da
linha) em cada célula, e inserir ou remover passa a mexer em duas listas.

</details>

**11. Qual estrutura?** Para cada caso, escolha entre AVL, skip list, lista com
mover para a frente e tabela hash: (a) um corretor que consulta sempre as mesmas
50 palavras de uma lista de 200; (b) listar todos os produtos entre R$ 20 e R$ 50
num catálogo que muda o dia todo; (c) saber se um CPF já votou, entre 10 milhões;
(d) as últimas telas abertas num aplicativo.

<details><summary>Resposta</summary>

(a) **lista MTF**: poucos itens, acessos muito concentrados (ou hash, se a lista
crescer); (b) **AVL ou skip list**: as duas mantêm a ordem e fazem a busca por
faixa (E974); a skip list com um código mais simples; (c) **hash**: só pergunta
"está ou não está", sem ordem; (d) **lista MTF com corte**, o LRU do E983.

</details>

## Questões no estilo da prova

Estas estruturas não caem direto na prova do PPGI, mas questões no
mesmo formato treinam o que cai: contar memória, contar comparações e
separar custo esperado de pior caso. Uma alternativa certa em cada.

**1.** Uma matriz 1000 × 1000 de `int` tem 2000 valores diferentes de zero.
Ela é guardada como lista por linha: um vetor de 1000 ponteiros (8 bytes
cada) e uma célula `struct { int coluna; int valor; struct Cel *prox; }`
(16 bytes) por valor. Quanto ocupa, perto de, a versão esparsa, e quanto a
matriz cheia?

- (A) 24 KB e 4 MB
- (B) 40 KB e 4 MB
- (C) 40 KB e 1 MB
- (D) 4 MB e 4 MB
- (E) 32 KB e 8 MB

<details><summary>Gabarito</summary>

**(B).** 2000 × 16 + 1000 × 8 = 40.000 bytes, contra 1000 × 1000 × 4 =
4.000.000 bytes da matriz cheia: 100 vezes menos. O ponteiro `prox` e o
enchimento entram na conta; esquecer o vetor de linhas dá os 32 KB de (E).
Veja 0162.

</details>

**2.** Na matriz esparsa por listas, o que deve acontecer quando o programa
grava 0 numa célula que já existe na lista?

- (A) A célula fica com valor 0, para manter a posição.
- (B) A linha inteira é apagada.
- (C) A célula é removida da lista, porque zero não se guarda.
- (D) Nada: gravar 0 é proibido.
- (E) A matriz é convertida para a forma cheia.

<details><summary>Gabarito</summary>

**(C).** Quem não está na lista vale 0. Se o zero ficasse guardado, a
estrutura engordaria com células inúteis e cada leitura da linha andaria
mais. Veja 0162.

</details>

**3.** Numa skip list em que cada nó sobe mais um andar com probabilidade
1/2, quantos nós, em média, aparecem no andar 3 ou acima, com `n = 1024`
chaves?

- (A) 128
- (B) 256
- (C) 512
- (D) 10
- (E) 341

<details><summary>Gabarito</summary>

**(A).** Um nó chega ao andar `k` com probabilidade (1/2)^k: 1024 / 8 = 128.
Somando todos os andares, o número esperado de ponteiros é 2n, e a altura
esperada fica perto de log₂ n = 10. Veja 0163.

</details>

**4.** Sobre a busca numa skip list com `n` chaves, assinale a alternativa
**correta**:

- (A) O(log n) no pior caso, como na AVL.
- (B) O(1), porque a cabeça está em todos os andares.
- (C) O(n) esperado, porque o andar 0 tem todas as chaves.
- (D) O(log n) esperado, na média dos sorteios; no pior caso, O(n).
- (E) O(√n) sempre.

<details><summary>Gabarito</summary>

**(D).** A garantia é probabilística: um azar (todos os nós no andar 0)
transforma a skip list numa lista comum. A AVL garante O(log n) no pior
caso (A). Veja 0163 e 0165.

</details>

**5.** A lista `A B C D` usa **mover para a frente**. Ela recebe as buscas
D, C, D, A, nessa ordem, e cada busca custa a posição do item. Qual o custo
total e a ordem final?

- (A) 10, `D C A B`
- (B) 13, `A B D C`
- (C) 11, `A D C B`
- (D) 16, `A B C D`
- (E) 13, `A D C B`

<details><summary>Gabarito</summary>

**(E).** D custa 4 (fica `D A B C`), C custa 4 (`C D A B`), D custa 2
(`D C A B`), A custa 3 (`A D C B`): 4 + 4 + 2 + 3 = 13. Com
**transposição**, o total também dá 13, mas a ordem final é `A B D C`
(alternativa B). Sem ajuste nenhum, seriam 4 + 3 + 4 + 1 = 12. Veja 0164.

</details>

**6.** Três contatos são procurados com probabilidades 0,5, 0,3 e 0,2 numa
busca sequencial. Qual o número **esperado** de comparações com a melhor
ordem fixa?

- (A) 2,3
- (B) 2,0
- (C) 1,0
- (D) 1,5
- (E) 1,7

<details><summary>Gabarito</summary>

**(E).** A melhor ordem fixa é a de probabilidade decrescente: 1 × 0,5 +
2 × 0,3 + 3 × 0,2 = 1,7. Na ordem inversa, 2,3 (A). A política de
**contagem** converge para essa ordem; mover para a frente chega perto sem
conhecer as probabilidades. Veja 0164.

</details>

**7.** Mil chaves entram, em ordem crescente, numa BST sem balanceamento.
Quantas comparações a busca pela maior chave faz, e quantas faria uma AVL
com as mesmas chaves, no máximo, aproximadamente?

- (A) 10 e 10
- (B) 500 e 10
- (C) 1000 e cerca de 14
- (D) 1000 e 1000
- (E) 1 e 10

<details><summary>Gabarito</summary>

**(C).** Em ordem crescente, cada chave vira filha direita da anterior, e a
BST é uma lista de altura 999: a maior está a 1000 comparações. A altura da
AVL é no máximo cerca de 1,44 log₂ n, uns 14 níveis para 1000 chaves (na
prática, perto de 10). Veja 0165, 0099 e 0101.

</details>

**8.** Por que a lista encadeada combina melhor com **mover para a frente**
do que um vetor?

- (A) Porque no vetor a busca sequencial é mais lenta.
- (B) Porque, achado o nó (com o anterior guardado), tirá-lo do lugar e pô-lo no início são três atribuições de ponteiro, O(1); no vetor, é preciso empurrar todos os anteriores, O(posição).
- (C) Porque a lista ocupa menos memória que o vetor.
- (D) Porque o vetor não permite busca sequencial.
- (E) Porque a lista mantém as chaves ordenadas.

<details><summary>Gabarito</summary>

**(B).** A busca custa o mesmo nos dois, O(posição); a diferença está na
mudança de lugar. Já a **transposição** troca dois vizinhos e funciona bem
nas duas representações. A lista gasta **mais** memória, por causa dos
ponteiros (C). Veja 0164.

</details>

## Para ler mais

- SZWARCFITER, J. L.; MARKENZON, L. *Estruturas de dados e seus algoritmos*. 3. ed. Rio de Janeiro: LTC, 2010. Capítulos sobre listas (exercícios de matriz esparsa) e listas autoajustáveis.
- CORTÉS, M. I. *Estrutura de dados*. 3. ed. Fortaleza: EdUECE, 2015. Capítulo de busca avançada: estruturas autoajustáveis.
- TENENBAUM, A. M.; LANGSAM, Y.; AUGENSTEIN, M. J. *Estruturas de dados usando C*. São Paulo: Makron Books, 1995. Cap. 7 (busca: reordenação da lista, mover para a frente e transposição).
- FEOFILOFF, P. *Algoritmos em linguagem C*. Rio de Janeiro: Elsevier, 2009. Capítulos sobre listas encadeadas e busca.
- CELES, W.; CERQUEIRA, R.; RANGEL, J. L. *Introdução a estruturas de dados: com técnicas de programação em C*. Rio de Janeiro: Elsevier, 2004.
- PUGH, W. Skip lists: a probabilistic alternative to balanced trees. *Communications of the ACM*, v. 33, n. 6, p. 668-676, 1990.
- SLEATOR, D. D.; TARJAN, R. E. Amortized efficiency of list update and paging rules. *Communications of the ACM*, v. 28, n. 2, p. 202-208, 1985.
- MORIN, P. *Open data structures*. Edmonton: AU Press, 2013. Cap. 4: skiplists. Disponível em: <https://opendatastructures.org/>.
- SEDGEWICK, R. *Algorithms in C*: parts 1-4. 3. ed. Reading: Addison-Wesley, 1998. Cap. 13 (skip lists) e busca sequencial auto-organizável.
- CORMEN, T. H.; LEISERSON, C. E.; RIVEST, R. L.; STEIN, C. *Algoritmos: teoria e prática*. 4. ed. Rio de Janeiro: GEN LTC, 2024. Cap. 27 (algoritmos on-line: manter uma lista de busca com mover para a frente e análise competitiva).
- KERNIGHAN, B. W.; RITCHIE, D. M. *C: a linguagem de programação padrão ANSI*. Rio de Janeiro: Campus, 1989. Seção 5.11: ponteiros para funções.
- CPPREFERENCE. *Struct declaration: flexible array member*. Disponível em: <https://en.cppreference.com/w/c/language/struct>.
