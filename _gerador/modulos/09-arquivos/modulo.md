# Módulo 09 · Arquivos e linha de comando

Até aqui, todo programa do curso nasce, faz a conta e morre levando tudo
junto. As variáveis moram na RAM, e a RAM é esvaziada quando o processo
termina. Para um programa **lembrar** de alguma coisa (um cadastro, uma
configuração, o placar de ontem), ele precisa gravar em **arquivo**.

No C você vê as engrenagens: o `FILE *` que representa o
arquivo aberto, o buffer que junta os bytes antes de ir para o disco, a
posição que anda a cada leitura. E aparece uma escolha importante:
gravar **texto**, legível e portável, ou **binário**, a cópia exata dos bytes
da memória, compacta e com acesso direto a qualquer registro.

O módulo fecha com a outra porta de entrada de um programa: os **argumentos
da linha de comando**. É o que transforma os seus exercícios em ferramentas de
verdade, do tipo que você chama no terminal como chama `git` ou `grep`, e que
encadeia com outras em scripts.

## O que você vai aprender

- abrir, escrever, ler e fechar **arquivos texto** com `fopen`, `fprintf`, `fgets`, `fscanf`, `fgetc` e `fclose`
- os modos `"r"`, `"w"` e `"a"`, o **buffer** e por que nunca usar `while (!feof(f))`
- gravar e ler **arquivos binários** com `fwrite` e `fread`, e pular direto para um registro com `fseek` e `ftell`
- quando escolher texto e quando escolher binário
- receber dados pelo **`argc` e `argv`**, converter com `strtol` e `strtod` e devolver o **código de saída**
- juntar tudo numa ferramenta de terminal com subcomandos

## Como estudar cada assunto

1. Leia o texto e olhe o **diagrama da ideia**: é o exemplo desenhado.
2. Leia o código. É o mesmo exemplo, com os mesmos valores.
3. Siga o **fluxograma** com o dedo: é o caminho que o programa faz.
4. Rode os exemplos. Mude um valor, quebre de propósito, rode de novo.
5. Faça os exercícios. ★☆☆ é aquecimento, ★★☆ pede raciocínio, ★★★ é desafio.
   As dicas vêm logo abaixo do enunciado: tente antes de ler.

No meio de cada assunto tem uma **Pergunta para você**. Responda antes de rodar.

## As cores e as formas

<p align="center"><img src="../legenda.svg" alt="Legenda: formas e cores do fluxograma" width="916"></p>

## Antes de começar

Os exemplos gravam em `/tmp`, com nomes claros (`/tmp/despesas.txt`,
`/tmp/estoque.bin`), e quase todos apagam o arquivo no fim com `remove`.
Quando um deixa o arquivo lá de propósito, o comentário avisa, para você
abrir com `cat`. Nenhum exemplo depende de um arquivo que já exista: cada um
cria o que vai ler.

Para passar argumentos a um programa, escreva-os depois do caminho, no
`rodar`: ele repassa tudo para o programa.

```bash
~/LPEDC/rodar 09-arquivos/0074-argumentos/A147.c 187.40 4
```

Duas ferramentas ajudam a enxergar o que os programas gravam: `od -A d -t x1
arquivo` mostra os bytes em hexadecimal (já vem no sistema), e o `strace`
mostra as chamadas ao sistema operacional, como cada `write` no disco:

```bash
sudo pacman -S strace       # Arch Linux
sudo apt install strace     # Debian / Ubuntu
```

Você vai usar structs (módulo 08), strings com `fgets` (0047) e ponteiros o
tempo todo. Se `typedef struct`, `sizeof` e `char *` ainda dão aquela
hesitação, revise antes.

{{indice}}

---

{{assuntos}}

---

## Desafios do módulo

Problemas para resolver com o que você viu no módulo, do médio ao difícil.
Crie os arquivos de teste no terminal com `printf '...' > /tmp/teste.txt`.

**1. O seu `cp`.** Escreva `copia <origem> <destino>`, que copia qualquer
arquivo (texto ou não) byte a byte. Confira o `argc`, os dois `fopen` e mostre
quantos bytes copiou. Teste copiando o próprio executável e comparando com
`cmp`.

