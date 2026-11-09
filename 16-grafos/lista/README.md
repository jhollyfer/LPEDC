<!-- Gerado por _gerador a partir dos arquivos P????.c desta pasta. -->

# Lista prática · Módulo 16 · Grafos

30 exercícios de codificar que treinam o módulo inteiro, misturando os assuntos, no ritmo da prova do PPGI (veja [PPGI.md](../../PPGI.md)). Cada arquivo `P????.c` desta pasta é um exercício: a resposta vai dentro dele, embaixo de `// Escreva sua resposta abaixo:`. Uma resolução de cada um está em `_respostas/16-grafos/lista/`. Só olhe depois de tentar.

[Voltar ao módulo](../README.md)

## ★☆☆ Aquecimento

**Exercício P1601** · ★☆☆ · Grau das paradas e número de linhas

A matriz do esqueleto liga seis bairros de Manaus por linhas de ônibus
diretas, de ida e volta (grafo NÃO dirigido): adj[i][j] == 1 quer dizer que
uma linha liga i e j. Escreva do zero um programa que mostre:

- o grau de cada bairro (quantas linhas saem dele);
- a soma dos graus e o número de linhas (arestas), calculado pela soma;
- o bairro com o maior grau (no empate, o de menor índice);
- os bairros "ponta de linha", com grau 1.


```text
Saída esperada:
Centro        grau 3
Adrianopolis  grau 3
Cidade Nova   grau 2
Ponta Negra   grau 1
Compensa      grau 2
Aleixo        grau 3
Soma dos graus: 14
Linhas (arestas): 7
Maior grau: Centro (3)
Ponta de linha: Ponta Negra
```

**Dicas:**

1. O grau de i é a soma da linha i da matriz.
2. Cada aresta i-j aparece duas vezes na matriz (adj[i][j] e adj[j][i]):
   por isso a soma dos graus é sempre o dobro do número de arestas.
3. Para o maior grau, troque o campeão só quando o grau for estritamente
   maior: assim o empate fica com o primeiro.
4. Resposta esperada: soma dos graus 14, 7 linhas, maior grau Centro (3),
   e a única ponta de linha é Ponta Negra.

```bash
~/LPEDC/rodar 16-grafos/lista/P1601.c
```

---

**Exercício P1602** · ★☆☆ · Voos diretos: graus de entrada e de saída

Uma companhia aérea tem voos diretos entre seis capitais. Voo é de mão
única: o voo Manaus -> Belém não garante o voo Belém -> Manaus (grafo
DIRIGIDO). O esqueleto traz o vetor voos[], um par {origem, destino} por voo.

Escreva o programa que:

- monte a matriz de adjacência m[V][V] a partir de voos[];
- mostre, para cada capital, o grau de SAÍDA (voos que partem) e o grau de
ENTRADA (voos que chegam);
- confira que as duas somas dão o número de voos;
- mostre o "hub" (a capital com o maior grau de entrada);
- conte os pares de capitais com voo nos DOIS sentidos.


```text
Saída esperada:
Manaus     saída 3  entrada 2
Belem      saída 1  entrada 1
Brasilia   saída 3  entrada 3
Sao Paulo  saída 2  entrada 2
Recife     saída 1  entrada 2
Boa Vista  saída 1  entrada 1
Voos: 11 | soma das saídas 11 | soma das entradas 11
Hub: Brasilia (3 chegadas)
Ida e volta: Manaus <-> Brasilia
Ida e volta: Manaus <-> Boa Vista
Ida e volta: Brasilia <-> Sao Paulo
Ida e volta: Sao Paulo <-> Recife
Pares com ida e volta: 4
```

**Dicas:**

1. Num grafo dirigido, a saída de i é a soma da LINHA i, e a entrada de j é
   a soma da COLUNA j.
2. Cada voo soma 1 em uma saída e 1 em uma entrada: as duas somas são
   iguais ao número de arestas (e não ao dobro, como no não dirigido).
3. Para os pares de ida e volta, olhe só i < j e teste m[i][j] && m[j][i]:
   assim cada par conta uma vez.
4. Resposta esperada: 11 voos nas duas somas, hub Brasilia (3 chegadas) e
   4 pares com ida e volta.

```bash
~/LPEDC/rodar 16-grafos/lista/P1602.c
```

---

**Exercício P1603** · ★☆☆ · Da lista para a matriz: o cadastro torto

A rede de amigos de um grupo de corrida está guardada em LISTA de adjacência
(listas encadeadas com malloc). Amizade é recíproca, então toda ligação
deveria aparecer nas duas listas. Só que alguém cadastrou uma amizade em um
sentido só.

Complete as duas funções:


```text
void lista_para_matriz(No *lista[], int m[V][V]);
int confere_simetria(int m[V][V]);
```


A primeira zera m e marca m[u][v] = 1 para cada nó v da lista de u. A
segunda mostra cada par i < j com m[i][j] != m[j][i] e devolve quantos
achou. O main já monta as listas, chama as duas funções, mostra a matriz e
libera tudo.


```text
Saída esperada:
       A B C D E
Ana    0 1 1 0 0
Bruno  1 0 1 0 1
Carla  1 1 0 1 0
Davi   0 0 1 0 1
Eva    0 1 0 0 0
Torto: Davi e Eva
Pares tortos: 1
```

**Dicas:**

1. Percorra a lista de cada u com um ponteiro: for (No *p = lista[u]; p;
   p = p->prox) m[u][p->v] = 1;
2. A conversão custa O(V + E) para percorrer as listas, mais O(V²) para
   zerar a matriz: a matriz sempre cobra V².
3. Na simetria, compare só a metade de cima (j > i): cada par aparece uma
   vez.
4. Resposta esperada: a matriz acima e um único par torto, Davi e Eva.

```bash
~/LPEDC/rodar 16-grafos/lista/P1603.c
```

---

**Exercício P1604** · ★☆☆ · O grupo de estudos é completo?

Cinco colegas que vão fazer a prova do mestrado montaram um grupo de estudos.
A matriz do esqueleto diz quem já estudou junto com quem (não dirigido). O
grupo só fica "completo" quando TODO par de pessoas já estudou junto: é o
grafo completo K5, com 5·4/2 = 10 arestas.

Escreva:


```text
int arestas(int m[V][V]);
bool completo(int m[V][V]);
```


e um main que mostre quantas arestas há, quantas o K5 teria, os pares que
ainda faltam e, depois de marcar esses pares na matriz (as sessões que
faltam), se o grupo ficou completo.


```text
Saída esperada:
Arestas: 7 de 10
completo: não
Falta: Iara-Luana
Falta: Joao-Moacir
Falta: Kaue-Luana
Depois das sessões: 10 arestas
completo: sim
```

**Dicas:**

1. Conte só a metade de cima da matriz (i < j): cada aresta uma vez.
2. Um grafo simples com n vértices é completo quando tem n(n - 1)/2 arestas,
   ou, do jeito direto, quando m[i][j] == 1 para todo i != j.
