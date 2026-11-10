# Módulo 14 · Árvores

Pastas, organograma e sumário de livro são **hierarquias**, e a estrutura para
elas é a **árvore**. Ela também resolve um problema do módulo 13: a busca
binária exige vetor ordenado, e inserir no meio dele custa caro. A **árvore
binária de busca** (BST) busca e insere descendo um caminho; a **AVL** a
endireita com rotações; o **heap** entrega o maior elemento num vetor, sem
ponteiros, e dá o **heapsort**.

Quase tudo aqui é recursivo: a função resolve cada subárvore e junta as
respostas.

**Progressão.** O módulo usa recursão (assuntos 0032 e 0033), ponteiros para
struct (0062), `malloc` e `free` (0054), TAD (0074), a fila do 0085 e a busca
binária do 0090. O heapsort completa as ordenações do módulo 13. O módulo 15
troca a hierarquia por uma tabela de espalhamento (hash), que busca em O(1) na
média.

## O que você vai aprender

- vocabulário: **raiz**, **filho**, **folha**, **altura** e **profundidade**
- **árvore binária** em C e os quatro **percursos**: pré-ordem, em ordem,
  pós-ordem e por nível
- **BST**: busca, inserção e os três casos da **remoção**
- por que a BST pode virar lista e como a **AVL** se equilibra com
  **rotações**
- **heap** num vetor e **fila de prioridade**
- **heapsort**: O(n log n) sem memória extra
- um programa que junta BST e heap

## Antes de começar

A partir do 0098, cada assunto tem um TAD na pasta (`arvore.h`, `bst.h`,
`avl.h`, `heap.h`, `cadastro.h`) e o exemplo só usa a interface; abra também o
`.c`, que tem o algoritmo. Nos desenhos, as arestas verdes marcam o caminho de
uma busca e o nó vermelho é o que vai sair ou está desequilibrado. Desenhe a
árvore no papel e use a saída só para conferir.

O comando compila junto o `.c` de apoio da pasta (como `bst.c`):

```bash
gcc ~/LPEDC/14-arvores/0099-bst-busca-insercao/A197.c ~/LPEDC/14-arvores/0099-bst-busca-insercao/bst.c -o ~/LPEDC/14-arvores/0099-bst-busca-insercao/A197 && ~/LPEDC/14-arvores/0099-bst-busca-insercao/A197
```

**Altura conta arestas** em todo o módulo: a folha tem altura 0 e a árvore
vazia, -1. Alguns livros contam nós; confira a convenção.

{{indice}}

---

{{assuntos}}

---

## Desafios do módulo

Problemas para fechar o módulo, misturando os assuntos. Escreva em C e compile
com o gcc e as flags de estudo. Quando o desafio citar `avl.h` ou `heap.h`,
copie o `.h` e o `.c` do assunto para a pasta do seu arquivo.

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

## Questões de provas do PPGI

Questões reais das provas de conhecimento do PPGI/UFAM, na íntegra e com o gabarito oficial. Resolva no papel, em 3 minutos por questão, e só depois abra o gabarito.

**Edital 032/2016 · Questão 12**

Marque a resposta correta. Ao inserirmos as chaves 1, 2 e 3, 4, 5, 6 em uma árvore AVL, sua altura (medida como a quantidade máxima de nós em um caminho entre a raiz e uma folha da árvore, incluindo a raiz e a folha na conta) será:

- a) 2
- b) 3
- c) 4
- d) 5
- e) 6

<details><summary>Gabarito</summary>

**B.** Inserir 1..6 dá raiz 4, esquerda 2(1,3), direita 5(-,6): 3 nós no maior caminho. Assunto 0101.

</details>

**Edital 032/2016 · Questão 13**

Sobre uma árvore binária de pesquisa sem balanceamento, pode-se afirmar que:

I) São estruturas de dados que, quando degeneradas, têm custo de inserção proporcional ao número de chaves inseridas\
II) Não servem para armazenar dados quando deseja-se ter acesso aos mesmos de maneira ordenada\
III) Têm como principal custo extra de memória os dois apontadores que indicam os nós à esquerda e à direita de cada nó criado\

Sobre as afirmações, sabe-se que:

- a) Apenas I é verdadeira
- b) Apenas I e II são verdadeiras
- c) Todas as afirmações são verdadeiras
- d) Apenas II e III são verdadeiras
- e) Nenhuma das alternativas anteriores está correta

<details><summary>Gabarito</summary>

**E.** I e III são verdadeiras, II é falsa, e "I e III" não está entre as letras. Assunto 0099.

</details>

**Edital 032/2016 · Questão 14**

Sobre árvores binárias de pesquisa sem balanceamento, pode-se afirmar que:

I) É uma estrutura de dados inerentemente recursiva, sendo impossível implementar uma busca em uma árvore de maneira não recursiva\
II) É uma estrutura de dados inerentemente recursiva, sendo impossível implementar uma inserção em uma árvore de maneira não recursiva\
III) Em muitos casos práticos, pode ter custo de busca com número de operações proporcional a log n, onde n é o número de elementos inseridos na árvore\

