## 0080 · Vetor dinâmico

Você vai passar o fim de semana na praia e quer anotar cada despesa da
viagem: o café, o estacionamento, o almoço. Quantas serão? Não dá para saber.
Um `int despesas[100]` desperdiça memória se forem 5 e estoura se forem 101.

A saída é um vetor que cresce sob demanda: ele começa com uma folga e,
quando a folga acaba, pede um vetor maior e copia tudo. É o que toda
biblioteca de "lista que cresce sozinha" faz por baixo, e é o que você vai
escrever agora.

Uma **lista sequencial** guarda os itens lado a lado, num vetor contínuo, na
ordem em que estão na lista. Para ela crescer, você controla três coisas: o
endereço do vetor no heap (`itens`), quantos itens estão em uso (`tam`) e
quantos cabem (`cap`). Enquanto `tam < cap`, inserir no fim é só escrever em
`itens[tam]`.

Quando `tam == cap`, o vetor está cheio. Aí entra o `realloc` (assunto 0060):
ele pede um bloco maior, copia os itens e devolve o bloco antigo. A pergunta
é: maior quanto? A resposta clássica é **dobrar a capacidade**. Você vai ver
no "Por dentro do C" por que crescer de um em um é uma péssima ideia.

O pacote todo vira um **TAD** (assunto 0079): `lista.h` diz **o que** a lista
faz e `lista.c` diz **como**. A `struct lista` fica escondida no `.c`, então
quem usa a lista nunca mexe em `tam` na mão. O `rodar` compila o `lista.c`
junto com o exemplo, porque ele está na mesma pasta.

Vamos ver na prática. A lista começa com espaço para 2 despesas. A 3ª dobra
para 4 e a 5ª, o R$ 27, encontra o vetor cheio de novo: o `realloc` dobra
para 8, copia os quatro valores e ainda sobram três vagas:

{{ideia}}

O coração do `lista.c` é a função que garante espaço antes de cada inserção:

```c
struct lista {
    int *itens; // vetor no heap
    int tam;    // quantos itens estão em uso
    int cap;    // quantos itens cabem no vetor
};

// garante espaço para mais um item: se encheu, dobra
static bool garante_espaco(Lista *l) {
    if (l->tam < l->cap) return true;
    int nova_cap = l->cap * 2;
    int *novo = realloc(l->itens, nova_cap * sizeof(int));
    if (novo == NULL) return false; // l->itens continua valendo
    l->itens = novo;
    l->cap = nova_cap;
    return true;
}

bool lista_insere_fim(Lista *l, int valor) {
    if (!garante_espaco(l)) return false;
    l->itens[l->tam] = valor;
    l->tam++;
    return true;
}
```

E quem usa a lista só enxerga a interface de `lista.h`:

```c
#include <stdio.h>
#include "lista.h"

int main(void) {
    int despesas[] = {12, 35, 8, 50, 27}; // em reais
    Lista *viagem = lista_cria(2);        // começa com espaço para 2
    if (viagem == NULL) return 1;

    for (int i = 0; i < 5; i++) {
        lista_insere_fim(viagem, despesas[i]);
        printf("inseriu %2d: tam %d, cap %d\n", despesas[i],
               lista_tamanho(viagem), lista_capacidade(viagem));
    }
    lista_imprime(viagem);

    int total = 0;
    for (int i = 0; i < lista_tamanho(viagem); i++) {
        int valor;
        lista_pega(viagem, i, &valor);
        total += valor;
    }
    printf("total: R$ %d\n", total);

    lista_libera(viagem);
    return 0;
}
// Saída:
// inseriu 12: tam 1, cap 2
// inseriu 35: tam 2, cap 2
// inseriu  8: tam 3, cap 4
// inseriu 50: tam 4, cap 4
// inseriu 27: tam 5, cap 8
// [12, 35, 8, 50, 27]
// total: R$ 132
```

Repara no fluxograma: a pergunta "está cheio?" vem antes de escrever. No caso
do 27 a resposta é Sim, o vetor dobra e só depois o valor entra em
`itens[4]`. Se o `realloc` falhar, a função avisa com `false` e a lista
continua inteira:

{{fluxograma}}

O preço do vetor aparece quando você insere ou remove **no meio**: todo mundo
que vem depois precisa andar uma casa (o exemplo A160 mostra). Ler a posição
`i`, por outro lado, é instantâneo: `itens[i]` é uma conta de endereço.

> [!WARNING]
> Guardar o **endereço** de um item e depois inserir é pedir um ponteiro
> solto: `int *p = &itens[0];` aponta para o bloco antigo, que o `realloc`
> pode ter devolvido. Guarde a **posição** (o índice), nunca o endereço. E
> nunca escreva `l->itens = realloc(l->itens, ...)` direto: se o `realloc`
> devolver `NULL`, você perde o único endereço do bloco antigo.

> [!TIP]
> **Por dentro do C:** dobrando, inserir n itens copia no total menos de 2n
> itens (1 + 2 + 4 + ... + n/2 + n), então cada inserção custa O(1) **em
> média** (custo amortizado). Crescendo de um em um, cada inserção copia tudo
> de novo: 1 + 2 + 3 + ... + n ≈ n²/2 cópias. Para um milhão de despesas, são
> uns 20 `realloc` contra um milhão deles. A `struct lista` tem 16 bytes
> (ponteiro de 8 + dois `int` de 4) e mora num bloco do heap; o vetor mora em
> outro bloco. Por isso o `lista_libera` faz dois `free`, primeiro o vetor.

> [!NOTE]
> **Pergunta para você:** começando com `lista_cria(2)`, quantas vezes o
> `realloc` roda até a lista ter 100 itens? E qual é a capacidade final?
> Quantas vagas ficam sobrando?

{{pratique}}
