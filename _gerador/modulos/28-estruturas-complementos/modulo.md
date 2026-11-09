# Módulo 28 · Estruturas: o que faltava

Os módulos 11, 14 e 15 construíram listas, árvores e tabelas hash do jeito
mais direto: o que funciona e cabe numa primeira leitura. Este módulo volta
a essas três estruturas e preenche o que ficou de fora, com o olhar do
Cormen, o livro da prova do PPGI. Não há estrutura nova, e sim as versões
que aparecem nos livros, nas bibliotecas e nas questões de concurso.

Três ideias atravessam o módulo. A primeira é a **sentinela**: um nó falso que
fica onde estaria o `NULL` e apaga os casos especiais do código, na lista
(`L.nil`) e na rubro-negra (`T.nil`). A segunda é o **conserto na volta**: a
AVL e a rubro-negra quebram uma regra ao inserir ou remover e consertam
subindo, com rotações e recolorações. A terceira é que **a escolha do número
importa**: o `m` da tabela hash, a constante `A` da multiplicação, o passo da
dispersão dupla e a ordem das passadas numa chave composta mudam o custo de
O(1) para O(n) sem mudar uma linha da lógica.

O que muda na cabeça é a pergunta "por quê?". Por que `m` primo e longe de
potência de 2? Por que a dupla só quando o filho pende para dentro? Por que a
altura da rubro-negra é no máximo 2 log₂(n + 1)? A prova cobra esses
porquês, e o módulo termina com uma agenda de consultas que usa a lista
com sentinela, a rubro-negra e a dispersão dupla no mesmo programa.

## O que você vai aprender

- a **lista dupla circular com sentinela** (`L.nil`): inserir, remover e
  buscar sem nenhum caso especial, e o truque da chave guardada na sentinela
- o vocabulário das árvores: **grau** do nó e da árvore, **nível**,
  **profundidade**, **altura**, **fator de balanceamento**; e **sucessor** e
  **antecessor** com ponteiro para o pai (`TREE-SUCCESSOR`)
- a **remoção na AVL**: o filho com fator 0, a rotação que encurta a subárvore
  e as **várias rotações** até a raiz
- a **rubro-negra clássica**: as **cinco propriedades**, a sentinela `T.nil`,
  a inserção com os **casos do tio**, a **altura negra** e a prova de que
  h ≤ 2 log₂(n + 1)
- as funções hash do Cormen: **divisão** (por que `m` primo) e
  **multiplicação** (`A` de Knuth e a versão em inteiros com deslocamento)
- **sondagem linear, quadrática e dispersão dupla**, agrupamento primário e
  secundário, **lápide** e **fator de carga** com as fórmulas de custo
- o **pigeonhole sort**, ordenação **estável** e não estável (quais dos
  clássicos são o quê) e **chave composta**: comparador composto e passadas
  estáveis em sequência

## Antes de começar

Este módulo é uma revisão por dentro. Ele supõe que você já fez a **lista
dupla** e a **lista circular** (0079 e 0080), a **BST** com busca, inserção e
remoção (0099 e 0100), a **AVL** com as rotações (0101), a **tabela hash** com
encadeamento e com sondagem linear (0105 a 0107) e as ordenações dos módulos
13 e 18, em especial a **estabilidade** (0096 e 0120). **Ponteiro para struct**
(0062), `malloc`/`free` e **TAD** (0074) aparecem em todo assunto.

Cada assunto tem um **TAD** na pasta (`sentinela.h`, `arvpai.h`, `avlrem.h`,
`vermelhopreto.h`, `espalha.h`, `sondagem.h`, `pombal.h`, `agenda.h`). O
texto mostra só o pedaço do `.c` que importa: abra o `.c` inteiro também. O
`rodar` compila junto os `.c` de apoio da pasta (como `vermelhopreto.c`),
então os comandos são os de sempre:

```bash
~/LPEDC/rodar 28-estruturas-complementos/0177-rubro-negra-classica/A353.c
```

