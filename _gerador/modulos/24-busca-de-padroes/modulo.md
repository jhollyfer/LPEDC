# Módulo 24 · Busca de padrões em texto

Ctrl+F, `grep`, o antivírus, o filtro de palavrões do chat, o trecho de DNA
num genoma de 3 bilhões de letras: tudo é achar um **padrão** de `m` letras
num **texto** de `n` letras.

Testar cada posição funciona, mas o pior caso é O(n·m). Este módulo traz três
ideias melhores: **não reler** o que já foi visto (KMP), **pular** o que não
pode dar certo (Horspool) e **comparar números** em vez de letras
(Rabin-Karp). No fim, os quatro algoritmos viram um TAD e você monta um
**mini-grep** que mede qual trabalha menos.

## O que você vai aprender

- a **força bruta** e o `strstr`: ocorrências sobrepostas e a armadilha do
  `size_t`
- o **KMP**: bordas, tabela π e busca O(n + m) sem voltar no texto
- o **Horspool**: comparar da direita para a esquerda e saltar com uma tabela
  de 256 posições
- o **Rabin-Karp**: hash rolante, aritmética modular e falsos positivos
- a comparar algoritmos por **comparações de letra** e por `clock()`

## Antes de começar

Usa strings (0041), ponteiros (0047), `size_t` (0003), análise de custo (0072),
invariantes (0073), hashing (0105) e ponteiros para função (0050).

Nos diagramas, o texto é uma fileira de gavetas com o padrão embaixo. **Verde**
é letra que bateu ou ocorrência achada, **vermelha** a que falhou (ou o falso
positivo), **amarela** a que decide o próximo passo, **roxa** o padrão,
**azul** texto ainda não comparado e **cinza** o que não precisou ser olhado.
Faça o passo a passo no papel antes de rodar.

Este módulo é complemento: não cai direto na prova do PPGI (o que mais cai
está em `PPGI.md`, na raiz do curso).

Os quatro primeiros assuntos têm um arquivo só por exemplo; no 0161 os
algoritmos viram o TAD `padroes.h`, compilado junto com os exemplos e
exercícios da pasta. Os exemplos contam **comparações de letra**, um custo que
dá o mesmo número em qualquer máquina; o tempo de relógio só aparece no A321.
Os algoritmos trabalham com **bytes**: em UTF-8, letra acentuada tem dois
bytes acima de 127, que num `char` com sinal viram negativos e quebram o uso
como índice de tabela (assunto 0159).

{{indice}}

---

{{assuntos}}

---

### Desafios do módulo

Problemas para fechar o módulo, misturando os assuntos. Escreva em C e rode
com as flags de estudo.

**1. O curinga.** Adapte a força bruta para aceitar `?` no padrão, valendo
qualquer letra. Procure `c?sa` em `"casa cosa cesta case"`.

<details><summary>Resposta</summary>

A única mudança é a comparação do laço de dentro: a letra casa se
`padrao[j] == '?' || padrao[j] == texto[i + j]`. As ocorrências ficam em **0**
("casa") e **5** ("cosa"); "cesta" falha no `t` e "case" no `e`. O KMP e o
Horspool não se adaptam tão fácil: a tabela π e a de saltos supõem que
cada letra do padrão é uma letra só.

</details>

**2. Quantas, afinal?** Num texto com mil letras `a`, quantas ocorrências de
`aa` existem contando as sobrepostas? E sem contar? Quantas comparações a força
bruta faz?

<details><summary>Resposta</summary>

Sobrepostas: **999** (uma para cada `i` de 0 a 998). Sem sobreposição
(recomeçando em `i + m` depois de achar): **500**. A força bruta testa os 999
alinhamentos e compara as 2 letras em todos: **1998** comparações. Aqui ela
faz o máximo possível, porque todo alinhamento é uma ocorrência.

</details>

**3. A tabela π de um nome.** Calcule a tabela π de `paraparapa` e diga qual é
a maior borda da palavra inteira.

<details><summary>Resposta</summary>

`pi = 0 0 0 0 1 2 3 4 5 6`. A maior borda tem **6** letras: `parapa`, que é o
começo e também o fim de `paraparapa`. Seguindo a corrente, `pi[5] = 2` dá a
borda seguinte, `pa`. O menor período é `10 - 6 = 4` ("para"), mas 4 não divide
10: a palavra não é uma repetição exata (sobra um "pa").

</details>

**4. O salto perfeito.** Um texto de 3000 letras não tem nenhum `x`, `y` ou `z`.
Quantos alinhamentos e quantas comparações o Horspool faz para procurar `xyz`?
E a força bruta?

<details><summary>Resposta</summary>

