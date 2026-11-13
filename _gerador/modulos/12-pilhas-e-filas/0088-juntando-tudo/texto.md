## 0088 · Juntando tudo: a calculadora de expressões

- **Duas etapas**: **converter** a infixa em pós-fixa e **avaliar** a
  pós-fixa, com uma **fila** no meio e duas **pilhas**
  (TENENBAUM; LANGSAM; AUGENSTEIN, 1995, cap. 2).
- **Pátio de manobras** (*shunting-yard*): os números vão direto para a fila
  de saída; os operadores esperam numa pilha até nenhum operador mais forte
  precisar passar na frente. O algoritmo é de Dijkstra (DIJKSTRA, 1961).
- **Regras da conversão**: número vai para a fila; `(` empilha; `)`
  desempilha para a fila até achar o `(`, que é descartado; operador
  desempilha enquanto o topo tiver precedência **maior ou igual** e depois se
  empilha; no fim, o que sobrou vai para a fila (FEOFILOFF, 2009).
- **Avaliar**: os itens saem da fila na ordem de entrada (FIFO) e passam por
  uma **pilha de valores**, como no 0084 (KERNIGHAN; RITCHIE, 1988, seç. 4.3).
- **Produtor e consumidor**: a etapa 1 produz itens e a 2 os consome na mesma
  ordem; a fila também guarda o 35 inteiro, sem juntar dígitos de novo.
- **Códigos negativos**: a fila e a pilha só guardam `int`. Os números são
  `>= 0`, então os operadores viram negativos num `enum` (0063): `SOMA = -1`,
  `SUB = -2`. Na avaliação, `t < 0` é operador.
- **Custo**: cada símbolo entra e sai da fila uma vez e de cada pilha no
  máximo uma: O(n).

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
