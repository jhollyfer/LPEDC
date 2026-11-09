<!-- Gerado por _gerador a partir dos arquivos P????.c desta pasta. -->

# Lista prática · Módulo 18 · Ordenação além da comparação e seleção

30 exercícios de codificar que treinam o módulo inteiro, misturando os assuntos, no ritmo da prova do PPGI (veja [PPGI.md](../../PPGI.md)). Cada arquivo `P????.c` desta pasta é um exercício: a resposta vai dentro dele, embaixo de `// Escreva sua resposta abaixo:`. Uma resolução de cada um está em `_respostas/18-ordenacao-linear/lista/`. Só olhe depois de tentar.

[Voltar ao módulo](../README.md)

## ★☆☆ Aquecimento

**Exercício P1801** · ★☆☆ · Counting sort passo a passo: o vetor C e a saída

No posto de vacinação, as idades das 10 crianças da fila (0 a 4 anos) vão
para o relatório em ordem. Escreva do zero o counting sort do Cormen e
mostre o estado dos vetores como a prova pede:

1. C depois da contagem (C[x] = quantas crianças têm x anos);
2. C depois das somas acumuladas (C[x] = quantas têm idade <= x);
3. cada passo da colocação, de trás para frente: o valor, a posição em que
ele entra na saída B e o vetor C logo depois;
4. o vetor B no fim.

Use posições de 0 a n - 1 (em C, decremente antes de usar).


```text
Saída esperada:
Contagem: C = 1 3 1 2 3
Acumulado: C = 1 4 5 7 10
A[9] = 1 vai para B[3] | C = 1 3 5 7 10
A[8] = 3 vai para B[6] | C = 1 3 5 6 10
A[7] = 4 vai para B[9] | C = 1 3 5 6 9
A[6] = 1 vai para B[2] | C = 1 2 5 6 9
A[5] = 2 vai para B[4] | C = 1 2 4 6 9
A[4] = 0 vai para B[0] | C = 0 2 4 6 9
A[3] = 4 vai para B[8] | C = 0 2 4 6 8
A[2] = 3 vai para B[5] | C = 0 2 4 5 8
A[1] = 1 vai para B[1] | C = 0 1 4 5 8
A[0] = 4 vai para B[7] | C = 0 1 4 5 7
B = 0 1 1 1 2 3 3 4 4 4
```

**Dicas:**

1. Depois da soma acumulada, C[x] - 1 é a ÚLTIMA posição livre do bloco
   dos x: por isso o laço da colocação anda de trás para frente e
   decrementa antes de gravar.
2. Mostre C com uma função que recebe um rótulo, como mostra("C:", c).
3. O último elemento de A (1) é o primeiro a ser colocado: vai para a
   última posição do bloco dos 1.
4. Resposta esperada: C = 1 3 1 2 3 depois da contagem, 1 4 5 7 10 depois
   das somas, e B = 0 1 1 1 2 3 3 4 4 4.

```bash
~/LPEDC/rodar 18-ordenacao-linear/lista/P1801.c
```

---

**Exercício P1802** · ★☆☆ · Shell sort com os saltos de Shell: n/2, n/4, ..., 1

Os saltos originais de Donald Shell (1959) são n/2, n/4, ..., 1 (divisão
inteira). Ordene as alturas, em cm, dos 10 atletas do time de basquete da
escola com essa sequência e mostre o vetor depois de cada passada, junto
com o salto e as comparações feitas naquela passada.

Cada passada com salto h é um insertion sort que compara v[j] com
v[j - h] em vez de v[j - 1].


```text
Saída esperada:
início: 190 175 201 168 183 178 194 172 186 181
h = 5:  178 175 172 168 181 190 194 201 186 183  (5 comparações)
h = 2:  172 168 178 175 181 183 186 190 194 201  (11 comparações)
h = 1:  168 172 175 178 181 183 186 190 194 201  (10 comparações)
```

**Dicas:**

1. for (h = n / 2; h >= 1; h /= 2), e dentro o insertion sort com passo h:
   para i de h até n - 1, desloque de h em h enquanto v[j - h] > x.
2. Conte uma comparação a cada teste v[j - h] > x que chega a ser feito
   (quando j - h >= 0).
3. Com n = 10, os saltos são 5, 2 e 1. Na última passada, o vetor já está
   quase ordenado e o insertion sort trabalha pouco.
4. Resposta esperada: o vetor final 168 172 175 178 181 183 186 190 194
   201, com 5, 11 e 10 comparações nas três passadas.

```bash
~/LPEDC/rodar 18-ordenacao-linear/lista/P1802.c
```

---

**Exercício P1803** · ★☆☆ · Radix com base 100: dois dígitos por passada

As matrículas dos calouros têm 6 dígitos. Em base 10, o radix sort LSD faz
6 passadas. Em base 100, cada "dígito" é um par de dígitos decimais (de 00
a 99), e bastam 3 passadas: (m / 1) % 100, (m / 100) % 100 e
(m / 10000) % 100.

Escreva o radix sort LSD em base 100, com um counting sort estável de 100
posições em cada passada, e mostre o vetor depois de cada passada, com o
divisor usado.


```text
Saída esperada:
div     1: 230105 190305 241012 241077 210477 230388 180399
div   100: 230105 190305 230388 180399 210477 241012 241077
div 10000: 180399 190305 210477 230105 230388 241012 241077
```

**Dicas:**

1. Mesma estrutura do radix em base 10: só troque 10 por 100. O vetor C
   passa a ter 100 posições.
2. Com d passadas de base b, o custo é Θ(d (n + b)). Aqui d = 3 e b = 100
   contra d = 6 e b = 10: com poucos números, b = 100 pesa; com milhões,
   metade das passadas ganha.
3. Depois da primeira passada, o vetor está ordenado pelos dois últimos
   dígitos; depois da segunda, pelos quatro últimos.
4. Resposta esperada: na primeira passada, 230105 e 190305 (final 05) vêm
   antes de 241012; no fim, 180399 190305 210477 230105 230388 241012
   241077.

```bash
~/LPEDC/rodar 18-ordenacao-linear/lista/P1803.c
```

---

**Exercício P1804** · ★☆☆ · Bucket sort da ocupação dos voos

A companhia aérea guarda a taxa de ocupação de cada voo do dia como um
número em [0, 1): 0.87 é 87% dos assentos. Ordene as 10 taxas do esqueleto
com o bucket sort do Cormen: n = 10 baldes, o valor x vai para o balde
⌊10 x⌋, cada balde é uma lista encadeada (malloc) mantida em ordem por
inserção, e no fim os baldes são concatenados em ordem.

Mostre o conteúdo de cada balde não vazio e o vetor ordenado. Libere todos
os nós.


```text
Saída esperada:
balde 0: 0.05
balde 1: 0.12
balde 3: 0.31 0.36
balde 5: 0.52
balde 7: 0.79
balde 8: 0.84 0.87 0.88
balde 9: 0.99
ordenado: 0.05 0.12 0.31 0.36 0.52 0.79 0.84 0.87 0.88 0.99
```

**Dicas:**

1. Balde de x: (int)(x * n). Como x < 1, o índice fica entre 0 e n - 1.
2. Inserir em ordem numa lista: ande com um ponteiro para ponteiro
   (No **p = &balde[b]) enquanto (*p)->x < x, e encaixe o novo ali.
