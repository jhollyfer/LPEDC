<!-- Gerado por _gerador a partir dos arquivos P????.c desta pasta. -->

# Lista prática · Módulo 29 · Grafos: ciclos e cortes; problemas difíceis

30 exercícios de codificar que treinam o módulo inteiro, misturando os assuntos, no ritmo da prova do PPGI (veja [PPGI.md](../../PPGI.md)). Cada arquivo `P????.c` desta pasta é um exercício: a resposta vai dentro dele, embaixo de `// Escreva sua resposta abaixo:`. Uma resolução de cada um está em `_respostas/29-grafos-e-np/lista/`. Só olhe depois de tentar.

[Voltar ao módulo](../README.md)

## ★☆☆ Aquecimento

**Exercício P2901** · ★☆☆ · Graus do metrô

O metrô tem sete estações (0 a 6): Sé, Luz, Brás, Arena, Parque, Vila e
Porto. Os trilhos, de mão dupla, ligam:


```text
Sé-Luz, Sé-Brás, Luz-Brás, Luz-Arena, Brás-Parque, Arena-Parque,
Parque-Vila, Arena-Vila, Vila-Porto
```


Escreva o programa do zero: mostre o grau de cada estação, a estação de
maior grau (a primeira, em caso de empate), a soma dos graus comparada
com 2E e quantas estações têm grau ímpar.


```text
Saída esperada:
Sé: 2
Luz: 3
Brás: 3
Arena: 3
Parque: 3
Vila: 3
Porto: 1
Maior grau: Luz (3)
Soma dos graus: 18 = 2 x 9
Estações de grau ímpar: 6
```

**Dicas:**

