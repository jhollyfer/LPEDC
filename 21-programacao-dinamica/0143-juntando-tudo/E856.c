// 0143 · Juntando tudo: um mini-diff
// Exercício E856 · ★★☆
//
// A saída do diff serve para mais do que olhar: é um PATCH, a receita para
// transformar a versão antiga na nova. Quem recebe o patch aplica no seu
// arquivo e fica com a versão nova, sem precisar do arquivo inteiro. Este é
// o patch da lista de compras do texto:
//
//   "  arroz", "  feijão", "+ açúcar", "  café", "- leite",
//   "+ leite sem lactose", "  pão", "  banana", "- sabão"
//
// Escreva
//
//   int aplica(const char *orig[], int m, const char *patch[], int p,
//              const char *novo[])
//
// que aplica o patch ao original e grava as linhas da versão nova em novo,
// devolvendo quantas são. Linhas "  " e "- " falam de uma linha do original
// e precisam BATER com ela; se não baterem, o patch não se aplica: devolva
// -(número da linha do original, contando de 1). Teste com a lista antiga
// e com uma lista em que a 3ª linha virou "chá".
//
//   Saída esperada:
//   v1: arroz, feijão, açúcar, café, leite sem lactose, pão, banana
//   outra lista: o patch não se aplica (linha 3)
//
// Dicas:
// 1. Um índice i anda no original. Para cada linha do patch, olhe o 1º
//    caractere; o texto da linha começa em patch[k] + 2.
// 2. '+': o texto entra em novo. ' ': confere com orig[i], entra e i++.
//    '-': confere com orig[i] e só faz i++.
// 3. novo[] pode guardar os próprios ponteiros (const char *), sem copiar
//    as strings.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {

    return 0;
}
