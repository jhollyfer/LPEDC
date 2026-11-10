# Módulo 15 · Tabelas hash

Achar um item custou até aqui O(n) na lista e O(log n) na busca binária e na
árvore equilibrada. A tabela hash troca a procura por uma **conta**: uma
função transforma a chave num índice de vetor, e o acesso custa O(1).
Dicionários, conjuntos e caches de quase todo software são tabelas hash.

O módulo cobre a função hash, a colisão (tratada por **encadeamento**, com uma
lista em cada balde, ou por **endereçamento aberto**, que procura outra
posição no vetor), o crescimento da tabela e a falta de ordem. Termina com um
contador de palavras.

## O que você vai aprender

- **função hash**, **colisão**, **fator de carga** e endereçamento direto
- hash para inteiros (`k % m`, `m` primo) e para texto (polinômio de base 31, em `unsigned`)
- **encadeamento**: inserir, buscar, remover e liberar cada corrente
- **endereçamento aberto**: sondagem linear e marca de **removida**
- custo (comparações, sondagens, agrupamento) e **rehash**
- a tabela como contador e como conjunto

## Antes de começar

Este módulo usa listas encadeadas (módulo 11), `malloc`/`free`, structs,
ponteiro para função e `qsort`. As tabelas seguem o padrão TAD: `tabela.h` e
`tabela.c` (encadeamento), `aberta.h` e `aberta.c` (endereçamento aberto),
`palavras.h` e `palavras.c` (contador) ficam na pasta de cada assunto, e o
comando compila tudo junto:

```bash
gcc ~/LPEDC/A211.c ~/LPEDC/0106-tabela.c -o ~/LPEDC/A211 && ~/LPEDC/A211
```

Nos desenhos, cada balde é uma gaveta com o índice à esquerda e a corrente de
nós à direita; vermelho marca colisão.

**Progressão.** Do módulo 11 vem a lista encadeada, que vira a corrente de
cada balde; dos módulos 13 e 14 vem o O(log n) da busca binária e da árvore,
contra o qual o O(1) esperado da tabela é comparado. O módulo 16 reaproveita
a lista de vizinhos nos grafos, e o 17 dá o rigor formal para provar custos.

{{indice}}

---

{{assuntos}}

---

## Desafios do módulo

Problemas extras que misturam os assuntos do módulo. Todos pedem código:
resolva num arquivo seu e compile com as flags de estudo.

**1. Base e tamanho brigando.** Um colega usou o hash polinomial de base 31
(`h = h * 31 + c`) com uma tabela de `m = 31` baldes, e quase todas as
palavras caíram em poucos baldes. Escreva `unsigned hash(const char *s,
unsigned m)` e uma função que imprime o balde de cada palavra de `{"casa",
"mesa", "bola", "pato", "gato", "rato", "sapo", "dado", "vaso", "copo",
"lua", "rua"}` e quantos baldes diferentes foram usados. Rode com `m = 31` e
com `m = 37`.

<details><summary>Resposta</summary>

```
m = 31: 4 4 4 18 18 18 18 18 18 18 4 4 -> 2 baldes usados
m = 37: 15 34 0 27 10 2 32 14 32 33 27 21 -> 10 baldes usados
```

</details>

**2. Sondagem linear contada.** Tabela com `m = 7`, `h(k) = k % 7`,
sondagem linear e `-1` marcando posição vazia. Escreva o `insere`, que
devolve quantas posições olhou, e o `busca`, que conta as sondagens até
achar a chave ou uma vazia. Insira 15, 22, 9, 4 e 29, mostrando onde cada um
ficou e as sondagens, o total, a tabela inteira e quantas sondagens custa
buscar o 36, que não está lá.

<details><summary>Resposta</summary>

```
15 -> [1], sondagens: 1
22 -> [2], sondagens: 2
9 -> [3], sondagens: 2
4 -> [4], sondagens: 1
29 -> [5], sondagens: 5
total: 11
[0] -
[1] 15
[2] 22
[3] 9
[4] 4
[5] 29
[6] -
busca 36: nao esta com 6 sondagens
```