1. O grau de u é a soma da linha u da matriz de adjacência.
2. Pelo lema do aperto de mãos, a soma tem de ser 2 x 9 = 18, e o número de
   estações de grau ímpar tem de ser par.
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 29-grafos-e-np/lista/P2901.c
```

---

**Exercício P2902** · ★☆☆ · Fontes e sumidouros

A reforma de uma casa tem oito tarefas (0 a 7): Projeto, Demolição,
Elétrica, Hidráulica, Reboco, Piso, Pintura e Limpeza. A seta a -> b diz
"a precisa acabar antes de b":


```text
Projeto->Demolição, Demolição->Elétrica, Demolição->Hidráulica,
Elétrica->Reboco, Hidráulica->Reboco, Reboco->Piso, Reboco->Pintura,
Piso->Limpeza, Pintura->Limpeza
```


Escreva o programa: mostre o grau de entrada e o de saída de cada tarefa,
confira que as duas somas dão E e liste as FONTES (grau de entrada 0:
podem começar já) e os SUMIDOUROS (grau de saída 0: ninguém depende delas).


```text
Saída esperada:
Projeto: entrada 0, saída 1
Demolição: entrada 1, saída 2
Elétrica: entrada 1, saída 1
Hidráulica: entrada 1, saída 1
Reboco: entrada 2, saída 2
Piso: entrada 1, saída 1
Pintura: entrada 1, saída 1
Limpeza: entrada 2, saída 0
Somas: entrada 9, saída 9
Fontes: Projeto
Sumidouros: Limpeza
```

**Dicas:**

1. Entrada de u é a coluna u da matriz; saída, a linha u.
2. No dirigido, cada seta conta 1 na saída de quem sai e 1 na entrada de quem
   chega: as duas somas valem E = 9.
3. Resposta esperada: a saída acima. Num grafo sem ciclo existe sempre pelo
   menos uma fonte e um sumidouro.

```bash
~/LPEDC/rodar 29-grafos-e-np/lista/P2902.c
```

---

**Exercício P2903** · ★☆☆ · Passeio, trajeto ou caminho

No parque há seis quiosques (A a F) e as trilhas A-B, B-C, C-D, D-A, B-D,
D-E, E-F. Um corredor anota a sequência de quiosques por onde passou.
Escreva int classifica(const char *s), que devolve 0 se a sequência não é
um passeio (alguma trilha não existe), 1 para passeio (repete trilha), 2
para trajeto (repete quiosque, não trilha), 3 para caminho (não repete
nada). Se a sequência for fechada, os nomes viram passeio fechado,
circuito e ciclo. Mostre o nome e o COMPRIMENTO (número de trilhas).
Teste: ABCD, ABCDB, ABCDBA, ABCDA, DEFD.


```text
Saída esperada:
ABCD    caminho, comprimento 3
ABCDB   trajeto, comprimento 4
ABCDBA  passeio fechado, comprimento 5
ABCDA   ciclo, comprimento 4
DEFD    não é passeio, comprimento 3
```

**Dicas:**

1. O comprimento é o número de letras menos 1. Fechada: primeira letra igual
   à última.
2. Na fechada, não conte a última letra como repetição do quiosque (ela é a
   primeira de novo). Trilha repetida: o par (x, y) aparece de novo em
   qualquer ordem.
3. Resposta esperada: a saída acima. DEFD falha porque não existe a trilha
   F-D, por mais que a sequência pareça um triângulo.

```bash
~/LPEDC/rodar 29-grafos-e-np/lista/P2903.c
```

---

**Exercício P2904** · ★☆☆ · Diagnóstico de Euler por lista de arestas

Três prefeituras mandaram o mapa das ruas como lista de arestas (pode
haver duas ruas entre as mesmas esquinas). Para cada mapa, diga se o
caminhão da varrição consegue passar por toda rua uma vez e voltar
(circuito), passar por toda rua sem voltar (trajeto, dizendo de onde a
onde) ou nenhum dos dois:


```text
Mapa 1 (5 esquinas): 0-1, 1-2, 2-0, 2-3, 3-4, 4-2
Mapa 2 (5 esquinas): 0-1, 1-2, 2-3, 3-0, 0-2, 1-3, 1-4, 4-3
Mapa 3 (6 esquinas): 0-1, 1-2, 2-0, 3-4, 4-5, 5-3
```


Escreva void diagnostico(int nv, int ne, int a[][2]) e use-a nos três.


```text
Saída esperada:
Mapa 1: circuito
Mapa 2: trajeto de 0 a 2
Mapa 3: nenhum (desconexo)
```

**Dicas:**

1. Conte o grau percorrendo a lista: cada aresta soma 1 nas duas pontas.
   Para a conexidade, uma DFS em matriz montada a partir da lista basta
   (ignore esquinas de grau 0).
2. Conexo e 0 ímpares: circuito. Conexo e 2 ímpares: trajeto entre eles.
   Desconexo ou outro número de ímpares: nenhum.
3. Resposta esperada: a saída acima. O mapa 3 tem todos os graus pares e
   mesmo assim não tem circuito.

```bash
~/LPEDC/rodar 29-grafos-e-np/lista/P2904.c
```

---

**Exercício P2905** · ★☆☆ · Conferindo a rota do ônibus circular

O ônibus circular passa por seis pontos (0 a 5), numa cidade de ruas de
mão única. As ruas dirigidas são:


```text
0->1, 1->2, 2->3, 3->4, 4->5, 5->0, 1->4, 3->1, 4->2, 2->0
```


A empresa recebeu quatro propostas de rota (começando no ponto 0; a volta
ao 0 fica subentendida) e quer saber quais são ciclos hamiltonianos
DIRIGIDOS. Escreva o verificador bool valida(const int r[], int n), que
mostra "ok" ou o primeiro problema: "falta ponto", "repete o ponto X" ou
"não há rua X->Y" (inclusive na volta).


```text
A: 0 1 2 3 4 5     B: 0 1 4 2 3 1     C: 0 1 4 5 2 3     D: 0 1 4 2 3
```



```text
Saída esperada:
A: ok
B: repete o ponto 1
C: não há rua 5->2
D: falta ponto
```

**Dicas:**

1. Primeiro confira o tamanho (n == 6), depois as repetições com um vetor
   bool visto[], depois as ruas, inclusive a de r[n - 1] para r[0].
2. Num grafo dirigido, rua[x][y] = 1 não implica rua[y][x] = 1.
3. Resposta esperada: a saída acima. O verificador custa O(n): é por isso que
   o problema do ciclo hamiltoniano está em NP.

```bash
~/LPEDC/rodar 29-grafos-e-np/lista/P2905.c
```

---

**Exercício P2906** · ★☆☆ · Verificador de cobertura com limite

A versão de decisão da cobertura de vértices pergunta: "existe uma
cobertura com no máximo k vértices?". O certificado é a própria lista.
Uma rede tem sete roteadores (0 a 6) e os cabos:


```text
0-1, 0-2, 1-3, 2-3, 3-4, 4-5, 4-6, 5-6
```


Escreva bool confere(const int c[], int tam, int k), que mostra o
veredito e o primeiro cabo descoberto, se houver. Teste os certificados
{0, 3, 4, 5} com k = 4, {1, 2, 4, 6} com k = 4, {0, 3, 4, 6} com k = 3 e
{1, 2, 5, 6} com k = 4.


```text
Saída esperada:
aceito
aceito
rejeitado: 4 vértices, limite 3
rejeitado: cabo 3-4 descoberto
```

**Dicas:**

1. Marque os vértices do certificado num vetor bool e percorra os cabos:
   cada um precisa de pelo menos uma ponta marcada.
2. Confira o tamanho antes: um certificado maior que k é rejeitado mesmo que
   cubra tudo.
3. Resposta esperada: a saída acima. Conferir custa O(V + E); achar a menor
   cobertura é NP-difícil.

```bash
~/LPEDC/rodar 29-grafos-e-np/lista/P2906.c
```

---

**Exercício P2907** · ★☆☆ · Clique ou independente?

Numa turma de oito alunos (0 a 7), as amizades são:


```text
0-1, 0-2, 0-3, 1-2, 1-3, 2-3, 3-4, 4-5, 5-6, 6-7, 4-6
```


Escreva int tipo(const int s[], int k), que devolve 2 se o grupo é uma
clique (todos amigos entre si), 1 se é independente (nenhum par amigo) e
0 se não é nenhum dos dois, e mostre o resultado para os grupos
{0, 1, 2, 3}, {0, 4, 7}, {4, 5, 6}, {2, 5, 7} e {3, 4, 5}.


```text
Saída esperada:
{0, 1, 2, 3}: clique
{0, 4, 7}: independente
{4, 5, 6}: clique
{2, 5, 7}: independente
{3, 4, 5}: nenhum dos dois
```

**Dicas:**

1. Conte quantos dos k(k-1)/2 pares são amigos.
2. Todos os pares: clique. Nenhum: independente. Alguns: nenhum dos dois.
3. Resposta esperada: a saída acima. Os dois verificadores custam O(k²).

```bash
~/LPEDC/rodar 29-grafos-e-np/lista/P2907.c
```

---

**Exercício P2908** · ★☆☆ · Custo de uma ordem de multiplicação

Cinco matrizes têm dimensões p = 6, 2, 9, 4, 7, 3 (Ai é p[i-1] x p[i]).
Calcule, com uma função long custo_esq(int i, int j) e outra
long custo_dir(int i, int j), o número de multiplicações das duas ordens
"ingênuas": da esquerda para a direita, ((((A1 A2) A3) A4) A5), e da
direita para a esquerda, (A1 (A2 (A3 (A4 A5)))). Mostre também as
dimensões do resultado.


```text
Saída esperada:
Resultado: 6 x 3
Da esquerda: 618
Da direita: 282
```

**Dicas:**

1. Da esquerda: o acumulado é sempre p[0] x p[k]; juntar com A(k+1) custa
   p[0] · p[k] · p[k+1].
2. Da direita: o acumulado é p[k-1] x p[5]; juntar A(k-1) na frente custa
   p[k-2] · p[k-1] · p[5].
3. Resposta esperada: a saída acima. Nenhuma das duas é a ótima: a PD do
   0185 acha uma ordem com 206 multiplicações.

```bash
~/LPEDC/rodar 29-grafos-e-np/lista/P2908.c
```

---

**Exercício P2909** · ★☆☆ · O verificador do caixeiro viajante

A versão de decisão do caixeiro viajante é: "existe uma volta por todas
as cidades com custo no máximo L?". Cinco cidades (0 a 4) têm a matriz
de distâncias (km) do main abaixo; -1 quer dizer "sem estrada". Escreva
bool aceita(const int r[], int n, int limite), que confere o certificado
(é uma permutação das 5 cidades, toda estrada existe, a volta incluída)
e compara o custo com o limite. Teste:


```text
0 1 2 3 4 com L = 90      0 2 4 1 3 com L = 100
0 1 3 2 4 com L = 100     0 1 3 2 4 com L = 90
```



```text
Saída esperada:
aceito (custo 87)
rejeitado (sem estrada 4-1)
aceito (custo 94)
rejeitado (custo 94 > 90)
```

**Dicas:**

1. Use a matriz
   {{0, 12, 30, -1, 25}, {12, 0, 18, 20, -1}, {30, 18, 0, 15, 22},
   {-1, 20, 15, 0, 17}, {25, -1, 22, 17, 0}}.
2. Mostre "aceito (custo C)", "rejeitado (custo C > L)", "rejeitado (sem
   estrada X-Y)" ou "rejeitado (repete cidade)".
3. Resposta esperada: a saída acima. O mesmo certificado pode ser aceito
   para um L e rejeitado para outro.

```bash
~/LPEDC/rodar 29-grafos-e-np/lista/P2909.c
```

---

**Exercício P2910** · ★☆☆ · Mudança em caminhões

Uma família vai se mudar e o caminhão leva 12 m³ por viagem. Os volumes,
na ordem em que estão na sala, são 5, 7, 3, 8, 4, 2, 6, 3 m³. Escreva o
first fit decrescente (ordene uma cópia com qsort) e mostre o conteúdo de
cada viagem, quanto sobra nela e o limite inferior.


```text
Saída esperada:
Viagem 1: 8 4 (sobram 0)
Viagem 2: 7 5 (sobram 0)
Viagem 3: 6 3 3 (sobram 0)
Viagem 4: 2 (sobram 10)
Limite inferior: 4 viagens
```

**Dicas:**

1. Comparador decrescente: (x < y) - (x > y).
2. Limite inferior: soma 38, então (38 + 11) / 12 = 4 viagens.
3. Resposta esperada: a saída acima: o FFD bateu o limite inferior, logo é
   ótimo aqui.

```bash
~/LPEDC/rodar 29-grafos-e-np/lista/P2910.c
```

## ★★☆ Para pensar

**Exercício P2911** · ★★☆ · Circuito com ruas paralelas

O mapa da varrição tem cinco esquinas (0 a 4) e sete ruas, numeradas na
ordem da lista; entre 0 e 1 há duas ruas paralelas, e entre 2 e 4 também:


```text
r0: 0-1   r1: 1-0   r2: 1-2   r3: 2-3   r4: 3-1   r5: 2-4   r6: 4-2
```


A matriz 0/1 não guarda ruas paralelas, então trabalhe com a lista e um
vetor bool usada[7]. Escreva o Hierholzer com pilha: no topo u, pegue a
rua livre de MENOR número que toca u, marque-a e empilhe a outra ponta.
Mostre o circuito (esquinas) e a ordem das ruas usadas.


```text
Saída esperada:
Circuito: 0 1 2 4 2 3 1 0
Ruas: r0 r2 r5 r6 r3 r4 r1
```

**Dicas:**

1. Empilhe pares (esquina, rua pela qual chegou). Ao desempilhar, guarde a
   esquina e a rua: lidos de trás para frente, são o circuito e as ruas.
2. A outra ponta da rua k a partir de u é rua[k][0] + rua[k][1] - u.
3. Resposta esperada: a saída acima. Todos os graus são pares (2, 4, 4, 2,
   2), então o circuito existe.

```bash
~/LPEDC/rodar 29-grafos-e-np/lista/P2911.c
```

---

**Exercício P2912** · ★★☆ · Trajeto euleriano dirigido

Um barco de passeio faz trechos de rio que só podem ser navegados no
sentido da correnteza. Portos 0 a 4, trechos dirigidos:


```text
0->1, 1->2, 2->0, 0->3, 3->1, 1->4
```


O barco quer navegar todos os trechos uma vez cada, sem precisar voltar
ao início. Escreva o programa que mostra saída - entrada de cada porto,
escolhe o início (o porto com saída - entrada = 1; se todos forem 0, o
porto 0) e roda o Hierholzer dirigido a partir dele.


```text
Saída esperada:
Porto 0: saída - entrada = 1
Porto 1: saída - entrada = 0
Porto 2: saída - entrada = 0
Porto 3: saída - entrada = 0
Porto 4: saída - entrada = -1
Trajeto: 0 1 2 0 3 1 4
```

**Dicas:**

1. Trajeto euleriano dirigido (com o grafo conexo): no máximo um porto com
   saída - entrada = 1 (início), um com -1 (fim), o resto com 0.
2. O Hierholzer é o do texto, apagando só trecho[u][v] e escolhendo o
   destino de menor índice.
3. Resposta esperada: a saída acima. O trajeto termina no porto 4, o único
   com entrada - saída = 1.

```bash
~/LPEDC/rodar 29-grafos-e-np/lista/P2912.c
```

---

**Exercício P2913** · ★★☆ · Todos os caminhos hamiltonianos de s a t

Um fiscal precisa visitar as seis obras de uma avenida (0 a 5), cada uma
uma vez, saindo do escritório na obra 0 e terminando em casa, perto da
obra 5. As vias entre as obras são:


```text
0-1, 0-2, 1-2, 1-3, 2-3, 2-4, 3-4, 3-5, 4-5
```


Escreva o backtracking que lista TODOS os caminhos hamiltonianos de 0 a
5 (vizinhos em ordem de índice) e conta as chamadas da recursão.


```text
Saída esperada:
Caminho 1: 0 1 2 3 4 5
Caminho 2: 0 1 2 4 3 5
Caminho 3: 0 1 3 2 4 5
Caminho 4: 0 2 1 3 4 5
Total: 4 caminhos, 26 chamadas
```

**Dicas:**

1. Fixe rota[0] = 0. Quando a rota tiver os 6 vértices, aceite só se o
   último for 5. Pode podar antes: não entre no 5 enquanto faltarem outros.
2. Conte uma chamada no começo da função, antes de qualquer teste.
3. Resposta esperada: a saída acima (com a poda do 5).

```bash
~/LPEDC/rodar 29-grafos-e-np/lista/P2913.c
```

---

**Exercício P2914** · ★★☆ · Pontes com lista de adjacência

Uma rede de oito servidores (0 a 7) tem os cabos:


```text
0-1, 1-2, 2-0, 2-3, 3-4, 4-5, 5-3, 5-6, 6-7
```


Monte o grafo como LISTA de adjacência dinâmica (cada vértice com um vetor
alocado com malloc do tamanho do seu grau) e rode a DFS com tin e low a
partir do 0. Mostre as pontes, na ordem em que a DFS as acha, e as
articulações, em ordem de índice. Libere tudo no fim.


```text
Saída esperada:
Ponte: 6-7
Ponte: 5-6
Ponte: 2-3
Articulações: 2 3 5 6
```

**Dicas:**

1. Conte os graus primeiro, aloque vizinho[u] = malloc(grau[u] * sizeof(int))
   e depois preencha. Confira NULL.
2. As regras são as do texto: ponte se low[v] > tin[u]; articulação se
   low[v] >= tin[u] fora da raiz, ou raiz com 2 ou mais filhos.
3. Resposta esperada: a saída acima. Com lista, a DFS custa O(V + E) em vez
   de O(V²).

```bash
~/LPEDC/rodar 29-grafos-e-np/lista/P2914.c
```

---

**Exercício P2915** · ★★☆ · A rede é robusta?

Uma rede é "robusta" para a operadora quando é conexa e nenhum cabo
sozinho a desconecta (não tem ponte). Escreva void avalia(const char *nome,
int nv, int ne, int c[][2]) que conta os componentes e as pontes (uma
DFS com tin e low por componente) e dá o veredito. Teste:


```text
R1 (6 nós): 0-1, 1-2, 2-0, 3-4, 4-5, 5-3
R2 (6 nós): 0-1, 1-2, 2-0, 2-3, 3-4, 4-5, 5-3
R3 (6 nós): 0-1, 1-2, 2-3, 3-4, 4-5, 5-0, 0-3
```



```text
Saída esperada:
R1: 2 componente(s), 0 ponte(s): frágil
R2: 1 componente(s), 1 ponte(s): frágil
R3: 1 componente(s), 0 ponte(s): robusta
```

**Dicas:**

1. Zere tin[] a cada rede. O laço externo começa uma DFS em cada nó ainda
   não visitado: cada começo é um componente.
2. Robusta = 1 componente e 0 pontes.
3. Resposta esperada: a saída acima. R1 não tem ponte, mas está partida em
   dois; R2 está inteira, mas o cabo 2-3 é ponte.

```bash
~/LPEDC/rodar 29-grafos-e-np/lista/P2915.c
```

---

**Exercício P2916** · ★★☆ · Tabela de cortes e parênteses

Seis matrizes têm dimensões p = 20, 40, 10, 6, 15, 30, 12 (Ai é
p[i-1] x p[i]). Preencha m e s pela PD do 0185 (laço externo pelo
tamanho da cadeia) e mostre a tabela s (só i < j; "-" no resto, cada
casa com %3s ou %3d), o custo mínimo e a parentização ótima.


```text
Saída esperada:
Tabela s:
  -  1  1  3  3  3
  -  -  2  3  3  3
  -  -  -  3  3  3
  -  -  -  -  4  5
  -  -  -  -  -  5
  -  -  -  -  -  -
