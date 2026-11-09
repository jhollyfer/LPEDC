<!-- Gerado por _gerador a partir dos arquivos P????.c desta pasta. -->

# Lista prática · Módulo 24 · Busca de padrões em texto

30 exercícios de codificar que treinam o módulo inteiro, misturando os assuntos, no ritmo da prova do PPGI (veja [PPGI.md](../../PPGI.md)). Cada arquivo `P????.c` desta pasta é um exercício: a resposta vai dentro dele, embaixo de `// Escreva sua resposta abaixo:`. Uma resolução de cada um está em `_respostas/24-busca-de-padroes/lista/`. Só olhe depois de tentar.

[Voltar ao módulo](../README.md)

## ★☆☆ Aquecimento

**Exercício P2401** · ★☆☆ · O último Pix do extrato

O extrato do dia veio numa linha só:


```text
"pix 50; boleto 120; pix 35; ted 900; pix 18; tarifa 12"
```


Você quer o ÚLTIMO lançamento de cada tipo. Escreva do zero
int ultima(const char *texto, const char *padrao, int *alinhamentos): a
força bruta andando de trás para a frente (i de n - m até 0), que devolve
a posição da última ocorrência (ou -1) e conta os alinhamentos testados.
Procure "pix", "ted" e "doc" e mostre as 10 letras a partir da posição
achada com "%.10s".


```text
Saída esperada:
pix: última em 37 -> "pix 18; ta" (15 alinhamentos)
ted: última em 28 -> "ted 900; p" (24 alinhamentos)
doc: não aparece (52 alinhamentos)
```

**Dicas:**

1. Andando de trás para a frente, a primeira ocorrência que aparece é a
   última do texto: pode devolver na hora.
2. Quando o padrão não aparece, são testados todos os n - m + 1
   alinhamentos.
3. Resposta esperada: "pix" na posição 37 depois de 15 alinhamentos;
   "doc" não aparece (52 alinhamentos, o texto tem 54 letras).

```bash
~/LPEDC/rodar 24-busca-de-padroes/lista/P2401.c
```

---

**Exercício P2402** · ★☆☆ · Quantos kk tem a risada

A mensagem no grupo foi "kkkkk ri muito kkk". Quantos "kk" tem nela?
Depende: contando sobrepostas (como a busca de padrões conta) ou não
(como quem risca o texto e não reaproveita letra). Escreva do zero
int conta(texto, padrao, pulo_inteiro), que usa strstr num laço: depois
de cada achado, avança 1 letra (pulo_inteiro = 0) ou o tamanho do padrão
(pulo_inteiro = 1). Conte "kk" e "kkk" dos dois jeitos.


```text
Saída esperada:
"kk" com sobreposição: 6
"kk" sem sobreposição: 3
"kkk" com sobreposição: 4
"kkk" sem sobreposição: 2
```

**Dicas:**

1. strstr(p, padrao) devolve o ponteiro para a primeira ocorrência a
   partir de p, ou NULL. Continue a partir de p + 1 ou p + strlen(padrao).
2. Num bloco de r letras k, há r - m + 1 ocorrências sobrepostas e
   r / m sem sobrepor.
3. Resposta esperada: "kk" dá 6 e 3; "kkk" dá 4 e 2.

```bash
~/LPEDC/rodar 24-busca-de-padroes/lista/P2402.c
```

---

**Exercício P2403** · ★☆☆ · A borda de cada prefixo

A tabela π é difícil de ler só com números. O programa abaixo já
calcula pi[] de uma palavra. Estenda a função mostra: para cada j,
mostre o índice (%2d), o prefixo p[0..j] alinhado à esquerda numa
coluna da largura da palavra, o valor de pi[j] e, quando ele não é zero,
a borda: o prefixo de tamanho pi[j], que também é o fim de p[0..j].
Teste com "tatuta" e "aabaaab".


```text
Saída esperada:
tatuta
   0 t      pi = 0
   1 ta     pi = 0
   2 tat    pi = 1  borda "t"
   3 tatu   pi = 0
   4 tatut  pi = 1  borda "t"
   5 tatuta pi = 2  borda "ta"
aabaaab
   0 a       pi = 0
   1 aa      pi = 1  borda "a"
   2 aab     pi = 0
   3 aaba    pi = 1  borda "a"
   4 aabaa   pi = 2  borda "aa"
   5 aabaaa  pi = 2  borda "aa"
   6 aabaaab pi = 3  borda "aab"
```

**Dicas:**

1. "%.*s" mostra só as primeiras letras: printf("%.*s", j + 1, p). Com
   "%-*.*s" você ainda escolhe a largura: printf("%-*.*s", m, j + 1, p).
2. Em "aabaaa" a borda é "aa", e não "aaa": a borda é um prefixo
   PRÓPRIO que termina no fim, e "aaa" não é prefixo de "aabaaa".
3. Resposta esperada: a última linha de "aabaaab" tem pi = 3 e borda
   "aab".

```bash
~/LPEDC/rodar 24-busca-de-padroes/lista/P2403.c
```

