// 0020 · While
// Exercício E117 · ★★☆
//
// A caixa d'água tem 1000 litros e a casa gasta 180 litros por dia. O programa
// abaixo deveria dizer quantos dias COMPLETOS a água dura e quanto sobra, mas
// mostra:
//
//   Dá para 6 dias. Sobram -80 litros.
//
// O código com o erro está logo abaixo; ele roda, mas dá a resposta errada.
// Conserte e rode de novo até aparecer a resposta certa. Se ajudar, ponha um
// printf dentro do laço mostrando litros e dias a cada volta.
//
// Dicas:
// 1. No 6º dia, quanta água havia antes de gastar? Dava para o dia inteiro?
// 2. A pergunta do while precisa ser "tem água para MAIS UM dia inteiro?".
// 3. Resposta esperada: troque "litros > 0" por "litros >= consumo". Saída:
//    "Dá para 5 dias. Sobram 100 litros."
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

int main(void) {
    int litros = 1000;
    int consumo = 180;
    int dias = 0;

    while (litros > 0) {
        litros = litros - consumo;
        dias++;
    }
    printf("Dá para %d dias. Sobram %d litros.\n", dias, litros);
    return 0;
}
