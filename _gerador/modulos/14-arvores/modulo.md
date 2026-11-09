# Módulo 14 · Árvores

Até aqui, toda estrutura de dados do curso era uma fila de elementos: vetor,
lista, pilha, fila. Cada um tinha um antes e um depois. Só que muita coisa no
mundo não é fila, é **hierarquia**: as pastas do computador, a árvore
genealógica, o organograma da empresa, o sumário de um livro, a fórmula de uma
planilha. Para isso existe a **árvore**.

A árvore também resolve um problema que ficou aberto no módulo de busca: a
busca binária é rápida, mas exige um vetor ordenado, e inserir no meio de um
vetor custa caro. A **árvore binária de busca** busca e insere descendo um único
caminho. Quando ela fica torta, a **AVL** a endireita com rotações. E quando
você só precisa do maior elemento, o **heap** faz isso morando num vetor
comum, sem ponteiro nenhum, e ainda serve para ordenar (o **heapsort**).

Quase tudo aqui é recursivo. Uma árvore é um nó com árvores menores
penduradas, então a função que resolve a árvore resolve cada subárvore e junta
as respostas. Se a recursão do módulo 04 ficou nebulosa, aqui ela ganha
sentido.

## O que você vai aprender

- o vocabulário das árvores: **raiz**, **filho**, **folha**, **altura** e **profundidade**
- a **árvore binária** em C e os quatro **percursos**: pré-ordem, em ordem, pós-ordem e por nível
- a **árvore binária de busca** (BST): busca, inserção e os três casos da **remoção**
- por que a BST pode virar uma lista, e como a **AVL** se equilibra com **rotações**
- o **heap** num vetor e a **fila de prioridade**
- o **heapsort**: ordenar em O(n log n) sem memória extra
- montar um programa que junta BST e heap, cada um no que faz melhor

## Antes de começar

Você precisa estar à vontade com **recursão** (assuntos 0032 e 0033),
**ponteiros para struct** e `->` (0062), `malloc` e `free` (0054) e a ideia de
**TAD** com `.h` e `.c` (0074). A fila do assunto 0085 aparece no percurso por
nível, e o assunto 0090 (busca binária) é o primo da BST.

A partir do 0098, cada assunto tem um TAD na pasta (`arvore.h`, `bst.h`,
`avl.h`, `heap.h`, `cadastro.h`) e o exemplo só usa a interface: abra o `.c`
também, porque o algoritmo está nele. Nos desenhos de árvore, as arestas
verdes marcam o caminho de uma busca e o nó vermelho é o que vai sair ou o
que está desequilibrado. Desenhe a árvore no papel a cada inserção e remoção
antes de rodar, e use a saída só para conferir.

O `rodar` compila junto os `.c` de apoio da pasta (como `bst.c`). Por isso os
comandos dos exemplos e exercícios são os de sempre:

```bash
~/LPEDC/rodar 14-arvores/0099-bst-busca-insercao/A197.c
```

Uma convenção vale para o módulo todo: **altura conta arestas**. Uma folha tem
altura 0 e a árvore vazia tem altura -1. Alguns livros contam nós (folha com
altura 1): confira a convenção quando consultar outro material.

{{indice}}

---

{{assuntos}}

---

## Desafios do módulo

Problemas para fechar o módulo, misturando os assuntos. Escreva em C e rode
com o `rodar`; quando o desafio citar `avl.h` ou `heap.h`, copie o `.h` e o
`.c` do assunto para a pasta do seu arquivo.

**1. Quantos nós cabem?** Escreva `int max_nos(int h)`, que soma os níveis
cheios (1 + 2 + 4 + ...) de uma árvore binária de altura `h`, e mostre o menor
e o maior número de nós de uma árvore de altura 4. Com um `while`, ache a
menor altura que comporta 1000 chaves. Depois confira na prática com uma BST:
insira 1, 2, ..., 1000 em ordem e mostre a altura; libere, insira as mesmas
chaves "pelo meio" (uma função recursiva que insere o meio de `[ini, fim]` e
depois chama a si mesma para cada metade) e mostre a altura de novo.

<details><summary>Resposta</summary>

```text
Altura 4: de 5 a 31 nós
1000 chaves: altura mínima 9, máxima 999
BST inserindo 1, 2, ..., 1000: altura 999
BST inserindo pelo meio: altura 9
```

