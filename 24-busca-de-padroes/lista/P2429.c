// Lista · Módulo 24 · Busca de padrões em texto
// Exercício P2429 · ★★★ · O verificador que fugiu da frase
//
// Ache o bug. Este verificador de palíndromos ignora tudo o que não é
// letra. Nas três primeiras frases ele acerta, mas na quarta ("?!") o
// AddressSanitizer para o programa com global-buffer-overflow (é de
// propósito): o índice i passou do '\0' e saiu lendo a memória depois da
// frase. Rode, leia o erro (ele aponta a linha) e conserte as DUAS linhas
// com o mesmo problema.
//
//   Saída esperada:
//   [Ame o poema.] sim
//   [Luz azul!] sim
//   [A cara rajada da jararaca.] sim
//   [?!] sim
//   [Oi, tchau.] não
//   [...] sim
//
// Dicas:
// 1. O que faz o laço "pula o que não é letra" numa frase sem letra
//    nenhuma? Quem faz ele parar?
// 2. O j tem o problema do outro lado: numa frase só de pontuação ele
//    desceria abaixo de 0.
// 3. Resposta esperada: ponha i < j na condição dos dois laços internos;
//    "?!" e "..." viram "sim" (não há letra que quebre a simetria) e só
//    "Oi, tchau." é "não".
//
// Escreva sua resposta abaixo (conserte o código):

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool palindromo(const char *s) {
    int i = 0, j = (int)strlen(s) - 1;
    while (i < j) {
        while (!isalpha((unsigned char)s[i])) i++;
        while (!isalpha((unsigned char)s[j])) j--;
        if (tolower((unsigned char)s[i]) != tolower((unsigned char)s[j])) return false;
        i++;
        j--;
    }
    return true;
}

int main(void) {
    const char *frases[] = {"Ame o poema.", "Luz azul!", "A cara rajada da jararaca.", "?!", "Oi, tchau.", "..."};
    for (int k = 0; k < 6; k++) printf("[%s] %s\n", frases[k], palindromo(frases[k]) ? "sim" : "não");
    return 0;
}
