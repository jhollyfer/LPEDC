<!-- Gerado por _gerador a partir dos arquivos P????.c desta pasta. -->

# Lista prática · Módulo 23 · Grafos: estrutura e caminhos

30 exercícios de codificar que treinam o módulo inteiro, misturando os assuntos, no ritmo da prova do PPGI (veja [PPGI.md](../../PPGI.md)). Cada arquivo `P????.c` desta pasta é um exercício: a resposta vai dentro dele, embaixo de `// Escreva sua resposta abaixo:`. Uma resolução de cada um está em `_respostas/23-grafos-avancados/lista/`. Só olhe depois de tentar.

[Voltar ao módulo](../README.md)

## ★☆☆ Aquecimento

**Exercício P2301** · ★☆☆ · Grupos do condomínio

No condomínio, nove moradores (índices 0 a 8) estão em grupos de conversa:
Ana, Bia, Caio, Duda, Edu, Fabi, Gil, Hugo e Iara. As amizades, de mão
dupla, são:


```text
Ana-Caio, Caio-Gil, Bia-Duda, Duda-Hugo, Edu-Fabi
```


Escreva o programa do zero. Uma DFS dá a cada morador o número do seu
componente (grupo[u], começando em 1, na ordem do primeiro morador de
cada grupo). Mostre os grupos e depois responda, em O(1) cada, se estes
pares estão no mesmo grupo: Ana e Gil, Bia e Edu, Hugo e Bia, Iara e Ana.


```text
Saída esperada:
Grupo 1: Ana Caio Gil
Grupo 2: Bia Duda Hugo
Grupo 3: Edu Fabi
Grupo 4: Iara
Ana e Gil: mesmo grupo
Bia e Edu: grupos diferentes
Hugo e Bia: mesmo grupo
Iara e Ana: grupos diferentes
```

**Dicas:**

1. Guarde as amizades numa matriz amigo[V][V], marcando os dois sentidos.
2. marca(u, g) pinta u com g e chama a si mesma para todo amigo de u
   ainda sem grupo. O main chama marca(u, ++g) para cada u com grupo 0.
3. Resposta esperada: 4 grupos (Iara fica sozinha); a consulta é só
   grupo[a] == grupo[b].

```bash
~/LPEDC/rodar 23-grafos-avancados/lista/P2301.c
```

---

**Exercício P2302** · ★☆☆ · O cano que fecha o circuito

Na vila, os canos de água (mão dupla) ligam o Poço e cinco casas
(índices 0 a 5: Poço, Ana, Beto, Cida, Davi, Elza):


```text
Poço-Ana, Ana-Beto, Beto-Cida, Cida-Davi, Ana-Davi, Davi-Elza
```


Num grafo NÃO dirigido não precisa de três cores: basta lembrar o pai de
cada vértice na DFS. Um vizinho já visitado que não é o pai fecha um
circuito. Escreva o programa do zero: mostre o cano que fecha o circuito
e o circuito inteiro, subindo de pai em pai. Depois a vila tira o cano
Ana-Davi; analise de novo. Examine os vizinhos em ordem de índice.


```text
Saída esperada:
Rede atual: o cano Davi-Ana fecha o circuito Ana - Beto - Cida - Davi - Ana
Rede nova: sem circuito
```

**Dicas:**

1. dfs(u) marca u e, para cada vizinho v: se não foi visto, pai[v] = u e
   desce; se foi visto e v != pai[u], achou (guarde ini = v e fim = u).
2. Para mostrar o circuito, suba de fim até ini por pai[] guardando num
   vetor e mostre ao contrário, terminando de novo em ini.
3. Resposta esperada: o cano Davi-Ana fecha Ana - Beto - Cida - Davi -
   Ana; sem o cano Ana-Davi, a rede vira árvore e não tem circuito.

```bash
~/LPEDC/rodar 23-grafos-avancados/lista/P2302.c
```

---

**Exercício P2303** · ★☆☆ · Referência circular na planilha

Na planilha do orçamento, a fórmula de uma célula usa o valor de outras
(seta a -> b: a fórmula de a usa b). Na planilha de maio:


```text
A1 -> B1, B1 -> C1, C1 -> B2, B2 -> D1, D1 -> B1, A2 -> C2
```


O programa abaixo já tem a DFS de três cores pela metade. Complete a
função visita(u): além de achar a seta que chega num CINZA, ela guarda
em pai[] quem descobriu cada célula e, ao achar o ciclo, guarda ini (a
célula cinza) e fim (quem apontou para ela). A função confere já usa
ini, fim e pai[] para mostrar o ciclo.


```text
Saída esperada:
Planilha de maio: referência circular B1 -> C1 -> B2 -> D1 -> B1
Planilha de junho: sem referência circular
```

**Dicas:**

1. Pinte u de CINZA ao entrar e de PRETO ao terminar o laço dos vizinhos.
2. Vizinho BRANCO: pai[v] = u e desce; se a descida achou, devolva true.
   Vizinho CINZA: ini = v, fim = u, devolva true. PRETO: ignore.
3. Resposta esperada: B1 -> C1 -> B2 -> D1 -> B1 em maio; em junho, sem
   a seta D1 -> B1, nenhum ciclo.

```bash
~/LPEDC/rodar 23-grafos-avancados/lista/P2303.c
```

---

**Exercício P2304** · ★☆☆ · O manual do guarda-roupa

Montar o guarda-roupa tem sete passos (índices 0 a 6): separar, base,
laterais, prateleiras, portas, puxadores e fixar. As regras "a antes de
b" do manual são:


```text
separar -> base, base -> laterais, laterais -> prateleiras,
laterais -> portas, portas -> puxadores, prateleiras -> fixar,
portas -> fixar
```


Escreva kahn(rotulo) do zero: o Kahn com fila mostra a ordem de montagem.
Quando a fila esvazia antes de sair todo mundo, o manual tem ciclo: mostre
também os passos que ficaram travados (grau de entrada ainda maior que 0).
Chame para o manual certo e para a reimpressão com erro, que acrescentou a
regra puxadores -> laterais.


```text
Saída esperada:
Manual certo: separar base laterais prateleiras portas puxadores fixar
Manual com erro: separar base
  travados: laterais prateleiras portas puxadores fixar
```

**Dicas:**

1. grau[b] = quantas regras chegam em b. Comece a fila com os de grau 0.
2. Ao tirar u da fila, mostre-o e desconte 1 do grau de cada v com
   antes[u][v]; quem chegar a 0 entra na fila.
