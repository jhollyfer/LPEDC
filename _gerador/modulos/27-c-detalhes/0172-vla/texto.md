## 0172 · Vetor de tamanho variável (VLA)

A academia do bairro quer uma planilha de treinos: uma linha por aluno, uma
coluna por semana. Só que o número de alunos e de semanas muda a cada
turma, e só é conhecido quando o professor digita. Até aqui, você teria duas
saídas: reservar uma matriz enorme "por garantia" ou chamar o `malloc`.

O C99 trouxe uma terceira: o **VLA** (*variable length array*, vetor de
tamanho variável). É um vetor local cujo tamanho é uma expressão calculada
na hora, não uma constante: `int treinos[alunos][semanas];`. Ele mora na
**pilha**, como qualquer variável local, e some sozinho no fim do bloco. Não
tem `free`.

Com o VLA, o `sizeof` deixa de ser uma constante do compilador: `sizeof
treinos` é calculado **em tempo de execução**, e vale `alunos * semanas *
sizeof(int)`. O VLA também tem limites: não pode ser `static` nem global, e
não aceita inicialização (`int v[n] = {0};` é erro no C17). Preencha com um
laço.

O uso mais útil é como **parâmetro**. Uma função comum precisa saber a
largura da matriz já ao compilar (`int m[][4]`). Com VLA, a função recebe as
dimensões e a matriz: `void f(int l, int c, int m[l][c])`. A ordem importa:
`l` e `c` vêm **antes**, porque o tipo `m[l][c]` usa os dois. Assim uma
só função serve para matrizes de qualquer tamanho.

Um detalhe de versão: no C99 o VLA é obrigatório; no C11 e no C17 virou
**opcional**. Um compilador sem VLA define a macro `__STDC_NO_VLA__`. O gcc
e o clang suportam; o compilador da Microsoft, não. Quem quer garantir
escreve:

```c
#ifdef __STDC_NO_VLA__
#error "este programa precisa de VLA"
#endif
```

Com 3 alunos e 4 semanas, a planilha tem 12 `int`:
48 bytes, reservados na pilha no momento em que a linha do VLA roda. O
desenho mostra a matriz e onde ela fica:

{{ideia}}

O programa lê as dimensões, confere, cria o VLA e passa para as funções:

```c
#include <stdio.h>

// treinos fictícios de cada aluno em cada semana (1 a 5)
void preencher(int l, int c, int m[l][c]) {
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            m[i][j] = (3 * i + 2 * j) % 5 + 1;
        }
    }
}

// as dimensões vêm ANTES da matriz: o tipo m[l][c] usa l e c
int total_do_aluno(int l, int c, int m[l][c], int aluno) {
    int soma = 0;
    for (int j = 0; j < c; j++) {
        soma += m[aluno][j];
    }
    return soma;
}

int main(void) {
    int alunos, semanas;
    printf("Alunos e semanas: ");
    if (scanf("%d %d", &alunos, &semanas) != 2 || alunos < 1 || alunos > 100 ||
        semanas < 1 || semanas > 52) {
        printf("valores inválidos\n"); // VLA de tamanho <= 0 é indefinido
        return 1;
    }

    int treinos[alunos][semanas]; // VLA: o tamanho só existe agora
    printf("sizeof treinos = %zu bytes\n", sizeof treinos); // calculado na hora

    preencher(alunos, semanas, treinos);
    for (int i = 0; i < alunos; i++) {
        printf("aluno %d:", i + 1);
        for (int j = 0; j < semanas; j++) {
            printf(" %d", treinos[i][j]);
        }
        printf("  total %d\n", total_do_aluno(alunos, semanas, treinos, i));
    }
    return 0;
}
// Saída (digitando 3 4):
// Alunos e semanas: 3 4
// sizeof treinos = 48 bytes
// aluno 1: 1 3 5 2  total 11
// aluno 2: 4 1 3 5  total 13
// aluno 3: 2 4 1 3  total 10
```

No fluxograma, a validação vem **antes** do VLA. Depois que a linha
`int treinos[alunos][semanas];` roda, não há como desistir nem como saber se
deu certo:

{{fluxograma}}

> [!WARNING]
> O VLA não avisa quando falha. O `malloc` devolve `NULL` se não houver
> memória; o VLA pede o espaço à pilha, e a pilha de um programa
> no Linux tem uns **8 MB** (confira com `ulimit -s`). Um `int v[n]` com `n`
> igual a 3 milhões pede 12 MB e derruba o programa com *segmentation
> fault*, sem chance de tratar. E um `n` que veio do usuário pode ser 0,
> negativo ou gigante. Regra prática: VLA só para tamanhos **pequenos e
> conferidos**; para dados grandes ou de tamanho desconhecido, `malloc`.

> [!TIP]
> **Por dentro do C:** um vetor comum tem tamanho fixo, e o compilador já
> sabe, ao compilar, quanto descer o ponteiro da pilha (`sub rsp, 48`). Com
> VLA, ele gera código que calcula `alunos * semanas * 4` na hora e desce o
> ponteiro da pilha por esse valor: é tão rápido quanto uma variável local,
> muito mais que o `malloc`. Dá para ter o melhor dos dois: `int (*m)[c] =
> malloc(l * sizeof *m);` cria a matriz no heap, com tipo VLA, e você
> continua escrevendo `m[i][j]` (veja o A344).

> [!NOTE]
> **Pergunta para você:** se o professor digitar `100 52`, quantos bytes
> o `sizeof treinos` mostra? E quantas planilhas desse tamanho caberiam numa
> pilha de 8 MB?

{{pratique}}
