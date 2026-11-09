# Módulo 22 · Árvores e conjuntos avançados

No módulo 14, a árvore era quase sempre binária, morava na memória e guardava
números. Este módulo tira as três rodinhas. Uma árvore pode ter **qualquer
número de filhos** (o orçamento de uma obra, o sumário de uma apostila). Pode
ser equilibrada com **um bit por nó** em vez de uma altura (a rubro-negra). Pode
ter nós **gordos**, com centenas de chaves, para morar no disco (a árvore B dos
bancos de dados). Pode ter arestas que **são letras** (a trie do autocompletar).
E pode até ter as setas ao contrário, do filho para o pai, para responder "estes
dois estão no mesmo grupo?" quase de graça (o union-find).

O que muda na cabeça é a pergunta que você faz antes de escolher a estrutura:
em vez de "qual árvore eu sei programar?", vem "**qual operação vai rodar
milhões de vezes?**". Busca exata, busca por prefixo, leitura em disco, união de
grupos: cada uma pede um formato de nó diferente, e o formato do nó decide o
custo.

Quase tudo continua recursivo, e a árvore 2-3 aparece como o elo escondido entre
duas delas: a rubro-negra é uma árvore 2-3 escrita com nós binários, e a árvore
B é a mesma ideia com nós ainda maiores. No fim, um corretor ortográfico junta a
trie com a distância de edição do módulo 21 e compara a trie com a hash e a BST
no mesmo dicionário.

## O que você vai aprender

- representar **árvores gerais** com primeiro filho / próximo irmão e ver nelas uma árvore binária
- a **rubro-negra esquerdista** (LLRB): as três regras, os três consertos e a árvore 2-3 por trás
- a **árvore B**: nós com várias chaves, busca, **divisão** do nó cheio e inserção que cresce pela raiz
- a **trie**: o prefixo como endereço, busca em O(tamanho da palavra) e **autocompletar**
- o **union-find**: conjuntos disjuntos com **união por tamanho** e **compressão de caminho**
- montar um **corretor ortográfico** e comparar trie, tabela hash e BST com números de verdade

## Antes de começar

Este módulo usa muito do que veio antes: **recursão** (0032 e 0033),
**ponteiros para struct** (0062), `malloc`, `calloc` e `free` (0054 e 0055),
**TAD** (0074), a **BST** e as **rotações da AVL** (0099 a 0101), a **tabela
hash** (0105 a 0108) e a **distância de edição** (0142). A análise amortizada do
0116 explica o "quase O(1)" do union-find.

Cada assunto tem um **TAD** na pasta (`arvgen.h`, `rubronegra.h`, `arvoreb.h`,
`trie.h`, `uniao.h`, `corretor.h`). O texto mostra o pedaço do `.c` que
importa; abra o `.c` inteiro também. O `rodar` compila junto os `.c` de apoio
da pasta (como `trie.c`):

```bash
~/LPEDC/rodar 22-arvores-avancadas/0147-trie/A293.c
```

Duas convenções valem para o módulo todo. **Altura conta arestas**, como no
módulo 14: uma folha tem altura 0. E, na árvore B, o TAD usa o **grau mínimo**
`t` (de `t - 1` a `2t - 1` chaves por nó). Outros livros falam em "ordem m"
querendo dizer o número máximo de filhos (e o Ziviani, de m a 2m chaves por
página); confira a convenção antes de comparar números. A rubro-negra do 0145
é a **esquerdista** (LLRB); a clássica do Cormen, que é a que a prova do PPGI
cobra, está no assunto 0177.

Papel e lápis continuam obrigatórios. Na rubro-negra, desenhe a árvore 2-3
junto; na árvore B, cada divisão; no union-find, as setas para o pai antes e
depois de cada busca. Nos desenhos, o nó vermelho da rubro-negra é vermelho e
o preto aparece em cinza; na trie, os nós verdes terminam uma palavra; no
union-find, a raiz verde é o representante do grupo.

{{indice}}

---

{{assuntos}}

---