</details>

**3. Média de comparações.** Monte uma tabela com encadeamento de 5 baldes
(`h(k) = k % 5`, inserindo no fim de cada corrente) com as chaves 0, 5, 10,
1, 3 e 8, o que dá correntes de 3, 1, 0, 2 e 0 nós. Escreva uma busca que
conta as comparações. Mostre os baldes, a média de comparações para buscar
cada uma das 6 chaves que estão lá e a média para buscar 100, 101, 102, 103
e 104 (uma chave ausente em cada balde).

<details><summary>Resposta</summary>

```
[0] 0 5 10
[1] 1
[2]
[3] 3 8
[4]
com sucesso: 10 comparacoes / 6 = 1.67
sem sucesso: 6 comparacoes / 5 = 1.20
```

</details>

**4. A remoção que quebra tudo.** Tabela aberta com `m = 5`,
`h(k) = k % 5` e um vetor de estados (`LIVRE`, `OCUPADA`, `REMOVIDA`, com
`enum`). Entram 10, 15 e 20 (vão para 0, 1 e 2) e o 15 sai. Escreva uma
busca que para numa posição `LIVRE`, pula as `REMOVIDA` e conta as
sondagens. Faça duas rodadas: na primeira, a remoção marca a posição do 15
como `LIVRE`; na segunda, como `REMOVIDA`. Em cada uma, busque o 20.

<details><summary>Resposta</summary>

```
marcando livre: 20 nao encontrado (2 sondagens)
marcando removida: 20 na posicao 2 (3 sondagens)
```

</details>

**5. Hash de número negativo.** Escreva `int h_errado(int k)`, que devolve
`k % 10`, e `int h_certo(int k, int m)`, que sempre devolve um índice de 0 a
`m - 1`. Imprima os dois para os saldos -37, 42, -10 e -5.

<details><summary>Resposta</summary>

```
 -37: errado  -7, certo 3
  42: errado   2, certo 2
 -10: errado   0, certo 0
  -5: errado  -5, certo 5
```

</details>

**6. Dois preços que fecham a conta.** Você tem um vale de R$ 50 e os
preços 12, 31, 7, 19 e 43. Escreva um programa que ache um par que soma
exatamente 50 numa passada só, usando uma tabela hash como conjunto
(endereçamento aberto com `m = 11`, funções `insere` e `contem`): para cada
preço `p`, pergunte se `50 - p` já está no conjunto; se não, guarde `p`.
Imprima cada passo.

<details><summary>Resposta</summary>

```
12: 38 nao esta, guarda 12
31: 19 nao esta, guarda 31
7: 43 nao esta, guarda 7
19: 31 ja esta -> par 31 + 19
```

</details>

**7. Hash ou árvore?** A agenda precisa listar os contatos em ordem
alfabética e achar "todos entre Ana e Bia". Insira `{"Caio", "Ana", "Bruno",
"Bia", "Davi", "Alice", "Beto"}` numa tabela hash com encadeamento (`m = 7`,
hash polinomial de base 31, inserindo no início da corrente) e numa árvore
binária de busca. Imprima a tabela balde a balde, a árvore em ordem e, só
com a árvore, os nomes entre "Ana" e "Bia" (inclusive).

<details><summary>Resposta</summary>

```
hash (balde a balde): Beto Caio Alice Davi Ana Bia Bruno
arvore (em ordem): Alice Ana Beto Bia Bruno Caio Davi
entre Ana e Bia: Ana Beto Bia
```

</details>

**8. Crescer sem copiar.** Uma tabela aberta com `m = 7` (sondagem linear,
`h(k) = k % m`) tem as chaves 10, 24, 31, 45 e 52 e vai crescer para
`m = 17`. Escreva `insere` e `busca` que recebem o vetor e o `m`. Mostre a
tabela velha; depois copie o vetor velho para o começo de um novo de 17
posições, posição por posição, e busque as 5 chaves; por fim, monte outra
tabela de 17 **reinserindo** cada chave e busque de novo. Marque com `(?)` as
chaves não encontradas.

