# Módulo 15 · Tabelas hash

Até aqui, achar uma coisa sempre custou alguma procura: O(n) na lista, O(log
n) na busca binária e na árvore equilibrada. A tabela hash troca a procura
por uma **conta**: uma função transforma a chave num índice de vetor, e o
acesso ao vetor custa O(1). É a estrutura de dados mais usada na prática.

Dicionários, conjuntos e caches de quase todo software são tabelas hash por
baixo. No C não tem nada disso pronto, e é aí que você entende como elas
funcionam: a função
hash que mistura os bytes da chave, o que acontece quando duas chaves caem no
mesmo lugar, por que a tabela cresce quando enche e por que ela não guarda
ordem nenhuma.

O módulo tem duas famílias para tratar colisão: o **encadeamento**, que
pendura uma lista em cada balde, e o **endereçamento aberto**, que procura
outra posição dentro do próprio vetor. Termina com um contador de palavras
de verdade, que junta tabela, strings, `qsort` e memória dinâmica.

## O que você vai aprender

- o que é **endereçamento direto**, **função hash**, **colisão** e **fator de carga**
- escrever funções hash boas para inteiros (`k % m`, com `m` primo) e para texto (polinômio de base 31, em `unsigned`)
- montar uma tabela com **encadeamento**: inserir, buscar, remover e liberar cada corrente
- montar uma tabela com **endereçamento aberto** e sondagem linear, com a marca de **removida**
- medir o custo: comparações, sondagens, agrupamento e quando crescer a tabela (**rehash**)
- usar a tabela como contador e como conjunto, num programa completo

## Como estudar cada assunto

1. Leia o texto e olhe o **diagrama da ideia**: é o exemplo desenhado.
2. Leia o código. É o mesmo exemplo, com os mesmos valores.
3. Siga o **fluxograma** com o dedo: é o caminho que o programa faz.
4. Rode os exemplos. Mude um valor, quebre de propósito, rode de novo.
5. Faça os exercícios. ★☆☆ é aquecimento, ★★☆ pede raciocínio, ★★★ é desafio.
   As dicas vêm logo abaixo do enunciado: tente antes de ler.

No meio de cada assunto tem uma **Pergunta para você**. Responda antes de rodar.

## As cores e as formas

Caixa azul é dado entrando ou saindo, roxa é o programa fazendo alguma coisa,
amarela é pergunta. Verde é o caminho que o exemplo segue; cinza, o que ele não
usa; vermelho, erro ou colisão. Nas tabelas, cada balde é uma gaveta com o
índice à esquerda, e a corrente de nós sai dela para a direita.

<p align="center"><img src="../legenda.svg" alt="Legenda: formas e cores do fluxograma" width="916"></p>

## Antes de começar

Este módulo usa listas encadeadas (módulo 11) o tempo todo: inserir no
início, percorrer e remover guardando o anterior. Usa também `malloc`/`free`,
structs, ponteiro para função e `qsort`. Se algo disso estiver nebuloso,
revise antes.

As tabelas seguem o padrão TAD: `tabela.h`/`tabela.c` (encadeamento),
`aberta.h`/`aberta.c` (endereçamento aberto) e `palavras.h`/`palavras.c`
(o contador) ficam na pasta de cada assunto, e o `rodar` compila tudo junto:

```bash
~/LPEDC/rodar 15-hash/0106-encadeamento/A211.c
```

Os exercícios trazem a própria implementação dentro do arquivo, para você
escrever cada pedaço com as mãos.

{{indice}}

---

{{assuntos}}

---

## Desafios do módulo

Problemas extras, misturando os assuntos do módulo. Todos pedem código:
resolva num arquivo seu e rode com o `rodar`.

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

Dica: marque os baldes usados num vetor de flags. Com `m = 31`, o resto de
`h * 31` por 31 é sempre 0: sobra só `c % 31`, o código da **última letra**
(`'a'` dá 4, `'o'` dá 18). Use um `m` sem fator comum com a base: um primo
diferente de 31, como 37, 101 ou 1009.

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

Dica: o laço anda com `i = (i + 1) % M` e soma 1 a cada posição olhada; na
busca, limite a `M` voltas para não girar para sempre numa tabela cheia. O
29 (hash 1) tenta 1, 2, 3, 4 e 5; o 36 olha de 1 a 5 e para na 6, livre. Um
bloco de 5 ocupadas seguidas é o agrupamento primário em ação.

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