3. Resposta esperada: com o erro só saem separar e base; os outros cinco
   ficam travados (laterais, portas e puxadores formam o ciclo, e
   prateleiras e fixar esperam por eles).

```bash
~/LPEDC/rodar 23-grafos-avancados/lista/P2304.c
```

---

**Exercício P2305** · ★☆☆ · Os relógios da DFS

O programa abaixo monta, com a DFS, a ordem das etapas de publicar um
sistema (seta a -> b: a etapa a vem antes de b):


```text
lint -> testes, testes -> build, build -> deploy, banco -> deploy,
deploy -> aviso
```


Hoje ele não mostra nada. Instrumente-o como no Cormen: um relógio global
que avança 1 quando a DFS DESCOBRE um vértice (guarde em d[u]) e 1 quando
ela TERMINA o vértice (guarde em f[u]). Mostre d e f de cada etapa e a
ordem, com o f de cada uma entre parênteses: ela sai em ordem decrescente
de término.


```text
Saída esperada:
lint      d =  1  f = 10
testes    d =  2  f =  9
build     d =  3  f =  8
banco     d = 11  f = 12
deploy    d =  4  f =  7
aviso     d =  5  f =  6
Ordem: banco(12) lint(10) testes(9) build(8) deploy(7) aviso(6)
```

**Dicas:**

1. d[u] = ++relogio logo ao entrar em dfs(u); f[u] = ++relogio logo
   depois do laço dos vizinhos, antes de pôr u na ordem.
2. Use printf("%-9s d = %2d  f = %2d\n", ...) para cada etapa.
3. Resposta esperada: lint vai de 1 a 10; banco, que ninguém alcança,
   só é descoberto no 11 e termina no 12, por isso abre a ordem.

```bash
~/LPEDC/rodar 23-grafos-avancados/lista/P2305.c
```

---

**Exercício P2306** · ★☆☆ · Fibra nas escolas rurais

A secretaria de educação vai ligar seis escolas rurais com fibra óptica:
Sede, Vila Amazônia, Caburi, Mocambo, Tracajá e Zé Açu (índices 0 a 5).
Os trechos possíveis (mão dupla, em km):


```text
Sede-Vila Amazônia 7, Sede-Caburi 12, Vila Amazônia-Caburi 2,
Vila Amazônia-Mocambo 9, Caburi-Mocambo 6, Caburi-Tracajá 10,
Mocambo-Tracajá 3, Mocambo-Zé Açu 4, Tracajá-Zé Açu 5, Sede-Zé Açu 15
```


Escreva o Kruskal do zero: um vetor de struct {a, b, km}, qsort do mais
curto para o mais longo e union-find com pai[] (sem compressão mesmo).
Mostre cada trecho aceito e cada trecho recusado, na ordem em que o
algoritmo os examina, e pare quando tiver V - 1 trechos.


```text
Saída esperada:
aceita Vila Amazônia-Caburi (2 km)
aceita Mocambo-Tracajá (3 km)
aceita Mocambo-Zé Açu (4 km)
recusa Tracajá-Zé Açu (5 km): fecharia ciclo
aceita Caburi-Mocambo (6 km)
aceita Sede-Vila Amazônia (7 km)
Total: 22 km
```

**Dicas:**

1. acha(x) sobe por pai[] até achar quem é pai de si mesmo.
2. Trecho com acha(a) == acha(b) fecharia ciclo: recuse. Senão,
   pai[acha(a)] = acha(b) e some os km.
3. Resposta esperada: só Tracajá-Zé Açu é recusado; total 22 km.

```bash
~/LPEDC/rodar 23-grafos-avancados/lista/P2306.c
```

---

**Exercício P2307** · ★☆☆ · As chaves do Prim

Uma usina vai levar energia a quatro comunidades ribeirinhas. O Prim
abaixo, em O(V²), já monta a rede a partir da Usina e mostra cada linha
que entra. Instrumente-o: depois de cada vértice entrar e atualizar os
vizinhos, mostre o vetor chave[] inteiro, com "-" para infinito e um "*"
colado em quem já está na rede. Use "%3d" para cada número, com um
espaço antes, e "   -" para infinito.


```text
Saída esperada:
entra Usina
  chave:   0*   6    3    -    9
entra Bom Jesus: Usina - Bom Jesus, 3 km
  chave:   0*   4    3*   7    8
entra Boa Vista: Bom Jesus - Boa Vista, 4 km
  chave:   0*   4*   3*   2    8
entra Santa Luzia: Boa Vista - Santa Luzia, 2 km
  chave:   0*   4*   3*   2*   5
entra São José: Santa Luzia - São José, 5 km
  chave:   0*   4*   3*   2*   5*
Total: 14 km
```

**Dicas:**

1. Escreva mostra_chaves(chave, na_rede) e chame-a no fim de cada volta
   do laço "passo".
2. Repare na Santa Luzia: a chave dela cai de 7 para 2 quando Boa Vista
   entra. A chave é o cabo mais barato até a REDE, não até a Usina.
3. Resposta esperada: total de 14 km; a última linha de chaves é
   0* 4* 3* 2* 5*.

```bash
~/LPEDC/rodar 23-grafos-avancados/lista/P2307.c
```

---

**Exercício P2308** · ★☆☆ · Bellman-Ford rodada a rodada

O app de corrida dá um cupom no trecho Terminal -> Shopping (custo
R$ -2). Os trechos, de mão única, estão na lista do main numa ordem ruim
de propósito para o algoritmo: os trechos que saem da Casa vêm por último.


```text
Casa -> Shopping 8, Casa -> Terminal 5, Terminal -> Shopping -2,
Shopping -> Faculdade 4, Terminal -> Faculdade 9,
Faculdade -> Estágio 3, Shopping -> Estágio 10
```


Complete o laço das rodadas: em cada uma, relaxe os trechos na ordem da
lista; se nada mudou, mostre que parou e saia; se mudou, mostre o vetor
dist com a função mostra (já pronta). Faça no máximo V - 1 rodadas.


```text
Saída esperada:
rodada 0:   0   -   -   -   -
rodada 1:   0   8   5   -   -
rodada 2:   0   3   5  12  18
rodada 3:   0   3   5   7  13
rodada 4:   0   3   5   7  10
```

**Dicas:**

1. Relaxar: se dist[de] não é INF e dist[de] + custo < dist[para],
   atualize e marque mudou = true.
