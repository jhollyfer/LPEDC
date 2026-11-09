# Módulo 05 · Vetores, matrizes e strings

Até aqui, cada variável guardava um valor. Para guardar as notas de uma turma,
os passos de um mês ou as poltronas de um cinema, você precisaria de dezenas
de variáveis. Este módulo traz a primeira **estrutura de dados** do curso: o
**vetor**, várias variáveis do mesmo tipo com um nome só, lado a lado na
memória.

No C, o vetor é um bloco de bytes. Tamanho fixo, nenhum `length`, nenhuma
conferência de índice. Parece pouco, e é por isso que é rápido: acessar a
posição 999 custa o mesmo que acessar a 0.

E o texto? O C não tem um tipo string. Uma string é um vetor de `char` que
termina num byte zero, o `'\0'`. Esse detalhe explica boa parte das falhas de
segurança da história do software.

## O que você vai aprender

- declarar, inicializar e percorrer **vetores**, e por que o índice começa em 0
- passar vetores para **funções** (vai o endereço, não uma cópia) e proteger com `const`
- **matrizes**: linhas, colunas e a memória contínua por baixo
- **caracteres** como números: a tabela ASCII e o `<ctype.h>`
- **strings**: o `'\0'`, o `<string.h>` e o estouro de buffer
- **ler texto** do teclado com segurança: `fgets`, o `'\n'` e por que o `gets` foi banido

## Antes de começar

Você vai usar tudo dos módulos anteriores, principalmente laços (`for` e
laços aninhados), os padrões contador, acumulador e maior/menor, e funções com
parâmetros. Ponteiros ainda não apareceram: quando o texto disser "vai o
endereço do vetor", guarde a ideia, que o módulo 06 mostra a sintaxe.

Nos desenhos, cada gaveta do vetor tem o índice embaixo, em cinza. Quase todo
assunto aqui é um laço: siga o fluxograma com o dedo e, ao rodar, mude um
tamanho ou um índice de propósito. Responda a **Pergunta para você** de cada
assunto antes de rodar.

O **AddressSanitizer** do `rodar` confere, enquanto o programa roda, o que o
C não confere: índice e tamanho de string. Quando aparecer
`stack-buffer-overflow` ou `index out of
bounds`, leia a linha indicada: é quase sempre um `<=` no lugar de `<` ou um
`'\0'` que ficou sem lugar.

{{indice}}

---

{{assuntos}}

---

## Desafios do módulo

Problemas extras para treinar, misturando os assuntos do módulo. Resolva num
arquivo seu e rode com o `rodar`.

**1. Segundo maior.** Dado `int v[] = {14, 9, 27, 3, 27, 18};`, ache o segundo
maior valor **diferente** do maior, numa passada só, sem ordenar.

<details><summary>Resposta</summary>

O maior é 27 e o segundo maior é **18** (o outro 27 não conta). Guarde
`maior` e `segundo`. Para cada item: se for maior que `maior`, o antigo
`maior` desce para `segundo`; senão, se for menor que `maior` e maior que
`segundo`, ele vira o `segundo`. Comece os dois com o menor `int` possível
(`INT_MIN`, de `<limits.h>`).

</details>

**2. Remover duplicados de um vetor ordenado.** `int v[] = {2, 2, 3, 5, 5, 5,
8, 9, 9};` Deixe cada valor uma vez só, **no próprio vetor**, e devolva o novo
tamanho.

<details><summary>Resposta</summary>

Fica `2 3 5 8 9` e o tamanho **5**. Use dois índices: `escrita` começa em 1;
`leitura` anda de 1 até o fim e, sempre que `v[leitura] != v[escrita - 1]`,
copia para `v[escrita]` e avança `escrita`. Uma passada só, sem vetor extra.
As posições depois do novo tamanho continuam com valores velhos: quem chama
passa a usar só o tamanho devolvido.

</details>

**3. Juntar duas listas ordenadas.** `a = {1, 4, 9, 12}` e `b = {2, 3, 10}`.
Monte `c` com os 7 valores em ordem, sem ordenar `c` depois.

<details><summary>Resposta</summary>

`1 2 3 4 9 10 12`. Um índice em cada vetor: compare `a[i]` com `b[j]`, copie
o menor para `c[k]` e avance quem foi copiado. Quando um acabar, copie o
resto do outro. É o coração do *merge sort* (assunto 0094).

</details>

**4. Girar a matriz.** Gire `{{1, 2, 3}, {4, 5, 6}}` (2×3) 90° no sentido
horário, gerando uma 3×2.

<details><summary>Resposta</summary>

