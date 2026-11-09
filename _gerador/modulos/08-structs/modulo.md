# Módulo 08 · Tipos compostos

Até aqui, cada variável guardava uma coisa só: um número, um caractere, um
vetor de coisas iguais. Os dados do mundo real vêm em pacotes. Um pedido tem
tamanho, quantidade e preço; um time tem nome, vitórias e empates. Este
módulo ensina o C a guardar pacotes.

No C, você desenha o pacote byte a byte: decide a ordem dos campos (e paga
pelas sobras de alinhamento), decide se ele anda por cópia ou por ponteiro (e
paga pela cópia), decide se dois campos dividem a mesma memória. Nada fica
escondido, e você passa a saber o que um objeto **custa**.

O módulo fecha no nível do bit: máscaras e flags, o jeito mais compacto de
guardar sim/não. Com struct, ponteiro para struct e `malloc`, você tem todas
as peças das estruturas de dados que começam no módulo 10.

## O que você vai aprender

- agrupar dados de tipos diferentes numa **struct**, com o ponto, a cópia por atribuição e o alinhamento
- dar nomes curtos aos tipos com **typedef**, e por que ele não cria um tipo novo
- montar, percorrer e ordenar **vetores de structs**
- usar **ponteiro para struct**: a seta `->`, struct no heap com `malloc` e o custo de passar por valor
- dar nome a estados e opções com **enum**
- fazer campos dividirem a memória com **union**, e enxergar a **endianness** da máquina
- ler e escrever **bits** com `& | ^ ~ << >>`, máscaras e flags (as permissões `rwx` do Linux)

## Antes de começar

Este módulo usa tudo dos anteriores: funções, vetores, strings com `fgets`,
ponteiros, `malloc`/`realloc`/`free` e `qsort`. Se `int *p = malloc(n *
sizeof *p);` ainda não parece natural, revise o módulo 07 antes.

Vários exemplos mostram tamanhos (`sizeof`) e a ordem dos bytes. Os valores
dos comentários são os de um PC de 64 bits com Linux (Intel, AMD ou ARM).
Em outra máquina os números podem mudar, e perceber isso faz parte do
módulo. Ao rodar, troque a ordem dos campos de uma struct e compare o
`sizeof`. Responda a **Pergunta para você** de cada assunto antes de rodar.

```bash
~/LPEDC/rodar 08-structs/0059-struct/A117.c
```

{{indice}}

---

{{assuntos}}

---

## Desafios do módulo

Problemas para resolver num arquivo seu, misturando os assuntos do módulo. Do
médio ao difícil.

**1. Agenda com busca.** Monte uma agenda com 5 contatos (nome, telefone,
aniversário como struct `Data`). Leia um nome com `fgets` e mostre o contato,
ou "não encontrado". Depois mostre quem faz aniversário no mês 10.

<details><summary>Resposta</summary>

Um vetor de `Contato`, cada um com um campo `Data` aninhado
(`agenda[i].aniversario.mes`). A busca é um laço com
`strcmp(agenda[i].nome, nome) == 0`; tire o `'\n'` do `fgets` antes de
comparar, senão nada bate. Devolva o **índice** encontrado (ou -1), não uma
cópia.

</details>

**2. Desempate do campeonato.** Ordene uma tabela de times por pontos; no
empate, por saldo de gols; no empate, por gols marcados; e, por fim, pelo nome.

<details><summary>Resposta</summary>

Uma comparadora para o `qsort` com uma cascata de `if`: compare pontos; se
diferentes, devolva a diferença invertida (maior primeiro); senão passe para o
saldo, depois gols, e termine com `strcmp` nos nomes. O último critério garante
uma ordem única, porque o `qsort` não é estável.

</details>

**3. Os retângulos se encostam?** Com `typedef struct { double x, y; } Ponto;`
e um retângulo dado por dois cantos, escreva `bool sobrepoe(Retangulo a,
Retangulo b)`. Teste com (0,0)-(4,3) e (3,2)-(6,5), e com (0,0)-(2,2) e
(3,3)-(5,5).

<details><summary>Resposta</summary>

