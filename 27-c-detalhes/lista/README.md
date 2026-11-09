<!-- Gerado por _gerador a partir dos arquivos P????.c desta pasta. -->

# Lista prática · Módulo 27 · Detalhes de C que caem em prova

30 exercícios de codificar que treinam o módulo inteiro, misturando os assuntos, no ritmo da prova do PPGI (veja [PPGI.md](../../PPGI.md)). Cada arquivo `P????.c` desta pasta é um exercício: a resposta vai dentro dele, embaixo de `// Escreva sua resposta abaixo:`. Uma resolução de cada um está em `_respostas/27-c-detalhes/lista/`. Só olhe depois de tentar.

[Voltar ao módulo](../README.md)

## ★☆☆ Aquecimento

**Exercício P2701** · ★☆☆ · A calculadora do caixa

Escreva int calcular(int a, char op, int b, int *resultado), que usa um
switch sobre op ('+', '-', '*', '/') para fazer a conta e guardar em
*resultado. Ela devolve 1 se deu certo, 0 se a divisão é por zero e -1 se
a operação não existe. No main, faça as contas abaixo e mostre cada uma.


```text
12 + 5    12 - 5    12 * 5    12 / 5    7 / 0    12 % 5
```



```text
Saída esperada:
12 + 5 = 17
12 - 5 = 7
12 * 5 = 60
12 / 5 = 2
7 / 0: divisão por zero
12 % 5: operação inválida
```

**Dicas:**

1. Cada case termina com break ou return; sem isso, a execução cai no
   case de baixo.
2. O default pega qualquer char que não tem case.
3. No printf, o % sozinho se escreve %%; o char da operação sai com %c.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/lista/P2701.c
```

---

**Exercício P2702** · ★☆☆ · Dígitos com do/while

Escreva int contar_digitos(unsigned n) e unsigned somar_digitos(unsigned n),
as duas com do/while. O do/while roda o corpo pelo menos uma vez, e é
exatamente isso que faz o 0 ter 1 dígito. Teste com 0, 7, 2026 e 1000000.


```text
Saída esperada:
0: 1 dígito(s), soma 0
7: 1 dígito(s), soma 7
2026: 4 dígito(s), soma 10
1000000: 7 dígito(s), soma 1
```

**Dicas:**

1. O último dígito é n % 10; tirar o último dígito é n /= 10.
2. do { ... } while (n > 0); com ponto e vírgula depois do while.
3. Com while comum, o 0 daria 0 dígitos.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/lista/P2702.c
```

---

**Exercício P2703** · ★☆☆ · A conta de luz

A conta de luz cobra cada kWh pela tarifa mais a bandeira, e soma uma taxa
fixa. Com 250 kWh, tarifa de 80 centavos, bandeira de 10 centavos por kWh e
taxa de R$ 15,00, a conta é R$ 240,00. O programa abaixo compila sem aviso,
mas as duas contas estão erradas. Conserte só com parênteses e com a ordem
das operações.


```text
Saída esperada:
total: R$ 240.00
bandeira: 11% do preço do kWh
```

**Dicas:**

1. Rode antes: sai R$ 215.10 e 0%.
2. O consumo multiplica a soma da tarifa com a bandeira.
3. 10 / 90 em inteiros é 0: multiplique por 100 antes de dividir.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/lista/P2703.c
```

---

**Exercício P2704** · ★☆☆ · Quatro operações sobre um bit

Escreva as funções abaixo, com n de 0 a 7, e uma void mostrar(unsigned x)
que escreve os 8 bits de baixo de x:


```text
bool testar(unsigned x, int n)
unsigned ligar(unsigned x, int n)
unsigned desligar(unsigned x, int n)
unsigned inverter(unsigned x, int n)
```


Comece com x = 0x2C e mostre o que se pede.


```text
Saída esperada:
x = 00101100
bit 3 ligado? sim
ligar 0 -> 00101101
desligar 5 -> 00001100
inverter 7 -> 10101100
```

**Dicas:**

1. A máscara do bit n é 1u << n.
2. Ligar é |, desligar é & com ~, inverter é ^, testar é (x >> n) & 1u.
3. Cada operação parte do x original: as funções não mudam x.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/lista/P2704.c
```

