<!-- Gerado por _gerador a partir dos arquivos P????.c desta pasta. -->

# Lista prática · Módulo 09 · Arquivos e linha de comando

30 exercícios de codificar que treinam o módulo inteiro, misturando os assuntos, no ritmo da prova do PPGI (veja [PPGI.md](../../PPGI.md)). Cada arquivo `P????.c` desta pasta é um exercício: a resposta vai dentro dele, embaixo de `// Escreva sua resposta abaixo:`. Uma resolução de cada um está em `_respostas/09-arquivos/lista/`. Só olhe depois de tentar.

[Voltar ao módulo](../README.md)

## ★☆☆ Aquecimento

**Exercício P0901** · ★☆☆ · Calor de Manaus no arquivo

As máximas da semana em Manaus foram 33, 35, 31, 36, 34, 32 e 30 graus.
Grave os sete valores em /tmp/p0901_temps.txt, um por linha, com fprintf.
Feche o arquivo, abra de novo para leitura e leia os números com fscanf
até o arquivo acabar (sem saber de antemão quantos são). Mostre quantos
dias foram lidos, a maior máxima (e em que dia, contando de 1) e a média.
No fim, apague o arquivo com remove().


```text
Saída esperada:
Dias lidos: 7
Maior: 36 graus (dia 4)
Média: 33.0 graus
```

**Dicas:**

1. Grave com fprintf(arq, "%d\n", t[i]) e feche com fclose antes de
   reabrir em "r".
2. O laço de leitura é while (fscanf(arq, "%d", &t) == 1): o fscanf
   devolve quantos campos converteu e para no fim do arquivo.
3. Resposta esperada: 7 dias, maior 36 no dia 4, média 231 / 7 = 33.0.

```bash
~/LPEDC/rodar 09-arquivos/lista/P0901.c
```

---

**Exercício P0902** · ★☆☆ · Lista de chamada numerada

Grave em /tmp/p0902_chamada.txt os nomes da chamada do cursinho, um por
linha: Ana Clara, Bruno, Iara Souza e Joao. Depois leia o arquivo linha a
linha com fgets e mostre cada nome numerado e com o tamanho (sem contar o
'\n'). No fim, mostre quantas linhas o arquivo tinha e apague o arquivo.


```text
Saída esperada:
1: Ana Clara (9 caracteres)
2: Bruno (5 caracteres)
3: Iara Souza (10 caracteres)
4: Joao (4 caracteres)
Total: 4 linhas
```

**Dicas:**

1. fgets(linha, sizeof linha, arq) devolve NULL quando o arquivo acaba.
2. A linha lida vem com o '\n' no fim: tire com
   linha[strcspn(linha, "\n")] = '\0' antes do strlen.
3. Resposta esperada: a saída acima; sem tirar o '\n', cada tamanho sairia
   com 1 a mais.

```bash
~/LPEDC/rodar 09-arquivos/lista/P0902.c
```

---

**Exercício P0903** · ★☆☆ · O livro-caixa que esquece vendas

A padaria anota as vendas num arquivo texto. De manhã o programa grava
12, 30 e 8 reais; à tarde ele ACRESCENTA 25 e 15; no fim do dia ele lê
tudo e soma. O programa abaixo compila sem aviso, mas tem DOIS erros de
propósito e mostra só "Total do dia: R$ 0". Conserte para a saída ficar:


```text
Saída esperada:
Venda: 12
Venda: 30
Venda: 8
Venda: 25
Venda: 15
Total do dia: R$ 90
```

**Dicas:**

1. Que modo de abertura zera o arquivo? E qual escreve depois do fim?
2. O fprintf não vai direto para o disco: ele enche um buffer na memória,
   que só é despejado no fclose (ou quando enche). Se você abre o arquivo
   de novo para ler sem fechar o da escrita, a leitura não enxerga nada.
3. Resposta esperada: na tarde, troque "w" por "a" e acrescente
   fclose(arq) depois dos dois fprintf. A saída fica igual à de cima.

```bash
~/LPEDC/rodar 09-arquivos/lista/P0903.c
```

---

**Exercício P0904** · ★☆☆ · Quantos produtos tem o arquivo?

O main abaixo já grava 5 produtos em /tmp/p0904_produtos.bin. Escreva a
função


```text
long conta_registros(FILE *arq)
```


que descobre quantos registros Produto o arquivo tem SEM ler nenhum: vá
até o fim com fseek, pergunte a posição com ftell e divida pelo tamanho
de um registro. Depois, no main, leia só o ÚLTIMO produto, com um fseek
a partir do fim, e mostre-o. Num PC de 64 bits comum, cada Produto ocupa
16 bytes (4 do int, 4 de preenchimento, 8 do double).


```text
Saída esperada:
Tamanho do arquivo: 80 bytes
Registros: 5
Último: código 105, R$ 4.99
```

**Dicas:**

1. fseek(arq, 0, SEEK_END) e depois ftell(arq) dá o tamanho em bytes.
2. O último registro começa sizeof(Produto) bytes antes do fim:
   fseek(arq, -(long) sizeof(Produto), SEEK_END).