2. Cada rodada empurra a informação uma aresta para a frente. Com a pior
   ordem, o caminho Casa -> Terminal -> Shopping -> Faculdade -> Estágio,
   de 4 trechos, precisa das 4 rodadas.
3. Resposta esperada: no fim, Shopping R$ 3, Terminal 5, Faculdade 7 e
   Estágio 10; o Estágio só chega no valor certo na rodada 4.

```bash
~/LPEDC/rodar 23-grafos-avancados/lista/P2308.c
```

---

**Exercício P2309** · ★☆☆ · Floyd-Warshall quadro a quadro

Os tempos de ônibus (minutos, mão única) entre quatro bairros:


```text
Centro -> Adrianópolis 10, Adrianópolis -> Ponta Negra 25,
Centro -> Ponta Negra 40, Ponta Negra -> Cidade Nova 15,
Cidade Nova -> Centro 20, Adrianópolis -> Cidade Nova 30
```


Complete floyd(d): o Floyd-Warshall com o k no laço de fora e, depois de
cada k, a linha "Depois de k = SIGLA:" e a matriz (a função mostra está
pronta). É assim que a prova cobra: a matriz D(k) de cada rodada.


```text
Saída esperada:
Início:
       CEN  ADR  PNE  CNO
CEN      0   10   40    -
ADR      -    0   25   30
PNE      -    -    0   15
CNO     20    -    -    0
Depois de k = CEN:
       CEN  ADR  PNE  CNO
CEN      0   10   40    -
ADR      -    0   25   30
PNE      -    -    0   15
CNO     20   30   60    0
Depois de k = ADR:
       CEN  ADR  PNE  CNO
CEN      0   10   35   40
ADR      -    0   25   30
PNE      -    -    0   15
CNO     20   30   55    0
Depois de k = PNE:
       CEN  ADR  PNE  CNO
CEN      0   10   35   40
ADR      -    0   25   30
PNE      -    -    0   15
CNO     20   30   55    0
Depois de k = CNO:
       CEN  ADR  PNE  CNO
CEN      0   10   35   40
ADR     50    0   25   30
PNE     35   45    0   15
CNO     20   30   55    0
```

**Dicas:**

1. INF vale 1000000: a soma de dois INF ainda cabe num int, então dá
   para comparar d[i][k] + d[k][j] < d[i][j] direto.
2. Na rodada k só mudam casas cujo melhor caminho passa por k, e nunca a
   linha k nem a coluna k.
3. Resposta esperada: k = PNE não muda nada; na rodada CNO, Ponta Negra
   chega no Centro em 35 (15 + 20).

```bash
~/LPEDC/rodar 23-grafos-avancados/lista/P2309.c
```

---

**Exercício P2310** · ★☆☆ · Quem recebe o recado

Na família, cada um repassa o recado só para algumas pessoas (mão
única): Ana -> Bia, Bia -> Caio, Caio -> Ana, Caio -> Davi, Edu -> Davi.
Escreva do zero o fecho transitivo pelo algoritmo de Warshall: o Floyd-
Warshall com 0 e 1 no lugar de números, em que alcanca[i][j] vira 1
quando alcanca[i][k] e alcanca[k][j] são 1. Mostre a matriz e, para cada
pessoa, quantas OUTRAS pessoas recebem o recado dela.


```text
Saída esperada:
      Ana Bia Caio Davi Edu
Ana     1   1    1    1   0   chega em 3
Bia     1   1    1    1   0   chega em 3
Caio    1   1    1    1   0   chega em 3
Davi    0   0    0    0   0   chega em 0
Edu     0   0    0    1   0   chega em 1
```

**Dicas:**

1. A diagonal começa em 0. Ela só vira 1 se a pessoa está num ciclo (o
   recado volta para ela).
2. Cabeçalho com printf("      Ana Bia Caio Davi Edu\n"); os números com
   "%3d", menos nas colunas Caio e Davi, que usam "%4d".
3. Resposta esperada: Ana, Bia e Caio chegam em 3 pessoas cada; Davi em
   nenhuma; Edu só em Davi.

```bash
~/LPEDC/rodar 23-grafos-avancados/lista/P2310.c
```

## ★★☆ Para pensar

**Exercício P2311** · ★★☆ · Kosaraju nas rotas de barco

Oito portos do Amazonas têm barcos de mão única entre eles (seta a -> b:
tem barco de a para b). Um grupo de portos é FORTEMENTE CONEXO quando
dá para ir de qualquer um deles a qualquer outro, e voltar, só de barco.
O algoritmo de Kosaraju acha esses grupos com duas DFS:


```text
1. uma DFS no grafo original anota a ordem de TÉRMINO dos vértices;
2. uma DFS no grafo com as setas INVERTIDAS, começando pelos vértices
   do último a terminar para o primeiro: cada DFS nova pinta um grupo.
```


O programa já faz o passo 1 e monta a matriz inversa. Complete o passo
2: escreva dfs2(u, g) e o laço que a chama, e mostre os grupos (os
portos de cada um em ordem de índice).


```text
Saída esperada:
Término da 1ª DFS: Autazes Silves Itacoatiara Careiro Novo Airão Manacapuru Iranduba Manaus
Grupo 1: Manaus Iranduba Manacapuru
Grupo 2: Novo Airão Careiro
Grupo 3: Autazes Itacoatiara Silves
```

**Dicas:**

1. dfs2(u, g) é a mesma DFS de componentes: grupo[u] = g e desce em todo
   v com inversa[u][v] e grupo[v] == 0.
2. Percorra ordem[] de trás para a frente (i de V - 1 até 0). Quem ainda
   está com grupo 0 começa um grupo novo: dfs2(u, ++g).
3. Resposta esperada: 3 grupos: Manaus, Iranduba e Manacapuru; Novo Airão
   e Careiro; Autazes, Itacoatiara e Silves.

```bash
~/LPEDC/rodar 23-grafos-avancados/lista/P2311.c
```

---

**Exercício P2312** · ★★☆ · O alfabeto do idioma inventado

Num jogo, os elfos escrevem com as letras de sempre, mas a ordem do
alfabeto deles é outra. Você recebe listas de palavras JÁ em ordem
alfabética élfica. Comparando duas palavras vizinhas, a primeira letra
diferente diz quem vem antes ("cab" < "cad": b antes de d). Se uma é
prefixo da outra, não há informação.


```text
Lista 1: cab, cad, ae, aed, eb, bd
Lista 2: ba, bc, ca, ab
```


