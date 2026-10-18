// 0090 · Busca binária
// Exercício E535 · ★☆☆
//
// Os armários livres do vestiário do clube estão numa lista ordenada, e o
// programa abaixo procura números nela. Deixe a busca "falar" o que está
// fazendo:
//
// a) no printf de cada volta, mostre também ini e fim;
// b) conte as voltas numa variável e mostre o total no "achou" e no
//    "não achou";
// c) no "não achou", mostre ainda os valores de ini e fim que pararam o laço;
// d) no main, procure também o 62, o último armário.
//
//   Saída esperada:
//   Procurando 47
//   ini=0 fim=8 meio=4 (30)
//   ini=5 fim=8 meio=6 (47)
//   achou na posição 6 em 2 voltas
//   Procurando 5
//   ini=0 fim=8 meio=4 (30)
//   ini=0 fim=3 meio=1 (9)
//   ini=0 fim=0 meio=0 (4)
//   não achou em 3 voltas (parou com ini=1 fim=0)
//   Procurando 62
//   ini=0 fim=8 meio=4 (30)
//   ini=5 fim=8 meio=6 (47)
//   ini=7 fim=8 meio=7 (55)
//   ini=8 fim=8 meio=8 (62)
//   achou na posição 8 em 4 voltas
//
// Dicas:
// 1. Crie int voltas = 0; antes do while e some 1 logo depois de calcular meio.
// 2. O printf da volta fica: printf("ini=%d fim=%d meio=%d (%d)\n", ...).
// 3. O laço para quando ini fica maior que fim: é isso que o "não achou"
//    vai mostrar.
// 4. Resposta esperada: a saída acima. Repare que o 62 custa 4 voltas, o
//    máximo para 9 elementos.
//
// Escreva sua resposta abaixo (modifique o código):

#include <stdio.h>

void procura(const int v[], int n, int x) {
    int ini = 0, fim = n - 1;
    printf("Procurando %d\n", x);
    while (ini <= fim) {
        int meio = ini + (fim - ini) / 2;
        printf("meio=%d (%d)\n", meio, v[meio]);
        if (v[meio] == x) {
            printf("achou na posição %d\n", meio);
            return;
        }
        if (v[meio] < x) {
            ini = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    printf("não achou\n");
}

int main(void) {
    int armarios[] = {4, 9, 13, 21, 30, 38, 47, 55, 62};
    procura(armarios, 9, 47);
    procura(armarios, 9, 5);
    return 0;
}
