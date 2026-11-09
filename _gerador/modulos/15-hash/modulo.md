# Módulo 15 · Tabelas hash

Até aqui, achar uma coisa sempre custou alguma procura: O(n) na lista, O(log
n) na busca binária e na árvore equilibrada. A tabela hash troca a procura
por uma **conta**: uma função transforma a chave num índice de vetor, e o
acesso ao vetor custa O(1). É a estrutura de dados mais usada na prática.

Dicionários, conjuntos e caches de quase todo software são tabelas hash por
baixo. O C não traz nada disso pronto, e por isso você vai ver como elas
funcionam: a função hash que mistura os bytes da chave, o que acontece quando
duas chaves caem no mesmo lugar, por que a tabela cresce quando enche e por
que ela não guarda ordem nenhuma.

O módulo tem duas famílias para tratar colisão: o **encadeamento**, que
pendura uma lista em cada balde, e o **endereçamento aberto**, que procura
outra posição dentro do próprio vetor. Termina com um contador de palavras
que junta tabela, strings, `qsort` e memória dinâmica.

## O que você vai aprender

- o que é **endereçamento direto**, **função hash**, **colisão** e **fator de carga**
- escrever funções hash boas para inteiros (`k % m`, com `m` primo) e para texto (polinômio de base 31, em `unsigned`)
- montar uma tabela com **encadeamento**: inserir, buscar, remover e liberar cada corrente
- montar uma tabela com **endereçamento aberto** e sondagem linear, com a marca de **removida**
- medir o custo: comparações, sondagens, agrupamento e quando crescer a tabela (**rehash**)
- usar a tabela como contador e como conjunto, num programa completo

## Antes de começar

Este módulo usa listas encadeadas (módulo 11) o tempo todo: inserir no
início, percorrer e remover guardando o anterior. Usa também `malloc`/`free`,
structs, ponteiro para função e `qsort`. Se algo disso estiver nebuloso,
revise antes.

Nos desenhos das tabelas, cada balde é uma gaveta com o índice à esquerda, e
a corrente de nós sai dela para a direita; vermelho marca colisão.

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
(3 + 1 + 0 + 2 + 0) / 5 = 1,2, o próprio fator de carga α = 6/5.
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

## Questões no estilo da prova

Questões objetivas no formato da prova do mestrado. Nas de endereçamento
aberto, desenhe a tabela e preencha posição por posição; a notação é a do
Cormen: `h(k, i)` é a posição da tentativa `i`, começando em `i = 0`.

**1.** Uma tabela com encadeamento tem `m = 7` baldes, `h(k) = k mod 7`, e cada
chave nova entra no **início** da lista do seu balde. São inseridas
`15 22 8 29 3 36 10`, nesta ordem. Qual é a lista do balde 1, da cabeça ao
fim?

- (A) `15 22 8 29 36`
- (B) `8 15 22 29 36`
- (C) `36 29 22 15 8`
- (D) `36 29 8 22 15`
- (E) `36 29 8 22 15 3 10`

<details><summary>Gabarito</summary>

**D.** 15, 22, 8, 29 e 36 dão resto 1; o 3 e o 10 vão para o balde 3. Como
cada nova entra na cabeça, a lista fica na ordem inversa da chegada. Cinco das
sete chaves no mesmo balde: as chaves têm um padrão (diferença múltipla de 7)
que o método da divisão não desfaz. Veja 0106.

</details>

**2.** Uma tabela com `m = 11` posições usa sondagem linear,
`h(k, i) = (k mod 11 + i) mod 11`. Inserem-se `20 31 9 42 14 53 25`, nesta
ordem. Em que posições ficam o 53 e o 25?

- (A) 9 e 3
- (B) 2 e 4
- (C) 2 e 3
- (D) 1 e 4
- (E) 4 e 5

<details><summary>Gabarito</summary>

**B.** 20 vai para 9; 31 (casa 9) para 10; 9 (casa 9) dá a volta até 0; 42
(casa 9) até 1; 14 para 3; 53 (casa 9) tenta 9, 10, 0, 1 e para no 2, com 5
sondagens; 25 (casa 3) para no 4. O bloco 9, 10, 0, 1, 2, que cresce a cada
inserção, é o agrupamento primário. Veja 0107.

</details>

**3.** Uma tabela com `m = 8` posições usa sondagem quadrática
`h(k, i) = (k mod 8 + (i + i²)/2) mod 8` (o caso c₁ = c₂ = 1/2 do Cormen).
Inserem-se `17 25 9 33 41`, todas com `k mod 8 = 1`. Em que posição fica o 41?

- (A) 3
- (B) 5
- (C) 6
- (D) 0
- (E) nenhuma: a sondagem não encontra posição livre

<details><summary>Gabarito</summary>

**A.** Os deslocamentos são 0, 1, 3, 6, 10, ...: o 17 fica em 1, o 25 em 2, o
9 em 4 e o 33 em 7. O 41 tenta 1, 2, 4, 7 e, com `i = 4`, `(1 + 10) mod 8 =
3`. Com `m` potência de 2 e esses coeficientes, a sequência visita todas as
posições. Veja 0107 e o assunto 0179, que aprofunda a sondagem quadrática.

</details>

**4.** Uma tabela com `m = 13` posições usa dispersão dupla
`h(k, i) = (h₁(k) + i · h₂(k)) mod 13`, com `h₁(k) = k mod 13` e
`h₂(k) = 1 + (k mod 11)`. Inserem-se `18 44 57 31`, nesta ordem. Em que
posições ficam o 57 e o 31?