3. Resposta esperada: 80 bytes, 5 registros, último código 105 a R$ 4.99.

```bash
~/LPEDC/rodar 09-arquivos/lista/P0904.c
```

---

**Exercício P0905** · ★☆☆ · A cidade de nome mais comprido

Escreva um programa que recebe nomes de cidades pela linha de comando e
mostra quantos vieram e qual é o mais comprido (no empate, vale o
primeiro). Sem nenhum argumento, ele mostra como usar e termina com
return 1.


```text
$ ./rodar P0905.c manaus belem parintins tefe
```



```text
Saída esperada:
4 cidades
Maior nome: parintins (9 letras)
```


Sem argumentos, a saída é "uso: P0905 cidade1 cidade2 ...".

**Dicas:**

1. argc conta também o argv[0] (o nome do programa): as cidades são
   argv[1] até argv[argc - 1].
2. Guarde o ÍNDICE da maior e compare com strlen. Use > (e não >=) para
   o empate ficar com a primeira.
3. Resposta esperada: 4 cidades, maior nome parintins com 9 letras.

```bash
~/LPEDC/rodar 09-arquivos/lista/P0905.c
```

---

**Exercício P0906** · ★☆☆ · O recibo da conta de luz, letra por letra

Grave em /tmp/p0906_recibo.txt as três linhas do recibo:


```text
Consumo: 230 kWh
Tarifa: R$ 0.85
Total: R$ 195.50
```


(use fprintf e calcule o total no programa: 230 * 0.85). Depois reabra o
arquivo e leia-o UM CARACTERE POR VEZ com fgetc: mostre cada caractere
na tela com putchar e conte quantos caracteres e quantas linhas ('\n')
o arquivo tem. Apague o arquivo no fim.


```text
Saída esperada:
Consumo: 230 kWh
Tarifa: R$ 0.85
Total: R$ 195.50
3 linhas, 50 caracteres
```

**Dicas:**

1. fgetc devolve um int, não um char: guarde em int c e compare com EOF.
   Um char não consegue distinguir o EOF de um byte de verdade.
2. O laço é while ((c = fgetc(arq)) != EOF) { ... }.
3. Resposta esperada: 3 linhas e 50 caracteres (17 + 16 + 17, contando o
   '\n' de cada linha).

```bash
~/LPEDC/rodar 09-arquivos/lista/P0906.c
```

---

**Exercício P0907** · ★☆☆ · O aviso da feira em maiúsculas

Grave em /tmp/p0907_aviso.txt estas duas linhas:


```text
Bom dia, Manaus!
A feira abre as 6h.
```


Depois copie o arquivo, caractere por caractere, para
/tmp/p0907_grito.txt, trocando cada letra minúscula pela maiúscula (os
outros caracteres passam iguais). Por fim, mostre o conteúdo do segundo
arquivo lendo-o com fgets e apague os dois arquivos.


```text
Saída esperada:
BOM DIA, MANAUS!
A FEIRA ABRE AS 6H.
```

**Dicas:**

1. Abra os dois ao mesmo tempo: a origem em "r" e o destino em "w".
2. Leia com fgetc, converta com toupper (de ctype.h) e grave com fputc.
3. Resposta esperada: as duas linhas em maiúsculas, como acima.

```bash
~/LPEDC/rodar 09-arquivos/lista/P0907.c
```

---

**Exercício P0908** · ★☆☆ · Pulando de dois em dois no arquivo

Grave em /tmp/p0908_quadrados.bin, em binário, os quadrados de 1 a 10
(1, 4, 9, ..., 100) como int. Depois leia SÓ os que estão nas posições
ímpares da contagem humana (1º, 3º, 5º, 7º e 9º): leia um com fread e
pule o seguinte com fseek a partir da posição atual. Mostre os lidos e
quantos foram.


```text
Saída esperada:
1 9 25 49 81
Lidos: 5
```

**Dicas:**

1. Depois de cada fread de um int, o arquivo já andou 4 bytes. Para pular
   o próximo, fseek(arq, sizeof(int), SEEK_CUR).
2. O laço pode ser while (fread(&x, sizeof x, 1, arq) == 1): quando o
   fseek passa do fim, o fread seguinte devolve 0 e o laço para.
3. Resposta esperada: 1 9 25 49 81 e Lidos: 5.

```bash
~/LPEDC/rodar 09-arquivos/lista/P0908.c
```

---

**Exercício P0909** · ★☆☆ · O boletim que lê o aluno errado

O programa grava 4 alunos (matrícula e nota) em binário e depois lê os
registros 2, 0 e 3 com a função le_registro. Ele compila sem aviso, mas
mostra números sem sentido: a função tem um erro de propósito na conta da
posição. Conserte para a saída ficar:


```text
Saída esperada:
Registro 2: matrícula 2203, nota 7.5
Registro 0: matrícula 2201, nota 9.0
Registro 3: matrícula 2204, nota 4.0
```

**Dicas:**

1. O fseek conta em BYTES, não em registros.
2. O registro i começa no byte i * sizeof(Aluno).
3. Resposta esperada: fseek(arq, i * (long) sizeof(Aluno), SEEK_SET). A
   saída fica igual à de cima.

