# Módulo 19 · Enumeração e backtracking

Problema sem fórmula pede **testar as possibilidades** sem esquecer nem
repetir. O módulo enumera subconjuntos e permutações com recursão e chega ao
**backtracking**, que volta atrás e **poda** o que não serve: soma de
subconjuntos, N-rainhas, labirinto, flood fill e sudoku. Depende da recursão
(módulos 04 e 13) e da DFS (módulo 16).

## O que você vai aprender

- **subconjuntos**, pela recursão e pelos **bits** de um número
- **permutações** com troca, recursão e desfazer
- o esqueleto do **backtracking**: parada, **poda** e escolha com desfazer
- a **soma de subconjuntos** e o efeito da poda
- as **N-rainhas**, com o ataque testado em O(1)
- **labirinto** em matriz e **flood fill**
- um **resolvedor de sudoku**

## Antes de começar

Revise a recursão (0031 a 0033), as matrizes (0039), os operadores de bits
(0065) e o vetor de `bool` de `<stdbool.h>`.

Em cada função recursiva, ache onde ela **para**, onde **poda** e onde
**escolhe e desfaz**. Os programas contam as **chamadas**: com a poda, a saída
é a mesma e o número cai.

Nas árvores de decisão, amarelo é decisão aberta, verde solução, vermelho
galho podado e cinza beco sem saída; nos tabuleiros, verde é a solução e
vermelho, casa proibida.

{{indice}}

---

{{assuntos}}

---

## Desafios do módulo

Problemas para resolver no papel e, quando fizer sentido, num arquivo `.c` seu.
Eles misturam os assuntos do módulo.

**1. Amigo secreto.** Quatro amigos sorteiam o amigo secreto e ninguém pode
tirar o próprio nome. Quantos sorteios válidos existem? E com cinco amigos?

<details><summary>Resposta</summary>

São **9** com quatro e **44** com cinco. Cada sorteio é uma permutação em que
`pos[i] != i` para todo `i` (um **desarranjo**). Caminho: a permutação com
vetor de usados do exemplo A251, com uma poda a mais: na posição `i`, pule o
candidato `i`. A conta direta é 4! · (1 - 1 + 1/2 - 1/6 + 1/24) = 9.

</details>

**2. O quadrado mágico.** Quantos jeitos há de escolher três números
diferentes de 1 a 9 que somam 15 (sem importar a ordem)?

<details><summary>Resposta</summary>

São **8**: {1, 5, 9}, {1, 6, 8}, {2, 4, 9}, {2, 5, 8}, {2, 6, 7}, {3, 4, 8},
{3, 5, 7} e {4, 5, 6}. São exatamente as 3 linhas, as 3 colunas e as 2
diagonais do quadrado mágico 3 × 3. Caminho: combinações de 3 com o
`inicio` do exemplo A250 e a poda "passou de 15, volte".

</details>

**3. Somando 15.** Quantos subconjuntos de {1, 2, ..., 10} somam exatamente
15? Que poda funciona quando os números estão em ordem crescente?

<details><summary>Resposta</summary>

São **20** subconjuntos. Com os números em ordem crescente, dá para podar mais
cedo que no texto: se `soma + v[i]` já passa de 15, nenhum item a partir de
`i` cabe (todos são maiores), e a função pode voltar sem tentar nem o caminho
"sem o item".

</details>

**4. Dois times de mesma soma.** As camisas de 1 a 8 precisam ser divididas
em dois times cuja soma dos números seja igual. De quantas formas?

<details><summary>Resposta</summary>

A soma total é 36, então cada time soma **18**. Há 14 subconjuntos de
{1..8} com soma 18, mas cada divisão aparece duas vezes (o time e o
complemento): **7** divisões. Caminho: o E748, fixando a camisa 1 num dos
times para não contar em dobro.

</details>

**5. BANANA.** Quantos anagramas diferentes tem a palavra BANANA? Quantas
linhas a recursão por trocas do texto mostraria?

<details><summary>Resposta</summary>

São 6! / (3! · 2!) = 720 / 12 = **60** anagramas diferentes. A recursão por
trocas não sabe que as letras iguais são iguais: mostraria as **720** ordens,
cada anagrama repetido 12 vezes. O jeito do exemplo A252, com a contagem de
cada letra, gera só os 60.

</details>

**6. Troco de R$ 1,00.** De quantas formas dá para formar R$ 1,00 com moedas
de 5, 10, 25 e 50 centavos, podendo repetir moedas? Como evitar contar
"50 + 25 + 25" e "25 + 50 + 25" como formas diferentes?

<details><summary>Resposta</summary>

