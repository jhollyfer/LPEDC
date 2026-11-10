# Módulo 06 · Ponteiros

Até aqui você usou variáveis pelo **nome**: o compilador trocava cada nome
por um endereço e escondia isso de você. Neste módulo a cortina abre. Toda
variável mora numa gaveta numerada da memória, dá para guardar o número dessa
gaveta numa outra variável e, com esse número na mão, ler e mudar o dado de
qualquer lugar do programa.

No C, se uma função precisa mudar uma variável sua, você entrega o endereço
dela. Dá trabalho, mas em troca você sabe o que cada linha custa e entende
por que o `scanf` pedia aquele `&` desde o módulo 01.

Tudo o que vem depois depende de ponteiro: memória dinâmica (módulo 07),
structs encadeadas (módulo 08), listas, pilhas, filas, árvores e grafos. Vá
devagar, desenhe as gavetas no papel e rode cada exemplo mais de uma vez.

## O que você vai aprender

- a memória como um **gaveteiro numerado**: endereço, `&` e `%p`
- declarar e usar **ponteiros**: `*`, desreferência e `NULL`
- **passagem por referência**: a troca (swap), funções que devolvem vários resultados e o `&` do `scanf` explicado
- **aritmética de ponteiros** e por que `v[i]` é o mesmo que `*(v + i)`
- a diferença entre `char *` e `char []`, e por que um literal de string é **só leitura**
- **ponteiro para ponteiro** (`**`) e vetor de ponteiros
- **ponteiro para função**: callbacks e o `qsort`
- **`void *`**: o ponteiro genérico, o cast e funções que servem para qualquer tipo

## Antes de começar

Você precisa estar à vontade com vetores, strings e funções (módulos 04 e
05). Os erros de ponteiro raramente aparecem na compilação: aparecem quando
o programa roda, às vezes bem longe da linha culpada. Por isso, rode
**sempre** com as flags de estudo, que liga o AddressSanitizer. Quando ele acusar
algo, leia o relatório de cima para baixo: o tipo do erro
(`stack-buffer-overflow`, `SEGV on unknown address`), a linha e a variável
envolvida.

O diagrama da ideia deste módulo é quase sempre um gaveteiro com endereços e
setas; nele, roxo marca os ponteiros.

> [!NOTE]
> Os endereços dos desenhos são **fictícios** e curtos (`0x1000`, `0x1004`)
> para caber na cabeça. Os de verdade têm 12 dígitos hexa e **mudam a cada
> execução**: os endereços nos comentários dos exemplos são de uma execução
> qualquer, e os seus vão ser outros. O que importa são as relações entre
> eles (iguais, 4 bytes depois etc.).

Para seguir um ponteiro passo a passo, use o `gdb`
(`print p`, `print *p`, `print &x`):

```bash
sudo pacman -S gdb          # Arch Linux
sudo apt install gdb        # Debian / Ubuntu
```

{{indice}}

---

{{assuntos}}

---

## Desafios do módulo

Problemas extras, misturando os assuntos do módulo. Resolva num arquivo seu
e rode com as flags de estudo.

**1. O gaveteiro de três níveis.** Ponha num `main` as linhas
`int x = 7; int *p = &x; int **pp = &p; **pp = 9; *pp = NULL;` e, depois
delas, mostre o valor de `x`, o resultado de `p == NULL` e o de `pp == &p`.
Acrescente então `printf("%d\n", *p);`, rode com as flags de estudo e veja o que
acontece. Por fim, conserte: só mostre `*p` se `p` não for `NULL`; senão,
mostre `p não aponta para nada`.

<details><summary>Resposta</summary>

Com o `printf` de `*p` solto, o AddressSanitizer derruba o programa:
`AddressSanitizer: SEGV on unknown address 0x000000000000`. Depois do
conserto:

```text
x = 9
p == NULL: 1
pp == &p: 1
p não aponta para nada
```

`**pp = 9` atravessa dois `*` e chega no `x`; `*pp = NULL` atravessa um só e
muda o ponteiro `p`, não o `x`. O `pp` continua guardando o endereço de `p`.
Desenhe sempre o que cada `*` atravessa.

</details>

