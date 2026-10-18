## 0107 · Heap e fila de prioridade

No pronto-socorro, ninguém é atendido por ordem de chegada. A triagem dá uma
nota de gravidade a cada paciente, e o próximo a entrar é sempre o **mais
grave** de quem está esperando. Chegou alguém com infarto? Passa na frente de
todo mundo.

Isso é uma **fila de prioridade**: você insere elementos com uma prioridade e
sempre tira o de **maior** prioridade. Dá para fazer com o que você já sabe, mas
tudo custa caro. Num vetor solto, inserir é O(1) e achar o máximo é O(n). Num
vetor ordenado, tirar o máximo é O(1), mas inserir é O(n). Numa BST, os dois são
O(log n) só se ela estiver equilibrada.

O **heap** (de máximo) faz as duas operações em O(log n), sempre, e sem um
ponteiro sequer. Ele é uma árvore binária com duas regras:

- **forma**: a árvore é **completa**: todos os níveis cheios, menos talvez o
  último, que se enche da esquerda para a direita;
- **ordem**: todo pai é **maior ou igual** aos filhos. Logo, o máximo está
  sempre na raiz.

Repare que a regra de ordem é mais fraca que a da BST: não importa quem fica à
esquerda ou à direita, nem se um primo é maior que o outro. Por isso o heap não
serve para buscar uma chave qualquer. Ele só sabe responder "quem é o maior?".

A regra de forma é o pulo do gato. Uma árvore completa cabe **num vetor**, nível
por nível, sem buracos. A raiz fica em `v[0]` e, para qualquer índice `i`:

| Quem | Índice |
| --- | --- |
| pai de `i` | `(i - 1) / 2` (divisão inteira) |
| filho esquerdo | `2 * i + 1` |
| filho direito | `2 * i + 2` |

As duas operações consertam o heap andando por um único caminho:

- **inserir**: o novo entra no fim do vetor (a próxima vaga da árvore) e **sobe**:
  enquanto for maior que o pai, troca com ele;
- **remover o máximo**: a raiz sai, o último elemento do vetor vai para o lugar
  dela e **desce**: enquanto for menor que algum filho, troca com o **maior**
  dos filhos.

A árvore tem altura ⌊log₂ n⌋, então subir ou descer custa no máximo isso.

Vamos ver na prática. Chegam pacientes com gravidade 40, 70, 20, 90, 50 e 30.
Depois das seis chegadas, o heap é `[90 70 30 40 50 20]`. A árvore e o vetor são
a mesma coisa: o 70 está no índice 1, e os filhos dele ficam nos índices 3 e 4:

{{ideia}}

O TAD guarda o vetor, quantos elementos tem e quantos cabem. As duas peças do
`heap.c` que fazem o trabalho:

```c
// o elemento em i sobe enquanto for maior que o pai
static void sobe(Heap *h, int i) {
    while (i > 0 && h->v[(i - 1) / 2] < h->v[i]) {
        troca(&h->v[(i - 1) / 2], &h->v[i]);
        i = (i - 1) / 2;
    }
}

// o elemento em i desce, trocando com o MAIOR dos filhos
static void desce(Heap *h, int i) {
    while (2 * i + 1 < h->n) {
        int f = 2 * i + 1;                       // filho esquerdo
        if (f + 1 < h->n && h->v[f + 1] > h->v[f]) {
            f++;                                 // o direito é maior
        }
        if (h->v[i] >= h->v[f]) {
            break;                               // já está no lugar
        }
        troca(&h->v[i], &h->v[f]);
        i = f;
    }
}
```

O cliente só vê `heap_insere` e `heap_remove`:

```c
#include <stdio.h>
#include "heap.h"

int main(void) {
    // gravidade de cada paciente, na ordem em que chegaram (maior = mais urgente)
    int chegada[] = {40, 70, 20, 90, 50, 30};
    Heap *fila = heap_cria(10);

    for (int i = 0; i < 6; i++) {
        heap_insere(fila, chegada[i]);
        printf("Chega %d: ", chegada[i]);
        heap_mostra(fila);
        printf("\n");
    }
    for (int i = 0; i < 2; i++) {
        int atendido = heap_remove(fila);
        printf("Atende %d: ", atendido);
        heap_mostra(fila);
        printf("\n");
    }

    heap_libera(fila);
    return 0;
}
// Saída:
// Chega 40: [40]
// Chega 70: [70 40]
// Chega 20: [70 40 20]
// Chega 90: [90 70 20 40]
// Chega 50: [90 70 20 40 50]
// Chega 30: [90 70 30 40 50 20]
// Atende 90: [70 50 30 40 20]
// Atende 70: [50 40 30 20]
```

Repara no fluxograma: é a subida do 30, o último a chegar. Ele entra no índice
5, o pai dele (índice 2) é o 20, menor: troca. Agora o 30 está no índice 2 e o
pai é o 90: para. Uma troca só:

{{fluxograma}}

### Passo a passo

A remoção do 90. O último (20) vai para a raiz e desce pelo filho maior:

| Passo | Vetor | `i` | Filhos de `i` | Maior filho | Troca? |
| --- | --- | --- | --- | --- | --- |
| tira o 90, o 20 vai para `v[0]` | `[20 70 30 40 50]` | 0 | 70, 30 | 70 (índice 1) | sim |
| | `[70 20 30 40 50]` | 1 | 40, 50 | 50 (índice 4) | sim |
| | `[70 50 30 40 20]` | 4 | (nenhum) | | para |

> [!WARNING]
> Na descida, troque com o **maior** dos filhos, não com o primeiro que for
> maior que o pai. No passo 1, o 20 é menor que o 70 e também que o 30. Trocar
> com o 30 colocaria o 30 na raiz, acima do 70: o heap quebra, e o próximo
> "atende" chamaria o paciente errado. O mesmo cuidado vale para o último
> filho: `f + 1 < h->n` confere se o filho direito existe antes de ler
> `v[f + 1]`.

> [!TIP]
> **Por dentro do C:** a palavra **heap** tem dois sentidos em C, e eles não
> têm nada a ver um com o outro. O heap do `malloc` (assunto 0058) é a região
> da memória para alocação dinâmica; o heap deste assunto é uma estrutura de
> dados. Aqui o heap de dados até mora no heap de memória (o `heap_cria` faz
> `malloc` do vetor), mas é coincidência. E por morar num vetor contíguo, o
> heap não gasta 16 bytes de ponteiros por elemento como a BST, e percorre a
> memória em sequência, o que o cache do processador adora.

> [!NOTE]
> **Pergunta para você:** o vetor `[90 70 30 40 50 20]` é um heap. E o vetor
> `[90 30 70 40 50 20]`? Desenhe a árvore e confira a regra em cada pai. Um vetor
> em ordem **decrescente** é sempre um heap?

{{pratique}}
