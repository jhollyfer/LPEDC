# Módulo 09 · Arquivos e linha de comando

Como fazer o programa **lembrar** depois de terminar: arquivos texto, arquivos
binários com acesso direto a um registro e argumentos da linha de comando.
Depende de structs (módulo 08), `fgets` (0042) e ponteiros; prepara o módulo
10 e a busca binária em disco (0090).

## O que você vai aprender

- abrir, escrever, ler e fechar **arquivos texto** (`fopen`, `fprintf`, `fgets`, `fscanf`, `fgetc`, `fclose`)
- os modos `"r"`, `"w"` e `"a"`, o **buffer** e por que nunca usar `while (!feof(f))`
- **arquivos binários** com `fwrite` e `fread`, e acesso direto a um registro com `fseek` e `ftell`
- quando escolher texto e quando escolher binário
- receber dados por `argc` e `argv`, converter com `strtol` e `strtod` e devolver o **código de saída**
- juntar tudo numa ferramenta de terminal com subcomandos

## Antes de começar

Os exemplos gravam em `/tmp` e quase todos apagam o arquivo no fim com
`remove`; quando um o deixa lá, o comentário avisa. Nenhum depende de arquivo
pré-existente. Para passar argumentos, escreva-os depois do executável:

```bash
gcc ~/LPEDC/material/A137.c -o ~/LPEDC/material/A137 && ~/LPEDC/material/A137 -r 7 -a 4
```

Duas ferramentas mostram o que os programas gravam: `od -A d -t x1 arquivo`
(bytes em hexadecimal, já vem no sistema) e o `strace` (chamadas ao sistema,
como cada `write`):

```bash
sudo pacman -S strace       # Arch Linux
sudo apt install strace     # Debian / Ubuntu
```

{{indice}}

---

{{assuntos}}

---

### Desafios do módulo

Problemas do médio ao difícil. Crie os arquivos de teste com
`printf '...' > /tmp/teste.txt`.

**1. O seu `cp`.** Escreva `copia <origem> <destino>`, que copia qualquer
arquivo (texto ou não) byte a byte. Confira o `argc`, os dois `fopen` e mostre
quantos bytes copiou. Teste copiando o próprio executável e comparando com
`cmp`.

<details><summary>Resposta</summary>

Abra a origem com `"rb"` e o destino com `"wb"`. Se o segundo `fopen` falhar,
feche o primeiro. O laço é `while ((c = fgetc(ent)) != EOF) { fputc(c, sai);
n++; }` com `int c`. Com `char c`, um byte 0xFF no meio do arquivo vira -1 e o
laço para antes da hora e a cópia de um executável sai cortada. Use o modo
`b` para funcionar no Windows também.

</details>

**2. O seu `tac`.** Mostre as linhas de um arquivo de trás para frente. O
arquivo pode ter qualquer quantidade de linhas (até 255 caracteres cada).
Para `printf 'um\ndois\ntres\n'`, a saída é `tres`, `dois`, `um`.

<details><summary>Resposta</summary>

Leia com `fgets` e guarde cada linha num vetor de `char *` que cresce com
`realloc` (dobrando a capacidade), com uma cópia de cada linha feita com
`malloc` + `strcpy`. Depois imprima do último para o primeiro e libere cada
linha e o vetor. Outro caminho, sem guardar tudo: anote com `ftell` onde cada
linha começa e depois volte com `fseek`.

</details>

**3. Frequência de letras.** Conte quantas vezes cada letra de `a` a `z`
aparece num arquivo, sem diferenciar maiúscula de minúscula, e mostre só as
que aparecem. Para um arquivo com `Banana`, a saída é `a: 3`, `b: 1`, `n: 2`.

<details><summary>Resposta</summary>

Um `int freq[26] = {0}`, um laço com `fgetc` e, para cada `c` com
`isalpha(c)`, `freq[tolower(c) - 'a']++`. Letras acentuadas em UTF-8 ocupam 2
bytes que não são letras ASCII, então ficam de fora: isso é esperado.

</details>

**4. Quanto pesa cada arquivo.** Escreva `tamanho <arq1> <arq2> ...`, que
mostra o tamanho de cada arquivo passado e o total, sem ler o conteúdo.
Arquivo que não abre mostra o erro e não entra no total, mas os outros
continuam.

