// corretor.c · implementação do TAD corretor ortográfico
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "corretor.h"

static const char *BASICO[] = {
    "a", "o", "e", "de", "do", "da", "no", "na", "em", "um", "uma", "que", "com",
    "para", "por", "nao", "sim", "casa", "caso", "cama", "cara", "caro", "carro",
    "janela", "porta", "portao", "azul", "amarela", "amarelo", "verde", "branco",
    "tem", "tinha", "foi", "vai", "passou", "sol", "mar", "rua", "bairro", "cidade",
    "escola", "aluno", "aluna", "livro", "mesa", "agua", "cafe", "pao", "leite",
    "bolo", "bola", "gato", "dia", "noite", "hoje", "amanha", "ontem", "bom", "boa",
    "muito", "pouco", "grande", "feira", "mercado", "preco", "barato", "real",
    "reais", "trabalho", "onibus", "ponto", "chuva", "frio", "calor", "festa",
    "amigo", "amiga", "familia", "ele", "ela", "eu", "voce", "nos",
};

NoC *cor_cria(void) {
    NoC *n = calloc(1, sizeof(NoC));
    if (n == NULL) {
        fprintf(stderr, "sem memória\n");
        exit(1);
    }
    return n;
}

static bool so_letras(const char *p) {
    if (strlen(p) >= COR_MAX) {
        return false;
    }
    for (; *p != '\0'; p++) {
        if (*p < 'a' || *p > 'z') {
            return false;
        }
    }
    return true;
}

bool cor_insere(NoC *d, const char *palavra) {
    if (!so_letras(palavra)) {
        return false;
    }
    for (; *palavra != '\0'; palavra++) {
        int i = *palavra - 'a';
        if (d->filho[i] == NULL) {
            d->filho[i] = cor_cria();
        }
        d = d->filho[i];
    }
    d->fim = true;
    return true;
}

bool cor_contem(const NoC *d, const char *palavra) {
    if (!so_letras(palavra)) {
        return false;
    }
    for (; *palavra != '\0' && d != NULL; palavra++) {
        d = d->filho[*palavra - 'a'];
    }
    return d != NULL && d->fim;
}

int cor_carrega_basico(NoC *d) {
    int n = (int)(sizeof BASICO / sizeof BASICO[0]);
    for (int i = 0; i < n; i++) {
        cor_insere(d, BASICO[i]);
    }
    return n;
}

// guarda c em sug se estiver no dicionário e ainda não estiver na lista,
// mantendo a lista em ordem alfabética (inserção ordenada)
static void anota(const NoC *d, const char *c, char sug[][COR_MAX], int *qtd, int max) {
    if (!cor_contem(d, c)) {
        return;
    }
    int i = 0;
    while (i < *qtd && strcmp(sug[i], c) < 0) {
        i++;
    }
    if (i < *qtd && strcmp(sug[i], c) == 0) {
        return; // repetida
    }
    if (*qtd == max) {
        if (i == max) {
            return; // não cabe e é maior que todas
        }
        (*qtd)--; // descarta a última para abrir espaço
    }
    for (int k = *qtd; k > i; k--) {
        strcpy(sug[k], sug[k - 1]);
    }
    strcpy(sug[i], c);
    (*qtd)++;
}

int cor_sugere(const NoC *d, const char *palavra, char sug[][COR_MAX], int max) {
    int n = (int)strlen(palavra);
    int qtd = 0;
    char c[COR_MAX + 1];
    if (n >= COR_MAX - 1) {
        return 0;
    }
    for (int i = 0; i < n; i++) { // 1. tirar a letra i
        memcpy(c, palavra, i);
        strcpy(c + i, palavra + i + 1);
        anota(d, c, sug, &qtd, max);
    }
    for (int i = 0; i + 1 < n; i++) { // 2. trocar as letras i e i + 1 de lugar
        strcpy(c, palavra);
        char t = c[i];
        c[i] = c[i + 1];
        c[i + 1] = t;
        anota(d, c, sug, &qtd, max);
    }
    for (int i = 0; i < n; i++) { // 3. trocar a letra i por outra
        strcpy(c, palavra);
        for (char l = 'a'; l <= 'z'; l++) {
            if (l != palavra[i]) {
                c[i] = l;
                anota(d, c, sug, &qtd, max);
            }
        }
    }
    for (int i = 0; i <= n; i++) { // 4. pôr uma letra na posição i
        for (char l = 'a'; l <= 'z'; l++) {
            memcpy(c, palavra, i);
            c[i] = l;
            strcpy(c + i + 1, palavra + i);
            anota(d, c, sug, &qtd, max);
        }
    }
    return qtd;
}

bool cor_proxima(const char **texto, char palavra[]) {
    const char *p = *texto;
    while (*p != '\0' && (*p < 'a' || *p > 'z')) { // pula espaços e pontuação
        p++;
    }
    int k = 0;
    while (*p >= 'a' && *p <= 'z') {
        if (k < COR_MAX - 1) {
            palavra[k++] = *p;
        }
        p++;
    }
    palavra[k] = '\0';
    *texto = p;
    return k > 0;
}

int cor_nos(const NoC *d) {
    if (d == NULL) {
        return 0;
    }
    int total = 1;
    for (int i = 0; i < COR_LETRAS; i++) {
        total += cor_nos(d->filho[i]);
    }
    return total;
}

void cor_libera(NoC *d) {
    if (d == NULL) {
        return;
    }
    for (int i = 0; i < COR_LETRAS; i++) {
        cor_libera(d->filho[i]);
    }
    free(d);
}
