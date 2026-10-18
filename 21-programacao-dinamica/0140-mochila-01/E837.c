// 0140 · Mochila 0/1
// Exercício E837 · ★★☆
//
// Véspera de vestibular: você tem 6 horas de estudo e uma estimativa de
// quantos pontos cada revisão completa rende. Cada matéria é revisada
// inteira ou não é revisada:
//
//   matéria      horas  pontos
//   Matemática    2.5     30
//   Português     1.5     18
//   História      1.0     10
//   Física        2.0     25
//   Química       1.5     16
//   Inglês        0.5      6
//
// O problema: a tabela da mochila precisa de capacidades INTEIRAS, e as
// horas são double. Guarde as horas como double no programa, converta tudo
// para meias horas (unidades inteiras) e resolva a mochila 0/1 com
// recuperação. Mostre o máximo, as matérias e as horas usadas.
//
//   Saída esperada:
//   Máximo: 73 pontos em 6.0 h
//   Estudar: Física Português Matemática
//   Horas usadas: 6.0
//
// Dicas:
// 1. Meia hora vira 1 unidade: 2.5 h são 5 unidades e as 6 h são 12.
// 2. Converta com (int) (horas * 2 + 0.5). Só o cast trunca, e um double
//    que deveria ser 5.0 pode estar guardado como 4.99999...
// 3. Daí em diante é a tabela t[i][c] do texto, com c de 0 a 12, e a volta
//    pela tabela somando horas[i] de quem entrou.
// 4. Resposta esperada: a saída acima (30 + 18 + 25 = 73).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
