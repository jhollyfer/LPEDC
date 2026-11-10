## 0088 · Juntando tudo: a calculadora de expressões

No bar do 0084 você escreveu `35 25 + 3 * 4 /` em pós-fixa. Ninguém digita
assim: a pessoa digita `(35 + 25) * 3 / 4` e quer ver 45. O programa deste
assunto faz o caminho inteiro com uma **fila** e duas **pilhas**, em duas
etapas:

1. **converter** a infixa em pós-fixa. Os números vão direto para uma fila de
   saída. Os operadores esperam numa **pilha** e só vão para a fila quando
   nenhum operador mais forte precisa passar na frente. É o algoritmo do
   **pátio de manobras** (*shunting-yard*), de Dijkstra, o mesmo do E503;
2. **avaliar** a pós-fixa: os itens saem da fila na ordem de entrada (FIFO) e
   passam por uma **pilha de valores**, como no A168.

A fila fica no meio porque a etapa 1 produz itens e a etapa 2 os consome na
mesma ordem: o padrão **produtor e consumidor**. Ela também guarda o 35
inteiro, sem juntar dígitos de novo.

A fila e a pilha do curso só guardam `int`. Como os números são sempre
`>= 0`, os operadores viram **códigos negativos** com um `enum` (assunto 0063):
`SOMA = -1`, `SUB = -2` e assim por diante. Na avaliação, `t >= 0` é número e
`t < 0` é operador. A alternativa seria uma `struct` com uma etiqueta do tipo
do item.

Regras da conversão, para cada símbolo lido:

- número: vai para a **fila**;
- `(`: empilha;
- `)`: desempilha para a fila até achar o `(`, que é descartado;
- operador: enquanto o topo tiver precedência **maior ou igual**, desempilha
  para a fila; depois empilha o operador;
- fim: o que sobrou na pilha vai para a fila.

Com `(35 + 25) * 3 / 4`, a fila de saída fica `35 25 + 3 * 4 /`. Quando chega
o `/`, a pilha de valores tem 180 e 4, e a última conta dá 45:

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

No fluxograma, as perguntas de erro só aparecem na avaliação, onde a falta de
operando e a divisão por zero se revelam:

{{fluxograma}}

O A176 junta fila e pilha de outro jeito: as letras de uma frase entram nas
duas. A fila devolve a ordem original e a pilha, a invertida; se as duas
sequências coincidirem letra a letra, a frase é um palíndromo.

> [!WARNING]
> O "maior **ou igual**" da conversão muda o resultado. Só com "maior",
> `8 - 3 - 2` vira `8 3 2 - -`, que dá `8 - (3 - 2) = 7`; o certo é
> `(8 - 3) - 2 = 3`. Operadores de mesma precedência associam **à esquerda**,
> então o que já está na pilha sai antes do novo. (A potência associa à
> direita, por isso o programa não tem `^`.) É o bug do E526.

> [!TIP]
> Tipos não têm ligação: `No` (pilha) e `NoFila` poderiam ter o mesmo nome em
> arquivos separados. O conflito só ocorre entre **funções** de mesmo nome, por
> isso cada TAD prefixa as suas (`pilha_`, `fila_`). Cada símbolo entra e sai
> da fila uma vez e de cada pilha no máximo uma, então a calculadora é
> **O(n)**.

> [!NOTE]
> **Pergunta para você:** como fica a pós-fixa de `100 / (2 + 3) - 4`? E o
> resultado? Faça a conversão à mão, com a pilha de operadores desenhada,
> antes de trocar a expressão no programa da calculadora.

{{pratique}}