3. Ao marcar um par que falta, marque os dois sentidos: m[i][j] = m[j][i] = 1.
4. Resposta esperada: 7 arestas de 10, faltam Iara-Luana, Joao-Moacir e
   Kaue-Luana; depois, "completo: sim".

```bash
~/LPEDC/rodar 16-grafos/lista/P1604.c
```

---

**Exercício P1605** · ★☆☆ · O complemento: quem ainda precisa ser apresentado

No coffee break de um congresso em Manaus, a organização quer apresentar
quem ainda não se conhece. A matriz conhece[][] (não dirigida) diz quem já
se conhece. O grafo das apresentações que faltam é o COMPLEMENTO: tem uma
aresta i-j (com i != j) exatamente quando conhece[i][j] == 0.

Escreva void complemento(int g[V][V], int c[V][V]) e um main que mostre,
para cada pessoa, quem ela ainda precisa conhecer, o número de arestas dos
dois grafos e a soma, que tem de dar o número de arestas do grafo completo.


```text
Saída esperada:
Raimundo : Ubiratan Vania
Socorro  : Ubiratan Vania Wesley
Tiago    : Vania Wesley
Ubiratan : Raimundo Socorro Wesley
Vania    : Raimundo Socorro Tiago
Wesley   : Socorro Tiago Ubiratan
conhece: 7 | complemento: 8 | total: 15 = 6·5/2
```

**Dicas:**

1. c[i][j] = (i != j && !g[i][j]). A diagonal fica 0: ninguém é
   apresentado a si mesmo.
2. Toda aresta possível (são V(V - 1)/2) está em g ou em c, nunca nas duas.
3. Para mostrar "ninguém", use um contador por pessoa.
4. Resposta esperada: 7 arestas em conhece, 8 no complemento, 15 no total.

```bash
~/LPEDC/rodar 16-grafos/lista/P1605.c
```

---

**Exercício P1606** · ★☆☆ · Quem me segue: o grafo transposto

Numa rede social, "u segue v" é uma seta u -> v (grafo dirigido). O
esqueleto guarda, em lista de adjacência, QUEM CADA PERFIL SEGUE. Para
mostrar os SEGUIDORES de cada perfil, você precisa do grafo TRANSPOSTO: o
mesmo grafo com todas as setas invertidas (cada u -> v vira v -> u).

Complete No **transposta(No *lista[]), que cria (com malloc) as listas do
transposto, e mostre os seguidores de cada perfil em ordem alfabética.
Libere as duas listas no fim.


```text
Saída esperada:
Ana segue: Beto Cris
Beto segue: Cris
Cris segue: Ana
Dani segue: Ana Cris
Enzo segue: Dani
Seguidores de Ana: Cris Dani
Seguidores de Beto: Ana
Seguidores de Cris: Ana Beto Dani
Seguidores de Dani: Enzo
Seguidores de Enzo: ninguém
```

**Dicas:**

1. Para cada u e cada nó v da lista de u, insira u na lista de v do
   transposto. Custo: O(V + E).
2. insere() põe no COMEÇO da lista. Se você percorrer u de V - 1 até 0, os
   seguidores ficam em ordem crescente de índice.
3. O vetor de cabeças do transposto também precisa de malloc (ou calloc,
   que já zera os ponteiros).
4. Resposta esperada: a saída acima. Ana tem 2 seguidores; Enzo, nenhum.

```bash
~/LPEDC/rodar 16-grafos/lista/P1606.c
```

---

**Exercício P1607** · ★☆☆ · BFS a partir da rodoviária: d e π

Você chegou à rodoviária de Manaus, no bairro Flores, e quer saber quantas
baldeações de ônibus separam Flores de cada bairro. As linhas diretas (mão
dupla) estão na matriz do esqueleto.

Complete void bfs(int s, int d[], int pi[]) no estilo do Cormen: d[v] é a
distância (em arestas) de s até v, ou -1 se v não foi alcançado, e pi[v] é o
predecessor de v na árvore da BFS, ou -1 (NIL). Examine os vizinhos em ordem
de índice. O main já mostra a tabela. Acrescente na bfs um printf com a
ordem em que os bairros SAEM da fila.


```text
Saída esperada:
Saem da fila: Flores Parque Dez Aleixo Centro Cachoeirinha Coroado Educandos Japiim
bairro        d  pi
Flores        0  NIL
Parque Dez    1  Flores
Aleixo        1  Flores
Centro        2  Parque Dez
Educandos     3  Centro
Cachoeirinha  2  Parque Dez
Japiim        3  Cachoeirinha
Coroado       2  Aleixo
```

**Dicas:**

1. Comece com d[v] = -1 e pi[v] = -1 para todo v; depois d[s] = 0 e s
   entra na fila.
2. Ao tirar u da fila, para cada v com adj[u][v] e d[v] == -1: d[v] =
   d[u] + 1, pi[v] = u, v entra na fila. Marcar na ENTRADA da fila evita que
   um bairro entre duas vezes.
3. Cada vértice entra uma vez na fila: um vetor de V posições basta.
4. Resposta esperada: a saída acima. Os mais longe são Educandos e Japiim
   (d = 3), e Educandos tem π = Centro.

```bash
~/LPEDC/rodar 16-grafos/lista/P1607.c
```

---

**Exercício P1608** · ★☆☆ · Conserte a BFS das trilhas do bosque

Conserte o programa. Ele deveria mostrar a quantos trechos de trilha cada
ponto do bosque fica da Entrada (grafo não dirigido) e por onde se chega,
mas o colega deixou DOIS erros de propósito. Não há erro de memória: o
programa roda até o fim, só que as distâncias e os predecessores saem
errados.


```text
Saída que aparece:
Entrada    d=0  pi=NIL
Lago       d=1  pi=Lago
Viveiro    d=1  pi=Viveiro
Mirante    d=2  pi=Mirante
Orquidario d=2  pi=Orquidario
Torre      d=3  pi=Torre
Cafe       d=3  pi=Cafe
```



```text
Saída esperada:
Entrada    d=0  pi=NIL
Lago       d=1  pi=Entrada
Viveiro    d=1  pi=Entrada
Mirante    d=2  pi=Lago
Orquidario d=2  pi=Viveiro
Torre      d=3  pi=Mirante
Cafe       d=2  pi=Lago
```

**Dicas:**

1. Uma fila tira do COMEÇO (ini++) e põe no FIM (fim++). Tirar do fim
   transforma a fila em pilha, e a "BFS" deixa de andar por camadas.
2. O predecessor de v é quem o descobriu: o u que acabou de sair da fila.
3. Confira à mão: Lago e Viveiro são vizinhos da Entrada, então têm d = 1.
4. Resposta esperada: a segunda saída acima; a Torre fica a 3 trechos, pelo
   Mirante.

