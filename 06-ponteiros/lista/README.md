<!-- Gerado por _gerador a partir dos arquivos P????.c desta pasta. -->

# Lista prática · Módulo 06 · Ponteiros

30 exercícios de codificar que treinam o módulo inteiro, misturando os assuntos, no ritmo da prova do PPGI (veja [PPGI.md](../../PPGI.md)). Cada arquivo `P????.c` desta pasta é um exercício: a resposta vai dentro dele, embaixo de `// Escreva sua resposta abaixo:`. Uma resolução de cada um está em `_respostas/06-ponteiros/lista/`. Só olhe depois de tentar.

[Voltar ao módulo](../README.md)

## ★☆☆ Aquecimento

**Exercício P0601** · ★☆☆ · O placar pelo ponteiro

O narrador anotou os gols de Remo x Paysandu numa string, na ordem em que
saíram: 'R' é gol do Remo e 'P' é gol do Paysandu.


```text
char gols[] = "RPPRRPR";
```


Declare int remo = 0, paysandu = 0; e, para cada letra, faça um ponteiro
int *alvo apontar para a variável do time que marcou e some o gol com
(*alvo)++. A soma é feita SEMPRE pelo ponteiro, numa linha só. Mostre o
placar parcial a cada gol:


```text
Saída esperada:
Gol 1 (Remo): Remo 1 x 0 Paysandu
Gol 2 (Paysandu): Remo 1 x 1 Paysandu
Gol 3 (Paysandu): Remo 1 x 2 Paysandu
Gol 4 (Remo): Remo 2 x 2 Paysandu
Gol 5 (Remo): Remo 3 x 2 Paysandu
Gol 6 (Paysandu): Remo 3 x 3 Paysandu
Gol 7 (Remo): Remo 4 x 3 Paysandu
```

**Dicas:**

1. alvo = (gols[i] == 'R') ? &remo : &paysandu; escolhe o endereço.
2. Os parênteses em (*alvo)++ importam: *alvo++ anda o PONTEIRO e não mexe
   no placar (o ++ vale para alvo, e o * lê o valor antigo).
3. Resposta esperada: a saída acima (4 x 3 para o Remo).

```bash
~/LPEDC/rodar 06-ponteiros/lista/P0601.c
```

---

**Exercício P0602** · ★☆☆ · As leituras até o -1

O hidrômetro manda o consumo diário (em litros) e o -1 marca o fim das
leituras:


```text
int leituras[] = {312, 280, 455, 301, 298, -1};
```


Sem usar colchetes depois da declaração, ande com um ponteiro p de
leituras até achar o -1, somando o consumo. No fim, use a diferença de
ponteiros p - leituras para saber quantas leituras eram e mostre a média:


```text
Saída esperada:
Leituras: 5
Total: 1646 litros
Média: 329.20 litros por dia
```

**Dicas:**

1. int *p = leituras; while (*p != -1) { soma += *p; p++; }
2. Quando o laço termina, p aponta para o -1. A distância p - leituras
   conta ELEMENTOS (não bytes): é a quantidade de leituras.
3. O tipo da diferença de ponteiros é ptrdiff_t; para mostrar, converta
   para int e use %d (ou use %td direto).
4. Resposta esperada: a saída acima (5 leituras, média 329.20 litros).

```bash
~/LPEDC/rodar 06-ponteiros/lista/P0602.c
```

---

**Exercício P0603** · ★☆☆ · Rachando a conta do bar

Escreva


```text
bool rachar(double total, int pessoas, double *por_pessoa, double *gorjeta)
```


que calcula os 10% do garçom (em *gorjeta) e quanto cada pessoa paga com a
gorjeta incluída (em *por_pessoa). Se pessoas for menor que 1, a função
devolve false e não mexe em nada. Teste com R$ 186.00 para 4 pessoas,
R$ 95.50 para 3 e R$ 50.00 para 0:


```text
Saída esperada:
R$ 186.00 / 4: gorjeta R$ 18.60, cada um paga R$ 51.15
R$ 95.50 / 3: gorjeta R$ 9.55, cada um paga R$ 35.02
R$ 50.00 / 0: ninguém para pagar
```

**Dicas:**

1. *gorjeta = total * 0.10; *por_pessoa = (total + *gorjeta) / pessoas;
2. No main, declare double cada, gorjeta; e passe &cada e &gorjeta.
3. Teste o retorno antes de usar os valores: se a função devolveu false,
   eles não foram preenchidos.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 06-ponteiros/lista/P0603.c