Escreva descobre(rotulo, palavras, n) do zero: mostre cada regra que a
lista dá e, com o Kahn sobre as 26 letras (só as que aparecem nas
palavras), o alfabeto élfico. Se o Kahn não consegue tirar todas as
letras, a lista é inconsistente. Escolha da fila: letras livres entram
em ordem de 'a' a 'z'.


```text
Saída esperada:
Lista 1
  cab < cad: b antes de d
  cad < ae: c antes de a
  aed < eb: a antes de e
  eb < bd: e antes de b
  alfabeto: caebd
Lista 2
  ba < bc: a antes de c
  bc < ca: b antes de c
  ca < ab: c antes de a
  lista inconsistente: as regras formam um ciclo
```

**Dicas:**

1. Vértice c = letra - 'a'. Marque aparece[c] para todas as letras de
   todas as palavras; são elas que contam no fim.
2. Cuidado para não somar 2 no grau se a mesma regra aparecer duas
   vezes: só some quando antes[a][b] ainda era 0.
3. Resposta esperada: Lista 1 dá o alfabeto caebd; a Lista 2 tem o ciclo
   a antes de c e c antes de a.

```bash
~/LPEDC/rodar 23-grafos-avancados/lista/P2312.c
```

---

**Exercício P2313** · ★★☆ · A trilha que vale mais pontos

No jogo de plataforma, você sai do Início e chega ao Chefão passando por
fases; cada passagem (só para a frente) dá pontos:


```text
Início -> Floresta 5, Início -> Caverna 3, Floresta -> Rio 6,
Caverna -> Rio 9, Floresta -> Castelo 2, Rio -> Castelo 4,
Rio -> Chefão 7, Castelo -> Chefão 8
```


Num grafo qualquer, o caminho MAIS LONGO é um problema difícil. Num DAG
ele é fácil: a mesma ideia do caminho mínimo em DAG, relaxando na ordem
topológica, mas guardando o MAIOR total. Escreva o programa do zero:
ordem topológica pelo Kahn, o maior total até cada fase e a trilha
campeã (refeita por pai[]).


```text
Saída esperada:
Ordem: Início Floresta Caverna Rio Castelo Chefão
Início: 0 pontos
Floresta: 5 pontos
Caverna: 3 pontos
Rio: 12 pontos
Castelo: 16 pontos
Chefão: 24 pontos
Melhor trilha: Início -> Caverna -> Rio -> Castelo -> Chefão
```

**Dicas:**

1. Comece melhor[] com INT_MIN (inalcançável) e melhor[Início] = 0.
   Pule vértices ainda em INT_MIN para não somar com ele.
2. Na ordem topológica, quando você processa u, todos que chegam em u já
   foram processados: melhor[u] já é definitivo.
3. Resposta esperada: 24 pontos, pela Caverna (3 + 9 + 4 + 8), contra 23
   pela Floresta.

```bash
~/LPEDC/rodar 23-grafos-avancados/lista/P2313.c
```

---

**Exercício P2314** · ★★☆ · A descida do rio

Descendo o rio de caiaque, cada trecho gasta energia, mas as corredeiras
a favor EMPURRAM o caiaque e devolvem energia (custo negativo). Como o
rio só desce, o grafo é um DAG. O programa já calcula o gasto mínimo
com Bellman-Ford e conta quantas relaxações ele tenta.

Estenda: escreva dag(dist), que faz a ordem topológica (Kahn) e relaxa
as arestas que saem de cada vértice uma vez só, na ordem topológica,
contando as tentativas. Mostre as duas respostas lado a lado e as duas
contagens.


```text
Saída esperada:
Ponto        BF  DAG
Cabeceira     0    0
Pedral        4    4
Remanso       1    1
Cachoeira    -1   -1
Praia         0    0
Foz          -4   -4
Relaxações tentadas: Bellman-Ford 45, DAG 9
```

**Dicas:**

1. Com a lista de trechos, o grau de entrada é grau[t[i].para]++. Para
   os vizinhos de u, percorra a lista e pegue os t[i].de == u.
2. Cada aresta é relaxada exatamente uma vez: o DAG custa O(V + E), sem
   nenhuma rodada extra, e aceita peso negativo (num DAG não há ciclo).
3. Resposta esperada: as duas colunas iguais (a Foz fica em -4) e 9
   tentativas contra 45 do Bellman-Ford.

```bash
~/LPEDC/rodar 23-grafos-avancados/lista/P2314.c
```

---

**Exercício P2315** · ★★☆ · O union-find que solta galhos

Ache o bug. O parque estadual vai ligar seis pontos com passarelas
(custo em R$ mil, mão dupla), gastando o mínimo. O Kruskal abaixo
compila e roda, mas a saída tem um ciclo (Portão-Lago, Portão-Mirante e
Lago-Mirante) e o Camping ficou de fora:


```text
Saída que aparece:
Portão-Lago (1)
Portão-Mirante (2)
Lago-Mirante (3)
Mirante-Gruta (4)
Gruta-Cachoeira (5)
Total: R$ 15 mil
```


O erro está numa linha só, na hora de juntar dois grupos. Conserte.


```text
Saída esperada:
Portão-Lago (1)
Portão-Mirante (2)
Mirante-Gruta (4)
Gruta-Cachoeira (5)
Cachoeira-Camping (6)
Total: R$ 18 mil
```

**Dicas:**

1. Siga à mão: depois de Portão-Lago, pai[Portão] = Lago. O que acontece
   com pai[Portão] quando Portão-Mirante entra? Para onde foi o Lago?
2. Mudar o pai de um vértice que não é raiz arranca ele (e quem está
   pendurado nele) do grupo antigo. Só a RAIZ pode ganhar pai novo.
3. Resposta esperada: troque a linha por pai[ra] = rb; total R$ 18 mil,
   com Lago-Mirante recusada e Cachoeira-Camping aceita.

```bash
~/LPEDC/rodar 23-grafos-avancados/lista/P2315.c
```

---

**Exercício P2316** · ★★☆ · O Prim preguiçoso e as sobras do heap

A prefeitura vai ligar cinco praças com cabo de Wi-Fi público (metros,
mão dupla). O heap de mínimo já está pronto: poe(item) e tira(). Escreva
o laço do Prim preguiçoso a partir da Matriz: o heap guarda arestas
(peso, de, para); ao tirar uma, se o "para" já está na rede, ela é uma
SOBRA (o vértice entrou por um caminho mais barato depois que ela foi
posta) e é descartada. Mostre cada item tirado e pare quando os cinco
estiverem na rede.


