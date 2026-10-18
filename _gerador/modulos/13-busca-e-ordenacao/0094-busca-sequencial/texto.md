## 0094 · Busca sequencial

Você passa a carteirinha na catraca da academia. Em meio segundo ela responde
"liberado" ou "bloqueado". Por trás, o sistema procurou a sua matrícula numa
lista de alunos ativos. Como?

O jeito mais simples de procurar é o que você faria com uma pilha de fichas:
olhar a primeira, depois a segunda, depois a terceira, até achar ou acabar a
pilha. Isso é a **busca sequencial** (ou **busca linear**). Ela não exige nada
do vetor: pode estar em qualquer ordem.

O contrato é o de sempre no C: a função recebe o vetor, o tamanho e o valor
procurado (a **chave**), e devolve o **índice** onde achou. Se não achou,
devolve `-1`, que nunca é um índice válido. É exatamente o que o
`Array.prototype.indexOf` faz no JS. A diferença é que aqui você escreve o
laço e passa o tamanho, porque o vetor do C não sabe quantos elementos tem.

Quanto custa? Conte as **comparações** com a chave, que é o trabalho de
verdade:

- **melhor caso**: a chave está na posição 0. Uma comparação.
- **pior caso**: a chave está no fim ou não está no vetor. São `n`
  comparações. Para responder "não tem", a busca precisa olhar **todos**.
- **caso médio** (chave presente, em posição sorteada): `(n + 1) / 2`
  comparações, mais ou menos metade do vetor.

Em notação do assunto 0077, a busca sequencial é **O(n)**: dobrou o número de
alunos, dobrou o tempo da catraca no pior caso.

Vamos ver na prática. A academia tem 6 alunos ativos e a catraca procura a
matrícula 1290. Ela compara com 4172, 3305 e 8821 (diferentes, em amarelo) e
acha na quarta gaveta, a de índice 3. As duas últimas nem são olhadas:

{{ideia}}

O mesmo exemplo em C. A função conta as comparações num ponteiro, para você
ver o custo de cada busca:

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

O teste de mesa da busca por 1290. Cada linha é uma volta do laço:

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

Repara no fluxograma: são duas perguntas por volta. A primeira (`i < n?`)
protege o vetor; a segunda (`v[i] == x?`) é a busca de fato. O caminho verde
dá a volta três vezes antes de sair pelo Sim:

{{fluxograma}}

> [!WARNING]
> O erro clássico é decidir cedo demais. Com `if (v[i] == x) return i; else
> return -1;` dentro do laço, a função olha **só o primeiro** elemento e
> desiste. "Não achei" só pode ser dito **depois** do laço, quando todos já
> foram olhados. O compilador não reclama: o programa roda e responde errado.

> [!TIP]
> **Por dentro do C:** `const int v[]` no parâmetro é, na verdade, um
> `const int *`: a função recebe só o endereço da gaveta 0, e `v[i]` é
> `*(v + i)`. Como as gavetas são vizinhas na memória, a busca sequencial lê
> os bytes em ordem, e o processador adora isso: ele traz da RAM blocos de 64
> bytes (uma **linha de cache**, 16 `int`) de uma vez. Por isso, em vetores
> pequenos (dezenas de elementos), a busca sequencial costuma ganhar de
> estruturas "mais espertas". Um truque antigo é a **sentinela**: copiar a
> chave para uma gaveta extra no fim. Aí o laço não precisa mais perguntar
> `i < n`, porque sempre vai achar. É uma pergunta a menos por volta (veja o
> exemplo A188).

> [!NOTE]
> **Pergunta para você:** se a matrícula 3305 aparecesse duas vezes no vetor,
> nas posições 1 e 4, qual posição a função devolveria? E quantas comparações
> ela faria para achar 7034? Responda e confira mudando o exemplo A187.

{{pratique}}
