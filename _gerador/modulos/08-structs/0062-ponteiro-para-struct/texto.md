## 0062 · Ponteiro para struct

Você passa o cartão do ônibus na catraca e o validador desconta R$ 4,40. Ele
mexe no saldo do cartão **de verdade**, não de uma cópia. Se descontasse numa
cópia, você andaria de graça para sempre.

Com struct em função vale o mesmo. Como todo parâmetro em C, a struct vai
**por valor**: a função recebe uma cópia de todos os bytes, e mudar a cópia
não muda o original. Para a função alterar a struct de quem chamou, passe o
**endereço** dela: um `Cartao *`.

Com um ponteiro `c` para struct, o campo se acessa assim: `(*c).saldo`.
Primeiro `*c` chega à struct, depois `.saldo` ao campo. Os parênteses são
obrigatórios: o ponto tem prioridade maior que o `*`, e `*c.saldo` seria
`*(c.saldo)`, mas `c` é ponteiro e não tem campo.

O atalho é a **seta** `->`: `c->saldo` é igual a `(*c).saldo`. Variável struct
usa ponto (`cartao.saldo`); ponteiro para struct usa seta (`c->saldo`).

O ponteiro também leva a struct para o **heap**. `malloc(sizeof *c)` reserva
um `Cartao` inteiro e devolve o endereço; `sizeof *c` mede o tipo apontado e
acompanha mudanças. Como todo `malloc`, confira o `NULL` e termine com `free`.

O cartão da Luana mora no heap com R$ 10,00. A variável `c` no `main` guarda
só o endereço dele, e `cobrar_passagem` recebe uma cópia desse **endereço**,
não do cartão. As duas setas apontam para o mesmo lugar:

{{ideia}}

São três passagens seguidas, e a terceira não passa:

```c
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TARIFA 4.40

typedef struct {
    char titular[30];
    double saldo;
    int viagens;
} Cartao;

// recebe o ENDEREÇO do cartão: mexe no original, não numa cópia
bool cobrar_passagem(Cartao *c) {
    if (c->saldo < TARIFA) { // c->saldo é o mesmo que (*c).saldo
        return false;
    }
    c->saldo -= TARIFA;
    c->viagens++;
    return true;
}

int main(void) {
    Cartao *c = malloc(sizeof *c); // um Cartao inteiro no heap
    if (c == NULL) {
        return 1;
    }
    strcpy(c->titular, "Luana");
    c->saldo = 10.00;
    c->viagens = 0;

    for (int i = 1; i <= 3; i++) {
        if (cobrar_passagem(c)) {
            printf("Viagem %d: liberada, saldo R$ %.2f\n", i, c->saldo);
        } else {
            printf("Viagem %d: saldo insuficiente (R$ %.2f)\n", i, c->saldo);
        }
    }
    printf("%s fez %d viagens\n", c->titular, c->viagens);

    free(c);
    return 0;
}
// Saída:
// Viagem 1: liberada, saldo R$ 5.60
// Viagem 2: liberada, saldo R$ 1.20
// Viagem 3: saldo insuficiente (R$ 1.20)
// Luana fez 2 viagens
```

### Passo a passo

O teste de mesa das três chamadas, olhando o cartão no heap:

| Chamada | saldo antes | saldo < 4.40? | saldo depois | viagens |
| --- | --- | --- | --- | --- |
| 1ª | 10.00 | não | 5.60 | 1 |
| 2ª | 5.60 | não | 1.20 | 2 |
| 3ª | 1.20 | sim: devolve false | 1.20 | 2 |

A pergunta do saldo fica na função, mas o laço das três chamadas é do `main`.
Como a função mexe no original, cada volta enxerga o saldo da anterior:

{{fluxograma}}

> [!WARNING]
> Struct vai por valor. `void recarregar(Cartao c, double v) { c.saldo += v; }`
> compila, roda e não faz nada: recarrega uma cópia. Passe `Cartao *c`. Outros
> erros: `*c.saldo` não compila (use `c->saldo`) e `return &cartao;` de uma
> struct local devolve endereço que morre no `return` (use `malloc` ou devolva
> a struct por valor).

> [!TIP]
> Passar por valor copia a struct **a cada chamada**. Um `Cartao` tem 48 bytes,
> tanto faz; uma struct com `double leituras[1000]` copia 8016 bytes (A124),
> contra 8 do ponteiro. Struct grande anda por ponteiro, e `const Cartao *c`
> deixa claro que a função só lê e faz o compilador barrar alterações.

> [!NOTE]
> **Pergunta para você:** se `cobrar_passagem` recebesse `Cartao c` (sem o
> `*`) e o `main` passasse `*c`, o que a saída mostraria nas três viagens? E
> quantas viagens a Luana teria feito no fim?

{{pratique}}
