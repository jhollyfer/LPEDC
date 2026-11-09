// Lista · Módulo 02 · Decisões
// Exercício P0224 · ★★★ · O desempate do campeonato

#include <stdio.h>

int main(void) {
    int p1 = 58, v1 = 17, gp1 = 50, gc1 = 31; // Manaus FC
    int p2 = 58, v2 = 17, gp2 = 54, gc2 = 35; // Amazonas FC
    int s1 = gp1 - gc1, s2 = gp2 - gc2;

    printf("Manaus FC: %d pts, %d V, saldo %d, %d GP\n", p1, v1, s1, gp1);
    printf("Amazonas FC: %d pts, %d V, saldo %d, %d GP\n", p2, v2, s2, gp2);

    if (p1 != p2) {
        printf("Na frente: %s (critério: pontos)\n", p1 > p2 ? "Manaus FC" : "Amazonas FC");
    } else if (v1 != v2) {
        printf("Na frente: %s (critério: vitórias)\n", v1 > v2 ? "Manaus FC" : "Amazonas FC");
    } else if (s1 != s2) {
        printf("Na frente: %s (critério: saldo de gols)\n", s1 > s2 ? "Manaus FC" : "Amazonas FC");
    } else if (gp1 != gp2) {
        printf("Na frente: %s (critério: gols pró)\n", gp1 > gp2 ? "Manaus FC" : "Amazonas FC");
    } else {
        printf("Empate total: vale o sorteio\n");
    }
    return 0;
}
