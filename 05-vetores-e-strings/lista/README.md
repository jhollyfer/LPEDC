<!-- Gerado por _gerador a partir dos arquivos P????.c desta pasta. -->

# Lista prática · Módulo 05 · Vetores, matrizes e strings

30 exercícios de codificar que treinam o módulo inteiro, misturando os assuntos, no ritmo da prova do PPGI (veja [PPGI.md](../../PPGI.md)). Cada arquivo `P????.c` desta pasta é um exercício: a resposta vai dentro dele, embaixo de `// Escreva sua resposta abaixo:`. Uma resolução de cada um está em `_respostas/05-vetores-e-strings/lista/`. Só olhe depois de tentar.

[Voltar ao módulo](../README.md)

## ★☆☆ Aquecimento

**Exercício P0501** · ★☆☆ · O melhor dia da padaria

A padaria do bairro anotou o faturamento de cada dia da semana, em reais:


```text
Dom 1830  Seg 920  Ter 1045  Qua 870  Qui 1110  Sex 1490  Sáb 2210
```


Guarde os valores num vetor int vendas[7] e os nomes dos dias numa matriz
de char dias[7][5]. Mostre o total da semana, a média (com 2 casas) e o dia
de maior e o de menor faturamento, pelo nome.


```text
Saída esperada:
Total da semana: R$ 9475
Média por dia: R$ 1353.57
Maior: Sáb (R$ 2210)
Menor: Qua (R$ 870)
```

**Dicas:**

1. Comece com i_maior = i_menor = 0 e compare cada vendas[i] com
   vendas[i_maior] e vendas[i_menor]. Guarde o ÍNDICE, não o valor.
2. Com o índice, o nome sai de dias[i_maior] e o valor de vendas[i_maior].
3. Para a média com casas, divida por 7.0, não por 7.
4. Por que [5] se "Sáb" tem 3 letras? Em UTF-8 o á ocupa 2 bytes: são 4
   bytes mais o '\0'. Com [4], o '\0' não cabe e o printf passa do fim.
5. Resposta esperada: total 9475, média 1353.57, maior no sábado e menor na
   quarta.

```bash
~/LPEDC/rodar 05-vetores-e-strings/lista/P0501.c
```

---

**Exercício P0502** · ★☆☆ · Procurando o código no estoque

O mercadinho guarda os códigos dos produtos num vetor, na ordem em que
foram cadastrados:


```text
int codigos[8] = {4410, 1270, 9031, 5588, 1270, 3302, 7745, 6120};
```


Escreva int buscar(const int v[], int n, int procurado), que devolve a
POSIÇÃO da primeira ocorrência de procurado no vetor, ou -1 se ele não
estiver lá. No main, procure 5588, 1270 e 2000 e mostre o resultado assim:


```text
Saída esperada:
Código 5588: posição 3
Código 1270: posição 1
Código 2000: não cadastrado
```

**Dicas:**

1. Uma busca linear: um for de 0 a n - 1 que compara v[i] com procurado.
2. Achou? return i na hora: é isso que garante a PRIMEIRA ocorrência.
3. O return -1 fica depois do laço: só chega lá quem não achou.
4. Resposta esperada: a saída acima (1270 aparece duas vezes, mas a busca
   para na posição 1).

```bash
~/LPEDC/rodar 05-vetores-e-strings/lista/P0502.c
```

---

**Exercício P0503** · ★☆☆ · A fila ao contrário

Na fila do posto de saúde, as senhas foram chamadas nesta ordem:


```text
int senhas[] = {101, 102, 105, 108, 110, 113, 117};
```


O auditor quer ver a fila de trás para a frente. Escreva
void inverter(int v[], int n), que inverte o vetor NO LUGAR (sem criar
outro vetor), e void mostrar(const int v[], int n). Mostre a fila antes e
depois de inverter.


```text
Saída esperada:
Antes:  101 102 105 108 110 113 117
Depois: 117 113 110 108 105 102 101
```

**Dicas:**

1. Troque v[0] com v[n - 1], v[1] com v[n - 2], e assim por diante.
2. Pare no meio (i < n / 2). Se for até o fim, você destroca tudo e o vetor
   volta a ser o que era.
3. A troca usa uma variável auxiliar: aux = v[i]; v[i] = v[j]; v[j] = aux;
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 05-vetores-e-strings/lista/P0503.c
```

---

**Exercício P0504** · ★☆☆ · O estoque das duas lojas

Uma rede de açaí tem duas lojas. Cada matriz 2x3 guarda os litros em
estoque (linhas: polpa pura e com guaraná; colunas: tamanhos P, M e G):


```text
int centro[2][3] = {{12, 20, 8}, {5, 9, 14}};
int bairro[2][3] = {{7, 3, 10}, {11, 6, 2}};
```


Monte a matriz total[2][3] com a soma das duas (posição por posição) e
mostre as três matrizes, cada número com %4d:


```text
Saída esperada:
Centro:
  12  20   8
   5   9  14
Bairro:
   7   3  10
  11   6   2
Total:
  19  23  18
  16  15  16
```

**Dicas:**

1. Soma de matrizes é feita casa a casa: total[i][j] = centro[i][j] +
   bairro[i][j], com dois for aninhados.
2. Escreva void mostrar(const char titulo[], int m[2][3]) para não repetir
   o laço de impressão três vezes.
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 05-vetores-e-strings/lista/P0504.c
```

