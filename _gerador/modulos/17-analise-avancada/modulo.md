# Módulo 17 · Medindo algoritmos recursivos

No módulo 10 você aprendeu a contar passos e a ler a classe de um código
pelos laços: um laço é O(n), dois aninhados são O(n²), um laço que divide por
2 é O(log n). Isso funciona até aparecer uma função que chama a si
mesma. Quanto custa o merge sort? O "n log n" que você leu no módulo 13 veio
de um desenho e de um pouco de fé. Aqui ele vira conta.

Este módulo traz as ferramentas que faltavam. A **recorrência** transforma o código recursivo numa equação, e a **árvore de
recursão** resolve a equação somando nível por nível. O **teorema mestre**
resolve de uma vez as recorrências de divisão e conquista mais comuns. A
**análise amortizada** explica por que o vetor que dobra é barato, mesmo
copiando tudo de vez em quando. E o **limite inferior** troca a pergunta
"quanto custa este algoritmo?" por "dá para fazer melhor?". Para ordenar
comparando, não dá: n log n é o piso.

O custo passa a ser algo que você calcula, prevê e confere. No último assunto, você usa tudo isso para prever quanto
tempo quatro ordenações levam com 1 milhão de elementos, a partir de uma
medida com 16 mil, e confere a previsão no computador.

## O que você vai aprender

- escrever a **recorrência** de uma função recursiva lendo o código, e resolvê-la com a **árvore de recursão**
- a diferença entre `T(n-1)` e `T(n/2)`, e por que "duas chamadas" pode ser Θ(n) ou Θ(2ⁿ)
- o **teorema mestre**: os três casos, como reconhecer cada um e quando ele **não** se aplica
- a **análise amortizada**: método agregado e método do banqueiro no vetor que dobra, no contador binário e na pilha com multipop
- a **árvore de decisão** e o limite **Ω(n log n)** para ordenar por comparação
- as notações **Θ** e **Ω**, ao lado do **O** que você já conhece
- **medir** com `clock()` e contadores, e **prever** o tempo para entradas grandes

## Antes de começar

Este módulo usa sem cerimônia: **recursão** e pilha de chamadas (0031 a
0033), **Big-O** e contagem de passos (0071 e 0072), o **vetor que cresce**
(0055 e 0075), **pilha** (0082) e **fila** (0085), as ordenações do módulo 13
(merge sort e quick sort, principalmente) e o **heap** (0102 e 0103). Também
aparecem ponteiros para função (0050), para guardar várias ordenações num
vetor.

Matemática: só potências e logaritmos. Lembre que `log₂ n` é "quantas vezes
dá para dividir n por 2 até chegar em 1" (`log₂ 1024 = 10`), e que
`log_b a` é o expoente que leva `b` a `a` (`log₂ 8 = 3`, `log₃ 9 = 2`). No C,
`log2` e `log` ficam em `<math.h>`, e o `rodar` já liga a biblioteca
matemática (`-lm`).

O último assunto tem um TAD na pasta, `ordena.h` e `ordena.c`, com as quatro
ordenações e um contador de comparações. O `rodar` compila o `ordena.c` junto
com qualquer exemplo ou exercício da pasta. Alguns programas medem **tempo**:
os números de tempo mudam de máquina para máquina e de uma execução para
outra; os de comparações, não. Os exercícios de "ache o erro" trazem o bug de
propósito, e o enunciado avisa.

Nos diagramas da ideia, **roxo** é trabalho sendo feito (uma chamada, um
nível), **verde** é o que domina o custo ou o resultado, **amarelo** marca um
empate e **vermelho** é o caro demais ou o que deu errado. Abra cada
recorrência à mão no **Passo a passo** e responda a **Pergunta para você**
antes de rodar: quase todo exemplo conta algo (chamadas, cópias,
comparações) e confere a contagem com a fórmula.

{{indice}}

---

{{assuntos}}

---

## Desafios do módulo

Problemas para fechar o módulo, misturando os assuntos. Resolva no papel e,
sempre que der, confira com um programa em C rodado com o `rodar`.

**1. O pior quick sort.** Com o pivô sempre no último elemento, um vetor já
ordenado faz o quick sort particionar em pedaços de tamanho `n - 1` e 0.
Escreva a recorrência das comparações, resolva e calcule para `n = 10.000`.
Compare com o melhor caso.

<details><summary>Resposta</summary>

