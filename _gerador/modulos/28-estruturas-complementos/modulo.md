# Módulo 28 · Estruturas: o que faltava

Completa listas, árvores e hash dos módulos 11, 14 e 15 com as versões do
Cormen: lista com sentinela, sucessor com ponteiro para o pai, remoção na AVL,
rubro-negra clássica, hash por multiplicação, sondagem quadrática e dupla e
ordenação estável por chave composta. Termina com uma agenda que junta tudo.

## O que você vai aprender

- a **lista dupla circular com sentinela** (`L.nil`) e o truque da chave
  guardada nela
- o vocabulário das árvores (**grau**, **nível**, **profundidade**,
  **altura**, **fator de balanceamento**), **sucessor** e **antecessor** com
  ponteiro para o pai
- a **remoção na AVL**: filho com fator 0 e rotações até a raiz
- a **rubro-negra clássica**: as **cinco propriedades**, os **casos do tio**,
  a **altura negra** e h ≤ 2 log₂(n + 1)
- as funções hash do Cormen: **divisão** (por que `m` primo) e
  **multiplicação** (`A` de Knuth, versão em inteiros)
- **sondagem linear, quadrática e dupla**, **lápide** e **fator de carga**
- o **pigeonhole sort**, ordenação **estável** e **chave composta**

## Antes de começar

Supõe lista dupla e circular (0079, 0080), BST (0099, 0100), AVL (0101),
hash (0105 a 0107), estabilidade (0096, 0120), ponteiro para struct (0062) e
TAD (0074).

Cada assunto tem um TAD na pasta (`sentinela.h`, `arvpai.h`, `avlrem.h`,
`vermelhopreto.h`, `espalha.h`, `sondagem.h`, `pombal.h`, `agenda.h`), e o
texto mostra só o pedaço do `.c` que importa. Compile junto os `.c` de apoio:

```bash
gcc ~/LPEDC/material/A353.c ~/LPEDC/material/0177-vermelhopreto.c -o ~/LPEDC/material/A353 -lm && ~/LPEDC/material/A353
```

Convenções do Cormen: altura conta arestas (folha 0, árvore vazia -1), a raiz
está no nível 0 e o fator é `altura(esq) - altura(dir)`. Confira a definição
do enunciado, porque alguns livros mudam isso.

Nos desenhos, a sentinela e o nó preto são cinza; nas tabelas hash, amarelo
marca as posições olhadas e verde, onde achou a chave.

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

Questões objetivas no formato da Prova de Conhecimentos do PPGI: uma
alternativa certa. Onde o enunciado não disser outra coisa, a raiz fica no
nível 1 e a folha tem altura 1.

**1.** A lista duplamente encadeada abaixo é circular, com nó sentinela
(`nil`). A função remove o nó `x`, que é um nó real da lista:

```c
typedef struct No {
    int chave;
    struct No *ant, *prox;
} No;

void remover(No *x) {
    free(x);
    x->ant->prox = x->prox;
    x->prox->ant = x->ant;
}
```

Qual é o defeito?

- (A) Falta tratar o caso de `x` ser o único nó da lista.
- (B) Falta testar se `x` é a sentinela, que nunca pode sair.
- (C) As duas linhas de religação estão na ordem trocada.
- (D) Lê `x->ant` e `x->prox` depois do `free(x)`; o `free` deveria vir depois das duas atribuições.
- (E) Falta zerar `x->ant` e `x->prox` para a lista não ficar com ponteiros soltos.

<details><summary>Gabarito</summary>

**D.** O `free` devolve o bloco, e as três linhas seguintes leem e usam o
conteúdo dele: é uso depois de liberar, comportamento indefinido (o valgrind
acusa "Invalid read", e o gcc avisa com `-Wall`). A ordem certa é religar os
vizinhos e só então liberar. Com a sentinela, o único nó não pede caso
especial (A), e a ordem das duas religações tanto faz (C). Veja 0174.

</details>

**2.** Numa ABB sem balanceamento são inseridas as chaves
`60 35 85 20 45 75 95 40 55 50`, nesta ordem. Usando o `TREE-SUCCESSOR` do
Cormen (com ponteiro para o pai), quais são o sucessor do 45 e o sucessor do
60, respectivamente?

- (A) 50 e 75
- (B) 55 e 85
- (C) 50 e 85
- (D) 55 e 75
- (E) 40 e 75

<details><summary>Gabarito</summary>

**A.** Se o nó tem filho direito, o sucessor é o mínimo dessa subárvore. O 45
tem o 55 à direita, e o mínimo a partir dele, descendo pela esquerda, é o 50
(o 55 é só o filho direito, não o mínimo). O 60 tem o 85 à direita, e o 85
tem o 75 à esquerda. Sem filho direito, sobe-se até o primeiro ancestral
de quem o nó descende pela esquerda. Veja 0175.

