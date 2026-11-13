## 0080 · Lista circular

Algumas tarefas não têm fim, só "o próximo". O garçom do rodízio serve as
mesas 3, 7, 12 e 15 e, depois da última, volta à 3. No jogo de tabuleiro, a
vez passa de jogador em jogador e, depois do último, volta ao primeiro. Numa
lista encadeada comum, o último nó aponta para `NULL`, e o programa teria de
perceber o fim e pular de volta ao início a cada volta.

Pense numa roda de ciranda: cada pessoa segura a mão da seguinte, e a última
segura a mão da primeira. Não há ponta solta. Uma **lista circular** é uma
lista encadeada em que o último nó aponta para o **primeiro**, e não para
`NULL`, e os nós formam um anel (FEOFILOFF, 2009, cap. 4). Ela serve para
rodízios em geral, como a vez dos jogadores ou a divisão do tempo da CPU entre
os programas que estão rodando (TENENBAUM; LANGSAM; AUGENSTEIN, 1995,
cap. 4).

Numa lista circular, convém guardar o ponteiro para o **último** nó, e não
para o primeiro. Parece estranho, mas o primeiro está a uma seta de
distância: é `ultimo->prox`. Com o último em mãos, você alcança as duas
pontas sem percorrer nada, e inserir no início **e** no fim custa O(1)
(TENENBAUM; LANGSAM; AUGENSTEIN, 1995, cap. 4). Inserir no início é encaixar
o novo nó entre o último e o primeiro. Inserir no fim é a mesma coisa, com
um passo a mais: depois de encaixar, declare o novo nó como o último. No
anel, início e fim são vizinhos, e só o ponteiro `ultimo` diz quem é quem.

Se a lista guardasse o primeiro, inserir no início exigiria mudar a seta do
último para o novo primeiro, e achar o último custa percorrer o anel inteiro,
O(n).

Percorrer pede um cuidado novo. Não existe `NULL` para parar o laço; ele para
ao **voltar ao ponto de partida**. Só que o laço começa justamente no ponto
de partida, e um `while (p != primeiro)` testaria a condição antes de andar e
não rodaria nem uma vez. O laço certo é o **do-while** (assunto 0021), que
executa o corpo antes de testar. A lista vazia, `ultimo == NULL`, não tem
primeiro, e é tratada antes do laço (CELES; RANGEL, 2002):

```c
if (ultimo != NULL) {
    No *p = ultimo->prox;      // começa no primeiro
    do {
        printf("%d ", p->valor);
        p = p->prox;
    } while (p != ultimo->prox); // parou quando voltou ao primeiro
}
```

Duas operações saem quase de graça. **Girar** a roda, fazendo o primeiro
virar o último, é só `ultimo = ultimo->prox`: nenhum nó muda, só o ponteiro de
referência anda uma casa. **Juntar** duas listas circulares numa só é trocar
dois ponteiros, as setas que fecham cada anel, também O(1).

A lista dupla também pode ser circular: o último aponta para o primeiro pela
frente, e o primeiro aponta para o último por trás. É a forma que o Cormen
usa, com um nó **sentinela** que fica entre o fim e o começo e nunca guarda
dado (CORMEN et al., 2024, cap. 10). O assunto 0174 volta a ela.

Um problema clássico usa o anel: o **problema de Josephus**. Pessoas em roda
eliminam uma a cada k passos, até sobrar uma. Na lista circular, isso vira
andar k nós, remover o nó, e repetir até restar um nó que aponta para si
mesmo (FEOFILOFF, 2009, cap. 4).

> [!WARNING]
> Na lista circular, `p` **nunca** vira `NULL`: um laço `p != NULL` não
> termina. No `libera`, **corte o círculo** antes (`ultimo->prox = NULL`) e
> trate como lista comum: sem isso, o seguinte do último é o primeiro, já
> liberado.

{{exemplo}}

O garçom do rodízio serve as mesas 3, 7, 12 e 15 e, na última, volta à 3. O
ponteiro da lista fica na mesa 15, e a 3 é `ultimo->prox`:

{{ideia}}

As duas inserções do `lista.c`:

```c
No *lista_insere_inicio(No *ultimo, int valor) {
    No *novo = cria_no(valor);       // cria_no faz novo->prox = novo
    if (ultimo == NULL) return novo; // único nó: primeiro e último
    novo->prox = ultimo->prox;       // o novo aponta para o antigo primeiro
    ultimo->prox = novo;             // o último fecha o círculo no novo
    return ultimo;
}

No *lista_insere_fim(No *ultimo, int valor) {
    // inserir no fim = inserir no início e dizer que o novo é o último
    ultimo = lista_insere_inicio(ultimo, valor);
    return ultimo->prox;
}
```

```c
#include <stdio.h>
#include "lista.h"

int main(void) {
    No *salao = NULL; // ponteiro para a ÚLTIMA mesa
    int mesas[] = {3, 7, 12, 15};
    for (int i = 0; i < 4; i++) salao = lista_insere_fim(salao, mesas[i]);
    lista_imprime(salao);

    // o garçom sai da primeira mesa e serve 6 vezes, sem nunca achar um fim
    printf("serve:");
    No *garcom = salao->prox;
    for (int i = 0; i < 6; i++) {
        printf(" %d", garcom->valor);
        garcom = garcom->prox;
    }
    printf("\n");

    lista_remove(&salao, 12);
    printf("a mesa 12 pagou e foi embora\n");
    lista_imprime(salao);

    lista_libera(salao);
    return 0;
}
// Saída:
// 3 -> 7 -> 12 -> 15 -> (volta ao 3)
// serve: 3 7 12 15 3 7
// a mesa 12 pagou e foi embora
// 3 -> 7 -> 15 -> (volta ao 3)
```

O `lista_imprime` testa a lista vazia, põe `p` na mesa 3 e pergunta "já
voltei ao primeiro?": com 4 mesas, Não três vezes e Sim na quarta:

{{fluxograma}}