Custo mínimo: 13500
Ordem: ((A1 (A2 A3)) ((A4 A5) A6))
```

**Dicas:**

1. s[i][j] é o k do melhor corte entre Ak e Ak+1.
2. A parentização sai de uma função recursiva: se i == j mostre Ai; senão,
   "(" + metade da esquerda + " " + metade da direita + ")".
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 29-grafos-e-np/lista/P2916.c
```

---

**Exercício P2917** · ★★☆ · Contando as soluções de uma fórmula

A escala de um posto de saúde usa cinco variáveis (x1 a x5: cada médico
está ou não de plantão) e esta fórmula 3-CNF, guardada no formato +v/-v:


```text
(x1 ou x2 ou x3) (não x1 ou não x2 ou x4) (x2 ou não x3 ou x5)
(não x4 ou não x5 ou x1) (x3 ou x4 ou não x2) (não x1 ou não x3 ou não x5)
```


Escreva o verificador e a força bruta pelas 2^5 máscaras (bit v-1 é xv).
Mostre cada atribuição que satisfaz como uma sequência de 0 e 1 (x1 a
x5) e o total.


```text
Saída esperada:
10000
01100
10010
01010
11010
01110
11110
10001
00101
01101
10011
11011
Total: 12 de 32
```

**Dicas:**