---

**Exercício P2705** · ★☆☆ · Para onde vai o negativo

Converter um valor para um tipo sem sinal é sempre definido: o C soma ou
subtrai 2^bits até o valor caber. Escreva um programa que guarde cada valor
abaixo numa variável do tipo pedido e mostre o resultado:


```text
-1 em unsigned char      256 em unsigned char    300 em unsigned char
-2 em unsigned short     -3 em unsigned
```



```text
Saída esperada:
(unsigned char)-1 = 255
(unsigned char)256 = 0
(unsigned char)300 = 44
(unsigned short)-2 = 65534
(unsigned)-3 = 4294967293
```

**Dicas:**

1. unsigned char tem 8 bits: a conta é módulo 256. unsigned short tem 16:
   módulo 65536.
2. Use o cast para o gcc não reclamar de constante grande demais:
   unsigned char a = (unsigned char)300;
3. unsigned char e unsigned short viram int no printf: %d serve. O
   unsigned vai com %u.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/lista/P2705.c
```

---

**Exercício P2706** · ★☆☆ · Três idades em ordem

Escreva void trocar(int *a, int *b) e void ordenar3(int *a, int *b, int *c),
que deixa os três valores em ordem crescente usando só trocar. No main, as
idades da família são 30, 12 e 25, em três variáveis separadas.


```text
Saída esperada:
antes: 30 12 25
depois: 12 25 30
```

**Dicas:**

1. Três comparações bastam: (a, b), (b, c) e de novo (a, b).
2. Dentro de ordenar3, a, b e c já são ponteiros: trocar(a, b), sem &.
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/lista/P2706.c
```

---

**Exercício P2707** · ★☆☆ · A lista da feira no arquivo

Grave a lista da feira no arquivo p2707_feira.txt, um item por linha no
formato nome;preço, com fopen e fprintf. Feche, abra de novo para leitura,
leia cada linha com fscanf e some os preços. No fim, apague o arquivo com
remove.


```text
banana 6.50    tomate 8.90    alface 3.00    queijo 22.40
```



```text
Saída esperada:
gravados 4 itens
banana: R$ 6.50
tomate: R$ 8.90
alface: R$ 3.00
queijo: R$ 22.40
total da feira: R$ 40.80
```

**Dicas:**

1. Sempre confira se o fopen devolveu NULL.
2. fscanf(f, " %31[^;];%lf", nome, &preco) lê o nome até o ; e depois o
   número. O espaço no começo pula o \n da linha anterior.
3. O laço continua enquanto o fscanf devolver 2.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/lista/P2707.c
```

---

**Exercício P2708** · ★☆☆ · Dia útil ou fim de semana

Crie typedef enum { DOM, SEG, TER, QUA, QUI, SEX, SAB } Dia; e um vetor com
os nomes. Escreva const char *tipo(Dia d) com um switch em que DOM e SAB
dividem o mesmo case (um embaixo do outro, sem break entre eles) e os
outros dias caem no default. Mostre o tipo de DOM, QUA e SAB e, no fim, o
dia que fica 2 depois de QUA, usando que um enum é um int.


```text
Saída esperada:
DOM: fim de semana
QUA: dia útil
SAB: fim de semana
QUA + 2 = SEX (5)
```

**Dicas:**

1. case DOM:
   case SAB:
       return "fim de semana";
2. O enum começa em 0: QUA vale 3, e QUA + 2 vale 5, que é SEX.
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/lista/P2708.c
```

---

**Exercício P2709** · ★☆☆ · Notas válidas com macros

