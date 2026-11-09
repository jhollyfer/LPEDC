<!-- Gerado por _gerador a partir dos arquivos P????.c desta pasta. -->

# Lista prática · Módulo 07 · Memória dinâmica

30 exercícios de codificar que treinam o módulo inteiro, misturando os assuntos, no ritmo da prova do PPGI (veja [PPGI.md](../../PPGI.md)). Cada arquivo `P????.c` desta pasta é um exercício: a resposta vai dentro dele, embaixo de `// Escreva sua resposta abaixo:`. Uma resolução de cada um está em `_respostas/07-memoria-dinamica/lista/`. Só olhe depois de tentar.

[Voltar ao módulo](../README.md)

## ★☆☆ Aquecimento

**Exercício P0701** · ★☆☆ · Uma cópia no heap

O motorista de aplicativo anotou os km rodados nas corridas de hoje:


```text
double km[6] = {12.4, 3.8, 25.1, 7.6, 18.0, 5.3};
```


Escreva double *copiar(const double *v, int n), que reserva com malloc um
bloco novo do tamanho exato, copia os n valores e devolve o endereço (ou
NULL se faltar memória). No main, faça a cópia, aplique na CÓPIA um
desconto de 10% em cada corrida e mostre os dois vetores e o total de cada
um. No fim, libere a cópia:


```text
Saída esperada:
Original: 12.40  3.80 25.10  7.60 18.00  5.30 | total 72.20
Desconto: 11.16  3.42 22.59  6.84 16.20  4.77 | total 64.98
```

**Dicas:**

1. double *novo = malloc(n * sizeof *novo); e confira if (novo == NULL).
2. sizeof *novo é o tamanho de UM double (8 bytes): escrever assim
   continua certo mesmo se o tipo do ponteiro mudar.
3. km mora na pilha (some com o main); a cópia mora no heap e só some com
   free.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 07-memoria-dinamica/lista/P0701.c
```

---

**Exercício P0702** · ★☆☆ · Juntar nome e sobrenome no heap

Escreva


```text
char *juntar(const char *a, const char *sep, const char *b, size_t *bytes);
```


que devolve uma string NOVA no heap com a, sep e b em sequência, do tamanho
exato (nem um byte a mais), e guarda em *bytes quanto pediu ao malloc. Junte
"Francisca" e "Pereira" com " " e
"Manaus" e "AM" com " - ". Mostre cada resultado, o strlen e quantos bytes
foram pedidos ao malloc, e libere as duas:


```text
Saída esperada:
"Francisca Pereira": strlen 17, malloc de 18 bytes
"Manaus - AM": strlen 11, malloc de 12 bytes
```

**Dicas:**

1. Os bytes: strlen(a) + strlen(sep) + strlen(b) + 1. O + 1 é do '\0'.
2. Depois do malloc: strcpy(novo, a); strcat(novo, sep); strcat(novo, b);
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 07-memoria-dinamica/lista/P0702.c
```

---

**Exercício P0703** · ★☆☆ · A lista de espera que cresce de 3 em 3

O posto de vacinação registra as senhas que chegam num vetor dinâmico de
int que começa com capacidade 3 e, quando enche, ganha mais 3 posições com
realloc. Chegaram estas 8 senhas:


```text
int chegada[8] = {501, 502, 503, 504, 505, 506, 507, 508};
```


Adicione uma de cada vez e mostre uma linha toda vez que a capacidade
mudar. No fim, mostre o vetor e libere:


```text
Saída esperada:
Capacidade inicial: 3
Senha 504 não cabia: capacidade agora 6
Senha 507 não cabia: capacidade agora 9
Fila (8 de 9): 501 502 503 504 505 506 507 508
```

**Dicas:**

1. Guarde três coisas: int *v, int n (quantos estão em uso) e int cap
   (quantos cabem).
2. Antes de pôr a senha: if (n == cap) { int *novo = realloc(v, (cap + 3)
   * sizeof *v); ... }. Use um ponteiro novo: se o realloc falhar, v
   continua valendo e precisa ser liberado.
3. Para começar, v = malloc(3 * sizeof *v) e cap = 3.
4. Resposta esperada: a saída acima (3 -> 6 -> 9).

```bash
~/LPEDC/rodar 07-memoria-dinamica/lista/P0703.c
```

---

**Exercício P0704** · ★☆☆ · A identidade do tamanho que pedirem

Escreva int **identidade(int n), que monta no heap uma matriz n x n (um
vetor de n ponteiros, cada um apontando para uma linha alocada com calloc)
com 1 na diagonal e 0 no resto, e void liberar(int **m, int n). No main,
monte e mostre as identidades de tamanho 2 e 4 e libere as duas:


```text
Saída esperada:
Identidade 2x2:
1 0
0 1
Identidade 4x4:
1 0 0 0
0 1 0 0
0 0 1 0
0 0 0 1
```

**Dicas:**

1. int **m = malloc(n * sizeof *m); e, para cada linha, m[i] =
   calloc(n, sizeof *m[i]); — o calloc já entrega a linha zerada.
2. Com a linha zerada, basta m[i][i] = 1.
3. Se o calloc de uma linha falhar, libere as linhas que já deram certo
   e o vetor de ponteiros, e devolva NULL.