```

---

**Exercício P0604** · ★☆☆ · A placa no padrão Mercosul

O despachante digitou as placas em minúsculas. Escreva void maiusculas(char
*s), que passa a string para maiúsculas andando com o próprio ponteiro s
até o '\0' (sem índice), e bool padrao_mercosul(const char *p), que confere
o formato LLLNLNN (3 letras, 1 dígito, 1 letra, 2 dígitos). Teste:


```text
char placas[3][8] = {"rio2a18", "abc1234", "qxz9b07"};
```



```text
Saída esperada:
RIO2A18: Mercosul
ABC1234: modelo antigo
QXZ9B07: Mercosul
```

**Dicas:**

1. while (*s != '\0') { *s = toupper((unsigned char) *s); s++; } — dentro
   da função, s é uma CÓPIA do endereço: andar com ela não estraga o
   ponteiro do main.
2. No padrao_mercosul, confira cada posição com isalpha ou isdigit:
   p[0], p[1], p[2] letras; p[3] dígito; p[4] letra; p[5], p[6] dígitos;
   e p[7] tem que ser o '\0'.
3. Não dá para passar um literal ("abc1234") para maiusculas: literal é só
   de leitura. Por isso as placas estão num vetor de char.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 06-ponteiros/lista/P0604.c
```

---

**Exercício P0605** · ★☆☆ · Troca de plantão

O hospital guarda quem está de plantão em dois ponteiros para string:


```text
const char *dia = "Dra. Socorro";
const char *noite = "Dr. Wanderley";
```


Escreva void troca_plantao(const char **a, const char **b), que troca para
onde os dois ponteiros apontam (as strings não mudam de lugar: só os
ponteiros). Mostre a escala antes e depois e, para provar que nenhum texto
foi copiado, mostre o endereço guardado em dia antes e o guardado em noite
depois (são o mesmo):


```text
Saída esperada (os endereços mudam a cada execução):
Antes:  dia = Dra. Socorro, noite = Dr. Wanderley
Depois: dia = Dr. Wanderley, noite = Dra. Socorro
dia antes:    0x55d0c3a01004
noite depois: 0x55d0c3a01004
```

**Dicas:**

1. Para mudar um int do main, a função recebe int *. Para mudar um
   const char * do main, ela recebe const char ** (o endereço do ponteiro).
2. Dentro: const char *aux = *a; *a = *b; *b = aux;
3. Na chamada: troca_plantao(&dia, &noite).
4. Mostre os endereços com %p e um cast para (void *).
5. Resposta esperada: a saída acima, com as duas últimas linhas iguais.

```bash
~/LPEDC/rodar 06-ponteiros/lista/P0605.c
```

---

**Exercício P0606** · ★☆☆ · O pódio do campeonato

Os pontos dos 8 times do campeonato amazonense, fora de ordem:


```text
int pontos[8] = {21, 34, 18, 29, 34, 12, 25, 30};
```


Ordene do MAIOR para o menor com qsort, escrevendo a função de comparação
int decrescente(const void *a, const void *b). Mostre a tabela e o pódio:


```text
Saída esperada:
Tabela: 34 34 30 29 25 21 18 12
1º: 34 pontos
2º: 34 pontos
3º: 30 pontos
```

**Dicas:**

1. O qsort entrega dois const void *; converta: int x = *(const int *) a;
   e o mesmo para b.
2. Para decrescente, devolva negativo quando x deve vir ANTES de y, ou
   seja, quando x > y: return (x < y) - (x > y);
3. Evite return y - x: com números grandes a subtração estoura o int.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 06-ponteiros/lista/P0606.c
```

---

**Exercício P0607** · ★☆☆ · A regra de desconto como parâmetro

A loja tem três promoções, cada uma uma função double regra(double preco):
- black_friday: 30% de desconto;
- cupom10: R$ 10 a menos, mas nunca abaixo de zero;
- leve_mais: 5% de desconto se o preço passar de R$ 100, senão nada.

Escreva double total_com(const double *precos, int n, double
(*regra)(double)),
que soma os preços depois de aplicar a regra recebida em cada um. Para o
carrinho abaixo, mostre o total sem desconto e com cada promoção:


```text
double carrinho[4] = {129.90, 8.50, 45.00, 210.00};
```



```text
Saída esperada:
Sem desconto  R$  393.40
Black Friday  R$  275.38
Cupom R$ 10   R$  354.90
Leve mais     R$  376.40
```

**Dicas:**

1. Para "sem desconto", escreva também double nenhuma(double p) { return p;
   }.
2. Dentro de total_com: soma += regra(precos[i]); — chamar pelo ponteiro é
   igual a chamar pelo nome.
3. Para não repetir o printf, guarde os ponteiros num vetor:
   double (*regras[4])(double) = {nenhuma, black_friday, cupom10, leve_mais};
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 06-ponteiros/lista/P0607.c
```

---

**Exercício P0608** · ★☆☆ · Conserte os ponteiros soltos

O programa da bilheteria tem DOIS erros de propósito, e o gcc avisa dos
dois. Um ponteiro é usado sem apontar para nada, e uma função devolve o
endereço de uma variável que deixa de existir quando ela termina. Rode, leia
os avisos (warning) e conserte sem mudar o que o programa mostra:


```text
Saída esperada:
Público do dia: 229
Sessão mais cheia: 142
```

**Dicas:**

1. Um ponteiro declarado e não inicializado guarda lixo: *p = ... escreve
   num endereço qualquer. Faça p apontar para uma variável de verdade.