```bash
~/LPEDC/rodar 09-arquivos/lista/P0909.c
```

---

**Exercício P0910** · ★☆☆ · Os preços da feira pela linha de comando

Os preços chegam pela linha de comando. Grave cada um em
/tmp/p0910_precos.txt, um por linha e com duas casas. Feche, reabra para
leitura, some tudo com fscanf e mostre quantos preços foram gravados e o
total. Sem argumentos, mostre "uso: P0910 preco1 preco2 ..." e termine
com return 1. Apague o arquivo no fim.


```text
$ ./rodar P0910.c 12.50 3.99 7.00
```



```text
Saída esperada:
3 preços gravados
Total: R$ 23.49
```

**Dicas:**

1. argv[i] é texto: atof(argv[i]) transforma "12.50" em 12.5.
2. Grave com fprintf(arq, "%.2f\n", preco) e leia com fscanf(arq, "%lf",
   &preco) num while que confere se devolveu 1.
3. Resposta esperada: 3 preços gravados e Total: R$ 23.49.

```bash
~/LPEDC/rodar 09-arquivos/lista/P0910.c
```

## ★★☆ Para pensar

**Exercício P0911** · ★★☆ · Só os aprovados vão para o outro arquivo

Grave em /tmp/p0911_turma.txt a turma do cursinho, uma pessoa por linha
(nome e duas notas):


```text
Ana 7.0 8.0
Beto 5.0 4.5
Caio 6.0 6.0
Dani 9.5 8.5
Edu 3.0 7.0
```


Depois leia esse arquivo com fscanf e escreva em /tmp/p0911_aprovados.txt
só quem tem média >= 6, no formato "nome média" (duas casas). Por fim,
mostre o arquivo dos aprovados (lendo com fgets), quantos passaram e
apague os dois arquivos.


```text
Saída esperada:
Ana 7.50
Caio 6.00
Dani 9.00
Aprovados: 3 de 5
```

**Dicas:**

1. Leia cada linha com fscanf(ent, "%19s %lf %lf", nome, &n1, &n2) e
   pare quando o retorno for diferente de 3.
2. Deixe os dois arquivos abertos ao mesmo tempo: o da turma em "r" e o
   dos aprovados em "w". Feche o de escrita antes de reabrir para ler.
3. Resposta esperada: Ana 7.50, Caio 6.00, Dani 9.00 e Aprovados: 3 de 5.

```bash
~/LPEDC/rodar 09-arquivos/lista/P0911.c
```

---

**Exercício P0912** · ★★☆ · Tirando um produto do catálogo

Um arquivo binário não tem "apagar registro do meio". O jeito clássico é
copiar todos os registros, MENOS o que sai, para um arquivo novo. Escreva


```text
int remove_produto(const char *origem, const char *destino, int codigo)
```


que faz essa cópia e devolve quantos registros foram para o destino (ou
-1 se não conseguir abrir algum arquivo). O main grava 5 produtos em
/tmp/p0912_catalogo.bin, remove o código 103 gerando
/tmp/p0912_novo.bin, lista o arquivo novo e apaga os dois no fim.


```text
Saída esperada:
Antes: 5 produtos
Depois: 4 produtos
101 Arroz        R$  24.90
102 Feijao       R$   8.75
104 Farinha      R$   6.40
105 Cafe         R$  17.30
```

**Dicas:**

1. Abra a origem em "rb" e o destino em "wb". Leia um registro por vez
   com fread e só chame fwrite se o código for diferente do que sai.
2. Para listar, um while (fread(&p, sizeof p, 1, arq) == 1) basta.
3. Resposta esperada: Depois: 4 produtos, sem o 103 (Acucar) na lista.

```bash
~/LPEDC/rodar 09-arquivos/lista/P0912.c
```

---

**Exercício P0913** · ★★☆ · Busca binária no cadastro do cursinho

O arquivo de alunos está ORDENADO por matrícula, então dá para achar um
aluno lendo poucos registros: olhe o do meio com fseek e fread e descarte
a metade que não pode ter a matrícula. Escreva


```text
int busca(FILE *arq, int n, int matricula, Aluno *achado, int *leituras)
```


que devolve 1 se achou (e copia o aluno para *achado) ou 0 se não achou,
e conta em *leituras quantos fread fez. O main grava os 8 alunos e
procura 2041, 2007 e 2050. O n (quantos registros) deve ser calculado
pelo tamanho do arquivo, não escrito à mão.


```text
Saída esperada:
8 alunos no arquivo
2041: Kaio (2 leituras)
2007: Bruna (2 leituras)
2050: não encontrada (4 leituras)
```

**Dicas:**

1. n = ftell depois de fseek(arq, 0, SEEK_END), dividido por sizeof(Aluno).
2. Com ini = 0 e fim = n - 1: meio = (ini + fim) / 2, fseek para
   meio * sizeof(Aluno), fread, compare. Menor: ini = meio + 1; maior:
   fim = meio - 1. Pare quando ini > fim.
3. Resposta esperada: a saída acima. Com 8 registros, nenhuma busca passa
   de 4 leituras (piso de log2 8, mais 1).