As convenções são as do Cormen: **altura conta arestas** (folha tem altura 0,
árvore vazia tem -1), a raiz está no **nível 0** e o **fator de
balanceamento** é `altura(esq) - altura(dir)`. Alguns livros contam o nível a
partir de 1 ou o fator ao contrário: na prova, leia a definição do enunciado
antes de fazer a conta.

Nos assuntos 0176 e 0177, refaça o **Passo a passo** no papel antes de rodar,
desenhando a árvore inteira a cada rotação, com as alturas (AVL) ou as cores
(rubro-negra). Nos desenhos, a sentinela das listas é o nó cinza; na
rubro-negra, o nó preto aparece em cinza; nas tabelas hash, amarelo marca as
posições que a busca olhou e verde, onde achou a chave.

{{indice}}


---

{{assuntos}}

---

## Desafios do módulo

Problemas para resolver no papel e, quando fizer sentido, num arquivo `.c` seu
usando os TADs do módulo. Eles misturam os assuntos.

**1. A lista que não tem ponta.** Numa lista com sentinela que contém 10, 20 e
30, faça, nesta ordem: insira 5 no começo, remova o último, insira 40 depois
do último (`sent_insere_apos(L, L->nil.ant, 40)`), busque o 20 e remova o nó
achado. Como fica a lista, de frente para trás e de trás para a frente?
Quantas vezes você precisou de um `if` para tratar uma ponta?

<details><summary>Resposta</summary>

**[ 5 10 40 ]** e, de trás, **[ 40 10 5 ]**. Nenhum `if`: a inserção no
começo é "depois da sentinela", a remoção do último é `sent_remove(L,
L->nil.ant)` e a inserção no fim é "depois do último". Caminho: faça as
operações uma a uma desenhando os quatro ponteiros de cada inserção e os dois
de cada remoção.

</details>

**2. Sucessores numa árvore torta.** Insira 40, 20, 60, 10, 30, 50, 70, 25, 35
e 33, nesta ordem, numa BST com pai. Qual é o sucessor de 35, o antecessor de
40, o sucessor de 30 e o antecessor de 25? Qual é o grau do 30, a
profundidade do 33, a altura da árvore e o fator de balanceamento do 20?

<details><summary>Resposta</summary>

Sucessor de 35: **40** (caso 2: sobe por 30 e 20, que foram alcançados pela
direita, até o 40, alcançado pela esquerda). Antecessor de 40: **35** (o
máximo da esquerda). Sucessor de 30: **33** (o mínimo da subárvore do 35).
Antecessor de 25: **20** (sobe: 25 é filho esquerdo do 30, que é filho
direito do 20). Grau do 30: **2**; profundidade do 33: **4**; altura: **4**;
fator do 20: altura(10) - altura(30) = 0 - 2 = **-2**. Confira com `arvpai.h`.

</details>

**3. A AVL que esvazia.** Insira 1 a 7 numa AVL (sai a árvore perfeita com o 4
na raiz) e remova 1, 2 e 3, nesta ordem. Quantas rotações cada remoção faz e
qual é a pré-ordem no fim?

<details><summary>Resposta</summary>

Tirar 1: **0** rotações; tirar 2: **0**; tirar 3: **1** (o 4 fica sem
filhos à esquerda e com a subárvore do 6, de altura 1, à direita: fator -2,
filho 6 com fator 0, rotação simples à esquerda). Pré-ordem final:
**6 4 5 7**. Repare no fator 0 do filho: só a remoção produz esse caso, e ele
pede a rotação simples.

</details>

**4. O menor AVL de cada altura.** Qual é o menor número de nós de uma AVL de
altura 5? Quantas rotações a remoção da maior chave faz nessa árvore?

<details><summary>Resposta</summary>

N(h) = N(h - 1) + N(h - 2) + 1, com N(0) = 1 e N(1) = 2: 1, 2, 4, 7, 12,
**20**. É a árvore de Fibonacci do E1056. Tirar a maior chave dela faz **2**
rotações: em geral, ⌊h/2⌋, uma a cada dois níveis, porque cada conserto
encurta a subárvore e passa o desequilíbrio para o avô.

</details>