4. Ordem do free: primeiro cada linha, depois o vetor de ponteiros.
5. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 07-memoria-dinamica/lista/P0704.c
```

---

**Exercício P0705** · ★☆☆ · Conserte os dois free

O programa da padaria guarda as encomendas do dia no heap. Ele tem DOIS
erros de propósito. O gcc já desconfia dos dois (leia os warnings), e o
AddressSanitizer confirma, um de cada vez: rode, leia o relatório (a
primeira linha diz o tipo do erro e a linha do programa), conserte e rode
de novo. Ele deve mostrar:


```text
Saída esperada:
Maior encomenda: 50
Total: 100 pães
```

**Dicas:**

1. heap-use-after-free: o programa lê o bloco depois de devolvê-lo. Mova o
   free para depois do último uso.
2. attempting free on address which was not malloc()-ed: só se passa para
   o free um endereço que veio do malloc, calloc ou realloc. Variável
   local mora na pilha e some sozinha.
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 07-memoria-dinamica/lista/P0705.c
```

---

**Exercício P0706** · ★☆☆ · O cartão mascarado

O comprovante da maquininha mostra só os 4 últimos dígitos do cartão.
Escreva char *mascarar(const char *num), que devolve uma string NOVA no
heap, do mesmo tamanho de num, com cada dígito trocado por '*', menos os 4
últimos dígitos (espaços continuam espaços). O original não muda. Teste:


```text
const char *cartoes[3] = {"4539 1488 0343 6467", "5162 3001 9925", "1234"};
```



```text
Saída esperada:
4539 1488 0343 6467  -> **** **** **** 6467
5162 3001 9925       -> **** **** 9925
1234                 -> 1234
```

**Dicas:**

1. Primeiro conte os dígitos da string inteira (isdigit). Depois copie
   caractere a caractere, contando de novo: o dígito número k (a partir
   de 0) vira '*' se k < total - 4.
2. malloc(strlen(num) + 1) e não esqueça o '\0' no fim da cópia.
3. Quem chama recebe o bloco e é quem faz o free.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 07-memoria-dinamica/lista/P0706.c
```

---

**Exercício P0707** · ★☆☆ · Faixas de idade do tamanho certo

A campanha de vacinação registrou as idades abaixo e quer contar quantas
pessoas há em cada faixa de 10 anos (0-9, 10-19, ...). O número de faixas
depende da maior idade, então o vetor de contadores é criado com calloc
DEPOIS de achar a maior:


```text
int idades[12] = {67, 8, 34, 71, 15, 42, 88, 3, 59, 64, 27, 80};
```


Mostre quantas faixas foram criadas e a contagem de cada uma (inclusive as
vazias), e libere o vetor:


```text
Saída esperada:
9 faixas
 0- 9: 2
10-19: 1
20-29: 1
30-39: 1
40-49: 1
50-59: 1
60-69: 2
70-79: 1
80-89: 2
```

**Dicas:**

1. faixas = maior / 10 + 1. Com maior 88, são 9 faixas (0-9 até 80-89).
2. int *cont = calloc(faixas, sizeof *cont); — o calloc zera, então dá
   para fazer cont[idades[i] / 10]++ direto.
3. Com malloc, os contadores começariam com lixo.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 07-memoria-dinamica/lista/P0707.c
```

---

**Exercício P0708** · ★☆☆ · A transposta numa matriz nova

Escreva int **transposta(int **m, int l, int c), que devolve uma matriz
NOVA no heap, c x l, com t[j][i] = m[i][j]. A original continua inteira.
Use funções criar(l, c) e liberar(m, l), como no texto do assunto 0056. No
main, crie a matriz 2x3 de horas extras abaixo (linhas: Ana e Davi; colunas:
semana 1 a 3), monte a transposta, mostre as duas e libere as duas:


```text
2 5 1
4 0 3
```



```text
Saída esperada:
Original (2x3):
2 5 1
4 0 3
Transposta (3x2):
2 4
5 0
1 3
```

**Dicas:**

1. A transposta tem c linhas de l colunas: int **t = criar(c, l);
2. Na hora de liberar, cada matriz é liberada com o SEU número de
   linhas: liberar(m, 2) e liberar(t, 3).
3. Se criar devolver NULL, libere o que já existe antes de sair.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 07-memoria-dinamica/lista/P0708.c
```

---

**Exercício P0709** · ★☆☆ · O realloc não zera

O calloc entrega o bloco zerado, mas, quando o realloc aumenta o bloco, a
parte nova vem com o que estiver lá (lixo). Escreva


```text
int *crescer_zerado(int *v, int n_velho, int n_novo);
```


que aumenta o bloco com realloc e zera SÓ as posições novas (de n_velho a
n_novo - 1), devolvendo o novo endereço (ou NULL, deixando v intacto). No
main, crie com calloc os pontos de 3 jogadores de um torneio de dominó,
anote algumas vitórias, cresça para 5 jogadores e anote mais. Mostre o
placar nas duas etapas:


```text
Saída esperada:
Placar (3 jogadores): 2 0 1
Placar (5 jogadores): 3 0 1 0 3
```

**Dicas:**

1. int *novo = realloc(v, n_novo * sizeof *novo); if (novo == NULL)
   return NULL;
2. for (int i = n_velho; i < n_novo; i++) novo[i] = 0;
3. As posições antigas o realloc preserva (ele copia, se precisar mudar o
   bloco de lugar).
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 07-memoria-dinamica/lista/P0709.c
```

---

**Exercício P0710** · ★☆☆ · Somar duas matrizes dinâmicas