Defina, com #define, a constante QTD_NOTAS (5) e as macros
QUADRADO(x) e ENTRE(x, a, b) (verdadeiro se a <= x <= b), com todos os
parênteses que uma macro precisa. Para as notas {7, 11, -1, 10, 5}, diga
quais são válidas (de 0 a 10) e some os quadrados das válidas.


```text
Saída esperada:
nota 7: válida
nota 11: inválida
nota -1: inválida
nota 10: válida
nota 5: válida
válidas: 3, soma dos quadrados: 174
```

**Dicas:**

1. #define QUADRADO(x) ((x) * (x))
2. #define ENTRE(x, a, b) ((x) >= (a) && (x) <= (b))
3. Teste a macro com QUADRADO(1 + 2): tem que dar 9, não 5.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/lista/P2709.c
```

---

**Exercício P2710** · ★☆☆ · A semana mais quente

As máximas da semana em Manaus foram {28, 31, 33, 29, 35, 30, 27}, de
domingo (dia 0) a sábado (dia 6). Escreva um programa que mostre a média
com duas casas, quantos dias ficaram acima da média e o dia mais quente.


```text
Saída esperada:
média = 30.43
acima da média: 3 dias
mais quente: 35 no dia 4
```

**Dicas:**

1. A média precisa de divisão real: (double)soma / 7.
2. Calcule o tamanho com sizeof v / sizeof v[0] em vez de escrever 7.
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/lista/P2710.c
```

## ★★☆ Para pensar

**Exercício P2711** · ★★☆ · O estoque que não fica negativo

Com typedef struct { char nome[20]; unsigned qtd; double preco; } Produto;,
escreva:


```text
bool vender(Produto *p, unsigned q)  // recusa se não houver q unidades
double valor_estoque(const Produto v[], int n)
```


Como qtd é unsigned, uma venda maior que o estoque daria a volta para um
número enorme: vender tem que conferir ANTES de subtrair. Estoque inicial:
café (10 a R$ 18.00), açúcar (4 a R$ 5.50), leite (12 a R$ 6.00). Venda 3
cafés, 5 açúcares e 12 leites.


```text
Saída esperada:
vender 3 café: ok
vender 5 açúcar: recusada (só 4)
vender 12 leite: ok
café: 7, açúcar: 4, leite: 0
valor em estoque: R$ 148.00
```

**Dicas:**

1. if (q > p->qtd) return false; e só depois p->qtd -= q.
2. O valor é a soma de qtd * preco: 7 * 18 + 4 * 5.5 + 0 * 6.
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/lista/P2711.c
```

---

**Exercício P2712** · ★★☆ · A célula da planilha (union com etiqueta)

Uma célula de planilha guarda um inteiro, um número real ou um texto, um
de cada vez. Monte uma union com etiqueta:


```text
typedef enum { INTEIRO, REAL, TEXTO } Tipo;
typedef struct { Tipo tipo; union { int i; double d; char s[16]; } v; } Celula;
```


Escreva void mostrar(const Celula *c), com um switch sobre c->tipo que lê
só o campo certo da union. Mostre as células 42, 3.14 e "feira" e, no fim,
o sizeof de Celula e da union.


```text
Saída esperada:
inteiro: 42
real: 3.14
texto: feira
sizeof(Celula) = 24, sizeof da union = 16
```

**Dicas:**

1. Na union, os três campos começam no mesmo byte: o tamanho é o do maior
   (16, o vetor de char), e não a soma.
2. A struct tem 4 bytes do enum, 4 de sobra para alinhar o double da
   union e os 16 da union: 24.
3. Para o texto, use strcpy(c.v.s, "feira") depois de pôr c.tipo = TEXTO.
4. sizeof c.v mede só a union.
5. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/lista/P2712.c
```

---

**Exercício P2713** · ★★☆ · Quem ganhou o jogo da velha

Escreva char vencedor(char t[3][3]), que devolve 'X' ou 'O' se alguma linha,
coluna ou diagonal tem três iguais, ou '-' se ninguém ganhou. Teste com os
dois tabuleiros abaixo ('.' é casa vazia).