Sobre as afirmações, sabe-se que:

- a) Apenas I e II estão corretas
- b) Apenas III está correta
- c) Apenas I e III estão corretas
- d) Apenas II e III estão corretas
- e) Nenhuma das alternativas anteriores

<details><summary>Gabarito</summary>

**B.** I e II são falsas (busca e inserção têm versão iterativa); III é verdadeira (árvore razoavelmente balanceada). Assunto 0099.

</details>

**Edital 032/2016 · Questão 15**

Marque a resposta correta. Ao inserirmos as chaves 1, 2 e 3, 4, 5, 6 em uma árvore AVL, a diferença de altura entre as sub-árvores à esquerda e à direita do nó raiz será:

- a) 0
- b) 1
- c) 2
- d) 3
- e) 4

<details><summary>Gabarito</summary>

**A.** Mesma árvore da Q12: subárvore esquerda 2(1,3) e direita 5(-,6) têm altura 2, diferença 0. Assunto 0101.

</details>

**Edital 053/2016 · Questão 03**

As seguintes afirmações sobre árvores estão corretas, com EXCEÇÃO de:

- a) É um grafo conexo que admite ciclos.
- b) É um grafo conexo e há exatamente um caminho entre dois vértices quaisquer.
- c) Uma árvore com n vértices possui n-1 arestas.
- d) Toda árvore é um grafo, mas nem todo grafo é uma árvore.
- e) Uma união disjunta de árvores forma uma floresta

<details><summary>Gabarito</summary>

**A.** Árvore é grafo conexo e acíclico; "admite ciclos" é a exceção. Assunto 0097.

</details>

**Edital 053/2016 · Questão 07**

Considere a estrutura de dados Árvore Binária de Busca (ABB). Se inserirmos numa ABB inicialmente vazia os nós: 60, 10, 20, 80, 15, 75, 12 e 77, nessa ordem. Dado que a raiz encontra-se no nível 1, a altura da árvore e o nível do nó 15, respectivamente, serão:

- a) 5 e 4
- b) 5 e 5
- c) 6 e 5
- d) 6 e 4
- e) 7 e 3

<details><summary>Gabarito</summary>

**A.** Com raiz no nível 1: altura 5 (caminho 60-10-20-15-12), nível do 15 é 4; conferido em C. Assunto 0099.

</details>

**Edital 053/2016 · Questão 11**

As sequências que representam os percursos da árvore da figura em pós-ordem e in-ordem são, respectivamente:

![Questão 11 - árvore](_fontes/provas-figuras/2016-053/q11-arvore.png)

- a) P Q S T R e P Q S T R
- b) S T Q P R e S T Q R P
- c) S T Q R P e S Q T P R
- d) R P Q T S e S T Q R P
- e) P T Q R S e P Q S T R

<details><summary>Gabarito</summary>

**C.** Assunto 0098.

</details>

**Edital 053/2016 · Questão 13**

Em uma árvore AVL, todos os nós têm grau

- a) 0, 1 ou 2.
- b) divisível por 2.
- c) 2
- d) 1 e 2
- e) maior ou igual a 2.

<details><summary>Gabarito</summary>

**A.** Nó de AVL é binário: grau 0, 1 ou 2. Assunto 0101.

</details>

**Edital 053/2016 · Questão 14**

A estrutura de dados conhecida como Árvore Binária de Busca (ABB) encontra diversas aplicações em soluções práticas. Sobre esta estrutura é CORRETO afirmar:

- a) Uma ABB é um conjunto finito de nós que possui um nó especial, chamado raiz, do qual partem os nós de duas árvores binárias distintas: a da esquerda e a da direita.
- b) Quando os elementos a serem inseridos na ABB estão em ordem crescente, resulta em uma ABB com altura mínima.
- c) Para se utilizar uma ABB como método de ordenação, basta fazer o caminhamento ou percurso "em-ordem" e obter todos os elementos ordenados.
- d) Uma característica que confere à ABB grande agilidade na pesquisa e recuperação de elementos é que seus nós são sempre rearranjados de forma que a árvore resultante é sempre perfeitamente balanceada.
- e) ABB são um caso especial de listas encadeadas em que nenhum nó aponta para mais de 2 sucessores.

<details><summary>Gabarito</summary>

**A.** Assunto 0099.

</details>

**Edital 053/2016 · Questão 16**

Uma árvore AVL é uma árvore binária de busca com balanceamento automático que respeita algumas propriedades fundamentais. Como todas as árvores, ela tem uma propriedade chamada altura. Sabendo que a altura de uma folha é igual a um e que a altura de um nó pai é igual ao máximo das alturas de seus filhos mais um, qual estrutura NÃO pode representar uma árvore AVL?