O mínimo de altura h é uma fila indiana, h + 1 nós; o máximo é 2^(h+1) - 1,
todos os níveis cheios. Altura 8 comporta só 511 nós, altura 9 comporta 1023:
por isso 9. Inserir em ordem dá a pior árvore possível, uma lista de 1000 nós
(a recursão da altura desce 1000 níveis e ainda cabe na pilha). Inserir pelo
meio dá a melhor. A altura é a de sempre: vazia vale -1, e cada nó vale
1 + o maior dos filhos.

</details>

**2. Reconstrua a árvore.** Uma árvore binária de `char` tem pré-ordem
`FBADCEGIH` e em ordem `ABCDEFGHI`. Escreva `No *reconstroi(const char *pre,
const char *em, int n)`, que monta a árvore a partir das duas strings, e
mostre a árvore com recuo de dois espaços por nível (prefixo `e: ` para filho
esquerdo e `d: ` para direito) e a pós-ordem.

<details><summary>Resposta</summary>

```text
F
  e: B
    e: A
    d: D
      e: C
      d: E
  d: G
    d: I
      e: H
Pós-ordem: A C E D B H I G F
```

A pré-ordem diz que `pre[0]` é a raiz; ache a posição `k` dela em `em`: os `k`
primeiros de `em` são a subárvore esquerda, e o resto depois dela, a direita.
Em código: `r->esq = reconstroi(pre + 1, em, k)` e `r->dir = reconstroi(pre +
1 + k, em + k + 1, n - 1 - k)`, com `n == 0` devolvendo `NULL`. O recuo é
`printf("%*s%s%c\n", 2 * nivel, "", lado, r->info)`. Com pré-ordem e
pós-ordem sozinhas não dá para reconstruir sempre: um filho único pode ser
esquerdo ou direito.

</details>

**3. Conte as BSTs.** Gere as 6 ordens de inserção das chaves 1, 2 e 3 (três
`for` de 1 a 3, pulando as repetidas), insira cada ordem numa BST vazia e
mostre a pré-ordem que sai. Como a pré-ordem de uma BST identifica a árvore,
guarde as pré-ordens já vistas numa matriz `int vistas[6][3]` e conte quantas
BSTs diferentes apareceram e quantas ordens deram raiz 2.

<details><summary>Resposta</summary>

```text
ordem 1 2 3 -> pré-ordem 1 2 3
ordem 1 3 2 -> pré-ordem 1 3 2
ordem 2 1 3 -> pré-ordem 2 1 3
ordem 2 3 1 -> pré-ordem 2 1 3
ordem 3 1 2 -> pré-ordem 3 1 2
ordem 3 2 1 -> pré-ordem 3 2 1
BSTs diferentes: 5
Ordens que dão raiz 2: 2
```

A de raiz 2 (a equilibrada) sai de duas ordens, 2 1 3 e 2 3 1; cada uma das
outras quatro sai de uma ordem só. Inserir em ordem aleatória favorece as
árvores mais equilibradas. A pré-ordem vai para um vetor com um contador
passado por ponteiro (`v[(*n)++] = r->chave`), e libere cada árvore antes da
próxima ordem.

</details>

**4. A BST de nomes.** Faça uma BST de nomes (`char nome[16]` no nó, comparação
com `strcmp`) e insira, nesta ordem, Maria, Carlos, Tiago, Ana, Fernanda, Rui
e Zélia. Mostre a altura e os nós por onde passa a busca por "Fernanda". Por
fim, insira também "Élio" e mostre todos os nomes em ordem.

<details><summary>Resposta</summary>

```text
Altura: 2
Busca por Fernanda: Maria Carlos Fernanda
Em ordem: Ana Carlos Fernanda Maria Rui Tiago Zélia Élio
```

Maria na raiz; Carlos (Ana, Fernanda) à esquerda; Tiago (Rui, Zélia) à
direita. A busca é um `while` que mostra o nome do nó antes de decidir o lado
com `strcmp`. O "Élio" no fim é a pegadinha: `strcmp` compara bytes, e em
UTF-8 o `É` começa com o byte 195, maior que qualquer letra sem acento. Por
isso ele fica depois de "Zélia".

</details>

**5. Remoções em sequência.** Monte a BST inserindo 50, 30, 70, 20, 40, 60 e
80 e, usando a remoção pelo **sucessor** do assunto 0100, remova 50, depois
60, depois 70. Mostre a pré-ordem no início e depois de cada remoção.

<details><summary>Resposta</summary>

```text
Início: 50 30 20 40 70 60 80
Sem o 50: 60 30 20 40 70 80
Sem o 60: 70 30 20 40 80
Sem o 70: 80 30 20 40
```

