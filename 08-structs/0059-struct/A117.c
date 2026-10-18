// A117 · A matrícula na academia

#include <stddef.h>
#include <stdio.h>

struct aluno {
    char plano;       // 'M' mensal, 'T' trimestral, 'A' anual
    int faltas;       // faltas no mês
    double mensalidade;
    int armario;      // 0 = sem armário
};

int main(void) {
    // com nome de campo, a ordem é livre; quem não aparece começa com zero
    struct aluno caio = {.mensalidade = 99.90, .plano = 'M'};
    printf("Caio: plano %c, R$ %.2f, %d faltas, armário %d\n",
           caio.plano, caio.mensalidade, caio.faltas, caio.armario);

    // literal composto: troca a struct inteira de uma vez
    caio = (struct aluno){'A', 0, 79.90, 12};
    printf("Caio: plano %c, R$ %.2f, %d faltas, armário %d\n",
           caio.plano, caio.mensalidade, caio.faltas, caio.armario);

    // comparar structs: campo a campo (== entre structs não compila)
    struct aluno duda = caio;
    duda.armario = 13;
    if (duda.plano == caio.plano && duda.mensalidade == caio.mensalidade) {
        printf("Duda e Caio têm o mesmo plano\n");
    }
    if (duda.armario != caio.armario) {
        printf("mas armários diferentes: %d e %d\n", duda.armario, caio.armario);
    }

    // onde cada campo começa dentro da struct
    printf("plano em %zu, faltas em %zu, mensalidade em %zu, armario em %zu\n",
           offsetof(struct aluno, plano), offsetof(struct aluno, faltas),
           offsetof(struct aluno, mensalidade), offsetof(struct aluno, armario));
    // 16 + 4 = 20, mas o total arredonda para múltiplo de 8 (o double): 24
    printf("sizeof: %zu bytes\n", sizeof(struct aluno));
    return 0;
}
// Saída:
// Caio: plano M, R$ 99.90, 0 faltas, armário 0
// Caio: plano A, R$ 79.90, 0 faltas, armário 12
// Duda e Caio têm o mesmo plano
// mas armários diferentes: 13 e 12
// plano em 0, faltas em 4, mensalidade em 8, armario em 16
// sizeof: 24 bytes