- a) Uma árvore com três nós e altura igual a três
- b) Uma árvore com seis nós e altura igual a três
- c) Uma árvore com três nós e altura igual a dois
- d) Uma árvore vazia
- e) Uma árvore com dois nós

<details><summary>Gabarito</summary>

**A.** Três nós em altura 3 é cadeia, fator de balanceamento 2: não é AVL. Assunto 0101.

</details>

**Edital 053/2016 · Questão 18**

Considere as definições a seguir.

I) O nível do nó raiz de uma árvore é 1.\
II) O nível de qualquer nó subsequente é igual ao nível do seu nó pai mais 1.\
III) A profundidade de uma árvore é igual ao maior nível encontrado dentre todos os seus nós\

Partindo-se das premissas acima, a menor e a maior quantidade de nós, respectivamente, que poderiam existir em uma árvore binária de profundidade 4 são:

- a) 4 e 15
- b) 3 e 15
- c) 3 e 16
- d) 4 e 16
- e) 5 e 14

<details><summary>Gabarito</summary>

**A.** Mínimo é 1 nó por nível (4), máximo é 2^4-1 = 15. Assunto 0097.

</details>

**Edital 053/2016 · Questão 19**

Uma árvore binária completa tem no 5º nível uma quantidade de nós igual a

- a) 16
- b) 15
- c) 31
- d) 64
- e) 32

<details><summary>Gabarito</summary>

**A.** Nível 5 tem 2^(5-1) = 16 nós. Assunto 0097.

</details>

**Edital 053/2016 · Questão 20**

Considere uma árvore binária de busca cujos nós armazenam números inteiros variando de 1 a 100, na qual se quer buscar o número 54. Qual das seguintes sequências representa uma sequência de busca válida dentro desta árvore?

- a) 5, 18, 34, 60, 40, 52, 54
- b) 25, 27, 28, 26, 60, 50, 58, 54
- c) 37, 70, 32, <não encontrou>
- d) 40, 70, 43, 44, 73, 57, 54
- e) Nenhuma das alternativas anteriores

<details><summary>Gabarito</summary>

**A.** Só a sequência A respeita os limites da ABB em todos os passos (B, C e D violam). Assunto 0099.

</details>

**Edital 024/2017 · Questão 01**

Avaliando as seguintes sentenças a respeito de estrutura de dados:

I. A diferença entre árvore binária de busca e árvores AVL é o fato de que a segunda pode se reconfigurar dinamicamente, com o intuito de manter um bom nível de balanceamento.\
II. Uma pilha garante que o último elemento inserido seja localizado no seu topo. Porém, do ponto de vista conceitual, qualquer elemento da pilha pode ser removido, ainda que não esteja no seu topo.\
III. Do ponto de vista conceitual, não há diferença alguma entre uma estrutura de array e uma lista encadeada.\
IV. Tabelas hash são estruturas de dados indicadas para armazenar grande volume de dados. Apesar dessas estruturas permitirem acesso indexado, mais de um elemento pode ter o mesmo índice. Elementos com o mesmo índice podem ser armazenados em uma mesma lista encadeada.\

É CORRETO afirmar que:

- a) apenas I e IV são verdadeiras.
- b) apenas I é verdadeira.
- c) apenas III e IV são verdadeiras.
- d) apenas II e III são verdadeiras.
- e) apenas I, II e IV são verdadeiras.

<details><summary>Gabarito</summary>

**A.** I e IV verdadeiras; II falsa (pilha só remove do topo), III falsa (array é contíguo, lista não) Assunto 0101.

</details>

**Edital 024/2017 · Questão 02**

Marque a alternativa CORRETA.
Qual dos algoritmos abaixo apresenta o menor custo (em termos de número comparações entre elementos) ao considerar-se, para cada algoritmo, a pior disposição possível para os elementos do vetor a ser ordenado. Considere que o vetor a ser ordenado é muito grande, acima de 1 milhão de elementos.

- a) Heapsort
- b) Quicksort
- c) Inserção
- d) Seleção
- e) Nenhuma das anteriores porque todos apresentam custo igual

<details><summary>Gabarito</summary>

**A.** pior caso: heapsort O(n log n); quicksort, inserção e seleção O(n²) Assunto 0103.

</details>

**Edital 024/2017 · Questão 08**

Considere as seguintes árvores onde são apresentados apenas os valores das chaves em cada nó, sem mostrar o valor de outros campos eventualmente existentes. Considerando em todos os casos que as árvores não estão em processo de rotação por inserção de chaves, estando portanto em seu estado final após a inserção do conjunto de chaves mostrado.

![Questão 08 - árvores (I) a (IV)](_fontes/provas-figuras/2017-024/q08-arvores.png)

É CORRETO afirmar que:

- a) Apenas a árvore do quadro I poderia ser uma árvore AVL
- b) Todas as opções apresentadas nos quadros de I a IV podem ser exemplos de árvores AVL
- c) Nenhuma das 4 opções apresentadas podem ser exemplos de árvores AVL
- d) Apenas as opções I e III podem ser exemplos de árvores AVL
- e) Nenhuma das alternativas anteriores (de A até D) está correta