Duas filiais de uma loja de celulares anotaram as vendas de 3 modelos
(linhas) em 2 meses (colunas). As matrizes foram criadas no heap, com o
tamanho que só se sabe na hora de rodar:


```text
filial A: 14 9 / 6 11 / 20 17
filial B: 8 12 / 3 5 / 15 22
```


Escreva int **somar(int **a, int **b, int l, int c), que devolve uma
matriz NOVA com a soma. Use criar e liberar (do P0708). Mostre a soma e
libere as três matrizes:


```text
Saída esperada:
Total das filiais:
Modelo 1:  22  21
Modelo 2:   9  16
Modelo 3:  35  39
```

**Dicas:**

1. Para preencher A e B a partir dos números, use vetores fixos de 6
   posições e o índice i * c + j.
2. São três matrizes de 3 linhas: três chamadas de liberar(x, 3).
3. Se alguma criação falhar, libere as que já existem (liberar aceita
   NULL).
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 07-memoria-dinamica/lista/P0710.c
```

## ★★☆ Para pensar

**Exercício P0711** · ★★☆ · Juntar a lista com um malloc só

O app da feira monta a lista de compras numa linha só para mandar por
mensagem. Escreva


```text
char *juntar_todas(const char **itens, int n, const char *sep);
```


que devolve uma string nova no heap com os itens separados por sep (sem
sep depois do último), fazendo UM malloc só, do tamanho exato. Teste com a
lista abaixo e os separadores ", " e " | ", e com uma lista vazia (n = 0,
que devolve ""):


```text
const char *feira[5] = {"farinha", "tucumã", "jambu",
                        "cheiro-verde", "pupunha"};
```



```text
Saída esperada:
"farinha, tucumã, jambu, cheiro-verde, pupunha" -> malloc(47)
"farinha | tucumã | jambu | cheiro-verde | pupunha" -> malloc(51)
"" -> malloc(1)
```

**Dicas:**

1. Primeiro calcule o tamanho: soma dos strlen dos itens + (n - 1) vezes
   strlen(sep) + 1. Com n = 0, o tamanho é só 1 (o '\0').
2. Comece com s[0] = '\0' e use strcat. (Para listas grandes, o strcat
   fica lento porque procura o fim a cada chamada; guardar um ponteiro
   para o fim resolve.)
3. Os bytes do "tucumã" são 7: o ã ocupa 2 em UTF-8, e o strlen conta
   bytes.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 07-memoria-dinamica/lista/P0711.c
```

---

**Exercício P0712** · ★★☆ · Turmas de tamanhos diferentes

O cursinho tem três turmas, cada uma com um número diferente de alunos:


```text
turma A: 7.5 8.0 6.0
turma B: 9.0 5.5 7.0 8.5 6.5
turma C: 4.0 10.0
```


Em vez de uma matriz retangular (que desperdiça casas), monte no heap um
vetor de 3 ponteiros, em que a linha i tem EXATAMENTE tam[i] notas:
double **notas e int tam[3] = {3, 5, 2}. Calcule a média de cada turma, a
média geral (de todos os alunos) e mostre quantos bytes de notas foram
alocados contra os de uma matriz 3x5:


```text
Saída esperada:
Turma A (3 alunos): média 7.17
Turma B (5 alunos): média 7.30
Turma C (2 alunos): média 7.00
Média geral: 7.20
Bytes das notas: 80 (matriz 3x5 usaria 120)
```

**Dicas:**

1. notas = malloc(3 * sizeof *notas); notas[i] = malloc(tam[i] * sizeof
   *notas[i]);
2. A média geral NÃO é a média das três médias: some todas as notas e
   divida pelo total de alunos (10).
3. Bytes: (3 + 5 + 2) * sizeof(double) contra 3 * 5 * sizeof(double).
4. Libere cada linha e depois o vetor de ponteiros.
5. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 07-memoria-dinamica/lista/P0712.c
```

---

**Exercício P0713** · ★★☆ · Ler uma linha de qualquer tamanho

O fgets precisa de um vetor de tamanho fixo. Escreva char *ler_linha(void),
que lê uma linha inteira do teclado, de QUALQUER tamanho, com getchar: o
buffer começa com capacidade 8 e dobra com realloc sempre que enche. O
'\n' não entra. Devolve a linha no heap (quem chama faz o free), ou NULL se
a entrada já tiver acabado. Para mostrar o crescimento, a função imprime
uma linha a cada realloc. No main, leia uma linha e mostre o tamanho:


```text
Exemplo de execução:
Rua Ramos Ferreira, 1200, Centro, Manaus
(cresceu para 16)
(cresceu para 32)
(cresceu para 64)
Lido: "Rua Ramos Ferreira, 1200, Centro, Manaus" (40 caracteres)
```



```text
(a primeira linha é a que você digita)
```

**Dicas:**

1. int c (não char!): o getchar devolve EOF, que não cabe num char.
2. Laço: while ((c = getchar()) != EOF && c != '\n'). Antes de guardar,
   se n + 1 == cap (falta espaço para o caractere e o '\0'), dobre.
3. Se o primeiro getchar já der EOF, libere o buffer e devolva NULL.
4. Teste: printf 'Rua Ramos Ferreira, 1200, Centro, Manaus\n' | ./rodar ...
5. Resposta esperada: a execução acima.

```bash
~/LPEDC/rodar 07-memoria-dinamica/lista/P0713.c
```

---

**Exercício P0714** · ★★☆ · Inserir em ordem num vetor que cresce

A loja guarda os preços dos produtos em ordem crescente num vetor dinâmico
que começa com capacidade 2 e dobra quando enche. Escreva


```text
bool inserir(int **v, int *n, int *cap, int valor);
```


que garante espaço (com realloc, dentro da função) e encaixa o valor no
lugar certo, empurrando os maiores. Insira os preços abaixo, um por vez,
mostrando a capacidade sempre que ela mudar, e mostre o vetor no fim:


```text
int novos[7] = {45, 12, 89, 30, 12, 70, 5};
```



```text
Saída esperada:
(capacidade 2)
(capacidade 4)
(capacidade 8)
Preços (7 de 8): 5 12 12 30 45 70 89
```

**Dicas:**

1. A função muda o PONTEIRO do main quando faz realloc, por isso recebe
   int **v: o realloc é feito em *v, e o novo endereço volta para lá.
2. Dentro: int *p = *v; e o mesmo deslocamento do P0514 (comece do fim,
   empurre os maiores, guarde em i + 1).
3. Comece no main com int *v = NULL, n = 0, cap = 0: realloc(NULL, x) é o
   mesmo que malloc(x). A primeira capacidade é 2; depois, dobra.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 07-memoria-dinamica/lista/P0714.c
```