3. Com dados espalhados por igual, cada balde recebe O(1) itens em média e
   o total é Θ(n). Aqui o balde 8 recebe três voos.
4. Resposta esperada: baldes 0, 1, 3, 5, 7, 8 e 9 ocupados; o vetor
   ordenado começa em 0.05 e termina em 0.99.

```bash
~/LPEDC/rodar 18-ordenacao-linear/lista/P1804.c
```

---

**Exercício P1805** · ★☆☆ · O 3º posto mais barato, partição por partição

O app de combustível tem o preço do litro (em centavos) em 9 postos de
Manaus e quer o 3º MENOR preço sem ordenar tudo. Escreva o quickselect com
a partição de Lomuto (pivô = último elemento do pedaço) e mostre cada
partição: o pedaço [ini, fim], o pivô, a posição final dele e para que lado
a busca continua. Use k a partir de 1 (k = 1 é o menor).


```text
Saída esperada:
[0, 8] pivô 594 foi para 3 -> esquerda
[0, 2] pivô 579 foi para 1 -> direita
[2, 2] pivô 589 foi para 2 -> achou
3º menor preço: 589 centavos (R$ 5,89)
```

**Dicas:**

1. Depois da partição, o pivô está na posição p, e há p - ini elementos
   menores à esquerda dele no pedaço. Compare p com a posição procurada,
   k - 1 (índice a partir de 0).
2. Se p == k - 1, achou. Se k - 1 < p, continue em [ini, p - 1]; senão, em
   [p + 1, fim]. Só UM lado: por isso o caso médio é Θ(n), e não n lg n.
3. Faça iterativo (um laço while): não precisa de recursão, porque só há
   uma chamada.
4. Resposta esperada: três partições, e o 3º menor preço é 589 centavos
   (R$ 5,89).

```bash
~/LPEDC/rodar 18-ordenacao-linear/lista/P1805.c
```

---

**Exercício P1806** · ★☆☆ · De trás para frente ou da frente para trás?

As inscrições da corrida de rua chegam em ordem de inscrição, cada uma com
o nome e a categoria (0 = 5 km, 1 = 10 km, 2 = meia, 3 = maratona). A
organização quer a lista por categoria e, dentro dela, na ORDEM DE
INSCRIÇÃO: é preciso uma ordenação ESTÁVEL.

Complete o counting sort por categoria com um parâmetro bool de_tras: com
true, a colocação anda de n - 1 até 0 (a versão do Cormen); com false,
anda de 0 até n - 1, mas continua usando --c[x]. Mostre as duas saídas e
diga, para cada uma, se ficou estável (compare a ordem dos nomes dentro de
cada categoria com a ordem de inscrição, guardada no campo ordem).


```text
Saída esperada:
de trás: Bruno(0) Elis(0) Ana(1) Davi(1) Gil(1) Fabio(2) Carla(3) Hana(3) -> estável
da frente: Elis(0) Bruno(0) Gil(1) Davi(1) Ana(1) Fabio(2) Hana(3) Carla(3) -> NÃO estável
```

**Dicas:**

1. Com --c[x], cada bloco é preenchido de trás para frente. Se a leitura
   também é de trás para frente, o último inscrito de cada categoria fica
   no fim do bloco: a ordem se mantém.
2. Lendo da frente com --c[x], o PRIMEIRO inscrito vai para o fim do bloco:
   os empates saem invertidos. Para ler da frente e ser estável, seria
   preciso usar as posições iniciais dos blocos com c[x]++.
3. Estável: para todo i, se saida[i].cat == saida[i + 1].cat, então
   saida[i].ordem < saida[i + 1].ordem.
4. Resposta esperada: de trás para frente é estável (Ana antes de Davi nos
   10 km); da frente para trás, não.

```bash
~/LPEDC/rodar 18-ordenacao-linear/lista/P1806.c
```

---

**Exercício P1807** · ★☆☆ · Quantas corridas entre R$ 10 e R$ 20? Em O(1)

O app de transporte registrou o valor (em reais inteiros, de 0 a 50) das
20 corridas da manhã. O gerente vai fazer várias perguntas do tipo
"quantas corridas custaram entre a e b reais?".

O vetor acumulado do counting sort responde cada pergunta em O(1): depois
de um pré-processamento Θ(n + k), C[x] = quantas corridas custaram <= x, e
a resposta para [a, b] é C[b] - C[a - 1] (com C[-1] = 0). Escreva o
pré-processamento e a função int entre(const int c[], int a, int b), e
responda às perguntas do esqueleto.


```text
Saída esperada:
Entre R$ 10 e R$ 20:  9 corridas
Entre R$  0 e R$ 50: 20 corridas
Entre R$  0 e R$  9:  4 corridas
Entre R$ 15 e R$ 15:  2 corridas
Entre R$ 30 e R$ 50:  4 corridas
```

**Dicas:**

1. Mesmo começo do counting sort: conte cada valor e faça as somas
   acumuladas. Não precisa ordenar nada.
2. Cuidado com a = 0: não existe C[-1]; trate como 0.
3. Para conferir, a pergunta [0, 50] tem de dar 20, e [x, x] dá quantas
   corridas custaram exatamente x.
4. Resposta esperada: 9 corridas entre R$ 10 e R$ 20, 20 no total, 4 até
   R$ 9 e 2 de exatamente R$ 15.

```bash
~/LPEDC/rodar 18-ordenacao-linear/lista/P1807.c
```

---

**Exercício P1808** · ★☆☆ · Radix sort bit a bit: zeros na frente, uns atrás

O radix sort não precisa de base 10: em base 2, cada passada olha um bit.
Com um bit só, o counting sort vira uma SEPARAÇÃO ESTÁVEL: primeiro todos
os que têm aquele bit 0, na ordem em que estão, depois todos os que têm 1,
também na ordem.

Os códigos das 8 linhas de um terminal de ônibus vão de 0 a 15 (4 bits).
Escreva a passada (bit b: (x >> b) & 1) e rode o radix LSD do bit 0 ao
bit 3, mostrando o vetor em binário e em decimal depois de cada passada.


```text
Saída esperada:
início 1100 0101 1001 1110 0011 1010 0110 1011 | 12 5 9 14 3 10 6 11
bit 0   1100 1110 1010 0110 0101 1001 0011 1011 | 12 14 10 6 5 9 3 11
bit 1   1100 0101 1001 1110 1010 0110 0011 1011 | 12 5 9 14 10 6 3 11
bit 2   1001 1010 0011 1011 1100 0101 1110 0110 | 9 10 3 11 12 5 14 6
bit 3   0011 0101 0110 1001 1010 1011 1100 1110 | 3 5 6 9 10 11 12 14
```

**Dicas:**

1. Uma passada: conte quantos têm o bit 0 (zeros); percorra o vetor
   copiando os de bit 0 para saida[iz++] (iz começa em 0) e os de bit 1
   para saida[iu++] (iu começa em zeros). É o counting sort com k = 2, sem
   precisar ler de trás para frente.
2. Para imprimir em binário, mostre os bits 3, 2, 1 e 0 de cada número.
3. Depois da passada do bit b, o vetor está ordenado pelos b + 1 bits de
   baixo: é o invariante do radix LSD.
