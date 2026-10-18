## 0085 · Lista circular

Na churrascaria de rodízio, o garçom da pizza passa de mesa em mesa: 3, 7,
12, 15. Quando serve a última, ele não para: volta para a mesa 3 e começa
outra rodada. Para ele, não existe "fim da fila". Existe só "a próxima mesa".

Uma **lista circular** é uma lista encadeada em que o último nó, em vez de
apontar para `NULL`, aponta de volta para o **primeiro**. Os nós formam um
anel. Ela serve para tudo que é rodízio: a vez de cada jogador num jogo de
tabuleiro, a playlist no "repetir tudo", os programas que dividem a CPU, o
revezamento de motoristas numa viagem.

Num anel, qual nó você guarda? A escolha esperta é guardar o **último**. Dele
você chega às duas pontas em um passo: o último é `ultimo` e o primeiro é
`ultimo->prox`. Com isso, inserir no início **e** no fim custa O(1). Inserir
no fim é até mais curioso: é inserir no início e dizer que o novo é o
último.

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

Percorrer muda de cara. Não tem `NULL` para avisar que acabou: você para
quando **voltar ao ponto de partida**. Como o primeiro passo já começa no
ponto de partida, o laço certo é o **do-while** (assunto 0026): ele roda o
corpo uma vez antes de testar. E a lista vazia (`ultimo == NULL`) precisa ser
tratada antes, porque não tem por onde começar.

Vamos ver na prática. As quatro mesas formam o anel, o ponteiro da lista
fica na mesa 15 (a última) e a mesa 3 é `ultimo->prox`. O garçom serve 6
vezes seguidas sem testar nada, porque sempre existe uma próxima:

{{ideia}}

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

Repara no fluxograma do `lista_imprime`: a pergunta da lista vazia vem
primeiro. Depois, `p` começa na mesa 3 e o laço mostra, anda e só então
pergunta "já voltei ao primeiro?". Com as 4 mesas, a resposta é Não três
vezes e Sim na quarta:

{{fluxograma}}

O clássico da lista circular é o **problema de Josephus**: pessoas em roda, e
a cada k passos uma sai. Quem sobra? O exemplo A170 resolve com a batata
quente, tirando nós do anel até sobrar um que aponta para si mesmo.

> [!WARNING]
> Todo laço de lista que você escreveu até aqui termina em `p != NULL`. Numa
> lista circular, `p` **nunca** vira `NULL`: o laço dá voltas para sempre.
> No `libera` é pior: depois de liberar o último, o "seguinte" dele é o
> primeiro, que você já liberou. Para liberar, **corte o círculo** primeiro
> (`ultimo->prox = NULL`) e trate como lista comum. E cuidado com o `while`
> no lugar do `do-while`: `while (p != ultimo->prox)` começando no primeiro
> não roda nem uma vez.

> [!TIP]
> **Por dentro do C:** o nó é o mesmo da lista simples, 16 bytes. Não há
> custo de memória a mais: o círculo é só o último `prox` apontando para um
> endereço em vez de `NULL`. Os truques vêm de graça: **girar** a roda é
> mudar um ponteiro (`ultimo = ultimo->prox`), sem mexer em nó nenhum; e
> **juntar** duas listas circulares é trocar dois ponteiros, O(1). O
> escalonador de um sistema operacional faz exatamente isso: o processo da
> frente roda um pouquinho e, se não terminou, a roda gira.

> [!NOTE]
> **Pergunta para você:** se a lista guardasse o ponteiro para o **primeiro**
> nó em vez do último, quanto custaria inserir no fim? E no início? (Lembre
> que o último precisa apontar para o novo primeiro.)

{{pratique}}
