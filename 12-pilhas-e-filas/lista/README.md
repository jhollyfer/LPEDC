<!-- Gerado por _gerador a partir dos arquivos P????.c desta pasta. -->

# Lista prática · Módulo 12 · Pilhas e filas

30 exercícios de codificar que treinam o módulo inteiro, misturando os assuntos, no ritmo da prova do PPGI (veja [PPGI.md](../../PPGI.md)). Cada arquivo `P????.c` desta pasta é um exercício: a resposta vai dentro dele, embaixo de `// Escreva sua resposta abaixo:`. Uma resolução de cada um está em `_respostas/12-pilhas-e-filas/lista/`. Só olhe depois de tentar.

[Voltar ao módulo](../README.md)

## ★☆☆ Aquecimento

**Exercício P1201** · ★☆☆ · O painel de LEDs em binário

O painel da estação mostra números em binário. Para converter, divida por
2 até chegar a zero: os restos saem do bit menos significativo para o
mais significativo, ou seja, AO CONTRÁRIO da ordem de leitura. Uma pilha
desinverte. Escreva uma pilha de int sobre vetor (32 posições) com
empilha, desempilha e vazia, e a função


```text
void binario(int n)   // mostra n em binário, usando a pilha
```


Mostre 13, 156, 1024 e 0.


```text
Saída esperada:
13 = 1101
156 = 10011100
1024 = 10000000000
0 = 0
```

**Dicas:**

1. typedef struct { int v[32]; int n; } Pilha; com n = quantos itens. O
   topo é v[n - 1].
2. Use do { empilha(&p, n % 2); n /= 2; } while (n > 0); para o 0 também
   gerar um dígito. Depois desempilhe e mostre até a pilha ficar vazia.
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 12-pilhas-e-filas/lista/P1201.c
```

---

**Exercício P1202** · ★☆☆ · Os índices da fila circular, passo a passo

A fila do ponto de ônibus cabe num vetor de 5 posições usado em círculo,
com três campos: inicio (quem sai primeiro), fim (a próxima vaga) e n
(quantos estão na fila). Escreva insere e retira (devolvendo false quando
a fila está cheia ou vazia) e uma função que mostra o estado. Faça, nesta
ordem, mostrando o estado depois de cada uma: insere 10, 20 e 30; retira
duas vezes; insere 40, 50, 60 e 70; insere 80.


```text
Saída esperada:
insere 10: inicio=0 fim=1 n=1
insere 20: inicio=0 fim=2 n=2
insere 30: inicio=0 fim=3 n=3
retira 10: inicio=1 fim=3 n=2
retira 20: inicio=2 fim=3 n=1
insere 40: inicio=2 fim=4 n=2
insere 50: inicio=2 fim=0 n=3
insere 60: inicio=2 fim=1 n=4
insere 70: inicio=2 fim=2 n=5
insere 80: fila cheia
```

**Dicas:**

1. insere: v[fim] = x; fim = (fim + 1) % CAP; n++. retira: x =
   v[inicio]; inicio = (inicio + 1) % CAP; n--.
2. Com n você distingue cheia (n == CAP) de vazia (n == 0), mesmo quando
   inicio == fim nos dois casos.
3. Repare em "insere 50": o fim deu a volta e foi para 0. E em
   "insere 70": inicio == fim == 2 com a fila cheia.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 12-pilhas-e-filas/lista/P1202.c
```

---

**Exercício P1203** · ★☆☆ · A pilha de livros da cabeceira

Os livros da cabeceira formam uma pilha: o último que você pôs em cima é
o primeiro que pega. Escreva uma pilha ENCADEADA de livros (título e
páginas), com:


```text
Livro *empilha(Livro *topo, const char *titulo, int paginas)
Livro *desempilha(Livro *topo, char *titulo, int *paginas)
int total_paginas(const Livro *topo)
```


(empilha e desempilha devolvem o novo topo; desempilha copia o título e
as páginas do livro que saiu e libera o nó). Empilhe Dom Casmurro (256),
Vidas Secas (176) e Capitães da Areia (280), mostre o topo e o total de
páginas, e desempilhe todos, mostrando cada um.


```text
Saída esperada:
Topo: Capitães da Areia
Páginas na pilha: 712
Pegou Capitães da Areia (280 páginas)
Pegou Vidas Secas (176 páginas)
Pegou Dom Casmurro (256 páginas)
```

**Dicas:**

1. Empilhar é inserir no início da lista; desempilhar é tirar do início.
   Os dois são O(1), e a pilha não tem limite de tamanho.
2. Em desempilha, guarde o prox antes do free: ele é o novo topo.
3. Resposta esperada: a saída acima, sem vazamento.

```bash
~/LPEDC/rodar 12-pilhas-e-filas/lista/P1203.c
```

---

**Exercício P1204** · ★☆☆ · Quão fundo vão os parênteses?

A planilha aceita fórmulas com (), [] e {}. Escreva


```text
int profundidade(const char *s)
```


que confere se os delimitadores estão bem casados (com uma pilha de char
sobre vetor) e devolve a PROFUNDIDADE máxima de aninhamento, ou -1 se a
fórmula estiver mal formada. Os outros caracteres são ignorados.


