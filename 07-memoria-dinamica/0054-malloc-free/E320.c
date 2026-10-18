// 0054 · malloc e free
// Exercício E320 · ★☆☆
//
// Complete a função duplicar: ela recebe uma string e devolve uma CÓPIA dela
// num bloco novo do heap, do tamanho exato. O main já está pronto: ele
// passa a cópia para maiúsculas e mostra que a original não mudou.
//
//   Saída esperada:
//   Original: coxinha
//   Cópia: COXINHA
//
// Dicas:
// 1. Quantos bytes ocupa "coxinha"? Conte o '\0'.
// 2. malloc(strlen(texto) + 1), confira o NULL e use strcpy.
// 3. Resposta esperada: a saída acima. Sem o + 1, o strcpy escreve o '\0'
//    um byte depois do fim do bloco e o AddressSanitizer acusa
//    heap-buffer-overflow.
//
// Escreva sua resposta abaixo (complete a função):

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *duplicar(const char *texto) {
    // TODO: aloque strlen(texto) + 1 bytes, confira o NULL, copie e devolva
    (void)texto; // apague esta linha quando usar o parâmetro
    return NULL;
}

int main(void) {
    const char *original = "coxinha";
    char *copia = duplicar(original);
    if (copia == NULL) {
        printf("duplicar ainda não foi feita\n");
        return 0;
    }
    for (int i = 0; copia[i] != '\0'; i++) {
        copia[i] = (char)toupper((unsigned char)copia[i]);
    }
    printf("Original: %s\n", original);
    printf("Cópia: %s\n", copia);
    free(copia);
    return 0;
}
