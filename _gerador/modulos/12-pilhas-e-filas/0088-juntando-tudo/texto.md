## 0088 · Juntando tudo: a calculadora de expressões

No bar do 0084 você escreveu `35 25 + 3 * 4 /` em pós-fixa e a pilha deu 45.
Só que ninguém digita assim. A pessoa digita `(35 + 25) * 3 / 4` e quer ver
45. Para fechar o caminho, o programa precisa traduzir a notação infixa da
escola para a pós-fixa e só então fazer a conta. Este assunto junta tudo o
que o módulo construiu: uma **fila** e duas **pilhas** trabalhando em duas
etapas (TENENBAUM; LANGSAM; AUGENSTEIN, 1995, cap. 2).

A primeira etapa **converte** a infixa em pós-fixa. O algoritmo se chama
**pátio de manobras** (*shunting-yard*) e foi criado por Dijkstra para um
tradutor de Algol (DIJKSTRA, 1961). O nome vem da ferrovia: os vagões de
número seguem direto pelo trilho principal até a fila de saída, e os vagões
de operador esperam num desvio, que é uma pilha, até que nenhum operador mais
forte precise passar na frente deles.

As regras olham um símbolo de cada vez. A precedência é a força do operador:
`*` e `/` são mais fortes que `+` e `-`, e por isso fazem a conta antes. A
tabela resume o que fazer com cada tipo de símbolo (FEOFILOFF, 2009):

| Símbolo lido | O que fazer |
| --- | --- |
| número | vai direto para a **fila** de saída |
| `(` | empilha |
| `)` | desempilha para a fila até achar o `(`, que é descartado |
| operador | enquanto o topo tiver precedência **maior ou igual**, desempilha para a fila; depois empilha o operador |
| fim da expressão | o que sobrou na pilha vai para a fila |

Com `(35 + 25) * 3 / 4`, a fila de saída termina como `35 25 + 3 * 4 /`. O
`+` ficou preso entre os parênteses e saiu no `)`. O `*` saiu quando chegou o
`/`, porque os dois têm a mesma força e o `*` estava antes.

A segunda etapa **avalia** a pós-fixa exatamente como no 0084. Os itens saem
da fila na ordem em que entraram (FIFO) e passam por uma **pilha de
valores**: número empilha, operador desempilha dois, calcula e empilha o
resultado (KERNIGHAN; RITCHIE, 1988, seç. 4.3). Quando chega o `/`, a pilha
tem 180 e 4, e a última conta dá 45.

Por que uma fila no meio, e não uma string? Porque a etapa 1 produz itens e a
etapa 2 os consome na mesma ordem em que foram produzidos. Esse é o padrão
**produtor e consumidor**, e a fila é a estrutura natural para ele. A fila
também guarda o 35 como um número inteiro, e a avaliação não precisa juntar
os dígitos de novo.

Resta um detalhe de C. A fila e a pilha do curso só guardam `int`, e a fila
de saída mistura números e operadores. Como os números da calculadora são
sempre `>= 0`, os operadores viram **códigos negativos** num `enum` (assunto
0063): `SOMA = -1`, `SUB = -2` e assim por diante. Na avaliação, `t >= 0` é
número e `t < 0` é operador. A alternativa seria uma `struct` com uma
etiqueta que diz o tipo do item. O nome dos tipos não atrapalha: `No` e
`NoFila` podiam até ser iguais em arquivos separados, porque tipo não tem
ligação. O conflito só aparece entre **funções** de mesmo nome, e por isso
cada TAD prefixa as suas com `pilha_` ou `fila_`.

A calculadora inteira é **O(n)** para uma expressão de n símbolos: cada
símbolo entra e sai da fila uma vez, e de cada pilha no máximo uma vez.

> [!WARNING]
> O "maior **ou igual**" muda o resultado. Só com "maior", `8 - 3 - 2` vira
> `8 3 2 - -`, que dá 7; o certo é `(8 - 3) - 2 = 3`. Mesma precedência
> associa **à esquerda**: o que já está na pilha sai antes do novo.

{{exemplo}}

A conta do bar, digitada como `(35 + 25) * 3 / 4`. A fila de saída fica
`35 25 + 3 * 4 /`; quando chega o `/`, a pilha de valores tem 180 e 4, e a
última conta dá 45:

{{ideia}}

A pasta tem o `pilha.c` do 0083 e o `fila.c` do 0086; o comando do exemplo
compila os quatro com o programa:

```c
#include <stdbool.h>
#include <stdio.h>
#include "fila.h"
#include "pilha.h"

// Na fila e na pilha só cabe int. Números são >= 0; operadores e o "("
// viram códigos negativos, que nunca se confundem com um número.
enum { SOMA = -1, SUB = -2, MULT = -3, DIV = -4, ABRE = -5 };

int codigo_de(char c) {
    return c == '+' ? SOMA : c == '-' ? SUB : c == '*' ? MULT : DIV;
}

int precedencia(int op) {
    return (op == MULT || op == DIV) ? 2 : (op == SOMA || op == SUB) ? 1 : 0; // ABRE: 0
}

// Etapa 1: infixa -> fila em ordem pós-fixa. A pilha segura os operadores.
bool converte(const char *s, Fila *saida) {
    Pilha *ops = pilha_cria();
    if (ops == NULL) {
        return false;
    }
    int topo;
    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        if (c >= '0' && c <= '9') {
            int numero = 0;
            for (; s[i] >= '0' && s[i] <= '9'; i++) {
                numero = numero * 10 + (s[i] - '0');
            }
            i--;
            fila_insere(saida, numero); // número vai direto para a saída
        } else if (c == '(') {
            pilha_empilha(ops, ABRE);
        } else if (c == ')') {
            while (pilha_desempilha(ops, &topo) && topo != ABRE) {
                fila_insere(saida, topo);
            }
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            int op = codigo_de(c);
            // sai antes quem tem precedência maior ou igual (conta da esquerda primeiro)
            while (pilha_topo(ops, &topo) && precedencia(topo) >= precedencia(op)) {
                pilha_desempilha(ops, &topo);
                fila_insere(saida, topo);
            }
            pilha_empilha(ops, op);
        }
    }
    while (pilha_desempilha(ops, &topo)) {
        fila_insere(saida, topo);
    }
    pilha_libera(ops);
    return true;
}

// Etapa 2: consome a fila pós-fixa com uma pilha de valores.
bool avalia(Fila *posfixa, int *resultado) {
    Pilha *val = pilha_cria();
    if (val == NULL) {
        return false;
    }
    bool ok = true;
    int t, a, b;
    printf("Pós-fixa: ");
    while (ok && fila_retira(posfixa, &t)) {
        if (t >= 0) {
            printf(" %d", t);
            pilha_empilha(val, t);
        } else if (!pilha_desempilha(val, &b) || !pilha_desempilha(val, &a) || (t == DIV && b == 0)) {
            ok = false;
        } else {
            printf(" %c", t == SOMA ? '+' : t == SUB ? '-' : t == MULT ? '*' : '/');
            pilha_empilha(val, t == SOMA ? a + b : t == SUB ? a - b : t == MULT ? a * b : a / b);
        }
    }
    printf("\n");
    ok = ok && pilha_desempilha(val, resultado) && pilha_vazia(val);
    pilha_libera(val);
    return ok;
}

int main(void) {
    const char *contas[] = {"(35 + 25) * 3 / 4", "2 * (3 + 4) - 10 / 5"};
    for (int i = 0; i < 2; i++) {
        Fila *posfixa = fila_cria();
        if (posfixa == NULL) {
            return 1;
        }
        int r;
        printf("Infixa:    %s\n", contas[i]);
        if (converte(contas[i], posfixa) && avalia(posfixa, &r)) {
            printf("Resultado: %d\n", r);
        } else {
            printf("Expressão inválida\n");
        }
        fila_libera(posfixa);
    }
    return 0;
}
// Saída:
// Infixa:    (35 + 25) * 3 / 4
// Pós-fixa:  35 25 + 3 * 4 /
// Resultado: 45
// Infixa:    2 * (3 + 4) - 10 / 5
// Pós-fixa:  2 3 4 + * 10 5 / -
// Resultado: 12
```

As perguntas de erro só aparecem na avaliação, onde a falta de operando e a
divisão por zero se revelam:

{{fluxograma}}
