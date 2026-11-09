// Lista · Módulo 20 · Divisão e conquista e algoritmos gulosos
// Exercício P2023 · ★★★ · Huffman de ida e volta

#include <stdio.h>
#include <string.h>

#define MAXN 64

typedef struct {
    int freq, esq, dir;
    char c;
} No;

No no[MAXN];
int heap[MAXN], nh = 0;
char codigo[256][32];

int menor(int i, int j) {
    if (no[i].freq != no[j].freq) {
        return no[i].freq < no[j].freq;
    }
    return i < j;
}

void insere(int x) {
    int i = nh++;
    heap[i] = x;
    while (i > 0 && menor(heap[i], heap[(i - 1) / 2])) {
        int p = (i - 1) / 2, t = heap[i];
        heap[i] = heap[p];
        heap[p] = t;
        i = p;
    }
}

int retira(void) {
    int r = heap[0];
    heap[0] = heap[--nh];
    int i = 0;
    for (;;) {
        int e = 2 * i + 1, d = e + 1, m = i;
        if (e < nh && menor(heap[e], heap[m])) {
            m = e;
        }
        if (d < nh && menor(heap[d], heap[m])) {
            m = d;
        }
        if (m == i) {
            break;
        }
        int t = heap[i];
        heap[i] = heap[m];
        heap[m] = t;
        i = m;
    }
    return r;
}

void gera(int i, char buf[], int prof) {
    if (no[i].esq < 0) {
        buf[prof] = '\0';
        strcpy(codigo[(unsigned char)no[i].c], buf);
        return;
    }
    buf[prof] = '0';
    gera(no[i].esq, buf, prof + 1);
    buf[prof] = '1';
    gera(no[i].dir, buf, prof + 1);
}

int main(void) {
    const char *frase = "MANAUS AMAZONAS";
    int freq[256] = {0};
    for (int i = 0; frase[i] != '\0'; i++) {
        freq[(unsigned char)frase[i]]++;
    }
    int n = 0;
    for (int c = 0; c < 256; c++) {
        if (freq[c] > 0) {
            no[n] = (No){freq[c], -1, -1, (char)c};
            insere(n);
            n++;
        }
    }
    while (nh > 1) {
        int a = retira(), b = retira();
        no[n] = (No){no[a].freq + no[b].freq, a, b, 0};
        insere(n);
        n++;
    }
    int raiz = retira();
    char buf[32];
    gera(raiz, buf, 0);
    for (int c = 0; c < 256; c++) {
        if (freq[c] > 0) {
            printf("'%c' %d vez(es): %s\n", c, freq[c], codigo[c]);
        }
    }
    char bits[512] = "";
    for (int i = 0; frase[i] != '\0'; i++) {
        strcat(bits, codigo[(unsigned char)frase[i]]);
    }
    printf("Bits: %s\n", bits);
    char volta[64];
    int k = 0, atual = raiz;
    for (int i = 0; bits[i] != '\0'; i++) {
        atual = bits[i] == '0' ? no[atual].esq : no[atual].dir;
        if (no[atual].esq < 0) {
            volta[k++] = no[atual].c;
            atual = raiz;
        }
    }
    volta[k] = '\0';
    printf("%zu caracteres, %zu bits (ASCII: %zu)\n", strlen(frase), strlen(bits), 8 * strlen(frase));
    printf("Decodificado: %s (%s)\n", volta, strcmp(volta, frase) == 0 ? "igual" : "diferente");
    return 0;
}
