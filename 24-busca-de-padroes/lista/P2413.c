// Lista · Módulo 24 · Busca de padrões em texto
// Exercício P2413 · ★★☆ · O colar girado
//
// Um colar de contas coloridas pode ser lido a partir de qualquer conta.
// b é uma ROTAÇÃO de a quando girar a algumas casas para a esquerda dá b.
// O truque: b é rotação de a se e só se b aparece dentro de a + a. Escreva
// giros(a, b), que monta a + a e usa o KMP para mostrar TODOS os k
// (0 <= k < n) em que girar a k casas dá b, e devolve quantos são. Copie
// a calcula_pi do assunto 0158.
//
//   Saída esperada:
//   azulverdeazulverde -> verdeazulverdeazul: 4 13 (2 giro(s))
//   amarelopreto -> pretoamarelo: 7 (1 giro(s))
//   rosabranco -> brancoroxa: não é rotação (0 giro(s))
//   ouroouroouro -> ouroouroouro: 0 4 8 (3 giro(s))
//
// Dicas:
// 1. Uma ocorrência que termina em i começa em i - n + 1. Só valem as que
//    começam antes de n: percorra i de 0 até 2n - 2.
// 2. Se os tamanhos forem diferentes, já não é rotação. Use snprintf para
//    montar a + a num vetor de 128.
// 3. Resposta esperada: azulverdeazulverde vira o outro com 4 ou 13 giros;
//    ouroouroouro, com 0, 4 ou 8; rosabranco não vira brancoroxa.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {
    const char *pares[][2] = {{"azulverdeazulverde", "verdeazulverdeazul"},
                              {"amarelopreto", "pretoamarelo"},
                              {"rosabranco", "brancoroxa"},
                              {"ouroouroouro", "ouroouroouro"}};
    printf("%s -> %s\n", pares[0][0], pares[0][1]);
    return 0;
}