**2. Minutos de academia.** Escreva
`void resumo(const int *min, int n, int *total, int *dias_acima, double *media)`
que recebe os minutos de treino da semana `{45, 0, 60, 30, 75, 0, 50}` e
devolve o total, quantos dias passaram de 40 minutos e a média dos dias em
que houve treino.

<details><summary>Resposta</summary>

Total **260**, **4** dias acima de 40 (45, 60, 75, 50) e média **52.0** (260
em 5 dias com treino). Caminho: um laço só, três ponteiros de saída; cuidado
para não dividir por zero se a semana inteira for zero.

</details>

**3. Rotação da escala.** A escala de plantão `{"ana", "bia", "caio", "davi",
"eva"}` está num `const char *escala[5]`. Escreva `void gira(const char **v,
int n)` que move todo mundo uma posição para a esquerda (o primeiro vai para
o fim), trocando só ponteiros. Gire duas vezes.

<details><summary>Resposta</summary>

Depois de duas rotações: **caio davi eva ana bia**. Guarde `v[0]` num `const
char *tmp`, ande de `i = 0` a `n - 2` fazendo `v[i] = v[i + 1]` e termine
com `v[n - 1] = tmp`. Nenhum caractere é copiado: só endereços.

</details>

**4. O meu strcat.** Escreva `char *junta(char *destino, const char
*origem)` só com ponteiros: ande até o `'\0'` do destino e copie a origem dali
em diante. Devolva `destino`. Teste com `char cidade[30] = "Campina";` e
`" Grande"`. Depois troque para `char cidade[10]`, rode de novo com as flags de estudo e veja o erro que ele mostra.

<details><summary>Resposta</summary>

Mostra **"Campina Grande"** (14 letras + `'\0'` = 15 bytes). Com `char
cidade[10]`, a cópia passa do fim e o AddressSanitizer acusa
`stack-buffer-overflow`. A função não tem como saber o tamanho do destino:
é por isso que existe `strncat`, e por isso quem chama precisa garantir o
espaço.

</details>

**5. Palavras de uma frase.** Escreva `int conta_palavras(const char *s)`
andando com ponteiro: uma palavra começa quando o caractere atual não é
espaço e o anterior era espaço (ou é o começo). Teste com
`"  pix   caiu na   conta "`.

<details><summary>Resposta</summary>

**4** palavras. Guarde um "estava em espaço?" (começando verdadeiro); a cada
caractere não espaço com a marca ligada, conte e desligue a marca; a cada
espaço, ligue de novo. Espaços repetidos e nas pontas não atrapalham.

</details>

**6. O laço que se encontra no meio.** Rode o trecho abaixo dentro de um
`main` e acrescente, dentro do laço, um `printf` que mostre a cada volta os
índices de `p` e `q` (`p - v` e `q - v`, com `%td`) e o vetor inteiro.
Depois troque a condição para `p <= q` e veja o que muda no `v[2]`.

```c
int v[5] = {1, 2, 3, 4, 5};
int *p = v, *q = v + 4;
while (p < q) {
    *p += *q;
    p++;
    q--;
}
printf("%d %d %d %d %d\n", v[0], v[1], v[2], v[3], v[4]);
```

<details><summary>Resposta</summary>

Duas voltas: `p=0 q=4` (vira **6** 2 3 4 5) e `p=1 q=3` (vira 6 **6** 3 4 5);
aí `p` e `q` se encontram em `v[2]` e o laço para: **6 6 3 4 5**. Com
`p <= q` há uma terceira volta com os dois em `v[2]`, que soma o elemento
com ele mesmo: **6 6 6 4 5**.

</details>

**7. Menu sem switch.** Monte um menu de conversões com um vetor de
ponteiros para função `double (*conv[3])(double)`: km para milhas (÷ 1.609),
kg para libras (× 2.205) e °C para °F. Leia a opção (0, 1 ou 2) e o valor
com `scanf`, valide a opção e chame `conv[op](valor)`. Teste com opção 0 e
10 km.

<details><summary>Resposta</summary>

10 km ≈ **6.21 milhas**. O índice lido vira direto a posição no vetor de
funções. Valide `0 <= op && op < 3` antes de chamar: um índice fora do vetor
"chama" um endereço qualquer, e aí nem o AddressSanitizer salva.