```text
Saída esperada:
(a+b): 1
{[(x)]}: 3
(a)[b]{c}: 1
((1+2)*[3-(4/5)]): 3
([)]: -1
((: -1
```

**Dicas:**

1. A profundidade num instante é o tamanho da pilha. Depois de cada
   empilha, compare o tamanho com o maior visto até ali.
2. No fechamento, a pilha não pode estar vazia e o topo tem que ser o
   abre do mesmo tipo. No fim da string, a pilha tem que estar vazia.
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 12-pilhas-e-filas/lista/P1204.c
```

---

**Exercício P1205** · ★☆☆ · A fila do forno da pizzaria

Os pedidos entram no forno na ordem em que chegam. Escreva uma fila
ENCADEADA de pedidos (nome do cliente e sabor), com ponteiros para o
início e o fim, e as operações entra (no fim), sai (do início, copiando o
pedido e liberando o nó) e tamanho (guardado num campo, O(1)). Faça:
entram Ana/calabresa, Beto/marguerita e Caio/portuguesa; sai um; entra
Duda/frango; mostre o tamanho e esvazie a fila.


```text
Saída esperada:
Saiu: Ana (calabresa)
Na fila: 3 pedidos
Saiu: Beto (marguerita)
Saiu: Caio (portuguesa)
Saiu: Duda (frango)
Na fila: 0 pedidos
```

**Dicas:**

1. typedef struct { Pedido *inicio, *fim; int n; } Fila; começando com
   {NULL, NULL, 0}.
2. Quando a fila esvazia em sai, o fim também tem que voltar a NULL. Se
   não voltar, a próxima entrada escreve num nó já liberado.
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 12-pilhas-e-filas/lista/P1205.c
```

---

**Exercício P1206** · ★☆☆ · Palíndromo pelas duas pontas do deque

Um deque deixa tirar dos dois lados, e isso resolve o palíndromo: ponha
todas as letras no deque e vá tirando uma da frente e uma de trás,
comparando. Escreva um deque de char sobre vetor circular (capacidade 32)
com insere_fim, retira_inicio, retira_fim e tamanho, e


```text
bool palindromo(const char *palavra)
```


Teste com arara, osso, ovo, casa e a.


```text
Saída esperada:
arara: sim
osso: sim
ovo: sim
casa: não
a: sim
```

**Dicas:**

1. Campos: char v[32]; int inicio, n. O fim é (inicio + n) % CAP.
   retira_fim pega v[(inicio + n - 1) % CAP] e faz n--.
2. Pare quando sobrar 0 ou 1 letra: a do meio não tem par.
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 12-pilhas-e-filas/lista/P1206.c
```

---

**Exercício P1207** · ★☆☆ · A pilha de bandejas que transborda

No balcão cabem 4 bandejas. A pilha abaixo guarda as bandejas num vetor
alocado com malloc. Ela compila sem aviso, mas tem DOIS erros de
propósito, e o sanitizer acusa "heap-buffer-overflow". Um erro deixa
empilhar a 5ª bandeja (que não cabe); o outro faz desempilhar ler a
posição errada. Conserte os dois para a saída ficar:


```text
Saída esperada:
empilha 1: ok
empilha 2: ok
empilha 3: ok
empilha 4: ok
empilha 5: pilha cheia
desempilha: 4 3 2 1
```

**Dicas:**

1. Com n itens, as posições ocupadas são 0 a n - 1. Quando a pilha está
   cheia, quanto vale n? E qual é a última posição válida do vetor?
2. Onde está o topo: em v[n] ou em v[n - 1]? Decremente ANTES de ler.
3. Resposta esperada: o teste de cheia é n >= CAP (ou n == CAP), não
   n > CAP; e desempilha faz *x = v[--n], não v[n--].

```bash
~/LPEDC/rodar 12-pilhas-e-filas/lista/P1207.c
```

---

**Exercício P1208** · ★☆☆ · O jogo das bolhas de mesma cor

No joguinho do celular, as bolhas caem em fila, e duas bolhas da MESMA cor
que ficam encostadas estouram. Quando um par estoura, as vizinhas se
encostam e podem estourar também. Cada cor é uma letra. Escreva


```text
void estoura(const char *bolhas, char *sobra)
```


que usa uma pilha de char: para cada bolha, se ela é igual à do topo, o
topo sai (as duas estouram); senão, ela é empilhada. No fim, a pilha (de
baixo para cima) é o que sobrou. Teste com abbaca, aabbcc, azxxzy e abc.


```text
Saída esperada:
abbaca -> ca
aabbcc -> (nada)
azxxzy -> ay
abc -> abc
```

**Dicas:**

1. Em abbaca: a; ab; o b estoura com o b (fica a); o a estoura com o a
   (vazia); c; ca.
2. A pilha pode ser o próprio vetor sobra, com um índice n: o fundo da
   pilha é sobra[0]. No fim, sobra[n] = '\0'.
3. Resposta esperada: a saída acima. Cada bolha entra e sai no máximo uma
   vez: O(n).

```bash
~/LPEDC/rodar 12-pilhas-e-filas/lista/P1208.c
```

---

**Exercício P1209** · ★☆☆ · Por que a fila em vetor é circular

Um jeito ingênuo de fazer fila em vetor: o primeiro está SEMPRE em v[0];
para retirar, todo mundo anda uma casa para a frente. Escreva essa fila
(insere no fim, retira de v[0] deslocando os outros) contando os
deslocamentos, e a fila circular (inicio, n) contando os mesmos. Nas
duas, insira as senhas 1 a 5 e depois retire as 5, mostrando a ordem em
que saíram.


```text
Saída esperada:
Deslocando: saíram 1 2 3 4 5 com 10 deslocamentos
Circular:   saíram 1 2 3 4 5 com 0 deslocamentos
```

**Dicas:**

1. Na ingênua, retirar com n itens desloca n - 1: 4 + 3 + 2 + 1 + 0.
   Esvaziar uma fila de n itens custa n (n - 1) / 2: O(n²).
2. Na circular, retirar só anda o inicio: inicio = (inicio + 1) % CAP.
   Cada operação é O(1).
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 12-pilhas-e-filas/lista/P1209.c
```