---

**Exercício P2404** · ★☆☆ · Onde aparece o CEP

A mensagem do cliente tem três CEPs. Complete
int kmp_primeira(t, p, &comparacoes): o KMP que para na PRIMEIRA
ocorrência e devolve a posição dela (ou -1), contando cada comparação
t[i] com p[k], inclusive as que acontecem nos recuos. A calcula_pi já
está pronta.


```text
Saída esperada:
69060-001: posição 39, 49 comparações
69061-000: posição 52, 65 comparações
69000-000: posição -1, 67 comparações
```

**Dicas:**

1. Escreva a comparação num laço só, para não contar duas vezes:
   for (;;) { conta; se t[i] == p[k], k++ e sai; se k == 0, sai;
   senão k = pi[k - 1]; }.
2. A ocorrência termina em i quando k chega a m: ela começa em i - m + 1.
3. Resposta esperada: 69060-001 na posição 39 (49 comparações); o
   69000-000 não aparece, com 67 comparações num texto de 61 letras:
   o KMP nunca passa de 2n.

```bash
~/LPEDC/rodar 24-busca-de-padroes/lista/P2404.c
```

---

**Exercício P2405** · ★☆☆ · Quanto o Horspool pula

No cardápio da barraca de comida regional, quanto maior o padrão, maior
o salto do Horspool. Complete horspool(t, p, &alinhamentos), que conta
as ocorrências e os alinhamentos testados (a tabela de saltos já está
pronta). Procure "pa", "pato" e "tapioca de coco" no texto do main.


```text
Saída esperada:
texto com 73 letras
pa               m =  2: 1 ocorrência(s), 37 alinhamentos
pato             m =  4: 1 ocorrência(s), 21 alinhamentos
tapioca de coco  m = 15: 1 ocorrência(s),  8 alinhamentos
```

**Dicas:**

1. Em cada alinhamento i, compare de j = m - 1 para trás. Achando ou
   não, avance i += salto[(unsigned char)t[i + m - 1]].
2. Com m = 2 o salto máximo é 2: quase metade das posições é testada.
   Com m = 15 o salto chega a 15.
3. Resposta esperada: 37, 21 e 8 alinhamentos, uma ocorrência de cada.

```bash
~/LPEDC/rodar 24-busca-de-padroes/lista/P2405.c
```

---

**Exercício P2406** · ★☆☆ · A janela que rola pelo código de barras

O código de barras do pacote de café é "7891000315507". Escreva do zero
um programa que mostra o hash (base 10, módulo Q = 97) de cada janela de
4 dígitos, mas calculando do zero SÓ a primeira: as outras saem rolando,
tirando o dígito da esquerda e pondo o da direita.


```text
Saída esperada:
0: 7891 -> 34
1: 8910 -> 83
2: 9100 -> 79
3: 1000 -> 30
4: 0003 ->  3
5: 0031 -> 31
6: 0315 -> 24
7: 3155 -> 51
8: 1550 -> 95
9: 5507 -> 75
```

**Dicas:**

1. Calcule antes pot = 10^(m-1) mod Q (com m = 4, pot = 1000 % 97 = 30).
2. Rolar: h = (h - esquerda * pot % Q + Q) % Q e depois
   h = (h * 10 + direita) % Q. O "+ Q" evita resto negativo.
3. Resposta esperada: a janela 0003 dá 3, e a última, 5507, dá 75
   (5507 = 56 × 97 + 75).

```bash
~/LPEDC/rodar 24-busca-de-padroes/lista/P2406.c
```

---

**Exercício P2407** · ★☆☆ · A frase que lê dos dois lados

Escreva do zero bool palindromo(const char *s), que diz se a frase é
palíndromo ignorando os espaços e a diferença entre maiúsculas e
minúsculas. Use dois índices, um em cada ponta, andando um para o outro
(sem copiar a frase). Teste as cinco frases do esqueleto, mostrando cada
uma com "%-40s".


```text
Saída esperada:
Socorram me subi no onibus em Marrocos   sim
A base do teto desaba                    sim
Roma me tem amor                         sim
Bom dia Manaus                           não
ovo                                      sim
```

**Dicas:**

1. i = 0 e j = strlen(s) - 1. Enquanto i < j: espaço em s[i], i++;
   espaço em s[j], j--; senão compare tolower dos dois.
2. tolower recebe um unsigned char convertido para int: tolower(
   (unsigned char)s[i]).
3. Resposta esperada: só "Bom dia Manaus" não é palíndromo.

```bash
~/LPEDC/rodar 24-busca-de-padroes/lista/P2407.c
```

---

**Exercício P2408** · ★☆☆ · O filtro do grupo da família

O grupo da família tem um filtro: cada palavra proibida vira asteriscos,
letra por letra, na própria mensagem. Escreva do zero
int censura(char *texto, const char *palavra), uma força bruta que troca
cada ocorrência por '*' e devolve quantas achou. Rode para "droga",
"saco" e "chato", uma depois da outra, e mostre a mensagem final.