Sem o 50, o sucessor 60 sobe. Sem o 60 (raiz de novo, dois filhos), o
sucessor 70 sobe e o 80 fica à direita dele. Sem o 70, o sucessor é o 80, que
era folha. Remover sempre pelo sucessor deixa a árvore pendendo para a
esquerda. A pré-ordem é `printf(" %d", r->chave)` antes das duas
chamadas recursivas.

</details>

**6. AVL de 1 a 10.** Com o `avl.h` do assunto 0101, insira 1, 2, ..., 10
numa AVL vazia e mostre a pré-ordem, a raiz, a altura (`avl_altura`) e
quantas rotações simples aconteceram (`avl_rotacoes`).

<details><summary>Resposta</summary>

```text
Pré-ordem: 4 2 1 3 8 6 5 7 9 10
Raiz: 4
Altura: 3
Rotações: 6
```

As 6 rotações são todas à esquerda, ao inserir 3, 5, 6, 7, 9 e 10: inserir em
ordem sempre pende a árvore para a direita. Numa BST comum a mesma sequência
daria altura 9; a AVL fica com 3, o mínimo para 10 nós. A raiz está em
`r->chave`, porque o `avl.h` deixa a struct à mostra.

</details>

**7. A AVL mais magra.** Escreva `No *magra(int h)`, que monta a AVL com o
**menor** número de nós de altura `h`: a raiz tem, à esquerda, `magra(h - 1)`
e, à direita, `magra(h - 2)` (altura negativa é `NULL`). Para h de 0 a 5,
mostre quantos nós ela tem, quantos tem a árvore cheia da mesma altura, a
altura medida e se todo nó tem fator entre -1 e 1.

<details><summary>Resposta</summary>

```text
 h  magra  cheia  altura  AVL?
 0      1      1       0  sim
 1      2      3       1  sim
 2      4      7       2  sim
 3      7     15       3  sim
 4     12     31       4  sim
 5     20     63       5  sim
```

N(h) = N(h - 1) + N(h - 2) + 1: uma subárvore com altura h - 1, a outra com
h - 2, mais a raiz. Como cresce como Fibonacci, a altura de uma AVL fica
abaixo de uns 1,44 · log₂ n. A cheia começa em 1 e vira `2 * cheia + 1` a cada
nível. A conferência de AVL é recursiva: o fator da raiz entre -1 e 1 **e** as
duas subárvores AVL.

</details>

**8. Heap ou BST?** Insira os preços 45, 12, 78, 33, 90, 5 e 61 num heap de
máximo (`heap.h`) e numa BST. Mostre o vetor do heap e, para cada estrutura,
conte quantos nós ou posições você olha para: achar o menor, achar o maior e
buscar o 33. No heap, o menor só pode estar nas folhas (de `n / 2` a
`n - 1`), e a busca é sequencial. No fim, liste os preços em ordem pela BST
(em ordem) e pelo heap (esvaziando com `heap_remove`).

<details><summary>Resposta</summary>

```text
Heap: [90 78 61 12 33 5 45]
BST, menor: 5 (3 nós)
BST, maior: 90 (3 nós)
Heap, maior: 90 (1 posição)
Heap, menor: 5 (4 posições: as folhas)
BST, busca 33: 3 nós
Heap, busca 33: 5 posições
BST em ordem: 5 12 33 45 61 78 90
Heap esvaziado: 90 78 61 45 33 12 5
```

O heap só é bom no que ele promete: o maior em O(1). Menor e maior a qualquer
momento, busca por uma chave qualquer e listagem em ordem são da BST (a
listagem pelo heap **destrói** o heap; com um milhão de preços, olhar as
folhas seria olhar meio milhão). Já "atender sempre o pedido mais antigo de
uma lista que muda" é de um heap de mínimo pela hora do pedido. Para saber se
um CPF está cadastrado, a BST ganha do heap, e no módulo 15 a tabela hash
ganha das duas.

</details>

**9. Heap de 1 a 7.** Com o `heap.h`, insira 1, 2, 3, 4, 5, 6 e 7, nesta
ordem, num heap de máximo vazio e mostre o vetor com `heap_mostra`. Remova o
máximo duas vezes, mostrando o vetor depois de cada remoção.

<details><summary>Resposta</summary>

```text
[7 4 6 1 3 2 5]
sem o 7: [6 4 5 1 3 2]
sem o 6: [5 4 2 1 3]
```