</details>

**8. qsort em dupla.** Os pedidos do restaurante estão em dois vetores
paralelos: `int mesa[6] = {4, 2, 7, 2, 4, 1}` e `int minuto[6] = {12, 5, 3,
9, 1, 20}` (minuto em que o pedido chegou). Mostre os pedidos ordenados por
mesa e, dentro da mesma mesa, por minuto, sem mexer nos vetores originais.

<details><summary>Resposta</summary>

Ordem: mesa 1 (min 20), mesa 2 (min 5), mesa 2 (min 9), mesa 4 (min 1),
mesa 4 (min 12), mesa 7 (min 3). Caminho: um vetor de índices `int
ordem[6] = {0, ..., 5}` e uma comparação que lê os vetores paralelos (que
podem ser `static` globais), ou um vetor de `const int *` para `mesa`, como
no assunto 0052, usando `p - mesa` para achar o minuto.

</details>

**9. Endianness na prática.** Escreva `bool little_endian(void)` que
descobre a ordem dos bytes da máquina olhando o primeiro byte de um `int`
que vale 1 (por meio de um `unsigned char *`). Depois escreva
`unsigned int inverte_bytes(unsigned int x)` que troca a ordem dos 4 bytes
usando a `troca_generica` do assunto 0051 nos bytes certos.

<details><summary>Resposta</summary>

No seu PC, `little_endian()` dá **verdadeiro**: o primeiro byte do 1 é
`01`. `inverte_bytes(0x0A0B0C0D)` dá **0x0D0C0B0A**: troque o byte 0 com o 3
e o 1 com o 2 (`troca_generica(&b[0], &b[3], 1)` e assim por diante, com `b`
sendo um `unsigned char *` para `x`). É o que as funções de rede (`htonl`)
fazem.

</details>

**10. Busca binária genérica.** Escreva `void *busca_bin(const void *chave,
void *v, size_t n, size_t tam, int (*cmp)(const void *, const void *))` que
faz busca binária num vetor já ordenado de qualquer tipo e devolve o endereço
do elemento ou `NULL`. Teste com `int cods[8] = {3, 8, 15, 21, 30, 42, 57,
60}` procurando 42 e 10, e compare com o `bsearch` da `stdlib.h`, que tem
exatamente essa assinatura.

<details><summary>Resposta</summary>

42 está no **índice 5** (subtraia o ponteiro devolvido de `cods`); 10 dá
**NULL**. O meio fica em `(unsigned char *)v + meio * tam`. Compare
`cmp(chave, meio)`: negativo, procure à esquerda; positivo, à direita; zero,
achou. A busca binária em si é o assunto 0090.

</details>

## Questões no estilo da prova

Questões objetivas no formato da prova do mestrado do PPGI/UFAM. Resolva no
papel, sem rodar, marque uma letra e só então abra o gabarito. Todos os
trechos foram compilados com `gcc -std=c17 -Wall -Wextra`.

**Questão 1.** O que o programa imprime?

```c
int v[5] = {10, 20, 30, 40, 50};
int *p = v + 1;
printf("%d %d %d\n", *(p + 2), p[-1], *p + 2);
```

- (A) `30 20 22`
- (B) `40 10 22`
- (C) `40 20 32`
- (D) `30 10 12`
- (E) `40 10 32`

<details><summary>Gabarito</summary>

**(B)**. `p` aponta para `v[1]` (20). `*(p + 2)` anda duas gavetas e lê
`v[3]` = 40; `p[-1]` é `*(p - 1)` = `v[0]` = 10; em `*p + 2` o `*` vem
antes do `+`: 20 + 2 = 22. Veja 0047.

</details>

**Questão 2.** O que o programa imprime?

```c
int v[3] = {5, 8, 2};
int *p = v;
int a = *p++;
int b = (*p)++;
printf("%d %d %d %d\n", a, b, v[0], v[1]);
```

- (A) `5 8 6 8`
- (B) `5 9 5 9`
- (C) `8 8 5 9`
- (D) `5 8 5 9`
- (E) `5 8 6 9`

<details><summary>Gabarito</summary>

