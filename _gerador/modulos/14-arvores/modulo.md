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
a cada inserção e a cada remoção. Os exercícios de "preveja a saída" existem
para isso.

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

Problemas para resolver no papel e, quando fizer sentido, num arquivo `.c` seu.
Eles misturam os assuntos do módulo.

**1. Quantos nós cabem?** Uma árvore binária tem altura 4. Qual é o menor e o
maior número de nós que ela pode ter? E uma BST com 1000 chaves: qual é a menor
altura possível? E a maior?

<details><summary>Resposta</summary>

Altura 4: no mínimo **5 nós** (uma fila indiana) e no máximo **31** (2⁵ - 1,
todos os níveis cheios). Em geral, entre h + 1 e 2^(h+1) - 1. Com 1000 chaves, a
menor altura é **9**: altura 8 comporta no máximo 511 nós, e altura 9 comporta
1023. A maior é **999** (inserção em ordem).

</details>

**2. Reconstrua a árvore.** Uma árvore binária tem pré-ordem `F B A D C E G I H`
e em ordem `A B C D E F G H I`. Desenhe a árvore e dê a pós-ordem.

<details><summary>Resposta</summary>

A pré-ordem diz que **F** é a raiz; na em ordem, tudo antes de F (`A B C D E`)
fica à esquerda e o resto (`G H I`) à direita. Repetindo nas partes: F (B (A, D
(C, E)), G (-, I (H, -))). Pós-ordem: **A C E D B H I G F**. Caminho: a
pré-ordem dá as raízes, a em ordem separa os lados. (Com pré-ordem e pós-ordem
sozinhas não dá para reconstruir sempre: um filho único pode ser esquerdo ou
direito.)

</details>

**3. Conte as BSTs.** Com as chaves 1, 2 e 3, quantas BSTs diferentes existem?
Das 6 ordens de inserção, quantas geram a árvore com raiz 2?

<details><summary>Resposta</summary>

São **5** BSTs. A de raiz 2 (a equilibrada) sai de **2** ordens: 2 1 3 e 2 3 1.
Cada uma das outras quatro sai de uma ordem só. Inserir em ordem aleatória
favorece as árvores mais equilibradas.

</details>

**4. A BST de nomes.** Insira numa BST, nesta ordem, os nomes Maria, Carlos,
Tiago, Ana, Fernanda, Rui e Zélia (comparação alfabética com `strcmp`). Qual é a
altura? Por quais nós passa a busca por "Fernanda"?

<details><summary>Resposta</summary>

Maria na raiz; Carlos (Ana, Fernanda) à esquerda; Tiago (Rui, Zélia) à direita.
Altura **2**. A busca por Fernanda passa por **Maria, Carlos, Fernanda**. Cuidado
com acentos: `strcmp` compara bytes, e em UTF-8 as letras acentuadas ficam
depois de todas as letras sem acento ("Élio" viria depois de "Zélia").

</details>

**5. Remoções em sequência.** Na BST 50 (30 (20, 40), 70 (60, 80)), remova 50,
depois 60, depois 70 (sempre pelo sucessor). Dê a pré-ordem depois de cada passo.

<details><summary>Resposta</summary>

Sem o 50: o sucessor 60 sobe, pré **60 30 20 40 70 80**. Sem o 60 (raiz de novo,
dois filhos): o sucessor 70 sobe e o 80 fica à direita dele, pré **70 30 20 40
80**. Sem o 70: o sucessor é o 80, que era folha, pré **80 30 20 40**. Repare
como remover sempre pelo sucessor deixa a árvore pendendo para a esquerda.

</details>

**6. AVL de 1 a 10.** Insira 1, 2, ..., 10 numa AVL vazia. Qual é a raiz no fim
e qual é a altura? Quantas rotações simples aconteceram?

<details><summary>Resposta</summary>

Raiz **4**, altura **3**, com **6** rotações simples (todas à esquerda: ao
inserir 3, 5, 6, 7, 9 e 10). Pré-ordem final: 4 2 1 3 8 6 5 7 9 10. Confira com o
`avl.h`: insira de 1 a 10 e chame `avl_pre_ordem` e `avl_rotacoes`.

</details>

**7. A AVL mais magra.** Qual é o **menor** número de nós de uma AVL de altura
h? Calcule para h = 0 a 5 e compare com a árvore cheia.

<details><summary>Resposta</summary>

N(0) = 1, N(1) = 2 e N(h) = N(h - 1) + N(h - 2) + 1: uma subárvore com altura
h - 1, a outra com h - 2, mais a raiz. Valores: **1, 2, 4, 7, 12, 20**. A árvore
cheia de altura 5 tem 63 nós. Como N(h) cresce como Fibonacci, a altura de uma
AVL fica abaixo de uns 1,44 · log₂ n.

</details>

**8. Heap ou BST?** Para cada caso, diga se usaria heap ou BST: (a) achar o
menor e o maior a qualquer momento; (b) atender sempre o pedido mais antigo de
uma lista que muda; (c) listar os produtos em ordem de preço; (d) saber se o
CPF 123 está cadastrado.

<details><summary>Resposta</summary>

(a) **BST**: menor e maior são as pontas (um heap de máximo não acha o mínimo
rápido); (b) **heap de mínimo** pela hora do pedido; (c) **BST** pelo preço
(em ordem dá a lista; um heap teria que ser esvaziado); (d) **BST** (o heap não
busca uma chave qualquer; no módulo 15, a tabela hash ganha das duas).

</details>

**9. Heap de 1 a 7.** Insira 1, 2, 3, 4, 5, 6 e 7, nesta ordem, num heap de
máximo vazio (com `heap_insere`). Qual é o vetor? Remova o máximo duas vezes e
dê o vetor de novo.

<details><summary>Resposta</summary>

Depois das inserções: **[7 4 6 1 3 2 5]**. Sem o 7: o 5 vai para a raiz e desce
pelo 6, **[6 4 5 1 3 2]**. Sem o 6: o 2 vai para a raiz e desce pelo 5,
**[5 4 2 1 3]**.

</details>

**10. Os 10 maiores de um milhão.** Você recebe um milhão de números, um de cada
vez, e no fim precisa dos 10 maiores. Compare três jeitos: ordenar tudo, usar
um heap de máximo com todos e usar um heap de mínimo com 10. Quanto custa cada
um e quanta memória usa?

<details><summary>Resposta</summary>

Ordenar: O(n log n), cerca de 20 milhões de comparações, e guarda tudo. Heap de
máximo com todos: montar O(n) e tirar 10 vezes O(10 log n), mas também guarda
tudo. **Heap de mínimo com 10**: cada número compara com a raiz e, se for maior,
entra no lugar dela, O(n log 10), uns 3 milhões de passos no pior caso, e
guarda só 10 números. É o exercício E611 em escala.

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
