// 0080 · Vetor dinâmico
// Exercício E477 · ★★☆
//
// O pluviômetro da escola anota a chuva do dia em mm, e grava -1 quando o
// sensor falha. Complete as duas funções usando SÓ a interface de lista.h:
//
//   posicao_de(l, valor)   primeira posição de valor na lista, ou -1
//   remove_todos(l, valor) tira todas as ocorrências e devolve quantas tirou
//
// Com as leituras 4, -1, 0, 12, -1, -1, 7:
//
//   Saída esperada:
//   antes:  [4, -1, 0, 12, -1, -1, 7]
//   depois: [4, 0, 12, 7]
//   3 falhas removidas
//
// Dicas:
// 1. posicao_de é um for de 0 até lista_tamanho(l) com lista_pega.
// 2. remove_todos pode repetir: "ache a posição; se achou, remova" até não
//    achar mais.
// 3. Cuidado com o atalho "for (i = 0; i < tam; i++) se for -1, remove i":
//    depois de remover, o vizinho escorrega para a posição i e o i++ pula
//    ele. Com dois -1 seguidos, um escapa.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (complete as funções):

#include <stdio.h>
#include "lista.h"

// devolve a primeira posição de "valor" na lista, ou -1 se não tiver
int posicao_de(const Lista *l, int valor) {
    (void)l;     // apague estas duas linhas
    (void)valor; // quando escrever a função
    return -1;
}

// tira todas as ocorrências de "valor" e devolve quantas tirou
int remove_todos(Lista *l, int valor) {
    (void)l;     // apague estas duas linhas
    (void)valor; // quando escrever a função
    return 0;
}

int main(void) {
    int chuva[] = {4, -1, 0, 12, -1, -1, 7};
    Lista *l = lista_cria(4);
    if (l == NULL) return 1;
    for (int i = 0; i < 7; i++) lista_insere_fim(l, chuva[i]);

    printf("antes:  ");
    lista_imprime(l);
    int tirou = remove_todos(l, -1);
    printf("depois: ");
    lista_imprime(l);
    printf("%d falhas removidas\n", tirou);

    lista_libera(l);
    return 0;
}