```text
tabuleiro 1:  X O .     tabuleiro 2:  X O X
              O X .                   X O O
              . O X                   O X X
```



```text
Saída esperada:
tabuleiro 1: vencedor X
tabuleiro 2: vencedor -
```

**Dicas:**

1. Uma função auxiliar trinca(a, b, c) que devolve a se a == b == c e a
   não é '.', ou 0, deixa o código curto.
2. São 8 trincas: 3 linhas, 3 colunas e 2 diagonais.
3. Inicialize com strings: char t1[3][3] = {{'X','O','.'}, ...}.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/lista/P2713.c
```

---

**Exercício P2714** · ★★☆ · Um processador de brinquedo

Um processador de brinquedo tem instruções de 1 byte: os bits 7-6 são o
código da operação (00 LOAD, 01 ADD, 10 SUB, 11 JMP) e os bits 5-0 são o
operando (0 a 63). Escreva um programa que, com um switch, execute os bytes
{0x05, 0x47, 0x83, 0xC0} sobre um acumulador que começa em 0, mostrando
cada instrução decodificada.


```text
Saída esperada:
0x05: LOAD 5 -> acc = 5
0x47: ADD 7 -> acc = 12
0x83: SUB 3 -> acc = 9
0xC0: JMP 0 (fim do programa)
```

**Dicas:**

1. Código: (b >> 6) & 3u. Operando: b & 0x3Fu.
2. Um enum { LOAD, ADD, SUB, JMP } deixa os case legíveis: os valores 0 a
   3 batem com os bits.
3. Guarde os bytes em unsigned char e mostre com 0x%02X.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/lista/P2714.c
```

---

**Exercício P2715** · ★★☆ · O inverno em Gramado

O programa abaixo compila sem nenhum aviso, mas as duas funções erram por
misturar int e unsigned:


```text
- media devolve a média das temperaturas, e sai um número absurdo;
- compara devolve -1, 0 ou 1 conforme a é menor, igual ou maior que b, e
  diz que 3 é maior que 7.
```


Conserte as duas sem mudar as assinaturas.


```text
Saída esperada:
média: -2.00
compara(3, 7) = -1
compara(7, 3) = 1
compara(5, 5) = 0
```

**Dicas:**

1. Em soma / n, o int soma vira unsigned (conversão aritmética usual):
   -8 vira 4294967288. Converta para double antes de dividir.
2. a - b > 0 com unsigned é verdadeiro sempre que a != b. Compare a e b
   direto.
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/lista/P2715.c
```

---

**Exercício P2716** · ★★☆ · A tabela de distâncias da BR

Quatro cidades ficam na mesma rodovia, nos quilômetros {0, 12, 30, 45}.
Com int n = 4, crie um VLA int d[n][n] com a distância entre cada par
(|km[i] - km[j]|), mostre a tabela e o par mais distante. Escreva o
preenchimento e a busca como funções com parâmetro VLA.


```text
Saída esperada:
  0 12 30 45
 12  0 18 33
 30 18  0 15
 45 33 15  0
mais distantes: 0 e 3 (45 km)
```

**Dicas:**

1. void preencher(int n, const int km[n], int d[n][n])
2. A tabela é simétrica: basta olhar j > i na busca.
3. Cada número com %3d.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/lista/P2716.c
```

---

**Exercício P2717** · ★★☆ · Boletim em arquivo binário

Com typedef struct { char nome[16]; float nota; } Aluno;, grave os 4
alunos abaixo de uma vez no arquivo p2717_boletim.bin com fwrite. Feche,
abra de novo, leia registro por registro com fread e mostre só os
aprovados (nota >= 7). No fim, apague o arquivo.


```text
Ana 8.5    Bruno 6.0    Caio 7.0    Duda 4.5
```



```text
Saída esperada:
gravados 4 registros (80 bytes)
aprovado: Ana (8.5)
aprovado: Caio (7.0)
```

