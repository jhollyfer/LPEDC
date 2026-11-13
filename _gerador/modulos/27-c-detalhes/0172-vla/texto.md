## 0172 · Vetor de tamanho variável (VLA)

- **VLA** (*variable length array*): vetor local cujo tamanho é uma expressão
  calculada na execução, como `int treinos[alunos][semanas];`. Veio no C99
  (ISO/IEC, 2018).
- **Onde mora**: na **pilha**; some no fim do bloco, sem `free`. Não pode ser
  `static` nem global (CPPREFERENCE, s.d.).
- **`sizeof` na execução**: `sizeof treinos` vale `alunos * semanas *
  sizeof(int)`, calculado na hora (ISO/IEC, 2018).
- **Sem inicializador**: `int v[n] = {0};` é erro no C17; zere com um laço
  (CPPREFERENCE, s.d.).
- **VLA como parâmetro**: `void f(int l, int c, int m[l][c])`. As dimensões
  vêm **antes** da matriz, porque o tipo `m[l][c]` usa as duas
  (ISO/IEC, 2018).
- **Opcional desde o C11**: o compilador sem VLA define `__STDC_NO_VLA__`
  (gcc e clang têm; o da Microsoft não). Para exigir VLA:

```c
#ifdef __STDC_NO_VLA__
#error "este programa precisa de VLA"
#endif
```

- **VLA no heap**: `int (*m)[c] = malloc(l * sizeof *m);` cria a matriz no
  heap, e `m[i][j]` continua valendo (veja o A344).

> [!WARNING]
> O VLA não avisa quando falha. A pilha do Linux tem uns **8 MB** (`ulimit -s`):
> `int v[n]` com 3 milhões de `int` derruba o programa. Use VLA só para
> tamanhos pequenos e conferidos; para o resto, `malloc`, que devolve `NULL`.

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
