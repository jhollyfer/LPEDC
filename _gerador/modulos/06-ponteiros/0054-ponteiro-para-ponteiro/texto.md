## 0054 · Ponteiro para ponteiro

Você pergunta ao porteiro onde fica o salão de festas. Ele não sabe, mas
aponta para um quadro de avisos: "o mapa do condomínio está no quadro". No
quadro, o mapa mostra o salão. Você chegou lá em **dois saltos**: porteiro →
quadro → salão.

Um ponteiro é uma variável como outra qualquer: mora numa gaveta e tem
endereço (assunto 0050). Então dá para guardar **o endereço de um
ponteiro** em outra variável. Ela é um **ponteiro para ponteiro**, declarado
com dois asteriscos: `int **pp;` se lê "pp aponta para um `int *`".

Com `int vagas = 40; int *p = &vagas; int **pp = &p;`:

- `pp` guarda o endereço de `p`;
- `*pp` é o próprio `p`, ou seja, o endereço de `vagas`;
- `**pp` é `vagas`: 40. Dois saltos, dois asteriscos.

A regra é contar estrelas: cada `*` na declaração é um nível, e para chegar
no dado você usa o mesmo número de `*`. Dá para fazer `int ***`, mas acima
de dois níveis o código vira charada. Evite.

Para que serve, além de quebra-cabeça? Dois usos que você vai ver o curso
todo:

- **mudar o ponteiro de quem chamou.** Se uma função precisa mudar um `int`
  do `main`, ela recebe `int *` (assunto 0051). Se precisa mudar um `int *`
  do `main`, fazer ele apontar para outro lugar, recebe `int **`. É a mesma
  regra, um nível acima. O A108 escolhe o posto mais barato assim, e as
  listas encadeadas do módulo 11 usam isso para mudar o início da lista;
- **vetor de ponteiros.** `const char *dias[]` (assunto 0053) é um vetor
  cujos elementos são `const char *`. O nome dele decai para o endereço do
  primeiro elemento: um `const char **`. É o tipo do famoso `char **argv`
  (assunto 0074) e da matriz alocada no módulo 07.

Vamos ver na prática. No estacionamento do shopping há 40 vagas. `p` aponta
para `vagas` e `pp` aponta para `p`. Quando entram 2 carros, o programa
atualiza `vagas` sem citar o nome dela, em dois saltos:

{{ideia}}

O programa mostra cada nível e confere quem é igual a quem:

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

Leia os pares: `&vagas` e `p` são iguais; `&p` e `pp` são iguais; `*pp` volta
a ser o endereço de `vagas`.

Repara no fluxograma: não há decisão. Primeiro a corrente é montada, elo
por elo (`vagas`, depois `p`, depois `pp`); depois o `**pp` percorre a
corrente de volta até chegar em `vagas`:

{{fluxograma}}

> [!WARNING]
> Estrela a menos é o erro clássico. `*pp = 38;` não muda `vagas`: tenta
> guardar o número 38 **em `p`**, como se fosse um endereço (o compilador
> avisa: `assignment to 'int *' from 'int' makes pointer from integer`).
> Depois disso, `p` aponta para a "gaveta 38" e o próximo `*p` derruba o
> programa. E na função: se ela precisa mudar o seu ponteiro, passe `&posto`
> (um `double **`). Passar `posto` entrega uma cópia, e a função muda só a
> cópia, como o `troca_copias` do assunto 0051.

> [!TIP]
> **Por dentro do C:** cada nível é uma variável de 8 bytes de verdade. Ler
> `**pp` custa duas leituras de memória em sequência: a primeira busca o que
> tem em `pp` (o endereço de `p`), a segunda busca o que tem em `p` (o
> endereço de `vagas`), e só então a terceira traz o 40. O processador não
> consegue adiantar a segunda antes de terminar a primeira. É por isso que
> estruturas cheias de ponteiros (listas, árvores) são mais lentas de
> percorrer que um vetor contíguo, assunto que volta no módulo 10.

> [!NOTE]
> **Pergunta para você:** com `int outra = 5;`, o que muda depois de
> `*pp = &outra;`? Quanto valem `vagas`, `*p` e `**pp`?

{{pratique}}
