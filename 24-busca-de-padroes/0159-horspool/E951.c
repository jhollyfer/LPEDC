// 0159 · Horspool
// Exercício E951 · ★★☆
//
// O cardápio da feira foi digitado com o Caps Lock ligando e desligando.
// Escreva int horspool_todas(const char *texto, const char *padrao): um
// Horspool que ignora maiúsculas e minúsculas, mostra cada ocorrência (como
// está escrita no texto) e devolve o total. Procure "banana" em:
//
//   "Banana na BANANEIRA, banana no prato, BANANA no bolo"
//
//   Saída esperada:
//   posição  0: Banana
//   posição 21: banana
//   posição 38: BANANA
//   3 ocorrências
//
// Dicas:
// 1. Faça uma função baixa(c) que devolve tolower((unsigned char) c).
// 2. A tabela precisa usar a MESMA conversão nos dois lados: monte-a com
//    baixa(padrao[j]) e consulte com baixa(texto[i + m - 1]). Montar com as
//    letras originais e consultar convertida faz o salto errar.
// 3. Depois de achar, não pare: salte como num alinhamento qualquer.
// 4. Resposta esperada: a saída acima. O "BANANE" de BANANEIRA não conta.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ALFABETO 256

int main(void) {

    return 0;
}