```text
Saída esperada:
droga: 2
saco: 1
chato: 0
que *****, perdi o onibus de novo, ***** de chuva, que ****
```

**Dicas:**

1. A mensagem precisa estar num vetor (char msg[] = "..."), não num
   ponteiro para literal: literal não pode ser alterado.
2. Ao achar em i, troque texto[i] até texto[i + m - 1] por '*'.
3. Resposta esperada: droga 2, saco 1, chato 0.

```bash
~/LPEDC/rodar 24-busca-de-padroes/lista/P2408.c
```

---

**Exercício P2409** · ★☆☆ · A batida que se repete

O professor de percussão escreve as batidas como palavras. O PERÍODO
de uma palavra é o tamanho do menor pedaço que, repetido (o último pode
ficar pela metade), forma a palavra inteira. A tabela π dá o período de
graça: periodo = m - pi[m - 1]. Escreva o programa do zero (pode copiar
a calcula_pi do assunto 0158): mostre o período e o pedaço de cada
batida e, quando o pedaço cabe um número inteiro de vezes (e mais de
uma), quantas.


```text
Batidas: "tumtatumtatumta", "tumtumpa", "abcabcab", "xxxxxx", "samba"
```



```text
Saída esperada:
tumtatumtatumta  período  5 ("tumta"), repete 3 vezes inteiras
tumtumpa         período  8 ("tumtumpa")
abcabcab         período  3 ("abc")
xxxxxx           período  1 ("x"), repete 6 vezes inteiras
samba            período  5 ("samba")
```

**Dicas:**

1. A maior borda b tem a propriedade: p[j] == p[j + m - b] para todo j.
   Por isso a palavra "anda" de m - b em m - b.
2. "abcabcab" tem período 3 mas não é "abc" repetido inteiro: 8 não é
   múltiplo de 3.
3. Resposta esperada: tumtatumtatumta tem período 5 e repete 3 vezes;
   xxxxxx, período 1, 6 vezes.

```bash
~/LPEDC/rodar 24-busca-de-padroes/lista/P2409.c
```

---

**Exercício P2410** · ★☆☆ · O letreiro que gira

O letreiro do ônibus mostra "030 CENTRO " e gira 3 letras para a
esquerda a cada passo. Escreva do zero gira(s, k), que roda a string k
casas para a esquerda NO PRÓPRIO VETOR, sem vetor auxiliar, com o
truque das três inversões: inverta s[0..k-1], depois s[k..n-1], depois a
string inteira. Mostre o letreiro entre colchetes antes e depois de cada
um de 4 passos. Por fim gire "ABCDE" 12 casas.


```text
Saída esperada:
[030 CENTRO ]
[ CENTRO 030]
[NTRO 030 CE]
[O 030 CENTR]
[30 CENTRO 0]
ABCDE girado 12: CDEAB
```

**Dicas:**

1. Escreva antes inverte(s, i, j), que troca s[i] com s[j] e anda até
   os índices se cruzarem.
2. Girar n casas é não girar: use k %= n antes.
3. Resposta esperada: depois do 4º passo, [30 CENTRO 0]; ABCDE girado
   12 vira CDEAB (12 % 5 = 2).

```bash
~/LPEDC/rodar 24-busca-de-padroes/lista/P2410.c
```

## ★★☆ Para pensar

**Exercício P2411** · ★★☆ · A tabela π atrasada

Ache o bug. O KMP abaixo conta o refrão "tumtum" na batucada e "abab"
numa sequência, mas perde as ocorrências que se sobrepõem. A tabela π
sai errada; o resto do KMP está certo:


```text
Saída que aparece:
pi de tumtum: 0 0 0 0 1 2
  achou em 0
  achou em 11
total: 2
pi de abab: 0 0 0 1
  achou em 0
  achou em 4
total: 2
```


O erro está na ordem de duas linhas da calcula_pi. Conserte.


```text
Saída esperada:
pi de tumtum: 0 0 0 1 2 3
  achou em 0
  achou em 3
  achou em 11
total: 3
pi de abab: 0 0 1 2
  achou em 0
  achou em 2
  achou em 4
total: 3
```

**Dicas:**

1. Calcule à mão o pi de "abab": pi[2] tem que ser 1 ("a") e pi[3], 2
   ("ab"). Cada valor errado é exatamente 1 a menos que o certo.
2. pi[j] é a borda de p[0..j], que inclui a letra j. A borda só fica
   certa DEPOIS de testar se p[j] estende a borda anterior.
3. Resposta esperada: grave pi[j] = k depois do if que faz k++; saem 3
   ocorrências em cada busca.

```bash
~/LPEDC/rodar 24-busca-de-padroes/lista/P2411.c
```

---

**Exercício P2412** · ★★☆ · Os alarmes falsos do Rabin-Karp

Escreva do zero int busca(t, p, q, mostrar): o Rabin-Karp com base 256 e
módulo q, que conta as ocorrências e os FALSOS POSITIVOS (hash igual,
letras diferentes) e, quando mostrar é 1, mostra cada falso positivo com
a posição e a janela. Procure "roma" na frase do main com q = 11, 101 e
1009.


