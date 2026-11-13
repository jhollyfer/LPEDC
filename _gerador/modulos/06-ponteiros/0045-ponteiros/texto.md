## 0045 · Ponteiros

- **Ponteiro**: variável que guarda um **endereço**. Ele também mora numa
  gaveta, mas guarda o número de **outra**. Ziviani e a tradução do K&R dizem
  **apontador** (ZIVIANI, 2010).
- **Declaração**: `int *cartao;` lê-se "ponteiro para int". O tipo diz o que
  mora lá e quantos bytes ler (DEITEL; DEITEL, 2011, cap. 7).
- **`&` e `*`**: `&x` dá o endereço; `*p` vai ao endereço guardado e lê ou
  escreve lá, que é **desreferenciar** (KERNIGHAN; RITCHIE, 1989, cap. 5).
- **Três papéis do `*`**: multiplicação (`a * b`), declaração (`int *p`) e
  desreferência (`*p = 5`) (BACKES, 2013, cap. 10).
- **`NULL`**: endereço que quer dizer "lugar nenhum". Teste
  `if (p != NULL)` antes de usar; desreferenciá-lo derruba o programa
  (*segmentation fault*) (DEITEL; DEITEL, 2011, cap. 7).
- **Tamanho**: todo ponteiro de dado tem 8 bytes em 64 bits; o tipo muda só a
  leitura (BACKES, 2013, cap. 10).

> [!WARNING]
> `int *p;` sem valor guarda **lixo**, e `*p = 10;` escreve numa gaveta
> desconhecida. Inicialize com um endereço ou `NULL`. E em `int *a, b;` só `a`
> é ponteiro.

{{exemplo}}

No caixa da farmácia, o cliente tem 120 pontos. O ponteiro `cartao` começa em
`NULL`, recebe `&pontos`, e a compra soma 30 **por meio do ponteiro**:

{{ideia}}

```c
#include <stdio.h>

int main(void) {
    int pontos = 120;     // pontos do cartão fidelidade
    int *cartao = NULL;   // ponteiro para int; NULL: ainda não aponta para nada

    cartao = &pontos;     // o cliente passou o cartão: cartao guarda &pontos

    printf("&pontos = %p\n", (void *)&pontos);
    printf("cartao  = %p\n", (void *)cartao); // o mesmo endereço
    printf("*cartao = %d\n", *cartao);        // o que tem na gaveta apontada

    if (cartao != NULL) {
        *cartao = *cartao + 30; // compra de R$ 30: muda pontos ATRAVÉS do ponteiro
    } else {
        printf("Compra sem cartão\n");
    }
    printf("pontos  = %d\n", pontos);
    printf("&cartao = %p\n", (void *)&cartao); // o ponteiro também mora numa gaveta
    return 0;
}
// Saída (os endereços mudam a cada execução):
// &pontos = 0x7f631f200030
// cartao  = 0x7f631f200030
// *cartao = 120
// pontos  = 150
// &cartao = 0x7f631f200040
```

`cartao` é o endereço guardado, `*cartao` o valor lá dentro e `&cartao` onde o
próprio ponteiro mora. Antes de desreferenciar, o teste contra `NULL`:

{{fluxograma}}