4. Resposta esperada: no fim, 0011 0101 0110 1001 1010 1011 1100 1110
   (3 5 6 9 10 11 12 14).

```bash
~/LPEDC/rodar 18-ordenacao-linear/lista/P1808.c
```

---

**Exercício P1809** · ★☆☆ · A tabela do campeonato em ordem decrescente, estável

No campeonato de futsal do bairro, os times já estão em ordem alfabética.
A tabela tem de sair por PONTOS, do maior para o menor, e os empatados
continuam em ordem alfabética. Os pontos vão de 0 a 15.

Complete o counting sort decrescente e estável. O truque: ordene pela chave
invertida, MAX - pontos, em ordem crescente. Quem tem mais pontos tem chave
menor e vai para o começo, e a estabilidade do counting sort preserva a
ordem alfabética dos empates.


```text
Saída esperada:
1. Goias            15
2. Para             12
3. Amazonas          9
4. Bahia             9
5. Ceara             9
6. Espirito Santo    7
7. Fortaleza         4
8. Distrito Federal  2
```

**Dicas:**

1. Use chave(t) = 15 - t.pontos em todos os lugares em que o counting sort
   usaria t.pontos.
2. Não dá para ordenar crescente e inverter o vetor depois: a inversão
   também inverte os empates (Bahia sairia antes de Amazonas).
3. Confira os empates: Amazonas, Bahia e Ceara têm 9 pontos.
4. Resposta esperada: Goias 15, Para 12, Amazonas 9, Bahia 9, Ceara 9,
   Espirito Santo 7, Fortaleza 4, Distrito Federal 2.

```bash
~/LPEDC/rodar 18-ordenacao-linear/lista/P1809.c
```

---

**Exercício P1810** · ★☆☆ · Conserte o counting sort das notas

Conserte o programa. Ele ordena as notas (inteiras, de 0 a 10) de 12 alunos
com counting sort, mas tem DOIS erros de propósito, e os dois são de
índice. Rode com ./rodar: o AddressSanitizer acusa leitura e escrita fora
do vetor c (stack-buffer-overflow). Ache os dois, conserte e confira a
saída:


```text
Saída esperada:
0 3 4 5 5 6 7 7 8 9 10 10
```

**Dicas:**

1. Se as notas vão de 0 a K, quantas posições o vetor de contagem precisa
   ter? Um vetor int c[K] tem as posições 0 a K - 1.
2. Olhe o laço das somas acumuladas: na primeira volta, que posição ele
   lê?
3. Os dois erros são clássicos de "fora por um". Em C, nada impede o
   acesso fora do vetor: só o sanitizer (ou um resultado esquisito) avisa.
4. Resposta esperada: 0 3 4 5 5 6 7 7 8 9 10 10.

```bash
~/LPEDC/rodar 18-ordenacao-linear/lista/P1810.c
```

## ★★☆ Para pensar

**Exercício P1811** · ★★☆ · Quatro sequências de saltos no mesmo shell sort

O shell sort é o mesmo algoritmo com qualquer sequência de saltos que
termine em 1, mas o desempenho muda muito. Compare quatro:

- Shell (1959): n/2, n/4, ..., 1;
- Hibbard (1963): 2^k - 1 (1, 3, 7, 15, 31, ...);
- Knuth (1973): h = 3h + 1 (1, 4, 13, 40, 121, ...), começando no maior
h < n/3;
- Sedgewick (1986): 4^k + 3 · 2^(k-1) + 1, com 1 no começo (1, 8, 23, 77,
281, 1073, 4193, ...).

Escreva shell(v, n, saltos, ns), que recebe os saltos em ordem DECRESCENTE,
e conte as comparações. Ordene cópias dos mesmos tempos de entrega (gerados
no esqueleto) para n = 1000 e n = 10000, confira que ficaram ordenados e
mostre as comparações de cada sequência e do insertion sort puro.


```text
Saída esperada:
             n = 1000  n = 10000
Shell           14923     258585
Hibbard         14298     231869
Knuth           13674     233094
Sedgewick       15546     221889
insertion      256897   24710349
Todos ordenados: sim
```

**Dicas:**

1. Monte cada sequência num vetor (em ordem crescente, que é mais fácil de
   gerar) e passe para a função percorrendo de trás para frente.
2. Para Hibbard e Sedgewick, use só os saltos menores que n. Para Knuth,
   pare quando o próximo passaria de n/3.
3. O insertion sort é o shell sort com a sequência "1": aproveite a mesma
   função.
4. Resposta esperada: o insertion sort fica perto de n²/4 (24,7 milhões
   com n = 10000, contra uns 230 mil das sequências). Com n = 1000 as
   quatro empatam perto de 15 mil; com n = 10000, Shell é a pior (258585) e
   Sedgewick, a melhor (221889). A diferença cresce com n.

```bash
~/LPEDC/rodar 18-ordenacao-linear/lista/P1811.c
```

---

**Exercício P1812** · ★★☆ · Radix LSD mostrando o vetor C de cada passada

Na prova, o radix sort aparece como "qual é o vetor depois da segunda
passada?" e o counting sort como "qual é o vetor C?". Junte os dois: ordene
os 8 códigos de rastreio (3 dígitos) de uma agência dos Correios com radix
LSD em base 10 e, em CADA passada, mostre:

- o dígito usado de cada número;
- o vetor C depois das somas acumuladas (C[d] = quantos têm dígito <= d);
- o vetor depois da passada.


```text
Saída esperada:
Passada div = 1
dígitos: 5 1 2 7 3 0 5 1
C acumulado: 1 3 4 5 5 7 7 8 8 8
vetor: 540 331 801 902 283 465 615 747
Passada div = 10
dígitos: 4 3 0 0 8 6 1 4
C acumulado: 2 3 3 4 6 6 7 7 8 8
vetor: 801 902 615 331 540 747 465 283
Passada div = 100
dígitos: 8 9 6 3 5 7 4 2
C acumulado: 0 0 1 2 3 4 5 6 7 8
vetor: 283 331 465 540 615 747 801 902
```

**Dicas:**

1. Dígito da passada com divisor div: (x / div) % 10, com div = 1, 10, 100.
2. C acumulado diz onde termina cada bloco: os de dígito d ocupam as
   posições C[d - 1] até C[d] - 1.
3. Um dígito que não aparece repete o valor do anterior em C: o bloco dele
   tem tamanho zero.
4. Resposta esperada: depois das unidades, 540 801 331 902 283 465 615 747;
   depois das dezenas, 801 902 615 331 540 747 465 283; no fim, 283 331 465
   540 615 747 801 902.

```bash
~/LPEDC/rodar 18-ordenacao-linear/lista/P1812.c
```

---

**Exercício P1813** · ★★☆ · Três chaves, três passadas estáveis

A central de suporte quer os chamados ordenados por PRIORIDADE (0 a 3, 0
é a mais urgente), depois por SETOR (0 a 4) e, dentro disso, pelo MINUTO em
que chegaram (0 a 59). Em vez de um comparador com três critérios, use o
truque do radix: passadas estáveis, da chave MENOS significativa para a
MAIS significativa.