<details><summary>Gabarito</summary>

**E.** Assunto 0101.

</details>

**Edital 024/2017 · Questão 10**

Considere as seguintes árvores onde são apresentados apenas os valores das chaves em cada nó, sem mostrar o valor de outros campos eventualmente existentes. Considerando em todos os casos que as árvores não estão em processo de rotação por inserção de chaves, estando portanto em seu estado final após a inserção do conjunto de chaves mostrado.

![Questão 10 - árvores (I) a (IV)](_fontes/provas-figuras/2017-024/q10-arvores.png)

É CORRETO afirmar que:

- a) Apenas a árvore do quadro I poderia ser uma árvore binária de pesquisa sem balanceamento
- b) Todas as 4 opções podem ser exemplos de árvores binárias de pesquisa sem balanceamento
- c) Nenhuma das 4 opções pode ser uma árvore binária de pesquisa sem balanceamento
- d) Apenas as opções II e III podem de árvores binárias de pesquisa sem balanceamento
- e) Nenhuma das alternativas anteriores (de A até D) está correta

<details><summary>Gabarito</summary>

**E.** Assunto 0099.

</details>

**Edital 024/2017 · Questão 11**

Sabendo que um arvore binária com 5 nós tem como resultados dos seus percursos pós-ordem e in-ordem, respectivamente S T Q R P e S Q T P R.
É CORRETO afirmar:

- a) O nó raiz tem o valor P
- b) Q é um nó folha
- c) S é um nó interno
- d) T é filho de S
- e) Todas as alternativas estão corretas

<details><summary>Gabarito</summary>

**A.** pós-ordem dá raiz P; Q tem filhos S e T; S e T são folhas Assunto 0098.

</details>

**Edital 024/2017 · Questão 16**

Considere que o vetor a seguir é uma heap mínima (assuma índice do array iniciando em zero)

`4 5 7 10 13 11 15 22`

Marque a alternativa que contem a afirmativa CORRETA:

- a) Essa heap possui todos os nós folhas na mesma altura
- b) Ao alterar o valor 22 por 6, 2 trocas são necessárias para corrigir a heap
- c) O valor no índice 7 precisa ser necessariamente menor que o do índice 4
- d) O valor no índice 6 precisa ser obrigatoriamente maior que o do índice 1
- e) Ao alterar o valor 13 por 8, nada precisa ser feito para corrigir a heap

<details><summary>Gabarito</summary>

**E.** índice 4 (13) é folha com pai 5; trocar por 8 mantém a heap; em b só há 1 troca (6 sobe de 10, para abaixo de 5) Assunto 0102.

</details>

**Edital 055/2017 · Questão 04**

Observe a árvore binária de pesquisa sem balanceamento:

![Questão 04 - árvore](_fontes/provas-figuras/2017-055/q04-arvore.png)

Considere as afirmativas a seguir.

I. Os nós 6 e 8 são irmãos.\
II. O nó 4 é uma das raízes da árvore.\
III. O nó com valor 3, ao ser inserido, ocuparia a posição iv.\
IV. O nó com valor 1, ao ser inserido, ocuparia a posição i.\

Marque a alternativa CORRETA:

- A) Apenas a afirmativa III está correta.
- B) Apenas as afirmativas I e IV estão corretas.
- C) Apenas as afirmativas II e III estão corretas.
- D) Apenas as afirmativas I, II e IV estão corretas.
- E) Todas as afirmativas estão corretas.

<details><summary>Gabarito</summary>

**B.** Assunto 0099.

</details>

**Edital 055/2017 · Questão 07**

Marque a alternativa CORRETA.
Suponha que T seja uma árvore binária de pesquisa sem balanceamento inicialmente vazia, e considere a inserção dos elementos 30, 50, 60, 20, 40, 10 e 25 em T, exatamente nessa ordem. Qual das sequências abaixo corresponde a um percurso de T em pré-ordem?

- A) 30 50 60 40 20 25 10
- B) 10 25 20 40 60 50 30
- C) 10 20 25 30 40 50 60
- D) 30 20 10 25 50 40 60
- E) 60 50 40 30 25 20 10

<details><summary>Gabarito</summary>

**D.** raiz 30, esquerda 20 (10, 25), direita 50 (40, 60); pré-ordem 30 20 10 25 50 40 60 Assunto 0098.

</details>

**Edital 055/2017 · Questão 16**

Considere as seguintes árvores onde são apresentados apenas os valores das chaves em cada nó, sem mostrar o valor de outros campos eventualmente existentes. Além disso, note que em todos os casos, as árvores não estão em processo de rotação por inserção de chaves, estando portanto em seu estado final após a inserção do conjunto de chaves mostrado.

![Questão 16 - árvores (I) a (IV)](_fontes/provas-figuras/2017-055/q16-arvores.png)

É CORRETO afirmar que:

