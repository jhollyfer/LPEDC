// 0177 · Rubro-negra clássica
// Exercício E1058 · ★☆☆
//
// Os Correios do bairro guardam os CEPs atendidos numa rubro-negra
// (vermelhopreto.h): 69050, 69020, 69099, 69010, 69077, 69045 e 69033.
// Escreva minimo(T, x) e maximo(T, x), que descem até o filho ser a
// sentinela (&T->nil). Mostre os CEPs em ordem, o menor, o maior e se o CEP
// 69088 está cadastrado (vp_busca devolve &T->nil quando não acha).
//
//   Saída esperada:
//   em ordem: 69010 69020 69033 69045 69050 69077 69099
//   menor: 69010 | maior: 69099
//   69088: não cadastrado
//
// Dicas:
// 1. while (x->esq != &T->nil) x = x->esq; o máximo é o espelho.
// 2. Compare o retorno de vp_busca com &T->nil, nunca com NULL.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include "vermelhopreto.h"

int main(void) {

    return 0;
}