```bash
~/LPEDC/rodar 16-grafos/lista/P1608.c
```

---

**Exercício P1609** · ★☆☆ · DFS com relógio: os tempos d e f

No parque, as trilhas são de sentido único (grafo DIRIGIDO):


```text
Portao -> Lago, Portao -> Viveiro, Lago -> Mirante, Mirante -> Portao,
Viveiro -> Mirante, Viveiro -> Cascata, Quiosque -> Cascata,
Quiosque -> Viveiro
```


Complete a DFS no estilo do Cormen. Um relógio global começa em 0 e avança
a cada descoberta e a cada término: d[u] é o tempo em que u fica CINZA e
f[u] o tempo em que fica PRETO. O laço do main tenta os vértices em ordem de
índice e começa uma árvore nova em cada vértice ainda branco. Mostre também
a ordem em que os vértices terminam.


```text
Saída esperada:
Portao     1/10
Lago       2/ 5
Mirante    3/ 4
Viveiro    6/ 9
Cascata    7/ 8
Quiosque  11/12
Terminam: Mirante Lago Cascata Viveiro Portao Quiosque
```

**Dicas:**

1. dfs_visita(u): d[u] = ++relogio; cor[u] = CINZA; para cada v com
   adj[u][v] e cor[v] == BRANCO, dfs_visita(v); depois cor[u] = PRETO e
   f[u] = ++relogio.
2. Com V vértices, o relógio termina em 2V: cada vértice gasta um tique ao
   ser descoberto e outro ao terminar.
3. O Quiosque não é alcançado a partir do Portão: ele abre uma segunda
   árvore e recebe d = 11.
4. Resposta esperada: Portao 1/10, Lago 2/5, Mirante 3/4, Viveiro 6/9,
   Cascata 7/8, Quiosque 11/12.

```bash
~/LPEDC/rodar 16-grafos/lista/P1609.c
```

---

**Exercício P1610** · ★☆☆ · Comunidades do rio: quantas lanchas faltam

Nove comunidades ribeirinhas do Rio Negro (0 a 8) são ligadas por linhas
de lancha de ida e volta:


```text
0-1, 1-2, 0-2, 3-4, 5-6, 6-7, 5-7
```


A comunidade 8 está isolada. Um grupo de comunidades que se alcançam, direta
ou indiretamente, é um COMPONENTE CONEXO. Para ligar k componentes num só
bastam k - 1 linhas novas (uma ligando cada grupo ao seguinte).

Escreva do zero um programa que rotule os componentes com uma DFS (comp[v] =
número do componente), mostre os membros de cada componente e quantas linhas
novas são necessárias.


```text
Saída esperada:
Componente 0: 0 1 2
Componente 1: 3 4
Componente 2: 5 6 7
Componente 3: 8
Componentes: 4
Linhas novas necessárias: 3
```

**Dicas:**

1. Comece com comp[v] = -1. Para cada v ainda sem rótulo, chame
   dfs(v, k) com o próximo número k e some 1 em k.
2. dfs(u, k): comp[u] = k; visite todo vizinho sem rótulo com o mesmo k.
3. Componente com um vértice só também conta: a comunidade 8 é um
   componente.
4. Resposta esperada: 4 componentes, logo 3 linhas novas.

```bash
~/LPEDC/rodar 16-grafos/lista/P1610.c
```

## ★★☆ Para pensar

**Exercício P1611** · ★★☆ · Menos conexões até Porto Alegre

Você sai de Manaus e quer chegar a outra capital com o MENOR número de
voos. A companhia voa nos dois sentidos nos trechos da matriz do esqueleto
(não dirigido). Oiapoque está no cadastro, mas a companhia não voa para lá.

Rode uma BFS a partir de Manaus guardando pi[] e escreva, SEM recursão:


```text
int caminho(const int pi[], int s, int t, int rota[]);
```


Ela devolve o número de voos de s até t e preenche rota[] com as cidades na
ordem da viagem, de s até t; se t não foi alcançado, devolve -1. Mostre a
rota para Porto Alegre, Fortaleza e Oiapoque.


```text
Saída esperada:
Porto Alegre: Manaus -> Brasilia -> Recife -> Rio -> Porto Alegre (4 voos, d = 4)
Fortaleza: Manaus -> Belem -> Fortaleza (2 voos, d = 2)
Oiapoque: sem rota
```

**Dicas:**

1. Andar por pi[] a partir de t dá o caminho DE TRÁS PARA FRENTE: guarde
   t, pi[t], pi[pi[t]], ... até chegar em s, e depois inverta o vetor.
2. Se t != s e pi[t] == -1, t não foi descoberto: devolva -1.
3. O número de voos é o número de cidades na rota menos 1, e tem de bater
   com d[t] da BFS.
4. Resposta esperada: Porto Alegre em 4 voos (Manaus, Brasilia, Recife,
   Rio, Porto Alegre), Fortaleza em 2 e Oiapoque sem rota.

```bash
~/LPEDC/rodar 16-grafos/lista/P1611.c
```

---

**Exercício P1612** · ★★☆ · Os links do site: os quatro tipos de aresta

O site de uma loja de açaí tem sete páginas, e cada link é uma seta
(grafo DIRIGIDO), guardada na matriz do esqueleto. Rode uma DFS (laço
principal e vizinhos em ordem de índice) e classifique cada link no momento
em que ele é examinado, de u para v:

- ÁRVORE: v é branco (a DFS desce por ele);
- RETORNO: v é cinza (v é ancestral de u: ciclo);
- AVANÇO: v é preto e d[u] < d[v] (v é descendente de u já terminado);
- CRUZAMENTO: v é preto e d[u] > d[v] (outro ramo ou outra árvore).

Mostre cada link com o tipo, na ordem em que a DFS os examina, e a contagem
de cada tipo.


```text
Saída esperada:
Home     -> Blog     árvore
Blog     -> Post     árvore
Post     -> Home     retorno
Post     -> Contato  árvore
Home     -> Loja     árvore
Loja     -> Contato  cruzamento
Loja     -> Carrinho árvore
Carrinho -> Loja     retorno
Home     -> Post     avanço
Ajuda    -> Home     cruzamento
Ajuda    -> Contato  cruzamento
árvore 5, retorno 2, avanço 1, cruzamento 3
```

**Dicas:**

1. Use enum { BRANCO, CINZA, PRETO }, d[] e um relógio, como no Cormen.
2. Classifique ANTES da chamada recursiva: depois dela, v já virou preto.
3. Avanço e cruzamento só existem em grafo dirigido; num não dirigido toda
   aresta é de árvore ou de retorno.
4. Resposta esperada: 5 de árvore, 2 de retorno, 1 de avanço e 3 de
   cruzamento (11 links).

```bash
~/LPEDC/rodar 16-grafos/lista/P1612.c
```

---

**Exercício P1613** · ★★☆ · Dois turnos de prova e a aresta que estraga

