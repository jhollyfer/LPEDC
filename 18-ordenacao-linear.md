<!-- Gerado por _gerador. Para mudar este arquivo, edite _gerador/modulos/18-ordenacao-linear/ e rode: cd _gerador && npm run gerar -->

# Módulo 18 · Ordenação além da comparação e seleção

No módulo 13 você ordenou comparando: bubble, selection, insertion, merge e
quick sort, todos decidindo a ordem com perguntas do tipo "`a` vem antes de
`b`?". No módulo 17 viu que esse jeito tem um piso: nenhuma ordenação que só
compara faz menos que uns n log₂ n comparações no pior caso. Este módulo
mostra o que existe fora desse piso.

A saída é olhar para os **dados**, e não só para o algoritmo. Se as chaves
são inteiros pequenos, o valor vira índice de vetor, e não há comparação
nenhuma: é o **counting sort**. Se as chaves têm dígitos ou bytes, dá para
ordenar casa por casa: **radix sort**. Se os valores estão bem espalhados num
intervalo conhecido, baldes por faixa resolvem quase tudo: **bucket sort**. Os
três são lineares e cobram um preço: memória extra e suposições sobre os
dados que, se forem falsas, viram escrita fora do vetor.

O módulo ainda traz dois parentes. O **shell sort** continua comparando, mas
dá ao insertion sort pulos longos e foge do n² com quase o mesmo código. E o
**quickselect** responde "quem é o k-ésimo menor?" (a mediana, o percentil,
os k maiores) sem ordenar nada, reaproveitando a separação do quick sort.

## O que você vai aprender

- **shell sort**: insertion sort com saltos, a sequência de Knuth e por que os saltos importam
- **counting sort**: contar, acumular e distribuir; a **estabilidade** e por que ela depende de um laço de trás para a frente
- **radix sort**: ordenar dígito a dígito (LSD), em base 10 e em base 256 com operadores de bits
- **bucket sort**: baldes por faixa com listas encadeadas, o caso médio O(n) e o pior caso O(n²)
- **quickselect**: o k-ésimo menor, a mediana e os k maiores em O(n) médio, com pivô sorteado para fugir do pior caso
- ordenar por **duas chaves** com passadas estáveis e medir 1 milhão de registros contra o `qsort`

## Antes de começar

Este módulo usa muito do que veio antes: o insertion sort (0093) e a
separação do quick sort (0095), listas encadeadas (0076 a 0078), filas
(0085), operadores de bits (0065), `malloc` e `calloc`, e o `qsort` com
função de comparação (0096). Se algum desses estiver enferrujado, revise
antes.

Nos vetores dos diagramas, cada linha de gavetas é um momento do algoritmo:
**roxo** marca o pivô ou a posição da vez, **amarelo** destaca o que você deve
acompanhar (uma fileira, um empate), **verde** é o que já está no lugar e
**cinza** é o que o algoritmo descartou. Faça o **Passo a passo** no papel
antes de conferir a tabela.

Os exemplos dos cinco primeiros assuntos cabem num arquivo só. O último
assunto, que ordena 1 milhão de registros, usa um TAD: `pix.h` e `pix.c`
ficam na pasta do assunto, e o `rodar` compila os dois junto com o exemplo.

Vários exemplos geram dados com um gerador de números pseudoaleatórios
escrito à mão (uma conta com `unsigned` que dá a volta), em vez do `rand`:
assim a saída é a mesma em qualquer computador. Os exemplos que medem
**tempo** com `clock()` são a exceção: os números mudam a cada execução, e
o AddressSanitizer do `rodar` deixa tudo mais lento. Compare as proporções,
não os valores.

Alguns exercícios de "ache o erro" trazem o bug de propósito: o programa
roda até o fim, mas a saída sai errada. O enunciado avisa.