---

**Exercício P1210** · ★☆☆ · Copiar a pilha sem virar de cabeça para baixo

O caixa quer uma CÓPIA da pilha de comandas para conferir, sem mexer na
original. Copiar desempilhando de uma e empilhando na outra inverte a
ordem. Com uma pilha AUXILIAR dá certo. Usando só as operações da pilha
encadeada abaixo (empilha, desempilha, vazia), escreva


```text
No *copia(No **original)
```


que devolve uma pilha nova com os mesmos itens na mesma ordem e deixa a
original exatamente como estava. Depois, desempilhe a cópia toda e mostre
que a original continua inteira.


```text
Saída esperada:
original (topo primeiro): 30 20 10
cópia (topo primeiro):    30 20 10
desempilhando a cópia: 30 20 10
original depois:          30 20 10
```

**Dicas:**

1. Passe tudo da original para a auxiliar (fica invertido). Depois, para
   cada item que sai da auxiliar, empilhe-o na original E na cópia.
2. A função recebe No ** porque desempilha e empilha mudam o topo da
   original.
3. Resposta esperada: a saída acima. Cada item é movido 3 vezes: O(n).

```bash
~/LPEDC/rodar 12-pilhas-e-filas/lista/P1210.c
```

## ★★☆ Para pensar

**Exercício P1211** · ★★☆ · Pós-fixa com potência (que associa à direita)

Escreva void para_posfixa(const char *in, char *out), que converte uma
expressão infixa com variáveis de UMA letra (A a Z), os operadores + - *
/ ^ e parênteses para a notação pós-fixa, com uma pilha de operadores.
A potência tem a maior precedência e associa à DIREITA: A^B^C é A^(B^C).
Os outros associam à esquerda: A-B-C é (A-B)-C.


```text
Saída esperada:
A+B*C -> ABC*+
(A+B)*C -> AB+C*
A-B-C -> AB-C-
A^B^C -> ABC^^
A*(B+C)^D -> ABC+D^*
A/B^C-D -> ABC^/D-
```

**Dicas:**

1. Letra vai direto para a saída. '(' é empilhado. ')' desempilha para a
   saída até achar o '(' (que é descartado).
2. Operador op: enquanto o topo for operador e tiver precedência MAIOR
   que op, ou IGUAL e op associar à esquerda, desempilhe para a saída.
   Depois empilhe op. Com ^ e ^ no topo, a igualdade não desempilha.
3. No fim, desempilhe tudo para a saída e termine com '\0'.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 12-pilhas-e-filas/lista/P1211.c
```

---

**Exercício P1212** · ★★☆ · Uma pilha feita com duas filas

A recíproca da fila com duas pilhas: faça uma PILHA usando só duas FILAS.
Escreva uma fila circular de int sobre vetor (capacidade 8: insere,
retira, vazia, tamanho) e, em cima dela, o tipo


```text
typedef struct { Fila a, b; } PilhaDeFilas;
```


com pdf_empilha e pdf_desempilha. Regra: a fila a guarda os itens com o
TOPO NA FRENTE. Para empilhar x, ponha x na fila b vazia, passe todos de
a para b (atrás do x) e troque os papéis de a e b. Conte quantos itens
passaram de uma fila para outra. Faça: empilha 1, 2 e 3; desempilha;
empilha 4; desempilha até esvaziar.


```text
Saída esperada:
desempilha: 3
desempilha até o fim: 4 2 1
itens movidos entre as filas: 5
```

**Dicas:**

1. Com a regra acima, desempilhar é só retirar da frente de a: O(1).
   O custo fica no empilha: O(n), porque passa a fila inteira.
2. Para trocar os papéis, troque as duas structs inteiras (Fila t = p->a;
   p->a = p->b; p->b = t;).
3. Movidos: empilha 1 move 0, empilha 2 move 1, empilha 3 move 2; depois
   de tirar o 3 sobram dois, então empilha 4 move 2: 0 + 1 + 2 + 2 = 5.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 12-pilhas-e-filas/lista/P1212.c
```

---

**Exercício P1213** · ★★☆ · A caixa-preta que guarda só as últimas leituras

A caixa-preta do caminhão guarda só as 4 últimas leituras de velocidade:
quando chega uma nova com o buffer cheio, a MAIS ANTIGA é descartada para
abrir espaço. É uma fila circular que, em vez de recusar, sobrescreve.
Escreva