**5. Rubro-negra em ordem.** Insira 1 a 8, em ordem, numa rubro-negra
clássica. Qual é a pré-ordem (marque os vermelhos), quantas vezes rodou cada
caso do conserto, quantas rotações houve, qual é a altura e a altura negra?

<details><summary>Resposta</summary>

Pré-ordem **4 2\* 1 3 6\* 5 7 8\***. Caso 1: **3** vezes; caso 2: **0**; caso
3: **4** vezes, portanto **4** rotações. Altura **3**, altura negra **2**.
Com chaves crescentes, o novo nó sempre fica "em linha" com o pai e o avô
(filho direito de filho direito): nunca há triângulo, então o caso 2 não
aparece. Confira com `T->casos` do `vermelhopreto.h`.

</details>

**6. O limite da rubro-negra.** Uma rubro-negra tem 1000 nós. Qual é a maior
altura possível? E a menor? Uma rubro-negra com altura negra 4 pode ter 12
nós?

<details><summary>Resposta</summary>

Maior: h ≤ 2 log₂(1001) ≈ 19,9, então no máximo **19**. Menor: a de qualquer
árvore binária com 1000 nós, ⌈log₂(1001)⌉ - 1 = **9**. Com altura negra 4 a
árvore tem pelo menos 2⁴ - 1 = **15** nós, então **não** pode ter 12. O A353
mede: 1000 chaves crescentes dão altura 16.

</details>

**7. Duas funções, uma chave.** Para k = 1000 e m = 16, calcule o balde pelo
método da divisão e pela multiplicação em inteiros (s = 2654435769, p = 4). E
para k = 1001?

<details><summary>Resposta</summary>

Divisão: 1000 % 16 = **8**; 1001 % 16 = **9** (chaves vizinhas, baldes
vizinhos). Multiplicação: os 4 bits altos de (1000 · s) mod 2³² dão **0**; para
1001, **10**. A multiplicação espalha chaves vizinhas para longe uma da outra,
mas não promete evitar o balde 0. Confira com `esp_mult_desloca`.

</details>

**8. Três sondagens, mesmas chaves.** Numa tabela de m = 11, insira 4, 15, 26,
37 e 48 (todas começam no 4) com sondagem linear e com quadrática
(h + i²). Em que posição cada uma fica e quantas sondagens custa a última?

<details><summary>Resposta</summary>

Linear: 4, 5, 6, 7, 8; a 48 faz **5** sondagens. Quadrática: 4, 5, 8, 2
(4 + 9 = 13, mod 11) e 9 (4 + 16 = 20, mod 11); a 48 também faz **5**. As
posições mudam, mas como todas começam no 4, a quadrática repete a mesma
trilha para todas: agrupamento secundário. Só a dispersão dupla separaria as
trilhas.

</details>

**9. Dupla com passo bom e passo ruim.** Numa tabela de m = 11 com
h₁(k) = k mod 11 e h₂(k) = 1 + (k mod 10), insira 22, 33, 44, 55 e 66. Depois
diga por que h₂(k) = k mod 10 (sem o 1) seria um erro.

<details><summary>Resposta</summary>

Posições **0, 4, 5, 6 e 7**, com 1, 2, 2, 2 e 2 sondagens (passos 3, 4, 5, 6
e 7 a partir do 0). Sem o `+ 1`, as chaves terminadas em 0 (como 110) teriam
passo **0**: a sequência ficaria parada na mesma posição e a inserção
falharia com a tabela quase vazia.

</details>

**10. Lista de aprovados.** O resultado do vestibular tem cidade, curso e
nota. A lista final é por cidade; dentro da cidade, por curso; dentro do
curso, da maior nota para a menor. Usando só ordenações estáveis de uma chave
por vez, quais passadas você faz e em que ordem? E com `qsort`?

<details><summary>Resposta</summary>

Da chave menos importante para a mais importante: **nota (decrescente),
depois curso, depois cidade**, todas com método estável (inserção, merge,
counting ou pigeonhole, se o intervalo for pequeno). Com `qsort`, **uma
passada** com um comparador composto: compara cidade; se empatar, curso; se
empatar, a nota ao contrário. Como o `qsort` não é estável, um último
desempate (nome ou matrícula) deixa a ordem determinada.