```text
Saída esperada:
tira Matriz-Porto (1): entra Porto
tira Porto-Feira (2): entra Feira
tira Matriz-Feira (4): descartada, Feira já está na rede
tira Feira-Escola (5): entra Escola
tira Escola-Ginásio (3): entra Ginásio
Total: 11 metros; sobraram 2 itens no heap
```

**Dicas:**

1. Comece com a Matriz na rede e ponha no heap todas as arestas dela.
2. Quando v entra, ponha no heap as arestas de v para quem ainda está
   fora. Uma mesma praça pode estar no heap várias vezes.
3. Resposta esperada: só Matriz-Feira (4) é descartada; total 11 metros
   e 2 itens ainda no heap no fim (Porto-Escola e Porto-Ginásio).

```bash
~/LPEDC/rodar 23-grafos-avancados/lista/P2316.c
```

---

**Exercício P2317** · ★★☆ · A rota do BRT

O BRT liga cinco estações (minutos, mão dupla). O programa já calcula a
tabela de distâncias com Floyd-Warshall, mas o passageiro quer saber POR
ONDE ir. Estenda: acrescente a matriz prox[i][j], a primeira estação
depois de i no melhor caminho até j, atualize-a dentro do Floyd e
escreva rota(a, b), que mostra o tempo e o caminho. Mostre as rotas
Terminal -> Aeroporto, Universidade -> Rodoviária, Aeroporto -> Terminal
e Rodoviária -> Universidade.


```text
Saída esperada:
Terminal -> Aeroporto (17 min): Terminal -> Centro -> Rodoviária -> Aeroporto
Universidade -> Rodoviária (9 min): Universidade -> Aeroporto -> Rodoviária
Aeroporto -> Terminal (17 min): Aeroporto -> Rodoviária -> Centro -> Terminal
Rodoviária -> Universidade (9 min): Rodoviária -> Aeroporto -> Universidade
```

**Dicas:**

1. No começo, prox[a][b] = b para cada linha direta (nos dois sentidos).
2. Quando i -> k -> j melhora, o primeiro passo de i até j passa a ser o
   primeiro passo de i até k: prox[i][j] = prox[i][k].
3. Resposta esperada: Terminal -> Aeroporto em 17 min pelo Centro e pela
   Rodoviária; a linha direta Terminal-Universidade (20) nunca é usada.

```bash
~/LPEDC/rodar 23-grafos-avancados/lista/P2317.c
```

---

**Exercício P2318** · ★★☆ · Dijkstra e Bellman-Ford na mesma balança

Seis cidades do Pará (siglas BEL, CAS, BRA, CAP, SAL, ABA) estão ligadas
por estradas de mão única, todas com km positivos. O programa tem o
Dijkstra em O(V²) e conta quantas arestas ele olha. Estenda: escreva
bellman_ford(origem, dist), que varre a matriz inteira em cada rodada
(u de 0 a V - 1, v de 0 a V - 1), para cedo quando nada muda e soma em
olhadas_bf cada aresta que olha. Rode os dois a partir de CADA cidade,
mostre a tabela do Dijkstra, confira se as duas tabelas são iguais e
mostre as contagens.


```text
Saída esperada:
     BEL  CAS  BRA  CAP  SAL  ABA
BEL    0   70  190  160  220   60
CAS  370    0  120   90  150  430
BRA  270  340    0  430   50  330
CAP  280  350   30    0   60  340
SAL  220  290  410  380    0  280
ABA  420   50  170  140  200    0
As duas tabelas conferem
Arestas olhadas: Dijkstra 60, Bellman-Ford 170
```

**Dicas:**

1. Uma rodada olha as 10 arestas. A parada antecipada conta a rodada que
   não mudou nada também: ela é a prova de que acabou.
2. Sem peso negativo, os dois PRECISAM dar a mesma tabela. A diferença
   está no trabalho: o Dijkstra olha cada aresta uma vez por origem.
3. Resposta esperada: as tabelas conferem; Dijkstra 60 arestas olhadas
   (6 origens × 10), Bellman-Ford 170.

```bash
~/LPEDC/rodar 23-grafos-avancados/lista/P2318.c
```

---

**Exercício P2319** · ★★☆ · A cerca que fecha o curral

O vaqueiro estica arame entre sete mourões (M0 a M6), uma cerca por vez,
nesta ordem:


```text
M0-M1, M1-M2, M3-M4, M2-M3, M4-M0, M5-M6, M2-M5, M6-M1, M3-M0
```


Cada cerca que liga dois mourões JÁ ligados por arame fecha um curral
(um ciclo). Escreva do zero, com union-find (acha com compressão de
caminho), um programa que diz, a cada cerca, se ela fecha um curral ou
só estende o arame, e o total de currais. Sem DFS: o grafo cresce aresta
por aresta e o union-find responde cada uma em tempo quase constante.


```text
Saída esperada:
cerca 1 (M0-M1): só estende o arame
cerca 2 (M1-M2): só estende o arame
cerca 3 (M3-M4): só estende o arame
cerca 4 (M2-M3): só estende o arame
cerca 5 (M4-M0): fecha o curral 1
cerca 6 (M5-M6): só estende o arame
cerca 7 (M2-M5): só estende o arame
cerca 8 (M6-M1): fecha o curral 2
cerca 9 (M3-M0): fecha o curral 3
Currais fechados: 3
```

**Dicas:**

1. acha(x): se pai[x] != x, pai[x] = acha(pai[x]); devolva pai[x].
2. Cerca a-b com acha(a) == acha(b) fecha curral; senão, junte os dois
   grupos (pai[acha(a)] = acha(b)).
3. Resposta esperada: as cercas 5, 8 e 9 fecham currais; 3 no total
   (9 cercas - 6 que bastam para ligar 7 mourões).

```bash
~/LPEDC/rodar 23-grafos-avancados/lista/P2319.c
```

---

**Exercício P2320** · ★★☆ · Quantos jeitos de descer a ladeira

Em Olinda, um bloco de carnaval quer descer do Alto da Sé até a Praia
sem subir nunca. As ladeiras (só de descida) ligam:


