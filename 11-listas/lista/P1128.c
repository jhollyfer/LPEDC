// Lista · Módulo 11 · Listas
// Exercício P1128 · ★★★ · A esteira do sushi em ordem de preço
//
// Os pratos da esteira do restaurante giram em círculo e ficam em ordem de
// preço: do mais barato até o mais caro, e depois do mais caro volta o
// mais barato. A esteira é uma lista circular guardada pelo ÚLTIMO nó (o
// prato mais caro). Escreva
//
//   No *insere_ordenado(No *ultimo, int preco)
//
// que encaixa o prato no lugar certo e devolve o (possivelmente novo)
// último. Ponha, nesta ordem, pratos de 30, 10, 50, 20, 40, 60 e 5 reais,
// mostrando a esteira (do primeiro ao último) depois de cada um.
//
//   Saída esperada:
//   30 | último: 30
//   10 30 | último: 30
//   10 30 50 | último: 50
//   10 20 30 50 | último: 50
//   10 20 30 40 50 | último: 50
//   10 20 30 40 50 60 | último: 60
//   5 10 20 30 40 50 60 | último: 60
//
// Dicas:
// 1. Esteira vazia: o novo aponta para si mesmo e é o último.
// 2. Se o preço é >= ao do último, o novo entra DEPOIS do último e vira o
//    novo último. Isso cobre o "mais caro de todos".
// 3. Senão, ande p a partir do último enquanto p->prox->preco <= preco e
//    encaixe depois de p. O laço sempre para, porque o último é mais caro.
//    O "mais barato de todos" cai aqui: entra logo depois do último, sem
//    mudar quem é o último.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int preco;
    struct no *prox;
} No;

int main(void) {

    return 0;
}