2. A variável local de uma função mora no frame dela, que some no return.
   Devolva o VALOR (int), não o endereço.
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 06-ponteiros/lista/P0608.c
```

---

**Exercício P0609** · ★☆☆ · Uma função que mostra qualquer coisa

O painel do posto mostra dados de tipos diferentes. Escreva


```text
void mostrar(const char *rotulo, const void *p, char tipo)
```


em que tipo diz o que existe no endereço p: 'i' (int), 'd' (double),
'c' (char) ou 's' (string). A função converte p para o tipo certo antes de
ler. No main, mostre as quatro variáveis abaixo com ela:


```text
int bomba = 3;
double litro = 6.29;
char combustivel = 'G';
char frentista[] = "Rosinete";
```



```text
Saída esperada:
Bomba:       3
Litro: R$    6.29
Tipo:        G
Frentista:   Rosinete
```

**Dicas:**

1. Um void * não pode ser lido direto: *p não compila. Converta antes:
   *(const int *) p, *(const double *) p, *(const char *) p.
2. Para a string, o próprio p já é o endereço do primeiro char:
   printf("%s", (const char *) p).
3. Use um switch no tipo.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 06-ponteiros/lista/P0609.c
```

---

**Exercício P0610** · ★☆☆ · O maior da matriz por um ponteiro só

A matriz guarda as vendas de 3 vendedores (linhas) em 4 semanas (colunas):


```text
int v[3][4] = {{12, 18, 9, 14}, {20, 7, 16, 11}, {13, 15, 22, 8}};
```


Na memória, as 12 casas ficam uma depois da outra, linha por linha. Use um
único ponteiro int *p = &v[0][0] e ande pelas 12 casas com p++ (sem
v[i][j]) para achar o maior valor. Depois, com a POSIÇÃO dele no bloco
(k = p_maior - &v[0][0]), descubra a linha (k / 4) e a coluna (k % 4):


```text
Saída esperada:
Maior venda: 22
Posição no bloco: 10
Vendedor (linha): 2
Semana (coluna): 2
```

**Dicas:**

1. int *inicio = &v[0][0]; int *fim = inicio + 12; e um for de p = inicio
   até p < fim.
2. Guarde o ponteiro do maior (int *p_maior), não só o valor.
3. A casa (i, j) fica em i * 4 + j a partir do início: é o mesmo cálculo
   ao contrário.
4. Resposta esperada: a saída acima (22 na posição 10: linha 2, coluna 2).

```bash
~/LPEDC/rodar 06-ponteiros/lista/P0610.c
```

## ★★☆ Para pensar

**Exercício P0611** · ★★☆ · Lado par, lado ímpar

O carteiro recebeu as cartas de uma rua fora de ordem e quer separar o lado
par do lado ímpar antes de sair:


```text
int casas[10] = {15, 8, 23, 42, 7, 10, 31, 6, 19, 4};
```


Escreva int separar(int *v, int n), que deixa os pares no começo e os
ímpares no fim, NO PRÓPRIO VETOR, e devolve quantos pares há. Use dois
ponteiros: esq começa no
primeiro elemento e dir no último. Enquanto esq < dir: avance esq enquanto
ele for par, recue dir enquanto ele for ímpar e, se os dois ainda não se
cruzaram, troque *esq com *dir. Mostre o vetor e onde começa o lado ímpar:


```text
Saída esperada:
4 8 6 42 10 7 31 23 19 15
Pares: 5 casas; o lado ímpar começa na posição 5
```

**Dicas:**

1. int *esq = v; int *dir = v + n - 1;
2. Os laços internos também precisam do esq < dir, senão eles passam do
   fim do vetor quando todos são pares (ou todos ímpares).
3. Escreva void troca(int *a, int *b) e chame troca(esq, dir): os dois já
   são endereços.
4. Quando o laço termina, esq == dir. Se *esq for par, ele também é do lado
   par: os pares são (esq - v) + 1; senão, são esq - v.
5. A ordem dentro de cada lado muda; isso é normal (é a mesma partição do
   quicksort, no módulo 13).
6. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 06-ponteiros/lista/P0611.c
```

---

**Exercício P0612** · ★★☆ · O qsort numa matriz de char

Os bairros de Manaus estão numa matriz de char (cada linha é uma string de
até 19 letras), não num vetor de ponteiros:


```text
char bairros[6][20] = {"Flores", "Adrianopolis", "Compensa",
                       "Aleixo", "Educandos", "Cachoeirinha"};
```


Ordene com qsort em ordem alfabética. Cuidado: aqui cada elemento é uma
LINHA de 20 bytes, não um char *. O tamanho do elemento é sizeof
bairros[0], e o que chega na comparação é o endereço do primeiro char da
linha. Mostre também quantos bytes o qsort move a cada troca:


```text
Saída esperada:
1. Adrianopolis
2. Aleixo
3. Cachoeirinha
4. Compensa
5. Educandos
6. Flores
Cada elemento tem 20 bytes
```

**Dicas:**

1. int compara(const void *a, const void *b) { return strcmp((const char *)
   a, (const char *) b); } — o endereço da linha JÁ é o endereço da string.
2. Compare com o vetor de ponteiros (const char *v[]): lá o elemento é um
   ponteiro, e a comparação precisa de *(const char **) a.
3. qsort(bairros, 6, sizeof bairros[0], compara);
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 06-ponteiros/lista/P0612.c
```

