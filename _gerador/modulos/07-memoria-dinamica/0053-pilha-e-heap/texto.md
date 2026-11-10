## 0053 · Pilha e heap

Sexta à noite, restaurante cheio. O garçom anota o pedido da mesa 4 num
bloquinho, arranca a folha e prende a comanda no balcão da cozinha. O
bloquinho volta limpo para o bolso; a comanda fica lá até alguém pagar a conta
e jogá-la fora.

O seu programa faz o mesmo com a memória. Tem rascunho que dura só enquanto
uma função trabalha e tem coisa que precisa sobreviver a ela. Até agora você
só usou o primeiro tipo. Para o segundo, existe o **heap**.

O sistema operacional entrega ao programa uma faixa de endereços dividida em
quatro regiões:

| Região | O que guarda | Quem cria e quem apaga | Dura |
| --- | --- | --- | --- |
| **código** | as instruções e os literais (`"bom dia"`) | o compilador | o programa todo, só leitura |
| **dados** | globais e `static` | o compilador | o programa todo |
| **heap** | blocos pedidos com `malloc` | **você** pede e **você** devolve | até o `free` |
| **pilha** | locais e parâmetros (os frames) | a chamada e o `return` | enquanto a função roda |

A **pilha** (*stack*), do assunto 0031, empilha um **frame** com as locais a
cada chamada e o desempilha no `return`. É automática e rápida, mas tem duas
limitações: o frame some no `return`, então nada que mora nele sobrevive à
função; e ela é pequena (no Linux, 8 MiB: `ulimit -s` mostra `8192`, em KiB).

O **heap** é um depósito do tamanho da memória livre da máquina. Você pede um
bloco de N bytes, recebe o **endereço** dele e usa como vetor. O bloco não
pertence a função nenhuma: fica vivo até o `free`. Por isso dá para criar
numa função e usar em outra.

Os livros chamam as regiões de alocação **estática** (dados: tamanho e
endereço fixos desde a compilação), **automática** (pilha) e **dinâmica**
(heap).

O C não tem coletor de lixo (*garbage collector*, que apaga sozinho o que
ninguém mais usa). Tudo o que você pega do heap, você devolve.

A função `abrir_comanda` monta a comanda da mesa 4 com três itens (R$ 18,
R$ 25 e R$ 7). A variável `itens` mora no frame dela, na pilha. Os três
valores vão para um bloco no heap. O contador `pedidos_do_dia` mora nos dados.
Quando a função retorna, o frame some, mas o bloco continua lá e `main` guarda
o endereço dele:

{{ideia}}

O `malloc` e o `free` têm assunto próprio (0054). Aqui, observe em que região
cada coisa mora e quanto tempo vive:

```c
#include <stdio.h>
#include <stdlib.h>

int pedidos_do_dia = 0; // DADOS: existe do começo ao fim do programa

int *abrir_comanda(int mesa) {
    int itens = 3; // PILHA: some quando a função retorna
    int *comanda = malloc(itens * sizeof(int)); // o bloco fica no HEAP
    if (comanda == NULL) {
        return NULL;
    }
    comanda[0] = 18; // suco
    comanda[1] = 25; // prato feito
    comanda[2] = 7;  // pudim
    pedidos_do_dia++;
    printf("Mesa %d: comanda com %d itens\n", mesa, itens);
    return comanda; // o endereço volta; o bloco continua vivo no heap
}

int main(void) {
    int *comanda = abrir_comanda(4); // PILHA: o ponteiro mora no frame de main
    if (comanda == NULL) {
        printf("Sem memória\n");
        return 1;
    }
    int total = comanda[0] + comanda[1] + comanda[2];
    printf("Total: R$ %d\n", total);
    printf("Pedidos do dia: %d\n", pedidos_do_dia);
    free(comanda); // devolve o bloco ao heap
    return 0;
}
// Saída:
// Mesa 4: comanda com 3 itens
// Total: R$ 50
// Pedidos do dia: 1
```

O frame de `abrir_comanda` nasce e morre no meio do caminho, mas o bloco do
heap atravessa o `return` e só termina no `free`, no fim de `main`:

{{fluxograma}}

> [!WARNING]
> Nunca devolva o endereço de uma variável local. `char senha[8]; ... return
> senha;` devolve um endereço que deixa de valer no `return`. O gcc avisa
> (`function returns address of local variable`) e devolve `NULL` no lugar.
> Saídas: quem chama empresta o vetor (parâmetro), a variável vira `static`
> ou o bloco vem do heap.

> [!NOTE]
> **Pergunta para você:** um vetor local `int leituras[5000000];` (20 MB)
> funciona? E se ele for global? Pense no tamanho de cada região antes de
> testar.

{{pratique}}