```bash
~/LPEDC/rodar 09-arquivos/lista/P0913.c
```

---

**Exercício P0914** · ★★☆ · O extrato com sujeira

O app do banco exportou os valores do mês num arquivo texto, separados
por espaço, mas alguns campos vieram corrompidos. Grave em
/tmp/p0914_extrato.txt exatamente esta linha:


```text
150 abc 32 -10 x9 20 7a
```


Depois leia o arquivo palavra por palavra com fscanf("%31s") e use
strtol para decidir se cada palavra é um inteiro válido (a palavra
inteira tem que ser número). Some os válidos e mostre, na ordem, os que
foram ignorados. Apague o arquivo no fim.


```text
Saída esperada:
Válidos: 4 (soma 192)
Ignorados: abc x9 7a
```

**Dicas:**

1. long v = strtol(palavra, &fim, 10): fim aponta para o primeiro
   caractere que NÃO entrou no número.
2. A palavra é um número válido se fim != palavra (leu algum dígito) e
   *fim == '\0' (não sobrou nada). O "7a" para no 'a': inválido.
3. Resposta esperada: válidos 150, 32, -10 e 20 (soma 192); ignorados
   abc, x9 e 7a.

```bash
~/LPEDC/rodar 09-arquivos/lista/P0914.c
```

---

**Exercício P0915** · ★★☆ · A média com modo detalhado

As notas chegam pela linha de comando. Se o PRIMEIRO argumento for "-v"
(de verboso), o programa mostra cada nota antes da média; sem "-v", mostra
só a média. Sem nenhuma nota (inclusive quando só veio o "-v"), ele mostra
"uso: P0915 [-v] nota1 nota2 ..." e termina com return 1.


```text
$ ./rodar P0915.c -v 7 8 9.5
```



```text
Saída esperada:
nota 1: 7.0
nota 2: 8.0
nota 3: 9.5
Média: 8.17
```


Com ./rodar P0915.c 7 8 9.5 sai só a linha "Média: 8.17".

**Dicas:**

1. Compare com strcmp(argv[1], "-v") == 0, mas só se argc >= 2.
2. Use uma variável "primeira" com o índice da primeira nota: 2 com o
   "-v", 1 sem ele. O número de notas é argc - primeira.
3. Resposta esperada: com -v, as três notas e Média: 8.17 (24.5 / 3).

```bash
~/LPEDC/rodar 09-arquivos/lista/P0915.c
```

---

**Exercício P0916** · ★★☆ · A linha mais comprida do poema

Grave em /tmp/p0916_poema.txt estas quatro linhas:


```text
Choveu em Manaus
o rio subiu devagar
e a balsa atrasou
fim
```


Depois leia o arquivo com fgets e mostre qual é a linha mais comprida e
qual é a mais curta (número da linha, tamanho sem o '\n' e o texto).
Apague o arquivo no fim.


```text
Saída esperada:
Mais comprida: linha 2 (19 caracteres): o rio subiu devagar
Mais curta: linha 4 (3 caracteres): fim
```

**Dicas:**

1. Guarde o texto da maior e da menor em dois vetores de char com strcpy,
   porque o vetor da leitura é sobrescrito a cada fgets.
2. Tire o '\n' com linha[strcspn(linha, "\n")] = '\0' antes de medir.
3. Resposta esperada: linha 2 com 19 caracteres e linha 4 com 3.

```bash
~/LPEDC/rodar 09-arquivos/lista/P0916.c
```

---

**Exercício P0917** · ★★☆ · Virar o arquivo do avesso no lugar

O medidor de pressão gravou 6 leituras em /tmp/p0917_pressao.bin, em
binário: 120, 118, 125, 130, 122 e 119. Inverta a ordem DENTRO do próprio
arquivo, sem carregar tudo num vetor: abra com "rb+" e, para cada i de 0
até n/2 - 1, leia o registro i e o registro n-1-i e grave cada um no
lugar do outro. Mostre o arquivo antes e depois.


```text
Saída esperada:
Antes:  120 118 125 130 122 119
Depois: 119 122 130 125 118 120
```

**Dicas:**

1. Escreva duas funções pequenas: int le(FILE *arq, int i) e
   void grava(FILE *arq, int i, int valor), cada uma com um fseek para
   i * sizeof(int) antes do fread ou fwrite.
2. Num arquivo aberto com "+", sempre faça um fseek entre uma leitura e
   uma escrita: a regra do C exige isso para trocar de direção.
3. Resposta esperada: Depois: 119 122 130 125 118 120 (só 3 trocas para
   6 registros).

```bash
~/LPEDC/rodar 09-arquivos/lista/P0917.c
```

---

**Exercício P0918** · ★★☆ · Salvar e carregar o orçamento da reforma

Complete as duas funções do programa:


```text
int salva(const char *caminho, const Item *itens, int n)
int carrega(const char *caminho, Item *itens, int max)
```