A coordenação quer marcar as provas finais em DOIS turnos, manhã e tarde.
Duas disciplinas com alunos em comum (uma aresta do grafo não dirigido) não
podem cair no mesmo turno. Isso só é possível se o grafo for BIPARTIDO.

Escreva bool bipartido(int adj[V][V], int turno[]), que colore o grafo com
BFS (turno 0 = manhã, 1 = tarde), começando uma BFS nova em cada vértice
ainda sem turno (o grafo pode ter vários componentes). Ao achar uma aresta
com as duas pontas no mesmo turno, mostre essa aresta e devolva false.

Teste no grafo do esqueleto e, depois, no mesmo grafo com a aresta extra
Calculo-Fisica.


```text
Saída esperada:
Bipartido:
  Calculo     manhã
  Algoritmos  tarde
  Fisica      manhã
  Discreta    tarde
  Ingles      manhã
  Estatistica tarde
Com Calculo-Fisica:
Conflito: Algoritmos-Fisica no mesmo turno
Não é bipartido
```

**Dicas:**

1. Comece com turno[v] = -1. A raiz de cada BFS recebe 0; cada vizinho
   novo recebe 1 - turno[u].
2. Se o vizinho já tem turno e é igual ao de u, a aresta fecha um ciclo de
   tamanho ímpar: não existe divisão em dois turnos.
3. Os vértices sem nenhuma aresta (ou de outro componente) precisam da
   BFS nova: sem ela ficam com -1.
4. Resposta esperada: o primeiro grafo é bipartido; o segundo não, e a
   aresta que estraga aparece ao examinar Algoritmos-Fisica.

```bash
~/LPEDC/rodar 16-grafos/lista/P1613.c
```

---

**Exercício P1614** · ★★☆ · O anel na rede de água: ache e mostre o ciclo

A rede de canos de água de um bairro liga sete pontos (não dirigido). Para
a manutenção, interessa saber se existe um ANEL (ciclo) e por onde ele
passa: num anel, a água chega a um ponto por dois caminhos.

Escreva uma DFS com pai[] que, ao achar uma aresta u-v com v já visitado e
v != pai[u] (aresta de retorno), mostre o ciclo inteiro subindo por pai[] de
u até v. Pare na primeira que achar. Rode na rede do esqueleto e, depois,
sem o cano Valvula-Caixa.


```text
Saída esperada:
Ciclo: Posto -> Escola -> Caixa -> Valvula -> Posto
Sem Valvula-Caixa: sem ciclo
```

**Dicas:**

1. Num grafo não dirigido, a aresta para o pai não conta: é o mesmo cano
   por onde a DFS chegou.
2. Quando u enxerga um v visitado que não é o pai, v é um ancestral de u
   na árvore da DFS. Subir de u por pai[] até v percorre o ciclo.
3. Use uma variável global achou para parar a DFS assim que o ciclo for
   mostrado.
4. Resposta esperada: Posto -> Escola -> Caixa -> Valvula -> Posto (a DFS
   desce Reservatorio, Valvula, Caixa, Escola, Posto, e Posto enxerga
   Valvula) e, sem o cano, "sem ciclo".

```bash
~/LPEDC/rodar 16-grafos/lista/P1614.c
```

---

**Exercício P1615** · ★★☆ · Dijkstra do centro de distribuição, com a rota

Um centro de distribuição (CD) no Distrito Industrial de Manaus entrega em
seis bairros. As ruas são de mão dupla, com a distância em km na matriz
peso[][] do esqueleto (0 = não há rua direta).

Escreva o Dijkstra O(V²), sem heap: a cada rodada, escolha o vértice NÃO
FECHADO de menor dist, feche-o e relaxe as arestas que saem dele, guardando
pi[]. Depois mostre, para cada bairro, a distância e a rota a partir do CD
(use uma função recursiva para imprimir a rota na ordem certa).


```text
Saída esperada:
Japiim        4 km: CD -> Japiim
Coroado       6 km: CD -> Japiim -> Coroado
Aleixo        9 km: CD -> Japiim -> Coroado -> Aleixo
Centro       13 km: CD -> Japiim -> Centro
Flores       15 km: CD -> Japiim -> Coroado -> Aleixo -> Flores
Ponta Negra  25 km: CD -> Japiim -> Coroado -> Aleixo -> Flores -> Ponta Negra
```

**Dicas:**

1. dist[CD] = 0 e dist[v] = INF para os outros. São V rodadas, e cada uma
   varre o vetor dist[] inteiro: O(V²), bom para grafos densos.
2. Relaxar u-v: se dist[u] + peso[u][v] < dist[v], então dist[v] =
   dist[u] + peso[u][v] e pi[v] = u.
3. Para a rota: rota(v) chama rota(pi[v]) antes de imprimir v, se pi[v]
   não é -1.
4. Resposta esperada: Ponta Negra a 25 km, por CD -> Japiim -> Coroado ->
   Aleixo -> Flores -> Ponta Negra; o Centro sai mais perto pelo Japiim
   (13 km) do que pelo Aleixo (14 km).

```bash
~/LPEDC/rodar 16-grafos/lista/P1615.c
```

---

**Exercício P1616** · ★★☆ · Conserte o Dijkstra das balsas

Conserte o programa. Ele calcula o menor tempo de viagem de balsa, em
horas, saindo de Manaus para cidades do Amazonas (trechos de ida e volta,
peso 0 = não há balsa direta). O código tem DOIS erros de propósito: um na
escolha do próximo vértice e outro no relaxamento. Ele termina e não tem
erro de memória, mas a resposta está errada:


```text
Saída que aparece:
Manacapuru   3 h
Itacoatiara  6 h
Parintins   18 h
Coari       30 h
Tefe         0 h
```


Depois do conserto:


```text
Saída esperada:
Manacapuru   3 h
Itacoatiara  6 h
Parintins   16 h
Coari       23 h
Tefe        35 h
```

**Dicas:**

1. Olhe a escolha do mínimo: um vértice já fechado continua com o menor
   dist para sempre. Se ele puder ser escolhido de novo, o algoritmo nunca
   sai do lugar.
2. Na matriz, peso 0 quer dizer "não há aresta". Um relaxamento que não
   testa isso acha que existe uma balsa de 0 horas entre quaisquer duas
   cidades.
3. Um bom teste: Tefe não tem balsa direta de Manaus. Se aparecer com 0 h,
   o relaxamento está usando uma aresta que não existe.
4. Resposta esperada: Manacapuru 3 h, Itacoatiara 6 h, Parintins 16 h,
   Coari 23 h, Tefe 35 h.

```bash
~/LPEDC/rodar 16-grafos/lista/P1616.c
```

---

**Exercício P1617** · ★★☆ · Amigos de amigos: o quadrado do grafo

A sugestão de amizade de uma rede social mostra "amigos de amigos". Em
grafos, isso é o QUADRADO do grafo: G² tem a aresta i-j (i != j) quando G
tem um caminho de uma ou duas arestas entre i e j.