**Dicas:**

1. Modo "wb" para gravar e "rb" para ler: o arquivo guarda os bytes da
   struct, como estão na memória.
2. fwrite(v, sizeof v[0], 4, f) devolve quantos registros gravou.
3. while (fread(&a, sizeof a, 1, f) == 1) lê um por vez.
4. sizeof(Aluno) = 16 + 4 = 20 bytes.
5. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/lista/P2717.c
```

---

**Exercício P2718** · ★★☆ · A catraca do ônibus

A catraca tem dois estados, typedef enum { TRAVADA, LIBERADA } Estado;, e
recebe dois eventos: 'M' (moeda) e 'P' (empurrar). Travada, a moeda
libera e o empurrão é bloqueado; liberada, o empurrão deixa passar e trava
de novo, e uma moeda a mais é desperdiçada. Processe a sequência "PMPMMPP"
com um do/while sobre a string e um switch sobre o estado, contando
passagens, moedas, moedas desperdiçadas e bloqueios.


```text
Saída esperada:
passagens: 2
moedas: 3 (1 desperdiçada)
bloqueios: 2
```

**Dicas:**

1. const char *p = eventos; do { ... p++; } while (*p != '\0'); serve
   porque a string tem pelo menos um evento.
2. Dentro do switch (estado), um if sobre o evento decide o que fazer.
3. Comece em TRAVADA.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/lista/P2718.c
```

---

**Exercício P2719** · ★★☆ · Ordenar andando com ponteiros

Sem usar índice nenhum (nada de v[i]), só aritmética de ponteiros, escreva:


```text
int *maior(int *ini, int *fim)   // o maior em [ini, fim); fim fica de fora
void ordenar(int *ini, int *fim) // ordem crescente, por seleção
```


Ordenar coloca o maior do trecho na última posição, encurta o trecho e
repete. Use com o vetor {42, 7, 19, 88, 3} e mostre o índice do maior
com a diferença de ponteiros.


```text
Saída esperada:
maior: 88 no índice 3
ordenado: 3 7 19 42 88
```

**Dicas:**

1. for (int *p = ini + 1; p < fim; p++) percorre o trecho.
2. p - v dá o índice, do tipo ptrdiff_t: mostre com %td.
3. Na ordenação, troque *maior(ini, fim) com *(fim - 1) e faça fim--.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/lista/P2719.c
```

---

**Exercício P2720** · ★★☆ · Uma biblioteca de bits em macros

Escreva quatro macros para mexer em bits de um uint8_t, com todos os
parênteses que uma macro precisa:


```text
BIT(n)        o número só com o bit n ligado
LIGA(x, n)    x com o bit n ligado
DESLIGA(x, n) x com o bit n desligado
TESTA(x, n)   1 se o bit n de x está ligado, senão 0
```


Para provar que as macros estão blindadas, use argumentos com
expressões: comece com uint8_t flags = 0; ligue o bit 1 + 1 e o bit 6,
desligue o bit 2 * 3 e teste !TESTA(flags, 2) e TESTA(flags, 7 - 1).


```text
Saída esperada:
BIT(1 + 1) = 4
depois de ligar 2 e 6: 68
depois de desligar 6: 4
!TESTA(flags, 2) = 0
TESTA(flags, 7 - 1) = 0
```

**Dicas:**

1. #define BIT(n) (1u << (n)): sem os parênteses em volta de n,
   1u << 1 + 1 até daria certo, mas BIT(a) * 2 não.
2. #define TESTA(x, n) (((x) >> (n)) & 1u): sem os parênteses de fora,
   !TESTA(...) aplicaria o ! só ao primeiro pedaço.
3. Guarde de volta com cast: flags = (uint8_t)LIGA(flags, 1 + 1);
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/lista/P2720.c
```

## ★★★ Desafio

**Exercício P2721** · ★★★ · Calculadora de notação polonesa reversa