<details><summary>Resposta</summary>

```
velha (m = 7): 52 - - 10 24 31 45
copiando posicao por posicao: 10(?) 24(?) 31(?) 45(?) 52(?) -> acha 0 de 5
reinserindo: 10 24 31 45 52 -> acha 5 de 5
```

</details>

**9. A letra mais comum, sem colisão.** Conte quantas vezes cada letra de
"a" a "z" aparece no texto `"a arara azul voa sobre a casa da vovo"` usando
só um `int conta[26]` com `conta[c - 'a']++`. Imprima as letras que
aparecem, com a contagem, e a mais comum.

<details><summary>Resposta</summary>

```
a: 10
b: 1
c: 1
d: 1
e: 1
l: 1
o: 4
r: 3
s: 2
u: 1
v: 3
z: 1
mais comum: a (10 vezes)
```

</details>

## Questões de provas do PPGI

Questões reais das provas de conhecimento do PPGI/UFAM, na íntegra e com o gabarito oficial. Resolva no papel, em 3 minutos por questão, e só depois abra o gabarito.

**Edital 032/2016 · Questão 09**

Considere as afirmações sobre um hash por encadeamento:

I) Suas colisões secundárias podem prejudicar seu desempenho\
II) Não funciona com número de chaves maior que o tamanho da tabela hash\
III) O número médio de operações esperado para realizar uma inserção é constante quando computado em função do tamanho da tabela se o hash for bem projetado\

Sobre as afirmações, sabe-se que:

- a) Todas são verdadeiras
- b) Todas são falsas
- c) Apenas I e III são verdadeiras
- d) Apenas III é verdadeira
- e) Apenas I e II são verdadeiras

<details><summary>Gabarito</summary>

**D.** I é falsa (colisão secundária é do endereçamento aberto), II é falsa (encadeamento aceita mais chaves que a tabela), III é verdadeira. Assunto 0105.

</details>

**Edital 053/2016 · Questão 10**

Considere as afirmações sobre um hash linear (sem encadeamento):

I) É obrigatório o uso de várias funções de hash\
II) Não funciona com número de chaves maior que o tamanho da tabela hash\
III) Quando acontece uma colisão, o valor a ser inserido é colocado no local no lugar do já existente.\

Sobre as afirmações, sabe-se que:

- a) Todas são verdadeiras
- b) Todas são falsas
- c) Apenas I e III são verdadeiras
- d) Apenas II é verdadeira
- e) Apenas I e II são verdadeiras

<details><summary>Gabarito</summary>

**D.** I falsa, II verdadeira (endereçamento aberto não passa de M chaves), III falsa (vai para a próxima posição livre). Assunto 0107.

</details>

**Edital 053/2016 · Questão 12**

Considere as afirmações sobre hash linear e hash encadeado

I) Hash encadeado funciona melhor em disco, pois as chaves sempre ficam próximas uma das outras, facilitando a varredura.\
II) Para uma tabela hash de tamanho M, tanto o hash linear quanto o hash encadeado podem receber uma quantidade de chaves C, onde C > M.\
III) Quanto acontece uma colisão no hash encadeado, a chave é inserida na posição livre mais próxima da chave original.\

Sobre as afirmações, sabe-se que:

- a) Todas são verdadeiras
- b) Todas são falsas
- c) Apenas I e III são verdadeiras
- d) Apenas II é verdadeira
- e) Apenas I e II são verdadeiras

<details><summary>Gabarito</summary>

**B.** I falsa (disco), II falsa (o linear não aceita C>M), III falsa (colisão no encadeado entra na lista). Assunto 0106.

</details>

**Edital 024/2017 · Questão 07**

Considere as seguintes afirmações:

I. Hash por encadeamento nunca apresenta colisões secundárias\
II. Hash por encadeamento jamais permite que o número de comparações entre chaves em uma operação de busca passe de log n, onde n é o número de chaves inseridas no hash.\
III. Hash por encadeamento realiza sempre menos comparações entre chaves do que qualquer hash por endereçamento aberto.\