## Desafios do módulo

Problemas para resolver no papel e, quando fizer sentido, num arquivo `.c` seu
usando os TADs do módulo. Eles misturam os assuntos.

**1. A geral e a binária.** A árvore geral A tem os filhos B, C e D, nesta
ordem; B tem os filhos E e F; D tem o filho G. Dê a pré-ordem e a pós-ordem da
árvore geral. Depois desenhe a versão primeiro filho / próximo irmão como árvore
binária (filho à esquerda, irmão à direita) e dê a em ordem e a altura dela.

<details><summary>Resposta</summary>

Pré-ordem: **A B E F C D G**. Pós-ordem: **E F B C G D A**. Na binária, A tem B
à esquerda; B tem E à esquerda e C à direita; E tem F à direita; C tem D à
direita; D tem G à esquerda. A em ordem da binária é **E F B C G D A**, igual à
pós-ordem da geral (o A288 mostra isso no código). A altura da geral é **2**; a
da binária é **4** (A, B, C, D, G), porque cada irmão vira um degrau.

</details>

**2. Rubro-negra ao contrário.** Insira 7, 6, 5, 4, 3, 2 e 1, nesta ordem, numa
LLRB vazia. Qual é a pré-ordem final? Quantos nós vermelhos sobram, quantas
rotações e quantas inversões de cor aconteceram?

<details><summary>Resposta</summary>

Pré-ordem **4 2 1 3 6 5 7**, todos pretos: a árvore 2-3 equivalente é perfeita,
com sete nós de uma chave. Foram **4 rotações** (todas à direita: dois vermelhos
seguidos à esquerda) e **4 inversões**. Altura 2, altura preta 3. Confira com
`rn_pre_ordem`, `rn_rotacoes` e `rn_inversoes`.

</details>

**3. Quantos nós cabem na altura preta?** Uma LLRB tem altura preta 3 (três nós
pretos da raiz até qualquer `NULL`). Qual é o menor e o maior número de nós que
ela pode ter?

<details><summary>Resposta</summary>

Pense na árvore 2-3 equivalente, com 3 níveis. No mínimo, todo nó tem uma
chave: 1 + 2 + 4 = **7** nós, todos pretos. No máximo, todo nó tem duas chaves e
três filhos: 1 + 3 + 9 = 13 nós 2-3, com 26 chaves. Na LLRB, são **26** nós: 13
pretos, cada um com um vermelho colado à esquerda. Em geral, com altura preta b,
a LLRB tem de 2^b - 1 a 3^b - 1 nós.

</details>

**4. Escrevendo a 2-3 em cores.** A árvore 2-3 tem a raiz `[20 40]` e os filhos
`[10]`, `[30]` e `[50 60]`. Escreva a LLRB equivalente em pré-ordem, com `*` nos
vermelhos. Que ordem de inserção produz exatamente essa árvore?

<details><summary>Resposta</summary>

Pré-ordem **40 20\* 10 30 60 50\***: cada nó de duas chaves vira a chave maior
preta com a menor vermelha à esquerda. A ordem 20, 40, 10, 30, 50, 60 produz essa
árvore (confira com o TAD). Repare que a LLRB nunca tem o vermelho à direita: o
`[50 60]` vira 60 com 50 pendurado à esquerda, e não 50 com 60 à direita.

</details>

**5. Limites da árvore B.** Numa árvore B com grau mínimo t = 3 (de 2 a 5 chaves
por nó, a raiz pode ter 1), qual é o maior e o menor número de chaves que cabe em
altura 2?

<details><summary>Resposta</summary>

Maior: todos os nós com 5 chaves e 6 filhos: 5 + 6 · 5 + 36 · 5 = **215**, ou
6³ - 1. Menor: a raiz com 1 chave e 2 filhos, e cada nó abaixo com 2 chaves e 3
filhos: 1 + 2 · 2 + 6 · 2 = **17**, ou 2 · t² - 1. Para buscar em qualquer
árvore B de altura 2, três nós são lidos, tenha ela 17 ou 215 chaves.

