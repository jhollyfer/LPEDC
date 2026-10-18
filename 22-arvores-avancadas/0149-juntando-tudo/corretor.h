// corretor.h · interface do TAD corretor ortográfico (dicionário numa trie)
#ifndef CORRETOR_H
#define CORRETOR_H

#include <stdbool.h>

#define COR_LETRAS 26
#define COR_MAX 32  // tamanho máximo de uma palavra (com o '\0')

typedef struct NoC {
    struct NoC *filho[COR_LETRAS];
    bool fim;
} NoC;

NoC *cor_cria(void);                         // dicionário vazio
bool cor_insere(NoC *d, const char *palavra); // false se tiver algo fora de a-z
bool cor_contem(const NoC *d, const char *palavra);

// põe no dicionário as palavras do vocabulário básico; devolve quantas
int cor_carrega_basico(NoC *d);

// sugestões a uma edição de distância (tirar, trocar de lugar, trocar ou pôr
// uma letra) que estão no dicionário, sem repetição e em ordem alfabética;
// guarda até max em sug e devolve quantas guardou
int cor_sugere(const NoC *d, const char *palavra, char sug[][COR_MAX], int max);

// separa o texto em palavras: pula o que não for letra de a a z, copia as
// letras seguintes para palavra (até COR_MAX - 1) e avança *texto. Devolve
// false quando o texto acaba sem nenhuma palavra.
bool cor_proxima(const char **texto, char palavra[]);

int cor_nos(const NoC *d);
void cor_libera(NoC *d);

#endif
