# Módulo 26 · Notação assintótica, somatórios e espaço

No módulo 10 você aprendeu a contar passos e a dizer "isso é O(n²)" olhando
os laços. No módulo 17, a resolver recorrências e a usar Θ e Ω. Faltava
fechar três pontas, e é delas que este módulo trata: as **definições
formais** de O, Ω e Θ, com as constantes `c` e `n₀`; os **somatórios** que
dão o número exato de vezes que um laço roda; e a **complexidade
espacial**, que mede memória do mesmo jeito que o tempo.

A mudança na cabeça é passar do "parece n²" para a conta. Dizer que
`3n² + 10n + 20` é Θ(n²) vira uma afirmação que se **prova** (exibindo `c₁`,
`c₂` e `n₀`) ou se **refuta** (mostrando que nenhum par serve). Dizer que um
laço dependente roda "umas n²/2 vezes" vira `n(n-1)/2`, exato, conferido
por um contador. E dizer que uma função "não usa memória" passa a exigir
olhar a pilha da recursão, que gasta espaço mesmo sem nenhum vetor.

Tudo é verificado em C: cada fórmula tem um programa que conta e confere.
O último assunto junta as três ideias numa conferência completa de cinco
funções: passos, bytes e frames, medidos e comparados com a fórmula.

## O que você vai aprender

- as definições de **O**, **Ω** e **Θ** com `c` e `n₀`, e como **provar** e **refutar** um limite
- a diferença entre **melhor caso**, **pior caso** e **caso médio**, e por que isso não é a mesma coisa que O, Ω e Θ
- achar `c` e `n₀` com um programa, e entender por que o programa não substitui a prova
- transformar laços em **somatórios**: aritmética, quadrados, geométrica e harmônica, com laços dependentes
- calcular o número **exato** de execuções de um laço e conferir com um contador
- a **complexidade espacial**: espaço extra, algoritmos **in-place**, o espaço da **pilha da recursão**
- a troca de **tempo por espaço**: tabelas, prefixos e memoização
- conferir uma ficha de complexidade inteira medindo passos, bytes e frames

## Como estudar cada assunto

1. Leia o texto e olhe o **diagrama da ideia**: a tabela do `n₀`, o
   triângulo dos apertos de mão, a memória extra da inversão, a ficha das
   cinco funções. Os números são os mesmos do código.
2. Faça as contas no papel **antes** de rodar: a desigualdade do `n₀`, o
   somatório do laço, os bytes extras.
3. Siga o **fluxograma** com o dedo.
4. Rode o exemplo e confira a saída com a sua conta. Mude o `n`, dobre, e
   veja se o contador acompanha a fórmula.
5. Faça os exercícios. ★☆☆ é aquecimento, ★★☆ pede raciocínio, ★★★ é desafio.
   As dicas vêm logo abaixo do enunciado: tente antes de ler.
6. No fim, resolva as **questões no estilo da prova**: elas cobram o mesmo
   conteúdo no formato de múltipla escolha.

No meio de cada assunto tem uma **Pergunta para você**. Responda antes de rodar.

## As cores e as formas

Nos fluxogramas, caixa azul é dado entrando ou saindo, roxa é o programa
fazendo alguma coisa, amarela é pergunta. Verde é o caminho que o exemplo
segue; cinza, o que ele não usa.

Nos diagramas da ideia, **verde** é o que vale (o teto que já segura, o
espaço constante), **vermelho** é o que falha ou o que cresce com `n` (o teto
que ainda perde, a cópia extra), **roxo** é trabalho sendo contado,
**amarelo** marca o ponto de virada (o `n₀`, a razão ao dobrar `n`) e
**cinza** é o que não entra na conta.

<p align="center"><img src="../legenda.svg" alt="Legenda: formas e cores do fluxograma" width="916"></p>

## Antes de começar

Este módulo usa: contagem de passos e notação O (0071 e 0072), pilha de
chamadas e recursão (0031 a 0033), pilha, heap, `malloc` e `free` (0053 e 0054),
ponteiro para função (0050), busca binária (0090), insertion sort e merge
sort (0093 e 0094), recorrências e a notação Θ (0114 a 0117), permutações
por backtracking (0126), potência rápida (0131) e memoização (0138).

