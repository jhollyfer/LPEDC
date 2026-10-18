// 0039 · Matrizes
// Exercício E233 · ★★★
//
// Dois alunos fizeram 4 provas cada (uma linha por aluno, uma coluna por
// prova). O programa deveria mostrar a média de cada aluno, mas tem DOIS erros
// de propósito. Rode com o rodar: o sanitizer acusa um deles. O outro só dá
// resultado errado. Ache, explique e conserte os dois.
//
//   Saída esperada depois do conserto:
//   Aluno 1: média 7.50
//   Aluno 2: média 7.25
//
// Dicas:
// 1. Quantas linhas e quantas colunas a matriz tem? E até onde vai cada laço?
// 2. Mesmo com os laços certos, o aluno 1 sairia com média 7.00. Por quê?
//    (assunto 0007: divisão inteira)
// 3. Resposta esperada: os limites estão trocados (o laço dos alunos vai até
//    4 e lê notas[2], notas[3]: linhas que não existem; o das provas vai só
//    até 2); e soma / 4 é divisão de int por int, que joga fora o ,50
//    (use soma / 4.0).
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

int main(void) {
    int notas[2][4] = {
        {7, 8, 6, 9},
        {5, 10, 8, 6},
    };

    for (int a = 0; a < 4; a++) {
        int soma = 0;
        for (int p = 0; p < 2; p++) {
            soma += notas[a][p];
        }
        double media = soma / 4;
        printf("Aluno %d: média %.2f\n", a + 1, media);
    }
    return 0;
}
