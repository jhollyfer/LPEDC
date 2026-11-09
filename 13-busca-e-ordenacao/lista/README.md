<!-- Gerado por _gerador a partir dos arquivos P????.c desta pasta. -->

# Lista prática · Módulo 13 · Busca e ordenação

30 exercícios de codificar que treinam o módulo inteiro, misturando os assuntos, no ritmo da prova do PPGI (veja [PPGI.md](../../PPGI.md)). Cada arquivo `P????.c` desta pasta é um exercício: a resposta vai dentro dele, embaixo de `// Escreva sua resposta abaixo:`. Uma resolução de cada um está em `_respostas/13-busca-e-ordenacao/lista/`. Só olhe depois de tentar.

[Voltar ao módulo](../README.md)

## ★☆☆ Aquecimento

**Exercício P1301** · ★☆☆ · A placa no estacionamento, com sentinela

A cancela do estacionamento guarda os números das placas que estão lá
dentro, sem ordem: 4821, 1307, 9954, 2210, 6638, 7012, 3389, 5146.

Escreva int busca_sentinela(int v[], int n, int x, int *comparacoes): ela
copia x para v[n] (a sentinela) e anda com um while que só testa
v[i] != x, sem testar i < n. No fim, devolve i se i < n, ou -1. Conte uma
comparação para cada v[i] olhado, inclusive o da sentinela. O vetor tem que
ter uma posição a mais (9 posições) para caber a sentinela.

Procure 2210, 5146 e 1000.


```text
Saída esperada:
Placa 2210: posição 3 (4 comparações)
Placa 5146: posição 7 (8 comparações)
Placa 1000: posição -1 (9 comparações)
```

**Dicas:**

1. Declare int placas[9] = {4821, ..., 5146}; e use n = 8.
2. Comece com comparacoes = 1 (o primeiro v[0] != x) e some 1 a cada i++.
3. Quem não está no vetor custa n + 1 comparações: a última é a sentinela.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 13-busca-e-ordenacao/lista/P1301.c
```

---

**Exercício P1302** · ★☆☆ · Quantas voltas a busca binária dá

A tabela de preços da papelaria (em reais, em ordem crescente) tem 15
itens. Complete a busca binária (intervalo fechado [ini, fim]) para que ela
conte em *voltas quantas vezes o while rodou, e mostre o resultado para os
preços 33, 28, 3, 89 e 50.


```text
Saída esperada:
R$ 33: posição 7 (voltas: 1)
R$ 28: posição 6 (voltas: 4)
R$ 3: posição 0 (voltas: 4)
R$ 89: posição 14 (voltas: 4)
R$ 50: posição -1 (voltas: 4)
```

**Dicas:**

1. Some 1 em *voltas logo no começo do corpo do while.
2. O meio é ini + (fim - ini) / 2.
3. Com 15 elementos, o pior caso é ⌊log₂ 15⌋ + 1 = 4 voltas, achando ou não.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 13-busca-e-ordenacao/lista/P1302.c
```

---

**Exercício P1303** · ★☆☆ · O bubble passada a passada

Os gols das 6 rodadas do time do bairro foram 3, 0, 5, 1, 4, 2. Escreva um
bubble sort crescente que mostre o vetor depois de CADA passada e pare
assim que uma passada inteira não fizer nenhuma troca (avisando com
"nenhuma troca: parou"). Na passada p, o laço interno vai de j = 0 até
j < n - p, comparando v[j] com v[j + 1].


```text
Saída esperada:
passada 1: 0 3 1 4 2 5
passada 2: 0 1 3 2 4 5
passada 3: 0 1 2 3 4 5
passada 4: 0 1 2 3 4 5
nenhuma troca: parou
```

**Dicas:**

1. Use um bool trocou = false no começo de cada passada.
2. A passada 3 já deixa tudo ordenado, mas o bubble só descobre isso na 4,
   quando nada troca.
3. Repare: depois da passada p, os p maiores já estão no fim. É isso que a
   prova pergunta em "o vetor após a k-ésima passada".
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 13-busca-e-ordenacao/lista/P1303.c
```

---

**Exercício P1304** · ★☆☆ · Selection sort das senhas da farmácia

As senhas da fila da farmácia estão bagunçadas: 27, 12, 44, 8, 31, 19.
Complete o selection sort: em cada passada i, ache o menor de
senhas[i..n-1] e troque com senhas[i], mas SÓ troque se o menor não estiver
já em i. Mostre o vetor depois de cada passada e, no fim, quantas trocas
aconteceram de verdade.


```text
Saída esperada:
passada 1: 8 12 44 27 31 19
passada 2: 8 12 44 27 31 19
passada 3: 8 12 19 27 31 44
passada 4: 8 12 19 27 31 44
passada 5: 8 12 19 27 31 44
trocas: 2
```

**Dicas:**

1. Guarde o ÍNDICE do menor (int menor = i), não o valor.
2. Conte a troca dentro do if (menor != i).
3. O selection sempre faz n - 1 passadas: ele não percebe que o vetor
   ficou pronto na passada 3.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 13-busca-e-ordenacao/lista/P1304.c
```

---

**Exercício P1305** · ★☆☆ · Insertion sort das encomendas

