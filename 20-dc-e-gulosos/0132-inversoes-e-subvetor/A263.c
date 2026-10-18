// A263 · A melhor sequência de dias, dividindo ao meio

#include <stdio.h>

typedef struct {
    int soma;
    int ini, fim; // a faixa v[ini..fim]
} Faixa;

// melhor faixa que CRUZA o meio: obrigatoriamente contém v[meio] e v[meio + 1]
Faixa cruzando(const int v[], int ini, int meio, int fim) {
    Faixa f = {0, meio, meio + 1};
    int soma = 0, melhor_esq = v[meio];
    for (int i = meio; i >= ini; i--) {      // do meio para a esquerda
        soma += v[i];
        if (soma >= melhor_esq) {
            melhor_esq = soma;
            f.ini = i;
        }
    }
    soma = 0;
    int melhor_dir = v[meio + 1];
    for (int j = meio + 1; j <= fim; j++) {  // do meio para a direita
        soma += v[j];
        if (soma > melhor_dir) {
            melhor_dir = soma;
            f.fim = j;
        }
    }
    f.soma = melhor_esq + melhor_dir;
    return f;
}

// melhor faixa de v[ini..fim]
Faixa melhor(const int v[], int ini, int fim) {
    if (ini == fim) {
        return (Faixa){v[ini], ini, fim};   // um dia só
    }
    int meio = ini + (fim - ini) / 2;
    Faixa e = melhor(v, ini, meio);         // inteira na esquerda
    Faixa d = melhor(v, meio + 1, fim);     // inteira na direita
    Faixa c = cruzando(v, ini, meio, fim);  // cruzando o meio
    if (e.soma >= d.soma && e.soma >= c.soma) return e;
    if (d.soma >= c.soma) return d;
    return c;
}

int main(void) {
    // lucro de uma barraca de praia em 10 dias (R$); chuva dá prejuízo
    int lucro[] = {120, -80, 200, -50, -90, 300, 150, -400, 180, 60};
    int n = 10;

    Faixa f = melhor(lucro, 0, n - 1);
    printf("Melhor sequência: dia %d ao dia %d\n", f.ini, f.fim);
    printf("Dias:");
    for (int i = f.ini; i <= f.fim; i++) {
        printf(" %d", lucro[i]);
    }
    printf("\nLucro somado: R$ %d\n", f.soma);
    // repare: a melhor faixa engole dois dias de prejuízo (-50 e -90) para
    // juntar os dias bons dos dois lados

    return 0;
}
// Saída:
// Melhor sequência: dia 0 ao dia 6
// Dias: 120 -80 200 -50 -90 300 150
// Lucro somado: R$ 550
