// Lista · Módulo 25 · Estruturas especiais
// Exercício P2524 · ★★★ · Desfazer o mover para a frente

#include <stdio.h>
#include <string.h>

void codifica(const char *texto, int saida[]) {
    char alf[27] = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; texto[i]; i++) {
        int p = (int)(strchr(alf, texto[i]) - alf);
        saida[i] = p;
        for (int k = p; k > 0; k--) alf[k] = alf[k - 1];
        alf[0] = texto[i];
    }
}

// o decodificador faz o MESMO movimento: lê a posição, pega a letra que
// está lá e a leva para a frente
void decodifica(const int cod[], int n, char saida[]) {
    char alf[27] = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < n; i++) {
        int p = cod[i];
        char c = alf[p];
        saida[i] = c;
        for (int k = p; k > 0; k--) alf[k] = alf[k - 1];
        alf[0] = c;
    }
    saida[n] = '\0';
}

int main(void) {
    int recebido[] = {1, 1, 13, 1, 1, 1, 2, 1, 2, 1, 1, 1};
    int n = 12;
    char msg[64];
    decodifica(recebido, n, msg);
    printf("Mensagem: %s\n", msg);

    int ida[64];
    codifica(msg, ida);
    int igual = 1, pequenos = 0;
    for (int i = 0; i < n; i++) {
        if (ida[i] != recebido[i]) igual = 0;
        pequenos += ida[i] < 3;
    }
    printf("Codificando de novo: %s\n", igual ? "mesmos números" : "DIFERENTE");
    printf("Números menores que 3: %d de %d\n", pequenos, n);

    const char *frase = "aaaabbbbaaaabbbb";
    int c[64], m = (int)strlen(frase);
    codifica(frase, c);
    printf("%s ->", frase);
    for (int i = 0; i < m; i++) printf(" %d", c[i]);
    printf("\n");
    return 0;
}