1. Literal lit é verdadeiro se lit > 0 ? x[lit] : !x[-lit]; cláusula
   verdadeira se algum literal for; fórmula, se todas forem.
2. Percorra as máscaras de 0 a 31 em ordem e mostre x1 primeiro.
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 29-grafos-e-np/lista/P2917.c
```

---

**Exercício P2918** · ★★☆ · Clique pelo resolvedor de independente

Agora o contrário do 0187: você só tem uma caixa-preta que acha o MAIOR
CONJUNTO INDEPENDENTE (já pronta no esqueleto) e precisa achar a maior
clique de uma rede de colaboração entre sete pesquisadores (0 a 6):


```text
0-1, 0-2, 0-3, 1-2, 1-3, 2-3, 2-4, 3-4, 4-5, 5-6, 4-6
```


Complete o main: monte o complemento, chame maior_independente nele e
mostre a clique e o tamanho. Mostre também a menor cobertura de
vértices do COMPLEMENTO (o resto dos vértices).


```text
Saída esperada:
Maior clique: 0 1 2 3 (4)
Cobertura do complemento: 4 5 6 (3)
```

**Dicas:**

1. comp[a][b] = a != b && !g[a][b]. Independente no complemento é clique em
   G.
2. O bit v da máscara diz se v está no conjunto; o resto é todos & ~s.
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 29-grafos-e-np/lista/P2918.c
```

