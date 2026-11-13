## 0049 · Ponteiro para ponteiro

- **Ponteiro para ponteiro**: variável que guarda o endereço de um ponteiro.
  `int **pp;` lê-se "pp aponta para um `int *`" (BACKES, 2013, cap. 10).
- **Níveis**: com `int *p = &vagas; int **pp = &p;`, `*pp` é o próprio `p` e
  `**pp` é `vagas`. Cada `*` da declaração é um nível, e o acesso usa o mesmo
  número de `*` (BACKES, 2013, cap. 10).
- **Mudar o ponteiro de quem chamou**: para mudar um `int`, a função recebe
  `int *`; para mudar um `int *`, recebe `int **`. As listas do módulo 11 mudam
  o início assim (DEITEL; DEITEL, 2011, cap. 7).
- **Vetor de ponteiros**: o nome de `const char *dias[]` decai para
  `const char **`, o tipo do `char **argv` (assunto 0069) (KERNIGHAN; RITCHIE,
  1989, cap. 5).

> [!WARNING]
> Estrela a menos: `*pp = 38;` não muda `vagas`, guarda 38 **em `p`** como
> endereço, e o próximo `*p` derruba o programa. Para a função mudar o seu
> ponteiro, passe `&posto`, não `posto`.

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
