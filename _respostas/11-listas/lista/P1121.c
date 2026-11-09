// Lista · Módulo 11 · Listas
// Exercício P1121 · ★★★ · A agenda que sobrevive ao desligar

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct contato {
    char nome[16];
    char fone[20];
    struct contato *prox;
} Contato;

Contato *insere(Contato *inicio, const char *nome, const char *fone) {
    Contato *novo = malloc(sizeof *novo);
    if (novo == NULL) {
        fprintf(stderr, "sem memória\n");
        exit(1);
    }
    strcpy(novo->nome, nome);
    strcpy(novo->fone, fone);
    if (inicio == NULL || strcmp(nome, inicio->nome) < 0) {
        novo->prox = inicio;
        return novo;
    }
    Contato *p = inicio;
    while (p->prox != NULL && strcmp(p->prox->nome, nome) < 0) {
        p = p->prox;
    }
    novo->prox = p->prox;
    p->prox = novo;
    return inicio;
}

Contato *remove_nome(Contato *inicio, const char *nome) {
    Contato *ant = NULL, *p = inicio;
    while (p != NULL && strcmp(p->nome, nome) != 0) {
        ant = p;
        p = p->prox;
    }
    if (p == NULL) {
        return inicio;
    }
    if (ant == NULL) {
        inicio = p->prox;
    } else {
        ant->prox = p->prox;
    }
    free(p);
    return inicio;
}

const Contato *busca(const Contato *inicio, const char *nome) {
    for (const Contato *p = inicio; p != NULL; p = p->prox) {
        if (strcmp(p->nome, nome) == 0) {
            return p;
        }
    }
    return NULL;
}

int salva(const Contato *inicio, const char *caminho) {
    FILE *arq = fopen(caminho, "w");
    if (arq == NULL) {
        return -1;
    }
    int n = 0;
    for (const Contato *p = inicio; p != NULL; p = p->prox) {
        fprintf(arq, "%s %s\n", p->nome, p->fone);
        n++;
    }
    fclose(arq);
    return n;
}

Contato *carrega(const char *caminho, int *n) {
    *n = 0;
    FILE *arq = fopen(caminho, "r");
    if (arq == NULL) {
        return NULL;
    }
    Contato *inicio = NULL;
    char nome[16], fone[20];
    while (fscanf(arq, "%15s %19s", nome, fone) == 2) {
        inicio = insere(inicio, nome, fone);
        (*n)++;
    }
    fclose(arq);
    return inicio;
}

void nomes(const char *rotulo, const Contato *inicio) {
    printf("%s:", rotulo);
    for (const Contato *p = inicio; p != NULL; p = p->prox) {
        printf(" %s", p->nome);
    }
    printf("\n");
}

void libera(Contato *inicio) {
    while (inicio != NULL) {
        Contato *seguinte = inicio->prox;
        free(inicio);
        inicio = seguinte;
    }
}

int main(void) {
    const char *caminho = "/tmp/p1121_agenda.txt";
    Contato *ag = NULL;
    ag = insere(ag, "Rui", "(92)98100-0001");
    ag = insere(ag, "Ana", "(92)98100-0002");
    ag = insere(ag, "Lia", "(92)98100-0003");
    ag = insere(ag, "Bia", "(92)98100-0004");
    nomes("Agenda", ag);
    ag = remove_nome(ag, "Lia");
    nomes("Sem Lia", ag);

    printf("Salvos: %d contatos\n", salva(ag, caminho));
    libera(ag); // a lista some; o arquivo fica

    int n;
    Contato *nova = carrega(caminho, &n);
    printf("Carregados: %d contatos\n", n);
    for (const Contato *p = nova; p != NULL; p = p->prox) {
        printf("%s %s\n", p->nome, p->fone);
    }
    const Contato *bia = busca(nova, "Bia");
    if (bia != NULL) {
        printf("Bia: %s\n", bia->fone);
    }
    libera(nova);
    remove(caminho);
    return 0;
}
