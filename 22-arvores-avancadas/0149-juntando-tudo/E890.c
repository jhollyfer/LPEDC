// 0149 · Juntando tudo
// Exercício E890 · ★☆☆
//
// O cor_proxima só entende letras de 'a' a 'z': maiúscula vira separador, e
// "Hoje" sai como "oje". Escreva normaliza(s), que troca as maiúsculas por
// minúsculas no próprio vetor. O main confere o recado antes e depois.
//
//   Saída esperada:
//   palavras: oje a da ua tem ao e afe
//     8 palavras, 4 fora do dicionário
//   palavras: hoje a feira da rua tem pao e cafe
//     9 palavras, 0 fora do dicionário
//
// Dicas:
// 1. Use tolower, de <ctype.h>, em cada caractere até o '\0'. Converta para
//    unsigned char antes: tolower((unsigned char)s[i]).
// 2. O recado é um vetor (char recado[]), e não um ponteiro para literal:
//    por isso dá para alterá-lo. A pontuação não precisa sair: cor_proxima já
//    pula o que não é letra.
// 3. Resposta esperada: a saída acima. "FEIRA" inteira some na primeira
//    conferência: nenhuma letra dela está entre 'a' e 'z'.
//
// Escreva sua resposta abaixo (escreva normaliza e chame no main):

#include <ctype.h>
#include <stdio.h>
#include "corretor.h"

void confere(const NoC *dic, const char *texto) {
    char palavra[COR_MAX];
    int total = 0, fora = 0;
    printf("palavras:");
    while (cor_proxima(&texto, palavra)) {
        printf(" %s", palavra);
        total++;
        fora += !cor_contem(dic, palavra);
    }
    printf("\n  %d palavras, %d fora do dicionário\n", total, fora);
}

int main(void) {
    NoC *dic = cor_cria();
    cor_carrega_basico(dic);
    char recado[] = "Hoje, a FEIRA da Rua tem Pao e Cafe!";
    confere(dic, recado);
    // normaliza(recado); e confira de novo
    cor_libera(dic);
    return 0;
}
