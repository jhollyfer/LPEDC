## 0049 · Ponteiro para ponteiro

Você pergunta ao porteiro onde fica o salão de festas. Ele aponta para o
quadro de avisos, onde o mapa do condomínio mostra o salão. Você chegou em
**dois saltos**: porteiro, quadro, salão.

Um ponteiro é uma variável comum: mora numa gaveta e tem endereço (assunto
0045). Dá para guardar **o endereço de um ponteiro** em outra variável, um
**ponteiro para ponteiro**, declarado com dois asteriscos: `int **pp;` lê-se
"pp aponta para um `int *`".

Com `int vagas = 40; int *p = &vagas; int **pp = &p;`:

- `pp` guarda o endereço de `p`;
- `*pp` é o próprio `p`: o endereço de `vagas`;
- `**pp` é `vagas`: 40. Dois saltos, dois asteriscos.

Conte as estrelas: cada `*` na declaração é um nível, e para chegar ao dado
usa-se o mesmo número de `*`. Acima de dois níveis o código vira charada.

Dois usos aparecem no curso todo:

- **mudar o ponteiro de quem chamou.** Para mudar um `int` do `main`, a função
  recebe `int *` (assunto 0046); para mudar um `int *` do `main`, fazendo-o
  apontar para outro lugar, recebe `int **`. É a mesma regra, um nível acima. O
  A098 escolhe o posto mais barato assim, e as listas encadeadas do módulo 11
  mudam o início da lista assim;
- **vetor de ponteiros.** `const char *dias[]` (assunto 0048) é um vetor de
  `const char *`; o nome dele decai para um `const char **`. É o tipo do
  `char **argv` (assunto 0069) e da matriz alocada no módulo 07.

O estacionamento do shopping tem 40 vagas. `p` aponta para `vagas` e `pp`
aponta para `p`. Quando entram 2 carros, o programa atualiza `vagas` sem citar
o nome dela, em dois saltos:

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

Leia os pares: `&vagas` e `p` são iguais; `&p` e `pp` são iguais; `*pp` volta a
ser o endereço de `vagas`.

Não há decisão. Primeiro a corrente é montada, elo por elo (`vagas`, `p`,
`pp`); depois o `**pp` a percorre de volta até `vagas`:

{{fluxograma}}

> [!WARNING]
> Estrela a menos é o erro clássico. `*pp = 38;` não muda `vagas`: guarda o
> número 38 **em `p`**, como endereço (o compilador avisa: `assignment to 'int
> *' from 'int' makes pointer from integer`), e o próximo `*p` derruba o
> programa. Na função, para mudar o seu ponteiro, passe `&posto` (um
> `double **`); passar `posto` entrega uma cópia, como no `troca_copias` do
> assunto 0046.

> [!TIP]
> **Por dentro do C:** cada nível é uma variável de 8 bytes. Ler `**pp` são
> três leituras de memória em sequência, cada uma dependendo da anterior. Por
> isso estruturas cheias de ponteiros (listas, árvores) percorrem mais devagar
> que um vetor contíguo, tema do módulo 10.

> [!NOTE]
> **Pergunta para você:** com `int outra = 5;`, o que muda depois de
> `*pp = &outra;`? Quanto valem `vagas`, `*p` e `**pp`?

{{pratique}}
