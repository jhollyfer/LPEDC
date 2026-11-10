// Lista · Módulo 29 · Grafos: ciclos e cortes; problemas difíceis
// Exercício P2903 · ★☆☆ · Passeio, trajeto ou caminho
//
// No parque há seis quiosques (A a F) e as trilhas A-B, B-C, C-D, D-A, B-D,
// D-E, E-F. Um corredor anota a sequência de quiosques por onde passou.
// Escreva int classifica(const char *s), que devolve 0 se a sequência não é
// um passeio (alguma trilha não existe), 1 para passeio (repete trilha), 2
// para trajeto (repete quiosque, não trilha), 3 para caminho (não repete
// nada). Se a sequência for fechada, os nomes viram passeio fechado,
// circuito e ciclo. Mostre o nome e o COMPRIMENTO (número de trilhas).
// Teste: ABCD, ABCDB, ABCDBA, ABCDA, DEFD.
//
//   Saída esperada:
//   ABCD    caminho, comprimento 3
//   ABCDB   trajeto, comprimento 4
//   ABCDBA  passeio fechado, comprimento 5
//   ABCDA   ciclo, comprimento 4
//   DEFD    não é passeio, comprimento 3
//
// Dicas:
// 1. O comprimento é o número de letras menos 1. Fechada: primeira letra igual
//    à última.
// 2. Na fechada, não conte a última letra como repetição do quiosque (ela é a
//    primeira de novo). Trilha repetida: o par (x, y) aparece de novo em
//    qualquer ordem.
// 3. Resposta esperada: a saída acima. DEFD falha porque não existe a trilha
//    F-D, por mais que a sequência pareça um triângulo.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