```text
Saída esperada:
  falso positivo em  3: "ato "
  falso positivo em  9: "eu a"
  falso positivo em 16: "upa "
  falso positivo em 27: "de r"
  falso positivo em 37: "a ra"
q =   11: 1 ocorrência(s), 5 falso(s) positivo(s)
  falso positivo em 37: "a ra"
q =  101: 1 ocorrência(s), 1 falso(s) positivo(s)
q = 1009: 1 ocorrência(s), 0 falso(s) positivo(s)
```

**Dicas:**

1. Use (unsigned char) em cada letra e o "+ q" ao tirar a letra da
   esquerda, para o resto não ficar negativo.
2. Com q = 11 só existem 11 hashes possíveis: uma janela qualquer bate
   com o padrão por acaso cerca de 1 vez em 11.
3. Resposta esperada: 5 falsos positivos com q = 11, 1 com q = 101
   ("a ra", na posição 37) e nenhum com q = 1009.

```bash
~/LPEDC/rodar 24-busca-de-padroes/lista/P2412.c
```

---

**Exercício P2413** · ★★☆ · O colar girado

Um colar de contas coloridas pode ser lido a partir de qualquer conta.
b é uma ROTAÇÃO de a quando girar a algumas casas para a esquerda dá b.
O truque: b é rotação de a se e só se b aparece dentro de a + a. Escreva
giros(a, b), que monta a + a e usa o KMP para mostrar TODOS os k
(0 <= k < n) em que girar a k casas dá b, e devolve quantos são. Copie
a calcula_pi do assunto 0158.


```text
Saída esperada:
azulverdeazulverde -> verdeazulverdeazul: 4 13 (2 giro(s))
amarelopreto -> pretoamarelo: 7 (1 giro(s))
rosabranco -> brancoroxa: não é rotação (0 giro(s))
ouroouroouro -> ouroouroouro: 0 4 8 (3 giro(s))
```

**Dicas:**

1. Uma ocorrência que termina em i começa em i - n + 1. Só valem as que
   começam antes de n: percorra i de 0 até 2n - 2.
2. Se os tamanhos forem diferentes, já não é rotação. Use snprintf para
   montar a + a num vetor de 128.
3. Resposta esperada: azulverdeazulverde vira o outro com 4 ou 13 giros;
   ouroouroouro, com 0, 4 ou 8; rosabranco não vira brancoroxa.

```bash
~/LPEDC/rodar 24-busca-de-padroes/lista/P2413.c
```

---

**Exercício P2414** · ★★☆ · O mesmo colar visto de outro ponto

A artesã anota cada colar de miçangas pelas cores (A azul, B branca,
V vermelha) a partir de uma conta qualquer. Dois registros são o mesmo
colar se um é rotação do outro. Para agrupar, use a FORMA CANÔNICA: a
menor rotação em ordem alfabética. Escreva:
- menor_rotacao(s), que compara as n rotações letra a letra, dando a

```text
volta com (k + j) % n, sem montar nenhuma string, e devolve o início
da menor;
```

- canonica(s, saida), que escreve essa rotação em saida.
Mostre a forma de cada colar do main e os grupos de colares iguais.


```text
Saída esperada:
VAAVB -> AAVBV
AVBVA -> AAVBV
BAVAV -> AVAVB
VBVAA -> AAVBV
AVAVB -> AVAVB
ABAVV -> ABAVV
Colar 1: VAAVB AVBVA VBVAA
Colar 2: BAVAV AVAVB
Colar 3: ABAVV
```

**Dicas:**

1. Para comparar as rotações k e melhor, avance j enquanto
   s[(k + j) % n] == s[(melhor + j) % n]; a primeira diferença decide.
2. Força bruta O(n²): para colares pequenos está ótimo. Os grupos saem
   comparando as formas com strcmp.
3. Resposta esperada: 3 colares diferentes: VAAVB, AVBVA e VBVAA são o
   mesmo (forma AAVBV).

```bash
~/LPEDC/rodar 24-busca-de-padroes/lista/P2414.c
```

---

**Exercício P2415** · ★★☆ · O Horspool que confunde bolo com rolo

Ache o bug. A padaria procura "bolo" e "de" no quadro de avisos, mas o
Horspool abaixo acha coisas demais:


```text
Saída que aparece:
  bolo em 0
  bolo em 8
  bolo em 14
  bolo em 33
  bolo em 46
bolo: 5
  de em 5
  de em 19
  de em 27
de: 3
```


Na posição 8 está "rolo" e na 33, "tolo". O erro está na comparação de
cada alinhamento (duas linhas). Conserte.


```text
Saída esperada:
  bolo em 0
  bolo em 14
  bolo em 46
bolo: 3
  de em 5
  de em 19
de: 2
```

**Dicas:**

1. Para qual j o laço de comparação para? A letra p[0] chega a ser
   comparada alguma vez?
2. O Horspool compara da direita para a esquerda até j passar do começo:
   j >= 0. Achou quando todas bateram, ou seja, j < 0.
