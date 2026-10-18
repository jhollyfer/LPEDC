## 0053 · Pilha e heap

Sexta à noite, restaurante cheio. O garçom anota o pedido da mesa 4 num
bloquinho, arranca a folha e prende a comanda no balcão da cozinha. O
bloquinho volta limpo para o bolso; a comanda fica lá até alguém pagar a conta
e jogá-la fora.

O seu programa faz a mesma coisa com a memória. Tem rascunho que dura só
enquanto uma função trabalha e tem coisa que precisa sobreviver a ela. Até
agora você só usou o primeiro tipo. Para o segundo, existe o **heap**.

Quando o programa roda, o sistema operacional entrega a ele uma faixa de
endereços dividida em quatro regiões:

| Região | O que guarda | Quem cria e quem apaga | Dura |
| --- | --- | --- | --- |
| **código** | as instruções e os literais (`"bom dia"`) | o compilador | o programa todo, só leitura |
| **dados** | globais e `static` | o compilador | o programa todo |
| **heap** | blocos pedidos com `malloc` | **você** pede e **você** devolve | até o `free` |
| **pilha** | locais e parâmetros (os frames) | a chamada e o `return` | enquanto a função roda |

A **pilha** (*stack*) você já conhece do assunto 0031: cada chamada empilha um
**frame** com as locais, cada `return` desempilha. É automática e rapidíssima,
mas tem duas limitações. A primeira: o frame some no `return`, então nada que
mora nele sobrevive à função. A segunda: ela é pequena. No Linux, o padrão é
8 MiB (`ulimit -s` mostra `8192`, em KiB).

O **heap** é um depósito grande, do tamanho da memória livre da máquina. Você
pede um bloco de N bytes, recebe o **endereço** dele e usa como vetor. O bloco
não pertence a função nenhuma: fica vivo até você devolvê-lo com `free`. Por
isso dá para criar numa função e usar em outra.

No C não existe coletor de lixo (*garbage collector*), um mecanismo que apaga
sozinho o que ninguém mais usa. Você é o coletor: tudo o que pegou do heap, devolve.

Vamos ver na prática. A função `abrir_comanda` monta a comanda da mesa 4 com
três itens (R$ 18, R$ 25 e R$ 7). A variável `itens` mora no frame dela, na
pilha. Os três valores vão para um bloco no heap. O contador `pedidos_do_dia`
mora nos dados. Quando a função retorna, o frame dela some, mas o bloco
continua lá, e `main` guarda o endereço dele:

{{ideia}}

O `malloc` e o `free` ganham um assunto só deles (0054). Aqui, repare só em
onde cada coisa mora e em quanto tempo ela vive:

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

Repara no fluxograma: o frame de `abrir_comanda` nasce e morre no meio do
caminho, mas o bloco do heap atravessa o `return` e só termina no `free`, lá
no fim de `main`:

{{fluxograma}}

> [!WARNING]
> Nunca devolva o endereço de uma variável local. `char senha[8]; ... return
> senha;` devolve um endereço que deixa de valer no exato momento do `return`:
> o próximo frame vai escrever por cima. O gcc avisa (`function returns address
> of local variable`) e, de propósito, devolve `NULL` no lugar. As saídas são
> três: quem chama empresta o vetor (parâmetro), a variável vira `static` ou o
> bloco vem do heap.

> [!TIP]
> **Por dentro do C:** reservar espaço na pilha custa **uma instrução**: o
> processador só diminui o registrador que marca o topo (`sub rsp, 32`). Por
> isso locais são de graça. O `malloc` precisa procurar um pedaço livre do
> tamanho certo numa lista de blocos e anotar o tamanho num cabeçalho
> escondido logo antes do endereço que ele te entrega. É bem mais caro. Rode
> `size` no executável (`gcc A105.c -o comanda && size comanda`) e veja as
> colunas `text` (código), `data` (globais com valor) e `bss` (globais
> zeradas). Heap e pilha não aparecem: eles só existem quando o programa roda.

> [!NOTE]
> **Pergunta para você:** um vetor local `int leituras[5000000];` (20 MB)
> funciona? E se ele for global? Pense no tamanho de cada região antes de
> testar.

{{pratique}}
