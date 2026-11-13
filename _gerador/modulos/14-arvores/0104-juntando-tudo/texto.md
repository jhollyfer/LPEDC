## 0104 · Juntando tudo

A academia quer largar a planilha. O sistema novo precisa achar um aluno pela
matrícula, cadastrar, cancelar e mostrar, no fim do mês, o pódio de quem mais
treinou. São dois pedidos de natureza diferente: três operações que olham a
matrícula e uma que olha os treinos. Este assunto mostra como as estruturas
do módulo dividem esse trabalho, cada uma no papel em que é boa.

Achar, cadastrar e cancelar pela matrícula é trabalho de **BST** (0099 e
0100): as três operações descem um caminho e custam O(altura). O pódio pede
"os maiores" por outro critério, os treinos, e a BST não ajuda, porque está
ordenada pela matrícula. Para "quem é o maior?" existe o **heap** do 0102
(CORMEN et al., 2024, caps. 6 e 12). Nenhuma das duas faz bem o serviço da
outra, e o sistema usa as duas.

Até aqui, cada nó guardava um `int`. Agora o nó guarda um **registro**, uma
`struct` com matrícula, nome e treinos. Uma parte do registro é a **chave**,
o campo que decide a posição na árvore; aqui, a matrícula. O resto viaja
junto, sem influenciar nada (KERNIGHAN; RITCHIE, 1989, seção 6.5). As funções
são as mesmas da BST, só que comparam `r->a.matricula` onde antes
comparavam `r->chave`. Na remoção com dois filhos, a cópia do sucessor passa
a copiar a `struct` inteira, e não só a chave.

A busca pode devolver um ponteiro para o registro que está **dentro** da
árvore. Com ele, quem chama soma um treino ao aluno sem remover e reinserir
nada. O cuidado é o que se pode mudar por esse ponteiro: os campos comuns,
como os treinos, sim; a chave, nunca. Mudar a matrícula deixaria o nó num
lugar que a regra da BST não permite, e as buscas seguintes passariam a
errar (CELES; RANGEL, 2002).

Para o pódio, a árvore não pode ser reordenada pelos treinos sem deixar de
ser uma BST de matrículas. A saída é **copiar**: um percurso em ordem joga os
alunos num vetor, e sobre esse vetor você monta um heap de máximo **pelos
treinos**, com a fase 1 do heapsort (0103), em O(n). Depois tira o máximo
três vezes. É a fase 2 do heapsort interrompida no terceiro passo. Para achar
os k maiores, você não precisa ordenar o vetor inteiro: o custo é O(n) da
construção mais k descidas de O(log n) (TENENBAUM; LANGSAM; AUGENSTEIN, 1995,
cap. 6).

Se cada registro fosse grande, com endereço, histórico e foto, cada troca do
heap copiaria a `struct` inteira. Nesse caso, o heap guarda **ponteiros**
para os registros, um vetor `Aluno *v[]`, e as trocas movem só os ponteiros,
de 8 bytes cada (CELES; CERQUEIRA; RANGEL, 2016). O exercício E618 pede essa
versão.

> [!WARNING]
> O ponteiro de `cad_busca` aponta para dentro de um nó e vale só até a próxima
> remoção: `cad_remove` pode liberar esse nó ou copiar outro aluno por cima
> dele. Busque de novo depois de mexer na árvore e nunca altere `a->matricula`.

{{exemplo}}

A academia troca a planilha por um cadastro em BST, com a matrícula como
chave. A catraca acha o 60 (Fabio) descendo 50, 70 e 60 e soma um treino. O
30 (Bruno) cancela, e um heap pelos treinos entrega o pódio:

{{ideia}}

O nó do TAD (`cadastro.h` e `cadastro.c`) guarda a struct do aluno:

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
`cad_lista`), com `r->a.matricula` no lugar de `r->chave`. Na remoção com dois
filhos, `r->a = suc->a` copia a struct inteira do sucessor. O ranking copia os
alunos para um vetor (`cad_para_vetor`, em ordem) e monta o heap sobre ele:

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

O exemplo A208 comanda o cadastro pelo teclado (`i 50 Ana 12`, `b 50`,
`r 50`, `l`). O fluxograma é uma sequência de operações na BST e, no fim, um
laço sobre o heap:

{{fluxograma}}