Toda letra sob a última casa está fora do padrão, então todo salto é 3: os
alinhamentos são `i = 0, 3, ..., 2997`, **1000** ao todo, com 1 comparação
cada: **1000** comparações. A força bruta testa os 2998 alinhamentos, com uma
comparação cada (o `x` nunca bate): **2998**. É o melhor caso do Horspool,
`n / m`.

</details>

**5. Rotação.** Escreva `bool eh_rotacao(const char *a, const char *b)`, que diz
se `b` é `a` "girada" (como `drape` é `pedra` girada). Use uma busca de padrão,
em O(n).

<details><summary>Resposta</summary>

Se os tamanhos diferem, não é. Senão, monte `a + a` (por exemplo,
`pedrapedra`) e procure `b` nela com o KMP: toda rotação de `a` aparece dentro
de `a + a`. `drape` aparece na posição 2, então **é** rotação; `perda` não
aparece, então **não é**. Custo O(n) com o KMP; a força bruta aqui pode chegar
a O(n²).

</details>

**6. Quase igual.** Procure `casa` em `"a cosa e a caza na casa"` aceitando
**até uma letra diferente** (o mesmo tamanho, sem inserir nem apagar).

<details><summary>Resposta</summary>

Força bruta que conta as diferenças de cada alinhamento e desiste quando passa
de 1. Aparecem `cosa` na posição **2**, `caza` na **11** e `casa` (exata) na
**19**. Os algoritmos espertos do módulo supõem casamento exato; busca
aproximada é outra família (a distância de edição, do assunto 0142, é o
começo dela).

</details>

**7. Vários tamanhos.** O filtro de spoiler do A320 só funciona com palavras do
mesmo tamanho. Como estender o Rabin-Karp para `{"final", "morre", "vilao",
"mata", "beijo"}`?

<details><summary>Resposta</summary>

Agrupe os padrões por tamanho: aqui, 5 letras (`final`, `morre`, `vilao`,
`beijo`) e 4 (`mata`). Faça uma passada com janela rolante de 5 e outra de 4
(ou as duas no mesmo laço, com dois hashes rolando juntos). Com `k` tamanhos
diferentes, o custo é O(k·n) mais as conferências. Para dezenas de tamanhos,
a estrutura certa é uma trie com ligações de falha (o algoritmo de
Aho-Corasick, um "KMP para vários padrões").

</details>

**8. O pior caso do Rabin-Karp.** Mostre um texto e um padrão em que o
Rabin-Karp faz `(n - m + 1) · m` comparações de letra, por maior que seja o
`q`.

<details><summary>Resposta</summary>

Texto `aaaa...a` e padrão `aaa`. Todas as janelas são iguais ao padrão, então
todos os hashes batem, e **não são** falsos positivos: cada conferência é
necessária e compara `m` letras. Nenhuma escolha de `q` evita isso. O mesmo
texto deixa a força bruta e o Horspool no máximo também; só o KMP fica em O(n),
porque depois de achar ele reaproveita a borda.

</details>

**9. A palavra inteira, com `strstr`.** Conte quantas vezes a palavra `de`
aparece **sozinha** em `"desde cedo, de dia e de noite, ele decide"`, usando
`strstr` e `isalpha`.

<details><summary>Resposta</summary>

Chame `strstr` a partir de `p + 1` depois de cada achado e, para cada `p`,
confira se a letra antes (se existir) e a letra em `p + 2` não são letras. Os
`de` de "desde" (dois) e de "decide" (dois, no começo e no fim) ficam de fora; sobram **2**: "de dia" e
"de noite". O cuidado é não ler `p[-1]` quando `p` é o começo do texto.

</details>

**10. O grep com contexto.** Estenda o A322 com a opção `-C 1`: além da linha
que tem o padrão, mostre a anterior e a seguinte, sem repetir linhas quando
duas ocorrências estão perto.

<details><summary>Resposta</summary>

Guarde a linha anterior num segundo buffer (copiando com `strcpy` antes de
ler a próxima) e um contador "faltam mostrar depois". Ao achar, mostre a
anterior se ela ainda não saiu, mostre a atual e ponha o contador em 1. Numa
linha sem o padrão, se o contador é positivo, mostre e decremente. Uma variável
com o número da última linha impressa evita repetição. É um exercício de
máquina de estados com `fgets`, e a busca continua sendo uma chamada só.

</details>

### Questões no estilo da prova

Questões no formato da prova do PPGI, que treinam o que cai nela: contar passos, reconhecer a complexidade e seguir
uma tabela à mão. Uma alternativa certa em cada.

**1.** Qual é a tabela π (função prefixo do KMP, `pi[j]` = tamanho da maior
borda de `p[0..j]`) do padrão `aabaaab`?

- (A) 0 1 0 1 2 3 3
- (B) 0 0 0 1 2 2 3
- (C) 0 1 0 1 2 2 3
- (D) 0 1 2 0 1 2 3
- (E) 0 1 0 0 1 2 3