`T(n) = T(n-1) + (n - 1)`, com `T(1) = 0`: a árvore vira uma linha, e a soma
é `(n - 1) + (n - 2) + ... + 1 = n(n - 1)/2`. Para 10.000: **49.995.000
comparações**. No melhor caso (pivô sempre no meio), `T(n) = 2 T(n/2) + n`,
uns `n log₂ n ≈ 133 mil`. Quase 400 vezes menos. Para conferir, conte as
comparações de um quick sort com pivô no fim num vetor `0, 1, ..., 9999`.

</details>

**2. Três terços.** Resolva `T(n) = 3 T(n/3) + n`, com `T(1) = 1`, pelo
teorema mestre e pela árvore. Quanto dá `T(81)`?

<details><summary>Resposta</summary>

`a = 3`, `b = 3`, `k = 1`: `b^k = 3 = a`, caso 2, **Θ(n log n)**. Na árvore,
cada nível custa `n` e são `log₃ n + 1` níveis: `T(n) = n (log₃ n + 1)`.
Com `n = 81 = 3⁴`, são 5 níveis de 81: **T(81) = 405**.

</details>

**3. Pedaços de tamanhos diferentes.** O teorema mestre não resolve
`T(n) = T(n/2) + T(n/4) + n`. Use a árvore de recursão para achar a classe.

<details><summary>Resposta</summary>

O nível 0 custa `n`. O nível 1 tem pedaços de `n/2` e `n/4`: custa `3n/4`. O
nível 2 custa `9n/16`, e assim por diante: cada nível custa `3/4` do
anterior. A soma de uma progressão geométrica de razão `3/4` fica abaixo de
`4n`, e o primeiro nível já é `n`. Logo **Θ(n)**: a raiz domina, como num
caso 3.

</details>

**4. Quick sort azarado, mas nem tanto.** Um quick sort sempre divide o
pedaço na proporção 1 para 9 (10% de um lado, 90% do outro). Ele continua
O(n log n)? Quantos níveis tem a árvore para `n = 1 milhão`?

<details><summary>Resposta</summary>

Sim. Cada nível da árvore custa no máximo `n` (os pedaços de um nível não se
sobrepõem). O caminho mais fundo é o que segue sempre os 90%: o tamanho cai
por `10/9` a cada nível, então são `log_{10/9} n` níveis, uns `6,6 log₂ n`.
Para 1 milhão, **cerca de 131 níveis**, contra 20 da divisão ao meio. A
constante piora, mas continua **Θ(n log n)**. Qualquer proporção fixa serve;
o desastre é dividir em `n - 1` e 0.

</details>

**5. A tabela hash que dobra.** Uma tabela hash do módulo 15 começa com
espaço para 1 elemento e dobra de tamanho quando enche, reinserindo todos os
elementos na tabela nova. Quantas reinserções acontecem até ela guardar 1024
elementos? Qual o custo amortizado por inserção?

<details><summary>Resposta</summary>

As mudanças acontecem com 1, 2, 4, ..., 512 elementos: `1 + 2 + 4 + ... +
512` dá **1023 reinserções**, menos que `2 · 1024`. Somando as 1024 inserções
normais, menos de 3 operações por elemento: **O(1) amortizado**. É a mesma
conta do vetor que dobra do assunto 0116.

</details>

**6. O contador inteiro.** Um contador binário de 10 bits vai de 0 até 1023,
um incremento por vez. Quantas trocas de bit acontecem no total?

<details><summary>Resposta</summary>

O bit 0 troca 1023 vezes, o bit 1, 511, o bit 2, 255... o bit 9, 1 vez. A
soma é `(1024 - 1) + (512 - 1) + ... + (2 - 1) = 2046 - 10`:
**2036 trocas**. Em geral, `n` incrementos a partir do zero fazem `2n` menos
a quantidade de bits 1 de `n`: aqui, `2 · 1023 - 10`. Menos de 2 por incremento, como no A231.

</details>

**7. Intercalar é ótimo?** Juntar duas listas ordenadas de 4 elementos cada
custa até 7 comparações na intercalação do merge sort. Algum método faz
menos no pior caso?

<details><summary>Resposta</summary>

Não. Conte as folhas da árvore de decisão: o resultado é decidido por
**quais 4 das 8 posições** ficam com elementos da primeira lista, e isso dá
`C(8, 4) = 70` respostas possíveis. Com `h` comparações cabem `2^h` folhas:
`2^6 = 64 < 70 ≤ 128 = 2^7`. Precisa de **7 comparações** no pior caso, e a
intercalação comum faz exatamente `2 · 4 - 1 = 7`: ela é ótima.