```text
Alto da Sé -> Amparo, Alto da Sé -> Misericórdia, Amparo -> Bonsucesso,
Misericórdia -> Bonsucesso, Misericórdia -> Carmo, Bonsucesso -> Varadouro,
Carmo -> Varadouro, Bonsucesso -> Praia, Varadouro -> Praia,
Carmo -> Praia, Amparo -> Carmo
```


Quantos trajetos diferentes chegam em cada ponto? Escreva do zero: ordem
topológica pelo Kahn e, nessa ordem, jeitos[v] += jeitos[u] para cada
ladeira u -> v, com jeitos[Alto da Sé] = 1. Mostre cada ponto na ordem
topológica com a sua contagem.


```text
Saída esperada:
Alto da Sé: 1
Amparo: 1
Misericórdia: 1
Bonsucesso: 2
Carmo: 2
Varadouro: 4
Praia: 8
```

**Dicas:**

1. Os índices são 0 a 6 na ordem em que os pontos aparecem acima.
2. É programação dinâmica num DAG: quando u é processado, jeitos[u] já
   tem todos os caminhos que chegam nele.
3. Resposta esperada: 8 trajetos chegam à Praia.

```bash
~/LPEDC/rodar 23-grafos-avancados/lista/P2320.c
```

## ★★★ Desafio

**Exercício P2321** · ★★★ · A segunda melhor rede

Cinco aldeias vão ser ligadas por rádio-internet (custo em R$ mil, mão
dupla). A árvore mínima é a primeira escolha, mas o órgão de controle
exige um plano B: a SEGUNDA MELHOR árvore geradora, a mais barata que
seja diferente da mínima. As ligações possíveis:


```text
Aldeia Nova-Boa Esperança 4, Aldeia Nova-Cajual 6,
Boa Esperança-Cajual 5, Boa Esperança-Daracuí 3, Cajual-Daracuí 7,
Cajual-Extrema 8, Daracuí-Extrema 9
```


Para grafo pequeno há um jeito direto: a segunda melhor árvore difere
da mínima em UMA aresta. Então, para cada aresta da árvore mínima, rode
o Kruskal de novo proibindo só ela e fique com o menor total. Escreva o
programa do zero: mostre a árvore mínima, o total de cada tentativa e a
troca que dá a segunda melhor (a primeira tentativa com o menor total).


```text
Saída esperada:
Árvore mínima: 20
  Boa Esperança-Daracuí (3)
  Aldeia Nova-Boa Esperança (4)
  Boa Esperança-Cajual (5)
  Cajual-Extrema (8)
sem Boa Esperança-Daracuí (3): 24
sem Aldeia Nova-Boa Esperança (4): 22
sem Boa Esperança-Cajual (5): 21
sem Cajual-Extrema (8): 21
Segunda melhor: 21, trocando Boa Esperança-Cajual (5) por Aldeia Nova-Cajual (6)
```

**Dicas:**

1. Ordene a lista uma vez só. Escreva kruskal(proibida, usada[]), que
   pula o índice proibido e marca em usada[] as arestas escolhidas.
2. A aresta que entrou é a que está na árvore nova e não estava na
   mínima. Se uma tentativa não ligar todo mundo, devolva -1 e ignore.
3. Resposta esperada: mínima 20; segunda melhor 21, trocando
   Boa Esperança-Cajual (5) por Aldeia Nova-Cajual (6). Repare que tirar
   Cajual-Extrema também dá 21: o plano B nem sempre é único.

```bash
~/LPEDC/rodar 23-grafos-avancados/lista/P2321.c
```

---

**Exercício P2322** · ★★★ · Arbitragem na casa de câmbio

A casa de câmbio publica quanto se recebe de cada moeda por 1 unidade de
outra (Real, Dólar, Euro, Libra, Peso). ARBITRAGEM é uma volta de trocas
que termina com mais dinheiro do que começou: o produto das taxas da
volta passa de 1. O truque do Cormen: com peso -log(taxa), produto maior
que 1 vira soma negativa, e arbitragem vira CICLO NEGATIVO.

O main já tem as 20 taxas. Escreva analisa(rotulo, t, n) do zero:
- Bellman-Ford com todas as distâncias começando em 0 (é como ter uma
origem imaginária ligada a todas as moedas) e um vetor ant[];
- se a M-ésima rodada (a extra) ainda melhora alguém, guarde essa moeda
x, ande M passos por ant[] (assim você cai dentro do ciclo) e recolha
o ciclo seguindo ant[] até voltar em x;
- mostre o ciclo na ordem das trocas e o fator (produto das taxas).
Na terça a casa corrigiu Euro -> Real de 5.50 para 5.40.


```text
Saída esperada:
Segunda-feira: arbitragem Dólar -> Euro -> Real -> Dólar
  fator do ciclo: 1.0120 (lucro de 1.20%)
Terça-feira: sem arbitragem
```

**Dicas:**

1. Compare com folga por causa do double: troque quando
   dist[de] + w < dist[para] - 1e-12. Use log de <math.h>.
2. ant[] aponta para trás (de quem veio). Recolhendo x, ant[x],
   ant[ant[x]]..., você tem o ciclo ao contrário: mostre de trás para
   frente e, para cada par (de, para), multiplique a taxa da troca.
3. Resposta esperada: na segunda, Dólar -> Euro -> Real -> Dólar com
   fator 1.0120 (0,92 × 5,50 × 0,20); na terça, sem arbitragem.

```bash
~/LPEDC/rodar 23-grafos-avancados/lista/P2322.c
```

---

**Exercício P2323** · ★★★ · Kosaraju de mão trocada

Ache o bug. Uma rede social quer achar as "bolhas": grupos em que todo
mundo alcança todo mundo seguindo a relação "segue". Este Kosaraju
compila e roda, mas junta a rede inteira numa bolha só, e @dani nem
chega de volta em @ana:


```text
Saída que aparece:
Bolha 1: @ana @beto @caio @dani @enzo @fe @gabi
```


O erro está numa linha só. Conserte.


```text
Saída esperada:
Bolha 1: @ana @beto @caio
Bolha 2: @dani @enzo
Bolha 3: @fe @gabi
```

**Dicas:**

1. A 1ª DFS está certa: o último a terminar (@ana) fica num grupo de
   onde se SAI para os outros. Uma DFS normal a partir dele alcança tudo.
2. A 2ª passada tem que andar no grafo INVERTIDO: de @ana, para trás, só
   se alcança quem também chega em @ana.
3. Resposta esperada: em dfs2, troque segue[u][v] por inversa[u][v];
   saem 3 bolhas: @ana @beto @caio, @dani @enzo e @fe @gabi.

