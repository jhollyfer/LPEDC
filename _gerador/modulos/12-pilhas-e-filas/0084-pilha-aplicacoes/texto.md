## 0084 · Pilha na prática: parênteses e notação pós-fixa

Você esquece de fechar um colchete no VS Code e o editor sublinha o lugar
certo. Ele não conta parênteses: usa uma pilha.

Com um só tipo de parêntese, um contador resolve: soma 1 no `(`, tira 1 no
`)` e termina em zero. Com três tipos (`()`, `[]`, `{}`) ele falha: em
`( [ ) ]` as contas fecham, mas o `)` chegou quando quem esperava era o `[`.

A regra: **todo fechamento casa com a abertura mais recente ainda pendente**,
ou seja, o topo de uma pilha. O algoritmo:

1. abriu (`(`, `[` ou `{`): **empilha**;
2. fechou: **desempilha** e confere o par. Pilha vazia ou par errado: erro;
3. qualquer outro caractere: ignora;
4. acabou a string: a pilha tem que estar **vazia**; se sobrou abertura,
   faltou fechar.

Em `{ x = v[(i + 1)] }` sobram os delimitadores `{ [ ( ) ] }`. Os três
primeiros são empilhados. O `)` encontra `(` no topo e casa; depois `]` casa
com `[` e `}` casa com `{`:

{{ideia}}

O verificador testa quatro expressões, com o `pilha.h` e o `pilha.c` do 0083:

```c
#include <stdbool.h>
#include <stdio.h>
#include "pilha.h"

// a abertura que combina com cada fechamento
char abertura_de(char fecha) {
    if (fecha == ')') {
        return '(';
    }
    if (fecha == ']') {
        return '[';
    }
    return '{';
}

bool balanceada(const char *s) {
    Pilha *p = pilha_cria();
    if (p == NULL) {
        return false;
    }
    bool ok = true;
    for (int i = 0; s[i] != '\0' && ok; i++) {
        char c = s[i];
        if (c == '(' || c == '[' || c == '{') {
            pilha_empilha(p, c); // abriu: espera o fechamento lá na frente
        } else if (c == ')' || c == ']' || c == '}') {
            int topo;
            // fechou: tem que existir uma abertura e ela tem que ser do mesmo tipo
            if (!pilha_desempilha(p, &topo) || topo != abertura_de(c)) {
                ok = false;
            }
        }
    }
    if (!pilha_vazia(p)) {
        ok = false; // sobrou abertura sem fechamento
    }
    pilha_libera(p);
    return ok;
}

int main(void) {
    const char *testes[] = {"{ x = v[(i + 1)] }", "( [ ) ]", "(a + b))", "{ [ ("};
    for (int i = 0; i < 4; i++) {
        printf("%-20s %s\n", testes[i], balanceada(testes[i]) ? "balanceada" : "com erro");
    }
    return 0;
}
// Saída:
// { x = v[(i + 1)] }   balanceada
// ( [ ) ]              com erro
// (a + b))             com erro
// { [ (                com erro
```

O laço tem duas saídas antecipadas para o erro; "pilha vazia?" só é testada
no fim da string:

{{fluxograma}}

### Notação pós-fixa

A segunda aplicação é fazer conta: `(35 + 25) * 3 / 4`, a conta do bar dividida
por 4 amigos. Na **infixa**, o operador fica no meio e exige parênteses e
precedência. Na **pós-fixa** (a da HP 12C), ele vem **depois** dos operandos:
`35 25 + 3 * 4 /`. A ordem da escrita já é a ordem das contas.

Para avaliar, use uma pilha de números: número **empilha**; operador
**desempilha dois**, calcula e **empilha o resultado**. No fim, sobra um só
número, o resultado:

| lê | faz | pilha (topo à direita) |
| --- | --- | --- |
| `35` | empilha | 35 |
| `25` | empilha | 35 25 |
| `+` | tira 25 e 35, empilha 35 + 25 | 60 |
| `3` | empilha | 60 3 |
| `*` | tira 3 e 60, empilha 60 * 3 | 180 |
| `4` | empilha | 180 4 |
| `/` | tira 4 e 180, empilha 180 / 4 | 45 |

Cada um paga R$ 45. O A168 faz essa tabela em C, juntando os dígitos de `35` e
acusando expressão inválida quando falta operando ou sobra número na pilha.

> [!WARNING]
> Na pós-fixa, o **primeiro** a sair da pilha é o operando da **direita**. Em
> `8 3 -`, sai o 3 (b) e depois o 8 (a), e a conta é `a - b = 5`; inverter dá
> `-5`. O erro some na soma e na multiplicação, então teste com `-` e `/`. No
> verificador de parênteses, esquecer o passo 4 faz `{ [ (` passar como
> balanceada.

> [!TIP]
> O tamanho da pilha nunca passa do número de caracteres da string (no pior
> caso, `((((((`). Memória **O(n)**, tempo **O(n)**: cada caractere é visto
> uma vez.

> [!NOTE]
> **Pergunta para você:** quanto vale `2 3 4 * +`? E `2 3 + 4 *`? Escreva as
> duas na forma infixa, com parênteses só onde precisa, antes de testar no
> A168.

{{pratique}}
