## 0104 · Juntando tudo

A academia quer largar a planilha. O sistema novo precisa achar um aluno pela
matrícula, cadastrar, cancelar e mostrar, no fim do mês, o pódio de quem mais
treinou.

Achar, inserir e remover pela matrícula é trabalho de **BST**: O(altura). O
pódio pede "os maiores" por outro critério, os treinos, e a BST está ordenada
pela matrícula. Para isso existe o **heap**.

O nó agora guarda uma **struct** com matrícula, nome e treinos. A matrícula é
a **chave**; o resto vai junto. O TAD fica em `cadastro.h` e `cadastro.c`:

```c
typedef struct {
    int matricula;
    char nome[20];
    int treinos; // treinos no mês
} Aluno;

typedef struct NoAluno {
    Aluno a;
    struct NoAluno *esq;
    struct NoAluno *dir;
} NoAluno;
```

As funções são as da BST (`cad_insere`, `cad_busca`, `cad_remove`,
`cad_lista`), com `r->a.matricula` no lugar de `r->chave`. Dois detalhes:

- `cad_busca` devolve um `Aluno *` para o aluno **dentro** da árvore. Quem
  chama altera os treinos sem reinserir, mas não a matrícula, que quebraria a
  regra da BST;
- na remoção com dois filhos, `r->a = suc->a` copia a struct inteira do
  sucessor.

A árvore não pode ser reordenada pelos treinos. O ranking **copia** os alunos
para um vetor (`cad_para_vetor`, um percurso em ordem), monta um heap de máximo
**pelos treinos** em O(n) e tira o máximo três vezes: a fase 2 do heapsort
interrompida. Para os k maiores, não precisa ordenar tudo.

Sete alunos se matriculam. A catraca acha o 60 (Fabio) descendo 50, 70 e 60 e
soma um treino. O 30 (Bruno) cancela. Os treinos dos seis que sobram vão para
o vetor, e o heap entrega o pódio:

{{ideia}}

O programa usa o TAD para o cadastro e monta o heap do ranking sobre um vetor
de `Aluno`:

```c
#include <stdio.h>
#include "cadastro.h"

#define MAX 16

// heap de máximo pelos treinos, para o ranking
void desce(Aluno v[], int n, int i) {
    while (2 * i + 1 < n) {
        int f = 2 * i + 1;
        if (f + 1 < n && v[f + 1].treinos > v[f].treinos) {
            f++;
        }
        if (v[i].treinos >= v[f].treinos) {
            break;
        }
        Aluno t = v[i];
        v[i] = v[f];
        v[f] = t;
        i = f;
    }
}

// mostra os k que mais treinaram: monta o heap e tira o máximo k vezes
void ranking(const NoAluno *r, int k) {
    Aluno v[MAX];
    int n = cad_para_vetor(r, v, 0); // cópia: a árvore não muda
    for (int i = n / 2 - 1; i >= 0; i--) {
        desce(v, n, i);
    }
    for (int pos = 1; pos <= k && n > 0; pos++) {
        printf("  %dº %s (%d)\n", pos, v[0].nome, v[0].treinos);
        v[0] = v[--n];
        desce(v, n, 0);
    }
}

int main(void) {
    Aluno turma[] = {
        {50, "Ana", 12}, {30, "Bruno", 8}, {70, "Carla", 15}, {20, "Davi", 4},
        {40, "Eva", 20}, {60, "Fabio", 9}, {80, "Gil", 11},
    };
    NoAluno *cad = NULL;
    for (int i = 0; i < 7; i++) {
        cad = cad_insere(cad, turma[i]);
    }

    printf("Alunos (%d, altura %d):\n", cad_conta(cad), cad_altura(cad));
    cad_lista(cad);

    Aluno *a = cad_busca(cad, 60); // a catraca registra mais um treino
    if (a != NULL) {
        a->treinos++;
        printf("Catraca: %s agora tem %d treinos\n", a->nome, a->treinos);
    }

    cad = cad_remove(cad, 30); // Bruno cancelou
    printf("Sem o 30: %d alunos\n", cad_conta(cad));

    printf("Ranking do mês:\n");
    ranking(cad, 3);

    cad = cad_libera(cad);
    return 0;
}
// Saída:
// Alunos (7, altura 2):
//    20  Davi      4 treinos
//    30  Bruno     8 treinos
//    40  Eva      20 treinos
//    50  Ana      12 treinos
//    60  Fabio     9 treinos
//    70  Carla    15 treinos
//    80  Gil      11 treinos
// Catraca: Fabio agora tem 10 treinos
// Sem o 30: 6 alunos
// Ranking do mês:
//   1º Eva (20)
//   2º Carla (15)
//   3º Ana (12)
```

O fluxograma é uma sequência de operações na BST e, no fim, um laço sobre o
heap:

{{fluxograma}}

O exemplo A208 comanda o cadastro pelo teclado: `i 50 Ana 12` insere, `b 50`
busca, `r 50` remove e `l` lista.

> [!WARNING]
> O ponteiro de `cad_busca` aponta para dentro de um nó e vale só até a próxima
> remoção: `cad_remove` pode liberar esse nó ou copiar outro aluno por cima
> dele. Busque de novo depois de mexer na árvore e nunca altere `a->matricula`.

> [!TIP]
> Com structs grandes, monte o heap com um vetor de **ponteiros**
> (`Aluno *v[]`) e troque só os ponteiros, como no exercício E618.

> [!NOTE]
> **Pergunta para você:** se Gil (80) treinar mais 5 vezes antes do ranking, o
> pódio muda? E se os sete alunos entrassem em ordem crescente (20, 30, ..., 80),
> qual
> seria a altura mostrada na primeira linha?

{{pratique}}