Na notação polonesa reversa, o operador vem depois dos operandos e não
existe precedência nem parênteses: "3 4 + 2 *" é (3 + 4) * 2. Escreva
int avaliar(const char *expr, int *resultado), que percorre a string com um
ponteiro, empilha cada dígito (só operandos de 0 a 9) num vetor e, a cada
operador (+ - * /), desempilha dois, faz a conta com um switch e empilha o
resultado. Devolve 1 se deu certo e 0 se a expressão é inválida (faltou
operando, divisão por zero ou sobrou mais de um número).


```text
Saída esperada:
3 4 + 2 * = 14
5 1 2 + 4 * + 3 - = 14
9 2 3 * - = 3
4 + = expressão inválida
8 0 / = expressão inválida
```

**Dicas:**

1. Pilha num vetor: int pilha[32]; int topo = 0; empilhar é
   pilha[topo++] = x; desempilhar é pilha[--topo].
2. Cuidado com a ordem: o primeiro desempilhado é o operando da DIREITA.
   Em "9 2 3 * -", a conta é 9 - 6.
3. Um dígito c vira número com c - '0'. Espaço, pule.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/lista/P2721.c
```

---

**Exercício P2722** · ★★★ · O byte de trás para a frente

Escreva, para uint8_t, as funções abaixo e mostre os resultados para o
byte 0x1D (00011101):


```text
int contar(uint8_t b)          // quantos bits 1
int paridade(uint8_t b)        // 1 se a quantidade de bits 1 é ímpar
uint8_t espelhar(uint8_t b)    // bit 0 vira bit 7, bit 1 vira bit 6...
uint8_t girar(uint8_t b, int n) // gira n casas à esquerda (0 a 7)
```



```text
Saída esperada:
b = 00011101 (0x1D)
bits ligados: 4
paridade: 0
espelhado: 10111000 (0xB8)
girado 3: 11101000 (0xE8)
girado 0: 00011101 (0x1D)
```

**Dicas:**

1. Espelhar: para cada b de 0 a 7, se o bit b está ligado, ligue o bit
   7 - b do resultado.
2. Girar: (b << n) | (b >> (8 - n)), guardado num uint8_t. Com n = 0,
   b >> 8 é definido (o b virou int de 32 bits), mas trate o caso
   separado para ficar claro.
3. A promoção inteira transforma o uint8_t em int antes do <<: corte de
   volta com (uint8_t)(...).
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/lista/P2722.c
```

---

**Exercício P2723** · ★★★ · O sensor que manda bytes

Um sensor de temperatura manda cada leitura num byte em complemento de
dois (-128 a 127), e um segundo sensor manda leituras de 12 bits. Sem
depender de conversão "definida pela implementação", escreva:


```text
int de_byte(uint8_t b)       // 0x80 a 0xFF são negativos
uint8_t para_byte(int v)     // o caminho de volta, de -128 a 127
int de_12_bits(unsigned x)   // estende o sinal: o bit 11 é o sinal
```


Converta os bytes {0x00, 0x7F, 0x80, 0xFF, 0xF6}, volte o -10 para byte e
leia os valores de 12 bits 0x7FF e 0xFF6.


```text
Saída esperada:
0x00 -> 0
0x7F -> 127
0x80 -> -128
0xFF -> -1
0xF6 -> -10
-10 -> 0xF6
12 bits: 0x7FF -> 2047, 0xFF6 -> -10
```

**Dicas:**

1. Se b >= 128, o valor é b - 256. Isso é conta com int: sempre definida.
2. Converter para unsigned é sempre definido: (uint8_t)v soma 256 aos
   negativos.
3. Com 12 bits, a régua é 4096: se o bit 11 (0x800) está ligado, o valor é
   x - 4096.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/lista/P2723.c