---

**Exercício P0505** · ★☆☆ · A grade de horários deitada

A escola guarda quantas aulas cada professor dá em cada dia, numa matriz
3x4 (linhas: Ana, Beto, Cris; colunas: seg, ter, qua, qui):


```text
int aulas[3][4] = {{2, 4, 0, 3}, {1, 1, 5, 2}, {3, 0, 2, 4}};
```


A secretaria quer a tabela "deitada": uma linha por dia e uma coluna por
professor. Monte a TRANSPOSTA t[4][3] (t[j][i] = aulas[i][j]) e mostre as
duas, cada número com %3d:


```text
Saída esperada:
Por professor (3x4):
  2  4  0  3
  1  1  5  2
  3  0  2  4
Por dia (4x3):
  2  1  3
  4  1  0
  0  5  2
  3  2  4
```

**Dicas:**

1. A transposta de uma matriz L x C é C x L: o que era linha vira coluna.
2. Dois for: o de fora em i (0 a 2), o de dentro em j (0 a 3), e a linha
   t[j][i] = aulas[i][j]; dentro.
3. Para mostrar, os limites mudam: t tem 4 linhas de 3 colunas.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 05-vetores-e-strings/lista/P0505.c
```

---

**Exercício P0506** · ★☆☆ · É identidade?

A matriz identidade tem 1 na diagonal principal e 0 em todo o resto.
Escreva:


```text
void montar_identidade(int m[4][4]);
bool eh_identidade(int m[4][4]);
```


No main, monte a identidade 4x4 e mostre-a. Depois teste eh_identidade com
ela e com a matriz abaixo (que tem um 1 fora do lugar), e mostre o
resultado de cada teste:


```text
int quase[4][4] = {{1, 0, 0, 0}, {0, 1, 0, 1}, {0, 0, 1, 0}, {0, 0, 0, 1}};
```



```text
Saída esperada:
1 0 0 0
0 1 0 0
0 0 1 0
0 0 0 1
id é identidade? sim
quase é identidade? não
```

**Dicas:**

1. Na diagonal principal, a linha é igual à coluna: m[i][j] = (i == j).
2. Em eh_identidade, o valor esperado em cada casa também é (i == j): se
   alguma casa for diferente disso, return false na hora.
3. Para mostrar o bool, use um operador ternário: ok ? "sim" : "não".
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 05-vetores-e-strings/lista/P0506.c
```

---

**Exercício P0507** · ★☆☆ · Raio-x do endereço

O cadastro da loja recebeu o endereço abaixo e quer saber do que ele é
feito. Conte, com as funções do ctype.h, as letras maiúsculas, as
minúsculas, os dígitos, os espaços e o resto (pontuação):


```text
char endereco[] = "Rua 7 de Setembro, 1500 - Centro";
```



```text
Saída esperada:
Maiúsculas: 3
Minúsculas: 16
Dígitos: 5
Espaços: 6
Outros: 2
Total: 32 (strlen = 32)
```

**Dicas:**

1. Ande até o '\0': for (int i = 0; endereco[i] != '\0'; i++).
2. Uma cadeia de if/else if com isupper, islower, isdigit e isspace; o que
   sobrar cai no else (outros).
3. Confira: a soma das cinco contagens tem que dar o strlen do endereço.
4. Resposta esperada: a saída acima (32 caracteres no total).

```bash
~/LPEDC/rodar 05-vetores-e-strings/lista/P0507.c
```

---

**Exercício P0508** · ★☆☆ · O nome do crachá

O crachá do congresso mostra o sobrenome em maiúsculas, uma vírgula e o
primeiro nome. Com


```text
char nome[] = "Raimunda";
char sobrenome[] = "Nonato";
```


monte numa terceira string char cracha[40] o texto "NONATO, Raimunda",
usando strcpy e strcat. Depois mostre o crachá, o tamanho dele (strlen) e
as iniciais "R.N.".


```text
Saída esperada:
Crachá: NONATO, Raimunda
Tamanho: 16
Iniciais: R.N.
```

**Dicas:**

1. strcpy(cracha, sobrenome) copia; depois passe cada posição de cracha
   por toupper até o '\0'.
2. strcat(cracha, ", ") e strcat(cracha, nome) completam o texto.
3. As iniciais são nome[0] e sobrenome[0]: mostre com %c.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 05-vetores-e-strings/lista/P0508.c
```

---

**Exercício P0509** · ★☆☆ · Conserte o contador de letras

A função conta abaixo deveria dizer quantas vezes uma letra aparece no nome
do rio. Ela tem DOIS erros de propósito, e o gcc avisa dos dois: rode, leia
os avisos (warning) e conserte. Depois de consertado, o programa mostra:


```text
Saída esperada:
Letra o: 3
Letra a: 2
Letra z: 1
```

**Dicas:**

1. Um vetor que chega como parâmetro vira só um endereço: sizeof s dá o
   tamanho de um endereço (8), não o da string. Use o '\0' para parar.
2. Dentro do if, = é atribuição; para comparar, use ==.
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 05-vetores-e-strings/lista/P0509.c
```

---

**Exercício P0510** · ★☆☆ · Quantos de cada número

Uma sapataria vendeu 14 pares de tênis num sábado, com estes números:


```text
int vendidos[14] = {38, 40, 37, 42, 40, 39, 40, 35, 38, 41, 40, 44, 38, 37};
```


