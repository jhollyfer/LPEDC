## 0114 · Recorrências e árvore de recursão

Fim de ano na contabilidade de uma rede de farmácias: chegou um lote de notas
fiscais para auditar. A chefe confere o lote inteiro (passa o olho em todas as
notas), divide em dois lotes iguais e entrega cada metade para um auditor.
Cada auditor faz a mesma coisa: confere o seu lote, divide, repassa. Quando
um lote fica com uma nota só, quem recebeu confere essa nota e pronto.

Quantas notas são olhadas no total? Não dá para responder contando laços,
como no módulo 10: o trabalho está escondido nas chamadas. É hora de uma
ferramenta nova.

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
chegar em 1, então são `log₂ n + 1` níveis. Total: `n log₂ n + n`, ou seja,
**Θ(n log n)**.

O **Θ** (teta) é novo: ele diz que a função cresce **exatamente** naquele
ritmo, nem mais rápido nem mais devagar. O `O` do assunto 0072 é só um teto;
o Θ é teto e piso ao mesmo tempo. Quando você resolve uma recorrência até a
fórmula, sabe o ritmo exato, e o Θ é a palavra certa.

A forma da recorrência decide a forma da árvore. As cinco que você mais vai
ver:

| recorrência | árvore | resultado | exemplo |
| --- | --- | --- | --- |
| `T(n) = T(n-1) + 1` | uma linha de n nós | Θ(n) | percorrer lista recursivamente |
| `T(n) = T(n/2) + 1` | uma linha de log n nós | Θ(log n) | busca binária |
| `T(n) = T(n-1) + n` | uma linha, nós encolhendo | Θ(n²) | selection sort recursivo |
| `T(n) = 2 T(n/2) + n` | binária, log n níveis de custo n | Θ(n log n) | merge sort, a auditoria |
| `T(n) = 2 T(n-1) + 1` | binária, n níveis que dobram | Θ(2ⁿ) | Hanói (assunto 0033) |

Vamos ver na prática. Um lote de 8 notas. Cada caixa é uma chamada, com o
tamanho do lote que ela confere. Some cada linha: dá 8 em todas, e são 4
linhas:

{{ideia}}

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

Repara no fluxograma: é a função `audita` inteira, e ele não tem laço. A
repetição está escondida nas duas caixas `audita`: cada uma é o fluxograma
inteiro de novo, para uma metade. Duas caixas com metade do lote: é isso que
o `2 T(n/2)` da recorrência conta. A caixa `custo_nivel += n` é o `+ n`:

{{fluxograma}}

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
> Θ(2ⁿ): para `n = 30`, mais de um bilhão de chamadas. A diferença entre `n/2` e `n-1`
> na chamada é a diferença entre um programa instantâneo e um que não termina
> hoje. Leia com cuidado os argumentos de cada chamada antes de escrever a
> recorrência.

> [!TIP]
> **Por dentro do C:** a árvore de recursão é o **filme** da pilha de
> chamadas (assunto 0031). Cada nó é um frame que nasce, trabalha e morre; a
> ordem em que o programa visita os nós é a de uma DFS na árvore. Por isso o
> **tempo** é a soma de todos os nós (`2n - 1 = 15` chamadas para 8 notas),
> mas a **memória** da pilha é só a altura: no máximo `log₂ n + 1 = 4` frames
> vivos ao mesmo tempo. Para 1 milhão de notas, são 2 milhões de chamadas e
> só 21 frames empilhados. A pilha só estoura quando a árvore é **funda**,
> como na linha de `n` nós de `T(n-1) + 1`.

> [!NOTE]
> **Pergunta para você:** e se a chefe, em vez de dividir ao meio, tirasse uma
> nota só do lote e repassasse as outras `n - 1` para um único auditor? A
> recorrência vira `T(n) = T(n-1) + n`. Quanto dá para 8 notas? E para 1024?
> Compare com 32 e 11.264.

{{pratique}}