</details>

**6. A trie das palavras parecidas.** Quantos nós (contando a raiz) tem a trie com
"casa", "casaco", "caso", "cama" e "camelo"? Quantas palavras começam com
"cam", e qual é o maior prefixo comum a todas as cinco?

<details><summary>Resposta</summary>

**13 nós**: raiz, c, a; s, a (casa), c, o (casaco), o (caso); m, a (cama), e, l, o
(camelo). Com "cam" começam **2** (cama e camelo). O maior prefixo comum é
**"ca"**: no nó do `a`, o caminho se divide em `s` e `m`. Confira com `trie_nos`
e com o `prefixo_comum` do A294.

</details>

**7. O vetor pai no fim.** Num union-find de 10 elementos (TAD do 0148, união por
tamanho e compressão), faça, nesta ordem: une(0,1), une(2,3), une(4,5), une(6,7),
une(0,2), une(4,6), une(0,4), une(8,9), une(9,7). Qual é o vetor `pai` no fim?

<details><summary>Resposta</summary>

**pai = 0 0 0 2 0 4 0 0 0 8**. Até une(0,4), as raízes vão se pendurando (nos
empates, a raiz de a fica). Em une(9,7), `acha(7)` sobe 7, 6, 4, 0 e comprime: o
7 e o 6 passam a apontar direto para o 0. Depois, o grupo do 8 (tamanho 2) vai
para baixo do 0 (tamanho 8). O 3, o 5 e o 9 continuam a dois passos da raiz até
alguém perguntar por eles.

</details>

**8. Igualdades impossíveis.** Um sistema recebe restrições sobre variáveis:
x1 = x2, x3 = x4, x5 = x1, x2 = x3 e x4 ≠ x5. Dá para atender todas? Como um
union-find responde isso para mil restrições?

<details><summary>Resposta</summary>

**Não dá.** As quatro igualdades juntam x1, x2, x3, x4 e x5 num grupo só, e aí
x4 ≠ x5 é uma contradição. O método: primeiro faça une(a, b) para cada igualdade;
depois, para cada diferença, confira `uf_juntos(a, b)`: se der verdadeiro, é
impossível. Custo quase linear no número de restrições. A ordem importa: as
diferenças só podem ser conferidas depois de todas as igualdades.

</details>

**9. Qual estrutura?** Escolha entre trie, tabela hash, rubro-negra, árvore B e
union-find: (a) o campo de busca que completa nomes de cidade a cada letra; (b)
contar visitantes únicos do site pelo CPF; (c) o índice de uma tabela de 500
milhões de registros num banco de dados; (d) uma agenda em memória que recebe
compromissos o tempo todo e lista os próximos em ordem de horário; (e) saber se
duas pessoas estão ligadas por uma corrente de amizades que cresce a cada
minuto.

<details><summary>Resposta</summary>

(a) **trie**: o prefixo leva direto às cidades; (b) **hash**: só busca exata, a
mais rápida; (c) **árvore B**: poucos blocos lidos do disco por busca; (d)
**rubro-negra**: inserção em O(log n) no pior caso e percurso em ordem; (e)
**union-find**: cada amizade é um une, cada pergunta é um acha.

</details>

**10. A conta da memória.** Um dicionário de 100 mil palavras vira uma trie de
26 ponteiros com 250 mil nós. Quanta memória a trie ocupa? E as mesmas palavras
como strings, com média de 9 letras?

<details><summary>Resposta</summary>

Cada nó tem 216 bytes: 250 000 · 216 = 54 000 000 bytes, cerca de **54 MB**. As
strings ocupam 100 000 · (9 + 1) = 1 000 000 bytes, cerca de **1 MB**. A trie
gasta mais de 50 vezes mais, quase tudo em ponteiros `NULL`. É por isso que
tries de verdade usam nós menores: lista de filhos (a ideia do 0144), vetor só
das letras que existem ou árvore ternária de busca.

</details>

