// 0086 · Fila encadeada
// Exercício E515 · ★★★
//
// No banco, a lei manda atender primeiro quem tem prioridade, mas sem largar
// a fila comum esquecida. A regra da agência: chame 2 preferenciais, depois
// 1 comum, e repita. Se uma das filas estiver vazia, chame da outra.
//
// Use duas filas do fila.h. As senhas preferenciais são 101, 102 e 103; as
// comuns, 1, 2, 3 e 4. Mostre a ordem de chamada, com P na frente das
// preferenciais e C na frente das comuns.
//
//   Saída esperada:
//   Chamando: P101 P102 C1 P103 C2 C3 C4
//
// Dicas:
// 1. Um contador de preferenciais chamadas seguidas decide de qual fila
//    tirar: se for menor que 2 e a preferencial não estiver vazia, tire
//    dela; senão, tire da comum (e zere o contador).
// 2. Cuidado com o caso "contador chegou a 2, mas a comum está vazia": aí
//    a preferencial continua.
// 3. O laço roda enquanto alguma das duas filas tiver gente.
// 4. Resposta esperada: Chamando: P101 P102 C1 P103 C2 C3 C4.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include "fila.h"

int main(void) {

    return 0;
}