A loja trabalha do 34 ao 44. Conte quantos pares de cada número saíram,
usando um vetor de contadores de 11 posições (uma por número), e mostre só
os números que venderam, com um # por par:


```text
Saída esperada:
35: # (1)
37: ## (2)
38: ### (3)
39: # (1)
40: #### (4)
41: # (1)
42: # (1)
44: # (1)
```

**Dicas:**

1. O número 34 vai na posição 0, o 35 na 1... o número n vai em n - 34.
2. Zere o vetor de contadores na declaração: int cont[11] = {0};
3. Um laço passa pelos 14 pares fazendo cont[vendidos[i] - 34]++; outro
   laço mostra de 0 a 10, pulando quem tem contador 0.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 05-vetores-e-strings/lista/P0510.c
```

## ★★☆ Para pensar

**Exercício P0511** · ★★☆ · Quanto custa cada receita em cada mercado

Uma doceira faz duas receitas. A matriz q (2x3) diz quantos quilos de cada
ingrediente cada receita usa (colunas: farinha, açúcar, chocolate), e a
matriz p (3x2) diz o preço do quilo de cada ingrediente em dois mercados:


```text
double q[2][3] = {{2.0, 1.0, 0.5},    // bolo
                  {1.0, 0.5, 1.0}};   // brigadeirão
double p[3][2] = {{5.50, 4.90},       // farinha: mercado A, B
                  {4.20, 4.80},       // açúcar
                  {38.00, 41.50}};    // chocolate
```


O custo de cada receita em cada mercado é o produto c = q x p (2x2):
c[i][j] = soma de q[i][k] * p[k][j], para k de 0 a 2. Escreva a função


```text
void multiplicar(double a[2][3], double b[3][2], double c[2][2]);
```


e mostre o resultado, dizendo o mercado mais barato para cada receita:


```text
Saída esperada:
Bolo: A = R$ 34.20, B = R$ 35.35 -> mais barato no A
Brigadeirão: A = R$ 45.60, B = R$ 48.80 -> mais barato no A
```

**Dicas:**

1. Três for aninhados: i (linhas de q), j (colunas de p) e k (o índice
   que "anda junto": coluna de q e linha de p).
2. Zere c[i][j] antes do laço em k e acumule com +=.
3. Uma matriz 2x3 só pode ser multiplicada por uma que tem 3 linhas: o
   número de colunas da primeira tem que ser o de linhas da segunda.
4. Resposta esperada: bolo R$ 34.20 x R$ 35.35 (A) e brigadeirão
   R$ 45.60 x R$ 48.80 (A).

```bash
~/LPEDC/rodar 05-vetores-e-strings/lista/P0511.c
```

---

**Exercício P0512** · ★★☆ · A tabela de distâncias é simétrica?

Uma transportadora de Manaus guarda as distâncias (em km) entre 4 bases numa
matriz 4x4. Se a ida e a volta têm a mesma distância, a matriz é SIMÉTRICA:
m[i][j] == m[j][i] para todo i e j. Uma delas foi digitada com erro:


```text
int d1[4][4] = {{0, 12, 30, 8}, {12, 0, 25, 17},
                {30, 25, 0, 21}, {8, 17, 21, 0}};
int d2[4][4] = {{0, 12, 30, 8}, {12, 0, 25, 17},
                {30, 52, 0, 21}, {8, 17, 21, 0}};
```


Escreva bool simetrica(int m[4][4], int erro[2]), que devolve se a matriz
é simétrica e, quando não for, guarda em erro[0] e erro[1] a linha e a coluna
do primeiro par diferente (com coluna maior que a linha).
Mostre também a soma dos números acima da diagonal principal (que, numa
tabela simétrica, é a soma de todas as distâncias, cada uma uma vez só):


```text
Saída esperada:
d1: simétrica, soma acima da diagonal = 113 km
d2: NÃO simétrica em [1][2] (25 x 52)
```

**Dicas:**

1. Só precisa olhar acima da diagonal: j começa em i + 1. Cada par (i, j)
   é comparado com (j, i) uma vez só.
2. Um vetor passado para a função é alterado no original: é assim que
   erro[0] e erro[1] voltam para o main.
3. Acima da diagonal principal, j > i.
4. Resposta esperada: d1 simétrica com soma 113; d2 não simétrica, primeiro
   erro em [1][2] (25 x 52).

```bash
~/LPEDC/rodar 05-vetores-e-strings/lista/P0512.c
```

---

**Exercício P0513** · ★★☆ · Busca binária nos CEPs

A transportadora guarda 10 CEPs de entrega em ordem crescente:


```text
int ceps[10] = {69005010, 69020030, 69040000, 69050010, 69053000,
                69057040, 69060000, 69075351, 69083000, 69097290};
```


Num vetor ORDENADO dá para buscar sem olhar um por um: compare com o do
meio; se o procurado for menor, descarte a metade de cima; se for maior, a
de baixo. Escreva int busca_binaria(const int v[], int n, int x, int
passos[1]), que devolve a posição de x (ou -1) e guarda em passos[0]
quantas comparações com o meio fez. Procure 69075351, 69005010 e 69099999:


```text
Saída esperada:
CEP 69075351: posição 7 em 2 passos
CEP 69005010: posição 0 em 3 passos
CEP 69099999: não atendido (4 passos)
```

**Dicas:**

1. Use ini = 0 e fim = n - 1. Enquanto ini <= fim: meio = (ini + fim) / 2.
2. Se v[meio] == x, achou. Se x < v[meio], fim = meio - 1; senão,
   ini = meio + 1.
3. Conte um passo a cada volta do while (cada vez que olha o meio).
4. Com 10 itens, a busca linear chega a 10 comparações; a binária, no pior
   caso, a 4.
5. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 05-vetores-e-strings/lista/P0513.c
```