```

---

**Exercício P2724** · ★★★ · Figuras lidas de um arquivo

Grave no arquivo p2724_figuras.txt as linhas abaixo (uma letra e as
medidas) e depois leia o arquivo com fscanf. Cada figura vai para uma
struct com etiqueta: typedef enum { CIRCULO, RETANGULO, TRIANGULO } Forma;
e uma union com as medidas de cada forma. Calcule a área de cada uma com
um switch (triângulo pelos três lados, com a fórmula de Heron) e a soma.
Apague o arquivo no fim.


```text
C 2
R 3 4
T 3 4 5
```



```text
Saída esperada:
círculo de raio 2.0: 12.57
retângulo 3.0 x 4.0: 12.00
triângulo 3.0, 4.0, 5.0: 6.00
área total: 30.57
```

**Dicas:**

1. Leia a letra com fscanf(f, " %c", &letra) e, conforme ela, leia 1, 2
   ou 3 números.
2. Heron: s = (a + b + c) / 2 e área = sqrt(s(s - a)(s - b)(s - c)).
3. Use acos(-1.0) para o pi; o rodar já liga a libm (-lm).
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/lista/P2724.c
```

---

**Exercício P2725** · ★★★ · Girar a foto 90 graus

Uma foto em tons de cinza é uma matriz de pixels. Escreva, com parâmetros
VLA:


```text
void girar(int l, int c, int a[l][c], int r[c][l])  // 90° no sentido horário
void mostrar(int l, int c, int m[l][c])
bool iguais(int l, int c, int a[l][c], int b[l][c])
```


Gire a foto 2 x 3 abaixo e mostre o resultado. Depois, com uma 3 x 3
preenchida de 1 a 9, gire quatro vezes seguidas e confira que voltou à
original.


```text
1 2 3
4 5 6
```



```text
Saída esperada:
girada (3 x 2):
  4  1
  5  2
  6  3
4 giros na 3 x 3 voltam ao original? sim
```

**Dicas:**

1. Girando no sentido horário, a linha i da original vira a coluna
   l - 1 - i da girada: r[j][l - 1 - i] = a[i][j].
2. Para girar várias vezes, alterne entre duas matrizes 3 x 3 (ou copie
   de volta depois de cada giro).
3. VLA não aceita = {...}: preencha a 2 x 3 com a[i][j] = i * c + j + 1.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/lista/P2725.c
```

---

**Exercício P2726** · ★★★ · A tabela do campeonato com qsort

Com typedef struct { char nome[16]; int pontos; int saldo; } Time; e
typedef enum { POR_PONTOS, POR_NOME } Criterio;, escreva duas comparadoras
para o qsort e uma função void ordenar(Time v[], int n, Criterio c) que
escolhe a comparadora com um switch, guardando-a num ponteiro para função.
Por pontos: mais pontos primeiro; no empate, maior saldo.


```text
Times: Remo (10, +3), Paysandu (12, +5), Nacional (10, +6), Fast (7, -2)
```



```text
Saída esperada:
por pontos: Paysandu 12, Nacional 10, Remo 10, Fast 7
por nome: Fast 7, Nacional 10, Paysandu 12, Remo 10
```

**Dicas:**

1. A comparadora recebe const void *: converta com
   const Time *x = a;
2. int (*cmp)(const void *, const void *) = NULL; e, no switch,
   cmp = comparar_pontos;
3. Para "mais pontos primeiro", devolva y->pontos - x->pontos.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/lista/P2726.c
```

---

**Exercício P2727** · ★★★ · O wc de bolso

Escreva um programa que grave o texto abaixo no arquivo p2727_texto.txt,
feche, e depois o leia caractere por caractere com fgetc, contando linhas
(quantidade de '\n'), palavras (sequências de não espaços) e bytes, como o
comando wc do Linux. Apague o arquivo no fim.


```text
"Bom dia\nfeira no domingo\n\ncafe com pao\n"
```



```text
Saída esperada:
linhas: 4
palavras: 8
bytes: 39
```

**Dicas:**

1. O fgetc devolve int, não char: só assim dá para diferenciar o EOF de
   um byte válido. int c; while ((c = fgetc(f)) != EOF).