| # | Assunto | Pasta |
| --- | --- | --- |
| [0119](#0119--shell-sort) | Shell sort | [`0119-shell-sort/`](18-ordenacao-linear/0119-shell-sort/) |
| [0120](#0120--counting-sort) | Counting sort | [`0120-counting-sort/`](18-ordenacao-linear/0120-counting-sort/) |
| [0121](#0121--radix-sort) | Radix sort | [`0121-radix-sort/`](18-ordenacao-linear/0121-radix-sort/) |
| [0122](#0122--bucket-sort) | Bucket sort | [`0122-bucket-sort/`](18-ordenacao-linear/0122-bucket-sort/) |
| [0123](#0123--quickselect) | Quickselect | [`0123-quickselect/`](18-ordenacao-linear/0123-quickselect/) |
| [0124](#0124--juntando-tudo) | Juntando tudo | [`0124-juntando-tudo/`](18-ordenacao-linear/0124-juntando-tudo/) |

---

## 0119 · Shell sort

O motorista da van de entregas recebe 10 pacotes jogados no banco de trás, com
os números de rota 62, 17, 85, 40, 9, 73, 28, 51, 94 e 33. Ele quer os
pacotes em ordem de rota. Se fizer como no insertion sort, pegando um por vez
e escorregando para a esquerda casa a casa, o pacote 9, que está na quinta
posição, vai precisar de quatro empurrões para chegar na frente.

Esse é o ponto fraco do **insertion sort** (assunto 0093): cada movimento
anda **uma casa só**. Um elemento que está longe do lugar certo paga uma
comparação e um deslocamento por casa que atravessa. Num vetor invertido, a
conta vira n²/2.

Em 1959, Donald Shell propôs: antes de andar de uma em uma casa, ande de
**h em h**. O **shell sort** faz o insertion sort várias vezes,
com saltos `h` cada vez menores:

1. com um salto grande, os elementos dão pulos longos e chegam **perto** do
   lugar certo;
2. com saltos menores, o vetor fica cada vez mais arrumado;
3. a última rodada é sempre com `h = 1`: o insertion sort comum, só que sobre
   um vetor **quase ordenado**, justamente o caso em que ele é rápido.

Depois da rodada com salto `h`, o vetor está **h-ordenado**: se você pegar
um elemento a cada `h` casas, a partir de qualquer posição, essa fileira está
em ordem. Com `h = 4`, as posições 0, 4, 8 formam uma fileira; 1, 5, 9
formam outra; 2, 6 e 3, 7 formam mais duas. São quatro insertion sorts
pequenos, entrelaçados no mesmo vetor.

A sequência de saltos mais conhecida é a de **Knuth**: `h = 3h + 1`, que dá
1, 4, 13, 40, 121, 364... Você começa com o maior salto abaixo de `n / 3` e
vai dividindo por 3. Com `n = 10`, os saltos são só 4 e 1.

Na primeira linha do desenho, cada cor é uma fileira de salto 4. Cada fileira
se ordena sozinha: o 9 troca com o 62, o 33 com o 73 e o 28 com o 85. Com
três movimentos, o vetor fica quase pronto:

<p align="center"><img src="18-ordenacao-linear/0119-shell-sort/ideia.svg" alt="Diagrama da ideia: Shell sort" width="858"></p>

Em C, o laço de dentro é o insertion sort do assunto 0093 com o `1` trocado
por `h`:

```c
#include <stdio.h>

void mostra(const int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf(" %d", v[i]);
    }
}

// insertion sort com saltos: os saltos seguem a sequência de Knuth
void shell_sort(int v[], int n) {
    int h = 1;
    while (h < n / 3) {
        h = 3 * h + 1;                  // 1, 4, 13, 40, 121...
    }
    for (; h >= 1; h /= 3) {            // ..., 121, 40, 13, 4, 1
        int movimentos = 0;
        // insertion sort entre elementos que estão a h casas de distância
        for (int i = h; i < n; i++) {
            int x = v[i];
            int j = i;
            while (j >= h && v[j - h] > x) {
                v[j] = v[j - h];        // empurra h casas para a direita
                j -= h;
                movimentos++;
            }
            v[j] = x;
        }
        printf("h = %d:", h);
        mostra(v, n);
        printf("  (%d movimentos)\n", movimentos);
    }
}

int main(void) {
    int rotas[] = {62, 17, 85, 40, 9, 73, 28, 51, 94, 33};
    int n = 10;

    printf("início:");
    mostra(rotas, n);
    printf("\n");
    shell_sort(rotas, n);
    return 0;
}
// Saída:
// início: 62 17 85 40 9 73 28 51 94 33
// h = 4: 9 17 28 40 62 33 85 51 94 73  (3 movimentos)
// h = 1: 9 17 28 33 40 51 62 73 85 94  (6 movimentos)
```

São 9 movimentos no total. O insertion sort comum, no mesmo vetor, faz 21:
o 9, sozinho, gastaria 4. No shell sort ele deu **um** pulo de 4 casas.

O `h /= 3` desfaz a conta `3 * h + 1`: na divisão inteira, 13 / 3 é 4 e
4 / 3 é 1. O laço de fora para quando `h` vira 0. O programa primeiro sobe
até o maior salto, depois desce rodada por rodada, e a última rodada é
sempre a do `h = 1`:

<p align="center"><img src="18-ordenacao-linear/0119-shell-sort/fluxograma.svg" alt="Fluxograma: Shell sort" width="437"></p>

### Passo a passo

A rodada com `h = 4`. O `i` anda de 4 até 9, e cada `v[i]` só se compara com
quem está 4, 8, ... casas para trás:

| i | x | compara com | ação | vetor depois |
| --- | --- | --- | --- | --- |
| 4 | 9 | v[0] = 62 | 62 pula para v[4]; 9 vai para v[0] | 9 17 85 40 62 73 28 51 94 33 |
| 5 | 73 | v[1] = 17 | nada | 9 17 85 40 62 73 28 51 94 33 |
| 6 | 28 | v[2] = 85 | 85 pula para v[6]; 28 vai para v[2] | 9 17 28 40 62 73 85 51 94 33 |
| 7 | 51 | v[3] = 40 | nada | 9 17 28 40 62 73 85 51 94 33 |
| 8 | 94 | v[4] = 62 | nada | 9 17 28 40 62 73 85 51 94 33 |
| 9 | 33 | v[5] = 73, depois v[1] = 17 | 73 pula para v[9]; 33 vai para v[5] | 9 17 28 40 62 33 85 51 94 73 |

> [!WARNING]
> A última rodada **tem** que ser com `h = 1`. As rodadas com salto grande só
> garantem que cada fileira está em ordem, não o vetor todo: depois do
> `h = 4`, o 62 ainda está antes do 33. Se você inventar sua própria
> sequência (5, 3, 2, por exemplo) e esquecer do 1, o programa termina sem
> erro e com o vetor fora de ordem. Outro tropeço: escrever a
> condição como `j > 0` (a do insertion sort comum). Com salto `h`, o certo é
> `j >= h`, senão `v[j - h]` lê antes do começo do vetor.

> [!TIP]
> **Por dentro do C:** o shell sort não usa memória extra: só `h`, `i`, `j` e
> `x`, umas poucas variáveis na pilha, qualquer que seja o tamanho do vetor.
> Por isso ele aparece em sistemas embarcados e no código de
> bibliotecas pequenas (a uClibc, por exemplo, implementa o `qsort` com shell
> sort). O custo depende dos saltos, e ninguém sabe a fórmula exata para a
> maioria das sequências: com a de Knuth, o pior caso é O(n^1,5), e na
> prática fica perto de n^1,25. Já os saltos `n/2, n/4, ..., 1` (os de Shell)
> têm pior caso O(n²): quando `n` é potência de 2, todos são pares menos o
> último, e posições pares e ímpares só se comparam na rodada final.

> [!NOTE]
> **Pergunta para você:** o shell sort é estável? Pense em `5 3a 3b 1` (dois
> 3 iguais, o `a` antes do `b`) com saltos 2 e 1. Faça as duas rodadas no
> papel e veja em que ordem os dois 3 terminam.

### Hora de praticar

Arquivos em [`0119-shell-sort/`](18-ordenacao-linear/0119-shell-sort/).

**Exemplo A237 · A escolha dos saltos muda tudo**

```c
#include <stdio.h>
#include <stdlib.h>

#define N 4096 // potência de 2, de propósito

static long comparacoes;
static unsigned semente;

// gerador de números pseudoaleatórios simples: a mesma semente dá sempre a
// mesma sequência, então a saída é igual em qualquer computador
int sorteia(void) {
    semente = semente * 1103515245u + 12345u;
    return (int) ((semente >> 16) % 100000);
}

// uma rodada de insertion sort com salto h
void rodada(int v[], int n, int h) {
    for (int i = h; i < n; i++) {
        int x = v[i];
        int j = i;
        while (j >= h) {
            comparacoes++;
            if (v[j - h] <= x) {
                break;
            }
            v[j] = v[j - h];
            j -= h;
        }
        v[j] = x;
    }
}

void so_insertion(int v[], int n) {
    rodada(v, n, 1);
}

void saltos_de_shell(int v[], int n) { // n/2, n/4, ..., 1
    for (int h = n / 2; h >= 1; h /= 2) {
        rodada(v, n, h);
    }
}

void saltos_de_knuth(int v[], int n) { // ..., 40, 13, 4, 1
    int h = 1;
    while (h < n / 3) {
        h = 3 * h + 1;
    }
    for (; h >= 1; h /= 3) {
        rodada(v, n, h);
    }
}

// tipo 0: aleatório; 1: decrescente; 2: metade de baixo nas posições ímpares,
// metade de cima nas pares (só se misturam quando o salto é ímpar)
void testa(const char *nome, void (*ordena)(int[], int), int tipo) {
    int *v = malloc(N * sizeof(int));
    if (v == NULL) {
        return;
    }
    semente = 2024;
    for (int i = 0; i < N; i++) {
        if (tipo == 0) {
            v[i] = sorteia();
        } else if (tipo == 1) {
            v[i] = N - i;
        } else {
            v[i] = i % 2 == 0 ? N / 2 + i / 2 : i / 2;
        }
    }
    comparacoes = 0;
    ordena(v, N);
    int ok = 1;
    for (int i = 1; i < N; i++) {
        if (v[i - 1] > v[i]) {
            ok = 0;
        }
    }
    printf("%-18s %10ld comparações%s\n", nome, comparacoes, ok ? "" : " (ERRO)");
    free(v);
}

int main(void) {
    const char *titulos[] = {"aleatórios", "decrescentes", "grandes nas pares, pequenos nas ímpares"};
    for (int t = 0; t < 3; t++) {
        printf("%d números %s:\n", N, titulos[t]);
        testa("  insertion sort", so_insertion, t);
        testa("  saltos de Shell", saltos_de_shell, t);
        testa("  saltos de Knuth", saltos_de_knuth, t);
    }
    return 0;
}
// Saída:
// 4096 números aleatórios:
//   insertion sort      4245375 comparações
//   saltos de Shell      168264 comparações
//   saltos de Knuth       77422 comparações
// 4096 números decrescentes:
//   insertion sort      8386560 comparações
//   saltos de Shell       65538 comparações
//   saltos de Knuth       42751 comparações
// 4096 números grandes nas pares, pequenos nas ímpares:
//   insertion sort      2102270 comparações
//   saltos de Shell     2143232 comparações
//   saltos de Knuth       45536 comparações
//
// No último caso, os saltos 2048, 1024, ..., 2 são todos pares: as posições
// pares nunca encontram as ímpares, e a rodada final com h = 1 faz o
// trabalho inteiro de um insertion sort. Os saltos de Knuth alternam pares e
// ímpares (40, 13, 4, 1) e misturam tudo cedo.
```

```bash
~/LPEDC/rodar 18-ordenacao-linear/0119-shell-sort/A237.c
```

**Exemplo A238 · O shell sort embaralha os empates**

```c
#include <stdio.h>

typedef struct {
    char hora[6]; // "19:05"
    int zona;     // zona de entrega: 1, 2 ou 3
} Pedido;

// ordena pela zona com saltos dados; o último salto é sempre 1
void ordena_por_zona(Pedido v[], int n, const int saltos[], int qtd) {
    for (int s = 0; s < qtd; s++) {
        int h = saltos[s];
        for (int i = h; i < n; i++) {
            Pedido x = v[i];
            int j = i;
            while (j >= h && v[j - h].zona > x.zona) { // só ">": empate não anda
                v[j] = v[j - h];
                j -= h;
            }
            v[j] = x;
        }
    }
}

void mostra(const char *rotulo, const Pedido v[], int n) {
    printf("%s\n", rotulo);
    for (int z = 1; z <= 3; z++) {
        printf("  zona %d:", z);
        for (int i = 0; i < n; i++) {
            if (v[i].zona == z) {
                printf(" %s", v[i].hora);
            }
        }
        printf("\n");
    }
}

int main(void) {
    // os pedidos chegam em ordem de horário
    Pedido chegada[] = {
        {"19:00", 2}, {"19:04", 3}, {"19:07", 1}, {"19:11", 2}, {"19:15", 1},
        {"19:18", 3}, {"19:22", 2}, {"19:26", 1}, {"19:30", 3}, {"19:33", 2},
    };
    int n = 10;
    Pedido a[10], b[10];
    for (int i = 0; i < n; i++) {
        a[i] = b[i] = chegada[i];
    }

    int so_um[] = {1};
    ordena_por_zona(a, n, so_um, 1);           // é o insertion sort
    mostra("insertion sort (saltos 1):", a, n);

    int knuth[] = {4, 1};
    ordena_por_zona(b, n, knuth, 2);           // é o shell sort
    mostra("shell sort (saltos 4 e 1):", b, n);
    return 0;
}
// Saída:
// insertion sort (saltos 1):
//   zona 1: 19:07 19:15 19:26
//   zona 2: 19:00 19:11 19:22 19:33
//   zona 3: 19:04 19:18 19:30
// shell sort (saltos 4 e 1):
//   zona 1: 19:15 19:07 19:26
//   zona 2: 19:33 19:00 19:22 19:11
//   zona 3: 19:04 19:30 19:18
//
// Os dois deixam as zonas em ordem, mas só o insertion sort é ESTÁVEL: dentro
// de cada zona, os horários continuam na ordem de chegada. No shell sort,
// na rodada h = 4, o pedido das 19:00 foi empurrado da posição 0 para a 4 e o
// das 19:33 pulou da posição 9 para a 1: os dois, da zona 2, se cruzaram sem
// nunca serem comparados. A rodada h = 1 não desfaz isso, porque empates não
// se movem.
```

```bash
~/LPEDC/rodar 18-ordenacao-linear/0119-shell-sort/A238.c
```

#### Exercícios

**Exercício E709** · ★☆☆

Antes de ordenar, o shell sort escolhe os saltos. Escreva a função
void mostra_saltos(int n), que mostra os saltos de Knuth (h = 3h + 1) que
o shell sort do texto usa para um vetor de n elementos, na ordem em que
eles são usados (do maior para o 1). Chame para n = 10, 100, 1000 e
1000000.


```text
Saída esperada:
n = 10: 4 1
n = 100: 40 13 4 1
n = 1000: 364 121 40 13 4 1
n = 1000000: 797161 265720 88573 29524 9841 3280 1093 364 121 40 13 4 1
```

**Dicas:**

1. Primeiro suba: comece com h = 1 e faça h = 3 * h + 1 enquanto
   h < n / 3.
2. Depois desça com h /= 3 até h chegar a 0, mostrando cada h.
3. Um milhão de elementos pede só 13 rodadas.

```bash
~/LPEDC/rodar 18-ordenacao-linear/0119-shell-sort/E709.c
```

**Exercício E710** · ★☆☆

O técnico do time de vôlei quer as idades das 11 atletas em ordem. Em vez
dos saltos de Knuth, use os saltos fixos 5, 3 e 1. O main já faz as três
rodadas e mostra o vetor depois de cada uma: complete a função rodada,
que faz o insertion sort entre os elementos a h casas de distância.


```text
Saída esperada:
início: 31 19 27 22 35 18 24 29 20 33 26
h = 5: 18 19 27 20 33 26 24 29 22 35 31
h = 3: 18 19 22 20 29 26 24 31 27 35 33
h = 1: 18 19 20 22 24 26 27 29 31 33 35
```

**Dicas:**

1. É o laço de dentro do shell_sort do texto, sem o laço dos saltos.
2. O i começa em h, e o j anda de h em h para trás: j >= h e v[j - h].
3. Com h = 5, as fileiras são 31 18 26, 19 24, 27 29, 22 20 e 35 33.

```bash
~/LPEDC/rodar 18-ordenacao-linear/0119-shell-sort/E710.c
```

**Exercício E711** · ★★☆

A lista de convidados da festa precisa ir para a portaria em ordem
alfabética. Escreva void shell_nomes(const char *v[], int n), um shell
sort com os saltos de Knuth para um vetor de strings, que troca só os
ponteiros (as letras não saem do lugar). Conte as comparações (cada strcmp
conta uma) numa variável static.


```text
Convidados: Rafael Bianca Tiago Larissa Diego Amanda Paulo Helena Caio
            Sofia Murilo Elisa
```



```text
Saída esperada:
Amanda, Bianca, Caio, Diego, Elisa, Helena, Larissa, Murilo, Paulo, Rafael, Sofia, Tiago
36 comparações
```

**Dicas:**

1. É o shell_sort do texto com int trocado por const char * e
   v[j - h] > x trocado por strcmp(v[j - h], x) > 0.
2. Com n = 12, os saltos são 4 e 1.
3. Para contar cada strcmp, escreva o while só com j >= h e faça o teste
   do strcmp dentro dele, com um break.

```bash
~/LPEDC/rodar 18-ordenacao-linear/0119-shell-sort/E711.c
```

**Exercício E712** · ★★☆

Um vetor está h-ORDENADO quando toda fileira de passo h (v[i], v[i + h],
v[i + 2h], ...) está em ordem. O programa abaixo roda o shell sort num
vetor de 40 números e, depois de cada rodada, pergunta se o vetor está
13-, 4- e 1-ordenado. Escreva a função esta_h_ordenado e rode.


```text
Saída esperada:
início: 13-ordenado? não, 4-ordenado? não, 1-ordenado? não
h = 13: 13-ordenado? sim, 4-ordenado? não, 1-ordenado? não
h =  4: 13-ordenado? sim, 4-ordenado? sim, 1-ordenado? não
h =  1: 13-ordenado? sim, 4-ordenado? sim, 1-ordenado? sim
```


Na coluna do 13, a rodada com h = 4 mexe no vetor, mas não desfaz o
que a rodada h = 13 arrumou. É isso que faz cada rodada aproveitar o
trabalho da anterior.

**Dicas:**

1. Não precisa separar as fileiras: basta conferir v[i - h] <= v[i] para
   todo i de h até n - 1.
2. Achou um par fora de ordem? Pode devolver false na hora.
3. 1-ordenado é o mesmo que ordenado.

```bash
~/LPEDC/rodar 18-ordenacao-linear/0119-shell-sort/E712.c
```

**Exercício E713** · ★★★

Ache os bugs. Este shell sort deveria ordenar as 13 senhas de atendimento
do cartório, mas a saída sai fora de ordem. Não há erro de memória: o
programa roda até o fim, só que errado. São DOIS erros, um em cada laço
while. Conserte os dois e rode.


```text
Saída esperada:
2 5 8 11 14 17 20 23 26 29 32 35 38
```

**Dicas:**

1. Mostre o valor de h no começo de cada rodada. Quantas rodadas
   acontecem? Qual devia ser a última?
2. Com o primeiro erro consertado, mostre o vetor depois de cada rodada.
   Na rodada h = 1, o v[1] chega a ser comparado com o v[0]?
3. Compare as condições com as do shell_sort do texto.
4. Resposta esperada: o laço dos saltos tem que rodar também com h = 1
   (while (h >= 1), e não while (h > 1)); e o laço de dentro tem que
   andar enquanto j >= h, e não j > h. Consertado, sai a linha acima.

```bash
~/LPEDC/rodar 18-ordenacao-linear/0119-shell-sort/E713.c
```

**Exercício E714** · ★★★

Uma INVERSÃO é um par de posições i < j com v[i] > v[j]: um par fora de
ordem. Vetor ordenado tem 0 inversões. Estenda o programa abaixo para
medir o que cada rodada do shell sort faz:

a) escreva long inversoes(const int v[], int n) (dois laços, O(n²));

b) conte os movimentos (v[j] = v[j - h]) de cada rodada;

c) depois de cada rodada, mostre as inversões que sobraram e os
movimentos da rodada; no fim, o total de movimentos comparado com as
inversões do início.


```text
Saída esperada:
início:  9775 inversões
h = 121:  7359 inversões,   12 movimentos
h =  40:  2602 inversões,  131 movimentos
h =  13:  1004 inversões,  172 movimentos
h =   4:   288 inversões,  234 movimentos
h =   1:     0 inversões,  288 movimentos
total: 837 movimentos (o insertion sort faria 9775)
```


Na primeira rodada, 12 movimentos desfizeram 2416 inversões. Na última,
os movimentos são exatamente as inversões que sobraram.

**Dicas:**

1. Guarde as inversões do início numa variável: o insertion sort comum
   faz um movimento por inversão, então esse é o custo dele.
2. Um pulo de h casas pode desfazer várias inversões de uma vez: todos os
   elementos que ficavam entre as duas posições também entram na conta.
3. Formatos: "h = %3d: %5ld inversões, %4ld movimentos".

```bash
~/LPEDC/rodar 18-ordenacao-linear/0119-shell-sort/E714.c
```

---

## 0120 · Counting sort

No fim do expediente, a dona da lanchonete olha as avaliações do dia no app
de entregas. Cada pedido recebeu de 0 a 4 estrelas, e ela quer a lista em
ordem de nota para responder primeiro os clientes insatisfeitos. São 8
pedidos, de A a H, com 3, 1, 3, 2, 1, 4, 0 e 3 estrelas.

Ela não compara pedido com pedido. Faz cinco montes, um para cada nota, joga
cada pedido no seu monte e depois junta os montes, do 0 ao 4.

No assunto 0117 você viu que nenhuma ordenação **por comparação** faz menos
que uns n log₂ n testes no pior caso. O **counting sort** (ordenação por
contagem) não fura esse limite, porque não compara: usa o **valor** da chave
como **índice** de um vetor. Para isso, as chaves precisam
ser inteiros num intervalo pequeno, de 0 a k - 1.

O algoritmo tem três passos, cada um um laço simples:

1. **contar**: `c[x]` recebe quantos elementos têm a chave `x`;
2. **acumular**: cada `c[x]` passa a valer quantos têm chave **menor ou
   igual** a `x`. Isso diz onde termina o bloco de cada valor na saída: as
   três avaliações de 3 estrelas ocupam as posições 4, 5 e 6, porque há 7
   avaliações com até 3 estrelas;
3. **distribuir**: percorra a entrada **de trás para a frente** e coloque
   cada elemento na última vaga livre do seu bloco: `c[x]--` e
   `saida[c[x]] = v[i]`.

De trás para a frente, entre chaves iguais, quem vem por último na entrada
ocupa a última vaga do bloco. A ordem original dos empates se mantém: o
counting sort é **estável**. Essa propriedade faz dele a peça central do
radix sort, no próximo assunto.

O Cormen escreve `COUNTING-SORT(A, n, k)` com vetores de 1 a n e chaves de 0
a **k**, portanto k + 1 contadores; aqui, em C, as chaves vão de 0 a k - 1. A
conta é a mesma: Θ(n + k), que vira Θ(n) quando k = O(n).

A entrada passa uma vez para contar e outra para distribuir. Os três pedidos
de 3 estrelas (A, C e H, em verde) chegam à saída na mesma ordem em que
estavam:

<p align="center"><img src="18-ordenacao-linear/0120-counting-sort/ideia.svg" alt="Diagrama da ideia: Counting sort" width="858"></p>

No código, a saída vai para outro vetor: o counting sort não ordena no
lugar.

```c
#include <stdio.h>

#define K 5 // estrelas vão de 0 a 4

typedef struct {
    char codigo; // pedido 'A', 'B', ...
    int estrelas;
} Avaliacao;

void mostra(const char *rotulo, const int c[]) {
    printf("%-10s", rotulo);
    for (int x = 0; x < K; x++) {
        printf(" %d", c[x]);
    }
    printf("\n");
}

// ordena v pelas estrelas, de forma estável, e grava o resultado em saida
void counting_sort(const Avaliacao v[], Avaliacao saida[], int n) {
    int c[K] = {0};
    for (int i = 0; i < n; i++) {
        c[v[i].estrelas]++;              // 1) conta cada valor
    }
    mostra("contagem:", c);
    for (int x = 1; x < K; x++) {
        c[x] += c[x - 1];                // 2) c[x] = quantos têm <= x
    }
    mostra("acumulado:", c);
    for (int i = n - 1; i >= 0; i--) {   // 3) de trás para a frente
        int x = v[i].estrelas;
        c[x]--;
        saida[c[x]] = v[i];              // última vaga livre do bloco x
    }
}

int main(void) {
    Avaliacao v[] = {{'A', 3}, {'B', 1}, {'C', 3}, {'D', 2},
                     {'E', 1}, {'F', 4}, {'G', 0}, {'H', 3}};
    Avaliacao saida[8];
    int n = 8;

    counting_sort(v, saida, n);
    printf("ordenado: ");
    for (int i = 0; i < n; i++) {
        printf(" %c%d", saida[i].codigo, saida[i].estrelas);
    }
    printf("\n");
    return 0;
}
// Saída:
// contagem:  1 2 1 3 1
// acumulado: 1 3 4 7 8
// ordenado:  G0 B1 E1 D2 A3 C3 H3 F4
```

### Passo a passo

O terceiro laço, com o acumulado `1 3 4 7 8` no começo. Cada linha usa uma
vaga e diminui o contador daquela nota:

| i | pedido | c[x] antes | vai para | c depois |
| --- | --- | --- | --- | --- |
| 7 | H3 | c[3] = 7 | saida[6] | 1 3 4 6 8 |
| 6 | G0 | c[0] = 1 | saida[0] | 0 3 4 6 8 |
| 5 | F4 | c[4] = 8 | saida[7] | 0 3 4 6 7 |
| 4 | E1 | c[1] = 3 | saida[2] | 0 2 4 6 7 |
| 3 | D2 | c[2] = 4 | saida[3] | 0 2 3 6 7 |
| 2 | C3 | c[3] = 6 | saida[5] | 0 2 3 5 7 |
| 1 | B1 | c[1] = 2 | saida[1] | 0 1 3 5 7 |
| 0 | A3 | c[3] = 5 | saida[4] | 0 1 3 4 7 |

No fim, cada `c[x]` aponta para o **começo** do bloco de `x`.

São três laços em sequência, nenhum dentro do outro. Dois andam pelos n
elementos e um pelas k chaves, então o custo é **O(n + k)**:

<p align="center"><img src="18-ordenacao-linear/0120-counting-sort/fluxograma.svg" alt="Fluxograma: Counting sort" width="459"></p>

> [!WARNING]
> Se o terceiro laço for da frente para trás (`for (int i = 0; i < n; i++)`)
> com o mesmo `c[x]--`, o vetor sai ordenado pelas estrelas, mas os empates
> saem **invertidos**: H3 C3 A3 em vez de A3 C3 H3. O programa não dá erro,
> e o estrago só aparece quando a ordem dos empates importa (no radix
> sort, ela importa sempre). Outro cuidado: a chave tem que caber no vetor.
> Uma nota 5, ou uma nota negativa, vira `c[5]` ou `c[-1]`: escrita fora do
> vetor, que o AddressSanitizer pega e um programa sem ele ignora.

> [!TIP]
> **Por dentro do C:** o counting sort troca tempo por memória. Ele precisa
> de `k` contadores e de um vetor de saída com `n` elementos, além da
> entrada. Com notas de 0 a 4, `c` tem 20 bytes e mora na pilha. Com chaves
> de 0 a 1 bilhão, `c` teria 4 GB: aí o O(n + k) deixa de ser linear na
> prática, porque o `k` domina. A regra é usar counting sort quando `k` é da
> ordem de `n` ou menor. E o laço `c[v[i].estrelas]++` acessa a memória de
> `c` fora de ordem, pulando de contador em contador: com `c` pequeno, tudo
> cabe no cache e cada acesso é quase de graça.

> [!NOTE]
> **Pergunta para você:** e se você só precisasse dos números, sem o código
> do pedido? Dá para pular o vetor de saída e o acumulado: basta escrever
> cada nota `c[x]` vezes, em ordem. Por que essa versão curta não serve para
> ordenar as avaliações com o código junto?

### Hora de praticar

Arquivos em [`0120-counting-sort/`](18-ordenacao-linear/0120-counting-sort/).

**Exemplo A239 · Temperaturas abaixo de zero**

```c
#include <stdio.h>
#include <stdlib.h>

// versão curta: só números, sem registros junto. A chave pode ser negativa,
// então o índice do contador é (valor - menor)
int ordena_temperaturas(int v[], int n) {
    int menor = v[0], maior = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] < menor) {
            menor = v[i];
        }
        if (v[i] > maior) {
            maior = v[i];
        }
    }
    int k = maior - menor + 1;           // quantos valores possíveis
    int *c = calloc(k, sizeof(int));     // calloc já zera os contadores
    if (c == NULL) {
        return 0;
    }
    for (int i = 0; i < n; i++) {
        c[v[i] - menor]++;               // -3 vai para c[0], -2 para c[1]...
    }
    int pos = 0;
    for (int x = 0; x < k; x++) {        // reescreve cada valor c[x] vezes
        for (int r = 0; r < c[x]; r++) {
            v[pos++] = x + menor;
        }
    }
    free(c);
    return k;
}

int main(void) {
    // mínimas de 14 madrugadas de julho numa cidade serrana, em graus
    int minimas[] = {4, -2, 7, 0, -3, 4, 9, 1, -2, 4, 12, 0, 3, -1};
    int n = 14;

    int k = ordena_temperaturas(minimas, n);
    printf("%d leituras, %d contadores\n", n, k);
    for (int i = 0; i < n; i++) {
        printf(i == 0 ? "%d" : " %d", minimas[i]);
    }
    printf("\nmediana: entre %d e %d graus\n", minimas[n / 2 - 1], minimas[n / 2]);
    return 0;
}
// Saída:
// 14 leituras, 16 contadores
// -3 -2 -2 -1 0 0 1 3 4 4 4 7 9 12
// mediana: entre 1 e 3 graus
//
// De -3 a 12 são 16 valores possíveis: o vetor c tem 16 contadores, mesmo
// que só 10 temperaturas diferentes apareçam. Sem o "- menor", o -3 viraria
// c[-3], uma escrita antes do começo do vetor.
```

```bash
~/LPEDC/rodar 18-ordenacao-linear/0120-counting-sort/A239.c
```

**Exemplo A240 · A chamada pela inicial**

```c
#include <stdio.h>

#define LETRAS 26

// a chave não precisa ser um campo pronto: aqui é a inicial do nome,
// convertida em 0..25
int chave(const char *nome) {
    return nome[0] - 'A';
}

void por_inicial(const char *v[], const char *saida[], int n) {
    int c[LETRAS] = {0};
    for (int i = 0; i < n; i++) {
        c[chave(v[i])]++;
    }
    for (int x = 1; x < LETRAS; x++) {
        c[x] += c[x - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        saida[--c[chave(v[i])]] = v[i];  // só o ponteiro é copiado
    }
}

int main(void) {
    // ordem de inscrição na escolinha de futebol
    const char *inscritos[] = {"Mateus", "Bruna", "Lucas", "Beatriz", "Murilo", "Ana",
                               "Lara", "Bento", "Miguel", "Alice"};
    const char *chamada[10];
    int n = 10;

    por_inicial(inscritos, chamada, n);
    char letra = ' ';
    for (int i = 0; i < n; i++) {
        if (chamada[i][0] != letra) {    // começou um bloco novo
            letra = chamada[i][0];
            printf("%s%c:", i == 0 ? "" : "\n", letra);
        }
        printf(" %s", chamada[i]);
    }
    printf("\n");
    return 0;
}
// Saída:
// A: Ana Alice
// B: Bruna Beatriz Bento
// L: Lucas Lara
// M: Mateus Murilo Miguel
//
// As iniciais estão em ordem, mas dentro de cada letra os nomes seguem a
// ordem de inscrição: Ana veio antes de Alice, então continua antes. O
// counting sort ordena por UMA chave e não mexe no resto. Para a ordem
// alfabética completa, é preciso ordenar letra por letra: é o radix sort.
```

```bash
~/LPEDC/rodar 18-ordenacao-linear/0120-counting-sort/A240.c
```

#### Exercícios

**Exercício E715** · ★☆☆

As notas da prova de 20 alunos vão de 0 a 10. Ordene o vetor com a versão
curta do counting sort (conte cada nota e reescreva cada uma c[x] vezes,
sem vetor de saída) e mostre também a nota mais comum, usando os mesmos
contadores.


```text
Saída esperada:
ordenadas: 2 3 4 5 5 5 5 6 6 7 7 7 7 7 8 8 8 9 10 10
mais comum: 7 (5 alunos)
```

**Dicas:**

1. int c[11] = {0}; tem um contador para cada nota, de 0 a 10.
2. Para reescrever, use um índice pos que só anda para a frente.
3. A nota mais comum é o x com o maior c[x]: dá para achar no mesmo laço
   que reescreve o vetor.

```bash
~/LPEDC/rodar 18-ordenacao-linear/0120-counting-sort/E715.c
```

**Exercício E716** · ★☆☆

A sapataria guarda quantos pares tem de cada tamanho, do 34 ao 44, e quer
arrumar a prateleira em ordem de tamanho, um par ao lado do outro. Complete
o programa: transforme a contagem em acumulado e, para cada tamanho que
tem estoque, mostre em que posições da prateleira ele fica.


```text
Saída esperada:
total: 27 pares
tamanho 34: posições 0 a 1
tamanho 36: posições 2 a 4
tamanho 37: posições 5 a 9
tamanho 38: posições 10 a 13
tamanho 39: posições 14 a 19
tamanho 40: posições 20 a 22
tamanho 41: posições 23 a 24
tamanho 43: posição 25
tamanho 44: posição 26
```

**Dicas:**

1. Depois do acumulado, c[x] diz quantos pares têm tamanho até x + 34.
   O total é o último contador.
2. O bloco do tamanho x vai de c[x - 1] até c[x] - 1. Para x = 0, o
   começo é 0.
3. Bloco vazio (começo igual a c[x]) não aparece; bloco de um par só usa
   "posição", no singular.

```bash
~/LPEDC/rodar 18-ordenacao-linear/0120-counting-sort/E716.c
```

**Exercício E717** · ★★☆

Na triagem do pronto-socorro, cada paciente recebe uma cor de risco:
vermelho, laranja, amarelo, verde ou azul, do mais grave para o menos
grave. A fila de atendimento é por cor e, dentro da mesma cor, por ordem
de chegada. Escreva ordena_triagem, um counting sort ESTÁVEL que usa como
chave a posição da cor no vetor ordem_cores, e mostre a fila.


```text
Saída esperada:
 1. Rita  (vermelho)
 2. Otto  (vermelho)
 3. Davi  (laranja)
 4. Ivo   (laranja)
 5. Joana (amarelo)
 6. Caio  (amarelo)
 7. Sara  (amarelo)
 8. Pedro (verde)
 9. Nina  (verde)
10. Lia   (azul)
```

**Dicas:**

1. Escreva antes int chave(const Paciente *p), que procura p->cor em
   ordem_cores com strcmp e devolve o índice (0 a 4).
2. Depois é o counting_sort do texto com v[i].estrelas trocado por
   chave(&v[i]). O vetor de saída é outro vetor de Paciente.
3. Formato de cada linha: "%2d. %-5s (%s)\n".

```bash
~/LPEDC/rodar 18-ordenacao-linear/0120-counting-sort/E717.c
```

**Exercício E718** · ★★☆

Duas palavras são ANAGRAMAS quando usam as mesmas letras, nas mesmas
quantidades: "porta" e "tropa". Um jeito de conferir: ordene as letras de
cada uma e compare. Escreva void ordena_letras(char s[]), um counting sort
das letras da própria string, com um contador para cada valor possível de
char (256), e use no programa abaixo.


```text
Saída esperada:
alegria -> aaegilr | regalia -> aaegilr: anagramas
porta -> aoprt | tropa -> aoprt: anagramas
mesa -> aems | seta -> aest: não são anagramas
carro -> acorr | corra -> acorr: anagramas
```

**Dicas:**

1. int c[256] = {0}; e c[(unsigned char) s[i]]++ até achar o '\0'.
2. Por que o cast? O char pode ter sinal: uma letra acentuada em UTF-8
   vira um byte negativo, e c[-61] escreve antes do vetor.
3. Depois, reescreva a string: cada x de 0 a 255, c[x] vezes. O '\0' do
   fim fica onde estava, porque o tamanho não muda.

```bash
~/LPEDC/rodar 18-ordenacao-linear/0120-counting-sort/E718.c
```

**Exercício E719** · ★★★

Ache o bug. A central de suporte ordena os chamados por prioridade (0 é
urgente, 3 pode esperar) e, dentro da mesma prioridade, quer atender
primeiro quem abriu antes (número menor). O programa compila e roda, mas
a ordem dentro de cada prioridade sai errada. Faça duas coisas:

a) escreva a função estavel, que confere a fila pronta: entre chamados de
mesma prioridade, os números têm que vir crescentes. Rode: com o bug,
tem que aparecer "estável? não";

b) ache e conserte o erro do counting sort e rode de novo.


```text
Saída esperada depois de (a):
p0: 110 106 102
p1: 108 105
p2: 107 104 101
p3: 109 103
estável? não
```



```text
Saída esperada depois de (b):
p0: 102 106 110
p1: 105 108
p2: 101 104 107
p3: 103 109
estável? sim
```

**Dicas:**

1. Na função estavel, compare cada fila[i] com fila[i - 1]: mesma
   prioridade e número menor quer dizer que a ordem se perdeu.
2. O erro está em um dos três laços de ordena. Qual deles decide quem
   fica com a ÚLTIMA vaga de cada bloco?
3. Resposta esperada: o terceiro laço anda da frente para trás. Com
   c[x]--, o primeiro chamado de cada prioridade fica com a última vaga
   do bloco, e os empates saem invertidos. O certo é
   for (int i = n - 1; i >= 0; i--).

```bash
~/LPEDC/rodar 18-ordenacao-linear/0120-counting-sort/E719.c
```

**Exercício E720** · ★★★

Quem quebra códigos secretos começa contando letras. Escreva um programa
que mostre as letras da frase abaixo da MAIS frequente para a menos
frequente (só as que aparecem), com empates em ordem alfabética:


```text
o rato roeu a roupa do rei de roma e a rainha ficou brava
```



```text
Saída esperada:
a:9 o:7 r:7 e:4 i:3 u:3 d:2 b:1 c:1 f:1 h:1 m:1 n:1 p:1 t:1 v:1
```


A regra: nada de comparar letra com letra. Conte as frequências (um
contador por letra) e depois ordene as 26 letras com um counting sort
estável cuja chave é a frequência.

**Dicas:**

1. freq[letra - 'a']++ para cada letra de 'a' a 'z' (pule os espaços).
2. O counting sort deixa as chaves em ordem crescente. Para a ordem
   decrescente, use a chave maior - freq[l], em que maior é a maior
   frequência: a letra mais frequente fica com chave 0.
3. Se as letras entrarem de 'a' a 'z' e o sort for estável (terceiro
   laço de trás para a frente), os empates saem em ordem alfabética sem
   nenhum esforço extra.
4. O vetor ordenado guarda letras (0 a 25), não frequências: ranking[i]
   é a letra que ficou na posição i.

```bash
~/LPEDC/rodar 18-ordenacao-linear/0120-counting-sort/E720.c
```

---

## 0121 · Radix sort

Antes dos computadores de hoje, os censos eram processados com cartões
perfurados e uma máquina **classificadora**. Ela olhava uma coluna do cartão e
jogava cada cartão num de 10 escaninhos, do 0 ao 9. O operador juntava os
escaninhos em ordem e passava o maço de novo, agora pela coluna seguinte.
Depois de passar por todas as colunas, o maço estava ordenado.

Parece ao contrário, mas a máquina começava pela coluna **menos**
significativa. O **radix sort** (ordenação digital, ou por raiz) faz o mesmo
com números:

1. ordene pelo dígito das **unidades**;
2. depois pelo das **dezenas**;
3. depois pelo das **centenas**, e assim até o dígito mais alto do maior
   número.

Cada passada é um **counting sort** (assunto 0120) com 10 chaves, de 0 a 9.
O dígito de `x` na casa `exp` (1, 10, 100...) sai com `(x / exp) % 10`. Essa
versão, que começa pelo dígito menos significativo, se chama **LSD** (*least
significant digit*).

Depois da passada das dezenas, os números estão em ordem pelos dois últimos
dígitos. Na passada das centenas, dois números com a mesma centena, como 807
e 830, ficam na ordem em que já estavam, que é a ordem das dezenas. Por isso
cada passada **precisa ser estável**: a estabilidade guarda o trabalho das
passadas anteriores.

O custo é de `d` passadas de counting sort, com `d` dígitos e base `b`:
**O(d · (n + b))**. Para números de tamanho fixo, `d` é constante e o radix
sort é linear, de novo sem comparar elementos. O Cormen
escreve Θ(d(n + k)), com k valores por dígito, e para chaves de `b` bits
quebradas em dígitos de `r` bits, Θ((b/r)(n + 2^r)): a melhor escolha fica
perto de r = log₂ n.

O exemplo usa oito números de pedido de um mercado online, com até três
dígitos (escritos com zeros à esquerda para os dígitos ficarem alinhados).
Acompanhe o 807 e o 830, em amarelo: a passada das dezenas põe o 807 na
frente, e a das centenas, que vê os dois empatados no 8, respeita essa ordem:

<p align="center"><img src="18-ordenacao-linear/0121-radix-sort/ideia.svg" alt="Diagrama da ideia: Radix sort" width="858"></p>

A `passada` é o counting sort do assunto 0120 com a
chave trocada pelo dígito; o vetor auxiliar é alocado uma vez só e
reaproveitado em todas as passadas:

```c
#include <stdio.h>
#include <stdlib.h>

void mostra(const int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf(" %03d", v[i]);
    }
    printf("\n");
}

// counting sort estável de v pelo dígito (v[i] / exp) % 10
void passada(int v[], int aux[], int n, int exp) {
    int c[10] = {0};
    for (int i = 0; i < n; i++) {
        c[(v[i] / exp) % 10]++;
    }
    for (int d = 1; d < 10; d++) {
        c[d] += c[d - 1];
    }
    for (int i = n - 1; i >= 0; i--) {      // de trás para a frente
        int d = (v[i] / exp) % 10;
        c[d]--;
        aux[c[d]] = v[i];
    }
    for (int i = 0; i < n; i++) {
        v[i] = aux[i];
    }
}

void radix_sort(int v[], int n) {
    int maior = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] > maior) {
            maior = v[i];
        }
    }
    int *aux = malloc(n * sizeof(int));
    if (aux == NULL) {
        return;
    }
    for (int exp = 1; maior / exp > 0; exp *= 10) {  // um dígito por passada
        passada(v, aux, n, exp);
        printf("exp = %3d:", exp);
        mostra(v, n);
    }
    free(aux);
}

int main(void) {
    int pedidos[] = {251, 47, 830, 509, 74, 216, 553, 807};
    int n = 8;

    printf("início:   ");
    mostra(pedidos, n);
    radix_sort(pedidos, n);
    return 0;
}
// Saída:
// início:    251 047 830 509 074 216 553 807
// exp =   1: 830 251 553 074 216 047 807 509
// exp =  10: 807 509 216 830 047 251 553 074
// exp = 100: 047 074 216 251 509 553 807 830
```

### Passo a passo

A passada das dezenas (`exp = 10`) recebe o vetor da passada anterior. O
dígito de cada número é `(x / 10) % 10`:

| número | 830 | 251 | 553 | 074 | 216 | 047 | 807 | 509 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| dígito | 3 | 5 | 5 | 7 | 1 | 4 | 0 | 0 |

Contagem por dígito: 0 → 2, 1 → 1, 3 → 1, 4 → 1, 5 → 2, 7 → 1. Os blocos
na saída ficam: `807 509 | 216 | 830 | 047 | 251 553 | 074`. Dentro do
bloco do 0, o 807 vem antes do 509 porque já vinha antes: a passada não
olhou as unidades, mas também não estragou a ordem delas.

O laço para quando `exp` passa do maior número. Com o
maior igual a 830, são três passadas (`exp` = 1, 10, 100); com `exp = 1000`,
`830 / 1000` dá 0:

<p align="center"><img src="18-ordenacao-linear/0121-radix-sort/fluxograma.svg" alt="Fluxograma: Radix sort" width="601"></p>

> [!WARNING]
> Use uma ordenação **estável** em cada passada. Se o terceiro laço da
> `passada` andar da frente para trás, cada passada inverte os empates, e o
> resultado sai `074 047 251 216 553 509 830 807`: as centenas em ordem, o
> resto bagunçado, sem erro nenhum. Também não dá para começar pelas
> centenas com esse código: a última passada é a que manda, então ela tem
> que ser a do dígito mais importante. E o número de
> passadas vem do **maior** elemento, não do primeiro: um número de 4 dígitos
> escondido no meio do vetor precisa da quarta passada.

> [!TIP]
> **Por dentro do C:** divisão e resto custam caro para o processador, e
> base 10 é uma escolha humana. Programas de verdade usam **base 256**: o
> "dígito" é um byte, e sai com operadores de bits (assunto 0065):
> `(x >> 8 * b) & 0xFF` é o byte `b` de `x`. Um `int` de 32 bits tem 4 bytes,
> então são sempre 4 passadas, com `c[256]` (1 KB, cabe no cache L1). Um
> milhão de inteiros vira 4 passadas de 1 milhão, contra uns 20 milhões de
> comparações de um bom O(n log n). O preço é a memória: o vetor auxiliar tem
> o tamanho da entrada.

> [!NOTE]
> **Pergunta para você:** este código funciona com números negativos? Pense
> no que `(-47 / 1) % 10` dá em C (o resto tem o sinal do dividendo) e em
> que posição do vetor `c` isso cairia.

### Hora de praticar

Arquivos em [`0121-radix-sort/`](18-ordenacao-linear/0121-radix-sort/).

**Exemplo A241 · Placas de carro, letra por letra**

```c
#include <stdio.h>
#include <string.h>

#define TAM 7 // placa no padrão Mercosul: ABC1D23

// counting sort estável dos ponteiros pela letra da posição pos
void passada(const char *v[], const char *aux[], int n, int pos) {
    int c[256] = {0};
    for (int i = 0; i < n; i++) {
        c[(unsigned char) v[i][pos]]++;
    }
    for (int x = 1; x < 256; x++) {
        c[x] += c[x - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        unsigned char x = (unsigned char) v[i][pos];
        aux[--c[x]] = v[i];
    }
    memcpy(v, aux, n * sizeof(const char *)); // copia os ponteiros de volta
}

int main(void) {
    const char *placas[] = {"RIO2A18", "BRA0S17", "RIO1B99", "SPX3C40", "BRA0S09", "MGA7E21"};
    const char *aux[6];
    int n = 6;

    for (int pos = TAM - 1; pos >= 0; pos--) { // da última letra para a primeira
        passada(placas, aux, n, pos);
        printf("posição %d:", pos);
        for (int i = 0; i < n; i++) {
            printf(" %s", placas[i]);
        }
        printf("\n");
    }
    return 0;
}
// Saída:
// posição 6: SPX3C40 MGA7E21 BRA0S17 RIO2A18 RIO1B99 BRA0S09
// posição 5: BRA0S09 BRA0S17 RIO2A18 MGA7E21 SPX3C40 RIO1B99
// posição 4: RIO2A18 RIO1B99 SPX3C40 MGA7E21 BRA0S09 BRA0S17
// posição 3: BRA0S09 BRA0S17 RIO1B99 RIO2A18 SPX3C40 MGA7E21
// posição 2: BRA0S09 BRA0S17 MGA7E21 RIO1B99 RIO2A18 SPX3C40
// posição 1: MGA7E21 RIO1B99 RIO2A18 SPX3C40 BRA0S09 BRA0S17
// posição 0: BRA0S09 BRA0S17 MGA7E21 RIO1B99 RIO2A18 SPX3C40
//
// Sete passadas, uma por posição, sempre da direita para a esquerda. Repare
// em BRA0S09 e BRA0S17: só diferem na posição 5, e quem decidiu a ordem dos
// dois foi a passada da posição 5. As passadas seguintes os viram empatados
// e, por estabilidade, não mexeram. Para strings de tamanhos diferentes, o
// radix LSD não serve direto: seria preciso completar as curtas.
```

```bash
~/LPEDC/rodar 18-ordenacao-linear/0121-radix-sort/A241.c
```

**Exemplo A242 · Um byte por passada**

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define N 200000

// radix sort de inteiros sem sinal de 32 bits, em base 256: 4 passadas
void radix_256(uint32_t v[], uint32_t aux[], int n) {
    for (int b = 0; b < 4; b++) {
        int desloca = 8 * b;            // byte 0: bits 0-7; byte 3: bits 24-31
        int c[256] = {0};
        for (int i = 0; i < n; i++) {
            c[(v[i] >> desloca) & 0xFF]++;
        }
        for (int x = 1; x < 256; x++) {
            c[x] += c[x - 1];
        }
        for (int i = n - 1; i >= 0; i--) {
            aux[--c[(v[i] >> desloca) & 0xFF]] = v[i];
        }
        uint32_t *t = v;                // em vez de copiar de volta, troca
        v = aux;                        // os papéis dos dois vetores
        aux = t;
    }
    // 4 trocas (um número par): o resultado terminou no vetor original
}

int main(void) {
    uint32_t x = 3000000000u;
    printf("%u em hexadecimal: %08X\n", (unsigned) x, (unsigned) x);
    for (int b = 0; b < 4; b++) {
        printf("  byte %d: %3u\n", b, (unsigned) ((x >> 8 * b) & 0xFF));
    }

    uint32_t *v = malloc(N * sizeof(uint32_t));
    uint32_t *aux = malloc(N * sizeof(uint32_t));
    if (v == NULL || aux == NULL) {
        free(v);
        free(aux);
        return 1;
    }
    uint32_t semente = 7;
    for (int i = 0; i < N; i++) {
        semente = semente * 1664525u + 1013904223u; // números de 32 bits
        v[i] = semente;
    }

    radix_256(v, aux, N);
    int ordenado = 1;
    for (int i = 1; i < N; i++) {
        if (v[i - 1] > v[i]) {
            ordenado = 0;
        }
    }
    printf("%d números, 4 passadas de %d: ordenado? %s\n", N, N, ordenado ? "sim" : "não");
    printf("menor: %u, maior: %u\n", (unsigned) v[0], (unsigned) v[N - 1]);
    free(v);
    free(aux);
    return 0;
}
// Saída:
// 3000000000 em hexadecimal: B2D05E00
//   byte 0:   0
//   byte 1:  94
//   byte 2: 208
//   byte 3: 178
// 200000 números, 4 passadas de 200000: ordenado? sim
// menor: 4403, maior: 4294950843
//
// Cada passada olha um byte: B2 D0 5E 00 são 178, 208, 94 e 0. O byte 0 (o
// menos significativo) vem primeiro, como as unidades na base 10. Não há
// divisão nem resto, só deslocamento e máscara, e o número de passadas não
// depende dos valores: são sempre 4 para 32 bits. A troca de ponteiros no
// fim de cada passada economiza a cópia de 200000 números.
```

```bash
~/LPEDC/rodar 18-ordenacao-linear/0121-radix-sort/A242.c
```

#### Exercícios

**Exercício E721** · ★☆☆

As duas perguntas que o radix sort faz o tempo todo são "quantos dígitos
tem o maior número?" (quantas passadas) e "qual é o dígito desta casa?".
Escreva as duas funções, só com divisão e resto por 10 (sem pow):

- int quantos_digitos(int x): 5082 tem 4, 7 tem 1;

- int digito(int x, int pos): pos 0 é a unidade, 1 a dezena, e assim por
diante. digito(5082, 1) é 8.

O main já mostra a tabela para quatro números.


```text
Saída esperada:
5082: 4 dígitos; unidade 2, dezena 8, centena 0, milhar 5
7: 1 dígito; unidade 7
340: 3 dígitos; unidade 0, dezena 4, centena 3
19000: 5 dígitos; unidade 0, dezena 0, centena 0, milhar 9, dezena de milhar 1
```

**Dicas:**

1. quantos_digitos: comece com 1 e divida por 10 enquanto x >= 10.
   Cuidado com o 0, que tem 1 dígito.
2. digito: divida x por 10, pos vezes, e devolva x % 10.

```bash
~/LPEDC/rodar 18-ordenacao-linear/0121-radix-sort/E721.c
```

**Exercício E722** · ★☆☆

A transportadora separa as encomendas pelo começo do CEP (5 dígitos).
Ordene os 7 prefixos com o radix sort LSD em base 10 e mostre o vetor
depois de cada passada. Mostre os números com %05d: o prefixo 01310 é
guardado como o int 1310, mas continua tendo 5 dígitos para o carteiro.


```text
Saída esperada:
início:      69050 13083 69005 01310 40140 13010 88015
exp =     1: 69050 01310 40140 13010 13083 69005 88015
exp =    10: 69005 01310 13010 88015 40140 69050 13083
exp =   100: 69005 13010 88015 69050 13083 40140 01310
exp =  1000: 40140 01310 13010 13083 88015 69005 69050
exp = 10000: 01310 13010 13083 40140 69005 69050 88015
```

**Dicas:**

1. A passada é a do texto. O vetor auxiliar pode ser um int aux[7]
   comum, porque n é fixo.
2. O maior é 88015, então são 5 passadas. O 1310 tem só 4 dígitos "de
   verdade", mas na quinta passada o dígito dele é 0, e ele vai para a
   frente.
3. Formato das linhas: "exp = %5d:" seguido de " %05d" para cada número.

```bash
~/LPEDC/rodar 18-ordenacao-linear/0121-radix-sort/E722.c
```

**Exercício E723** · ★★☆

A classificadora de cartões tinha 10 escaninhos, e cada escaninho é uma
FILA: o primeiro cartão que entra é o primeiro que sai (assunto 0085).
Faça o radix sort assim, sem contagem nem acumulado: em cada passada,
distribua os números em 10 filas pelo dígito da vez e depois recolha as
filas em ordem, da 0 à 9, de volta no vetor. Os números são os cubos de 0
a 9, embaralhados:


```text
64 8 216 512 27 729 0 1 343 125
```



```text
Saída esperada:
exp =   1: 000 001 512 343 064 125 216 027 008 729
exp =  10: 000 001 008 512 216 125 027 729 343 064
exp = 100: 000 001 008 027 064 125 216 343 512 729
```

**Dicas:**

1. Uma fila simples basta: typedef struct { int itens[MAX]; int ini, fim; }
   Fila; com enfileira (itens[fim++] = x), desenfileira (itens[ini++]) e
   vazia (ini == fim). Cada passada começa com as 10 filas zeradas.
2. Cada fila recebe no máximo os 10 números, então MAX = 16 sobra.
3. A fila é o que garante a estabilidade: quem entrou antes no escaninho
   sai antes. Com uma PILHA no lugar, o resultado sairia errado.

```bash
~/LPEDC/rodar 18-ordenacao-linear/0121-radix-sort/E723.c
```

**Exercício E724** · ★★☆

O radix sort não precisa de dígitos: qualquer chave formada por "casas"
serve. Uma data tem três casas: dia, mês e ano, do menos para o mais
importante. Ordene os vencimentos dos boletos em ordem cronológica com
três passadas de counting sort estável: primeiro pelo dia, depois pelo
mês, por fim pelo ano. Mostre o vetor depois de cada passada.


```text
Saída esperada:
início: 15/03/2025 05/11/2024 15/01/2025 28/02/2024 05/03/2025 10/11/2024 28/01/2025
dia:    05/11/2024 05/03/2025 10/11/2024 15/03/2025 15/01/2025 28/02/2024 28/01/2025
mês:    15/01/2025 28/01/2025 28/02/2024 05/03/2025 15/03/2025 05/11/2024 10/11/2024
ano:    28/02/2024 05/11/2024 10/11/2024 15/01/2025 28/01/2025 05/03/2025 15/03/2025
```

**Dicas:**

1. Escreva int chave(Data d, int campo): campo 0 devolve o dia, 1 o mês e
   2 o ano - 2020 (os anos vão de 2020 a 2029). Assim, uma passada só
   serve para os três campos.
2. Com 32 contadores, cabem os dias (1 a 31), os meses e os anos.
3. Formato de cada data: " %02d/%02d/%d".

```bash
~/LPEDC/rodar 18-ordenacao-linear/0121-radix-sort/E724.c
```

**Exercício E725** · ★★★

Ache o bug. A loja de aplicativos ordena os downloads do mês com um radix
sort em base 256. O programa compila, roda sem erro de memória e quase
acerta: os números pequenos saem em ordem, mas os grandes não.


```text
Saída esperada:
5 300 65535 70000 131072 1000000 16777216 4000000000
```



```text
Saída que aparece:
16777216 5 300 65535 70000 131072 4000000000 1000000
```


Ache a linha errada, conserte e rode.

**Dicas:**

1. Acrescente um printf que mostre desloca em cada passada. Que bits a
   última passada olha?
2. 16777216 é 2 elevado a 24: só o byte 3 dele não é zero. Alguma passada
   olha esse byte?
3. Resposta esperada: desloca = 4 * b anda meio byte (4 bits) por
   passada; as 4 passadas só cobrem os bits 0 a 19. O certo é
   desloca = 8 * b: os bytes 0, 1, 2 e 3 (deslocamentos 0, 8, 16 e 24).
   Consertado, sai a saída esperada.

```bash
~/LPEDC/rodar 18-ordenacao-linear/0121-radix-sort/E725.c
```

**Exercício E726** · ★★★

O extrato da conta tem saques (negativos) e depósitos (positivos), em
centavos. O radix sort em base 256 olha os bits, e no complemento de dois
o -7 é FFFFFFF9: como número sem sinal, ele é enorme. Por isso um radix
ingênuo põe todos os negativos DEPOIS dos positivos.

a) Escreva radix(v, aux, n, com_chave), um radix sort em base 256 para
int32_t. Com com_chave = false, use os bits do número direto:
(uint32_t) x. Rode e veja o problema.

b) Com com_chave = true, use a chave (uint32_t) x ^ 0x80000000u, que
inverte só o bit de sinal. Rode de novo.


```text
Saída esperada:
-7 como uint32_t: FFFFFFF9
sem a chave: 0 7 3200 98000 2147483647 -2147483648 -150000 -98000 -7
com a chave: -2147483648 -150000 -98000 -7 0 7 3200 98000 2147483647
```

**Dicas:**

1. Uma função uint32_t bits(int32_t x, bool com_chave) devolve a chave
   certa; o resto do radix é o do exemplo A242, com bits(v[i], com_chave)
   no lugar de v[i].
2. Por que a chave funciona? INT_MIN (80000000) vira 00000000, -1
   (FFFFFFFF) vira 7FFFFFFF, 0 vira 80000000 e INT_MAX vira FFFFFFFF: a
   ordem dos int passa a ser a ordem dos uint32_t.
3. Só a chave muda: o vetor continua guardando os int32_t originais.

```bash
~/LPEDC/rodar 18-ordenacao-linear/0121-radix-sort/E726.c
```

---

## 0122 · Bucket sort

Na secretaria da escola, as provas corrigidas chegam numa pilha só, fora de
ordem. A secretária espalha dez envelopes na mesa, um para cada nota inteira
(0, 1, 2, ..., 9), e vai jogando cada prova no envelope certo: a de 6,4 vai
para o envelope 6, a de 2,7 para o 2. Depois arruma cada envelope, que tem
poucas provas, e empilha os envelopes em ordem.

Esse é o **bucket sort** (ordenação por baldes). Ele divide o intervalo dos
valores em **faixas** de mesmo tamanho, uma por **balde**, e:

1. joga cada elemento no balde da sua faixa: para notas de 0 a 10 e 10
   baldes, o balde de `x` é `(int) x`;
2. ordena cada balde, que é pequeno, com um método simples;
3. **concatena** os baldes, do primeiro ao último.

Funciona porque a função que escolhe o balde **preserva a ordem**: tudo que
está no balde 2 é menor que tudo que está no balde 4. Lembra uma tabela hash
(assunto 0105) com o objetivo oposto: o hash quer espalhar sem ordem, o
bucket sort quer espalhar **em ordem**.

Cada balde é uma **lista encadeada** (assunto 0076): não dá para saber de
antemão quantos elementos caem em cada um. E em vez de ordenar a lista
depois, cada elemento já entra **no lugar certo** da lista, como na lista
ordenada do assunto 0078: o insertion sort feito na lista.

Se os `n` valores estão bem **espalhados** pelo intervalo e há
uns `n` baldes, cada balde recebe em média um elemento, e o custo total é
**O(n)** em média. Se todos caem no mesmo balde, sobra um insertion sort de
`n` elementos: **O(n²)**.
O Cormen apresenta a versão com valores em [0, 1) e `n` baldes: `x` vai para
o balde ⌊n · x⌋, e o Θ(n) médio supõe valores **uniformes** no intervalo.

No exemplo, dez notas finais vão para dez baldes. Três notas caem no balde 2
e entram em ordem na lista; quatro baldes ficam vazios. Ler os baldes de cima
para baixo já dá o vetor ordenado:

<p align="center"><img src="18-ordenacao-linear/0122-bucket-sort/ideia.svg" alt="Diagrama da ideia: Bucket sort" width="858"></p>

Em C, os baldes são um vetor de 10 ponteiros para lista, todos começando em
`NULL`:

```c
#include <stdio.h>
#include <stdlib.h>

#define NB 10 // um balde para cada nota inteira: 0, 1, ..., 9

typedef struct No {
    double valor;
    struct No *prox;
} No;

// insere x na lista sem perder a ordem: é o insertion sort, na lista
No *insere_ordenado(No *lista, double x) {
    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        exit(1);
    }
    novo->valor = x;
    if (lista == NULL || x < lista->valor) {
        novo->prox = lista;               // entra na frente
        return novo;
    }
    No *p = lista;
    while (p->prox != NULL && p->prox->valor <= x) {
        p = p->prox;                      // <= : iguais ficam na ordem de chegada
    }
    novo->prox = p->prox;
    p->prox = novo;
    return lista;
}