Escreva void quadrado(int g[V][V], int q[V][V]), que monta G² pela matriz em
O(V³), e um main que mostre as arestas de G, as de G² e as SUGESTÕES (as
arestas de G² que não estão em G), cada par uma vez.


```text
Saída esperada:
Arestas em G: 5 | em G²: 10
Sugestões:
  Aline-Caua
  Aline-Flora
  Bento-Dora
  Caua-Edson
  Caua-Flora
```

**Dicas:**

1. q[i][j] = 1 se g[i][j] == 1 ou se existe k com g[i][k] && g[k][j].
2. É o produto de matrizes trocando "soma" por "ou" e "vezes" por "e":
   por isso custa O(V³).
3. Não esqueça de deixar a diagonal em 0: i é vizinho de vizinho de si
   mesmo, mas ninguém recebe sugestão de amizade consigo.
4. Resposta esperada: 5 arestas em G, 10 em G², e 5 sugestões, começando
   por Aline-Caua e Aline-Flora.

```bash
~/LPEDC/rodar 16-grafos/lista/P1617.c
```

---

**Exercício P1618** · ★★☆ · O caminho do entregador desenhado na grade

O mapa de um condomínio virou uma grade: # é muro, . é passagem, S é a
portaria e E é o bloco da entrega. O entregador anda uma casa por vez, na
horizontal ou na vertical. Cada casa é um vértice e cada vizinha livre é
uma aresta: é um grafo, mesmo sem matriz de adjacência.

Rode uma BFS a partir de S, guardando o pai de cada casa (casa = l * C + c),
e mostre o número de passos até E e o mapa com o caminho marcado com *
(sem apagar S e E). Examine as direções na ordem cima, baixo, esquerda,
direita.


```text
Saída esperada:
Passos: 16
S**#****
.#*#*##*
.#***#**
.##.#.*#
....#.E.
```

**Dicas:**

1. Os vizinhos saem de dois vetores: dl[] = {-1, 1, 0, 0} e
   dc[] = {0, 0, -1, 1}. Confira os limites da grade antes de ler mapa[][].
2. A fila guarda o número da casa; l = casa / C e c = casa % C.
3. Para marcar o caminho, ande de E para trás por pai[] até chegar em S,
   trocando cada '.' por '*'.
4. Resposta esperada: 16 passos e o mapa acima.

```bash
~/LPEDC/rodar 16-grafos/lista/P1618.c
```

---

**Exercício P1619** · ★★☆ · Instrumente: a BFS na matriz e na lista

A BFS custa O(V²) com matriz e O(V + E) com lista de adjacência. Confira
isso contando operações. O esqueleto tem uma BFS na matriz. Faça três
coisas:

1. Acrescente um contador global consultas que soma 1 a cada vez que a BFS
OLHA uma posição adj[u][v] da matriz.
2. Escreva bfs_lista(), a mesma BFS sobre uma lista de adjacência com
malloc, contando 1 a cada nó de lista visitado.
3. Rode as duas num "grafo caminho" (a linha de ônibus que vai parando:
0-1, 1-2, ..., (n-2)-(n-1)) com n = 10, 100 e 1000, conferindo que as
duas BFS dão o mesmo d[n - 1].


```text
Saída esperada:
n =   10: matriz d =   9,     100 consultas | lista d =   9,   18 consultas
n =  100: matriz d =  99,   10000 consultas | lista d =  99,  198 consultas
n = 1000: matriz d = 999, 1000000 consultas | lista d = 999, 1998 consultas
```

**Dicas:**

1. Na matriz, cada vértice que sai da fila varre a linha inteira: V
   consultas por vértice, V² no total, tenha o grafo muitas arestas ou não.
2. Na lista, cada vértice percorre só os seus vizinhos: a soma dos graus,
   que é 2E. No grafo caminho, E = n - 1.
3. A matriz de 1000 × 1000 pode ser global e de char (1 MB); a lista cabe
   em 2E nós. Libere a lista no fim de cada rodada.
4. Resposta esperada: com n = 1000, a matriz faz 1000000 consultas e a
   lista 1998, e as duas dão d = 999.

```bash
~/LPEDC/rodar 16-grafos/lista/P1619.c
```

---

**Exercício P1620** · ★★☆ · A celebridade da festa em O(V)

Na festa de lançamento de um livro, conhece[i][j] == 1 quer dizer que i
conhece j (grafo DIRIGIDO: conhecer não é recíproco). A CELEBRIDADE é quem
todos conhecem e não conhece ninguém: em grafos, um vértice com grau de
entrada V - 1 e grau de saída 0 (o "sumidouro universal" do Cormen).

Olhar a matriz inteira custa V² consultas. Escreva int celebridade(int
c[V][V]) com no máximo 3(V - 1) consultas: devolve o índice ou -1. Conte as
consultas e teste nas duas festas do esqueleto.


```text
Saída esperada:
Festa 1: Rubem (15 consultas de 36)
Festa 2: sem celebridade (13 consultas de 36)
```

**Dicas:**

1. Eliminação: comece com candidato = 0. Para i de 1 a V - 1, se o
   candidato conhece i, ele não é celebridade (e i ainda pode ser): troque o
   candidato por i. Se não conhece, i não é celebridade (alguém não o
   conhece). Cada consulta elimina uma pessoa: V - 1 consultas.
2. Sobra um candidato, que ainda precisa ser conferido: para todo i !=
   candidato, c[candidato][i] == 0 e c[i][candidato] == 1. Mais 2(V - 1)
   consultas, no máximo.
3. Faça a consulta passar por uma função que soma 1 num contador global.
4. Resposta esperada: na festa 1 a celebridade é Rubem, com 15 consultas
   (5 na eliminação + 10 na conferência, de 36 da matriz inteira);
   na festa 2 não há celebridade.

```bash
~/LPEDC/rodar 16-grafos/lista/P1620.c
```

## ★★★ Desafio

**Exercício P1621** · ★★★ · As duas jarras do vendedor de caldo de cana

Na feira, o vendedor de caldo de cana só tem uma jarra de 3 L e outra de
5 L, sem marcação, e um cliente pediu exatamente 4 L. Ele pode, a cada
passo: encher uma jarra, esvaziar uma jarra, ou despejar uma na outra até a
de origem esvaziar ou a de destino encher.

Isso é um grafo implícito: cada ESTADO (a, b), com a litros na primeira
jarra e b na segunda, é um vértice, e cada operação é uma aresta dirigida.
A BFS a partir de (0, 0) acha a sequência com o MENOR número de passos.

Escreva void jarras(int A, int B, int alvo), que roda a BFS no grafo de
estados (estado = a * (B + 1) + b), para no primeiro estado com a == alvo
ou b == alvo, e mostra os passos, ou "impossível". Tente as operações nesta
ordem: enche A, enche B, esvazia A, esvazia B, A -> B, B -> A. Mostre
também quantos estados a BFS descobriu. Rode jarras(3, 5, 4) e
jarras(4, 6, 3).


