// Lista · Módulo 06 · Ponteiros
// Exercício P0615 · ★★☆ · Troque o prato do cardápio

#include <stdio.h>
#include <string.h>

const char **achar(const char **itens, int n, const char *prato) {
    for (int i = 0; i < n; i++) {
        if (strcmp(itens[i], prato) == 0) {
            return &itens[i]; // o endereço da gaveta, não o texto
        }
    }
    return NULL;
}

void mostrar(const char **itens, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d. %s\n", i + 1, itens[i]);
    }
}

void trocar(const char **itens, int n, const char *velho, const char *novo) {
    const char **gaveta = achar(itens, n, velho);
    if (gaveta == NULL) {
        printf("%s não está no cardápio\n", velho);
        return;
    }
    *gaveta = novo;
    printf("%s trocado por %s (gaveta %d)\n", velho, novo, (int) (gaveta - itens));
}

int main(void) {
    const char *cardapio[5] = {"Tacacá", "Pato no tucupi", "Tambaqui assado",
                               "Vatapá", "Maniçoba"};

    trocar(cardapio, 5, "Vatapá", "Caldeirada");
    trocar(cardapio, 5, "Feijoada", "Moqueca");
    mostrar(cardapio, 5);
    return 0;
}