void bucket_sort(double v[], int n) {
    No *baldes[NB] = {NULL};
    for (int i = 0; i < n; i++) {
        int b = (int) v[i];               // 6.4 vai para o balde 6
        baldes[b] = insere_ordenado(baldes[b], v[i]);
    }
    int k = 0;
    for (int b = 0; b < NB; b++) {        // junta os baldes, em ordem
        if (baldes[b] == NULL) {
            continue;                     // balde vazio
        }
        printf("balde %d:", b);
        No *p = baldes[b];
        while (p != NULL) {
            printf(" %.1f", p->valor);
            v[k++] = p->valor;
            No *prox = p->prox;
            free(p);                      // devolve o nó assim que copia
            p = prox;
        }
        printf("\n");
    }
}

int main(void) {
    double notas[] = {6.4, 2.7, 8.1, 4.5, 2.2, 9.6, 6.9, 0.8, 4.1, 2.9};
    int n = 10;

    bucket_sort(notas, n);
    printf("ordenadas:");
    for (int i = 0; i < n; i++) {
        printf(" %.1f", notas[i]);
    }
    printf("\n");
    return 0;
}
// Saída:
// balde 0: 0.8
// balde 2: 2.2 2.7 2.9
// balde 4: 4.1 4.5
// balde 6: 6.4 6.9
// balde 8: 8.1
// balde 9: 9.6
// ordenadas: 0.8 2.2 2.7 2.9 4.1 4.5 6.4 6.9 8.1 9.6
```

O laço de espalhar passa uma vez pelo vetor, e o de juntar passa uma vez por
cada balde e cada nó. O trabalho escondido está no `insere_ordenado`, que
anda pela lista do balde; com baldes curtos, ele quase não pesa:

<p align="center"><img src="18-ordenacao-linear/0122-bucket-sort/fluxograma.svg" alt="Fluxograma: Bucket sort" width="529"></p>

> [!WARNING]
> O índice do balde tem que caber no vetor de baldes. Uma nota 10,0 dá
> `(int) 10.0 == 10`, e `baldes[10]` não existe: escrita fora do vetor. Com
> o intervalo fechado [0, 10], use 11 baldes ou trate o máximo à parte (`b
> = b == NB ? NB - 1 : b`). O mesmo vale para valores negativos e para
> qualquer valor fora da faixa que você imaginou: o bucket sort precisa
> **conhecer o intervalo** dos dados antes de começar.

> [!TIP]
> **Por dentro do C:** cada nota custa um `malloc` de um nó de 16 bytes (8
> do `double`, 8 do ponteiro), mais o controle que o próprio `malloc` guarda
> junto. Para 10 notas tanto faz, mas para 1 milhão são 1 milhão de chamadas
> ao alocador e nós espalhados pelo heap, o que o cache detesta. Por isso
> implementações rápidas fazem uma **contagem** antes (quantos vão para cada
> balde) e usam um vetor só, dividido em pedaços, sem lista: o counting sort
> do assunto 0120 com chaves que são faixas. E cada `malloc`
> pede o seu `free`: este código libera cada nó logo depois de copiar o
> valor.

> [!NOTE]
> **Pergunta para você:** a turma de reforço tirou 5,1; 5,4; 5,0; 5,8; 5,3;
> 5,6; 5,2 e 5,9. Em quantos baldes essas notas caem? Quantas comparações o
> `insere_ordenado` faz no total? Como você mudaria a função do balde para
> espalhar melhor essas notas?

### Hora de praticar

Arquivos em [`0122-bucket-sort/`](18-ordenacao-linear/0122-bucket-sort/).

**Exemplo A243 · Quando todo mundo cai no mesmo balde**

```c
#include <stdio.h>
#include <stdlib.h>

#define N 1000

typedef struct No {
    double valor;
    struct No *prox;
} No;

static long comparacoes;
static unsigned semente;

// número entre 0 e 1 (sem chegar a 1), sempre a mesma sequência
double sorteia(void) {
    semente = semente * 1103515245u + 12345u;
    return ((semente >> 8) % 1000000) / 1000000.0;
}

No *insere_ordenado(No *lista, double x) {
    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        exit(1);
    }
    novo->valor = x;
    No **p = &lista;                  // ponteiro para o elo que vai mudar
    while (*p != NULL) {
        comparacoes++;
        if ((*p)->valor > x) {
            break;
        }
        p = &(*p)->prox;
    }
    novo->prox = *p;
    *p = novo;
    return lista;
}

// n baldes para notas de 0 a 10: cada balde cobre uma faixa de 10 / n
void bucket_sort(double v[], int n, int *maior_balde) {
    No **baldes = calloc(n, sizeof(No *));
    int *tamanho = calloc(n, sizeof(int));
    if (baldes == NULL || tamanho == NULL) {
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        int b = (int) (v[i] / 10.0 * n);
        baldes[b] = insere_ordenado(baldes[b], v[i]);
        tamanho[b]++;
    }
    *maior_balde = 0;
    int k = 0;
    for (int b = 0; b < n; b++) {
        if (tamanho[b] > *maior_balde) {
            *maior_balde = tamanho[b];
        }
        while (baldes[b] != NULL) {
            No *p = baldes[b];
            v[k++] = p->valor;
            baldes[b] = p->prox;
            free(p);
        }
    }
    free(baldes);
    free(tamanho);
}

void testa(const char *nome, double base, double largura) {
    double v[N];
    semente = 42;
    for (int i = 0; i < N; i++) {
        v[i] = base + largura * sorteia();
    }
    comparacoes = 0;
    int maior;
    bucket_sort(v, N, &maior);
    printf("%-22s %7ld comparações, maior balde com %3d notas\n", nome, comparacoes, maior);
}

int main(void) {
    testa("notas de 0 a 10:", 0.0, 10.0);
    testa("notas de 5 a 6:", 5.0, 1.0);
    testa("notas de 5,0 a 5,01:", 5.0, 0.01);
    return 0;
}
// Saída:
// notas de 0 a 10:           469 comparações, maior balde com   6 notas
// notas de 5 a 6:           3237 comparações, maior balde com  18 notas
// notas de 5,0 a 5,01:    243539 comparações, maior balde com 1000 notas
//
// Os mesmos 1000 baldes, três distribuições. Espalhadas de 0 a 10, as notas
// caem em média uma por balde e o total é menos de meia comparação por nota.
// Concentradas entre 5 e 6, só 100 baldes trabalham. Entre 5,0 e 5,01, todas
// caem no balde 500 e sobra um insertion sort de 1000 elementos: perto de
// n²/4 comparações. O insere_ordenado usa um ponteiro para ponteiro (No **)
// para não tratar o começo da lista como caso especial.
```

```bash
~/LPEDC/rodar 18-ordenacao-linear/0122-bucket-sort/A243.c
```

**Exemplo A244 · Baldes sem lista encadeada**

```c
#include <stdio.h>

#define NB 10 // faixas etárias: 0-9, 10-19, ..., 90-99

// insertion sort só no pedaço v[ini..fim-1]
void insertion(int v[], int ini, int fim) {
    for (int i = ini + 1; i < fim; i++) {
        int x = v[i];
        int j = i;
        while (j > ini && v[j - 1] > x) {
            v[j] = v[j - 1];
            j--;
        }
        v[j] = x;
    }
}