O formato do arquivo texto é: na 1ª linha, quantos itens vêm; depois, um
item por linha, "descricao quantidade preco". salva devolve 1 se deu
certo. carrega lê no máximo max itens e devolve quantos leu (ou -1 se não
abriu o arquivo). O main já grava, carrega num OUTRO vetor e mostra.


```text
Saída esperada:
Carregados: 3 itens
cimento      10 x R$  32.90 = R$  329.00
areia         3 x R$ 120.00 = R$  360.00
tijolo      500 x R$   0.85 = R$  425.00
Total: R$ 1114.00
```

**Dicas:**

1. Em salva: fprintf(arq, "%d\n", n) e depois um fprintf por item.
2. Em carrega: leia o n com fscanf, e no laço pare em i < n e i < max.
   Confira se cada fscanf devolveu 3.
3. Resposta esperada: a saída acima; o total é 329 + 360 + 425 = 1114.

```bash
~/LPEDC/rodar 09-arquivos/lista/P0918.c
```

---

**Exercício P0919** · ★★☆ · A votação em que o "sim" nunca vence

O condomínio votou a troca do portão, e cada voto ficou numa linha do
arquivo: sim, nao, sim, sim. O programa abaixo compila sem aviso, mas
mostra "Votos sim: 2, não: 2, inválidos: 0", um empate que não houve.
Há DOIS erros de propósito:
um faz toda comparação falhar e outro faz a ÚLTIMA linha ser contada
diferente das outras quando o arquivo não termina com '\n'. Conserte
os dois (sem mudar o que é gravado no arquivo).


```text
Saída esperada:
Votos sim: 3, não: 1, inválidos: 0
```

**Dicas:**

1. O que o fgets guarda no vetor, além das letras? Acrescente um
   printf("[%s]\n", linha) no laço e rode para ver.
2. Cortar o último caractere "na marra" (linha[strlen(linha) - 1] = '\0')
   estraga a linha que não tem '\n': ela perde uma letra de verdade.
3. Resposta esperada: troque o corte na marra por
   linha[strcspn(linha, "\n")] = '\0' e compare com strcmp(...) == 0 (o
   código compara com != 0). A saída fica igual à de cima.

```bash
~/LPEDC/rodar 09-arquivos/lista/P0919.c
```

---

**Exercício P0920** · ★★☆ · A planilha de vendas no arquivo

Três vendedores da loja de açaí, quatro semanas (em reais):


```text
vendedor 1: 120  90 150  80
vendedor 2: 200 110  70 130
vendedor 3:  95 140 160 100
```


Grave essa matriz 3 x 4 em /tmp/p0920_vendas.txt, uma linha por vendedor.
Depois leia o arquivo para OUTRA matriz com fscanf e mostre o total de
cada semana e o vendedor que mais vendeu no mês. Apague o arquivo no fim.


```text
Saída esperada:
Semana 1: R$ 415
Semana 2: R$ 340
Semana 3: R$ 380
Semana 4: R$ 310
Melhor vendedor: 2 (R$ 510)
```

**Dicas:**

1. Grave com dois for: fprintf(arq, "%d ", v[i][j]) e, no fim da linha,
   fprintf(arq, "\n"). O fscanf("%d") pula espaços e quebras de linha.
2. Total da semana j: some a coluna j. Total do vendedor i: some a linha i.
3. Resposta esperada: semanas 415, 340, 380 e 310; o vendedor 2, com 510.

```bash
~/LPEDC/rodar 09-arquivos/lista/P0920.c
```

## ★★★ Desafio

**Exercício P0921** · ★★★ · A agenda que se mantém em ordem no disco

Uma agenda guarda contatos (nome e telefone) num arquivo binário SEMPRE
em ordem alfabética, para que a busca seja binária. Escreva:


```text
void insere(FILE *arq, const Contato *novo, int *deslocados)
  acha a posição do novo lendo o arquivo do começo; depois empurra uma
  posição para a frente cada registro que fica depois dele (do último
  para trás, para não sobrescrever ninguém) e grava o novo no buraco.
  Conta em *deslocados quantos registros foram empurrados.
int busca(FILE *arq, const char *nome, Contato *achado, int *leituras)
  busca binária pelo nome, contando os fread.
```


No main, abra /tmp/p0921_agenda.bin com "wb+" e insira, nesta ordem:
Marta 92 99100-0001, Bia 92 99100-0002, Rui 92 99100-0003,
Caio 92 99100-0004 e Ana 92 99100-0005. Liste a agenda, mostre o total
de deslocamentos e procure Caio e Zeca. Apague o arquivo no fim.


```text
Saída esperada:
0 Ana     92 99100-0005
1 Bia     92 99100-0002
2 Caio    92 99100-0004
3 Marta   92 99100-0001
4 Rui     92 99100-0003
Deslocamentos: 7
Caio: 92 99100-0004 (1 leitura)
Zeca: não está na agenda (3 leituras)
```

**Dicas:**

1. O número de registros é o tamanho do arquivo (fseek até o fim, ftell)
   dividido por sizeof(Contato). Faça funções le(arq, i, &c) e
   grava(arq, i, &c) com o fseek certo dentro.
2. Para abrir o buraco na posição pos: for (i = n - 1; i >= pos; i--),
   leia o registro i e grave-o em i + 1. Depois grave o novo em pos.