---

**Exercício P2919** · ★★☆ · Quão longe do ótimo fica a 2-aproximação?

Rode a cobertura de vértices 2-aproximada (arestas na ordem dada; aresta
descoberta -> as duas pontas entram) e a cobertura ótima por força bruta
em três grafos de 8 vértices, e mostre a razão:


```text
caminho: 0-1, 1-2, 2-3, 3-4, 4-5, 5-6, 6-7
estrela: 0-1, 0-2, 0-3, 0-4, 0-5, 0-6, 0-7
completo + caminho: 0-1, 0-2, 0-3, 1-2, 1-3, 2-3, 4-5, 5-6, 6-7
```


Escreva void compara(const char *nome, int ne, int a[][2]).


```text
Saída esperada:
caminho: aprox 8, ótimo 4, razão 2.00
estrela: aprox 2, ótimo 1, razão 2.00
completo + caminho: aprox 8, ótimo 5, razão 1.60
```

**Dicas:**

1. A força bruta testa as 256 máscaras e fica com a menor que cobre todas as
   arestas.
2. Mostre "aprox A, ótimo O, razão R" com R em %.2f.
3. Resposta esperada: a saída acima. A razão nunca passa de 2: no caminho e
   na estrela ela bate exatamente em 2; com o K4 ela cai.

