// 0137 · Juntando tudo
// Exercício E817 · ★☆☆

#include <stdio.h>
#include "compactador.h"

int main(void) {
    const char *cardapio =
        "PRATO DO DIA\n"
        "Segunda: feijoada com couve e laranja\n"
        "Terça: frango assado com farofa\n"
        "Quarta: feijoada com couve e laranja\n"
        "Quinta: peixe com pirão\n"
        "Sexta: feijoada com couve e laranja\n";

    FILE *f = fopen("cardapio.txt", "w");
    if (f == NULL) {
        return 1;
    }
    for (int i = 0; i < 30; i++) {          // o cardápio de 30 semanas
        fputs(cardapio, f);
    }
    fclose(f);

    long original = arq_tamanho("cardapio.txt");
    long compacto = huf_compacta("cardapio.txt", "cardapio.huf");
    long volta = huf_descompacta("cardapio.huf", "cardapio2.txt");
    printf("Original:      %ld bytes\n", original);
    printf("Compactado:    %ld bytes (%.1f%%)\n", compacto, 100.0 * compacto / original);
    printf("Descompactado: %ld bytes\n", volta);

    remove("cardapio.txt");
    remove("cardapio.huf");
    remove("cardapio2.txt");
    return 0;
}