Escreva um counting sort genérico que recebe a função da chave:


```text
void counting(Chamado v[], int n, int (*chave)(const Chamado *), int k);
```


e faça três passadas: por minuto, por setor e por prioridade, mostrando a
ordem dos chamados depois de cada uma e, no fim, os campos de cada um.


```text
Saída esperada:
por minuto:     #4 #5 #1 #3 #7 #2 #6 #8
por setor:      #5 #8 #3 #6 #4 #2 #1 #7
por prioridade: #3 #6 #1 #8 #4 #2 #7 #5
  #3 prioridade 0, setor 1, minuto 15
  #6 prioridade 0, setor 1, minuto 40
  #1 prioridade 0, setor 3, minuto 12
  #8 prioridade 1, setor 0, minuto 59
  #4 prioridade 1, setor 2, minuto  5
  #2 prioridade 1, setor 2, minuto 33
  #7 prioridade 2, setor 4, minuto 20
  #5 prioridade 3, setor 0, minuto  8
```

**Dicas:**

1. A função da chave devolve um inteiro de 0 a k - 1; o counting sort usa
   chave(&v[i]) onde usaria v[i]. Escreva int por_minuto(const Chamado *c)
   e as outras duas.
2. Por que da menos para a mais significativa? A última passada decide a
   ordem principal; a estabilidade preserva, nos empates, a ordem deixada
   pelas passadas anteriores.
3. Cada passada custa Θ(n + k): o total é Θ(3n + 60 + 5 + 4), linear.
4. Resposta esperada: no fim, #3 #6 #1 #8 #4 #2 #7 #5. Repare em #4 e #2:
   mesma prioridade e setor, e o minuto 5 vem antes do 33 porque a
   primeira passada deixou os dois nessa ordem.

```bash
~/LPEDC/rodar 18-ordenacao-linear/lista/P1813.c
```

---

**Exercício P1814** · ★★☆ · Mediana: quickselect contra ordenar tudo

Para achar a mediana do tempo de espera de 1001 pacientes de uma UBS, não
é preciso ordenar: o quickselect acha o elemento de posição 500 (a partir
de 0) em tempo médio Θ(n). Confira contando comparações.

Escreva o quickselect (Lomuto, pivô no último) e um merge sort, os dois
contando comparações entre elementos, e mostre a mediana e as comparações
de cada um em dois vetores:

- os tempos sorteados do esqueleto;
- os mesmos tempos JÁ ORDENADOS (o pior caso do pivô no último).


```text
Saída esperada:
sorteado:
  quickselect: mediana 118,   5351 comparações
  merge sort:  mediana 118,   8693 comparações
ordenado:
  quickselect: mediana 118,  90220 comparações
  merge sort:  mediana 118,   5049 comparações
```

**Dicas:**

1. Quickselect iterativo: particione [ini, fim]; se o pivô parou na posição
   procurada, achou; senão continue só no lado que contém a posição.
2. Com o vetor ordenado, o pivô no último é sempre o maior do pedaço: cada
   partição tira poucos elementos (os iguais ao pivô), e o quickselect
   vira quadrático. O pivô sorteado (ou a mediana das medianas) evita isso.
3. O merge sort quase não liga para a ordem da entrada: ordenado ou não,
   fica em Θ(n lg n).
4. Resposta esperada: a mesma mediana (118) nos quatro casos; no vetor
   sorteado, o quickselect faz 5351 comparações contra 8693 do merge sort;
   no ordenado, o quickselect sobe para 90220, e o merge sort cai para 5049.

```bash
~/LPEDC/rodar 18-ordenacao-linear/lista/P1814.c
```

---

**Exercício P1815** · ★★☆ · Bucket sort fora de [0, 1): as temperaturas de Manaus

O bucket sort do Cormen supõe valores em [0, 1). As máximas diárias de
Manaus num mês vão de uns 23 °C a uns 38 °C. Para usar baldes, NORMALIZE:
com mín e máx do vetor, o valor x vai para o balde


```text
b = (int)((x - mín) / (máx - mín) * n)
```


e o máximo (que daria b = n) vai para o balde n - 1. Ordene as 12
temperaturas do esqueleto com n baldes (listas encadeadas em ordem, com
malloc), mostre os baldes não vazios e o vetor ordenado.


```text
Saída esperada:
balde  0: 22.9
balde  3: 27.3
balde  5: 29.5
balde  6: 30.7 31.2
balde  7: 32.4
balde  8: 33.8 34.1
balde  9: 35.0
balde 10: 36.4
balde 11: 37.6 38.1
ordenado: 22.9 27.3 29.5 30.7 31.2 32.4 33.8 34.1 35.0 36.4 37.6 38.1
```

**Dicas:**

1. Ache mín e máx numa passada (Θ(n)) antes de distribuir.
2. Sem o ajuste do máximo, ele cairia no balde n, fora do vetor: o
   AddressSanitizer acusa na hora.
3. Se todos os valores forem iguais, máx - mín = 0: trate esse caso (todo
   mundo no balde 0) antes de dividir.
4. Resposta esperada: 12 baldes, o 0 com 22.9 e o 11 com 37.6 e 38.1; o
   vetor ordenado vai de 22.9 a 38.1.

```bash
~/LPEDC/rodar 18-ordenacao-linear/lista/P1815.c
```

---

**Exercício P1816** · ★★☆ · Os rios do Amazonas ordenados pelo tamanho do nome

Um app de geografia quer mostrar os rios do esqueleto agrupados pelo
NÚMERO DE LETRAS do nome, do mais curto para o mais longo, e, dentro de
cada tamanho, na ordem em que estão na lista.

Ordene o vetor de strings (const char *) com counting sort estável pela
chave strlen(nome). Os nomes têm até 12 letras. Mostre os grupos com o
tamanho na frente e, depois, o vetor C como fica no fim da colocação:
com os decrementos, cada C[x] passa a apontar o INÍCIO do bloco x.


```text
Saída esperada:
3 letras: Ica
5 letras: Negro Purus Jurua
6 letras: Japura Javari Uatuma
7 letras: Madeira Tapajos
8 letras: Solimoes
9 letras: Trombetas
C (depois da colocação, início de cada bloco): 0 0 0 0 1 1 4 7 9 10 11 11 11
```

**Dicas:**

1. Ordene os PONTEIROS, não as letras: saida[--c[strlen(v[i])]] = v[i]
   copia só o endereço da string, 8 bytes, seja ela longa ou curta.
2. Calcule cada strlen uma vez e guarde num vetor tam[]: strlen percorre a
   string inteira toda vez que é chamada.
3. Estável: Negro e Purus têm 5 letras, e Negro vem antes porque está antes
   na lista.
4. Resposta esperada: 3 letras: Ica; 5: Negro Purus Jurua; 6: Japura
   Javari Uatuma; 7: Madeira Tapajos; 8: Solimoes; 9: Trombetas.

```bash
~/LPEDC/rodar 18-ordenacao-linear/lista/P1816.c
```

---

**Exercício P1817** · ★★☆ · Conserte o radix sort das encomendas

Conserte o programa. A transportadora ordena os pesos das encomendas (em
gramas) com radix sort LSD em base 10, mas o colega deixou DOIS erros de
propósito. Não há erro de memória; o resultado é que sai fora de ordem:


```text
Saída que aparece:
45 3005 120 1250 340 12400 870 9800
```


Depois do conserto:


```text
Saída esperada:
45 120 340 870 1250 3005 9800 12400
```

**Dicas:**

1. Quantas passadas o radix precisa? Tantas quantos dígitos tem o MAIOR
   número, não o primeiro do vetor.
2. Cada passada tem de ser ESTÁVEL. Com --c[d], a colocação precisa andar
   de trás para frente; da frente para trás, os empates de cada dígito
   saem invertidos e a ordem das passadas anteriores se perde.
3. Para ver o erro 2, faça à mão a passada das unidades: 870, 12400, 120,
   9800 e 340 terminam em 0. Da frente para trás com --c[0], o 870 vai para
   a última vaga do bloco, e eles saem na ordem inversa.
4. Resposta esperada: 45 120 340 870 1250 3005 9800 12400.

```bash
~/LPEDC/rodar 18-ordenacao-linear/lista/P1817.c
```

---

**Exercício P1818** · ★★☆ · Onde pôr o depósito: a mediana ponderada

Uma rede tem 7 lojas ao longo da Av. Torquato Tapajós, cada uma num km
(de 0 a 30) e com um número de entregas por dia (o peso). O depósito vai
num km p, e o custo diário é a soma de peso · |km - p|. O melhor p é a
MEDIANA PONDERADA (problema 9-2 do Cormen): ordene as lojas pelo km e ande
somando os pesos; o primeiro km em que a soma chega à metade do peso total
é a resposta.

Ordene as lojas pelo km com counting sort (os km são inteiros pequenos),
ache a mediana ponderada e mostre o custo em quatro candidatos: a mediana
ponderada, a mediana simples dos km (sem pesos), a média ponderada
arredondada e o melhor km por força bruta (testando de 0 a 30).


```text
Saída esperada:
km  2 Cidade Nova          peso  5, acumulado  5 de 23
km  5 Novo Israel          peso  1, acumulado  6 de 23
km  7 Lago Azul            peso  2, acumulado  8 de 23
km 12 Monte das Oliveiras  peso  1, acumulado  9 de 23
km 18 Santa Etelvina       peso  1, acumulado 10 de 23
km 21 Colonia              peso  2, acumulado 12 de 23
Mediana ponderada: km 21, custo 206
Força bruta:       km 21, custo 206
Mediana simples:   km 12, custo 245
Média ponderada:   km 17, custo 220
```

**Dicas:**

1. Para comparar com a metade sem usar double, compare 2 · acumulado com o
   peso total.
2. Por que funciona? Andando um km para a direita a partir de p, o custo
   aumenta (peso à esquerda) e diminui (peso à direita). Enquanto houver
   mais peso à direita, vale a pena andar.
3. A média ponderada minimiza a soma dos QUADRADOS das distâncias, não a
   soma das distâncias: aqui ela perde.
4. Resposta esperada: mediana ponderada no km 21, com custo 206; a força
   bruta concorda; a mediana simples (km 12) custa 245 e a média (km 17),
   220.

```bash
~/LPEDC/rodar 18-ordenacao-linear/lista/P1818.c
```

---

**Exercício P1819** · ★★☆ · Qual base para o radix? Conte as operações

O radix sort LSD de inteiros sem sinal de 32 bits pode olhar r bits por
passada (base b = 2^r): são ⌈32 / r⌉ passadas de Θ(n + b) cada. Base
pequena faz muitas passadas; base grande faz poucas, mas cada uma paga o
vetor C de b posições.

Escreva radix(v, n, r), que funciona para r = 1, 4, 8 e 16, e conte as
operações: cada passada soma n (contagem) + b (somas acumuladas) + n
(colocação) + n (cópia de volta). Ordene cópias dos mesmos 100000 códigos
de produto (sorteados no esqueleto) com cada r, confira o resultado e
mostre passadas, operações e operações por elemento. Depois, repita com só
n = 1000 elementos.


```text
Saída esperada:
n = 100000
  r =  1: 32 passadas, 9600064 operações ( 96.0 por item), ordenado
  r =  4:  8 passadas, 2400128 operações ( 24.0 por item), ordenado
  r =  8:  4 passadas, 1201024 operações ( 12.0 por item), ordenado
  r = 16:  2 passadas,  731072 operações (  7.3 por item), ordenado
n = 1000
  r =  1: 32 passadas,   96064 operações ( 96.1 por item), ordenado
  r =  4:  8 passadas,   24128 operações ( 24.1 por item), ordenado
  r =  8:  4 passadas,   13024 operações ( 13.0 por item), ordenado
  r = 16:  2 passadas,  137072 operações (137.1 por item), ordenado
```

**Dicas:**

1. Dígito da passada p: (x >> (p · r)) & (b - 1). Use unsigned para que o
   deslocamento não mexa no sinal.
2. O vetor C de r = 16 tem 65536 posições: deixe-o static, e zere só as b
   posições usadas em cada passada.
3. Fórmula: ⌈32/r⌉ · (3n + b). Com n grande, r = 16 ganha (2 passadas);
   com n pequeno, o b = 65536 pesa mais que o n, e r = 8 ganha.
4. Resposta esperada: com n = 100000, r = 16 ganha (731072 operações,
   contra 1201024 de r = 8); com n = 1000, r = 8 ganha (13024, contra
   137072 de r = 16).

```bash
~/LPEDC/rodar 18-ordenacao-linear/lista/P1819.c
```

---

**Exercício P1820** · ★★☆ · Counting sort custa n + k: quando o k atrapalha

O counting sort é Θ(n + k): linear em n, mas paga o tamanho k do intervalo
das chaves. Com k pequeno é imbatível; com k enorme, perde até para uma
ordenação por comparação.

Ordene n = 1000 valores sorteados com chaves em [0, k), para k = 10, 1000,
100000 e 1000000, com counting sort e com merge sort. Conte as operações
do counting sort (n na contagem + k nas somas + n na colocação) e as
comparações do merge sort. Mostre as contagens e quem ganhou, e confira que
os dois resultados são iguais.


```text
Saída esperada:
      k  counting   merge  vencedor  iguais
     10      2010    8507  counting  sim
   1000      3000    8719  counting  sim
 100000    102000    8706  merge     sim
1000000   1002000    8712  merge     sim
```

**Dicas:**

1. O vetor C com 1 milhão de int ocupa 4 MB: deixe-o static.
2. O merge sort faz pouco menos que n lg n ≈ 10 mil comparações para
   n = 1000 (perto de 8700), qualquer que seja k.
3. O ponto de virada fica onde 2n + k ≈ comparações do merge: com n = 1000,
   k na casa de 7 mil. Para chaves grandes (CPF, telefone), use radix sort,
   que quebra a chave em dígitos pequenos.
4. Resposta esperada: counting ganha com k = 10 e k = 1000 (2010 e 3000
   operações); merge ganha com k = 100000 e 1000000.

```bash
~/LPEDC/rodar 18-ordenacao-linear/lista/P1820.c
```

## ★★★ Desafio

**Exercício P1821** · ★★★ · O painel de partidas do aeroporto

