## 0089 · Busca sequencial

- **Busca sequencial** (ou **linear**): olha a primeira posição, depois a
  segunda, até achar ou acabar o vetor. Não exige ordem (ZIVIANI, 2010,
  cap. 5).
- **Chave**: o valor procurado. A função devolve o **índice** em que achou
  ou `-1`, que nunca é índice válido. O tamanho vai como parâmetro porque o
  vetor do C não o guarda (DEITEL; DEITEL, 2011, cap. 6).
- **Custo**: conta-se o número de **comparações** com a chave. Melhor caso,
  1 (a chave na posição 0); pior caso, `n` (no fim ou ausente: "não tem" exige
  olhar todos); caso médio, `(n + 1) / 2` (ZIVIANI, 2010, cap. 5).
- **O(n)** (0072): dobrou o tamanho, dobra o tempo no pior caso
  (FEOFILOFF, 2009).
- **Sentinela**: copia a chave para uma gaveta extra no fim, e o laço deixa
  de testar `i < n`: uma pergunta a menos por volta (ZIVIANI, 2010, cap. 5).

> [!WARNING]
> Com `if (v[i] == x) return i; else return -1;` dentro do laço, a função olha
> só o primeiro elemento e desiste. "Não achei" só vale **depois** do laço.

{{exemplo}}

A catraca da academia procura a matrícula 1290 entre 6 alunos ativos. Compara
com 4172, 3305 e 8821 (amarelo) e acha na gaveta de índice 3; as duas últimas
nem são olhadas:

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

Para 9999, as 6 linhas seriam "não" e o `-1` só sai depois da última.

Duas perguntas por volta: `i < n?` protege o vetor e `v[i] == x?` é a busca.
O caminho dá a volta três vezes antes de sair pelo Sim:

{{fluxograma}}