```text
Saída esperada:
Jarras de 3 L e 5 L, alvo 4 L: 6 passos (15 estados descobertos)
  enche B   -> (0, 5)
  B -> A    -> (3, 2)
  esvazia A -> (0, 2)
  B -> A    -> (2, 0)
  enche B   -> (2, 5)
  B -> A    -> (3, 4)
Jarras de 4 L e 6 L, alvo 3 L: impossível (10 estados descobertos)
```

**Dicas:**

1. São (A + 1)(B + 1) estados no máximo; os vetores dist[], pai[] e op[]
   (a operação que levou até ali) cabem num tamanho fixo, como 11 * 11.
2. Despejar A em B: passa x = min(a, B - b) litros; o novo estado é
   (a - x, b + x).
3. Para mostrar o caminho, guarde em pai[] o estado anterior e em op[] o
   nome da operação; percorra de trás para frente para um vetor e imprima
   ao contrário.
4. Com 4 L e 6 L, todo estado alcançável tem quantidades pares: 3 L é
   impossível, e a BFS termina sem achar o alvo.
5. Resposta esperada: 4 L em 6 passos (enche B, B -> A, esvazia A, B -> A,
   enche B, B -> A, terminando em (3, 4)); 3 L com 4 e 6 é impossível.

```bash
~/LPEDC/rodar 16-grafos/lista/P1621.c
```

---

**Exercício P1622** · ★★★ · O cavalo do torneio de xadrez da escola

No torneio de xadrez da escola, o desafio é levar o cavalo de a1 até h8 com
o menor número de lances. Cada casa do tabuleiro 8 × 8 é um vértice, e o
cavalo liga uma casa às (até) oito casas em "L" a partir dela: um grafo em
grade sem matriz de adjacência, com os vizinhos calculados na hora.

Escreva um programa que rode uma BFS a partir de a1 e mostre:

- o tabuleiro com o número mínimo de lances até cada casa (linha 8 em
cima, coluna a à esquerda);
- quantas casas ficam à distância máxima, e qual é essa distância;
- um caminho mínimo de a1 até h8, com as casas na notação do xadrez.

Use os saltos nesta ordem: (+1,+2), (+2,+1), (+2,-1), (+1,-2), (-1,-2),
(-2,-1), (-2,+1), (-1,+2), com (coluna, linha).


```text
Saída esperada:
8  5 4 5 4 5 4 5 6
7  4 3 4 3 4 5 4 5
6  3 4 3 4 3 4 5 4
5  2 3 2 3 4 3 4 5
4  3 2 3 2 3 4 3 4
3  2 1 4 3 2 3 4 5
2  3 4 1 2 3 4 3 4
1  0 3 2 3 2 3 4 5
   a b c d e f g h
Distância máxima: 6 lances (1 casa)
a1 até h8 em 6 lances: a1 b3 c5 d7 f8 g6 h8
```

**Dicas:**

1. Numere a casa como linha * 8 + coluna, com a1 = 0 e h8 = 63. Na
   notação, a coluna vira 'a' + coluna e a linha vira '1' + linha.
2. Para imprimir com a linha 8 em cima, percorra as linhas de 7 até 0.
3. A BFS dá UM caminho mínimo, e qual ele é depende da ordem dos saltos;
   o número de lances não depende.
4. Resposta esperada: h8 a 6 lances de a1, e é a única casa tão longe:
   o canto oposto.

```bash
~/LPEDC/rodar 16-grafos/lista/P1622.c
```

---

**Exercício P1623** · ★★★ · Dijkstra com heap indexado e diminuir-chave

O Dijkstra do Cormen põe TODOS os vértices numa fila de prioridade mínima
pela chave dist e, a cada relaxamento que melhora dist[v], chama
DIMINUIR-CHAVE(v). Com heap binário, cada operação custa O(lg V), e o total
fica O((V + E) lg V).

Para diminuir a chave de v é preciso saber ONDE v está no heap: guarde
pos[v] (o índice de v no vetor do heap, ou -1 se já saiu) e atualize pos[]
em toda troca.

Escreva esse Dijkstra com lista de adjacência (malloc) para as estradas
da região de Manaus (km, mão dupla, no esqueleto), saindo de Manaus. Mostre
a ordem em que os vértices saem do heap com a distância, e conte as
extrações e as chamadas de diminuir-chave.


```text
Saída esperada:
sai Manaus             0 km
sai Iranduba          27 km
sai Rio Preto da Eva  80 km
sai Manacapuru        87 km
sai Careiro          100 km
sai Pres. Figueiredo 107 km
sai Novo Airao       202 km
sai Itacoatiara      250 km
Extrações: 8 | diminuir-chave: 10
Itacoatiara: 250 km, chegando por Rio Preto da Eva
```

**Dicas:**

1. O heap guarda vértices em h[0..tam-1] e compara dist[h[i]]. Pai de i é
   (i - 1) / 2; filhos 2i + 1 e 2i + 2.
2. troca(i, j) troca h[i] com h[j] e acerta pos[h[i]] = i e pos[h[j]] = j.
   Esquecer o pos[] é o erro clássico: o diminuir-chave sobe o vértice
   errado.
3. diminuir_chave(v): dist[v] já diminuiu; suba a partir de pos[v]
   enquanto o pai tiver dist maior.
4. Ao contrário do heap "preguiçoso" (que empurra cópias), aqui o heap
   nunca passa de V itens e cada vértice sai uma vez só: V extrações.
5. Resposta esperada: 8 extrações e 10 diminuir-chave; Itacoatiara a 250
   km, por Rio Preto da Eva.

```bash
~/LPEDC/rodar 16-grafos/lista/P1623.c
```

---

**Exercício P1624** · ★★★ · Mesmo tempo, menos baldeações

O app de ônibus calcula o trajeto mais rápido do Terminal 1, no Centro, até
a Ponta Negra (minutos, mão dupla, no esqueleto). Só que há DOIS trajetos de
40 minutos: um com 4 trechos (4 ônibus) e outro com 2. O Dijkstra comum
fica com o que encontrar primeiro.

Escreva o Dijkstra O(V²) com uma chave de DOIS critérios: compare primeiro
o tempo e, no empate, o número de trechos. Mostre o trajeto do Dijkstra
comum e o do Dijkstra com desempate, com tempo e trechos.


```text
Saída esperada:
Comum: Terminal 1 -> Cachoeirinha -> Sao Jorge -> Dom Pedro -> Ponta Negra (40 min, 4 trechos)
Com desempate: Terminal 1 -> Alvorada -> Ponta Negra (40 min, 2 trechos)
```

**Dicas:**