<details><summary>Resposta</summary>

Para cada `argv[i]`, de 1 a `argc - 1`: `fopen` com `"rb"`, `fseek(f, 0,
SEEK_END)`, `ftell(f)`, `fclose`. Se o `fopen` falhar, `perror(argv[i])` e
`continue`. O código de saída pode ser 1 se algum falhou, como faz o `ls`.

</details>

**5. Busca binária no disco.** Um arquivo binário tem 1000 registros
`{ int codigo; double preco; }` **ordenados por código**. Ache o preço do
código 4321 lendo o mínimo possível de registros. No máximo, quantos `fread`?

<details><summary>Resposta</summary>

Busca binária com `fseek`: `ini = 0`, `fim = 999`; leia o registro do `meio`
com `fseek(f, meio * (long) sizeof(Registro), SEEK_SET)` e um `fread`; compare
e corte metade. São no máximo **10 leituras**, porque 2¹⁰ = 1024 ≥ 1000. Isso
depende de os registros terem tamanho fixo: num arquivo texto, você não sabe
onde fica o "meio".

</details>

**6. Reajuste de 10%.** Um arquivo binário tem vários registros de
`Produto` (`nome[20]`, `qtd`, `preco`). Aumente o preço de todos em 10%,
alterando o arquivo **no lugar**, sem criar outro e sem carregar tudo na
memória.

<details><summary>Resposta</summary>

Abra com `"rb+"`. Para cada registro: `fread`, `p.preco *= 1.10`,
`fseek(f, -(long) sizeof p, SEEK_CUR)` para voltar, `fwrite`, e um
`fseek(f, 0, SEEK_CUR)` antes do próximo `fread`: o C exige um
posicionamento entre escrever e ler no mesmo `FILE`. Sem a volta, o `fwrite`
gravaria por cima do registro **seguinte**.

</details>

**7. Intercalar dois arquivos.** Dois arquivos texto têm números inteiros em
ordem crescente, um por linha. Gere um terceiro com todos os números, ainda em
ordem, lendo cada arquivo uma vez só. Com `1 4 9` e `2 3 10`, sai
`1 2 3 4 9 10`.

<details><summary>Resposta</summary>

Leia o primeiro número de cada arquivo. Enquanto os dois tiverem número,
grave o menor e leia o próximo **daquele** arquivo. Quando um acabar, copie o
resto do outro. É a etapa de intercalação do merge sort (assunto 0094), e é
assim que se ordena um arquivo maior que a RAM.

</details>

**8. Editar no meio do arquivo.** Escreva um programa que grave
`Ana 25\nBia 31\n` em `/tmp/pessoas.txt`, feche, abra de novo com `"r+"` e
grave `Mariana 25\n` logo no começo. Volte ao início com `fseek` e imprima
cada linha do arquivo entre colchetes. Depois faça o mesmo com registros
binários `typedef struct { char nome[12]; int idade; } Pessoa;`: grave
Ana (25) e Bia (31) em `/tmp/pessoas.bin`, reabra com `"rb+"`, grave por cima
do primeiro o registro Mariana (25) e imprima os registros.

<details><summary>Resposta</summary>

```
texto:
[Mariana 25]
[31]
binario:
[Mariana 25]
[Bia 31]
```

Dica: tire o `'\n'` do `fgets` antes de imprimir, e use `fseek(f, 0,
SEEK_SET)` entre escrever e ler. No texto, a linha nova tem 11 bytes, ocupa os
7 da linha da Ana e os 4 primeiros da Bia (`Bia `) e sobra o `31` solto:
arquivo não "abre espaço" no meio, escrever é sempre sobrescrever. Com
registros de tamanho fixo, o novo valor ocupa exatamente os bytes do antigo.

</details>

**9. O seu `cmp`.** Escreva `compara <a> <b>`, que diz se dois arquivos são
iguais e, se não forem, o primeiro byte diferente (contando do 0) e os dois
valores. Para `casa\n` e `cama\n`: `diferem no byte 2: 's' x 'm'`. Código de
saída 0 se iguais, 1 se diferentes.

<details><summary>Resposta</summary>