São **40** formas. Para não repetir, escolha as moedas em ordem não
crescente: a função recebe o índice da maior moeda ainda permitida e só
desce para moedas iguais ou menores. É a mesma ideia do `inicio` das
combinações (A250), e o problema volta no módulo de programação dinâmica.

</details>

**7. Caminhos na praça.** Numa grade vazia 3 × 3, quantos caminhos sem
repetir casa vão de um canto ao canto oposto (andando na horizontal e na
vertical)? E numa 4 × 4?

<details><summary>Resposta</summary>

São **12** na 3 × 3 e **184** na 4 × 4 (numa 5 × 5, 8512). É o exemplo A258
sem paredes. O número explode porque, ao desmarcar a casa na volta, a busca
deixa de ser O(L · C): cada caminho diferente é visitado inteiro.

</details>

**8. Rainhas impossíveis.** Mostre, no papel, por que não existe solução das
N-rainhas para N = 2 e N = 3. E das 92 soluções do 8-rainhas, quantas têm uma
rainha em algum canto do tabuleiro?

<details><summary>Resposta</summary>

N = 2: as duas casas da linha 1 estão na coluna ou na diagonal da rainha da
linha 0. N = 3: rainha da linha 0 no canto deixa uma casa só na linha 1, e as
duas juntas atacam a linha 2 inteira; no meio, ela ataca a linha 1 inteira. No
8-rainhas, **16** soluções têm rainha num canto. Caminho: conte as soluções
em que `pos[0]` ou `pos[7]` vale 0 ou 7.

</details>

**9. O décimo estado.** No código de Gray de 4 bits (o pisca-pisca do E750
com quatro lâmpadas), qual é o 10º estado, contando o 0000 como o 1º?

<details><summary>Resposta</summary>

O 10º estado é o de `m = 9`: `9 ^ (9 >> 1)` = `1001 ^ 0100` = **1101**. O
anterior (m = 8) é 1100, então a passagem acende a lâmpada 0.

</details>

**10. Sudoku sem chute.** No jogo do texto (assunto 0130), quantas casas vazias
têm um candidato só logo no começo? Por que preencher essas casas antes da
busca ajuda?

<details><summary>Resposta</summary>

São **2**: a (4, 0), que só aceita o 3, e a (5, 5), que só aceita o 7.
Preencher uma casa de candidato único não cria ramo nenhum na árvore, e ainda
corta candidatos das vizinhas, que às vezes ficam com um candidato só também.
A heurística do exemplo A260 faz isso naturalmente: a casa de 1 candidato é
sempre a mais apertada.

</details>

**11. Quanto tempo?** Um computador faz uns 100 milhões de chamadas
recursivas simples por segundo. Quanto tempo leva enumerar todos os
subconjuntos de 30 itens, sem poda nenhuma? E de 40?

<details><summary>Resposta</summary>

A árvore tem 2ⁿ⁺¹ - 1 nós. Com 30 itens, uns **2,1 bilhões** de chamadas:
cerca de 21 segundos. Com 40, uns **2,2 trilhões**: mais de 6 horas. Cada
item a mais dobra o tempo. Por isso a poda importa, e problemas como a
mochila ganham, no módulo 21, um método que não testa tudo.

</details>

## Questões do POSCOMP

Questões reais do POSCOMP (SBC) sobre este módulo. O enunciado está no caderno oficial: abra o link, resolva e confira o gabarito.

