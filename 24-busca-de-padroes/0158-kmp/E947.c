// 0158 · KMP
// Exercício E947 · ★★★
//
// Ache o bug. A central do alarme usa KMP para desarmar quando a senha 1112
// aparece nas teclas. O cliente digitou 1, 1, 2, 1, 1, 2, 1, 1, 1 e o alarme
// DESARMOU, mas a senha nunca foi digitada. O programa não quebra: o erro é
// de lógica, numa linha só da função central. Conserte e rode.
//
//   Saída que aparece:
//   1121112: desarmou na tecla 7 (a senha começou na posição 3)
//   112112111: desarmou na tecla 6 (a senha começou na posição 2)
//
//   Saída esperada:
//   1121112: desarmou na tecla 7 (a senha começou na posição 3)
//   112112111: continua armado
//
// Dicas:
// 1. pi de "1112" é 0 1 2 0. Siga a central com 112112111 e anote o k depois
//    de cada tecla.
// 2. Na 3ª tecla (2), k vale 2 e não serve. O código recua para pi[1] = 1,
//    mas o 2 também não continua "1". O que deveria acontecer em seguida?
// 3. Na calcula_pi o recuo está certo. Compare as duas.
// 4. Resposta esperada: o recuo da central precisa ser um while, não um if.
//    Com o if, o k fica em 1 depois do 2, a central "acha" que um 1 já foi
//    digitado e aceita 2112 como se fosse 1112.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <string.h>

#define MAX 16

void calcula_pi(const char *p, int m, int pi[]) {
    int k = 0;
    pi[0] = 0;
    for (int j = 1; j < m; j++) {
        while (k > 0 && p[j] != p[k]) {
            k = pi[k - 1];
        }
        if (p[j] == p[k]) {
            k++;
        }
        pi[j] = k;
    }
}

// a central recebe as teclas uma a uma e desarma quando a senha aparece
void central(const char *senha, const char *teclas) {
    int m = (int) strlen(senha);
    int pi[MAX];
    int k = 0;
    calcula_pi(senha, m, pi);
    for (int i = 0; teclas[i] != '\0'; i++) {
        if (k > 0 && teclas[i] != senha[k]) {
            k = pi[k - 1];
        }
        if (teclas[i] == senha[k]) {
            k++;
        }
        if (k == m) {
            printf("%s: desarmou na tecla %d (a senha começou na posição %d)\n",
                   teclas, i + 1, i - m + 1);
            return;
        }
    }
    printf("%s: continua armado\n", teclas);
}

int main(void) {
    central("1112", "1121112");
    central("1112", "112112111");
    return 0;
}