---

**Exercício P0613** · ★★☆ · O filtro do extrato do Pix

O extrato do mês tem estes valores (positivo é entrada, negativo é saída):


```text
int pix[10] = {1500, -89, -230, 45, -12, 3200, -1450, -75, 300, -640};
```


Escreva int filtrar(const int *v, int n, int *saida, bool (*passa)(int)),
que copia para saida, na ordem, só os valores para os quais passa devolve
true, e devolve quantos copiou. Escreva três critérios e mostre o
resultado de cada um com a soma:
- entrada: o valor é positivo;
- saida_grande: é uma saída de mais de R$ 100;
- miudo: o valor, com ou sem sinal, é menor que R$ 100.


```text
Saída esperada:
Entradas: 1500 45 3200 300 (4 itens, soma 5045)
Saídas grandes: -230 -1450 -640 (3 itens, soma -2320)
Miúdos: -89 45 -12 -75 (4 itens, soma -131)
```

**Dicas:**

1. saida_grande(int x) é x < -100; miudo(int x) é abs(x) < 100 (abs está
   no stdlib.h).
2. O vetor saida precisa caber o pior caso: todos passam. int saida[10].
3. Escreva void relatorio(const char *nome, const int *v, int n,
   bool (*passa)(int)) para o main ficar com três linhas.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 06-ponteiros/lista/P0613.c
```

---

**Exercício P0614** · ★★☆ · A extensão do arquivo

O sistema de upload precisa da extensão de cada arquivo. Escreva


```text
const char *extensao(const char *nome);
```


que devolve um ponteiro para o texto DEPOIS do último ponto do nome (dentro
da própria string, sem copiar nada). Se não houver ponto, ou se o único
ponto for o primeiro caractere (arquivo oculto, como ".bashrc"), devolve um
ponteiro para o '\0' do fim (string vazia). Teste:


```text
const char *arquivos[5] = {"relatorio.final.pdf", "foto.JPG", "LEIAME",
                           ".bashrc", "backup.tar.gz"};
```


Mostre cada nome, a extensão entre colchetes e em que posição do nome ela
começa (diferença de ponteiros):


```text
Saída esperada:
relatorio.final.pdf  [pdf] posição 16
foto.JPG             [JPG] posição 5
LEIAME               [] posição 6
.bashrc              [] posição 7
backup.tar.gz        [gz] posição 11
```

**Dicas:**

1. Ande com um ponteiro p do começo até o '\0', guardando em ultimo o
   endereço do último '.' visto (comece com ultimo = NULL).
2. No fim, p aponta para o '\0': é ele que você devolve quando não há
   extensão. Se ultimo for NULL ou igual a nome, return p.
3. Senão, return ultimo + 1 (o caractere logo depois do ponto).
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 06-ponteiros/lista/P0614.c
```

---

**Exercício P0615** · ★★☆ · Troque o prato do cardápio

O cardápio do dia é um vetor de ponteiros para string:


```text
const char *cardapio[5] = {"Tacacá", "Pato no tucupi", "Tambaqui assado",
                           "Vatapá", "Maniçoba"};
```


Escreva const char **achar(const char **itens, int n, const char *prato),
que devolve o ENDEREÇO da gaveta do vetor onde está o prato (ou NULL). Com
esse endereço, o main troca o prato sem saber o índice: *gaveta = "novo".
Escreva também void mostrar(const char **itens, int n). Troque "Vatapá" por
"Caldeirada", tente trocar "Feijoada" e mostre o cardápio:


```text
Saída esperada:
Vatapá trocado por Caldeirada (gaveta 3)
Feijoada não está no cardápio
1. Tacacá
2. Pato no tucupi
3. Tambaqui assado
4. Caldeirada
5. Maniçoba
```

**Dicas:**

1. No achar, compare com strcmp(itens[i], prato) == 0 e devolva &itens[i]
   (ou itens + i, que é a mesma coisa).
2. O retorno é const char **: um ponteiro para uma gaveta que guarda um
   const char *. *gaveta é o ponteiro da gaveta; **gaveta seria a primeira
   letra do prato.
3. Antes de usar o retorno, teste se é NULL.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 06-ponteiros/lista/P0615.c
```

---

**Exercício P0616** · ★★☆ · Ordem alfabética sem ligar para maiúsculas

A lista de convidados foi digitada de qualquer jeito:


```text
const char *convidados[6] = {"bruna", "Ademir", "carlos", "Beatriz",
                             "ana", "Caio"};