O painel de partidas do aeroporto de Manaus mostra os voos dos próximos
dias por DIA, HORA e MINUTO e, no mesmo horário, pelo NÚMERO do voo. Os
registros chegam fora de ordem (vetor do esqueleto).

Monte a ordem com passadas estáveis de counting sort, da chave menos
significativa para a mais: número do voo (de 0 a 9999), minuto, hora e
dia. Use um único counting sort genérico, que recebe a chave por ponteiro
de função e o tamanho do intervalo. Mostre a ordem dos números de voo
depois de cada passada, o painel final e a conferência com o qsort usando
um comparador de quatro critérios.


```text
Saída esperada:
por número: 1190 1501 1502 1777 2011 2210 2788 3320 3999 4410
por minuto: 1777 3999 2788 3320 1502 2210 1190 1501 4410 2011
por hora:   1502 2210 1777 3999 2788 3320 2011 1190 1501 4410
por dia:    1502 1190 1501 2210 2788 3320 2011 1777 3999 4410
Data  Hora    Voo  Destino
09/11 06:15  1502  Brasilia
09/11 21:30  1190  Boa Vista
09/11 21:30  1501  Brasilia
10/11 06:15  2210  Porto Velho
10/11 14:05  2788  Sao Paulo
10/11 14:05  3320  Belem
10/11 14:50  2011  Santarem
11/11 08:00  1777  Rio
11/11 08:00  3999  Recife
11/11 23:40  4410  Fortaleza
qsort concorda: sim
```

**Dicas:**

1. Os números de voo vão até 9999: o vetor C dessa passada tem 10000
   posições (static). As outras têm 60, 24 e 31.
2. O comparador do qsort compara dia; se empatar, hora; depois minuto;
   depois número. Os dois métodos têm de dar a mesma sequência.
3. As passadas custam Θ(4n + 10000 + 60 + 24 + 31): com poucos voos, o
   10000 domina. Com milhões de voos, é linear e ganha do qsort.
4. Resposta esperada: o painel começa com o voo 1502 do dia 9 às 06:15 e
   termina com o 4410 do dia 11 às 23:40; o qsort concorda.

```bash
~/LPEDC/rodar 18-ordenacao-linear/lista/P1821.c
```

---

**Exercício P1822** · ★★★ · Radix MSD: os municípios em ordem alfabética

O radix LSD precisa de chaves do mesmo tamanho. O radix MSD (do dígito
MAIS significativo) não: ele separa as strings pela primeira letra com um
counting sort e, dentro de cada grupo, resolve RECURSIVAMENTE pela segunda
letra, e assim por diante. Uma string que já acabou (o '\0' na posição d)
vai para o grupo 0 e fica antes de todas as que continuam: é por isso que
"mana" viria antes de "manaus".

Escreva msd(v, ini, fim, d), que ordena os ponteiros v[ini..fim] olhando a
posição d (grupos de 0 a 256, com o caractere + 1 e 0 para o fim da string),
com um vetor auxiliar de ponteiros (pode acrescentar um parâmetro que diga
se a chamada mostra os grupos, para só a primeira mostrar). Ordene os 15 municípios do esqueleto,
conte as chamadas, mostre os grupos do primeiro nível (a letra e quantos
nomes) e o vetor final (5 por linha), e confira com strcmp que ficou em
ordem.


```text
Saída esperada:
Primeiro nível: b(2) c(3) h(1) i(2) m(4) p(1) t(2)
barcelos borba careiro coari codajas
humaita iranduba itacoatiara manacapuru manaus
manicore maues parintins tabatinga tefe
Chamadas: 10 | em ordem pelo strcmp: sim
```

**Dicas:**

1. Grupo da string s na posição d: (unsigned char)s[d] + 1 se s[d] != '\0',
   senão 0. São 257 grupos; C tem 258 posições para guardar os inícios.
2. Depois do counting sort da posição d, chame msd para cada grupo de 1 até
   256 com mais de um elemento, com d + 1. O grupo 0 já está pronto: são
   strings iguais.
3. Só chame strlen se precisar: s[d] já diz se a string acabou, desde que
   d nunca passe do fim (e não passa, porque o grupo 0 não desce).
4. Resposta esperada: o primeiro nível tem b(2) c(3) h(1) i(2) m(4) p(1)
   t(2); a ordem final vai de barcelos a tefe; strcmp confirma.

```bash
~/LPEDC/rodar 18-ordenacao-linear/lista/P1822.c
```

---

**Exercício P1823** · ★★★ · O ponto de encontro da turma: duas medianas

Nove amigos moram em esquinas de um bairro em grade, e cada um anda pelas
ruas (distância de Manhattan: |x1 - x2| + |y1 - y2| quarteirões). Em que
esquina marcar o churrasco para que a SOMA das distâncias seja a menor
possível?

Como a distância separa x e y, o problema se divide em dois de uma dimensão,
e em uma dimensão a soma de |x - p| é mínima na MEDIANA. Logo, o melhor
ponto é (mediana dos x, mediana dos y), e cada mediana sai de um
quickselect em Θ(n) médio, sem ordenar nada.

Escreva o quickselect (Lomuto, pivô no último; trabalhe em cópias, porque
ele bagunça o vetor) e mostre: o ponto das medianas e a soma das distâncias
nele; o "centro de massa" (médias arredondadas) e a soma nele; e o melhor
ponto por força bruta, testando todas as esquinas de 0 a 20 nos dois
eixos, para conferir.


```text
Saída esperada:
Medianas: (6, 5), soma 67
Centro de massa: (8, 7), soma 75
Força bruta: (6, 5), soma 67
```

**Dicas:**

1. Com n = 9 (ímpar), a mediana é o elemento de posição 4 (a partir de 0).
   Com n par, qualquer ponto entre os dois do meio serve.
2. As médias minimizam a soma dos QUADRADOS das distâncias. Quem mora longe
   puxa a média, mas não a mediana.
3. A força bruta testa 21 × 21 esquinas, cada uma com 9 distâncias: tudo
   bem para conferir, mas é Θ(L² n) contra Θ(n) das medianas.
4. Resposta esperada: medianas em (6, 5) com soma 67; o centro de massa
   (8, 7) dá 75; a força bruta confirma (6, 5) e 67.

```bash
~/LPEDC/rodar 18-ordenacao-linear/lista/P1823.c
```

---

**Exercício P1824** · ★★★ · Por dentro da análise do bucket sort

A análise do bucket sort no Cormen diz: com n valores uniformes em [0, 1)
e n baldes, o número n_i de itens no balde i segue uma distribuição
binomial, E[n_i²] = 2 - 1/n, e o tempo esperado é Θ(n). Confira no
computador.

Gere n = 10000 valores com o gerador do esqueleto, faça o bucket sort
completo (listas encadeadas com malloc, inserção em ordem contando as
comparações, concatenação, free de tudo) e mostre:

- o histograma da ocupação: quantos baldes ficaram com 0, 1, 2, ...
itens, ao lado do esperado pela aproximação de Poisson, n · e^(-1) / j!;
- a soma dos n_i², comparada com n · (2 - 1/n);
- as comparações da inserção, comparadas com a soma dos n_i (n_i - 1)/2
(o pior caso dentro de cada balde) e com n;
- se o vetor final ficou ordenado.