```text
void registra(Buffer *b, int leitura)   // nunca falha
void mostra(const Buffer *b)            // da mais antiga à mais nova
```


e conte quantas leituras foram sobrescritas. Registre 60, 72, 80, 85, 90,
70 e 65 km/h, mostrando o buffer depois da 4ª e no fim.


```text
Saída esperada:
depois de 4: 60 72 80 85
no fim: 85 90 70 65
sobrescritas: 3
```

**Dicas:**

1. Campos: int v[4]; int inicio, n. Se n < 4, insira como numa fila
   comum. Se n == 4, grave em v[inicio] (onde está a mais antiga) e
   avance inicio: a segunda mais antiga vira a primeira.
2. Para mostrar: for (k = 0; k < n; k++) v[(inicio + k) % 4].
3. Resposta esperada: a saída acima. Cada registro é O(1), não importa
   quantas leituras já passaram.

```bash
~/LPEDC/rodar 12-pilhas-e-filas/lista/P1213.c
```

---

**Exercício P1214** · ★★☆ · O jogo das cartas nas pontas

As cartas 3, 9, 1, 2, 7 e 5 estão enfileiradas na mesa. Ana e Beto jogam
alternados, Ana primeiro: na sua vez, cada um pega a carta de UMA DAS
PONTAS, sempre a maior das duas (no empate, a da esquerda). Ponha as
cartas num deque de int sobre vetor circular e simule com primeiro,
ultimo, retira_inicio e retira_fim. Mostre cada jogada e os totais.


```text
Saída esperada:
Ana pega 5 (direita)
Beto pega 7 (direita)
Ana pega 3 (esquerda)
Beto pega 9 (esquerda)
Ana pega 2 (direita)
Beto pega 1 (esquerda)
Ana: 10 pontos, Beto: 17 pontos
```

**Dicas:**

1. primeiro(d) é v[inicio] e ultimo(d) é v[(inicio + n - 1) % CAP];
   as duas só olham, sem tirar.
2. Use int vez = 0 e troque com vez = 1 - vez a cada jogada.
3. Repare que pegar sempre a maior ponta NÃO é a melhor estratégia: Ana
   perdeu porque, ao pegar o 3, deixou o 9 para o Beto. (A estratégia
   ótima é assunto de programação dinâmica.)
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 12-pilhas-e-filas/lista/P1214.c
```

---

**Exercício P1215** · ★★☆ · Avaliar a notação PREfixa

Na notação prefixa (a polonesa original), o operador vem ANTES dos
operandos: "+ 9 * 2 3" é 9 + (2 * 3). Ela também dispensa parênteses e
também se avalia com uma pilha, só que lendo a expressão da DIREITA para
a ESQUERDA. Escreva


```text
int avalia_prefixa(const char *s, int *resultado)
```


para operandos de um dígito, operadores + - * / e espaços entre os
itens. Devolve 1 se deu certo ou 0 se a expressão é inválida (faltou
operando, sobrou operando ou divisão por zero).


```text
Saída esperada:
+ 9 * 2 3 = 15
- * 5 6 / 8 2 = 26
* + 1 2 + 3 4 = 21
- 8 3 = 5
+ 1: inválida
/ 7 0: inválida
```

**Dicas:**

1. Da direita para a esquerda: dígito, empilha. Operador: desempilha a
   (o PRIMEIRO a sair é o operando da esquerda!) e depois b, e empilha
   a op b.
2. É o contrário da pós-fixa, onde o primeiro que sai é o da direita.
   Com "- 8 3", o 3 é empilhado antes do 8, então o 8 sai primeiro.
3. No fim, a expressão é válida se sobrou exatamente 1 item.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 12-pilhas-e-filas/lista/P1215.c
```

---

**Exercício P1216** · ★★☆ · Quantos dias até esquentar?

As máximas da semana foram 28, 26, 27, 30, 25, 29 e 31 graus. Para cada
dia, quantos dias você espera até uma máxima MAIOR que a dele? (0 se não
vier nenhuma.) Com dois laços sai em O(n²). Com uma pilha de ÍNDICES sai
em O(n): a pilha guarda os dias que ainda esperam por um dia mais quente.
Escreva


```text
void espera(const int t[], int n, int resposta[], int *operacoes)
```


contando em *operacoes os empilha e desempilha.


```text
Saída esperada:
28 26 27 30 25 29 31
 3  1  1  3  1  1  0
operações na pilha: 13
```

**Dicas:**

1. Para cada dia i: enquanto a pilha não estiver vazia e t[topo] < t[i],
   desempilhe o topo j e anote resposta[j] = i - j. Depois empilhe i.
2. Quem sobrar na pilha no fim nunca viu um dia mais quente: resposta 0.
3. Cada índice é empilhado uma vez e desempilhado no máximo uma vez: até
   2n operações, por isso O(n). Aqui: 7 empilha + 6 desempilha.
4. Resposta esperada: a saída acima (cada número com "%2d" e um espaço
   entre eles).

```bash
~/LPEDC/rodar 12-pilhas-e-filas/lista/P1216.c
```

---

**Exercício P1217** · ★★☆ · Embaralhar a fila como um baralho