<details><summary>Resposta</summary>

Abra a origem com `"rb"` e o destino com `"wb"`; se o segundo `fopen` falhar,
feche o primeiro. O laço é `while ((c = fgetc(ent)) != EOF) { fputc(c, sai);
n++; }` com `int c`. Com `char c`, um byte 0xFF no meio do arquivo vira -1 e o
laço para antes da hora: a cópia de um executável sai cortada. Use o modo
`b`, para valer no Windows também.

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
e corte metade. São no máximo **10 leituras**, porque 2¹⁰ = 1024 ≥ 1000. Só
funciona porque os registros têm tamanho fixo: num arquivo texto, você não
sabe onde fica o "meio".

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
resto do outro. É a etapa de intercalação do merge sort (assunto 0099), e é
assim que se ordenam arquivos maiores que a RAM.

</details>

**8. Por que não dá para editar no meio?** Um arquivo texto tem
`Ana 25\nBia 31\n`. Você abre com `"r+"`, posiciona no começo e grava
`Mariana 25\n`. O que fica no arquivo? Por que o mesmo problema não acontece
com registros binários de tamanho fixo?

<details><summary>Resposta</summary>

Fica `Mariana 25\n31\n`: a linha nova tem 11 bytes, ocupa os 7 da linha da
Ana e os 4 primeiros da linha da Bia (`Bia `), e sobra o `31\n` como uma linha
solta.
Arquivo não "abre espaço" no meio: escrever é sempre sobrescrever. Em texto,
os campos têm tamanho variável, então mudar um valor obriga a reescrever o
arquivo inteiro (copiar para um novo e renomear). Com registros fixos, o novo
valor ocupa exatamente os bytes do antigo.

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

**10. Texto ou binário, na ponta do lápis.** Você vai guardar os números de 0
a 999.999, um por linha num arquivo texto, ou como `int` num binário. Quantos
bytes ocupa cada um?

<details><summary>Resposta</summary>

Binário: 1.000.000 × 4 = **4.000.000 bytes**. Texto: dígitos de 1 a 6 casas,
10 × 1 + 90 × 2 + 900 × 3 + 9.000 × 4 + 90.000 × 5 + 900.000 × 6 = 5.888.890,
mais 1.000.000 de `\n`: **6.888.890 bytes**, uns 72% a mais. Para números
pequenos o texto até ganha (`7\n` tem 2 bytes); para números grandes, o
binário ganha sempre e ainda poupa a conversão.

</details>

## Para ler mais

- BACKES, A. *Linguagem C: completa e descomplicada*. Rio de Janeiro: Elsevier, 2013. Cap. 12: arquivos; cap. 13: argumentos do main.
- BACKES, A. R. *Linguagem C: descomplicada*. Uberlândia: FACOM/UFU, [s.d.]. Apostila. Capítulos de arquivos e de recursos avançados.
- DEITEL, P.; DEITEL, H. *C: como programar*. 6. ed. São Paulo: Pearson Prentice Hall, 2011. Cap. 11: processamento de arquivos.
- CELES, W.; RANGEL, J. L. *Apostila de estruturas de dados*. Rio de Janeiro: PUC-Rio, 2002. Capítulo de arquivos.
- ROCHA, A. M. A.; BORGES, A. R. O. S. *Programação, estruturas de dados e algoritmos em C*. Aveiro: Universidade de Aveiro, [s.d.]. Cap. 3: arquivos.
- ANTONELLO, R. *Linguagem C*. 1. ed. Disponível em: <http://www.antonello.com.br>.
- KERNIGHAN, B. W.; RITCHIE, D. M. *C: a linguagem de programação padrão ANSI*. Rio de Janeiro: Campus, 1989. Cap. 7: entrada e saída.
- CPPREFERENCE. *File input/output*. Disponível em: <https://en.cppreference.com/w/c/io>.
- LINUX MAN-PAGES PROJECT. *fopen(3)*, *fseek(3)*, *strtol(3)*. Disponível em: <https://man7.org/linux/man-pages/>.