Resultado: `4 1 / 5 2 / 6 3`. A regra é `g[c][L - 1 - l] = m[l][c]`, com
`L` = número de linhas da original (2). Confira com a célula do 6: na
original está em `[1][2]`, na girada vai para `[2][0]`.

</details>

**5. Quadrado mágico?** Escreva `bool eh_magico(int m[][4])` para uma matriz
4×4: todas as linhas, colunas e as duas diagonais com a mesma soma. Teste com
`{{16, 3, 2, 13}, {5, 10, 11, 8}, {9, 6, 7, 12}, {4, 15, 14, 1}}`.

<details><summary>Resposta</summary>

É mágico: tudo soma **34**. Calcule a soma da primeira linha como referência
e compare as outras 9 somas (3 linhas, 4 colunas, 2 diagonais) com ela. Na
primeira diferente, devolva `false`.

</details>

**6. Anagramas.** "Roma" e "amor" são anagramas (mesmas letras, outra ordem).
Escreva `bool anagramas(const char a[], const char b[])` sem ordenar nada,
ignorando maiúsculas.

<details><summary>Resposta</summary>

Um vetor `int conta[26] = {0}`: cada letra de `a` soma 1 em
`conta[tolower(c) - 'a']`, cada letra de `b` subtrai 1. São anagramas se,
no fim, as 26 posições forem zero. "Roma" e "amor": **sim**. Antes de usar
o caractere como índice, confira com `isalpha`: um espaço ou um byte de "ã"
daria um índice fora do vetor.

</details>

**7. Achar uma palavra dentro da outra.** Sem usar `strstr`, escreva
`int posicao(const char texto[], const char busca[])` que devolve a posição em que
`busca` começa em `texto`, ou -1.

<details><summary>Resposta</summary>

`posicao("banana split", "na")` é **2**; `posicao("banana", "uva")` é **-1**.
Para cada `i` do texto, compare `texto[i + k]` com `busca[k]` enquanto forem
iguais e `busca[k] != '\0'`. Se chegou ao `'\0'` da busca, achou em `i`. Não
precisa de cuidado extra com o fim do texto: o `'\0'` do texto é diferente
de qualquer letra da busca, e a comparação para ali.

</details>

**8. Somar números gigantes.** `long long` vai até uns 9 × 10¹⁸. Some
`"98765432109876543210"` com `"12345678901234567890"` guardando os números
como strings, dígito a dígito, como na escola.

<details><summary>Resposta</summary>

**111111111011111111100**. Ande do último dígito para o primeiro nas duas
strings, some `(a[i] - '0') + (b[j] - '0') + vai_um`, guarde
`soma % 10` e leve `soma / 10`. O resultado sai de trás para frente: inverta
no fim (ou escreva de trás para frente num vetor com uma posição extra para o
último "vai um").

</details>

**9. Cifra de Vigenère.** É a César com um deslocamento diferente para cada
letra, dado por uma chave que se repete (A = 0, B = 1, ..., L = 11...).
Escreva `void vigenere(char texto[], const char chave[], int sentido)` que
cifra o texto no próprio vetor com `sentido` 1 e decifra com -1. No `main`,
cifre `char msg[] = "ATACARAGORA"` com a chave "LIMAO", mostre, decifre e
mostre de novo.

<details><summary>Resposta</summary>

```text
Cifrado:   LBMCOCISOFL
Decifrado: ATACARAGORA
```

A letra `i` do texto anda `chave[i % strlen(chave)] - 'A'` posições: A + L =
L, T + I = B, A + M = M, C + A = C, A + O = O, R + L = C, e assim por diante,
sempre com `% 26`. Para decifrar, ande `26 - desloc`, o que mantém a conta
sem número negativo.

</details>

**10. Jogo da vida, duas gerações.** Numa matriz 5×5 de 0 e 1, cada célula
viva com 2 ou 3 vizinhas vivas continua viva; uma morta com exatamente 3
vizinhas nasce; o resto morre ou fica morto. Escreva
`void proxima(int m[5][5], int nova[5][5])` e uma função que mostre a matriz
com `#` para viva e `.` para morta. Comece com um "pisca-pisca", uma linha de
três vivas no meio (`m[2][1]`, `m[2][2]`, `m[2][3]`), e mostre as gerações 0,
1 e 2.

<details><summary>Resposta</summary>

```text
Geração 0:
.....
.....
.###.
.....
.....
Geração 1:
.....
..#..
..#..
..#..
.....
Geração 2:
.....
.....
.###.
.....
.....
```

A linha vira **coluna** e volta a ser linha. O cuidado: calcule tudo numa
**segunda matriz**. Se você atualizar a original enquanto conta, as células
já mudadas atrapalham a contagem das vizinhas. A contagem de vizinhas é a do
campo minado (E234). Para a geração 2, chame `proxima(b, a)`: as duas
matrizes revezam.