---

**Exercício P0715** · ★★☆ · Conserte o diário de bordo

O diário de bordo de um barco de linha guarda o nome do barco numa cópia
no heap e as paradas num vetor que cresce. O programa tem TRÊS erros de
propósito. Dois o AddressSanitizer acusa (um de cada vez); o terceiro não
aparece nos testes, porque só dá problema no dia em que faltar memória.
Conserte os três. O programa deve mostrar:


```text
Saída esperada:
Barco: Comandante Paiva
Paradas (h): 0 6 14 20 31
Viagem total: 31 horas
```

**Dicas:**

1. Uma cópia de string precisa de strlen + 1 bytes: o '\0' também ocupa.
2. O realloc recebe BYTES, não elementos: cap * sizeof *paradas.
3. Se o realloc falhar, ele devolve NULL e o bloco antigo continua lá.
   Com v = realloc(v, ...), você perde o único endereço dele (vazamento).
   Receba o retorno num ponteiro novo e só depois troque.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 07-memoria-dinamica/lista/P0715.c
```

---

**Exercício P0716** · ★★☆ · Recortar a imagem

Uma imagem em preto e branco está num vetor de strings, uma por linha
('#' é pixel aceso):


```text
const char *img[6] = {"..........",
                      "..####....",
                      ".#....#...",
                      ".#.##.#...",
                      "..####....",
                      ".........."};
```


Escreva char **recortar(const char **img, int l0, int c0, int alt,
int larg), que devolve uma imagem NOVA no heap com alt linhas, cada uma uma
string de larg caracteres (+ '\0'), copiada a partir da linha l0, coluna
c0. Escreva também void liberar(char **m, int alt). Recorte o desenho
(linhas 1 a 4, colunas 1 a 6) e, do recorte, só o miolo 2x4 (linhas 1 e 2,
colunas 1 a 4 do recorte):


```text
Saída esperada:
Recorte 4x6:
  .####.
  #....#
  #.##.#
  .####.
Miolo 2x4:
  ....
  .##.
```

**Dicas:**

1. m = malloc(alt * sizeof *m); m[i] = malloc(larg + 1); e copie
   img[l0 + i][c0 + j] para m[i][j]. Feche cada linha com m[i][larg] = '\0'.
2. Para recortar o recorte, passe (const char **) recorte: as linhas dele
   também são strings.
3. Cada recorte é liberado com o seu número de linhas.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 07-memoria-dinamica/lista/P0716.c
```

---

**Exercício P0717** · ★★☆ · A média móvel do sensor

Um sensor de temperatura de uma câmara fria manda uma leitura por minuto, e
o painel mostra a média das K últimas. Guarde as últimas K leituras num
bloco de K double alocado com malloc, usado em roda (buffer circular): a
leitura nova entra na posição pos, que avança e volta a 0 depois da
última. Com K = 4 e as leituras abaixo, mostre, a cada minuto, a média do
que já está guardado (no começo, menos de K):


```text
double leituras[9] = {4.0, 4.5, 5.0, 6.5, 8.0, 7.5, 5.0, 4.0, 3.5};
```



```text
Saída esperada:
Min 1: leitura 4.0, média das últimas 1 = 4.00
Min 2: leitura 4.5, média das últimas 2 = 4.25
Min 3: leitura 5.0, média das últimas 3 = 4.50
Min 4: leitura 6.5, média das últimas 4 = 5.00
Min 5: leitura 8.0, média das últimas 4 = 6.00
Min 6: leitura 7.5, média das últimas 4 = 6.75
Min 7: leitura 5.0, média das últimas 4 = 6.75
Min 8: leitura 4.0, média das últimas 4 = 6.12
Min 9: leitura 3.5, média das últimas 4 = 5.00
```

**Dicas:**

1. Guarde: double *janela, int pos (onde entra a próxima), int usados
   (quantas posições já têm leitura, até K) e double soma.
2. Ao entrar uma leitura com a janela cheia, tire da soma o valor que vai
   ser sobrescrito (janela[pos]) antes de escrever o novo.