</details>

**11. Custos da agenda.** Na agenda do 0181, com n pacientes cadastrados, c
horários na árvore e f pessoas na fila, qual é o custo de: cadastrar,
marcar, achar a próxima consulta depois de certa hora, cancelar com fila e
listar k consultas de um intervalo?

<details><summary>Resposta</summary>

Cadastrar: **O(1)** em média (a carga fica abaixo de 1/2). Marcar: **O(log
c)** na rubro-negra, mais O(1) na hash; se o paciente estava na fila,
`ag_marca` ainda o procura nela, **O(f)**. Próxima consulta: **O(log c)** se
não houver horários vagos no caminho (teto + sucessor). Cancelar: O(log c) +
O(1) + a marcação do primeiro da fila. Intervalo: **O(log c + k)**.

</details>

## Questões no estilo da prova

**1.** Numa lista duplamente encadeada circular com nó sentinela `L.nil`, a
lista contém apenas o nó `x`. Executa-se:

```c
x->ant->prox = x->prox;
x->prox->ant = x->ant;
```

Logo depois dessas duas linhas, é correto afirmar que:

(A) `L.nil.prox == NULL` e `L.nil.ant == NULL`.
(B) `L.nil.prox == &L.nil` e `L.nil.ant == &L.nil`.
(C) `L.nil.prox == x`, porque `x` ainda não foi liberado.
(D) o código acessa `NULL`, pois `x` não tem vizinhos.
(E) é preciso um `if` para o caso de `x` ser o único nó.

<details><summary>Gabarito</summary>

**(B).** Com um nó só, os dois vizinhos de `x` são a própria sentinela: a
primeira linha faz `nil.prox = nil` e a segunda, `nil.ant = nil`. É o estado
da lista vazia, sem nenhum caso especial. (A) e (D) supõem `NULL`, que não
existe dentro dessa lista. Estude o 0174.

</details>

**2.** Insere-se, nesta ordem, as chaves 50, 30, 80, 20, 40, 70, 90, 35, 45 e
42 numa árvore binária de busca sem balanceamento. Usando o algoritmo
`TREE-SUCCESSOR` (com ponteiro para o pai), o sucessor de 45 e o sucessor
de 40 são, respectivamente:

(A) 42 e 45.
(B) 50 e 42.
(C) 50 e 45.
(D) 80 e 42.
(E) 42 e 35.

<details><summary>Gabarito</summary>

**(B).** O 45 não tem filho direito (só o 42, à esquerda): sobe pelo 40 e
pelo 30, ambos alcançados pela direita, até o 50, alcançado pela esquerda.
O 40 tem subárvore direita (45 com 42): o sucessor é o mínimo dela, 42.
Estude o 0175.

</details>

**3.** Na mesma árvore da questão 2, com altura medida em arestas e a raiz no
nível 0, assinale a afirmativa correta.

(A) A altura da árvore é 3.
(B) O nó 42 está no nível 3.
(C) O fator de balanceamento da raiz é 2, logo a árvore não é AVL.
(D) O grau da árvore é 3.
(E) O nó 40 é uma folha.

<details><summary>Gabarito</summary>

**(C).** A subárvore do 30 tem altura 3 (30, 40, 45, 42) e a do 80, altura
1: fator 3 - 1 = 2. A altura da árvore é 4 e o 42 está no nível 4 (A e B
erradas); a árvore é binária, então o grau é no máximo 2 (D); o 40 tem dois
filhos (E). Estude o 0175.

</details>

**4.** Numa árvore AVL, insere-se 50, 30, 70, 20, 40, 80 e 10, nesta ordem
(nenhuma rotação acontece). Em seguida remove-se o 70 e depois o 80 (na
remoção de nó com dois filhos, usa-se o sucessor). Ao final:

(A) a raiz é 50 e não houve rotação.
(B) a raiz é 30, depois de uma rotação simples à direita.
(C) a raiz é 40, depois de uma rotação dupla.
(D) a raiz é 30, depois de duas rotações duplas.
(E) a árvore deixa de ser AVL, pois a remoção não rebalanceia.

<details><summary>Gabarito</summary>

