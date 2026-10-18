## 0087 · Pilha

Você monta o pedido no app de delivery: pizza, refrigerante, pudim. Bateu o
arrependimento e você toca em "desfazer". Sai o pudim, o último que entrou.
Ninguém espera que o desfazer apague a pizza lá do começo.

Esse comportamento tem nome: **pilha** (*stack*). Só uma ponta está ao seu
alcance, o **topo**. Tudo entra por cima e sai por cima, então o último a
entrar é o primeiro a sair: **LIFO** (*last in, first out*). É a pilha de
pratos do restaurante por quilo, o Ctrl+Z do editor, o botão Voltar do
navegador e a pilha de chamadas que você viu no assunto 0036.

As operações são poucas, e é isso que dá força à pilha:

- **empilhar** (*push*): põe um item no topo;
- **desempilhar** (*pop*): tira o item do topo e devolve o valor;
- **olhar o topo** (*peek*): lê o topo sem tirar;
- **vazia?**: pergunta se ainda tem alguma coisa.

No JS, um array já faz isso: `pedido.push(2590)` e `pedido.pop()`. No C não
existe nada pronto, então você monta a pilha como um **TAD** (assunto 0079):
o `pilha.h` diz **o que** a pilha faz e o `pilha.c` decide **como**. Quem usa
só inclui o `.h`:

```c
typedef struct pilha Pilha; // tipo opaco: os campos ficam no pilha.c

Pilha *pilha_cria(void);                     // pilha vazia (NULL se faltar memória)
void pilha_libera(Pilha *p);                 // devolve toda a memória da pilha
bool pilha_vazia(const Pilha *p);            // true se não tem nada
int pilha_tamanho(const Pilha *p);           // quantos itens tem
bool pilha_empilha(Pilha *p, int valor);     // push: false se não coube
bool pilha_desempilha(Pilha *p, int *valor); // pop: false se estava vazia
bool pilha_topo(const Pilha *p, int *valor); // peek: olha o topo sem tirar
```

Repare no `bool` de volta. O valor desempilhado vem pelo ponteiro, e o retorno
só diz se deu certo. Tirar de uma pilha vazia (**underflow**) é erro de lógica
de quem chamou. Empilhar numa pilha cheia (**overflow**) só acontece porque o
vetor tem tamanho fixo.

Por dentro, a versão deste assunto usa um **vetor** e um contador `n`. O fundo
fica em `itens[0]`, o topo em `itens[n - 1]`, e `n` é a próxima vaga. O trecho
que importa do [`pilha.c`](0087-pilha/pilha.c):

```c
struct pilha {
    int itens[CAPACIDADE]; // CAPACIDADE = 100
    int n;                 // quantos itens estão na pilha
};

bool pilha_empilha(Pilha *p, int valor) {
    if (p->n == CAPACIDADE) {
        return false; // cheia: estouro (overflow)
    }
    p->itens[p->n] = valor;
    p->n++;
    return true;
}

bool pilha_desempilha(Pilha *p, int *valor) {
    if (p->n == 0) {
        return false; // vazia: nada para tirar (underflow)
    }
    p->n--;
    *valor = p->itens[p->n]; // o valor continua no vetor, mas saiu da pilha
    return true;
}
```

Vamos ver na prática. Os três preços entram em centavos (2590, 800 e 1200),
um em cima do outro. No vetor, ocupam as gavetas 0, 1 e 2, e `n` vale 3. O
desfazer tira o 1200 do topo:

{{ideia}}

O programa do pedido. Ele não sabe que existe um vetor lá dentro: só conversa
com as funções do `pilha.h`:

```c
#include <stdio.h>
#include "pilha.h"

int main(void) {
    Pilha *pedido = pilha_cria();
    if (pedido == NULL) {
        return 1;
    }

    // preços em centavos: inteiro não tem erro de arredondamento
    pilha_empilha(pedido, 2590); // pizza: R$ 25,90
    pilha_empilha(pedido, 800);  // refrigerante: R$ 8,00
    pilha_empilha(pedido, 1200); // pudim: R$ 12,00

    int preco;
    if (pilha_desempilha(pedido, &preco)) { // "desfazer": sai o último que entrou
        printf("Desfeito: R$ %d,%02d\n", preco / 100, preco % 100);
    }
    if (pilha_topo(pedido, &preco)) { // só olha, não tira
        printf("Agora no topo: R$ %d,%02d\n", preco / 100, preco % 100);
    }
    printf("Itens no pedido: %d\n", pilha_tamanho(pedido));

    pilha_libera(pedido);
    return 0;
}
// Saída:
// Desfeito: R$ 12,00
// Agora no topo: R$ 8,00
// Itens no pedido: 2
```

Repara no fluxograma do desfazer: a primeira coisa é perguntar se a pilha está
vazia. Só depois `n` diminui e o valor é lido:

{{fluxograma}}

> [!WARNING]
> A ordem de `n--` e da leitura é o erro clássico. Se você lê `itens[n]` antes
> de diminuir `n`, pega a gaveta **vazia** logo acima do topo: lixo, ou um
> valor velho que já tinha saído. Fixe a convenção e não misture: aqui `n` é a
> próxima vaga (empilha em `itens[n]` e depois `n++`; desempilha com `n--` e
> depois lê). Muito livro usa `topo = -1` para pilha vazia, e aí o topo é
> `itens[topo]`. As duas funcionam. Misturar as duas não.

> [!TIP]
> **Por dentro do C:** desempilhar **não apaga** nada. O 1200 continua na
> gaveta 2; ele só deixou de fazer parte da pilha porque `n` voltou para 2. O
> próximo `push` escreve por cima. Por isso empilhar e desempilhar custam
> **O(1)**: uma conta e uma cópia, não importa se a pilha tem 3 ou 100 itens.
> E repare no tamanho: `sizeof(struct pilha)` dá 404 bytes (100 `int` de 4
> bytes, mais o `n`), alocados de uma vez pelo `malloc` no `pilha_cria`, mesmo
> com só 3 itens dentro. O vetor é a casa da pilha, não a pilha.

> [!NOTE]
> **Pergunta para você:** no A173, se o cliente tocar em "desfazer" mais três
> vezes seguidas, o que cada chamada de `pilha_desempilha` devolve? E o que
> fica em `preco` na última? Pense antes de testar.

{{pratique}}
