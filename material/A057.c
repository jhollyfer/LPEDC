// A057 · O parâmetro casa pela posição, não pelo nome

#include <stdio.h>

double com_desconto(double preco, double percentual);
void contagem(int segundos);

int main(void) {
    double preco = 80.00;
    double percentual = 25;

    // certo: o 1º argumento vai para o 1º parâmetro, o 2º para o 2º
    printf("Certo: R$ %.2f\n", com_desconto(preco, percentual));

    // trocado: os nomes iguais não ajudam, o C só olha a ordem
    printf("Trocado: R$ %.2f\n", com_desconto(percentual, preco));

    // literal e expressão também servem: a função recebe só o valor
    printf("Literal: R$ %.2f\n", com_desconto(200, 10 + 5));

    int tempo = 3;
    contagem(tempo);
    printf("No main, tempo continua %d\n", tempo);
    return 0;
}

double com_desconto(double preco, double percentual) {
    return preco - preco * percentual / 100;
}

// o parâmetro é uma variável de trabalho: pode diminuir até zero
void contagem(int segundos) {
    while (segundos > 0) {
        printf("%d... ", segundos);
        segundos--;
    }
    printf("já!\n");
}
// Saída:
// Certo: R$ 60.00
// Trocado: R$ 5.00
// Literal: R$ 170.00
// 3... 2... 1... já!
// No main, tempo continua 3