Dois retângulos **não** se sobrepõem quando um está todo à esquerda, à
direita, acima ou abaixo do outro: `a.sup.x < b.inf.x || b.sup.x < a.inf.x ||
a.sup.y < b.inf.y || b.sup.y < a.inf.y`. Negue isso. O primeiro par se
sobrepõe (no quadrado de (3,2) a (4,3)); o segundo, não.

</details>

**4. A struct gorda.** Escreva um programa que mostre o `sizeof` e o
`offsetof` de cada campo de `struct Sensor { char id; double leitura; char
status; int contador; };`. Crie uma versão com os campos reorganizados para
ocupar o mínimo e mostre quantos bytes ela economiza num vetor de 1 milhão de
sensores.

<details><summary>Resposta</summary>

`id` no byte 0, 7 de sobra, `leitura` no 8, `status` no 16, 3 de sobra,
`contador` no 20: **24 bytes**. Na ordem `double`, `int`, `char`, `char`: 8 + 4
+ 1 + 1 = 14, arredondado para **16**. São 8 bytes por sensor, 8 MB a menos no
vetor. Confira com `sizeof` e `offsetof`.

</details>

**5. Dentro do float.** Com uma union de `float` e `uint32_t`, separe os
campos do `-6.25f`: o bit de sinal (bit 31), o expoente (bits 30 a 23) e a
mantissa (bits 22 a 0).

<details><summary>Resposta</summary>

Os bits são `0xC0C80000`. Sinal: `bits >> 31` = **1** (negativo). Expoente:
`(bits >> 23) & 0xFF` = **129**, que, menos o desvio de 127, dá 2. Mantissa:
`bits & 0x7FFFFF` = `0x480000`, que representa a parte fracionária de
1,5625. E 1,5625 × 2² = 6,25.

</details>

**6. Quantos bits mudaram?** Escreva `int distancia(unsigned a, unsigned b)`
que conta em quantas casas os bits de `a` e `b` diferem (a distância de
Hamming). Quanto dá para 11 e 6?

<details><summary>Resposta</summary>

O `^` liga exatamente as casas diferentes; depois é só contar os bits 1:
`11 ^ 6` = `1011 ^ 0110` = `1101`, **3 bits**. É assim que códigos de correção
de erro medem quantos bits uma transmissão estragou.

</details>

**7. Potência de 2 numa linha.** Escreva `bool potencia_de_2(unsigned n)` só
com `n > 0 && (n & (n - 1)) == 0`. Para 64, 96 e 1, mostre o resultado e os
bits de `n` e de `n - 1`, um embaixo do outro, para ver por que funciona.

<details><summary>Resposta</summary>

Uma potência de 2 tem **um** bit ligado (`64` = `1000000`). Subtrair 1 apaga
esse bit e liga todos à direita (`63` = `0111111`), então o `&` dá zero. Se
houver mais de um bit ligado (`96` = `1100000`, `95` = `1011111`), o bit mais
alto sobrevive ao `&`. 64 e 1 dão verdadeiro; 96, falso.

</details>

**8. A data em 16 bits.** O sistema de arquivos FAT guarda uma data em 16
bits: dia nos bits 0 a 4, mês nos bits 5 a 8 e (ano - 1980) nos bits 9 a 15.
Empacote 18/10/2026 e desempacote de volta.

<details><summary>Resposta</summary>

`(46 << 9) | (10 << 5) | 18` = 23552 + 320 + 18 = **23890** (`0x5D52`). Para
voltar: dia = `d & 0x1F`, mês = `(d >> 5) & 0xF`, ano = `(d >> 9) + 1980`.
Cinco bits para o dia porque 2⁵ = 32 > 31; quatro para o mês, porque 2⁴ = 16 >
12; sete para o ano, o que vai até 1980 + 127 = 2107.

</details>

**9. Um conjunto em 64 bits.** Represente conjuntos de números de 0 a 63 num
`uint64_t` e escreva `inserir`, `contem`, `uniao`, `intersecao` e `tamanho`.
Teste com {1, 3, 5, 7} e {3, 4, 5}.

<details><summary>Resposta</summary>