---

**Exercício P0514** · ★★☆ · Encaixar na fila preferencial

A fila do cartório é ordenada pela idade, do mais velho para o mais novo.
Ela cabe até 10 pessoas e hoje tem 6:


```text
int idades[10] = {91, 84, 77, 70, 66, 61};
int n = 6;
```


Escreva int inserir(int v[], int n, int cap, int idade), que encaixa a idade
no lugar certo (empurrando os mais novos uma casa para a direita) e devolve
o novo tamanho. Se a fila estiver cheia, não mexe e devolve n. Insira 80,
95 e 60, mostrando a fila depois de cada inserção:


```text
Saída esperada:
Entrou 80: 91 84 80 77 70 66 61
Entrou 95: 95 91 84 80 77 70 66 61
Entrou 60: 95 91 84 80 77 70 66 61 60
```

**Dicas:**

1. Comece do fim: i = n - 1. Enquanto i >= 0 e v[i] < idade, copie v[i]
   para v[i + 1] e ande i para trás.
2. Quando o laço para, o lugar livre é i + 1.
3. Por que do fim? Se você empurrar a partir do começo, cada cópia apaga o
   valor que ainda ia ser copiado.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 05-vetores-e-strings/lista/P0514.c
```

---

**Exercício P0515** · ★★☆ · Tirar da vitrine o que acabou

A loja on-line tem 9 produtos, cada um com um código e o estoque, em dois
vetores paralelos (a posição i dos dois fala do mesmo produto):


```text
int codigo[9]  = {11, 12, 13, 14, 15, 16, 17, 18, 19};
int estoque[9] = { 4,  0,  7,  0,  0,  2,  9,  0,  1};
```


Escreva int compactar(int cod[], int est[], int n), que remove dos DOIS
vetores os produtos com estoque 0, sem usar vetor auxiliar e mantendo a
ordem, e devolve quantos sobraram. Mostre os vetores antes e depois:


```text
Saída esperada:
Antes (9):  11:4 12:0 13:7 14:0 15:0 16:2 17:9 18:0 19:1
Depois (5): 11:4 13:7 16:2 17:9 19:1
```

**Dicas:**

1. Use dois índices: i lê todas as posições e k marca onde o próximo
   produto que fica vai ser escrito.
2. Se est[i] != 0, copie cod[i] e est[i] para a posição k e faça k++.
3. No fim, k é o novo tamanho. É uma passada só: n operações, e não n²
   como "apagar e empurrar tudo" a cada zero.
4. Resposta esperada: a saída acima (sobram 5 produtos).

```bash
~/LPEDC/rodar 05-vetores-e-strings/lista/P0515.c
```

---

**Exercício P0516** · ★★☆ · A mediana do tempo de entrega

O app de entregas mediu, em minutos, as 9 últimas corridas de um motoboy:


```text
int tempos[9] = {34, 18, 52, 27, 41, 23, 19, 60, 30};
```


A média engana quando há corrida muito demorada; a MEDIANA é o valor do
meio depois de ordenar. Ordene o vetor com a ordenação por seleção (a cada
passo, ache o menor do que sobrou e troque com a posição i), mostrando o
vetor depois de cada passo. No fim, mostre a média e a mediana:


```text
Saída esperada:
Passo 1: 18 34 52 27 41 23 19 60 30
Passo 2: 18 19 52 27 41 23 34 60 30
Passo 3: 18 19 23 27 41 52 34 60 30
Passo 4: 18 19 23 27 41 52 34 60 30
Passo 5: 18 19 23 27 30 52 34 60 41
Passo 6: 18 19 23 27 30 34 52 60 41
Passo 7: 18 19 23 27 30 34 41 60 52
Passo 8: 18 19 23 27 30 34 41 52 60
Média: 33.78 min
Mediana: 30 min
```

**Dicas:**

1. Para i de 0 a n - 2: ache o índice do menor entre v[i] e v[n - 1] e
   troque-o com v[i]. Mostre o vetor depois da troca.
2. Com n ímpar, a mediana é v[n / 2] depois de ordenado.
3. A média usa double: soma / (double) n.
4. Resposta esperada: a saída acima (média 33.78, mediana 30).

```bash
~/LPEDC/rodar 05-vetores-e-strings/lista/P0516.c
```

---

**Exercício P0517** · ★★☆ · Arrumando os espaços do endereço

O formulário do correio recebeu um endereço cheio de espaços sobrando:


```text
char end[] = "   Av.   Eduardo    Ribeiro ,  620   ";
```


Escreva void normalizar(char s[]), que arruma a string NO LUGAR: tira os
espaços do começo e do fim, deixa um espaço só entre as palavras e tira o
espaço que vem antes de vírgula. Mostre a string entre colchetes, antes e
depois, e o strlen de cada uma:


```text
Saída esperada:
Antes:  [   Av.   Eduardo    Ribeiro ,  620   ] (37)
Depois: [Av. Eduardo Ribeiro, 620] (24)
```

**Dicas:**

1. Mesma ideia de compactar vetor: i lê, k escreve. A string só encolhe,
   então escrever em s[k] nunca atropela o que i ainda vai ler.
2. Ao ver um espaço, não escreva na hora: lembre que "tem espaço pendente".
   Ao ver um caractere que não é espaço, escreva o espaço pendente antes
   (se k > 0 e o caractere não for vírgula) e depois o caractere.
3. Espaço pendente no fim é simplesmente descartado. Feche com s[k] = '\0'.
4. Resposta esperada: [Av. Eduardo Ribeiro, 620], com 24 caracteres.

```bash
~/LPEDC/rodar 05-vetores-e-strings/lista/P0517.c
```

---

**Exercício P0518** · ★★☆ · O telefone digitado de qualquer jeito

O cadastro da farmácia lê o celular com fgets, e cada pessoa digita de um
jeito: "92 99123-4567", "(92)991234567", "92.99123.4567". Escreva um
programa que lê UMA linha com fgets num char linha[40], guarda só os
dígitos numa outra string e:
- se sobrarem exatamente 11 dígitos, mostra "Celular: (92) 99123-4567";
- senão, mostra "Inválido: 9 dígitos" (com a quantidade que veio).


```text
Exemplo de execução 1:
(92)991234567
Celular: (92) 99123-4567
```



```text
(a primeira linha é a que você digita; só a segunda é do programa)
```



```text
Exemplo de execução 2:
9912-3456
Inválido: 8 dígitos
```

**Dicas:**

1. if (fgets(linha, sizeof linha, stdin) == NULL) return 1; protege contra
   entrada vazia. O '\n' do fim nem atrapalha: ele não é dígito.
2. Monte digitos[] com isdigit, um k que avança e digitos[k] = '\0' no fim.
3. Para formatar, mostre os caracteres por posição: %c%c para o DDD, depois
   5 dígitos, traço e os 4 últimos. Um laço de i a j ajuda.
4. Teste com printf '(92)991234567\n' | ./rodar ... e com 9912-3456.
5. Resposta esperada: as duas execuções acima.

```bash
~/LPEDC/rodar 05-vetores-e-strings/lista/P0518.c
```

---

**Exercício P0519** · ★★☆ · Totais da planilha de vendas

A sorveteria anota as vendas (em potes) de 3 sabores em 4 semanas:


```text
int v[3][4] = {{40, 35, 52, 48}, {22, 30, 27, 31}, {15, 18, 12, 25}};
```


Complete o programa: falta calcular o total de cada sabor (linha), o total
de cada semana (coluna) e o total geral, para a tabela sair assim:


```text
Saída esperada:
            S1   S2   S3   S4  Total