</details>

**3.** Uma árvore binária perfeita (todos os níveis completos) tem 63 nós.
Qual é a altura dela e quantas folhas ela tem?

- (A) altura 5; 31 folhas
- (B) altura 6; 31 folhas
- (C) altura 6; 32 folhas
- (D) altura 7; 32 folhas
- (E) altura 7; 64 folhas

<details><summary>Gabarito</summary>

**C.** O nível `k` tem 2^(k-1) nós: 1 + 2 + 4 + 8 + 16 + 32 = 63, seis níveis,
logo a altura é 6 (folha com altura 1). As folhas são o último nível: 32,
que é (n + 1)/2. A (A) usaria altura em arestas (5) e erraria as folhas. Se a
prova trocasse para a altura em arestas, a resposta mudaria para 5: leia a
convenção do enunciado. Veja 0175.

</details>

**4.** Numa AVL vazia são inseridas as chaves `60 30 80 20 40 70 90 10 50 65`,
nesta ordem (nenhuma rotação acontece). Em seguida remove-se o 90. Qual é a
pré-ordem depois da remoção e do rebalanceamento?

- (A) `60 30 20 10 40 50 80 70 65`; nenhuma rotação
- (B) `60 30 20 10 40 50 70 65 80`; rotação simples à direita no 80
- (C) `60 30 20 10 40 50 65 70 80`; rotação dupla (esquerda no 70, direita no 80)
- (D) `60 30 20 10 40 50 70 65 80`; rotação dupla (esquerda no 70, direita no 80)
- (E) `30 20 10 60 40 50 80 70 65`; rotação simples à direita na raiz 60

<details><summary>Gabarito</summary>

**B.** O 90 é folha e sai. O 80 fica com o 70 (e o 65 embaixo) à esquerda e
nada à direita: fator 2. O filho esquerdo, 70, tem fator 1 (o 65 à esquerda
dele): caso esquerda-esquerda, uma rotação simples à direita no 80 faz o 70
subir, com o 65 e o 80 de filhos. A (A) deixa a árvore desequilibrada. A (C)
e a (D) seriam o caso zigue-zague, que exigiria o 65 à direita do 70. A raiz
continua com fator 1, sem rotação (E). Veja 0176.

</details>

**5.** Considere as afirmações:

I. Na rubro-negra clássica, uma inserção faz no máximo 2 rotações.\
II. Na rubro-negra clássica, uma remoção faz no máximo 3 rotações.\
III. Na AVL, uma remoção faz no máximo 1 rotação, com certeza.

Está(ão) correta(s):

- (A) Apenas I.
- (B) Apenas II e III.
- (C) Apenas III.
- (D) Apenas I e III.
- (E) Apenas I e II.

<details><summary>Gabarito</summary>

**E.** São os limites do Cormen: `RB-INSERT-FIXUP` rotaciona no máximo duas
vezes (o recolorir é que pode subir pela árvore) e `RB-DELETE-FIXUP`, no
máximo três. Na III, "com certeza" derruba: numa AVL, depois de rotacionar, a
subárvore pode encolher e o desequilíbrio subir, até uma rotação por nível. É
a diferença entre as duas árvores na remoção. Veja 0176 e 0177.

</details>

**6.** Uma tabela hash com `m = 1000` posições usa o método da multiplicação,
`h(k) = ⌊m · (k · A mod 1)⌋`, com `A = (√5 - 1)/2 ≈ 0,6180339887`. Para a
chave `k = 350`, o valor de `h(k)` é:

- (A) 311
- (B) 216
- (C) 618
- (D) 688
- (E) 350

<details><summary>Gabarito</summary>

**A.** 350 · 0,6180339887 = 216,3119...; o `mod 1` fica só com a parte
fracionária, 0,3119...; multiplicando por 1000 dá 311,9..., e o piso é 311.
A (B) é a parte inteira, que o `mod 1` descarta; a (D), o complemento
1 - 0,3119; a (C), o próprio `A · 1000`. Veja 0178.

</details>

**7.** Uma tabela de endereçamento aberto tem `m = 11` e usa sondagem
quadrática, `h(k, i) = (k mod 11 + i²) mod 11`. Inserem-se, nesta ordem, as
chaves `14 25 36 47 5 16 27` numa tabela vazia. Conte uma colisão cada vez que
a sondagem cai numa posição ocupada. Em que posição fica o 27 e quantas
colisões houve ao todo?

- (A) posição 7; 9 colisões
- (B) posição 6; 15 colisões
- (C) posição 9; 15 colisões
- (D) posição 9; 9 colisões
- (E) posição 8; 10 colisões

<details><summary>Gabarito</summary>

