// Lista · Módulo 04 · Funções e modularização
// Exercício P0424 · ★★★ · Goldbach nos anos pares
//
// A conjectura de Goldbach diz que todo par maior que 2 é a soma de dois
// primos. Ninguém provou, mas ninguém achou exceção. Escreva "bool
// eh_primo(int n)", "int menor_parcela(int n)" (o menor primo p tal que n − p
// também é primo) e "int formas(int n)" (quantos pares p ≤ q de primos somam
// n). Mostre a decomposição com a menor parcela para os anos pares de 2020 a
// 2030 e de quantas formas dá para escrever 2026:
//
//   Saída esperada:
//   2020 = 3 + 2017
//   2022 = 5 + 2017
//   2024 = 7 + 2017
//   2026 = 23 + 2003
//   2028 = 11 + 2017
//   2030 = 3 + 2027
//   2026 pode ser escrito de 32 formas
//
// Dicas:
// 1. eh_primo: menor que 2 não é; teste divisores d com d * d <= n.
// 2. menor_parcela: para p de 2 em diante, devolva o primeiro p com eh_primo(p)
//    && eh_primo(n - p).
// 3. formas: conte os p de 2 até n / 2 que funcionam.
// 4. Resposta esperada: as sete linhas acima.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
