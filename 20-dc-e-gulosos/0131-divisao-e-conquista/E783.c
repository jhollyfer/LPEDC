// 0131 · Divisão e conquista
// Exercício E783 · ★★☆
//
// Este programa calcula 3^20 certinho, mas está lento: conta 63 chamadas,
// quando a potência rápida faria 6. Rode, ache a linha que estraga a
// divisão e conquista e conserte, sem mudar o resultado.
//
//   Saída que aparece:
//   3^20 = 3486784401
//   Chamadas: 63
//
//   Saída esperada:
//   3^20 = 3486784401
//   Chamadas: 6
//
// Depois do conserto, troque 20 por 39 nas duas versões (a sua e a
// original, num arquivo à parte) e compare as chamadas: a original faz 127
// e a sua, 7. (Não vá além de 39: 3^40 estoura o long long.)
//
// Dicas:
// 1. Quantas vezes a função chama a si mesma em cada nível?
// 2. Com duas chamadas por nível, a conta é C(n) = 1 + 2·C(n/2): 3, 7, 15,
//    31, 63. É uma árvore de recursão inteira, e não um caminho.
// 3. Resposta esperada: guarde potencia(x, n / 2) numa variável (metade) e
//    use metade * metade. Chamadas: 6.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

static int chamadas = 0;

long long potencia(long long x, int n) {
    chamadas++;
    if (n == 0) {
        return 1;
    }
    if (n % 2 == 0) {
        return potencia(x, n / 2) * potencia(x, n / 2);
    }
    return potencia(x, n / 2) * potencia(x, n / 2) * x;
}

int main(void) {
    printf("3^20 = %lld\n", potencia(3, 20));
    printf("Chamadas: %d\n", chamadas);
    return 0;
}