Matemática: potências, logaritmos e somas. Lembre que `log₂ n` é quantas
vezes dá para dividir `n` por 2 até chegar em 1, e que `ln n` é o logaritmo
natural (`log` em `<math.h>`). O `rodar` já liga a biblioteca matemática.

O último assunto tem um TAD na pasta, `custo.h` e `custo.c`, com cinco
funções instrumentadas. O `rodar` compila o `custo.c` junto com qualquer
exemplo ou exercício da pasta; por isso, nos exercícios de lá, não use os
nomes `custo_passos`, `custo_bytes` e `custo_prof_max` para variáveis suas.
Os exercícios de "conserte" trazem o erro de propósito, e o enunciado
avisa.

{{indice}}

---

{{assuntos}}

---

## Desafios do módulo

Problemas para fechar o módulo, misturando os assuntos. Resolva no papel e,
sempre que der, confira com um programa em C rodado com o `rodar`.

**1. Um sanduíche cúbico.** Prove que `f(n) = 5n³ + 2n² - 7` é Θ(n³):
encontre `c₁`, `c₂` e `n₀`.

<details><summary>Resposta</summary>

Piso: `5n³ + 2n² - 7 ≥ 5n³` quando `2n² ≥ 7`, ou seja, `n ≥ 2`. Teto:
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

## Questões no estilo da prova

Dez questões objetivas no formato da prova de conhecimentos do PPGI. Marque
uma alternativa antes de abrir o gabarito.

**1.** Seja `f(n) = 3n² + 10n + 20`. Assinale a alternativa correta.

- (A) `f(n)` é O(n).
- (B) `f(n)` é Ω(n³).
- (C) `f(n)` é Θ(n²).
- (D) `f(n)` é O(n log n).
- (E) `f(n)` é Θ(n).

<details><summary>Gabarito</summary>

**C.** `3n² ≤ f(n) ≤ 4n²` para todo `n ≥ 12`. (A), (D) e (E) pedem um teto
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
- (C) Θ(n), por causa da pilha de chamadas.
- (D) Θ(n log n), por causa das somas parciais.
- (E) Θ(n²), porque cada chamada copia o vetor.

<details><summary>Gabarito</summary>

**C.** Ficam `n + 1` frames vivos ao mesmo tempo, cada um de tamanho
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
`n ≥ 1`; O é só um teto, e um teto mais alto continua teto. Veja 0166.

</details>

**6.** Sobre o merge sort que usa um vetor auxiliar de `n` posições, o
tempo no pior caso e o espaço extra são, respectivamente:

- (A) Θ(n log n) e Θ(1)
- (B) Θ(n²) e Θ(n)
- (C) Θ(n log n) e Θ(n)
- (D) Θ(n log n) e Θ(log n)
- (E) Θ(n) e Θ(n)

<details><summary>Gabarito</summary>

**C.** O tempo é Θ(n log n) em qualquer entrada. O espaço extra soma o
auxiliar, Θ(n), e a pilha, Θ(log n): o auxiliar domina. (D) esquece o
vetor; (A) descreve o heapsort. Veja 0168 e 0169.

</details>

**7.** Para provar que `f(n) = 5n + 40` é O(n) com a constante `c = 6`, qual
é o **menor** `n₀` possível?

- (A) 6
- (B) 8
- (C) 20
- (D) 40
- (E) 45

<details><summary>Gabarito</summary>

**D.** `5n + 40 ≤ 6n` equivale a `n ≥ 40`. O 20 serve para `c = 7` e o 8
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
- (D) `4ⁿ` é O(2ⁿ).
- (E) `100n + 5` é O(n).

<details><summary>Gabarito</summary>

**D.** `4ⁿ / 2ⁿ = 2ⁿ` cresce sem limite: nenhum `c` serve. Em (A) a razão é
2; em (B), `log₂(n²) = 2 log₂ n`; em (C), `log n ≤ n`; em (E), `c = 105`
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