<details><summary>Gabarito</summary>

**(C).** `a` (0), `aa` (borda `a`, 1), `aab` (0), `aaba` (`a`, 1), `aabaa`
(`aa`, 2), `aabaaa` (`aa`, 2: a borda `aab` não serve, o recuo cai em
`pi[1] = 1` e o `a` casa), `aabaaab` (`aab`, 3). Veja 0158.

</details>

**2.** O programa abaixo procura `aaab` em `aaaaaaaa` por força bruta, com
comparação letra a letra, e para no primeiro erro de cada alinhamento. O que
ele mostra (comparações e posição achada, com -1 se não achar)?

```c
#include <stdio.h>
#include <string.h>

int main(void) {
    const char *t = "aaaaaaaa", *p = "aaab";
    int n = strlen(t), m = strlen(p), cmp = 0, achou = -1;
    for (int i = 0; i + m <= n && achou < 0; i++) {
        int j = 0;
        while (j < m) {
            cmp++;
            if (t[i + j] != p[j]) break;
            j++;
        }
        if (j == m) achou = i;
    }
    printf("%d %d\n", cmp, achou);
    return 0;
}
```

- (A) 20 -1
- (B) 8 -1
- (C) 32 -1
- (D) 20 4
- (E) 5 -1

<details><summary>Gabarito</summary>

**(A).** Há `n − m + 1 = 5` alinhamentos, e em cada um os três `a` casam e o
`b` falha: 4 comparações. São 5 × 4 = 20, o pior caso `(n − m + 1) · m`, que
é O(n · m), e nenhum alinhamento casa (-1). O KMP faria no máximo `2n = 16`.
Veja 0157.

</details>

**3.** Sobre o custo dos algoritmos de busca de padrão, com texto de tamanho
`n` e padrão de tamanho `m`, analise as afirmações.

- I. O KMP faz, no pior caso, Θ(n · m) comparações, como a força bruta.
- II. O KMP gasta O(m) para montar a tabela π e O(n) na busca.
- III. O Horspool costuma pular letras do texto e comparar menos que o KMP em
  textos comuns, mas o pior caso dele continua O(n · m).

Marque a alternativa **CORRETA**.

- (A) I, apenas.
- (B) I e II, apenas.
- (C) II e III, apenas.
- (D) I e III, apenas.
- (E) I, II e III.

<details><summary>Gabarito</summary>

**(C).** II é verdadeira: na busca, `k` sobe no máximo uma vez por letra do
texto e cada recuo o diminui, então avanços e recuos somam no máximo `2n`; o
mesmo argumento vale para montar a tabela. Por isso I é falsa. III é
verdadeira: o salto do Horspool ajuda na média, não na pior entrada. Veja
0158 e 0159.

</details>

**4.** O Rabin-Karp procura `26` em `31415926535`, com os dígitos lidos como
números na base 10 e hash módulo `q = 11`. Quantos **falsos positivos**
(janelas com o mesmo hash do padrão, mas diferentes dele) aparecem?

- (A) 0
- (B) 3
- (C) 1
- (D) 4
- (E) 10

<details><summary>Gabarito</summary>

**(B).** O hash do padrão é 26 mod 11 = 4. As janelas 15, 59 e 92 também
deixam resto 4 e são conferidas letra a letra à toa; a 26 é a única
ocorrência de verdade. Quatro janelas batem no hash (D), mas uma delas é
verdadeira. Veja 0160.

</details>

**5.** No Horspool, o salto de cada letra `c` é `m − 1 − j`, com `j` a
última posição de `c` em `p[0..m−2]`, ou `m` se `c` não aparece ali. Para o
padrão `banana`, quais os saltos de `a`, `n`, `b` e `x`?

- (A) 1, 2, 5, 6
- (B) 0, 1, 5, 6
- (C) 2, 1, 5, 5
- (D) 2, 1, 5, 6
- (E) 1, 2, 6, 6

<details><summary>Gabarito</summary>

**(D).** Em `banan` (sem a última letra), o último `a` está na posição 3
(salto 2), o último `n` na 4 (salto 1) e o `b` na 0 (salto 5). O `x` não
aparece: salto `m = 6`. A última letra do padrão fica de fora para que
nenhum salto seja 0 (alternativa B). Veja 0159.

</details>

**6.** Sobre o Rabin-Karp com módulo primo `q`, analise as afirmações.

- I. Hashes iguais garantem janelas iguais, então ele nunca precisa comparar
  letra a letra.
- II. O pior caso da busca é Θ((n − m + 1) · m), quando quase toda janela
  colide.
- III. O hash rolante atualiza o hash da janela seguinte em O(1).
- IV. O pré-processamento (hash do padrão e da primeira janela) é Θ(m).

Marque a alternativa **CORRETA**.

