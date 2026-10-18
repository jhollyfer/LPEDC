// 0160 · Rabin-Karp
// Exercício E959 · ★★★
//
// Ache o bug. A função conta as ocorrências de um número de telefone dentro
// de uma sequência de dígitos. Nos dois testes o padrão aparece DUAS vezes,
// mas a função acha 0 no primeiro e 1 no segundo. O programa não quebra: o
// erro está nas contas do hash rolante. Conserte e rode.
//
//   Saída que aparece:
//   8922: 0
//   800: 1
//
//   Saída esperada:
//   8922: 2
//   800: 2
//
// Dicas:
// 1. Acrescente um printf("%d ", ht) em cada volta e compare com o hp.
// 2. Em C, o resto de um número negativo é negativo: -7 % 101 vale -7, e
//    não 94. Um hash negativo nunca vai ser igual ao hp, que é positivo.
// 3. ht - dígito * pot fica negativo sempre que o dígito que sai pesa mais
//    que o hash atual. Some Q antes de tirar o resto (e reduza o produto
//    com % Q, para a soma com Q bastar).
// 4. Resposta esperada: ht = (ht - (t[i] - '0') * pot % Q + Q) % Q; e a
//    saída acima.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <string.h>

#define Q 101

int iguais(const char *t, const char *p, int m) {
    for (int j = 0; j < m; j++) {
        if (t[j] != p[j]) {
            return 0;
        }
    }
    return 1;
}

int conta(const char *t, const char *p) {
    int n = (int) strlen(t);
    int m = (int) strlen(p);
    int pot = 1;
    for (int j = 0; j < m - 1; j++) {
        pot = pot * 10 % Q;
    }
    int hp = 0, ht = 0;
    for (int j = 0; j < m; j++) {
        hp = (hp * 10 + (p[j] - '0')) % Q;
        ht = (ht * 10 + (t[j] - '0')) % Q;
    }
    int total = 0;
    for (int i = 0; i <= n - m; i++) {
        if (ht == hp && iguais(t + i, p, m)) {
            total++;
        }
        if (i < n - m) {
            ht = (ht - (t[i] - '0') * pot) % Q;
            ht = (ht * 10 + (t[i + m] - '0')) % Q;
        }
    }
    return total;
}

int main(void) {
    printf("8922: %d\n", conta("4002892240028922", "8922"));
    printf("800: %d\n", conta("0800729072908007", "800"));
    return 0;
}
