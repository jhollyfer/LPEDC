// Lista · Módulo 05 · Vetores, matrizes e strings
// Exercício P0530 · ★★★ · O fatorial que não cabe no long long
//
// O fatorial de 30 tem 33 dígitos, e um unsigned long long vai só até uns
// 1,8 x 10^19 (20 dígitos). Calcule 30! guardando o número num vetor de
// dígitos, int d[60], com o dígito das unidades em d[0], o das dezenas em
// d[1], e assim por diante, e um int tam com quantos dígitos estão em uso.
//
// Escreva void multiplicar(int d[], int tam[1], int k), que multiplica o
// número por um int pequeno k (até 100) e atualiza tam[0] (um vetor de uma
// posição volta alterado para o main, como o erro[] do P0512), do jeito que
// se faz à mão: dígito a dígito, levando o "vai um". Mostre 10!, 20!, 25! e
// 30!, com o número de dígitos de cada um:
//
//   Saída esperada:
//   10! = 3628800 (7 dígitos)
//   20! = 2432902008176640000 (19 dígitos)
//   25! = 15511210043330985984000000 (26 dígitos)
//   30! = 265252859812191058636308480000000 (33 dígitos)
//
// Dicas:
// 1. Comece com d[0] = 1 e tam[0] = 1 (o número 1).
// 2. Para multiplicar por k: vai = 0; para i de 0 a tam - 1, faça
//    x = d[i] * k + vai; d[i] = x % 10; vai = x / 10.
// 3. Depois do laço, o "vai" que sobrou vira dígitos novos no fim: enquanto
//    vai > 0, d[tam++] = vai % 10 e vai /= 10.
// 4. Para mostrar, ande de d[tam - 1] até d[0]: o dígito mais importante
//    está no fim do vetor.
// 5. Resposta esperada: a saída acima (30! =
//    265252859812191058636308480000000).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
