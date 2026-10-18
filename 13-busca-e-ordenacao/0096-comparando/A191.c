// A191 · Duas vitrines do mesmo cardápio com qsort

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[16];
    double preco;
    int calorias;
} Prato;

// o vetor ordenado é de Prato *: o qsort entrega o ENDEREÇO de cada ponteiro
int por_preco(const void *a, const void *b) {
    const Prato *p = *(const Prato *const *) a;
    const Prato *q = *(const Prato *const *) b;
    return (p->preco > q->preco) - (p->preco < q->preco);
}

int por_calorias_desc(const void *a, const void *b) {
    const Prato *p = *(const Prato *const *) a;
    const Prato *q = *(const Prato *const *) b;
    if (p->calorias != q->calorias) {
        return (p->calorias < q->calorias) - (p->calorias > q->calorias);
    }
    return strcmp(p->nome, q->nome);        // desempate: nome
}

void mostra(const char *titulo, Prato *const v[], size_t n) {
    printf("%s\n", titulo);
    for (size_t i = 0; i < n; i++) {
        printf("  %-10s R$ %5.2f %4d kcal\n", v[i]->nome, v[i]->preco, v[i]->calorias);
    }
}

int main(void) {
    Prato cardapio[] = {
        {"Coxinha", 7.50, 290}, {"Pastel", 9.00, 340}, {"Tapioca", 12.00, 250},
        {"Esfiha", 6.50, 250}, {"Cuscuz", 15.00, 480},
    };
    size_t n = sizeof cardapio / sizeof cardapio[0];
    Prato *vitrine1[5], *vitrine2[5];
    for (size_t i = 0; i < n; i++) {
        vitrine1[i] = vitrine2[i] = &cardapio[i];  // só endereços, nada copiado
    }

    qsort(vitrine1, n, sizeof vitrine1[0], por_preco);
    qsort(vitrine2, n, sizeof vitrine2[0], por_calorias_desc);

    mostra("Mais barato primeiro:", vitrine1, n);
    mostra("Mais calórico primeiro:", vitrine2, n);
    printf("cardapio[0] continua: %s (cada ponteiro tem %zu bytes, cada Prato %zu)\n",
           cardapio[0].nome, sizeof vitrine1[0], sizeof cardapio[0]);
    return 0;
}
// Saída (8 e 32 bytes numa máquina de 64 bits comum):
// Mais barato primeiro:
//   Esfiha     R$  6.50  250 kcal
//   Coxinha    R$  7.50  290 kcal
//   Pastel     R$  9.00  340 kcal
//   Tapioca    R$ 12.00  250 kcal
//   Cuscuz     R$ 15.00  480 kcal
// Mais calórico primeiro:
//   Cuscuz     R$ 15.00  480 kcal
//   Pastel     R$  9.00  340 kcal
//   Coxinha    R$  7.50  290 kcal
//   Esfiha     R$  6.50  250 kcal
//   Tapioca    R$ 12.00  250 kcal
// cardapio[0] continua: Coxinha (cada ponteiro tem 8 bytes, cada Prato 32)