```bash
~/LPEDC/rodar 29-grafos-e-np/lista/P2919.c
```

---

**Exercício P2920** · ★★☆ · Quatro heurísticas contra o ótimo

Nove encomendas (em kg) vão em motos que levam 10 kg: 6, 3, 7, 2, 5, 4,
5, 3, 5. Compare next fit, first fit, best fit e first fit decrescente
com o ótimo, que você acha por backtracking: tente pôr cada encomenda
(na ordem decrescente) em cada moto já aberta onde caiba ou numa nova, e
corte quando o número de motos já igualar o melhor achado.


```text
Saída esperada:
Next fit: 5
First fit: 5
Best fit: 5
First fit decrescente: 4
Ótimo: 4
```

**Dicas:**

1. Escreva cada heurística como int nome(const int x[], int n). O FFD chama o
   first fit numa cópia ordenada.
2. No backtracking, bt(i, motos) com livre[] global; ao abrir moto nova
   pela primeira vez já não adianta tentar abrir outra para o mesmo item.
3. Resposta esperada: a saída acima. Soma 40: o limite inferior é 4.

```bash
~/LPEDC/rodar 29-grafos-e-np/lista/P2920.c
```

## ★★★ Desafio

**Exercício P2921** · ★★★ · A raiz que não é articulação

Uma malha de ciclovias tem sete pontos (0 a 6) e os trechos:


```text
0-1, 1-2, 2-0, 1-3, 3-4, 4-1, 4-5, 5-6
```


Tirando o ponto 0, o resto continua ligado. Mas o programa abaixo, que
roda a DFS a partir do 0, diz que ele é articulação.


```text
Saída que aparece:
Articulações: 0 1 4 5
```



```text
Saída esperada:
Articulações: 1 4 5
```


O programa compila e roda sem erro; o problema é de lógica. Conserte-o.

**Dicas:**

1. Na raiz, low[v] >= tin[raiz] é sempre verdade: nada tem tin menor.
2. A raiz é articulação só se tiver 2 ou mais filhos na árvore da DFS. Conte
   os filhos (variável local) e aplique a regra comum só fora da raiz.
3. Resposta esperada: a saída esperada acima.

```bash
~/LPEDC/rodar 29-grafos-e-np/lista/P2921.c
```

---

**Exercício P2922** · ★★★ · A dimensão trocada

A cadeia tem quatro matrizes, p = 8, 20, 4, 30, 6 (Ai é p[i-1] x p[i]).
O programa abaixo segue a recorrência do 0185, mas devolve um custo e
uma ordem errados.


```text
Saída que aparece:
Custo: 3600
Ordem: (A1 ((A2 A3) A4))
```



```text
Saída esperada:
Custo: 1552
Ordem: ((A1 A2) (A3 A4))
```


O programa compila e roda sem erro; o problema é de lógica. Conserte-o.

**Dicas:**

1. Juntar (Ai..Ak) com (Ak+1..Aj) é multiplicar uma matriz de quantas linhas
   por quantas colunas?
2. A cadeia Ai..Aj começa com as linhas de Ai, que são p[i-1], não p[i].
3. Resposta esperada: a saída esperada acima.

```bash
~/LPEDC/rodar 29-grafos-e-np/lista/P2922.c
```

---

**Exercício P2923** · ★★★ · O carteiro e as duas esquinas ímpares

O carteiro precisa passar por toda rua do bairro e voltar ao correio
(esquina 0). Se o grafo tem exatamente duas esquinas ímpares, ele terá de
repetir ruas: o mínimo a mais é a distância mais curta entre essas duas
esquinas (problema do carteiro chinês). Ruas com o comprimento em metros:


```text
0-1 100, 1-2 80, 2-3 120, 3-0 90, 2-4 60, 4-5 70, 5-2 50, 1-4 200
```


Escreva o programa: some os comprimentos, ache as esquinas ímpares, rode
Floyd-Warshall (0155) e mostre a distância extra e o total percorrido.


```text
Saída esperada:
Ruas: 770 m
Esquinas ímpares: 1 e 4
Extra: 140 m
Total: 910 m
```

**Dicas:**

1. Use INF = 1000000 para "sem rua" e d[i][i] = 0 antes do Floyd.
2. Com 0 esquinas ímpares o extra seria 0 (circuito euleriano). Aqui são 2.
3. Resposta esperada: a saída acima. Repare que o carteiro não repete a rua
   1-4 (200 m): ele refaz 1-2-4, que soma 140 m.

