// 0011 · Juntando tudo
// Exercício E065 · ★★★
//
// Resposta: (1) "#define META 6.0;" fazia a linha da diferença virar
// "double diferenca = 6.0; - media;": a diferença ficava 6.0 e o "- media;"
// virava uma instrução solta (aviso "statement with no effect"). (2) soma é
// double: no scanf, %lf. (3) faltava o & em scanf("%d", alunos): o programa
// quebrava. (4) printf com %d para um double: %.2f. (5) "acima da meta" é
// media - META; META - media dava -0.90.

#include <stdio.h>

#define META 6.0

int main(void) {
    double soma;
    int alunos;

    scanf("%lf", &soma);
    scanf("%d", &alunos);

    double media = soma / alunos;
    double diferenca = media - META;

    printf("Soma das notas: %.1f\n", soma);
    printf("Alunos: %d\n", alunos);
    printf("Média: %.2f\n", media);
    printf("Acima da meta em %.2f ponto\n", diferenca);
    return 0;
}