</details>

**8. O vice-campeão.** Ache o **segundo maior** de 16 valores. O jeito
óbvio (achar o maior, tirá-lo e achar o maior de novo) usa `15 + 14 = 29`
comparações. Faça com 18.

<details><summary>Resposta</summary>

Um **torneio**: os 16 jogam em pares, os vencedores jogam em pares, até
sobrar o campeão. São 15 comparações (todo mundo, menos o campeão, perde uma
vez). O segundo maior só pode ter perdido **para o campeão**, e o campeão
jogou `log₂ 16 = 4` vezes. O máximo entre esses 4 adversários sai com 3
comparações: `15 + 3`, **18 comparações**. Em geral, `n + ⌈log₂ n⌉ - 2`.
Guarde, para cada vencedor, a lista de quem ele derrotou.

</details>

**9. Prever a multiplicação de números enormes.** Um programa de
criptografia multiplica números de 10 mil dígitos em 2 segundos com o
método de Karatsuba, Θ(n^(log₂ 3)). Quanto tempo ele deve levar com 40 mil
dígitos? E se usasse o método da escola, Θ(n²), com os mesmos 2 segundos em
10 mil dígitos?

<details><summary>Resposta</summary>

O tamanho foi multiplicado por 4. Karatsuba: `4^(log₂ 3) = (2²)^(log₂ 3) =
3² = 9`, então **uns 18 segundos**. Método da escola: `4² = 16`, **uns 32
segundos**. A diferença cresce com `n`: com 160 mil dígitos seriam 162
segundos contra 512.

</details>

**10. Descobrir o expoente.** Você não tem o código de uma função, só pode
rodá-la. Com `n = 50 mil` ela leva 1,2 s; com `n = 100 mil`, 3,4 s. Qual é o
expoente provável do custo? Quanto deve levar com 400 mil?

<details><summary>Resposta</summary>

A razão é `3,4 / 1,2 ≈ 2,83`. Se o custo é `n^p`, dobrar `n` multiplica por
`2^p`: `p = log₂ 2,83`, logo **p ≈ 1,5**. De 100 mil para 400 mil, o tamanho
multiplica por 4 e o tempo por `4^1,5 = 8`: **uns 27 segundos**. Antes de
confiar, meça mais um ponto (200 mil deve dar uns 9,6 s): duas medidas
apenas não distinguem `n^1,5` de, digamos, `n log² n`.

</details>

## Questões no estilo da prova

Questões objetivas no formato da prova do PPGI. Resolva no papel, marque a
letra e só depois abra o gabarito. O teorema mestre usado aqui é o da forma
do Cormen (veja o [!NOTE] do assunto 0115).

**1.** Qual é a solução de `T(n) = 4 T(n/2) + n²`?

- (A) Θ(n²)
- (B) Θ(n³)
- (C) Θ(n² log n)
- (D) Θ(n log n)
- (E) Θ(n⁴)

<details><summary>Gabarito</summary>

**C.** `a = 4`, `b = 2`: `n^(log₂ 4) = n²`, igual a `f(n) = n²`. Caso 2 (o custo
por nível não muda): Θ(n² log n). São `log₂ n + 1` níveis de custo `n²` cada.
Veja 0115.

</details>

**2.** Qual é a solução de `T(n) = 2 T(n/4) + √n`?

- (A) Θ(√n log n)
- (B) Θ(√n)
- (C) Θ(n)
- (D) Θ(log n)
- (E) Θ(n log n)

<details><summary>Gabarito</summary>

**A.** `n^(log₄ 2) = n^(1/2) = √n`, do mesmo tamanho de `f(n)`: caso 2,
Θ(√n log n). Quem compara `f(n)` com `n` em vez de com `n^(log_b a)` marca
(C) e erra. Veja 0115.

</details>

**3.** Qual é a solução de `T(n) = 5 T(n/2) + n³`?

- (A) Θ(n^(log₂ 5))
- (B) Θ(n³ log n)
- (C) Θ(n^2,32 log n)
- (D) Θ(n⁵)
- (E) Θ(n³)

<details><summary>Gabarito</summary>

**E.** `log₂ 5 ≈ 2,32 < 3`: `f(n) = n³` é polinomialmente maior que
`n^(log₂ 5)`. Caso 3, desde que valha a condição de regularidade:
`5 (n/2)³ = (5/8) n³ ≤ c · n³` com `c = 5/8 < 1`. Vale, e a raiz domina:
Θ(n³). Veja 0115.

