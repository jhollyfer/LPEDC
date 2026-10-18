// A264 · Kadane: a soma máxima numa passada só

#include <stdio.h>

// a melhor faixa que TERMINA no dia i ou é o próprio dia i (começar de novo)
// ou é a melhor que terminava no dia i - 1 com o dia i grudado no fim.
// Guardando só esse número, uma passada resolve: O(n), sem recursão.
void kadane(const char *rotulo, const int v[], int n) {
    int aqui = v[0], ini_aqui = 0;          // melhor faixa que termina em i
    int melhor = v[0], ini = 0, fim = 0;    // melhor faixa vista até agora
    for (int i = 1; i < n; i++) {
        if (aqui + v[i] < v[i]) {
            aqui = v[i];                    // o passado só atrapalha: recomeça
            ini_aqui = i;
        } else {
            aqui += v[i];                   // vale a pena continuar
        }
        if (aqui > melhor) {
            melhor = aqui;
            ini = ini_aqui;
            fim = i;
        }
    }
    printf("%-10s rodadas %d a %d, saldo %+d\n", rotulo, ini + 1, fim + 1, melhor);
}

int main(void) {
    // saldo de gols de dois times, rodada a rodada
    int tigre[] = {2, -1, -3, 4, -1, 2, 1, -5, 4, 1};
    int lanterna[] = {-2, -1, -4, -1, -3}; // perdeu todas

    kadane("Tigre:", tigre, 10);
    kadane("Lanterna:", lanterna, 5);
    // com tudo negativo, a melhor faixa é a menos ruim: um jogo só (-1).
    // Começar "aqui" e "melhor" com 0 em vez de v[0] daria saldo 0 numa faixa
    // vazia, o que não é uma sequência de rodadas.
    return 0;
}
// Saída:
// Tigre:     rodadas 4 a 7, saldo +6
// Lanterna:  rodadas 2 a 2, saldo -1
