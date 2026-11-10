# Módulo 26 · Notação assintótica, somatórios e espaço

Nos módulos 10 e 17 você contou passos, disse "isso é O(n²)" e resolveu
recorrências. Este módulo fecha três pontas: as **definições formais** de O,
Ω e Θ, com `c` e `n₀`; os **somatórios** que dão o número exato de vezes que
um laço roda; e a **complexidade espacial**, que mede memória como se mede
tempo.

A mudança é trocar o "parece n²" pela conta: dizer que `3n² + 10n + 20` é
Θ(n²) vira uma afirmação que se **prova** ou se **refuta**. O laço que roda
"umas n²/2 vezes" passa a rodar `n(n-1)/2`, conferido por um contador. E a
função que "não usa memória" obriga a olhar a pilha da recursão. O último
assunto junta as três ideias na ficha de cinco funções.

## O que você vai aprender

- as definições de **O**, **Ω** e **Θ** com `c` e `n₀`; **provar** e
  **refutar** um limite
- **melhor**, **pior** e **médio** caso, que não são O, Ω e Θ
- achar `c` e `n₀` com um programa e por que ele não substitui a prova
- transformar laços em **somatórios**: aritmético, quadrático, geométrico,
  harmônico e laços dependentes
- a **complexidade espacial**: espaço extra, **in-place** e pilha da recursão
- a troca de **tempo por espaço**: tabelas, prefixos e memoização
- conferir uma ficha de complexidade medindo passos, bytes e frames

## Antes de começar

Usa contagem de passos e notação O (0071, 0072), pilha de chamadas e recursão
(0031 a 0033), pilha, heap, `malloc` e `free` (0053, 0054), ponteiro para
função (0050), busca binária (0090), insertion e merge sort (0093, 0094),
recorrências e Θ (0114 a 0117), backtracking (0126), potência rápida (0131) e
memoização (0138).

Faça as contas no papel **antes** de rodar; depois dobre o `n` e veja se o
contador acompanha a fórmula. Nos diagramas, verde é o que vale (teto que
segura, espaço constante), vermelho é o que falha ou cresce com `n`, amarelo
marca a virada (o `n₀`, a razão ao dobrar `n`) e roxo é trabalho contado.

Lembre que `log₂ n` é quantas vezes dá para dividir `n` por 2 até chegar em 1,
e que `ln n` é o logaritmo natural (`log` em `<math.h>`).

O último assunto tem um TAD, `custo.h` e `custo.c`, compilado junto com os
exemplos e exercícios da pasta: não dê os nomes `custo_passos`, `custo_bytes`
e `custo_prof_max` a variáveis suas.

{{indice}}

---

{{assuntos}}

---

## Desafios do módulo

Problemas que misturam os assuntos do módulo. Resolva no papel e, sempre que
der, confira com um programa compilado e rodado.

**1. Um sanduíche cúbico.** Prove que `f(n) = 5n³ + 2n² - 7` é Θ(n³):
encontre `c₁`, `c₂` e `n₀`.

<details><summary>Resposta</summary>

Piso: `5n³ + 2n² - 7 ≥ 5n³` quando `2n² ≥ 7`, isto é, `n ≥ 2`. Teto:
`5n³ + 2n² - 7 ≤ 5n³ + 2n³ = 7n³` para todo `n ≥ 1`. Logo **`c₁ = 5`, `c₂ = 7`
e `n₀ = 2`**. Confira: `f(2) = 41`, entre `40` e `56`. Com `n = 1`, `f(1) = 0`
fica abaixo de `5`: por isso o `n₀` não pode ser 1.

</details>

**2. A exponencial vence o polinômio.** `2ⁿ` é O(n¹⁰)? A partir de que `n` a
exponencial passa de `n¹⁰` de vez?

<details><summary>Resposta</summary>

Não é. A razão `2ⁿ / n¹⁰` cresce sem limite: cada passo de `n` multiplica o
numerador por 2 e o denominador por `((n+1)/n)¹⁰`, que tende a 1. Testando,
`2ⁿ ≤ n¹⁰` vale até **n = 58** (`2⁵⁸ ≈ 2,9 · 10¹⁷` contra `58¹⁰ ≈ 4,3 · 10¹⁷`), e
de **59** em diante a exponencial fica sempre acima. Para conferir, use
`double` e `pow`: os números passam do `long`.

