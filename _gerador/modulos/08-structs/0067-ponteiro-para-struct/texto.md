## 0067 · Ponteiro para struct

Você passa o cartão do ônibus na catraca e o validador desconta R$ 4,40. Ele
não faz uma cópia do seu cartão para descontar dela: mexe no saldo do cartão
**de verdade**. Se descontasse numa cópia, você andaria de graça para sempre.

Com struct em função acontece a mesma coisa. Como qualquer parâmetro em C, uma
struct vai **por valor**: a função recebe uma cópia de todos os bytes. Mudar a
cópia não muda o original. Para a função alterar a struct de quem chamou, você
passa o **endereço** dela: um `Cartao *`.

Com um ponteiro `c` para struct, o campo se acessa assim: `(*c).saldo`.
Primeiro `*c` chega na struct, depois `.saldo` chega no campo. Os parênteses
são obrigatórios, porque o ponto tem prioridade maior que o `*`: `*c.saldo`
significaria `*(c.saldo)`, e `c` não tem campo nenhum, é um ponteiro.

Como isso é escrito o tempo todo, o C tem um atalho: a **seta** `->`.
`c->saldo` é exatamente `(*c).saldo`. A regra prática: variável struct usa
ponto (`cartao.saldo`); ponteiro para struct usa seta (`c->saldo`).

O ponteiro também é o caminho para struct no **heap**. `malloc(sizeof *c)`
reserva o espaço de um `Cartao` inteiro e devolve o endereço. O `sizeof *c`
mede o tipo apontado: se um dia o tipo de `c` mudar, a conta acompanha. E,
como todo `malloc`, confira o `NULL` e termine com `free`.

Vamos ver na prática. O cartão da Luana mora no heap com R$ 10,00. A variável
`c` no `main` guarda só o endereço dele, e a função `cobrar_passagem` recebe
uma cópia desse **endereço**, não do cartão. As duas setas apontam para o
mesmo lugar:

{{ideia}}

Três passagens seguidas. A terceira não passa:

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

Repara no fluxograma: a pergunta do saldo fica dentro da função, mas o laço
que chama três vezes é do `main`. Como a função mexe no original, cada volta
do laço enxerga o saldo que a anterior deixou:

{{fluxograma}}

> [!WARNING]
> O erro mais comum é esquecer que struct vai por valor. Uma função
> `void recarregar(Cartao c, double v) { c.saldo += v; }` compila, roda e não
> faz nada: recarrega uma cópia que morre no fim da função. Quem vem do JS
> estranha, porque lá objeto passado para função é alterado. O segundo erro é
> a precedência: `*c.saldo` não compila. Escreva `c->saldo` ou `(*c).saldo`.
> E nunca devolva o endereço de uma struct local (`return &cartao;`): ela morre
> quando a função termina. Para criar uma struct dentro de uma função e
> devolvê-la, use `malloc` (ou devolva a struct por valor).

> [!TIP]
> **Por dentro do C:** passar por valor custa uma cópia do tamanho da struct
> **a cada chamada**. Um `Cartao` tem 48 bytes, então tanto faz. Mas uma struct
> com `double leituras[1000]` tem mais de 8 KB, e o exemplo A134 mostra o
> `sizeof` dentro da função: 8016 bytes copiados na pilha a cada chamada,
> contra 8 bytes do ponteiro. Por isso, em C, struct grande quase sempre anda
> por ponteiro, mesmo quando a função só lê. Para deixar claro que ela só lê,
> e para o compilador barrar uma alteração por engano, use `const Cartao *c`.

> [!NOTE]
> **Pergunta para você:** se `cobrar_passagem` recebesse `Cartao c` (sem o
> `*`) e o `main` passasse `*c`, o que a saída mostraria nas três viagens? E
> quantas viagens a Luana teria feito no fim?

{{pratique}}
