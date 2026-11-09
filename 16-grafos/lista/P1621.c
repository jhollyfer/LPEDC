// Lista · Módulo 16 · Grafos
// Exercício P1621 · ★★★ · As duas jarras do vendedor de caldo de cana
//
// Na feira, o vendedor de caldo de cana só tem uma jarra de 3 L e outra de
// 5 L, sem marcação, e um cliente pediu exatamente 4 L. Ele pode, a cada
// passo: encher uma jarra, esvaziar uma jarra, ou despejar uma na outra até a
// de origem esvaziar ou a de destino encher.
//
// Isso é um grafo implícito: cada ESTADO (a, b), com a litros na primeira
// jarra e b na segunda, é um vértice, e cada operação é uma aresta dirigida.
// A BFS a partir de (0, 0) acha a sequência com o MENOR número de passos.
//
// Escreva void jarras(int A, int B, int alvo), que roda a BFS no grafo de
// estados (estado = a * (B + 1) + b), para no primeiro estado com a == alvo
// ou b == alvo, e mostra os passos, ou "impossível". Tente as operações nesta
// ordem: enche A, enche B, esvazia A, esvazia B, A -> B, B -> A. Mostre
// também quantos estados a BFS descobriu. Rode jarras(3, 5, 4) e
// jarras(4, 6, 3).
//
//   Saída esperada:
//   Jarras de 3 L e 5 L, alvo 4 L: 6 passos (15 estados descobertos)
//     enche B   -> (0, 5)
//     B -> A    -> (3, 2)
//     esvazia A -> (0, 2)
//     B -> A    -> (2, 0)
//     enche B   -> (2, 5)
//     B -> A    -> (3, 4)
//   Jarras de 4 L e 6 L, alvo 3 L: impossível (10 estados descobertos)
//
// Dicas:
// 1. São (A + 1)(B + 1) estados no máximo; os vetores dist[], pai[] e op[]
//    (a operação que levou até ali) cabem num tamanho fixo, como 11 * 11.
// 2. Despejar A em B: passa x = min(a, B - b) litros; o novo estado é
//    (a - x, b + x).
// 3. Para mostrar o caminho, guarde em pai[] o estado anterior e em op[] o
//    nome da operação; percorra de trás para frente para um vetor e imprima
//    ao contrário.
// 4. Com 4 L e 6 L, todo estado alcançável tem quantidades pares: 3 L é
//    impossível, e a BFS termina sem achar o alvo.
// 5. Resposta esperada: 4 L em 6 passos (enche B, B -> A, esvazia A, B -> A,
//    enche B, B -> A, terminando em (3, 4)); 3 L com 4 e 6 é impossível.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

void jarras(int A, int B, int alvo) {
    (void)A; // apague e escreva a função
    (void)B;
    (void)alvo;
}

int main(void) {
    jarras(3, 5, 4);
    jarras(4, 6, 3);
    return 0;
}
