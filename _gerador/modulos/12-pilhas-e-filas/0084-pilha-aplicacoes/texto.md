## 0084 · Pilha na prática: parênteses e notação pós-fixa

- **Contador não basta**: com um só tipo de parêntese, somar 1 no `(` e
  tirar 1 no `)` resolve. Com `()`, `[]` e `{}` falha: em `( [ ) ]` as contas
  fecham, mas o par está errado (TENENBAUM; LANGSAM; AUGENSTEIN, 1995,
  cap. 2).
- **Regra**: todo fechamento casa com a abertura **mais recente** ainda
  pendente, que é o topo de uma pilha (FEOFILOFF, 2009).
- **Algoritmo**: abriu, **empilha**; fechou, **desempilha** e confere o par
  (pilha vazia ou par errado é erro); outro caractere, ignora; no fim, a
  pilha tem de estar **vazia** (FEOFILOFF, 2009).
- **Infixa e pós-fixa**: na **infixa**, o operador fica no meio e exige
  parênteses e precedência. Na **pós-fixa** (a da HP 12C), ele vem **depois**
  dos operandos: `35 25 + 3 * 4 /` (TENENBAUM; LANGSAM; AUGENSTEIN, 1995,
  cap. 2).
- **Avaliar a pós-fixa**: número **empilha**; operador **desempilha dois**,
  calcula e **empilha o resultado**. No fim sobra um número, o resultado
  (KERNIGHAN; RITCHIE, 1988, seç. 4.3).
- **Custo**: a pilha nunca passa do número de caracteres; tempo e memória
  O(n), cada caractere visto uma vez (FEOFILOFF, 2009).

> [!WARNING]
> Na pós-fixa, o **primeiro** a sair é o operando da **direita**. Em `8 3 -`,
> sai o 3 (b) e depois o 8 (a): a conta é `a - b = 5`. Teste com `-` e `/`,
> onde a inversão aparece. Nos parênteses, esquecer o teste final de pilha
> vazia faz `{ [ (` passar como balanceada.

{{exemplo}}

Em `{ x = v[(i + 1)] }` sobram os delimitadores `{ [ ( ) ] }`. Os três
primeiros são empilhados; o `)` encontra `(` no topo e casa, depois `]` casa
com `[` e `}` com `{`:

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

### Passo a passo: notação pós-fixa

A conta do bar, `(35 + 25) * 3 / 4`, dividida por 4 amigos, vira
`35 25 + 3 * 4 /`:

| lê | faz | pilha (topo à direita) |
| --- | --- | --- |
| `35` | empilha | 35 |
| `25` | empilha | 35 25 |
| `+` | tira 25 e 35, empilha 35 + 25 | 60 |
| `3` | empilha | 60 3 |
| `*` | tira 3 e 60, empilha 60 * 3 | 180 |
| `4` | empilha | 180 4 |
| `/` | tira 4 e 180, empilha 180 / 4 | 45 |

Cada um paga R$ 45. O A168 faz essa tabela em C.
