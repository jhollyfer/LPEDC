// Lista · Módulo 24 · Busca de padrões em texto
// Exercício P2407 · ★☆☆ · A frase que lê dos dois lados
//
// Escreva do zero bool palindromo(const char *s), que diz se a frase é
// palíndromo ignorando os espaços e a diferença entre maiúsculas e
// minúsculas. Use dois índices, um em cada ponta, andando um para o outro
// (sem copiar a frase). Teste as cinco frases do esqueleto, mostrando cada
// uma com "%-40s".
//
//   Saída esperada:
//   Socorram me subi no onibus em Marrocos   sim
//   A base do teto desaba                    sim
//   Roma me tem amor                         sim
//   Bom dia Manaus                           não
//   ovo                                      sim
//
// Dicas:
// 1. i = 0 e j = strlen(s) - 1. Enquanto i < j: espaço em s[i], i++;
//    espaço em s[j], j--; senão compare tolower dos dois.
// 2. tolower recebe um unsigned char convertido para int: tolower(
//    (unsigned char)s[i]).
// 3. Resposta esperada: só "Bom dia Manaus" não é palíndromo.
//
// Escreva sua resposta abaixo:

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    const char *frases[] = {"Socorram me subi no onibus em Marrocos", "A base do teto desaba",
                            "Roma me tem amor", "Bom dia Manaus", "ovo"};
    printf("%s\n", frases[0]);
    return 0;
}
