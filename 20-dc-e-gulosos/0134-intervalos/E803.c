// 0134 · Seleção de intervalos
// Exercício E803 · ★★★
//
// Este programa tem DOIS erros de propósito. O festival tem um palco só, e
// o programa escolhe o maior número de shows sem choque, com os horários
// [ini, fim). Ele roda sem aviso nenhum, mas aceita um show só:
//
//   Saída que aparece:
//   14h-16h Forró do Zé
//   Shows no palco: 1
//
//   Saída esperada:
//   14h-16h Forró do Zé
//   16h-18h Samba da Vila
//   18h-20h MPB Nova
//   20h-22h Axé Total
//   22h-24h Brega Chic
//   Shows no palco: 5
//
// Ache e conserte os dois erros. Para achar, acrescente um printf que mostre
// livre_em a cada volta do laço.
//
// Dicas:
// 1. O Samba começa às 16h, exatamente quando o Forró termina. Com
//    intervalos semiabertos, isso é choque?
// 2. Depois de recusar o Rock Raiz (15h-19h), o palco deveria continuar
//    livre a partir das 18h. O que o programa faz com livre_em quando
//    recusa um show?
// 3. Resposta esperada: o teste certo é s[i].ini >= livre_em, e a linha
//    livre_em = s[i].fim precisa ficar DENTRO do if (só show aceito ocupa o
//    palco). Consertado, mostra a saída acima.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    const char *banda;
    int ini, fim; // [ini, fim), em horas
} Show;

int por_fim(const void *a, const void *b) {
    const Show *x = a, *y = b;
    return (x->fim > y->fim) - (x->fim < y->fim);
}

int main(void) {
    Show s[] = {
        {"Forró do Zé", 14, 16}, {"Samba da Vila", 16, 18}, {"Rock Raiz", 15, 19},
        {"MPB Nova", 18, 20},    {"Pagode 10", 17, 21},     {"Axé Total", 20, 22},
        {"Funk Sul", 21, 23},    {"Brega Chic", 22, 24},
    };
    int n = 8;

    qsort(s, n, sizeof s[0], por_fim);
    int livre_em = 0;
    int total = 0;
    for (int i = 0; i < n; i++) {
        if (s[i].ini > livre_em) {
            printf("%dh-%dh %s\n", s[i].ini, s[i].fim, s[i].banda);
            total++;
        }
        livre_em = s[i].fim;
    }
    printf("Shows no palco: %d\n", total);
    return 0;
}
