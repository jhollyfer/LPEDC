## 0114 · Recorrências e árvore de recursão

- **Recorrência**: equação que dá o custo de uma função recursiva em termos do
  custo dela em entradas menores, mais um caso base
  (CORMEN et al., 2024, cap. 4).
- **Ler a recorrência no código**: quantas chamadas e de que tamanho (o termo
  `2 T(n/2)`)? Quanto trabalho fora delas (o `+ n`)? Qual o caso base e seu
  custo (`T(1) = 1`)? (ZIVIANI, 2010, cap. 2).
- **Árvore de recursão**: cada chamada vira um nó com o trabalho que faz
  sozinha, e a soma é feita **nível por nível**. Serve para resolver e para
  chutar a resposta (LINTZMAYER; MOTA, 2023).
- **Substituição**: chute a resposta e prove por indução. No passo é preciso
  chegar **exatamente** na expressão chutada (CORMEN et al., 2024, cap. 4).
- **Θ** (teta): a função cresce **exatamente** naquele ritmo. O `O` (0072) é
  teto; o Θ é teto e piso. Definições formais no 0166
  (CORMEN et al., 2024, cap. 3).
- **Tempo e memória**: o tempo é a soma dos nós da árvore; a memória é a
  altura, os frames vivos na pilha (0031) (FEOFILOFF, 2009).

```text
T(1) = 1                  (caso base: confere a nota e para)
T(n) = 2 T(n/2) + n       (duas chamadas com metade, mais n de trabalho)
```

Os lotes caem pela metade até 1: há `log₂ n + 1` níveis de custo `n`, e o
total é `n log₂ n + n`, ou **Θ(n log n)**.

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