1. Guarde dist[v] e trechos[v]. Uma função melhor(t1, b1, t2, b2) devolve
   true se t1 < t2, ou se t1 == t2 e b1 < b2.
2. Use essa função nos dois lugares: na escolha do próximo vértice e no
   relaxamento (o candidato é dist[u] + w com trechos[u] + 1).
3. Funciona porque a chave (tempo, trechos) só cresce ao andar por uma
   aresta de peso >= 0: a mesma condição que deixa o Dijkstra correto.
4. Faça uma função só com um parâmetro bool desempata, para não escrever o
   Dijkstra duas vezes.
5. Resposta esperada: o comum vai pelo Sao Jorge e Dom Pedro (4 trechos); o
   com desempate vai pelo Alvorada (2 trechos); os dois levam 40 min.

```bash
~/LPEDC/rodar 16-grafos/lista/P1624.c
```

---

**Exercício P1625** · ★★★ · Entrega com parada obrigatória na farmácia

Um motoboy sai da Loja, precisa PASSAR na Farmácia para pegar um remédio e
só então ir à casa do Cliente. As ruas do centro são de mão única (grafo
DIRIGIDO), com o tempo em minutos na matriz do esqueleto.

O caminho mínimo com parada obrigatória é o mínimo de Loja até Farmácia
emendado no mínimo de Farmácia até Cliente: rode o Dijkstra duas vezes, com
origens diferentes. Escreva um programa que mostre:

- o trajeto e o tempo direto Loja -> Cliente (sem a parada);
- o trajeto completo Loja -> ... -> Farmácia -> ... -> Cliente e o tempo;
- quantos minutos a parada custou a mais;
- o tempo de volta da Farmácia para a Loja, que NÃO é igual ao de ida
(mão única).


```text
Saída esperada:
Direto: Loja -> Praca -> Igreja -> Cliente (14 min)
Com a parada: Loja -> Praca -> Farmacia -> Mercado -> Cliente (9 + 13 = 22 min)
A parada custou 8 min a mais
Loja -> Farmacia: 9 min | Farmacia -> Loja: 13 min
```

**Dicas:**

1. Escreva dijkstra(s, dist, pi) e chame com s = Loja e com s = Farmacia.
   Guarde os resultados em vetores diferentes.
2. Para emendar, imprima o caminho até a Farmácia com o primeiro pi[] e o
   resto com o segundo, sem repetir a Farmácia.
3. Num grafo dirigido, dist(a, b) e dist(b, a) podem ser diferentes. A
   matriz não é simétrica.
4. Resposta esperada: direto 14 min; com a parada, 22 min (8 a mais); a
   volta Farmácia -> Loja leva 13 min, contra 9 da ida.

```bash
~/LPEDC/rodar 16-grafos/lista/P1625.c
```

---

**Exercício P1626** · ★★★ · O teorema dos parênteses no aeroporto

Os corredores do aeroporto de Manaus são de mão única (grafo DIRIGIDO,
vértices A a H no esqueleto). Rode a DFS do Cormen (laço principal e
vizinhos em ordem de índice) e escreva "(X" quando X é descoberto e "X)"
quando termina. O resultado é uma expressão de parênteses bem formada: é o
TEOREMA DOS PARÊNTESES. Para dois vértices u e v, os intervalos [d, f] ou
são disjuntos, ou um está inteiro dentro do outro, e v é descendente de u
na floresta da DFS exatamente quando d[u] < d[v] < f[v] < f[u].

Mostre:

- a expressão de parênteses;
- d/f de cada vértice;
- quantos pares {u, v} têm intervalos aninhados, quantos disjuntos e
quantos se cruzam "pela metade" (tem de dar 0);
- os descendentes de B pelo teste dos intervalos e, para conferir, subindo
por pi[] de cada vértice até achar (ou não) o B.


```text
Saída esperada:
(A (B (C (D (E E) D) C) B) A) (F F) (G (H H) G)
A  1/10
B  2/ 9
C  3/ 8
D  4/ 7
E  5/ 6
F 11/12
G 13/16
H 14/15
Pares: 11 aninhados, 17 disjuntos, 0 cruzados
Descendentes de B (intervalos): C D E
Descendentes de B (pi):         C D E
```

**Dicas:**

1. Ponha os printf de "(X" e "X)" nos mesmos lugares em que d[u] e f[u]
   recebem ++relogio.
2. Para cada par i < j: aninhado se um intervalo contém o outro; disjunto
   se f[i] < d[j] ou f[j] < d[i]; senão, cruzado.
3. v é descendente de u pelo pi[] se, subindo v, pi[v], pi[pi[v]], ...,
   aparece u antes de -1.
4. Com 8 vértices há 28 pares. Os que estão na mesma linha de ancestrais
   são aninhados (os 10 pares da cadeia A-B-C-D-E e o par G-H); o resto é
   disjunto.
5. Resposta esperada: três árvores, (A ... A) (F F) (G (H H) G); 11 pares
   aninhados, 17 disjuntos, 0 cruzados; descendentes de B: C D E.

```bash
~/LPEDC/rodar 16-grafos/lista/P1626.c
```

---

**Exercício P1627** · ★★★ · Quem alcança quem no centro histórico

No centro histórico de Manaus, as ruas do esqueleto são de mão única
(grafo DIRIGIDO). A prefeitura quer duas respostas:

1. O FECHO TRANSITIVO: alc[u][v] == 1 se dá para ir de u até v (u sempre
alcança a si mesmo). Calcule rodando uma BFS a partir de CADA vértice:
V buscas de O(V + E) cada, com lista de adjacência. Use a matriz só
para guardar o resultado.
2. Os GRUPOS DE IDA E VOLTA: u e v estão no mesmo grupo quando alc[u][v] e
alc[v][u]. Mostre cada grupo uma vez (rotule com o menor índice) e diga
quantos pares (u, v), u != v, têm caminho de u para v.


```text
Saída esperada:
de \ para    0 1 2 3 4 5 6
0 Teatro     1 1 1 1 1 1 1
1 Praca      1 1 1 1 1 1 1
2 Palacio    0 0 1 1 1 1 1
3 Mercado    0 0 0 1 1 1 1
4 Porto      0 0 0 1 1 1 1
5 Alfandega  0 0 0 1 1 1 1
6 Matriz     0 0 0 0 0 0 1
Grupo: Teatro Praca
Grupo: Palacio
Grupo: Mercado Porto Alfandega
Grupo: Matriz
Grupos de ida e volta: 4 | pares com caminho: 25
```

**Dicas:**

1. Monte a lista de adjacência a partir de ruas[] com malloc e libere no
   fim. A BFS a partir de s marca alc[s][v] = 1 para cada v descoberto.
2. Os grupos são as COMPONENTES FORTEMENTE CONEXAS. Aqui elas saem do fecho
   em O(V²), sem algoritmo novo: grupo[v] = o menor u com alc[u][v] e
   alc[v][u].
