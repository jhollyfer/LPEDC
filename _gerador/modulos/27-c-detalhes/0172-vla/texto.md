## 0172 · Vetor de tamanho variável (VLA)

O professor de educação física quer uma planilha de treinos: uma linha por
aluno, uma coluna por semana. Só que o número de alunos e de semanas só é
conhecido quando ele digita. Até aqui você tinha duas saídas: declarar uma
matriz enorme "por garantia", como `int treinos[100][52]`, e usar só um
canto dela; ou pedir a memória ao `malloc` e cuidar do `free`. O C tem uma
terceira.

O **VLA**, sigla de *variable length array* (vetor de tamanho variável), é
um vetor local cujo tamanho é uma expressão calculada durante a execução,
e não uma constante conhecida na compilação (ISO/IEC, 2018). Ele entrou na
linguagem no C99. Com ele, a planilha se declara do tamanho exato:

```c
int alunos = 3, semanas = 4;          // lidos do teclado, na prática
int treinos[alunos][semanas];         // 12 int, criados agora
```

O VLA mora na **pilha**, como qualquer variável local. Ele é criado quando
a execução chega à declaração e some sozinho no fim do bloco, sem `free`.
Por morar na pilha e depender de um valor calculado na hora, ele não pode
ser `static` nem global: essas variáveis existem desde o início do
programa, antes de qualquer valor ser lido (CPPREFERENCE, s.d.).

Como o tamanho só existe na execução, o `sizeof` de um VLA também é
calculado na execução. Com 3 alunos e 4 semanas, `sizeof treinos` vale
`alunos * semanas * sizeof(int)`, isto é, `3 * 4 * 4 = 48` bytes (ISO/IEC,
2018). É uma das poucas situações em que o `sizeof` gera código em vez de
virar uma constante.

O VLA não aceita inicializador. `int v[n] = {0};` é erro no C17, porque o
compilador não sabe quantos zeros escrever (CPPREFERENCE, s.d.). Para
começar com tudo zerado, use um laço depois da declaração.

O uso mais útil do VLA é como **parâmetro** de função. Uma função comum que
recebe uma matriz precisa saber a largura dela na compilação, e por isso se
escreve `int m[][4]`: ela só serve para matrizes de 4 colunas. Com VLA, a
função recebe as dimensões junto com a matriz e serve para qualquer
tamanho: `void f(int l, int c, int m[l][c])`. A ordem importa: `l` e `c`
vêm **antes** de `m`, porque o tipo `m[l][c]` usa os dois, e um nome só pode
ser usado depois de declarado (ISO/IEC, 2018).

O VLA nem sempre está disponível. Ele era obrigatório no C99 e passou a ser
**opcional** no C11 e no C17. Um compilador que não oferece VLA define a
macro `__STDC_NO_VLA__`; o gcc e o clang oferecem, e o compilador da
Microsoft não. Um programa que depende de VLA pode exigir o recurso e
parar a compilação com uma mensagem clara:

```c
#ifdef __STDC_NO_VLA__
#error "este programa precisa de VLA"
#endif
```

O tipo VLA também serve para matrizes no heap. A declaração
`int (*m)[c] = malloc(l * sizeof *m);` cria um ponteiro para linhas de `c`
inteiros e pede `l` dessas linhas ao `malloc`. A matriz fica no heap, sem o
limite da pilha, e `m[i][j]` continua funcionando como numa matriz comum
(veja o A344).

> [!WARNING]
> O VLA não avisa quando falha. A pilha do Linux tem uns **8 MB**
> (`ulimit -s`): `int v[n]` com 3 milhões de `int` pede 12 MB e derruba o
> programa com *segmentation fault*. Um `n` vindo do usuário pode ser 0,
> negativo ou gigante. Use VLA só para tamanhos pequenos e conferidos; para
> o resto, `malloc`, que devolve `NULL`.

{{exemplo}}

Uma planilha de treinos em que alunos e semanas só chegam na digitação. Com 3
alunos e 4 semanas, ela tem 12 `int`: 48 bytes na pilha:

{{ideia}}

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

No fluxograma, a validação vem **antes** do VLA: depois da declaração não há
como desistir nem saber se deu certo:

{{fluxograma}}