A transportadora carrega as encomendas da mais leve para a mais pesada.
Os pesos, em kg, chegaram nesta ordem: 14, 9, 22, 5, 17, 9. Escreva um
insertion sort que mostre o vetor depois de encaixar cada elemento
(j = 1 até j = 5). Use pesos[i] > x no while, para o algoritmo ser
estável.


```text
Saída esperada:
j = 1: 9 14 22 5 17 9
j = 2: 9 14 22 5 17 9
j = 3: 5 9 14 22 17 9
j = 4: 5 9 14 17 22 9
j = 5: 5 9 9 14 17 22
```

**Dicas:**

1. Guarde x = pesos[j] antes de deslocar: a posição j vai ser sobrescrita.
2. Desloque para a direita enquanto i >= 0 e pesos[i] > x; depois,
   pesos[i + 1] = x.
3. Depois do passo j, só a parte pesos[0..j] está garantidamente
   ordenada; o resto continua como chegou.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 13-busca-e-ordenacao/lista/P1305.c
```

---

**Exercício P1306** · ★☆☆ · Intercalando as filas de embarque

No aeroporto, os passageiros dos portões A e B chegam já em ordem de
assento: A tem 4, 11, 18, 25, 30 e B tem 2, 9, 13. Complete a função
intercala, que junta as duas filas numa só, em ordem, e devolve quantas
comparações a[i] <= b[j] ela fez.


```text
Saída esperada:
fila: 2 4 9 11 13 18 25 30
comparações: 5
```

**Dicas:**

1. Enquanto as duas filas têm gente, compare as frentes e copie a menor.
2. Quando uma acaba, copie o resto da outra sem comparar nada.
3. O B acaba depois de 5 comparações (sai o 13); o 18, o 25 e o 30
   descem direto. O pior caso seria na + nb - 1 = 7.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 13-busca-e-ordenacao/lista/P1306.c
```

---

**Exercício P1307** · ★☆☆ · Uma partição de Lomuto

O entregador do prédio tem os andares 12, 3, 17, 8, 21, 5, 10. Escreva a
partição de Lomuto (a PARTITION do Cormen): o pivô é o ÚLTIMO elemento, i
começa em p - 1, j vai de p a r - 1 e, quando v[j] <= pivô, i avança e
v[i] troca com v[j]. No fim, o pivô troca com v[i + 1], que é a posição
devolvida. Faça UMA partição do vetor inteiro e mostre o resultado.


```text
Saída esperada:
depois da partição: 3 8 5 10 21 17 12
pivô 10 na posição 3
```

**Dicas:**

1. Escreva void troca(int *a, int *b) e int particiona(int v[], int p, int r).
2. Faça à mão antes: o 3, o 8 e o 5 são <= 10 e vão para a frente, na
   ordem em que aparecem.
3. O lado direito (21 17 12) não fica ordenado: a partição só promete
   "menores ou iguais à esquerda, maiores à direita".
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 13-busca-e-ordenacao/lista/P1307.c
```

---

**Exercício P1308** · ★☆☆ · As capitais mais quentes primeiro

As máximas do dia em sete capitais foram 34, 29, 38, 22, 31, 36 e 27 graus.
O programa abaixo já ordena em ordem crescente com qsort. Estenda: escreva
a função decrescente (use a crescente, trocando a ordem dos argumentos),
ordene de novo do maior para o menor e mostre as 3 mais quentes.


```text
Saída esperada:
crescente: 22 27 29 31 34 36 38
decrescente: 38 36 34 31 29 27 22
as 3 mais quentes: 38 36 34
```

**Dicas:**

1. A compara recebe const void *; decrescente(a, b) pode só devolver
   crescente(b, a).
2. Repare que a crescente usa (x > y) - (x < y) em vez de x - y: a
   subtração pode estourar o int com valores grandes.
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 13-busca-e-ordenacao/lista/P1308.c
```

---

**Exercício P1309** · ★☆☆ · A busca binária que esquece a ponta

A secretaria procura matrículas num vetor ordenado com a busca binária
abaixo, que tem um erro de propósito: ela não acha algumas matrículas que
estão lá. Rode, veja quais falham e conserte (é uma mudança pequena).


```text
Saída esperada (depois do conserto):
10: 0
47: 3
98: 7
60: -1
```

**Dicas:**

1. Antes do conserto, o 10 e o 98 dão -1. Os dois são pontas do vetor.
2. O intervalo é fechado: [ini, fim] inclui as duas pontas. Quando
   ini == fim, ainda sobra uma posição para olhar.
3. Resposta esperada: a condição do while deve ser ini <= fim; aí a saída
   fica igual à de cima.

```bash
~/LPEDC/rodar 13-busca-e-ordenacao/lista/P1309.c
```

---

**Exercício P1310** · ★☆☆ · Todas as vezes que o ônibus passou

O fiscal anotou as linhas de ônibus que passaram no ponto, na ordem:
302, 115, 302, 640, 115, 302, 88, 640, 302, 115.

Escreva int todas(const int v[], int n, int x, int pos[]), que guarda em
pos[] TODAS as posições onde x aparece e devolve quantas são. No main,
consulte as linhas 302, 640 e 500.


```text
Saída esperada:
linha 302: 4 vez(es), posições 0 2 5 8
linha 640: 2 vez(es), posições 3 7
linha 500: 0 vez(es)
```

**Dicas:**