- A) Apenas a árvore do quadro I poderia ser uma árvore AVL.
- B) Apenas a árvore III não poderia ser uma árvore AVL.
- C) Nenhuma das 4 opções apresentadas poderiam ser exemplos de árvores AVL.
- D) Apenas as opções I e II podem ser exemplos de árvores AVL.
- E) Nenhuma das alternativas anteriores (de A, B, C ou D) está correta.

<details><summary>Gabarito</summary>

**B.** Assunto 0101.

</details>

**Edital 055/2017 · Questão 20**

Ao inserirmos as chaves 2, 4, 6, 8, 10 e 12, nessa ordem, em uma árvore AVL que estava originalmente vazia, a diferença de altura entre a sub-árvores que está à direita da raiz e a sub-árvore que está à esquerda da raiz será:

- A) 0.
- B) 2.
- C) 4.
- D) 6.
- E) 8.

<details><summary>Gabarito</summary>

**A.** rodando AVL (programa em C): raiz 8, esquerda 4 (2, 6), direita 10 (12); diferença 0 Assunto 0101.

</details>

**Edital 023/2018 · Questão 03**

Analise as duas afirmativas a seguir, relacionadas a árvores de busca:

I. Uma árvore AVL é uma árvore binária de busca autobalanceada que respeita algumas propriedades fundamentais.\
II. Como todas as árvores, ela tem uma propriedade chamada altura, que é igual ao valor da altura de sua raiz.\

Sabendo que a altura de uma folha é igual a um (01) e que a altura de um nó pai é igual ao máximo das alturas de seus filhos mais um, qual estrutura NÃO pode representar uma árvore AVL?

- a) Uma árvore vazia
- b) Uma árvore com dois nós
- c) Uma árvore com três nós e altura igual a dois
- d) Uma árvore com três nós e altura igual a três
- e) Uma árvore com seis nós e altura igual a três

<details><summary>Gabarito</summary>

**D.** Com folha de altura 1, três nós em altura três é uma cadeia, com fator de balanceamento 2 na raiz. Assunto 0101.

</details>

**Edital 023/2018 · Questão 04**

Um heap (fila de prioridade) é uma estrutura de dados muito importante, que tem duas utilidades principais: organizar acesso a um recurso com base na prioridade dos requerentes (processos, impressões, etc.) ou servir como base a um algoritmo de ordenação muito eficiente denominado heapsort. Para poder servir a esses propósitos, um heap possui uma série de propriedades especiais que têm que ser mantidas por todas as operações nelas realizadas. Levando em consideração estas propriedades, analise as afirmativas abaixo.

![Questão 04 - heaps (afirmativas I, II e III)](_fontes/provas-figuras/2018-023/q04-heaps.png)

I. `50 40 49 39 45 46` representa um heap sintaticamente correto\
II. Dado o heap `21 14 10 9 5`, a inserção do elemento 12 se dá através dos passos `21 14 10 9 5 12` ⇒ `21 14 12 9 5 10`\
III. Dado o heap `21 14 10 9 5`, a retirada do elemento do topo se dá através dos passos `5 14 10 9` ⇒ `14 5 12 9` ⇒ `14 9 12 5`\

É CORRETO APENAS o que se afirma em:

- a) I.
- b) II.
- c) III.
- d) I e II.
- e) II e III.

<details><summary>Gabarito</summary>

**B.** Assunto 0102.

</details>

**Edital 023/2018 · Questão 06**

Uma lista ordenada de N números é inserida em uma pilha e depois retirada, sendo que, a cada POP, o elemento retirado é inserido em uma árvore de busca binária. Após a completa inserção de todos os elementos nesta árvore, são feitas buscas de números na mesma. O tempo médio de busca de um número nesta árvore é

- a) O(1)
- b) O(log N)
- c) O(N)
- d) O(Nlog N)
- e) O(N2)

<details><summary>Gabarito</summary>

**C.** Lista ordenada pela pilha sai ordenada ao contrário e a ABB degenera em lista: busca O(N). Assunto 0099.

</details>

**Edital 023/2018 · Questão 07**

Assinale cada afirmativa abaixo como verdadeira (V) ou falsa (F). Em seguida, marque a opção que corresponde à sequência CORRETA.

( ) Uma árvore não-vazia é balanceada AVL se, pelo menos, uma de suas árvores, esquerda ou direita, for balanceada AVL;
( ) As árvores cheias são árvores balanceadas AVL;
( ) Uma boa condição de balanceamento AVL deve assegurar que a altura de uma árvore com n nós é da ordem de O(log n);
( ) Uma árvore AVL é uma árvore balanceada pela altura;
( ) Ao inserir ou remover um item em uma árvore AVL, o custo adicional para balancear esta árvore é da ordem de O(n/2).

- a) V - V - F - V - V
- b) F - V - V - V - F
- c) V - F - F - V - F
- d) F - V - V - F - V
- e) F - F - V - V - F

<details><summary>Gabarito</summary>