3. Deslocamentos: Marta 0, Bia 1, Rui 0, Caio 2 e Ana 4, total 7. É o
   custo de manter a ordem: inserir é O(n), mas buscar fica O(log n).
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 09-arquivos/lista/P0921.c
```

---

**Exercício P0922** · ★★★ · O banquinho do bairro processa o dia

O banco comunitário guarda as contas em binário e recebe as operações do
dia num arquivo texto. Escreva um programa que:

1. grave em /tmp/p0922_contas.bin as contas 101 Ana R$ 500.00,

```text
 102 Beto R$ 120.00 e 103 Caio R$ 0.00;
```

2. grave em /tmp/p0922_dia.txt as operações, uma por linha:


```text
D 103 250.00
S 102 200.00
S 101 80.50
T 101 103 100.00
S 104 10.00
```



```text
 (D = depósito, S = saque, T = transferência da 1ª conta para a 2ª);
```

3. leia as operações com fscanf e aplique cada uma DIRETO no arquivo de

```text
 contas (abra com "rb+", ache o registro, altere e regrave). Saque ou
 transferência sem saldo é recusado; conta que não existe também;
```

4. mostre o resultado de cada operação e os saldos finais, e apague os

```text
 dois arquivos.
```



```text
Saída esperada:
D 103 250.00: ok
S 102 200.00: saldo insuficiente
S 101 80.50: ok
T 101 103 100.00: ok
S 104 10.00: conta inexistente
101 Ana    R$  319.50
102 Beto   R$  120.00
103 Caio   R$  350.00
```

**Dicas:**

1. Escreva long acha(FILE *arq, int numero, Conta *c), que percorre o
   arquivo e devolve a posição do registro (ou -1), e
   void regrava(FILE *arq, long pos, const Conta *c).
2. Leia o tipo com fscanf(op, " %c %d", &tipo, &num): o espaço antes do
   %c pula o '\n' da linha anterior. Na transferência, leia mais um %d.
3. Numa transferência, confira as duas contas e o saldo ANTES de mexer em
   qualquer uma: ou as duas mudam, ou nenhuma.
4. Resposta esperada: a saída acima (Ana: 500 - 80.50 - 100 = 319.50).

```bash
~/LPEDC/rodar 09-arquivos/lista/P0922.c
```

---

**Exercício P0923** · ★★★ · O índice de linhas do cardápio

Num arquivo texto, cada linha tem um tamanho, então não dá para calcular
onde começa a linha k como num arquivo de registros. Mas dá para montar um
ÍNDICE: leia o arquivo uma vez e anote, num vetor de long, a posição
(ftell) do começo de cada linha. Depois, qualquer linha é um fseek e um
fgets, sem reler o arquivo.

Grave em /tmp/p0923_cardapio.txt estas 6 linhas:


```text
Tacaca na esquina
Pirarucu de casaca
Tucupi no pato
Bolo de macaxeira
Cupuacu gelado
Pupunha com cafe
```


Monte o índice (no máximo 100 linhas) e mostre as linhas 5, 2, 6 e 9,
nesta ordem, com o byte onde cada uma começa. Apague o arquivo no fim.


```text
Saída esperada:
6 linhas indexadas
Linha 5 (byte 70): Cupuacu gelado
Linha 2 (byte 18): Pirarucu de casaca
Linha 6 (byte 85): Pupunha com cafe
Linha 9: não existe
```

**Dicas:**

1. Antes de cada fgets da primeira passada, pos[n] = ftell(arq).
2. Para mostrar a linha k: fseek(arq, pos[k - 1], SEEK_SET) e um fgets.
3. A linha 2 começa no byte 18 porque a linha 1 tem 17 letras mais o '\n'.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 09-arquivos/lista/P0923.c
```

---

**Exercício P0924** · ★★★ · Os produtos entre R$ 10 e R$ 20

O arquivo binário do mercadinho tem 10 produtos ORDENADOS por preço (em
centavos, para não ter erro de arredondamento):


```text
299 Agua, 450 Pao, 699 Leite, 899 Biscoito, 1050 Cafe, 1290 Queijo,
1599 Mel, 1890 Manteiga, 2100 Sabao, 3490 Azeite
```


Para listar os que custam de R$ 10,00 a R$ 20,00 sem ler o arquivo todo,
faça uma busca binária que acha a POSIÇÃO do primeiro produto com preço
>= 1000 e, de lá, leia em sequência enquanto o preço for <= 2000. Escreva


```text
long primeiro_maior_igual(FILE *arq, long n, int alvo, int *leituras)
```


que devolve a primeira posição com preço >= alvo (ou n, se não houver) e
conta os fread da busca. Grave o arquivo em /tmp/p0924_precos.bin no
próprio programa e apague-o no fim.


```text
Saída esperada:
Busca: 4 leituras, primeiro na posição 4
R$ 10.50 Cafe
R$ 12.90 Queijo
R$ 15.99 Mel
R$ 18.90 Manteiga
4 produtos na faixa
```

**Dicas:**