```bash
~/LPEDC/rodar 23-grafos-avancados/lista/P2323.c
```

---

**Exercício P2324** · ★★★ · A carreta mais pesada

Cada estrada entre seis cidades tem um limite de peso (toneladas, mão
dupla). Uma carreta passa por um caminho se aguentar o trecho MAIS
FRACO dele. Para cada par de cidades, qual a carreta mais pesada que
consegue ir de uma à outra? As estradas:


```text
Manaus-Itacoatiara 40, Manaus-Humaitá 18, Itacoatiara-Humaitá 25,
Humaitá-Porto Velho 30, Itacoatiara-Porto Velho 12, Humaitá-Lábrea 22,
Porto Velho-Lábrea 35, Manaus-Tefé 15, Tefé-Lábrea 28
```


Escreva do zero uma variação do Floyd-Warshall (o caminho de GARGALO
máximo): passar por k vale min(cap[i][k], cap[k][j]), e fica o maior.
Use 0 para "sem estrada" e ignore a diagonal. Mostre a tabela com as
siglas MAO ITA HUM PVH LAB TEF e as duas perguntas do fim.


```text
Saída esperada:
     MAO ITA HUM PVH LAB TEF
MAO    -  40  25  25  25  25
ITA   40   -  25  25  25  25
HUM   25  25   -  30  30  28
PVH   25  25  30   -  35  28
LAB   25  25  30  35   -  28
TEF   25  25  28  28  28   -
Manaus -> Porto Velho: até 25 t
Tefé -> Lábrea: até 28 t
```

**Dicas:**

1. A troca é "max no lugar de min, min no lugar de +": o resto do Floyd
   (o k por fora, a ordem dos laços) fica igual.
2. Sem estrada vale 0, e min(0, x) = 0: "não passa nada" se comporta
   sozinho, sem precisar de INF.
3. Resposta esperada: Manaus -> Porto Velho até 25 t (por Itacoatiara e
   Humaitá; a estrada Manaus-Humaitá aguenta só 18) e Tefé -> Lábrea até
   28 t, a estrada direta.

```bash
~/LPEDC/rodar 23-grafos-avancados/lista/P2324.c
```

---

**Exercício P2325** · ★★★ · Quantas ordens tem a reforma

Contar as ordenações topológicas com backtracking (assunto 0127) gasta
um passo por ORDEM: sem regra nenhuma, 12 tarefas teriam 12! = 479
milhões de ordens. A programação dinâmica conta sem listar: jeitos[S] é
quantas ordens existem para fazer PRIMEIRO exatamente o conjunto S de
tarefas (S guardado como bits de um int). Começa com jeitos[0] = 1 e,
para cada S e cada tarefa v fora de S cujos pré-requisitos estão todos
em S, soma jeitos[S] em jeitos[S | 1 << v].

Escreva do zero enumera(feitas) (o backtracking) e conta_pd(), com
pred[v] = bits dos pré-requisitos de v. Teste os três casos:


```text
Banheiro, 6 tarefas: 0->1, 0->2, 1->3, 3->4, 2->4, 4->5
Casa, 12 tarefas: 0->1, 0->2, 0->3, 1->4, 2->4, 3->5, 4->6, 5->6,
                  6->7, 6->8, 7->9, 8->10, 9->11, 10->11
Sem regras, 12 tarefas: só a PD (o backtracking demoraria demais)
```



```text
Saída esperada:
Banheiro (6 tarefas): backtracking 3, PD 3
Casa (12 tarefas): backtracking 120, PD 120
Sem regras (12 tarefas): PD 479001600
```

**Dicas:**

1. v está em S quando (S >> v & 1) é 1. "Todos os pré-requisitos em S"
   é (pred[v] & ~S) == 0.
2. A PD tem 2^n estados e n transições por estado: O(2^n · n), umas 50
   mil operações para n = 12, contra milhões de folhas do backtracking.
   Use long long: 12! não cabe em muitos tipos menores.
3. Resposta esperada: 3 ordens no banheiro, 120 na casa e 479001600 sem
   regras.

```bash
~/LPEDC/rodar 23-grafos-avancados/lista/P2325.c
```

---

**Exercício P2326** · ★★★ · Onde o ciclo negativo contamina

Num jogo, atravessar portais (mão única) custa energia; alguns devolvem
energia (custo negativo). A volta Ponte -> Torre -> Mina -> Ponte custa
3 - 4 - 1 = -2: quem entra nela fica girando e a energia "mínima" de
tudo o que vem depois é -infinito. O programa abaixo já faz as V - 1
rodadas do Bellman-Ford e só mostra números. Estenda-o:
- na rodada extra, cada aresta que ainda melhora marca o destino;
- a partir de cada marcado, uma DFS espalha a marca por tudo o que ele
alcança (essas salas ficam em -infinito);
- mostre "-infinito", "inalcançável" ou o número de cada sala.


```text
Saída esperada:
Base   0
Ponte  -infinito
Torre  -infinito
Mina   -infinito
Vale   -infinito
Lago   6
Bosque 7
Ilha   inalcançável
```

**Dicas:**

1. espalha(u) marca infinito[u] e desce por todo portal u -> v com v
   ainda não marcado.
2. A Ilha tem um ciclo negativo próprio (o portal Ilha -> Ilha), mas
   ninguém da Base chega nela: ciclo inalcançável não contamina nada.
   O Bosque também não: a Ilha chega nele, mas a Base não chega na Ilha.
3. Resposta esperada: Ponte, Torre, Mina e Vale em -infinito; Lago 6,
   Bosque 7, Ilha inalcançável.

```bash
~/LPEDC/rodar 23-grafos-avancados/lista/P2326.c
```

---

**Exercício P2327** · ★★★ · O Prim que virou Dijkstra

Ache o bug. A operadora vai ligar cinco torres com o mínimo de cabo
(km, mão dupla). O código abaixo parece um Prim, mas a rede sai cara e
toda pendurada na Central:


```text
Saída que aparece:
Central - Morro: 5 km
Central - Vila: 6 km
Vila - Usina: 3 km
Central - Sítio: 9 km
Total: 23 km
```


Isso é a árvore de caminhos mínimos do Dijkstra, não a árvore geradora
mínima. O erro está no bloco que atualiza a chave dos vizinhos (duas
linhas). Conserte.


