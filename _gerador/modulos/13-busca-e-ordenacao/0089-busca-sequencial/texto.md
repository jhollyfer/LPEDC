## 0089 · Busca sequencial

Você passa a carteirinha na catraca da academia e ela responde "liberado" ou
"bloqueado": o sistema procurou a sua matrícula numa lista de alunos ativos.

A **busca sequencial** (ou **busca linear**) olha a primeira posição, depois a
segunda, e assim por diante, até achar ou acabar o vetor. Não exige ordem.

A função recebe o vetor, o tamanho e o valor procurado (a **chave**) e devolve
o **índice** em que achou. Se não achou, devolve `-1`, que nunca é um índice
válido. O tamanho vai como parâmetro porque o vetor do C não o guarda.

O custo é o número de **comparações** com a chave:

- **melhor caso**: a chave está na posição 0. Uma comparação.
- **pior caso**: a chave está no fim ou não está no vetor. São `n`
  comparações, porque responder "não tem" exige olhar **todos**.
- **caso médio** (chave presente, em posição sorteada): `(n + 1) / 2`
  comparações.

No assunto 0072, isso é **O(n)**: dobrou o número de alunos, dobrou o tempo
no pior caso.

A academia tem 6 alunos ativos e a catraca procura a matrícula 1290. Ela
compara com 4172, 3305 e 8821 (diferentes, em amarelo) e acha na quarta gaveta,
a de índice 3. As duas últimas nem são olhadas:

{{ideia}}

A função conta as comparações num ponteiro:

```c
#include <stdio.h>

// devolve o índice de x em v[0..n-1], ou -1 se x não estiver lá
int busca(const int v[], int n, int x, int *comparacoes) {
    *comparacoes = 0;
    for (int i = 0; i < n; i++) {
        (*comparacoes)++;
        if (v[i] == x) {
            return i; // achou: para na hora
        }
    }
    return -1; // olhou todos e não achou
}

int main(void) {
    int matriculas[] = {4172, 3305, 8821, 1290, 5567, 7034};
    int n = sizeof matriculas / sizeof matriculas[0];
    int comparacoes;

    int pos = busca(matriculas, n, 1290, &comparacoes);
    printf("1290: posição %d, %d comparações\n", pos, comparacoes);

    pos = busca(matriculas, n, 9999, &comparacoes);
    printf("9999: posição %d, %d comparações\n", pos, comparacoes);
    return 0;
}
// Saída:
// 1290: posição 3, 4 comparações
// 9999: posição -1, 6 comparações
```

### Passo a passo

Teste de mesa da busca por 1290, uma linha por volta do laço:

| i | v[i] | `v[i] == 1290`? | comparações | estado da gaveta |
| --- | --- | --- | --- | --- |
| 0 | 4172 | não | 1 | amarela (olhada) |
| 1 | 3305 | não | 2 | amarela |
| 2 | 8821 | não | 3 | amarela |
| 3 | 1290 | **sim** | 4 | verde: `return 3` |
| 4 | 5567 | | | cinza (nem olhada) |
| 5 | 7034 | | | cinza |

Para 9999, as 6 linhas seriam "não" e a função só devolve `-1` depois da
última.

O fluxograma faz duas perguntas por volta: `i < n?` protege o vetor e
`v[i] == x?` é a busca de fato. O caminho verde dá a volta três vezes antes de
sair pelo Sim:

{{fluxograma}}

> [!WARNING]
> Com `if (v[i] == x) return i; else return -1;` dentro do laço, a função olha
> só o primeiro elemento e desiste. "Não achei" só vale **depois** do laço.

> [!TIP]
> A **sentinela** copia a chave para uma gaveta extra no fim do vetor, e o laço
> deixa de testar `i < n`: uma pergunta a menos por volta (exemplo A178).

> [!NOTE]
> **Pergunta para você:** se a matrícula 3305 aparecesse nas posições 1 e 4,
> qual posição a função devolveria? E quantas comparações ela faria para achar
> 7034? O exemplo A177 mostra como achar todas as ocorrências.

{{pratique}}
