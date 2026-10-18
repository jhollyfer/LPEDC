## 0120 · Counting sort

No fim do expediente, a dona da lanchonete olha as avaliações do dia no app
de entregas. Cada pedido recebeu de 0 a 4 estrelas, e ela quer a lista em
ordem de nota para responder primeiro os clientes insatisfeitos. São 8
pedidos, de A a H, com 3, 1, 3, 2, 1, 4, 0 e 3 estrelas.

Ela nem pensa em comparar pedido com pedido. Faz cinco montes, um para cada
nota, e joga cada pedido no seu monte. Depois é só juntar os montes, do 0 ao
4. Ninguém foi comparado com ninguém.

No assunto 0117 você viu que nenhuma ordenação **por comparação** faz menos
que uns n log₂ n testes no pior caso. O **counting sort** (ordenação por
contagem) não fura esse limite: ele simplesmente não compara. Ele usa o
**valor** da chave como **índice** de um vetor. Para isso, as chaves precisam
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

Por que de trás para a frente? Porque assim, entre chaves iguais, quem vem
por último na entrada ocupa a última vaga do bloco. A ordem original dos
empates se mantém: o counting sort é **estável**. Isso parece detalhe, mas é
o que faz dele a peça central do radix sort, no próximo assunto.

Vamos ver na prática. A entrada passa uma vez para contar e outra para
distribuir. Os três pedidos de 3 estrelas (A, C e H, em verde) chegam à
saída na mesma ordem em que estavam:

{{ideia}}

O mesmo exemplo em C. A saída vai para outro vetor: o counting sort não
ordena no lugar.

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

Repara no fluxograma: são três laços em sequência, nenhum dentro do outro.
Dois andam pelos n elementos e um pelas k chaves, então o custo é
**O(n + k)**:

{{fluxograma}}

> [!WARNING]
> Se o terceiro laço for da frente para trás (`for (int i = 0; i < n; i++)`)
> com o mesmo `c[x]--`, o vetor sai ordenado pelas estrelas, mas os empates
> saem **invertidos**: H3 C3 A3 em vez de A3 C3 H3. O programa não dá erro
> nenhum, e o estrago só aparece quando a ordem dos empates importa (no radix
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

{{pratique}}