1. Use o intervalo meio aberto [ini, fim) com ini = 0 e fim = n. Se o
   preço do meio é >= alvo, a resposta está em [ini, meio]: fim = meio.
   Senão, ini = meio + 1. Pare quando ini == fim; a resposta é ini.
2. Essa busca nunca para "porque achou": ela sempre estreita até sobrar
   uma posição, por isso funciona até se nenhum produto custar 1000 exato.
3. Resposta esperada: a saída acima (meios lidos: 5, 2, 4 e 3).

```bash
~/LPEDC/rodar 09-arquivos/lista/P0924.c
```

---

**Exercício P0925** · ★★★ · Ordenar a fila da vacina dentro do arquivo

O posto de saúde tem a lista de espera da vacina num arquivo binário, e a
regra é: mais velho primeiro. O arquivo pode ser grande demais para a
memória, então ordene-o NO DISCO, com a ordenação por seleção: para cada
posição i, procure (lendo do arquivo) o paciente mais velho entre i e o
fim e troque-o com o da posição i. Nunca guarde mais que 3 registros na
memória ao mesmo tempo, e conte quantos fread e quantos fwrite fez.

Grave em /tmp/p0925_fila.bin: Ana 34, Beto 71, Ceci 18, Davi 65, Eva 80,
Fabio 42. Ordene, liste e apague o arquivo. Só faça a troca (2 fwrite)
quando o mais velho não estiver já na posição i.


```text
Saída esperada:
1. Eva    80 anos
2. Beto   71 anos
3. Davi   65 anos
4. Fabio  42 anos
5. Ana    34 anos
6. Ceci   18 anos
Leituras: 20, escritas: 6
```

**Dicas:**

1. Na passada i, leia o registro i (ele é o "mais velho até agora") e
   depois cada j de i + 1 a n - 1. São 1 + (n - 1 - i) leituras.
2. Com n = 6 há 5 passadas: 6 + 5 + 4 + 3 + 2 = 20 leituras. A seleção
   sempre lê a mesma quantidade, esteja o arquivo como estiver: Θ(n²).
3. Só 3 passadas precisam trocar (i = 0, 2 e 3): 6 escritas.
4. Resposta esperada: a saída acima. Não conte as leituras da listagem.

```bash
~/LPEDC/rodar 09-arquivos/lista/P0925.c
```

---

**Exercício P0926** · ★★★ · Compactar a leitura do sensor (RLE)

O sensor da estufa manda uma letra por minuto (A = ok, B = quente,
C = seco, D = desligado) e repete muito: "AAAAABBBCCCCCCCCDAA". A
codificação RLE guarda cada SEQUÊNCIA como um par (quantidade, letra):
5A 3B 8C 1D 2A. Escreva:


```text
int compacta(const char *texto, const char *caminho)
  grava os pares em binário (struct Par com unsigned char qtd e char c)
  e devolve quantos pares gravou (-1 se não abriu o arquivo);
int descompacta(const char *caminho, char *saida, int max)
  lê os pares e remonta o texto em saida (no máximo max - 1 letras,
  mais o '\0'), devolvendo o tamanho remontado.
```


Use /tmp/p0926_sensor.rle, mostre os tamanhos, os pares, o texto
remontado e se ele confere com o original. Apague o arquivo no fim.


```text
Saída esperada:
Original: 19 bytes
Compactado: 10 bytes (5 pares)
5xA 3xB 8xC 1xD 2xA
Descompactado: AAAAABBBCCCCCCCCDAA
Confere: sim
```

**Dicas:**

1. Para compactar, ande com i pelo texto; conte quantas letras iguais a
   texto[i] vêm seguidas (no máximo 255, que é o limite do unsigned char)
   e grave o par. Depois pule essa sequência.
2. O tamanho do arquivo vem de fseek até o fim e ftell. Cada Par ocupa
   2 bytes (dois campos de 1 byte, sem preenchimento).
3. Resposta esperada: a saída acima. RLE compensa com muita repetição; com
   "ABCD" o arquivo ficaria com o DOBRO do tamanho.

```bash
~/LPEDC/rodar 09-arquivos/lista/P0926.c
```

---

**Exercício P0927** · ★★★ · O cadastro da clínica veterinária

A clínica cadastra um pet por vez num arquivo binário e depois lista
todos e mostra o pet do meio do arquivo. O programa abaixo compila sem
aviso, mas não lista nada. Ele tem TRÊS erros de propósito, um em cada
função de arquivo. Conserte os três para a saída ficar:


```text
Saída esperada:
Rex: 3 anos, 12.5 kg
Mimi: 5 anos, 4.2 kg
Thor: 2 anos, 30.0 kg
Do meio: Mimi
```

**Dicas:**

1. cadastra é chamada uma vez por pet. Com que modo de abertura cada
   chamada preserva os pets anteriores?
2. Dentro de cadastra, p é um ponteiro. Quanto vale sizeof p? E quanto
   vale sizeof *p?
3. O registro do meio é o n / 2, contado a partir de onde?
4. Resposta esperada: "wb" vira "ab"; sizeof p vira sizeof *p; e o fseek
   de le_meio usa SEEK_SET em vez de SEEK_END. A saída fica igual à de
   cima.

