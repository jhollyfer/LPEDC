// A353 · A altura que a rubro-negra garante

#include <math.h>
#include <stdio.h>
#include "0177-vermelhopreto.h"

void testa(const char *nome, int n, int passo) {
    ArvVP *T = vp_cria();
    if (T == NULL) {
        return;
    }
    for (int i = 0; i < n; i++) {
        vp_insere(T, (int)((long)i * passo % n)); // passo 1: crescente
    }
    int bh = vp_altura_negra(T);
    printf("%-12s n = %d | altura %2d | altura negra %2d | 2^bh - 1 = %4d <= n? %s | regras: %s\n",
           nome, n, vp_altura(T), bh, (1 << bh) - 1, (1 << bh) - 1 <= n ? "sim" : "não",
           vp_confere(T) ? "ok" : "quebradas");
    vp_libera(T);
}

int main(void) {
    testa("crescente:", 1000, 1);
    testa("embaralhada:", 1000, 7919);
    testa("crescente:", 4095, 1);
    printf("Limite 2 log2(n + 1): %.1f para n = 1000 e %.1f para n = 4095\n",
           2 * log2(1001.0), 2 * log2(4096.0));
    return 0;
}
// Saída:
// crescente:   n = 1000 | altura 16 | altura negra  9 | 2^bh - 1 =  511 <= n? sim | regras: ok
// embaralhada: n = 1000 | altura 11 | altura negra  6 | 2^bh - 1 =   63 <= n? sim | regras: ok
// crescente:   n = 4095 | altura 21 | altura negra 11 | 2^bh - 1 = 2047 <= n? sim | regras: ok
// Limite 2 log2(n + 1): 19.9 para n = 1000 e 24.0 para n = 4095