</details>

**3. Expoente somado e expoente multiplicado.** `2^(n+10)` é O(2ⁿ)? E
`2^(2n)`?

<details><summary>Resposta</summary>

`2^(n+10) = 1024 · 2ⁿ`: **sim**, com `c = 1024` e `n₀ = 1`. Já
`2^(2n) = 4ⁿ = 2ⁿ · 2ⁿ`: a razão para `2ⁿ` é o próprio `2ⁿ`, que passa de
qualquer `c`. **Não**. Somar no expoente multiplica por uma constante;
multiplicar o expoente muda a base.

</details>

**4. O logaritmo do fatorial.** Mostre que `log₂(n!)` é Θ(n log n), sem
usar a fórmula de Stirling.

<details><summary>Resposta</summary>

Teto: `n! = 1 · 2 · ... · n ≤ nⁿ`, então `log₂(n!) ≤ n log₂ n`. Piso: os
`n/2` maiores fatores do `n!` são todos pelo menos `n/2`, então
`n! ≥ (n/2)^(n/2)` e `log₂(n!) ≥ (n/2) log₂(n/2)`, que é pelo menos
`(n/4) log₂ n` para `n ≥ 4`. **Θ(n log n)**, com `c₁ = 1/4`, `c₂ = 1` e
`n₀ = 4`. É o limite do assunto 0117 visto pelo outro lado.

</details>

**5. O laço que dobra, contado.** Quantas vezes o `x++` executa com
`n = 1000`?

```c
for (int i = 1; i <= n; i *= 2)
    for (int j = 1; j <= i; j++)
        x++;
```

<details><summary>Resposta</summary>

O `i` vale 1, 2, 4, ..., 512 (o próximo, 1024, passa de 1000). A soma
geométrica dá `1 + 2 + ... + 512 = 1023`. **1023 vezes**, Θ(n), embora sejam
dois laços aninhados.

</details>

**6. Três laços amarrados.** Quantas vezes o `x++` executa? Dê a fórmula
e o valor para `n = 10`.

```c
for (int i = 1; i <= n; i++)
    for (int j = i; j <= n; j++)
        for (int k = i; k <= j; k++)
            x++;
```

<details><summary>Resposta</summary>

Para `i` e `j` fixos, o laço de `k` roda `j - i + 1` vezes. Chamando
`m = n - i + 1`, a soma em `j` dá `1 + 2 + ... + m = m(m+1)/2`, e somando
em `m` de 1 a `n` sai **`n(n+1)(n+2)/6`**, Θ(n³). Para `n = 10`:
`10 · 11 · 12 / 6 = 220`. Um programa com contador confirma.

</details>

**7. Quick sort sem pilha funda.** No pior caso, o quick sort recursivo
empilha `n` frames. Como mudar o código para que a pilha nunca passe de
uns `log₂ n` frames, sem mudar o tempo?

<details><summary>Resposta</summary>

Depois de particionar, faça a chamada recursiva só para o **pedaço
menor** e trate o pedaço maior com um laço (troque `ini` ou `fim` e volte
ao começo). Cada frame novo recebe no máximo metade do pedaço do anterior,
então a profundidade fica **no máximo `log₂ n` + 1**. O tempo no pior caso
continua Θ(n²): o truque só muda o espaço.

</details>

**8. A matriz que não cabe.** Um sistema de logística guarda as distâncias
entre 50 mil cidades numa matriz de `double`. Quanta memória isso exige?
E com listas de adjacência, se houver 200 mil estradas?

<details><summary>Resposta</summary>

A matriz tem `50.000² = 2,5 · 10⁹` posições de 8 bytes: **20 GB**, Θ(n²)
de espaço. As listas de adjacência guardam cada estrada duas vezes (ida e
volta): `400 mil` nós com destino, distância e ponteiro, uns 24 bytes
cada, mais o vetor de cabeças: **uns 10 MB**, Θ(n + m). Com poucas
arestas, a matriz é desperdício (assunto 0109).

</details>

**9. Caso médio com ausentes.** Numa busca sequencial em 1000 elementos,
metade das consultas procura um valor que está no vetor (em posição
uniforme) e metade procura um que não está. Qual é o número médio de
comparações?

<details><summary>Resposta</summary>