</details>

**4.** Qual é o custo de tempo de cada função, em função de `n`?

```c
int f(int n) {
    if (n <= 1) return 1;
    return f(n - 1) + f(n - 1);
}

int g(int n) {
    if (n <= 1) return 1;
    return 2 * g(n - 1);
}
```

- (A) `f` e `g` são Θ(2ⁿ).
- (B) `f` é Θ(2ⁿ) e `g` é Θ(n).
- (C) `f` é Θ(n) e `g` é Θ(2ⁿ).
- (D) `f` e `g` são Θ(n).
- (E) `f` é Θ(n²) e `g` é Θ(n).

<details><summary>Gabarito</summary>

**B.** As duas devolvem 2ⁿ⁻¹, mas `f` faz **duas** chamadas com `n - 1`:
`T(n) = 2 T(n-1) + 1`, Θ(2ⁿ) (com `n = 20`, 1.048.575 chamadas). `g` faz uma
só e multiplica o resultado: `T(n) = T(n-1) + 1`, Θ(n) (20 chamadas). O que
conta é quantas vezes a função chama a si mesma, não o valor devolvido. Veja
0114.

</details>

**5.** Quanto vale `conta` depois de `h(16)`?

```c
int conta = 0;

void h(int n) {
    if (n == 0) return;
    conta++;
    h(n / 2);
    h(n / 2);
}
```

- (A) 16
- (B) 32
- (C) 80
- (D) 31
- (E) 63

<details><summary>Gabarito</summary>

**D.** `C(0) = 0` e `C(n) = 1 + 2 C(n/2)`: C(1) = 1, C(2) = 3, C(4) = 7,
C(8) = 15, **C(16) = 31**. A árvore de recursão tem 1 + 2 + 4 + 8 + 16 nós que
contam: `2n - 1`, Θ(n). Duas chamadas com metade não é n log n quando o
trabalho fora das chamadas é constante. Veja 0114.

</details>

**6.** Pela versão do teorema mestre da 4ª edição do Cormen, qual é a
solução de `T(n) = 2 T(n/2) + n log n`?

- (A) Θ(n log n)
- (B) Θ(n log² n)
- (C) Θ(n²)
- (D) o teorema não se aplica
- (E) Θ(n^1,5)

<details><summary>Gabarito</summary>

**B.** `n^(log₂ 2) = n` e `f(n) = n log n = Θ(n · log¹ n)`. O caso 2 do
Cormen, na forma `f(n) = Θ(n^(log_b a) · logᵏ n)` com `k ≥ 0`, dá
Θ(n^(log_b a) · log^(k+1) n) = Θ(n log² n). Na forma simples, com `f(n) = nᵏ`,
o teorema não pega essa recorrência, e muito material antigo responde (D).
Veja 0115.

</details>

**7.** Em qual destas recorrências o teorema mestre se aplica diretamente?

- (A) `T(n) = T(n - 1) + n`
- (B) `T(n) = T(n/3) + T(2n/3) + n`
- (C) `T(n) = 2 T(n/2) + n / log n`
- (D) `T(n) = 2ⁿ T(n/2) + n`
- (E) `T(n) = 9 T(n/3) + n`

<details><summary>Gabarito</summary>

**E.** `a = 9`, `b = 3`: `n^(log₃ 9) = n²`, polinomialmente maior que `n`.
Caso 1: Θ(n²). Nas outras: (A) o tamanho cai subtraindo; (B) os pedaços têm
tamanhos diferentes; (C) `n / log n` fica abaixo de `n` só por um fator de
log, e o caso 2 exige `k ≥ 0`; (D) `a` não é constante. Veja 0115.

</details>

**8.** Um vetor dinâmico começa com capacidade 1 e dobra quando enche (alocar
o novo e copiar todos os elementos). Cada escrita e cada cópia custam 1. Qual
é o custo total de 33 inserções seguidas, e o custo amortizado por inserção?

- (A) 96; O(1)
- (B) 63; O(log n)
- (C) 528; O(n)
- (D) 33; O(1)
- (E) 96; O(log n)

<details><summary>Gabarito</summary>

**A.** As cópias acontecem nas inserções 2, 3, 5, 9, 17 e 33: 1 + 2 + 4 + 8 +
16 + 32 = 63. Somadas às 33 escritas, 96, menos que 3 × 33. Pelo método
agregado, o custo amortizado é O(1), mesmo com a 33ª inserção custando 33
sozinha. Veja 0116.