Leia os dois com `fgetc` no mesmo laço, contando a posição. Pare quando os
bytes forem diferentes ou quando um dos dois for `EOF`. Se só um acabou, os
arquivos diferem no tamanho: um é o começo do outro. Se os dois acabaram
juntos, são iguais.

</details>

**10. Texto ou binário, medido.** Escreva um programa que grave os números
de 0 a 999.999 em `/tmp/numeros.txt` (um por linha, com `fprintf`) e em
`/tmp/numeros.bin` (como `int`, com `fwrite`), feche os dois e imprima o
tamanho de cada um com `fseek` e `ftell`, e quantos por cento o texto ocupa
a mais.

<details><summary>Resposta</summary>

```
texto:   6888890 bytes
binario: 4000000 bytes
o texto ocupa 72.2% a mais
```

Dica: escreva uma `long tamanho(const char *nome)` que abre com `"rb"`, vai
ao fim com `fseek(f, 0, SEEK_END)` e devolve o `ftell`. A conta bate com o
papel: binário é 1.000.000 × 4; texto é 10 × 1 + 90 × 2 + 900 × 3 + 9.000 × 4
+ 90.000 × 5 + 900.000 × 6 dígitos, mais 1.000.000 de `\n`. Para números
pequenos o texto até ganha (`7\n` tem 2 bytes); para grandes, o binário ganha.

</details>

### Questões no estilo da prova

Formato da prova do mestrado do PPGI/UFAM. Resolva no papel, marque uma letra
e só depois abra o gabarito. Os trechos foram compilados com
`gcc -std=c17 -Wall -Wextra` e rodados no Linux. Neles, a conferência de `NULL`
depois do `fopen` foi omitida para encurtar; no seu código, é obrigatória.

**Questão 1.** Sobre arquivos em C, considere as afirmações e marque a alternativa CORRETA.

- **I.** `"w"` apaga o conteúdo de um arquivo que já existe.
- **II.** `"a"` escreve sempre no fim do arquivo.
- **III.** `"r"` cria o arquivo quando ele não existe.
- **IV.** `fwrite` devolve o número de bytes gravados.

- (A) Apenas I
- (B) Apenas II e III
- (C) Apenas I e II
- (D) Apenas III e IV
- (E) Apenas I, II e IV

<details><summary>Gabarito</summary>

**(C).** I e II são verdadeiras. III é falsa: `"r"` devolve `NULL` se o arquivo não existe. IV é falsa: `fwrite` devolve o número de **itens** gravados, não de bytes. Veja 0067 e 0068.

</details>

**Questão 2.** Depois do trecho abaixo, o que há no arquivo `g.txt`?

```c
FILE *f = fopen("g.txt", "w"); fprintf(f, "abc"); fclose(f);
f = fopen("g.txt", "a");       fprintf(f, "de");  fclose(f);
f = fopen("g.txt", "w");       fprintf(f, "xy");  fclose(f);
f = fopen("g.txt", "a");       fprintf(f, "z");   fclose(f);
```

- (A) `abcdexyz`
- (B) `xyz`
- (C) `z`
- (D) `xycdez`
- (E) `abcdez`

<details><summary>Gabarito</summary>

**(B)**. O segundo `"w"` zera o arquivo e joga fora o `abcde`. Depois dele
ficam `xy` e o `z` acrescentado no fim. Veja 0067.

</details>

**Questão 3.** Em uma plataforma com `int` de 4 bytes, o trecho grava os
mesmos três números num arquivo texto (`t`) e num binário (`b`). O que o
`fwrite` devolve e qual o tamanho, em bytes, de cada arquivo?

```c
int v[3] = {7, 42, 1000};
for (int i = 0; i < 3; i++) fprintf(t, "%d\n", v[i]);
size_t n = fwrite(v, sizeof(int), 3, b);
```

- (A) `n` = 3; texto com 10 bytes; binário com 12
- (B) `n` = 12; texto com 10 bytes; binário com 12
- (C) `n` = 3; texto com 12 bytes; binário com 12
- (D) `n` = 3; texto com 7 bytes; binário com 12
- (E) `n` = 12; texto com 7 bytes; binário com 3

<details><summary>Gabarito</summary>

**(A)**. O `fwrite` devolve **quantos itens** gravou (3), não quantos
bytes. No texto, cada número vira seus dígitos mais o `\n`: 2 + 3 + 5 = 10
bytes. No binário, cada `int` ocupa sempre 4 bytes: 12. Veja 0068.