```


Com strcmp, as maiúsculas vêm antes de todas as minúsculas ('Z' é 90 e 'a'
é 97). Escreva int compara_sem_caixa(const char *a, const char *b), que
compara letra a letra com tolower, andando com os dois ponteiros, e use-a
numa função de comparação para o qsort. Mostre a lista nas duas ordens:


```text
Saída esperada:
strcmp: Ademir Beatriz Caio ana bruna carlos
sem caixa: Ademir ana Beatriz bruna Caio carlos
```

**Dicas:**

1. Enquanto *a != '\0' e tolower(*a) == tolower(*b), avance os dois. No
   fim, devolva tolower(*a) - tolower(*b) (use unsigned char nos
   tolower).
2. A comparação do qsort recebe o endereço de cada GAVETA (um const char
   **): const char *x = *(const char **) pa;
3. Escreva duas comparações (uma com strcmp e outra com a sua) e ordene uma
   cópia do vetor para cada.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 06-ponteiros/lista/P0616.c
```

---

**Exercício P0617** · ★★☆ · Conserte o reajuste dos preços

A cantina vai subir R$ 1 em todos os preços. O programa abaixo tem DOIS
erros de propósito na parte dos ponteiros. O gcc avisa de um (leia o
warning); o outro, o AddressSanitizer acusa quando roda. Conserte os dois.
O programa deve mostrar:


```text
Saída esperada:
5 8 4 11 7
Total: R$ 35
```

**Dicas:**

1. *p++ é *(p++): lê o valor e anda o ponteiro. Para somar no valor
   apontado, use (*p)++ ou *p += 1.
2. fim = precos + n aponta para a casa DEPOIS da última: ela pode ser
   comparada, mas não lida. O laço precisa de p < fim.
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 06-ponteiros/lista/P0617.c
```

---

**Exercício P0618** · ★★☆ · Ponteiro para uma linha inteira

Numa matriz int m[3][4], o nome m vira um ponteiro para a primeira LINHA:
o tipo é int (*)[4], e m + 1 pula 4 int de uma vez. Com as notas de 3
alunos em 4 provas,


```text
int notas[3][4] = {{7, 8, 6, 9}, {5, 6, 7, 4}, {10, 9, 9, 8}};
```


escreva void medias(int (*linha)[4], int n, double *saida), que anda com
o ponteiro linha (linha++) pelas n linhas e calcula a média de cada uma em
saida[i]. Mostre as médias e, para ver o salto, sizeof *linha e a
distância em bytes entre notas e notas + 1:


```text
Saída esperada:
Aluno 1: 7.50
Aluno 2: 5.50
Aluno 3: 9.00
sizeof *p = 16 bytes
notas + 1 fica 16 bytes depois de notas
```

**Dicas:**

1. Dentro de medias, (*linha)[j] é a nota j da linha atual (os parênteses
   são obrigatórios: *linha[j] seria *(linha[j])).
2. A distância em bytes: (char *) (notas + 1) - (char *) notas.
3. O parâmetro int (*linha)[4] é o mesmo que int linha[][4]: o compilador
   precisa saber o tamanho da linha para dar o salto.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 06-ponteiros/lista/P0618.c
```

---

**Exercício P0619** · ★★☆ · Média e desvio de uma vez

Uma corredora anotou os tempos (em minutos) dos seus treinos de 5 km:


```text
double tempos[6] = {28.5, 27.9, 30.2, 26.8, 29.1, 27.5};
```


Escreva bool estatisticas(const double *v, int n, double *media,
double *desvio), que devolve false se n < 1 e, senão, entrega a média e o
desvio padrão (populacional) pelos ponteiros. Mostre os dois e quais
treinos ficaram abaixo da média:


```text
Saída esperada:
Média: 28.33 min
Desvio: 1.11 min
Abaixo da média: treino 2 (27.9) treino 4 (26.8) treino 6 (27.5)
```

**Dicas:**

1. Desvio padrão = raiz da média dos quadrados das diferenças:
   sqrt(soma de (v[i] - media)² / n). sqrt está no math.h (o rodar já
   liga a biblioteca com -lm).
2. São duas passadas: a primeira acha a média; a segunda usa a média.
3. Atenção: dentro da função, media é um ponteiro. A conta usa *media.
4. Resposta esperada: a saída acima (média 28.33, desvio 1.11).

```bash
~/LPEDC/rodar 06-ponteiros/lista/P0619.c
```

---

**Exercício P0620** · ★★☆ · Três ordens para o mesmo vetor

O sorteio de uma rifa tirou estes números:


```text
int sorteados[8] = {47, 12, 85, 30, 9, 66, 21, 58};
```


Escreva void ordenar_e_mostrar(const char *nome, const int *orig, int n,
int (*cmp)(const void *, const void *)), que copia orig para um vetor
local, ordena a cópia com qsort usando a comparação recebida e mostra o
resultado. Escreva três comparações:
- crescente;
- decrescente;
- pares_primeiro: pares antes dos ímpares; dentro de cada grupo, crescente.


```text
Saída esperada:
Crescente:       9 12 21 30 47 58 66 85
Decrescente:    85 66 58 47 30 21 12  9
Pares primeiro: 12 30 58 66  9 21 47 85
```

**Dicas:**

1. A cópia evita que uma ordenação estrague a próxima: int v[8]; e um for.
2. Em pares_primeiro, calcule o "grupo" de cada um (x % 2: 0 para par e 1
   para ímpar). Grupos diferentes: devolva a diferença dos grupos. Grupos
   iguais: compare os valores.
