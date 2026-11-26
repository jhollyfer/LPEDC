## 0062 · Ponteiro para struct

Você passa o cartão do ônibus na catraca e o validador desconta R$ 4,40. Ele
mexe no saldo do cartão **de verdade**. Se descontasse numa cópia do cartão,
o seu saldo nunca baixaria e você andaria de graça para sempre. Quando uma
função precisa mudar uma struct, ela enfrenta esse mesmo problema.

Em C, todo parâmetro vai **por valor**, e com struct não é diferente: a
função recebe uma cópia de todos os bytes da struct, e o que ela muda fica na
cópia. A struct de quem chamou continua igual. Para a função alterar o
original, passe o **endereço** da struct, um ponteiro do tipo `Cartao *`
(DEITEL; DEITEL, 2011, cap. 10). A cópia agora é do endereço, e um endereço
copiado ainda aponta para o mesmo cartão.

Com o ponteiro `c` em mãos, você chega a um campo em dois passos. `*c` segue
o endereço e entrega a struct; `.saldo` escolhe o campo. Juntos, ficam
`(*c).saldo`. Os parênteses são obrigatórios porque o ponto tem prioridade
maior que o `*`. Sem eles, `*c.saldo` seria lido como `*(c.saldo)`, e `c` é
um ponteiro, que não tem campo nenhum: o compilador recusa (FEOFILOFF, 2009,
ap. E).

Como esse caso aparece o tempo todo, o C tem um atalho, a **seta** `->`.
`c->saldo` quer dizer exatamente o mesmo que `(*c).saldo`. A regra de uso
cabe numa frase: variável struct usa ponto (`cartao.saldo`); ponteiro para
struct usa seta (`c->saldo`) (BACKES, 2013, cap. 8). Se você errar, o
compilador avisa que o operando da seta não é ponteiro, ou que o do ponto
é.

O ponteiro também abre a porta do **heap**, a área de memória que você pede
com `malloc` e devolve com `free`, vista no módulo 07. `Cartao *c =
malloc(sizeof *c);` reserva um `Cartao` inteiro e guarda o endereço em `c`.
O `sizeof *c` mede o tipo para o qual `c` aponta; se um dia o tipo mudar, a
conta acompanha sozinha. Como em todo `malloc`, confira se voltou `NULL`
antes de usar e chame `free(c)` quando terminar (CELES; RANGEL, 2002).

A struct no heap resolve outro problema: o tempo de vida. Uma struct
declarada dentro de uma função é **local** e deixa de existir no `return`.
Devolver o endereço dela (`return &cartao;`) entrega um endereço de memória
que já foi liberada. Quem precisa sobreviver à função vai para o heap, ou é
devolvido por valor, como cópia.

Há ainda a questão do custo. Passar por valor copia a struct **a cada
chamada**. Um `Cartao` de 48 bytes pouco pesa, mas uma struct com
`double leituras[1000]` copia 8016 bytes toda vez, contra os 8 bytes de um
ponteiro. Por isso struct grande anda por ponteiro mesmo quando a função só
precisa ler. Nesse caso, escreva `const Cartao *c`: o `const` avisa a quem lê
que a função não altera nada, e faz o compilador barrar uma alteração por
engano (CELES; RANGEL, 2002).

> [!WARNING]
> `void recarregar(Cartao c, double v) { c.saldo += v; }` compila, roda e não
> faz nada: recarrega uma cópia. Passe `Cartao *c` e escreva `c->saldo += v`.
> Outros dois erros comuns: `*c.saldo` não compila (use `c->saldo`), e
> `return &cartao;` de uma struct local devolve um endereço que morre no
> `return`.

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