Coco        40   35   52   48    175
Manga       22   30   27   31    110
Tapioca     15   18   12   25     70
Total       77   83   91  104    355
```

**Dicas:**

1. O total da linha i soma v[i][j] variando j; o da coluna j soma v[i][j]
   variando i.
2. Você pode fazer tudo num par de for só, acumulando em tot_lin[i],
   tot_col[j] e geral ao mesmo tempo.
3. Confira: a soma dos totais das linhas é igual à soma dos totais das
   colunas, e as duas dão o total geral.
4. Resposta esperada: a saída acima (total geral 355).

```bash
~/LPEDC/rodar 05-vetores-e-strings/lista/P0519.c
```

---

**Exercício P0520** · ★★☆ · O meu atoi

O extrato do banco chegou como texto, e cada lançamento é uma string:


```text
char lanc[5][8] = {"1200", "-350", "+80", "-1045", "75"};
```


Escreva int texto_para_int(const char s[]), que converte a string em int
SEM usar atoi nem sscanf: aceita um sinal opcional (+ ou -) no começo e
para no primeiro caractere que não é dígito. Mostre cada valor convertido
e o saldo final (a soma de todos):


```text
Saída esperada:
"1200" -> 1200
"-350" -> -350
"+80" -> 80
"-1045" -> -1045
"75" -> 75
Saldo: -40
```

**Dicas:**

1. Um char dígito vira número com s[i] - '0' (o '7' vale 55 na tabela
   ASCII, o '0' vale 48: 55 - 48 = 7).
2. Para juntar os dígitos: valor = valor * 10 + (s[i] - '0'). "1200" passa
   por 1, 12, 120, 1200.
3. Guarde o sinal numa variável (1 ou -1) e multiplique no fim.
4. Resposta esperada: a saída acima (saldo -40).

```bash
~/LPEDC/rodar 05-vetores-e-strings/lista/P0520.c
```

## ★★★ Desafio

**Exercício P0521** · ★★★ · Quem ganhou o jogo da velha

Escreva o juiz do jogo da velha. O tabuleiro tem 3 linhas de 3 casas, com
'X', 'O' ou '.' (casa vazia), e cada linha é uma string: char t[3][4] (3
letras + '\0'). Escreva:


```text
char vencedor(char t[3][4]);  // 'X', 'O' ou '.' se ninguém fechou linha
bool cheio(char t[3][4]);     // true se não sobrou casa vazia
```


e void julgar(char t[3][4]), que mostra o tabuleiro e uma das três frases:
"Vitória do X", "Deu velha" ou "Em andamento". Julgue os quatro tabuleiros
abaixo (escritos linha por linha):


```text
"XOX" "OXO" "OOX"   (X na diagonal principal)
"OXX" "XOO" "XOX"   (cheio, ninguém fechou)
"XX." "OO." "..."   (ainda tem jogo)
"XXO" "XOX" "OXX"   (O na diagonal secundária)
```



```text
Saída esperada:
Jogo 1:
X O X
O X O
O O X
Vitória do X
Jogo 2:
O X X
X O O
X O X
Deu velha
Jogo 3:
X X .
O O .
. . .
Em andamento
Jogo 4:
X X O
X O X
O X X
Vitória do O
```

**Dicas:**

1. São 8 linhas para conferir: 3 linhas, 3 colunas e 2 diagonais. Para cada
   uma, as três casas são iguais e diferentes de '.'?
2. Um laço de i = 0 a 2 confere a linha i (t[i][0], t[i][1], t[i][2]) e a
   coluna i (t[0][i], t[1][i], t[2][i]). As diagonais ficam fora do laço.
3. A ordem dos testes no julgar importa: um tabuleiro cheio pode ter
   vencedor, então pergunte primeiro por vencedor.
4. Os tabuleiros estão em char jogos[4][3][4]: 4 jogos, 3 linhas, 3 letras
   + '\0'. jogos[k] é um char [3][4]: passe direto para a função.
5. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 05-vetores-e-strings/lista/P0521.c
```

