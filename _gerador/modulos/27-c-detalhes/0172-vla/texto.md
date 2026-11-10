## 0172 · Vetor de tamanho variável (VLA)

Numa planilha de treinos, alunos e semanas só são conhecidos na digitação.
Até aqui, as saídas eram uma matriz enorme "por garantia" ou o `malloc`.

O C99 trouxe o **VLA** (*variable length array*): um vetor local cujo tamanho
é uma expressão calculada na hora, como `int treinos[alunos][semanas];`. Ele
mora na **pilha** e some no fim do bloco, sem `free`.

Com VLA, `sizeof treinos` é calculado **na execução**: `alunos * semanas *
sizeof(int)`. O VLA não pode ser `static` nem global e não aceita
inicialização (`int v[n] = {0};` é erro no C17): use um laço.

O uso mais útil é como **parâmetro**. Uma função comum precisa da largura da
matriz ao compilar (`int m[][4]`); com VLA, ela recebe as dimensões e a
matriz: `void f(int l, int c, int m[l][c])`. `l` e `c` vêm **antes**, porque o
tipo `m[l][c]` usa os dois.

O VLA é obrigatório no C99 e **opcional** no C11 e no C17: o compilador sem
VLA define `__STDC_NO_VLA__` (o da Microsoft não suporta; gcc e clang sim).
Para exigir VLA:

```c
#ifdef __STDC_NO_VLA__
#error "este programa precisa de VLA"
#endif
```

Com 3 alunos e 4 semanas, a planilha tem 12 `int`: 48 bytes na pilha:

{{ideia}}

O programa lê as dimensões, confere, cria o VLA e o passa às funções:

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

No fluxograma, a validação vem **antes** do VLA: depois da linha, não há como
desistir nem saber se deu certo:

{{fluxograma}}

> [!WARNING]
> O VLA não avisa quando falha. A pilha no Linux tem uns **8 MB** (veja com
> `ulimit -s`): `int v[n]` com `n` igual a 3 milhões pede 12 MB e derruba o
> programa com *segmentation fault*. Um `n` do usuário pode ser 0, negativo
> ou gigante. Use VLA só para tamanhos **pequenos e conferidos**; para o
> resto, `malloc`, que devolve `NULL` quando falta memória.

> [!TIP]
> `int (*m)[c] = malloc(l * sizeof *m);` cria no heap uma matriz com tipo
> VLA, e `m[i][j]` continua valendo (veja o A344).

> [!NOTE]
> **Pergunta para você:** se o professor digitar `100 52`, quantos bytes o
> `sizeof treinos` mostra? E quantas planilhas desse tamanho caberiam numa
> pilha de 8 MB?

{{pratique}}