Presente: em média `(n + 1)/2 = 500,5`. Ausente: sempre `n = 1000`. A média
ponderada é `0,5 · 500,5 + 0,5 · 1000 = 750,25` comparações. Ainda Θ(n),
mas com outra constante: o caso médio depende da hipótese sobre as
entradas, e a hipótese tem que estar escrita.

</details>

**10. Divisores em série.** Quantas vezes o `x++` executa com `n = 12`? E
qual é a classe?

```c
for (int i = 1; i <= n; i++)
    for (int j = i; j <= n; j += i)
        x++;
```

<details><summary>Resposta</summary>

O laço de dentro passa pelos múltiplos de `i`: `⌊n/i⌋` vezes. Para 12:
`12 + 6 + 4 + 3 + 2 + 2 + 1 + 1 + 1 + 1 + 1 + 1 = 35`. A soma harmônica
dá **Θ(n log n)**. De quebra, o `x++` executado para cada par (`i`, `j`)
conta os divisores de cada `j`: dá para montar a tabela de divisores de 1
a `n` nesse tempo.

</details>

## Questões do POSCOMP

Questões reais do POSCOMP (SBC) sobre este módulo. O enunciado está no caderno oficial: abra o link, resolva e confira o gabarito.

| Ano | Questão | Assunto | Gabarito | Prova |
| --- | --- | --- | --- | --- |
| 2019 | 22 | Relações entre funções com O e Ômega | D | [caderno](https://www.sbc.org.br/wp-content/uploads/2025/02/0518.002_Exame_POSCOMP_2019.pdf) |
| 2024 | 22 | Objetivo da análise assintótica de algoritmos | E | [caderno](https://www2.uesb.br/curso/cienciadacomputacao/wp-content/uploads/2026/05/caderno_2024.pdf) |
| 2025 | 23 | Notação assintótica O, alternativa incorreta | a conferir no gabarito oficial | [caderno](https://www2.uesb.br/curso/cienciadacomputacao/wp-content/uploads/2026/05/caderno_2025.pdf) |

O gabarito oficial de 2025 não estava disponível quando este material foi montado.


## Questões no estilo da prova

Dez questões no formato da prova do PPGI. Marque uma alternativa antes de
abrir o gabarito.

**1.** Seja `f(n) = 3n² + 10n + 20`. Assinale a alternativa correta.

- (A) `f(n)` é Θ(n²).
- (B) `f(n)` é Ω(n³).
- (C) `f(n)` é O(n).
- (D) `f(n)` é O(n log n).
- (E) `f(n)` é Θ(n).

<details><summary>Gabarito</summary>

**A.** `3n² ≤ f(n) ≤ 4n²` para todo `n ≥ 12`. (C), (D) e (E) pedem um teto
menor que n², que nenhum `c` sustenta; (B) pede um piso n³, que `f` não
alcança. Veja 0166.

</details>

**2.** Qual é o valor de `cont` ao final do trecho, com `n = 10`?

```c
int cont = 0;
for (int i = 0; i < n; i++)
    for (int j = i; j < n; j++)
        cont++;
```

- (A) 45
- (B) 50
- (C) 55
- (D) 100
- (E) 110

<details><summary>Gabarito</summary>

**C.** Com `j` começando em `i`, a volta `i` roda `n - i` vezes:
`10 + 9 + ... + 1 = n(n+1)/2 = 55`. O 45 seria `j` começando em `i + 1`.
Veja 0167.

</details>

**3.** Qual é a complexidade de tempo do trecho abaixo, em função de `n`?

```c
for (int i = 1; i < n; i *= 2)
    for (int j = 0; j < i; j++)
        x++;
```

- (A) Θ(log n)
- (B) Θ(n)
- (C) Θ(n log n)
- (D) Θ(n²)
- (E) Θ(2ⁿ)

<details><summary>Gabarito</summary>

**B.** As voltas internas somam `1 + 2 + 4 + ...` até a maior potência de 2
menor que `n`: uma soma geométrica menor que `2n` (com `n = 1024`, dá 1023).
Dois laços aninhados não garantem Θ(n log n) nem Θ(n²). Veja 0167.

</details>

**4.** Considere a função:

```c
long soma(const int v[], int n) {
    if (n == 0) return 0;
    return v[n - 1] + soma(v, n - 1);
}
```

O espaço extra usado por `soma(v, n)` é:

- (A) Θ(1), porque a função não declara vetores.
- (B) Θ(log n), porque cada chamada reduz o problema.
- (C) Θ(n log n), por causa das somas parciais.
- (D) Θ(n), por causa da pilha de chamadas.
- (E) Θ(n²), porque cada chamada copia o vetor.

<details><summary>Gabarito</summary>

**D.** Ficam `n + 1` frames vivos ao mesmo tempo, cada um de tamanho
constante. O vetor não é copiado (passa um ponteiro), o que derruba (E).
Veja 0168.

</details>

**5.** Analise as afirmações:

- I. Se `f(n)` é Θ(g(n)), então `f(n)` é O(g(n)) e Ω(g(n)).
- II. O pior caso da busca sequencial em `n` elementos é Ω(n).
- III. Toda função que é O(n) também é O(n²).

Está correto o que se afirma em:

- (A) I, apenas.
- (B) I e II, apenas.
- (C) I e III, apenas.
- (D) II e III, apenas.
- (E) I, II e III.

<details><summary>Gabarito</summary>

**E.** I é a definição de Θ. II: o pior caso faz `n` comparações, logo é
Θ(n), e portanto Ω(n). III: se `f(n) ≤ c · n`, então `f(n) ≤ c · n²` para
`n ≥ 1`. O é um teto, e um teto mais alto continua teto. Veja 0166.

</details>

**6.** Sobre algoritmos de ordenação, analise as afirmações.

- I. O merge sort com vetor auxiliar tem tempo Θ(n log n) em qualquer entrada
  e espaço extra Θ(n).
- II. O heapsort ordena no próprio vetor, com espaço extra Θ(1), e é estável.
- III. O quick sort, com pivô sempre no extremo e vetor já ordenado, tem tempo
  Θ(n²).

Marque a alternativa **CORRETA**.

- (A) I, apenas.
- (B) I e II, apenas.
- (C) I e III, apenas.
- (D) II e III, apenas.
- (E) I, II e III.

<details><summary>Gabarito</summary>

**C.** I: o tempo é Θ(n log n) em qualquer entrada, e o espaço soma o
auxiliar, Θ(n), e a pilha, Θ(log n): o auxiliar domina. II é falsa: o heapsort
usa Θ(1) de espaço extra, mas **não** é estável (a troca da raiz com o último
embaralha chaves iguais). III: o pivô nos extremos só tira um elemento por
nível, e a recorrência vira `T(n) = T(n - 1) + Θ(n)`. Veja 0168 e 0169.

</details>

**7.** Para provar que `f(n) = 5n + 40` é O(n) com a constante `c = 6`, qual
é o **menor** `n₀` possível?

- (A) 6
- (B) 40
- (C) 20
- (D) 8
- (E) 45

<details><summary>Gabarito</summary>

**B.** `5n + 40 ≤ 6n` equivale a `n ≥ 40`. O 20 serve para `c = 7` e o 8
para `c = 10`: quanto maior o `c`, menor o `n₀`. Veja 0166 (exercício E991).

</details>

**8.** Quantas vezes a instrução `t ← t + 1` é executada para `n = 6`?

```text
t ← 0
para i de 0 até n - 1 faça
    para j de i + 1 até n - 1 faça
        para k de j + 1 até n - 1 faça
            t ← t + 1
```

- (A) 20
- (B) 36
- (C) 56
- (D) 120
- (E) 216

<details><summary>Gabarito</summary>

**A.** Cada execução corresponde a um trio `i < j < k` de `{0, ..., 5}`:
`C(6, 3) = n(n-1)(n-2)/6 = 20`. O 216 seria `n³`, com os três laços
independentes. Veja 0167 (exercício E999).

</details>

**9.** Assinale a relação **falsa**.

- (A) `2^(n+1)` é O(2ⁿ).
- (B) `log₂(n²)` é Θ(log n).
- (C) `n log n` é O(n²).
- (D) `100n + 5` é O(n).
- (E) `4ⁿ` é O(2ⁿ).

<details><summary>Gabarito</summary>

**E.** `4ⁿ / 2ⁿ = 2ⁿ` cresce sem limite: nenhum `c` serve. Em (A) a razão é
2; em (B), `log₂(n²) = 2 log₂ n`; em (C), `log n ≤ n`; em (D), `c = 105`
com `n₀ = 1`. Veja 0166 (exemplo A332).

</details>

**10.** Numa busca sequencial em um vetor de 99 elementos distintos, o
valor procurado sempre está no vetor, com a mesma chance em cada posição.
O número médio de comparações é:

- (A) 1
- (B) 49
- (C) 49,5
- (D) 50
- (E) 99

<details><summary>Gabarito</summary>

**D.** Na posição `i` (contando de 1), a busca faz `i` comparações. A média
é `(1 + 2 + ... + 99) / 99 = (n + 1)/2 = 50`. (A) é o melhor caso e (E), o
pior. Veja 0166 (exemplo A331).

</details>

## Questões de provas do PPGI

Questões reais das provas de conhecimento do PPGI/UFAM, na íntegra e com o gabarito oficial. Resolva no papel, em 3 minutos por questão, e só depois abra o gabarito.

**Edital 055/2017 · Questão 13**

Marque a alternativa CORRETA.
Considerando-se para cada algoritmo o pior cenário possível em termos de uso de espaço, são algoritmos que utilizam espaço extra constante, independentemente do número de elementos do vetor de entrada a ser ordenado:

- A) Mergesort e Seleção.
- B) Quicksort e Mergesort.
- C) Mergesort e Heapsort.
- D) Inserção e Quicksort.
- E) Nenhuma das alternativas acima está correta.