Cada número novo entra no fim e sobe enquanto for maior que o pai, por isso o
7 chega à raiz e o 1 vai parar na posição 3. Sem o 7, o último (5) vai para a
raiz e desce pelo 6; sem o 6, o 2 vai para a raiz e desce pelo 5.

</details>

**10. Os 10 maiores de um milhão.** Gere um milhão de números, um de cada vez,
com `x = i * 7919 % 1000003` para `i` de 1 a 1.000.000 (faça a conta em
`long`), sem guardar todos. Mantenha um **heap de mínimo** com 10 posições: os
10 primeiros enchem o heap; depois, cada número que for maior que a raiz
entra no lugar dela e desce. No fim, mostre os 10 maiores do maior para o
menor, quantos números entraram no lugar da raiz e quantos bytes o heap usa,
comparando com guardar o milhão.

<details><summary>Resposta</summary>

```text
Os 10 maiores: 1000002 1000001 1000000 999999 999998 999997 999996 999995 999994 999993
Trocas na raiz: 199
Memória do heap: 40 bytes (guardar tudo: 4000000 bytes)
```

Cada número custa uma comparação com a raiz e, só quando entra, uma descida de
log₂ 10 ≈ 3 níveis: O(n log 10). Ordenar tudo custaria O(n log n), uns 20
milhões de comparações, e guardaria tudo; um heap de máximo com todos também
guardaria tudo. O `desce` do heap de mínimo é o do `heap.c` com os sinais
trocados (troca com o **menor** filho). Para mostrar do maior para o menor,
tire a raiz 10 vezes guardando de trás para frente num vetor. É o exercício
E611 em escala.

</details>

## Questões no estilo da prova

Questões objetivas no formato da prova do mestrado. Desenhe a árvore no papel
a cada passo. As medidas seguem o Cormen: altura e profundidade contadas em
**arestas**, raiz com profundidade (nível) 0.

As questões 1, 2, 3 e 9 usam a BST montada inserindo, nesta ordem, as chaves
`45 20 60 10 30 50 70 25 35` numa árvore vazia.

**1.** Qual é o percurso em **pós-ordem** dessa BST?

- (A) `10 20 25 30 35 45 50 60 70`
- (B) `10 25 35 30 20 50 70 60 45`
- (C) `45 20 10 30 25 35 60 50 70`
- (D) `10 25 30 35 20 50 60 70 45`
- (E) `25 35 10 30 50 70 20 60 45`

<details><summary>Gabarito</summary>

**B.** A árvore tem 45 na raiz; 20 (filhos 10 e 30, e o 30 com 25 e 35) à
esquerda; 60 (filhos 50 e 70) à direita. Pós-ordem é esquerda, direita, raiz.
A (A) é a em ordem (crescente, como em toda BST) e a (C), a pré-ordem. Veja
0098 e 0099.

</details>

**2.** Sobre a mesma BST, qual afirmação é correta?

- (A) A altura da árvore é 4.
- (B) A árvore tem 4 folhas.
- (C) O 60 está no nível 2.
- (D) O fator de balanceamento da raiz, `altura(esq) - altura(dir)`, é 0.
- (E) A altura da árvore é 3, a profundidade do 25 é 3 e o grau do 20 é 2.

<details><summary>Gabarito</summary>

**E.** O caminho mais longo é 45, 20, 30, 25: 3 arestas. A (A) conta nós em
vez de arestas (convenção de outros livros). Folhas são 10, 25, 35, 50 e 70:
cinco. O 60 é filho da raiz: nível 1. A subárvore esquerda tem altura 2 e a
direita, 1: fator +1. Veja 0097, 0101 e o assunto 0175, que aprofunda nível,
grau e fator de balanceamento.

</details>

**3.** Remove-se a raiz 45 da mesma BST com o algoritmo do Cormen, que
coloca o **sucessor** no lugar de um nó com dois filhos. Qual é a pré-ordem
depois da remoção?

- (A) `50 20 10 30 25 35 60 70`
- (B) `35 20 10 30 25 60 50 70`
- (C) `60 20 10 30 25 35 50 70`
- (D) `50 20 10 30 25 35 70 60`
- (E) `20 10 30 25 35 60 50 70`

<details><summary>Gabarito</summary>

**A.** O sucessor de 45 é o menor da subárvore direita: o 50, que é folha.
Ele sobe para a raiz e o 60 fica só com o 70. A (B) é o resultado com o
**antecessor** (o 35, maior da esquerda), a outra convenção. Veja 0100.

</details>

