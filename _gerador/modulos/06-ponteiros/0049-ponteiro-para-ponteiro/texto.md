## 0049 · Ponteiro para ponteiro

Você pergunta ao porteiro onde fica o salão de festas. Ele não leva você até
lá; aponta para o quadro de avisos, e o mapa do quadro mostra o salão. Você
chegou em **dois saltos**: porteiro, quadro, salão. Em C há situações em que
é preciso andar assim, guardando não o endereço do dado, mas o endereço de
quem guarda esse endereço.

Um ponteiro é uma variável como outra qualquer: mora numa gaveta e tem
endereço próprio (assunto 0045). Então dá para guardar **o endereço de um
ponteiro** em outra variável. Essa variável é um **ponteiro para ponteiro**,
e se declara com dois asteriscos: `int **pp;` lê-se "pp aponta para um
`int *`" (BACKES, 2013, cap. 10).

Veja os níveis num exemplo. Com `int vagas = 40; int *p = &vagas; int **pp =
&p;`, a variável `pp` guarda o endereço de `p`. Um salto, `*pp`, leva ao
próprio `p`, que guarda o endereço de `vagas`. Dois saltos, `**pp`, chegam a
`vagas`, que vale 40. A regra é contar as estrelas: cada `*` da declaração é
um nível, e para chegar ao dado você usa o mesmo número de `*` (BACKES,
2013, cap. 10). Acima de dois níveis o código vira charada, e quase nunca é
necessário.

```c
int vagas = 40;
int *p = &vagas;
int **pp = &p;
**pp = **pp - 2;        // dois saltos: chega a vagas
printf("%d\n", vagas);  // 38
```

Para que serve isso? O primeiro uso é **mudar o ponteiro de quem chamou**. No
assunto 0046, para uma função mudar um `int` do `main`, ela recebia um
`int *`. Se a função precisa mudar um `int *` do `main`, fazendo-o apontar
para outro lugar, ela recebe um `int **`. É a mesma regra, um nível acima: a
função recebe o endereço daquilo que vai mudar (DEITEL; DEITEL, 2011,
cap. 7). O A098 escolhe o posto de combustível mais barato assim, e as listas
encadeadas do módulo 11 trocam o início da lista do mesmo jeito.

O segundo uso é o **vetor de ponteiros**. `const char *dias[]` (assunto 0048)
é um vetor cujos itens são `const char *`. Pela regra do decaimento (assunto
0047), o nome do vetor vira o endereço do primeiro item, que é um ponteiro;
o resultado é um `const char **`. É o tipo do `char **argv`, que o `main`
recebe com os argumentos da linha de comando (assunto 0069), e da matriz
alocada no módulo 07 (KERNIGHAN; RITCHIE, 1989, cap. 5).

Cada nível tem um custo. Cada ponteiro é uma variável de 8 bytes, e ler
`**pp` são três leituras de memória em sequência, cada uma esperando a
anterior para saber aonde ir. Por isso estruturas cheias de ponteiros, como
listas e árvores, costumam ser percorridas mais devagar que um vetor com os
itens colados, tema do módulo 10.

> [!WARNING]
> Estrela a menos: `*pp = 38;` não muda `vagas`; guarda o número 38 **em
> `p`**, como se fosse endereço, e o próximo `*p` derruba o programa. O
> compilador avisa. Para a função mudar o seu ponteiro, passe `&posto`, não
> `posto`: sem o `&`, ela recebe uma cópia.

{{exemplo}}

O estacionamento do shopping tem 40 vagas. `p` aponta para `vagas` e `pp` para
`p`; quando entram 2 carros, o programa atualiza `vagas` em dois saltos:

{{ideia}}

```c
#include <stdio.h>

int main(void) {
    int vagas = 40;      // vagas livres no estacionamento do shopping
    int *p = &vagas;     // p guarda o endereço de vagas
    int **pp = &p;       // pp guarda o endereço de p

    printf("&vagas = %p\n", (void *)&vagas);
    printf("p      = %p   (o endereço de vagas)\n", (void *)p);
    printf("&p     = %p\n", (void *)&p);
    printf("pp     = %p   (o endereço de p)\n", (void *)pp);
    printf("*pp    = %p   (o que tem em p)\n", (void *)*pp);
    printf("**pp   = %d\n", **pp);

    **pp = **pp - 2;     // entraram 2 carros: muda vagas em dois saltos
    printf("vagas  = %d\n", vagas);
    return 0;
}
// Saída (os endereços mudam a cada execução):
// &vagas = 0x7fe808c00030
// p      = 0x7fe808c00030   (o endereço de vagas)
// &p     = 0x7fe808c00040
// pp     = 0x7fe808c00040   (o endereço de p)
// *pp    = 0x7fe808c00030   (o que tem em p)
// **pp   = 40
// vagas  = 38
```

`&vagas` e `p` são iguais; `&p` e `pp` também. Primeiro a corrente é montada,
elo por elo; depois `**pp` a percorre até `vagas`:

{{fluxograma}}
