// 0160 · Rabin-Karp
// Exercício E960 · ★★★
//
// Por que o hash do Rabin-Karp é um polinômio, e não a simples soma dos
// bytes? A soma também rola fácil (tira um byte, soma outro), mas ignora a
// ORDEM das letras. Escreva duas buscas que contam as verificações letra a
// letra (hash igual) e as ocorrências: busca_soma, com o hash soma, e
// busca_polinomial, com base 256 e Q = 1000003. Procure "amor" em
// "roma, amor, mora, ramo, omar e amora":
//
//   Saída esperada:
//   soma:       7 verificações, 2 ocorrências
//   polinomial: 2 verificações, 2 ocorrências
//
// Dicas:
// 1. Soma: hp e ht começam com a soma dos m primeiros bytes; para rolar,
//    ht += t[i + m] - t[i] (converta para unsigned char).
// 2. Com a soma, todo anagrama de "amor" tem o mesmo hash: roma, mora, ramo,
//    omar e até o "mora" de "amora". Cada um vira uma conferência inútil.
// 3. No polinômio, cada letra é multiplicada por uma potência diferente da
//    base: trocar duas letras de lugar muda o valor.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {

    return 0;
}
