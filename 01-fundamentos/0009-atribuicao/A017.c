// A017 · Vagas que descem, senhas que sobem (até de letra)

#include <stdio.h>

int main(void) {
    // -- conta para baixo: cada carro que entra ocupa uma vaga
    int vagas = 3;
    vagas--;                 // 2
    vagas--;                 // 1
    printf("Vagas livres: %d\n", vagas);

    // ++ num char: o char é número, então ++ vai para a próxima letra
    char fila = 'A';
    int senha = 41;
    printf("Chamando %c%02d\n", fila, senha);
    senha++;
    printf("Chamando %c%02d\n", fila, senha);
    fila++;                  // 'A' (65) vira 'B' (66)
    senha = 1;               // a fila nova recomeça do 1
    printf("Chamando %c%02d\n", fila, senha);

    // /= com int faz divisão inteira: a moeda ímpar some
    int moedas = 25;
    moedas /= 2;
    printf("Cada irmão fica com %d moedas\n", moedas);

    // -= com double: o desconto sai do valor que já está lá
    double conta = 120.00;
    conta -= 15.50;          // cupom
    conta -= conta * 0.10;   // mais 10% sobre o que sobrou
    printf("Conta final: R$ %.2f\n", conta);
    return 0;
}
// Saída:
// Vagas livres: 1
// Chamando A41
// Chamando A42
// Chamando B01
// Cada irmão fica com 12 moedas
// Conta final: R$ 94.05
