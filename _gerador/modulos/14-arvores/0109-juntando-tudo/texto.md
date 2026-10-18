## 0109 · Juntando tudo

A academia do bairro quer largar a planilha. O sistema novo precisa de três
coisas: achar um aluno pela matrícula na hora em que ele passa na catraca,
cadastrar e cancelar matrículas a qualquer momento, e, no fim do mês, mostrar o
pódio de quem mais treinou.

Cada pedido combina com uma estrutura deste módulo. Achar, inserir e remover
pela matrícula é trabalho de **BST**: cada operação desce um caminho só, O(altura).
O pódio pede "os maiores" por outro critério, os treinos, e a BST está ordenada
pela matrícula, não pelos treinos. Para isso existe o **heap**.

A diferença em relação aos assuntos anteriores é o dado. Agora o nó não guarda
um `int` solto, e sim uma **struct** com matrícula, nome e treinos. A matrícula
é a **chave**: é ela que decide esquerda ou direita. O resto vai junto, de
carona. O TAD fica em `cadastro.h` e `cadastro.c`:

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

As funções são as da BST (`cad_insere`, `cad_busca`, `cad_remove`, `cad_lista`),
trocando `r->chave` por `r->a.matricula`. Dois detalhes mudam:

- `cad_busca` devolve um `Aluno *`, um ponteiro para o aluno **dentro** da
  árvore. Quem chama pode alterar os treinos direto, sem remover e inserir de
  novo. Só não pode alterar a matrícula: isso quebraria a regra da BST;
- na remoção com dois filhos, `r->a = suc->a` copia a struct inteira do
  sucessor, com nome e tudo.

E o pódio? A árvore não pode ser reordenada pelos treinos, senão a busca pela
matrícula deixa de funcionar. Então o ranking **copia** os alunos para um vetor
(`cad_para_vetor`, uma em ordem que vai enchendo o vetor), monta um heap de
máximo **pelos treinos** nesse vetor, em O(n), e tira o máximo três vezes. É a
fase 2 do heapsort interrompida depois de três passos: para pegar os k maiores,
não precisa ordenar tudo.

Vamos ver na prática. Sete alunos se matriculam. A catraca acha o 60 (Fabio)
descendo 50, 70, 60 e soma um treino. O 30 (Bruno) cancela. No fim, os treinos
dos seis que sobraram vão para o vetor, em ordem de matrícula, e o heap entrega o
pódio:

{{ideia}}

O programa usa o TAD para o cadastro e escreve o heap do ranking direto sobre um
vetor de `Aluno`:

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

Repara no fluxograma: o programa é uma sequência de operações na BST e, no fim,
um laço curto sobre o heap. Cada estrutura faz o que sabe fazer bem:

{{fluxograma}}

O exemplo A218 é o mesmo cadastro, agora comandado pelo teclado: a recepção
digita `i 50 Ana 12` para inserir, `b 50` para buscar, `r 50` para remover e `l`
para listar.

> [!WARNING]
> O ponteiro devolvido por `cad_busca` aponta para dentro de um nó. Ele vale até
> a próxima remoção: se o `cad_remove` liberar esse nó (ou copiar outro aluno por
> cima dele, no caso de dois filhos), o ponteiro passa a apontar para memória
> devolvida ou para outro aluno. Use o ponteiro na hora e busque de novo depois de
> mexer na árvore. E nunca altere `a->matricula` por ele: o aluno ficaria no
> lugar errado da BST e as buscas não o achariam mais.

> [!TIP]
> **Por dentro do C:** `n->a = a` e `Aluno t = v[i]` copiam a struct inteira,
> 28 bytes (4 da matrícula, 20 do nome e 4 dos treinos), com uma atribuição só:
> o compilador gera a cópia dos bytes por você, sem `memcpy` à mão. Com structs
> grandes, copiar a cada troca do heap pesa. Aí o normal é montar o heap com um
> vetor de **ponteiros** para os alunos (`Aluno *v[]`) e trocar só os ponteiros, 8
> bytes cada, como no exercício E648 com as strings.

> [!NOTE]
> **Pergunta para você:** se Gil (80) treinar mais 5 vezes antes do ranking, o
> pódio muda? E se os sete alunos tivessem se matriculado em ordem crescente de
> matrícula (20, 30, ..., 80), qual seria a altura mostrada na primeira linha?

{{pratique}}