Para o sorteio da quadrilha junina, a fila de pares 1 a 8 deve ser
"embaralhada" como um baralho: a primeira metade intercalada com a
segunda, 1 5 2 6 3 7 4 8. Escreva


```text
void intercala_metades(Fila *f)
```


usando só insere, retira e tamanho de uma fila circular de int, mais UMA
fila auxiliar. O tamanho é sempre par.


```text
Saída esperada:
antes:  1 2 3 4 5 6 7 8
depois: 1 5 2 6 3 7 4 8
antes:  10 20 30 40
depois: 10 30 20 40
```

**Dicas:**

1. Tire a primeira metade (n / 2 itens) da fila e ponha na auxiliar.
   O que sobra na fila original é a segunda metade.
2. Depois, repita n / 2 vezes: tire um da auxiliar e ponha no fim da
   original; tire um da frente da original (da segunda metade) e ponha no
   fim dela de novo.
3. Para mostrar a fila sem destruí-la, tire e reponha cada item, n vezes.
4. Resposta esperada: a saída acima. Cada item é movido O(1) vezes: O(n).

```bash
~/LPEDC/rodar 12-pilhas-e-filas/lista/P1217.c
```

---

**Exercício P1218** · ★★☆ · A fila do lava-jato que trava

O lava-jato tem vaga para 4 carros na fila. A fila circular abaixo (com
inicio, fim e n) compila sem aviso, mas tem TRÊS erros de propósito: um
em insere e dois em retira. O resultado é que a fila "trava" e recusa
carros que cabem. Conserte os três para a saída ficar:


```text
Saída esperada:
entram 1 2 3
saem 1 2
entram 4 5 6
saem até esvaziar: 3 4 5 6
```

**Dicas:**

1. Depois de "entram 1 2 3" e "saem 1 2", sobra 1 carro e há 3 vagas.
   Acompanhe inicio, fim e n à mão (ou com um printf) e veja qual campo
   sai errado primeiro.
2. O fim precisa dar a volta no vetor, como o inicio.
3. Com a fila cheia, inicio == fim, igual à fila vazia: quem distingue os
   dois casos é o n.
4. Resposta esperada: em insere, fim = (fim + 1) % CAP; em retira, teste
   vazia com n == 0 e faça n-- ao retirar.

```bash
~/LPEDC/rodar 12-pilhas-e-filas/lista/P1218.c
```

---

**Exercício P1219** · ★★☆ · O Ctrl+Z do bloco de notas

Todo editor guarda as operações numa PILHA: desfazer é desempilhar a
última e fazer o contrário dela. Escreva um mini editor com um texto
(char[100]) e uma pilha de operações sobre vetor (até 20), em que cada
operação guarda o tipo ('D' digitou, 'A' apagou) e o pedaço de texto
envolvido:


```text
void digita(Editor *e, const char *s)  // põe s no fim e empilha {'D', s}
void apaga(Editor *e, int k)           // tira os k últimos e empilha
                                       // {'A', o que foi apagado}
bool desfaz(Editor *e)                 // false se não há o que desfazer
```


Faça: digita "Bom", digita " dia", apaga 3, digita "tarde" e depois
desfaz cinco vezes, mostrando o texto entre colchetes a cada passo.


```text
Saída esperada:
digita: [Bom]
digita: [Bom dia]
apaga:  [Bom ]
digita: [Bom tarde]
desfaz: [Bom ]
desfaz: [Bom dia]
desfaz: [Bom]
desfaz: []
desfaz: nada para desfazer
```

**Dicas:**

1. Desfazer um 'D' é apagar strlen(texto da operação) letras do fim.
   Desfazer um 'A' é colar o texto guardado de volta no fim (strcat).
2. Para guardar o que apagou: copie &e->texto[n - k] para a operação
   ANTES de pôr o '\0' em e->texto[n - k].
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 12-pilhas-e-filas/lista/P1219.c
```

---

**Exercício P1220** · ★★☆ · Um painel para dois guichês

Dois guichês do Detran emitem senhas com o horário de chegada (em minutos
depois das 8h), e cada guichê tem a sua fila, já em ordem de chegada. O
painel novo chama todo mundo numa fila ÚNICA, também por ordem de
chegada. Escreva uma fila encadeada de int (entra, sai, frente, vazia) e


```text
void junta(Fila *a, Fila *b, Fila *painel)
```


que move todos os itens de a e b para o painel, sempre o de menor horário
primeiro (no empate, o de a), usando SÓ essas quatro operações.


```text
Saída esperada:
guichê A: 5 12 20
guichê B: 7 8 25 30
painel: 5 7 8 12 20 25 30
A e B vazias: sim
```

**Dicas:**

1. frente(f) devolve o primeiro sem tirar. Enquanto as duas tiverem
   gente, compare as frentes e mova a menor. Quando uma esvaziar, mova o
   resto da outra.
2. É a intercalação de listas ordenadas, mas só com as operações da fila:
   você não enxerga os nós. Custa O(n + m).
3. Para mostrar uma fila sem perdê-la, tire e reponha cada item.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 12-pilhas-e-filas/lista/P1220.c
```

## ★★★ Desafio

**Exercício P1221** · ★★★ · O banco em que o cliente desiste

