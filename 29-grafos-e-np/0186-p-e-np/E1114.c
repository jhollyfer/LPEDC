// 0186 · P e NP
// Exercício E1114 · ★★☆
//
// Colorir um grafo com 3 cores também é NP-completo. A coordenação precisa
// marcar seis provas em três turnos (manhã, tarde, noite) sem que um aluno
// tenha duas no mesmo turno. Provas: Cálculo, Física, Química, Algoritmos,
// Inglês, Desenho (0 a 5). Pares em conflito:
//
//   Cálculo-Física, Cálculo-Química, Física-Química, Física-Algoritmos,
//   Química-Algoritmos, Algoritmos-Inglês, Cálculo-Inglês, Inglês-Desenho,
//   Algoritmos-Desenho
//
// Escreva:
//   1. o verificador bool valida(const int turno[]), que mostra o primeiro
//      conflito que achar (pares a < b em ordem) e devolve false;
//   2. teste o palpite da coordenação: turnos 0, 1, 2, 0, 1, 0;
//   3. a força bruta pelas 3^6 = 729 escalas, contando em base 3 (o
//      algarismo p do código é o turno da prova p), parando na primeira
//      válida.
//
//   Saída esperada:
//   Palpite da coordenação:
//     conflito: Algoritmos e Desenho de manhã
//     inválido
//   Primeira escala válida (tentativa 141):
//     Cálculo: noite
//     Física: tarde
//     Química: manhã
//     Algoritmos: noite
//     Inglês: tarde
//     Desenho: manhã
//
// Dicas:
// 1. Base 3: turno[p] = resto % 3; resto /= 3, para p de 0 a 5. É o mesmo
//    truque da máscara de bits, com três valores por posição.
// 2. Com k cores e n vértices, a força bruta testa k^n escalas; o
//    verificador, só os pares, O(n²).
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
