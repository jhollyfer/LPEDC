// 0105 · A ideia e a função hash
// Exercício E626 · ★☆☆
//
// O programa abaixo mostra o balde de 4 palavras com a soma dos códigos e
// M = 5. Estenda o programa: escreva a função "unsigned soma(const char *s)",
// que devolve a soma dos códigos SEM o resto, e, depois da lista, compare
// todos os pares de palavras. Para cada par que cai no mesmo balde, mostre
// os dois nomes e as duas somas completas. Assim você vê qual colisão vem
// de anagrama (somas iguais) e qual é só acaso do resto (somas diferentes).
//
//   Saída esperada:
//   sol=4
//   los=4
//   Sol=2
//   lua=2
//   sol e los colidem (somas 334 e 334)
//   Sol e lua colidem (somas 302 e 322)
//
// Dicas:
// 1. h() pode chamar soma() e só tirar o resto: "return soma(s) % M;".
// 2. Pares sem repetir: "for (i = 0; i < 4; i++) for (j = i + 1; j < 4; j++)".
// 3. Resposta esperada: a saída acima. "sol" e "los" são anagramas;
//    "Sol" e "lua" só têm o mesmo resto por 5 ('S' = 83 não é 's' = 115).
//
// Escreva sua resposta abaixo (estenda o código):

#include <stdio.h>

#define M 5

unsigned h(const char *s) {
    unsigned total = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        total += (unsigned char)s[i];
    }
    return total % M;
}

int main(void) {
    const char *p[] = {"sol", "los", "Sol", "lua"};
    for (int i = 0; i < 4; i++) {
        printf("%s=%u\n", p[i], h(p[i]));
    }

    // compare os pares aqui

    return 0;
}