Simule a fila de uma agência com UM caixa. Cada cliente tem nome, minuto
de chegada, minutos de atendimento e TOLERÂNCIA (quantos minutos aceita
esperar). Quando o caixa fica livre, ele chama o primeiro da fila; se
esse cliente já esperou MAIS que a tolerância, ele tinha ido embora: o
caixa registra a desistência e chama o próximo, no mesmo minuto.


```text
cliente  chegada  atendimento  tolerância
Ana         0          5           10
Beto        1          3            2
Caio        2          4           10
Duda        3          2            1
Edu         8          3            5
Fabi        9          1            0
```


Use uma fila encadeada de structs e um relógio que avança de minuto em
minuto: em cada minuto, primeiro entram na fila os que chegaram, depois o
caixa (se livre) chama. Mostre cada chamada e o resumo.


```text
Saída esperada:
min 0: atende Ana (esperou 0)
min 5: Beto tinha desistido
min 5: atende Caio (esperou 3)
min 9: Duda tinha desistido
min 9: atende Edu (esperou 1)
min 12: Fabi tinha desistido
Atendidos: 3, desistências: 3
Espera média dos atendidos: 1.33 min
```

**Dicas:**

1. Guarde livre_em: o minuto em que o caixa termina o atendimento atual.
   O caixa está livre quando livre_em <= minuto.
2. Espera = minuto da chamada - chegada. Desistiu se espera > tolerância.
3. Pare quando todos tiverem chegado e a fila estiver vazia. Lembre de
   liberar cada nó que sai da fila.
4. Resposta esperada: a saída acima ((0 + 3 + 1) / 3 = 1.33).

```bash
~/LPEDC/rodar 12-pilhas-e-filas/lista/P1221.c
```

---

**Exercício P1222** · ★★★ · Calcular a infixa direto, com duas pilhas

Dá para avaliar uma expressão infixa SEM gerar a pós-fixa antes: o
algoritmo das duas pilhas usa uma pilha de VALORES (int) e uma de
OPERADORES (char). Escreva


```text
int avalia(const char *s, int *resultado)
```


para operandos de um dígito, + - * / e parênteses (sem espaços).
Devolve 1 se deu certo ou 0 se faltou operando ou houve divisão por zero.


```text
Saída esperada:
2+3*4 = 14
(2+3)*4 = 20
8-3-2 = 3
9/3/3 = 1
2*(3+4)-5 = 9
7/(2-2): erro
```

**Dicas:**

1. Escreva aplica(): tira um operador da pilha de operadores, tira b e
   depois a da pilha de valores (b sai primeiro: é o da direita) e empilha
   a op b.
2. Dígito: empilha o valor. '(': empilha. ')': aplica até achar o '(' e
   descarta o '('. Operador op: enquanto o topo for operador com
   precedência >= à de op, aplica; depois empilha op.
3. No fim, aplique o que sobrou. Deu certo se a pilha de valores ficou
   com um item só. O ">=" na dica 2 é o que faz 8-3-2 dar 3.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 12-pilhas-e-filas/lista/P1222.c
```

---

**Exercício P1223** · ★★★ · O menor caminho na feira (busca em largura)

O mapa da feira tem corredores livres ('.'), barracas ('#'), a entrada
(S) e a barraca do açaí (F). Você anda uma casa por passo, para cima,
baixo, esquerda ou direita. Qual o MENOR número de passos de S até F?
Uma FILA resolve: a partir de S, visite primeiro todas as casas a 1 passo,
depois todas a 2 passos, e assim por diante (é a busca em largura).


```text
S.#...
.##.#.
...#..
#....#
...#.F
```


Escreva o programa com uma fila circular de posições (linha, coluna), uma
matriz de distâncias (-1 = não visitada) e uma matriz de "de onde vim"
para refazer o caminho. Mostre o número de passos e o mapa com o caminho
marcado com '*' (sem apagar S e F). Na hora de visitar vizinhos, use a
ordem: cima, baixo, esquerda, direita.


```text
Saída esperada:
Menor caminho: 9 passos
S.#...
*##.#.
**.#..
#****#
...#*F
```

**Dicas:**

1. Ponha S na fila com distância 0. Enquanto a fila não esvaziar: tire
   (l, c); para cada vizinho dentro do mapa, que não é '#' e ainda não
   foi visitado, anote dist = dist[l][c] + 1, anote de onde veio e ponha
   na fila.
2. A primeira vez que uma casa é visitada já é pelo menor caminho: a fila
   garante que todas as casas a k passos saem antes das a k + 1.
3. Para marcar o caminho, ande de F para trás pelo "de onde vim" até S.
4. A fila nunca guarda a mesma casa duas vezes, então cabe com 30
   posições (5 x 6). Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 12-pilhas-e-filas/lista/P1223.c
```

---

**Exercício P1224** · ★★★ · A Torre de Hanói sem recursão

Cada pino da Torre de Hanói é uma PILHA de discos: só se mexe no disco de
cima, e nunca um disco maior sobre um menor. Há um jeito iterativo de
resolver, sem recursão nenhuma: com n ímpar, repita em ciclo os pares de
pinos (A, C), (A, B), (B, C); com n par, (A, B), (A, C), (B, C). Em cada
par, faça o ÚNICO movimento permitido entre os dois pinos (o disco menor
vai para cima do maior, ou para o pino vazio). Pare quando os n discos
estiverem em C. Escreva o programa com três pilhas de int sobre vetor,
para n = 3, numerando os movimentos.