3. pos = (pos + 1) % K faz a volta.
4. A média é soma / usados: sem somar a janela inteira a cada minuto.
5. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 07-memoria-dinamica/lista/P0717.c
```

---

**Exercício P0718** · ★★☆ · Cópia rasa e cópia profunda

A agenda da semana de um consultório é uma matriz dinâmica 2x3 (linhas:
manhã e tarde; colunas: seg, ter, qua) com o número de consultas. Faça
DUAS cópias dela:
- rasa: um vetor novo de 2 ponteiros que recebe os MESMOS endereços das

```text
linhas (m_rasa[i] = m[i]);
```

- profunda: linhas novas, com os valores copiados.

Depois mude m[0][1] (terça de manhã) de 4 para 9 e mostre as três. Mostre
também se a linha 0 de cada cópia mora no mesmo endereço que a de m.
Cuidado na hora de liberar: as linhas da rasa são as de m.


```text
Saída esperada:
Original: manhã 3 9 2 | tarde 5 1 6
Rasa:     manhã 3 9 2 | tarde 5 1 6
Profunda: manhã 3 4 2 | tarde 5 1 6
Linha 0 da rasa é a de m? sim
Linha 0 da profunda é a de m? não
```

**Dicas:**

1. Na rasa, só o vetor de ponteiros é novo: um malloc de 2 ponteiros e
   um for com m_rasa[i] = m[i].
2. Na profunda, um malloc por linha e um for copiando os valores.
3. Liberar: as linhas de m e o vetor de m; o vetor da rasa (só ele!); as
   linhas e o vetor da profunda. Liberar as linhas da rasa seria free
   duplo.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 07-memoria-dinamica/lista/P0718.c
```

---

**Exercício P0719** · ★★☆ · União e interseção do tamanho exato

Dois grupos de WhatsApp de um condomínio têm os números dos apartamentos de
quem participa, em ordem crescente:


```text
int a[6] = {101, 103, 202, 204, 301, 402};
int b[5] = {103, 104, 204, 302, 402};
```


Escreva int *uniao(const int *a, int na, const int *b, int nb, int *n) e
int *intersecao(...) com a mesma assinatura. Cada uma reserva o pior caso
(na + nb para a união; o menor dos dois para a interseção), preenche
andando nos dois vetores ao mesmo tempo e, no fim, ENCOLHE o bloco com
realloc para o tamanho exato. Mostre os resultados e o tamanho de cada um:


```text
Saída esperada:
Nos dois grupos ou em um (8): 101 103 104 202 204 301 302 402
Nos dois grupos (3): 103 204 402
```

**Dicas:**

1. Dois índices, i em a e j em b. Na união: se a[i] < b[j], pega a[i] e
   avança i; se b[j] < a[i], pega b[j]; se forem iguais, pega um só e
   avança os dois. No fim, copia o que sobrou de cada lado.
2. Na interseção, só os iguais entram.
3. Ao encolher, um realloc para 0 bytes pode devolver NULL: se *n for 0,
   devolva o bloco como está. Se o realloc falhar, o bloco grande ainda
   serve.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 07-memoria-dinamica/lista/P0719.c
```

---

**Exercício P0720** · ★★☆ · A borda e o miolo do terreno

Um terreno foi dividido num quadriculado, e cada casa tem a altura do solo
em centímetros. Leia do teclado o número de linhas e de colunas e depois as
alturas, linha por linha. Guarde numa matriz dinâmica (vetor de ponteiros)
e mostre a soma das casas da BORDA (primeira e última linha, primeira e
última coluna, sem contar canto duas vezes) e a do MIOLO (o resto):


```text
Exemplo de execução:
Linhas e colunas: 3 4
Alturas:
5 2 7 1
3 9 8 4
6 0 2 5
Borda: 35
Miolo: 17
```


(as alturas são digitadas; o programa mostra só as outras linhas)

**Dicas:**

1. Uma casa (i, j) é da borda se i == 0, i == l - 1, j == 0 ou j == c - 1.
   Um if só, com ||: assim o canto não conta duas vezes.
2. Confira o retorno de cada scanf; se a leitura falhar, libere o que já
   alocou antes de sair.
3. Com l ou c menor que 3 não há miolo: o programa mostra Miolo: 0.
4. Teste: printf '3 4\n5 2 7 1\n3 9 8 4\n6 0 2 5\n' | ./rodar ...
5. Resposta esperada: Borda 35 e Miolo 17.

```bash
~/LPEDC/rodar 07-memoria-dinamica/lista/P0720.c
```

## ★★★ Desafio

**Exercício P0721** · ★★★ · Um vetor que cresce para qualquer tipo

Escreva um vetor dinâmico genérico, que serve para int, double ou qualquer
outro tipo. Sem struct (só no módulo 08), o estado fica em três variáveis
do main (void *v, size_t n, size_t cap), passadas por endereço:


```text
bool empurrar(void **v, size_t *n, size_t *cap, size_t tam, const void *item);
```


A função dobra a capacidade quando enche (começando em 1), copia os tam
bytes de item para o fim com memcpy e devolve false se faltar memória.
Use-a para guardar os gols por rodada de um time (int) e as médias de
público (double):


```text
int gols[7] = {2, 0, 1, 3, 1, 1, 4};
double publico[3] = {18450.5, 22010.0, 9875.25};
```


Mostre cada vetor, n e cap, e libere os dois:


```text
Saída esperada:
Gols (n = 7, cap = 8): 2 0 1 3 1 1 4
Público (n = 3, cap = 4): 18450.50 22010.00 9875.25
```

**Dicas:**

1. O fim do vetor, em bytes: (unsigned char *) *v + *n * tam.
2. Para crescer: void *novo = realloc(*v, nova_cap * tam); e, se deu
   certo, *v = novo; *cap = nova_cap. Começando com v = NULL e cap = 0,
   o primeiro realloc funciona como malloc.
3. memcpy(destino, item, tam) copia os bytes, seja qual for o tipo.
4. Para ler de volta, converta: const int *g = v_gols; g[i].
5. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 07-memoria-dinamica/lista/P0721.c
```

