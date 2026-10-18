// 0029 · Parâmetros e passagem por valor
// Exercício E173 · ★★★
//
// O boletim abaixo calcula a média de duas notas inteiras, mas mostra
// "media(7, 8) = 7.0". Cada argumento é convertido para o tipo do parâmetro,
// e o valor do return é convertido para o tipo da função: o problema está
// numa dessas conversões. Rode e veja.
//
// Depois:
//   1. conserte media sem mudar os tipos dos parâmetros (continuam int);
//   2. escreva "int arredondar(double x)", que arredonda para o inteiro mais
//      próximo (x >= 0), sem math.h, e tire as barras das duas linhas
//      comentadas do main.
// A linha de metade(7.9) não muda: ela mostra outra conversão acontecendo.
//
//   Saída esperada:
//   metade(7.9) = 3
//   media(7, 8) = 7.5
//   media(9, 10) = 9.5
//   arredondar(7.5) = 8
//   arredondar(media(6, 7)) = 7
//
// Dicas:
// 1. Em media, a e b são int: (a + b) / 2 é divisão inteira, e só depois o
//    resultado vira double. Basta um dos lados da divisão ser double: 2.0.
// 2. arredondar: some 0.5 e deixe a conversão para int cortar a parte
//    decimal: return x + 0.5; (o return converte para int sozinho).
// 3. Resposta esperada: a saída acima. 7.9 entra num parâmetro int e vira 7
//    antes da conta: 7 / 2 = 3. media(6, 7) = 6.5, e 6.5 + 0.5 = 7.0 vira 7.
//
// Escreva sua resposta abaixo (conserte e complete o código):

#include <stdio.h>

int metade(int x) {
    return x / 2;
}

double media(int a, int b) {
    return (a + b) / 2;
}

int main(void) {
    printf("metade(7.9) = %d\n", metade(7.9));
    printf("media(7, 8) = %.1f\n", media(7, 8));
    printf("media(9, 10) = %.1f\n", media(9, 10));
    // printf("arredondar(7.5) = %d\n", arredondar(7.5));
    // printf("arredondar(media(6, 7)) = %d\n", arredondar(media(6, 7)));
    return 0;
}