```text
Saída esperada:
1. disco 1: A -> C
2. disco 2: A -> B
3. disco 1: C -> B
4. disco 3: A -> C
5. disco 1: B -> A
6. disco 2: B -> C
7. disco 1: A -> C
Pino C (de baixo para cima): 3 2 1
```

**Dicas:**

1. Comece com A = 3 2 1 (o 3 embaixo). topo(p) devolve o disco de cima,
   ou um número grande (como 99) se o pino está vazio: assim "mover o
   menor para cima do maior" vira uma comparação só.
2. Em cada par (x, y): se topo(x) < topo(y), mova de x para y; senão, de
   y para x.
3. São sempre 2ⁿ - 1 movimentos: 7 para n = 3. O laço pode ir até o pino
   C ter n discos.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 12-pilhas-e-filas/lista/P1224.c
```

---

**Exercício P1225** · ★★★ · Os lagos da várzea (preenchimento com pilha)

Na foto de satélite da várzea, '~' é água e '.' é terra. Um LAGO é um
grupo de casas de água ligadas por cima, baixo, esquerda ou direita.
Quantos lagos há, e de que tamanho? Varra o mapa linha por linha; ao achar
uma água ainda não visitada, "pinte" o lago inteiro com uma PILHA
explícita de posições (sem recursão), contando as casas.


```text
~~..~...
~...~~..
..~.....
.~~~..~~
......~.
~~....~.
```


Escreva o programa com uma pilha de structs Pos {linha, coluna} sobre
vetor (48 posições bastam) e uma matriz bool de visitadas. Mostre cada
lago na ordem em que foi achado e o maior.


```text
Saída esperada:
Lago 1: 3 casas (começa em 0,0)
Lago 2: 3 casas (começa em 0,4)
Lago 3: 4 casas (começa em 2,2)
Lago 4: 4 casas (começa em 3,6)
Lago 5: 2 casas (começa em 5,0)
Maior: 4 casas
```

**Dicas:**

1. Ao achar o começo: marque visitada, empilhe. Enquanto a pilha não
   esvaziar: desempilhe, conte 1 e, para cada vizinho de água ainda não
   visitado, marque e empilhe.
2. Marque como visitada NA HORA DE EMPILHAR, não ao desempilhar: assim
   nenhuma casa entra duas vezes na pilha, e 48 posições sempre bastam.
3. Essa é a busca em profundidade; trocando a pilha por uma fila vira
   busca em largura, e o número de lagos é o mesmo.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 12-pilhas-e-filas/lista/P1225.c
```

---

**Exercício P1226** · ★★★ · A triagem do pronto-socorro

No pronto-socorro, a fila não é por ordem de chegada: a classificação de
risco manda (1 vermelho, 2 laranja, 3 amarelo, 4 verde, 5 azul). Entre
pacientes da mesma cor, vale a ordem de chegada. Faça essa FILA DE
PRIORIDADE com uma lista encadeada mantida em ordem:


```text
void chega(Triagem *t, const char *nome, int cor)  // encaixa no lugar
bool atende(Triagem *t, char *nome, int *cor)      // tira o primeiro
```


Faça: chegam Ana (4), Beto (3), Caio (1) e Duda (4); mostre a fila;
atenda dois; chegam Edu (2), Fabi (5) e Gil (3); mostre a fila; atenda
todos.


```text
Saída esperada:
fila: Caio(vermelho) Beto(amarelo) Ana(verde) Duda(verde)
atende Caio (vermelho)
atende Beto (amarelo)
fila: Edu(laranja) Gil(amarelo) Ana(verde) Duda(verde) Fabi(azul)
atende Edu (laranja)
atende Gil (amarelo)
atende Ana (verde)
atende Duda (verde)
atende Fabi (azul)
```

**Dicas:**

1. Para a ordem de chegada valer no empate, o novo entra DEPOIS de todos
   os de cor menor OU IGUAL: ande enquanto p->prox->cor <= cor.
2. Atender é tirar do início: O(1). Chegar é O(n) (procura o lugar). Com
   um heap (assunto 0102) as duas ficam O(log n).