**B.** F-V-V-V-F: AVL exige as duas subárvores AVL, cheias são AVL e o custo de balancear é O(log n), não O(n/2). Assunto 0101.

</details>

**Edital 023/2018 · Questão 08**

Considere uma estrutura do tipo árvore binária que começa vazia. Nela são introduzidos os números 2, 10, 5, 7, 1, 0 e 8, exatamente nessa ordem. Se essa árvore for lida em pós-ordem, que sequência de números será impressa?

- a) 2, 1, 0, 8, 7, 5, 10
- b) 2, 1, 0, 10, 5, 7, 8
- c) 0, 1, 8, 7, 5, 10, 2
- d) 0, 1, 2, 8, 7, 5, 10
- e) 0, 1, 2, 10, 5, 7, 8

<details><summary>Gabarito</summary>

**C.** Rodado em C: pós-ordem `0 1 8 7 5 10 2`. Assunto 0098.

</details>

**Edital 023/2018 · Questão 10**

Considere a seguinte árvore de pesquisa binária:

![Questão 10 - árvore de pesquisa binária](_fontes/provas-figuras/2018-023/q10-arvore.png)

Ao executarmos o procedimento de remoção da raiz, na nova árvore binária de busca, teremos como novo nó raiz:

- a) 11
- b) 2
- c) 17
- d) 18
- e) Nenhuma das anteriores

<details><summary>Gabarito</summary>

**D.** Assunto 0100.

</details>

**Edital 023/2018 · Questão 15**

As árvores são estruturas de dados poderosas e se subdividem em vários tipos, cada um dos quais com suas características próprias. Relacione os tipos de árvores, apresentados na coluna da esquerda, com as suas respectivas características, indicadas na coluna da direita:

| Tipo de árvore | Característica |
|---|---|
| I – Heap | W – Pode degenerar se os elementos forem inseridos de forma ordenada. |
| II – Rubro-Negra | X – É balanceada. |
| III – Avore AVL | Y – Têm altura sempre proporcional/próxima a O(log2 n), onde n é o número de nós que contém. |
| IV – Árvores binária de busca | Z – São sempre completas. |

Estão CORRETAS as associações:

- a) I–X, IV–Z, II–Y
- b) I–Z, IV–X, III–W
- c) I–Z, IV–X, III–Y
- d) I–Y, IV–W, III–X
- e) I–X, IV–W, II–Y

<details><summary>Gabarito</summary>

**D.** Heap com altura log n, ABB que degenera, AVL balanceada. Ver observação. Assunto 0101.

</details>

**Edital 023/2018 · Questão 16**

Sobre o algoritmo de ordenação heapsort, marque a alternativa CORRETA:

- a) Utiliza ordenação por árvore de decisão, ao invés de ordenação por comparação
- b) A estrutura de dados que utiliza, chamada heap, pode ser interpretada como uma árvore binária
- c) Seu desempenho de pior caso é pior do que o do algoritmo quicksort
- d) Todas as alternativas estão corretas
- e) Nenhuma das alternativas está correta

<details><summary>Gabarito</summary>

**B.** O heap é uma árvore binária em vetor; o pior caso do heapsort é O(n log n), melhor que o do quicksort. Assunto 0103.

</details>

**Edital 061/2018 · Questão 05**

A árvore binária de busca, formada pela inserção dos números 100, 80, 25, 72, 23, 42 e 5, nesta ordem, terá como nós folha os números __I__ e __II__, e como pai do nó 72 o número __III__. As lacunas I, II e III são preenchidas CORRETAMENTE e, respectivamente, por:

- a) 100 – 80 – 100
- b) 5 – 42 – 25
- c) 23 – 25 – 72
- d) 25 – 72 – 100
- e) 72 – 5 – 23

<details><summary>Gabarito</summary>

**B.** Folhas 5 e 42, pai do 72 é o 25. Assunto 0099.

</details>

**Edital 061/2018 · Questão 13**

Suponha que uma Árvore Binária de Busca possui números entre 1 e 1000 e que se quer procurar pelo número 363. Qual sequência abaixo NÃO poderia ser a sequência de nós examinados?

- a) 2, 252, 401, 398, 330, 344, 397, 363.
- b) 924, 220, 911, 244, 898, 258, 362, 363.
- c) 925, 202, 911, 240, 912, 245, 363.
- d) 2, 399, 387, 219, 266, 382, 381, 278, 363.
- e) 935, 278, 347, 621, 350, 392, 358, 363.

<details><summary>Gabarito</summary>

**C.** Só a C é impossível: após 911 vem 240 (à direita de 202, esquerda de 911), e o 912 sairia do intervalo (240, 911). A nova E é válida (350, 392, 358 cabem). Assunto 0099.

</details>

**Edital 061/2018 · Questão 15**

Se em uma árvore binária de pesquisa a diferença de altura entre a subárvore à esquerda e a subarvore à direita de um dos nós for maior que 1, pode-se concluir que:

- a) A árvore é uma árvore AVL.
- b) Trata-se com certeza de uma árvore binária sem balanceamento.
- c) Trata-se com certeza de uma árvore vermelho e preto.
- d) Tal árvore não pode existir por não se tratar de uma árvore binária de pesquisa.
- e) Nenhuma das alternativas anteriores está correta.

<details><summary>Gabarito</summary>

**E.** A ABB com diferença maior que 1 não é AVL, mas pode ser rubro-negra: nada se conclui com certeza. Assunto 0101.

</details>

**Edital 061/2018 · Questão 19**

Quanto ao algoritmo e estrutura de dados no caso de árvore AVL, analise as afirmativas abaixo como verdadeiras (V) ou falsas (F) e assinale a alternativa que apresenta a sequência CORRETA de cima para baixo:

( ) Uma árvore AVL é dita balanceada quando, para cada nó da árvore, a diferença entre as alturas das suas sub-árvores (direita e esquerda) não é maior do que um.
( ) Caso haja diferença de altura maior que 1 ente as sub-árvores à direita e à esquerda de qualquer nó, é necessário que se realizem rotações com o objetivo de reduzir tal diferença.
( ) A operação de rotação realizada em um ponto da árvore, após a inserção, pode resultar em uma árvore ainda desbalanceada, podendo ser necessária a realização de novas rotações que, na pior das hipóteses, podem ser propagadas até a raiz.

- a) F-V-V
- b) F-F-V
- c) V-F-F
- d) V-V-F
- e) V-V-V

<details><summary>Gabarito</summary>

**D.** V-V-F: após inserção uma rotação (simples ou dupla) basta; a propagação até a raiz é da remoção. Assunto 0101.

</details>

**Edital 033/2019 · Questão 02**

A parte essencial do Heap Sort é a construção do heap máximo. Considerando a árvore mostrada abaixo, o nó 24 viola a propriedade do heap máximo. Uma vez que o procedimento de heap é aplicado a ele, em que posição ele estará?

![Questão 02 - heap com posições numeradas](_fontes/provas-figuras/2019-033/q02-heap.png)

- a) 4
- b) 5
- c) 8
- d) 9
- e) 6

<details><summary>Gabarito</summary>

**D.** Assunto 0102.

</details>

**Edital 033/2019 · Questão 04**

A figura abaixo mostra uma árvore B de ordem 5. Qual é o resultado da remoção do nó 130 dessa árvore?

![Questão 04 - árvore B de ordem 5](_fontes/provas-figuras/2019-033/q04-arvore-b.png)

Alternativas a) e b):

![Questão 04 - alternativas a) e b)](_fontes/provas-figuras/2019-033/q04-opcoes-ab.png)

Alternativas c) e d):

![Questão 04 - alternativas c) e d)](_fontes/provas-figuras/2019-033/q04-opcoes-cd.png)

- e) Nenhuma das anteriores

<details><summary>Gabarito</summary>

**C.** Folha `110` fica com 1 chave; irmãos têm o mínimo (2) e não emprestam, então funde com a direita: `110 140 144 156`, raiz `100 160`. Assunto 0097.

</details>

**Edital 033/2019 · Questão 08**

Quais são, respectivamente, o pior caso e o caso médio de uma árvore de busca binária em termos de complexidade?

- a) O(n), O(n)
- b) O(logn), O(logn)
- c) O(logn), O(n)
- d) O(n), O(logn)
- e) Nenhuma das respostas anteriores.

<details><summary>Gabarito</summary>

**D.** ABB sem balanceamento: pior caso O(n), caso médio O(log n). Assunto 0099.

</details>

**Edital 033/2019 · Questão 09**

Uma árvore B de ordem 4 e de altura 3, onde ordem é o número máximo de filhos em cada nó, terá um máximo de chaves igual a?

- a) 255
- b) 63
- c) 127
- d) 188
- e) 256

<details><summary>Gabarito</summary>

**A.** Ordem 4 (4 filhos, 3 chaves), altura 3 em arestas (Cormen): 1+4+16+64 = 85 nós, 85 x 3 = 255 chaves. Assunto 0097.

</details>

**Edital 033/2019 · Questão 12**

Qual é a altura máxima de qualquer árvore AVL com 7 nós? Assuma que a altura de uma árvore com um único nó seja 0.

- a) 2
- b) 3
- c) 4
- d) 5
- e) 6

<details><summary>Gabarito</summary>

**B.** Mínimo de nós por altura em AVL: 1, 2, 4, 7; 7 nós cabem em altura 3 (nó único = 0). Assunto 0101.

</details>

**Edital 033/2019 · Questão 16**

Ao se representar a heap máxima da figura abaixo em um array, a ordem dos elementos no array será a seguinte:

![Questão 16 - heap máxima](_fontes/provas-figuras/2019-033/q16-heap-maxima.png)