```bash
~/LPEDC/rodar 09-arquivos/lista/P0927.c
```

---

**Exercício P0928** · ★★★ · A tabela do Barezão

Os jogos da rodada do campeonato estão num arquivo texto, um por linha,
no formato "mandante gols visitante gols". Grave em /tmp/p0928_jogos.txt:


```text
Nacional 2 Fast 1
Manaus 1 Amazonas 1
Fast 0 Manaus 3
Amazonas 2 Nacional 2
Nacional 1 Manaus 0
Amazonas 3 Fast 1
```


Leia os jogos com fscanf e monte a tabela num vetor de structs (nome,
pontos, vitórias, saldo de gols): vitória vale 3, empate 1. Ordene com
qsort por pontos (maior primeiro), depois saldo, depois nome. Grave a
classificação em /tmp/p0928_tabela.txt, mostre esse arquivo lendo com
fgets e apague os dois.


```text
Saída esperada:
1. Nacional   7 pts  2 V  saldo +2
2. Amazonas   5 pts  1 V  saldo +2
3. Manaus     4 pts  1 V  saldo +2
4. Fast       0 pts  0 V  saldo -6
```

**Dicas:**

1. Escreva int acha_ou_cria(Time t[], int *n, const char *nome), que
   devolve o índice do time no vetor e o cria (zerado) se ainda não existe.
2. Para cada jogo, atualize os dois times: saldo += gols feitos - gols
   sofridos; pontos e vitórias conforme o placar.
3. O "%+d" do printf mostra o sinal sempre: +2, -6.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 09-arquivos/lista/P0928.c
```

---

**Exercício P0929** · ★★★ · O recado cifrado da linha de comando

A cifra de César troca cada letra pela que está k posições adiante no
alfabeto (com k = 3, a vira d, x vira a). Escreva um programa chamado
assim:


```text
$ ./rodar P0929.c 3 ataque ao amanhecer
```


O primeiro argumento é a chave k; os outros são as palavras do recado. O
programa cifra o recado (palavras separadas por um espaço), grava o texto
cifrado em /tmp/p0929_recado.txt (sem '\n' no fim), lê o arquivo de
volta, mostra o cifrado e o tamanho do arquivo, decifra o que leu (chave
-k) e mostra o recado de novo. Maiúsculas giram dentro de A-Z, e o que
não é letra passa igual. Se faltar argumento ou a chave não for número,
mostre "uso: P0929 chave palavra1 palavra2 ..." e termine com return 1.


```text
Saída esperada:
Cifrado: dwdtxh dr dpdqkhfhu
Arquivo: 19 bytes
Decifrado: ataque ao amanhecer
```

**Dicas:**

1. Para girar uma minúscula: 'a' + ((c - 'a' + k) % 26 + 26) % 26. O
   "+ 26) % 26" conserta o resto negativo quando k é negativo.
2. Valide a chave com strtol e o ponteiro de fim, como no assunto 0069.
3. Grave com fputc letra por letra (e um espaço entre as palavras) e leia
   de volta com fgets.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 09-arquivos/lista/P0929.c
```

---

**Exercício P0930** · ★★★ · O índice da biblioteca

Os livros da biblioteca estão num arquivo de dados na ordem em que
chegaram, então a busca por código seria sequencial. A solução dos bancos
de dados é um ÍNDICE: um segundo arquivo, pequeno e ordenado, com pares
(código, posição no arquivo de dados). Busca-se no índice (binária) e
depois se vai direto ao registro com um fseek.

1. Grave em /tmp/p0930_dados.bin, nesta ordem: 3071 Vidas Secas 1938,

```text
 1150 Macunaima 1928, 4420 Iracema 1865, 2088 Dom Casmurro 1899,
 1999 O Cortico 1890 e 3500 Grande Sertao 1956.
```

2. Monte um vetor de Entrada {codigo, posicao}, ordene com qsort e grave

```text
 em /tmp/p0930_indice.bin.
```

3. Escreva long procura(FILE *indice, int codigo, int *leituras): busca

```text
 binária NO ARQUIVO de índice que devolve a posição no arquivo de dados
 (ou -1), contando os fread.
```

4. Procure 2088, 4420 e 1000, leia o livro no arquivo de dados e mostre.

```text
 Apague os dois arquivos no fim.
```



```text
Saída esperada:
Índice: 1150 1999 2088 3071 3500 4420
2088: Dom Casmurro (1899), registro 3, 1 leitura no índice
4420: Iracema (1865), registro 2, 3 leituras no índice
1000: não cadastrado, 2 leituras no índice
```

**Dicas:**

1. O índice tem n entradas: o tamanho do arquivo de índice dividido por
   sizeof(Entrada).
2. Achou a entrada? fseek(dados, e.posicao * sizeof(Livro), SEEK_SET) e
   um fread trazem o livro.
3. Por que não ordenar o próprio arquivo de dados? Porque registros
   grandes custam caro para mover, e dá para ter vários índices (por
   código, por ano...) sobre os mesmos dados.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 09-arquivos/lista/P0930.c
```