Inserir `x`: `s |= (uint64_t)1 << x` (o 1 precisa ser de 64 bits, senão o
deslocamento estoura). Contém: `(s >> x) & 1`. União é `|`, interseção é `&`,
tamanho é contar bits. União {1, 3, 4, 5, 7} (5 elementos), interseção {3, 5}
(2 elementos). Cada operação de conjunto custa uma instrução.

</details>

**10. Playlist encadeada.** Sem `malloc`, crie 4 variáveis `Musica` (título,
duração em segundos e `struct Musica *proxima`) ligadas em sequência, com
`NULL` na última. Percorra a partir da primeira, mostrando cada uma e a duração
total em minutos e segundos.

<details><summary>Resposta</summary>

A struct precisa de nome para apontar para si mesma: `typedef struct Musica {
...; struct Musica *proxima; } Musica;`. O laço é `for (const Musica *m =
&primeira; m != NULL; m = m->proxima)`. Total em segundos `t`: `t / 60` minutos
e `t % 60` segundos. Isso já é uma **lista encadeada**; no módulo 11 os nós
passam a vir do `malloc`.

</details>

## Questões no estilo da prova

Questões objetivas no formato da prova do mestrado do PPGI/UFAM. Resolva no
papel, marque uma letra e só então abra o gabarito. Todos os trechos foram
compilados com `gcc -std=c17 -Wall -Wextra`. Quando a resposta depende da
máquina, a questão diz qual.

**Questão 1.** Em uma plataforma de 64 bits típica (`int` de 4 bytes,
alinhado em 4), quanto valem `sizeof(struct a)` e `sizeof(struct b)`?

```c
struct a { char x; int y; char z; };
struct b { int y; char x; char z; };
```

- (A) 6 e 6
- (B) 12 e 8
- (C) 12 e 12
- (D) 8 e 8
- (E) 9 e 6

<details><summary>Gabarito</summary>

**(B)**. Em `a`: `x` no byte 0, 3 bytes de preenchimento, `y` nos bytes 4 a
7, `z` no 8 e mais 3 de preenchimento no fim para o tamanho ser múltiplo de 4
(um vetor de `struct a` precisa manter cada `y` alinhado): 12. Em `b`: `y`
de 0 a 3, `x` no 4, `z` no 5, 2 bytes no fim: 8. Mesmos campos, ordem
diferente, tamanho diferente. Veja 0059.

</details>

**Questão 2.** Em uma plataforma de 64 bits típica, quanto vale
`sizeof(union u)`?

```c
union u { int i; double d; char s[10]; };
```

- (A) 22
- (B) 10
- (C) 8
- (D) 16
- (E) 24

<details><summary>Gabarito</summary>

**(D)**. Os campos de uma union começam no mesmo endereço; o tamanho é o do
maior campo (10, do `s`) arredondado para o alinhamento mais exigente (8, do
`double`): 16. Somar os campos (22) seria o raciocínio de uma struct sem
preenchimento. Veja 0064.

</details>

**Questão 3.** O que o trecho imprime?

```c
enum cor { AZUL, VERDE = 5, AMARELO, ROXO = 2, CINZA };
printf("%d %d %d %d %d\n", AZUL, VERDE, AMARELO, ROXO, CINZA);
```

- (A) `0 5 6 2 3`
- (B) `1 5 6 2 3`
- (C) `0 5 2 2 3`
- (D) `0 5 6 2 7`
- (E) não compila: valores de enum fora de ordem

<details><summary>Gabarito</summary>

**(A)**. O primeiro vale 0; cada nome sem valor vale o anterior mais 1.
`AMARELO` continua do 5 (6), e `CINZA` continua do 2 (3). Valores fora de
ordem e até repetidos são permitidos. Veja 0063.

</details>

**Questão 4.** O que o trecho imprime?

```c
typedef struct { int qtd; double preco; } Item;

Item a = {2, 9.5};
Item b = a;
Item *p = &a;
b.qtd = 7;
p->preco = 10.0;
printf("%d %.1f %d %.1f\n", a.qtd, a.preco, b.qtd, b.preco);
```

