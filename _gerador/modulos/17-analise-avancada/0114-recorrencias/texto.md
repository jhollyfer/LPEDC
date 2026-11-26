## 0114 · Recorrências e árvore de recursão

No módulo 10, você mediu o custo de um algoritmo contando as voltas dos laços.
Uma função recursiva quase não tem laço: o trabalho está espalhado pelas
chamadas que ela faz a si mesma. Pense na contabilidade de uma rede de
farmácias. A chefe recebe um lote de notas fiscais, confere o lote inteiro,
divide em dois lotes iguais e entrega cada metade a um auditor, que faz o
mesmo com a sua metade. Com uma nota só, o auditor confere e para. Quantas
notas são olhadas no total? Contar laços não responde.

A ferramenta para isso é a **recorrência**: uma equação que dá o custo de uma
função recursiva para uma entrada de tamanho `n` em termos do custo dela para
entradas menores, mais um caso base que diz quanto custa a menor entrada
(CORMEN et al., 2024, cap. 4). Chamando de `T(n)` o custo de conferir um lote
de `n` notas, a auditoria fica assim:

```text
T(1) = 1                  (caso base: confere a nota e para)
T(n) = 2 T(n/2) + n       (duas chamadas com metade, mais n de trabalho)
```

Para escrever a recorrência a partir do código, faça três perguntas. Quantas
chamadas recursivas a função faz, e com que tamanho? Aqui são 2, com metade
cada, e isso vira o termo `2 T(n/2)`. Quanto trabalho ela faz fora das
chamadas? Aqui, olhar as `n` notas, e isso vira o `+ n`. Qual é o caso base e
quanto ele custa? Aqui, `T(1) = 1` (ZIVIANI, 2010, cap. 2).

A recorrência tem `T` dos dois lados, então ainda não diz quanto custa.
**Resolver** é chegar numa fórmula só em `n`. O jeito mais visual é a **árvore
de recursão**: cada chamada vira um nó, e dentro do nó fica o trabalho que ela
faz sozinha, sem contar as filhas. Depois você soma **nível por nível**
(LINTZMAYER; MOTA, 2023). Na auditoria, o nível 0 é a chefe, com `n` notas. O
nível 1 tem 2 auditores com `n/2` cada, que somam `n`. O nível `k` tem `2^k`
chamadas de `n/2^k` notas, e de novo a soma dá `n`. Os lotes caem pela metade
até chegar em 1, o que leva `log₂ n` divisões, então há `log₂ n + 1` níveis.
O total é `n log₂ n + n`, ou **Θ(n log n)**.

O símbolo **Θ** (teta) diz que a função cresce **exatamente** naquele ritmo. O
`O` do assunto 0072 é um teto: garante que o custo não passa daquilo. O Θ é
teto e piso ao mesmo tempo: o custo nem passa nem fica abaixo daquele ritmo,
fora constantes. As definições formais estão no assunto 0166 (CORMEN et al.,
2024, cap. 3).

A árvore também serve para chutar a resposta de uma recorrência difícil. O
chute então é confirmado pelo **método da substituição**: você supõe que a
resposta vale para entradas menores e prova por indução que vale para `n`. O
cuidado é chegar **exatamente** na expressão chutada no passo da indução; uma
constante a mais que "não faz diferença" invalida a prova (CORMEN et al.,
2024, cap. 4). O terceiro método, o teorema mestre, é o assunto 0115.

A árvore mostra ainda os dois recursos que uma função recursiva gasta, porque
ela é o filme da pilha de chamadas do assunto 0031. O **tempo** é a soma de
todos os nós: para 8 notas, são `2n - 1 = 15` chamadas. A **memória** é a
altura da árvore, porque só os frames de um caminho da raiz até uma folha
ficam vivos ao mesmo tempo: no máximo `log₂ n + 1 = 4` (FEOFILOFF, 2009).

A forma da recorrência decide a forma da árvore, e a forma da árvore decide o
resultado. Uma chamada só, com tamanho caindo de 1 em 1, dá uma linha de `n`
nós. Uma chamada só, com tamanho caindo pela metade, dá uma linha de `log n`
nós. Duas chamadas com tamanho caindo de 1 em 1 dão uma árvore que dobra a
cada nível. A tabela reúne os casos que mais aparecem:

| recorrência | árvore | resultado | exemplo |
| --- | --- | --- | --- |
| `T(n) = T(n-1) + 1` | uma linha de n nós | Θ(n) | percorrer lista recursivamente |
| `T(n) = T(n/2) + 1` | uma linha de log n nós | Θ(log n) | busca binária |
| `T(n) = T(n-1) + n` | uma linha, nós encolhendo | Θ(n²) | selection sort recursivo |
| `T(n) = 2 T(n/2) + n` | binária, log n níveis de custo n | Θ(n log n) | merge sort, a auditoria |
| `T(n) = 2 T(n-1) + 1` | binária, n níveis que dobram | Θ(2ⁿ) | Hanói (assunto 0033) |

> [!WARNING]
> "Duas chamadas recursivas" não diz nada sozinho: decide o **tamanho** de cada
> chamada. `2 T(n/2) + 1` (máximo dividindo o vetor) dá Θ(n); `2 T(n-1) + 1`
> (Hanói) dá Θ(2ⁿ): para `n = 30`, mais de um bilhão de chamadas.

{{exemplo}}

A chefe da contabilidade confere um lote de notas, divide em dois e passa
cada metade a um auditor, que faz o mesmo. Com 8 notas, cada caixa é uma
chamada; cada linha soma 8, e são 4 linhas:

{{ideia}}

O código soma as notas de cada nível num vetor indexado pela profundidade e
confere `n log₂ n + n` para lotes maiores:

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

O fluxograma é a função `audita` e não tem laço: as duas caixas `audita` são
o `2 T(n/2)` e a caixa `custo_nivel += n` é o `+ n`:

{{fluxograma}}

### Passo a passo

Abrir o `T` até o caso base, com `n = 8`:

| passo | conta | valor |
| --- | --- | --- |
| T(1) | caso base | 1 |
| T(2) | 2 · T(1) + 2 = 2 + 2 | 4 |
| T(4) | 2 · T(2) + 4 = 8 + 4 | 12 |
| T(8) | 2 · T(4) + 8 = 24 + 8 | **32** |

Bate com a árvore (4 níveis de 8) e com o programa.