3. O qsort não sabe nada de pares e ímpares: quem decide a ordem é só a
   comparação que você passa.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 06-ponteiros/lista/P0620.c
```

## ★★★ Desafio

**Exercício P0621** · ★★★ · O ranking do processo seletivo

No resultado de um processo seletivo, cada candidato é uma linha de uma
matriz de int com {inscrição, nota (de 0 a 100), idade}:


```text
int cand[7][3] = {{1043, 82, 29}, {1007, 91, 33}, {1120, 82, 41},
                  {1088, 75, 26}, {1015, 91, 33}, {1102, 82, 41},
                  {1061, 68, 52}};
```


Ordene com qsort, e cada ELEMENTO é uma linha inteira (int[3]). A ordem é:
nota maior primeiro; no empate, o mais velho primeiro (como no edital do
mestrado); persistindo o empate, a menor inscrição. Mostre a classificação:


```text
Saída esperada:
Pos Inscr Nota Idade
 1º  1007   91    33
 2º  1015   91    33
 3º  1102   82    41
 4º  1120   82    41
 5º  1043   82    29
 6º  1088   75    26
 7º  1061   68    52
```

**Dicas:**

1. qsort(cand, 7, sizeof cand[0], compara); sizeof cand[0] é 12 bytes:
   o qsort move a linha inteira a cada troca.
2. Na comparação, o void * aponta para o primeiro int da linha:
   const int *x = a, *y = b; e x[1] é a nota, x[2] a idade.
3. Compare um critério de cada vez: if (x[1] != y[1]) return y[1] - x[1];
   depois a idade (decrescente), depois a inscrição (crescente).
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 06-ponteiros/lista/P0621.c
```

---

**Exercício P0622** · ★★★ · O meu qsort de qualquer tipo

Escreva a sua versão genérica de ordenação, com a mesma assinatura do
qsort:


```text
void ordenar(void *base, size_t n, size_t tam,
             int (*cmp)(const void *, const void *));
```


Use o método de inserção: para cada i de 1 a n - 1, enquanto o elemento
j - 1 for maior que o j (segundo cmp), troque os dois e recue j. Como você
não sabe o tipo, trabalhe com bytes: o elemento i começa em
(unsigned char *) base + i * tam, e a troca é byte a byte (escreva void
troca_bytes(void *a, void *b, size_t tam)). Teste com os três vetores:


```text
int idades[6] = {34, 19, 52, 27, 19, 40};
double precos[5] = {9.90, 2.49, 15.00, 4.75, 2.10};
char cidades[5][12] = {"Tefe", "Coari", "Borba", "Manaus", "Autazes"};
```



```text
Saída esperada:
Idades: 19 19 27 34 40 52
Preços: 2.10 2.49 4.75 9.90 15.00
Cidades: Autazes Borba Coari Manaus Tefe
```

**Dicas:**

1. Aritmética com void * não é C padrão: converta para unsigned char * e
   ande tam bytes por elemento.
2. troca_bytes: um for de 0 a tam - 1 trocando pa[k] com pb[k], onde pa e
   pb são unsigned char *.
3. As comparações são as de sempre: para int, *(const int *) a; para a
   matriz de char, o endereço da linha já é a string (strcmp direto).
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 06-ponteiros/lista/P0622.c
```

---

**Exercício P0623** · ★★★ · Separar a linha do CSV no lugar

Uma linha de CSV da agenda do mestrado tem campos separados por ';', e
alguns podem estar vazios:


```text
char linha[] = "27/11/2026;Prova de Conhecimentos;;08:00;Manaus";
```


Escreva int separar(char *linha, char sep, char *campos[], int max), que
NÃO copia nada: troca cada separador por '\0' dentro da própria linha e
guarda em campos[i] o endereço do começo de cada campo. Devolve quantos
campos achou (no máximo max). Campo vazio vira uma string vazia, e não
some (diferente do strtok, que pula separadores seguidos). Mostre os
campos e a posição de cada um dentro da linha:


```text
Saída esperada:
5 campos
[0] posição  0: "27/11/2026"
[1] posição 11: "Prova de Conhecimentos"
[2] posição 34: ""
[3] posição 35: "08:00"
[4] posição 41: "Manaus"
A linha agora: "27/11/2026"
```

**Dicas:**

1. O primeiro campo começa em linha: campos[0] = linha; n = 1.
2. Ande com char *p de linha até o '\0'. Ao achar sep: *p = '\0'; e, se
   n < max, campos[n++] = p + 1.
3. A posição de cada campo é campos[i] - linha.
4. Depois de separar, printf("%s", linha) mostra só o primeiro campo: o
   '\0' que você pôs no lugar do ';' termina a string ali.
5. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 06-ponteiros/lista/P0623.c
```

---

**Exercício P0624** · ★★★ · Números romanos nos dois sentidos

Os capítulos de um livro antigo vêm em algarismos romanos. Escreva:


```text
int romano_para_int(const char *s);
void int_para_romano(int n, char *saida);
```


