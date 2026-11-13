## 0062 · Ponteiro para struct

- **Struct vai por valor**: a função recebe uma cópia de todos os bytes, e
  mudar a cópia não muda o original. Para alterar, passe o **endereço**
  (DEITEL; DEITEL, 2011, cap. 10).
- **`(*c).saldo`**: `*c` chega à struct e `.saldo` ao campo. Os parênteses são
  obrigatórios: o ponto tem prioridade, e `*c.saldo` vira `*(c.saldo)`
  (FEOFILOFF, 2009, ap. E).
- **Seta** `->`: `c->saldo` é o mesmo que `(*c).saldo`. Variável struct usa
  ponto; ponteiro para struct usa seta (BACKES, 2013, cap. 8).
- **Struct no heap**: `malloc(sizeof *c)` reserva a struct inteira. Confira o
  `NULL` e termine com `free` (CELES; RANGEL, 2002).
- **Struct grande anda por ponteiro**: por valor, uma struct com
  `double leituras[1000]` copia 8016 bytes a cada chamada, contra 8 do
  ponteiro. `const Cartao *c` diz que a função só lê (CELES; RANGEL, 2002).

> [!WARNING]
> `void recarregar(Cartao c, double v) { c.saldo += v; }` compila, roda e não
> faz nada: recarrega uma cópia. Passe `Cartao *c`. E `return &cartao;` de uma
> struct local devolve endereço que morre no `return`.

{{exemplo}}

O cartão de ônibus da Luana mora no heap com R$ 10,00, e cada passagem custa
R$ 4,40. `cobrar_passagem` recebe uma cópia do **endereço**, não do cartão: as
duas setas apontam para o mesmo lugar:

{{ideia}}

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
Cada volta enxerga o saldo da anterior:

{{fluxograma}}