```text
Saída esperada:
Central - Morro: 5 km
Morro - Vila: 2 km
Vila - Usina: 3 km
Usina - Sítio: 1 km
Total: 11 km
```

**Dicas:**

1. No Dijkstra, a chave de v é a distância da ORIGEM até v. No Prim, é o
   cabo mais barato que liga v a QUALQUER torre já na rede.
2. O Sítio tem o cabo Usina-Sítio de 1 km, mas o programa compara
   chave[Usina] + 1 = 10 com 9 e fica com a ligação direta.
3. Resposta esperada: compare e guarde só km[u][v]; total 11 km.

```bash
~/LPEDC/rodar 23-grafos-avancados/lista/P2327.c
```

---

**Exercício P2328** · ★★★ · Três zonas de entrega

Uma rede de farmácias vai dividir nove bairros em 3 zonas de entrega,
com bairros parecidos juntos e zonas o mais separadas possível. As
coordenadas (km) estão no main; a distância é a de quarteirão,
|x1 - x2| + |y1 - y2|.

O Kruskal resolve: ordene todos os pares pela distância e vá juntando
grupos, mas PARE quando sobrarem 3. A próxima aresta que ligaria dois
grupos diferentes é o ESPAÇAMENTO, a menor distância entre zonas, e
esse corte é o que deixa o espaçamento máximo. Escreva do zero: monte as
36 arestas, ordene (empate: menor a, depois menor b), mostre as zonas
(na ordem do primeiro bairro de cada uma) e o espaçamento.


```text
Saída esperada:
Zona 1: Aleixo Flores Parque 10
Zona 2: Compensa Glória Santo Antônio
Zona 3: Japiim Coroado Distrito
Espaçamento: 4 km (Aleixo-Japiim)
```

**Dicas:**

1. Use as coordenadas do esqueleto: x = {2, 3, 2, 10, 11, 9, 6, 7, 6} e
   y = {9, 8, 7, 2, 3, 1, 9, 10, 11}, na ordem Aleixo, Flores, Parque 10,
   Compensa, Glória, Santo Antônio, Japiim, Coroado, Distrito.
2. O desempate no comparador deixa a saída a mesma em qualquer máquina:
   o qsort não garante a ordem de iguais.
3. Resposta esperada: Aleixo, Flores e Parque 10; Compensa, Glória e
   Santo Antônio; Japiim, Coroado e Distrito; espaçamento 4 km
   (Aleixo-Japiim).

```bash
~/LPEDC/rodar 23-grafos-avancados/lista/P2328.c
```

---

**Exercício P2329** · ★★★ · Johnson em miniatura

O Dijkstra não aceita peso negativo, e rodar Bellman-Ford de cada origem
custa O(V² E). O algoritmo de Johnson faz um Bellman-Ford só e depois
V Dijkstras:


```text
1. calcule h[v], a menor distância de uma origem imaginária q (ligada
   a todos com peso 0) até v: é o Bellman-Ford com h[] começando em 0;
2. troque cada peso por w'(u, v) = w(u, v) + h[u] - h[v], que nunca é
   negativo;
3. rode o Dijkstra com w' de cada origem e desfaça a troca:
   d(u, v) = d'(u, v) - h[u] + h[v].
```


O programa já tem dijkstra(o, peso, dist) e floyd(d) para conferir.
Complete o main com os três passos: mostre h, os pesos novos (na ordem
u, v de 0 a 4), a tabela final e se ela bate com a do Floyd-Warshall.


```text
Saída esperada:
h: A=0 B=0 C=-2 D=0 E=-1
Pesos novos: AB=3 AC=6 AE=6 BC=0 CD=0 DB=1 DE=0 EC=4
      A   B   C   D   E
A     0   3   1   3   2
B     -   0  -2   0  -1
C     -   3   0   2   1
D     -   1  -1   0  -1
E     -   6   3   5   0
Floyd-Warshall confere
```

**Dicas:**

1. Para o passo 1, V rodadas sobre a matriz inteira bastam (são V + 1
   vértices contando o q). Aqui não há ciclo negativo.
2. w' >= 0 sai da desigualdade triangular: h[v] <= h[u] + w(u, v).
3. Resposta esperada: h = 0, 0, -2, 0, -1; a linha de A fica
   0 3 1 3 2 e o Floyd-Warshall confere.

```bash
~/LPEDC/rodar 23-grafos-avancados/lista/P2329.c
```

---

**Exercício P2330** · ★★★ · Quantas ruas novas no centro histórico

No centro histórico, todas as ruas são de mão única. Hoje não dá para
ir de qualquer largo a qualquer outro. A prefeitura quer abrir o MÍNIMO
de ruas novas (também de mão única) para que dê. As ruas:


```text
Sé -> Carmo, Carmo -> Rosário, Rosário -> Sé, Rosário -> Mercado,
Mercado -> Teatro, Teatro -> Mercado, Carmo -> Matriz,
Cais -> Matriz, Estação -> Feira, Feira -> Estação, Estação -> Sé
```


O resultado clássico: encolha cada componente fortemente conexo num
ponto só (o grafo vira um DAG). Conte as FONTES (grupos onde nenhuma
rua chega de fora) e os SUMIDOUROS (de onde nenhuma rua sai para
fora). Se houver mais de um grupo, a resposta é max(fontes,
sumidouros); com um grupo só, 0. Escreva do zero: Kosaraju, a marcação
de quem entra e quem sai de cada grupo, e a resposta.


```text
Saída esperada:
Grupo 1: Estação Feira (ninguém chega)
Grupo 2: Cais (ninguém chega)
Grupo 3: Sé Carmo Rosário
Grupo 4: Matriz (não sai)
Grupo 5: Mercado Teatro (não sai)
Fontes: 2, sumidouros: 2
Ruas novas, no mínimo: 2
```

**Dicas:**

1. Índices 0 a 8 na ordem Sé, Carmo, Rosário, Mercado, Teatro, Matriz,
   Cais, Estação, Feira. Rode a 1ª DFS com u de 0 a 8 e numere os
   grupos na ordem da 2ª passada.
2. Só contam as setas a -> b com grupo[a] != grupo[b]: elas marcam
   sai[grupo[a]] e entra[grupo[b]].
3. Resposta esperada: 5 grupos, 2 fontes ({Estação, Feira} e {Cais}),
   2 sumidouros ({Matriz} e {Mercado, Teatro}): 2 ruas novas.

```bash
~/LPEDC/rodar 23-grafos-avancados/lista/P2330.c
```
