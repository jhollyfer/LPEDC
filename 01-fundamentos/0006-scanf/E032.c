// 0006 · scanf
// Exercício E032 · ★☆☆
//
// Este programa compila com DOIS avisos e, quando roda, quebra ou mostra
// lixo. Rode com printf '42\n80.5\n' | ~/LPEDC/rodar E032.c, leia os avisos
// e o relatório do AddressSanitizer, e conserte.
//
//   Exemplo de execução (depois de consertar):
//   Número do calçado: 42
//   Peso (kg): 80.5
//   Calçado 42, peso 80.5 kg
//
// Dicas:
// 1. Procure "expects argument of type 'int *'" e "'float *'" nos avisos.
// 2. O scanf precisa do endereço da variável. E o tipo da variável decide
//    o especificador.
// 3. Resposta esperada: faltou o & em scanf("%d", calcado): o scanf usou o
//    VALOR de calcado (0) como endereço e tentou escrever no endereço 0
//    ("SEGV on unknown address 0x000000000000"); e peso é double, então o
//    scanf usa %lf, não %f.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

int main(void) {
    int calcado = 0;
    double peso = 0;

    printf("Número do calçado: ");
    scanf("%d", calcado);
    printf("Peso (kg): ");
    scanf("%f", &peso);

    printf("Calçado %d, peso %.1f kg\n", calcado, peso);
    return 0;
}
