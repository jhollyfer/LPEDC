// 0158 · KMP
// Exercício E948 · ★★★
//
// Uma brincadeira de palavras: acrescentar o MÍNIMO de letras no começo de
// uma palavra para ela virar palíndromo. "ovos" vira "sovos"; "arara" já é.
// O segredo é achar o maior prefixo da palavra que é palíndromo: o resto vai,
// ao contrário, para a frente. E a tabela pi acha esse prefixo em O(m).
// Escreva void completa(const char *s, char saida[]) e teste com "ovos",
// "arara", "abacaxi" e "assar":
//
//   Saída esperada:
//   ovos     -> sovos        (prefixo palíndromo: 3 letras, +1)
//   arara    -> arara        (prefixo palíndromo: 5 letras, +0)
//   abacaxi  -> ixacabacaxi  (prefixo palíndromo: 3 letras, +4)
//   assar    -> rassar       (prefixo palíndromo: 4 letras, +1)
//
// Dicas:
// 1. Monte aux = s + "#" + (s ao contrário). Para "ovos": "ovos#sovo".
// 2. Uma borda de aux é um prefixo de s que, lido ao contrário, é o fim do
//    reverso, ou seja, é igual a ele mesmo invertido: um palíndromo. O '#'
//    impede a borda de passar do meio. Logo, pi[último] de aux é o tamanho do
//    maior prefixo palíndromo (3 para "ovos": "ovo").
// 3. A saída é s[pal..m-1] ao contrário, seguida de s inteira.
// 4. printf("%-8s -> %-12s ...") alinha as colunas. Resposta esperada: a
//    saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

#define MAX 32

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

int main(void) {

    return 0;
}