| Ano | Questão | Assunto | Gabarito | Prova |
| --- | --- | --- | --- | --- |
| 2025 | 47 | Tentativa e erro, exploração sistemática de soluções | a conferir no gabarito oficial | [caderno](https://www2.uesb.br/curso/cienciadacomputacao/wp-content/uploads/2026/05/caderno_2025.pdf) |

O gabarito oficial de 2025 não estava disponível quando este material foi montado.


## Questões no estilo da prova

Questões objetivas no formato da prova do PPGI. Resolva no papel, marque a
letra e só depois abra o gabarito. Todo código daqui compila: rode para
conferir.

**1.** Quantas vezes a função `gera` é chamada, contando a primeira, quando
`n = 5` e o programa faz `gera(0)`?

```c
void gera(int i) {
    if (i == n) {
        mostra();
        return;
    }
    gera(i + 1);   // o item i fica de fora
    gera(i + 1);   // o item i entra
}
```

- (A) 32
- (B) 31
- (C) 63
- (D) 64
- (E) 120

<details><summary>Gabarito</summary>

**C.** A árvore de decisões é binária completa com 6 níveis (i = 0 a 5): 1 +
2 + 4 + 8 + 16 + 32 = 2⁶ - 1 = 63 chamadas, das quais 32 são folhas (os 2⁵
subconjuntos). Veja 0125.

</details>

**2.** A função abaixo gera as permutações de `v[0..n-1]` por trocas. Com
`n = 4`, quantas permutações ela mostra e quantas vezes `permuta` é chamada,
contando a primeira?

```c
void permuta(int v[], int i) {
    if (i == n) {
        mostra(v);
        return;
    }
    for (int j = i; j < n; j++) {
        troca(&v[i], &v[j]);
        permuta(v, i + 1);
        troca(&v[i], &v[j]);
    }
}
```

- (A) 24 permutações e 65 chamadas
- (B) 24 permutações e 24 chamadas
- (C) 16 permutações e 31 chamadas
- (D) 24 permutações e 41 chamadas
- (E) 256 permutações e 341 chamadas

<details><summary>Gabarito</summary>

**A.** O nível `i` tem 4!/(4 - i)! chamadas: 1, 4, 12, 24 e 24 (o último nível
é o das folhas, com `i == n`). Soma: 65. As folhas são as 4! = 24
permutações. Veja 0126.

</details>

**3.** O que o programa mostra?

```c
#include <stdio.h>

void f(int n) {
    if (n == 0) return;
    f(n - 1);
    printf("%d", n);
    f(n - 1);
}

int main(void) {
    f(3);
    printf("\n");
    return 0;
}
```

- (A) 123
- (B) 321
- (C) 3213121
- (D) 1231231
- (E) 1213121

<details><summary>Gabarito</summary>

**E.** `f(1)` mostra `1`; `f(2)` mostra f(1), `2`, f(1): `121`; `f(3)` mostra
`121`, `3`, `121`. São 2³ - 1 = 7 dígitos, o mesmo padrão dos movimentos da
Torre de Hanói. Veja 0033 e 0125.

</details>

**4.** Sobre o problema das N-rainhas resolvido por backtracking (uma rainha
por linha, poda por coluna e diagonais), analise as afirmações.

- I. Para N = 4 existem exatamente 2 soluções.
- II. O número de soluções sempre cresce quando N cresce.
- III. Para N = 3 não há solução: o programa percorre a árvore, volta de todos
  os ramos e termina sem mostrar nada.

Marque a alternativa **CORRETA**.

- (A) I e III, apenas.
- (B) I e II, apenas.
- (C) II e III, apenas.
- (D) I, II e III.
- (E) II, apenas.

<details><summary>Gabarito</summary>

**A.** I é verdadeira (N = 4 dá 2). II é falsa por causa do "sempre": N = 5
dá 10 soluções e N = 6 dá só 4. III é verdadeira: N = 2 e N = 3 não têm
solução. Mesmo com a poda, a árvore continua exponencial no pior caso. Veja
0128.

</details>

**5.** O backtracking abaixo procura subconjuntos dos preços `{7, 5, 4, 3}`
que somem exatamente 12. Quantas vezes `soma` é chamada, contando
`soma(0, 0)`?

```c
int preco[] = {7, 5, 4, 3};

void soma(int i, int s) {
    if (s > 12) return;               // poda: passou do alvo
    if (s == 12) { mostra(); return; }
    if (i == 4) return;               // acabaram os itens
    soma(i + 1, s + preco[i]);        // leva o item i
    soma(i + 1, s);                   // não leva
}
```

- (A) 16
- (B) 31
- (C) 2
- (D) 25
- (E) 15

<details><summary>Gabarito</summary>

**D.** Sem poda, seriam 31 chamadas (a árvore completa de 4 itens). A poda
corta, por exemplo, o ramo 7 + 5 + ... (a soma bate 12 e volta) e o 7 + 4 + 3
(passa de 12). As soluções são {7, 5} e {5, 4, 3}; contando as chamadas com
um contador global, saem 25. Veja 0127.

</details>

**6.** Um programa gera e **mostra** todos os subconjuntos de `n` itens (cada
subconjunto impresso item a item) e, em outra versão, todas as permutações.
Quais são os custos?

- (A) Θ(2ⁿ) e Θ(n!)
- (B) Θ(n · 2ⁿ) e Θ(n · n!)
- (C) Θ(n²) e Θ(n³)
- (D) Θ(2ⁿ) e Θ(2ⁿ)
- (E) Θ(n log n) e Θ(n!)

<details><summary>Gabarito</summary>

**B.** São 2ⁿ subconjuntos e n! permutações, e mostrar cada um custa até `n`
passos. A recursão em si (os nós internos) não muda a classe. Veja 0125 e
0126.

</details>

**7.** No N-rainhas com `N = 8`, a casa da linha 2 e coluna 5 ocupa quais
índices nos vetores `diag1` (↗, índice `l + c`) e `diag2` (↘, índice
`l - c + N - 1`)?

- (A) `diag1[3]` e `diag2[7]`
- (B) `diag1[7]` e `diag2[-3]`
- (C) `diag1[10]` e `diag2[4]`
- (D) `diag1[7]` e `diag2[10]`
- (E) `diag1[7]` e `diag2[4]`

<details><summary>Gabarito</summary>

**E.** `l + c = 2 + 5 = 7` e `l - c + N - 1 = 2 - 5 + 7 = 4`. O `-3` da (B) é
o `l - c` sem o deslocamento, que escreveria fora do vetor. Veja 0128.

</details>

**8.** Num labirinto em grade, sem pesos, analise as afirmações.

- I. O backtracking em profundidade (a DFS do labirinto) acha um caminho até a
  saída, mas não garante que seja o mais curto.
- II. A BFS, que explora por distância, acha com certeza o caminho com menor
  número de passos.
- III. Se as casas já visitadas não forem marcadas, a busca termina sempre,
  porque a grade é finita.

Marque a alternativa **CORRETA**.

- (A) I, apenas.
- (B) I e II, apenas.
- (C) II e III, apenas.
- (D) I e III, apenas.
- (E) I, II e III.

<details><summary>Gabarito</summary>

**B.** I e II estão certas: a DFS para no primeiro caminho que dá certo, e a
ordem das direções decide qual é ele; a BFS anda por camadas e a primeira vez
que chega à saída é pelo menor número de passos. III é falsa: sem a marca,
duas casas vizinhas se chamam uma à outra sem fim (ou a busca anda em
círculos) e a pilha estoura. Veja 0129 e 0110.

</details>

**9.** Quantas chamadas a função faz para calcular `fib(6)`, contando a
primeira?

```c
int fib(int n) {
    if (n < 2) return n;
    return fib(n - 1) + fib(n - 2);
}
```

- (A) 6
- (B) 13
- (C) 15
- (D) 25
- (E) 64

<details><summary>Gabarito</summary>

**D.** Chamando de `C(n)` as chamadas: C(0) = C(1) = 1 e C(n) = 1 + C(n - 1)
+ C(n - 2). Daí C(2) = 3, C(3) = 5, C(4) = 9, C(5) = 15, **C(6) = 25**. Em
geral, C(n) = 2 · fib(n + 1) - 1, que cresce como φⁿ (φ ≈ 1,618): a mesma
sub-resposta é recalculada muitas vezes. A programação dinâmica do módulo 21
resolve isso. Veja 0032.

</details>

## Para ler mais

- FEOFILOFF, P. *Algoritmos em linguagem C*. Rio de Janeiro: Elsevier, 2009. Capítulo sobre enumeração (subsequências, combinações e permutações) e os exercícios de backtracking.
- FEOFILOFF, P. *Projeto de algoritmos em C*: enumeração e backtracking. São Paulo: IME-USP. Disponível em: <https://www.ime.usp.br/~pf/algoritmos/>.
- TENENBAUM, A. M.; LANGSAM, Y.; AUGENSTEIN, M. J. *Estruturas de dados usando C*. São Paulo: Makron Books, 1995. Cap. 3: recursividade (oito rainhas e labirinto com backtracking).
- WIRTH, N. *Algoritmos e estruturas de dados*. Rio de Janeiro: LTC, 1989. Capítulo sobre algoritmos de tentativa e erro (as oito rainhas e o passeio do cavalo).
- ZIVIANI, N. *Projeto de algoritmos com implementações em Pascal e C*. 3. ed. São Paulo: Cengage Learning, 2010. Cap. 2: paradigmas de projeto (recursividade e tentativa e erro).
- DEITEL, P.; DEITEL, H. *C: como programar*. 6. ed. São Paulo: Pearson, 2011. Exercícios do passeio do cavalo, das oito rainhas e do labirinto; apêndice sobre sudoku.
- CASTILHO, M. A.; SILVA, F.; WEINGAERTNER, D. *Algoritmos e estruturas de dados 1*. Curitiba: UFPR, 2020. Capítulos sobre matrizes e o flood fill.
- ROVAI, K. R. *Algoritmos e estrutura de dados*. Londrina: Editora e Distribuidora Educacional, 2018. Pilhas: o labirinto e a memória de decisões.
- KNUTH, D. E. *The art of computer programming*. v. 4A: combinatorial algorithms, part 1. Boston: Addison-Wesley, 2011. Geração de tuplas (código de Gray), permutações e combinações.
- CORMEN, T. H. et al. *Algoritmos: teoria e prática*. 4. ed. Rio de Janeiro: GEN LTC, 2024. Cap. 20: busca em profundidade e busca em largura (a base do labirinto e do flood fill).
- KERNIGHAN, B. W.; RITCHIE, D. M. *C: a linguagem de programação padrão ANSI*. Rio de Janeiro: Campus, 1989. Seção 4.10: recursividade.