```text
Saída esperada:
itens  baldes  esperado
    0    3663      3679
    1    3736      3679
    2    1776      1839
    3     634       613
    4     149       153
    5      38        31
    6       4         5
Soma dos n_i²: 20024 (esperado n(2 - 1/n) = 19999)
Comparações: 4559 (pior caso nos baldes: 5012; n = 10000)
Ordenado: sim
```

**Dicas:**

1. valor = sorteia() / 4294967296.0 dá um double em [0, 1) a partir de um
   unsigned de 32 bits.
2. Guarde n_i num vetor ao inserir; o histograma é um counting sort dos
   n_i.
3. Poisson com média 1: P(j) = e^(-1) / j!. Calcule j! num laço e use
   exp(-1.0).
4. Resposta esperada: 3663 baldes vazios (Poisson: 3679), 3736 com 1 item,
   1776 com 2 e 634 com 3; soma dos n_i² 20024 (esperado 19999); 4559
   comparações, menos de uma por item; ordenado.

```bash
~/LPEDC/rodar 18-ordenacao-linear/lista/P1824.c
```

---

**Exercício P1825** · ★★★ · Counting sort sem vetor de saída: as camisas no lugar

O counting sort do Cormen precisa de um vetor de saída B do tamanho da
entrada. Quando a memória aperta, dá para ordenar NO LUGAR com poucas
chaves: conte, calcule onde começa e onde termina cada bloco, e vá
trocando cada item para dentro do seu bloco ("ciclos").

A loja tem 12 camisas de tamanhos P, M, G, GG e XG (chaves 0 a 4). Escreva:


```text
void ordena_no_lugar(Camisa v[], int n);
```


1. conte as chaves e calcule prox[k] (a próxima vaga do bloco k, começando
no início do bloco) e fim[k] (onde o bloco k termina);
2. para cada bloco k, enquanto prox[k] < fim[k]: olhe a camisa em
v[prox[k]]; se ela é do bloco k, avance prox[k]; senão, troque-a com
v[prox[chave]] e avance prox[chave].

Mostre o vetor antes e depois, o número de trocas (cada troca põe pelo
menos uma camisa no lugar definitivo: no máximo n) e se o resultado ficou
ESTÁVEL (compare a ordem dos códigos dentro de cada tamanho).


```text
Saída esperada:
antes:  G(1) XG(2) P(3) G(4) M(5) GG(6) M(7) P(8) XG(9) G(10) GG(11) M(12)
depois: P(3) P(8) M(7) M(12) M(5) G(1) G(10) G(4) GG(6) GG(11) XG(9) XG(2)
Trocas: 9 (n = 12) | estável: não
```

**Dicas:**

1. Comece prox[0] = 0 e prox[k] = prox[k - 1] + c[k - 1]; fim[k] =
   prox[k] + c[k] (calcule antes de mexer em prox).
2. A troca manda uma camisa direto para o seu bloco, na vaga prox[chave],
   que avança. A camisa que veio de lá é examinada na próxima volta, sem
   avançar prox[k].
3. É Θ(n + k) de tempo e Θ(k) de memória extra, mas NÃO é estável: as
   trocas embaralham os empates. Para um passo de radix sort, isso não
   serve.
4. Resposta esperada: P P M M M G G G GG GG XG XG, com 9 trocas, e não
   estável (o M 107 fica antes do M 105, por exemplo).

```bash
~/LPEDC/rodar 18-ordenacao-linear/lista/P1825.c
```

---

**Exercício P1826** · ★★★ · Os números mais sorteados: frequência, depois valor

Uma lotérica anotou as 40 dezenas (de 1 a 60) que saíram nos últimos
sorteios. Ela quer a lista reordenada pela FREQUÊNCIA, da dezena que mais
saiu para a que menos saiu, com as repetições juntas, e, no empate de
frequência, a dezena MENOR primeiro. Exemplo: se 7 saiu 3 vezes e 2 saiu
3 vezes, a lista começa 2 2 2 7 7 7.

Tudo em tempo linear, sem comparar elementos:

1. conte a frequência de cada dezena (counting, k = 61);
2. monte a lista das dezenas que apareceram em ordem crescente (é só
percorrer o vetor de contagem);
3. ordene essa lista com um counting sort ESTÁVEL pela chave
(maior_freq - freq), que põe as mais frequentes primeiro e preserva a
ordem crescente nos empates;
4. escreva cada dezena freq vezes.

Mostre as dezenas distintas com a frequência, na ordem final, e a lista
completa (10 por linha).


```text
Saída esperada:
Dezenas (frequência):
  6(3) 24(3) 36(3) 1(2) 25(2) 29(2) 50(2) 2(1) 3(1) 4(1)
  5(1) 8(1) 9(1) 17(1) 18(1) 23(1) 26(1) 28(1) 37(1) 38(1)
  44(1) 45(1) 47(1) 48(1) 49(1) 51(1) 52(1) 55(1) 56(1) 60(1)
Lista:
   6  6  6 24 24 24 36 36 36  1
   1 25 25 29 29 50 50  2  3  4
   5  8  9 17 18 23 26 28 37 38
  44 45 47 48 49 51 52 55 56 60
Total: 40 números
```

**Dicas:**

1. Os dados do esqueleto vêm de um gerador fixo: a saída é sempre a mesma.
2. A chave do passo 3 vai de 0 (as mais frequentes) a maior_freq - 1: o
   vetor C tem maior_freq posições.
3. Por que o passo 2 dispensa ordenação? O vetor de contagem já está
   indexado pela dezena: percorrê-lo de 1 a 60 dá as dezenas em ordem.
4. Resposta esperada: 6, 24 e 36 saíram 3 vezes e abrem a lista (6 6 6 24
   24 24 36 36 36); depois vêm 1, 25, 29 e 50, com 2; a lista tem 40
   números.

```bash
~/LPEDC/rodar 18-ordenacao-linear/lista/P1826.c
```

---

**Exercício P1827** · ★★★ · n números de 0 a n² - 1 em tempo linear

Exercício clássico do Cormen (8.3-4): ordenar n inteiros no intervalo
[0, n² - 1] em tempo O(n). O counting sort direto pagaria k = n². O radix
sort em base 10 faria lg₁₀(n²) passadas. O truque: use BASE n. Todo número
x < n² tem só dois "dígitos" nessa base, x % n e x / n, e cada passada
custa Θ(n + n) = Θ(n).

Uma cooperativa tem n = 1000 produtores, e cada código de lote vai de 0 a
999999 (= n² - 1). Ordene os códigos do esqueleto de três jeitos, contando
as operações (por passada: n na contagem + b nas somas + n na colocação +
n na cópia):

- counting sort direto, com k = n²;
- radix em base 10 (6 passadas);
- radix em base n (2 passadas).

Confira que os três dão o mesmo vetor e mostre as operações de cada um.


```text
Saída esperada:
counting direto (k = n²):  1003000 operações
radix base 10 (6 passadas):  18060 operações
radix base n (2 passadas):    8000 operações
Iguais: sim | menor 581, maior 999150
```

**Dicas:**

1. Escreva uma passada genérica que recebe o divisor e a base:
   dígito = (x / div) % base. Na base n, div vale 1 e depois n.