2. Uma palavra começa quando c não é espaço e o anterior era espaço (ou é
   o começo). Use isspace de <ctype.h>.
3. A linha em branco conta como linha, mas não tem palavra.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/lista/P2727.c
```

---

**Exercício P2728** · ★★★ · O crivo de Eratóstenes em bits

Para achar os primos até 100, o crivo de Eratóstenes marca os múltiplos
de cada primo. Em vez de um vetor de 101 bool, use um vetor de uint32_t
em que cada bit é um número: o número k fica no bit k % 32 da palavra
k / 32. Escreva as macros ou funções para marcar e testar um bit, rode o
crivo e mostre quantos primos existem até 100, os maiores que 80 e
quantos bytes o vetor ocupou.


```text
Saída esperada:
primos até 100: 25
maiores que 80: 83 89 97
vetor de bits: 16 bytes
```

**Dicas:**

1. São 101 números: (101 + 31) / 32 = 4 palavras de 4 bytes.
2. Marcar k: v[k / 32] |= (uint32_t)1 << (k % 32). O 1 precisa ser de
   32 bits sem sinal antes de deslocar.
3. Comece o crivo em p = 2 e, para cada p não marcado, marque p * p,
   p * p + p, ... até 100.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/lista/P2728.c
```

---

**Exercício P2729** · ★★★ · O relatório de vendas com quatro bugs

O relatório abaixo compila sem nenhum aviso e roda até o fim, mas tem
quatro bugs, cada um uma pegadinha deste módulo. Três aparecem na saída; o
quarto só aparece quando a função dos dias recebe n = 0. Conserte os quatro
sem reescrever o programa e acrescente, no fim do main, a linha que chama a
função com n = 0 e mostra quantos dias ela mostrou.


```text
Saída esperada:
total: R$ 1500
comissão (5%): R$ 75
média por vendedor: R$ 500
dias de trás para a frente: 600 500 400
vendas sem nenhum dia: 0 dias
```

**Dicas:**

1. Rode antes e compare linha por linha.
2. Olhe a macro, o ?: no meio de uma soma, a ordem de / e * com inteiros
   e o laço que desce com size_t quando n é 0.
3. Depois de consertar a função dos dias, chame-a também com n = 0: ela
   não pode mostrar nada nem ler fora do vetor.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/lista/P2729.c
```

---

**Exercício P2730** · ★★★ · O extrato do Pix

Juntando tudo. Grave o extrato abaixo no arquivo p2730_pix.txt (dia;tipo;
valor em centavos;flags), leia de volta para um vetor de structs e gere o
relatório. O tipo é 'R' (recebido) ou 'E' (enviado) e vira um enum; as
flags são bits: AGENDADO = 1u << 0 e CONTESTADO = 1u << 1.


```text
1;R;250000;0
1;E;12000;0
2;E;8990;2
2;E;4500;0
3;R;3000;1
3;E;30000;0
```


Descubra quantos dias o extrato tem (o maior dia lido) e crie dois VLAs,
long saldo_dia[dias] e long gasto_dia[dias]. Mostre o saldo de cada dia,
o saldo final, o dia de maior gasto e o total contestado.


```text
Saída esperada:
dia 1: +2380.00
dia 2: -134.90
dia 3: -270.00
saldo final: R$ 1975.10
maior gasto: dia 3 (R$ 300.00)
contestadas: 1 (R$ 89.90)
```

**Dicas:**

1. Leia cada linha com fscanf(f, "%d;%c;%ld;%u", ...) e confira que
   devolveu 4.
2. Um switch sobre a letra escolhe o enum; o recebido soma e o enviado
   subtrai.
3. Os VLAs só podem ser criados depois de saber dias, e não aceitam
   = {0}: zere com um laço (ou memset).
4. Valores em centavos, num long: mostre reais com v / 100 e v % 100, ou
   com v / 100.0 e %.2f.
5. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/lista/P2730.c
```
