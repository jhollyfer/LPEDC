## 0089 · Busca sequencial

Você passa a carteirinha na catraca da academia e ela responde "liberado" ou
"bloqueado". Por trás da resposta, o sistema procurou a sua matrícula numa
lista de alunos ativos. Procurar um valor numa coleção é uma das tarefas mais
comuns de um programa, e o módulo começa pelo jeito mais direto de fazê-la.

Pense em achar um nome numa lista de chamada sem ordem nenhuma. Você lê o
primeiro nome, depois o segundo, e segue até encontrar ou chegar ao fim da
folha. A **busca sequencial**, também chamada de **busca linear**, é isso
num vetor: ela compara o valor procurado com a posição 0, depois com a 1, e
assim por diante, até achar ou acabar o vetor. Ela não exige que o vetor
esteja em ordem (ZIVIANI, 2010, cap. 5).

O valor procurado se chama **chave**. A função recebe o vetor, o tamanho e a
chave, e devolve o **índice** em que achou. Se não achou, devolve `-1`, que
nunca é um índice válido e por isso não se confunde com uma resposta. O
tamanho vai como parâmetro porque o vetor do C não guarda o próprio tamanho:
dentro da função, ele chega como um ponteiro para o primeiro elemento
(DEITEL; DEITEL, 2011, cap. 6).

Para medir o custo, você conta quantas **comparações** com a chave a função
faz. No **melhor caso**, a chave está na posição 0 e basta uma comparação. No
**pior caso**, a chave está na última posição ou nem está no vetor, e a
função faz `n` comparações. Responder "não tem" é sempre o caso caro, porque
só dá para afirmar a ausência depois de olhar **todos** os elementos. No
**caso médio**, com a chave presente numa posição qualquer, a função faz
`(n + 1) / 2` comparações (ZIVIANI, 2010, cap. 5).

Na notação do assunto 0072, a busca sequencial é **O(n)**: o pior caso cresce
na mesma proporção do vetor. Se a academia dobra o número de alunos, a
catraca leva o dobro do tempo para dizer "bloqueado" a quem não está na lista
(FEOFILOFF, 2009). Para algumas centenas de alunos, ninguém percebe. Para
milhões de registros consultados a toda hora, isso pesa, e o 0090 mostra como
fazer melhor quando o vetor está ordenado.

Dá para economizar um pouco mesmo sem ordem. O laço comum faz duas perguntas
por volta: "`i` ainda está dentro do vetor?" e "`v[i]` é a chave?". A
**sentinela** elimina a primeira. Você copia a chave para uma gaveta extra no
fim do vetor; assim o laço sempre para, no pior caso nessa gaveta, e não
precisa mais testar `i < n` (ZIVIANI, 2010, cap. 5). Se a busca parou na
gaveta extra, a chave não estava no vetor original. O custo continua O(n),
mas cada volta faz uma pergunta a menos.

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