---

**Exercício P0722** · ★★★ · Somar duas matrizes esparsas

Duas fiscalizações anotaram as multas por quarteirão de um bairro (grade de
100 x 100), e quase todos os quarteirões têm zero. Cada matriz é guardada
como triplas (linha, coluna, valor) em ordem de linha e coluna, num vetor
de int no heap (3 int por tripla):


```text
int a[] = {0, 4, 2,   3, 7, 1,   3, 9, 5,   42, 0, 3};   // 4 triplas
int b[] = {3, 7, 4,   10, 10, 1,   42, 0, 2,   99, 99, 6}; // 4 triplas
```


Escreva int *somar(const int *a, int na, const int *b, int nb, int *n),
que devolve a soma também em triplas ordenadas, sem montar a grade de
10.000 casas: ande nas duas listas ao mesmo tempo (como na união do
P0719), somando os valores quando a posição for a mesma. O resultado começa
com capacidade 2 triplas e dobra com realloc. Mostre as triplas e quantos
bytes a soma ocupa contra a grade cheia:


```text
Saída esperada:
Soma (6 triplas): (0,4,2) (3,7,5) (3,9,5) (10,10,1) (42,0,5) (99,99,6)
Esparsa: 72 bytes; grade cheia: 40000 bytes
```

**Dicas:**

1. Compare posições pela chave linha * 100 + coluna: quem tem a chave
   menor entra primeiro.
2. Escreva bool anexar(int **v, int *n, int *cap, int l, int c, int x),
   que cresce o vetor e acrescenta uma tripla em (*v)[3 * *n] em diante.
3. Se a soma de uma posição der 0, ela não entra (aqui não acontece, mas
   a regra da matriz esparsa é guardar só o que não é zero).
4. Bytes: 3 * n * sizeof(int) contra 100 * 100 * sizeof(int).
5. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 07-memoria-dinamica/lista/P0722.c
```

---

**Exercício P0723** · ★★★ · Quebrar o texto em linhas

O visor da máquina de cartão tem 16 colunas. Escreva


```text
char **quebrar(const char *texto, int largura, int *n_linhas);
```


que divide o texto em linhas de no máximo largura caracteres, quebrando
nos espaços (uma palavra nunca é cortada, a não ser que sozinha passe da
largura: aí ela é partida). Cada linha é uma string nova no heap, sem
espaço no começo nem no fim, e o vetor de linhas cresce com realloc.
Mostre as linhas entre barras, para ver o tamanho, e libere tudo:


```text
const char *msg = "Pagamento aprovado no credito em 3x sem juros. "
                  "Obrigado pela preferencia, volte sempre!";
```



```text
Saída esperada:
|Pagamento       |  9
|aprovado no     | 11
|credito em 3x   | 13
|sem juros.      | 10
|Obrigado pela   | 13
|preferencia,    | 12
|volte sempre!   | 13
7 linhas
```

**Dicas:**

1. Ande com um ponteiro p. Pule espaços. A partir de p, ache o fim da
   linha: avance palavra por palavra enquanto couber (o tamanho conta os
   espaços entre as palavras).
2. Se nem a primeira palavra cabe, corte em largura caracteres.
3. Para cada linha: malloc(tam + 1), memcpy e o '\0'. Para o vetor:
   realloc a cada linha nova (ou dobrando, se preferir).
4. Para liberar: cada linha e, por fim, o vetor.
5. Resposta esperada: a saída acima (7 linhas).

```bash
~/LPEDC/rodar 07-memoria-dinamica/lista/P0723.c
```

---

**Exercício P0724** · ★★★ · Multiplicar números que não cabem em nenhum tipo

Escreva char *multiplicar(const char *a, const char *b), que recebe dois
números naturais como strings de dígitos, de qualquer tamanho, e devolve o
produto numa string nova no heap, sem zeros à esquerda. Faça como na conta
à mão: o dígito i de a (contado da direita) vezes o dígito j de b vai para
a casa i + j de um vetor de int alocado com calloc, e depois se acertam os
"vai um". Teste:


```text
"12" x "34"
"99999999999" x "99999999999"
"123456789012345678901234567890" x "987654321"
"2026" x "0"
```



```text
Saída esperada:
12 x 34 =
  408 (tamanho 3)
99999999999 x 99999999999 =
  9999999999800000000001 (tamanho 22)
123456789012345678901234567890 x 987654321 =
  121932631124828532112482853211126352690 (tamanho 39)
2026 x 0 =
  0 (tamanho 1)