**4.** Numa AVL vazia são inseridas as chaves `50 20 80 10 30 25`, nesta
ordem. Qual é a pré-ordem final e o que aconteceu na última inserção?

- (A) `20 10 50 30 25 80`; rotação simples à direita no 50
- (B) `50 25 20 10 30 80`; rotação simples à esquerda no 20
- (C) `30 20 10 25 50 80`; rotação dupla (esquerda no 20, direita no 50)
- (D) `30 20 10 25 50 80`; rotação simples à direita no 50
- (E) `50 20 10 30 25 80`; nenhuma rotação

<details><summary>Gabarito</summary>

**C.** O 25 entra à esquerda do 30. O 50 fica com fator +2 e o filho
esquerdo (20) com fator −1: caso esquerda-direita, zigue-zague. Gira à
esquerda no 20 (o 30 sobe) e à direita no 50: o 30 vira a raiz. A (A) é o que
uma rotação simples faria: o 20 subiria e o desequilíbrio só trocaria de lado.
Veja 0101.

</details>

**5.** Num heap de máximo guardado em vetor (raiz em `v[0]`), inicialmente
vazio, são inseridas as chaves `15 40 25 60 10 50`, nesta ordem, cada uma
subindo enquanto for maior que o pai. Qual é o vetor final?

- (A) `60 50 40 25 15 10`
- (B) `60 40 25 15 10 50`
- (C) `60 15 50 40 10 25`
- (D) `60 40 50 15 10 25`
- (E) `50 40 60 15 10 25`

<details><summary>Gabarito</summary>

**D.** Depois de 15, 40, 25: `40 15 25`. O 60 entra no índice 3, sobe pelo 15
e pelo 40: `60 40 25 15`. O 10 fica no índice 4. O 50 entra no índice 5, pai
no índice 2 (o 25): troca, e para abaixo do 60. A (B) esquece essa subida.
Veja 0102.

</details>

**6.** No Cormen, o heap fica em `A[1..n]`, com `PARENT(i) = ⌊i/2⌋`,
`LEFT(i) = 2i` e `RIGHT(i) = 2i + 1`. Para o elemento `A[7]`, quais são o pai
e os filhos?

- (A) pai `A[3]`; filhos `A[15]` e `A[16]`
- (B) pai `A[3]`; filhos `A[14]` e `A[15]`
- (C) pai `A[2]`; filhos `A[13]` e `A[14]`
- (D) pai `A[4]`; filhos `A[14]` e `A[15]`
- (E) pai `A[3]`; filhos `A[8]` e `A[9]`

<details><summary>Gabarito</summary>

**B.** ⌊7/2⌋ = 3, 2 · 7 = 14 e 2 · 7 + 1 = 15. A (C) mistura as fórmulas do
vetor que começa em 0 (pai `(i − 1)/2`, filhos `2i + 1` e `2i + 2`), que dão,
para `v[6]` (o mesmo elemento), pai `v[2]` e filhos `v[13]` e `v[14]`. Veja
0102.

</details>

**7.** O `BUILD-MAX-HEAP` (fazer cada pai descer, do último pai até a raiz) é
aplicado ao vetor `12 4 30 9 18 7 25 3`. Qual é o resultado?

- (A) `30 18 25 4 9 7 12 3`
- (B) `30 12 25 9 18 7 4 3`
- (C) `30 4 25 9 18 7 12 3`
- (D) `30 18 12 9 4 7 25 3`
- (E) `30 18 25 9 4 7 12 3`

<details><summary>Gabarito</summary>

**E.** Os pais são os índices 3, 2, 1 e 0. O 9 já é maior que o 3; o 30 já é
maior que 7 e 25; o 4 troca com o 18; o 12 troca com o 30 e depois com o 25.
A (A) é o heap que se obtém **inserindo** um por um: também é um heap válido,
mas outro. A construção de baixo para cima custa O(n). Veja 0103.

</details>

**8.** Uma árvore binária tem pré-ordem `M D B F K R P W` e em ordem
`B D F K M P R W`. Qual é a pós-ordem?

- (A) `B K F D P W R M`
- (B) `B F K D P W R M`
- (C) `K F B D W P R M`
- (D) `B D F K P R W M`
- (E) `W P R K F B D M`

<details><summary>Gabarito</summary>

**A.** A pré-ordem diz a raiz (M); a em ordem separa os lados: `B D F K` à
esquerda e `P R W` à direita. Repetindo: D com B à esquerda e F à direita, e o
K é filho direito do F; R com P e W. Pós-ordem: `B K F D P W R M`. Veja 0098.

