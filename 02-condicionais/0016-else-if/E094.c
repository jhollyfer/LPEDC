// 0016 · else if, if aninhado e o else pendurado
// Exercício E094 · ★★☆
//
// O conceito deveria ser A (nota 9 ou mais), B (7 ou mais), C (5 ou mais)
// ou D (abaixo de 5). Mas quem tirou 9.5 recebeu C. O programa compila sem
// nenhum aviso: o erro é de lógica. Ache e conserte.
//
// Dicas:
// 1. Com 9.5, qual é a primeira condição verdadeira?
// 2. O else if para no primeiro Sim. Uma nota alta também é >= 5.
// 3. Resposta esperada: as condições estão na ordem errada; teste primeiro
//    >= 9, depois >= 7, depois >= 5. Consertado: 9.5 → A; 7.0 → B;
//    5.5 → C; 3.0 → D.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

int main(void) {
    double nota;
    printf("Nota: ");
    if (scanf("%lf", &nota) != 1) {
        printf("Entrada inválida\n");
        return 1;
    }

    if (nota >= 5) {
        printf("Conceito C\n");
    } else if (nota >= 7) {
        printf("Conceito B\n");
    } else if (nota >= 9) {
        printf("Conceito A\n");
    } else {
        printf("Conceito D\n");
    }
    return 0;
}