**(D)**. Em `*p++` o `++` vale para o ponteiro: lê `v[0]` (5) e depois `p`
passa para `v[1]`. Em `(*p)++` o `++` vale para o valor: `b` recebe 8 (o
pós-incremento devolve o valor antigo) e `v[1]` vira 9. `v[0]` nunca muda.
Veja 0047.

</details>

**Questão 3.** Sobre ponteiros em C, considere as afirmações e marque a alternativa CORRETA.

- **I.** Se `p` é um `int *`, `p + 1` aponta para o `int` seguinte, `sizeof(int)` bytes adiante.
- **II.** `*p++` incrementa o valor apontado por `p`.
- **III.** Desreferenciar um ponteiro `NULL` é seguro: o programa só devolve 0.
- **IV.** Se `v` é um vetor, `v[i]` equivale a `*(v + i)`.

- (A) Apenas I e IV
- (B) Apenas I e II
- (C) Apenas II e III
- (D) Apenas III e IV
- (E) Apenas I, II e IV

<details><summary>Gabarito</summary>

**(A).** I é verdadeira: a aritmética de ponteiros anda em unidades do tipo apontado. II é falsa: o `++` vale para o ponteiro, e o valor lido é o antigo (para incrementar o valor, é `(*p)++`). III é falsa: é comportamento indefinido, e na prática costuma derrubar o programa. IV é verdadeira. Veja 0047.

</details>

**Questão 4.** Qual o valor final de `x`?

```c
int x = 4;
int *p = &x;
int **pp = &p;
**pp += 3;
*p *= 2;
```

- (A) 14
- (B) 11
- (C) 8
- (D) 10
- (E) 7

<details><summary>Gabarito</summary>

**(A)**. `**pp` atravessa dois `*` e chega em `x`: 4 + 3 = 7. `*p` também é
`x`: 7 × 2 = 14. Veja 0049.

</details>

**Questão 5.** Com `double v[10]; double *p = &v[2], *q = &v[7];`, os
valores de `q - p` e de `(char *)q - (char *)p` são, respectivamente:

- (A) 5 e 5
- (B) 40 e 40
- (C) 5 e 40
- (D) 6 e 48
- (E) 5 e 20

<details><summary>Gabarito</summary>

**(C)**. A diferença de dois ponteiros do mesmo vetor conta **elementos**:
7 − 2 = 5. Convertidos para `char *`, eles contam **bytes**: 5 × 8 = 40
(`sizeof(double)` é 8). Veja 0047.

</details>

**Questão 6.** Em uma plataforma de 64 bits típica, o que o trecho imprime?

```c
char s[] = "banana";
char *t = "banana";
printf("%zu %zu %zu %zu\n", sizeof s, strlen(s), sizeof t, strlen(t));
```

- (A) `6 6 6 6`
- (B) `7 6 7 6`
- (C) `6 6 8 6`
- (D) `7 7 8 7`
- (E) `7 6 8 6`

<details><summary>Gabarito</summary>

**(E)**. `s` é um vetor: `sizeof` conta os 6 caracteres mais o `'\0'` (7).
`t` é um ponteiro: `sizeof t` é o tamanho de um endereço (8). O `strlen` não
conta o `'\0'` nos dois casos (6). Veja 0048.

</details>

**Questão 7.** Em uma plataforma com `int` de 4 bytes, o que o trecho
imprime?

```c
int m[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
printf("%td %td %d\n", (char *)(m + 1) - (char *)m,
       (char *)(m[0] + 1) - (char *)m[0], *(*(m + 2) + 1));
```

- (A) `4 4 10`
- (B) `16 16 6`
- (C) `4 16 10`
- (D) `16 4 10`
- (E) `16 4 6`

<details><summary>Gabarito</summary>

**(D)**. O elemento de `m` é uma linha inteira (4 `int`), então `m + 1`
anda 16 bytes. `m[0]` é o endereço do primeiro `int` da linha 0, e
`m[0] + 1` anda 4. `*(*(m + 2) + 1)` é `m[2][1]` = 10. Veja 0047 e 0039.

</details>

**Questão 8.** O que o programa imprime?

```c
int dobro(int x) { return 2 * x; }
int quadrado(int x) { return x * x; }

int main(void) {
    int (*f[2])(int) = {dobro, quadrado};
    printf("%d\n", f[1](f[0](3)));
    return 0;
}
```