```bash
~/LPEDC/rodar 29-grafos-e-np/lista/P2923.c
```

---

**Exercício P2924** · ★★★ · Código de Gray: um ciclo hamiltoniano no hipercubo

No hipercubo de dimensão 4, os vértices são os números de 0 a 15 e dois
são vizinhos quando diferem em exatamente um bit. O código de Gray,
g(i) = i ^ (i >> 1), percorre os 16 vértices formando um ciclo
hamiltoniano. Escreva o programa que gera a sequência, mostra cada
vértice em binário (4 dígitos) e confere com um verificador: 16 vértices
distintos, e cada vizinho da sequência (inclusive o último com o
primeiro) difere em um bit só.


```text
Saída esperada:
0000 0001 0011 0010 0110 0111 0101 0100
1100 1101 1111 1110 1010 1011 1001 1000
Ciclo hamiltoniano: sim
```

**Dicas:**

1. x e y diferem em um bit só quando z = x ^ y é potência de 2: z != 0 e
   (z & (z - 1)) == 0.
2. Mostre os bits com um laço de b = 3 até 0: (x >> b) & 1.
3. Resposta esperada: a saída acima. Para o hipercubo, achar o ciclo é fácil
   porque o grafo tem estrutura; o difícil é o caso geral.

```bash
~/LPEDC/rodar 29-grafos-e-np/lista/P2924.c
```

---

**Exercício P2925** · ★★★ · De 3-SAT para conjunto independente

Outra redução clássica: 3-SAT para CONJUNTO INDEPENDENTE. Cada literal de
cada cláusula vira um vértice; ligue (1) os três vértices de uma mesma
cláusula entre si (um triângulo) e (2) todo par de vértices
contraditórios (x e não x), em qualquer cláusula. A fórmula é
satisfatível se e só se o grafo tem um conjunto independente de tamanho
m (o número de cláusulas). Para


```text
(x1 ou x2 ou não x3) (não x1 ou x3 ou x4) (não x2 ou não x4 ou x3)
(x1 ou não x3 ou não x4)
```


monte o grafo, mostre quantas arestas ele tem, procure pela força bruta
(máscaras de 12 bits com exatamente 4 bits ligados, em ordem crescente)
o primeiro conjunto independente de tamanho 4 e traduza-o numa
atribuição (variável não escolhida fica falsa). Confira a atribuição na
fórmula.


```text
Saída esperada:
Grafo: 12 vértices, 21 arestas
Independente: x1 x3 não x2 x1
Atribuição: x1=V x2=F x3=V x4=F
Satisfaz a fórmula? sim
```

**Dicas:**

1. O vértice a é o literal f[a / 3][a % 3]. Aresta se a / 3 == b / 3 ou
   f(a) == -f(b).
2. Um independente de tamanho m pega exatamente um literal por cláusula (o
   triângulo impede dois) e nunca x junto com não x.
3. Resposta esperada: a saída acima. São 12 arestas dos triângulos mais as
   dos pares contraditórios.

```bash
~/LPEDC/rodar 29-grafos-e-np/lista/P2925.c
```

---

**Exercício P2926** · ★★★ · De ciclo hamiltoniano para caixeiro viajante

A redução que prova que o caixeiro viajante é NP-difícil: dado um grafo
G com n vértices, monte a matriz de custos d[a][b] = 1 se a-b é aresta
de G e 2 se não é. G tem ciclo hamiltoniano se e só se a volta mais
barata custa exatamente n. Escreva a redução e resolva o caixeiro pelo
Held-Karp, para dois grafos de 6 vértices:


```text
G1: 0-1, 0-2, 0-4, 1-2, 1-3, 2-3, 3-4, 3-5, 4-5   (as agências do 0183)
G2: 0-1, 1-2, 2-0, 0-3, 3-4, 4-0, 0-5, 5-1        (gravata com um extra)
```



```text
Saída esperada:
G1: volta mais barata = 6 -> tem ciclo hamiltoniano
G2: volta mais barata = 7 -> não tem
```

**Dicas:**

1. Uma função void decide(const char *nome, int ne, int a[][2]) monta d e
   chama o Held-Karp (dp[1 << 6][6], global).
2. Toda volta usa n trechos; cada trecho custa 1 ou 2. Custo n quer dizer
   que todos os trechos são arestas de G.
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 29-grafos-e-np/lista/P2926.c
```

---

**Exercício P2927** · ★★★ · Rota mais curta que termina em casa

O entregador da farmácia do 0189 não volta para a farmácia: depois da
última entrega ele vai para casa, que fica no ponto do Gil (índice 7).
Pontos (quarteirões): Farmácia (0,0), Ana (1,3), Bruno (4,4),
Clara (6,3), Dênis (7,0), Edna (5,1), Fábio (2,6), Gil (3,1).
Adapte o Held-Karp para CAMINHO hamiltoniano de 0 até 7: a resposta é
dp[todos][7], sem volta. Reconstrua a rota com uma tabela ant[][] e
compare com a volta fechada (28 quarteirões).


```text
Saída esperada:
Caminho até a casa: 24 quarteirões
Farmácia -> Ana -> Fábio -> Bruno -> Clara -> Dênis -> Edna -> Gil
Volta fechada era 28; terminar no Gil economiza 4
```

**Dicas:**

1. A PD é a mesma; só muda o fim: em vez de min sobre j de dp[todos][j] +
   d[j][0], pegue dp[todos][7].
2. Reconstrução: do (todos, 7), ant diz o anterior; apague o bit e repita até
   chegar ao 0.
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 29-grafos-e-np/lista/P2927.c
```