Marque a alternativa CORRETA:

- a) Apenas a afirmação I é verdadeira
- b) Apenas a afirmação II é verdadeira
- c) Apenas a afirmação III é verdadeira
- d) Apenas as afirmações II e III são verdadeiras
- e) Nenhuma das alternativas anteriores está correta

<details><summary>Gabarito</summary>

**A.** colisão secundária é de endereçamento aberto, então I é verdadeira; II e III falsas (pior caso é n, e aberto pode ganhar do encadeado) Assunto 0106.

</details>

**Edital 024/2017 · Questão 14**

Considere as afirmações sobre um hash linear (sem encadeamento):

I. No evento de uma colisão, o valor a ser inserido é sempre colocado no início do array;\
II. A busca pela chave é realizada utilizando busca binária (mais eficiente)\
III. É obrigatório o uso de funções diferentes para inserção e remoção de chaves\
IV. É projetado para funcionar com arrays de tamanho previamente definido.\

Sobre as afirmações, sabe-se que:

- a) Todas são verdadeiras
- b) Todas são falsas
- c) Apenas II e IV são verdadeiras
- d) Apenas IV é verdadeira
- e) Apenas I e II são verdadeiras

<details><summary>Gabarito</summary>

**D.** só IV: tamanho fixo; sondagem linear não usa busca binária nem coloca no início Assunto 0107.

</details>

**Edital 024/2017 · Questão 15**

Considere as afirmações sobre hash linear vs hash encadeado

I. Para uma tabela hash de tamanho M, tanto o hash linear quanto o hash encadeado podem receber uma quantidade de chaves C, onde C > M.\
II. Quanto acontece uma colisão no hash encadeado, a chave é inserida na posição livre mais próxima da chave original.\
III. Hash linear funciona melhor em disco, pois as chaves obrigatoriamente ficam em espaços separados de memória, facilitando a varredura.\
IV. O uso de uma segunda função de hash (no hash encadeado), garante um melhor espalhamento das chaves pela tabela hash\

Sobre as afirmações, sabe-se que:

- a) Todas são verdadeiras
- b) Todas são falsas
- c) Apenas I e III são verdadeiras
- d) Apenas III é verdadeira
- e) Apenas I e II são verdadeiras

<details><summary>Gabarito</summary>

**B.** I falsa (linear não passa de M), II descreve o linear, III sem sentido, IV é dispersão dupla, não encadeamento Assunto 0106.

</details>

**Edital 055/2017 · Questão 05**

Quando um algoritmo de hash produz um endereço para uma chave e esse endereço já está ocupado, isso é chamado de __________.

- A) Sinônimo
- B) Inicial
- C) Prospecção
- D) Colisão
- E) Overflow

<details><summary>Gabarito</summary>

**D.** endereço já ocupado é colisão Assunto 0105.

</details>

**Edital 055/2017 · Questão 06**

Considere uma tabela hash com resolução de colisões por encadeamento com as seguintes características:

- As chaves são as letras A,B,C,D,H,J,K,M,N,O,P,R,S,T,U;
- A tabela possui 11 posições, referenciadas pelos índices de 0 até 10;
- A função de hash é definida como hash(x)=posição(x) mod 11, onde x é a chave, e posição(x) é a posição da chave no alfabeto ABCDEFGHIJKLMNOPQRSTUVWXYZ, tal que posição("A") retorna 1 e posição("Z") retorna 26.

Analise as afirmativas sobre a tabela após seu preenchimento com as chaves listadas acima.

I. Nenhuma chave foi alocada à posição 6;\
II. A chave "K" foi alocada à posição zero;\
III. As chaves "B" e "N" colidiram na posição 3;\
IV. Apenas uma letra foi alocada à posição 9.\

Com base nessas afirmativas, marque a alternativa CORRETA:

- A) Apenas as afirmativas I e II estão corretas.
- B) Apenas as afirmativas I e IV estão corretas.
- C) Apenas as afirmativas I, II e IV estão corretas.
- D) Apenas as afirmativas II e III.
- E) Apenas as afirmativas II, III e IV estão corretas.