</details>

## Questões no estilo da prova

Questões objetivas no formato da Prova de Conhecimentos do PPGI: uma
alternativa certa. Nas de vetor, desenhe as gavetas com os índices embaixo;
nas de string, não esqueça a gaveta do `'\0'`.

**1.** Numa máquina de 64 bits (ponteiro de 8 bytes, `int` de 4), o que
`tam(v)` mostra quando `v` é um `int v[10]`?

```c
void tam(int v[]) {
    printf("%zu\n", sizeof(v) / sizeof(v[0]));
}
```

- (A) 10
- (B) 40
- (C) 2
- (D) 1
- (E) 8

<details><summary>Gabarito</summary>

**(C).** Um vetor passado para função chega como o **endereço** do primeiro
item. Dentro de `tam`, `v` é um `int *`: `sizeof(v)` é 8, e 8 / 4 = 2. A
conta `sizeof(v) / sizeof(v[0])` só funciona no bloco em que o vetor foi
declarado; por isso o tamanho vai como parâmetro. O gcc avisa
(`-Wsizeof-array-argument`). Veja 0038.

</details>

**2.** Qual a saída?

```c
void zera(int v[], int n) {
    for (int i = 0; i < n; i++)
        v[i] = 0;
}

int main(void) {
    int a[3] = {1, 2, 3};
    zera(a, 2);
    printf("%d %d %d\n", a[0], a[1], a[2]);
    return 0;
}
```

- (A) 0 0 3
- (B) 1 2 3
- (C) 0 0 0
- (D) 1 0 0
- (E) 0 2 3

<details><summary>Gabarito</summary>

**(A).** A passagem continua sendo por valor, mas o valor copiado é o
**endereço** do vetor. A função escreve nas gavetas originais. Com `n = 2`,
só `a[0]` e `a[1]` viram 0. Veja 0038.

</details>

**3.** Qual a saída?

```c
char s[20] = "Manaus";
printf("%zu %zu\n", strlen(s), sizeof(s));
```

- (A) 6 6
- (B) 7 20
- (C) 6 7
- (D) 6 20
- (E) 20 20

<details><summary>Gabarito</summary>

**(D).** `strlen` conta os caracteres **antes** do `'\0'`: 6. `sizeof` mede
o vetor inteiro, 20 bytes, usados ou não. O 7 seria `sizeof` de
`char s[] = "Manaus"`, em que o compilador conta o `'\0'`. Veja 0041.

</details>

**4.** Em `int m[3][4];`, quantos `int` ficam na memória **antes** de
`m[2][1]`?

- (A) 6
- (B) 9
- (C) 5
- (D) 3
- (E) 8

<details><summary>Gabarito</summary>

**(B).** O C guarda a matriz linha após linha (*row-major*). Antes da linha
2 vêm 2 linhas de 4, e dentro dela vem 1 item: `2 * 4 + 1 = 9`. O 5 seria a
conta por colunas (`1 * 3 + 2`), que não é a do C. Veja 0039.

</details>

**5.** Depois de `int w[5] = {3, 1};`, quanto vale a soma dos 5 itens?

- (A) lixo, porque três itens não foram inicializados
- (B) 3
- (C) 15
- (D) 8
- (E) 4

<details><summary>Gabarito</summary>

**(E).** Com inicializador, o que falta vira **zero**: o vetor é
`{3, 1, 0, 0, 0}`. Lixo só aparece num vetor local declarado **sem** nenhum
inicializador. Veja 0037.

</details>

**6.** Qual a saída?

```c
char t[10] = "ufam\0pg";
int i = 0;
while (t[i])
    i++;
printf("%d\n", i);
```

- (A) 7
- (B) 10
- (C) 4
- (D) 6
- (E) 8

<details><summary>Gabarito</summary>

**(C).** O laço para no primeiro byte zero, e o `\0` escrito no meio do
texto é um zero de verdade, na posição 4. Para qualquer função de string, o
`t` é só `"ufam"`; o `pg` continua na memória, mas ninguém enxerga. Veja 0041.

</details>

**7.** Qual a saída?

```c
char x[] = "PPGI", y[] = "PPGI";
printf("%d %d\n", x == y, strcmp(x, y) == 0);
```

- (A) 1 1
- (B) 0 1
- (C) 1 0
- (D) 0 0
- (E) não compila: vetores não se comparam com `==`

<details><summary>Gabarito</summary>

**(B).** `x == y` compara os **endereços** dos dois vetores, que são
diferentes: 0. Quem compara o conteúdo, letra por letra, é o `strcmp`, que
devolve 0 quando são iguais. Compila, com o aviso
`comparison between two arrays`. Veja 0041.

