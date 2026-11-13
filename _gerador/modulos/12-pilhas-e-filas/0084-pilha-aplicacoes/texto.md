## 0084 · Pilha na prática: parênteses e notação pós-fixa

Você esquece de fechar um colchete no editor de código e ele sublinha o lugar
exato do erro. Para isso, o editor precisa saber, a cada `)`, `]` ou `}`, qual
abertura ele está fechando. A pilha resolve esse problema e mais um, que
aparece em toda calculadora: fazer contas sem depender de parênteses. São as
duas aplicações clássicas da pilha.

Comece pelo jeito ingênuo. Com um só tipo de parêntese, um contador basta:
soma 1 em cada `(`, tira 1 em cada `)` e, no fim, o contador tem de valer
zero sem nunca ter ficado negativo. Com três tipos (`()`, `[]` e `{}`), o
contador falha. Em `( [ ) ]` as contas fecham, mas o `)` chegou quando quem
esperava fechamento era o `[` (TENENBAUM; LANGSAM; AUGENSTEIN, 1995, cap. 2).
Falta lembrar a **ordem** das aberturas, e não só quantas são.

A regra que resolve é esta: todo fechamento casa com a abertura **mais
recente** que ainda está pendente. "A mais recente pendente" é exatamente o
topo de uma pilha, porque a última abertura empilhada é a primeira que pede
fechamento (FEOFILOFF, 2009). Pense em caixas dentro de caixas: você só fecha
a caixa de fora depois de fechar a de dentro.

O algoritmo percorre a string uma vez. Se o caractere abre (`(`, `[` ou `{`),
você **empilha**. Se fecha, você **desempilha** e confere se o par combina; se
a pilha estava vazia ou o par não combina, a expressão tem erro. Qualquer
outro caractere é ignorado. Quando a string acaba, a pilha tem de estar
**vazia**: se sobrou abertura, faltou fechar alguma coisa (FEOFILOFF, 2009).
Em `{ x = v[(i + 1)] }`, os três primeiros delimitadores entram na pilha; o
`)` encontra `(` no topo, o `]` encontra `[` e o `}` encontra `{`.

A segunda aplicação é a conta. O jeito de escrever que você aprendeu na
escola é a **notação infixa**: o operador fica no meio dos operandos, como em
`(35 + 25) * 3 / 4`. Ela precisa de parênteses e de regras de precedência
para dizer o que vem primeiro. Na **notação pós-fixa**, também chamada de
polonesa reversa, o operador vem **depois** dos dois operandos: a mesma conta
fica `35 25 + 3 * 4 /` (TENENBAUM; LANGSAM; AUGENSTEIN, 1995, cap. 2). A
calculadora HP 12C funciona assim. A ordem da escrita já é a ordem das
contas, e nenhum parêntese é necessário.

Avaliar a pós-fixa exige uma pilha de números. Leu um número, **empilha**.
Leu um operador, **desempilha dois** números, faz a conta e **empilha o
resultado**. No fim sobra um só número na pilha, e ele é o resultado
(KERNIGHAN; RITCHIE, 1988, seç. 4.3). Se faltar operando para um operador, ou
se sobrar mais de um número no fim, a expressão está mal escrita. A tabela
mostra a conta do bar de R$ 60 com 3 rodadas, dividida por 4 amigos:

| lê | faz | pilha (topo à direita) |
| --- | --- | --- |
| `35` | empilha | 35 |
| `25` | empilha | 35 25 |
| `+` | tira 25 e 35, empilha 35 + 25 | 60 |
| `3` | empilha | 60 3 |
| `*` | tira 3 e 60, empilha 60 * 3 | 180 |
| `4` | empilha | 180 4 |
| `/` | tira 4 e 180, empilha 180 / 4 | 45 |

As duas aplicações custam o mesmo. Cada caractere é lido uma vez, então o
tempo é O(n) para uma string de n caracteres. A pilha nunca passa de n itens
(o pior caso é `((((((`), então a memória também é O(n) (FEOFILOFF, 2009).

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