3. Resposta esperada: bolo 3, de 2.

```bash
~/LPEDC/rodar 24-busca-de-padroes/lista/P2415.c
```

---

**Exercício P2416** · ★★☆ · O maior palíndromo escondido

Dentro de "bananas" está o palíndromo "anana". Escreva do zero
maior(s), que acha o MAIOR trecho palíndromo da palavra pela expansão
ao redor do centro: cada palíndromo tem um centro, que é uma letra
(tamanho ímpar) ou o espaço entre duas letras (tamanho par). Para cada
um dos 2n - 1 centros, abra as pontas enquanto forem iguais. Em empate,
fica o primeiro achado.


```text
Saída esperada:
bananas          "anana" (posição 1, 5 letra(s))
paralelepipedo   "epipe" (posição 7, 5 letra(s))
arrozzorra       "arrozzorra" (posição 0, 10 letra(s))
abcd             "a" (posição 0, 1 letra(s))
osso             "osso" (posição 0, 4 letra(s))
sopapos          "sopapos" (posição 0, 7 letra(s))
```

**Dicas:**

1. expande(s, n, e, d) abre e-- e d++ enquanto s[e] == s[d] e devolve
   d - e - 1. Chame com (c, c) e com (c, c + 1).
2. Um palíndromo de tamanho t centrado em c começa em c - t / 2 (ímpar)
   ou c - t / 2 + 1 (par). Mostre com printf("%-16s ...") e "%.*s".
3. Resposta esperada: paralelepipedo esconde "epipe"; arrozzorra,
   osso e sopapos são palíndromos inteiros.

```bash
~/LPEDC/rodar 24-busca-de-padroes/lista/P2416.c
```

---

**Exercício P2417** · ★★☆ · Várias palavras numa passada

O Rabin-Karp tem uma vantagem quando há MUITOS padrões do mesmo tamanho:
a janela rola uma vez só pelo texto, e cada hash é comparado com os
hashes de todos os padrões. Escreva o programa do zero: base 256,
Q = 1000003, padrões "caju", "acai", "cedo" e "doce" no texto do
esqueleto. Mostre cada ocorrência na ordem do texto, o total de cada
padrão e quantas conferências letra a letra foram feitas.


```text
Saída esperada:
caju em 12
acai em 35
caju em 43
cedo em 67
caju: 2
acai: 1
cedo: 1
doce: 0
Janelas: 68; conferências letra a letra: 4
```

**Dicas:**

1. Calcule os quatro hp[] antes do laço. Para cada janela, percorra os
   padrões; só com ht == hp[p] faça o strncmp.
2. Use long long nas contas: 1000002 × 256 passa do limite de um int
   de 32 bits.
3. Resposta esperada: caju 2, acai 1, cedo 1, doce 0; só 4 conferências
   em 68 janelas (nenhum falso positivo).

```bash
~/LPEDC/rodar 24-busca-de-padroes/lista/P2417.c
```

---

**Exercício P2418** · ★★☆ · O KMP passo a passo

O programa abaixo procura "abab" em "abaababcabab" com o KMP, mas não
mostra nada. Instrumente-o: para cada i, mostre t[i], o k antes de ler a
letra, o k depois e, quando houver recuo pela tabela, os valores que k
assumiu em cada recuo. Marque as ocorrências. É o teste de mesa que a
prova pede.


```text
Saída esperada:
 i t[i] k antes k depois
 0   a       0        1
 1   b       1        2
 2   a       2        3
 3   a       3        1  recuou para 1 0
 4   b       1        2
 5   a       2        3
 6   b       3        4  <- achou em 3
 7   c       2        0  recuou para 0
 8   a       0        1
 9   b       1        2
10   a       2        3
11   b       3        4  <- achou em 8
```

**Dicas:**

1. Guarde os recuos num vetor durante o while e mostre depois do printf
   principal, com printf("%2d   %c %7d %8d", i, t[i], antes, k).
2. Na letra 3 ('a'), k estava em 3 (lido "aba") e esperava 'b': recua
   para pi[2] = 1, ainda não bate, recua para 0, e aí 'a' bate: k = 1.
3. Resposta esperada: ocorrências em 3 e 8; a única outra linha com
   recuo é a do 'c', de 2 para 0.

```bash
~/LPEDC/rodar 24-busca-de-padroes/lista/P2418.c
```

---

**Exercício P2419** · ★★☆ · Anagramas escondidos

Na frase "a roma de amor e o ramo de mora", quantos trechos de 4 letras
são anagramas de "amor" (as mesmas letras, em qualquer ordem)? Escreva
do zero com uma janela deslizante de CONTAGENS: quer[c] conta as letras
do padrão e janela[c] as da janela atual; a cada passo, sai uma letra
pela esquerda e entra outra pela direita. Mostre a posição e o trecho de
cada anagrama e o total.


```text
Saída esperada:
 2: roma
10: amor
19: ramo
27: mora
Anagramas de "amor": 4
```

**Dicas:**