**11. A divisão em cascata.** Na árvore B do texto do 0146 (raiz `[40]`, nível
1 `[20] [70]`, folhas `[10] [25 30] [50 60] [80 85 90]`), insira 87, 95, 97 e
99, nesta ordem. Quantas divisões acontecem e como fica a árvore?

<details><summary>Resposta</summary>

O 87 divide a folha `[80 85 90]` (o 85 sobe para `[70 85]`) e entra em
`[87 90]`. O 95 vai para `[87 90 95]`. O 97 encontra essa folha cheia, que se
divide (o 90 sobe: `[70 85 90]`), e entra em `[95 97]`. O 99 encontra o nó
`[70 85 90]` cheio no caminho: ele se divide antes de descer (o 85 sobe para a
raiz, `[40 85]`), e o 99 termina em `[95 97 99]`. São **3 divisões**. Por nível:
`[40 85]`; `[20] [70] [90]`; `[10] [25 30] [50 60] [80] [87] [95 97 99]`. A
altura continua 2. Confira com `ab_insere` e `ab_mostra`.

</details>

## Questões no estilo da prova

Questões objetivas no formato da Prova de Conhecimentos do PPGI: uma
alternativa certa. As definições seguem o Cormen: rubro-negra **clássica**
(cor no nó, assunto 0177), árvore B pelo **grau mínimo** `t` (a raiz no
nível 0 quando o enunciado falar em altura da B) e união por posto com
compressão de caminho.

**1.** Considere as afirmações sobre árvores rubro-negras (Cormen):

I. Um nó vermelho nunca tem filho vermelho.\
II. Todos os nós da árvore têm a mesma altura negra.\
III. Com `n` nós internos, a altura é no máximo 2 · lg(n + 1).\
IV. Toda inserção exige pelo menos uma rotação, com certeza.

Estão corretas:

- (A) Apenas I.
- (B) Apenas I e III.
- (C) Apenas II e IV.
- (D) Apenas I, III e IV.
- (E) Apenas III e IV.

<details><summary>Gabarito</summary>

**B.** A I é uma das propriedades. A II confunde: é todo **caminho a partir de
um mesmo nó** que tem o mesmo número de nós pretos; a raiz tem altura negra
maior que a dos filhos pretos. A III é o teorema do Cormen. Na IV, "com
certeza" derruba: o nó novo entra vermelho, e se o pai é preto nada muda; se
o tio é vermelho, só há recoloração. Veja 0145 e 0177.

</details>

**2.** Pelo Cormen, a altura negra `bh(x)` não conta o próprio `x` e conta a
folha `NIL`. Qual o menor número de nós internos de uma subárvore rubro-negra
cuja raiz tem `bh = 5`?

- (A) 5
- (B) 10
- (C) 32
- (D) 31
- (E) 63

<details><summary>Gabarito</summary>

**D.** A subárvore de um nó `x` tem pelo menos 2^bh(x) - 1 nós internos, e o
mínimo vem da árvore toda preta e perfeita: 2^5 - 1 = 31. O 32 erra por um, e
o 63 usa `bh = 6`. É esse limite que leva à altura de até 2 lg(n + 1): pelo
menos metade dos nós de um caminho é preta. Veja 0145 e 0177.

</details>

**3.** Insere-se, nesta ordem, as chaves `15 8 23 4 42 16 31 12 27 19` numa
árvore B de grau mínimo `t = 2` (cada nó guarda de 1 a 3 chaves), pelo
algoritmo do Cormen, que divide na descida todo nó cheio que encontra. Depois
das dez inserções, quais são a raiz, o número de folhas e o número de divisões
de nó que aconteceram?

- (A) raiz `15 23`; 3 folhas; 2 divisões
- (B) raiz `15 23`; 3 folhas; 3 divisões
- (C) raiz `15`; 2 folhas; 2 divisões
- (D) raiz `15 23`; 4 folhas; 3 divisões
- (E) raiz `15`; 3 folhas; 3 divisões

<details><summary>Gabarito</summary>