- (A) 18
- (B) 12
- (C) 36
- (D) 9
- (E) 6

<details><summary>Gabarito</summary>

**(C)**. `f` é um vetor de dois ponteiros para função. `f[0](3)` chama
`dobro(3)` = 6; `f[1](6)` chama `quadrado(6)` = 36. A resposta (A) troca a
ordem das chamadas. Veja 0050.

</details>

**Questão 9.** Com `int x = 1, y = 2; const int *p = &x; int *const q = &x;`,
quais das linhas abaixo **compilam**?

```c
p = &y;   /* I   */
*q = 5;   /* II  */
*p = 9;   /* III */
q = &y;   /* IV  */
```

- (A) apenas I
- (B) apenas I e II
- (C) apenas I e III
- (D) apenas II e IV
- (E) todas

<details><summary>Gabarito</summary>

**(B)**. Leia da direita para a esquerda. `const int *p`: ponteiro para
`int` constante; o ponteiro pode andar (I), mas `*p` não pode ser escrito
(III dá `assignment of read-only location`). `int *const q`: ponteiro
constante para `int`; `*q` pode ser escrito (II), mas `q` não pode mudar
(IV dá `assignment of read-only variable`). Veja 0046 e 0047.

</details>

## Para ler mais

- BACKES, A. *Linguagem C: completa e descomplicada*. Rio de Janeiro: Elsevier, 2013. Cap. 10: ponteiros; cap. 13: ponteiro para função.
- BACKES, A. R. *Linguagem C: descomplicada*. Apostila. Uberlândia: FACOM/UFU. Capítulos de ponteiros e de recursos avançados.
- DEITEL, P. J.; DEITEL, H. M. *C: como programar*. 6. ed. São Paulo: Pearson Prentice Hall, 2011. Cap. 7: ponteiros em C.
- CELES, W.; RANGEL, J. L. *Apostila de estruturas de dados*. Rio de Janeiro: PUC-Rio, 2002. Ponteiros, vetores e ordenação genérica.
- FEOFILOFF, P. *Algoritmos em linguagem C*. Rio de Janeiro: Elsevier, 2009. Apêndice D: endereços e ponteiros.
- CELES, W.; CERQUEIRA, R.; RANGEL, J. L. *Introdução a estruturas de dados: com técnicas de programação em C*. 2. ed. Rio de Janeiro: Elsevier, 2016. Ponteiros, vetores e ponteiros para função.
- TENENBAUM, A. M.; LANGSAM, Y.; AUGENSTEIN, M. J. *Estruturas de dados usando C*. São Paulo: Makron Books, 1995. Cap. 1: vetores, ponteiros e estruturas em C.
- ZIVIANI, N. *Projeto de algoritmos: com implementações em Pascal e C*. 3. ed. rev. e ampl. São Paulo: Cengage Learning, 2010. Usa o nome **apontador** e o aplica em listas, pilhas e filas.
- LAUREANO, M. *Estrutura de dados com algoritmos e C*. Rio de Janeiro: Brasport, 2008. Cap. 1 e 2: ponteiros e uso de memória.
- ROCHA, A. M. A.; BORGES, A. R. O. S. *Programação, estruturas de dados e algoritmos em C*. Aveiro: Universidade de Aveiro, DETI. Ponteiros e ponteiro para função.
- HARA, C.; ZOLA, W. *Linguagem C: notas de aula*. Curitiba: UFPR, 2008. Ponteiros e passagem por referência.
- KERNIGHAN, B. W.; RITCHIE, D. M. *C: a linguagem de programação padrão ANSI*. Rio de Janeiro: Campus, 1989. Cap. 5: apontadores e vetores.
- CPPREFERENCE. *Pointer declaration*. Disponível em: <https://en.cppreference.com/w/c/language/pointer>.
- CPPREFERENCE. *qsort, qsort_s*. Disponível em: <https://en.cppreference.com/w/c/algorithm/qsort>.
- KERRISK, M. *qsort(3)*: Linux manual page. Disponível em: <https://man7.org/linux/man-pages/man3/qsort.3.html>.