</details>

**9.** Na BST das questões 1 a 3 (antes de qualquer remoção), quem é o
**sucessor** (o próximo na em ordem) do 35?

- (A) 30
- (B) 25
- (C) 50
- (D) 45
- (E) o 35 não tem sucessor

<details><summary>Gabarito</summary>

**D.** O 35 não tem filho direito. Então o sucessor é o ancestral mais baixo
do qual o 35 está na subárvore **esquerda**: sobe 35, 30, 20 (todos filhos
direitos) até o 20, que é filho esquerdo do 45. É a `TREE-SUCCESSOR` do
Cormen. Veja 0099 (a em ordem) e o assunto 0175, que aprofunda sucessor e
antecessor.

</details>

**10.** Sobre árvores balanceadas, assinale a afirmação **falsa**.

- (A) Numa rubro-negra, todo caminho de um nó até as folhas (NIL) abaixo dele tem o mesmo número de nós pretos.
- (B) Uma rubro-negra com n nós internos tem altura no máximo 2 lg(n + 1).
- (C) Na AVL, uma inserção pode exigir uma rotação em cada ancestral do nó inserido, O(log n) rotações.
- (D) Numa árvore B de grau mínimo t, todo nó, exceto a raiz, tem entre t − 1 e 2t − 1 chaves.
- (E) Numa rubro-negra, um nó vermelho não tem filho vermelho.

<details><summary>Gabarito</summary>

**C.** Na inserção da AVL, a primeira rotação (simples ou dupla) devolve à
subárvore a altura que ela tinha antes, e nenhum ancestral acima precisa mais
de conserto: no máximo uma rotação por inserção. Quem pode girar em vários
níveis é a **remoção**. As outras são propriedades do Cormen. Veja 0101, o
0176 (remoção na AVL), o 0177 (rubro-negra) e o 0146 (árvore B).

</details>

## Para ler mais

- CORMEN, T. H.; LEISERSON, C. E.; RIVEST, R. L.; STEIN, C. *Algoritmos: teoria e prática*. 4. ed. Rio de Janeiro: GEN LTC, 2024. Caps. 6 (heapsort e filas de prioridade), 12 (árvores de busca binária), 13 (árvores rubro-negras) e 18 (árvores B); problema 13-3 (árvores AVL).
- ZIVIANI, N. *Projeto de algoritmos: com implementações em Pascal e C*. 3. ed. São Paulo: Cengage Learning, 2010. Caps. 5 (pesquisa em memória primária: árvores de pesquisa) e 6 (árvores B).
- FEOFILOFF, P. *Algoritmos em linguagem C*. Rio de Janeiro: Elsevier, 2009. Capítulos sobre heapsort, árvores binárias e árvores binárias de busca.
- CELES, W.; RANGEL, J. L. *Apostila de estruturas de dados*. Rio de Janeiro: PUC-Rio, 2002. Capítulos sobre árvores e árvores binárias de busca.
- CELES, W.; CERQUEIRA, R.; RANGEL, J. L. *Introdução a estruturas de dados: com técnicas de programação em C*. 2. ed. Rio de Janeiro: Elsevier, 2016.
- TENENBAUM, A. M.; LANGSAM, Y.; AUGENSTEIN, M. J. *Estruturas de dados usando C*. São Paulo: Makron Books, 1995. Caps. 5 (árvores), 6 (classificação: heapsort) e 7 (busca: árvores balanceadas).
- DEITEL, P.; DEITEL, H. *C: como programar*. 6. ed. São Paulo: Pearson, 2011. Cap. 12: estruturas de dados (árvores binárias de busca).
- LAUREANO, M. *Estrutura de dados com algoritmos e C*. Rio de Janeiro: Brasport, 2008. Capítulo sobre árvores.
- ROCHA, A. M. A.; BORGES, A. R. O. S. *Programação, estruturas de dados e algoritmos em C*. Aveiro: Universidade de Aveiro. Apostila.
- ADELSON-VELSKY, G. M.; LANDIS, E. M. An algorithm for the organization of information. *Soviet Mathematics Doklady*, v. 3, p. 1259-1263, 1962.
- KERNIGHAN, B. W.; RITCHIE, D. M. *C: a linguagem de programação padrão ANSI*. Rio de Janeiro: Campus, 1989. Seção 6.5: estruturas autorreferenciadas (a árvore de palavras).
- CPPREFERENCE. *qsort, qsort_s*. Disponível em: <https://en.cppreference.com/w/c/algorithm/qsort>.