**A.** As três primeiras chaves enchem a raiz `8 15 23`. O 4 encontra a raiz
cheia: divisão 1, o 15 sobe e a raiz fica `15` com filhos `4 8` e `23`. A
seguir entram 42 e 16 (o filho `23` vira `16 23 42`). O 31 encontra esse
filho cheio: divisão 2, o 23 sobe, e a raiz fica `15 23`. O 12, o 27 e o 19
só entram nas folhas, que terminam em `4 8 12`, `16 19` e `27 31 42`. A altura
não passou de 1. Veja 0146.

</details>

**4.** Uma árvore B de grau mínimo `t = 5` tem altura 3 (a raiz no nível 0 e
as folhas no nível 3). Cada nó guarda no máximo `2t - 1 = 9` chaves. Qual o
número máximo de chaves da árvore?

- (A) 1 111
- (B) 999
- (C) 4 999
- (D) 10 000
- (E) 9 999

<details><summary>Gabarito</summary>

**E.** Cada nó cheio tem 9 chaves e 10 filhos. Os níveis 0 a 3 têm 1, 10, 100
e 1000 nós: 1 111 nós, e 1 111 · 9 = 9 999 chaves, que é (2t)^(h+1) - 1. A
(A) conta nós em vez de chaves e a (B), só o último nível de uma árvore de
altura 2. Veja 0146.

</details>

**5.** Os elementos de 0 a 9 começam cada um no seu conjunto, com posto 0. O
`UNION(a, b)` chama `LINK(FIND-SET(a), FIND-SET(b))`, e o `LINK(x, y)` faz:
se `x.rank > y.rank`, `y.p = x`; senão `x.p = y`, e se os postos eram iguais,
`y.rank` aumenta 1. Executam-se `UNION(1, 2)`, `UNION(3, 4)`, `UNION(1, 3)`,
`UNION(5, 6)`, `UNION(7, 8)`, `UNION(5, 7)`, `UNION(9, 5)` e `UNION(2, 9)`, e
depois `FIND-SET(1)` com compressão de caminho. Qual o representante, o posto
dele e quais nós mudam de pai nesse `FIND-SET`?

- (A) representante 4; mudam de pai o 1 e o 2
- (B) representante 8, posto 3; muda de pai só o 1
- (C) representante 8, posto 3; mudam de pai o 1 e o 2
- (D) representante 8, posto 2, pois a compressão reduz o posto; mudam de pai o 1 e o 2
- (E) representante 9; mudam de pai o 1, o 2 e o 4

<details><summary>Gabarito</summary>

**C.** Os conjuntos crescem assim: `2` sobre o 1 (posto 1), `4` sobre o 3,
depois `4` sobre o 2 (posto 2); `6` sobre o 5, `8` sobre o 7, depois `8`
sobre o 6 (posto 2); o 9, de posto 0, vai para baixo do 8. Na última união
as raízes 4 e 8 têm posto 2: o 4 vai para baixo do 8, que ganha posto 3. O
caminho do 1 é 1, 2, 4, 8: a compressão liga o 1 e o 2 direto ao 8, e o 4 já
estava. A compressão nunca altera o posto. Veja 0148.

</details>

**6.** As palavras `rio rios rima rimar pia pio piano rio`, nesta ordem
(a última é repetida), são inseridas numa trie de letras minúsculas, cada nó
com um vetor de 26 filhos. Sem contar a raiz, que não guarda letra, quantos
nós a trie tem?

- (A) 12
- (B) 14
- (C) 27
- (D) 13
- (E) 8

<details><summary>Gabarito</summary>

**D.** Cada nó é uma letra nova num prefixo novo. De `rio` saem `r`, `i`, `o`
(3); `rios` acrescenta o `s` (4); `rima` aproveita `ri` e cria `m`, `a` (6);
`rimar`, o `r` (7); `pia` cria `p`, `i`, `a` (10); `pio` só o `o` (11);
`piano` aproveita `pia` e cria `n`, `o` (13); o `rio` repetido não cria nada,
só reafirma a marca de fim. A (C) soma as letras de todas as palavras
distintas, como se não houvesse prefixo comum. Veja 0147.

