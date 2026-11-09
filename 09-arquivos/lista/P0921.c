// Lista · Módulo 09 · Arquivos e linha de comando
// Exercício P0921 · ★★★ · A agenda que se mantém em ordem no disco
//
// Uma agenda guarda contatos (nome e telefone) num arquivo binário SEMPRE
// em ordem alfabética, para que a busca seja binária. Escreva:
//
//   void insere(FILE *arq, const Contato *novo, int *deslocados)
//     acha a posição do novo lendo o arquivo do começo; depois empurra uma
//     posição para a frente cada registro que fica depois dele (do último
//     para trás, para não sobrescrever ninguém) e grava o novo no buraco.
//     Conta em *deslocados quantos registros foram empurrados.
//   int busca(FILE *arq, const char *nome, Contato *achado, int *leituras)
//     busca binária pelo nome, contando os fread.
//
// No main, abra /tmp/p0921_agenda.bin com "wb+" e insira, nesta ordem:
// Marta 92 99100-0001, Bia 92 99100-0002, Rui 92 99100-0003,
// Caio 92 99100-0004 e Ana 92 99100-0005. Liste a agenda, mostre o total
// de deslocamentos e procure Caio e Zeca. Apague o arquivo no fim.
//
//   Saída esperada:
//   0 Ana     92 99100-0005
//   1 Bia     92 99100-0002
//   2 Caio    92 99100-0004
//   3 Marta   92 99100-0001
//   4 Rui     92 99100-0003
//   Deslocamentos: 7
//   Caio: 92 99100-0004 (1 leitura)
//   Zeca: não está na agenda (3 leituras)
//
// Dicas:
// 1. O número de registros é o tamanho do arquivo (fseek até o fim, ftell)
//    dividido por sizeof(Contato). Faça funções le(arq, i, &c) e
//    grava(arq, i, &c) com o fseek certo dentro.
// 2. Para abrir o buraco na posição pos: for (i = n - 1; i >= pos; i--),
//    leia o registro i e grave-o em i + 1. Depois grave o novo em pos.
// 3. Deslocamentos: Marta 0, Bia 1, Rui 0, Caio 2 e Ana 4, total 7. É o
//    custo de manter a ordem: inserir é O(n), mas buscar fica O(log n).
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[16];
    char fone[16];
} Contato;

int main(void) {

    return 0;
}