2. O counting direto é uma "passada" com base n² e div = 1: Θ(n + n²).
3. Fórmulas: direto 3n + n² = 1003000; base 10: 6 · (3n + 10) = 18060;
   base n: 2 · (3n + n) = 8000.
4. Resposta esperada: os três vetores iguais; 1003000, 18060 e 8000
   operações.

```bash
~/LPEDC/rodar 18-ordenacao-linear/lista/P1827.c
```

---

**Exercício P1828** · ★★★ · A entrada que derruba os saltos de Shell

Com os saltos de Shell (n/2, n/4, ..., 2, 1) e n potência de 2, TODOS os
saltos menores que n são pares, menos o último. Então, até a passada com
h = 1, as posições pares só são comparadas com posições pares, e as ímpares
com ímpares. Monte uma entrada que aproveita isso:

- as posições PARES recebem os n/2 maiores valores, em ordem crescente;
- as posições ÍMPARES recebem os n/2 menores, em ordem crescente.

Cada fileira de salto par já está ordenada: as passadas com h >= 2 não
movem nada. A última passada (insertion sort puro) tem de levar cada
pequeno da metade da frente até o seu lugar: Θ(n²).

Gere essa entrada para n = 1024 e n = 4096 (valores 0 a n - 1) e conte as
comparações do shell sort com os saltos de Shell, com os de Hibbard
(2^k - 1, todos ímpares) e com os de Knuth (3h + 1), mais o insertion sort
puro. Repita com um vetor sorteado do mesmo tamanho para comparar.


```text
Saída esperada:
n = 1024 (n²/8 = 131072)
                   ruim   sorteado
  Shell          140544      23965
  Hibbard          9998      15278
  Knuth            8792      14013
  insertion      132350     254622
n = 4096 (n²/8 = 2097152)
                   ruim   sorteado
  Shell         2143232     207201
  Hibbard         50192      79705
  Knuth           44720      78028
  insertion     2102270    4116375
```

**Dicas:**

1. Entrada ruim: para i de 0 a n/2 - 1, v[2i] = n/2 + i e v[2i + 1] = i.
2. Reaproveite uma função shell(v, n, saltos, ns) que conta comparações;
   cada sequência é só um vetor de saltos diferente.
3. Na última passada, o menor da metade da frente precisa andar até a
   posição certa: o i-ésimo pequeno anda cerca de n/2 - i casas. A soma é
   perto de n²/8.
4. Resposta esperada: com n = 4096 na entrada ruim, os saltos de Shell
   fazem 2143232 comparações (mais que o insertion puro, e perto de
   n²/8 = 2097152), enquanto Hibbard e Knuth ficam perto de 50 mil.

```bash
~/LPEDC/rodar 18-ordenacao-linear/lista/P1828.c
```

---

**Exercício P1829** · ★★★ · A classificação do campeonato com quatro critérios

No campeonato amador do Amazonas, a classificação segue os critérios, em
ordem: mais PONTOS, depois mais VITÓRIAS, depois maior SALDO de gols e, por
fim, ordem ALFABÉTICA. Os times chegam do sistema já em ordem alfabética.

Monte a tabela só com passadas estáveis de counting sort, da chave menos
significativa para a mais (o alfabeto já vem resolvido pela entrada):
saldo, vitórias e pontos, todas DECRESCENTES. O saldo vai de -30 a +30:
desloque a chave para ficar em 0..60. Mostre a ordem depois de cada
passada e a tabela final, e confira com o qsort e um comparador dos quatro
critérios.


```text
Saída esperada:
por saldo:     Tucu Tamb Boto Jara Arar Pira Peix Vito Onca Suma
por vitórias:  Tucu Boto Jara Tamb Peix Arar Pira Vito Onca Suma
por pontos:    Tucu Boto Jara Tamb Peix Arar Pira Vito Onca Suma
 #  Time           Pts  V  Saldo
 1  Tucunare        22  7    +11
 2  Boto Rosa       19  6     +8
 3  Jaraqui         19  6     +5
 4  Tambaqui        19  5     +9
 5  Peixe-Boi       15  5     -1
 6  Arara Azul      15  4     +3
 7  Pirarucu        15  4     +3
 8  Vitoria-Regia   10  3     -2
 9  Onca Pintada    10  2     -6
10  Sumauma          7  1    -12
qsort concorda: sim
```

**Dicas:**

1. Decrescente e estável: use a chave invertida (MAX - valor). Para o
   saldo, chave = 30 - saldo, que vai de 0 (saldo +30) a 60 (saldo -30).
2. A ordem das passadas é saldo, vitórias, pontos: a última decide o
   critério principal, e cada passada estável preserva os desempates das
   anteriores.
3. O qsort não é estável, mas aqui isso não importa: com o nome no
   comparador, não há dois times "iguais".
4. Resposta esperada: Tucunare (22 pts) em 1º; Boto e Jaraqui empatam em
   19 pontos e 6 vitórias, e o saldo (+8 contra +5) põe o Boto na frente;
   Arara e Pirarucu empatam em tudo menos no nome; o qsort concorda.

```bash
~/LPEDC/rodar 18-ordenacao-linear/lista/P1829.c
```

---

**Exercício P1830** · ★★★ · O log do servidor: IPs ordenados por radix base 256

O servidor do portal da prefeitura registrou os IPs de 16 acessos, como
strings "a.b.c.d". Para achar quem mais acessou, ordene os IPs e conte as
repetições, que ficam juntas.

Um IPv4 são 4 bytes: guarde cada um num unsigned de 32 bits
((a << 24) | (b << 16) | (c << 8) | d) e ordene com radix LSD em base 256,
4 passadas, uma por byte, do menos significativo (d) para o mais (a).
Escreva:


```text
unsigned ip_de(const char *s);          // com sscanf("%u.%u.%u.%u")
void ip_para(unsigned ip, char s[16]);  // de volta para "a.b.c.d"
void radix256(unsigned v[], int n);
```


Mostre os IPs distintos em ordem com o número de acessos e o IP que mais
acessou. Compare com a ordem das STRINGS: "10.0.0.9" vem depois de
"10.0.0.10" no strcmp, mas antes na ordem numérica.


```text
Saída esperada:
8.8.8.8         1 acesso
10.0.0.9        2 acessos
10.0.0.10       3 acessos
172.16.0.1      2 acessos
192.168.1.3     1 acesso
192.168.1.20    4 acessos
200.17.5.3      2 acessos
200.17.5.30     1 acesso
Distintos: 8 | quem mais acessou: 192.168.1.20 (4)
strcmp("10.0.0.9", "10.0.0.10") > 0: sim
```

**Dicas:**

1. Byte da passada p: (ip >> (8 * p)) & 255. São 4 passadas com C de 256
   posições: Θ(4(n + 256)).
2. Confira o retorno do sscanf: tem de ser 4. Cada parte tem de ser <= 255.
3. Depois de ordenar, um laço conta as repetições: enquanto v[j] == v[i],
   j++. O total de acessos de v[i] é j - i.
4. Resposta esperada: 8 IPs distintos; 10.0.0.9 antes de 10.0.0.10 e
   192.168.1.20 com 4 acessos é quem mais acessou.

```bash
~/LPEDC/rodar 18-ordenacao-linear/lista/P1830.c
```
