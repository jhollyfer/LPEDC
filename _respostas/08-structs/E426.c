// 0071 · Juntando tudo: o cardápio
// Exercício E426 · ★★★

#include <stdbool.h>
#include <stdio.h>

typedef enum { J_NULO, J_NUMERO, J_TEXTO, J_BOOL } TipoJson;

typedef struct {
    TipoJson tipo;
    union {
        double numero;
        char texto[32];
        bool booleano;
    } v;
} ValorJson;

typedef struct {
    char chave[16];
    ValorJson valor;
} Campo;

void imprimir_valor(const ValorJson *v) {
    switch (v->tipo) {
    case J_NULO:
        printf("null");
        break;
    case J_NUMERO:
        printf("%g", v->v.numero);
        break;
    case J_TEXTO:
        printf("\"%s\"", v->v.texto);
        break;
    case J_BOOL:
        printf("%s", v->v.booleano ? "true" : "false");
        break;
    }
}

void imprimir_objeto(const Campo campos[], int n) {
    printf("{");
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            printf(", ");
        }
        printf("\"%s\": ", campos[i].chave);
        imprimir_valor(&campos[i].valor);
    }
    printf("}\n");
}

int main(void) {
    Campo perfil[] = {
        {"nome", {J_TEXTO, .v.texto = "Ana"}},
        {"idade", {J_NUMERO, .v.numero = 31}},
        {"altura", {J_NUMERO, .v.numero = 1.68}},
        {"ativa", {J_BOOL, .v.booleano = true}},
        {"apelido", {J_NULO, .v.numero = 0}},
    };
    imprimir_objeto(perfil, sizeof perfil / sizeof perfil[0]);
    return 0;
}
