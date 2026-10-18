// 0104 · Juntando tudo
// Exercício E622 · ★★☆
//
// Matrícula nova precisa de um número livre, e a recepção quer saber qual é
// a próxima matrícula ocupada depois de um número qualquer. Escreva
// proxima(r, x): devolve a MENOR matrícula maior que x, ou -1 se não houver.
// Não percorra a árvore inteira: desça um caminho só.
//
//   Saída esperada:
//   depois de 45: 50
//   depois de 50: 60
//   depois de 10: 20
//   depois de 80: -1
//
// Dicas:
// 1. Desça da raiz. Se a matrícula do nó for maior que x, ela é uma
//    candidata: guarde e vá para a esquerda, procurando uma menor que ainda
//    seja maior que x. Senão, vá para a direita.
// 2. Quando chegar no NULL, a última candidata guardada é a resposta.
// 3. Resposta esperada: a saída acima. Para 50, o caminho é 50 (não serve),
//    70 (candidata), 60 (candidata melhor), NULL.
//
// Escreva sua resposta abaixo (complete proxima):

#include <stdio.h>
#include "cadastro.h"

int proxima(const NoAluno *r, int x) {
    (void)r; // apague estas duas linhas
    (void)x;
    return -1;
}

int main(void) {
    Aluno turma[] = {
        {50, "Ana", 12}, {30, "Bruno", 8}, {70, "Carla", 15}, {20, "Davi", 4},
        {40, "Eva", 20}, {60, "Fabio", 9}, {80, "Gil", 11},
    };
    NoAluno *cad = NULL;
    for (int i = 0; i < 7; i++) {
        cad = cad_insere(cad, turma[i]);
    }
    int testes[] = {45, 50, 10, 80};
    for (int i = 0; i < 4; i++) {
        printf("depois de %d: %d\n", testes[i], proxima(cad, testes[i]));
    }
    cad = cad_libera(cad);
    return 0;
}