A primeira anda com um ponteiro pela string: cada símbolo soma seu valor,
mas se o próximo for MAIOR, ele subtrai (IV = 4, XC = 90). A segunda
escreve o romano em saida, avançando um ponteiro de escrita. Converta os
romanos "XIV", "XCIX", "MMXXVI" e "CDXLIV" para int, e 1987, 3999 e 49
para romano:


```text
Saída esperada:
XIV = 14
XCIX = 99
MMXXVI = 2026
CDXLIV = 444
1987 = MCMLXXXVII
3999 = MMMCMXCIX
49 = XLIX
```

**Dicas:**

1. Uma função int valor(char c) com um switch (I 1, V 5, X 10, L 50,
   C 100, D 500, M 1000).
2. Na leitura: se valor(*s) < valor(*(s + 1)), subtrai; senão, soma. No
   último símbolo, *(s + 1) é o '\0', que vale 0: soma.
3. Na escrita, use duas tabelas em ordem decrescente, incluindo os pares
   de subtração: 1000 M, 900 CM, 500 D, 400 CD, 100 C, 90 XC, 50 L,
   40 XL, 10 X, 9 IX, 5 V, 4 IV, 1 I. Enquanto n >= valor, copie o símbolo
   (andando com char *p) e tire o valor de n. Feche com *p = '\0'.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 06-ponteiros/lista/P0624.c
```

---

**Exercício P0625** · ★★★ · Conserte a escala de folgas

O programa da escala de folgas tem TRÊS erros de propósito, e o gcc não
avisa de nenhum. Ele deveria: trocar o primeiro e o último da equipe de
lugar, ordenar a equipe em ordem alfabética e montar o crachá do primeiro
da lista. Rode com o rodar e compare com a saída esperada: a troca não
troca e a ordem sai errada. Conserte esses dois; aí o AddressSanitizer
passa a acusar o terceiro (é comum um erro esconder o outro). No fim, o
programa mostra:


```text
Saída esperada:
Trocados: Wellington Rui Mirela Edson Joana
Em ordem: Edson Joana Mirela Rui Wellington
Crachá do último: Wellington
```

**Dicas:**

1. A troca recebe cópias dos dois ponteiros: trocar as cópias não muda o
   vetor. Ela precisa receber o endereço das gavetas (const char **).
2. No qsort de um vetor de const char *, cada elemento é um PONTEIRO: a
   comparação recebe o endereço da gaveta e precisa de *(const char **) a
   para chegar na string.
3. Conte as letras de "Wellington" e o tamanho do crachá.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 06-ponteiros/lista/P0625.c
```

---

**Exercício P0626** · ★★★ · O ponto de equilíbrio pela bisseção

Uma fábrica de açaí em pó tem lucro, em milhares de reais, de
lucro(x) = -0.5x² + 12x - 40 quando produz x toneladas. Ela quer saber a
partir de quantas toneladas o lucro deixa de ser negativo: a RAIZ de lucro
entre 0 e 10. Escreva o método da bisseção, que serve para QUALQUER
função:


```text
double bissecao(double (*f)(double), double a, double b, double tol,
                int *voltas);
```


Se f(a) e f(b) têm sinais opostos, existe raiz entre eles. Olhe o meio m:
se f(a) e f(m) têm sinais opostos, a raiz está em [a, m]; senão, em [m, b].
Repita até o intervalo ficar menor que tol e devolva o meio. Use tol =
0.0001 e resolva também x³ - x - 2 = 0 entre 1 e 2:


```text
Saída esperada:
lucro: raiz 4.0000 em 17 voltas (f = -0.00018)
x³ - x - 2: raiz 1.5214 em 14 voltas (f = 0.00008)
lucro: sem troca de sinal em [5.0, 10.0]
```

**Dicas:**

1. Sinais opostos: f(a) * f(m) < 0.
2. while (b - a > tol) { m = (a + b) / 2; ...; (*voltas)++; } e, no fim,
   return (a + b) / 2;
3. Antes do laço, se f(a) * f(b) > 0 não há garantia de raiz: devolva a
   e deixe *voltas = -1 (o main avisa).
4. A raiz exata da primeira é 12 - sqrt(64) = 4: a bisseção chega em
   4.0000 com 17 voltas.
5. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 06-ponteiros/lista/P0626.c
```

---

**Exercício P0627** · ★★★ · Multiplicar matrizes guardadas em fila

Quando as dimensões mudam, é comum guardar a matriz num vetor simples:
o elemento (i, j) de uma matriz com C colunas fica em v[i * C + j].
Escreva


```text
void multiplicar(const int *a, const int *b, int *c, int l, int m, int n);
```


que calcula c = a x b, com a de l x m, b de m x n e c de l x n, todas
nesse formato. Escreva também void mostrar(const int *v, int l, int c) e
bool identidade(const int *v, int n). Calcule a x b para as matrizes
abaixo e confira que a x I = a, com I a identidade 3x3:


```text
int a[2 * 3] = {1, 2, 3,
                4, 5, 6};
int b[3 * 4] = {2, 0, 1, 3,
                1, 4, 0, 2,
                0, 1, 5, 1};
```



```text
Saída esperada:
a x b (2x4):
   4  11  16  10
  13  26  34  28