</details>

**Questão 4.** Um arquivo binário tem 5 registros `Produto` gravados em
sequência, cada um com `sizeof(Produto)` = 32. Depois de

```c
fseek(f, 3 * sizeof(Produto), SEEK_SET);
fread(&p, sizeof p, 1, f);
```

qual registro está em `p` (contando de 0) e quanto vale `ftell(f)`?

- (A) o registro 3; 96
- (B) o registro 2; 96
- (C) o registro 4; 128
- (D) o registro 2; 128
- (E) o registro 3; 128

<details><summary>Gabarito</summary>

**(E)**. O registro `i` começa no byte `i * 32`: o 3 começa no 96. O `fread`
lê 32 bytes e deixa a posição no fim do que leu, 128, que é o começo do
registro 4. Veja 0068.

</details>

**Questão 5.** Sobre leitura e escrita de arquivos, considere as afirmações e marque a alternativa CORRETA.

- **I.** `fscanf` devolve a quantidade de campos que conseguiu converter.
- **II.** Num arquivo texto com linhas de tamanhos diferentes, `fseek(f, k * tam, SEEK_SET)` leva ao início da linha `k`.
- **III.** Num arquivo binário de registros de tamanho fixo, o registro `i` começa no byte `i * sizeof(registro)`.
- **IV.** `feof` só passa a valer verdadeiro depois que uma leitura tenta passar do fim do arquivo.

- (A) Apenas I e II
- (B) Apenas II e III
- (C) Apenas I e III
- (D) Apenas I, III e IV
- (E) Apenas II, III e IV

<details><summary>Gabarito</summary>

**(D).** I é verdadeira. II é falsa: as linhas não têm tamanho fixo, então não há conta para chegar à linha `k`. III é verdadeira, e é por isso que a busca binária direto no arquivo funciona. IV é verdadeira: testar `feof` antes de ler leva à volta extra clássica. Veja 0067 e 0068.

</details>

**Questão 6.** O arquivo `precos.txt` tem as quatro linhas abaixo. Quanto
vale `lidos` no fim?

```text
arroz 5.50
feijao 8.90
cafe x
leite 4.20
```

```c
char nome[20];
double preco;
int lidos = 0;
while (fscanf(f, "%19s %lf", nome, &preco) == 2) lidos++;
```

- (A) 4
- (B) 2
- (C) 3
- (D) 0
- (E) o laço não termina

<details><summary>Gabarito</summary>

**(B)**. O `fscanf` devolve quantos campos converteu. Nas duas primeiras
linhas, 2. Na terceira, `x` não é número: devolve 1, o laço para e `leite`
nem é lido. Com `!= EOF` no lugar de `== 2`, o laço daria 5 voltas e
"leria" `cafe` e `x` com o preço velho (8.90) ainda em `preco`. Veja 0067.

</details>

**Questão 7.** O programa abaixo é chamado como `./divide pix 25.90 maria`.
O que ele imprime?

```c
int main(int argc, char *argv[]) {
    printf("%d %s %c\n", argc, argv[2], argv[3][1]);
    return 0;
}
```

- (A) `3 pix a`
- (B) `3 25.90 m`
- (C) `4 pix a`
- (D) `4 25.90 a`
- (E) `4 25.90 m`

<details><summary>Gabarito</summary>

**(D)**. `argv[0]` é o nome do programa, então são 4 argumentos. `argv[2]`
é `"25.90"` (texto, não número) e `argv[3][1]` é o segundo caractere de
`"maria"`. Veja 0069.

</details>

**Questão 8.** Um arquivo binário tem 1.000.000 de registros de tamanho
fixo, ordenados pelo código. Uma busca binária feita direto no arquivo
(`fseek` até o registro do meio e um `fread` por passo) faz, no pior caso,
cerca de quantas leituras?

- (A) 20
- (B) 1.000
- (C) 500.000
- (D) 1.000.000
- (E) 10

<details><summary>Gabarito</summary>