3. Um vetor de nomes de cor, indexado por cor - 1, evita um switch.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 12-pilhas-e-filas/lista/P1226.c
```

---

**Exercício P1227** · ★★★ · O verificador de fórmulas com três defeitos

O verificador de delimitadores abaixo foi escrito às pressas. Ele compila
sem aviso, mas tem TRÊS erros de propósito: recusa uma fórmula certa,
aceita uma errada e, numa terceira, o sanitizer acusa
"stack-buffer-underflow" (leitura antes do começo do vetor). Conserte os
três. Rode, compare com a saída esperada e use cada fórmula como teste de
um caso: abrir, fechar, sobrar, faltar.


```text
Saída esperada:
{[()]}: ok
([)]: erro
((: erro
()): erro
a[b{c}d]e: ok
```

**Dicas:**

1. Qual fórmula é recusada sem motivo? Que fechamento dela dá problema?
   Confira a função par, caso por caso.
2. Em "((", o laço termina sem nenhum erro. O que a pilha ainda tem? Uma
   fórmula certa termina com a pilha como?
3. Em "())", o segundo ')' chega com a pilha vazia. O que o código lê?
4. Resposta esperada: par(']') deve devolver '[' (não '{'); o return
   final deve ser n == 0; e o fechamento deve testar n == 0 (devolvendo
   false) antes de olhar pilha[n - 1].

```bash
~/LPEDC/rodar 12-pilhas-e-filas/lista/P1227.c
```

---

**Exercício P1228** · ★★★ · A calculadora da HP (RPN com comandos)

As calculadoras HP usam notação pós-fixa (RPN) e alguns comandos de
pilha. Escreva


```text
int executa(const char *programa, double *resultado, char *erro)
```


que lê os itens separados por espaço (números reais, + - * / e os
comandos dup, swap e drop), usa uma pilha de double sobre vetor e, no
fim, exige que sobre exatamente um número. Devolve 1 se deu certo, ou 0
e uma mensagem em erro.


```text
dup: duplica o topo     swap: troca os dois de cima     drop: descarta o topo
```



```text
Saída esperada:
3 4 + 2 * => 14
5 dup * => 25
10 2 swap - => -8
1 2 3 drop + => 3
1.5 2.5 + 2 / => 2
4 0 / => erro: divisão por zero
2 + => erro: faltam operandos
7 8 => erro: sobraram 2 números
```

**Dicas:**

1. Separe os itens com um laço que copia os caracteres até o próximo
   espaço (ou o '\0') para um vetor char item[32].
2. É número se começa com dígito, ou com '-' ou '.' seguido de dígito;
   converta com atof. Compare os comandos com strcmp.
3. Antes de cada operação, confira se a pilha tem itens suficientes: 2
   para + - * / e swap, 1 para dup e drop.
4. Mostre o resultado com "%g". Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 12-pilhas-e-filas/lista/P1228.c
```

---

**Exercício P1229** · ★★★ · De quem é a vez no Uno?

Ana, Bia, Caio e Davi jogam Uno, sentados nessa ordem em roda. A vez anda
no sentido horário até alguém jogar "inverte" (a vez passa a andar no
sentido contrário) ou "pula" (o próximo perde a vez). Guarde os jogadores
num DEQUE (vetor circular de int, com os índices dos nomes) em que o da
FRENTE é quem joga agora:


```text
- andar no horário: tire da frente e ponha no fim;
- andar no anti-horário: tire do fim e ponha na frente.
```


As cartas jogadas, uma por vez, são: normal, normal, inverte, normal,
pula, normal, inverte, normal. Mostre cada jogada e de quem é a vez
depois dela.


```text
Saída esperada:
Ana joga normal; vez de Bia
Bia joga normal; vez de Caio
Caio joga inverte; vez de Bia
Bia joga normal; vez de Ana
Ana joga pula; vez de Caio
Caio joga normal; vez de Bia
Bia joga inverte; vez de Caio
Caio joga normal; vez de Davi
```

**Dicas:**

1. Com o deque [Ana Bia Caio Davi] e a vez no horário, "andar" deixa
   [Bia Caio Davi Ana]. No anti-horário, deixa [Davi Ana Bia Caio].
2. inverte: troque o sentido e ande uma vez (no sentido novo). pula: ande
   duas vezes. normal: ande uma vez.
3. Por que um deque: no horário você mexe nas duas pontas de um jeito, no
   anti-horário do outro. Uma fila só não dá conta do segundo caso.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 12-pilhas-e-filas/lista/P1229.c
```

---

**Exercício P1230** · ★★★ · O expediente da lotérica com arquivo de log

Junte filas com arquivos (módulo 09). Às 8h, seis clientes já estão na
fila da lotérica, cada um com senha, tipo (A aposta, B boleto, S saque)
e minutos de atendimento:


```text
1 B 3   2 A 1   3 B 4   4 A 2   5 S 5   6 A 1
```


1. Ponha as senhas numa fila circular de structs (capacidade 8).
2. Atenda em ordem com um caixa só, começando no minuto 0, e grave cada

```text
 atendimento como uma linha "senha tipo inicio fim" em
 /tmp/p1230_log.txt.
```

3. Feche o log, reabra para leitura e, só com o que está no arquivo

```text
 (fscanf), monte o relatório: quantos atendimentos e quantos minutos de
 cada tipo, a espera média (o "inicio" de cada um) e o minuto em que o
 expediente terminou. Apague o log no fim.
```



```text
Saída esperada:
Log gravado: 6 linhas
Apostas: 3 (4 min)
Boletos: 2 (7 min)
Saques: 1 (5 min)
Espera média: 6.67 min
Fim do atendimento: minuto 16
```

**Dicas:**

1. Os atendimentos vão de 0 a 3, 3 a 4, 4 a 8, 8 a 10, 10 a 15 e 15 a 16.
   O fim de um é o início do próximo.
2. Leia o log com while (fscanf(arq, "%d %c %d %d", ...) == 4). O espaço
   antes do %c pula o separador.
3. O relatório não usa a fila: a fila só existe durante o expediente; o
   log é o que sobra depois. Espera média = (0 + 3 + 4 + 8 + 10 + 15) / 6.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 12-pilhas-e-filas/lista/P1230.c
```