1. A busca não pode parar no primeiro achado: ela percorre o vetor todo.
2. Use um contador achou que também serve de índice: pos[achou++] = i.
3. Por isso, esta busca custa sempre n comparações, achando ou não.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 13-busca-e-ordenacao/lista/P1310.c
```

## ★★☆ Para pensar

**Exercício P1311** · ★★☆ · O primeiro boleto do dia

O app do banco guarda os dias de vencimento dos boletos do mês, em ordem
crescente e com repetidos:


```text
2, 3, 5, 5, 5, 5, 9, 10, 12, 12, 12, 15, 18, 20, 20, 25
```


Ele quer a PRIMEIRA posição de um dia (o primeiro boleto daquele dia).
Escreva duas funções que devolvem essa posição (ou -1) e contam em *comp
quantas vezes compararam o vetor:


```text
int primeira_binaria(const int v[], int n, int x, int *comp)
int primeira_sequencial(const int v[], int n, int x, int *comp)
```


A binária não pode parar quando acha: ela guarda a posição e continua
procurando na metade da esquerda. Conte 1 comparação por volta do while
(na binária) e 1 por posição olhada (na sequencial). Teste os dias 5, 12,
20 e 7.


```text
Saída esperada:
dia 5: binária 2 (4 comp.), sequencial 2 (3 comp.)
dia 12: binária 8 (4 comp.), sequencial 8 (9 comp.)
dia 20: binária 13 (4 comp.), sequencial 13 (14 comp.)
dia 7: binária -1 (4 comp.), sequencial -1 (16 comp.)
```

**Dicas:**

1. Comece com achou = -1. Quando v[meio] == x, faça achou = meio e
   fim = meio - 1.
2. A binária sempre roda até o intervalo esvaziar: com 16 elementos, são 4
   ou 5 voltas, mesmo quando acha cedo.
3. Para o dia 5, a sequencial ganha: o 5 está logo no começo. A binária só
   vale a pena quando o vetor é grande ou o alvo está longe do início.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 13-busca-e-ordenacao/lista/P1311.c
```

---

**Exercício P1312** · ★★☆ · Encaixando consultas na agenda

A agenda da clínica guarda os horários marcados em minutos desde a
meia-noite (480 é 8h00), em ordem crescente: 480, 540, 600, 660, 780, 840.
Chegam novos pedidos de horário: 615, 450, 900 e 600 (este já existe; o
novo entra ANTES do antigo).

Escreva:


```text
int ponto_insercao(const int v[], int n, int x)
  busca binária que devolve a primeira posição com v[i] >= x (de 0 a n)
int insere(int v[], int *n, int x)
  acha o ponto de inserção, desloca o resto uma casa para a direita,
  grava x, aumenta *n e devolve a posição
```


Mostre a agenda depois de cada inserção (o vetor tem capacidade 10).


```text
Saída esperada:
615 entrou na posição 3: 480 540 600 615 660 780 840
450 entrou na posição 0: 450 480 540 600 615 660 780 840
900 entrou na posição 8: 450 480 540 600 615 660 780 840 900
600 entrou na posição 3: 450 480 540 600 600 615 660 780 840 900
```

**Dicas:**

1. É a busca binária de sempre, com intervalo fechado, mas sem o "achou,
   devolve": se v[meio] < x, ini = meio + 1; senão, fim = meio - 1.
2. Quando o while termina, ini é o ponto de inserção. Faça o teste de mesa
   com x = 900: ini chega a 8 = n.
3. Desloque de trás para frente (i de *n até pos + 1), para não apagar
   ninguém.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 13-busca-e-ordenacao/lista/P1312.c
```

---

**Exercício P1313** · ★★☆ · O bubble no melhor e no pior dia

Instrumente o bubble sort com parada antecipada (para quando uma passada
não troca nada): escreva


```text
void bubble(int v[], int n, int *comp, int *trocas, int *passadas)
```


que ordena v e devolve quantas comparações v[j] > v[j + 1] fez, quantas
trocas e quantas passadas rodou. Teste com três vetores de 6 senhas:
crescente 1 2 3 4 5 6, invertido 6 5 4 3 2 1 e misturado 4 1 6 2 5 3.
Mostre cada linha com printf("%-10s passadas %d, comparações %2d, trocas %2d\n", ...).


```text
Saída esperada:
crescente  passadas 1, comparações  5, trocas  0
invertido  passadas 5, comparações 15, trocas 15
misturado  passadas 4, comparações 14, trocas  7
```

**Dicas:**

1. A passada p compara j de 0 a n - p - 1: n - p comparações.
2. O melhor caso (já ordenado) faz uma passada só: n - 1 comparações, O(n).
3. O pior caso (invertido) troca em toda comparação: n(n - 1)/2 = 15.
4. O número de trocas é igual ao número de inversões do vetor: o
   misturado tem 7.
5. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 13-busca-e-ordenacao/lista/P1313.c
```

---

**Exercício P1314** · ★★☆ · Quick sort com a partição de Hoare

Ordene as notas 7, 2, 9, 4, 7, 1, 8, 3 com quick sort usando a partição de
HOARE do Cormen (problema 7-1): o pivô é x = v[p]; i começa em p - 1 e j em
r + 1; repita: "j-- até v[j] <= x", "i++ até v[i] >= x"; se i < j, troca
v[i] com v[j]; senão, devolve j. Depois, a recursão é quick(p, j) e
quick(j + 1, r): o pivô NÃO fica necessariamente na posição j.

