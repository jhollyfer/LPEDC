// Lista · Módulo 06 · Ponteiros
// Exercício P0628 · ★★★ · Todas as vezes que a palavra aparece
//
// Um revisor quer achar todas as vezes que "boi" aparece na letra da toada:
//
//   const char *letra = "O boi bumbá, o boi Garantido, o boizinho do povo, boi!";
//
// Escreva int achar_todas(const char *texto, const char *palavra,
// const char *pos[], int max), que usa strstr para guardar em pos o endereço
// de cada ocorrência (no máximo max) e devolve quantas achou. Depois mostre
// a posição de cada uma (diferença de ponteiros) e o texto com cada
// ocorrência entre colchetes, imprimindo caractere a caractere:
//
//   Saída esperada:
//   4 ocorrências: 2 16 33 51
//   O [boi] bumbá, o [boi] Garantido, o [boi]zinho do povo, [boi]!
//
// Dicas:
// 1. const char *p = strstr(texto, palavra); enquanto p != NULL: guarde p e
//    continue a busca a partir de p + 1 (e não de texto, senão acha a mesma
//    de novo).
// 2. Para os colchetes, ande com um ponteiro c pelo texto e um índice k na
//    próxima ocorrência: se c == pos[k], imprima '[', a palavra e ']', pule
//    strlen(palavra) caracteres e faça k++.
// 3. "boizinho" também contém "boi": é ocorrência para o strstr.
// 4. Resposta esperada: a saída acima (4 ocorrências).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {
    const char *letra = "O boi bumbá, o boi Garantido, o boizinho do povo, boi!";
    (void) letra; // apague esta linha quando escrever

    return 0;
}
