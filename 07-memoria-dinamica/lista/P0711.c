// Lista · Módulo 07 · Memória dinâmica
// Exercício P0711 · ★★☆ · Juntar a lista com um malloc só
//
// O app da feira monta a lista de compras numa linha só para mandar por
// mensagem. Escreva
//
//   char *juntar_todas(const char **itens, int n, const char *sep);
//
// que devolve uma string nova no heap com os itens separados por sep (sem
// sep depois do último), fazendo UM malloc só, do tamanho exato. Teste com a
// lista abaixo e os separadores ", " e " | ", e com uma lista vazia (n = 0,
// que devolve ""):
//
//   const char *feira[5] = {"farinha", "tucumã", "jambu",
//                           "cheiro-verde", "pupunha"};
//
//   Saída esperada:
//   "farinha, tucumã, jambu, cheiro-verde, pupunha" -> malloc(47)
//   "farinha | tucumã | jambu | cheiro-verde | pupunha" -> malloc(51)
//   "" -> malloc(1)
//
// Dicas:
// 1. Primeiro calcule o tamanho: soma dos strlen dos itens + (n - 1) vezes
//    strlen(sep) + 1. Com n = 0, o tamanho é só 1 (o '\0').
// 2. Comece com s[0] = '\0' e use strcat. (Para listas grandes, o strcat
//    fica lento porque procura o fim a cada chamada; guardar um ponteiro
//    para o fim resolve.)
// 3. Os bytes do "tucumã" são 7: o ã ocupa 2 em UTF-8, e o strlen conta
//    bytes.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    const char *feira[5] = {"farinha", "tucumã", "jambu", "cheiro-verde", "pupunha"};
    (void) feira; // apague esta linha quando escrever

    return 0;
}