int main(void) {
    // idades dos voluntários da campanha do agasalho
    int idades[] = {34, 71, 19, 45, 38, 22, 67, 30, 18, 52, 41, 36, 25, 63, 33};
    int n = 15;
    int saida[15];

    // 1) conta quantos caem em cada balde e acha onde cada balde começa
    int comeco[NB + 1] = {0};
    for (int i = 0; i < n; i++) {
        comeco[idades[i] / 10 + 1]++;
    }
    for (int b = 1; b <= NB; b++) {
        comeco[b] += comeco[b - 1];   // balde b ocupa saida[comeco[b]..comeco[b+1]-1]
    }
    // 2) espalha: cada um vai para a próxima vaga livre do seu balde
    int vaga[NB];
    for (int b = 0; b < NB; b++) {
        vaga[b] = comeco[b];
    }
    for (int i = 0; i < n; i++) {
        int b = idades[i] / 10;
        saida[vaga[b]++] = idades[i];
    }
    // 3) ordena cada balde no lugar e mostra
    for (int b = 0; b < NB; b++) {
        insertion(saida, comeco[b], comeco[b + 1]);
        if (comeco[b + 1] > comeco[b]) {
            printf("%2d-%2d anos:", 10 * b, 10 * b + 9);
            for (int i = comeco[b]; i < comeco[b + 1]; i++) {
                printf(" %d", saida[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
// Saída:
// 10-19 anos: 18 19
// 20-29 anos: 22 25
// 30-39 anos: 30 33 34 36 38
// 40-49 anos: 41 45
// 50-59 anos: 52
// 60-69 anos: 63 67
// 70-79 anos: 71
//
// Nenhum malloc: a contagem diz de antemão o tamanho de cada balde, e os
// baldes viram pedaços vizinhos do mesmo vetor saida. É o counting sort do
// assunto 0120 com a chave "faixa" (idade / 10) no lugar da idade, seguido de
// um insertion sort em cada pedaço. O comeco[NB + 1] tem uma casa a mais
// para que comeco[b + 1] marque o fim do último balde.
```

```bash
~/LPEDC/rodar 18-ordenacao-linear/0122-bucket-sort/A244.c
```

#### Exercícios

**Exercício E727** · ★☆☆

A loja de R$ 1,99 virou "loja até R$ 50" e quer separar os produtos em 5
prateleiras de preço: de 0 a 10, de 10 a 20, ..., de 40 a 50. Escreva
int balde_de(double x, double max, int nb), que devolve o balde (de 0 a
nb - 1) de um valor x entre 0 e max, com nb baldes de mesma largura. O
preço máximo, R$ 50,00, vai para o último balde. Mostre o balde de cada
preço.


```text
Saída esperada:
R$ 12.50 -> balde 1
R$ 49.99 -> balde 4
R$ 50.00 -> balde 4
R$  0.00 -> balde 0
R$ 10.00 -> balde 1
R$ 37.20 -> balde 3
R$  9.99 -> balde 0
```

**Dicas:**

1. x / max dá um número de 0 a 1; vezes nb, de 0 a nb. A parte inteira
   é o balde: (int) (x / max * nb).
2. Só o próprio max dá nb, que não existe. Trate esse caso com um if.
3. Formato: "R$ %5.2f -> balde %d\n".

```bash
~/LPEDC/rodar 18-ordenacao-linear/0122-bucket-sort/E727.c
```

**Exercício E728** · ★☆☆

Os tempos da prova de natação vão de 0 a 599 segundos. O programa abaixo
já espalha os tempos em 6 baldes (um para cada 100 s), junta os baldes e
libera os nós. Falta a peça principal: complete insere_ordenado, que
insere x na lista do balde sem perder a ordem crescente, e devolve o novo
começo da lista.


```text
Saída esperada:
balde 0:
balde 1:
balde 2: 201 255 287 295 298
balde 3: 318 365
balde 4: 409 433 470
balde 5: 512
ordenados: 201 255 287 295 298 318 365 409 433 470 512
```

**Dicas:**

1. Crie o nó com malloc (confira NULL) e guarde x nele.
2. Lista vazia, ou x menor que o primeiro: o novo nó vira o começo.
3. Senão, ande com p enquanto p->prox existir e p->prox->valor <= x, e
   encaixe o nó depois de p.

```bash
~/LPEDC/rodar 18-ordenacao-linear/0122-bucket-sort/E728.c
```

**Exercício E729** · ★★☆

A agenda do celular agrupa os contatos pela letra inicial. Faça um bucket
sort de strings com 26 baldes, um por letra: o balde de um nome é
nome[0] - 'A', e cada balde é uma lista encadeada que guarda os nomes já
em ordem alfabética (compare com strcmp). Mostre cada balde que não está
vazio, devolva os nomes ao vetor em ordem e libere todos os nós.


```text
Saída esperada:
A: Alberto Amanda Ana
B: Beatriz Bruno
C: Caio Carla
M: Marcos Mariana Marta Mauro
agenda: Alberto Amanda Ana Beatriz Bruno Caio Carla Marcos Mariana Marta Mauro
```

**Dicas:**

1. O nó guarda só o ponteiro: typedef struct No { const char *nome;
   struct No *prox; } No; as letras continuam onde estão.
2. É o insere_ordenado do texto com "x < lista->valor" trocado por
   strcmp(nome, lista->nome) < 0 (e o mesmo no laço).
3. Na hora de juntar, copie p->nome para o vetor e dê free(p) antes de
   passar para o próximo.

```bash
~/LPEDC/rodar 18-ordenacao-linear/0122-bucket-sort/E729.c
```

**Exercício E730** · ★★☆

O programa abaixo tem um bucket sort que só aceita valores em [0, 1),
como as chances de chuva: com n valores, usa n baldes, e o balde de x é
(int) (x * n). Temperaturas não cabem nisso: podem ser negativas e passar
de 1. Estenda o programa com void bucket_sort_faixa(double v[], int n),
que acha o menor e o maior valor, mostra a faixa e usa n baldes de mesma
largura entre eles. Teste com as temperaturas e com um vetor de valores
todos iguais.


```text
Saída esperada:
0.05 0.35 0.41 0.62 0.80 0.97
faixa: -3.5 a 38.2, 12 baldes de 3.48
-3.50 -1.20 4.30 9.70 12.90 15.00 18.60 22.40 27.80 30.10 33.00 38.20
faixa: 7.0 a 7.0, 3 baldes de 0.00
7.00 7.00 7.00
```

**Dicas:**

1. O balde de x é (int) ((x - menor) / (maior - menor) * n): o menor vai
   para o balde 0.
2. O maior dá exatamente n, que não existe: mande para o n - 1.
3. Valores todos iguais: maior - menor é 0, e a divisão por zero dá NaN.
   Teste esse caso antes e mande todos para o balde 0.
4. Reaproveite insere_ordenado e junta. Formato da faixa:
   "faixa: %.1f a %.1f, %d baldes de %.2f\n".

```bash
~/LPEDC/rodar 18-ordenacao-linear/0122-bucket-sort/E730.c
```

**Exercício E731** · ★★★

Ache os bugs. A padaria ordena os pedidos do dia pelo valor com um bucket
sort, e quer que pedidos de mesmo valor fiquem na ordem de chegada. O
programa roda sem erro de memória, mas a saída é um desastre: tem pedido
repetido e pedido sumido. São DOIS erros. Conserte os dois e rode.


```text
Saída esperada:
I:9 B:12 E:12 A:35 C:35 H:35 G:38 F:50 D:87
```



```text
Saída que aparece:
D:87 H:35 C:35 G:38 E:12 F:50 G:38 H:35 I:9
```

**Dicas:**

1. Mostre o valor de k toda vez que um pedido volta para o vetor. Ele
   devia andar de 0 a 8 sem repetir.
2. Com o primeiro erro consertado, a saída fica quase certa:
   I:9 B:12 E:12 A:35 H:35 C:35 G:38 F:50 D:87. Compare A, C e H com a
   ordem de chegada. Quem decide onde entra um valor IGUAL a outro?
3. Resposta esperada: o int k = 0 está dentro do for dos baldes, então
   cada balde volta a escrever a partir de v[0]; ele tem que vir antes do
   for. E o laço do insere_ordenado anda com < em vez de <=: um valor
   igual para antes dos iguais que já estavam na lista, e a ordem de
   chegada se perde. Com <=, ele entra depois deles.

```bash
~/LPEDC/rodar 18-ordenacao-linear/0122-bucket-sort/E731.c
```

**Exercício E732** · ★★★

O fiscal da linha de ônibus quer saber qual é a maior espera entre duas
partidas seguidas. Os horários chegam fora de ordem, em minutos desde a
meia-noite. Ordenar e olhar os vizinhos resolve em O(n log n); o desafio
é resolver em O(n), com baldes e SEM ordenar:

1. ache o menor e o maior horário;
2. use N baldes de largura L = teto((maior - menor) / (N - 1)). Cada
balde guarda só o menor e o maior horário que caíram nele (e se foi
usado);
3. o maior intervalo nunca fica dentro de um balde: ele é sempre a
diferença entre o MENOR de um balde usado e o MAIOR do balde usado
anterior. Percorra os baldes e pegue a maior dessas diferenças.

No fim, confira a resposta ordenando com qsort.


```text
Saída esperada:
maior intervalo: 160 min, entre 17:30 e 20:10
conferindo com qsort: 160 min
```

**Dicas:**

1. Por que funciona: os N - 1 intervalos entre vizinhos somam
   maior - menor, então o maior intervalo é pelo menos a média, que é
   L. Dois horários no mesmo balde distam menos que L.
2. Teto com inteiros: (maior - menor + N - 2) / (N - 1). O balde de x é
   (x - menor) / L, que vai de 0 a N - 1.
3. O balde 0 sempre tem o menor horário: comece com anterior = maior do
   balde 0 e pule os baldes vazios.
4. Para mostrar a hora: sprintf(s, "%02d:%02d", m / 60, m % 60).

```bash
~/LPEDC/rodar 18-ordenacao-linear/0122-bucket-sort/E732.c
```

---

## 0123 · Quickselect

Você está procurando apartamento para alugar e anotou 9 anúncios do bairro:
R$ 1850, 1200, 2400, 980, 1450, 2050, 3100, 1600 e 1300. A média dá R$ 1770,
puxada para cima pela cobertura de R$ 3100. O número que diz quanto custa um
aluguel "típico" é a **mediana**: o valor do meio se a lista estivesse em
ordem. Metade dos anúncios custa menos, metade custa mais.

O jeito óbvio é ordenar e pegar `v[n / 2]`. Funciona, mas sobra trabalho:
para saber quem fica na posição 4, você arrumou as outras 8 posições também.
O problema geral se chama **seleção**: achar o **k-ésimo menor** elemento
(a mediana é o caso `k = n / 2`; o mínimo é `k = 0`).

O **quickselect** (Hoare, 1961, o mesmo do quick sort) usa a separação do
assunto 0095. Depois de um `separa`, o pivô está na posição **final** `j`:
à esquerda só há menores ou iguais, à direita só maiores. Então:

- se `j == k`, o pivô é a resposta;
- se `k < j`, a resposta está à **esquerda**: o lado direito pode ser
  esquecido;
- se `k > j`, a resposta está à **direita**.

A diferença para o quick sort é que ele segue **um lado só**. Não precisa
de recursão: um `while` que encolhe o intervalo `[p, r]` resolve. Você já viu
essa ideia de relance no exercício E569, do módulo 13; aqui ela ganha nome,
custo e cuidados.

Se o pivô cai perto do meio, cada separação descarta metade:
`n + n/2 + n/4 + ...`, que é menos que `2n`. O quickselect é **O(n) em
média**, contra O(n log n) de ordenar. No pior caso, o pivô é sempre o
maior ou o menor e o custo vira **O(n²)**, como no quick sort. O Cormen
chama a versão com pivô sorteado de `RANDOMIZED-SELECT` e mostra também o
`SELECT` (a mediana das medianas, de 1973), que garante O(n) no pior caso.

Nos aluguéis, a primeira separação, com pivô 1300, deixa o pivô na posição
2. A mediana está na posição 4, à direita: os três primeiros nunca mais são
olhados. Duas separações depois, o pivô cai na posição 4:

<p align="center"><img src="18-ordenacao-linear/0123-quickselect/ideia.svg" alt="Diagrama da ideia: Quickselect" width="858"></p>

Em C:

```c
#include <stdio.h>

void troca(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

// separação de Lomuto (assunto 0095): pivô v[r]; devolve a posição final dele
int separa(int v[], int p, int r) {
    int pivo = v[r], j = p;
    for (int k = p; k < r; k++) {
        if (v[k] <= pivo) {
            troca(&v[j], &v[k]);
            j++;
        }
    }
    troca(&v[j], &v[r]);
    return j;
}

// devolve o elemento que ficaria na posição k (0, 1, ...) se v fosse ordenado
int quickselect(int v[], int n, int k) {
    int p = 0, r = n - 1;
    while (p < r) {
        int j = separa(v, p, r);
        printf("pivô %d na posição %d:", v[j], j);
        for (int i = p; i <= r; i++) {
            printf(" %d", v[i]);
        }
        if (j == k) {
            printf("  -> achou\n");
            return v[j];
        }
        if (k < j) {
            printf("  -> segue à esquerda\n");
            r = j - 1;                  // a resposta está em v[p..j-1]
        } else {
            printf("  -> segue à direita\n");
            p = j + 1;                  // a resposta está em v[j+1..r]
        }
    }
    return v[p];                        // sobrou um só
}

int main(void) {
    int alugueis[] = {1850, 1200, 2400, 980, 1450, 2050, 3100, 1600, 1300};
    int n = 9;

    int mediana = quickselect(alugueis, n, n / 2);
    printf("aluguel mediano: R$ %d\n", mediana);
    return 0;
}
// Saída:
// pivô 1300 na posição 2: 1200 980 1300 1850 1450 2050 3100 1600 2400  -> segue à direita
// pivô 2400 na posição 7: 1850 1450 2050 1600 2400 3100  -> segue à esquerda
// pivô 1600 na posição 4: 1450 1600 2050 1850  -> achou
// aluguel mediano: R$ 1600
```

Foram 8 + 5 + 3 = 16 comparações. Com 9 elementos a economia é pequena (o
quick sort completo faz 18 neste vetor), mas ela cresce com `n`. A conta
`n + n/2 + ...` supõe o pivô sempre no meio; com pivôs ao acaso, a média para
achar a mediana fica em torno de 3,4 `n`. Para um milhão de elementos, uns
3,4 milhões de comparações, contra mais de 20 milhões para ordenar.

Ao contrário do quick sort, não há duas chamadas. Cada volta do laço escolhe
um lado e joga o outro fora:

<p align="center"><img src="18-ordenacao-linear/0123-quickselect/fluxograma.svg" alt="Fluxograma: Quickselect" width="778"></p>

> [!WARNING]
> Cuidado com o "k-ésimo". Em C, as posições começam em 0: o **menor** é
> `k = 0`, e "o 3º menor" é `k = 2`. Quem chama `quickselect(v, n, 3)`
> querendo o 3º menor recebe o 4º. E o quickselect **bagunça o vetor**: ele
> troca elementos de lugar a cada separação. Se você ainda precisa da ordem
> original (a ordem dos anúncios, por exemplo), passe uma cópia.

> [!TIP]
> **Por dentro do C:** a versão com `while` usa memória extra O(1): `p`,
> `r`, `j` e as variáveis do `separa`, na pilha. Uma versão recursiva, que
> chama `quickselect` num dos lados, é **recursão de cauda** (a chamada é a
> última coisa que a função faz), e o gcc com `-O2` costuma transformá-la
> num laço sozinho. Sem otimização (o `rodar` compila sem `-O2`), cada
> chamada é um frame novo, e no pior caso são `n` frames. Escrever o laço à
> mão não depende da boa vontade do compilador.

> [!NOTE]
> **Pergunta para você:** o que acontece se você pedir a mediana de um vetor
> que **já está em ordem** crescente, com 10.001 elementos? Quantas
> separações o quickselect faz, com o pivô sempre no fim? E se o pivô for
> sorteado?

### Hora de praticar

Arquivos em [`0123-quickselect/`](18-ordenacao-linear/0123-quickselect/).

**Exemplo A245 · O pódio sem ordenar a tabela**

```c
#include <stdio.h>

typedef struct {
    char nome[10];
    int pontos;
} Jogador;

void troca(Jogador *a, Jogador *b) {
    Jogador aux = *a;
    *a = *b;
    *b = aux;
}

int separa(Jogador v[], int p, int r) {
    int pivo = v[r].pontos, j = p;
    for (int k = p; k < r; k++) {
        if (v[k].pontos <= pivo) {
            troca(&v[j], &v[k]);
            j++;
        }
    }
    troca(&v[j], &v[r]);
    return j;
}

// deixa na posição k quem ficaria lá se v fosse ordenado; de brinde, à
// esquerda de k só ficam pontos <= e à direita só pontos >=
void seleciona(Jogador v[], int n, int k) {
    int p = 0, r = n - 1;
    while (p < r) {
        int j = separa(v, p, r);
        if (j == k) {
            return;
        }
        if (k < j) {
            r = j - 1;
        } else {
            p = j + 1;
        }
    }
}

int main(void) {
    Jogador torneio[] = {
        {"Bia", 1820}, {"Davi", 2150}, {"Edu", 1675}, {"Fábio", 2310}, {"Gabi", 1990},
        {"Hugo", 1540}, {"Íris", 2240}, {"Juca", 1880}, {"Kátia", 2075}, {"Léo", 1760},
        {"Malu", 1930}, {"Nico", 1610},
    };
    int n = 12;

    seleciona(torneio, n, n - 3);       // os 3 maiores vão para v[9..11]
    printf("depois da seleção:");
    for (int i = 0; i < n; i++) {
        printf(" %d", torneio[i].pontos);
    }
    printf("\n");

    // só os 3 do fim precisam de ordem: um insertion sort de 3 elementos
    for (int i = n - 2; i < n; i++) {
        Jogador x = torneio[i];
        int j = i;
        while (j > n - 3 && torneio[j - 1].pontos > x.pontos) {
            torneio[j] = torneio[j - 1];
            j--;
        }
        torneio[j] = x;
    }
    printf("ouro: %s (%d), prata: %s (%d), bronze: %s (%d)\n",
           torneio[n - 1].nome, torneio[n - 1].pontos, torneio[n - 2].nome,
           torneio[n - 2].pontos, torneio[n - 3].nome, torneio[n - 3].pontos);
    return 0;
}
// Saída:
// depois da seleção: 1540 1610 1675 1990 1820 1880 2075 1760 1930 2150 2240 2310
// ouro: Fábio (2310), prata: Íris (2240), bronze: Davi (2150)
//
// Repare na linha do meio: o vetor NÃO está ordenado (1990 antes de 1820,
// 2075 antes de 1760), mas os três últimos são os três maiores. O
// quickselect para k = n - 3 garante isso de graça, porque cada separação
// deixa os maiores à direita do pivô. Para o pódio, basta ordenar esses 3.
// Com uma tabela de 1 milhão de jogadores, são uns poucos milhões de passos,
// em vez de ordenar tudo.
```

```bash
~/LPEDC/rodar 18-ordenacao-linear/0123-quickselect/A245.c
```

**Exemplo A246 · Pivô sorteado contra o vetor já ordenado**

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 10001

static long comparacoes, separacoes;
static unsigned semente = 99;

// sorteia um índice em [p, r]; gerador próprio para a saída ser sempre igual
int sorteia(int p, int r) {
    semente = semente * 1103515245u + 12345u;
    return p + (int) ((semente >> 16) % (unsigned) (r - p + 1));
}

void troca(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

int separa(int v[], int p, int r) {
    int pivo = v[r], j = p;
    separacoes++;
    for (int k = p; k < r; k++) {
        comparacoes++;
        if (v[k] <= pivo) {
            troca(&v[j], &v[k]);
            j++;
        }
    }
    troca(&v[j], &v[r]);
    return j;
}

int quickselect(int v[], int n, int k, bool sorteado) {
    int p = 0, r = n - 1;
    while (p < r) {
        if (sorteado) {
            troca(&v[sorteia(p, r)], &v[r]); // o sorteado vira o pivô
        }
        int j = separa(v, p, r);
        if (j == k) {
            return v[j];
        }
        if (k < j) {
            r = j - 1;
        } else {
            p = j + 1;
        }
    }
    return v[p];
}

void testa(const char *nome, bool sorteado) {
    int *v = malloc(N * sizeof(int));
    if (v == NULL) {
        return;
    }
    for (int i = 0; i < N; i++) {
        v[i] = i + 1;                   // 1, 2, ..., 10001: já em ordem
    }
    comparacoes = separacoes = 0;
    int m = quickselect(v, N, N / 2, sorteado);
    printf("%s mediana %d, %5ld separações, %9ld comparações\n",
           nome, m, separacoes, comparacoes);
    free(v);
}

int main(void) {
    testa("pivô no fim:  ", false);
    testa("pivô sorteado:", true);
    return 0;
}
// Saída:
// pivô no fim:   mediana 5001,  5001 separações,  37507500 comparações
// pivô sorteado: mediana 5001,    20 separações,     37135 comparações
//
// Com o pivô sempre no fim de um vetor ordenado, cada separação só tira o
// último elemento do caminho: são 5001 separações e 10000 + 9999 + ... +
// 5000 comparações, O(n²). Sorteando o pivô, a chance de cair sempre num
// extremo é desprezível: 20 separações e menos de 4 comparações por
// elemento. A troca de uma linha (sortear e mandar para o fim) não muda o
// separa.
```

```bash
~/LPEDC/rodar 18-ordenacao-linear/0123-quickselect/A246.c
```

#### Exercícios

**Exercício E733** · ★☆☆

A escola quer um resumo das notas de redação do simulado: a menor, a
segunda menor, a mediana, a segunda maior e a maior, todas com o
quickselect do texto (já está no arquivo). Só que o quickselect bagunça o
vetor, e a escola quer a lista na ordem original. Escreva
int seleciona_copia(const int v[], int n, int k), que copia v para um
vetor local e roda o quickselect na cópia, e use para mostrar o resumo.
No fim, mostre notas[0] para provar que o vetor não mudou.


```text
Saída esperada:
menor:       380
2ª menor:    480
mediana:     680
2ª maior:    860
maior:       920
primeira do vetor continua: 720
```

**Dicas:**

1. Um int copia[MAX]; com MAX 100 basta para este programa.
2. As posições contam de 0: a menor é k = 0, a segunda menor é k = 1, a
   maior é k = n - 1 e a segunda maior, k = n - 2.
3. Com n = 11, a mediana está em k = n / 2 = 5.

```bash
~/LPEDC/rodar 18-ordenacao-linear/0123-quickselect/E733.c
```

**Exercício E734** · ★☆☆

Ninguém fala "a farmácia de posição 2 mais perto": fala "a 3ª mais perto".
Escreva bool k_esimo_menor(int v[], int n, int k, int *resposta), que
recebe k contado a partir de 1 (1 é o menor), confere se k faz sentido
(de 1 a n), chama o quickselect com a posição certa e devolve a resposta
pelo ponteiro. Para k fora da faixa, devolva false sem chamar nada.


```text
Saída esperada:
1ª mais perto: 1 km
3ª mais perto: 7 km
7ª mais perto: 25 km
0ª mais perto: não existe
8ª mais perto: não existe
```

**Dicas:**

1. O "k-ésimo" das pessoas é a posição k - 1 do quickselect.
2. Confira a faixa ANTES: com k = 8 e n = 7, o quickselect devolveria um
   valor qualquer, ou leria fora do vetor.

```bash
~/LPEDC/rodar 18-ordenacao-linear/0123-quickselect/E734.c
```

**Exercício E735** · ★★☆

Com um número PAR de valores, a mediana é a média dos dois do meio. O app
de entregas quer a mediana dos tempos de 10 entregas, sem ordenar o vetor.
Escreva double mediana(int v[], int n), que funciona para n par e ímpar,
usando UM quickselect só. Confira no fim com o qsort.


```text
Saída esperada:
10 entregas: mediana 39.5 min
9 entregas:  mediana 41.0 min
conferindo: 38 e 41 no meio
```

**Dicas:**

1. n ímpar: é o quickselect em k = n / 2, como no texto.
2. n par: os do meio estão nas posições n/2 - 1 e n/2. Rode o quickselect
   em k = n/2 - 1. Depois disso, tudo à direita de k é maior ou igual a
   v[k]: o outro do meio é o MENOR desse lado, e um laço simples acha.
3. Divida por 2.0, não por 2: (38 + 41) / 2 em int dá 39.
4. A compara do qsort já está no arquivo: qsort(v, 10, sizeof(int), compara).

```bash
~/LPEDC/rodar 18-ordenacao-linear/0123-quickselect/E735.c
```

**Exercício E736** · ★★☆

Quem cuida de servidores não olha a média do tempo de resposta, olha os
PERCENTIS: o p90 é o tempo que 90% das requisições não ultrapassam. O
programa abaixo gera 50 tempos (com alguns picos). Escreva
int percentil(int v[], int n, int pct) com o quickselect e mostre p50,
p90 e p99. Depois ordene com qsort e confira as posições 24, 44 e 49.


```text
Saída esperada:
p50: 138 ms
p90: 630 ms
p99: 826 ms
conferindo: 138, 630 e 826
```

**Dicas:**

1. Use a regra do "posto mais próximo": a posição do percentil pct é
   teto(pct * n / 100) - 1. Com inteiros: (pct * n + 99) / 100 - 1.
   Para n = 50: p50 fica na posição 24, p90 na 44 e p99 na 49.
2. Não precisa copiar o vetor entre um percentil e outro: o quickselect
   só troca os valores de lugar, não muda quais valores existem.

```bash
~/LPEDC/rodar 18-ordenacao-linear/0123-quickselect/E736.c
```

**Exercício E737** · ★★★

Ache os bugs. A secretaria da faculdade tem 10001 matrículas, numeradas de
1 a 10001 e já em ordem, e quer a matrícula mediana. Para fugir do pior
caso do vetor ordenado, o programador sorteou o pivô. Mas a resposta está
errada E o programa ainda faz milhares de separações. São DOIS erros:
conserte os dois e rode.


```text
Saída esperada:
mediana: 5001 (19 separações)
```



```text
Saída que aparece:
mediana: 5002 (3849 separações)
```

**Dicas:**

1. Com 10001 elementos, quantos ficam antes da mediana? Em que posição do
   vetor (contando de 0) ela está?
2. Mostre p, r e o pivô de cada separação. A partir da segunda, o pivô
   ainda é sorteado?
3. Resposta esperada: a mediana fica na posição N / 2 = 5000, e não em
   (N + 1) / 2 = 5001, que é a posição do 5002. E o sorteio está antes do
   while: só a primeira separação usa pivô sorteado; nas outras, o pivô
   volta a ser o último de um pedaço quase ordenado. A troca com o
   sorteado tem que ficar dentro do laço, antes de cada separa.

```bash
~/LPEDC/rodar 18-ordenacao-linear/0123-quickselect/E737.c
```

**Exercício E738** · ★★★

O pivô sorteado deixa o pior caso improvável, mas não impossível. Em
1973, Blum, Floyd, Pratt, Rivest e Tarjan acharam um pivô que GARANTE
O(n) no pior caso: a MEDIANA DAS MEDIANAS. Em cada volta do quickselect:

1. divida v[p..r] em grupos de 5 (o último pode ter menos), ordene cada
grupo com o insertion sort (já está no arquivo) e leve a mediana de
cada grupo para o começo do pedaço: v[p], v[p + 1], ...;
2. ache a mediana dessas medianas chamando a própria seleção
(recursivamente) só no pedaço das medianas;
3. use essa mediana como pivô: troque com v[r] e chame o separa de
sempre. O resto é o quickselect do texto.

Escreva int seleciona(int v[], int p, int r, int k, bool mm), que faz o
quickselect com pivô no fim (mm = false) ou com a mediana das medianas
(mm = true), e compare as comparações num vetor em ordem e num
embaralhado.


```text
Saída esperada:
vetor em ordem:
  pivô no fim:           mediana 5001,  37507500 comparações
  mediana das medianas:  mediana 5001,     61140 comparações
vetor embaralhado:
  pivô no fim:           mediana 5001,     28403 comparações
  mediana das medianas:  mediana 5001,     39964 comparações
```


A última linha mostra o preço da garantia: em dados comuns, o pivô
simples ganha.

**Dicas:**

1. Grupo g vai de g até fim = min(g + 4, r); a mediana dele, depois de
   ordenado, está em g + (fim - g) / 2. Troque-a com v[m] e faça m++,
   começando com m = p.
2. As medianas ficam em v[p..m-1]; a do meio está na posição
   meio = p + (m - p - 1) / 2. Chame seleciona(v, p, m - 1, meio, true):
   ela deixa a mediana das medianas exatamente em v[meio].
3. Depois, troca(&v[meio], &v[r]) e segue igual ao quickselect, com k
   sempre absoluto (posição no vetor inteiro).
4. Por que garante O(n)? A mediana das medianas é maior que uns 30% dos
   elementos e menor que outros 30%: cada volta descarta pelo menos 30%.

```bash
~/LPEDC/rodar 18-ordenacao-linear/0123-quickselect/E738.c
```

---

## 0124 · Juntando tudo

Fim do dia num banco digital: 1 milhão de Pix registrados, cada um com um
número, a hora (em segundos desde a meia-noite) e o valor em centavos. O time
de prevenção a fraudes pede dois relatórios: as transações em ordem de
**valor**, e a linha do tempo do dia em ordem de **horário**, com os Pix do
mesmo segundo do menor para o maior valor.

O caminho de sempre é o `qsort` (assunto 0096): ele ordena qualquer coisa,
desde que você dê uma função de comparação. Para 1 milhão de registros, são
uns 20 milhões de comparações, cada uma uma **chamada de função** por
ponteiro. Só que aqui as chaves são inteiros: o horário vai de 0 a 86399, e
o valor cabe em 4 bytes. Cabem as ordenações lineares deste módulo.

O TAD `pix.h` junta as peças. O registro tem 12 bytes:

```c
typedef struct {
    uint32_t id;       // número da transação, na ordem em que chegou
    int32_t segundo;   // hora do dia, em segundos desde a meia-noite
    int32_t centavos;  // valor, em centavos (sempre positivo)
} Pix;
```

As funções principais:

- `pix_por_valor`: **radix sort** em base 256 (assunto 0121) sobre o campo
  `centavos`. Quatro passadas, cada uma um counting sort estável pelo byte da
  vez, com um vetor auxiliar do mesmo tamanho;
- `pix_por_horario`: **counting sort** (assunto 0120) direto, com
  `k = 86400` contadores. Um vetor de 337 KB de contadores para 1 milhão de
  registros: `k` é menor que `n`, e o O(n + k) é linear de verdade;
- `pix_compara_valor`: a função de comparação para o `qsort`, para a
  comparação de tempo.

O segundo relatório tem **duas chaves**: horário e, no empate, valor. Não
precisa de função de comparação composta; basta a ideia do radix sort LSD:
ordene pela chave **menos** importante (valor) e depois, com um método
**estável**, pela mais importante (horário). A estabilidade do counting
sort preserva a ordem de valor dentro de cada segundo.

Os mesmos dados vão para dois vetores: um é ordenado
pelo `qsort`, o outro pelo radix. Os dois têm que terminar com os valores na
mesma ordem. Depois, o counting sort reorganiza o vetor do radix pelo
horário:

<p align="center"><img src="18-ordenacao-linear/0124-juntando-tudo/ideia.svg" alt="Diagrama da ideia: Juntando tudo" width="858"></p>

O programa mede o tempo de processador com `clock()`, de `<time.h>`: a
diferença entre duas chamadas, dividida por `CLOCKS_PER_SEC`, dá os
segundos gastos entre elas.

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "pix.h"

#define N 1000000

// tempo de processador gasto desde inicio, em segundos
double desde(clock_t inicio) {
    return (double) (clock() - inicio) / CLOCKS_PER_SEC;
}

int main(void) {
    Pix *a = malloc(N * sizeof(Pix));
    Pix *b = malloc(N * sizeof(Pix));
    Pix *aux = malloc(N * sizeof(Pix));
    if (a == NULL || b == NULL || aux == NULL) {
        free(a);
        free(b);
        free(aux);
        return 1;
    }
    pix_gera(a, N, 2024);
    memcpy(b, a, N * sizeof(Pix));     // os mesmos dados nos dois vetores

    clock_t t = clock();
    qsort(a, N, sizeof(Pix), pix_compara_valor);
    printf("qsort pelo valor:      %.2f s\n", desde(t));

    t = clock();
    pix_por_valor(b, aux, N);
    printf("radix pelo valor:      %.2f s\n", desde(t));

    int iguais = 1;
    for (int i = 0; i < N; i++) {
        if (a[i].centavos != b[i].centavos) {
            iguais = 0;
        }
    }
    printf("mesma ordem de valores? %s\n", iguais ? "sim" : "não");

    // segunda chave: pelo horário. O counting sort é estável, então dentro
    // do mesmo segundo os Pix continuam em ordem de valor
    t = clock();
    bool ok = pix_por_horario(b, aux, N);
    printf("counting pelo horário: %.2f s\n", desde(t));
    if (ok) {
        printf("os 4 primeiros do dia:\n");
        for (int i = 0; i < 4; i++) {
            pix_mostra(&b[i]);
        }
    }
    free(a);
    free(b);
    free(aux);
    return 0;
}
// Saída (os tempos mudam a cada execução e de máquina para máquina):
// qsort pelo valor:      0.28 s
// radix pelo valor:      0.08 s
// mesma ordem de valores? sim
// counting pelo horário: 0.04 s
// os 4 primeiros do dia:
// #0024846 00:00:00 R$       1,98
// #0293406 00:00:00 R$       7,46
// #0871952 00:00:00 R$      14,86
// #0653423 00:00:00 R$      21,63
```

O radix ordenou o milhão de valores em bem menos tempo que o `qsort`
(nesta execução, menos de um terço), e o counting pelo horário levou menos
ainda. Sem o AddressSanitizer e com `gcc -O2`, os números caem para uns
0,18 s, 0,03 s e 0,01 s: a proporção fica até maior. Os quatro primeiros do
dia são todos de 00:00:00 e estão em ordem de valor: a primeira ordenação
sobreviveu à segunda.

A conferência entre os dois vetores vem antes do segundo relatório. Comparar
com uma implementação confiável (o `qsort`) é o jeito mais simples de testar
uma ordenação escrita à mão:

<p align="center"><img src="18-ordenacao-linear/0124-juntando-tudo/fluxograma.svg" alt="Fluxograma: Juntando tudo" width="374"></p>

### Qual usar?

O resumo do módulo, com os algoritmos do módulo 13 de referência:

| Algoritmo | Custo | Memória extra | Estável | Quando usar |
| --- | --- | --- | --- | --- |
| shell sort | ~n^1,25 (Knuth: pior n^1,5) | O(1) | não | vetores médios, pouca memória, código curto |
| counting sort | O(n + k) | O(n + k) | sim | chaves inteiras num intervalo pequeno |
| radix sort | O(d · (n + b)) | O(n + b) | sim | inteiros ou strings de tamanho fixo |
| bucket sort | O(n) médio, O(n²) pior | O(n) | sim (inserindo depois dos iguais) | valores reais bem espalhados num intervalo conhecido |
| quickselect | O(n) médio, O(n²) pior | O(1) | não | o k-ésimo, a mediana, os k maiores, sem ordenar |
| qsort | O(n log n) | depende da biblioteca | não garantido | qualquer tipo, qualquer critério |

> [!WARNING]
> Ordenação linear troca a comparação por **suposições sobre os dados**. O counting sort pelo horário só funciona porque o
> horário vai de 0 a 86399; se um registro chegar com `segundo = 86400` (um
> bug na origem dos dados), `c[86400]` escreve fora do vetor. Antes de usar
> o valor como índice, confira a faixa, ou confie numa fonte que garanta.
> E o radix deste TAD supõe `centavos` positivo: um estorno negativo
> sairia no fim da lista (o exercício E726 mostra o conserto).

> [!TIP]
> **Por dentro do C:** cada passada do radix lê o vetor inteiro em
> sequência, do fim para o começo, e escreve espalhado em 256 regiões do
> auxiliar. 12 MB não cabem no cache, mas a leitura sequencial é a preferida
> do processador: ele adivinha os próximos endereços e busca antes.
> Já o `qsort` não sabe nada sobre o `Pix`: move cada registro como um
> bloco genérico de 12 bytes (só conhece o tamanho) e chama
> `pix_compara_valor` por ponteiro, sem poder colocar o código dela no
> lugar da chamada. As ordenações lineares exploram justamente o que o `qsort`
> ignora: o tipo e a faixa da chave.

> [!NOTE]
> **Pergunta para você:** o radix fez 4 passadas, mas nenhum Pix passa de
> R$ 9999,99 (999999 centavos, menos que 2²⁰). Quantas passadas seriam
> realmente necessárias? O byte 3 de todos os valores é zero: o que a
> quarta passada faz com o vetor?

### Hora de praticar

Arquivos em [`0124-juntando-tudo/`](18-ordenacao-linear/0124-juntando-tudo/).

**Exemplo A247 · Os maiores Pix do dia, sem ordenar o dia**

```c
#include <stdio.h>
#include <stdlib.h>
#include "pix.h"

#define N 1000000
#define TOP 5

void troca(Pix *a, Pix *b) {
    Pix aux = *a;
    *a = *b;
    *b = aux;
}

// quickselect pelo valor, com pivô do meio (os dados não vêm ordenados,
// mas o pivô do meio custa nada e protege do caso ordenado)
void seleciona(Pix v[], int n, int k) {
    int p = 0, r = n - 1;
    while (p < r) {
        troca(&v[p + (r - p) / 2], &v[r]);
        int pivo = v[r].centavos, j = p;
        for (int i = p; i < r; i++) {
            if (v[i].centavos <= pivo) {
                troca(&v[j], &v[i]);
                j++;
            }
        }
        troca(&v[j], &v[r]);
        if (j == k) {
            return;
        }
        if (k < j) {
            r = j - 1;
        } else {
            p = j + 1;
        }
    }
}

int main(void) {
    Pix *v = malloc(N * sizeof(Pix));
    if (v == NULL) {
        return 1;
    }
    pix_gera(v, N, 2024);

    seleciona(v, N, N / 2);
    printf("valor mediano: R$ %d,%02d\n", v[N / 2].centavos / 100, v[N / 2].centavos % 100);

    // os TOP maiores ficam em v[N-TOP..N-1]; só eles precisam de ordem
    seleciona(v, N, N - TOP);
    qsort(v + N - TOP, TOP, sizeof(Pix), pix_compara_valor);
    printf("os %d maiores do dia:\n", TOP);
    for (int i = N - 1; i >= N - TOP; i--) {
        pix_mostra(&v[i]);
    }
    free(v);
    return 0;
}
// Saída:
// valor mediano: R$ 56,98
// os 5 maiores do dia:
// #0323438 02:04:16 R$    9999,90
// #0698564 18:19:13 R$    9999,85
// #0090794 01:05:26 R$    9999,61
// #0331073 07:40:47 R$    9999,58
// #0324779 17:16:28 R$    9999,55
//
// Duas seleções e um qsort de 5 elementos, em vez de ordenar 1 milhão. O
// valor mediano (R$ 56,98) é bem menor que a média, puxada pelos poucos Pix
// grandes. Repare que pix_compara_valor, feita para o qsort do vetor
// inteiro, serve igual para ordenar só o pedaço v + N - TOP.
```

```bash
~/LPEDC/rodar 18-ordenacao-linear/0124-juntando-tudo/A247.c
```

**Exemplo A248 · Três ordenações, o mesmo resultado**

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "pix.h"

#define N 200000

// shell sort pelo valor (assunto 0119): sem memória extra
void shell_por_valor(Pix v[], int n) {
    int h = 1;
    while (h < n / 3) {
        h = 3 * h + 1;
    }
    for (; h >= 1; h /= 3) {
        for (int i = h; i < n; i++) {
            Pix x = v[i];
            int j = i;
            while (j >= h && v[j - h].centavos > x.centavos) {
                v[j] = v[j - h];
                j -= h;
            }
            v[j] = x;
        }
    }
}

// mesmos valores, na mesma ordem?
int mesmos_valores(const Pix a[], const Pix b[], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i].centavos != b[i].centavos) {
            return 0;
        }
    }
    return 1;
}

// nos empates de valor, os ids continuam crescentes (ordem de chegada)?
int estavel(const Pix v[], int n) {
    for (int i = 1; i < n; i++) {
        if (v[i].centavos == v[i - 1].centavos && v[i].id < v[i - 1].id) {
            return 0;
        }
    }
    return 1;
}

int main(void) {
    Pix *a = malloc(N * sizeof(Pix));
    Pix *b = malloc(N * sizeof(Pix));
    Pix *c = malloc(N * sizeof(Pix));
    Pix *aux = malloc(N * sizeof(Pix));
    if (a == NULL || b == NULL || c == NULL || aux == NULL) {
        free(a);
        free(b);
        free(c);
        free(aux);
        return 1;
    }
    pix_gera(a, N, 31);
    memcpy(b, a, N * sizeof(Pix));
    memcpy(c, a, N * sizeof(Pix));

    clock_t t = clock();
    shell_por_valor(a, N);
    printf("shell sort: %.3f s\n", (double) (clock() - t) / CLOCKS_PER_SEC);
    t = clock();
    qsort(b, N, sizeof(Pix), pix_compara_valor);
    printf("qsort:      %.3f s\n", (double) (clock() - t) / CLOCKS_PER_SEC);
    t = clock();
    pix_por_valor(c, aux, N);
    printf("radix:      %.3f s\n", (double) (clock() - t) / CLOCKS_PER_SEC);

    printf("valores iguais nos três? %s\n",
           mesmos_valores(a, b, N) && mesmos_valores(b, c, N) ? "sim" : "não");
    printf("empates na ordem de chegada? shell: %s, radix: %s\n",
           estavel(a, N) ? "sim" : "não", estavel(c, N) ? "sim" : "não");
    free(a);
    free(b);
    free(c);
    free(aux);
    return 0;
}
// Saída (os tempos mudam a cada execução):
// shell sort: 0.077 s
// qsort:      0.057 s
// radix:      0.027 s
// valores iguais nos três? sim
// empates na ordem de chegada? shell: não, radix: sim
//
// Os três concordam nos valores, mas não nos registros: há muitos Pix com o
// mesmo valor (só 9999 valores pequenos possíveis para 200 mil Pix), e o
// shell sort, que não é estável, embaralha os empates. O radix mantém a
// ordem de chegada. E o qsort? O padrão do C não promete estabilidade:
// dependendo da versão da biblioteca, os empates saem de um jeito ou de
// outro. Nos tempos, o shell sort perde para os dois, mas não usa nem um
// byte de memória extra.
```

```bash
~/LPEDC/rodar 18-ordenacao-linear/0124-juntando-tudo/A248.c
```

#### Exercícios

**Exercício E739** · ★☆☆

Use o TAD pix.h (está na pasta) para um teste pequeno antes de rodar com
um milhão. Gere 8 Pix com pix_gera e a semente 5, ordene pelo horário com
pix_por_horario e mostre a linha do tempo com pix_mostra. Depois ordene
pelo valor com pix_por_valor e mostre o Pix de menor e o de maior valor.


```text
Saída esperada:
linha do tempo:
#0000001 06:37:44 R$      46,82
#0000003 07:00:16 R$      71,08
#0000008 07:23:43 R$      88,39
#0000002 10:58:31 R$      14,80
#0000007 12:02:53 R$      50,89
#0000006 14:11:55 R$      87,07
#0000005 14:28:08 R$    3960,62
#0000004 15:23:46 R$      88,47
menor: #0000002 10:58:31 R$      14,80
maior: #0000005 14:28:08 R$    3960,62
```

**Dicas:**

1. As duas ordenações pedem um vetor auxiliar do mesmo tamanho:
   Pix v[8], aux[8];
2. pix_por_horario devolve false se não conseguir memória para os
   contadores: confira.
3. pix_mostra já pula a linha; para o "menor: " ficar na mesma linha,
   use printf sem \n antes.

```bash
~/LPEDC/rodar 18-ordenacao-linear/0124-juntando-tudo/E739.c
```

**Exercício E740** · ★☆☆

Antes de ordenar, vale olhar os dados. Conte quantos dos 1 milhão de Pix
do dia (pix_gera com a semente 2024) caem em cada faixa de valor: até
R$ 9,99; de R$ 10 a R$ 99,99; de R$ 100 a R$ 999,99; R$ 1000 ou mais. É
o primeiro laço do counting sort, com uma chave calculada: a faixa.


```text
Saída esperada:
até R$ 9,99:         87654 ( 8.8%)
R$ 10 a R$ 99,99:   788605 (78.9%)
R$ 100 a R$ 999,99:  11383 ( 1.1%)
R$ 1000 ou mais:    112358 (11.2%)
```

**Dicas:**

1. Escreva int faixa(int32_t centavos), que devolve 0, 1, 2 ou 3. Cuidado
   com a unidade: R$ 9,99 são 999 centavos.
2. Um int c[4] = {0}; e c[faixa(v[i].centavos)]++ para cada Pix.
3. O vetor de 1 milhão de Pix (12 MB) vai no heap, com malloc e free.
4. Formato: "%s %6d (%4.1f%%)\n", com os rótulos já alinhados com espaços.

```bash
~/LPEDC/rodar 18-ordenacao-linear/0124-juntando-tudo/E740.c
```

**Exercício E741** · ★★☆

O texto ordenou pelo valor e DEPOIS pelo horário para ter a linha do
tempo com os empates de segundo em ordem de valor. E se fizer na ordem
contrária? Escreva bool em_ordem(const Pix v[], int n, bool
horario_primeiro), que confere se v está em ordem de (horário, valor) ou,
com horario_primeiro = false, de (valor, horário). Depois, com 200 mil Pix
(semente 77) em dois vetores iguais, faça as duas ordens de passadas e
confira.


```text
Saída esperada:
valor, depois horário: (horário, valor)? sim
horário, depois valor: (horário, valor)? não
horário, depois valor: (valor, horário)? sim
```

**Dicas:**

1. Em ordem de (horário, valor) quer dizer: para cada vizinho, o horário
   de v[i - 1] é menor, ou é igual e o valor é menor ou igual.
2. Use memcpy para começar os dois vetores iguais e um aux só para as
   quatro ordenações.
3. A última passada é a que manda (é a chave principal); as anteriores só
   desempatam, e só porque as duas ordenações são estáveis.

```bash
~/LPEDC/rodar 18-ordenacao-linear/0124-juntando-tudo/E741.c
```

**Exercício E742** · ★★☆

O time de fraudes quer duas estatísticas dos valores do dia: a mediana
(posição N / 2) e o p99 (posição 989999 de 1 milhão, pela regra do posto
mais próximo). Para economizar, copie só os valores (os centavos) para um
vetor de int, 4 MB em vez dos 12 MB dos registros, e use o quickselect
nele, com pivô do meio. Depois confira: ordene os registros com
pix_por_valor e compare as duas posições.


```text
Saída esperada:
mediana: R$ 56,98
p99:     R$ 9160,98
conferindo com o radix: iguais
```

**Dicas:**

1. Dados: pix_gera(v, 1000000, 2024).
2. O quickselect do texto com uma linha a mais no começo de cada volta:
   troca(&v[p + (r - p) / 2], &v[r]), o pivô do meio.
3. Dá para chamar a seleção duas vezes no mesmo vetor de int: a segunda
   chamada só reaproveita a bagunça da primeira.
4. Formato do dinheiro: "R$ %d,%02d" com centavos / 100 e centavos % 100.

```bash
~/LPEDC/rodar 18-ordenacao-linear/0124-juntando-tudo/E742.c
```

**Exercício E743** · ★★★

Ache os bugs. Um colega reescreveu o counting sort pelo horário em vez de
usar o pix_por_horario, para montar a linha do tempo do horário de
almoço: pelo horário e, no mesmo segundo, pelo valor (por isso o
pix_por_valor roda antes). A saída não tem nada em ordem de horário. São
DOIS erros, os dois em ordena_horario. Conserte e rode.


```text
Saída esperada:
#0000005 12:00:00 R$       8,70
#0000002 12:00:00 R$      12,50
#0000007 12:00:00 R$     150,00
#0000003 12:00:01 R$       9,90
#0000006 12:00:01 R$      25,00
#0000001 12:00:01 R$      50,00
#0000008 12:00:02 R$       6,40
#0000004 12:00:02 R$     300,00
```

**Dicas:**

1. A saída que aparece está em ordem de VALOR: é como se ordena_horario
   não tivesse feito nada. Onde fica o resultado do terceiro laço?
2. Consertado o primeiro erro, os horários entram em ordem, mas dentro de
   cada segundo os valores saem do maior para o menor.
3. Resposta esperada: falta copiar aux de volta para v no fim (o
   resultado ficava só no rascunho). E o terceiro laço anda da frente
   para trás: com --c[...], o primeiro de cada segundo fica com a última
   vaga, e a ordem de valor deixada pelo radix se inverte. O certo é
   for (int i = n - 1; i >= 0; i--).

```bash
~/LPEDC/rodar 18-ordenacao-linear/0124-juntando-tudo/E743.c
```

**Exercício E744** · ★★★

A pergunta do texto: nenhum Pix passa de R$ 9999,99, então o byte 3 de
todos os valores é zero, e a quarta passada do radix copia 12 MB à toa.
Escreva int radix_esperto(Pix v[], Pix aux[], int n), um radix em base
256 pelo valor que, em cada passada, conta os bytes e, se TODOS caírem no
mesmo balde (algum c[x] == n), pula a passada. Devolva quantas passadas
fez. O programa compara com o pix_por_valor (os ids têm que sair na mesma
ordem, porque os dois são estáveis) em dois casos.


```text
Saída esperada:
valores do dia:      3 passadas de 4, igual ao pix_por_valor? sim
valores até R$ 2,55: 1 passada de 4, igual ao pix_por_valor? sim
```

**Dicas:**

1. Pular uma passada é seguro: se todo mundo tem o mesmo byte, um counting
   sort estável por ele deixaria o vetor exatamente como está.
2. A contagem precisa vir antes da decisão: conte, confira, e só então
   acumule e distribua.
3. Use dois ponteiros, origem e destino, e troque os dois depois de cada
   passada feita. Com um número ímpar de passadas (3 ou 1), o resultado
   termina no aux: copie de volta com memcpy.

```bash
~/LPEDC/rodar 18-ordenacao-linear/0124-juntando-tudo/E744.c
```

---

## Desafios do módulo

Problemas para fechar o módulo, misturando os assuntos. Escreva em C e rode
com o `rodar`.

**1. Quantas passadas?** Você vai ordenar 50 milhões de CPFs (11 dígitos,
guardados em `uint64_t`) com radix sort. Quantas passadas são em base 10? E
em base 256? E em base 65536 (dois bytes por vez)? Qual o tamanho do vetor
de contadores em cada caso?

<details><summary>Resposta</summary>

Base 10: **11 passadas**, 10 contadores. O maior CPF é menor que 10¹¹, que
é menor que 2³⁷: cabe em 37 bits. Base 256: ⌈37 / 8⌉ = **5 passadas**, 256
contadores (1 KB). Base 65536: ⌈37 / 16⌉ = **3 passadas**, 65536 contadores
(256 KB, que já não cabem no cache L1). Menos passadas nem sempre é mais
rápido: os contadores precisam caber perto do processador.

</details>

**2. Notas do vestibular.** São 2 milhões de candidatos, com notas de 0,00 a
1000,00 (duas casas). Ordene em O(n) do maior para o menor, mantendo, em
caso de empate, a ordem de inscrição.

<details><summary>Resposta</summary>

Multiplique por 100: as notas viram inteiros de 0 a 100000. Counting sort
estável com `k = 100001` contadores (uns 400 KB) e a chave invertida,
`100000 - nota`, para a ordem decrescente. Os empates ficam na ordem de
inscrição porque o terceiro laço anda de trás para a frente. Custo:
O(n + k), uns 2,1 milhões de passos.

</details>

**3. Elemento majoritário.** Um vetor de 1 milhão de votos (números de 1 a
5000) tem um candidato com **mais da metade** dos votos. Ache-o em O(n) de
dois jeitos: com contagem e com o quickselect.

<details><summary>Resposta</summary>

Contagem: `c[5001]`, um laço, e o `x` com `c[x] > n / 2`. Quickselect: se
um valor aparece mais de `n / 2` vezes, ele ocupa obrigatoriamente a
posição `n / 2` do vetor ordenado, então `quickselect(v, n, n / 2)` é a
resposta. O primeiro gasta 20 KB de contadores e não mexe no vetor; o
segundo não gasta memória, mas bagunça o vetor.

</details>

**4. Shell sort com Ciura.** Troque os saltos de Knuth pelos de Ciura (1,
4, 10, 23, 57, 132, 301, 701, e depois multiplicando por 2,25) e conte as
comparações num vetor aleatório de 100 mil elementos, com o gerador do
exemplo A237.

<details><summary>Resposta</summary>

Guarde os saltos num vetor e use do maior que seja menor que `n` até o 1.
Os de Ciura foram achados por experimento e costumam fazer menos
comparações que os de Knuth, no caso médio. Não há fórmula fechada para o custo
de nenhum dos dois: é um dos problemas em aberto da análise de algoritmos.

</details>

**5. Os 10 mais próximos.** Um app de entregas tem 200 mil motoboys, cada um
com a distância (em metros) até o restaurante. Ache os 10 mais próximos,
em ordem. Compare três jeitos: ordenar tudo, quickselect + ordenar 10, e um
heap de máximo de tamanho 10 (assunto 0102).

<details><summary>Resposta</summary>

Ordenar: O(n log n), uns 3,5 milhões de comparações. Quickselect em
`k = 9` deixa os 10 menores em `v[0..9]`; ordenar esses 10 custa quase nada: O(n) em
média, uns 400 mil passos. O heap de 10 passa uma vez pelo vetor: cada
motoboy mais perto que o pior do heap entra no lugar dele, O(n log 10), sem
bagunçar o vetor e funcionando com dados que chegam aos poucos.

</details>

**6. Datas e horas em uma chave.** Ordene 1 milhão de registros de ponto
(data e hora de entrada de cada funcionário) em ordem cronológica com **uma**
ordenação linear, sem passadas por campo.

<details><summary>Resposta</summary>

Monte uma chave numérica que já esteja em ordem cronológica:
`chave = ((ano * 12 + mes) * 31 + dia) * 86400 + segundo`, num
`uint64_t`. Depois, um radix em base 256 sobre a chave (5 passadas bastam
para os bits usados). É o mesmo truque das datas do E724, mas com as casas
juntas num número só.

</details>

**7. Bucket sort que se adapta.** O bucket sort do assunto 0122 sofre quando
os dados se concentram numa faixa. Proponha uma versão que não dependa de
o intervalo estar bem espalhado.

<details><summary>Resposta</summary>

Escolha as fronteiras dos baldes pelos **dados**, não pelo intervalo: pegue
uma amostra (por exemplo, 1000 elementos), ordene a amostra e use os seus
percentis como fronteiras. Para achar o balde de um valor, faça uma busca
binária (assunto 0090) nas fronteiras. Cada balde recebe mais ou menos a
mesma quantidade, qualquer que seja a distribuição. É a ideia do
*samplesort*, usado em ordenações paralelas.

</details>

**8. Radix de strings de tamanhos diferentes.** O radix LSD do exemplo A241
exige strings do mesmo tamanho. Ordene `"ana", "bia", "an", "bianca", "a"`
com radix, sem completar as strings com espaços.

<details><summary>Resposta</summary>

Trate a posição que não existe como o caractere 0, menor que qualquer
letra: a chave da posição `p` é `p < strlen(s) ? (unsigned char) s[p] : 0`.
Faça as passadas da posição `max - 1` até 0 (aqui, `max = 6`). O resultado
é `a an ana bia bianca`. A alternativa é o radix **MSD**: começa pela
primeira letra, divide em baldes e ordena cada balde recursivamente, o que
nem olha o fim das strings curtas.

</details>

**9. Mediana em fluxo.** As temperaturas de um sensor chegam uma a uma, e a
cada leitura você precisa mostrar a mediana até ali. Rodar o quickselect a
cada leitura custa O(n) por leitura. Faça melhor.

<details><summary>Resposta</summary>

Dois heaps (assunto 0102): um heap de **máximo** com a metade menor e um
de **mínimo** com a metade maior, com tamanhos que diferem no máximo em 1.
Cada leitura entra num deles e, se precisar, um elemento passa de um para o
outro. A mediana é a raiz do maior (ou a média das duas raízes). Cada
leitura custa O(log n).

</details>

**10. Contar inversões em O(n log n).** O exercício E714 contou inversões
com dois laços, O(n²). Conte as inversões de um vetor de 100 mil elementos
em O(n log n).

<details><summary>Resposta</summary>

Modifique o merge sort (assunto 0094): na intercalação, quando um elemento
da metade **direita** passa na frente, ele forma inversão com todos os que
ainda restam na metade esquerda. Some `meio - i` nesse momento. O total sai
junto com o vetor ordenado. Num vetor decrescente de 100 mil, são
4.999.950.000 inversões: use `long long`.

</details>

## Lista de exercícios práticos

30 exercícios que misturam os assuntos do módulo, no ritmo da prova do PPGI. Arquivos em [`lista/`](18-ordenacao-linear/lista/); resoluções em `_respostas/18-ordenacao-linear/lista/`.

### ★☆☆ Aquecimento

**Exercício P1801** · ★☆☆ · Counting sort passo a passo: o vetor C e a saída

No posto de vacinação, as idades das 10 crianças da fila (0 a 4 anos) vão
para o relatório em ordem. Escreva do zero o counting sort do Cormen e
mostre o estado dos vetores como a prova pede:

1. C depois da contagem (C[x] = quantas crianças têm x anos);
2. C depois das somas acumuladas (C[x] = quantas têm idade <= x);
3. cada passo da colocação, de trás para frente: o valor, a posição em que
ele entra na saída B e o vetor C logo depois;
4. o vetor B no fim.

Use posições de 0 a n - 1 (em C, decremente antes de usar).


```text
Saída esperada:
Contagem: C = 1 3 1 2 3
Acumulado: C = 1 4 5 7 10
A[9] = 1 vai para B[3] | C = 1 3 5 7 10
A[8] = 3 vai para B[6] | C = 1 3 5 6 10
A[7] = 4 vai para B[9] | C = 1 3 5 6 9
A[6] = 1 vai para B[2] | C = 1 2 5 6 9
A[5] = 2 vai para B[4] | C = 1 2 4 6 9
A[4] = 0 vai para B[0] | C = 0 2 4 6 9
A[3] = 4 vai para B[8] | C = 0 2 4 6 8
A[2] = 3 vai para B[5] | C = 0 2 4 5 8
A[1] = 1 vai para B[1] | C = 0 1 4 5 8
A[0] = 4 vai para B[7] | C = 0 1 4 5 7
B = 0 1 1 1 2 3 3 4 4 4
```

**Dicas:**

1. Depois da soma acumulada, C[x] - 1 é a ÚLTIMA posição livre do bloco
   dos x: por isso o laço da colocação anda de trás para frente e
   decrementa antes de gravar.
2. Mostre C com uma função que recebe um rótulo, como mostra("C:", c).
3. O último elemento de A (1) é o primeiro a ser colocado: vai para a
   última posição do bloco dos 1.
4. Resposta esperada: C = 1 3 1 2 3 depois da contagem, 1 4 5 7 10 depois
   das somas, e B = 0 1 1 1 2 3 3 4 4 4.

```bash
~/LPEDC/rodar 18-ordenacao-linear/lista/P1801.c
```

---

**Exercício P1802** · ★☆☆ · Shell sort com os saltos de Shell: n/2, n/4, ..., 1

Os saltos originais de Donald Shell (1959) são n/2, n/4, ..., 1 (divisão
inteira). Ordene as alturas, em cm, dos 10 atletas do time de basquete da
escola com essa sequência e mostre o vetor depois de cada passada, junto
com o salto e as comparações feitas naquela passada.

Cada passada com salto h é um insertion sort que compara v[j] com
v[j - h] em vez de v[j - 1].


```text
Saída esperada:
início: 190 175 201 168 183 178 194 172 186 181
h = 5:  178 175 172 168 181 190 194 201 186 183  (5 comparações)
h = 2:  172 168 178 175 181 183 186 190 194 201  (11 comparações)
h = 1:  168 172 175 178 181 183 186 190 194 201  (10 comparações)
```

**Dicas:**

1. for (h = n / 2; h >= 1; h /= 2), e dentro o insertion sort com passo h:
   para i de h até n - 1, desloque de h em h enquanto v[j - h] > x.
2. Conte uma comparação a cada teste v[j - h] > x que chega a ser feito
   (quando j - h >= 0).
3. Com n = 10, os saltos são 5, 2 e 1. Na última passada, o vetor já está
   quase ordenado e o insertion sort trabalha pouco.
4. Resposta esperada: o vetor final 168 172 175 178 181 183 186 190 194
   201, com 5, 11 e 10 comparações nas três passadas.

```bash
~/LPEDC/rodar 18-ordenacao-linear/lista/P1802.c
```

---

**Exercício P1803** · ★☆☆ · Radix com base 100: dois dígitos por passada

As matrículas dos calouros têm 6 dígitos. Em base 10, o radix sort LSD faz
6 passadas. Em base 100, cada "dígito" é um par de dígitos decimais (de 00
a 99), e bastam 3 passadas: (m / 1) % 100, (m / 100) % 100 e
(m / 10000) % 100.

Escreva o radix sort LSD em base 100, com um counting sort estável de 100
posições em cada passada, e mostre o vetor depois de cada passada, com o
divisor usado.


```text
Saída esperada:
div     1: 230105 190305 241012 241077 210477 230388 180399
div   100: 230105 190305 230388 180399 210477 241012 241077
div 10000: 180399 190305 210477 230105 230388 241012 241077
```

**Dicas:**

1. Mesma estrutura do radix em base 10: só troque 10 por 100. O vetor C
   passa a ter 100 posições.
2. Com d passadas de base b, o custo é Θ(d (n + b)). Aqui d = 3 e b = 100
   contra d = 6 e b = 10: com poucos números, b = 100 pesa; com milhões,
   metade das passadas ganha.
3. Depois da primeira passada, o vetor está ordenado pelos dois últimos
   dígitos; depois da segunda, pelos quatro últimos.
4. Resposta esperada: na primeira passada, 230105 e 190305 (final 05) vêm
   antes de 241012; no fim, 180399 190305 210477 230105 230388 241012
   241077.

```bash
~/LPEDC/rodar 18-ordenacao-linear/lista/P1803.c
```

---

**Exercício P1804** · ★☆☆ · Bucket sort da ocupação dos voos

A companhia aérea guarda a taxa de ocupação de cada voo do dia como um
número em [0, 1): 0.87 é 87% dos assentos. Ordene as 10 taxas do esqueleto
com o bucket sort do Cormen: n = 10 baldes, o valor x vai para o balde
⌊10 x⌋, cada balde é uma lista encadeada (malloc) mantida em ordem por
inserção, e no fim os baldes são concatenados em ordem.

Mostre o conteúdo de cada balde não vazio e o vetor ordenado. Libere todos
os nós.


```text
Saída esperada:
balde 0: 0.05
balde 1: 0.12
balde 3: 0.31 0.36
balde 5: 0.52
balde 7: 0.79
balde 8: 0.84 0.87 0.88
balde 9: 0.99
ordenado: 0.05 0.12 0.31 0.36 0.52 0.79 0.84 0.87 0.88 0.99
```

**Dicas:**

1. Balde de x: (int)(x * n). Como x < 1, o índice fica entre 0 e n - 1.
2. Inserir em ordem numa lista: ande com um ponteiro para ponteiro
   (No **p = &balde[b]) enquanto (*p)->x < x, e encaixe o novo ali.
3. Com dados espalhados por igual, cada balde recebe O(1) itens em média e
   o total é Θ(n). Aqui o balde 8 recebe três voos.
4. Resposta esperada: baldes 0, 1, 3, 5, 7, 8 e 9 ocupados; o vetor
   ordenado começa em 0.05 e termina em 0.99.

```bash
~/LPEDC/rodar 18-ordenacao-linear/lista/P1804.c
```

---

**Exercício P1805** · ★☆☆ · O 3º posto mais barato, partição por partição

O app de combustível tem o preço do litro (em centavos) em 9 postos de
Manaus e quer o 3º MENOR preço sem ordenar tudo. Escreva o quickselect com
a partição de Lomuto (pivô = último elemento do pedaço) e mostre cada
partição: o pedaço [ini, fim], o pivô, a posição final dele e para que lado
a busca continua. Use k a partir de 1 (k = 1 é o menor).


```text
Saída esperada:
[0, 8] pivô 594 foi para 3 -> esquerda
[0, 2] pivô 579 foi para 1 -> direita
[2, 2] pivô 589 foi para 2 -> achou
3º menor preço: 589 centavos (R$ 5,89)
```

**Dicas:**

1. Depois da partição, o pivô está na posição p, e há p - ini elementos
   menores à esquerda dele no pedaço. Compare p com a posição procurada,
   k - 1 (índice a partir de 0).
2. Se p == k - 1, achou. Se k - 1 < p, continue em [ini, p - 1]; senão, em
   [p + 1, fim]. Só UM lado: por isso o caso médio é Θ(n), e não n lg n.
3. Faça iterativo (um laço while): não precisa de recursão, porque só há
   uma chamada.
4. Resposta esperada: três partições, e o 3º menor preço é 589 centavos
   (R$ 5,89).

```bash
~/LPEDC/rodar 18-ordenacao-linear/lista/P1805.c
```

---

**Exercício P1806** · ★☆☆ · De trás para frente ou da frente para trás?

As inscrições da corrida de rua chegam em ordem de inscrição, cada uma com
o nome e a categoria (0 = 5 km, 1 = 10 km, 2 = meia, 3 = maratona). A
organização quer a lista por categoria e, dentro dela, na ORDEM DE
INSCRIÇÃO: é preciso uma ordenação ESTÁVEL.

Complete o counting sort por categoria com um parâmetro bool de_tras: com
true, a colocação anda de n - 1 até 0 (a versão do Cormen); com false,
anda de 0 até n - 1, mas continua usando --c[x]. Mostre as duas saídas e
diga, para cada uma, se ficou estável (compare a ordem dos nomes dentro de
cada categoria com a ordem de inscrição, guardada no campo ordem).


```text
Saída esperada:
de trás: Bruno(0) Elis(0) Ana(1) Davi(1) Gil(1) Fabio(2) Carla(3) Hana(3) -> estável
da frente: Elis(0) Bruno(0) Gil(1) Davi(1) Ana(1) Fabio(2) Hana(3) Carla(3) -> NÃO estável
```

**Dicas:**

1. Com --c[x], cada bloco é preenchido de trás para frente. Se a leitura
   também é de trás para frente, o último inscrito de cada categoria fica
   no fim do bloco: a ordem se mantém.
2. Lendo da frente com --c[x], o PRIMEIRO inscrito vai para o fim do bloco:
   os empates saem invertidos. Para ler da frente e ser estável, seria
   preciso usar as posições iniciais dos blocos com c[x]++.
3. Estável: para todo i, se saida[i].cat == saida[i + 1].cat, então
   saida[i].ordem < saida[i + 1].ordem.
4. Resposta esperada: de trás para frente é estável (Ana antes de Davi nos
   10 km); da frente para trás, não.

```bash
~/LPEDC/rodar 18-ordenacao-linear/lista/P1806.c
```

---

**Exercício P1807** · ★☆☆ · Quantas corridas entre R$ 10 e R$ 20? Em O(1)

O app de transporte registrou o valor (em reais inteiros, de 0 a 50) das
20 corridas da manhã. O gerente vai fazer várias perguntas do tipo
"quantas corridas custaram entre a e b reais?".

O vetor acumulado do counting sort responde cada pergunta em O(1): depois
de um pré-processamento Θ(n + k), C[x] = quantas corridas custaram <= x, e
a resposta para [a, b] é C[b] - C[a - 1] (com C[-1] = 0). Escreva o
pré-processamento e a função int entre(const int c[], int a, int b), e
responda às perguntas do esqueleto.


```text
Saída esperada:
Entre R$ 10 e R$ 20:  9 corridas
Entre R$  0 e R$ 50: 20 corridas
Entre R$  0 e R$  9:  4 corridas
Entre R$ 15 e R$ 15:  2 corridas
Entre R$ 30 e R$ 50:  4 corridas
```

**Dicas:**

1. Mesmo começo do counting sort: conte cada valor e faça as somas
   acumuladas. Não precisa ordenar nada.
2. Cuidado com a = 0: não existe C[-1]; trate como 0.
3. Para conferir, a pergunta [0, 50] tem de dar 20, e [x, x] dá quantas
   corridas custaram exatamente x.
4. Resposta esperada: 9 corridas entre R$ 10 e R$ 20, 20 no total, 4 até
   R$ 9 e 2 de exatamente R$ 15.

```bash
~/LPEDC/rodar 18-ordenacao-linear/lista/P1807.c
```

---

**Exercício P1808** · ★☆☆ · Radix sort bit a bit: zeros na frente, uns atrás

O radix sort não precisa de base 10: em base 2, cada passada olha um bit.
Com um bit só, o counting sort vira uma SEPARAÇÃO ESTÁVEL: primeiro todos
os que têm aquele bit 0, na ordem em que estão, depois todos os que têm 1,
também na ordem.

Os códigos das 8 linhas de um terminal de ônibus vão de 0 a 15 (4 bits).
Escreva a passada (bit b: (x >> b) & 1) e rode o radix LSD do bit 0 ao
bit 3, mostrando o vetor em binário e em decimal depois de cada passada.


```text
Saída esperada:
início 1100 0101 1001 1110 0011 1010 0110 1011 | 12 5 9 14 3 10 6 11
bit 0   1100 1110 1010 0110 0101 1001 0011 1011 | 12 14 10 6 5 9 3 11
bit 1   1100 0101 1001 1110 1010 0110 0011 1011 | 12 5 9 14 10 6 3 11
bit 2   1001 1010 0011 1011 1100 0101 1110 0110 | 9 10 3 11 12 5 14 6
bit 3   0011 0101 0110 1001 1010 1011 1100 1110 | 3 5 6 9 10 11 12 14
```

**Dicas:**

1. Uma passada: conte quantos têm o bit 0 (zeros); percorra o vetor
   copiando os de bit 0 para saida[iz++] (iz começa em 0) e os de bit 1
   para saida[iu++] (iu começa em zeros). É o counting sort com k = 2, sem
   precisar ler de trás para frente.
2. Para imprimir em binário, mostre os bits 3, 2, 1 e 0 de cada número.
3. Depois da passada do bit b, o vetor está ordenado pelos b + 1 bits de
   baixo: é o invariante do radix LSD.
4. Resposta esperada: no fim, 0011 0101 0110 1001 1010 1011 1100 1110
   (3 5 6 9 10 11 12 14).

```bash
~/LPEDC/rodar 18-ordenacao-linear/lista/P1808.c
```

---

**Exercício P1809** · ★☆☆ · A tabela do campeonato em ordem decrescente, estável

No campeonato de futsal do bairro, os times já estão em ordem alfabética.
A tabela tem de sair por PONTOS, do maior para o menor, e os empatados
continuam em ordem alfabética. Os pontos vão de 0 a 15.

Complete o counting sort decrescente e estável. Para isso, ordene pela chave
invertida, MAX - pontos, em ordem crescente. Quem tem mais pontos tem chave
menor e vai para o começo, e a estabilidade do counting sort preserva a
ordem alfabética dos empates.


```text
Saída esperada:
1. Goias            15
2. Para             12
3. Amazonas          9
4. Bahia             9
5. Ceara             9
6. Espirito Santo    7
7. Fortaleza         4
8. Distrito Federal  2
```

**Dicas:**

1. Use chave(t) = 15 - t.pontos em todos os lugares em que o counting sort
   usaria t.pontos.
2. Não dá para ordenar crescente e inverter o vetor depois: a inversão
   também inverte os empates (Bahia sairia antes de Amazonas).
3. Confira os empates: Amazonas, Bahia e Ceara têm 9 pontos.
4. Resposta esperada: Goias 15, Para 12, Amazonas 9, Bahia 9, Ceara 9,
   Espirito Santo 7, Fortaleza 4, Distrito Federal 2.

```bash
~/LPEDC/rodar 18-ordenacao-linear/lista/P1809.c
```

---

**Exercício P1810** · ★☆☆ · Conserte o counting sort das notas

Conserte o programa. Ele ordena as notas (inteiras, de 0 a 10) de 12 alunos
com counting sort, mas tem DOIS erros de propósito, e os dois são de
índice. Rode com ./rodar: o AddressSanitizer acusa leitura e escrita fora
do vetor c (stack-buffer-overflow). Ache os dois, conserte e confira a
saída:


```text
Saída esperada:
0 3 4 5 5 6 7 7 8 9 10 10
```

**Dicas:**

1. Se as notas vão de 0 a K, quantas posições o vetor de contagem precisa
   ter? Um vetor int c[K] tem as posições 0 a K - 1.
2. Olhe o laço das somas acumuladas: na primeira volta, que posição ele
   lê?
3. Os dois erros são clássicos de "fora por um". Em C, nada impede o
   acesso fora do vetor: só o sanitizer (ou um resultado esquisito) avisa.
4. Resposta esperada: 0 3 4 5 5 6 7 7 8 9 10 10.

```bash
~/LPEDC/rodar 18-ordenacao-linear/lista/P1810.c
```

### ★★☆ Para pensar

**Exercício P1811** · ★★☆ · Quatro sequências de saltos no mesmo shell sort

O shell sort é o mesmo algoritmo com qualquer sequência de saltos que
termine em 1, mas o desempenho muda muito. Compare quatro:

- Shell (1959): n/2, n/4, ..., 1;
- Hibbard (1963): 2^k - 1 (1, 3, 7, 15, 31, ...);
- Knuth (1973): h = 3h + 1 (1, 4, 13, 40, 121, ...), começando no maior
h < n/3;
- Sedgewick (1986): 4^k + 3 · 2^(k-1) + 1, com 1 no começo (1, 8, 23, 77,
281, 1073, 4193, ...).

Escreva shell(v, n, saltos, ns), que recebe os saltos em ordem DECRESCENTE,
e conte as comparações. Ordene cópias dos mesmos tempos de entrega (gerados
no esqueleto) para n = 1000 e n = 10000, confira que ficaram ordenados e
mostre as comparações de cada sequência e do insertion sort puro.


```text
Saída esperada:
             n = 1000  n = 10000
Shell           14923     258585
Hibbard         14298     231869
Knuth           13674     233094
Sedgewick       15546     221889
insertion      256897   24710349
Todos ordenados: sim
```

**Dicas:**

1. Monte cada sequência num vetor (em ordem crescente, que é mais fácil de
   gerar) e passe para a função percorrendo de trás para frente.
2. Para Hibbard e Sedgewick, use só os saltos menores que n. Para Knuth,
   pare quando o próximo passaria de n/3.
3. O insertion sort é o shell sort com a sequência "1": aproveite a mesma
   função.
4. Resposta esperada: o insertion sort fica perto de n²/4 (24,7 milhões
   com n = 10000, contra uns 230 mil das sequências). Com n = 1000 as
   quatro empatam perto de 15 mil; com n = 10000, Shell é a pior (258585) e
   Sedgewick, a melhor (221889). A diferença cresce com n.

```bash
~/LPEDC/rodar 18-ordenacao-linear/lista/P1811.c
```

---

**Exercício P1812** · ★★☆ · Radix LSD mostrando o vetor C de cada passada

Na prova, o radix sort aparece como "qual é o vetor depois da segunda
passada?" e o counting sort como "qual é o vetor C?". Junte os dois: ordene
os 8 códigos de rastreio (3 dígitos) de uma agência dos Correios com radix
LSD em base 10 e, em CADA passada, mostre:

- o dígito usado de cada número;
- o vetor C depois das somas acumuladas (C[d] = quantos têm dígito <= d);
- o vetor depois da passada.


```text
Saída esperada:
Passada div = 1
dígitos: 5 1 2 7 3 0 5 1
C acumulado: 1 3 4 5 5 7 7 8 8 8
vetor: 540 331 801 902 283 465 615 747
Passada div = 10
dígitos: 4 3 0 0 8 6 1 4
C acumulado: 2 3 3 4 6 6 7 7 8 8
vetor: 801 902 615 331 540 747 465 283
Passada div = 100
dígitos: 8 9 6 3 5 7 4 2
C acumulado: 0 0 1 2 3 4 5 6 7 8
vetor: 283 331 465 540 615 747 801 902
```

**Dicas:**

1. Dígito da passada com divisor div: (x / div) % 10, com div = 1, 10, 100.
2. C acumulado diz onde termina cada bloco: os de dígito d ocupam as
   posições C[d - 1] até C[d] - 1.
3. Um dígito que não aparece repete o valor do anterior em C: o bloco dele
   tem tamanho zero.
4. Resposta esperada: depois das unidades, 540 801 331 902 283 465 615 747;
   depois das dezenas, 801 902 615 331 540 747 465 283; no fim, 283 331 465
   540 615 747 801 902.

```bash
~/LPEDC/rodar 18-ordenacao-linear/lista/P1812.c
```

---

**Exercício P1813** · ★★☆ · Três chaves, três passadas estáveis

A central de suporte quer os chamados ordenados por PRIORIDADE (0 a 3, 0
é a mais urgente), depois por SETOR (0 a 4) e, dentro disso, pelo MINUTO em
que chegaram (0 a 59). Em vez de um comparador com três critérios, use o
truque do radix: passadas estáveis, da chave MENOS significativa para a
MAIS significativa.

Escreva um counting sort genérico que recebe a função da chave:


```text
void counting(Chamado v[], int n, int (*chave)(const Chamado *), int k);
```


e faça três passadas: por minuto, por setor e por prioridade, mostrando a
ordem dos chamados depois de cada uma e, no fim, os campos de cada um.


```text
Saída esperada:
por minuto:     #4 #5 #1 #3 #7 #2 #6 #8
por setor:      #5 #8 #3 #6 #4 #2 #1 #7
por prioridade: #3 #6 #1 #8 #4 #2 #7 #5
  #3 prioridade 0, setor 1, minuto 15
  #6 prioridade 0, setor 1, minuto 40
  #1 prioridade 0, setor 3, minuto 12
  #8 prioridade 1, setor 0, minuto 59
  #4 prioridade 1, setor 2, minuto  5
  #2 prioridade 1, setor 2, minuto 33
  #7 prioridade 2, setor 4, minuto 20
  #5 prioridade 3, setor 0, minuto  8
```

**Dicas:**

1. A função da chave devolve um inteiro de 0 a k - 1; o counting sort usa
   chave(&v[i]) onde usaria v[i]. Escreva int por_minuto(const Chamado *c)
   e as outras duas.
2. Por que da menos para a mais significativa? A última passada decide a
   ordem principal; a estabilidade preserva, nos empates, a ordem deixada
   pelas passadas anteriores.
3. Cada passada custa Θ(n + k): o total é Θ(3n + 60 + 5 + 4), linear.
4. Resposta esperada: no fim, #3 #6 #1 #8 #4 #2 #7 #5. Repare em #4 e #2:
   mesma prioridade e setor, e o minuto 5 vem antes do 33 porque a
   primeira passada deixou os dois nessa ordem.

```bash
~/LPEDC/rodar 18-ordenacao-linear/lista/P1813.c
```

---

**Exercício P1814** · ★★☆ · Mediana: quickselect contra ordenar tudo

Para achar a mediana do tempo de espera de 1001 pacientes de uma UBS, não
é preciso ordenar: o quickselect acha o elemento de posição 500 (a partir
de 0) em tempo médio Θ(n). Confira contando comparações.

Escreva o quickselect (Lomuto, pivô no último) e um merge sort, os dois
contando comparações entre elementos, e mostre a mediana e as comparações
de cada um em dois vetores:

- os tempos sorteados do esqueleto;
- os mesmos tempos JÁ ORDENADOS (o pior caso do pivô no último).


```text
Saída esperada:
sorteado:
  quickselect: mediana 118,   5351 comparações
  merge sort:  mediana 118,   8693 comparações
ordenado:
  quickselect: mediana 118,  90220 comparações
  merge sort:  mediana 118,   5049 comparações
```

**Dicas:**

1. Quickselect iterativo: particione [ini, fim]; se o pivô parou na posição
   procurada, achou; senão continue só no lado que contém a posição.
2. Com o vetor ordenado, o pivô no último é sempre o maior do pedaço: cada
   partição tira poucos elementos (os iguais ao pivô), e o quickselect
   vira quadrático. O pivô sorteado (ou a mediana das medianas) evita isso.
3. O merge sort quase não liga para a ordem da entrada: ordenado ou não,
   fica em Θ(n lg n).
4. Resposta esperada: a mesma mediana (118) nos quatro casos; no vetor
   sorteado, o quickselect faz 5351 comparações contra 8693 do merge sort;
   no ordenado, o quickselect sobe para 90220, e o merge sort cai para 5049.

```bash
~/LPEDC/rodar 18-ordenacao-linear/lista/P1814.c
```

---

**Exercício P1815** · ★★☆ · Bucket sort fora de [0, 1): as temperaturas de Manaus

O bucket sort do Cormen supõe valores em [0, 1). As máximas diárias de
Manaus num mês vão de uns 23 °C a uns 38 °C. Para usar baldes, NORMALIZE:
com mín e máx do vetor, o valor x vai para o balde


```text
b = (int)((x - mín) / (máx - mín) * n)
```


e o máximo (que daria b = n) vai para o balde n - 1. Ordene as 12
temperaturas do esqueleto com n baldes (listas encadeadas em ordem, com
malloc), mostre os baldes não vazios e o vetor ordenado.


```text
Saída esperada:
balde  0: 22.9
balde  3: 27.3
balde  5: 29.5
balde  6: 30.7 31.2
balde  7: 32.4
balde  8: 33.8 34.1
balde  9: 35.0
balde 10: 36.4
balde 11: 37.6 38.1
ordenado: 22.9 27.3 29.5 30.7 31.2 32.4 33.8 34.1 35.0 36.4 37.6 38.1
```

**Dicas:**

1. Ache mín e máx numa passada (Θ(n)) antes de distribuir.
2. Sem o ajuste do máximo, ele cairia no balde n, fora do vetor: o
   AddressSanitizer acusa na hora.
3. Se todos os valores forem iguais, máx - mín = 0: trate esse caso (todo
   mundo no balde 0) antes de dividir.
4. Resposta esperada: 12 baldes, o 0 com 22.9 e o 11 com 37.6 e 38.1; o
   vetor ordenado vai de 22.9 a 38.1.

```bash
~/LPEDC/rodar 18-ordenacao-linear/lista/P1815.c
```

---

**Exercício P1816** · ★★☆ · Os rios do Amazonas ordenados pelo tamanho do nome

Um app de geografia quer mostrar os rios do esqueleto agrupados pelo
NÚMERO DE LETRAS do nome, do mais curto para o mais longo, e, dentro de
cada tamanho, na ordem em que estão na lista.

Ordene o vetor de strings (const char *) com counting sort estável pela
chave strlen(nome). Os nomes têm até 12 letras. Mostre os grupos com o
tamanho na frente e, depois, o vetor C como fica no fim da colocação:
com os decrementos, cada C[x] passa a apontar o INÍCIO do bloco x.


```text
Saída esperada:
3 letras: Ica
5 letras: Negro Purus Jurua
6 letras: Japura Javari Uatuma
7 letras: Madeira Tapajos
8 letras: Solimoes
9 letras: Trombetas
C (depois da colocação, início de cada bloco): 0 0 0 0 1 1 4 7 9 10 11 11 11
```

**Dicas:**

1. Ordene os PONTEIROS, não as letras: saida[--c[strlen(v[i])]] = v[i]
   copia só o endereço da string, 8 bytes, seja ela longa ou curta.
2. Calcule cada strlen uma vez e guarde num vetor tam[]: strlen percorre a
   string inteira toda vez que é chamada.
3. Estável: Negro e Purus têm 5 letras, e Negro vem antes porque está antes
   na lista.
4. Resposta esperada: 3 letras: Ica; 5: Negro Purus Jurua; 6: Japura
   Javari Uatuma; 7: Madeira Tapajos; 8: Solimoes; 9: Trombetas.

```bash
~/LPEDC/rodar 18-ordenacao-linear/lista/P1816.c
```

---

**Exercício P1817** · ★★☆ · Conserte o radix sort das encomendas

Conserte o programa. A transportadora ordena os pesos das encomendas (em
gramas) com radix sort LSD em base 10, mas o colega deixou DOIS erros de
propósito. Não há erro de memória; o resultado é que sai fora de ordem:


```text
Saída que aparece:
45 3005 120 1250 340 12400 870 9800
```


Depois do conserto:


```text
Saída esperada:
45 120 340 870 1250 3005 9800 12400
```

**Dicas:**

1. Quantas passadas o radix precisa? Tantas quantos dígitos tem o MAIOR
   número, não o primeiro do vetor.
2. Cada passada tem de ser ESTÁVEL. Com --c[d], a colocação precisa andar
   de trás para frente; da frente para trás, os empates de cada dígito
   saem invertidos e a ordem das passadas anteriores se perde.
3. Para ver o erro 2, faça à mão a passada das unidades: 870, 12400, 120,
   9800 e 340 terminam em 0. Da frente para trás com --c[0], o 870 vai para
   a última vaga do bloco, e eles saem na ordem inversa.
4. Resposta esperada: 45 120 340 870 1250 3005 9800 12400.

```bash
~/LPEDC/rodar 18-ordenacao-linear/lista/P1817.c
```

---

**Exercício P1818** · ★★☆ · Onde pôr o depósito: a mediana ponderada

Uma rede tem 7 lojas ao longo da Av. Torquato Tapajós, cada uma num km
(de 0 a 30) e com um número de entregas por dia (o peso). O depósito vai
num km p, e o custo diário é a soma de peso · |km - p|. O melhor p é a
MEDIANA PONDERADA (problema 9-2 do Cormen): ordene as lojas pelo km e ande
somando os pesos; o primeiro km em que a soma chega à metade do peso total
é a resposta.

Ordene as lojas pelo km com counting sort (os km são inteiros pequenos),
ache a mediana ponderada e mostre o custo em quatro candidatos: a mediana
ponderada, a mediana simples dos km (sem pesos), a média ponderada
arredondada e o melhor km por força bruta (testando de 0 a 30).


```text
Saída esperada:
km  2 Cidade Nova          peso  5, acumulado  5 de 23
km  5 Novo Israel          peso  1, acumulado  6 de 23
km  7 Lago Azul            peso  2, acumulado  8 de 23
km 12 Monte das Oliveiras  peso  1, acumulado  9 de 23
km 18 Santa Etelvina       peso  1, acumulado 10 de 23
km 21 Colonia              peso  2, acumulado 12 de 23
Mediana ponderada: km 21, custo 206
Força bruta:       km 21, custo 206
Mediana simples:   km 12, custo 245
Média ponderada:   km 17, custo 220
```

**Dicas:**

1. Para comparar com a metade sem usar double, compare 2 · acumulado com o
   peso total.
2. Por que funciona? Andando um km para a direita a partir de p, o custo
   aumenta (peso à esquerda) e diminui (peso à direita). Enquanto houver
   mais peso à direita, vale a pena andar.
3. A média ponderada minimiza a soma dos QUADRADOS das distâncias, não a
   soma das distâncias: aqui ela perde.
4. Resposta esperada: mediana ponderada no km 21, com custo 206; a força
   bruta concorda; a mediana simples (km 12) custa 245 e a média (km 17),
   220.

```bash
~/LPEDC/rodar 18-ordenacao-linear/lista/P1818.c
```

---

**Exercício P1819** · ★★☆ · Qual base para o radix? Conte as operações

O radix sort LSD de inteiros sem sinal de 32 bits pode olhar r bits por
passada (base b = 2^r): são ⌈32 / r⌉ passadas de Θ(n + b) cada. Base
pequena faz muitas passadas; base grande faz poucas, mas cada uma paga o
vetor C de b posições.

Escreva radix(v, n, r), que funciona para r = 1, 4, 8 e 16, e conte as
operações: cada passada soma n (contagem) + b (somas acumuladas) + n
(colocação) + n (cópia de volta). Ordene cópias dos mesmos 100000 códigos
de produto (sorteados no esqueleto) com cada r, confira o resultado e
mostre passadas, operações e operações por elemento. Depois, repita com só
n = 1000 elementos.


```text
Saída esperada:
n = 100000
  r =  1: 32 passadas, 9600064 operações ( 96.0 por item), ordenado
  r =  4:  8 passadas, 2400128 operações ( 24.0 por item), ordenado
  r =  8:  4 passadas, 1201024 operações ( 12.0 por item), ordenado
  r = 16:  2 passadas,  731072 operações (  7.3 por item), ordenado
n = 1000
  r =  1: 32 passadas,   96064 operações ( 96.1 por item), ordenado
  r =  4:  8 passadas,   24128 operações ( 24.1 por item), ordenado
  r =  8:  4 passadas,   13024 operações ( 13.0 por item), ordenado
  r = 16:  2 passadas,  137072 operações (137.1 por item), ordenado
```

**Dicas:**

1. Dígito da passada p: (x >> (p · r)) & (b - 1). Use unsigned para que o
   deslocamento não mexa no sinal.
2. O vetor C de r = 16 tem 65536 posições: deixe-o static, e zere só as b
   posições usadas em cada passada.
3. Fórmula: ⌈32/r⌉ · (3n + b). Com n grande, r = 16 ganha (2 passadas);
   com n pequeno, o b = 65536 pesa mais que o n, e r = 8 ganha.
4. Resposta esperada: com n = 100000, r = 16 ganha (731072 operações,
   contra 1201024 de r = 8); com n = 1000, r = 8 ganha (13024, contra
   137072 de r = 16).

```bash
~/LPEDC/rodar 18-ordenacao-linear/lista/P1819.c
```

---

**Exercício P1820** · ★★☆ · Counting sort custa n + k: quando o k atrapalha

O counting sort é Θ(n + k): linear em n, mas paga o tamanho k do intervalo
das chaves. Com k pequeno é imbatível; com k enorme, perde até para uma
ordenação por comparação.

Ordene n = 1000 valores sorteados com chaves em [0, k), para k = 10, 1000,
100000 e 1000000, com counting sort e com merge sort. Conte as operações
do counting sort (n na contagem + k nas somas + n na colocação) e as
comparações do merge sort. Mostre as contagens e quem ganhou, e confira que
os dois resultados são iguais.


```text
Saída esperada:
      k  counting   merge  vencedor  iguais
     10      2010    8507  counting  sim
   1000      3000    8719  counting  sim
 100000    102000    8706  merge     sim
1000000   1002000    8712  merge     sim
```

**Dicas:**

1. O vetor C com 1 milhão de int ocupa 4 MB: deixe-o static.
2. O merge sort faz pouco menos que n lg n ≈ 10 mil comparações para
   n = 1000 (perto de 8700), qualquer que seja k.
3. O ponto de virada fica onde 2n + k ≈ comparações do merge: com n = 1000,
   k na casa de 7 mil. Para chaves grandes (CPF, telefone), use radix sort,
   que quebra a chave em dígitos pequenos.
4. Resposta esperada: counting ganha com k = 10 e k = 1000 (2010 e 3000
   operações); merge ganha com k = 100000 e 1000000.

```bash
~/LPEDC/rodar 18-ordenacao-linear/lista/P1820.c
```

### ★★★ Desafio

**Exercício P1821** · ★★★ · O painel de partidas do aeroporto

O painel de partidas do aeroporto de Manaus mostra os voos dos próximos
dias por DIA, HORA e MINUTO e, no mesmo horário, pelo NÚMERO do voo. Os
registros chegam fora de ordem (vetor do esqueleto).

Monte a ordem com passadas estáveis de counting sort, da chave menos
significativa para a mais: número do voo (de 0 a 9999), minuto, hora e
dia. Use um único counting sort genérico, que recebe a chave por ponteiro
de função e o tamanho do intervalo. Mostre a ordem dos números de voo
depois de cada passada, o painel final e a conferência com o qsort usando
um comparador de quatro critérios.


```text
Saída esperada:
por número: 1190 1501 1502 1777 2011 2210 2788 3320 3999 4410
por minuto: 1777 3999 2788 3320 1502 2210 1190 1501 4410 2011
por hora:   1502 2210 1777 3999 2788 3320 2011 1190 1501 4410
por dia:    1502 1190 1501 2210 2788 3320 2011 1777 3999 4410
Data  Hora    Voo  Destino
09/11 06:15  1502  Brasilia
09/11 21:30  1190  Boa Vista
09/11 21:30  1501  Brasilia
10/11 06:15  2210  Porto Velho
10/11 14:05  2788  Sao Paulo
10/11 14:05  3320  Belem
10/11 14:50  2011  Santarem
11/11 08:00  1777  Rio
11/11 08:00  3999  Recife
11/11 23:40  4410  Fortaleza
qsort concorda: sim
```

**Dicas:**

1. Os números de voo vão até 9999: o vetor C dessa passada tem 10000
   posições (static). As outras têm 60, 24 e 31.
2. O comparador do qsort compara dia; se empatar, hora; depois minuto;
   depois número. Os dois métodos têm de dar a mesma sequência.
3. As passadas custam Θ(4n + 10000 + 60 + 24 + 31): com poucos voos, o
   10000 domina. Com milhões de voos, é linear e ganha do qsort.
4. Resposta esperada: o painel começa com o voo 1502 do dia 9 às 06:15 e
   termina com o 4410 do dia 11 às 23:40; o qsort concorda.

```bash
~/LPEDC/rodar 18-ordenacao-linear/lista/P1821.c
```

---

**Exercício P1822** · ★★★ · Radix MSD: os municípios em ordem alfabética

O radix LSD precisa de chaves do mesmo tamanho. O radix MSD (do dígito
MAIS significativo) não: ele separa as strings pela primeira letra com um
counting sort e, dentro de cada grupo, resolve RECURSIVAMENTE pela segunda
letra, e assim por diante. Uma string que já acabou (o '\0' na posição d)
vai para o grupo 0 e fica antes de todas as que continuam: é por isso que
"mana" viria antes de "manaus".

Escreva msd(v, ini, fim, d), que ordena os ponteiros v[ini..fim] olhando a
posição d (grupos de 0 a 256, com o caractere + 1 e 0 para o fim da string),
com um vetor auxiliar de ponteiros (pode acrescentar um parâmetro que diga
se a chamada mostra os grupos, para só a primeira mostrar). Ordene os 15 municípios do esqueleto,
conte as chamadas, mostre os grupos do primeiro nível (a letra e quantos
nomes) e o vetor final (5 por linha), e confira com strcmp que ficou em
ordem.


```text
Saída esperada:
Primeiro nível: b(2) c(3) h(1) i(2) m(4) p(1) t(2)
barcelos borba careiro coari codajas
humaita iranduba itacoatiara manacapuru manaus
manicore maues parintins tabatinga tefe
Chamadas: 10 | em ordem pelo strcmp: sim
```

**Dicas:**

1. Grupo da string s na posição d: (unsigned char)s[d] + 1 se s[d] != '\0',
   senão 0. São 257 grupos; C tem 258 posições para guardar os inícios.
2. Depois do counting sort da posição d, chame msd para cada grupo de 1 até
   256 com mais de um elemento, com d + 1. O grupo 0 já está pronto: são
   strings iguais.
3. Só chame strlen se precisar: s[d] já diz se a string acabou, desde que
   d nunca passe do fim (e não passa, porque o grupo 0 não desce).
4. Resposta esperada: o primeiro nível tem b(2) c(3) h(1) i(2) m(4) p(1)
   t(2); a ordem final vai de barcelos a tefe; strcmp confirma.

```bash
~/LPEDC/rodar 18-ordenacao-linear/lista/P1822.c
```

---

**Exercício P1823** · ★★★ · O ponto de encontro da turma: duas medianas

Nove amigos moram em esquinas de um bairro em grade, e cada um anda pelas
ruas (distância de Manhattan: |x1 - x2| + |y1 - y2| quarteirões). Em que
esquina marcar o churrasco para que a SOMA das distâncias seja a menor
possível?

Como a distância separa x e y, o problema se divide em dois de uma dimensão,
e em uma dimensão a soma de |x - p| é mínima na MEDIANA. Logo, o melhor
ponto é (mediana dos x, mediana dos y), e cada mediana sai de um
quickselect em Θ(n) médio, sem ordenar nada.

Escreva o quickselect (Lomuto, pivô no último; trabalhe em cópias, porque
ele bagunça o vetor) e mostre: o ponto das medianas e a soma das distâncias
nele; o "centro de massa" (médias arredondadas) e a soma nele; e o melhor
ponto por força bruta, testando todas as esquinas de 0 a 20 nos dois
eixos, para conferir.


```text
Saída esperada:
Medianas: (6, 5), soma 67
Centro de massa: (8, 7), soma 75
Força bruta: (6, 5), soma 67
```

**Dicas:**

1. Com n = 9 (ímpar), a mediana é o elemento de posição 4 (a partir de 0).
   Com n par, qualquer ponto entre os dois do meio serve.
2. As médias minimizam a soma dos QUADRADOS das distâncias. Quem mora longe
   puxa a média, mas não a mediana.
3. A força bruta testa 21 × 21 esquinas, cada uma com 9 distâncias: tudo
   bem para conferir, mas é Θ(L² n) contra Θ(n) das medianas.
4. Resposta esperada: medianas em (6, 5) com soma 67; o centro de massa
   (8, 7) dá 75; a força bruta confirma (6, 5) e 67.

```bash
~/LPEDC/rodar 18-ordenacao-linear/lista/P1823.c
```

---

**Exercício P1824** · ★★★ · Por dentro da análise do bucket sort

A análise do bucket sort no Cormen diz: com n valores uniformes em [0, 1)
e n baldes, o número n_i de itens no balde i segue uma distribuição
binomial, E[n_i²] = 2 - 1/n, e o tempo esperado é Θ(n). Confira no
computador.

Gere n = 10000 valores com o gerador do esqueleto, faça o bucket sort
completo (listas encadeadas com malloc, inserção em ordem contando as
comparações, concatenação, free de tudo) e mostre:

- o histograma da ocupação: quantos baldes ficaram com 0, 1, 2, ...
itens, ao lado do esperado pela aproximação de Poisson, n · e^(-1) / j!;
- a soma dos n_i², comparada com n · (2 - 1/n);
- as comparações da inserção, comparadas com a soma dos n_i (n_i - 1)/2
(o pior caso dentro de cada balde) e com n;
- se o vetor final ficou ordenado.


```text
Saída esperada:
itens  baldes  esperado
    0    3663      3679
    1    3736      3679
    2    1776      1839
    3     634       613
    4     149       153
    5      38        31
    6       4         5
Soma dos n_i²: 20024 (esperado n(2 - 1/n) = 19999)
Comparações: 4559 (pior caso nos baldes: 5012; n = 10000)
Ordenado: sim
```

**Dicas:**

1. valor = sorteia() / 4294967296.0 dá um double em [0, 1) a partir de um
   unsigned de 32 bits.
2. Guarde n_i num vetor ao inserir; o histograma é um counting sort dos
   n_i.
3. Poisson com média 1: P(j) = e^(-1) / j!. Calcule j! num laço e use
   exp(-1.0).
4. Resposta esperada: 3663 baldes vazios (Poisson: 3679), 3736 com 1 item,
   1776 com 2 e 634 com 3; soma dos n_i² 20024 (esperado 19999); 4559
   comparações, menos de uma por item; ordenado.

```bash
~/LPEDC/rodar 18-ordenacao-linear/lista/P1824.c
```

---

**Exercício P1825** · ★★★ · Counting sort sem vetor de saída: as camisas no lugar

O counting sort do Cormen precisa de um vetor de saída B do tamanho da
entrada. Quando a memória aperta, dá para ordenar NO LUGAR com poucas
chaves: conte, calcule onde começa e onde termina cada bloco, e vá
trocando cada item para dentro do seu bloco ("ciclos").

A loja tem 12 camisas de tamanhos P, M, G, GG e XG (chaves 0 a 4). Escreva:


```text
void ordena_no_lugar(Camisa v[], int n);
```


1. conte as chaves e calcule prox[k] (a próxima vaga do bloco k, começando
no início do bloco) e fim[k] (onde o bloco k termina);
2. para cada bloco k, enquanto prox[k] < fim[k]: olhe a camisa em
v[prox[k]]; se ela é do bloco k, avance prox[k]; senão, troque-a com
v[prox[chave]] e avance prox[chave].

Mostre o vetor antes e depois, o número de trocas (cada troca põe pelo
menos uma camisa no lugar definitivo: no máximo n) e se o resultado ficou
ESTÁVEL (compare a ordem dos códigos dentro de cada tamanho).


```text
Saída esperada:
antes:  G(1) XG(2) P(3) G(4) M(5) GG(6) M(7) P(8) XG(9) G(10) GG(11) M(12)
depois: P(3) P(8) M(7) M(12) M(5) G(1) G(10) G(4) GG(6) GG(11) XG(9) XG(2)
Trocas: 9 (n = 12) | estável: não
```

**Dicas:**

1. Comece prox[0] = 0 e prox[k] = prox[k - 1] + c[k - 1]; fim[k] =
   prox[k] + c[k] (calcule antes de mexer em prox).
2. A troca manda uma camisa direto para o seu bloco, na vaga prox[chave],
   que avança. A camisa que veio de lá é examinada na próxima volta, sem
   avançar prox[k].
3. É Θ(n + k) de tempo e Θ(k) de memória extra, mas NÃO é estável: as
   trocas embaralham os empates. Para um passo de radix sort, isso não
   serve.
4. Resposta esperada: P P M M M G G G GG GG XG XG, com 9 trocas, e não
   estável (o M 107 fica antes do M 105, por exemplo).

```bash
~/LPEDC/rodar 18-ordenacao-linear/lista/P1825.c
```

---

**Exercício P1826** · ★★★ · Os números mais sorteados: frequência, depois valor

Uma lotérica anotou as 40 dezenas (de 1 a 60) que saíram nos últimos
sorteios. Ela quer a lista reordenada pela FREQUÊNCIA, da dezena que mais
saiu para a que menos saiu, com as repetições juntas, e, no empate de
frequência, a dezena MENOR primeiro. Exemplo: se 7 saiu 3 vezes e 2 saiu
3 vezes, a lista começa 2 2 2 7 7 7.

Tudo em tempo linear, sem comparar elementos:

1. conte a frequência de cada dezena (counting, k = 61);
2. monte a lista das dezenas que apareceram em ordem crescente (é só
percorrer o vetor de contagem);
3. ordene essa lista com um counting sort ESTÁVEL pela chave
(maior_freq - freq), que põe as mais frequentes primeiro e preserva a
ordem crescente nos empates;
4. escreva cada dezena freq vezes.

Mostre as dezenas distintas com a frequência, na ordem final, e a lista
completa (10 por linha).


```text
Saída esperada:
Dezenas (frequência):
  6(3) 24(3) 36(3) 1(2) 25(2) 29(2) 50(2) 2(1) 3(1) 4(1)
  5(1) 8(1) 9(1) 17(1) 18(1) 23(1) 26(1) 28(1) 37(1) 38(1)
  44(1) 45(1) 47(1) 48(1) 49(1) 51(1) 52(1) 55(1) 56(1) 60(1)
Lista:
   6  6  6 24 24 24 36 36 36  1
   1 25 25 29 29 50 50  2  3  4
   5  8  9 17 18 23 26 28 37 38
  44 45 47 48 49 51 52 55 56 60
Total: 40 números
```

**Dicas:**

1. Os dados do esqueleto vêm de um gerador fixo: a saída é sempre a mesma.
2. A chave do passo 3 vai de 0 (as mais frequentes) a maior_freq - 1: o
   vetor C tem maior_freq posições.
3. Por que o passo 2 dispensa ordenação? O vetor de contagem já está
   indexado pela dezena: percorrê-lo de 1 a 60 dá as dezenas em ordem.
4. Resposta esperada: 6, 24 e 36 saíram 3 vezes e abrem a lista (6 6 6 24
   24 24 36 36 36); depois vêm 1, 25, 29 e 50, com 2; a lista tem 40
   números.

```bash
~/LPEDC/rodar 18-ordenacao-linear/lista/P1826.c
```

---

**Exercício P1827** · ★★★ · n números de 0 a n² - 1 em tempo linear

Exercício clássico do Cormen (8.3-4): ordenar n inteiros no intervalo
[0, n² - 1] em tempo O(n). O counting sort direto pagaria k = n². O radix
sort em base 10 faria lg₁₀(n²) passadas. Use BASE n: todo número
x < n² tem só dois "dígitos" nessa base, x % n e x / n, e cada passada
custa Θ(n + n) = Θ(n).

Uma cooperativa tem n = 1000 produtores, e cada código de lote vai de 0 a
999999 (= n² - 1). Ordene os códigos do esqueleto de três jeitos, contando
as operações (por passada: n na contagem + b nas somas + n na colocação +
n na cópia):

- counting sort direto, com k = n²;
- radix em base 10 (6 passadas);
- radix em base n (2 passadas).

Confira que os três dão o mesmo vetor e mostre as operações de cada um.


```text
Saída esperada:
counting direto (k = n²):  1003000 operações
radix base 10 (6 passadas):  18060 operações
radix base n (2 passadas):    8000 operações
Iguais: sim | menor 581, maior 999150
```

**Dicas:**

1. Escreva uma passada genérica que recebe o divisor e a base:
   dígito = (x / div) % base. Na base n, div vale 1 e depois n.
2. O counting direto é uma "passada" com base n² e div = 1: Θ(n + n²).
3. Fórmulas: direto 3n + n² = 1003000; base 10: 6 · (3n + 10) = 18060;
   base n: 2 · (3n + n) = 8000.
4. Resposta esperada: os três vetores iguais; 1003000, 18060 e 8000
   operações.

```bash
~/LPEDC/rodar 18-ordenacao-linear/lista/P1827.c
```

---

**Exercício P1828** · ★★★ · A entrada que derruba os saltos de Shell

Com os saltos de Shell (n/2, n/4, ..., 2, 1) e n potência de 2, TODOS os
saltos menores que n são pares, menos o último. Então, até a passada com
h = 1, as posições pares só são comparadas com posições pares, e as ímpares
com ímpares. Monte uma entrada que aproveita isso:

- as posições PARES recebem os n/2 maiores valores, em ordem crescente;
- as posições ÍMPARES recebem os n/2 menores, em ordem crescente.

Cada fileira de salto par já está ordenada: as passadas com h >= 2 não
movem nada. A última passada (insertion sort puro) tem de levar cada
pequeno da metade da frente até o seu lugar: Θ(n²).

Gere essa entrada para n = 1024 e n = 4096 (valores 0 a n - 1) e conte as
comparações do shell sort com os saltos de Shell, com os de Hibbard
(2^k - 1, todos ímpares) e com os de Knuth (3h + 1), mais o insertion sort
puro. Repita com um vetor sorteado do mesmo tamanho para comparar.


```text
Saída esperada:
n = 1024 (n²/8 = 131072)
                   ruim   sorteado
  Shell          140544      23965
  Hibbard          9998      15278
  Knuth            8792      14013
  insertion      132350     254622
n = 4096 (n²/8 = 2097152)
                   ruim   sorteado
  Shell         2143232     207201
  Hibbard         50192      79705
  Knuth           44720      78028
  insertion     2102270    4116375
```

**Dicas:**

1. Entrada ruim: para i de 0 a n/2 - 1, v[2i] = n/2 + i e v[2i + 1] = i.
2. Reaproveite uma função shell(v, n, saltos, ns) que conta comparações;
   cada sequência é só um vetor de saltos diferente.
3. Na última passada, o menor da metade da frente precisa andar até a
   posição certa: o i-ésimo pequeno anda cerca de n/2 - i casas. A soma é
   perto de n²/8.
4. Resposta esperada: com n = 4096 na entrada ruim, os saltos de Shell
   fazem 2143232 comparações (mais que o insertion puro, e perto de
   n²/8 = 2097152), enquanto Hibbard e Knuth ficam perto de 50 mil.

```bash
~/LPEDC/rodar 18-ordenacao-linear/lista/P1828.c
```

---

**Exercício P1829** · ★★★ · A classificação do campeonato com quatro critérios

No campeonato amador do Amazonas, a classificação segue os critérios, em
ordem: mais PONTOS, depois mais VITÓRIAS, depois maior SALDO de gols e, por
fim, ordem ALFABÉTICA. Os times chegam do sistema já em ordem alfabética.

Monte a tabela só com passadas estáveis de counting sort, da chave menos
significativa para a mais (o alfabeto já vem resolvido pela entrada):
saldo, vitórias e pontos, todas DECRESCENTES. O saldo vai de -30 a +30:
desloque a chave para ficar em 0..60. Mostre a ordem depois de cada
passada e a tabela final, e confira com o qsort e um comparador dos quatro
critérios.


```text
Saída esperada:
por saldo:     Tucu Tamb Boto Jara Arar Pira Peix Vito Onca Suma
por vitórias:  Tucu Boto Jara Tamb Peix Arar Pira Vito Onca Suma
por pontos:    Tucu Boto Jara Tamb Peix Arar Pira Vito Onca Suma
 #  Time           Pts  V  Saldo
 1  Tucunare        22  7    +11
 2  Boto Rosa       19  6     +8
 3  Jaraqui         19  6     +5
 4  Tambaqui        19  5     +9
 5  Peixe-Boi       15  5     -1
 6  Arara Azul      15  4     +3
 7  Pirarucu        15  4     +3
 8  Vitoria-Regia   10  3     -2
 9  Onca Pintada    10  2     -6
10  Sumauma          7  1    -12
qsort concorda: sim
```

**Dicas:**

1. Decrescente e estável: use a chave invertida (MAX - valor). Para o
   saldo, chave = 30 - saldo, que vai de 0 (saldo +30) a 60 (saldo -30).
2. A ordem das passadas é saldo, vitórias, pontos: a última decide o
   critério principal, e cada passada estável preserva os desempates das
   anteriores.
3. O qsort não é estável, mas aqui isso não importa: com o nome no
   comparador, não há dois times "iguais".
4. Resposta esperada: Tucunare (22 pts) em 1º; Boto e Jaraqui empatam em
   19 pontos e 6 vitórias, e o saldo (+8 contra +5) põe o Boto na frente;
   Arara e Pirarucu empatam em tudo menos no nome; o qsort concorda.

```bash
~/LPEDC/rodar 18-ordenacao-linear/lista/P1829.c
```

---

**Exercício P1830** · ★★★ · O log do servidor: IPs ordenados por radix base 256

O servidor do portal da prefeitura registrou os IPs de 16 acessos, como
strings "a.b.c.d". Para achar quem mais acessou, ordene os IPs e conte as
repetições, que ficam juntas.

Um IPv4 são 4 bytes: guarde cada um num unsigned de 32 bits
((a << 24) | (b << 16) | (c << 8) | d) e ordene com radix LSD em base 256,
4 passadas, uma por byte, do menos significativo (d) para o mais (a).
Escreva:


```text
unsigned ip_de(const char *s);          // com sscanf("%u.%u.%u.%u")
void ip_para(unsigned ip, char s[16]);  // de volta para "a.b.c.d"
void radix256(unsigned v[], int n);
```


Mostre os IPs distintos em ordem com o número de acessos e o IP que mais
acessou. Compare com a ordem das STRINGS: "10.0.0.9" vem depois de
"10.0.0.10" no strcmp, mas antes na ordem numérica.


```text
Saída esperada:
8.8.8.8         1 acesso
10.0.0.9        2 acessos
10.0.0.10       3 acessos
172.16.0.1      2 acessos
192.168.1.3     1 acesso
192.168.1.20    4 acessos
200.17.5.3      2 acessos
200.17.5.30     1 acesso
Distintos: 8 | quem mais acessou: 192.168.1.20 (4)
strcmp("10.0.0.9", "10.0.0.10") > 0: sim
```

**Dicas:**

1. Byte da passada p: (ip >> (8 * p)) & 255. São 4 passadas com C de 256
   posições: Θ(4(n + 256)).
2. Confira o retorno do sscanf: tem de ser 4. Cada parte tem de ser <= 255.
3. Depois de ordenar, um laço conta as repetições: enquanto v[j] == v[i],
   j++. O total de acessos de v[i] é j - i.
4. Resposta esperada: 8 IPs distintos; 10.0.0.9 antes de 10.0.0.10 e
   192.168.1.20 com 4 acessos é quem mais acessou.

```bash
~/LPEDC/rodar 18-ordenacao-linear/lista/P1830.c
```

## Questões no estilo da prova

Questões objetivas no formato da prova do PPGI: conceito, afirmações
combinadas, simulação à mão, cálculo e código com erro. Resolva no papel,
marque a letra e só depois abra o gabarito. Sempre que a questão traz código
ou um vetor, dá para conferir rodando.

**1.** O counting sort do assunto 0120 ordena `3 0 2 3 1 0 3 2` (chaves de 0
a 3) com contagem, acumulação e distribuição **de trás para a frente**
(`saida[--c[x]] = v[i]`, de `i = n - 1` até 0). Em que posição do vetor de
saída (contando de 0) cai o elemento `v[0]`, o primeiro 3?

- (A) 3
- (B) 4
- (C) 5
- (D) 6
- (E) 7

<details><summary>Gabarito</summary>

**C.** A contagem dá `2 1 2 3`, e a acumulação, `c = 2 3 5 8`. Os três 3 ocupam
as posições 5, 6 e 7. Andando de trás para a frente, o último 3 (`v[6]`) pega a
7, o do meio (`v[3]`) pega a 6 e o primeiro (`v[0]`) pega a 5. É a ordem
original dos iguais, o que torna o método estável. Com o laço de frente para
trás, o `v[0]` iria para a 7 (a alternativa E). Veja 0120.

</details>

**2.** O radix sort LSD do assunto 0121, com counting sort estável em cada
passada e base 10, ordena `457 126 305 891 243 672 118 123`. Como fica o
vetor depois da **segunda** passada (a das dezenas)?

- (A) `305 118 123 126 243 457 672 891`
- (B) `891 672 243 123 305 126 457 118`
- (C) `305 118 126 123 243 457 672 891`
- (D) `118 123 126 243 305 457 672 891`
- (E) `305 118 123 126 243 672 457 891`

<details><summary>Gabarito</summary>

**A.** A passada das unidades dá `891 672 243 123 305 126 457 118` (a
alternativa B). Na das dezenas, 123 e 126 têm dezena 2 e mantêm a ordem da
passada anterior (123 antes de 126); a C inverte esse empate, o que só um
método instável faria. A D é o vetor depois da terceira passada. Veja 0121.

</details>

**3.** O shell sort do assunto 0119, com a sequência de intervalos 4, 2, 1,
ordena `23 8 41 5 16 30 2 19`. Como fica o vetor depois da passada com
`h = 2`?

- (A) `16 8 2 5 23 30 41 19`
- (B) `2 5 8 16 19 23 30 41`
- (C) `2 8 16 5 23 19 41 30`
- (D) `2 5 16 8 23 19 41 30`
- (E) `5 8 16 23 2 19 30 41`

<details><summary>Gabarito</summary>

**D.** Depois de `h = 4`: `16 8 2 5 23 30 41 19` (a alternativa A). A passada
com `h = 2` faz insertion sort nas posições pares (`16 2 23 41` vira
`2 16 23 41`) e nas ímpares (`8 5 30 19` vira `5 8 19 30`), intercaladas:
`2 5 16 8 23 19 41 30`. Falta a passada `h = 1`, que termina o serviço (a B).
Veja 0119.

</details>

**4.** Considere as afirmações sobre ordenação linear.

I. O counting sort não compara chaves entre si.
II. O counting sort é estável, qualquer que seja a ordem do laço que
distribui os elementos.
III. O radix sort LSD só funciona se a ordenação usada em cada passada for
estável.
IV. O counting sort é pouco indicado quando o intervalo de chaves `k` é muito
maior que `n`.

Marque a alternativa CORRETA.

- (A) Apenas I e III.
- (B) Apenas I, III e IV.
- (C) Apenas II e IV.
- (D) Apenas I, II e III.
- (E) I, II, III e IV.

<details><summary>Gabarito</summary>

**B.** I é verdadeira: ele usa a chave como índice. II é falsa: só a
distribuição de trás para a frente preserva a ordem dos iguais; "qualquer que
seja" é a pegadinha. III é verdadeira: sem estabilidade, a passada de um dígito
desfaz o trabalho da anterior. IV é verdadeira: o custo e o espaço são
Θ(n + k). Veja 0120 e 0121.

</details>

**5.** Considere as afirmações.

I. O quickselect tem custo esperado Θ(n) para achar o k-ésimo menor elemento
de um vetor de `n` posições.
II. O shell sort não é estável.
III. Todo algoritmo que ordena **só por comparações** faz Ω(n log n)
comparações no pior caso.

Marque a alternativa CORRETA.

- (A) Apenas I.
- (B) Apenas II e III.
- (C) Apenas I e III.
- (D) Apenas I e II.
- (E) I, II e III.

<details><summary>Gabarito</summary>

**E.** I é verdadeira: depois de particionar, o quickselect segue por um lado
só, e a soma `n + n/2 + n/4 + ...` dá menos que 2n. II é verdadeira: os saltos
de `h` posições passam por cima de iguais (com `20 21 10`, chaves iguais com
rótulos, o shell sort troca os dois iguais de lugar). III é verdadeira: a
árvore de decisão com `n!` folhas tem altura de pelo menos log₂ n!. O "todo"
aqui está certo porque a afirmação restringe o conjunto aos métodos por
comparação. Veja 0119, 0123 e 0117.

</details>

**6.** Chaves inteiras de 48 bits serão ordenadas por radix sort LSD, tomando
12 bits por "dígito" e um counting sort estável em cada passada. Quantas
passadas são feitas e quantos contadores o counting sort usa em cada uma?

- (A) 12 passadas; 4 contadores
- (B) 4 passadas; 48 contadores
- (C) 48 passadas; 2 contadores
- (D) 4 passadas; 4096 contadores
- (E) 2 passadas; 2²⁴ contadores

<details><summary>Gabarito</summary>

**D.** São `b/r = 48/12 = 4` passadas, e cada dígito de 12 bits vai de 0 a
2¹² - 1 = 4095, ou seja, 4096 contadores. O custo é Θ(4 · (n + 4096)), linear
em `n`. Veja 0121.

</details>

**7.** O counting sort abaixo tem chaves de 0 a `K = 4`, mas o laço de
acumulação foi escrito com `x < K`.

```c
#include <stdio.h>

int main(void) {
    enum { K = 4, N = 8 };
    int v[N] = {3, 1, 4, 1, 2, 4, 0, 3};
    int c[K + 1] = {0}, saida[N] = {0};

    for (int i = 0; i < N; i++) c[v[i]]++;
    for (int x = 1; x < K; x++) c[x] += c[x - 1];
    for (int i = N - 1; i >= 0; i--) saida[--c[v[i]]] = v[i];

    for (int i = 0; i < N; i++) printf("%d ", saida[i]);
    printf("\n");
    return 0;
}
```

O que o programa imprime?

- (A) `4 1 1 2 3 3 0 0`
- (B) `0 1 1 2 3 3 4 4`
- (C) `1 1 2 3 3 4 4 0`
- (D) `0 1 1 2 3 3 4 0`
- (E) Nada: o programa não compila.

<details><summary>Gabarito</summary>

**A.** O laço pula `c[4]`, que fica com a contagem simples (2) em vez da
acumulada (8). Os dois 4 vão para as posições 1 e 0, a posição 0 que deveria
ser do 0, e o 0 acaba sobrescrito pelo 4. As posições 6 e 7 nunca são
escritas e ficam com o 0 inicial. Compila sem aviso, e o resultado é o
impresso. O limite correto é `x <= K`. Veja 0120.

</details>

**8.** Considere as afirmações.

I. Ordenar 10 inteiros entre 0 e 10⁹ por counting sort direto é uma boa
escolha, porque o custo é linear.
II. O bucket sort que ordena cada balde com insertion sort pode custar Θ(n²)
no pior caso.
III. Para chaves inteiras entre `a` e `b`, o counting sort pode indexar os
contadores por `x - a`, e bastam `b - a + 1` contadores.

Marque a alternativa CORRETA.

- (A) Apenas I e II.
- (B) Apenas II e III.
- (C) Apenas I e III.
- (D) Apenas III.
- (E) I, II e III.

<details><summary>Gabarito</summary>

**B.** I é falsa: o custo é Θ(n + k), e aqui `k` é 10⁹ + 1, ou seja, um bilhão
de contadores para ordenar 10 números. II é verdadeira: se todos os valores
caem no mesmo balde, sobra um insertion sort de `n` elementos. III é
verdadeira, e é a forma de poupar memória quando as chaves ficam longe de 0.
Veja 0120 e 0122.

</details>

**9.** O quickselect (partição de Lomuto, pivô no último elemento do trecho)
procura o **3º menor** elemento de `12 7 19 3 15 8 21`. Qual é o resultado e
quantas partições são feitas?

- (A) 7, com 1 partição
- (B) 8, com 3 partições
- (C) 8, com 2 partições
- (D) 12, com 2 partições
- (E) 19, com 3 partições

<details><summary>Gabarito</summary>

**C.** O 3º menor está no índice 2 do vetor ordenado. 1ª partição, pivô 21: ele
fica no índice 6, e o 3º menor está à esquerda. 2ª partição, no trecho `12 7
19 3 15 8` com pivô 8: o vetor fica `7 3 8 12 15 19 21` e o 8 cai no índice 2.
Achou, com 2 partições e sem precisar ordenar nada. Veja
0123.

</details>

**10.** Qual é o menor número de comparações que **qualquer** algoritmo de
ordenação por comparações precisa fazer, no pior caso, para ordenar 5
elementos distintos?

- (A) 4
- (B) 5
- (C) 6
- (D) 8
- (E) 7

<details><summary>Gabarito</summary>

**E.** A árvore de decisão tem 5! = 120 folhas, e uma árvore binária de altura
`h` tem no máximo 2ʰ folhas. Logo 2ʰ ≥ 120, e `h ≥ ⌈log₂ 120⌉ = 7` (2⁶ = 64
é pouco; 2⁷ = 128 basta). Veja 0117 e 0120.

</details>

## Para ler mais

- CORMEN, T. H. et al. *Algoritmos: teoria e prática*. 4. ed. Rio de Janeiro: GEN LTC, 2024. Cap. 8 (limite inferior, counting, radix e bucket sort) e cap. 9 (medianas e estatísticas de ordem: `RANDOMIZED-SELECT` e `SELECT`).
- ZIVIANI, N. *Projeto de algoritmos com implementações em Pascal e C*. 3. ed. São Paulo: Cengage Learning, 2010. Cap. 4: ordenação (shellsort, estabilidade e ordenação parcial).
- SEDGEWICK, R. *Algorithms in C, parts 1-4*. 3. ed. Boston: Addison-Wesley, 1998. Caps. 6 (shellsort), 7 (quicksort e seleção) e 10 (radix sort).
- SEDGEWICK, R.; WAYNE, K. *Algorithms*. 4. ed. Boston: Addison-Wesley, 2011. Seções 2.1 (shellsort) e 5.1 (ordenação de strings). Disponível em: <https://algs4.cs.princeton.edu/>.
- KNUTH, D. E. *The art of computer programming, volume 3: sorting and searching*. 2. ed. Boston: Addison-Wesley, 1998. Seção 5.2.1 (shellsort) e 5.2.5 (ordenação por distribuição).
- SZWARCFITER, J. L.; MARKENZON, L. *Estruturas de dados e seus algoritmos*. 3. ed. Rio de Janeiro: LTC, 2010. Caps. de ordenação: limite inferior e ordenação por distribuição.
- TENENBAUM, A. M.; LANGSAM, Y.; AUGENSTEIN, M. J. *Estruturas de dados usando C*. São Paulo: Makron Books, 1995. Cap. 6 (classificação: shell sort, radix sort e cálculo de endereço).
- ROVAI, K. R. *Algoritmos e estrutura de dados*. Londrina: Editora e Distribuidora Educacional, 2018. Seção sobre espalhamento por cálculo de endereço (a semente do bucket sort).
- LINTZMAYER, C. N.; MOTA, G. O. *Análise de algoritmos e de estruturas de dados*. Santo André: UFABC, 2023. Rascunho. Seções de shellsort, counting sort e seleção.
- FEOFILOFF, P. *Algoritmos em linguagem C*. Rio de Janeiro: Elsevier, 2009. Caps. de ordenação; e as notas "Ordenação digital" e "Mediana e seleção". Disponível em: <https://www.ime.usp.br/~pf/algoritmos/>.
- HOARE, C. A. R. Algorithm 65: find. *Communications of the ACM*, v. 4, n. 7, p. 321-322, 1961.
- BLUM, M. et al. Time bounds for selection. *Journal of Computer and System Sciences*, v. 7, n. 4, p. 448-461, 1973.
- SHELL, D. L. A high-speed sorting procedure. *Communications of the ACM*, v. 2, n. 7, p. 30-32, 1959.
- CIURA, M. Best increments for the average case of shellsort. In: INTERNATIONAL SYMPOSIUM ON FUNDAMENTALS OF COMPUTATION THEORY, 13., 2001, Riga. *Proceedings*. Berlin: Springer, 2001. p. 106-117.
- KERNIGHAN, B. W.; RITCHIE, D. M. *C: a linguagem de programação padrão ANSI*. Rio de Janeiro: Campus, 1989. Seções 2.9 (operadores bit a bit) e 5.11 (ponteiros para funções).
- CPPREFERENCE. *qsort, qsort_s* e *clock*. Disponível em: <https://en.cppreference.com/w/c/algorithm/qsort> e <https://en.cppreference.com/w/c/chrono/clock>.
- LINUX MAN-PAGES. *qsort(3)* e *clock(3)*. Disponível em: <https://man7.org/linux/man-pages/man3/qsort.3.html>.
