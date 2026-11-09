// Lista · Módulo 24 · Busca de padrões em texto
// Exercício P2426 · ★★★ · A cifra de César do bilhete
//
// O bilhete veio cifrado com a cifra de César: cada letra minúscula foi
// empurrada s casas para a frente no alfabeto (dando a volta no z); o
// resto ficou igual. Você não sabe o s, mas sabe que a palavra "pix" está
// no bilhete. Escreva o programa do zero: para cada s de 0 a 25, decifre
// o bilhete e procure "pix" com o KMP; mostre cada deslocamento que dá e
// o texto decifrado, e quantos deram.
//
//   "alrfp z ati op ntynz cpltd lep dpiel, glwpf"
//
//   Saída esperada:
//   deslocamento 11: pague o pix de cinco reais ate sexta, valeu
//   Deslocamentos com "pix": 1 de 26
//
// Dicas:
// 1. Decifrar é andar para trás: 'a' + (c - 'a' - s + 26) % 26.
// 2. Escreva kmp_tem(t, p), que devolve 1 na primeira ocorrência.
// 3. Resposta esperada: só o deslocamento 11 tem "pix": pague o pix de
//    cinco reais ate sexta, valeu.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {

    return 0;
}
