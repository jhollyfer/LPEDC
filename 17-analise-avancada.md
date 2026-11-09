<!-- Gerado por _gerador. Para mudar este arquivo, edite _gerador/modulos/17-analise-avancada/ e rode: cd _gerador && npm run gerar -->

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

| # | Assunto | Pasta |
| --- | --- | --- |
| [0114](#0114--recorrências-e-árvore-de-recursão) | Recorrências e árvore de recursão | [`0114-recorrencias/`](17-analise-avancada/0114-recorrencias/) |
| [0115](#0115--teorema-mestre) | Teorema mestre | [`0115-teorema-mestre/`](17-analise-avancada/0115-teorema-mestre/) |
| [0116](#0116--análise-amortizada) | Análise amortizada | [`0116-amortizada/`](17-analise-avancada/0116-amortizada/) |
| [0117](#0117--limite-inferior-da-ordenação) | Limite inferior da ordenação | [`0117-limite-inferior/`](17-analise-avancada/0117-limite-inferior/) |
| [0118](#0118--juntando-tudo) | Juntando tudo | [`0118-juntando-tudo/`](17-analise-avancada/0118-juntando-tudo/) |

---

## 0114 · Recorrências e árvore de recursão

Fim de ano na contabilidade de uma rede de farmácias: chegou um lote de notas
fiscais para auditar. A chefe confere o lote inteiro (passa o olho em todas as
notas), divide em dois lotes iguais e entrega cada metade para um auditor.
Cada auditor faz a mesma coisa: confere o seu lote, divide, repassa. Quando
um lote fica com uma nota só, quem recebeu confere essa nota e pronto.

Quantas notas são olhadas no total? Contar laços, como no módulo 10, não
resolve: o trabalho está escondido nas chamadas.

Uma **recorrência** é uma equação que dá o custo de uma função recursiva em
termos do custo dela mesma com entradas menores. Chamando de `T(n)` o custo
para um lote de `n` notas:

```text
T(1) = 1                  (caso base: confere a nota e para)
T(n) = 2 T(n/2) + n       (duas chamadas com metade, mais n de trabalho)
```

Você escreve a recorrência **lendo o código**, em três perguntas:

1. **Quantas chamadas recursivas** a função faz, e com que tamanho? Aqui, 2
   chamadas de tamanho `n/2`: o termo `2 T(n/2)`.
2. **Quanto trabalho** ela faz fora das chamadas? Aqui, olhar as `n` notas:
   o termo `n`.
3. **Qual é o caso base**, e quanto ele custa? Aqui, `T(1) = 1`.

Escrever é a parte fácil. Para **resolver** (chegar numa fórmula sem `T` dos
dois lados), o jeito mais visual é a **árvore de recursão**: cada chamada
vira um nó com o trabalho que ela faz sozinha, e você soma **nível por
nível**. O nível `k` tem `2^k` chamadas, cada uma com um lote de `n/2^k`
notas: o nível inteiro custa `2^k · n/2^k = n`. Os lotes caem pela metade até
chegar em 1, então são `log₂ n + 1` níveis. Total: `n log₂ n + n`, que é
**Θ(n log n)**.

O **Θ** (teta) é novo: ele diz que a função cresce **exatamente** naquele
ritmo, nem mais rápido nem mais devagar. O `O` do assunto 0072 é um teto;
o Θ é teto e piso ao mesmo tempo. Quando você resolve uma recorrência até a
fórmula, sabe o ritmo exato, e o Θ é a palavra certa (as definições formais
de O, Ω e Θ estão no assunto 0166). O Cormen ensina três métodos para
resolver: a **substituição** (chutar a resposta e provar por indução), a
árvore de recursão e o teorema mestre, do próximo assunto.

A forma da recorrência decide a forma da árvore. As cinco mais comuns:

| recorrência | árvore | resultado | exemplo |
| --- | --- | --- | --- |
| `T(n) = T(n-1) + 1` | uma linha de n nós | Θ(n) | percorrer lista recursivamente |
| `T(n) = T(n/2) + 1` | uma linha de log n nós | Θ(log n) | busca binária |
| `T(n) = T(n-1) + n` | uma linha, nós encolhendo | Θ(n²) | selection sort recursivo |
| `T(n) = 2 T(n/2) + n` | binária, log n níveis de custo n | Θ(n log n) | merge sort, a auditoria |
| `T(n) = 2 T(n-1) + 1` | binária, n níveis que dobram | Θ(2ⁿ) | Hanói (assunto 0033) |

Tome um lote de 8 notas. Cada caixa é uma chamada, com o tamanho do lote que
ela confere. Some cada linha: dá 8 em todas, e são 4 linhas:

<p align="center"><img src="17-analise-avancada/0114-recorrencias/ideia.svg" alt="Diagrama da ideia: Recorrências e árvore de recursão" width="858"></p>

O código conta as notas de cada nível num vetor indexado pela profundidade
da chamada. Depois confere a fórmula `n log₂ n + n` para lotes maiores:

```c
#include <stdio.h>

#define MAX_NIVEIS 32

long custo_nivel[MAX_NIVEIS]; // notas conferidas em cada nível da recursão

// confere o lote [ini, fim): olha todas as notas e divide o lote em dois
void audita(int ini, int fim, int nivel) {
    int n = fim - ini;
    custo_nivel[nivel] += n;            // trabalho fora das chamadas: n
    if (n == 1) {
        return;                         // caso base: uma nota só
    }
    int meio = ini + n / 2;
    audita(ini, meio, nivel + 1);       // T(n/2)
    audita(meio, fim, nivel + 1);       // T(n/2)
}

// zera os níveis, audita n notas e devolve o total
long total_auditado(int n, int mostrar) {
    for (int k = 0; k < MAX_NIVEIS; k++) {
        custo_nivel[k] = 0;
    }
    audita(0, n, 0);
    long total = 0;
    for (int k = 0; k < MAX_NIVEIS && custo_nivel[k] > 0; k++) {
        if (mostrar) {
            printf("nível %d: %ld notas\n", k, custo_nivel[k]);
        }
        total += custo_nivel[k];
    }
    return total;
}

int main(void) {
    printf("total: %ld notas\n\n", total_auditado(8, 1));

    int tamanhos[] = {8, 64, 1024, 1048576};
    int lg[] = {3, 6, 10, 20};          // log2 de cada tamanho
    printf("      n         T(n)   n log n + n\n");
    for (int i = 0; i < 4; i++) {
        int n = tamanhos[i];
        printf("%7d %12ld %12ld\n", n, total_auditado(n, 0), (long)n * lg[i] + n);
    }
    return 0;
}
// Saída:
// nível 0: 8 notas
// nível 1: 8 notas
// nível 2: 8 notas
// nível 3: 8 notas
// total: 32 notas
//
//       n         T(n)   n log n + n
//       8           32           32
//      64          448          448
//    1024        11264        11264
// 1048576     22020096     22020096
```

O fluxograma é a função `audita` inteira, e não tem laço. A repetição está
nas duas caixas `audita`: cada uma é o fluxograma inteiro de novo, para uma
metade. Essas duas caixas são o `2 T(n/2)` da recorrência; a caixa
`custo_nivel += n` é o `+ n`:

<p align="center"><img src="17-analise-avancada/0114-recorrencias/fluxograma.svg" alt="Fluxograma: Recorrências e árvore de recursão" width="350"></p>

### Passo a passo

A recorrência também se resolve "abrindo" o `T` até o caso base, com `n = 8`:

| passo | conta | valor |
| --- | --- | --- |
| T(1) | caso base | 1 |
| T(2) | 2 · T(1) + 2 = 2 + 2 | 4 |
| T(4) | 2 · T(2) + 4 = 8 + 4 | 12 |
| T(8) | 2 · T(4) + 8 = 24 + 8 | **32** |

Bate com a árvore (4 níveis de 8) e com o programa.

> [!WARNING]
> "Duas chamadas recursivas" não diz nada sozinho: o que decide é **o
> tamanho** que cada chamada recebe. `2 T(n/2) + 1` (achar o máximo dividindo
> o vetor ao meio) dá Θ(n): umas `2n` chamadas. `2 T(n-1) + 1` (Hanói) dá
> Θ(2ⁿ): para `n = 30`, mais de um bilhão de chamadas. Entre `n/2` e `n-1`
> está a diferença entre um programa instantâneo e um que não termina hoje.
> Leia os argumentos de cada chamada antes de escrever a recorrência.

> [!TIP]
> **Por dentro do C:** a árvore de recursão é o **filme** da pilha de
> chamadas (assunto 0031). Cada nó é um frame que nasce, trabalha e morre; a
> ordem em que o programa visita os nós é a de uma DFS na árvore. Por isso o
> **tempo** é a soma de todos os nós (`2n - 1 = 15` chamadas para 8 notas),
> mas a **memória** da pilha é a altura: no máximo `log₂ n + 1 = 4` frames
> vivos ao mesmo tempo. Para 1 milhão de notas, são 2 milhões de chamadas e
> 21 frames empilhados. A pilha só estoura quando a árvore é **funda**,
> como na linha de `n` nós de `T(n-1) + 1`.

> [!NOTE]
> **Pergunta para você:** e se a chefe, em vez de dividir ao meio, tirasse uma
> nota só do lote e repassasse as outras `n - 1` para um único auditor? A
> recorrência vira `T(n) = T(n-1) + n`. Quanto dá para 8 notas? E para 1024?
> Compare com 32 e 11.264.

### Hora de praticar

Arquivos em [`0114-recorrencias/`](17-analise-avancada/0114-recorrencias/).

**Exemplo A227 · Duas chamadas, destinos diferentes**

```c
#include <stdio.h>

long chamadas = 0; // contador global: quantas vezes alguma função foi chamada

// maior valor de v[ini..fim-1] dividindo ao meio: T(n) = 2 T(n/2) + 1
int maximo(const int v[], int ini, int fim) {
    chamadas++;
    if (fim - ini == 1) {
        return v[ini];
    }
    int meio = ini + (fim - ini) / 2;
    int a = maximo(v, ini, meio);
    int b = maximo(v, meio, fim);
    return a > b ? a : b;
}

// Fibonacci ingênuo: T(n) = T(n-1) + T(n-2) + 1
long fib(int n) {
    chamadas++;
    if (n < 2) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

// soma de 1 a n, uma chamada por vez: T(n) = T(n-1) + 1
long soma(int n) {
    chamadas++;
    if (n == 0) {
        return 0;
    }
    return n + soma(n - 1);
}

int main(void) {
    int vendas[30];
    for (int i = 0; i < 30; i++) {
        vendas[i] = (i * 37) % 101; // vendas do dia, valores "embaralhados"
    }

    printf(" n | maximo: 2 T(n/2) + 1  | fib: T(n-1) + T(n-2) + 1  | soma: T(n-1) + 1\n");
    for (int n = 10; n <= 30; n += 10) {
        chamadas = 0;
        int m = maximo(vendas, 0, n);
        long c_max = chamadas;

        chamadas = 0;
        long f = fib(n);
        long c_fib = chamadas;

        chamadas = 0;
        long s = soma(n);
        long c_soma = chamadas;

        printf("%2d | %3d em %2ld chamadas    | %6ld em %7ld chamadas | %3ld em %2ld chamadas\n",
               n, m, c_max, f, c_fib, s, c_soma);
    }
    return 0;
}
// Saída:
//  n | maximo: 2 T(n/2) + 1  | fib: T(n-1) + T(n-2) + 1  | soma: T(n-1) + 1
// 10 |  94 em 19 chamadas    |     55 em     177 chamadas |  55 em 11 chamadas
// 20 |  97 em 39 chamadas    |   6765 em   21891 chamadas | 210 em 21 chamadas
// 30 |  97 em 59 chamadas    | 832040 em 2692537 chamadas | 465 em 31 chamadas
```

```bash
~/LPEDC/rodar 17-analise-avancada/0114-recorrencias/A227.c
```

**Exemplo A228 · Hanói: a árvore em que cada nível dobra**

```c
#include <stdio.h>

#define MAX_DISCOS 25

long movimentos_nivel[MAX_DISCOS]; // movimentos feitos em cada nível da recursão

// move n discos de 'de' para 'para' usando 'aux': T(n) = 2 T(n-1) + 1
void hanoi(int n, char de, char para, char aux, int nivel, int mostrar) {
    if (n == 0) {
        return;
    }
    if (mostrar) {
        printf("%*shanoi(%d, %c -> %c)\n", 2 * nivel, "", n, de, para);
    }
    hanoi(n - 1, de, aux, para, nivel + 1, mostrar); // tira os n-1 de cima
    movimentos_nivel[nivel]++;                       // move o disco maior: o "+ 1"
    hanoi(n - 1, aux, para, de, nivel + 1, mostrar); // põe os n-1 por cima
}

long resolve(int n, int mostrar) {
    for (int k = 0; k < MAX_DISCOS; k++) {
        movimentos_nivel[k] = 0;
    }
    hanoi(n, 'A', 'C', 'B', 0, mostrar);
    long total = 0;
    for (int k = 0; k < n; k++) {
        total += movimentos_nivel[k];
    }
    return total;
}

int main(void) {
    printf("A árvore de chamadas com 3 discos (o recuo é o nível):\n");
    resolve(3, 1);

    printf("\nCom 5 discos, nível por nível:\n");
    long total = resolve(5, 0);
    for (int k = 0; k < 5; k++) {
        printf("nível %d: %2ld × hanoi(%d), 1 movimento cada\n", k, movimentos_nivel[k], 5 - k);
    }
    printf("total: %ld = 2^5 - 1\n", total);

    printf("\n n   movimentos\n");
    for (int n = 5; n <= 20; n += 5) {
        printf("%2d %12ld\n", n, resolve(n, 0));
    }
    return 0;
}
// Saída:
// A árvore de chamadas com 3 discos (o recuo é o nível):
// hanoi(3, A -> C)
//   hanoi(2, A -> B)
//     hanoi(1, A -> C)
//     hanoi(1, C -> B)
//   hanoi(2, B -> C)
//     hanoi(1, B -> A)
//     hanoi(1, A -> C)
//
// Com 5 discos, nível por nível:
// nível 0:  1 × hanoi(5), 1 movimento cada
// nível 1:  2 × hanoi(4), 1 movimento cada
// nível 2:  4 × hanoi(3), 1 movimento cada
// nível 3:  8 × hanoi(2), 1 movimento cada
// nível 4: 16 × hanoi(1), 1 movimento cada
// total: 31 = 2^5 - 1
//
//  n   movimentos
//  5           31
// 10         1023
// 15        32767
// 20      1048575
```

```bash
~/LPEDC/rodar 17-analise-avancada/0114-recorrencias/A228.c
```

#### Exercícios

**Exercício E679** · ★☆☆

A busca binária recursiva abaixo segue a recorrência T(n) = T(n/2) + 1.
Confira isso no computador: acrescente um contador global de chamadas e
troque o main para buscar o valor 5 (menor que todos os CPFs, o pior caso
quando n é potência de 2) em pedaços de tamanho n = 1, 2, 4, ..., 1024 do
vetor, sempre a partir do índice 0, mostrando quantas chamadas cada busca
fez:


```text
Saída esperada:
   n  chamadas
   1  2
   2  3
   4  4
 ...
 512  11
1024  12
```

**Dicas:**

1. Declare long chamadas = 0; fora das funções e faça chamadas++ na
   primeira linha de busca, antes de qualquer return.
2. Zere o contador antes de cada busca. O laço de fora pode ser
   for (int n = 1; n <= 1024; n *= 2), chamando busca(cpfs, 0, n, 5).
3. Resposta esperada: a tabela acima, chamadas = log2(n) + 2. Um nível
   por divisão ao meio, mais a chamada com 1 elemento e a chamada com o
   pedaço vazio, que é quem devolve -1.

```bash
~/LPEDC/rodar 17-analise-avancada/0114-recorrencias/E679.c
```

**Exercício E680** · ★☆☆

Uma recorrência também é um programa: dá para calcular T(n) com uma função
recursiva que é a própria equação. Complete as três funções abaixo, todas
com caso base 1 quando n = 1:


```text
A(n) = A(n/2) + 1          (busca binária)
B(n) = 2 B(n/2) + 1        (máximo dividindo ao meio)
C(n) = 2 C(n/2) + n        (a auditoria do texto)
```


O main já mostra, ao lado de cada uma, a fórmula fechada que a árvore de
recursão dá. Se as colunas baterem, suas funções estão certas:


```text
Saída esperada:
 n | A(n) log+1 | B(n) 2n-1 | C(n) n log n + n
 1 |    1     1 |    1    1 |    1     1
 2 |    2     2 |    3    3 |    4     4
 4 |    3     3 |    7    7 |   12    12
 8 |    4     4 |   15   15 |   32    32
16 |    5     5 |   31   31 |   80    80
32 |    6     6 |   63   63 |  192   192
64 |    7     7 |  127  127 |  448   448
```

**Dicas:**

1. Cada função tem duas linhas de verdade: if (n == 1) return 1; e o
   return com a equação.
2. B não precisa de duas chamadas: 2 * rec_b(n / 2) + 1 calcula o mesmo
   valor com uma só (aqui você calcula o custo, não roda o algoritmo).
3. Resposta esperada: a tabela acima.

```bash
~/LPEDC/rodar 17-analise-avancada/0114-recorrencias/E680.c
```

**Exercício E681** · ★★☆

Um comparador de preços confere um lote de produtos assim: compara cada
preço do lote com TODOS os preços do lote (n² comparações), procurando
pares suspeitos, depois divide o lote ao meio e confere cada metade do
mesmo jeito. A recorrência é T(n) = 2 T(n/2) + n², com T(1) = 1.

O programa abaixo só mostra o total. Mude-o para contar as comparações
POR NÍVEL da recursão (como o custo_nivel do texto), mostrar os níveis
para n = 8 e depois os totais para n = 16, 32 e 64 ao lado de 2n² - n:


```text
Saída esperada:
nível 0: 64 comparações
nível 1: 32 comparações
nível 2: 16 comparações
nível 3: 8 comparações
total: 120

 n  T(n)  2n² - n
16   496   496
32  2016  2016
64  8128  8128
```


Repare: aqui o custo CAI pela metade a cada nível. É o oposto da
auditoria do texto, em que todo nível custava igual.

**Dicas:**

1. Troque o contador único por um vetor long custo_nivel[32] e passe o
   nível como parâmetro (a raiz é o nível 0; os filhos, nível + 1).
2. Antes de cada medição, zere o vetor inteiro.
3. Por que 2n² - n? Os níveis custam n², n²/2, n²/4, ..., n: a soma de
   uma progressão geométrica de razão 1/2 fica abaixo do dobro do
   primeiro termo. A raiz sozinha já é metade de tudo: Θ(n²).
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 17-analise-avancada/0114-recorrencias/E681.c
```

**Exercício E682** · ★★☆

Escreva do zero um selection sort RECURSIVO, sem laço externo:
ordena(v, n) procura o maior de v[0..n-1], troca com v[n-1] e chama
ordena(v, n - 1). Cada chamada mostra quantas comparações fez, e o main
mostra o total e o vetor ordenado. Os preços são:


```text
42 17 88 5 63 29 71 10
```



```text
Saída esperada:
ordena(8): 7 comparações
ordena(7): 6 comparações
ordena(6): 5 comparações
ordena(5): 4 comparações
ordena(4): 3 comparações
ordena(3): 2 comparações
ordena(2): 1 comparação
total: 28 = 8 · 7 / 2
5 10 17 29 42 63 71 88
```

**Dicas:**

1. Caso base: com n <= 1 não há o que fazer.
2. A recorrência é T(n) = T(n-1) + (n - 1), com T(1) = 0. A árvore de
   recursão vira uma linha: 7 + 6 + ... + 1.
3. Some as comparações num contador global para o total.
4. Resposta esperada: a saída acima. Para n = 1000 seriam 499.500
   comparações: Θ(n²), mesmo sem nenhum laço aninhado no código. A
   recursão faz o papel do laço de fora.

```bash
~/LPEDC/rodar 17-analise-avancada/0114-recorrencias/E682.c
```

**Exercício E683** · ★★★

Conserte o programa. Ele acha a maior temperatura de 20 dias e a resposta
está certa, mas ele é lento demais para o que faz:


```text
Saída que aparece:
maior: 35 graus, 1048575 chamadas
```


Com 30 dias, o mesmo programa faria mais de um bilhão de chamadas. Leia
os argumentos das duas chamadas recursivas, escreva (num comentário) a
recorrência que o código segue de verdade, e conserte a divisão para que
cada chamada receba METADE do pedaço. Depois acrescente a medição para
30 dias:


```text
Saída esperada:
maior: 35 graus, 39 chamadas
30 dias: maior 35 graus, 59 chamadas
```

**Dicas:**

1. Com fim - ini = n, quantos elementos tem [ini, fim - 1)? E
   [ini + 1, fim)? Os dois pedaços quase inteiros se sobrepõem.
2. O código segue T(n) = 2 T(n-1) + 1, a recorrência de Hanói: 2^n - 1
   chamadas. Para n = 20, 2^20 - 1 = 1.048.575.
3. Use meio = ini + (fim - ini) / 2 e as chamadas [ini, meio) e
   [meio, fim). Agora é T(n) = 2 T(n/2) + 1: 2n - 1 chamadas.
4. Resposta esperada: 39 chamadas para 20 dias e 59 para 30.

```bash
~/LPEDC/rodar 17-analise-avancada/0114-recorrencias/E683.c
```

**Exercício E684** · ★★★

Quantas chamadas o fib ingênuo faz? A própria contagem segue uma
recorrência: fib(n) é 1 chamada mais as chamadas de fib(n-1) e de
fib(n-2). Com C(n) = número de chamadas:


```text
C(0) = C(1) = 1
C(n) = C(n-1) + C(n-2) + 1
```


Escreva um programa com três funções:
- fib(n), a recursiva ingênua, com um contador global de chamadas;
- conta_chamadas(n), que calcula C(n) com um LAÇO (sem recursão);
- fib_laco(n), que calcula o Fibonacci F(n) com um laço.

Mostre, para n = 5, 10, ..., 25, as chamadas contadas de verdade, C(n) e a
fórmula 2F(n+1) - 1. No fim, use só o laço para mostrar C(40) (rodar o
fib(40) levaria muito tempo) e a razão C(40) / C(39):


```text
Saída esperada:
 n  contadas    C(n)  2F(n+1)-1
 5        15      15         15
10       177     177        177
15      1973    1973       1973
20     21891   21891      21891
25    242785  242785     242785
C(40) = 331160281
C(40) / C(39) = 1.6180
```

**Dicas:**

1. O laço de conta_chamadas guarda só os dois últimos valores, como o
   Fibonacci iterativo: proximo = atual + anterior + 1.
2. Zere o contador antes de cada fib(n).
3. A razão tende a 1,618... (o número de ouro): cada n a mais multiplica
   as chamadas por 1,6. É isso que quer dizer Θ(1,618ⁿ).
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 17-analise-avancada/0114-recorrencias/E684.c
```

---

## 0115 · Teorema mestre

Na declaração do Imposto de Renda, ninguém refaz a conta do imposto do zero.
Você acha a sua faixa na tabela progressiva e lê a alíquota. A tabela já
embute o cálculo: basta saber em que linha você cai.

O **teorema mestre** é a tabela pronta das recorrências de divisão e
conquista. No assunto anterior, cada recorrência pedia uma árvore de
recursão desenhada e somada nível por nível. Para a forma mais comum, essa
soma já foi feita em geral, e o resultado cabe em três linhas.

A forma é esta:

```text
T(n) = a T(n/b) + n^k
```

- `a` (pelo menos 1) é **quantas chamadas** recursivas cada chamada faz;
- `b` (maior que 1) é **quanto o tamanho encolhe**: cada chamada recebe `n/b`;
- `n^k` é o **trabalho fora das chamadas**: `k = 0` é constante, `k = 1` é
  linear, `k = 2` é quadrático.

De onde vêm as três linhas? Da árvore. No nível `j` há `a^j` chamadas, cada
uma com tamanho `n/b^j`, custando `(n/b^j)^k`. O nível inteiro custa
`n^k · (a/b^k)^j`: de um nível para o seguinte, o custo é multiplicado
sempre pela mesma razão, `a/b^k`. Só há três possibilidades:

| caso | comparação | o custo por nível... | quem pesa | resultado |
| --- | --- | --- | --- | --- |
| 1 | `a > b^k` | **cresce** a cada nível | as folhas | Θ(n^(log_b a)) |
| 2 | `a = b^k` | fica **igual** | todos os níveis | Θ(n^k log n) |
| 3 | `a < b^k` | **cai** a cada nível | a raiz | Θ(n^k) |

Quando o custo cresce (caso 1), o último nível manda: ele tem
`a^(log_b n) = n^(log_b a)` folhas, e os níveis de cima, somados, não
passam de um múltiplo fixo dele. Quando fica igual (caso 2), são
`log_b n + 1` níveis de `n^k`. Quando cai (caso 3), a raiz sozinha já é uma
fração fixa do total. Comparar `a`
com `b^k` é o mesmo que comparar o expoente `log_b a` com `k`.

Um escritório revisa um contrato de `n` páginas: o
revisor lê tudo (`n` páginas) e repassa **metade** do contrato para `a`
estagiários, que fazem o mesmo. Só o `a` muda: 1, 2 ou 4 estagiários. Com
`b = 2` e `k = 1`, temos `b^k = 2`, e cada valor de `a` cai numa linha
diferente da tabela. O desenho mostra a árvore de cada um para `n = 16`:

<p align="center"><img src="17-analise-avancada/0115-teorema-mestre/ideia.svg" alt="Diagrama da ideia: Teorema mestre" width="858"></p>

O código calcula o total de páginas lidas fazendo as `a` chamadas de
verdade. A última parte faz o teste prático do teorema: dobra o `n` e vê por
quanto o total é multiplicado:

```c
#include <stdio.h>

// o revisor lê as n páginas e repassa metade do contrato para 'a' estagiários
// T(n) = a T(n/2) + n, T(1) = 1
long paginas(int a, int n) {
    if (n == 1) {
        return 1;                        // uma página: lê e pronto
    }
    long total = n;                      // f(n) = n: lê tudo
    for (int i = 0; i < a; i++) {
        total += paginas(a, n / 2);      // a chamadas com metade
    }
    return total;
}

int main(void) {
    printf("    n      a = 1      a = 2      a = 4\n");
    for (int n = 16; n <= 1024; n *= 2) {
        printf("%5d", n);
        for (int a = 1; a <= 4; a *= 2) {
            printf(" %10ld", paginas(a, n));
        }
        printf("\n");
    }
    printf("\nquando n dobra (512 -> 1024), o total multiplica por:\n");
    for (int a = 1; a <= 4; a *= 2) {
        printf("a = %d: %.2f\n", a, (double)paginas(a, 1024) / paginas(a, 512));
    }
    return 0;
}
// Saída:
//     n      a = 1      a = 2      a = 4
//    16         31         80        496
//    32         63        192       2016
//    64        127        448       8128
//   128        255       1024      32640
//   256        511       2304     130816
//   512       1023       5120     523776
//  1024       2047      11264    2096128
//
// quando n dobra (512 -> 1024), o total multiplica por:
// a = 1: 2.00
// a = 2: 2.20
// a = 4: 4.00
```

Confira com a tabela. Com `a = 1`, `1 < 2`: caso 3, a raiz domina, Θ(n),
e o total é `2n - 1` (dobra quando `n` dobra). Com `a = 2`, `2 = 2`: caso 2,
empate, Θ(n log n), exatamente `n log₂ n + n` (dobra e mais um pouco). Com
`a = 4`, `4 > 2`: caso 1, as folhas dominam, Θ(n^(log₂ 4)) = Θ(n²), e o
total é `2n² - n` (quadruplica). A leitura no topo é a mesma nos três
escritórios; em `n = 1024`, o total difere por um fator de mil.

O fluxograma é o teorema como receita. Primeiro vem a pergunta que ninguém
pode pular (a recorrência tem a forma certa?), depois a comparação de `a`
com `b^k`. O caminho marcado é o de `a = 2`:

<p align="center"><img src="17-analise-avancada/0115-teorema-mestre/fluxograma.svg" alt="Fluxograma: Teorema mestre" width="963"></p>

A mesma receita resolve os algoritmos que você já conhece:

| algoritmo | a | b | k | b^k | resultado |
| --- | --- | --- | --- | --- | --- |
| busca binária | 1 | 2 | 0 | 1 | caso 2: Θ(log n) |
| máximo dividindo ao meio | 2 | 2 | 0 | 1 | caso 1: Θ(n) |
| merge sort | 2 | 2 | 1 | 2 | caso 2: Θ(n log n) |
| multiplicar polinômios com 3 produtos (Karatsuba) | 3 | 2 | 1 | 2 | caso 1: Θ(n^1,585) |
| algo que lê tudo e segue numa metade | 1 | 2 | 1 | 2 | caso 3: Θ(n) |

E quando o teorema **não** se aplica? Quando a recorrência não tem a forma
`a T(n/b) + n^k`: `T(n) = T(n-1) + n` (o tamanho cai **subtraindo**, não
dividindo), `T(n) = T(n/3) + T(2n/3) + n` (pedaços de tamanhos diferentes),
`T(n) = 2 T(n/2) + n log n` (o trabalho fica no meio do caminho entre `n^1`
e `n^(1+algo)`; a forma do Cormen, na nota abaixo, ainda pega este). Aí
você volta para a árvore de recursão, que sempre funciona. O exemplo A230
resolve dois desses casos.

> [!NOTE]
> **No Cormen (4ª ed.)** a forma é `T(n) = a T(n/b) + f(n)`, e `f(n)` é
> comparada com `n^(log_b a)`. Caso 1: `f(n) = O(n^(log_b a - ε))` para algum
> ε > 0 dá Θ(n^(log_b a)). Caso 2: `f(n) = Θ(n^(log_b a) · logᵖ n)` com p ≥ 0
> (ele chama o p de k) dá Θ(n^(log_b a) · log^(p+1) n). Caso 3:
> `f(n) = Ω(n^(log_b a + ε))` **e** a regularidade `a f(n/b) ≤ c f(n)` para
> algum c < 1 dão Θ(f(n)). A tabela acima é o caso `f(n) = nᵏ`. Com p = 1,
> `2 T(n/2) + n log n` dá Θ(n log² n), o que o A230 mede.

> [!WARNING]
> `a` e `b` são coisas diferentes e não precisam ser iguais. `a` conta as
> chamadas; `b` diz quanto cada uma encolhe. Os quatro estagiários do exemplo
> recebem metade cada um, então é `4 T(n/2)`, e não `4 T(n/4)`: as metades se
> sobrepõem, e por isso o custo explode. O erro mais comum é aplicar o
> teorema em `T(n) = 2 T(n-1) + 1` (Hanói). Ali não existe `b`,
> porque `n - 1` não é `n` dividido por nada. Quem força `b = 1` chega num
> absurdo; o certo é a árvore, que dá Θ(2ⁿ).

> [!TIP]
> **Por dentro do C:** o `n / 2` do código é divisão inteira. Com `n` ímpar,
> as metades de um merge sort ficam com `⌊n/2⌋` e `⌈n/2⌉` elementos, e o
> teorema continua valendo: arredondar para cima ou para baixo não muda o
> Θ. O que muda tudo é o **caso base**. Se a função pode receber `n = 0`
> (um vetor vazio, um `n / 2` a partir de `n = 1`), um teste `if (n == 1)`
> deixa passar o zero, `0 / 2` dá 0 de novo, e a recursão nunca termina: a
> pilha estoura. Por isso o caso base mais seguro é `if (n <= 1)`.

> [!NOTE]
> **Pergunta para você:** e com `a = 3`? Antes de mudar o laço do `main`
> para `a = 1, 2, 3, 4`, diga em que linha da tabela o 3 cai e por quanto o
> total deve multiplicar quando `n` dobra. Uma pista: `log₂ 3 ≈ 1,585` e
> `2^1,585 = 3`.

### Hora de praticar

Arquivos em [`0115-teorema-mestre/`](17-analise-avancada/0115-teorema-mestre/).

**Exemplo A229 · A tabela do teorema mestre em código**

```c
#include <math.h>
#include <stdio.h>

typedef struct {
    const char *nome;
    int a, b, k; // T(n) = a T(n/b) + n^k
} Recorrencia;

// b^k com inteiros: comparar a com b^k sem passar por double
long potencia(int b, int k) {
    long p = 1;
    for (int i = 0; i < k; i++) {
        p *= b;
    }
    return p;
}

// escreve n^k de um jeito legível em s: "1", "n", "n^2"...
void texto_nk(char s[], int tam, int k) {
    if (k == 0) {
        snprintf(s, tam, "1");
    } else if (k == 1) {
        snprintf(s, tam, "n");
    } else {
        snprintf(s, tam, "n^%d", k);
    }
}

void classifica(Recorrencia r) {
    char nk[8];
    texto_nk(nk, sizeof nk, r.k);
    printf("%d T(n/%d) + %-3s -> ", r.a, r.b, nk);

    long bk = potencia(r.b, r.k);
    if (r.a > bk) {
        double e = log(r.a) / log(r.b);  // log_b a, em double
        if (fabs(e - round(e)) < 1e-9) {
            printf("folhas: Θ(n^%.0f)", e); // expoente inteiro (com tolerância)
        } else {
            printf("folhas: Θ(n^%.3f)", e);
        }
    } else if (r.a == bk) {
        if (r.k == 0) {
            printf("empate: Θ(log n)");     // n^0 log n = log n
        } else {
            printf("empate: Θ(%s log n)", nk);
        }
    } else {
        printf("raiz: Θ(%s)", nk);
    }
    printf("   [%s]\n", r.nome);
}

int main(void) {
    Recorrencia lista[] = {
        {"busca binária", 1, 2, 0},
        {"busca em 3 partes", 1, 3, 0},
        {"máximo pelas metades", 2, 2, 0},
        {"merge sort", 2, 2, 1},
        {"Karatsuba", 3, 2, 1},
        {"matriz por blocos", 8, 2, 2},
        {"Strassen", 7, 2, 2},
        {"lê tudo e segue numa metade", 1, 2, 1},
        {"3 terços e trabalho n²", 3, 3, 2},
    };
    int total = sizeof lista / sizeof lista[0];
    for (int i = 0; i < total; i++) {
        classifica(lista[i]);
    }
    return 0;
}
// Saída:
// 1 T(n/2) + 1   -> empate: Θ(log n)   [busca binária]
// 1 T(n/3) + 1   -> empate: Θ(log n)   [busca em 3 partes]
// 2 T(n/2) + 1   -> folhas: Θ(n^1)   [máximo pelas metades]
// 2 T(n/2) + n   -> empate: Θ(n log n)   [merge sort]
// 3 T(n/2) + n   -> folhas: Θ(n^1.585)   [Karatsuba]
// 8 T(n/2) + n^2 -> folhas: Θ(n^3)   [matriz por blocos]
// 7 T(n/2) + n^2 -> folhas: Θ(n^2.807)   [Strassen]
// 1 T(n/2) + n   -> raiz: Θ(n)   [lê tudo e segue numa metade]
// 3 T(n/3) + n^2 -> raiz: Θ(n^2)   [3 terços e trabalho n²]
```

```bash
~/LPEDC/rodar 17-analise-avancada/0115-teorema-mestre/A229.c
```

**Exemplo A230 · Quando a tabela não serve: medindo na mão**

```c
#include <stdio.h>

// log2 inteiro: quantas vezes dá para dividir n por 2
int lg(long n) {
    int k = 0;
    while (n > 1) {
        n /= 2;
        k++;
    }
    return k;
}

// T(n) = 2 T(n/2) + n log n: o trabalho fica entre n e n^(1+algo)
long t_nlogn(long n) {
    if (n <= 1) {
        return 1;
    }
    return 2 * t_nlogn(n / 2) + n * lg(n);
}

// T(n) = T(n/3) + T(2n/3) + n: pedaços de tamanhos diferentes
long t_desigual(long n) {
    if (n <= 1) {
        return 1;
    }
    return t_desigual(n / 3) + t_desigual(2 * n / 3) + n;
}

// T(n) = T(n-1) + n: o tamanho cai subtraindo (calculado com laço)
long t_subtrai(long n) {
    long t = 1; // T(1)
    for (long i = 2; i <= n; i++) {
        t += i;
    }
    return t;
}

int main(void) {
    // se T/(n lg n) cresce sem parar, não é n log n; se T/(n lg² n) para
    // perto de uma constante, é Θ(n log² n)
    printf("2 T(n/2) + n log n:\n");
    printf("      n  T/(n lg n)  T/(n lg² n)\n");
    for (long n = 1024; n <= 1048576; n *= 32) {
        double t = t_nlogn(n);
        int l = lg(n);
        printf("%7ld %10.2f %11.3f\n", n, t / ((double)n * l), t / ((double)n * l * l));
    }

    // todo nível custa no máximo n, e são uns log n níveis: Θ(n log n)
    printf("\nT(n/3) + T(2n/3) + n:\n");
    printf("      n  T/(n lg n)\n");
    for (long n = 1024; n <= 1048576; n *= 32) {
        printf("%7ld %10.2f\n", n, t_desigual(n) / ((double)n * lg(n)));
    }

    // dobrar n quadruplica o total: Θ(n²), nada a ver com o "a = 1"
    printf("\nT(n-1) + n, dobrando n:\n");
    for (long n = 1000; n <= 8000; n *= 2) {
        printf("T(%ld) / T(%ld) = %.2f\n", 2 * n, n, (double)t_subtrai(2 * n) / t_subtrai(n));
    }
    return 0;
}
// Saída:
// 2 T(n/2) + n log n:
//       n  T/(n lg n)  T/(n lg² n)
//    1024       5.60       0.560
//   32768       8.07       0.538
// 1048576      10.55       0.527
//
// T(n/3) + T(2n/3) + n:
//       n  T/(n lg n)
//    1024       1.05
//   32768       1.06
// 1048576       1.07
//
// T(n-1) + n, dobrando n:
// T(2000) / T(1000) = 4.00
// T(4000) / T(2000) = 4.00
// T(8000) / T(4000) = 4.00
// T(16000) / T(8000) = 4.00
```

```bash
~/LPEDC/rodar 17-analise-avancada/0115-teorema-mestre/A230.c
```

#### Exercícios

**Exercício E685** · ★☆☆

Complete a função caso(a, b, k): ela recebe uma recorrência
T(n) = a T(n/b) + n^k e devolve o número do caso do teorema mestre
(1 se a > b^k, 2 se a = b^k, 3 se a < b^k). Calcule b^k com inteiros,
numa função potencia(b, k) com um laço. O main já testa sete
recorrências:


```text
Saída esperada:
 2 T(n/2) + n^1 -> caso 2, empate: Θ(n^k log n)
 4 T(n/2) + n^1 -> caso 1, folhas: Θ(n^(log_b a))
 1 T(n/2) + n^1 -> caso 3, raiz: Θ(n^k)
 9 T(n/3) + n^2 -> caso 2, empate: Θ(n^k log n)
 5 T(n/4) + n^1 -> caso 1, folhas: Θ(n^(log_b a))
 2 T(n/4) + n^1 -> caso 3, raiz: Θ(n^k)
16 T(n/4) + n^2 -> caso 2, empate: Θ(n^k log n)
```

**Dicas:**

1. potencia(b, k) começa com p = 1 e multiplica por b, k vezes. Use long.
2. Depois são dois if: a > bk devolve 1; a == bk devolve 2; senão, 3.
3. Resposta esperada: a saída acima. Repare no 9 T(n/3) + n²: 9 = 3²,
   então é empate, Θ(n² log n).

```bash
~/LPEDC/rodar 17-analise-avancada/0115-teorema-mestre/E685.c
```

**Exercício E686** · ★☆☆

A função trabalho(n) abaixo segue T(n) = 3 T(n/2) + n. Pelo teorema
(a = 3 > b^k = 2, caso 1), T(n) = Θ(n^(log₂ 3)) = Θ(n^1,585): quando n
dobra, o total deve ser multiplicado por 2^1,585 = 3. Confira no
computador: complete o main para mostrar T(n) e a razão T(n) / T(n/2)
para n = 64, 128, ..., 4096:


```text
Saída esperada:
    n     T(n)  T(n)/T(n/2)
   64     2059    3.096
  128     6305    3.062
  256    19171    3.041
  512    58025    3.027
 1024   175099    3.018
 2048   527345    3.012
 4096  1586131    3.008
```

**Dicas:**

1. Guarde o valor anterior numa variável: comece com anterior =
   trabalho(32) e, a cada volta, atualize anterior = t.
2. A divisão precisa de um cast: (double)t / anterior.
3. Resposta esperada: a tabela acima. A razão começa um pouco acima de 3
   (o "+ n" ainda pesa com n pequeno) e vai chegando em 3.

```bash
~/LPEDC/rodar 17-analise-avancada/0115-teorema-mestre/E686.c
```

**Exercício E687** · ★★☆

As 1024 notas de um concurso (de 0 a 10) estão em ordem crescente. A
função conta_lento conta quantas notas 7 existem dividindo o vetor ao
meio, mas olha SEMPRE as duas metades: T(n) = 2 T(n/2) + 1, caso 1 do
teorema, Θ(n). Ela não aproveita que o vetor está ordenado.

Escreva primeira(v, ini, fim, x), recursiva, que devolve a primeira
posição de v[ini..fim-1] com valor >= x (ou fim, se não houver),
seguindo só UMA metade a cada chamada: T(n) = T(n/2) + 1, caso 2,
Θ(log n). Conte as chamadas no mesmo contador global. As notas 7 são as
que ficam entre primeira(..., 7) e primeira(..., 8):


```text
Saída esperada:
lento:  93 notas 7 em 2047 chamadas
rápido: 93 notas 7 em 22 chamadas
```

**Dicas:**

1. Caso base: com ini == fim, o pedaço está vazio; devolva ini.
2. Se v[meio] < x, a resposta está à direita: [meio + 1, fim). Senão,
   o próprio meio pode ser a resposta: [ini, meio).
3. Quantidade = primeira(notas, 0, 1024, 8) - primeira(notas, 0, 1024, 7).
4. Resposta esperada: a saída acima (11 chamadas em cada busca). Com um
   milhão de notas, o lento faria 2 milhões de chamadas; o rápido, uns 42.

```bash
~/LPEDC/rodar 17-analise-avancada/0115-teorema-mestre/E687.c
```

**Exercício E688** · ★★☆

Se dividir ao meio dá log₂ n, dividir em três não seria melhor? Teste.
Escreva duas buscas RECURSIVAS num vetor ordenado v[0..N-1] com os
números pares 0, 2, 4, ..., contando cada comparação com um elemento do
vetor (cada == , < ou > com v[...]):

- binaria(ini, fim, x): compara x == v[meio]; depois x < v[meio] e segue
numa metade. T(n) = T(n/2) + 2.
- ternaria(ini, fim, x): com terco = (fim - ini) / 3, m1 = ini + terco e
m2 = fim - 1 - terco, compara x == v[m1], x == v[m2], x < v[m1] e
x > v[m2], e segue num dos três pedaços. T(n) = T(n/3) + 4.

Pelo teorema, as duas são caso 2, Θ(log n). Mas a constante importa.
Faça 1000 buscas por números ÍMPARES (que não estão no vetor), com
x = 2 * ((i * 7919) % N) + 1 para i de 0 a 999, e mostre a média:


```text
Saída esperada:
binária: 39.9 comparações por busca
ternária: 47.3 comparações por busca
```

**Dicas:**

1. Use intervalo semiaberto [ini, fim): o pedaço vazio (ini >= fim)
   devolve -1. Os três pedaços da ternária são [ini, m1), [m1 + 1, m2) e
   [m2 + 1, fim).
2. (long)i * 7919 evita estouro? Aqui não estoura, mas é bom hábito.
3. Por que perde? A binária gasta 2 comparações para dividir por 2
   (2 · log₂ n ≈ 40). A ternária gasta até 4 para dividir por 3
   (4 · log₃ n ≈ 4 · 12,6 ≈ 50; um pouco menos, porque às vezes para
   na terceira). Θ igual não quer dizer tempo igual.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 17-analise-avancada/0115-teorema-mestre/E688.c
```

**Exercício E689** · ★★★

Multiplicar dois polinômios de n coeficientes (n potência de 2) dividindo
cada um em duas metades, a(x) = a0 + a1·x^h e b(x) = b0 + b1·x^h, com
h = n/2, pede os produtos a0·b0, a0·b1, a1·b0 e a1·b1. A função
multiplica4 faz isso: T(n) = 4 T(n/2) + n, caso 1, Θ(n²) multiplicações.

O truque de Karatsuba precisa de só TRÊS produtos:


```text
p0 = a0·b0     p2 = a1·b1     p1 = (a0 + a1)·(b0 + b1) - p0 - p2
```


e o resultado é p0 + p1·x^h + p2·x^(2h). Agora T(n) = 3 T(n/2) + n:
ainda caso 1, mas Θ(n^(log₂ 3)) = Θ(n^1,585). Escreva multiplica3 e rode:


```text
Saída esperada:
4 produtos: 5 16 34 60 61 52 32  (16 multiplicações)
3 produtos: 5 16 34 60 61 52 32  (9 multiplicações)
n =  64:   4096 contra   729 multiplicações, mesmo resultado
n = 128:  16384 contra  2187 multiplicações, mesmo resultado
n = 256:  65536 contra  6561 multiplicações, mesmo resultado
```

**Dicas:**

1. Copie a estrutura de multiplica4: caso base n == 1 (conta 1
   multiplicação) e, no caso geral, um bloco de rascunho com malloc.
2. O rascunho precisa de 3 produtos de 2h - 1 coeficientes e das somas
   sa = a0 + a1 e sb = b0 + b1, de h coeficientes cada.
3. Monte o resultado como em multiplica4: r[i] += p0[i];
   r[i + h] += p1[i]; r[i + 2h] += p2[i]. Não esqueça do free.
4. Resposta esperada: a saída acima. 16 = 4², 729 = 3⁶, 6561 = 3⁸: com
   n = 2^j, são 4^j contra 3^j multiplicações.

```bash
~/LPEDC/rodar 17-analise-avancada/0115-teorema-mestre/E689.c
```

**Exercício E690** · ★★★

Ache o bug. Este classificador do teorema mestre calcula o expoente
c = log_b a com double e compara com k. Ele acerta quase tudo, mas erra
três das sete recorrências do teste:


```text
Saída que aparece:
   2 T(n/2)  + n^1 -> empate
   4 T(n/2)  + n^1 -> folhas
   1 T(n/2)  + n^1 -> raiz
 125 T(n/5)  + n^3 -> folhas
1000 T(n/10) + n^3 -> raiz
 216 T(n/6)  + n^3 -> folhas
   8 T(n/2)  + n^3 -> empate
```



```text
Saída esperada:
   2 T(n/2)  + n^1 -> empate
   4 T(n/2)  + n^1 -> folhas
   1 T(n/2)  + n^1 -> raiz
 125 T(n/5)  + n^3 -> empate
1000 T(n/10) + n^3 -> empate
 216 T(n/6)  + n^3 -> empate
   8 T(n/2)  + n^3 -> empate
```


Descubra por que (mostre c com %.17g para conferir) e conserte a função
para que ela nunca dependa da precisão do double.

**Dicas:**

1. 125 = 5³, 1000 = 10³ e 216 = 6³: nos três, log_b a deveria ser 3
   exatamente. O que o printf com %.17g mostra?
2. log(125) / log(5) dá 3.0000000000000004. Os logaritmos são
   arredondados para caber no double, e o == entre doubles quase nunca
   é o que você quer.
3. O conserto mais limpo nem usa log: compare a com b^k, calculado com
   inteiros num laço. a > b^k é folhas; a == b^k, empate; senão, raiz.
   (Outra saída, pior: considerar iguais se fabs(c - k) < 1e-9.)
4. Resposta esperada: a saída esperada acima.

```bash
~/LPEDC/rodar 17-analise-avancada/0115-teorema-mestre/E690.c
```

---

## 0116 · Análise amortizada

Uma família mora num apartamento de um quarto. Nasce o primeiro filho: muda
para um de dois quartos. Depois para um de quatro. Cada mudança é um dia
inteiro carregando **todos** os móveis, mas é rara: entre uma e outra, a
vida segue barata. Ninguém mede o custo de morar pela pior semana do ano.

O vetor que cresce do assunto 0075 vive a mesma coisa. Inserir no fim custa
uma escrita, até o dia em que o vetor enche: aí é preciso alocar um maior e
**copiar tudo**. Olhando uma operação isolada, o pior caso de uma inserção é
O(n). Multiplicando por `n` inserções, dá O(n²). A conta está certa, mas
pessimista: as inserções caras não acontecem uma atrás da outra.

A **análise amortizada** mede o custo de uma **sequência** de operações, no
pior caso, e divide pelo número de operações. O resultado é o **custo
amortizado** por operação: uma garantia sobre o total, sem sorteio nenhum.

O jeito mais direto é o **método agregado**: somar tudo. Com capacidade
inicial 1 e dobrando quando enche, `n` inserções fazem `n` escritas mais as
cópias das mudanças: `1 + 2 + 4 + ... + (a última potência de 2 menor que
n)`. Essa soma é sempre menor que `2n`. O total fica abaixo de `3n`: **O(1)
amortizado** por inserção.

O outro jeito é o **método do banqueiro** (ou contábil). Cada inserção paga
um preço fixo, digamos **3 moedas**: 1 paga a própria escrita e 2 vão para
um cofrinho. Quando o vetor de capacidade `c` enche e vira `2c`, metade dos
`c` elementos chegou depois da última mudança, e cada um guardou 2 moedas:
são `c` moedas, exatamente as `c` cópias. Se o cofrinho **nunca fica
negativo**, o preço fixo cobre o custo real, e o custo amortizado é 3.
O Cormen chama este de **método contábil** e traz um terceiro, o do
**potencial**: o cofrinho vira uma função Φ do estado da estrutura. Com
Φ = 2 · n - capacidade, cada inserção custa, amortizada, os mesmos 3.

O app do banco guarda o histórico de Pix num vetor que
começa com 1 posição e dobra quando enche. Chegam 16 Pix. As inserções 2, 3,
5 e 9 são as mudanças, em vermelho; o cofrinho embaixo cai nelas e se
recupera depois:

<p align="center"><img src="17-analise-avancada/0116-amortizada/ideia.svg" alt="Diagrama da ideia: Análise amortizada" width="870"></p>

O `insere` devolve o custo real de cada inserção. O vetor cresce com
`malloc`, cópia e `free` feitos à mão, para dar para contar cada cópia:

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *dados;
    int n;   // quantos tem
    int cap; // quantos cabem
} Vetor;

// insere no fim e devolve o custo: 1 escrita + as cópias, se precisou crescer
int insere(Vetor *v, int valor) {
    int custo = 1;
    if (v->n == v->cap) {
        int nova = v->cap * 2;                       // dobra
        int *maior = malloc(nova * sizeof *maior);
        if (maior == NULL) {
            exit(1);
        }
        for (int i = 0; i < v->n; i++) {
            maior[i] = v->dados[i];                  // a mudança: copia tudo
            custo++;
        }
        free(v->dados);
        v->dados = maior;
        v->cap = nova;
    }
    v->dados[v->n++] = valor;
    return custo;
}

int main(void) {
    Vetor v = {malloc(sizeof(int)), 0, 1};
    if (v.dados == NULL) {
        return 1;
    }
    int total = 0, cofrinho = 0;
    printf("Pix  custo  cofrinho\n");
    for (int i = 1; i <= 16; i++) {
        int custo = insere(&v, 100 * i);             // valor do Pix, tanto faz
        total += custo;
        cofrinho += 3 - custo;                       // cada inserção paga 3
        printf("%3d  %5d  %8d\n", i, custo, cofrinho);
    }
    printf("total: %d para 16 inserções (%.2f por inserção)\n", total, total / 16.0);
    free(v.dados);
    return 0;
}
// Saída:
// Pix  custo  cofrinho
//   1      1         2
//   2      2         3
//   3      3         3
//   4      1         5
//   5      5         3
//   6      1         5
//   7      1         7
//   8      1         9
//   9      9         3
//  10      1         5
//  11      1         7
//  12      1         9
//  13      1        11
//  14      1        13
//  15      1        15
//  16      1        17
// total: 31 para 16 inserções (1.94 por inserção)
```

As cópias somam `1 + 2 + 4 + 8 = 15`, mais 16 escritas: 31, menos de `2 · 16`.
O cofrinho desce até 3 em cada mudança e nunca chega a zero. As duas contas
dizem a mesma coisa: em média, menos de 2 por inserção, e nunca mais de 3.

O fluxograma segue o `insere` da 9ª inserção, a mais cara das 16. O vetor
tem 8 de 8 ocupados, então o caminho passa pela mudança inteira:

<p align="center"><img src="17-analise-avancada/0116-amortizada/fluxograma.svg" alt="Fluxograma: Análise amortizada" width="378"></p>

A mesma análise aparece num
**contador binário** (somar 1 às vezes vira muitos bits, mas em média vira
menos de 2; exemplo A231) e numa **pilha com `multipop(k)`**, que tira até
`k` itens de uma vez (cada item só sai uma vez depois de entrar; exemplo
A232). Nos três, o argumento é o mesmo: a operação cara "gasta" um trabalho
que as baratas acumularam antes.

Duas confusões comuns. Amortizado **não** é caso médio: o caso médio supõe
entradas sorteadas, e o amortizado vale para a **pior** sequência possível.
E amortizado **não** garante que cada operação é rápida: a 1.048.577ª
inserção copia mais de um milhão de elementos de uma vez. Para quem conta o
total, tanto faz; um sistema que não pode travar nem por um instante precisa
de outra solução.

> [!WARNING]
> Crescer de um **tamanho fixo** em vez de multiplicar estraga tudo. Com
> `nova = cap + 10`, as mudanças acontecem a cada 10 inserções e copiam 10,
> 20, 30... elementos: para 100.000 inserções, quase **500 milhões** de
> cópias, contra 131.071 dobrando. A soma `10 + 20 + ... ` é uma progressão
> aritmética, Θ(n²) no total: O(n) amortizado por inserção. Qualquer fator
> multiplicativo maior que 1 (1,5 ou 2) dá O(1) amortizado; somar uma
> constante, por maior que seja, não dá.

> [!TIP]
> **Por dentro do C:** na prática você usa `realloc` (assunto 0055), e às
> vezes ele nem copia: se o espaço logo depois do bloco estiver livre, ele
> estica o bloco no lugar. Isso não é garantido, e a análise conta o
> pior caso: copiar tudo. O preço do O(1) amortizado é memória: logo depois
> de dobrar, metade do vetor está vazia. Com 1.048.577 inteiros, o vetor
> ocupa espaço para 2.097.152, 8 MB em vez de 4 MB. E lembre do `realloc`
> seguro: `int *novo = realloc(v, ...)` num ponteiro à parte, conferindo
> `NULL` antes de jogar fora o antigo.

> [!NOTE]
> **Pergunta para você:** e na volta? Suponha que o vetor também **encolhe
> pela metade** quando fica com metade das posições ocupadas. Com 16
> elementos e capacidade 16, o que acontece se o programa alternar "insere,
> remove, insere, remove..." mil vezes? Quantas cópias cada operação faz?

### Hora de praticar

Arquivos em [`0116-amortizada/`](17-analise-avancada/0116-amortizada/).

**Exemplo A231 · O contador binário da catraca**

```c
#include <stdio.h>

#define BITS 24

// soma 1 ao contador (bit 0 em b[0]) e devolve quantos bits mudaram
int incrementa(int b[]) {
    int i = 0, trocas = 0;
    while (i < BITS && b[i] == 1) {
        b[i] = 0;                 // o vai-um zera os 1 do fim
        trocas++;
        i++;
    }
    if (i < BITS) {
        b[i] = 1;                 // e acende o primeiro 0
        trocas++;
    }
    return trocas;
}

void mostra(const int b[], int bits) {
    for (int i = bits - 1; i >= 0; i--) {
        printf("%d", b[i]);
    }
}

int main(void) {
    int b[BITS] = {0};
    int total = 0;
    printf("passou  contador  bits trocados\n");
    for (int k = 1; k <= 16; k++) {
        int t = incrementa(b);
        total += t;
        printf("%6d     ", k);
        mostra(b, 5);
        printf("  %d\n", t);
    }
    printf("16 passageiros: %d trocas (pior caso de um incremento: 5)\n\n", total);

    // um milhão de passageiros: quanto cada bit trocou
    int c[BITS] = {0};
    long por_bit[BITS] = {0}, soma = 0;
    for (long k = 1; k <= 1000000; k++) {
        int antes[BITS];
        for (int i = 0; i < BITS; i++) {
            antes[i] = c[i];
        }
        soma += incrementa(c);
        for (int i = 0; i < BITS; i++) {
            if (c[i] != antes[i]) {
                por_bit[i]++;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        printf("bit %d trocou %ld vezes\n", i, por_bit[i]);
    }
    printf("...\n1000000 incrementos: %ld trocas (%.6f por incremento)\n", soma, soma / 1e6);
    return 0;
}
// Saída:
// passou  contador  bits trocados
//      1     00001  1
//      2     00010  2
//      3     00011  1
//      4     00100  3
//      5     00101  1
//      6     00110  2
//      7     00111  1
//      8     01000  4
//      9     01001  1
//     10     01010  2
//     11     01011  1
//     12     01100  3
//     13     01101  1
//     14     01110  2
//     15     01111  1
//     16     10000  5
// 16 passageiros: 31 trocas (pior caso de um incremento: 5)
//
// bit 0 trocou 1000000 vezes
// bit 1 trocou 500000 vezes
// bit 2 trocou 250000 vezes
// bit 3 trocou 125000 vezes
// ...
// 1000000 incrementos: 1999993 trocas (1.999993 por incremento)
```

```bash
~/LPEDC/rodar 17-analise-avancada/0116-amortizada/A231.c
```

**Exemplo A232 · Pilha de pratos com multipop**

```c
#include <stdio.h>

#define CAP 1000000

typedef struct {
    int v[CAP];
    int topo; // quantos pratos tem
} Pilha;

int empilha(Pilha *p, int prato) {
    p->v[p->topo++] = prato;
    return 1;                              // custo 1
}

// tira até k pratos de uma vez; custo = quantos saíram de verdade
int multipop(Pilha *p, int k) {
    int saiu = 0;
    while (saiu < k && p->topo > 0) {
        p->topo--;
        saiu++;
    }
    return saiu;
}

int main(void) {
    Pilha p = {.topo = 0};
    // o que acontece na cozinha: 'E' = chega um prato sujo, 'L' = a
    // lava-louças leva até k pratos
    char tipo[] = {'E', 'E', 'E', 'E', 'E', 'L', 'E', 'E', 'L', 'E', 'E', 'E', 'E', 'L', 'L'};
    int k[] = {0, 0, 0, 0, 0, 3, 0, 0, 10, 0, 0, 0, 0, 2, 5};
    int ops = sizeof tipo / sizeof tipo[0];

    int total = 0, empilhados = 0, prato = 0, maior_custo = 0;
    for (int i = 0; i < ops; i++) {
        int custo;
        if (tipo[i] == 'E') {
            custo = empilha(&p, ++prato);
            empilhados++;
        } else {
            custo = multipop(&p, k[i]);
            printf("lava até %2d: saíram %d, sobraram %d\n", k[i], custo, p.topo);
        }
        total += custo;
        if (custo > maior_custo) {
            maior_custo = custo;
        }
    }
    printf("%d operações, %d empilhamentos\n", ops, empilhados);
    printf("operação mais cara: %d; custo total: %d <= 2 × %d\n\n", maior_custo, total, empilhados);

    // um mês de cozinha: 1 milhão de operações; 1 em cada 50 é lavar, e a
    // lava-louças leva até (i / 50) % 120 pratos (de 0 a 119)
    p.topo = 0;
    long total_mes = 0, emp_mes = 0;
    int pior = 0;
    for (int i = 1; i <= 1000000; i++) {
        int custo = (i % 50 == 0) ? multipop(&p, (i / 50) % 120) : empilha(&p, i);
        if (i % 50 != 0) {
            emp_mes++;
        }
        total_mes += custo;
        if (custo > pior) {
            pior = custo;
        }
    }
    printf("mês: %ld empilhamentos, pior operação %d, total %ld <= %ld\n",
           emp_mes, pior, total_mes, 2 * emp_mes);
    return 0;
}
// Saída:
// lava até  3: saíram 3, sobraram 2
// lava até 10: saíram 4, sobraram 0
// lava até  2: saíram 2, sobraram 2
// lava até  5: saíram 2, sobraram 0
// 15 operações, 11 empilhamentos
// operação mais cara: 4; custo total: 22 <= 2 × 11
//
// mês: 980000 empilhamentos, pior operação 98, total 1959271 <= 1960000
```

```bash
~/LPEDC/rodar 17-analise-avancada/0116-amortizada/A232.c
```

#### Exercícios

**Exercício E691** · ★☆☆

O vetor abaixo começa com capacidade 1 e dobra quando enche. Acrescente
à struct um campo long copias, que o insere aumenta a cada elemento
copiado numa mudança. Depois troque o main: para n = 10, 100, 1000 e
1000000, crie um vetor novo, insira n números, mostre as cópias e a
média de cópias por inserção, e libere o vetor:


```text
Saída esperada:
      n    cópias  cópias/n
     10        15      1.50
    100       127      1.27
   1000      1023      1.02
1000000   1048575      1.05
```

**Dicas:**

1. Comece cada vetor com Vetor v = {malloc(sizeof(int)), 0, 1, 0};
   (confira o NULL) e copias = 0.
2. As cópias são 1 + 2 + 4 + ... até a última potência de 2 menor que
   n. Para n = 10: 1 + 2 + 4 + 8 = 15.
3. Resposta esperada: a tabela acima. A média nunca passa de 2: é o
   O(1) amortizado na prática.

```bash
~/LPEDC/rodar 17-analise-avancada/0116-amortizada/E691.c
```

**Exercício E692** · ★☆☆

Para comparar estratégias de crescimento, nem precisa alocar memória:
basta simular. Escreva duas funções que recebem o número de inserções n
e devolvem quantas cópias as mudanças fariam:

- copias_soma(n, passo): a capacidade começa em passo e, quando enche,
cresce somando passo (10, 20, 30...);
- copias_dobra(n): a capacidade começa em 1 e dobra quando enche.

Em cada inserção, se tam == cap, a mudança copia os tam elementos e a
capacidade cresce; depois tam aumenta. Mostre n = 1000, 10000, 100000
com passo 10:


```text
Saída esperada:
     n      soma 10     dobra
  1000        49500      1023
 10000      4995000     16383
100000    499950000    131071
```

**Dicas:**

1. As variáveis da simulação são só cap, tam e copias, todas long.
2. Multiplicar n por 10 multiplica as cópias do "soma 10" por 100: é a
   marca do Θ(n²) no total.
3. Resposta esperada: a tabela acima. Com +10, cada inserção custa em
   média n/20 cópias (O(n) amortizado); dobrando, menos de 2 (O(1)).

```bash
~/LPEDC/rodar 17-analise-avancada/0116-amortizada/E692.c
```

**Exercício E693** · ★★☆

Muitas bibliotecas crescem o vetor por 1,5 em vez de 2: gastam menos
memória sobrando. Mas continua O(1) amortizado? Estenda o programa:

- o insere passa a receber o fator como fração (num, den): a nova
capacidade é cap * num / den (3 e 2 para 1,5; 2 e 1 para 2);
- a struct ganha os campos copias (long) e mudancas (int);
- uma função testa(nome, num, den, n) cria um vetor com capacidade 1,
insere n números, mostra mudanças, cópias, cópias por inserção e a
sobra (cap - n) no fim, e libera tudo.

Rode com n = 1000000:


```text
Saída esperada:
fator  mudanças    cópias  cópias/n     sobra
x 1,5        34    2099753     2.10     49869
x 2          20    1048575     1.05     48576
```


Cuidado: com cap = 1, a conta 1 * 3 / 2 dá 1 em divisão inteira. O
vetor "cresce" para o mesmo tamanho, e a próxima escrita cai fora dele
(o AddressSanitizer do rodar acusa heap-buffer-overflow). Garanta que a
nova capacidade seja sempre maior que a antiga.

**Dicas:**

1. Calcule com long para não estourar: (int)((long)v->cap * num / den).
2. Se a conta não passar de cap, use cap + 1.
3. printf("%-6s %8d %10ld %8.2f %9d\n", ...) dá as colunas da saída.
4. Resposta esperada: a tabela acima. O fator 1,5 copia o dobro (cada
   elemento é copiado, em média, umas 2 vezes), mas continua O(1)
   amortizado. A sobra parecida aqui é coincidência deste n: no pior
   caso, o x 2 deixa metade vazia; o x 1,5, só um terço.

```bash
~/LPEDC/rodar 17-analise-avancada/0116-amortizada/E693.c
```

**Exercício E694** · ★★☆

O contador binário tem custo amortizado menor que 2 por incremento. E se
ele também puder DIMINUIR? Escreva:

- decrementa(b): subtrai 1 do contador e devolve quantos bits mudaram
(os 0 do fim viram 1, porque o empréstimo passa por eles, e o primeiro
1 vira 0);
- carrega(b, x): coloca o número x nos bits (b[i] é o bit i de x);
- um main que faz dois testes com um contador de 10 bits: 100
incrementos a partir de 0, e 100 operações alternando incrementa e
decrementa a partir de 511 (0111111111).


```text
Saída esperada:
100 incrementos a partir de 0: 197 trocas (1.97 por operação)
inc/dec alternados a partir de 511: 1000 trocas (10.00 por operação)
```

**Dicas:**

1. decrementa é o espelho de incrementa: troque os papéis de 0 e 1.
2. Em carrega, o bit i de x é (x >> i) & 1 (assunto 0065).
3. 511 + 1 = 512 = 1000000000: os 10 bits mudam. 512 - 1 volta a 511:
   os 10 mudam de novo. Cada operação custa 10, para sempre.
4. Resposta esperada: a saída acima. O argumento amortizado só vale
   para a sequência de operações que ele analisou. Com o decremento, o
   cofrinho que os incrementos baratos enchiam nunca chega a encher.

```bash
~/LPEDC/rodar 17-analise-avancada/0116-amortizada/E694.c
```

**Exercício E695** · ★★★

A gráfica do bairro só tem pilhas no sistema, mas precisa de uma FILA de
pedidos (o primeiro a chegar é o primeiro a sair). Monte a fila com duas
pilhas, entrada e saida:

- enfileira(x): empilha x na entrada;
- desenfileira(): se a saida estiver vazia, passa TODOS os itens da
entrada para a saida (um por um, desempilhando de uma e empilhando na
outra: isso inverte a ordem); depois desempilha da saida.

Conte as transferências num contador global. Faça desenfileira devolver
também o custo da operação (1 + transferências feitas nela), por um
ponteiro. Rode esta sequência: enfileira 1 a 5, atende 2, enfileira 6 e
7, atende 4, enfileira 8, atende 2. Depois, com as pilhas zeradas, faça
1 milhão de operações: na operação i (de 1 a 1000000), se i for múltiplo
de 3 e a fila não estiver vazia, atenda; senão, enfileire i.


```text
Saída esperada:
atendidos: 1 2 3 4 5 6 7 8
8 pedidos, 8 transferências
666667 enfileirados, 524286 transferências, pior atendimento: 262145
```

**Dicas:**

1. Pilhas de 1 milhão de int ocupam 4 MB cada: declare-as como
   variáveis globais, não dentro do main (a pilha de chamadas tem uns
   8 MB e estouraria).
2. Cada pedido é transferido no máximo UMA vez: entra na entrada, passa
   para a saida, sai. Por isso as transferências nunca passam do número
   de enfileirados, e cada operação custa O(1) amortizado.
3. O "pior atendimento" mostra o outro lado: uma única operação chegou a
   mover 262.144 pedidos de uma vez.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 17-analise-avancada/0116-amortizada/E695.c
```

**Exercício E696** · ★★★

Conserte o programa. O carrinho de compras do app guarda os itens num
vetor que dobra quando enche e, para não desperdiçar memória, encolhe
pela metade quando fica com metade das posições ocupadas. Parece justo,
mas olhe o que acontece quando o cliente põe e tira o mesmo item várias
vezes com o carrinho cheio:


```text
Saída que aparece:
16 inserções: 15 cópias (cap 16)
1000 operações alternadas: 16000 cópias (cap 16)
esvaziar: 15 cópias (cap 1)
```


Cada operação da fase do meio copia 16 elementos. Mude SÓ a regra de
encolher, para que o vetor encolha pela metade apenas quando ficar com
UM QUARTO da capacidade ocupada:


```text
Saída esperada:
16 inserções: 15 cópias (cap 16)
1000 operações alternadas: 16 cópias (cap 32)
esvaziar: 15 cópias (cap 1)
```

**Dicas:**

1. Siga à mão: com n = 16 e cap = 16, insere dobra para 32 (16 cópias);
   remove deixa n = 16 = 32 / 2 e encolhe para 16 (16 cópias). E de novo.
2. A operação cara precisa de "folga" dos dois lados. Depois de encolher
   de cap para cap/2 com n = cap/4, o vetor fica meio cheio: faltam cap/4
   inserções para dobrar e cap/8 remoções para encolher de novo.
3. Resposta esperada: a saída esperada acima. A condição vira
   v->n == v->cap / 4.

```bash
~/LPEDC/rodar 17-analise-avancada/0116-amortizada/E696.c
```

---

## 0117 · Limite inferior da ordenação

Na agência dos Correios chegaram três encomendas, A, B e C, e a única
ferramenta é uma balança de dois pratos. Ela não mostra quilos: só diz qual
lado é mais pesado. Você quer enfileirar as três da mais leve para a mais
pesada. Quantas pesagens são necessárias, no pior caso, com o **melhor**
método possível?

Até aqui, toda análise media **um algoritmo**: o merge sort faz tantas
comparações, o insertion sort faz tantas. A pergunta agora é sobre o
**problema**: existe algum jeito de ordenar com menos? Dá para responder
isso para todos os algoritmos de uma vez, inclusive os que ninguém inventou
ainda, desde que eles só aprendam sobre os dados **comparando** dois
elementos, como a balança. Esses são os algoritmos de
**ordenação por comparação**: todos os do módulo 13, o heapsort e o `qsort`.

A ferramenta é a **árvore de decisão**. Cada nó interno é uma pergunta
("A é mais pesada que B?"), cada aresta é uma resposta (sim ou não), e cada
folha é uma resposta final: a ordem das encomendas. Rodar o algoritmo numa
entrada é descer da raiz até uma folha. O número de comparações no pior caso
é a **altura** da árvore.

O argumento tem três passos:

1. Com 3 encomendas há `3! = 6` ordens possíveis, e cada uma precisa ter a
   sua folha: se duas entradas com ordens diferentes chegassem à mesma
   folha, o algoritmo daria a mesma resposta para as duas e erraria uma.
2. Cada pergunta tem 2 respostas, então uma árvore de altura `h` tem no
   máximo `2^h` folhas.
3. Logo `2^h ≥ 6`. Com `h = 2`, só cabem 4 folhas. Precisa de `h ≥ 3`.

Nenhum método, por mais esperto, ordena 3 encomendas com menos de 3
pesagens no pior caso. Para `n` elementos, o mesmo raciocínio dá
`2^h ≥ n!`, isto é, **`h ≥ log₂(n!)`**.

O desenho mostra o insertion sort de 3 elementos como árvore de decisão. O caminho em verde é o da entrada A = 5 kg, B = 9 kg e
C = 2 kg, que termina na folha C A B depois de 3 pesagens:

<p align="center"><img src="17-analise-avancada/0117-limite-inferior/ideia.svg" alt="Diagrama da ideia: Limite inferior da ordenação" width="884"></p>

O programa passa as 6 ordens possíveis pela balança. A função
`mais_pesada` é o único acesso do algoritmo aos pesos, e ela anota cada
pergunta:

```c
#include <stdio.h>

typedef struct {
    char nome;
    int peso; // kg
} Encomenda;

int pesagens = 0;

// a balança de dois pratos: x é mais pesada que y? (anota a pergunta)
int mais_pesada(Encomenda x, Encomenda y) {
    pesagens++;
    int resposta = x.peso > y.peso;
    printf("%c>%c? %s  ", x.nome, y.nome, resposta ? "sim" : "não");
    return resposta;
}

// insertion sort de 3 encomendas, do mais leve ao mais pesado, só com a balança
void ordena3(Encomenda e[]) {
    for (int i = 1; i < 3; i++) {
        Encomenda atual = e[i];
        int j = i - 1;
        while (j >= 0 && mais_pesada(e[j], atual)) {
            e[j + 1] = e[j];
            j--;
        }
        e[j + 1] = atual;
    }
}

int main(void) {
    // as 3! = 6 maneiras de os pesos 2, 5 e 9 kg chegarem como A, B e C
    int chegada[6][3] = {{2, 5, 9}, {2, 9, 5}, {5, 2, 9}, {5, 9, 2}, {9, 2, 5}, {9, 5, 2}};
    int pior = 0;
    for (int k = 0; k < 6; k++) {
        Encomenda e[3] = {{'A', chegada[k][0]}, {'B', chegada[k][1]}, {'C', chegada[k][2]}};
        printf("%d %d %d | ", chegada[k][0], chegada[k][1], chegada[k][2]);
        pesagens = 0;
        ordena3(e);
        printf("%s-> %c %c %c (%d)\n", pesagens == 2 ? "          " : "",  // alinha
               e[0].nome, e[1].nome, e[2].nome, pesagens);
        if (pesagens > pior) {
            pior = pesagens;
        }
    }
    printf("pior caso: %d pesagens\n", pior);
    return 0;
}
// Saída:
// 2 5 9 | A>B? não  B>C? não            -> A B C (2)
// 2 9 5 | A>B? não  B>C? sim  A>C? não  -> A C B (3)
// 5 2 9 | A>B? sim  A>C? não            -> B A C (2)
// 5 9 2 | A>B? não  B>C? sim  A>C? sim  -> C A B (3)
// 9 2 5 | A>B? sim  A>C? sim  B>C? não  -> B C A (3)
// 9 5 2 | A>B? sim  A>C? sim  B>C? sim  -> C B A (3)
// pior caso: 3 pesagens
```

Cada linha da saída é um caminho da raiz até uma folha, e as 6 folhas são
diferentes. Duas entradas param com 2 pesagens, mas o pior caso é 3, igual
ao limite. Para 3 elementos, o insertion sort é **ótimo**.

O fluxograma traz o argumento inteiro, sem algoritmo específico. Ele vale
para qualquer método que só compara:

<p align="center"><img src="17-analise-avancada/0117-limite-inferior/fluxograma.svg" alt="Fluxograma: Limite inferior da ordenação" width="442"></p>

E para `n` grande? `log₂(n!)` cresce como `n log₂ n` (um pouco menos: a
diferença é perto de `1,44 n`). A tabela compara o limite com o pior caso do
merge sort:

| n | n! | limite ⌈log₂ n!⌉ | merge sort (pior caso) |
| --- | --- | --- | --- |
| 3 | 6 | 3 | 3 |
| 4 | 24 | 5 | 5 |
| 5 | 120 | 7 | 8 |
| 10 | 3.628.800 | 22 | 25 |
| 1000 | (2.568 dígitos) | 8.530 | 8.977 |

O limite inferior se escreve com **Ω** (ômega): ordenar por comparação é
**Ω(n log n)** no pior caso. É o piso, o contrário do teto `O`. Como o merge
sort e o heapsort fazem O(n log n), eles encostam no piso: são
**assintoticamente ótimos**. Ninguém vai inventar uma ordenação por
comparação O(n) ou O(n log log n); dá para ganhar só na constante.

> [!WARNING]
> O limite fala do **pior caso** de **qualquer** algoritmo que só compara.
> Ele não diz que toda entrada custa `n log n`: o insertion sort ordena um
> vetor que já está em ordem com `n - 1` comparações. E não vale para quem
> não compara: o counting sort do módulo 18 usa o valor como **índice** de
> um vetor e ordena inteiros pequenos em O(n), sem contradição nenhuma. Ele
> também não vale para outros problemas: achar o **maior** de `n` elementos
> precisa só de `n - 1` comparações, e não de `n log n`.

> [!TIP]
> **Por dentro do C:** o `qsort` da biblioteca segue à risca o modelo de
> comparação. Ele recebe o vetor como `void *` e uma função `compara`, e nunca
> olha os bytes dos elementos por conta própria: tudo o que ele sabe sobre a
> ordem vem das respostas da sua função, uma de cada vez. Por isso nenhuma
> implementação de `qsort`, em nenhuma biblioteca, consegue fazer menos de
> `⌈log₂ n!⌉` chamadas à `compara` no pior caso. Ponha um contador dentro da
> sua função e confira: para `n = 1000`, ele passa de 8.530.

> [!NOTE]
> **Pergunta para você:** com 4 encomendas, quantas pesagens são o mínimo
> no pior caso? E o insertion sort de 4 elementos, quantas faz no pior caso?
> Ele ainda é ótimo?

### Hora de praticar

Arquivos em [`0117-limite-inferior/`](17-analise-avancada/0117-limite-inferior/).

**Exemplo A233 · Quem encosta no limite**

```c
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

long comparacoes = 0;

int menor(int a, int b) {
    comparacoes++;
    return a < b;
}

void insertion(int v[], int n) {
    for (int i = 1; i < n; i++) {
        int x = v[i], j = i - 1;
        while (j >= 0 && menor(x, v[j])) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = x;
    }
}

void merge_sort(int v[], int w[], int p, int r) {
    if (r - p < 2) {
        return;
    }
    int q = p + (r - p) / 2;
    merge_sort(v, w, p, q);
    merge_sort(v, w, q, r);
    int i = p, j = q, k = 0;
    while (i < q && j < r) {
        w[k++] = menor(v[j], v[i]) ? v[j++] : v[i++];
    }
    while (i < q) w[k++] = v[i++];
    while (j < r) w[k++] = v[j++];
    for (k = 0; k < r - p; k++) {
        v[p + k] = w[k];
    }
}

// gerador próprio (o mesmo resultado em qualquer computador)
unsigned semente = 2024;
int sorteia(void) {
    semente = semente * 1103515245u + 12345u;
    return (int)(semente >> 8);
}

// ⌈log2(n!)⌉ = ⌈log2 1 + log2 2 + ... + log2 n⌉
long limite(int n) {
    double soma = 0;
    for (int k = 2; k <= n; k++) {
        soma += log2(k);
    }
    return (long)ceil(soma);
}

int main(void) {
    printf("    n    limite  merge sort    insertion\n");
    for (int n = 10; n <= 10000; n *= 10) {
        int *a = malloc(n * sizeof *a), *b = malloc(n * sizeof *b), *w = malloc(n * sizeof *w);
        if (a == NULL || b == NULL || w == NULL) {
            return 1;
        }
        for (int i = 0; i < n; i++) {
            a[i] = b[i] = sorteia();       // a mesma entrada para os dois
        }
        comparacoes = 0;
        merge_sort(a, w, 0, n);
        long cm = comparacoes;
        comparacoes = 0;
        insertion(b, n);
        printf("%5d %9ld %11ld %12ld\n", n, limite(n), cm, comparacoes);
        free(a);
        free(b);
        free(w);
    }
    return 0;
}
// Saída:
//     n    limite  merge sort    insertion
//    10        22          25           32
//   100       525         545         2646
//  1000      8530        8701       250918
// 10000    118459      120518     24780962
```

```bash
~/LPEDC/rodar 17-analise-avancada/0117-limite-inferior/A233.c
```

**Exemplo A234 · O adversário que esconde a ordem**

```c
#include <stdbool.h>
#include <stdio.h>

#define N 4
#define ORDENS 24 // 4!

int pos[ORDENS][N]; // pos[o][x] = lugar da encomenda x na ordem o (0 = mais leve)
bool viva[ORDENS];  // a ordem o ainda combina com tudo que a balança disse?
int perguntas = 0;

// gera as 24 ordens com quatro laços (cada encomenda num lugar diferente)
void gera_ordens(void) {
    int o = 0;
    for (int a = 0; a < N; a++) {
        for (int b = 0; b < N; b++) {
            for (int c = 0; c < N; c++) {
                for (int d = 0; d < N; d++) {
                    if (a != b && a != c && a != d && b != c && b != d && c != d) {
                        pos[o][0] = a;
                        pos[o][1] = b;
                        pos[o][2] = c;
                        pos[o][3] = d;
                        viva[o++] = true;
                    }
                }
            }
        }
    }
}

int vivas(void) {
    int k = 0;
    for (int o = 0; o < ORDENS; o++) {
        k += viva[o];
    }
    return k;
}

// a balança desonesta: "x é mais leve que y?" Ela não tem pesos de verdade:
// responde o que mantém MAIS ordens possíveis, e descarta as outras
bool mais_leve(int x, int y) {
    int sim = 0, nao = 0;
    for (int o = 0; o < ORDENS; o++) {
        if (viva[o]) {
            if (pos[o][x] < pos[o][y]) {
                sim++;
            } else {
                nao++;
            }
        }
    }
    bool resposta = sim >= nao;
    for (int o = 0; o < ORDENS; o++) {
        if (viva[o] && (pos[o][x] < pos[o][y]) != resposta) {
            viva[o] = false;                 // contradiz a resposta: descarta
        }
    }
    perguntas++;
    printf("  %c mais leve que %c? %s (ordens possíveis: %d)\n", 'A' + x, 'A' + y, resposta ? "sim" : "não", vivas());
    return resposta;
}

void insertion(int e[]) {
    for (int i = 1; i < N; i++) {
        int x = e[i], j = i - 1;
        while (j >= 0 && mais_leve(x, e[j])) {
            e[j + 1] = e[j];
            j--;
        }
        e[j + 1] = x;
    }
}

// merge sort de 4: ordena os pares (A,B) e (C,D) e intercala
void merge4(int e[]) {
    int esq[2] = {e[0], e[1]}, dir[2] = {e[2], e[3]};
    if (mais_leve(esq[1], esq[0])) {
        int t = esq[0];
        esq[0] = esq[1];
        esq[1] = t;
    }
    if (mais_leve(dir[1], dir[0])) {
        int t = dir[0];
        dir[0] = dir[1];
        dir[1] = t;
    }
    int i = 0, j = 0, k = 0;
    while (i < 2 && j < 2) {
        e[k++] = mais_leve(dir[j], esq[i]) ? dir[j++] : esq[i++];
    }
    while (i < 2) e[k++] = esq[i++];
    while (j < 2) e[k++] = dir[j++];
}

void joga(const char *nome, void (*ordena)(int[])) {
    int e[N] = {0, 1, 2, 3};
    gera_ordens();
    perguntas = 0;
    printf("%s contra o adversário:\n", nome);
    ordena(e);
    printf("  ordem final: %c %c %c %c, depois de %d perguntas\n\n", 'A' + e[0], 'A' + e[1], 'A' + e[2], 'A' + e[3], perguntas);
}

int main(void) {
    joga("insertion sort", insertion);
    joga("merge sort", merge4);
    printf("cada resposta deixa pelo menos metade: 24, 12, 6, 3, 2, 1 -> 5 perguntas no mínimo\n");
    return 0;
}
// Saída:
// insertion sort contra o adversário:
//   B mais leve que A? sim (ordens possíveis: 12)
//   C mais leve que A? sim (ordens possíveis: 8)
//   C mais leve que B? sim (ordens possíveis: 4)
//   D mais leve que A? sim (ordens possíveis: 3)
//   D mais leve que B? sim (ordens possíveis: 2)
//   D mais leve que C? sim (ordens possíveis: 1)
//   ordem final: D C B A, depois de 6 perguntas
//
// merge sort contra o adversário:
//   B mais leve que A? sim (ordens possíveis: 12)
//   D mais leve que C? sim (ordens possíveis: 6)
//   D mais leve que B? sim (ordens possíveis: 3)
//   C mais leve que B? não (ordens possíveis: 2)
//   C mais leve que A? sim (ordens possíveis: 1)
//   ordem final: D B C A, depois de 5 perguntas
//
// cada resposta deixa pelo menos metade: 24, 12, 6, 3, 2, 1 -> 5 perguntas no mínimo
```

```bash
~/LPEDC/rodar 17-analise-avancada/0117-limite-inferior/A234.c
```

#### Exercícios

**Exercício E697** · ★☆☆

Escreva teto_log2(x): o menor h tal que 2^h >= x, calculado só com
inteiros (um laço que dobra uma variável até alcançar x). Use-a para
mostrar o limite inferior ⌈log₂ n!⌉ de comparações para ordenar n
elementos, com n de 1 a 20:


```text
Saída esperada:
 n                   n!  limite
 1                    1       0
 2                    2       1
 3                    6       3
 4                   24       5
 5                  120       7
 6                  720      10
...
12            479001600      29
...
20  2432902008176640000      62
```

**Dicas:**

1. 20! não cabe em int nem em long de 32 bits: use unsigned long long e
   %llu no printf.
2. teto_log2 começa com h = 0 e folhas = 1; enquanto folhas < x,
   dobra folhas e soma 1 em h.
3. Calcule o fatorial acumulando no próprio laço do main (fat *= n).
4. Resposta esperada: a tabela acima. Nas linhas que não aparecem, o
   limite é 13, 16, 19, 22 e 26 (n = 7 a 11) e 33, 37, 41, 45, 49, 53 e
   57 (n = 13 a 19). Por que inteiros? Com log2 em double, um valor que
   devia dar 3 exato pode sair 3.0000000000000004, e o teto erra por 1.

```bash
~/LPEDC/rodar 17-analise-avancada/0117-limite-inferior/E697.c
```

**Exercício E698** · ★☆☆

Com 4 elementos, o limite é ⌈log₂ 24⌉ = 5 comparações no pior caso. O
insertion sort chega lá? Teste nas 24 ordens possíveis de 4 preços
(10, 20, 30 e 40): gere as ordens com quatro laços aninhados (a, b, c, d
de 0 a 3, todos diferentes), monte v = {precos[a], precos[b], precos[c],
precos[d]}, ordene com o insertion sort abaixo contando as comparações e
mostre o melhor caso, o pior, em quantas ordens o pior acontece e a
média:


```text
Saída esperada:
24 ordens testadas
melhor: 3, pior: 6 (em 8 ordens), média: 4.92
limite inferior: 5
```

**Dicas:**

1. Para pular as combinações com índices repetidos, use continue quando
   a == b || a == c || ... (são 6 pares para testar).
2. Conte as comparações dentro de uma função maior(a, b) que soma 1 num
   contador global e devolve a > b; use-a no while do insertion.
3. Ao achar um pior novo, zere o contador de "quantas no pior".
4. Resposta esperada: a saída acima. O insertion de 4 não é ótimo: faz
   6 no pior caso, um a mais que o limite (o exercício E702 mostra um
   método com 5). A média 4,92 abaixo de 5 não contradiz nada: o limite
   é de pior caso.

```bash
~/LPEDC/rodar 17-analise-avancada/0117-limite-inferior/E698.c
```

**Exercício E699** · ★★☆

Para achar o mínimo E o máximo de n temperaturas, o jeito óbvio compara
cada uma com o mínimo e com o máximo: 2(n - 1) comparações. Dá para
fazer com bem menos. Complete pares(): ande de DOIS em dois; compare os
dois entre si (1 comparação), e só o menor do par disputa o mínimo e só
o maior disputa o máximo (mais 2). São 3 comparações para cada 2
elementos, em vez de 4. Use a função menor() para contar.


```text
Saída esperada:
10 dias: mín 18, máx 35 | ingênuo 18 comparações | pares 13
11 dias: mín 18, máx 35 | ingênuo 20 comparações | pares 15
```

**Dicas:**

1. O começo depende da paridade. Com n par, compare v[0] com v[1] para
   iniciar mínimo e máximo e comece os pares em i = 2. Com n ímpar, o
   v[0] sozinho é mínimo e máximo, e os pares começam em i = 1.
2. O laço é for (; i + 1 < n; i += 2), com a = v[i] e b = v[i + 1];
   troque a e b se b for menor.
3. Resposta esperada: a saída acima. São ⌈3n/2⌉ - 2 comparações, e dá
   para provar (com um argumento de adversário, como no exemplo A234)
   que nenhum método faz menos.

```bash
~/LPEDC/rodar 17-analise-avancada/0117-limite-inferior/E699.c
```

**Exercício E700** · ★★☆

O pior caso do merge sort tem a sua própria recorrência: as duas metades
têm ⌈n/2⌉ e ⌊n/2⌋ elementos, e intercalar n elementos custa no máximo
n - 1 comparações:


```text
W(1) = 0
W(n) = W(⌈n/2⌉) + W(⌊n/2⌋) + (n - 1)
```


Escreva pior_merge(n) recursiva, que é a própria recorrência (não
precisa ordenar nada), e teto_log2(x) com inteiros, como no E697. Mostre
para n de 1 a 16 o limite ⌈log₂ n!⌉, o pior caso do merge sort e o do
insertion sort, n(n - 1)/2:


```text
Saída esperada:
 n  limite  merge  insertion
 1       0      0          0
 2       1      1          1
 3       3      3          3
 4       5      5          6
 5       7      8         10
 6      10     11         15
...
12      29     33         66
...
16      45     49        120
```

**Dicas:**

1. Em C, ⌈n/2⌉ é (n + 1) / 2 e ⌊n/2⌋ é n / 2 (divisão inteira).
2. O fatorial cabe em unsigned long long até n = 20.
3. Resposta esperada: a tabela acima. O merge sort é ótimo até n = 4 e
   depois fica a poucas comparações do limite (4 a mais em n = 16). O
   insertion se afasta cada vez mais: Θ(n²) contra Θ(n log n).

```bash
~/LPEDC/rodar 17-analise-avancada/0117-limite-inferior/E700.c
```

**Exercício E701** · ★★★

Ache os bugs. A função podio() recebe os tempos (em segundos) de três
corredores e escreve em r[] os tempos do mais rápido para o mais lento.
Ela foi escrita como uma árvore de decisão "na mão": cada if é um nó, e
cada folha monta uma ordem. O limite é 3 comparações no pior caso, e uma
árvore bem feita para 3 elementos tem 6 folhas e altura 3.

O main testa as 6 ordens possíveis e mostra:


```text
Saída que aparece:
10 20 30 -> 10 20 30 (2 comparações) ok
10 30 20 -> 20 10 30 (3 comparações) ERRADO
20 10 30 -> 10 20 30 (3 comparações) ok
20 30 10 -> 10 20 30 (3 comparações) ok
30 10 20 -> 10 20 30 (4 comparações) ok
30 20 10 -> 10 20 30 (4 comparações) ok
pior caso: 4 comparações
```


Há dois problemas: uma folha monta a ordem errada, e um ramo faz uma
pergunta cuja resposta ele já sabe. Conserte os dois sem mudar a ideia
da função:


```text
Saída esperada:
10 20 30 -> 10 20 30 (2 comparações) ok
10 30 20 -> 10 20 30 (3 comparações) ok
20 10 30 -> 10 20 30 (2 comparações) ok
20 30 10 -> 10 20 30 (3 comparações) ok
30 10 20 -> 10 20 30 (3 comparações) ok
30 20 10 -> 10 20 30 (3 comparações) ok
pior caso: 3 comparações
```

**Dicas:**

1. Para a folha errada: siga a entrada 10 30 20 pela árvore. Quais
   respostas levam até a folha? O que elas dizem sobre x, y e z?
2. Para a pergunta repetida: no ramo do else de menor(x, y), o que você
   já sabe sobre x e y? Alguma pergunta ali tem resposta garantida?
3. Resposta esperada: a saída esperada acima. A folha do "x < y, y > z,
   x < z" é x z y; e, com tempos diferentes, o menor(y, x) dentro do
   else é sempre verdadeiro: pode sair.

```bash
~/LPEDC/rodar 17-analise-avancada/0117-limite-inferior/E701.c
```

**Exercício E702** · ★★★

O limite para 4 elementos é 5 comparações, e o insertion sort faz 6 no
pior caso (E698). Escreva ordena4(v), que ordena 4 valores com NO
MÁXIMO 5 comparações, todas pela função menor(). A estratégia:


```text
1. compare v[0] com v[1]: fica um par (menor1, maior1);
2. compare v[2] com v[3]: outro par (menor2, maior2);
3. o menor de menor1 e menor2 é o mínimo de todos;
4. o maior de maior1 e maior2 é o máximo de todos;
5. sobram dois elementos: compare os dois para pôr o meio em ordem.
```


O main já testa as 24 ordens possíveis:


```text
Saída esperada:
24 ordens testadas, 24 certas
pior caso: 5 comparações (limite: 5)
```

**Dicas:**

1. Copie os quatro valores para variáveis locais (lo1, hi1, lo2, hi2) e
   troque dentro de cada par quando precisar.
2. No passo 3, quem perde (o maior dos dois "menores") é um dos do meio.
   No passo 4, quem perde (o menor dos dois "maiores") é o outro.
3. No fim, escreva mínimo, meio, meio e máximo de volta em v[0..3].
4. Resposta esperada: a saída acima. Esse método atinge o limite: é
   ótimo. Para 5 elementos o limite é 7, e também existe um método com
   7 (bem mais chato de escrever).

```bash
~/LPEDC/rodar 17-analise-avancada/0117-limite-inferior/E702.c
```

---

## 0118 · Juntando tudo

A loja virtual vai mudar o relatório do fim do dia: em vez de 16 mil pedidos,
agora ele vai ordenar **1 milhão**. O programador testou com 16 mil e mediu
alguns milissegundos. A gerente pergunta: "e com 1 milhão, quanto tempo vai
levar?". Rodar para ver pode demorar meia hora. Dá para **prever** antes?

Dá, com o que veio neste módulo. A receita tem quatro passos:

1. **Conhecer a classe.** Pela recorrência ou pela contagem: o insertion
   sort é `T(n) = T(n-1) + n`, Θ(n²); o merge sort é `2 T(n/2) + n`,
   Θ(n log n) pelo teorema mestre; o heapsort faz `n` descidas de
   O(log n); o quick sort é Θ(n log n) em média. E o limite inferior diz que
   nenhum deles pode fazer menos de `log₂ n!` comparações no pior caso.
2. **Medir em dois tamanhos, um o dobro do outro.** Se a classe está certa,
   dobrar `n` multiplica o custo por 4 (n²) ou por um pouco mais de 2
   (n log n). Se a razão não bater, a análise ou o código têm problema.
3. **Extrapolar.** Do tamanho medido `n` para o tamanho `N`, o custo é
   multiplicado por `(N/n)²` na classe n², ou por `(N log N)/(n log n)` na
   classe n log n.
4. **Conferir**, quando der para rodar o tamanho grande.

Medir tem duas réguas. A **contagem de comparações** sai igual em qualquer
computador e é a que confere a teoria. O **tempo** (com `clock()`, de
`<time.h>`) é o que a gerente quer saber, mas muda de máquina para máquina e
até de uma execução para outra. O programa usa as duas.

As quatro ordenações ficam num TAD, `ordena.h` e `ordena.c`, na pasta do
assunto. Toda comparação passa por uma função `menor` escondida no `.c`, que
conta:

```c
void ord_insertion(int v[], int n); // Θ(n²) no caso médio e no pior
void ord_merge(int v[], int n);     // Θ(n log n) sempre; usa um rascunho de n
void ord_heap(int v[], int n);      // Θ(n log n) sempre; in-place
void ord_quick(int v[], int n);     // Θ(n log n) em média; pivô = o do meio

void ord_zera_contagem(void);
long ord_contagem(void);
int ord_confere(const int v[], int n);
```

Os pedidos são números sorteados com um gerador
próprio, para a entrada ser a mesma em qualquer máquina. Cada algoritmo
ordena 8 mil e 16 mil; da razão sai a confirmação da classe, e da medida de
16 mil sai a previsão para 1 milhão. Em verde, o que a previsão acertou; em
vermelho, o que nem dá para rodar:

<p align="center"><img src="17-analise-avancada/0118-juntando-tudo/ideia.svg" alt="Diagrama da ideia: Juntando tudo" width="858"></p>

O programa mede, prevê e confere. O `insertion` só ganha previsão: rodar de
verdade levaria quase meia hora:

```c
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ordena.h"

typedef struct {
    const char *nome;
    void (*ordena)(int[], int);
    int quadratico; // 1 se Θ(n²), 0 se Θ(n log n)
} Algoritmo;

// gerador próprio: a mesma entrada em qualquer computador
unsigned semente = 42;
int sorteia(void) {
    semente = semente * 1103515245u + 12345u;
    return (int)(semente >> 8) % 1000000;
}

// ordena uma cópia de original[0..n-1] e devolve o tempo em ms
double mede(Algoritmo a, const int original[], int v[], int n) {
    memcpy(v, original, n * sizeof *v);   // sempre a mesma entrada
    ord_zera_contagem();
    clock_t ini = clock();
    a.ordena(v, n);
    double ms = 1000.0 * (clock() - ini) / CLOCKS_PER_SEC;
    if (!ord_confere(v, n)) {
        printf("%s não ordenou!\n", a.nome);
    }
    return ms;
}

// quanto o custo cresce de n0 para n1, conforme a classe
double fator(int quadratico, double n0, double n1) {
    if (quadratico) {
        return (n1 / n0) * (n1 / n0);
    }
    return (n1 * log2(n1)) / (n0 * log2(n0));
}

int main(void) {
    Algoritmo algs[] = {
        {"insertion", ord_insertion, 1}, {"merge", ord_merge, 0},
        {"heap", ord_heap, 0},           {"quick", ord_quick, 0},
    };
    int n0 = 8000, n1 = 16000, grande = 1000000;
    int *original = malloc(grande * sizeof *original);
    int *v = malloc(grande * sizeof *v);
    if (original == NULL || v == NULL) {
        return 1;
    }
    for (int i = 0; i < grande; i++) {
        original[i] = sorteia();
    }

    for (int k = 0; k < 4; k++) {
        Algoritmo a = algs[k];
        double t0 = mede(a, original, v, n0);
        long c0 = ord_contagem();
        double t1 = mede(a, original, v, n1);
        long c1 = ord_contagem();
        printf("%s: %ld -> %ld comparações (x%.2f), %.1f -> %.1f ms\n",
               a.nome, c0, c1, (double)c1 / c0, t0, t1);

        double f = fator(a.quadratico, n1, grande);
        printf("  previsão para 1 milhão: %8.1f milhões de comparações, %7.2f s\n", c1 * f / 1e6, t1 * f / 1000);
        if (!a.quadratico) {                // o insertion levaria tempo demais
            double t = mede(a, original, v, grande);
            printf("  medido para 1 milhão:   %8.1f milhões de comparações, %7.2f s\n", ord_contagem() / 1e6, t / 1000);
        }
    }
    free(original);
    free(v);
    return 0;
}
// Saída (os tempos são de uma execução; na sua máquina serão outros, mas
// as comparações e as razões saem iguais):
// insertion: 16227286 -> 64831293 comparações (x4.00), 89.4 -> 421.3 ms
//   previsão para 1 milhão: 253247.2 milhões de comparações, 1645.73 s
// merge: 93744 -> 203390 comparações (x2.17), 1.6 -> 3.3 ms
//   previsão para 1 milhão:     18.1 milhões de comparações,    0.29 s
//   medido para 1 milhão:       18.7 milhões de comparações,    0.29 s
// heap: 182686 -> 397420 comparações (x2.18), 2.4 -> 5.3 ms
//   previsão para 1 milhão:     35.4 milhões de comparações,    0.47 s
//   medido para 1 milhão:       36.8 milhões de comparações,    0.53 s
// quick: 120347 -> 275805 comparações (x2.29), 1.3 -> 2.8 ms
//   previsão para 1 milhão:     24.6 milhões de comparações,    0.25 s
//   medido para 1 milhão:       25.0 milhões de comparações,    0.26 s
```

A saída tem três camadas. As **razões** confirmam as classes: ×4,00 no
insertion, ×2,17 a ×2,29 nos outros três. As **previsões** de comparações
ficaram a menos de 4% do medido: o modelo `n log n` ignora termos menores,
então erra um pouco para baixo. E o **tempo** do insertion para 1 milhão,
1.600 segundos, é uns 27 minutos, contra um terço de segundo do merge sort:
a mesma tarefa, mais de 5 mil vezes mais lenta.

O fluxograma aplica a receita a um algoritmo. O caminho marcado é o do merge
sort, que passa pela previsão e pela conferência:

<p align="center"><img src="17-analise-avancada/0118-juntando-tudo/fluxograma.svg" alt="Fluxograma: Juntando tudo" width="527"></p>

### Passo a passo

A previsão do merge sort, de `n = 16.000` para `N = 1.000.000`:

| passo | conta | valor |
| --- | --- | --- |
| fator n log n | (1.000.000 · log₂ 1.000.000) / (16.000 · log₂ 16.000) | 19.931.569 / 223.453 = 89,2 |
| comparações previstas | 203.390 · 89,2 | 18,1 milhões |
| comparações medidas | (rodando) | 18,7 milhões |
| fator n² (insertion) | (1.000.000 / 16.000)² | 62,5² = 3.906 |
| comparações previstas | 64.831.293 · 3.906 | 253 bilhões |

> [!WARNING]
> Na classe n log n, dobrar `n` **não** dá ×2 exato. De 8 mil para 16 mil, a
> conta é `2 · log₂ 16.000 / log₂ 8.000 = 2,15`, e quem espera ×2 acha que o
> algoritmo "está piorando". O contrário também engana: com `n` pequeno
> (algumas centenas), o tempo é dominado por constantes, chamadas de função e
> cache, e as razões saem malucas. Meça com tamanhos grandes o bastante para
> o tempo passar de alguns milissegundos, e sempre a partir da **mesma
> entrada**: o `memcpy` do `mede` restaura o vetor original antes de cada
> ordenação. Sem ele, o segundo algoritmo receberia o vetor já ordenado.

> [!TIP]
> **Por dentro do C:** `clock()` devolve o tempo de processador gasto pelo
> programa, em "tiques"; `CLOCKS_PER_SEC` diz quantos tiques há num segundo
> (no Linux, 1.000.000). As duas coisas são inteiras: escrever
> `(clock() - ini) / CLOCKS_PER_SEC` faz divisão inteira e dá **0** para
> tudo que dura menos de um segundo. Por isso o `1000.0 *` na frente, que
> converte para `double` antes de dividir. E lembre que o `rodar` compila sem
> otimização e com o AddressSanitizer, que vigia cada acesso à memória: os
> tempos aqui são várias vezes maiores que os de um `gcc -O2` sem
> sanitizador. As **razões** continuam valendo, e a previsão trabalha com
> elas.

> [!NOTE]
> **Pergunta para você:** o quick sort daqui usa o elemento do meio como
> pivô. Ele continuaria rápido se o vetor de entrada já estivesse em ordem?
> E se os 1 milhão de pedidos tivessem só 10 valores diferentes (as notas de
> 0 a 9 de uma avaliação)? Pense na partição antes de rodar o exemplo A235.

### Hora de praticar

Arquivos em [`0118-juntando-tudo/`](17-analise-avancada/0118-juntando-tudo/).

**Exemplo A235 · A entrada também decide: quatro vetores, quatro ordenações**

```c
#include <stdio.h>
#include <string.h>
#include "ordena.h"

#define N 2000

unsigned semente = 7;
int sorteia(void) {
    semente = semente * 1103515245u + 12345u;
    return (int)(semente >> 8);
}

// o Θ diz como o custo cresce com n; a entrada decide em que ponto da faixa
// cada algoritmo cai. Repare no insertion (1999 em ordem, 2 milhões ao
// contrário) e no quick com muitos repetidos: todos os iguais ao pivô vão
// para o mesmo lado da partição, e ele fica 8 vezes mais caro
int main(void) {
    const char *entradas[] = {"sorteado", "ordenado", "invertido", "10 valores"};
    const char *nomes[] = {"insertion", "merge", "heap", "quick"};
    void (*ordena[])(int[], int) = {ord_insertion, ord_merge, ord_heap, ord_quick};
    int base[4][N], v[N];
    for (int i = 0; i < N; i++) {
        base[0][i] = sorteia() % 100000;
        base[1][i] = i;                   // já em ordem
        base[2][i] = N - i;               // ao contrário
        base[3][i] = sorteia() % 10;      // muitos repetidos
    }

    printf("%-10s", "n = 2000");
    for (int a = 0; a < 4; a++) {
        printf(" %10s", nomes[a]);
    }
    printf("\n");
    for (int e = 0; e < 4; e++) {
        printf("%-10s", entradas[e]);
        for (int a = 0; a < 4; a++) {
            memcpy(v, base[e], sizeof v);
            ord_zera_contagem();
            ordena[a](v, N);
            printf(" %10ld", ord_contagem());
        }
        printf("\n");
    }
    return 0;
}
// Saída:
// n = 2000    insertion      merge       heap      quick
// sorteado       971502      19433      37701      24402
// ordenado         1999      10864      39159      17964
// invertido     1999000      11088      35964      18799
// 10 valores     907042      18815      34854     209643
```

```bash
~/LPEDC/rodar 17-analise-avancada/0118-juntando-tudo/A235.c
```

**Exemplo A236 · Cronômetro honesto: repetir e tirar a mediana**

```c
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "ordena.h"

#define N 1000
#define REPETICOES 200

int original[N], v[N];

// tempo de UMA ordenação, em ms
double uma_vez(void) {
    memcpy(v, original, sizeof v);
    clock_t ini = clock();
    ord_merge(v, N);
    return 1000.0 * (clock() - ini) / CLOCKS_PER_SEC;
}

// tempo médio por ordenação num lote de REPETICOES (inclui o memcpy, O(n))
double lote(void) {
    clock_t ini = clock();
    for (int r = 0; r < REPETICOES; r++) {
        memcpy(v, original, sizeof v);
        ord_merge(v, N);
    }
    return 1000.0 * (clock() - ini) / CLOCKS_PER_SEC / REPETICOES;
}

// mediana de 5 valores: ordena uma cópia com insertion e pega o do meio
double mediana5(const double x[]) {
    double c[5];
    memcpy(c, x, sizeof c);
    for (int i = 1; i < 5; i++) {
        double t = c[i];
        int j = i - 1;
        while (j >= 0 && c[j] > t) {
            c[j + 1] = c[j];
            j--;
        }
        c[j + 1] = t;
    }
    return c[2];
}

int main(void) {
    unsigned s = 99;
    for (int i = 0; i < N; i++) {
        s = s * 1103515245u + 12345u;
        original[i] = (int)(s >> 8);
    }

    printf("uma ordenação por vez (ms):");
    for (int k = 0; k < 5; k++) {
        printf(" %.3f", uma_vez());
    }
    printf("\n");

    double medidas[5];
    printf("lotes de %d (ms por ordenação):", REPETICOES);
    for (int k = 0; k < 5; k++) {
        medidas[k] = lote();
        printf(" %.4f", medidas[k]);
    }
    printf("\nmediana dos lotes: %.4f ms\n", mediana5(medidas));
    return 0;
}
// Saída (de uma execução: os tempos mudam a cada vez e de máquina para
// máquina; repare que a primeira medida isolada costuma ser a mais lenta):
// uma ordenação por vez (ms): 0.203 0.150 0.146 0.151 0.163
// lotes de 200 (ms por ordenação): 0.1512 0.1477 0.1352 0.1362 0.1361
// mediana dos lotes: 0.1362 ms
```

```bash
~/LPEDC/rodar 17-analise-avancada/0118-juntando-tudo/A236.c
```

#### Exercícios

**Exercício E703** · ★☆☆

Meça o tempo de verdade. Escreva cronometra(ordena, n), que copia os n
primeiros números de original[] para v[], ordena v com a função recebida
e devolve o tempo em milissegundos, medido com clock(). Depois mostre o
tempo do ord_insertion e do ord_merge (do TAD ordena.h, que está na
pasta) para n = 1000, 2000, 4000 e 8000, com a razão em relação à linha
anterior. Os números do original vêm do gerador já escrito no main.


```text
Saída esperada (os tempos variam; o formato e as razões, não muito):
    n   insertion (ms)        merge (ms)
 1000      1.53            0.184
 2000      6.08  x4.0      0.327  x1.8
 4000     24.19  x4.0      0.746  x2.3
 8000     97.76  x4.0      1.513  x2.0
```

**Dicas:**

1. O parâmetro da função de ordenar é um ponteiro para função:
   void (*ordena)(int[], int). Passe ord_insertion ou ord_merge.
2. Tempo em ms: 1000.0 * (clock() - ini) / CLOCKS_PER_SEC. O 1000.0
   precisa vir antes da divisão (veja o TIP do texto).
3. Copie com memcpy(v, original, n * sizeof v[0]) antes de cada medida.
4. Resposta esperada: a razão do insertion fica em 4,0 (Θ(n²)). A do
   merge oscila em volta de 2,1 (Θ(n log n)): com tempos de menos de
   1 ms, o ruído pesa. Rode duas ou três vezes e compare.

```bash
~/LPEDC/rodar 17-analise-avancada/0118-juntando-tudo/E703.c
```

**Exercício E704** · ★☆☆

Complete prever(t0, n0, n1, quadratico): a partir do tempo t0 medido
com n0 elementos, devolve o tempo previsto para n1 elementos. Se
quadratico for 1, o fator é (n1/n0)²; se for 0, é
(n1 log₂ n1) / (n0 log₂ n0). O main já faz quatro previsões com medidas
de um computador de escritório: o insertion levou 0,8 s para 20 mil
pedidos e o merge sort, 0,004 s:


```text
Saída esperada:
insertion, 20 mil -> 100 mil:    20.0000 s
insertion, 20 mil -> 1 milhão: 2000.0000 s
merge,     20 mil -> 100 mil:     0.0233 s
merge,     20 mil -> 1 milhão:    0.2790 s
```

**Dicas:**

1. log2 está em <math.h> (o rodar já liga a biblioteca matemática).
2. Use double em tudo: n1 * n1 com int estoura para n1 = 1 milhão.
3. Resposta esperada: a saída acima. 2000 s são mais de 33 minutos,
   contra um quarto de segundo. Entrada 50 vezes maior: o insertion fica
   2500 vezes mais lento, o merge, só 70.

```bash
~/LPEDC/rodar 17-analise-avancada/0118-juntando-tudo/E704.c
```

**Exercício E705** · ★★☆

O cadastro de 10 mil clientes da loja fica em ordem de código, mas todo
dia umas poucas alterações bagunçam alguns vizinhos. Qual das quatro
ordenações do ordena.h é a melhor para reordenar esse vetor QUASE
ordenado? Escreva o programa:

- monte base[i] = i para i de 0 a 9999;
- faça 50 trocas de vizinhos: sorteie i = sorteia() % (N - 1) e troque
base[i] com base[i + 1];
- para cada algoritmo, copie base para v, zere a contagem, ordene, e
mostre as comparações (confira com ord_confere que ordenou);
- no fim, diga qual comparou menos.


```text
Saída esperada:
insertion   10049 comparações
merge       64644 comparações
heap       244460 comparações
quick      113650 comparações
vencedor: insertion
```

**Dicas:**

1. Guarde as funções num vetor de ponteiros para função:
   void (*ordena[])(int[], int) = {ord_insertion, ord_merge, ...};
2. Vetores de 10 mil int dentro do main ocupam 40 KB cada: funciona,
   mas static int base[N], v[N]; os tira da pilha.
3. Use o sorteia() já escrito, sem mudar a semente, para dar os mesmos
   números da saída esperada.
4. Resposta esperada: a saída acima. O insertion faz n - 1 comparações
   mais uma por inversão: Θ(n) num vetor quase ordenado. O pior caso
   Θ(n²) não conta a história toda; o heapsort, ótimo no pior caso, é o
   pior aqui.

```bash
~/LPEDC/rodar 17-analise-avancada/0118-juntando-tudo/E705.c
```

**Exercício E706** · ★★☆

Às vezes você recebe uma função pronta e quer saber a classe dela sem
fazer a análise. Dá para descobrir no experimento: dobre n e veja por
quanto o custo é multiplicado. Complete classe(f, &razao): ela calcula
razao = f(128) / f(64) (cada mistério devolve quantos passos deu) e
devolve o nome da classe pela razão:


```text
abaixo de 2,15  -> Θ(n)
abaixo de 3     -> Θ(n log n)
abaixo de 6     -> Θ(n²)
a partir de 6   -> Θ(n³)
```



```text
Saída esperada:
misterio_a: dobrou n, custo x4.03 -> Θ(n²)
misterio_b: dobrou n, custo x2.01 -> Θ(n)
misterio_c: dobrou n, custo x2.33 -> Θ(n log n)
misterio_d: dobrou n, custo x7.88 -> Θ(n³)
```


Depois de rodar, confira cada resposta lendo o código: qual é a
recorrência do misterio_b? Por que o misterio_d dá n³ se o laço de dentro
anda de 2 em 2?

**Dicas:**

1. Chame f como uma função comum: f(128). O cast (double) evita a
   divisão inteira.
2. Para n log n, dobrar n dá 2 · log(2n) / log n: com n = 64, 2 · 7 / 6 =
   2,33. Por isso o limite do Θ(n) é 2,15, e não 2,5.
3. Resposta esperada: a saída acima. O misterio_b é T(n) = 2 T(n/2) + 1
   (caso 1 do teorema mestre, Θ(n)); o passo 2 do misterio_d só divide
   o custo por uma constante.

```bash
~/LPEDC/rodar 17-analise-avancada/0118-juntando-tudo/E706.c
```

**Exercício E707** · ★★★

As bibliotecas de verdade não usam merge sort "puro": quando o pedaço
fica pequeno, trocam para o insertion sort, que não tem recursão nem
cópia para o rascunho. Estenda a função hibrido (hoje um merge sort
comum): escreva insertion_trecho(v, p, r), que ordena só v[p..r-1], e
faça hibrido chamá-la quando o pedaço tiver menos de limiar elementos.
O main já mede comparações e tempo para vários limiares, com 200 mil
números sorteados:


```text
Saída esperada (os tempos variam; as comparações, não):
L =   1:  3272603 comparações,   54.5 ms
L =   8:  3315173 comparações,   51.0 ms
L =  16:  3478137 comparações,   49.7 ms
L =  32:  3925760 comparações,   49.8 ms
L =  64:  4963872 comparações,   54.2 ms
L = 256: 11917965 comparações,   97.4 ms
```

**Dicas:**

1. insertion_trecho é o insertion de sempre, mas o laço vai de p + 1 até
   r - 1 e o while para em j >= p (e não em j >= 0).
2. Use a função menor() nas comparações do insertion também, para a
   contagem ser justa.
3. Resposta esperada: as comparações acima. Repare: as comparações SOBEM
   com o limiar (o insertion compara mais que o merge), mas o tempo
   costuma CAIR até uns 16 ou 32, porque cada comparação do insertion
   sai mais barata que a recursão e a cópia do merge. Com 256, o Θ(n²)
   dos pedaços já pesa. Comparações são um bom modelo, mas não são tudo.

```bash
~/LPEDC/rodar 17-analise-avancada/0118-juntando-tudo/E707.c
```

**Exercício E708** · ★★★

Conserte o programa. Ele devia comparar as quatro ordenações do
ordena.h com os MESMOS 20 mil números sorteados, mas os resultados não
fazem sentido:


```text
Saída que aparece:
insertion: 99529734 comparações, 0.000 s
merge:     99668950 comparações, 0.000 s
heap:      100198011 comparações, 0.000 s
quick:     100445261 comparações, 0.000 s
```


Há três erros, um em cada medida: o tempo sai sempre zero, as
comparações vão se acumulando de um algoritmo para o outro, e os três
últimos algoritmos não recebem a mesma entrada que o primeiro.


```text
Saída esperada (os tempos variam; as comparações, não):
insertion: 99529734 comparações, 0.658 s
merge:       260882 comparações, 0.004 s
heap:        510606 comparações, 0.007 s
quick:       331546 comparações, 0.004 s
```

**Dicas:**

1. clock() e CLOCKS_PER_SEC são inteiros. O que dá 658000 / 1000000 em
   divisão inteira?
2. Onde a contagem é zerada? Uma vez só, antes do laço?
3. Depois do insertion, como está o vetor v? O que o merge recebe?
4. Resposta esperada: a saída esperada acima. Os consertos: dividir em
   double ((double)(clock() - ini) / CLOCKS_PER_SEC), chamar
   ord_zera_contagem() antes de cada ordenação e copiar o original para
   v (memcpy) também antes de cada uma.

```bash
~/LPEDC/rodar 17-analise-avancada/0118-juntando-tudo/E708.c
```

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

## Lista de exercícios práticos

30 exercícios que misturam os assuntos do módulo, no ritmo da prova do PPGI. Arquivos em [`lista/`](17-analise-avancada/lista/); resoluções em `_respostas/17-analise-avancada/lista/`.

### ★☆☆ Aquecimento

**Exercício P1701** · ★☆☆ · O faturamento somado pelas metades

A padaria guarda o faturamento de cada dia (em reais) num vetor. A função
soma(v, ini, fim) do esqueleto soma v[ini..fim] dividindo o pedaço ao meio e
somando as duas metades. A recorrência do número de chamadas é


```text
C(1) = 1,  C(n) = C(⌈n/2⌉) + C(⌊n/2⌋) + 1
```


Confira no computador que C(n) = 2n - 1, para QUALQUER n (não só potência
de 2): acrescente um contador global de chamadas e mostre, para n = 1, 2,
3, 4, 10, 16, 64 e 100, a soma dos n primeiros dias, as chamadas contadas e
2n - 1.


```text
Saída esperada:
  n       soma  chamadas  2n-1
  1        900         1     1
  2       1850         3     3
  3       2850         5     5
  4       3900         7     7
 10      10200        19    19
 16      16550        31    31
 64      67050       127   127
100     104750       199   199
```

**Dicas:**

1. Some 1 no contador na primeira linha de soma(). Zere o contador antes
   de cada n.
2. A árvore de recursão tem n folhas (um dia cada) e n - 1 nós internos
   (cada um junta dois pedaços): 2n - 1 nós no total.
3. Por isso o custo é Θ(n): dividir ao meio não deixa a soma mais rápida
   que um laço; só muda a forma.
4. Resposta esperada: as duas colunas de chamadas são sempre iguais; com
   n = 100 são 199 chamadas.

```bash
~/LPEDC/rodar 17-analise-avancada/lista/P1701.c
```

---

**Exercício P1702** · ★☆☆ · A maior nota dividindo a turma em três

Complete a função maior3(v, ini, n), que acha a maior nota de v[ini ..
ini + n - 1] dividindo o pedaço em TRÊS terços iguais (n é potência de 3),
achando a maior de cada terço com uma chamada recursiva e comparando as
três. Um contador global soma 1 a cada chamada.

A recorrência das chamadas é C(1) = 1 e C(n) = 3 C(n/3) + 1. Pela árvore
de recursão, C(n) = 1 + 3 + 9 + ... + n = (3n - 1) / 2. Mostre, para n = 1,
3, 9, 27, 81 e 243, a maior nota, as chamadas contadas e (3n - 1) / 2.


```text
Saída esperada:
  n  maior  chamadas  (3n-1)/2
  1     11         1         1
  3     85         4         4
  9     95        13        13
 27     98        40        40
 81    100       121       121
243    100       364       364
```

**Dicas:**

1. Caso base: n == 1, devolve v[ini]. Senão, t = n / 3 e as chamadas são
   em ini, ini + t e ini + 2t, todas com tamanho t.
2. A árvore tem log₃ n + 1 níveis, com 3^i nós no nível i: a soma da
   progressão geométrica dá (3n - 1) / 2.
3. Pelo teorema mestre, T(n) = 3 T(n/3) + Θ(1) é o caso 1 (n^(log₃ 3) = n
   ganha de 1): Θ(n), como um laço.
4. Resposta esperada: com n = 243, 364 chamadas, igual a (3 · 243 - 1) / 2.

```bash
~/LPEDC/rodar 17-analise-avancada/lista/P1702.c
```

---

**Exercício P1703** · ★☆☆ · O hodômetro do ônibus: custo amortizado em base 10

O hodômetro mecânico de um ônibus tem 4 rodinhas de dígitos (0000 a 9999)
e soma 1 a cada quilômetro. Girar uma rodinha custa 1. Quase sempre só a
rodinha das unidades gira, mas de 0999 para 1000 giram quatro.

Guarde os dígitos num vetor int d[4] (d[0] = unidades) e escreva int
incrementa(int d[]), que soma 1 e devolve quantas rodinhas giraram. Mostre
o custo de cada passo de 0997 até 1000, e o custo TOTAL e o custo por
incremento depois de 10, 100, 1000 e 10000 quilômetros a partir de 0000.


```text
Saída esperada:
0998 (giraram 1)
0999 (giraram 1)
1000 (giraram 4)
   10 km:    11 rodinhas, 1.100 por km
  100 km:   111 rodinhas, 1.110 por km
 1000 km:  1111 rodinhas, 1.111 por km
10000 km: 11110 rodinhas, 1.111 por km
```

**Dicas:**

1. incrementa: i = 0; enquanto i < 4 e d[i] == 9, d[i] = 0 e i++ (cada
   uma é uma rodinha girada); se i < 4, d[i]++ (mais uma).
2. Análise agregada: em n incrementos, a rodinha das unidades gira n
   vezes, a das dezenas n/10, a das centenas n/100... A soma fica abaixo
   de n · 10/9 ≈ 1,111 n.
3. Em 10000 km o hodômetro volta para 0000: a rodinha dos milhares também
   gira 10 vezes.
4. Resposta esperada: 1, 1 e 4 rodinhas nos passos 0997 -> 0998 -> 0999 ->
   1000; 1111 rodinhas em 1000 km e 11110 em 10000 km (1,111 por km).

```bash
~/LPEDC/rodar 17-analise-avancada/lista/P1703.c
```

---

**Exercício P1704** · ★☆☆ · Contador binário: quantas vezes cada bit troca

A catraca da academia conta os acessos num contador binário de 8 bits,
guardado em int b[8] (b[0] é o bit menos significativo). Incrementar custa
o número de bits trocados.

Escreva int incrementa(int b[]) e um programa que faça 32 incrementos a
partir de 00000000, mostrando os oito primeiros (o contador e o custo) e,
no fim, quantas vezes CADA bit trocou, o total e o limite 2n da análise
agregada.


```text
Saída esperada:
00000001  custo 1
00000010  custo 2
00000011  custo 1
00000100  custo 3
00000101  custo 1
00000110  custo 2
00000111  custo 1
00001000  custo 4
bit 0: 32 trocas
bit 1: 16 trocas
bit 2:  8 trocas
bit 3:  4 trocas
bit 4:  2 trocas
bit 5:  1 trocas
bit 6:  0 trocas
bit 7:  0 trocas
Total: 63 trocas em 32 incrementos (limite 2n = 64)
```

**Dicas:**

1. incrementa: enquanto b[i] == 1, zere b[i] e avance i (cada um é uma
   troca); depois, se i < 8, b[i] = 1 (mais uma troca).
2. Some 1 em trocas[i] a cada troca do bit i: é a análise agregada do
   Cormen olhando bit por bit.
3. O bit i troca a cada 2^i incrementos: n, n/2, n/4, ... A soma é menor
   que 2n, então o custo amortizado é O(1) por incremento, mesmo com um
   incremento isolado custando até 8.
4. Resposta esperada: o bit 0 troca 32 vezes, o bit 1 16, ..., o bit 5
   uma vez; total 63, abaixo de 2n = 64.

```bash
~/LPEDC/rodar 17-analise-avancada/lista/P1704.c
```

---

**Exercício P1705** · ★☆☆ · A árvore de recursão do merge sort, nível por nível

O merge sort do esqueleto ordena os preços de 16 produtos. A recorrência
é T(n) = 2 T(n/2) + n: cada chamada com um pedaço de tamanho m custa m (o
trabalho de intercalar).

Instrumente o merge sort com um parâmetro nivel (a raiz é o nível 0) e,
em vetores globais, acumule por nível o número de chamadas e o custo (a
soma dos tamanhos dos pedaços). Mostre a tabela da árvore de recursão para
n = 16 e para n = 10 e o custo total. Para n potência de 2, o total é
n lg n + n: lg n + 1 níveis com custo n cada.


```text
Saída esperada:
n = 16: 2 3 5 7 8 9 11 12 15 18 19 22 25 30 33 40
nível  chamadas  custo
    0         1     16
    1         2     16
    2         4     16
    3         8     16
    4        16     16
Total: 80
n = 10: 3 5 8 9 12 15 18 22 30 40
nível  chamadas  custo
    0         1     10
    1         2     10
    2         4     10
    3         8     10
    4         4      4
Total: 44
```

**Dicas:**

1. Acrescente int nivel aos parâmetros: a chamada recursiva passa
   nivel + 1. Logo no começo, faça nos[nivel]++ e custo[nivel] += m.
2. Conte também as folhas (pedaços de tamanho 1): elas formam o último
   nível, com custo 1 cada.
3. Com n = 10 os pedaços não têm o mesmo tamanho, e o último nível fica
   incompleto. Mesmo assim cada nível cheio custa n.
4. Resposta esperada: n = 16 dá 5 níveis de custo 16 (total 80 = 16 · 4 +
   16); n = 10 dá 5 níveis, o último com 4 chamadas e custo 4 (total 44).

```bash
~/LPEDC/rodar 17-analise-avancada/lista/P1705.c
```

---

**Exercício P1706** · ★☆☆ · O desfazer do editor: pilha com multipop

Um editor de texto guarda cada tecla digitada numa pilha. "Desfazer k"
tira k teclas de uma vez (ou todas, se houver menos de k): é o MULTIPOP. O
custo real de empilhar é 1, e o de desfazer k é min(k, tamanho da pilha).

Complete int multipop(Pilha *p, int k), que devolve quantas teclas tirou,
e rode a sessão do esqueleto mostrando o custo de cada operação, o maior
custo de uma operação só, o custo total e o limite 2 · (empilhamentos) da
análise amortizada.


```text
Saída esperada:
digita "manaux" custo  6 | texto: "manaux"
desfaz 1        custo  1 | texto: "manau"
digita "s! ok"  custo  5 | texto: "manaus! ok"
desfaz 12       custo 10 | texto: ""
digita "oi"     custo  2 | texto: "oi"
desfaz 1        custo  1 | texto: "o"
Empilhadas 13, tiradas 12, total 25 (limite 2 x 13 = 26)
Operação mais cara: 10
```

**Dicas:**

1. multipop: enquanto k > 0 e a pilha não estiver vazia, tire o topo e
   diminua k. Devolva quantas saíram.
2. Uma operação isolada pode custar muito (o "desfazer 12" custa 10), mas
   cada tecla só sai da pilha se entrou antes: o total de pops não passa
   do total de pushes.
3. Por isso n operações custam no máximo 2n: custo amortizado O(1).
4. Resposta esperada: 13 teclas empilhadas, 12 tiradas, total 25, dentro
   do limite 26; a operação mais cara custou 10.

```bash
~/LPEDC/rodar 17-analise-avancada/lista/P1706.c
```

---

**Exercício P1707** · ★☆☆ · Insertion sort recursivo e a recorrência T(n-1) + n

Escreva do zero um insertion sort RECURSIVO para as senhas de atendimento
de uma agência: ordena(v, n) ordena v[0..n-2] com uma chamada recursiva e
depois insere v[n-1] na posição certa, deslocando os maiores. Conte as
comparações entre elementos num contador global.

A recorrência do pior caso é T(1) = 0 e T(n) = T(n - 1) + (n - 1), que
soma 1 + 2 + ... + (n - 1) = n(n - 1)/2. No melhor caso, cada inserção faz
uma comparação só: n - 1. Mostre as comparações para os três vetores de 10
senhas do esqueleto, junto com n - 1 e n(n - 1)/2.


```text
Saída esperada:
crescente     9 comparações: 101 102 103 104 105 106 107 108 109 110
decrescente  45 comparações: 101 102 103 104 105 106 107 108 109 110
misturado    26 comparações: 101 102 103 104 105 106 107 108 109 110
Melhor caso n - 1 = 9 | pior caso n(n - 1)/2 = 45
```

**Dicas:**

1. Caso base: n <= 1, nada a fazer. Depois da chamada, x = v[n - 1];
   j = n - 2; enquanto j >= 0 e (conte 1) v[j] > x, desloque v[j] para
   v[j + 1].
2. Conte a comparação ANTES de testar: se o laço para porque j < 0, não
   houve comparação.
3. O vetor crescente é o melhor caso (Θ(n)), o decrescente o pior
   (Θ(n²)). O misturado fica no meio.
4. Resposta esperada: 9 comparações no crescente, 45 no decrescente e 26
   no misturado.

```bash
~/LPEDC/rodar 17-analise-avancada/lista/P1707.c
```

---

**Exercício P1708** · ★☆☆ · Quão funda fica a pilha de chamadas

A recorrência mede o TEMPO; a altura da árvore de recursão mede a PILHA.
O esqueleto tem duas somas recursivas das contas de luz de um condomínio,
as duas com Θ(n) chamadas:

- soma_fila(v, n) = v[n - 1] + soma_fila(v, n - 1): T(n) = T(n - 1) + 1;
- soma_meio(v, ini, fim) divide ao meio: T(n) = 2 T(n/2) + 1.

Instrumente as duas com um parâmetro de profundidade e guarde a maior
profundidade alcançada (a raiz tem profundidade 1). Mostre, para n = 10,
100 e 1000, as chamadas e a profundidade máxima de cada uma.


```text
Saída esperada:
n =   10  fila: soma   1385,   11 chamadas, profundidade   11
          meio: soma   1385,   19 chamadas, profundidade    5
n =  100  fila: soma  15350,  101 chamadas, profundidade  101
          meio: soma  15350,  199 chamadas, profundidade    8
n = 1000  fila: soma 154400, 1001 chamadas, profundidade 1001
          meio: soma 154400, 1999 chamadas, profundidade   11
```

**Dicas:**

1. Passe prof + 1 nas chamadas recursivas e atualize uma variável global
   max_prof logo no começo da função.
2. soma_fila desce até n == 0: a pilha chega a n + 1 chamadas abertas ao
   mesmo tempo.
3. soma_meio para em pedaços de 1 elemento. A altura é ⌈lg n⌉ + 1: com
   n = 1000, só 11 chamadas abertas, contra 1001.
4. Resposta esperada: as duas somas dão o mesmo valor; chamadas n + 1 e
   2n - 1; profundidades 1001 e 11 para n = 1000.

```bash
~/LPEDC/rodar 17-analise-avancada/lista/P1708.c
```

---

**Exercício P1709** · ★☆☆ · A função que se chama duas vezes à toa

Um colega escreveu a função do esqueleto para calcular a meta de vendas do
mês n de uma loja: a meta dobra todo mês, e a de janeiro (n = 1) é R$ 100.
Ela funciona, mas chama meta(n - 1) DUAS vezes com o mesmo argumento:


```text
C(1) = 1,  C(n) = 2 C(n - 1) + 1  =>  C(n) = 2^n - 1 chamadas
```


Acrescente um contador de chamadas, escreva meta_boa(n), que chama
meta_boa(n - 1) uma vez só e guarda o resultado numa variável (C(n) =
C(n - 1) + 1 = n), e mostre, para n = 1, 5, 10, 20 e 25, a meta e as
chamadas das duas versões, junto com 2^n - 1.


```text
Saída esperada:
 n        meta  ruim: chamadas     2^n-1  boa: chamadas
 1         100                1         1              1
 5        1600               31        31              5
10       51200             1023      1023             10
20    52428800          1048575   1048575             20
25  1677721600         33554431  33554431             25
```

**Dicas:**

1. Use long para a meta: 100 · 2^24 passa de 1,6 bilhão.
2. A árvore de recursão da versão ruim é uma árvore binária cheia de
   altura n - 1: 2^n - 1 nós.
3. 2^n - 1 dá para calcular com (1L << n) - 1.
4. Resposta esperada: com n = 25, a meta é 1677721600, a versão ruim faz
   33554431 chamadas e a boa, 25.

```bash
~/LPEDC/rodar 17-analise-avancada/lista/P1709.c
```

---

**Exercício P1710** · ★☆☆ · Adivinhe o preço: o limite da árvore de decisão

No programa de auditório, o participante adivinha um preço inteiro de 1 a
n reais, e o apresentador responde "é esse", "mais" ou "menos". Qualquer
estratégia é uma árvore de decisão com n respostas possíveis; uma árvore
binária de altura h tem no máximo 2^h - 1 nós de "é esse", então o pior
caso precisa de pelo menos ⌈lg(n + 1)⌉ palpites.

A busca binária atinge esse limite. Escreva:


```text
int palpites(int n, int preco);   // palpites da busca binária até acertar
int teto_lg(int x);               // menor h com 2^h >= x, só com inteiros
```


e mostre, para n = 7, 15, 100, 1000 e 1000000, o pior caso da busca
binária (testando TODOS os preços de 1 a n) e o limite ⌈lg(n + 1)⌉.


```text
Saída esperada:
      n  pior caso  limite
      7          3       3
     15          4       4
    100          7       7
   1000         10      10
1000000         20      20
```

**Dicas:**

1. palpites: ini = 1, fim = n; a cada volta, chute meio = (ini + fim) / 2
   e conte 1; se acertou, pare; se o preço é maior, ini = meio + 1; senão,
   fim = meio - 1.
2. teto_lg: h = 0, p = 1; enquanto p < x, p *= 2 e h++. Use long para p.
3. Com n = 1000000, testar todos os preços custa uns 20 milhões de passos:
   roda em menos de um segundo.
4. Resposta esperada: as duas colunas são iguais; 3, 4, 7, 10 e 20.

```bash
~/LPEDC/rodar 17-analise-avancada/lista/P1710.c
```

### ★★☆ Para pensar

**Exercício P1711** · ★★☆ · A árvore de 3T(n/4) + n² contada por nível

A recorrência T(n) = 3 T(n/4) + n² é o exemplo clássico da árvore de
recursão no Cormen. Transforme-a num programa: trabalho(n, nivel) faz n²
unidades de trabalho (um laço duplo que soma 1 num contador do nível) e se
chama três vezes com n/4; com n == 1, faz 1 unidade e para.

Rode com n = 256 e mostre, por nível: o número de chamadas, o tamanho de
cada pedaço e o custo do nível. Mostre também o total e a razão total / n²,
que tem de ficar abaixo de 1/(1 - 3/16) = 16/13 ≈ 1,2308: a soma é uma
progressão geométrica de razão 3/16, e a RAIZ domina (caso 3 do teorema
mestre, Θ(n²)).


```text
Saída esperada:
nível  chamadas  tamanho  custo
    0         1      256  65536
    1         3       64  12288
    2         9       16   2304
    3        27        4    432
    4        81        1     81
Total: 80641 | total / n² = 1.2305 (limite 16/13 = 1.2308)
```

**Dicas:**

1. Guarde chamadas[nivel] e custo[nivel] em vetores globais; 256 = 4^4,
   então são 5 níveis (0 a 4).
2. O nível i tem 3^i chamadas com pedaços de n/4^i: o custo é
   3^i (n/4^i)² = (3/16)^i n².
3. Faça o laço duplo de verdade (for i < n, for j < n, custo++): com
   n = 256 são 65536 voltas na raiz, nada que demore.
4. Resposta esperada: custos 65536, 12288, 2304, 432 e 81; total 80641;
   razão 1.2305.

```bash
~/LPEDC/rodar 17-analise-avancada/lista/P1711.c
```

---

**Exercício P1712** · ★★☆ · Três funções, três casos, três fórmulas fechadas

As três funções do esqueleto fazem um laço de n voltas (custo n) e se
chamam com n/2, mudando só QUANTAS vezes:


```text
quatro(n): T(n) = 4 T(n/2) + n   caso 1: Θ(n²)
duas(n):   T(n) = 2 T(n/2) + n   caso 2: Θ(n lg n)
uma(n):    T(n) = T(n/2) + n     caso 3: Θ(n)
```


com T(1) = 1. Resolvendo exatamente para n potência de 2 (pela árvore de
recursão), as fórmulas são 2n² - n, n lg n + n e 2n - 1. Instrumente as três
com um contador global (some 1 em cada volta do laço e 1 no caso base) e
mostre, para n = 1, 2, 4, ..., 1024, o custo contado e a fórmula de cada
uma.


```text
Saída esperada:
   n    quatro   2n²-n   duas  nlgn+n   uma  2n-1
   1         1       1      1       1     1     1
   2         6       6      4       4     3     3
   4        28      28     12      12     7     7
   8       120     120     32      32    15    15
  16       496     496     80      80    31    31
  32      2016    2016    192     192    63    63
  64      8128    8128    448     448   127   127
 128     32640   32640   1024    1024   255   255
 256    130816  130816   2304    2304   511   511
 512    523776  523776   5120    5120  1023  1023
1024   2096128 2096128  11264   11264  2047  2047
```

**Dicas:**

1. Zere o contador antes de cada chamada de topo. Use long: quatro(1024)
   passa de 2 milhões.
2. Para o lg n, use um contador de expoente que sobe junto com n no laço do
   main (n = 1 << k).
3. As fórmulas saem da soma por nível: quatro tem 4^i pedaços de n/2^i
   (custo 2^i n no nível i); duas tem custo n em todo nível; uma tem
   n/2^i no nível i.
4. Resposta esperada: as colunas contadas e as fórmulas batem em todas as
   linhas; com n = 1024: 2096128, 11264 e 2047.

```bash
~/LPEDC/rodar 17-analise-avancada/lista/P1712.c
```

---

**Exercício P1713** · ★★☆ · Quando o mestre não serve: 2T(n/2) + n lg n

Um sistema de relatórios divide os registros ao meio, processa cada metade
recursivamente e, para juntar, gasta n lg n (ele ordena o resultado). A
recorrência é T(n) = 2 T(n/2) + n lg n, com T(1) = 1.

Parece o caso 3 (n lg n é maior que n^(log₂ 2) = n), mas não é: n lg n
não é POLINOMIALMENTE maior que n (não existe ε > 0 com n lg n = Ω(n^(1+ε))).
O teorema mestre na forma básica não se aplica. A árvore de recursão
resolve: o nível i custa n (lg n - i), e a soma dá


```text
T(n) = n + n · lg n (lg n + 1) / 2 = Θ(n lg² n)
```


Escreva relatorio(n), que conta n · lg n unidades de trabalho (lg n
calculado com inteiros) e se chama duas vezes com n/2, e mostre, para
n = 2, 4, 8, ..., 2^16, o custo contado, a fórmula, a razão custo/(n lg n)
(que CRESCE) e a razão custo/(n lg² n) (que se aproxima de 1/2).


```text
Saída esperada:
    n      custo    fórmula  c/(n lg n)  c/(n lg² n)
    2          4          4       2.000        2.000
    4         16         16       2.000        1.000
    8         56         56       2.333        0.778
   16        176        176       2.750        0.688
   32        512        512       3.200        0.640
   64       1408       1408       3.667        0.611
  128       3712       3712       4.143        0.592
  256       9472       9472       4.625        0.578
  512      23552      23552       5.111        0.568
 1024      57344      57344       5.600        0.560
 2048     137216     137216       6.091        0.554
 4096     323584     323584       6.583        0.549
 8192     753664     753664       7.077        0.544
16384    1736704    1736704       7.571        0.541
32768    3964928    3964928       8.067        0.538
65536    8978432    8978432       8.562        0.535
```

**Dicas:**

1. lg n com inteiros: conte quantas vezes dá para dividir n por 2 até
   chegar a 1.
2. Não precisa de laço de n lg n voltas: some n * lg(n) direto no
   contador (o custo é o que interessa, não o tempo).
3. Uma razão que cresce sem parar mostra que o palpite Θ(n lg n) está
   errado; uma razão que se estabiliza mostra a classe certa.
4. Resposta esperada: custo igual à fórmula em todas as linhas; com
   n = 65536, 8978432, razões 8.562 e 0.535.

```bash
~/LPEDC/rodar 17-analise-avancada/lista/P1713.c
```

---

**Exercício P1714** · ★★☆ · Apertando √ na calculadora: T(n) = T(√n) + 1

Na calculadora, você digita um número e aperta a tecla √ até o visor
mostrar 2 ou menos. Quantas vezes? A função raizes(n) do enunciado faz
isso recursivamente: se n <= 2, para; senão, chama raizes(⌊√n⌋). A
recorrência é T(n) = T(√n) + 1.

Ela não tem a forma a T(n/b) + f(n), mas a MUDANÇA DE VARIÁVEL resolve:
com n = 2^m, fica S(m) = S(m/2) + 1, que é Θ(lg m). Voltando, T(n) =
Θ(lg lg n). Para n = 2^(2^k) a conta é exata: k + 1 chamadas.

Escreva raiz_inteira(n) (o maior r com r · r <= n, só com inteiros, por
busca binária), teto_lg(n) (o menor h com 2^h >= n, só com inteiros) e
raizes(n) com um contador de chamadas, e mostre as chamadas e
⌈lg ⌈lg n⌉⌉ + 1 para n = 4, 16, 256, 65536, 4294967296 e
18446744073709551615 (o maior unsigned long long, que não é potência de
2^(2^k)).


```text
Saída esperada:
                   n  chamadas  teto(lg teto(lg n)) + 1
                   4         2            2
                  16         3            3
                 256         4            4
               65536         5            5
          4294967296         6            6
18446744073709551615         7            7
```

**Dicas:**

1. Use unsigned long long. Na busca binária, teste r <= n / r em vez de
   r * r <= n: o produto estoura para n perto de 2^64.
2. teto_lg(n): conte quantos bits tem n - 1 (desloque para a direita até
   zerar). Não use p *= 2 até passar de n: p estoura antes de 2^64.
3. Mesmo o maior número de 64 bits cai para 2 em 7 apertos: lg lg n cresce
   devagar demais para ser visto na prática.
4. Resposta esperada: 2, 3, 4, 5 e 6 chamadas para as potências, e 7 para
   o maior unsigned long long; a coluna da fórmula bate em todas.

```bash
~/LPEDC/rodar 17-analise-avancada/lista/P1714.c
```

---

**Exercício P1715** · ★★☆ · O método do potencial no vetor que dobra

O vetor de pedidos de um app começa VAZIO (capacidade 0). Ao inserir com o
vetor cheio, ele aloca o dobro (ou 1, se a capacidade era 0) e copia tudo.
O custo real de uma inserção é 1, mais o número de cópias.

O método do potencial do Cormen usa Φ = 2 · num - cap (num = itens, cap =
capacidade). O custo AMORTIZADO de uma operação é o real mais a variação do
potencial: ĉ = c + Φ(depois) - Φ(antes). Escreva o vetor com malloc (copie
os itens à mão, para contar as cópias) e mostre, para 17 inserções: num,
cap, custo real, Φ e custo amortizado. Mostre também a soma dos custos reais
e a dos amortizados.


```text
Saída esperada:
num  cap  real  phi  amortizado
  1    1     1    1           2
  2    2     2    2           3
  3    4     3    2           3
  4    4     1    4           3
  5    8     5    2           3
  6    8     1    4           3
  7    8     1    6           3
  8    8     1    8           3
  9   16     9    2           3
 10   16     1    4           3
 11   16     1    6           3
 12   16     1    8           3
 13   16     1   10           3
 14   16     1   12           3
 15   16     1   14           3
 16   16     1   16           3
 17   32    17    2           3
Soma real: 48 | soma amortizada: 50 (3n = 51)
```

**Dicas:**

1. Antes de inserir, guarde Φ = 2 · num - cap. Depois, calcule o novo Φ
   e ĉ = c + Φnovo - Φvelho.
2. Sem expansão: c = 1 e Φ sobe 2, então ĉ = 3. Com expansão de num = cap
   = k para 2k: c = k + 1 e Φ cai de k para 2, então ĉ = 3 também.
3. Como Φ começa em 0 e nunca fica negativo depois da primeira inserção, a
   soma dos reais nunca passa da soma dos amortizados: no máximo 3n.
4. Resposta esperada: amortizado 3 em todas as linhas (2 na primeira);
   soma real 48 e soma amortizada 50.

```bash
~/LPEDC/rodar 17-analise-avancada/lista/P1715.c
```

---

**Exercício P1716** · ★★☆ · Contador com zerar: o reset que não varre tudo

O contador de passageiros de uma estação tem 16 bits e duas operações:
INCREMENTA e ZERA (no fim de cada turno). Zerar varrendo os 16 bits custa
16 sempre. Dá para fazer melhor: guarde em maior o índice do bit 1 mais
alto já ligado desde o último zerar, e zere só os bits 0..maior (custo
maior + 1).

Com isso, n operações quaisquer custam O(n) no total. Pelo método
contábil, cada INCREMENTA paga 3: 1 pelo bit que liga, 1 de crédito para
quando esse bit for desligado, e 1 de crédito para o ZERA varrer a posição,
caso o incremento tenha subido o maior (ele sobe no máximo 1 por vez).

Escreva as duas versões do zerar e rode a sequência do esqueleto contando o
custo total de cada uma (incrementar custa os bits trocados; zerar custa os
bits varridos). Mostre também o limite 3 · (incrementos) + (zerares).


```text
Saída esperada:
Incrementos: 1150 | zerares: 52
Zerar varrendo tudo: 3026
Zerar até o maior:   2304
Limite 3·1150 + 52 = 3502
```

**Dicas:**

1. No incrementa, depois de ligar o bit i, faça maior = i se i > maior.
   Comece com maior = -1.
2. zera_esperto: para i de 0 até maior, b[i] = 0 (custo maior + 1); depois
   maior = -1. zera_bobo: varre os 16.
3. Um zerar logo depois de outro custa 0 na versão esperta (maior = -1).
4. Resposta esperada: versão boba 3026, esperta 2304, limite 3502; nos 50
   turnos curtos, cada zerar esperto custa 2 em vez de 16.

```bash
~/LPEDC/rodar 17-analise-avancada/lista/P1716.c
```

---

**Exercício P1717** · ★★☆ · Conserte o vetor que cresce de 10 em 10

Conserte o programa. O app de delivery guarda os pedidos do dia num vetor
dinâmico, e o colega fez o vetor crescer de 10 em 10 posições "para não
desperdiçar memória". O erro de propósito não é de memória (o
AddressSanitizer não reclama): é de ANÁLISE. Com crescimento aditivo, n
inserções copiam 10 + 20 + 30 + ... ≈ n²/20 itens: Θ(n²) no total, Θ(n)
por inserção. Veja a saída com 10 mil pedidos:


```text
Saída que aparece:
Pedidos: 10000 | capacidade: 10000
Realocações: 999 | cópias: 4995000 (499.50 por pedido)
```


Troque a regra de crescimento para DOBRAR a capacidade (começando em 10) e
confira que as cópias caem para menos de 2n, ou seja, O(1) amortizado:


```text
Saída esperada:
Pedidos: 10000 | capacidade: 10240
Realocações: 10 | cópias: 10230 (1.02 por pedido)
```

**Dicas:**

1. A única linha que muda é a da nova capacidade.
2. Dobrando a partir de 10, as cópias são 10 + 20 + 40 + ... + 5120: uma
   progressão geométrica que soma menos que o dobro do último termo.
3. Se quiser ver a diferença no relógio, aumente para 1 milhão de pedidos:
   a versão aditiva copia uns 50 bilhões de itens.
4. Resposta esperada: 10 realocações e 10230 cópias, contra 999 e 4995000.

```bash
~/LPEDC/rodar 17-analise-avancada/lista/P1717.c
```

---

**Exercício P1718** · ★★☆ · O laço que dobra dentro da recursão

A função do esqueleto organiza as filas de um evento: em cada pedaço de n
pessoas, um laço for (i = 1; i < n; i *= 2) faz lg n passos, e depois a
função se chama para as duas metades. A recorrência é


```text
T(1) = 1,  T(n) = 2 T(n/2) + lg n
```


Leia o código, ache a recorrência e aplique o teorema mestre: a = 2,
b = 2, n^(log₂ 2) = n, e f(n) = lg n = O(n^(1 - ε)): caso 1, Θ(n). A
árvore de recursão dá a fórmula exata para n potência de 2:
T(n) = 3n - lg n - 2.

Acrescente um contador global (1 por volta do laço e 1 no caso base) e
mostre, para n = 1, 4, 16, ..., 2^20 (potências de 4), o custo contado,
3n - lg n - 2 e a razão custo / n.


```text
Saída esperada:
      n    custo  3n-lg n-2  custo/n
      1        1          1   1.0000
      4        8          8   2.0000
     16       42         42   2.6250
     64      184        184   2.8750
    256      758        758   2.9609
   1024     3060       3060   2.9883
   4096    12274      12274   2.9966
  16384    49136      49136   2.9990
  65536   196590     196590   2.9997
 262144   786412     786412   2.9999
1048576  3145706    3145706   3.0000
```

**Dicas:**

1. Para ler a recorrência do código: duas chamadas com n/2 dão 2 T(n/2);
   o laço com i *= 2 roda ⌈lg n⌉ vezes; o resto é constante.
2. Mesmo com o trabalho por chamada crescendo (lg n), a quantidade de
   folhas (n) domina: o caso 1 diz que as folhas ganham.
3. A razão custo / n se aproxima de 3, a constante da fórmula.
4. Resposta esperada: o custo bate com 3n - lg n - 2 em todas as linhas;
   com n = 2^20, 3145706.

```bash
~/LPEDC/rodar 17-analise-avancada/lista/P1718.c
```

---

**Exercício P1719** · ★★☆ · Quantas chamadas para escolher o time do futsal

O técnico quer saber de quantos jeitos dá para escolher k jogadores de um
grupo de n. A função comb(n, k) do esqueleto usa a relação de Pascal:
C(n, k) = C(n - 1, k - 1) + C(n - 1, k), com C(n, 0) = C(n, n) = 1.

Toda folha da árvore de recursão devolve 1, então ela tem exatamente
C(n, k) folhas. E todo nó interno tem dois filhos. Numa árvore assim
(binária cheia), nós = 2 · folhas - 1. Logo:


```text
chamadas(n, k) = 2 C(n, k) - 1
```


Acrescente um contador e mostre, para (6, 2), (10, 5), (20, 10) e (26, 13),
o valor, as chamadas e 2 C(n, k) - 1. Depois escreva comb_linha(n, k), que
calcula o mesmo número sem recursão, pela fórmula multiplicativa
C(n, k) = C(n, k - 1) · (n - k + 1) / k, e conte as multiplicações.


```text
Saída esperada:
 n  k     C(n,k)  chamadas  2C-1      linha  mult
 6  2         15        29        29         15    2
10  5        252       503       503        252    5
20 10     184756    369511    369511     184756   10
26 13   10400600  20801199  20801199   10400600   13
```

**Dicas:**

1. Use long: C(26, 13) passa de 10 milhões, e as chamadas, de 20 milhões.
2. Na fórmula multiplicativa, faça r = r * (n - i + 1) / i para i de 1 a k,
   nessa ordem: a divisão é sempre exata.
3. A recursão gasta Θ(C(n, k)) chamadas, que crescem como 2^n / √n; a
   fórmula gasta k multiplicações.
4. Resposta esperada: 15, 252, 184756 e 10400600, com 29, 503, 369511 e
   20801199 chamadas; a fórmula faz 2, 5, 10 e 13 multiplicações.

```bash
~/LPEDC/rodar 17-analise-avancada/lista/P1719.c
```

---

**Exercício P1720** · ★★☆ · Quatro ordenações contando comparações

Em vez de cronometrar, conte. O esqueleto gera os preços de n produtos com
um gerador pseudoaleatório fixo (a mesma sequência em toda execução).
Escreva insertion sort, merge sort, heapsort e quicksort (pivô no último
elemento, partição de Lomuto) e conte as COMPARAÇÕES ENTRE ELEMENTOS de
cada um, todos ordenando cópias do mesmo vetor.

Mostre as contagens para n = 1000 e n = 2000, a razão entre as duas (quanto
cresce quando n dobra) e as referências n²/4 e n lg n. Confira também que
os quatro deixam o vetor ordenado.


```text
Saída esperada:
            n = 1000  n = 2000  razão
insertion     250962   1021285   4.07
merge           8707     19411   2.23
heapsort       16835     37713   2.24
quicksort      10531     23811   2.26
n²/4         250000   1000000   4.00
n lg n          9966     21932   2.20
Todos ordenados: sim
```

**Dicas:**

1. Faça a comparação passar por uma função menor(a, b) que soma 1 num
   contador global: assim nenhuma comparação escapa.
2. Quadrático: dobrar n multiplica por 4. Θ(n lg n): multiplica por um
   pouco mais que 2 (2 · lg 2n / lg n ≈ 2,2 para n = 1000).
3. O insertion sort faz em média n²/4 comparações: cada par fora de ordem
   custa uma. Os outros três são Θ(n lg n) com constantes diferentes; o
   heapsort compara duas vezes por nível ao descer, e por isso perde.
4. Resposta esperada: o insertion sort fica perto de n²/4 e quadruplica
   (razão 4,07); merge, heap e quick ficam entre 0,8 e 1,8 vezes n lg n e
   crescem cerca de 2,2 vezes.

```bash
~/LPEDC/rodar 17-analise-avancada/lista/P1720.c
```

### ★★★ Desafio

**Exercício P1721** · ★★★ · Matrizes por blocos: 8 chamadas contra as 7 de Strassen

Uma rede de farmácias multiplica matrizes n × n (transferências entre
filiais vezes custos) com n potência de 2. Dividindo cada matriz em quatro
blocos n/2 × n/2, o produto sai de 8 produtos de blocos:


```text
C11 = A11 B11 + A12 B21    C12 = A11 B12 + A12 B22
C21 = A21 B11 + A22 B21    C22 = A21 B12 + A22 B22
```


Isso dá M(n) = 8 M(n/2) multiplicações escalares, com M(1) = 1: n³, igual ao
laço triplo (caso 1 do mestre, n^(log₂ 8)). Strassen descobriu como fazer
com 7 produtos de blocos: S(n) = 7 S(n/2) = n^(log₂ 7) ≈ n^2,807.

Escreva:

1. mult_blocos(), recursiva com as 8 chamadas (trabalhe com deslocamentos
de linha e coluna nas matrizes globais, sem copiar blocos), contando as
multiplicações escalares;
2. a conferência com o laço triplo para n = 2, 4, 8 e 16;
3. a tabela de n³ e 7^(lg n) para n = 2, 4, ..., 1024, calculada pelas
recorrências, com a razão entre elas.


```text
Saída esperada:
n =  2:    8 multiplicações (n³ =    8), igual ao laço triplo: sim
n =  4:   64 multiplicações (n³ =   64), igual ao laço triplo: sim
n =  8:  512 multiplicações (n³ =  512), igual ao laço triplo: sim
n = 16: 4096 multiplicações (n³ = 4096), igual ao laço triplo: sim
    n          8 blocos   Strassen  razão
    2                 8          7   1.14
    4                64         49   1.31
    8               512        343   1.49
   16              4096       2401   1.71
   32             32768      16807   1.95
   64            262144     117649   2.23
  128           2097152     823543   2.55
  256          16777216    5764801   2.91
  512         134217728   40353607   3.33
 1024        1073741824  282475249   3.80
```

**Dicas:**

1. mult(ar, ac, br, bc, cr, cc, n): no caso base, C[cr][cc] += A[ar][ac] *
   B[br][bc]. Senão, com h = n/2, cada bloco Cxy recebe dois produtos:
   por exemplo, C11 += A11 B11 é mult(ar, ac, br, bc, cr, cc, h) e
   C11 += A12 B21 é mult(ar, ac + h, br + h, bc, cr, cc, h).
2. Zere C antes de cada n: as chamadas SOMAM em C.
3. A razão n³ / 7^(lg n) = (8/7)^(lg n) cresce devagar: só fica grande
   para n enorme, e por isso Strassen só compensa em matrizes grandes.
4. Resposta esperada: as multiplicações contadas são n³ e os produtos
   batem com o laço triplo; com n = 1024, 1073741824 contra 282475249
   (razão 3.80).

```bash
~/LPEDC/rodar 17-analise-avancada/lista/P1721.c
```

---

**Exercício P1722** · ★★★ · A árvore de recursão de qualquer a T(n/b) + n^k

O teorema mestre é a árvore de recursão resumida. Escreva um programa que
DESENHE a árvore, por nível, para qualquer recorrência T(n) = a T(n/b) + n^k
com T(1) = 1 (n potência de b), e que confira o total com uma função
recursiva que realmente soma os custos.


```text
void arvore(int a, int b, int k, long n);
```


Para cada nível i: o número de nós a^i, o tamanho n/b^i, o custo de cada
nó (n/b^i)^k e o custo do nível. No fim: o total da tabela, o total da
recursão (têm de bater) e o diagnóstico pela razão r = a / b^k entre o
custo de um nível e o do anterior:

- r > 1: o custo cresce para baixo, as FOLHAS dominam (caso 1);
- r == 1: todos os níveis custam o mesmo, total = custo × níveis (caso 2);
- r < 1: o custo cai, a RAIZ domina (caso 3).

Rode para (8, 2, 2), (4, 2, 2) e (2, 2, 2), todas com n = 64, e para
(9, 3, 1) com n = 81.


```text
Saída esperada:
T(n) = 8 T(n/2) + n^2, n = 64
  nível      nós  tamanho  custo/nó  custo do nível
      0        1       64      4096            4096
      1        8       32      1024            8192
      2       64       16       256           16384
      3      512        8        64           32768
      4     4096        4        16           65536
      5    32768        2         4          131072
      6   262144        1         1          262144
  total da tabela 520192, da recursão 520192
  r = 8/4 > 1: as folhas dominam (caso 1)
T(n) = 4 T(n/2) + n^2, n = 64
  nível      nós  tamanho  custo/nó  custo do nível
      0        1       64      4096            4096
      1        4       32      1024            4096
      2       16       16       256            4096
      3       64        8        64            4096
      4      256        4        16            4096
      5     1024        2         4            4096
      6     4096        1         1            4096
  total da tabela 28672, da recursão 28672
  r = 1: 7 níveis iguais (caso 2)
T(n) = 2 T(n/2) + n^2, n = 64
  nível      nós  tamanho  custo/nó  custo do nível
      0        1       64      4096            4096
      1        2       32      1024            2048
      2        4       16       256            1024
      3        8        8        64             512
      4       16        4        16             256
      5       32        2         4             128
      6       64        1         1              64
  total da tabela 8128, da recursão 8128
  r = 2/4 < 1: a raiz domina (caso 3)
T(n) = 9 T(n/3) + n^1, n = 81
  nível      nós  tamanho  custo/nó  custo do nível
      0        1       81        81              81
      1        9       27        27             243
      2       81        9         9             729
      3      729        3         3            2187
      4     6561        1         1            6561
  total da tabela 9801, da recursão 9801
  r = 9/3 > 1: as folhas dominam (caso 1)
```

**Dicas:**

1. Compare a com b^k em inteiros: nada de double nem de log, que erram por
   arredondamento.
2. A função recursiva custo(a, b, k, n) devolve n^k + a · custo(a, b, k,
   n/b), com custo(1) = 1. É a própria recorrência.
3. A última linha da tabela (tamanho 1) tem a^(log_b n) = n^(log_b a)
   folhas: é o termo que o caso 1 compara com f(n).
4. Resposta esperada: 8T(n/2)+n² tem folhas 262144 de 520192 (caso 1);
   4T(n/2)+n² tem 7 níveis de 4096 (caso 2); 2T(n/2)+n² tem raiz 4096 de
   8128 (caso 3); 9T(n/3)+n é caso 1.

```bash
~/LPEDC/rodar 17-analise-avancada/lista/P1722.c
```

---

**Exercício P1723** · ★★★ · Stooge sort: correto, recursivo e pior que o bubble

O stooge sort (problema 7-3 do Cormen) ordena v[i..j] assim: se v[i] >
v[j], troca os dois; se o pedaço tem 3 ou mais elementos, com t = ⌊(j - i +
1)/3⌋, ordena os primeiros 2/3, depois os últimos 2/3, depois os primeiros
2/3 de novo. Ele funciona, mas a recorrência é


```text
T(n) = 3 T(2n/3) + Θ(1)  =>  Θ(n^(log_{3/2} 3)) ≈ Θ(n^2,71)
```


pior que os Θ(n²) do bubble e do insertion sort.

Escreva o stooge sort com um contador de chamadas e a profundidade máxima
da recursão (a raiz tem profundidade 1), e ordene os tempos de volta de um
kart (vetor do esqueleto) para n = 10, 20, 40, ..., 640. Mostre, para
cada n: as chamadas, se ficou ordenado, a profundidade, log_{3/2} n e as
n(n - 1)/2 comparações do bubble sort. No fim, estime o expoente entre n = 10 e
n = 640 com log(c₆₄₀ / c₁₀) / log(64) e compare com log(3) / log(1,5).


```text
Saída esperada:
  n  chamadas  ordenado  prof  log1.5(n)  bubble
 10       364       sim     6       5.68      45
 20      3280       sim     8       7.39     190
 40      9841       sim     9       9.10     780
 80     88573       sim    11      10.81    3160
160    797161       sim    13      12.52   12720
320   7174453       sim    15      14.23   51040
640  21523360       sim    16      15.94  204480
Expoente estimado: 2.642 | teoria log(3) / log(1,5) = 2.7095
```

**Dicas:**

1. Os dois "2/3" se sobrepõem: primeiros vão de i até j - t, últimos de
   i + t até j. É essa sobreposição que garante que o maior chega ao fim.
2. Repare que as chamadas são sempre (3^p - 1)/2, com p a profundidade: a
   árvore é ternária e cheia. Cada fator 3/2 no tamanho acrescenta um
   nível, então p ≈ log_{3/2} n e as chamadas ≈ 3^(log_{3/2} n) =
   n^(log_{3/2} 3).
3. Por causa do ⌊ ⌋, a profundidade anda aos saltos: a razão entre n e 2n
   oscila. Estime o expoente num intervalo longo.
4. Resposta esperada: todos ordenados; com n = 640, 21523360 chamadas
   (contra 204480 comparações do bubble); expoente estimado 2.642, teoria
   2.7095.

```bash
~/LPEDC/rodar 17-analise-avancada/lista/P1723.c
```

---

**Exercício P1724** · ★★★ · A fila circular que dobra sem perder a ordem

A fila de senhas de um banco é um vetor CIRCULAR: ini aponta o primeiro,
num diz quantos há, e o próximo entra em (ini + num) % cap. Quando enche,
a fila dobra. A pegadinha: não dá para copiar o vetor velho como está,
porque a fila pode "dar a volta" no fim. É preciso copiar NA ORDEM DA FILA
(de ini até o fim, depois do começo até ini - 1) para o começo do vetor
novo, e fazer ini = 0.

Escreva enfileira, desenfileira e cresce, contando as cópias. Comece com
cap = 1 e rode o dia do esqueleto: 1000 rodadas de "chega, chega, atende,
chega, atende, chega, atende". Confira que as senhas saem na ordem em que chegaram,
mostre cada vez que a fila cresceu (de quanto para quanto, e com ini em
que posição) e o total de cópias, comparado com o número de enfileiramentos.


```text
Saída esperada:
cresce    1 ->    2 (ini era 0)
cresce    2 ->    4 (ini era 1)
cresce    4 ->    8 (ini era 2)
cresce    8 ->   16 (ini era 4)
cresce   16 ->   32 (ini era 8)
cresce   32 ->   64 (ini era 16)
cresce   64 ->  128 (ini era 32)
cresce  128 ->  256 (ini era 64)
cresce  256 ->  512 (ini era 128)
cresce  512 -> 1024 (ini era 256)
Crescimentos: 10 | cópias: 1023 | senhas enfileiradas: 4000
Atendidas em ordem: sim | na fila: 1000 (cap 1024)
```

**Dicas:**

1. Em cresce: para i de 0 a num - 1, novo[i] = velho[(ini + i) % cap].
   Depois libere o velho, ini = 0 e cap *= 2.
2. Mostre o ini ANTES da cópia: quando ele não é 0, a fila estava dando a
   volta, e um memcpy do vetor inteiro embaralharia a ordem.
3. As cópias somam 1 + 2 + 4 + ... + 512 = 1023: menos de uma cópia por
   senha enfileirada. Custo amortizado O(1).
4. Resposta esperada: 10 crescimentos (até cap 1024), quase todos com a
   fila dando a volta (ini na metade do vetor); 1023 cópias para 4000
   senhas; ordem conferida; 1000 senhas na fila no fim.

```bash
~/LPEDC/rodar 17-analise-avancada/lista/P1724.c
```

---

**Exercício P1725** · ★★★ · O método da substituição testado no computador

O merge sort com n qualquer (não só potência de 2) segue


```text
T(1) = 0,  T(n) = T(⌈n/2⌉) + T(⌊n/2⌋) + n - 1
```


(n - 1 é o pior caso de comparações ao intercalar). No método da
substituição, você chuta T(n) <= c · n lg n e prova por indução. O
computador não prova, mas mostra se o chute é bom e qual c serve.

Escreva um programa que calcule T(n) para todo n de 1 a 1000000 numa
tabela (de baixo para cima: T[n] só usa índices menores), e mostre:

- T(n) e T(n) / (n lg n) para n = 10, 100, ..., 1000000;
- o maior valor de T(n) / (n lg n) para 2 <= n <= 1000000, e em que n;
- a conferência da fórmula exata do pior caso do merge sort:
T(n) = n ⌈lg n⌉ - 2^⌈lg n⌉ + 1, para todo n de 1 a 1000000.


```text
Saída esperada:
      n          T(n)  T/(n lg n)
     10            25       0.753
    100           573       0.862
   1000          8977       0.901
  10000        123617       0.930
 100000       1568929       0.945
1000000      18951425       0.951
Maior razão: 0.9531, em n = 762546
Fórmula n teto(lg n) - 2^teto(lg n) + 1: 0 n errados
```

**Dicas:**

1. Um vetor de 1 milhão de long ocupa 8 MB: deixe-o global ou static.
2. T[n] = T[(n + 1) / 2] + T[n / 2] + n - 1: com inteiros, (n + 1) / 2 é
   o teto e n / 2 é o chão.
3. Para ⌈lg n⌉ e 2^⌈lg n⌉ sem double, ande com uma potência p que dobra
   enquanto p < n.
4. A razão fica abaixo de 1 em todo n: c = 1 serve no chute T(n) <= c n lg n,
   e o chute fica justo (a razão se aproxima de 1 por baixo).
5. Resposta esperada: a fórmula confere em todos os n; com n = 1000000,
   T = 18951425 e razão 0.951.

```bash
~/LPEDC/rodar 17-analise-avancada/lista/P1725.c
```

---

**Exercício P1726** · ★★★ · Busca na tabela de fretes: escada contra quadrantes

A transportadora tem uma tabela n × n de fretes, em reais, crescente em
cada linha (peso) e em cada coluna (distância): frete[i][j] = 10i + 7j.
Dado um valor, ela quer saber se ele aparece na tabela. Escreva as duas
buscas e conte as comparações com elementos da tabela:

- ESCADA: comece no canto de cima à direita. Se o valor é menor, vá para a
esquerda; se é maior, desça. No máximo 2n - 1 passos: Θ(n).
- QUADRANTES: compare com o elemento do meio m = frete[mi][mj]. Se o valor
é menor, ele não está no quadrante de baixo à direita (linhas >= mi e
colunas >= mj); se é maior, não está no de cima à esquerda (linhas <= mi
e colunas <= mj). Procure recursivamente nos TRÊS pedaços que sobram. A
recorrência é T(n) = 3 T(n/2) + 1, caso 1: Θ(n^(lg 3)) ≈ Θ(n^1,585).

Para n = 8, 16, 32 e 64, procure TODOS os valores de 0 até o maior da
tabela e mostre o pior caso de cada busca, 2n - 1 e n^(lg 3). Confira que as
duas buscas concordam em todos os valores.


```text
Saída esperada:
 n  escada  2n-1  quadrantes  n^lg3  concordam
 8      15    15          40     27        sim
16      25    31         121     81        sim
32      41    63         364    243        sim
64      73   127        1093    729        sim
```

**Dicas:**

1. A busca por quadrantes trabalha num retângulo (l0, c0, l1, c1); se ele
   está vazio (l0 > l1 ou c0 > c1), devolve falso sem comparar.
2. Com mi = (l0 + l1) / 2 e mj = (c0 + c1) / 2, os três pedaços para
   "valor menor" são (l0, c0, mi - 1, mj - 1), (l0, mj, mi - 1, c1) e
   (mi, c0, l1, mj - 1). Para "valor maior": (l0, mj + 1, mi, c1),
   (mi + 1, c0, l1, mj) e (mi + 1, mj + 1, l1, c1).
3. Dividir parece sempre melhor, mas aqui não é: três subproblemas de
   metade do lado dão n^1,585, que perde de 2n.
4. Resposta esperada: as buscas concordam; com n = 64, a escada faz no
   pior caso 73 comparações (o limite é 127) e a de quadrantes, 1093.

```bash
~/LPEDC/rodar 17-analise-avancada/lista/P1726.c
```

---

**Exercício P1727** · ★★★ · Montar o heap: n inserções ou BUILD-HEAP?

A central do SAMU recebe de uma vez a lista de chamados do turno e precisa
de um heap MÍNIMO pela gravidade (1 é o mais grave). Há dois jeitos:

- inserir um por um: cada inserção sobe o novo item, até lg i trocas. Total
O(n lg n);
- BUILD-HEAP (Floyd): põe tudo no vetor e chama "desce" para i de n/2 - 1
até 0. Um nó de altura h desce no máximo h níveis, e só ~n/2^(h+1) nós
têm altura h: a soma Σ h · n/2^(h+1) é menor que n. Total O(n).

Implemente os dois, contando as TROCAS, e teste no pior caso de cada um:
gravidades em ordem DECRESCENTE (n, n - 1, ..., 1), com n = 2^k - 1 para
k = 4, 8, 12, 16 e 20. Mostre as trocas, n lg n e n, e confira que os dois
heaps são válidos.


```text
Saída esperada:
      n   inserindo   build-heap      n lg n  válidos
     15          34           11          59      sim
    255        1538          247        2039      sim
   4095       40962         4083       49139      sim
  65535      917506        65519     1048559      sim
1048575    18874370      1048555    20971499      sim
```

**Dicas:**

1. Em ordem decrescente, cada novo item é o menor de todos: sobe até a
   raiz. São ⌊lg i⌋ trocas para o i-ésimo item.
2. No BUILD-HEAP, cada nó desce até uma folha. Para n = 2^k - 1, a soma das
   alturas dá exatamente n - k.
3. Heap mínimo válido: v[(i - 1) / 2] <= v[i] para todo i >= 1.
4. Resposta esperada: com n = 1048575, 18874370 trocas inserindo e 1048555
   com BUILD-HEAP (n - 20).

```bash
~/LPEDC/rodar 17-analise-avancada/lista/P1727.c
```

---

**Exercício P1728** · ★★★ · Fabrique o pior caso do merge sort

O merge sort intercala com no máximo n - 1 comparações; o pior caso total,
para n potência de 2, é n lg n - n + 1. Que entrada provoca isso? Uma
intercalação faz n - 1 comparações quando as duas metades se alternam até
o fim: o maior e o segundo maior ficam em metades diferentes, e assim por
diante. Dá para FABRICAR a entrada desfazendo o merge sort:


```text
pior(v[0..n-1] ordenado): os elementos das posições pares vão para a
metade esquerda, os das ímpares para a direita, e cada metade é
arrumada recursivamente do mesmo jeito.
```


Escreva pior() e um merge sort que conte comparações. Para n = 8, 16 e
1024, mostre as comparações com a entrada já ordenada, com a fabricada, a
fórmula n lg n - n + 1 e o limite inferior ⌈lg n!⌉ de qualquer ordenação
por comparação. Mostre também a entrada fabricada para n = 8 (com as notas
1 a 8 de uma prova).


```text
Saída esperada:
   n  ordenada  fabricada  n lg n - n + 1  teto(lg n!)
   8        12         17              17           16
  16        32         49              49           45
1024      5120       9217            9217         8770
Entrada fabricada (n = 8): 1 5 3 7 2 6 4 8
```

**Dicas:**

1. pior(v, n): copie os de índice par para aux[0..n/2-1] e os de índice
   ímpar para aux[n/2..n-1], chame pior nas duas metades de aux e copie de
   volta. Com n == 1, nada a fazer.
2. Na entrada ordenada, cada intercalação esgota a metade esquerda primeiro:
   n/2 comparações por nível, (n/2) lg n no total.
3. ⌈lg n!⌉ sai de somar log2(i) para i de 2 a n (com double) e arredondar
   para cima.
4. Resposta esperada: para n = 8, a entrada 1 5 3 7 2 6 4 8 dá 17
   comparações (fórmula 17, limite 16); para n = 1024, 9217 contra o limite
   8770.

```bash
~/LPEDC/rodar 17-analise-avancada/lista/P1728.c
```

---

**Exercício P1729** · ★★★ · A roda do amigo-secreto: simular ou recorrer?

Na roda de n pessoas, numeradas de 1 a n no sentido horário, a pessoa 1
começa: ela "pula" a vizinha, que sai da roda, e a vez passa para a pessoa
seguinte à que saiu. Isso se repete (sai uma, pula uma) até sobrar uma,
que escolhe o primeiro presente. É o problema de Josephus com passo 2.

Dois jeitos de achar quem sobra:

- SIMULAR com uma lista circular encadeada (malloc): n - 1 remoções, cada
uma com um passo de ponteiro: Θ(n) passos.
- RECORRER: J(1) = 1, J(2m) = 2 J(m) - 1 e J(2m + 1) = 2 J(m) + 1. Uma
chamada com n/2: C(n) = C(n/2) + 1 = ⌊lg n⌋ + 1 chamadas.

Escreva os dois, contando passos e chamadas, e confira com a fórmula
fechada J(n) = 2(n - 2^⌊lg n⌋) + 1. Rode para n = 5, 10, 41, 1000 e
100000.


```text
Saída esperada:
     n  simulação  passos  recursão  chamadas  fórmula
     5          3       4         3         3        3
    10          5       9         5         4        5
    41         19      40        19         6       19
  1000        977     999       977        10      977
100000      68929   99999     68929        17    68929
```

**Dicas:**

1. Lista circular: crie os nós 1..n, ligue o último ao primeiro e guarde
   em atual a pessoa da vez. Remover: alvo = atual->prox; atual->prox =
   alvo->prox; free(alvo); atual = atual->prox (conte 1 passo).
2. Sobra um nó só quando atual->prox == atual. Libere-o no fim.
3. Na recursão, J(m) é a resposta para metade da roda: depois da primeira
   volta, só sobram os ímpares, e a numeração deles é "dobrada".
4. Resposta esperada: sobram 3, 5, 19, 977 e 68929; a simulação gasta
   n - 1 passos, a recursão no máximo 17 chamadas.

```bash
~/LPEDC/rodar 17-analise-avancada/lista/P1729.c
```

---

**Exercício P1730** · ★★★ · Contador em que trocar o bit i custa 2^i

No contador binário comum, trocar qualquer bit custa 1, e n incrementos
custam menos que 2n: O(1) amortizado. Agora imagine um contador de placas
mecânicas em que a placa i é 2^i vezes mais pesada: trocar o bit i custa
2^i. O custo amortizado continua constante?

Análise agregada: em n = 2^k incrementos a partir de 0, o bit i (i < k)
troca n/2^i vezes, a 2^i cada: n por bit. Com k bits trocando, e mais a
placa k ligada uma vez no fim (custo 2^k = n), o total é n(k + 1) =
n(lg n + 1). Amortizado: lg n + 1, que CRESCE com n.

Escreva o contador (24 bits) com os dois custos e mostre, para n = 2^k com
k = 4, 8, 12, 16 e 20: o custo total comum, o total pesado, n(lg n + 1) e o
custo pesado por incremento.


```text
Saída esperada:
      n    comum      pesado  n(lg n + 1)  pesado/n
     16       31          80           80       5.0
    256      511        2304         2304       9.0
   4096     8191       53248        53248      13.0
  65536   131071     1114112      1114112      17.0
1048576  2097151    22020096     22020096      21.0
```

**Dicas:**

1. Um só incrementa() devolve as duas contagens por ponteiro: some 1 em
   *comum e 1 << i em *pesado a cada bit i trocado.
2. Use long para o custo pesado: com n = 2^20, passa de 20 milhões.
3. A análise agregada não muda de método, só de conta: o que importa é
   quantas vezes cada bit troca, multiplicado pelo preço do bit.
4. Resposta esperada: o comum fica em 2n - 1; o pesado bate com
   n(lg n + 1) em todas as linhas (21 por incremento com n = 2^20).

```bash
~/LPEDC/rodar 17-analise-avancada/lista/P1730.c
```

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