```

**Dicas:**

1. O produto de um número de na dígitos por um de nb tem no máximo
   na + nb dígitos: int *casas = calloc(na + nb, sizeof *casas);
2. Com os índices da direita: da = a[na - 1 - i] - '0', db = b[nb - 1 -
   j] - '0', e casas[i + j] += da * db.
3. Depois, de 0 a na + nb - 2: casas[k + 1] += casas[k] / 10;
   casas[k] %= 10.
4. Ache o dígito mais alto que não é zero (se todos forem zero, a resposta
   é "0"), aloque a string e escreva do mais alto para o mais baixo.
5. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 07-memoria-dinamica/lista/P0724.c
```

---

**Exercício P0725** · ★★★ · Conserte a lista de convidados

O programa da festa junina guarda os nomes dos convidados em cópias no
heap e um vetor de ponteiros, também no heap. Ele tem TRÊS erros de
propósito. O gcc desconfia de dois (leia os warnings) e o AddressSanitizer
acusa o terceiro assim que o programa roda. Conserte os três sem mudar a
ideia
do programa. Ele deve mostrar:


```text
Saída esperada:
1. Zefinha
2. Tião
3. Mariazinha
4. Chico Bento
4 convidados
```

**Dicas:**

1. O vetor guarda char *, então cada casa tem sizeof(char *) bytes (8),
   e não sizeof(char) (1). Use n * sizeof *lista.
2. Uma função não pode devolver o endereço de um vetor local: ele some no
   return. A cópia tem que ir para o heap: malloc(strlen(s) + 1).
3. Liberar o vetor e DEPOIS ler lista[i] para liberar cada nome é ler
   memória já devolvida. A ordem é: cada nome, e só então o vetor.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 07-memoria-dinamica/lista/P0725.c
```

---

**Exercício P0726** · ★★★ · Multiplicar polinômios

Um polinômio de grau g pode ser guardado como g + 1 coeficientes, do termo
independente para o de maior grau: 3 - 2x + x² vira {3, -2, 1}. Escreva:


```text
int *mult_poli(const int *p, int gp, const int *q, int gq, int *gr);
long long valor(const int *p, int g, int x);
void mostrar(const int *p, int g);
```


mult_poli devolve um vetor novo (calloc) com o produto, de grau gp + gq:
o coeficiente k soma p[i] * q[j] para todo i + j = k. valor calcula p(x)
pelo método de Horner (de dentro para fora: ((a3 x + a2) x + a1) x + a0).
Com p = 3 - 2x + x² e q = 1 + 4x, mostre p, q, o produto, e confira que
r(2) = p(2) * q(2). Depois eleve (1 + x) à quinta potência multiplicando
cinco vezes:


```text
Saída esperada:
p(x) = 3 - 2x + x^2
q(x) = 1 + 4x
r(x) = 3 + 10x - 7x^2 + 4x^3
r(2) = 27; p(2) * q(2) = 27
(1 + x)^5 = 1 + 5x + 10x^2 + 10x^3 + 5x^4 + x^5
```

**Dicas:**

1. O vetor do produto tem gp + gq + 1 casas, todas começando em 0 (por
   isso calloc): r[i + j] += p[i] * q[j].
2. Horner: r = 0; para i de g até 0: r = r * x + p[i].
3. Para a potência, guarde o resultado atual, multiplique, libere o
   antigo e fique com o novo. Comece com o polinômio 1 (grau 0).
4. No mostrar, pule coeficientes zero e mostre "x^k" (x^1 como x).
5. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 07-memoria-dinamica/lista/P0726.c
```

---

**Exercício P0727** · ★★★ · O determinante por Laplace

O determinante de uma matriz n x n pode ser calculado pela expansão de
Laplace na primeira linha: det(M) = soma, para j de 0 a n - 1, de
(-1)^j * M[0][j] * det(menor(M, j)), em que menor(M, j) é a matriz
(n - 1) x (n - 1) que sobra tirando a linha 0 e a coluna j. Para n = 1, o
determinante é o próprio número.

Escreva a função recursiva double det(double **m, int n), que monta cada
menor no heap (matriz dinâmica), calcula e libera. Conte num contador
global quantas matrizes menores foram alocadas. Calcule o determinante das
matrizes abaixo (uma 3x3 e uma 4x4) e da identidade 4x4:


```text
A = | 2 -1  0 |      B = | 1 0 2 -1 |
    | 1  3  2 |          | 3 0 0  5 |
    | 0  1  4 |          | 2 1 4 -3 |
                         | 1 0 5  0 |
```



```text
Saída esperada:
det A (3x3) = 24, com 6 menores alocados
det B (4x4) = 30, com 15 menores alocados
det I (4x4) = 1, com 3 menores alocados
```

**Dicas:**

1. Escreva criar(n) e liberar(m, n) para matrizes double ** quadradas.
2. Para montar o menor sem a coluna j: para cada linha i de 1 a n - 1,
   copie as colunas k != j, com um índice de destino que só anda quando
   copia.
3. Um termo com M[0][j] == 0 não precisa do menor: pule (e o contador
   mostra a economia).
4. O custo cresce como n!: para 4x4, até 4 + 4 * 3 = 16 menores; para
   10x10, mais de 6 milhões. Por isso, na prática, usa-se eliminação de
   Gauss.
5. Resposta esperada: a saída acima (det A = 24, det B = 30, det I = 1).

```bash
~/LPEDC/rodar 07-memoria-dinamica/lista/P0727.c
```

---

**Exercício P0728** · ★★★ · As palavras mais usadas do discurso