- (A) `7 10.0 7 10.0`
- (B) `2 9.5 7 10.0`
- (C) `7 9.5 7 9.5`
- (D) `2 10.0 7 10.0`
- (E) `2 10.0 7 9.5`

<details><summary>Gabarito</summary>

**(E)**. `b = a` copia o registro inteiro: `b` é independente, e mudar
`b.qtd` não mexe em `a`. Já `p` guarda o endereço de `a`, então
`p->preco` (o mesmo que `(*p).preco`) muda `a.preco`. `b.preco` continua com
a cópia antiga, 9.5. Veja 0059 e 0062.

</details>

**Questão 5.** Com `unsigned x = 0xB4;` (binário `1011 0100`), quanto valem
`x & 0x0F`, `x | 0x01` e `x >> 2`?

- (A) `0x0B`, `0xB5`, `0x2D`
- (B) `0x04`, `0xB4`, `0x2D`
- (C) `0x04`, `0xB5`, `0x2D`
- (D) `0x04`, `0xB5`, `0x5A`
- (E) `0xB0`, `0xB5`, `0x2D`

<details><summary>Gabarito</summary>

**(C)**. `& 0x0F` guarda só os 4 bits de baixo (`0100` = 0x04). `| 0x01`
liga o bit 0 (`1011 0101` = 0xB5). `>> 2` empurra tudo duas casas para a
direita (`0010 1101` = 0x2D); a resposta 0x5A seria `>> 1`. Veja 0065.

</details>

**Questão 6.** Qual o valor final de `flags` e o que o `printf` mostra?

```c
unsigned flags = 0x05;          /* 0101 */
flags |= 1u << 3;
flags &= ~(1u << 0);
printf("%u\n", (flags >> 2) & 1u);
```

- (A) `flags` = 0x0D; imprime 1
- (B) `flags` = 0x0C; imprime 1
- (C) `flags` = 0x0C; imprime 0
- (D) `flags` = 0x08; imprime 0
- (E) `flags` = 0x04; imprime 1

<details><summary>Gabarito</summary>

**(B)**. `|= 1u << 3` liga o bit 3: `1101` (0x0D). `&= ~(1u << 0)` desliga o
bit 0: `1100` (0x0C). `(flags >> 2) & 1u` testa o bit 2, que está ligado: 1.
São as três operações clássicas: ligar com `|`, desligar com `& ~`, testar
com `>>` e `&`. Veja 0065.

</details>

**Questão 7.** Em uma plataforma com `int` de 32 bits, o que o trecho
imprime?

```c
unsigned char c = 250;
c += 10;
int x = -1;
unsigned int u = 1;
printf("%d %d\n", c, x < u);
```

- (A) `260 1`
- (B) `4 1`
- (C) `260 0`
- (D) `-6 1`
- (E) `4 0`

<details><summary>Gabarito</summary>

**(E)**. `unsigned char` vai de 0 a 255 e a conta "dá a volta" módulo 256:
260 − 256 = 4 (para tipos sem sinal, isso é garantido pelo padrão). Na
comparação, o `int` −1 é convertido para `unsigned`, virando 4294967295, que
não é menor que 1: dá 0. O gcc avisa com `-Wsign-compare`. Veja 0065 (e
0171, que aprofunda com e sem sinal).

</details>

**Questão 8.** Em uma plataforma de 64 bits típica, o que o trecho imprime?

```c
#define PINT int *
typedef int *Pint;

int n = 0;
PINT a = &n, b = 0;
Pint c = &n, d = &n;
printf("%zu %zu %zu %zu\n", sizeof a, sizeof b, sizeof c, sizeof d);
```

- (A) `8 4 8 8`
- (B) `8 8 8 8`
- (C) `8 4 8 4`
- (D) `4 4 8 8`
- (E) não compila: `PINT` e `Pint` têm o mesmo nome

<details><summary>Gabarito</summary>

**(A)**. O `#define` só troca texto: a linha vira `int * a = &n, b = 0;`, e o
`*` vale só para `a`; `b` é um `int` (4 bytes). O `typedef` cria um nome de
tipo de verdade: `c` e `d` são os dois `int *` (8 bytes). E o C diferencia
maiúsculas de minúsculas, então os nomes não colidem. Veja 0060.

