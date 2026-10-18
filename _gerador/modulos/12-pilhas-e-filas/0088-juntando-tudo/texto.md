## 0088 · Juntando tudo: a calculadora de expressões

Lembra da conta do bar do 0084? Lá, você mesmo escreveu `35 25 + 3 * 4 /`
na notação pós-fixa. Ninguém digita assim no celular. A pessoa quer digitar
`(35 + 25) * 3 / 4` e ver 45. O programa do módulo faz o caminho inteiro, e
usa as duas estruturas: uma **fila** e duas **pilhas**.

São duas etapas, uma linha de produção:

1. **converter** a infixa para pós-fixa. Os números vão direto para uma
   fila de saída, na ordem em que aparecem. Os operadores esperam numa
   **pilha**: um operador só pode ir para a fila quando ninguém mais forte
   precisa passar na frente. É o algoritmo do **pátio de manobras**
   (*shunting-yard*), de Dijkstra, o mesmo do exercício E503;
2. **avaliar** a pós-fixa. Os itens saem da fila na ordem em que entraram
   (FIFO, exatamente o que a pós-fixa exige) e passam por uma **pilha de
   valores**, como no A168.

Por que fila no meio, e não uma string? Porque a etapa 1 produz itens e a
etapa 2 consome itens, um de cada vez, na mesma ordem. É o padrão
**produtor e consumidor**, o mesmo de um *pipe* no terminal ou de uma fila de
mensagens entre dois serviços. E a fila guarda o número 35 inteiro, sem
precisar juntar dígitos de novo.

Um detalhe: a fila e a pilha do curso só guardam `int`. Como fazer caber um
`+` ali? Os números da calculadora são sempre `>= 0`, então os operadores
viram **códigos negativos** com um `enum` (assunto 0063): `SOMA = -1`,
`SUB = -2` e assim por diante. Na hora de avaliar, `t >= 0` é número e
`t < 0` é operador. É um truque comum quando o tipo é fixo; a alternativa
seria uma `struct` com uma etiqueta dizendo o que o item é.

As regras da conversão, para cada símbolo lido:

- número: vai para a **fila**;
- `(`: empilha;
- `)`: desempilha para a fila até achar o `(`, que é descartado;
- operador: enquanto o topo tiver precedência **maior ou igual**, desempilha
  para a fila; depois empilha o operador;
- fim: o que sobrou na pilha vai para a fila.

Vamos ver na prática. Com `(35 + 25) * 3 / 4`, a fila de saída fica
`35 25 + 3 * 4 /`. Na avaliação, a pilha de valores chega a ter 180 e 4
quando aparece o `/`, e a última conta dá 45:

{{ideia}}

O programa completo. A pasta tem o `pilha.h`/`pilha.c` do 0083 e o
`fila.h`/`fila.c` do 0086, e o `rodar` compila os quatro junto:

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

Repara no fluxograma: as duas etapas ficam em sequência, e as perguntas de
erro só aparecem na avaliação, que é onde falta de operando e divisão por
zero se revelam:

{{fluxograma}}

O segundo exemplo, A176, junta fila e pilha de outro jeito: as letras de uma
frase entram nas duas ao mesmo tempo. A fila devolve na ordem original, a
pilha devolve ao contrário. Se as duas sequências baterem letra por letra, a
frase é um palíndromo.

> [!WARNING]
> O "maior **ou igual**" da conversão não é detalhe. Com só "maior", `8 - 3 -
> 2` vira `8 3 2 - -`, que calcula `8 - (3 - 2) = 7`. O certo é
> `(8 - 3) - 2 = 3`: operadores de mesma precedência associam **à esquerda**,
> então o que já está na pilha sai antes do novo. (A potência é a exceção que
> associa à direita, e por isso este programa não tem `^`.) Esse é o bug do
> E526.

> [!TIP]
> **Por dentro do C:** os quatro `.c` da pasta são compilados separados e
> juntados pelo ligador. O nó da pilha se chama `No` e o da fila, `NoFila`,
> mas, compilados separados, os dois poderiam se chamar `No`: tipo não tem
> ligação, ele só existe dentro do arquivo que o declara, e o ligador nunca o
> vê. Conflito haveria se os dois definissem uma **função** com o mesmo nome,
> como `cria`: por isso cada TAD prefixa as suas (`pilha_`, `fila_`). Repare também no custo: cada
> símbolo da expressão entra e sai da fila uma vez e de cada pilha no máximo
> uma vez, então a calculadora inteira é **O(n)** no tamanho da expressão.

> [!NOTE]
> **Pergunta para você:** como fica a pós-fixa de `100 / (2 + 3) - 4`? E o
> resultado? Faça a conversão à mão, com a pilha de operadores desenhada,
> antes de trocar a expressão no programa da calculadora.

{{pratique}}
