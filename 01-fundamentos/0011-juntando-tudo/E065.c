// 0011 · Juntando tudo
// Exercício E065 · ★★★
//
// Este programa calcula a média da turma no simulado, mas tem CINCO erros
// de propósito, de assuntos diferentes do módulo. Ele compila, com uma
// porção de avisos, e quebra ao rodar. Conserte um por vez, rodando de novo
// a cada conserto, até sair a saída esperada.
//
//   Exemplo de execução (depois de consertar):
//   Soma das notas: 172.5
//   Alunos: 25
//   Média: 6.90
//   Acima da meta em 0.90 ponto
//
// Teste: printf '172.5\n25\n' | ~/LPEDC/rodar E065.c
//
// Dicas:
// 1. Leia os avisos: dois são de scanf (o & e o especificador do double) e
//    um é de printf.
// 2. O aviso "statement with no effect" é estranho: escreva a linha da
//    diferença com o #define colado, ; inclusive.
// 3. Com isso resolvido, um erro ainda fica sem aviso: confira o sinal da
//    diferença na mão.
// 4. Resposta esperada: (1) tire o ; de "#define META 6.0;" (a linha virava
//    "diferenca = 6.0; - media;"); (2) soma é
//    double: scanf("%lf", &soma); (3) faltou o & em scanf("%d", alunos);
//    (4) o printf da média usa %d com double: %.2f; (5) META - media dá
//    -0.90: a diferença acima da meta é media - META.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

#define META 6.0;

int main(void) {
    double soma;
    int alunos;

    scanf("%f", &soma);
    scanf("%d", alunos);

    double media = soma / alunos;
    double diferenca = META - media;

    printf("Soma das notas: %.1f\n", soma);
    printf("Alunos: %d\n", alunos);
    printf("Média: %d\n", media);
    printf("Acima da meta em %.2f ponto\n", diferenca);
    return 0;
}