</details>

**7.** Considere as afirmações sobre a trie:

I. A busca de uma chave de tamanho `m` custa O(m), com os filhos em vetor de
tamanho fixo, qualquer que seja o número de chaves guardadas.\
II. A trie sempre ocupa menos memória do que uma tabela hash com as mesmas
chaves.\
III. Percorrer a trie em pré-ordem, visitando os filhos em ordem alfabética e
anotando os nós que fecham uma palavra, entrega as palavras em ordem
lexicográfica.

Estão corretas:

- (A) Apenas I e III.
- (B) Apenas II.
- (C) Apenas I e II.
- (D) Apenas II e III.
- (E) I, II e III.

<details><summary>Gabarito</summary>

**A.** A I vale: a busca anda uma letra por nível. A II cai no "sempre": com
vetor de 26 ponteiros por nó, e chaves que quase não dividem prefixo, a trie
gasta muito mais que o hash. A III vale: um prefixo é visitado antes das
palavras que o estendem (`rio` antes de `rios`), e os irmãos saem em ordem
alfabética. Veja 0147.

</details>

**8.** O trecho abaixo monta e consulta uma trie de letras minúsculas. Em
`main`, `ins(r, "rio")` e depois `busca(r, "rio")` deveriam dar 1, mas o
resultado depende do que havia na memória. Qual é o defeito?

```c
typedef struct T {
    struct T *f[26];
    int fim;
} T;

T *novo(void) {
    T *t = malloc(sizeof *t);
    t->fim = 0;
    return t;
}

void ins(T *r, const char *s) {
    for (; *s; s++) {
        int c = *s - 'a';
        if (!r->f[c]) r->f[c] = novo();
        r = r->f[c];
    }
    r->fim = 1;
}
```

- (A) `ins` deveria receber `T **r`, pois altera a raiz.
- (B) `novo` devolve o endereço de uma variável local.
- (C) `malloc` não zera o vetor `f`: o teste `!r->f[c]` lê ponteiros indeterminados. Falta `calloc` (ou `memset`).
- (D) Falta um `free(r)` no fim de `ins`.
- (E) O índice `*s - 'a'` sai do vetor para a letra `z`.

<details><summary>Gabarito</summary>

**C.** O `malloc` devolve memória com lixo: só o `fim` é inicializado, e os 26
ponteiros de `f` ficam indeterminados. Então `!r->f[c]` pode ser falso para um
filho que nunca existiu, e o código anda por um endereço inválido. No
valgrind, aparece "Conditional jump depends on uninitialised value". A
correção é `calloc(1, sizeof(T))`, que deixa tudo em `NULL` e `0`. A raiz não
muda dentro de `ins` (A), o `malloc` devolve memória do heap (B), e `'z' - 'a'`
é 25, dentro do vetor (E). Veja 0147.

</details>

**9.** Uma árvore geral com 20 nós é guardada com a representação
filho-esquerdo, irmão-direito: cada nó tem dois ponteiros, o do primeiro
filho e o do próximo irmão. Quantos desses ponteiros valem `NULL`?

- (A) 19
- (B) 20
- (C) 39
- (D) 40
- (E) 21

<details><summary>Gabarito</summary>

**E.** São 2n = 40 ponteiros. Os não nulos apontam cada um para um nó
diferente, e todo nó, menos a raiz, é apontado exatamente uma vez: 19
ponteiros. Sobram 40 - 19 = 21 nulos, o que dá n + 1 para qualquer n. É a
mesma conta da árvore binária de n nós, que tem n + 1 subárvores vazias. Veja
0144.

</details>

**10.** Considere as afirmações sobre a árvore B (Cormen):

I. Todas as folhas ficam no mesmo nível.\
II. A altura só cresce quando a raiz está cheia e se divide.\
III. A remoção nunca diminui a altura da árvore.\
IV. Com `t = 3`, um nó interno que não é a raiz pode ter apenas 1 chave.