O vetor e n são globais (já estão no esqueleto). A cada partição, mostre
o intervalo, o pivô, o j devolvido e o vetor inteiro; no fim, o vetor
ordenado.


```text
Saída esperada:
[0..7] pivô 7, j = 4: 3 2 1 4 7 9 8 7
[0..4] pivô 3, j = 1: 1 2 3 4 7 9 8 7
[0..1] pivô 1, j = 0: 1 2 3 4 7 9 8 7
[2..4] pivô 3, j = 2: 1 2 3 4 7 9 8 7
[3..4] pivô 4, j = 3: 1 2 3 4 7 9 8 7
[5..7] pivô 9, j = 6: 1 2 3 4 7 7 8 9
[5..6] pivô 7, j = 5: 1 2 3 4 7 7 8 9
final: 1 2 3 4 7 7 8 9
```

**Dicas:**

1. Use do { j--; } while (v[j] > x); e do { i++; } while (v[i] < x);
2. Guarde o pivô (v[p]) antes de chamar a partição, para poder mostrá-lo.
3. Na primeira partição, os 7 iguais ao pivô vão um para cada lado: Hoare
   para nos iguais, e é isso que deixa as metades equilibradas.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 13-busca-e-ordenacao/lista/P1314.c
```

---

**Exercício P1315** · ★★☆ · Quem ordena sem bagunçar os empates

A lista da escola está em ordem alfabética: Ana (turma 2), Beto (1),
Caio (2), Duda (1), Eva (3), Fabio (2). A secretaria quer por turma,
mantendo a ordem alfabética dentro de cada turma, ou seja, uma ordenação
ESTÁVEL.

Escreva selection(Aluno v[], int n) e insertion(Aluno v[], int n), as duas
ordenando pelo campo turma (o selection troca o menor com v[i]; o insertion
usa > no while). Ordene duas cópias da lista e mostre as duas.


```text
typedef struct { char nome[10]; int turma; } Aluno;
```



```text
Saída esperada:
selection: Beto(1) Duda(1) Caio(2) Ana(2) Fabio(2) Eva(3)
insertion: Beto(1) Duda(1) Ana(2) Caio(2) Fabio(2) Eva(3)
```

**Dicas:**

1. Struct se copia com =, então dá para trocar com Aluno t = v[i]; ...
2. Faça o selection à mão: na passada 1 o Duda troca com a Ana, e a Ana
   vai parar DEPOIS do Caio. É a troca à distância que quebra a
   estabilidade.
3. O insertion só move um elemento por cima de vizinhos MAIORES; iguais
   nunca passam um pelo outro.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 13-busca-e-ordenacao/lista/P1315.c
```

---

**Exercício P1316** · ★★☆ · Classificação do concurso com desempate

O edital do concurso da prefeitura diz: classifica primeiro quem tem a
maior nota; no empate, o candidato mais velho; persistindo, a ordem
alfabética do nome. Escreva a função compara para o qsort com essa chave
composta e mostre a classificação.


```text
Candidatos: Paulo 82 (30 anos), Rita 90 (25), Lucas 82 (41), Ana 82 (30),
Bruna 75 (52), Igor 90 (25), Celia 82 (41)
```



```text
Saída esperada:
1º Igor   nota 90, 25 anos
2º Rita   nota 90, 25 anos
3º Celia  nota 82, 41 anos
4º Lucas  nota 82, 41 anos
5º Ana    nota 82, 30 anos
6º Paulo  nota 82, 30 anos
7º Bruna  nota 75, 52 anos
```

**Dicas:**

1. Compare um critério de cada vez: só passe para o próximo se o atual
   empatar.
2. Para "maior primeiro", inverta: (y->nota > x->nota) - (y->nota < x->nota).
3. O último critério é strcmp(x->nome, y->nome).
4. Mostre cada linha com printf("%dº %-6s nota %d, %d anos\n", ...).
5. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 13-busca-e-ordenacao/lista/P1316.c
```

---

**Exercício P1317** · ★★☆ · O merge sort mostrando cada intercalação

Ordene os tempos de espera 38, 27, 43, 3, 9, 82, 10 (em minutos) com merge
sort, dividindo em q = (p + r) / 2. Instrumente a intercalação: no fim de
cada intercala(p, q, r), mostre o trecho v[p..r] já intercalado. Use um
vetor auxiliar global int aux[7].


```text
Saída esperada:
intercala [0..1]: 27 38
intercala [2..3]: 3 43
intercala [0..3]: 3 27 38 43
intercala [4..5]: 9 82
intercala [4..6]: 9 10 82
intercala [0..6]: 3 9 10 27 38 43 82
```

**Dicas:**

1. merge_sort(p, r): se p < r, ordena [p..q], ordena [q+1..r] e intercala.
2. A ordem das linhas é a ordem em que as chamadas TERMINAM: a metade
   esquerda inteira antes da direita. Repare que o trecho [6..6] (só o 10)
   não intercala nada.
3. São n - 1 = 6 intercalações para 7 elementos.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 13-busca-e-ordenacao/lista/P1317.c
```

---

**Exercício P1318** · ★★☆ · O pior caso do quick sort, medido

O quick sort abaixo usa a partição de Lomuto (pivô no fim). Instrumente:

a) conte numa variável global comparacoes cada v[j] <= pivo;
b) acrescente um parâmetro prof em quick (a raiz chama com 0 e cada

```text
 chamada recursiva passa prof + 1) e guarde em profundidade_max a maior
 profundidade alcançada, contando também as chamadas com p >= r;
```

c) escreva testa(nome, v, n), que zera os contadores, ordena e mostra.

Rode no vetor crescente 1..10 e no misturado 6 3 9 1 8 2 10 5 7 4, e
mostre n(n-1)/2 para comparar.


```text
Saída esperada:
crescente  comparações 45, profundidade 9
misturado  comparações 20, profundidade 4
n(n-1)/2 = 45
```

**Dicas:**

1. Atualize profundidade_max logo no começo de quick, antes do if.
2. No crescente, o pivô é sempre o maior: cada partição deixa o lado
   direito vazio e o esquerdo com um a menos. 9 + 8 + ... + 1 = 45.
3. A profundidade 9 é a pilha de chamadas crescendo em O(n): com um vetor
   de um milhão já ordenado, o programa estouraria a pilha.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 13-busca-e-ordenacao/lista/P1318.c
```

---

**Exercício P1319** · ★★☆ · Busca binária no ranking decrescente

O ranking do torneio de xadrez da escola está em ordem DECRESCENTE de
pontos: 980, 875, 870, 720, 650, 610, 455, 300. A busca abaixo foi copiada
de um vetor crescente e, aqui, erra quase tudo. Adapte a busca para vetor
decrescente e mostre a colocação (posição + 1) de quem fez 650, 980, 300 e
500 pontos.


```text
Saída esperada:
650 pontos: 5º lugar
980 pontos: 1º lugar
300 pontos: 8º lugar
500 pontos: ninguém
```

**Dicas:**

1. Rode antes: nenhuma das quatro é achada, porque a busca vai sempre
   para o lado errado.
2. No vetor decrescente, se v[meio] > x, o x está à DIREITA do meio.
3. Só uma comparação muda de sentido; o resto da busca fica igual.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 13-busca-e-ordenacao/lista/P1319.c
```

---

**Exercício P1320** · ★★☆ · Um selection sort estável

Na lotérica, a fila foi anotada em ordem de chegada com a prioridade de
cada cliente (1 = mais urgente): A3, B2, C3, D1, E2, F1. O selection sort
abaixo ordena por prioridade, mas embaralha a ordem de chegada entre
empatados (o E passa na frente do B).

Escreva selection_estavel: ache o menor de v[i..n-1] como antes, mas em vez
de TROCAR, guarde o menor, empurre v[i..menor-1] uma casa para a direita e
grave o menor em v[i]. Ordene uma cópia com cada versão e mostre as duas.


```text
Saída esperada:
com troca  : D1 F1 E2 B2 C3 A3
deslocando : D1 F1 B2 E2 A3 C3
```

**Dicas:**

1. O deslocamento é o mesmo do insertion: for (k = menor; k > i; k--)
   v[k] = v[k - 1];
2. Como o menor é o PRIMEIRO menor (< e não <=), quem empatou com ele e
   veio antes já saiu; quem vem depois continua depois.
3. O preço: em vez de 1 troca por passada, até n - i movimentos. O
   selection perde a sua única vantagem (poucas escritas).
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 13-busca-e-ordenacao/lista/P1320.c
```

## ★★★ Desafio

**Exercício P1321** · ★★★ · As quedas de mais da metade

O preço de uma ação, em reais, nos últimos 8 pregões foi
40, 15, 22, 90, 10, 35, 8, 50. O analista chama de "queda forte" todo par
de dias i < j em que o preço do dia i é MAIS QUE O DOBRO do preço do dia j
(v[i] > 2 * v[j]). Quantas quedas fortes houve?

Escreva duas versões:


```text
long long forca_bruta(const int v[], int n)                    O(n²)
long long conta(int v[], int aux[], int p, int r)    O(n log n), merge sort
```


Na versão rápida, depois de ordenar as duas metades e ANTES de intercalar,
conte os pares (i na esquerda, j na direita) com v[i] > 2 * v[j]. Como as
duas metades estão ordenadas, o índice j só anda para a frente: um laço
em i com um while em j, os dois juntos em O(n). Depois, intercale normalmente.
Mostre os dois resultados e o vetor ordenado.


```text
Saída esperada:
força bruta: 9 pares
merge sort: 9 pares
ordenado: 8 10 15 22 35 40 50 90
```

**Dicas:**

1. É o mesmo truque da contagem de inversões, com outra condição. Não dá
   para contar DURANTE a intercalação, porque a condição v[i] > 2 * v[j]
   não é a mesma que decide quem sai primeiro.
2. Para cada i da esquerda, avance j enquanto j <= r e v[i] > 2 * v[j];
   some j - (q + 1). Quando i cresce, v[i] cresce, e o j antigo continua
   valendo.
3. Use 2LL * v[j] para a conta não estourar com preços grandes.
4. Resposta esperada: 9 pares (por exemplo, 40 > 2 · 15 e 90 > 2 · 35).

```bash
~/LPEDC/rodar 13-busca-e-ordenacao/lista/P1321.c
```

---

**Exercício P1322** · ★★★ · Três filiais, uma fila de pedidos

Três filiais de uma pizzaria mandam os números dos pedidos já em ordem:
Centro 3, 10, 21, 30; Norte 1, 12, 18; Sul 5, 7, 25, 40. A central quer uma
fila só, em ordem. Faça de dois jeitos e conte as comparações entre
elementos (variável global comparacoes):

a) intercala3: olha as três frentes de uma vez e tira a menor. Use uma

```text
 função auxiliar menor(v, i, n, w, j, m) que devolve 1 se a fila v ainda
 tem gente e (a fila w acabou ou v[i] <= w[j]); ela só conta comparação
 quando as DUAS filas têm gente. A frente de a sai se for menor que a de
 b E que a de c; senão sai a de b, se for menor que a de c; senão a de c.
