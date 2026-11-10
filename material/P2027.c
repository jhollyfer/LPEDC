// Lista · Módulo 20 · Divisão e conquista e algoritmos gulosos
// Exercício P2027 · ★★★ · Quantos passaram?
//
// Este programa tem um erro de propósito. As notas da turma (vezes 10,
// para ficar em inteiros) estão em ordem crescente, com repetições:
//
//   35 40 50 60 70 70 70 85 90 100
//
// Aprovado é quem tem nota >= 70. A função primeira(v, ini, fim, x) devia
// devolver, por busca binária recursiva, o índice do PRIMEIRO elemento >=
// x (ou n, se nenhum for); os aprovados são n menos esse índice. Ela
// compila sem aviso e roda limpo, mas diz que só 3 passaram, e para nota de
// corte 50 diz 7. Conserte a função (o main está certo).
//
//   Saída esperada:
//   Corte 70: 6 aprovados
//   Corte 50: 8 aprovados
//   Corte 101: 0 aprovados
//
// Dicas:
// 1. Acrescente um printf com ini, fim e meio em cada chamada e veja o que
//    acontece quando v[meio] é igual a x.
// 2. Se v[meio] >= x, o meio PODE ser a resposta (ou haverá outra igual
//    antes dele): procure em [ini, meio], sem jogar o meio fora. Se v[meio]
//    < x, a resposta está em [meio + 1, fim].
// 3. Resposta esperada: troque o > por >= no teste. 6 aprovados com corte
//    70, 8 com corte 50 e 0 com corte 101.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

#define N 10

// procura em v[ini..fim]; fim == ini quer dizer "é este índice"
int primeira(const int v[], int ini, int fim, int x) {
    if (ini == fim) {
        return ini;
    }
    int meio = ini + (fim - ini) / 2;
    if (v[meio] > x) {
        return primeira(v, ini, meio, x);
    }
    return primeira(v, meio + 1, fim, x);
}

int main(void) {
    const int nota[N] = {35, 40, 50, 60, 70, 70, 70, 85, 90, 100};
    const int corte[3] = {70, 50, 101};
    for (int i = 0; i < 3; i++) {
        int p = primeira(nota, 0, N, corte[i]); // N é a resposta "nenhum"
        printf("Corte %d: %d aprovados\n", corte[i], N - p);
    }
    return 0;
}
