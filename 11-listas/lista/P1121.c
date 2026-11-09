// Lista · Módulo 11 · Listas
// Exercício P1121 · ★★★ · A agenda que sobrevive ao desligar
//
// Uma lista encadeada some quando o programa acaba. Junte o módulo 11 com o
// 09: escreva uma agenda de contatos (nome e telefone, sem espaços) numa
// lista ordenada por nome, que é salva num arquivo texto e carregada de
// volta. Funções:
//
//   Contato *insere(Contato *inicio, const char *nome, const char *fone)
//   Contato *remove_nome(Contato *inicio, const char *nome)
//   const Contato *busca(const Contato *inicio, const char *nome)
//   int salva(const Contato *inicio, const char *caminho)  // quantos gravou
//   Contato *carrega(const char *caminho, int *n)          // lista nova
//
// No main: insira Rui (92)98100-0001, Ana (92)98100-0002,
// Lia (92)98100-0003 e Bia (92)98100-0004; remova Lia; salve em
// /tmp/p1121_agenda.txt, uma linha "nome fone" por contato; LIBERE a lista;
// carregue numa lista nova, mostre-a e procure Bia. Apague o arquivo no fim.
//
//   Saída esperada:
//   Agenda: Ana Bia Lia Rui
//   Sem Lia: Ana Bia Rui
//   Salvos: 3 contatos
//   Carregados: 3 contatos
//   Ana (92)98100-0002
//   Bia (92)98100-0004
//   Rui (92)98100-0001
//   Bia: (92)98100-0004
//
// Dicas:
// 1. carrega lê com fscanf(arq, "%15s %19s", nome, fone) == 2 e chama
//    insere para cada linha: a lista nova já nasce ordenada.
// 2. Como o arquivo foi salvo em ordem, dá para inserir sempre no fim (com
//    um ponteiro para o último) e carregar em O(n) em vez de O(n²). Aqui,
//    com 3 contatos, tanto faz; com 1 milhão, não.
// 3. Nada de ponteiro no arquivo: um endereço de memória não vale nada na
//    próxima execução. Grave só os dados.
// 4. Resposta esperada: a saída acima, sem vazamento.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct contato {
    char nome[16];
    char fone[20];
    struct contato *prox;
} Contato;

int main(void) {

    return 0;
}
