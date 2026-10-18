// 0038 · Recursão na prática: Fibonacci, Hanói e Euclides
// Exercício E228 · ★★★
//
// Esta Torre de Hanói compila sem aviso e faz 7 movimentos, mas está errada.
// Siga os movimentos com três pilhas de moedas (ou no papel) e ache o primeiro
// movimento ilegal (disco maior sobre um menor) ou o problema no final.
// Explique o erro e conserte. A saída certa é a do A076.
//
// Dicas:
// 1. No passo 1 da receita, os n - 1 discos vão para a estaca AUXILIAR.
//    Confira para onde a primeira chamada recursiva manda.
// 2. Siga os dois primeiros movimentos: onde está o disco 1 quando o disco 2
//    se move? E no movimento 3, tem algum disco em B?
// 3. Resposta esperada: a primeira chamada recursiva repete a ordem das
//    estacas, hanoi(n - 1, origem, destino, auxiliar), e manda os n - 1 discos
//    para o destino, justo onde o maior vai cair. Já no movimento 2 o disco 2
//    cai sobre o disco 1 (ilegal), e no 3 o programa tira um disco de B, que
//    está vazia. O certo é hanoi(n - 1, origem, auxiliar, destino).
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

int movimentos = 0;

void hanoi(int n, char origem, char destino, char auxiliar) {
    if (n == 0) {
        return;
    }
    hanoi(n - 1, origem, destino, auxiliar);
    movimentos++;
    printf("%d. disco %d: %c -> %c\n", movimentos, n, origem, destino);
    hanoi(n - 1, auxiliar, destino, origem);
}

int main(void) {
    hanoi(3, 'A', 'C', 'B');
    printf("Total: %d movimentos\n", movimentos);
    return 0;
}