**D.** O 14 vai para a posição 3. O 25 (também 3): tenta 3 e 4, 1 colisão. O
36: 3, 4 e 3 + 4 = 7, 2 colisões. O 47: 3, 4, 7 e 3 + 9 = 12 mod 11 = 1, 3
colisões. O 5 cai livre na 5. O 16 (também 5): 5 e 6, 1 colisão. O 27
(também 5): 5, 6 e 5 + 4 = 9, 2 colisões. Total 0 + 1 + 2 + 3 + 0 + 1 + 2 = 9.
Com sondagem linear, o total seria 15: a quadrática desfaz os blocos. Veja
0179.

</details>

**8.** Considere as afirmações sobre endereçamento aberto:

I. Na sondagem linear, chaves com `h'(k)` diferentes podem passar a seguir a
mesma trilha: é o agrupamento primário.\
II. Na dispersão dupla, duas chaves com o mesmo `h₁(k)` seguem
necessariamente a mesma sequência de sondagem.\
III. Na sondagem quadrática `(h'(k) + i²) mod m`, com `m` primo, a sequência
de uma chave visita só cerca de metade das posições.\
IV. Ao remover uma chave, a posição deve virar lápide, e não livre.

Estão corretas:

- (A) Apenas I e II.
- (B) Apenas I, III e IV.
- (C) Apenas II e IV.
- (D) Apenas I e III.
- (E) I, II, III e IV.

<details><summary>Gabarito</summary>

**B.** A I descreve o bloco da linear: quem cai em qualquer ponto dele vai
para o fim. A II cai no "necessariamente": o passo `h₂(k)` depende da chave,
então chaves com o mesmo `h₁` costumam andar com passos diferentes (na
quadrática, sim, a trilha é a mesma: colisão secundária). Na III, os
quadrados módulo um primo `m` assumem só (m + 1)/2 valores. Na IV, uma posição
livre cortaria o caminho de quem passou por ali. Veja 0179.

</details>

**9.** A lista de chamada, em ordem alfabética, traz (nome, turma, nota): Ana
(2, 7), Bia (1, 9), Caio (2, 5), Duda (3, 7), Edu (1, 5), Fabi (3, 9), Gil
(2, 9), Hana (1, 7) e Ivo (2, 7). Quer-se ordenar por turma crescente e, dentro
da turma, por nota crescente, com empates na ordem original. Fazem-se duas
passadas estáveis de pigeonhole: primeiro pela nota, depois pela turma. Qual é
a ordem final?

- (A) `Bia Edu Hana Ana Caio Gil Ivo Duda Fabi`
- (B) `Edu Caio Hana Ana Ivo Duda Bia Gil Fabi`
- (C) `Edu Hana Bia Caio Ivo Ana Gil Duda Fabi`
- (D) `Bia Hana Edu Gil Ana Ivo Caio Fabi Duda`
- (E) `Edu Hana Bia Caio Ana Ivo Gil Duda Fabi`

<details><summary>Gabarito</summary>

**E.** Depois da passada pela nota: Caio Edu Ana Duda Hana Ivo Bia Fabi Gil
(a Ana antes do Ivo, empatados). A passada estável pela turma separa nas
turmas 1 (Edu, Hana, Bia), 2 (Caio, Ana, Ivo, Gil) e 3 (Duda, Fabi), mantendo
dentro de cada uma a ordem anterior. A (A) é só a passada pela turma, sem
ordenar a nota; a (B) inverte as passadas (a turma vira o critério
secundário); a (C) troca Ana e Ivo, o que um método não estável pode fazer; a
(D) usa nota decrescente. Veja 0180.

</details>

**10.** Considere as afirmações:

I. O pigeonhole sort é estável quando cada casa é uma fila.\
II. O custo O(n + r), com r o número de valores possíveis, faz dele sempre
mais rápido que o merge sort.\
III. Para ordenar por chave composta com passadas estáveis, ordena-se
primeiro pela chave menos importante e por último pela mais importante.\
IV. O selection sort é estável, pois só troca quando acha um elemento
estritamente menor.

Estão corretas:

- (A) Apenas I.
- (B) Apenas II e IV.
- (C) Apenas I e III.
- (D) Apenas I, III e IV.
- (E) Apenas II, III e IV.

<details><summary>Gabarito</summary>

**C.** A I vale: a fila devolve quem entrou primeiro. A II cai no "sempre":
se `r` for muito maior que `n` (chaves de 0 a 10^9 para mil registros), o
n + r é pior que n log n. A III é a regra do radix LSD: a última passada manda
e as anteriores só desempatam. Na IV, a troca é a distância e pula por cima de
iguais: em `2a 2b 1`, o 1 troca com o `2a` e o `2a` termina depois do `2b`.
Veja 0180 e 0096.

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