<details><summary>Gabarito</summary>

**E.** O(1) de espaço no pior caso: seleção, inserção, heap; merge usa O(n) e quick usa pilha de recursão (O(n) no pior caso) Assunto 0168.

</details>


## Para ler mais

- CORMEN, T. H.; LEISERSON, C. E.; RIVEST, R. L.; STEIN, C. *Algoritmos: teoria e prática*. 4. ed. Rio de Janeiro: GEN LTC, 2024. Cap. 2 (análise do insertion sort: melhor, pior e caso médio), cap. 3 (notações O, Ω e Θ, com as constantes `c` e `n₀`) e apêndice A (somatórios: aritmética, geométrica e harmônica). Referência do edital: em caso de divergência, siga as definições dele.
- ZIVIANI, N. *Projeto de algoritmos: com implementações em Pascal e C*. 3. ed. São Paulo: Cengage Learning, 2010. Cap. 1 (função de complexidade, melhor, pior e caso médio, dominação assintótica e as notações O, Ω e Θ).
- SZWARCFITER, J. L.; MARKENZON, L. *Estruturas de dados e seus algoritmos*. 3. ed. Rio de Janeiro: LTC, 2010. Cap. 1 (complexidade de pior caso, de melhor caso e média; notações O, Ω e Θ).
- FEOFILOFF, P. *Análise de algoritmos* (livrinho). São Paulo: IME-USP. Disponível em: <https://www.ime.usp.br/~pf/livrinho-AA/>. Capítulos sobre ordens O, Ω e Θ e sobre somatórios.
- FEOFILOFF, P. *Algoritmos em linguagem C*. Rio de Janeiro: Elsevier, 2009. Apêndices sobre análise de desempenho e recursão.
- LINTZMAYER, C. N.; MOTA, G. O. *Análise de algoritmos e de estruturas de dados*. Santo André: UFABC; São Paulo: IME-USP, 2023. Notas de aula. Partes sobre notação assintótica e somatórios.
- TENENBAUM, A. M.; LANGSAM, Y.; AUGENSTEIN, M. J. *Estruturas de dados usando C*. São Paulo: Makron Books, 1995. Cap. 3 (recursão e o custo da pilha) e cap. 6 (eficiência da classificação).
- KERNIGHAN, B. W.; RITCHIE, D. M. *C: a linguagem de programação padrão ANSI*. Rio de Janeiro: Campus, 1989. Seções 4.4 (variáveis externas e `extern`), 4.6 (`static`) e 4.10 (recursão).
- CPPREFERENCE. *Storage duration* e *malloc*. Disponível em: <https://en.cppreference.com/w/c/language/storage_duration>.
- LINUX MAN-PAGES. *getrlimit(2)* (o limite da pilha, `RLIMIT_STACK`) e *malloc(3)*. Disponível em: <https://man7.org/linux/man-pages/man2/getrlimit.2.html>.