```

b) duas a duas: intercala Centro com Norte num vetor temporário e depois o

```text
 resultado com Sul, com a intercala2 de sempre.
```



```text
Saída esperada:
de uma vez: 1 3 5 7 10 12 18 21 25 30 40
comparações: 19
duas a duas: 1 3 5 7 10 12 18 21 25 30 40
comparações: 15
```

**Dicas:**

1. O while de intercala3 continua enquanto ALGUMA fila tem gente
   (i < na || j < nb || k < nc).
2. O "de uma vez" gasta até 2 comparações por elemento; o "duas a duas",
   no máximo 1 por elemento em cada intercalação. Com muitas listas, o
   jeito certo de achar a menor frente é um heap (módulo 14).
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 13-busca-e-ordenacao/lista/P1322.c
```

---

**Exercício P1323** · ★★★ · Mediana de três contra o vetor ordenado

O quick sort com pivô no fim cai no pior caso justamente quando a lista
já vem ordenada, o que é comum (planilha exportada, senhas em ordem). A
defesa clássica é a MEDIANA DE TRÊS: antes de cada partição de v[p..r]
(com pelo menos 3 elementos), olhe v[p], v[m] e v[r], com
m = p + (r - p) / 2, ponha os três em ordem com até 3 trocas e leve a
mediana (que ficou em m) para v[r]. A partição de Lomuto não muda.

Escreva void quick(int v[], int p, int r, bool mediana) e conte as
comparações v[j] <= pivo (global comparacoes). Para cada vetor de 15
elementos (crescente 1..15, decrescente 15..1 e o misturado do esqueleto),
ordene uma cópia com cada versão e mostre:
printf("%-11s pivô no fim: %3d   mediana de três: %3d\n", ...).


```text
Saída esperada:
crescente   pivô no fim: 105   mediana de três:  34
decrescente pivô no fim: 105   mediana de três:  38
misturado   pivô no fim:  37   mediana de três:  36
```

**Dicas:**

1. Ordene os três assim: se v[m] < v[p], troca; se v[r] < v[p], troca; se
   v[r] < v[m], troca. Depois, troca v[m] com v[r].
2. Só conte as comparações da partição (as 3 da mediana ficam de fora).
3. 105 = 15 · 14 / 2: o pior caso. Com a mediana, o pivô do vetor ordenado
   é o elemento do meio, e o quick volta a dividir ao meio.
4. No vetor misturado quase não muda nada: a mediana não deixa o caso
   médio pior, só tira o pior caso dos dados "fáceis".
5. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 13-busca-e-ordenacao/lista/P1323.c
```

---

**Exercício P1324** · ★★★ · O quick sort com dois defeitos

Este quick sort deveria ordenar os tempos de corrida de 9 entregadores,
em minutos: 23, 8, 41, 15, 4, 36, 19, 2, 30. A partição de Lomuto tem DOIS
erros de propósito. O programa não quebra; só ordena errado. Ache os dois,
conserte e rode até sair:


```text
Saída esperada:
 2 4 8 15 19 23 30 36 41
```

**Dicas:**

1. Faça o teste de mesa da primeira partição (pivô 30): quais elementos o
   for olha? O 2, vizinho do pivô, é examinado?
2. Depois do for, onde está o pivô? A função devolve i + 1, mas o que tem
   em v[i + 1]?
3. Na Lomuto do Cormen, j vai de p até r - 1 (inclusive) e, no fim, o pivô
   troca de lugar com v[i + 1].
4. Resposta esperada: o for deve ser j < r (e não j < r - 1), e falta
   troca(&v[i + 1], &v[r]); antes do return. Com os dois consertos, a
   saída fica igual à de cima.

```bash
~/LPEDC/rodar 13-busca-e-ordenacao/lista/P1324.c
```

---

**Exercício P1325** · ★★★ · Duas passadas estáveis, uma chave composta

O motoboy quer as entregas agrupadas por bairro (em ordem alfabética) e,
dentro de cada bairro, por hora. Em vez de uma compara com dois critérios,
dá para ordenar DUAS VEZES com um algoritmo estável: primeiro pela chave
secundária (hora), depois pela principal (bairro). A segunda passada não
desfaz a primeira entre os empatados, justamente porque é estável.

Escreva por_hora e por_bairro, dois insertion sorts estáveis (o de bairro
compara com strcmp). Ordene uma cópia na ordem certa (hora, depois bairro)
e outra na ordem trocada (bairro, depois hora) e mostre as duas com
printf("  %-8s %02d:00 pedido %d\n", ...).


```text
typedef struct { char bairro[12]; int hora; int pedido; } Entrega;
```



```text
Entregas: Centro 15h (101), Aleixo 11h (102), Centro 9h (103),
Flores 14h (104), Aleixo 8h (105), Centro 12h (106), Flores 10h (107)
```



```text
Saída esperada:
hora, depois bairro (certo):
  Aleixo   08:00 pedido 105
  Aleixo   11:00 pedido 102
  Centro   09:00 pedido 103
  Centro   12:00 pedido 106
  Centro   15:00 pedido 101
  Flores   10:00 pedido 107
  Flores   14:00 pedido 104
