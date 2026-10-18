// 0032 · Juntando tudo
// Exercício E187 · ★☆☆
//
// No craps, o 7 é o número mais perigoso (e o mais comum). Lance dois dados
// 36 000 vezes (com srand(time(NULL))) e conte quantas vezes a soma deu 7 e
// quantas deu 2. Mostre as contagens e as porcentagens com 1 casa:
//
//   Exemplo de saída (os números mudam a cada execução):
//   Soma 7: 6043 (16.8%)
//   Soma 2: 1012 (2.8%)
//
// Dicas:
// 1. Some dois sorteios separados: (1 + rand() % 6) + (1 + rand() % 6). Não
//    use 2 + rand() % 11: isso daria a mesma chance para todas as somas.
// 2. Porcentagem: 100.0 * contagem / 36000.
// 3. Resposta esperada: o 7 sai perto de 6000 vezes (1/6, 16.7%), porque 6 das
//    36 combinações dão 7. O 2 sai perto de 1000 (1/36, 2.8%): só 1 + 1.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

    return 0;
}