</details>

**8.** Sobre o trecho abaixo, é correto afirmar:

```c
int v[5] = {1, 2, 3, 4, 5};
int s = 0;
for (int i = 0; i <= 5; i++)
    s += v[i];
```

- (A) `s` termina em 15, porque o C ignora índices fora do vetor.
- (B) `s` termina em 15, porque `v[5]` vale sempre 0.
- (C) o compilador rejeita o código, porque o laço passa do fim do vetor.
- (D) a última volta lê `v[5]`, que não existe: é comportamento indefinido.
- (E) o laço roda 5 vezes, de `v[0]` a `v[4]`.

<details><summary>Gabarito</summary>

**(D).** Num vetor de 5, os índices vão de 0 a 4. O `<=` faz uma sexta
volta, com `i = 5`, que lê o que estiver depois do vetor. O C **não confere**
índices: compila sem erro e o resultado pode ser qualquer coisa. O detector
do `rodar` acusa `index 5 out of bounds`. Veja 0037.

</details>

**9.** Qual o valor de `s`?

```c
#define N 3
int m[N][N] = {{2, 0, 1}, {3, 5, 4}, {6, 7, 8}};
int s = 0;
for (int k = 0; k < N; k++)
    s += m[k][N - 1 - k];
```

- (A) 12
- (B) 15
- (C) 13
- (D) 36
- (E) 9

<details><summary>Gabarito</summary>

**(A).** `m[k][N - 1 - k]` percorre a **diagonal secundária**: `m[0][2]`,
`m[1][1]` e `m[2][0]`, ou 1 + 5 + 6 = 12. O 15 é a diagonal principal
(`m[k][k]`: 2 + 5 + 8); o 36, a matriz inteira. Veja 0039.

</details>

**10.** A pessoa digita `Manaus` e aperta Enter. O que o trecho mostra?

```c
char lin[10];
if (fgets(lin, sizeof lin, stdin) != NULL)
    printf("%zu\n", strlen(lin));
```

- (A) 6
- (B) 10
- (C) 8
- (D) 9
- (E) 7

<details><summary>Gabarito</summary>

**(E).** O `fgets` guarda a linha **com** o `'\n'` do Enter, quando cabe:
`lin` fica `"Manaus\n"`, 7 caracteres antes do `'\0'`. Por isso o costume de
tirar o `'\n'` com `lin[strcspn(lin, "\n")] = '\0';`. Veja 0042.

</details>

## Para ler mais

- BACKES, A. *Linguagem C: completa e descomplicada*. Rio de Janeiro: Elsevier, 2013. Caps. 6 (vetores e matrizes), 7 (strings) e 9 (passagem de vetores para funções).
- BACKES, A. *Linguagem C: apostila*. Uberlândia: UFU, [s.d.]. Seções de vetores, matrizes e strings.
- DEITEL, P.; DEITEL, H. *C: como programar*. 6. ed. São Paulo: Pearson, 2011. Caps. 6 (arrays) e 8 (caracteres e strings).
- DEITEL, P.; DEITEL, H. *C: how to program*. 7. ed. Boston: Pearson, 2013. Caps. 6 e 8.
- CELES, W.; CERQUEIRA, R.; RANGEL, J. L. *Introdução a estruturas de dados: com técnicas de programação em C*. 2. ed. Rio de Janeiro: Elsevier, 2016. Capítulos de vetores, matrizes e cadeias de caracteres.
- TENENBAUM, A. M.; LANGSAM, Y.; AUGENSTEIN, M. J. *Estruturas de dados usando C*. São Paulo: Makron Books, 1995. Cap. 1: vetores e strings em C.
- ANTONELLO, R. *Linguagem C*. 1. ed. Disponível em: <http://www.antonello.com.br>. Cap. 8.
- LEAL, G. C. L. *Algoritmos e lógica de programação II*. Maringá: Unicesumar, 2016. Unidades de vetores, matrizes e strings.
- KERNIGHAN, B. W.; RITCHIE, D. M. *C: a linguagem de programação padrão ANSI*. Rio de Janeiro: Campus, 1989. Caps. 1.6, 1.9 e 5.
- CPPREFERENCE. *Null-terminated byte strings*. Disponível em: <https://en.cppreference.com/w/c/string/byte>.
- LINUX MAN-PAGES PROJECT. *fgets(3)*, *string(3)*, *ctype(3)*. Disponível em: <https://man7.org/linux/man-pages/>.
- SPAFFORD, E. H. The Internet worm program: an analysis. *ACM SIGCOMM Computer Communication Review*, v. 19, n. 1, p. 17-57, 1989.