Conte as palavras de um discurso de formatura e mostre as 3 mais usadas.
Não se sabe quantas palavras distintas virão, então guarde-as em dois
vetores dinâmicos que crescem JUNTOS (dobrando): char **palavras (cada uma
uma cópia no heap, em minúsculas) e int *cont. Palavras com menos de 3
letras não contam ("de", "a", "o"...). No empate, vale a que apareceu
primeiro. Mostre também quantas distintas foram guardadas e a capacidade
final:


```text
const char *discurso = "Hoje a turma celebra. A turma estudou, a turma "
    "errou, a turma aprendeu. Hoje celebramos o estudo e o futuro; "
    "o futuro da turma comeca hoje!";
```



```text
Saída esperada:
10 palavras distintas (capacidade 16)
1º turma (5)
2º hoje (3)
3º futuro (2)
```

**Dicas:**

1. Monte cada palavra num buffer local char p[32] (isalpha e tolower,
   como no P0524); ao fechar, se tiver 3 letras ou mais, processe.
2. Processar: procure com strcmp; achou, cont[k]++; não achou, garanta
   espaço nos DOIS vetores (dois realloc com ponteiros novos, e só troque
   depois que os dois derem certo) e guarde uma cópia com malloc.
3. Para as 3 maiores, faça 3 passadas: em cada uma, pegue o maior cont
   que ainda não foi escolhido (marque num vetor bool, ou use um calloc).
4. Libere cada palavra, o vetor de palavras e o de contagens.
5. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 07-memoria-dinamica/lista/P0728.c
```

---

**Exercício P0729** · ★★★ · Quantas ilhas tem o mapa do rio

Num mapa de satélite do Anavilhanas, '#' é terra e '.' é água. Uma ILHA é
um grupo de '#' ligados na horizontal ou na vertical (diagonal não liga).
O mapa vem como um vetor de strings:


```text
const char *mapa[6] = {"##....#...",
                       "##...###..",
                       "......#...",
                       "..#.......",
                       ".###..##.#",
                       "..#...##.#"};
```


Conte as ilhas e o tamanho de cada uma. Use uma matriz dinâmica de bool
visitado (alocada com calloc, já tudo false) e uma função recursiva
int inundar(const char **mapa, bool **vis, int l, int c, int i, int j),
que marca a casa (i, j) e as vizinhas de terra ainda não visitadas, e
devolve quantas casas marcou:


```text
Saída esperada:
Ilha 1: começa em (0, 0), 4 casas
Ilha 2: começa em (0, 6), 5 casas
Ilha 3: começa em (3, 2), 5 casas
Ilha 4: começa em (4, 6), 4 casas
Ilha 5: começa em (4, 9), 2 casas
Total: 5 ilhas
```

**Dicas:**

1. Para cada casa de terra não visitada, chame inundar: é uma ilha nova.
2. Em inundar, o caso base é sair do mapa, achar água ou achar casa já
   visitada: return 0. Senão, marque e devolva 1 + inundar das 4 vizinhas.
3. vis = malloc(l * sizeof *vis); vis[i] = calloc(c, sizeof *vis[i]);
4. A recursão usa a pilha: num mapa enorme, todo de terra, ela pode
   estourar. Para mapas grandes, troca-se a recursão por uma pilha ou
   fila no heap (módulos 12 e 16).
5. Resposta esperada: a saída acima (5 ilhas).

```bash
~/LPEDC/rodar 07-memoria-dinamica/lista/P0729.c
```

---

**Exercício P0730** · ★★★ · O editor de linhas

Escreva um editor de texto mínimo: o documento é um vetor dinâmico de
linhas (char **, cada linha uma cópia no heap) com n e cap. Escreva:


```text
bool inserir(char ***doc, int *n, int *cap, int pos, const char *texto);
void apagar(char **doc, int *n, int pos);
```


inserir abre espaço na posição pos (0 <= pos <= n) empurrando as linhas
seguintes uma casa para frente com memmove; apagar libera a linha pos e
puxa as seguintes com memmove. O vetor dobra quando enche (começando em
2). Execute os comandos abaixo e mostre o documento no fim:


```text
inserir 0 "Ata da reunião do condomínio"
inserir 1 "Pauta: portão da garagem"
inserir 2 "Encerrada às 21h"
inserir 2 "Aprovado o conserto por R$ 850"
inserir 1 "Presentes: 14 moradores"
apagar 3
inserir 3 "Aprovado o conserto por R$ 790"
```



```text
Saída esperada:
(capacidade 2)
(capacidade 4)
(capacidade 8)
1 | Ata da reunião do condomínio
2 | Presentes: 14 moradores
3 | Pauta: portão da garagem
4 | Aprovado o conserto por R$ 790
5 | Encerrada às 21h
5 linhas, capacidade 8
```

**Dicas:**

1. *doc é o vetor de linhas do main; como o realloc pode mudá-lo de
   lugar, inserir recebe char *** (o endereço do char ** do main).
2. memmove(&v[pos + 1], &v[pos], (*n - pos) * sizeof *v) empurra os
   PONTEIROS (as linhas não saem do lugar). memmove, e não memcpy, porque
   as duas áreas se sobrepõem.
3. Em apagar: free(v[pos]) antes de puxar, senão a linha vaza.
4. No fim, libere cada linha e o vetor.
5. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 07-memoria-dinamica/lista/P0730.c
```