---

**Exercício P0522** · ★★★ · A matriz esparsa do estacionamento

Um estacionamento de 5 andares e 6 setores anota quantos carros estão
parados em cada setor. Quase tudo é zero:


```text
int m[5][6] = {{0, 0, 3, 0, 0, 0},
               {0, 0, 0, 0, 0, 7},
               {1, 0, 0, 0, 0, 0},
               {0, 0, 4, 0, 0, 0},
               {0, 2, 0, 0, 0, 0}};
```


Guardar 30 números para 5 que importam é desperdício. Uma MATRIZ ESPARSA
guarda só as triplas (linha, coluna, valor) dos que não são zero. Escreva:
- int compactar(int m[5][6], int t[][3]): preenche as triplas, varrendo

```text
linha por linha, e devolve quantas são;
```

- int transpor(int t[][3], int k, int tt[][3]): monta as triplas da

```text
transposta (6x5) JÁ em ordem de linha, sem montar a matriz cheia;
```

- void mostrar_cheia(int t[][3], int k, int linhas, int colunas): mostra

```text
a matriz completa a partir das triplas (zero onde não há tripla).
```



```text
Saída esperada:
5 de 30 casas guardadas
Triplas: (0,2,3) (1,5,7) (2,0,1) (3,2,4) (4,1,2)
Transposta: (0,2,1) (1,4,2) (2,0,3) (2,3,4) (5,1,7)
Transposta cheia (6x5):
0 0 1 0 0
0 0 0 0 2
3 0 0 4 0
0 0 0 0 0
0 0 0 0 0
0 7 0 0 0
```

**Dicas:**

1. Na transposta, a tripla (l, c, v) vira (c, l, v). Para sair em ordem de
   linha da transposta, percorra as colunas c = 0 a 5 da original e, para
   cada uma, passe pelas k triplas pegando as que têm coluna c.
2. Para mostrar a cheia sem montar a matriz, para cada (i, j) procure uma
   tripla com linha i e coluna j; achou, mostra o valor; senão, 0.
3. As triplas cabem em int t[30][3] (no pior caso, nada é zero).
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 05-vetores-e-strings/lista/P0522.c
```

---

**Exercício P0523** · ★★★ · Lendo a planilha em CSV

Uma planilha de municípios do Amazonas foi exportada em CSV, com os campos
separados por ponto e vírgula (cidade;UF;população). Uma das linhas veio com
a UF vazia:


```text
char linhas[4][48] = {"Manaus;AM;2063547", "Parintins;;96372",
                      "Itacoatiara;AM;103598", "Manacapuru;AM;101883"};