</details>

**Questão 9.** Em uma plataforma x86-64 (*little-endian*), o que o trecho
imprime?

```c
union { uint32_t n; unsigned char b[4]; } u;
u.n = 0x11223344;
printf("0x%02X 0x%02X %zu\n", u.b[0], u.b[3], sizeof u);
```

- (A) `0x11 0x44 4`
- (B) `0x11 0x44 8`
- (C) `0x44 0x11 8`
- (D) `0x44 0x11 4`
- (E) `0x33 0x22 4`

<details><summary>Gabarito</summary>

**(D)**. Os dois campos dividem os mesmos 4 bytes. Em *little-endian*, o
byte menos significativo (0x44) fica no endereço mais baixo, `b[0]`, e o
mais significativo (0x11) em `b[3]`. O tamanho é o do maior campo: 4. Numa
máquina *big-endian* a ordem dos bytes se inverte. Veja 0064.

</details>

**Questão 10.** O que o trecho imprime?

```c
#define DOBRO(x) x * 2
#define DOBRO_OK(x) ((x) * 2)

printf("%d %d\n", DOBRO(3 + 1), DOBRO_OK(3 + 1));
```

- (A) `8 8`
- (B) `5 5`
- (C) `5 8`
- (D) `8 5`
- (E) não compila: macro não recebe expressão

<details><summary>Gabarito</summary>

**(C)**. O pré-processador cola o texto antes de compilar: `DOBRO(3 + 1)`
vira `3 + 1 * 2`, e a multiplicação vem primeiro: 5. Com parênteses em volta
do parâmetro e da expressão inteira, `((3 + 1) * 2)` dá 8. Veja 0004 e 0060.

</details>

## Para ler mais

- BACKES, A. *Linguagem C: completa e descomplicada*. Rio de Janeiro: Elsevier, 2013. Cap. 8: struct, union, enum e typedef; cap. 13: campos de bits.
- BACKES, A. *Linguagem C: descomplicada*. Apostila. Uberlândia: FACOM/UFU, [s.d.].
- DEITEL, P.; DEITEL, H. *C: como programar*. 6. ed. São Paulo: Pearson, 2011. Cap. 10: estruturas, uniões, manipulações de bits e enumerações.
- CELES, W.; RANGEL, J. L. *Apostila de estruturas de dados*. Rio de Janeiro: PUC-Rio, 2002.
- CELES, W.; CERQUEIRA, R.; RANGEL, J. L. *Introdução a estruturas de dados: com técnicas de programação em C*. 2. ed. Rio de Janeiro: Elsevier, 2016. Tipos estruturados: struct, union, enum e typedef.
- TENENBAUM, A. M.; LANGSAM, Y.; AUGENSTEIN, M. J. *Estruturas de dados usando C*. São Paulo: Makron Books, 1995. Cap. 1: estruturas e uniões em C.
- ZIVIANI, N. *Projeto de algoritmos: com implementações em Pascal e C*. 3. ed. rev. e ampl. São Paulo: Cengage Learning, 2010. Registros e tipos definidos pelo programador nas implementações em C.
- MARTINS, L. G. A. *Apostila de linguagem C: conceitos básicos*. Uberlândia: FACOM/UFU, [s.d.].
- ANTONELLO, R. *Linguagem C*. 1. ed. Disponível em: <http://www.antonello.com.br>.
- KERNIGHAN, B. W.; RITCHIE, D. M. *The C programming language*. 2. ed. Englewood Cliffs: Prentice Hall, 1988. Cap. 6: structures.
- CPPREFERENCE. *Struct declaration*; *Union declaration*; *Enumerations*; *Bitwise operators*. Disponível em: <https://en.cppreference.com/w/c/language>.
- LINUX MAN PAGES. *chmod(2)*, *inode(7)* (bits de permissão) e *byteorder(3)* (`htonl`, `ntohl`). Disponível em: <https://man7.org/linux/man-pages/>.
