## 0053 · Pilha e heap

- **Regiões da memória**: o programa recebe uma faixa de endereços dividida em
  código, dados, heap e pilha. Cada região tem um dono e um tempo de vida
  próprios (CELES; RANGEL, 2002).
- **Pilha** (*stack*): cada chamada empilha um **frame** com as locais e os
  parâmetros; o `return` o desempilha (assunto 0031). É automática, rápida e
  pequena: no Linux, 8 MiB (`ulimit -s` mostra `8192`, em KiB) (CELES; RANGEL, 2002).
- **Heap**: depósito do tamanho da memória livre. Você pede um bloco de N bytes
  em tempo de execução e recebe o **endereço** dele. O bloco não pertence a
  função nenhuma e vive até o `free` (BACKES, 2013, cap. 11).
- **Estática, automática e dinâmica**: os nomes dos livros para a alocação nos
  dados (tamanho fixo desde a compilação), na pilha e no heap
  (CELES; RANGEL, 2002).
- **Sem coletor de lixo**: o C não apaga sozinho o que ninguém usa. Tudo o que
  sai do heap volta com `free` (FEOFILOFF, 2009, ap. F).

| Região | O que guarda | Quem cria e quem apaga | Dura |
| --- | --- | --- | --- |
| **código** | as instruções e os literais (`"bom dia"`) | o compilador | o programa todo, só leitura |
| **dados** | globais e `static` | o compilador | o programa todo |
| **heap** | blocos pedidos com `malloc` | **você** pede e **você** devolve | até o `free` |
| **pilha** | locais e parâmetros (os frames) | a chamada e o `return` | enquanto a função roda |

> [!WARNING]
> Nunca devolva o endereço de uma variável local: `char senha[8]; ... return senha;`
> aponta para um frame que já morreu. O gcc avisa e devolve `NULL` no lugar.
> Saídas: quem chama empresta o vetor, a variável vira `static` ou o bloco vem do heap.

{{exemplo}}

A função `abrir_comanda` monta a comanda da mesa 4 com três itens (R$ 18, 25
e 7). A variável `itens` mora na pilha, os valores vão para um bloco no heap e
o contador `pedidos_do_dia` mora nos dados:

{{ideia}}

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

O frame de `abrir_comanda` nasce e morre no meio do caminho; o bloco do heap
atravessa o `return` e só termina no `free`:

{{fluxograma}}