Dica: achar o k-ésimo nó de uma corrente custa k comparações, (1 + 2 + 3) +
1 + (1 + 2) = 10. Sem sucesso, a busca percorre a corrente inteira:
(3 + 1 + 0 + 2 + 0) / 5 = 1,2, que é exatamente o fator de carga α = 6/5.
Libere as correntes no fim.

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

Dica: escreva uma função `rodada(int marca, const char *nome)` que zera a
tabela, insere os três, remove o 15 com a marca dada e busca o 20. Com
`LIVRE`, a busca vê o buraco na 1 e conclui que o 20 não está, embora ele
esteja na 2. Uma inserção nova com hash 0 pode reaproveitar a posição
`REMOVIDA`, depois de conferir que a chave não existe adiante.

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

Dica: em C, o resto tem o sinal do dividendo, então `-37 % 10` é -7, um
índice fora do vetor. O conserto é `((k % m) + m) % m`, que soma `m` a um
resto negativo e não estraga os positivos. Outro caminho é converter antes
para `unsigned` (o valor muda, mas fica sempre no intervalo certo).

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

Dica: pare no primeiro par achado e imprima "nenhum par" se o laço terminar.
Cuidado com `50 - p` negativo (um preço maior que o vale): não procure. É
O(n) em média, contra O(n²) de testar todos os pares.

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

Dica: o intervalo é um percurso em ordem com poda: só desça à esquerda se
"Ana" for menor que o nó, e à direita se o nó for menor que "Bia". A tabela
espalha as chaves de propósito e não guarda ordem: para listar em ordem ou
por intervalo, ela teria que ordenar tudo a cada consulta. Para só perguntar
"existe?" (palavras reservadas de um compilador, cache de sessões), a hash
ganha com O(1) médio.

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

Dica: as cinco chaves têm `k % 7 == 3` e se amontoam a partir da posição 3
(o 52 dá a volta até a 0). Com `m = 17`, `k % 17` aponta para outras
posições, que na cópia estão vazias, e a busca desiste. Reinserir custa O(n),
mas como acontece só quando a tabela dobra, o custo diluído por inserção
continua O(1), igual ao vetor que cresce com `realloc` (módulo 07).

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

Dica: só conte os caracteres entre `'a'` e `'z'` (o espaço fica de fora) e
troque a mais comum só quando a contagem for **maior**, para o empate ficar
com a primeira letra. A "função hash" `c - 'a'` leva as 26 chaves possíveis
em 26 posições diferentes: zero colisões. É o endereçamento direto, uma
tabela hash perfeita, possível porque o universo de chaves é pequeno e
conhecido.

</details>

## Para ler mais

- CELES, W.; RANGEL, J. L. *Apostila de estruturas de dados*. Rio de Janeiro: PUC-Rio, Departamento de Informática, 2002. Cap. de tabelas de dispersão.
- CELES, W.; CERQUEIRA, R.; RANGEL, J. L. *Introdução a estruturas de dados: com técnicas de programação em C*. Rio de Janeiro: Elsevier, 2004.
- TENENBAUM, A. M.; LANGSAM, Y.; AUGENSTEIN, M. J. *Estruturas de dados usando C*. São Paulo: Makron Books, 1995. Cap. 7: busca (espalhamento).
- FEOFILOFF, P. *Algoritmos em linguagem C*. Rio de Janeiro: Elsevier, 2009.
- KERNIGHAN, B. W.; RITCHIE, D. M. *The C programming language*. 2. ed. Englewood Cliffs: Prentice Hall, 1988. Seção 6.6: table lookup.
- CORMEN, T. H. et al. *Algoritmos: teoria e prática*. 3. ed. Rio de Janeiro: Elsevier, 2012. Cap. 11: tabelas de espalhamento.
- KNUTH, D. E. *The art of computer programming*: volume 3: sorting and searching. 2. ed. Reading: Addison-Wesley, 1998. Seção 6.4: hashing.
- CPPREFERENCE. *isalpha*. Disponível em: <https://en.cppreference.com/w/c/string/byte/isalpha>.