- a) 88 66 33 44 30 22 5 77 55 75
- b) 86 77 55 75 66 33 44 30 22 5
- c) 86 77 75 66 55 44 33 30 22 5
- d) 5 22 30 75 55 44 33 77 66 86
- e) 88 66 77 33 44 55 75 30 22 5

<details><summary>Gabarito</summary>

**E.** Array por níveis: 88 66 77 33 44 55 75 30 22 5. Assunto 0102.

</details>

**Edital 033/2019 · Questão 19**

Ao se construir uma árvore AVL, inicialmente vazia, com as seguintes chaves na ordem indicada - 2, 3, 5, 6, 9, 8, 7, 4, 1 – e sabendo que que se uma inserção fizer com que a árvore fique desequilibrada, é necessário executar as rotações para manter o equilíbrio, o resultado final da árvore AVL é:

![Questão 19 - alternativas a) a d)](_fontes/provas-figuras/2019-033/q19-arvores.png)

- e) Nenhuma das alternativas anteriores

<details><summary>Gabarito</summary>

**A.** Rodado em C: raiz 6; 3 e 8; 2, 5, 7, 9; 1, 4. Assunto 0101.

</details>

**Edital 033/2019 · Questão 20**

Sobre as afirmações abaixo, marque a alternativa CORRETA

I. A subárvore da raiz de um árvore vermelho e preto é sempre uma árvore vermelha e preta.\
II. O irmão de uma referência de filho nulo em uma árvore vermelha e preta é outra referência de filho nulo ou um nó vermelho.\
III. A pior complexidade de tempo da operação de inserção em uma árvore AVL é O(log n), onde n é o número de nós na árvore.\

- a) Somente a sentença I está correta
- b) As sentenças II e III estão correta
- c) Somente a sentença III está correta
- d) As sentenças I e III estão correta
- e) Somente a sentença II está correta

<details><summary>Gabarito</summary>

**B.** I falsa (a raiz de uma subárvore pode ser vermelha); II e III verdadeiras. Assunto 0101.

</details>

**Edital 060/2019 · Questão 02**

Dado os seguintes elementos (10, 20, 15, 25, 30, 16, 18, 19), qual desenho representa uma árvore AVL, inicialmente vazia, que é preenchida com esses elementos, na ordem apresentada, e que tem as devidas rotações efetuadas?

![Questão 02 - árvores (1) a (4)](_fontes/provas-figuras/2019-060/q02-arvores.png)

- a) 1
- b) 2
- c) 3
- d) 4
- e) Nenhuma das árvores desenhadas representa uma AVL

<details><summary>Gabarito</summary>

**A.** Assunto 0101.

</details>

**Edital 060/2019 · Questão 09**

Qual das afirmações a seguir é VERDADEIRA sobre árvores rubro-negra (vermelho e preto)?

- a) O caminho do nó raiz até o nó folha mais distante não é maior que o dobro do número de nós do caminho da raiz para a folha mais próxima
- b) O caminho do nó raiz para um nó folha ou para um nó nulo deve conter o mesmo número de nós pretos e vermelhos.
- c) A raiz pode ser vermelha
- d) Se um nó for vermelho, os nós filhos somente serão pretos. O inverso também acontece, ou seja, se um nó for preto, seus nós filhos somente serão vermelhos.
- e) Nenhumas das afirmações é verdadeira

<details><summary>Gabarito</summary>

**A.** Propriedade da rubro-negra: caminho mais longo no máximo o dobro do mais curto. Assunto 0101.

</details>

**Edital 060/2019 · Questão 12**

Quais das seguintes árvores abaixo respeita as regras básicas de balanceamento de árvores AVL?

![Questão 12 - árvores (A), (B) e (C)](_fontes/provas-figuras/2019-060/q12-arvores.png)

- a) Somente B
- b) A, B e C
- c) B e C
- d) A e C
- e) Nenhuma das árvores é AVL

<details><summary>Gabarito</summary>

**D.** A e C respeitam o fator de balanceamento; em B, o 50 fica com subárvore esquerda de altura 2 e direita vazia. Assunto 0101.

</details>

**Edital 060/2019 · Questão 15**

Comparando árvores AVL e rubro-negras, qual das seguintes afirmações é VERDADEIRA:

- a) As árvores AVL tendem a ter altura menor em comparação com as árvores rubro-negras, mas podem causar mais rotações durante operações de inserção e exclusão.
- b) As alturas das árvores AVL e rubro-negras são as mesmas, mas as árvores AVL podem causar mais rotações durante a inserção e exclusão.
- c) As árvores rubro-negras tendem a ter altura menor em comparação com as árvores AVL, mas podem causar mais rotações durante a inserção e exclusão.
- d) As alturas das árvores AVL e rubro-negras são as mesmas, mas as árvores rubro-negras podem causar mais rotações durante a inserção e exclusão.
- e) Todas as afirmações anteriores são falsas

<details><summary>Gabarito</summary>

**A.** AVL é mais rígida (altura menor) e rotaciona mais. Assunto 0101.

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