```


Escreva int separar(const char linha[], char campos[3][32]), que copia
cada campo para uma linha de campos (sem usar strtok) e devolve quantos
campos achou. Converta a população com a sua própria conta de dígitos (nada
de atoi). Mostre uma tabela alinhada, com "??" no lugar da UF vazia, e no
fim o total e a cidade mais populosa:


```text
Saída esperada:
Manaus       AM   2063547
Parintins    ??     96372
Itacoatiara  AM    103598
Manacapuru   AM    101883
Total: 2365400 habitantes
Mais populosa: Manaus
```

**Dicas:**

1. Ande pela linha com i; um índice c diz em qual campo você está e um j,
   a posição dentro do campo. Ao ver ';', feche o campo atual com '\0',
   faça c++ e j = 0. No fim da linha, feche o último campo.
2. Campo vazio não é problema: ";;" fecha um campo com zero caracteres,
   e campos[1][0] fica '\0'. Teste com campos[1][0] == '\0'.
3. Para a tabela: printf("%-12s %-3s %8d\n", ...).
4. Total e maior: guarde o índice da maior população, como no P0501.
5. Resposta esperada: a saída acima (total 2365400, Manaus a maior).

```bash
~/LPEDC/rodar 05-vetores-e-strings/lista/P0523.c
```

---

**Exercício P0524** · ★★★ · A nuvem de palavras do trava-língua

Conte quantas vezes cada palavra aparece no trava-língua abaixo, sem
diferenciar maiúscula de minúscula. Mostre as palavras na ordem em que
apareceram pela primeira vez e, no fim, a mais repetida (no empate, a que
apareceu antes):


```text
char frase[] = "O rato roeu a roupa do Rei de Roma, e o rei riu do rato.";
```


Guarde as palavras distintas numa matriz char palavras[20][16] e as
contagens num vetor int cont[20].


```text
Saída esperada:
o      2
rato   2
roeu   1
a      1
roupa  1
do     2
rei    2
de     1
roma   1
e      1
riu    1
Distintas: 11
Mais repetida: o (2 vezes)
```

**Dicas:**

1. Monte cada palavra numa string auxiliar char p[16]: junte letras
   (isalpha), já em minúscula (tolower); ao ver algo que não é letra, se p
   tiver alguma letra, feche com '\0' e processe.
2. Processar: procure p em palavras[0..n-1] com strcmp. Achou na posição
   k? cont[k]++. Não achou? strcpy(palavras[n], p), cont[n] = 1, n++.
3. Cuidado com a última palavra: se a frase não terminar com pontuação,
   ela fica em p quando o laço acaba. Processe-a depois do laço também.
4. Resposta esperada: a saída acima (11 palavras distintas).

```bash
~/LPEDC/rodar 05-vetores-e-strings/lista/P0524.c
```

---

**Exercício P0525** · ★★★ · A ronda em espiral

O vigia de um galpão com 4 corredores de 5 prateleiras faz a ronda em
espiral: vai pela borda de cima da esquerda para a direita, desce pela
direita, volta por baixo, sobe pela esquerda e repete por dentro, até passar
por todas. Cada prateleira tem um número:


```text
int g[4][5] = {{ 1,  2,  3,  4,  5},
               { 6,  7,  8,  9, 10},
               {11, 12, 13, 14, 15},
               {16, 17, 18, 19, 20}};
```


Mostre a ordem da ronda e, depois, uma matriz com o número do passo em que
cada prateleira foi visitada (%3d):


```text
Saída esperada:
Ronda: 1 2 3 4 5 10 15 20 19 18 17 16 11 6 7 8 9 14 13 12
  1  2  3  4  5
 14 15 16 17  6
 13 20 19 18  7
 12 11 10  9  8
```

**Dicas:**

1. Guarde quatro limites: cima = 0, baixo = 3, esq = 0, dir = 4. Cada
   volta percorre a linha cima (e faz cima++), a coluna dir (dir--), a
   linha baixo de trás para a frente (baixo--) e a coluna esq de baixo
   para cima (esq++).
2. Depois de cima++ e de dir--, o retângulo pode ter sumido: confira
   cima <= baixo antes da linha de baixo e esq <= dir antes da coluna da
   esquerda. Sem isso, matrizes não quadradas repetem casas.
3. Um contador de passos que começa em 1 preenche a segunda matriz.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 05-vetores-e-strings/lista/P0525.c
```

---

**Exercício P0526** · ★★★ · O cartão passa no teste de Luhn?

Antes de mandar o pagamento para o banco, a loja confere se o número do
cartão foi digitado direito com o algoritmo de Luhn:
1. Ande pelos dígitos da DIREITA para a esquerda.
2. Dobre um dígito sim, um não, começando pelo SEGUNDO da direita. Se o

```text
 dobro passar de 9, subtraia 9 (8 * 2 = 16 vira 7).
```

3. Some tudo. O número é válido se a soma for múltipla de 10.

Escreva bool luhn(const char s[], int soma[1]), que ignora espaços (e recusa
qualquer
outro caractere que não seja dígito) e confira os quatro números abaixo,
mostrando também a soma:


```text
"4539 1488 0343 6467"
"4539 1488 0343 6468"
"79927398713"
"1234-5678"
```



```text
Saída esperada:
4539 1488 0343 6467  soma  80 -> válido
4539 1488 0343 6468  soma  81 -> inválido
79927398713          soma  70 -> válido
1234-5678            soma  -1 -> inválido
```

**Dicas:**

1. Comece em i = strlen(s) - 1 e desça até 0. Um contador de dígitos já
   vistos (pos) diz se este é para dobrar: dobra quando pos é ímpar.
2. Guarde a soma em soma[0], para o main mostrar; ponha -1 lá quando
   aparecer caractere inválido.
3. Espaço: continue. Não dígito e não espaço: return false.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 05-vetores-e-strings/lista/P0526.c
```

---

**Exercício P0527** · ★★★ · A lista de chamada em ordem

A professora digitou a lista de chamada fora de ordem:


```text
char nomes[7][20] = {"Thiago", "Ana Clara", "Bruno", "Yasmin",
                     "Ana Beatriz", "Davi", "Larissa"};
