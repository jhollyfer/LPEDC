// Lista · Módulo 24 · Busca de padrões em texto
// Exercício P2422 · ★★★ · Um hash ou dois
//
// Um módulo pequeno dá muitos falsos positivos. Trocar por um módulo
// grande é uma saída; outra é usar DOIS hashes com módulos pequenos e
// diferentes: a janela só é conferida letra a letra se os dois baterem.
// Escreva o programa do zero:
// - gere um DNA de 3000 letras com o gerador fixo
// estado = estado * 1103515245u + 12345u (estado começa em 2026) e a
// letra "ACGT"[(estado >> 16) % 4];
// - o padrão são as 6 letras a partir da posição 1500;
// - role as janelas com base 4 (A=0, C=1, G=2, T=3) e dois hashes, módulos
// 97 e 89, e conte os falsos positivos do primeiro hash sozinho e dos
// dois juntos.
//
//   Saída esperada:
//   padrão: CGTCAA
//   janelas: 2995, ocorrências: 1
//   falsos positivos com um hash (q = 97): 32
//   falsos positivos com dois hashes (q = 97 e 89): 0
//
// Dicas:
// 1. Um vetor val[256] com val['C'] = 1, val['G'] = 2, val['T'] = 3 evita
//    um if por letra.
// 2. Com dois módulos primos diferentes, bater nos dois é como bater num
//    módulo 97 × 89 = 8633: a chance cai de 1/97 para 1/8633.
// 3. Resposta esperada: o padrão é CGTCAA, 1 ocorrência, 32 falsos
//    positivos com um hash e nenhum com os dois.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {

    return 0;
}