id é identidade? sim
a x I == a? sim
```

**Dicas:**

1. c[i * n + j] = soma de a[i * m + k] * b[k * n + j], para k de 0 a m - 1.
2. Monte a identidade 3x3 num int id[9] com id[i * 3 + j] = (i == j), e
   teste-a com a sua função identidade antes de usar.
3. Para conferir a x I = a, compare as 6 posições do resultado com as de a.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 06-ponteiros/lista/P0627.c
```

---

**Exercício P0628** · ★★★ · Todas as vezes que a palavra aparece

Um revisor quer achar todas as vezes que "boi" aparece na letra da toada:


```text
const char *letra = "O boi bumbá, o boi Garantido, o boizinho do povo, boi!";
```


Escreva int achar_todas(const char *texto, const char *palavra,
const char *pos[], int max), que usa strstr para guardar em pos o endereço
de cada ocorrência (no máximo max) e devolve quantas achou. Depois mostre
a posição de cada uma (diferença de ponteiros) e o texto com cada
ocorrência entre colchetes, imprimindo caractere a caractere:


```text
Saída esperada:
4 ocorrências: 2 16 33 51
O [boi] bumbá, o [boi] Garantido, o [boi]zinho do povo, [boi]!
```

**Dicas:**

1. const char *p = strstr(texto, palavra); enquanto p != NULL: guarde p e
   continue a busca a partir de p + 1 (e não de texto, senão acha a mesma
   de novo).
2. Para os colchetes, ande com um ponteiro c pelo texto e um índice k na
   próxima ocorrência: se c == pos[k], imprima '[', a palavra e ']', pule
   strlen(palavra) caracteres e faça k++.
3. "boizinho" também contém "boi": é ocorrência para o strstr.
4. Resposta esperada: a saída acima (4 ocorrências).

```bash
~/LPEDC/rodar 06-ponteiros/lista/P0628.c
```

---

**Exercício P0629** · ★★★ · Embaralhar qualquer vetor

O app do bingo da igreja precisa embaralhar vetores de vários tipos, e o
resultado tem que ser repetível para a auditoria. Escreva:


```text
unsigned sorteio(unsigned *semente, unsigned n);
void embaralhar(void *v, size_t n, size_t tam, unsigned *semente);
```


sorteio atualiza a semente com *semente = *semente * 1103515245u + 12345u
e devolve (*semente / 65536) % n (um número de 0 a n - 1). embaralhar usa o
algoritmo de Fisher-Yates: para i de n - 1 até 1, sorteia j entre 0 e i
e troca o elemento i com o j, byte a byte. Com a semente 2026, embaralhe
as 10 bolas e depois, com a mesma semente continuando, os 4 nomes:


```text
int bolas[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
char nomes[4][12] = {"Dona Lia", "Seu Ze", "Rita", "Padre Joao"};
```



```text
Saída esperada:
Bolas: 3 2 8 6 1 10 5 4 7 9
Ordem de chamada: Seu Ze, Dona Lia, Padre Joao, Rita
Semente final: 3469224078
```

**Dicas:**

1. A conta usa unsigned: quando passa do maior valor, ela "dá a volta"
   (módulo 2³²) sem comportamento indefinido. Com int, estourar é erro.
2. O elemento i começa em (unsigned char *) v + i * tam. Escreva uma
   troca_bytes(void *a, void *b, size_t tam) como no P0622.
3. j = sorteio(semente, i + 1) sorteia de 0 a i. Pule a troca se j == i.
4. A semente é passada por ponteiro para que a segunda chamada continue
   a sequência da primeira.
5. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 06-ponteiros/lista/P0629.c
```

---

**Exercício P0630** · ★★★ · O caça-palavras com ponteiros

Um caça-palavras de 5 linhas e 6 colunas está no esqueleto, numa matriz
char g[5][7] (cada linha tem 6 letras + '\0'). Escreva


```text
bool achar(char g[5][7], const char *palavra, int *lin, int *col,
           int *dir, const int *dl, const int *dc);
```


que procura a palavra nas 8 direções a partir de cada casa e,
se achar, entrega a casa inicial e o número da direção (0 a 7). Use os
vetores dl e dc do esqueleto: andar na direção d é somar dl[d] à linha e
dc[d] à coluna. Procure as cinco palavras do esqueleto:


```text
Saída esperada:
BURITI linha 4, coluna 0, ->
ACAI   linha 0, coluna 3, <-
PEQUI  linha 0, coluna 5, desce
TUPI   linha 4, coluna 4, sobe <-
CUPU   não está na grade
```

**Dicas:**

1. Quatro laços: linha, coluna, direção e, por fim, as letras da palavra.
   Para a letra k: l = i + k * dl[d], c = j + k * dc[d].
2. Antes de ler g[l][c], confira se 0 <= l < 5 e 0 <= c < 6. Ler fora da
   matriz é estouro (o AddressSanitizer acusa).
3. Ande pela palavra com um ponteiro: for (const char *p = palavra; *p;
   p++, k++).
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 06-ponteiros/lista/P0630.c
```