---

**Exercício P2928** · ★★★ · Exato contra três aproximações

Compare quatro jeitos de montar a volta do entregador em três dias
diferentes, cada um com 9 pontos (o ponto 0 é a loja). Os pontos de cada
dia vêm deste gerador, com semente = 11 * dia (dia = 1, 2, 3), coordenadas
de 0 a 14 e distância em quarteirões:


```text
semente = semente * 1103515245u + 12345u;  x[i] = (int)(semente >> 16) % 15;
semente = semente * 1103515245u + 12345u;  y[i] = (int)(semente >> 16) % 15;
```


Para cada dia mostre: o ótimo (Held-Karp), o vizinho mais próximo, a
árvore mínima em pré-ordem e a árvore seguida de 2-opt, com a razão de
cada aproximação para o ótimo (%.2f).


```text
Saída esperada:
dia  ótimo  vizinho     árvore      árvore+2opt
  1     52   60 (1.15)   60 (1.15)   52 (1.00)
  2     44   58 (1.32)   54 (1.23)   44 (1.00)
  3     58   68 (1.17)   70 (1.21)   58 (1.00)
```

**Dicas:**

1. Monte cada método como função que preenche int rota[N] (rota[0] = 0) e
   uma função custo(rota). Held-Karp só precisa do custo.
2. No 2-opt, troque as arestas (a, b) e (c, e) por (a, c) e (b, e) quando
   encurtar, invertendo o trecho, até nenhuma troca ajudar.
3. Resposta esperada: a saída acima. A árvore nunca passa de 2 vezes o
   ótimo; o vizinho mais próximo não tem essa garantia.

```bash
~/LPEDC/rodar 29-grafos-e-np/lista/P2928.c
```

---

**Exercício P2929** · ★★★ · Cobertura exata por ramificação

A cobertura de vértices é NP-difícil, mas existe um truque quando a
resposta k é pequena: pegue uma aresta descoberta u-v; alguma das pontas
TEM de estar na cobertura. Então tente u (e resolva com k - 1) e, se não
der, tente v. São no máximo 2^k ramos, não importa o tamanho do grafo.
Num grafo de 12 vértices (0 a 11) com as arestas


```text
0-1, 1-2, 2-3, 3-0, 4-5, 5-6, 6-4, 7-8, 8-9, 9-10, 10-11, 11-7, 0-4, 2-7
```


escreva bool cobre(int k), que decide se existe cobertura de tamanho no
máximo k, e ache o menor k testando k = 0, 1, 2, ... Conte as chamadas e
compare com as 2^12 máscaras da força bruta. Mostre a cobertura achada.


```text
Saída esperada:
Menor cobertura: 7 vértices: 0 2 4 5 7 8 10
Chamadas: 319 (força bruta: 4096 máscaras)
```

**Dicas:**

1. Guarde em[] global. Em cobre(k): ache a primeira aresta (na ordem da
   lista) sem ponta marcada; se não houver, devolva true. Se k == 0, false.
   Senão marque u, chame cobre(k - 1), desmarque; depois o mesmo com v.
2. Ao achar a cobertura, não desmarque: devolva true direto, e em[] guarda a
   resposta.
3. Resposta esperada: a saída acima. As chamadas somam todos os k testados,
   e mesmo assim ficam bem abaixo de 4096.

```bash
~/LPEDC/rodar 29-grafos-e-np/lista/P2929.c
```

---

**Exercício P2930** · ★★★ · A praça sem ruas

O bairro tem as esquinas 0 a 5 com as ruas 0-1, 1-2, 2-0, 2-3, 3-4, 4-5,
5-2 (todos os graus pares) e acabou de ganhar a esquina 6, uma praça que
ainda não tem rua nenhuma. O caminhão de lixo continua podendo passar por
toda rua uma vez e voltar, mas o programa abaixo diz que não.


```text
Saída que aparece:
Sem circuito: o bairro está partido
```



```text
Saída esperada:
Tem circuito euleriano
```


O programa compila e roda sem erro; o problema é de lógica. Conserte-o.

**Dicas:**

1. O teorema de Euler pede que as ARESTAS estejam num componente só.
   Vértices de grau 0 não atrapalham nenhum circuito.
2. Na conferência da conexidade, ignore as esquinas com grau 0 (e comece a
   DFS numa esquina com grau maior que 0).
3. Resposta esperada: a saída esperada acima.

```bash
~/LPEDC/rodar 29-grafos-e-np/lista/P2930.c
```
