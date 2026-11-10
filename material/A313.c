// A313 · O strstr e as risadas do grupo

#include <stdio.h>
#include <string.h>

// conta as ocorrências de padrao com strstr; depois de achar, recomeça
// 'pulo' letras à frente: 1 conta as sobrepostas, strlen(padrao) não conta
int conta(const char *texto, const char *padrao, size_t pulo) {
    int total = 0;
    const char *p = strstr(texto, padrao);
    while (p != NULL) {
        printf(" %td", p - texto); // posição = endereço achado - início
        total++;
        p = strstr(p + pulo, padrao);
    }
    return total;
}

int main(void) {
    const char *msg = "kkkkkk boa";

    printf("\"kk\" com pulo 1, posições:");
    int a = conta(msg, "kk", 1);
    printf(" -> %d vezes\n", a);

    printf("\"kk\" com pulo 2, posições:");
    int b = conta(msg, "kk", strlen("kk"));
    printf(" -> %d vezes\n", b);

    // strstr devolve NULL quando não acha e o próprio texto para padrão vazio
    printf("\"haha\": %s\n", strstr(msg, "haha") == NULL ? "NULL" : "achou");
    printf("\"\": aponta para a posição %td\n", strstr(msg, "") - msg);
    return 0;
}
// Saída:
// "kk" com pulo 1, posições: 0 1 2 3 4 -> 5 vezes
// "kk" com pulo 2, posições: 0 2 4 -> 3 vezes
// "haha": NULL
// "": aponta para a posição 0