3. Um grupo com um vértice só é um ponto de onde se sai e não se volta.
4. Resposta esperada: 4 grupos ({Teatro, Praca}, {Palacio}, {Mercado, Porto,
   Alfandega}, {Matriz}) e 25 pares com caminho.

```bash
~/LPEDC/rodar 16-grafos/lista/P1627.c
```

---

**Exercício P1628** · ★★★ · A rede de fibra do campus é uma árvore?

A rede de fibra de um campus liga seis prédios (não dirigido). Ela é uma
ÁRVORE quando é conexa e não tem ciclo; aí tem exatamente V - 1 cabos. Mas
a recíproca engana: ter V - 1 cabos não basta.

Escreva void diagnostico(const char *titulo, int cabos[][2], int e), que
monta a matriz, roda uma DFS por componente e mostra:

- V, E e o número de componentes;
- cada cabo que fecha ciclo (aresta de retorno, mostrada uma vez só);
- se é árvore; se não for, quantos cabos sobram (E - (V - componentes)) e
quantos faltam para ligar tudo (componentes - 1).

Rode nas três redes do esqueleto.


```text
Saída esperada:
Rede A:
  V = 6, E = 5, componentes = 1
  é árvore
Rede B:
  ciclo fechado por ICE-Reitoria
  V = 6, E = 5, componentes = 2
  não é árvore: sobram 1 cabo(s) (E - (V - comp) = 1), faltam 1
Rede C:
  ciclo fechado por Restaurante-Biblioteca
  ciclo fechado por Hospital-Reitoria
  V = 6, E = 7, componentes = 1
  não é árvore: sobram 2 cabo(s) (E - (V - comp) = 2), faltam 0
```

**Dicas:**

1. Uma DFS com pai[] e d[]: ao ver um vizinho v já visitado, com v !=
   pai[u] e d[v] < d[u], a aresta u-v é de retorno. O teste d[v] < d[u]
   evita mostrar o mesmo cabo duas vezes (quando a DFS o vê do outro lado).
2. Cada componente com k vértices tem uma árvore da DFS com k - 1 arestas.
   Logo, as arestas de árvore somam V - componentes, e as de retorno são o
   resto: E - (V - componentes).
3. A rede B é a pegadinha: tem 5 cabos (V - 1), mas um ciclo e dois
   componentes.
4. Resposta esperada: A é árvore; B tem 2 componentes e o ciclo fechado por
   ICE-Reitoria; C tem 2 cabos sobrando (Restaurante-Biblioteca e
   Hospital-Reitoria, nessa ordem da DFS).

```bash
~/LPEDC/rodar 16-grafos/lista/P1628.c
```

---

**Exercício P1629** · ★★★ · Três representações do mesmo bairro em grade

Um bairro planejado tem ruas em grade: 30 × 30 esquinas, cada esquina
ligada às vizinhas de cima, baixo, esquerda e direita (não dirigido). A
esquina (l, c) é o vértice l * 30 + c.

Escreva um programa que:

1. gere a LISTA DE ARESTAS da grade (cada rua uma vez, como par u-v);
2. converta a lista de arestas em MATRIZ de adjacência e em LISTA de
adjacência (malloc);
3. rode a BFS a partir da esquina 0 nas duas representações, contando as
consultas (posições da matriz olhadas / nós de lista visitados), e
confira que o d[] de todos os 900 vértices bate;
4. mostre a memória de cada representação, calculada com sizeof, e quanto
a matriz ocuparia numa grade de 1000 × 1000.


```text
Saída esperada:
V = 900, E = 1740
BFS: d máximo 58 | d igual nas duas: sim
Consultas: matriz 810000, lista 3480
Memória: arestas 13920 bytes, lista 62880 bytes, matriz 3240000 bytes
Grade 1000 x 1000: matriz de 4000000000000 bytes
```

**Dicas:**

1. Arestas da grade: para cada esquina, a da direita (se c + 1 < 30) e a
   de baixo (se l + 1 < 30). São 2 · 30 · 29 = 1740 ruas.
2. A matriz de 900 × 900 int tem 3,24 MB: deixe-a global (ou static), não
   na pilha.
3. Memória: matriz V² · sizeof(int); lista V · sizeof(No *) + 2E ·
   sizeof(No); arestas E · 2 · sizeof(int). Num sistema de 64 bits,
   sizeof(No) é 16 (int + ponteiro, com 4 bytes de alinhamento).
4. Resposta esperada: d máximo 58 (o canto oposto), 810000 consultas na
   matriz contra 3480 na lista, e a grade de um milhão de esquinas pediria
   4 TB de matriz.

```bash
~/LPEDC/rodar 16-grafos/lista/P1629.c
```

---

**Exercício P1630** · ★★★ · Fuga do incêndio no galpão

Um galpão em grade pegou fogo. # é parede, F é onde há fogo agora, P é a
pessoa e . é passagem. A cada minuto, o fogo se espalha para as casas
vizinhas (cima, baixo, esquerda, direita) e a pessoa anda uma casa. Ela
escapa ao chegar a uma casa da BORDA da grade e sair por ela, e só pode
entrar numa casa se chegar ANTES do fogo (chegar no mesmo minuto não vale).

São duas BFS em grade:

1. uma BFS com VÁRIAS origens (todas as casas F entram na fila no tempo 0)
calcula fogo[casa], o minuto em que o fogo chega;
2. uma BFS a partir de P anda só por casas com passo < fogo[casa].

Escreva int fuga(char mapa[][C + 1]), que devolve o número de minutos até
sair (passos até a casa da borda + 1 para sair), ou -1. Mostre também o
mapa do fogo (minuto em que chega em cada casa, # nas paredes) para o
primeiro galpão. Rode nos dois galpões do esqueleto.


```text
Saída esperada:
Fogo no galpão 1 (minuto em que chega):
  #  #  #  3  #  #  #  #  #
  #  0  1  2  #  8  9 10  #
  #  1  #  3  #  7  # 11  #
  #  2  3  4  5  6  # 12 13
  #  #  #  #  #  #  #  #  #
Galpão 1: 9 minutos
Galpão 2: -1
```

**Dicas:**

1. Casas que o fogo nunca alcança ficam com fogo = INT_MAX (ou um número
   grande): a pessoa sempre pode entrar nelas.
2. Na BFS da pessoa, a casa v só entra se passo[u] + 1 < fogo[v]. A
   própria P está no tempo 0 e o fogo ainda não está nela.
3. Ao tirar da fila uma casa na borda (l == 0, l == L - 1, c == 0 ou
   c == C - 1), a resposta é passo + 1.
4. Resposta esperada: no galpão 1, a saída de cima (5 minutos sem fogo)
   está fechada pelo fogo, e a pessoa sai pela direita em 9 minutos; no
   galpão 2, o fogo fecha a única saída e a resposta é -1.

```bash
~/LPEDC/rodar 16-grafos/lista/P1630.c
```