1. Use vetores de 256 posições indexados por (unsigned char). Monte a
   primeira janela com as m primeiras letras.
2. Comparar os dois vetores custa 256 por janela, mas não depende de m:
   a busca toda é O(256 n), e não O(n m · m).
3. Resposta esperada: roma, amor, ramo e mora, nas posições 2, 10, 19 e
   27.

```bash
~/LPEDC/rodar 24-busca-de-padroes/lista/P2419.c
```

---

**Exercício P2420** · ★★☆ · Quantos trechos diferentes no DNA

Quantos trechos DIFERENTES de tamanho m existem no DNA
"ACGTACGTTACGAACGT"? Escreva distintos(dna, m) do zero com hash rolante:
A, C, G e T valem 0, 1, 2 e 3, base B = 4 e módulo Q = 101. Para cada
janela, compare o hash com o dos trechos já guardados; só se o hash for
igual, confira as letras com strncmp (conte essas conferências). Trecho
novo é guardado (hash e início) e mostrado. Rode com m = 3 e m = 4.


```text
Saída esperada:
m = 3: ACG CGT GTA TAC GTT TTA CGA GAA AAC
  9 diferentes em 15 janelas, 6 conferências
m = 4: ACGT CGTA GTAC TACG CGTT GTTA TTAC ACGA CGAA GAAC AACG
  11 diferentes em 14 janelas, 3 conferências
```

**Dicas:**

1. Guarde num vetor hash_de[] e inicio[] (64 posições bastam).
2. Cada janela repetida gera pelo menos uma conferência (a que acha o
   igual); hash igual de trecho diferente também conferiria.
3. Resposta esperada: 9 diferentes de tamanho 3 (6 conferências) e 11 de
   tamanho 4 (3 conferências).

```bash
~/LPEDC/rodar 24-busca-de-padroes/lista/P2420.c
```

## ★★★ Desafio

**Exercício P2421** · ★★★ · A senha do cofre

No jogo de enigmas, a senha do cofre está escondida na dica: é o MAIOR
trecho que, ao mesmo tempo, começa a dica, termina a dica e aparece no
meio dela (uma ocorrência que não é nem a do começo nem a do fim). Se
não houver, não há senha. Escreva int senha(const char *s), em O(m),
com a tabela π:
- os candidatos são as bordas do texto inteiro: pi[m-1], depois

```text
pi[pi[m-1] - 1], e assim por diante;
```

- um candidato de tamanho L aparece no meio se algum pi[j], com

```text
1 <= j <= m - 2, é pelo menos L.
```



```text
Saída esperada:
fixprefixsuffix  senha "fix"
abcdabc          sem senha
aaaa             senha "aa"
papapapa         senha "papa"
araraquara       senha "ara"
```

**Dicas:**

1. Guarde meio = o maior pi[j] para j de 1 a m - 2. Desça pela cadeia de
   bordas enquanto L > meio.
2. Se pi[j] >= L, o prefixo de tamanho L termina em j (é borda de uma
   borda): logo ele aparece terminando antes do fim.
3. Resposta esperada: fixprefixsuffix dá "fix"; abcdabc não tem senha
   ("abc" é prefixo e sufixo, mas não aparece no meio); papapapa dá
   "papa".

```bash
~/LPEDC/rodar 24-busca-de-padroes/lista/P2421.c
```

---

**Exercício P2422** · ★★★ · Um hash ou dois

Um módulo pequeno dá muitos falsos positivos. Trocar por um módulo
grande é uma saída; outra é usar DOIS hashes com módulos pequenos e
diferentes: a janela só é conferida letra a letra se os dois baterem.
Escreva o programa do zero:
- gere um DNA de 3000 letras com o gerador fixo

```text
estado = estado * 1103515245u + 12345u (estado começa em 2026) e a
letra "ACGT"[(estado >> 16) % 4];
```

- o padrão são as 6 letras a partir da posição 1500;
- role as janelas com base 4 (A=0, C=1, G=2, T=3) e dois hashes, módulos

```text
97 e 89, e conte os falsos positivos do primeiro hash sozinho e dos
dois juntos.
```



```text
Saída esperada:
padrão: CGTCAA
janelas: 2995, ocorrências: 1
falsos positivos com um hash (q = 97): 32
falsos positivos com dois hashes (q = 97 e 89): 0
```

**Dicas:**

1. Um vetor val[256] com val['C'] = 1, val['G'] = 2, val['T'] = 3 evita
   um if por letra.
2. Com dois módulos primos diferentes, bater nos dois é como bater num
   módulo 97 × 89 = 8633: a chance cai de 1/97 para 1/8633.
3. Resposta esperada: o padrão é CGTCAA, 1 ocorrência, 32 falsos
   positivos com um hash e nenhum com os dois.

```bash
~/LPEDC/rodar 24-busca-de-padroes/lista/P2422.c
```

---

**Exercício P2423** · ★★★ · A mensagem em pedaços

O áudio virou texto em pedaços que se repetem nas pontas:


```text
"o rato roe", "roeu a rou", "a roupa do rei", "rei de roma",
"roma inteira"
```