**(A)**. Cada leitura descarta metade dos registros que sobram, e
2²⁰ = 1.048.576 ≥ 1.000.000: no máximo ⌊log₂ n⌋ + 1 = 20 leituras. Isso só
funciona porque o registro `i` está no byte `i * sizeof(registro)`. Num
arquivo texto, com linhas de tamanhos diferentes, não dá para pular para o
meio. Veja 0068 e 0090.

</details>

**Questão 9.** Um programa grava com `fwrite(&c, sizeof c, 1, f)` uma
variável do tipo abaixo e, em outra execução, lê de volta com `fread`. O que
acontece com o nome?

```c
typedef struct { char *nome; int idade; } Cliente;
```

- (A) O nome volta certo, porque o `fwrite` segue o ponteiro.
- (B) O nome volta certo só se o arquivo for aberto com `"rb"`.
- (C) Não compila: struct com ponteiro não pode ir para `fwrite`.
- (D) O nome volta certo se `nome` tiver até 8 caracteres.
- (E) O arquivo guarda o endereço, não o texto; na outra execução, `nome` aponta para lixo.

<details><summary>Gabarito</summary>

**(E)**. O `fwrite` copia os bytes da struct, e o campo `nome` é um
endereço (8 bytes num sistema de 64 bits). O texto apontado nunca vai para o
arquivo. Para gravar em binário, use `char nome[40]` dentro da struct.
Veja 0068.

</details>

**Questão 10.** Você precisa trocar o preço do registro 2 de um arquivo
binário que já existe, sem perder os outros registros. Qual modo de
abertura serve?

- (A) `"wb"`
- (B) `"ab"`
- (C) `"rb+"`
- (D) `"wb+"`
- (E) `"rb"`

<details><summary>Gabarito</summary>

**(C)**. `"rb+"` abre para leitura **e** escrita sem apagar nada: dá para
`fseek` até o registro, `fread`, alterar e `fwrite` por cima (com um `fseek`
entre a leitura e a escrita). `"wb"` e `"wb+"` apagam o arquivo. `"ab"`
escreve sempre no fim, mesmo depois de um `fseek`. `"rb"` não deixa
escrever. Veja 0068 e 0070.

</details>

## Para ler mais

- BACKES, A. *Linguagem C: completa e descomplicada*. Rio de Janeiro: Elsevier, 2013. Cap. 12: arquivos; cap. 13: argumentos do main.
- BACKES, A. R. *Linguagem C: descomplicada*. Uberlândia: FACOM/UFU, [s.d.]. Apostila. Capítulos de arquivos e de recursos avançados.
- DEITEL, P.; DEITEL, H. *C: como programar*. 6. ed. São Paulo: Pearson Prentice Hall, 2011. Cap. 11: processamento de arquivos.
- CELES, W.; RANGEL, J. L. *Apostila de estruturas de dados*. Rio de Janeiro: PUC-Rio, 2002. Capítulo de arquivos.
- CELES, W.; CERQUEIRA, R.; RANGEL, J. L. *Introdução a estruturas de dados: com técnicas de programação em C*. 2. ed. Rio de Janeiro: Elsevier, 2016. Arquivos texto e binários.
- ZIVIANI, N. *Projeto de algoritmos: com implementações em Pascal e C*. 3. ed. rev. e ampl. São Paulo: Cengage Learning, 2010. Pesquisa em memória secundária: acesso a registros em disco.
- ROCHA, A. M. A.; BORGES, A. R. O. S. *Programação, estruturas de dados e algoritmos em C*. Aveiro: Universidade de Aveiro, [s.d.]. Cap. 3: arquivos.
- ANTONELLO, R. *Linguagem C*. 1. ed. Disponível em: <http://www.antonello.com.br>.
- FEOFILOFF, P. *Algoritmos em linguagem C*. Rio de Janeiro: Elsevier, 2009. Apêndice H: entrada e saída, arquivos e argumentos da linha de comando.
- KERNIGHAN, B. W.; RITCHIE, D. M. *C: a linguagem de programação padrão ANSI*. Rio de Janeiro: Campus, 1989. Cap. 7: entrada e saída.
- CPPREFERENCE. *File input/output*. Disponível em: <https://en.cppreference.com/w/c/io>.
- LINUX MAN-PAGES PROJECT. *fopen(3)*, *fseek(3)*, *strtol(3)*. Disponível em: <https://man7.org/linux/man-pages/>.