**(B).** Tirar o 70 (que só tem o 80) põe o 80 no lugar, e o 50 fica com
altura 2 à esquerda e 0 à direita: fator 2. O filho 30 tem fator 1 (o 20,
com o 10 embaixo, contra o 40): rotação simples à direita no 50, e o 30 vira
a raiz. Tirar o 80 depois não desequilibra nada (pré-ordem final
30 20 10 50 40). Estude o 0176.

</details>

**5.** Sobre as árvores rubro-negras, na definição de Cormen et al., é
**incorreto** afirmar:

(A) A raiz é preta.
(B) Toda folha (`T.nil`) é preta.
(C) Se um nó é vermelho, seus dois filhos são pretos.
(D) Para cada nó, todos os caminhos dele até as folhas descendentes têm o
mesmo número de nós pretos.
(E) Todos os caminhos da raiz até as folhas têm o mesmo número de nós.

<details><summary>Gabarito</summary>

**(E).** O que é igual em todos os caminhos é o número de nós **pretos** (a
propriedade 5, em D). O total de nós pode variar: um caminho pode ter até o
dobro de nós de outro, alternando vermelhos e pretos. É por isso que a altura
fica em até 2 log₂(n + 1), e não em log₂(n + 1). Estude o 0177.

</details>

**6.** Uma árvore rubro-negra armazena 1023 chaves. O maior valor possível
para a sua altura é, no máximo:

(A) 9
(B) 10
(C) 20
(D) 512
(E) 1022

<details><summary>Gabarito</summary>

**(C).** h ≤ 2 log₂(n + 1) = 2 log₂(1024) = 20. A prova: a subárvore de um
nó x tem pelo menos 2^bh(x) - 1 nós, e pela propriedade 4 a altura negra da
raiz é pelo menos h/2. (B) seria o limite de uma árvore perfeitamente
balanceada; (E), o de uma BST degenerada. Estude o 0177.

</details>

**7.** Uma tabela hash com encadeamento vai guardar cerca de 2000 chaves
inteiras, com uns 3 elementos por lista, usando o método da divisão,
h(k) = k mod m. Pelo critério de Cormen et al., a melhor escolha para m é:

(A) 512
(B) 1024
(C) 701
(D) 1000
(E) 64

<details><summary>Gabarito</summary>

**(C).** O ideal é um primo perto de n/α ≈ 667 e longe de potências de 2.
Com m = 2^p (A, B, E), h(k) é só os p bits de baixo da chave; com m = 10³
(D), só os três últimos dígitos. 701 é primo, perto de 667 e longe de 512 e
de 1024. Estude o 0178.

</details>

**8.** Considere a função a seguir, em C:

```c
#include <stdint.h>
#include <stdio.h>

uint32_t h(uint32_t k, int p) {
    return (k * 2654435769u) >> (32 - p);
}

int main(void) {
    printf("%u %u\n", h(48, 4), h(48, 5));
    return 0;
}
```

Sabendo que 48 × 2654435769 = 0x1DAA66D2B0, o programa imprime:

(A) 0 0
(B) 10 21
(C) 10 20
(D) 13 27
(E) 48 48

<details><summary>Gabarito</summary>

**(B).** O `uint32_t` guarda só os 32 bits de baixo: 0xAA66D2B0, que começa
com os bits 1010 1... Com p = 4, os 4 bits mais altos: 1010 = 10. Com p = 5,
10101 = 21. É o método da multiplicação em inteiros, com s = ⌊A · 2³²⌋ e A de
Knuth. Estude o 0178.

</details>

**9.** Numa tabela de endereçamento aberto com m = 7, usa-se dispersão dupla:
h(k, i) = (h₁(k) + i · h₂(k)) mod 7, com h₁(k) = k mod 7 e
h₂(k) = 1 + (k mod 6). Inserindo-se 14, 21 e 28, nesta ordem, numa tabela
vazia, as posições ocupadas são:

(A) 0, 1 e 2
(B) 0, 4 e 5
(C) 0, 3 e 6
(D) 0, 2 e 4
(E) 0, 4 e 1

<details><summary>Gabarito</summary>

