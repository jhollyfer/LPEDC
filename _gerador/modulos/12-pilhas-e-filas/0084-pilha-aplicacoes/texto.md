## 0084 · Pilha na prática: parênteses e notação pós-fixa

Você esquece de fechar um colchete no VS Code e, na hora, o editor sublinha
de vermelho o lugar certo. Ele não está contando parênteses. Está usando uma
pilha.

Com um tipo só de parêntese, um contador resolve: soma 1 no `(`, tira 1 no
`)`, nunca pode ficar negativo e tem que terminar em zero. Com três tipos
(`()`, `[]`, `{}`) o contador quebra. Em `( [ ) ]` tem duas aberturas e dois
fechamentos, a conta fecha, e a expressão está errada: o `)` chegou quando
quem estava esperando era o `[`.

A regra que você precisa é: **todo fechamento casa com a abertura mais
recente que ainda não fechou**. "Mais recente ainda pendente" é exatamente o
topo de uma pilha. O algoritmo:

1. abriu (`(`, `[` ou `{`): **empilha**;
2. fechou: **desempilha** e confere se é o par certo. Pilha vazia ou par
   errado: erro;
3. qualquer outro caractere: ignora;
4. acabou a string: a pilha tem que estar **vazia**. Se sobrou alguém, faltou
   fechar.

Vamos ver na prática com `{ x = v[(i + 1)] }`. Tirando o resto, sobram os
delimitadores `{ [ ( ) ] }`. Os três primeiros são empilhados. Quando chega o
`)`, o topo é `(`: casou, desempilha e segue. Depois `]` casa com `[` e `}`
casa com `{`:

{{ideia}}

O verificador, testado com quatro expressões. O `pilha.h` e o `pilha.c` são
os mesmos do 0083 e estão na pasta do assunto:

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

Repara no fluxograma: o laço só tem duas saídas antecipadas para o erro, e a
pergunta "pilha vazia?" só acontece quando a string acaba:

{{fluxograma}}

### Notação pós-fixa

A segunda aplicação clássica é fazer conta. A conta do bar foi `(35 + 25) * 3
/ 4`: três rodadas de petisco e bebida, divididas por 4 amigos. Na notação de
sempre (**infixa**), o operador fica no meio e você precisa de parênteses e de
regras de precedência. Na **pós-fixa** (a da calculadora HP 12C), o operador
vem **depois** dos dois operandos: `35 25 + 3 * 4 /`. Sem parênteses, sem
precedência: a ordem da escrita já é a ordem das contas.

Para avaliar, uma pilha de números: número **empilha**; operador
**desempilha dois**, faz a conta e **empilha o resultado**. No fim, sobra um
número só, o resultado:

| lê | faz | pilha (topo à direita) |
| --- | --- | --- |
| `35` | empilha | 35 |
| `25` | empilha | 35 25 |
| `+` | tira 25 e 35, empilha 35 + 25 | 60 |
| `3` | empilha | 60 3 |
| `*` | tira 3 e 60, empilha 60 * 3 | 180 |
| `4` | empilha | 180 4 |
| `/` | tira 4 e 180, empilha 180 / 4 | 45 |

Cada um paga R$ 45. O exemplo A168 faz exatamente essa tabela em C, juntando
os dígitos de `35` num número só e acusando expressão inválida quando falta
operando ou sobra número na pilha. É assim que compiladores e máquinas
virtuais (a JVM, o WebAssembly) calculam: traduzem a sua expressão para algo
parecido com a pós-fixa e rodam numa pilha.

> [!WARNING]
> Na pós-fixa, o **primeiro** a sair da pilha é o operando da **direita**.
> Em `8 3 -`, desempilha o 3 (b) e depois o 8 (a), e a conta é `a - b = 5`.
> Inverter dá `-5`, e o erro some na soma e na multiplicação, que não ligam
> para a ordem. Teste sempre com `-` e `/`. No verificador de parênteses, o
> erro clássico é esquecer o passo 4: sem conferir se a pilha terminou
> vazia, `{ [ (` passa como balanceada.

> [!TIP]
> **Por dentro do C:** o `char` que entra no `pilha_empilha(p, c)` vira `int`
> sem cast nenhum (promoção de inteiros), e `'('` é só o número 40 na tabela
> ASCII. Na pós-fixa, `expr[i] - '0'` transforma o caractere `'7'` (55) no
> número 7, porque os dígitos são consecutivos na tabela. E o tamanho da pilha
> nunca passa do número de caracteres da string: no pior caso, `((((((`, tudo
> é empilhado. Memória **O(n)**, tempo **O(n)**: cada caractere é visto uma
> vez e entra e sai da pilha no máximo uma vez.

> [!NOTE]
> **Pergunta para você:** quanto vale `2 3 4 * +`? E `2 3 + 4 *`? Escreva as
> duas na forma infixa, com parênteses só onde precisa, antes de testar no
> A168.

{{pratique}}
