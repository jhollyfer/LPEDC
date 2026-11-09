// Lista · Módulo 08 · Tipos compostos
// Exercício P0823 · ★★★ · Do CSV para o vetor de structs

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct {
    char nome[24];
    int idade;
    char cidade[16];
} Atleta;

typedef struct {
    char cidade[16];
    int total;
} Contagem;

// copia de ini até fim (sem incluir fim) para dest, se couber
bool copiar_campo(char *dest, size_t cap, const char *ini, const char *fim) {
    size_t tam = (size_t) (fim - ini);
    if (tam == 0 || tam >= cap) {
        return false;
    }
    memcpy(dest, ini, tam);
    dest[tam] = '\0';
    return true;
}

bool ler_atleta(const char *linha, Atleta *a) {
    const char *p1 = strchr(linha, ';');
    if (p1 == NULL) {
        return false;
    }
    const char *p2 = strchr(p1 + 1, ';');
    if (p2 == NULL || strchr(p2 + 1, ';') != NULL) {
        return false; // menos ou mais de 3 campos
    }
    if (!copiar_campo(a->nome, sizeof a->nome, linha, p1)) {
        return false;
    }
    if (p2 == p1 + 1) {
        return false; // idade vazia
    }
    int idade = 0;
    for (const char *q = p1 + 1; q < p2; q++) {
        if (!isdigit((unsigned char) *q)) {
            return false;
        }
        idade = idade * 10 + (*q - '0');
    }
    a->idade = idade;
    return copiar_campo(a->cidade, sizeof a->cidade, p2 + 1, p2 + 1 + strlen(p2 + 1));
}

int main(void) {
    const char *linhas[7] = {"Ana Paula;34;Manaus", "Joel;abc;Parintins",
                             "Rosa;52;Manaus", "Iuri;19;Itacoatiara",
                             "Sem cidade;40", "Marta;27;Parintins",
                             "Caio;61;Manaus"};
    Atleta v[7];
    int n = 0;

    for (int i = 0; i < 7; i++) {
        if (ler_atleta(linhas[i], &v[n])) {
            n++;
        } else {
            printf("Recusada: \"%s\"\n", linhas[i]);
        }
    }

    Contagem por[7];
    int nc = 0;
    int soma = 0, velho = 0;
    for (int i = 0; i < n; i++) {
        soma += v[i].idade;
        if (v[i].idade > v[velho].idade) {
            velho = i;
        }
        int k = 0;
        while (k < nc && strcmp(por[k].cidade, v[i].cidade) != 0) {
            k++;
        }
        if (k == nc) {
            strcpy(por[nc].cidade, v[i].cidade);
            por[nc].total = 0;
            nc++;
        }
        por[k].total++;
    }
    printf("Aceitas: %d\n", n);
    printf("Média de idade: %.1f\n", soma / (double) n);
    printf("Mais velho: %s, %d anos\n", v[velho].nome, v[velho].idade);
    for (int k = 0; k < nc; k++) {
        printf("%s: %d\n", por[k].cidade, por[k].total);
    }
    return 0;
}