**(B).** As três chaves têm h₁ = 0. O 14 fica no 0. O 21 tem passo
1 + 21 mod 6 = 4: tenta 0 (ocupado) e fica no 4. O 28 tem passo
1 + 28 mod 6 = 5: tenta 0 e fica no 5. Com sondagem linear, seriam 0, 1 e 2
(A): agrupamento primário. Estude o 0179.

</details>

**10.** Considere, em suas implementações usuais, os métodos de ordenação:
I. inserção; II. seleção; III. merge sort; IV. heapsort; V. counting sort;
VI. quicksort. São estáveis apenas:

(A) I, II e III
(B) I, III e V
(C) II, IV e VI
(D) I, III, IV e V
(E) todos, desde que as chaves sejam inteiras

<details><summary>Gabarito</summary>

**(B).** Inserção (desloca só quem é estritamente maior), merge (no empate,
pega da esquerda) e counting (percorre a entrada de trás para a frente, ou
usa filas) preservam a ordem dos empates. Seleção, heapsort e quicksort fazem
trocas a distância, que pulam por cima de elementos iguais. Estude o 0180 e o
0096.

</details>

## Para ler mais

- CORMEN, T. H.; LEISERSON, C. E.; RIVEST, R. L.; STEIN, C. *Algoritmos: teoria e prática*. 4. ed. Rio de Janeiro: GEN LTC, 2024. Caps. 10 (listas com sentinela), 12 (árvores binárias de busca: sucessor e antecessor), 13 (árvores rubro-negras) e 11 (tabelas hash: divisão, multiplicação, endereçamento aberto).
- CELES, W.; CERQUEIRA, R.; RANGEL, J. L. *Introdução a estruturas de dados: com técnicas de programação em C*. 2. ed. Rio de Janeiro: Elsevier, 2016. Listas duplamente encadeadas e circulares, árvores e tabelas de dispersão.
- TENENBAUM, A. M.; LANGSAM, Y.; AUGENSTEIN, M. J. *Estruturas de dados usando C*. São Paulo: Makron Books, 1995. Listas com nó de cabeçalho, árvores balanceadas e métodos de hashing (sondagem e dispersão dupla).
- SZWARCFITER, J. L.; MARKENZON, L. *Estruturas de dados e seus algoritmos*. 3. ed. Rio de Janeiro: LTC, 2010. Árvores AVL (inserção e remoção), árvores rubro-negras e tabelas de dispersão.
- ZIVIANI, N. *Projeto de algoritmos com implementações em Pascal e C*. 3. ed. São Paulo: Cengage Learning, 2010. Ordenação (estabilidade), árvores balanceadas e transformação de chave (hashing).
- FEOFILOFF, P. *Algoritmos em linguagem C*. Rio de Janeiro: Elsevier, 2009. Listas encadeadas com cabeça, árvores de busca e tabelas de símbolos.
- KNUTH, D. E. *The art of computer programming*. v. 3: Sorting and searching. 2. ed. Reading: Addison-Wesley, 1998. Seção 6.4 (hashing: o método da multiplicação e a razão áurea).
- GUIBAS, L. J.; SEDGEWICK, R. A dichromatic framework for balanced trees. In: SYMPOSIUM ON FOUNDATIONS OF COMPUTER SCIENCE, 19., 1978, Ann Arbor. *Proceedings* [...]. IEEE, 1978. p. 8-21.
- ADELSON-VELSKY, G. M.; LANDIS, E. M. An algorithm for the organization of information. *Soviet Mathematics Doklady*, v. 3, p. 1259-1263, 1962.
- KERNIGHAN, B. W.; RITCHIE, D. M. *C: a linguagem de programação padrão ANSI*. Rio de Janeiro: Campus, 1989. Seção 6.5 (estruturas autorreferenciadas) e 5.11 (ponteiros para funções, usados pelo `qsort`).
- CPPREFERENCE. *qsort*. Disponível em: <https://en.cppreference.com/w/c/algorithm/qsort>.
- CPPREFERENCE. *Fixed width integer types* (`uint32_t`). Disponível em: <https://en.cppreference.com/w/c/types/integer>.