bairro, depois hora (errado):
  Aleixo   08:00 pedido 105
  Centro   09:00 pedido 103
  Flores   10:00 pedido 107
  Aleixo   11:00 pedido 102
  Centro   12:00 pedido 106
  Flores   14:00 pedido 104
  Centro   15:00 pedido 101
```

**Dicas:**

1. Os dois insertion sorts usam > no while (strcmp(...) > 0 no de bairro).
2. Na ordem trocada, a última passada (por hora) manda: o bairro só serve
   de desempate entre horas iguais, e aqui nenhuma hora se repete.
3. Se você trocar o insertion por um selection na segunda passada, a ordem
   das horas dentro do bairro pode se perder. É a mesma ideia do radix sort
   (módulo 18).
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 13-busca-e-ordenacao/lista/P1325.c
```

---

**Exercício P1326** · ★★★ · Busca binária na escala que deu a volta

O painel do pronto-atendimento guarda as senhas na ordem em que foram
chamadas. A contagem vai até 99 e recomeça, então o vetor é crescente mas
"girado":


```text
61, 67, 72, 80, 94, 3, 9, 18, 26, 33, 40, 52
```


Escreva uma busca O(log n) nesse vetor:

a) int ponto_de_giro(const int v[], int n): a posição do menor elemento,

```text
 por busca binária. Enquanto ini < fim: se v[meio] > v[fim], o giro está
 à direita (ini = meio + 1); senão, fim = meio (o meio pode ser o menor).
```

b) int busca(const int v[], int ini, int fim, int x, int *voltas): a

```text
 binária normal num trecho, somando as voltas.
```

c) int busca_girada(const int v[], int n, int x, int *voltas): zera as

```text
 voltas, acha o giro g e faz UMA busca binária no trecho certo: [0, g-1]
 se g > 0 e x >= v[0]; senão, [g, n-1].
```


Mostre o giro e procure 80, 3, 33, 61, 52 e 50.


```text
Saída esperada:
giro na posição 5
80: posição 3 (voltas: 2)
3: posição 5 (voltas: 3)
33: posição 9 (voltas: 3)
61: posição 0 (voltas: 2)
52: posição 11 (voltas: 3)
50: posição -1 (voltas: 3)
```

**Dicas:**

1. Compare com v[fim], não com v[ini]: assim o caso sem giro (vetor todo
   crescente) também dá certo e devolve 0.
2. As duas partes, v[0..g-1] e v[g..n-1], são crescentes. Todo elemento da
   primeira é maior que todo elemento da segunda.
3. As voltas contadas são só as da busca do item (c), não as do giro.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 13-busca-e-ordenacao/lista/P1326.c
```

---

**Exercício P1327** · ★★★ · O relatório dos três quadráticos

Monte um relatório que compara bubble, selection e insertion no mesmo
vetor. Cada um tem a assinatura void f(int v[], int n, int *comp, int *mov)
e conta:

- bubble (com parada antecipada): comp = comparações v[j] > v[j + 1],

```text
mov = trocas;
```

- selection: comp = comparações v[j] < v[menor], mov = trocas feitas (só

```text
quando menor != i);
```

- insertion: comp = cada vez que o while compara v[i] com x (inclusive a

```text
comparação que faz o laço parar), mov = deslocamentos v[i + 1] = v[i].
```


Escreva void relatorio(const char *nome, const int orig[], int n), que roda
os três numa CÓPIA de orig e mostra uma linha por algoritmo com
printf("  %-9s comparações %2d, movimentos %2d\n", ...). Rode com o
vetor misturado 5 2 8 1 9 3 7 4, o crescente 1 2 3 4 5 7 8 9 e o
decrescente 9 8 7 5 4 3 2 1.


```text
Saída esperada:
misturado:
  bubble    comparações 25, movimentos 13
  selection comparações 28, movimentos  5
  insertion comparações 18, movimentos 13
crescente:
  bubble    comparações  7, movimentos  0
  selection comparações 28, movimentos  0
  insertion comparações  7, movimentos  0
decrescente:
  bubble    comparações 28, movimentos 28
  selection comparações 28, movimentos  4
  insertion comparações 28, movimentos 28
```

**Dicas:**

1. No insertion, escreva o while como while (i >= 0) { comp++; if (v[i] <=
   x) break; ... } para contar também a comparação que para.
2. Um vetor de ponteiros para função deixa o relatório curto:
   void (*alg[])(int[], int, int *, int *) = {bubble, selection, insertion};
3. Repare: o selection compara sempre 28 = 8 · 7 / 2, mas é o que menos
   escreve. Bubble e insertion movem exatamente o número de inversões (13
   no misturado).
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 13-busca-e-ordenacao/lista/P1327.c
```

---

**Exercício P1328** · ★★★ · Merge sort na lista encadeada

Os valores dos pedidos da lanchonete (em reais) estão numa lista
encadeada: 58, 12, 97, 33, 12, 75, 4, 41, 66. Ordene a LISTA com merge
sort, sem vetor auxiliar e sem malloc durante a ordenação:

a) No *divide(No *l): corta a lista no meio com dois ponteiros (lento anda

```text
 1, rápido anda 2, rápido começa em l->prox) e devolve a segunda metade;
```

b) No *intercala(No *a, No *b): junta duas listas ordenadas RELIGANDO os

```text
 nós (use um nó "cabeça" local para não tratar o primeiro à parte);
```

c) No *merge_sort(No *l): lista vazia ou de um nó já está ordenada; senão,

```text
 divide, ordena as duas metades e intercala.
```


Monte a lista com malloc, mostre antes e depois e libere tudo no fim.


```text
Saída esperada:
antes : 58 12 97 33 12 75 4 41 66
depois: 4 12 12 33 41 58 66 75 97
```

**Dicas:**

1. Para montar na ordem certa com insere_inicio, insira de trás para frente.
2. Nó cabeça local: No cabeca = {0, NULL}; No *fim = &cabeca; ... e no fim
   devolva cabeca.prox.
3. Use <= na intercalação para o merge continuar estável.
4. Na lista, o merge sort é o algoritmo natural: não precisa de acesso por
   índice e não gasta memória extra, ao contrário do vetor.
5. Resposta esperada: a saída acima, limpa no AddressSanitizer.

```bash
~/LPEDC/rodar 13-busca-e-ordenacao/lista/P1328.c
```

---

**Exercício P1329** · ★★★ · Que algoritmo deixou o vetor assim?

Questão típica de prova: "o vetor 31 8 22 15 4 27 12 está sendo ordenado e,
num certo momento, está assim. Qual algoritmo, e em que passo?". Escreva um
programa que responde sozinho.

Escreva três funções que ordenam uma CÓPIA de orig e guardam o vetor depois
de cada passo em estados[k] (k = 0 é o passo 1), devolvendo quantos passos
deram:


```text
int bubble(const int orig[], int estados[][N])     passo = uma passada
                                                   (sem parada antecipada)
int selection(const int orig[], int estados[][N])  passo = uma passada i
int insertion(const int orig[], int estados[][N])  passo = um encaixe j
```


Depois, para cada pista, procure em qual algoritmo e passo ela aparece
(pegue o primeiro passo de cada algoritmo que bate). Se nenhum bater,
escreva "nenhum dos três".


```text
Pistas:
4 8 12 15 31 27 22
8 15 22 31 4 27 12
8 15 4 22 12 27 31
8 22 4 15 27 31 12
```



```text
Saída esperada:
pista 1: selection após o passo 3
pista 2: insertion após o passo 3
pista 3: bubble após o passo 2
pista 4: nenhum dos três
```

**Dicas:**

1. Use #define N 7. Um vetor int estados[N][N] cabe todos os passos.
2. Assinaturas iguais deixam você pôr as três funções num vetor:
   int (*alg[])(const int[], int[][N]) = {bubble, selection, insertion};
3. Para resolver de cabeça na prova: o selection deixa os k MENORES no
   começo, o bubble deixa os k MAIORES no fim, o insertion deixa os k + 1
   PRIMEIROS ordenados entre si (e o resto intacto).
4. A pista 4 parece bubble (31 no fim?), mas o 31 não está no fim.
5. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 13-busca-e-ordenacao/lista/P1329.c
```

---

**Exercício P1330** · ★★★ · A agenda do posto de saúde

O posto guarda as consultas como structs, fora de ordem:


```text
typedef struct { int data; int hora; char paciente[12]; } Consulta;
// data no formato aaaammdd, hora no formato hhmm
```



```text
{20261112, 1030, "Marta"}, {20261110, 900, "Joao"}, {20261112, 800, "Ivo"},
{20261111, 1400, "Sara"}, {20261110, 1500, "Lia"}, {20261112, 1330, "Davi"},
{20261110, 730, "Rosa"}, {20261114, 1000, "Tito"}
```


a) Ordene com qsort pela chave composta (data, depois hora).
b) Escreva int primeira_do_dia(const Consulta v[], int n, int data): busca

```text
 binária que devolve a primeira posição com v[i].data >= data (de 0 a n).
```

c) Escreva void lista_dia(v, n, data), que mostra o dia (dd/mm) e, a partir

```text
 da primeira posição, todas as consultas daquele dia; ou "nenhuma
 consulta".
```


Liste os dias 10, 12, 13 e 14 de novembro de 2026.


```text
Saída esperada:
10/11: 07:30 Rosa; 09:00 Joao; 15:00 Lia;
12/11: 08:00 Ivo; 10:30 Marta; 13:30 Davi;
13/11: nenhuma consulta
14/11: 10:00 Tito;
```

**Dicas:**

1. Na compara, só olhe a hora se as datas forem iguais.
2. O dia é data % 100 e o mês é data / 100 % 100; a hora é hora / 100 e os
   minutos, hora % 100. Use %02d.
3. Para o dia 13, a busca devolve a posição do Tito (o primeiro >= 13), que
   não é do dia 13: confira v[i].data antes de listar. Para um dia depois
   do último, ela devolve n.
4. A busca custa O(log n) e a listagem O(k), com k consultas no dia: é
   assim que agendas grandes respondem rápido.
5. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 13-busca-e-ordenacao/lista/P1330.c
```