</details>

**9.** Qual é o menor número de comparações que **qualquer** algoritmo de
ordenação por comparação precisa fazer, no pior caso, para ordenar 5
elementos distintos?

- (A) 5
- (B) 6
- (C) 7
- (D) 10
- (E) 12

<details><summary>Gabarito</summary>

**C.** A árvore de decisão precisa de uma folha para cada uma das 5! = 120
ordens, e uma árvore binária de altura `h` tem no máximo 2ʰ folhas. 2⁶ = 64 <
120 ≤ 128 = 2⁷: `h ≥ ⌈log₂ 120⌉ = 7`. Veja 0117.

</details>

**10.** Qual é a complexidade do trecho abaixo?

```c
long passos = 0;
for (int i = 1; i < n; i *= 2) {
    for (int j = 0; j < i; j++) {
        passos++;
    }
}
```

- (A) Θ(log n)
- (B) Θ(n log n)
- (C) Θ(n²)
- (D) Θ(n)
- (E) Θ(log² n)

<details><summary>Gabarito</summary>

**D.** O laço de fora roda log₂ n vezes, mas o de dentro não roda `n` vezes em
cada uma: roda 1, 2, 4, ..., até menos que `n`. A soma geométrica fica abaixo
de `2n` (com `n = 1024`, são 1023 passos). Multiplicar "log n voltas por n"
dá (B), um limite superior folgado, mas não o Θ. Veja 0114 e, para somatórios,
0167.

</details>

## Para ler mais

- CORMEN, T. H. et al. *Algoritmos: teoria e prática*. 4. ed. Rio de Janeiro: GEN LTC, 2024. Cap. 3 (notações O, Ω e Θ), cap. 4 (recorrências: substituição, árvore de recursão e teorema mestre), cap. 8 (limite inferior da ordenação) e cap. 16 (análise amortizada: métodos agregado, contábil e do potencial).
- ZIVIANI, N. *Projeto de algoritmos com implementações em Pascal e C*. 3. ed. São Paulo: Cengage Learning, 2010. Cap. 1 (análise de algoritmos e notação assintótica) e cap. 2 (recursividade e divisão e conquista).
- LINTZMAYER, C. N.; MOTA, G. O. *Análise de algoritmos e de estruturas de dados*. Santo André: UFABC; São Paulo: IME-USP, 2023. Notas de aula. Partes sobre recorrências, teorema mestre e limite inferior para ordenação.
- SZWARCFITER, J. L.; MARKENZON, L. *Estruturas de dados e seus algoritmos*. 3. ed. Rio de Janeiro: LTC, 2010. Caps. 1 (complexidade e limites inferiores), 7 (ordenação e árvore de decisão) e a análise amortizada.
- FEOFILOFF, P. *Análise de algoritmos* (livrinho). São Paulo: IME-USP. Disponível em: <https://www.ime.usp.br/~pf/livrinho-AA/>.
- FEOFILOFF, P. *Algoritmos em linguagem C*. Rio de Janeiro: Elsevier, 2009. Caps. de recursão, mergesort e quicksort.
- TENENBAUM, A. M.; LANGSAM, Y.; AUGENSTEIN, M. J. *Estruturas de dados usando C*. São Paulo: Makron Books, 1995. Cap. 6 (classificação, eficiência e o limite de log₂ n! comparações).
- CORTÉS, M. I. *Estrutura de dados*. 3. ed. Fortaleza: EdUECE, 2015. Cap. 1 (complexidade) e a seção de listas autoajustáveis, onde aparece a ideia de custo amortizado.
- ROVAI, K. R. *Algoritmos e estrutura de dados*. Londrina: Editora e Distribuidora Educacional, 2018. Unidade de tabelas de espalhamento (a tabela que dobra).
- MORIN, P. *Open data structures*. Edição em C++/Java/pseudocódigo. Disponível em: <https://opendatastructures.org/>. Caps. 1 e 2 (análise amortizada do vetor que cresce).
- KERNIGHAN, B. W.; RITCHIE, D. M. *C: a linguagem de programação padrão ANSI*. Rio de Janeiro: Campus, 1989. Seção 4.10 (recursão).
- CPPREFERENCE. *clock* e *CLOCKS_PER_SEC*. Disponível em: <https://en.cppreference.com/w/c/chrono/clock>.
- LINUX MAN-PAGES. *clock(3)* e *log2(3)*. Disponível em: <https://man7.org/linux/man-pages/man3/clock.3.html>.
