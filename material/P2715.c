// Lista · Módulo 27 · Detalhes de C que caem em prova
// Exercício P2715 · ★★☆ · O inverno em Gramado
//
// O programa abaixo compila sem nenhum aviso, mas as duas funções erram por
// misturar int e unsigned:
//
//   - media devolve a média das temperaturas, e sai um número absurdo;
//   - compara devolve -1, 0 ou 1 conforme a é menor, igual ou maior que b, e
//     diz que 3 é maior que 7.
//
// Conserte as duas sem mudar as assinaturas.
//
//   Saída esperada:
//   média: -2.00
//   compara(3, 7) = -1
//   compara(7, 3) = 1
//   compara(5, 5) = 0
//
// Dicas:
// 1. Em soma / n, o int soma vira unsigned (conversão aritmética usual):
//    -8 vira 4294967288. Converta para double antes de dividir.
// 2. a - b > 0 com unsigned é verdadeiro sempre que a != b. Compare a e b
//    direto.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

double media(const int *v, unsigned n) {
    int soma = 0;
    for (unsigned i = 0; i < n; i++) {
        soma += v[i];
    }
    return soma / n;
}

int compara(unsigned a, unsigned b) {
    if (a - b > 0) {
        return 1;
    }
    return a < b ? -1 : 0;
}

int main(void) {
    int temperaturas[] = {-3, 2, -5, -2};
    printf("média: %.2f\n", media(temperaturas, 4));
    printf("compara(3, 7) = %d\n", compara(3, 7));
    printf("compara(7, 3) = %d\n", compara(7, 3));
    printf("compara(5, 5) = %d\n", compara(5, 5));
    return 0;
}
