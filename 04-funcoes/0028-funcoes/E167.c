// 0028 · Funções
// Exercício E167 · ★★★
//
// A função ajusta, já pronta no arquivo, tem três return. Só o primeiro que
// for alcançado vale: os testes de baixo nem são feitos.
//
// Escreva "int passos(int n)", que aplica ajusta em n repetidas vezes até
// n chegar a 1, mostrando cada valor no caminho, e devolve quantas vezes
// aplicou. No main, use passos para 7, 14 e 30 e mostre o total de cada um,
// e mostre também ajusta(dobro(7)), resolvida de dentro para fora.
//
//   Saída esperada:
//   7: 8 4 2 1 (4 passos)
//   14: 4 2 1 (3 passos)
//   30: 20 10 5 6 3 4 2 1 (8 passos)
//   ajusta(dobro(7)) = 4
//
// Dicas:
// 1. Dentro de passos, um while (n != 1) com n = ajusta(n), um printf e um
//    contador. O parâmetro n é uma cópia: pode mudar à vontade.
// 2. O main mostra "7: ", chama passos(7) e depois mostra "(%d passos)" com o
//    retorno. Guarde o retorno numa variável antes do printf, para os números
//    do caminho saírem antes do total.
// 3. Resposta esperada: a saída acima. Em dobro, o printf depois do return
//    nunca roda: o return encerra a função na hora.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int dobro(int n) {
    return 2 * n;
    printf("nunca aparece\n");
}

int ajusta(int n) {
    if (n > 10) {
        return n - 10;
    }
    if (n % 2 == 0) {
        return n / 2;
    }
    return n + 1;
}

int main(void) {

    return 0;
}