<details><summary>Gabarito</summary>

**C.** posições: K=0, N=3 (não B), T=9 sozinho, nada em 6; I, II e IV verdadeiras, III falsa Assunto 0106.

</details>

**Edital 055/2017 · Questão 15**

Considere as seguintes afirmações:

I. Hash por encadeamento pode apresentar colisões secundárias.\
II. Hash por encadeamento pode permitir que o número de comparações entre chaves em uma operação de busca passe de √n, onde n é o número de chaves inseridas no hash.\
III. Hash por endereçamento aberto realiza sempre menos comparações entre chaves do que qualquer hash por encadeamento.\

Marque a alternativa CORRETA:

- A) Apenas a afirmação I é verdadeira.
- B) Apenas a afirmação II é verdadeira.
- C) Apenas a afirmação III é verdadeira.
- D) Apenas as afirmações II e III são verdadeiras.
- E) Apenas as afirmações I e III são verdadeiras.

<details><summary>Gabarito</summary>

**B.** Assunto 0106.

</details>

**Edital 023/2018 · Questão 18**

Considere uma tabela de espalhamento (hash table) de comprimento igual a 11, na qual a técnica de resolução de colisões utilizada é a de encadeamento. Nessa tabela, as posições são numeradas (indexadas) com os valores 0, 1, 2, ..., 10, o mapeamento de chaves para posições usa a função hash definida por h(k) = k mod 11, onde k é o valor da chave, e mod é o operador de módulo, e os números 1, 5, 18, 20, 4, 12, 10, 34, 15, 28 e 17 foram as chaves inseridas, nessa ordem, nessa tabela de espalhamento que estava inicialmente vazia. Qual a quantidade de posições em que houve colisão durante as inserções das chaves?

- a) 0
- b) 1
- c) 2
- d) 3
- e) 4

<details><summary>Gabarito</summary>

**D.** Rodado em C: colidem as posições 1 (1, 12, 34), 4 (4, 15) e 6 (28, 17): três posições. Assunto 0105.

</details>

**Edital 061/2018 · Questão 01**

Considere um arquivo sequencial com 10.000 registros, cujas chaves identificadoras são números inteiros de até 8 dígitos. Para criar um índice tipo hashing para esse arquivo, contendo endereços de 0 até 11.999, a mais adequada definição para uma função de hashing f(x), onde x é uma chave e (a mod b) é o resto da divisão de a por b, seria:

- a) f = x mod 1000 + 12
- b) f = x mod 12000
- c) f = x / 10000
- d) f = x / 11999
- e) f = (x – 11999) /10000

<details><summary>Gabarito</summary>

**B.** `x mod 12000` cobre exatamente 0 a 11.999; a A só gera 1000 endereços. Assunto 0105.

</details>

**Edital 061/2018 · Questão 16**

Considere as seguintes afirmações:

I. Hash por encadeamento nunca apresenta colisões secundárias\
II. Hash por encadeamento jamais permite que o número de comparações entre chaves em uma operação de busca passe de log n, onde n é o número de chaves inseridas no hash.\
III. Hash por encadeamento realiza sempre menos comparações entre chaves do que qualquer hash por endereçamento aberto.\

Agora marque a alternativa CORRETA:

- a) Apenas a afirmação I é verdadeira
- b) Apenas a afirmação II é verdadeira
- c) Apenas a afirmação III é verdadeira
- d) Apenas as afirmações II e III são verdadeiras
- e) Nenhuma das alternativas anteriores está correta

<details><summary>Gabarito</summary>

**A.** Só a I é verdadeira (colisão secundária é conceito de endereçamento aberto); II e III são falsas. Assunto 0106.

</details>

**Edital 061/2018 · Questão 18**

Considere as afirmações sobre um hash por encadeamento:

I. Tem como desvantagem o fato de não ordenar as chaves inseridas\
II. O número médio de operações esperado para realizar uma busca é constante se o hash for bem projetado\
III. Mesmo quando bem implementado, ocupa mais espaço extra do que uma árvore B em memória.\