Junte os pedaços em ordem, colando cada um com a MAIOR sobreposição: o
maior sufixo do que já foi montado que também é prefixo do pedaço novo.
O truque: essa sobreposição é a borda (π da última letra) da string
pedaço + '#' + montado. O '#' não aparece nos textos, então a borda não
passa dele. Escreva sobreposicao(a, b) com a calcula_pi e monte a
mensagem, mostrando quanto cada pedaço sobrepôs.


```text
Saída esperada:
"roeu a rou" sobrepõe 3: "roe"
"a roupa do rei" sobrepõe 5: "a rou"
"rei de roma" sobrepõe 3: "rei"
"roma inteira" sobrepõe 4: "roma"
Mensagem: o rato roeu a roupa do rei de roma inteira
```

**Dicas:**

1. Monte junto com snprintf(junto, sizeof junto, "%s#%s", b, a).
2. Depois de achar s, cole só o resto: strcat(msg, pedaco + s).
3. Resposta esperada: o rato roeu a roupa do rei de roma inteira.

```bash
~/LPEDC/rodar 24-busca-de-padroes/lista/P2423.c
```

---

**Exercício P2424** · ★★★ · O SOS que some

Ache o bug. O rádio do barco procura "sos" no sinal recebido. O KMP
abaixo compila e roda, mas perde pedidos de socorro que se encostam:


```text
Saída que aparece:
sososos: 0 4 (2)
xsosxsososx: 1 5 (2)
ososo: 1 (1)
aaaaa: 0 2 (2)
```


Em "sososos", o "sos" da posição 2 usa o último s do primeiro. O erro
está numa linha só. Conserte.


```text
Saída esperada:
sososos: 0 2 4 (3)
xsosxsososx: 1 5 7 (3)
ososo: 1 (1)
aaaaa: 0 1 2 3 (4)
```

**Dicas:**

1. O que o programa faz com k logo depois de achar uma ocorrência? O que
   ele "esquece" do que já leu?
2. Depois de casar o padrão inteiro, o fim dele pode ser o começo da
   próxima ocorrência: quanto? Exatamente a borda pi[m - 1].
3. Resposta esperada: troque k = 0 por k = pi[k - 1]; sososos tem 3
   ocorrências e aaaaa, 4.

```bash
~/LPEDC/rodar 24-busca-de-padroes/lista/P2424.c
```

---

**Exercício P2425** · ★★★ · Todos os palíndromos de uma palavra

Escreva todos(s), que acha TODOS os trechos palíndromos de uma palavra
pela expansão ao redor dos 2n - 1 centros: conte cada ocorrência (cada
passo de expansão que deu certo é um palíndromo) e guarde os
DIFERENTES numa tabela char achados[128][32], sem repetir. No fim,
ordene com qsort (menores primeiro; mesmo tamanho, ordem do strcmp) e
mostre. Teste com abacaba, arara, aaaa e tucano.


```text
Saída esperada:
abacaba: 12 ocorrências, 7 diferentes: a b c aba aca bacab abacaba
arara: 9 ocorrências, 5 diferentes: a r ara rar arara
aaaa: 10 ocorrências, 4 diferentes: a aa aaa aaaa
tucano: 6 ocorrências, 6 diferentes: a c n o t u
```

**Dicas:**

1. Um só laço cobre os dois tipos de centro: para c de 0 a 2n - 2,
   e = c / 2 e d = e + c % 2.
2. O qsort ordena as linhas da matriz: qsort(achados, n, 32, compara),
   e o compara recebe ponteiros para o começo de cada linha.
3. Resposta esperada: abacaba tem 12 ocorrências e 7 diferentes (a b c
   aba aca bacab abacaba); tucano, só as 6 letras.

```bash
~/LPEDC/rodar 24-busca-de-padroes/lista/P2425.c
```

---

**Exercício P2426** · ★★★ · A cifra de César do bilhete

O bilhete veio cifrado com a cifra de César: cada letra minúscula foi
empurrada s casas para a frente no alfabeto (dando a volta no z); o
resto ficou igual. Você não sabe o s, mas sabe que a palavra "pix" está
no bilhete. Escreva o programa do zero: para cada s de 0 a 25, decifre
o bilhete e procure "pix" com o KMP; mostre cada deslocamento que dá e
o texto decifrado, e quantos deram.


```text
"alrfp z ati op ntynz cpltd lep dpiel, glwpf"
```



```text
Saída esperada:
deslocamento 11: pague o pix de cinco reais ate sexta, valeu
Deslocamentos com "pix": 1 de 26
```

**Dicas:**

1. Decifrar é andar para trás: 'a' + (c - 'a' - s + 26) % 26.
2. Escreva kmp_tem(t, p), que devolve 1 na primeira ocorrência.
3. Resposta esperada: só o deslocamento 11 tem "pix": pague o pix de
   cinco reais ate sexta, valeu.

```bash
~/LPEDC/rodar 24-busca-de-padroes/lista/P2426.c
```

---

