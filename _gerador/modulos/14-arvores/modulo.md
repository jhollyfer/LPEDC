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
comum, sem ponteiro nenhum, e de quebra ainda ordena (o **heapsort**).

Quase tudo aqui é recursivo. Uma árvore é um nó com árvores menores
penduradas, então a função que resolve a árvore resolve cada subárvore e junta
as respostas. Se a recursão do módulo 04 ficou meio nebulosa, este é o momento
de ela fazer sentido.

## O que você vai aprender

- o vocabulário das árvores: **raiz**, **filho**, **folha**, **altura** e **profundidade**
- a **árvore binária** em C e os quatro **percursos**: pré-ordem, em ordem, pós-ordem e por nível
- a **árvore binária de busca** (BST): busca, inserção e os três casos da **remoção**
- por que a BST pode virar uma lista, e como a **AVL** se equilibra com **rotações**
- o **heap** num vetor e a **fila de prioridade**
- o **heapsort**: ordenar em O(n log n) sem memória extra
- montar um programa que junta BST e heap, cada um no que faz melhor

## Como estudar cada assunto

1. Leia o texto e olhe o **diagrama da ideia**: é o exemplo desenhado, com as
   mesmas chaves do código.
2. Leia o código. A partir do 0098, cada assunto tem um **TAD** na pasta
   (`arvore.h`, `bst.h`, `avl.h`, `heap.h`, `cadastro.h`) e o exemplo só usa a
   interface. Abra o `.c` do TAD também: é lá que mora o algoritmo.
3. Siga o **fluxograma** com o dedo: é o caminho que o exemplo faz.
4. Rode os exemplos. Mude a ordem das inserções, remova outra chave, rode de novo.
5. Faça os exercícios. ★☆☆ é aquecimento, ★★☆ pede raciocínio, ★★★ é desafio.
   As dicas vêm logo abaixo do enunciado: tente antes de ler.

Em árvore, **papel e lápis** são obrigatórios. Desenhe a árvore antes de rodar,
a cada inserção e a cada remoção, e só depois rode o programa para conferir o
desenho com a saída.

## As cores e as formas

Caixa azul é dado entrando ou saindo, roxa é o programa fazendo alguma coisa,
amarela é pergunta. Verde é o caminho que o exemplo segue; cinza, o que ele não
usa. Nos desenhos de árvore, as arestas verdes marcam o caminho de uma busca, e
o nó vermelho é o que vai sair ou o que está desequilibrado.

<p align="center"><img src="../legenda.svg" alt="Legenda: formas e cores do fluxograma" width="916"></p>

## Antes de começar

Você precisa estar à vontade com **recursão** (assuntos 0032 e 0033),
**ponteiros para struct** e `->` (0062), `malloc` e `free` (0054) e a ideia de
**TAD** com `.h` e `.c` (0074). A fila do assunto 0085 aparece no percurso por
nível, e o assunto 0090 (busca binária) é o primo da BST.

O `rodar` compila junto os `.c` de apoio da pasta (como `bst.c`). Por isso os
comandos dos exemplos e exercícios são os de sempre:

```bash
~/LPEDC/rodar 14-arvores/0099-bst-busca-insercao/A197.c
```

Uma convenção vale para o módulo todo: **altura conta arestas**. Uma folha tem
altura 0 e a árvore vazia tem altura -1. Alguns livros contam nós (folha com
altura 1). Quando for consultar outro material, confira qual é a convenção.

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
era folha. Repare como remover sempre pelo sucessor deixa a árvore pendendo
para a esquerda. A pré-ordem é `printf(" %d", r->chave)` antes das duas
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

## Para ler mais

- FEOFILOFF, P. *Algoritmos em linguagem C*. Rio de Janeiro: Elsevier, 2009. Capítulos sobre heapsort, árvores binárias e árvores binárias de busca.
- CELES, W.; RANGEL, J. L. *Apostila de estruturas de dados*. Rio de Janeiro: PUC-Rio, 2002. Capítulos sobre árvores e árvores binárias de busca.
- CELES, W.; CERQUEIRA, R.; RANGEL, J. L. *Introdução a estruturas de dados: com técnicas de programação em C*. Rio de Janeiro: Elsevier, 2004.
- TENENBAUM, A. M.; LANGSAM, Y.; AUGENSTEIN, M. J. *Estruturas de dados usando C*. São Paulo: Makron Books, 1995. Caps. 5 (árvores), 6 (classificação: heapsort) e 7 (busca: árvores balanceadas).
- DEITEL, P.; DEITEL, H. *C: como programar*. 6. ed. São Paulo: Pearson, 2011. Cap. 12: estruturas de dados (árvores binárias de busca).
- LAUREANO, M. *Estrutura de dados com algoritmos e C*. Rio de Janeiro: Brasport, 2008. Capítulo sobre árvores.
- ROCHA, A. M. A.; BORGES, A. R. O. S. *Programação, estruturas de dados e algoritmos em C*. Aveiro: Universidade de Aveiro. Apostila.
- CORMEN, T. H. et al. *Algoritmos: teoria e prática*. 3. ed. Rio de Janeiro: Elsevier, 2012. Caps. 6 (heapsort) e 12 (árvores de busca binária).
- ADELSON-VELSKY, G. M.; LANDIS, E. M. An algorithm for the organization of information. *Soviet Mathematics Doklady*, v. 3, p. 1259-1263, 1962.
- KERNIGHAN, B. W.; RITCHIE, D. M. *C: a linguagem de programação padrão ANSI*. Rio de Janeiro: Campus, 1989. Seção 6.5: estruturas autorreferenciadas (a árvore de palavras).
- CPPREFERENCE. *qsort, qsort_s*. Disponível em: <https://en.cppreference.com/w/c/algorithm/qsort>.
