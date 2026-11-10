// Lista · Módulo 24 · Busca de padrões em texto
// Exercício P2423 · ★★★ · A mensagem em pedaços
//
// O áudio virou texto em pedaços que se repetem nas pontas:
//
//   "o rato roe", "roeu a rou", "a roupa do rei", "rei de roma",
//   "roma inteira"
//
// Junte os pedaços em ordem, colando cada um com a MAIOR sobreposição: o
// maior sufixo do que já foi montado que também é prefixo do pedaço novo.
// O truque: essa sobreposição é a borda (π da última letra) da string
// pedaço + '#' + montado. O '#' não aparece nos textos, então a borda não
// passa dele. Escreva sobreposicao(a, b) com a calcula_pi e monte a
// mensagem, mostrando quanto cada pedaço sobrepôs.
//
//   Saída esperada:
//   "roeu a rou" sobrepõe 3: "roe"
//   "a roupa do rei" sobrepõe 5: "a rou"
//   "rei de roma" sobrepõe 3: "rei"
//   "roma inteira" sobrepõe 4: "roma"
//   Mensagem: o rato roeu a roupa do rei de roma inteira
//
// Dicas:
// 1. Monte junto com snprintf(junto, sizeof junto, "%s#%s", b, a).
// 2. Depois de achar s, cole só o resto: strcat(msg, pedaco + s).
// 3. Resposta esperada: o rato roeu a roupa do rei de roma inteira.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

void calcula_pi(const char *p, int m, int pi[]) {
    pi[0] = 0;
    int k = 0;
    for (int j = 1; j < m; j++) {
        while (k > 0 && p[j] != p[k]) k = pi[k - 1];
        if (p[j] == p[k]) k++;
        pi[j] = k;
    }
}

int main(void) {
    const char *pedacos[] = {"o rato roe", "roeu a rou", "a roupa do rei", "rei de roma", "roma inteira"};
    printf("%s\n", pedacos[0]);
    return 0;
}
