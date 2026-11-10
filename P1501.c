// Lista · Módulo 15 · Tabelas hash
// Exercício P1501 · ★☆☆ · Cem baldes ou noventa e sete?
//
// Os números de pedido de uma loja online terminam sempre em 00 ou 50:
// 31250, 48700, 52150, 61900, 77350, 80200, 93450, 15600. Escreva
// void distribui(const int chaves[], int n, int m), que usa o método da
// divisão, h(k) = k % m, e mostra quantos baldes foram usados, quantas
// colisões houve (em cada balde, todo mundo depois do primeiro conta como
// colisão) e o balde de cada pedido. Rode com m = 100 e com m = 97.
//
//   Saída esperada:
//   m = 100: baldes usados 2, colisões 6
//     31250 -> 50
//     48700 -> 0
//     52150 -> 50
//     61900 -> 0
//     77350 -> 50
//     80200 -> 0
//     93450 -> 50
//     15600 -> 0
//   m = 97: baldes usados 8, colisões 0
//     31250 -> 16
//     48700 -> 6
//     52150 -> 61
//     61900 -> 14
//     77350 -> 41
//     80200 -> 78
//     93450 -> 39
//     15600 -> 80
//
// Dicas:
// 1. Um vetor int conta[100] = {0} serve para os dois tamanhos.
// 2. Com m = 100, o resto é só os dois últimos dígitos: o padrão dos dados
//    vira o padrão dos baldes. Um primo longe de potências de 10 e de 2
//    mistura todos os dígitos.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