```


Escreva void ordenar(char v[][20], int n), que põe os nomes em ordem
alfabética com o método da bolha (compare vizinhos com strcmp e troque com
strcpy e uma string auxiliar). Depois escreva int buscar(char v[][20], int
n, const char nome[]), uma busca binária que devolve a posição do nome ou
-1. Mostre a lista numerada e procure "Davi" e "Carla":


```text
Saída esperada:
1. Ana Beatriz
2. Ana Clara
3. Bruno
4. Davi
5. Larissa
6. Thiago
7. Yasmin
Davi: número 4 da chamada
Carla: não está na lista
```

**Dicas:**

1. Bolha: para cada passada, compare v[j] com v[j + 1]; se
   strcmp(v[j], v[j + 1]) > 0, troque as duas strings (aux = v[j], v[j] =
   v[j + 1], v[j + 1] = aux, cada atribuição com strcpy).
2. Não dá para trocar strings com =: o nome de um vetor não é uma variável
   que se possa atribuir.
3. Na busca binária, strcmp(nome, v[meio]) negativo manda para a metade de
   baixo; positivo, para a de cima; zero, achou.
4. Resposta esperada: a saída acima ("Ana Beatriz" vem antes de "Ana Clara"
   porque 'B' < 'C').

```bash
~/LPEDC/rodar 05-vetores-e-strings/lista/P0527.c
```

---

**Exercício P0528** · ★★★ · O sudoku 4x4 está certo?

Um sudoku 4x4 está certo quando cada linha, cada coluna e cada um dos
quatro quadrados 2x2 tem os números 1, 2, 3 e 4, sem repetir. Escreva
bool valido(int s[4][4]), que mostra a PRIMEIRA regra quebrada (no formato
da saída) e devolve false, ou devolve true se tudo estiver certo. Teste:


```text
int a[4][4] = {{1, 2, 3, 4}, {3, 4, 1, 2}, {2, 1, 4, 3}, {4, 3, 2, 1}};
int b[4][4] = {{1, 2, 3, 4}, {3, 4, 1, 2}, {2, 1, 4, 3}, {4, 2, 3, 1}};
int c[4][4] = {{1, 2, 3, 4}, {2, 1, 4, 3}, {3, 4, 1, 2}, {4, 3, 2, 1}};
```



```text
Saída esperada:
a:
  certo
b:
  erro na coluna 1
  errado
c:
  erro no quadrado 0
  errado
```

**Dicas:**

1. Escreva bool tem_1_a_4(int g[4]): marca num vetor bool visto[5] cada
   número; se aparecer um fora de 1..4 ou repetido, false.
2. Para cada linha i, copie s[i][0..3] num vetor g e teste. Para cada
   coluna j, copie s[0..3][j]. Para cada quadrado (q de 0 a 3), o canto é
   linha (q / 2) * 2 e coluna (q % 2) * 2.
3. Teste nessa ordem (linhas, colunas, quadrados) e pare no primeiro erro.
4. Resposta esperada: a saída acima (b quebra a coluna 1; c só quebra um
   quadrado, apesar das linhas e colunas certas).

```bash
~/LPEDC/rodar 05-vetores-e-strings/lista/P0528.c
```

---

**Exercício P0529** · ★★★ · Conserte o gerador de etiquetas

O programa abaixo gera a etiqueta de envio "PARA: <nome> - <cidade>/<UF>"
e confere se o envio é expresso. Ele tem TRÊS erros de propósito:
- um o gcc avisa (leia o warning);
- um o AddressSanitizer acusa quando roda;
- um é de lógica: o programa roda, mas a etiqueta sai errada.

Conserte os três. Ele deve mostrar:


```text
Saída esperada:
PARA: Benedita Farias - Boa Vista/RR
Tamanho: 36
Envio expresso: entrega em 2 dias
```

**Dicas:**

1. Comparar strings com == compara os ENDEREÇOS dos dois vetores, não o
   texto: use strcmp(...) == 0.
2. Conte os bytes da etiqueta: "PARA: " (6) + nome + " - " (3) + cidade +
   "/" + UF + '\0'. Cabe em 24?
3. strcpy no lugar do primeiro strcat apaga o que já estava lá; strcat no
   lugar do strcpy inicial lê lixo. Olhe qual dos dois está em cada linha.
4. Resposta esperada: a saída acima (etiqueta com 36 caracteres).

```bash
~/LPEDC/rodar 05-vetores-e-strings/lista/P0529.c
```

---

**Exercício P0530** · ★★★ · O fatorial que não cabe no long long

O fatorial de 30 tem 33 dígitos, e um unsigned long long vai só até uns
1,8 x 10^19 (20 dígitos). Calcule 30! guardando o número num vetor de
dígitos, int d[60], com o dígito das unidades em d[0], o das dezenas em
d[1], e assim por diante, e um int tam com quantos dígitos estão em uso.

Escreva void multiplicar(int d[], int tam[1], int k), que multiplica o
número por um int pequeno k (até 100) e atualiza tam[0] (um vetor de uma
posição volta alterado para o main, como o erro[] do P0512), do jeito que
se faz à mão: dígito a dígito, levando o "vai um". Mostre 10!, 20!, 25! e
30!, com o número de dígitos de cada um:


```text
Saída esperada:
10! = 3628800 (7 dígitos)
20! = 2432902008176640000 (19 dígitos)
25! = 15511210043330985984000000 (26 dígitos)
30! = 265252859812191058636308480000000 (33 dígitos)
```

**Dicas:**

1. Comece com d[0] = 1 e tam[0] = 1 (o número 1).
2. Para multiplicar por k: vai = 0; para i de 0 a tam - 1, faça
   x = d[i] * k + vai; d[i] = x % 10; vai = x / 10.
3. Depois do laço, o "vai" que sobrou vira dígitos novos no fim: enquanto
   vai > 0, d[tam++] = vai % 10 e vai /= 10.
4. Para mostrar, ande de d[tam - 1] até d[0]: o dígito mais importante
   está no fim do vetor.
5. Resposta esperada: a saída acima (30! =
   265252859812191058636308480000000).

```bash
~/LPEDC/rodar 05-vetores-e-strings/lista/P0530.c
```