- (A) 7 e 8
- (B) 6 e 7
- (C) 8 e 3
- (D) 5 e 5
- (E) 8 e 2

<details><summary>Gabarito</summary>

**E.** As quatro chaves têm `h₁ = 5`. O 18 fica em 5. O 44 tem `h₂ = 1` e vai
para 6. O 57 tem `h₂ = 3`: tenta 5 e para em 8. O 31 tem `h₂ = 10`: tenta 5 e
para em `15 mod 13 = 2`. A (A) é o que a sondagem linear faria. Cada chave anda
com o seu próprio passo, e por isso a dispersão dupla não forma blocos. Veja o
assunto 0179.

</details>

**5.** Pelo método da multiplicação, `h(k) = ⌊m · (k · A mod 1)⌋`. Com
`m = 8` e `A = 157/256 ≈ 0,613`, quanto vale `h(21)`?

- (A) 5
- (B) 1
- (C) 7
- (D) 12
- (E) 0

<details><summary>Gabarito</summary>

**C.** `21 · 157 = 3297 = 12 · 256 + 225`, então `21 · A = 12,879...` e a
parte fracionária é `225/256 ≈ 0,879`. Vezes 8 dá 7,03, e o piso é 7. Em C, com
`w = 8` bits, é o *multiply-shift* da 4. ed. do Cormen: `((21 * 157) % 256) >>
5` também dá 7. A (A) é o `21 mod 8` da divisão. Veja 0105 e o assunto 0178,
que aprofunda o método da multiplicação.

</details>

**6.** Uma tabela com endereçamento aberto tem `m = 1000` posições e
`n = 800` chaves. Supondo hashing uniforme, qual é o limite do Cormen para o
número esperado de sondagens numa busca **sem sucesso**?

- (A) 0,8
- (B) 5
- (C) 1,25
- (D) cerca de 2,01
- (E) 800

<details><summary>Gabarito</summary>

**B.** O fator de carga é α = n/m = 0,8, e o limite é 1/(1 − α) = 1/0,2 = 5.
A (D) é o limite da busca **com** sucesso, (1/α) ln(1/(1 − α)) ≈ 2,01. Com
encadeamento, a mesma carga daria Θ(1 + α). Veja 0105, 0106 e 0107.

</details>

**7.** Pelo método da divisão, `h(k) = k mod m`, para cerca de mil chaves
inteiras. Qual valor de `m` é a melhor escolha?

- (A) 256
- (B) 1000
- (C) 389
- (D) 512
- (E) 1024

<details><summary>Gabarito</summary>

**C.** O Cormen recomenda um primo longe de potências de 2. Com `m = 2^p`
(256, 512, 1024), `k mod m` são só os `p` bits menos significativos da chave;
com `m = 1000`, só os três últimos dígitos decimais. O 389 é primo e fica longe
de 256 e de 512. O fator de carga fica perto de 2,6, o que o encadeamento
aguenta bem. Veja 0105 e 0108.

</details>

**8.** Sobre a **remoção** numa tabela com endereçamento aberto e sondagem
linear, qual afirmação é correta?

- (A) Marcar a posição como livre pode fazer uma busca parar cedo e não achar uma chave que está na tabela; por isso se usa uma marca de removida.
- (B) Basta marcar a posição como livre, porque a busca sempre percorre a tabela inteira.
- (C) A remoção é impossível: a única saída é reconstruir a tabela.
- (D) A remoção custa O(1) e nunca afeta as buscas seguintes.
- (E) As marcas de removida tornam as buscas sem sucesso mais curtas.

<details><summary>Gabarito</summary>

**A.** A busca para na primeira posição livre. Se uma chave tinha pulado a
posição removida, a busca por ela pararia ali. A marca `DELETED` (lápide) deixa
a busca passar e a inserção reaproveitar a posição. O preço: com muitas
lápides, as buscas sem sucesso ficam **longas** (por isso (E) é falsa). Veja
0107 (exemplo A214).

</details>

**9.** Uma tabela com encadeamento tem `m = 5`, `h(k) = k mod 5`, e insere
cada chave no início da lista do balde. São inseridas `12 7 22 3 17 8`.
Quantas chaves são comparadas na busca pelo 12?

- (A) 1
- (B) 2
- (C) 3
- (D) 6
- (E) 4

<details><summary>Gabarito</summary>

**E.** 12, 7, 22 e 17 caem no balde 2, que fica `17 22 7 12`; o 3 e o 8 vão
para o balde 3. A busca vai direto ao balde 2 e compara com 17, 22, 7 e 12.
O 12, primeiro a chegar, é o último da lista. Veja 0106.

</details>

**10.** Sobre as sondagens do endereçamento aberto, qual afirmação é correta?

- (A) A sondagem linear evita o agrupamento primário.
- (B) A sondagem quadrática evita o agrupamento secundário.
- (C) A sondagem linear gera Θ(m²) sequências de sondagem diferentes.
- (D) A dispersão dupla gera Θ(m²) sequências diferentes e evita os agrupamentos primário e secundário.
- (E) O encadeamento sofre de agrupamento primário.

<details><summary>Gabarito</summary>

**D.** Na linear e na quadrática, a primeira posição decide a sequência
inteira: só há `m` sequências. A linear forma blocos (agrupamento primário); a
quadrática não, mas chaves com a mesma casa seguem o mesmo caminho
(agrupamento secundário). Na dispersão dupla, cada par `(h₁(k), h₂(k))` dá uma
sequência. O encadeamento não sonda nada. Veja 0107 e o assunto 0179.

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