Estão corretas:

- (A) Apenas I.
- (B) Apenas I e II.
- (C) Apenas II e III.
- (D) Apenas I, II e IV.
- (E) Apenas III e IV.

<details><summary>Gabarito</summary>

**B.** A I é a razão de a busca ter sempre o mesmo custo no pior caso. A II
vale: dividir uma folha ou um nó interno só passa uma chave ao pai, e a
altura sobe apenas quando é a raiz que se divide. Na III, "nunca" derruba: se
a raiz fica sem chave depois de uma fusão dos dois únicos filhos, o filho
vira a raiz e a altura diminui. Na IV, um nó que não é raiz tem de 2 a 5
chaves para `t = 3`. Veja 0146.

</details>

## Para ler mais

- CORMEN, T. H.; LEISERSON, C. E.; RIVEST, R. L.; STEIN, C. *Algoritmos: teoria e prática*. 4. ed. Rio de Janeiro: GEN LTC, 2024. Caps. 10 (representação de árvores enraizadas), 13 (árvores vermelho-preto, as rubro-negras), 18 (árvores B) e 19 (estruturas de dados para conjuntos disjuntos).
- ZIVIANI, N. *Projeto de algoritmos: com implementações em Pascal e C*. 3. ed. rev. e ampl. São Paulo: Cengage Learning, 2010. Cap. 5 (pesquisa em memória primária: árvores binárias balanceadas e tries) e cap. 6 (pesquisa em memória secundária: árvores B e B*).
- SZWARCFITER, J. L.; MARKENZON, L. *Estruturas de dados e seus algoritmos*. 3. ed. Rio de Janeiro: LTC, 2010. Árvores gerais, árvores rubro-negras, árvores B, árvores digitais e o problema da união de conjuntos.
- SEDGEWICK, R.; WAYNE, K. *Algorithms*. 4. ed. Boston: Addison-Wesley, 2011. Seções 1.5 (union-find), 3.3 (árvores balanceadas: 2-3 e rubro-negras) e 5.2 (tries). Disponível em: <https://algs4.cs.princeton.edu/home/>.
- SEDGEWICK, R. *Left-leaning red-black trees*. Princeton: Princeton University, 2008. Disponível em: <https://sedgewick.io/wp-content/themes/sedgewick/papers/2008LLRB.pdf>.
- TENENBAUM, A. M.; LANGSAM, Y.; AUGENSTEIN, M. J. *Estruturas de dados usando C*. São Paulo: Makron Books, 1995. Cap. 5 (árvores gerais como árvores binárias) e cap. 7 (árvores B e tries).
- CELES, W.; RANGEL, J. L. *Apostila de estruturas de dados*. Rio de Janeiro: PUC-Rio, 2002. Capítulo sobre árvores genéricas (primeiro filho, próximo irmão).
- CORTÉS, M. I. *Estrutura de dados*. 3. ed. Fortaleza: EdUECE, 2015. Capítulo de busca avançada: árvore digital (trie).
- LINTZMAYER, C. N.; MOTA, G. O. *Análise de algoritmos e de estruturas de dados*. Santo André: UFABC, 2023. Notas de aula. Capítulo sobre union-find.
- BAYER, R.; McCREIGHT, E. Organization and maintenance of large ordered indexes. *Acta Informatica*, v. 1, n. 3, p. 173-189, 1972.
- TARJAN, R. E. Efficiency of a good but not linear set union algorithm. *Journal of the ACM*, v. 22, n. 2, p. 215-225, 1975.
- FREDKIN, E. Trie memory. *Communications of the ACM*, v. 3, n. 9, p. 490-499, 1960.
- KERNIGHAN, B. W.; RITCHIE, D. M. *C: a linguagem de programação padrão ANSI*. Rio de Janeiro: Campus, 1989. Seção 6.5: estruturas autorreferenciadas.
- CPPREFERENCE. *tolower*. Disponível em: <https://en.cppreference.com/w/c/string/byte/tolower>.