**Exercício P2427** · ★★★ · Os prefixos que são refrão

Um prefixo de tamanho i é um REFRÃO quando é um pedaço repetido um
número inteiro de vezes, duas ou mais ("tumtum" = "tum" × 2). Com a
tabela π, o período do prefixo de tamanho i é i - pi[i - 1]; ele é
refrão quando o período é menor que i e divide i. Escreva refraos(s),
que mostra todos os prefixos refrão de s, em O(m), com o tamanho, o
pedaço e quantas vezes ele se repete.


```text
Saída esperada:
tumtumtumpatumtumtumpa
   6 letras = "tum" x 2
   9 letras = "tum" x 3
  22 letras = "tumtumtumpa" x 2
aabaabaabaab
   2 letras = "a" x 2
   6 letras = "aab" x 2
   9 letras = "aab" x 3
  12 letras = "aab" x 4
```

**Dicas:**

1. Calcule pi uma vez só e percorra i de 2 até m.
2. Mostre com printf("  %2d letras = \"%.*s\" x %d\n", i, periodo, s,
   i / periodo).
3. Resposta esperada: a batucada inteira (22 letras) é "tumtumtumpa" × 2;
   aabaabaabaab tem 4 prefixos refrão.

```bash
~/LPEDC/rodar 24-busca-de-padroes/lista/P2427.c
```

---

**Exercício P2428** · ★★★ · O logotipo na tela

O Rabin-Karp também procura em 2D. A tela tem 6 linhas de 12 pixels
('#' aceso, '.' apagado) e o logotipo é um bloco de 2 linhas por 3
colunas:


```text
#.#
###
```


Escreva do zero (base 256, Q = 1000003):
- o hash de cada linha do logotipo;
- para cada linha da tela, o hash ROLANTE de cada trecho de 3 pixels,

```text
guardado em janela[i][j];
```

- um bloco com canto em (i, j) só é conferido pixel a pixel quando

```text
janela[i + r][j] bate com o hash da linha r do logotipo, para r = 0 e 1.
```

Mostre onde o logotipo aparece e quantos blocos foram conferidos.


```text
Saída esperada:
logotipo na linha 1, coluna 6
logotipo na linha 4, coluna 7
Total: 2; blocos conferidos letra a letra: 2
```

**Dicas:**

1. As janelas da tela custam O(L · C) para montar; depois cada canto
   custa só 2 comparações de números.
2. O índice da janela é o canto esquerdo: j vai de 0 até C - 3.
3. Resposta esperada: linha 1, coluna 6 e linha 4, coluna 7; os
   "#.#" das linhas 0 e 3 não contam porque embaixo deles não há "###".

```bash
~/LPEDC/rodar 24-busca-de-padroes/lista/P2428.c
```

---

**Exercício P2429** · ★★★ · O verificador que fugiu da frase

Ache o bug. Este verificador de palíndromos ignora tudo o que não é
letra. Nas três primeiras frases ele acerta, mas na quarta ("?!") o
AddressSanitizer para o programa com global-buffer-overflow (é de
propósito): o índice i passou do '\0' e saiu lendo a memória depois da
frase. Rode, leia o erro (ele aponta a linha) e conserte as DUAS linhas
com o mesmo problema.


```text
Saída esperada:
[Ame o poema.] sim
[Luz azul!] sim
[A cara rajada da jararaca.] sim
[?!] sim
[Oi, tchau.] não
[...] sim
```

**Dicas:**

1. O que faz o laço "pula o que não é letra" numa frase sem letra
   nenhuma? Quem faz ele parar?
2. O j tem o problema do outro lado: numa frase só de pontuação ele
   desceria abaixo de 0.
3. Resposta esperada: ponha i < j na condição dos dois laços internos;
   "?!" e "..." viram "sim" (não há letra que quebre a simetria) e só
   "Oi, tchau." é "não".

```bash
~/LPEDC/rodar 24-busca-de-padroes/lista/P2429.c
```

---

**Exercício P2430** · ★★★ · A roda da fortuna

No programa de auditório, as letras ficam numa roda: depois da última
vem a primeira de novo. A roda tem "abracadabra". Escreva
circular(t, p), um KMP que procura p no texto CIRCULAR sem montar t + t:
percorra i de 0 até n + m - 2 lendo t[i % n]. Mostre o início de cada
ocorrência (com um * quando ela dá a volta pelo fim) e o total.


```text
Saída esperada:
abra: 0 7 (2)
raab: 9* (1)
aabr: 10* (1)
dabraabr: 6* (1)
aa: 10* (1)
```

**Dicas:**

1. Uma ocorrência começa em (i - m + 1) % n; ela dá a volta quando
   começo + m > n.
2. Parar em n + m - 2 garante que cada começo de 0 a n - 1 é testado uma
   vez só (senão "abra" seria achado duas vezes na posição 0).
3. Resposta esperada: abra em 0 e 7; raab em 9*; aa em 10* (o último a
   da roda com o primeiro).

```bash
~/LPEDC/rodar 24-busca-de-padroes/lista/P2430.c
```