Sobre as afirmações, sabe-se que:

- a) Todas as afirmações são verdadeiras
- b) Todas as afirmações são falsas
- c) Apenas as afirmações I e III são verdadeiras
- d) Apenas a afirmação III é verdadeira
- e) Apenas as afirmações I e II são verdadeiras

<details><summary>Gabarito</summary>

**E.** I e II são verdadeiras; a III é duvidosa. Ver observação. Assunto 0106.

</details>

**Edital 060/2019 · Questão 01**

Suponha que você tenha a seguinte tabela hash implementada utilizando endereçamento aberto com sondagem linear (linear probing). A função hash que você está usando é uma função modular, h(x) = x MOD 9.

![Questão 01 - tabela hash](_fontes/provas-figuras/2019-060/q01-tabela-hash.png)

Qual das ordens abaixo pode ser a ordem em que os elementos foram adicionados à hash? Assuma que a hash nunca tenha sido redimensionada e que nenhum elemento tenha sido excluído ainda.

- a) 9, 14, 4, 18, 21, 3, 12
- b) 12, 3, 14, 18, 4, 9, 21
- c) 12, 14, 3, 9, 4, 18, 21
- d) 9, 12, 14, 3, 21, 18, 4
- e) 18, 9, 12, 3, 14, 4, 21

<details><summary>Gabarito</summary>

**C.** Rodado em C: só a ordem de C gera 9 18 _ 12 3 14 4 21 (as de b e e trocam 9 e 18). Assunto 0107.

</details>

**Edital 060/2019 · Questão 06**

Marque a alternativa CORRETA. Sobre um hash com encadeamento e com tabela de tamanho 100, pode-se dizer que:

- a) Para casos em que se insere um número n muito grande de chaves, o tempo no caso médio de busca será O(1)
- b) Para casos em que se insere um número n muito grande de chaves, o tempo de busca no pior caso será O(1)
- c) Para casos em que se insere um número n muito grande de chaves, o tempo no caso médio de busca será O(n)
- d) Para casos em que se insere um número n muito grande de chaves, o tempo de busca no pior caso será O(log n)
- e) Nenhuma das alternativas anteriores

<details><summary>Gabarito</summary>

**C.** Com m fixo, a cadeia média tem n/100 nós, que é O(n). Assunto 0106.

</details>

## Para ler mais

- CORMEN, T. H.; LEISERSON, C. E.; RIVEST, R. L.; STEIN, C. *Algoritmos: teoria e prática*. 4. ed. Rio de Janeiro: GEN LTC, 2024. Cap. 11: tabelas de espalhamento.
- ZIVIANI, N. *Projeto de algoritmos: com implementações em Pascal e C*. 3. ed. São Paulo: Cengage Learning, 2010. Cap. 5: pesquisa em memória primária (transformação de chave).
- CELES, W.; RANGEL, J. L. *Apostila de estruturas de dados*. Rio de Janeiro: PUC-Rio, Departamento de Informática, 2002. Cap. de tabelas de dispersão.
- CELES, W.; CERQUEIRA, R.; RANGEL, J. L. *Introdução a estruturas de dados: com técnicas de programação em C*. 2. ed. Rio de Janeiro: Elsevier, 2016.
- TENENBAUM, A. M.; LANGSAM, Y.; AUGENSTEIN, M. J. *Estruturas de dados usando C*. São Paulo: Makron Books, 1995. Cap. 7: busca (espalhamento).
- FEOFILOFF, P. *Algoritmos em linguagem C*. Rio de Janeiro: Elsevier, 2009.
- KERNIGHAN, B. W.; RITCHIE, D. M. *The C programming language*. 2. ed. Englewood Cliffs: Prentice Hall, 1988. Seção 6.6: table lookup.
- KNUTH, D. E. *The art of computer programming*: volume 3: sorting and searching. 2. ed. Reading: Addison-Wesley, 1998. Seção 6.4: hashing.
- CPPREFERENCE. *isalpha*. Disponível em: <https://en.cppreference.com/w/c/string/byte/isalpha>.