- (A) I e II, apenas.
- (B) I e III, apenas.
- (C) III e IV, apenas.
- (D) II, III e IV, apenas.
- (E) I, II, III e IV.

<details><summary>Gabarito</summary>

**(D).** I é falsa: hash igual pode ser colisão (falso positivo), então a
conferência letra a letra é obrigatória. II, III e IV são verdadeiras; com
`q` grande e poucas ocorrências, o tempo esperado é O(n + m). Veja 0160.

</details>

**7.** Quantas ocorrências de `aba` existem em `abababa`, contando as que se
sobrepõem?

- (A) 2
- (B) 1
- (C) 4
- (D) 5
- (E) 3

<details><summary>Gabarito</summary>

**(E).** Nas posições 0, 2 e 4. Para achar as sobrepostas, o KMP recua para
`pi[m − 1]` depois de cada ocorrência, em vez de zerar o `k`; quem zera
acharia só 2 (A). Veja 0158.

</details>

**8.** No hash rolante na base 10 com módulo 13, a janela `271` tem hash
271 mod 13 = 11. Usando `h' = ((h − 2 · (100 mod 13)) · 10 + 8) mod 13`
(tirando o resultado negativo para o intervalo 0..12), qual o hash da
janela seguinte, `718`?

- (A) 3
- (B) 8
- (C) 11
- (D) 5
- (E) 0

<details><summary>Gabarito</summary>

**(A).** 100 mod 13 = 9; 11 − 2 · 9 = −7, que vira 6 no intervalo 0..12;
6 · 10 + 8 = 68, e 68 mod 13 = 3. Confere: 718 = 13 · 55 + 3. Em C, o `%`
de número negativo dá resultado negativo, por isso o código soma `q` antes.
Veja 0160.

</details>

## Para ler mais

- FEOFILOFF, P. *Algoritmos em linguagem C*. Rio de Janeiro: Elsevier, 2009. Cap. 13 (busca de palavras em um texto: algoritmo trivial e Boyer-Moore).
- FEOFILOFF, P. *Algoritmo de Knuth-Morris-Pratt*. São Paulo: IME-USP. Disponível em: <https://www.ime.usp.br/~pf/estruturas-de-dados/aulas/kmp.html>.
- SZWARCFITER, J. L.; MARKENZON, L. *Estruturas de dados e seus algoritmos*. 3. ed. Rio de Janeiro: LTC, 2010. Cap. de casamento de cadeias (força bruta e KMP).
- CORMEN, T. H.; LEISERSON, C. E.; RIVEST, R. L.; STEIN, C. *Algoritmos: teoria e prática*. 4. ed. Rio de Janeiro: GEN LTC, 2024. Cap. 32 (correspondência de cadeias: ingênuo, Rabin-Karp, autômatos e KMP).
- ZIVIANI, N. *Projeto de algoritmos: com implementações em Pascal e C*. 3. ed. rev. e ampl. São Paulo: Cengage Learning, 2010. Cap. 8 (processamento de cadeias de caracteres: casamento exato, KMP, Boyer-Moore e Boyer-Moore-Horspool).
- SEDGEWICK, R.; WAYNE, K. *Algorithms*. 4. ed. Boston: Addison-Wesley, 2011. Seção 5.3 (substring search).
- KNUTH, D. E.; MORRIS, J. H.; PRATT, V. R. Fast pattern matching in strings. *SIAM Journal on Computing*, v. 6, n. 2, p. 323-350, 1977.
- HORSPOOL, R. N. Practical fast searching in strings. *Software: Practice and Experience*, v. 10, n. 6, p. 501-506, 1980.
- KARP, R. M.; RABIN, M. O. Efficient randomized pattern-matching algorithms. *IBM Journal of Research and Development*, v. 31, n. 2, p. 249-260, 1987.
- CELES, W.; RANGEL, J. L. *Apostila de estruturas de dados*. Rio de Janeiro: PUC-Rio, 2002. Cap. de arquivos (um "grep" simplificado com `fgets` e `strstr`).
- DEITEL, P.; DEITEL, H. *C: como programar*. 6. ed. São Paulo: Pearson Prentice Hall, 2011. Cap. 8 (funções de busca de `string.h`).
- KERNIGHAN, B. W.; RITCHIE, D. M. *C: a linguagem de programação padrão ANSI*. Rio de Janeiro: Campus, 1989. Seções 4.1 (um programa que mostra as linhas com um padrão) e 5.10 (o mesmo programa com as opções `-x` e `-n`).
- CPPREFERENCE. *strstr* e *clock*. Disponível em: <https://en.cppreference.com/w/c/string/byte/strstr> e <https://en.cppreference.com/w/c/chrono/clock>.
- LINUX MAN-PAGES. *strstr(3)*, *clock(3)* e *grep(1)*. Disponível em: <https://man7.org/linux/man-pages/>.
